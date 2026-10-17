#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chbaddiesetup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002B0: jal         0x800A5D60
    // 0x808002B4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x808002B4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808002B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002BC: jal         0x80800000
    // 0x808002C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x808002C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002C4: beq         $v0, $zero, L_80800368
    if (ctx->r2 == 0) {
        // 0x808002C8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800368;
    }
    // 0x808002C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808002CC: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x808002D0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808002D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808002D8: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808002DC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808002E0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x808002E4: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x808002E8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808002EC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808002F0: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808002F4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x808002F8: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x808002FC: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x80800300: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800304: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800308: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8080030C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x80800310: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x80800314: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x80800318: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080031C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80800320: sll         $t1, $t4, 5
    ctx->r9 = S32(ctx->r12 << 5);
    // 0x80800324: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80800328: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x8080032C: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80800330: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800334: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800338: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x8080033C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80800340: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x80800344: lbu         $t1, 0x4($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4);
    // 0x80800348: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080034C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80800350: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x80800354: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80800358: sw          $t4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r12;
    // 0x8080035C: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80800360: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800364: sb          $t7, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r15;
L_80800368:
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080036C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800370: jr          $ra
    // 0x80800374: nop

    return;
    // 0x80800374: nop

;}
RECOMP_FUNC void func_808051B4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808051B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808051B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808051BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808051C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808051C4: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x808051C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808051CC: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x808051D0: beq         $at, $zero, L_808052F4
    if (ctx->r1 == 0) {
        // 0x808051D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808052F4;
    }
    // 0x808051D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808051D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D38) << 16);
    // 0x808051DC: addu        $at, $at, $t6
    gpr jr_addend_808051E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808051E0: lw          $t6, 0x7D38($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D38));
    // 0x808051E4: jr          $t6
    // 0x808051E8: nop

    switch (jr_addend_808051E4 >> 2) {
        case 0: goto L_808051EC; break;
        case 1: goto L_8080520C; break;
        case 2: goto L_8080521C; break;
        case 3: goto L_80805244; break;
        case 4: goto L_808052D4; break;
        case 5: goto L_8080528C; break;
        case 6: goto L_808052A0; break;
        case 7: goto L_808052C0; break;
        case 8: goto L_80805230; break;
        case 9: goto L_808052F4; break;
        case 10: goto L_80805278; break;
        case 11: goto L_80805278; break;
        default: switch_error(__func__, 0x808051E4, 0x80807D38);
    }
    // 0x808051E8: nop

L_808051EC:
    // 0x808051EC: lw          $a0, 0x30($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X30);
    // 0x808051F0: jal         0x80802BE8
    // 0x808051F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80802BE8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808051F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808051F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808051FC: jal         0x80800478
    // 0x80805200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80805200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80805204: b           L_80805304
    // 0x80805208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x80805208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080520C:
    // 0x8080520C: jal         0x80805310
    // 0x80805210: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80805310_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805210: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80805214: b           L_80805304
    // 0x80805218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x80805218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080521C:
    // 0x8080521C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80805220: jal         0x80805474
    // 0x80805224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805474_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80805224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80805228: b           L_80805304
    // 0x8080522C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x8080522C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805230:
    // 0x80805230: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80805234: jal         0x80805474
    // 0x80805238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80805474_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80805238: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080523C: b           L_80805304
    // 0x80805240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x80805240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805244:
    // 0x80805244: lw          $t7, 0x64($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X64);
    // 0x80805248: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080524C: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80805250: bgez        $t9, L_80805268
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80805254: nop
    
            goto L_80805268;
    }
    // 0x80805254: nop

    // 0x80805258: jal         0x80803BE8
    // 0x8080525C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80803BE8_chgameselect(rdram, ctx);
        goto after_5;
    // 0x8080525C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80805260: b           L_80805304
    // 0x80805264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x80805264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805268:
    // 0x80805268: jal         0x80805BFC
    // 0x8080526C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805BFC_chgameselect(rdram, ctx);
        goto after_6;
    // 0x8080526C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80805270: b           L_80805304
    // 0x80805274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x80805274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805278:
    // 0x80805278: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080527C: jal         0x80805BFC
    // 0x80805280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805BFC_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80805280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80805284: b           L_80805304
    // 0x80805288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x80805288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080528C:
    // 0x8080528C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80805290: jal         0x80805CD8
    // 0x80805294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80805CD8_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80805294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80805298: b           L_80805304
    // 0x8080529C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x8080529C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808052A0:
    // 0x808052A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808052A4: jal         0x808068AC
    // 0x808052A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_808068AC_chgameselect(rdram, ctx);
        goto after_9;
    // 0x808052A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_9:
    // 0x808052AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808052B0: jal         0x80805CD8
    // 0x808052B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80805CD8_chgameselect(rdram, ctx);
        goto after_10;
    // 0x808052B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x808052B8: b           L_80805304
    // 0x808052BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x808052BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808052C0:
    // 0x808052C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808052C4: jal         0x80805CD8
    // 0x808052C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80805CD8_chgameselect(rdram, ctx);
        goto after_11;
    // 0x808052C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808052CC: b           L_80805304
    // 0x808052D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x808052D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808052D4:
    // 0x808052D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808052D8: jal         0x80806370
    // 0x808052DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80806370_chgameselect(rdram, ctx);
        goto after_12;
    // 0x808052DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_12:
    // 0x808052E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808052E4: jal         0x80805CD8
    // 0x808052E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80805CD8_chgameselect(rdram, ctx);
        goto after_13;
    // 0x808052E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808052EC: b           L_80805304
    // 0x808052F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80805304;
    // 0x808052F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808052F4:
    // 0x808052F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808052F8: jal         0x80800478
    // 0x808052FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_14;
    // 0x808052FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80805300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80805304:
    // 0x80805304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805308: jr          $ra
    // 0x8080530C: nop

    return;
    // 0x8080530C: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800788: jal         0x800CF87C
    // 0x8080078C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CF87C(rdram, ctx);
        goto after_0;
    // 0x8080078C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800794: bne         $v0, $at, L_808007A4
    if (ctx->r2 != ctx->r1) {
        // 0x80800798: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007A4;
    }
    // 0x80800798: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080079C: b           L_808007C8
    // 0x808007A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_808007C8;
    // 0x808007A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_808007A4:
    // 0x808007A4: jal         0x800CF87C
    // 0x808007A8: nop

    func_800CF87C(rdram, ctx);
        goto after_1;
    // 0x808007A8: nop

    after_1:
    // 0x808007AC: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x808007B0: bne         $v0, $at, L_808007C0
    if (ctx->r2 != ctx->r1) {
        // 0x808007B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007C0;
    }
    // 0x808007B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007B8: b           L_808007C8
    // 0x808007BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_808007C8;
    // 0x808007BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_808007C0:
    // 0x808007C0: jal         0x80800660
    // 0x808007C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800660_gccollectDll(rdram, ctx);
        goto after_2;
    // 0x808007C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_808007C8:
    // 0x808007C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_800A3DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A3DBC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A3DC0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800A3DC4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A3DC8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800A3DCC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800A3DD0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800A3DD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A3DD8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3DDC: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x800A3DE0: bnel        $a1, $t7, L_800A3E04
    if (ctx->r5 != ctx->r15) {
        // 0x800A3DE4: sb          $t2, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r10;
            goto L_800A3E04;
    }
    goto skip_0;
    // 0x800A3DE4: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    skip_0:
    // 0x800A3DE8: lh          $t9, 0x34($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X34);
    // 0x800A3DEC: bnel        $a2, $t9, L_800A3E04
    if (ctx->r6 != ctx->r25) {
        // 0x800A3DF0: sb          $t2, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r10;
            goto L_800A3E04;
    }
    goto skip_1;
    // 0x800A3DF0: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    skip_1:
    // 0x800A3DF4: lbu         $t1, 0x39($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X39);
    // 0x800A3DF8: beql        $a3, $t1, L_800A3EB8
    if (ctx->r7 == ctx->r9) {
        // 0x800A3DFC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800A3EB8;
    }
    goto skip_2;
    // 0x800A3DFC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x800A3E00: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
L_800A3E04:
    // 0x800A3E04: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800A3E08: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800A3E0C: addiu       $t3, $v0, 0x14
    ctx->r11 = ADD32(ctx->r2, 0X14);
    // 0x800A3E10: addiu       $t4, $v0, 0x18
    ctx->r12 = ADD32(ctx->r2, 0X18);
    // 0x800A3E14: addiu       $t5, $v0, 0x1C
    ctx->r13 = ADD32(ctx->r2, 0X1C);
    // 0x800A3E18: addiu       $t6, $v0, 0x20
    ctx->r14 = ADD32(ctx->r2, 0X20);
    // 0x800A3E1C: addiu       $t7, $v0, 0x24
    ctx->r15 = ADD32(ctx->r2, 0X24);
    // 0x800A3E20: addiu       $t8, $v0, 0x28
    ctx->r24 = ADD32(ctx->r2, 0X28);
    // 0x800A3E24: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800A3E28: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A3E2C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A3E30: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800A3E34: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A3E38: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3E3C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800A3E40: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x800A3E44: jal         0x800A59B8
    // 0x800A3E48: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    func_800A59B8(rdram, ctx);
        goto after_0;
    // 0x800A3E48: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    after_0:
    // 0x800A3E4C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800A3E50: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x800A3E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3E58: sh          $t9, 0x34($t0)
    MEM_H(0X34, ctx->r8) = ctx->r25;
    // 0x800A3E5C: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x800A3E60: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A3E64: jal         0x800A3DAC
    // 0x800A3E68: sb          $t1, 0x39($t2)
    MEM_B(0X39, ctx->r10) = ctx->r9;
    func_800A3DAC(rdram, ctx);
        goto after_1;
    // 0x800A3E68: sb          $t1, 0x39($t2)
    MEM_B(0X39, ctx->r10) = ctx->r9;
    after_1:
    // 0x800A3E6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A3E70: bne         $v0, $at, L_800A3EAC
    if (ctx->r2 != ctx->r1) {
        // 0x800A3E74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3EAC;
    }
    // 0x800A3E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3E78: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800A3E7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A3E80: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800A3E84: lw          $t3, 0x20($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X20);
    // 0x800A3E88: beq         $t3, $zero, L_800A3E9C
    if (ctx->r11 == 0) {
        // 0x800A3E8C: nop
    
            goto L_800A3E9C;
    }
    // 0x800A3E8C: nop

    // 0x800A3E90: lbu         $t4, 0x39($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X39);
    // 0x800A3E94: beq         $t4, $zero, L_800A3EAC
    if (ctx->r12 == 0) {
        // 0x800A3E98: nop
    
            goto L_800A3EAC;
    }
    // 0x800A3E98: nop

L_800A3E9C:
    // 0x800A3E9C: jal         0x800A3D78
    // 0x800A3EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3D78(rdram, ctx);
        goto after_2;
    // 0x800A3EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A3EA4: b           L_800A3EB8
    // 0x800A3EA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800A3EB8;
    // 0x800A3EA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800A3EAC:
    // 0x800A3EAC: jal         0x800A3BA8
    // 0x800A3EB0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800A3BA8(rdram, ctx);
        goto after_3;
    // 0x800A3EB0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x800A3EB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800A3EB8:
    // 0x800A3EB8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800A3EBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A3EC0: jr          $ra
    // 0x800A3EC4: nop

    return;
    // 0x800A3EC4: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FC8: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FC8);
    return;
    // 0x80087FCC: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_800BCF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCF28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCF2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCF30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BCF34: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BCF38: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
    // 0x800BCF3C: jal         0x800BCCC0
    // 0x800BCF40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BCF40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BCF44: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCF48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800BCF4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCF50: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BCF54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BCF58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800BCF5C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BCF60: addu        $t3, $a1, $v1
    ctx->r11 = ADD32(ctx->r5, ctx->r3);
    // 0x800BCF64: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800BCF68: bne         $t1, $zero, L_800BCF78
    if (ctx->r9 != 0) {
        // 0x800BCF6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BCF78;
    }
    // 0x800BCF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCF70: b           L_800BCF88
    // 0x800BCF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BCF88;
    // 0x800BCF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BCF78:
    // 0x800BCF78: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800BCF7C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800BCF80: srl         $t5, $t4, 1
    ctx->r13 = S32(U32(ctx->r12) >> 1);
    // 0x800BCF84: subu        $v0, $t2, $t5
    ctx->r2 = SUB32(ctx->r10, ctx->r13);
L_800BCF88:
    // 0x800BCF88: jr          $ra
    // 0x800BCF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BCF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chfiregen_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A08: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x80086A08);
    return;
    // 0x80086A0C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840A8: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840A8);
    return;
    // 0x800840AC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _bsvan_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084198: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084198);
    return;
    // 0x8008419C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_80800934_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080093C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800940: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800944: jal         0x8008CABC
    // 0x80800948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080094C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800950: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800954: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800958: beq         $v1, $at, L_80800970
    if (ctx->r3 == ctx->r1) {
        // 0x8080095C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800970;
    }
    // 0x8080095C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800960: beq         $v1, $at, L_808009D0
    if (ctx->r3 == ctx->r1) {
        // 0x80800964: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808009D0;
    }
    // 0x80800964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800968: b           L_808009E8
    // 0x8080096C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
        goto L_808009E8;
    // 0x8080096C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80800970:
    // 0x80800970: jal         0x8008AF24
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: jal         0x8008AED4
    // 0x80800980: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800980: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    after_2:
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800988: jal         0x8008B1BC
    // 0x8080098C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8080098C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_3:
    // 0x80800990: lui         $a2, 0x3F37
    ctx->r6 = S32(0X3F37 << 16);
    // 0x80800994: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: jal         0x8008B1D4
    // 0x808009A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808009A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A8: jal         0x8008B134
    // 0x808009AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808009AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808009B0: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x808009B4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808009B8: jal         0x8008B24C
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808009C0: jal         0x8008B064
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808009C8: b           L_808009E4
    // 0x808009CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_808009E4;
    // 0x808009CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808009D0:
    // 0x808009D0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808009D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808009D8: jal         0x8008CF1C
    // 0x808009DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_8;
    // 0x808009DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808009E0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808009E4:
    // 0x808009E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_808009E8:
    // 0x808009E8: sb          $v1, 0x15C($t6)
    MEM_B(0X15C, ctx->r14) = ctx->r3;
    // 0x808009EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009F8: jr          $ra
    // 0x808009FC: nop

    return;
    // 0x808009FC: nop

;}
RECOMP_FUNC void func_8010CC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CC10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010CC14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010CC18: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8010CC1C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8010CC20: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8010CC24: addiu       $s1, $s1, 0x6F68
    ctx->r17 = ADD32(ctx->r17, 0X6F68);
    // 0x8010CC28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010CC2C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8010CC30: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010CC34: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010CC38: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8010CC3C: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x8010CC40: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8010CC44: jal         0x800F5898
    // 0x8010CC48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x8010CC48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8010CC4C: blez        $v0, L_8010CCBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010CC50: addiu       $s2, $sp, 0x34
        ctx->r18 = ADD32(ctx->r29, 0X34);
            goto L_8010CCBC;
    }
    // 0x8010CC50: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
L_8010CC54:
    // 0x8010CC54: jal         0x800F6438
    // 0x8010CC58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x8010CC58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010CC5C: beq         $v0, $zero, L_8010CCA8
    if (ctx->r2 == 0) {
        // 0x8010CC60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010CCA8;
    }
    // 0x8010CC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CC64: jal         0x8010CBD0
    // 0x8010CC68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8010CBD0(rdram, ctx);
        goto after_2;
    // 0x8010CC68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x8010CC6C: add.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8010CC70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010CC74: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8010CC78: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CC7C: jal         0x800EFFB4
    // 0x8010CC80: nop

    func_800EFFB4(rdram, ctx);
        goto after_3;
    // 0x8010CC80: nop

    after_3:
    // 0x8010CC84: beq         $v0, $zero, L_8010CCA8
    if (ctx->r2 == 0) {
        // 0x8010CC88: nop
    
            goto L_8010CCA8;
    }
    // 0x8010CC88: nop

    // 0x8010CC8C: lw          $t6, 0x20($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X20);
    // 0x8010CC90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010CC94: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8010CC98: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x8010CC9C: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x8010CCA0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8010CCA4: sw          $t0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r8;
L_8010CCA8:
    // 0x8010CCA8: jal         0x800F5898
    // 0x8010CCAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_4;
    // 0x8010CCAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // 0x8010CCB0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010CCB4: bne         $at, $zero, L_8010CC54
    if (ctx->r1 != 0) {
        // 0x8010CCB8: nop
    
            goto L_8010CC54;
    }
    // 0x8010CCB8: nop

L_8010CCBC:
    // 0x8010CCBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010CCC0: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8010CCC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010CCC8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010CCCC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CCD0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8010CCD4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8010CCD8: jr          $ra
    // 0x8010CCDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8010CCDC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bskazmove_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834D8: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834D8);
    return;
    // 0x800834DC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800CBC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBC00: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CBC04: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CBC08: lw          $t7, -0x516C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X516C);
    // 0x800CBC0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBC10: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CBC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBC18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CBC1C: jal         0x800CB8F0
    // 0x800CBC20: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_800CB8F0(rdram, ctx);
        goto after_0;
    // 0x800CBC20: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800CBC24: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800CBC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBC30: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800CBC34: jr          $ra
    // 0x800CBC38: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800CBC38: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_80801108_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801108: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080110C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801110: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80801114: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80801118: jal         0x80106790
    // 0x8080111C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080111C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801120: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80801124: jal         0x80088658
    // 0x80801128: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _glhittableDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80801128: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8080112C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80801130: jal         0x80088650
    // 0x80801134: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _glhittableDll_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80801134: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_2:
    // 0x80801138: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8080113C: jal         0x80088638
    // 0x80801140: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _glhittableDll_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80801140: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x80801144: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80801148: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8080114C: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x80801150: srl         $t6, $v1, 22
    ctx->r14 = S32(U32(ctx->r3) >> 22);
    // 0x80801154: sltiu       $v1, $t6, 0x1
    ctx->r3 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80801158: beql        $v1, $zero, L_808011A0
    if (ctx->r3 == 0) {
        // 0x8080115C: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_808011A0;
    }
    goto skip_0;
    // 0x8080115C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80801160: lhu         $a0, 0x1A($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X1A);
    // 0x80801164: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x80801168: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8080116C: jal         0x800F70EC
    // 0x80801170: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    func_800F70EC(rdram, ctx);
        goto after_4;
    // 0x80801170: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_4:
    // 0x80801174: beq         $v0, $zero, L_8080118C
    if (ctx->r2 == 0) {
        // 0x80801178: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080118C;
    }
    // 0x80801178: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080117C: jal         0x800F6C1C
    // 0x80801180: nop

    func_800F6C1C(rdram, ctx);
        goto after_5;
    // 0x80801180: nop

    after_5:
    // 0x80801184: bnel        $v0, $zero, L_808011A0
    if (ctx->r2 != 0) {
        // 0x80801188: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_808011A0;
    }
    goto skip_1;
    // 0x80801188: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    skip_1:
L_8080118C:
    // 0x8080118C: jal         0x80088648
    // 0x80801190: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _glhittableDll_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80801190: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_6:
    // 0x80801194: bnel        $v0, $zero, L_808014A0
    if (ctx->r2 != 0) {
        // 0x80801198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014A0;
    }
    goto skip_2;
    // 0x80801198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080119C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_808011A0:
    // 0x808011A0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x808011A4: bnel        $t9, $zero, L_808011DC
    if (ctx->r25 != 0) {
        // 0x808011A8: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_808011DC;
    }
    goto skip_3;
    // 0x808011A8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x808011AC: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x808011B0: bne         $v0, $zero, L_808011C8
    if (ctx->r2 != 0) {
        // 0x808011B4: nop
    
            goto L_808011C8;
    }
    // 0x808011B4: nop

    // 0x808011B8: lw          $t0, 0x24($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X24);
    // 0x808011BC: srl         $t1, $t0, 22
    ctx->r9 = S32(U32(ctx->r8) >> 22);
    // 0x808011C0: bnel        $t1, $zero, L_808014A0
    if (ctx->r9 != 0) {
        // 0x808011C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014A0;
    }
    goto skip_4;
    // 0x808011C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_808011C8:
    // 0x808011C8: bgtzl       $v0, L_808011DC
    if (SIGNED(ctx->r2) > 0) {
        // 0x808011CC: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_808011DC;
    }
    goto skip_5;
    // 0x808011CC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x808011D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808011D4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x808011D8: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
L_808011DC:
    // 0x808011DC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x808011E0: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x808011E4: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x808011E8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x808011EC: mflo        $t8
    ctx->r24 = lo;
    // 0x808011F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808011F4: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x808011F8: lbu         $t5, 0x5C($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X5C);
    // 0x808011FC: bne         $t6, $zero, L_80801208
    if (ctx->r14 != 0) {
        // 0x80801200: nop
    
            goto L_80801208;
    }
    // 0x80801200: nop

    // 0x80801204: break       7
    do_break(2155876868);
L_80801208:
    // 0x80801208: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080120C: bne         $t6, $at, L_80801220
    if (ctx->r14 != ctx->r1) {
        // 0x80801210: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80801220;
    }
    // 0x80801210: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801214: bne         $t7, $at, L_80801220
    if (ctx->r15 != ctx->r1) {
        // 0x80801218: nop
    
            goto L_80801220;
    }
    // 0x80801218: nop

    // 0x8080121C: break       6
    do_break(2155876892);
L_80801220:
    // 0x80801220: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    tooie_enemy_hit_damage(rdram, ctx, 24);
    // 0x80801224: jal         0x800F0E28
    // 0x80801228: subu        $a1, $t5, $t8
    ctx->r5 = SUB32(ctx->r13, ctx->r24);
    func_800F0E28(rdram, ctx);
        goto after_7;
    // 0x80801228: subu        $a1, $t5, $t8
    ctx->r5 = SUB32(ctx->r13, ctx->r24);
    after_7:
    // 0x8080122C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801230: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801238: xori        $t9, $a3, 0x2
    ctx->r25 = ctx->r7 ^ 0X2;
    // 0x8080123C: sltiu       $v1, $t9, 0x1
    ctx->r3 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80801240: sb          $v0, 0x5C($a2)
    MEM_B(0X5C, ctx->r6) = ctx->r2;
    // 0x80801244: beq         $v1, $zero, L_80801258
    if (ctx->r3 == 0) {
        // 0x80801248: sw          $v1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r3;
            goto L_80801258;
    }
    // 0x80801248: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8080124C: lbu         $v1, 0x5C($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X5C);
    // 0x80801250: sltiu       $t1, $v1, 0x1
    ctx->r9 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80801254: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80801258:
    // 0x80801258: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8080125C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x80801260: beql        $t2, $zero, L_8080131C
    if (ctx->r10 == 0) {
        // 0x80801264: lbu         $v0, 0x5C($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X5C);
            goto L_8080131C;
    }
    goto skip_6;
    // 0x80801264: lbu         $v0, 0x5C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5C);
    skip_6:
    // 0x80801268: beq         $a3, $at, L_808012C8
    if (ctx->r7 == ctx->r1) {
        // 0x8080126C: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_808012C8;
    }
    // 0x8080126C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801270: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80801274: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801278: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8080127C: beql        $t3, $zero, L_8080131C
    if (ctx->r11 == 0) {
        // 0x80801280: lbu         $v0, 0x5C($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X5C);
            goto L_8080131C;
    }
    goto skip_7;
    // 0x80801280: lbu         $v0, 0x5C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5C);
    skip_7:
    // 0x80801284: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801288: jal         0x80109600
    // 0x8080128C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80109600(rdram, ctx);
        goto after_8;
    // 0x8080128C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_8:
    // 0x80801290: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80801294: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x80801298: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080129C: lw          $t7, 0x24($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X24);
    // 0x808012A0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808012A4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808012A8: srl         $t6, $t7, 22
    ctx->r14 = S32(U32(ctx->r15) >> 22);
    // 0x808012AC: bne         $t6, $at, L_808012C0
    if (ctx->r14 != ctx->r1) {
        // 0x808012B0: nop
    
            goto L_808012C0;
    }
    // 0x808012B0: nop

    // 0x808012B4: jal         0x800860D0
    // 0x808012B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808012B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_9:
    // 0x808012BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_808012C0:
    // 0x808012C0: b           L_80801318
    // 0x808012C4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
        goto L_80801318;
    // 0x808012C4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
L_808012C8:
    // 0x808012C8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808012CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808012D0: jal         0x80109600
    // 0x808012D4: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80109600(rdram, ctx);
        goto after_10;
    // 0x808012D4: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_10:
    // 0x808012D8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x808012DC: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x808012E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808012E4: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x808012E8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808012EC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808012F0: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x808012F4: bnel        $t9, $at, L_80801318
    if (ctx->r25 != ctx->r1) {
        // 0x808012F8: lw          $a3, 0x50($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X50);
            goto L_80801318;
    }
    goto skip_8;
    // 0x808012F8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    skip_8:
    // 0x808012FC: jal         0x800EC370
    // 0x80801300: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EC370(rdram, ctx);
        goto after_11;
    // 0x80801300: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_11:
    // 0x80801304: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801308: jal         0x80085F80
    // 0x8080130C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    _chfreezy_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x8080130C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x80801310: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801314: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
L_80801318:
    // 0x80801318: lbu         $v0, 0x5C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5C);
L_8080131C:
    // 0x8080131C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801320: beq         $v0, $zero, L_80801330
    if (ctx->r2 == 0) {
        // 0x80801324: nop
    
            goto L_80801330;
    }
    // 0x80801324: nop

    // 0x80801328: beql        $a3, $zero, L_80801464
    if (ctx->r7 == 0) {
        // 0x8080132C: lw          $t0, 0x4C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X4C);
            goto L_80801464;
    }
    goto skip_9;
    // 0x8080132C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    skip_9:
L_80801330:
    // 0x80801330: beq         $v0, $zero, L_8080134C
    if (ctx->r2 == 0) {
        // 0x80801334: addiu       $t1, $zero, 0x63
        ctx->r9 = ADD32(0, 0X63);
            goto L_8080134C;
    }
    // 0x80801334: addiu       $t1, $zero, 0x63
    ctx->r9 = ADD32(0, 0X63);
    // 0x80801338: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8080133C: xori        $t0, $a3, 0x2
    ctx->r8 = ctx->r7 ^ 0X2;
    // 0x80801340: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80801344: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80801348: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8080134C:
    // 0x8080134C: beql        $a3, $at, L_8080135C
    if (ctx->r7 == ctx->r1) {
        // 0x80801350: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8080135C;
    }
    goto skip_10;
    // 0x80801350: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    skip_10:
    // 0x80801354: sb          $t1, 0x5C($a2)
    MEM_B(0X5C, ctx->r6) = ctx->r9;
    // 0x80801358: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_8080135C:
    // 0x8080135C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80801360: beql        $t2, $zero, L_80801400
    if (ctx->r10 == 0) {
        // 0x80801364: lw          $a3, 0x50($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X50);
            goto L_80801400;
    }
    goto skip_11;
    // 0x80801364: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    skip_11:
    // 0x80801368: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8080136C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80801370: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801374: beql        $t3, $zero, L_80801400
    if (ctx->r11 == 0) {
        // 0x80801378: lw          $a3, 0x50($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X50);
            goto L_80801400;
    }
    goto skip_12;
    // 0x80801378: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    skip_12:
    // 0x8080137C: jal         0x8010A430
    // 0x80801380: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_8010A430(rdram, ctx);
        goto after_13;
    // 0x80801380: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_13:
    // 0x80801384: beql        $v0, $zero, L_80801400
    if (ctx->r2 == 0) {
        // 0x80801388: lw          $a3, 0x50($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X50);
            goto L_80801400;
    }
    goto skip_13;
    // 0x80801388: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    skip_13:
    // 0x8080138C: jal         0x800F54E4
    // 0x80801390: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x80801390: nop

    after_14:
    // 0x80801394: jal         0x800F5F24
    // 0x80801398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_15;
    // 0x80801398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x8080139C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x808013A0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808013A4: addiu       $a0, $a0, -0x710C
    ctx->r4 = ADD32(ctx->r4, -0X710C);
    // 0x808013A8: jal         0x800EB860
    // 0x808013AC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EB860(rdram, ctx);
        goto after_16;
    // 0x808013AC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_16:
    // 0x808013B0: jal         0x800EC708
    // 0x808013B4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800EC708(rdram, ctx);
        goto after_17;
    // 0x808013B4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_17:
    // 0x808013B8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x808013BC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x808013C0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808013C4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808013C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808013CC: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x808013D0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808013D4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x808013D8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x808013DC: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x808013E0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x808013E4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808013E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808013EC: jal         0x80086D50
    // 0x808013F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x808013F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_18:
    // 0x808013F4: jal         0x800EB874
    // 0x808013F8: nop

    func_800EB874(rdram, ctx);
        goto after_19;
    // 0x808013F8: nop

    after_19:
    // 0x808013FC: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
L_80801400:
    // 0x80801400: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801404: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80801408: beq         $a3, $zero, L_80801434
    if (ctx->r7 == 0) {
        // 0x8080140C: lw          $a1, 0x64($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X64);
            goto L_80801434;
    }
    // 0x8080140C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80801410: beq         $a3, $at, L_80801444
    if (ctx->r7 == ctx->r1) {
        // 0x80801414: lw          $t8, 0x5C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X5C);
            goto L_80801444;
    }
    // 0x80801414: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80801418: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080141C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80801420: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80801424: bne         $t6, $zero, L_80801458
    if (ctx->r14 != 0) {
        // 0x80801428: nop
    
            goto L_80801458;
    }
    // 0x80801428: nop

    // 0x8080142C: b           L_80801464
    // 0x80801430: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
        goto L_80801464;
    // 0x80801430: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_80801434:
    // 0x80801434: jal         0x80800EF0
    // 0x80801438: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    func_80800EF0_sucoasterfly(rdram, ctx);
        goto after_20;
    // 0x80801438: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_20:
    // 0x8080143C: b           L_80801464
    // 0x80801440: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
        goto L_80801464;
    // 0x80801440: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_80801444:
    // 0x80801444: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80801448: jal         0x80800F44
    // 0x8080144C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_80800F44_sucoasterfly(rdram, ctx);
        goto after_21;
    // 0x8080144C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_21:
    // 0x80801450: b           L_80801464
    // 0x80801454: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
        goto L_80801464;
    // 0x80801454: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_80801458:
    // 0x80801458: jal         0x80800FA8
    // 0x8080145C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_80800FA8_sucoasterfly(rdram, ctx);
        goto after_22;
    // 0x8080145C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_22:
    // 0x80801460: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
L_80801464:
    // 0x80801464: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80801468: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080146C: beq         $t0, $zero, L_8080149C
    if (ctx->r8 == 0) {
        // 0x80801470: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_8080149C;
    }
    // 0x80801470: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80801474: lw          $a1, 0x70($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X70);
    // 0x80801478: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3210, 0X2294) << 16);
    // 0x8080147C: addiu       $a3, $a3, 0x2294
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3210, 0X2294));
    // 0x80801480: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x80801484: jal         0x8010D930
    // 0x80801488: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_8010D930(rdram, ctx);
        goto after_23;
    // 0x80801488: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_23:
    // 0x8080148C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801490: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801494: jal         0x80089BF8
    // 0x80801498: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_24;
    // 0x80801498: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_24:
L_8080149C:
    // 0x8080149C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014A0:
    // 0x808014A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808014A4: jr          $ra
    // 0x808014A8: nop

    return;
    // 0x808014A8: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084398: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084398);
    return;
    // 0x8008439C: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void bs_setState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E5C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009E5CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009E5D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009E5D4: beq         $a1, $zero, L_8009E660
    if (ctx->r5 == 0) {
        // 0x8009E5D8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009E660;
    }
    // 0x8009E5D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009E5DC: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E5E0: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
    // 0x8009E5E4: lw          $t7, 0x120($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X120);
    // 0x8009E5E8: jal         0x8009CAAC
    // 0x8009E5EC: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    func_8009CAAC(rdram, ctx);
        goto after_0;
    // 0x8009E5EC: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_0:
    // 0x8009E5F0: beql        $v0, $zero, L_8009E614
    if (ctx->r2 == 0) {
        // 0x8009E5F4: lw          $v0, 0x120($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X120);
            goto L_8009E614;
    }
    goto skip_0;
    // 0x8009E5F4: lw          $v0, 0x120($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X120);
    skip_0:
    // 0x8009E5F8: lw          $t8, 0x120($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X120);
    // 0x8009E5FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E600: jal         0x8009CAAC
    // 0x8009E604: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    func_8009CAAC(rdram, ctx);
        goto after_1;
    // 0x8009E604: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    after_1:
    // 0x8009E608: jalr        $v0
    // 0x8009E60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8009E60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009E610: lw          $v0, 0x120($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X120);
L_8009E614:
    // 0x8009E614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E618: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8009E61C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009E620: lw          $v0, 0x120($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X120);
    // 0x8009E624: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8009E628: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009E62C: lw          $t1, 0x120($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X120);
    // 0x8009E630: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    // 0x8009E634: lw          $t2, 0x120($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X120);
    // 0x8009E638: jal         0x8009CAF8
    // 0x8009E63C: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    func_8009CAF8(rdram, ctx);
        goto after_3;
    // 0x8009E63C: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    after_3:
    // 0x8009E640: beql        $v0, $zero, L_8009E664
    if (ctx->r2 == 0) {
        // 0x8009E644: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009E664;
    }
    goto skip_1;
    // 0x8009E644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8009E648: lw          $t3, 0x120($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X120);
    // 0x8009E64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009E650: jal         0x8009CAF8
    // 0x8009E654: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    func_8009CAF8(rdram, ctx);
        goto after_4;
    // 0x8009E654: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    after_4:
    // 0x8009E658: jalr        $v0
    // 0x8009E65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x8009E65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8009E660:
    // 0x8009E660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009E664:
    // 0x8009E664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009E668: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009E66C: jr          $ra
    // 0x8009E670: nop

    return;
    // 0x8009E670: nop

;}
RECOMP_FUNC void _chlakemonster_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CE8: syscall     444
    recomp_syscall_handler(rdram, ctx, 0x80086CE8);
    return;
    // 0x80086CEC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bawasher_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: jal         0x800F53D0
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C8: lw          $v1, 0x14C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14C);
    // 0x808000CC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: addiu       $a0, $v1, 0x10
    ctx->r4 = ADD32(ctx->r3, 0X10);
    // 0x808000D4: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    // 0x808000D8: jal         0x80087298
    // 0x808000DC: addiu       $a2, $v1, 0x28
    ctx->r6 = ADD32(ctx->r3, 0X28);
    _chlaundry_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000DC: addiu       $a2, $v1, 0x28
    ctx->r6 = ADD32(ctx->r3, 0X28);
    after_1:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800780_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800780: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800784: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800788: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080078C: jal         0x8008CABC
    // 0x80800790: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800790: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800794: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800798: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8080079C: jal         0x800834B0
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: jal         0x800852F0
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B4: jal         0x80085300
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_3;
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808007BC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x808007C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007C8: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808007CC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808007D0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808007D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808007D8: lui         $a3, 0xC47A
    ctx->r7 = S32(0XC47A << 16);
    // 0x808007DC: jal         0x800F10B4
    // 0x808007E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808007E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808007E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007E8: jal         0x8009BCC4
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_5;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808007F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(244, 0XA90) << 16);
    // 0x808007F4: lwc1        $f6, 0xA90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XA90));
    // 0x808007F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007FC: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800800: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800804: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800808: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080080C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800810: jal         0x800F10B4
    // 0x80800814: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800814: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80800818: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080081C: jal         0x8008B1BC
    // 0x80800820: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80800820: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800824: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800828: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x8080082C: jal         0x8008B348
    // 0x80800830: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x80800830: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80800834: beq         $v0, $zero, L_80800860
    if (ctx->r2 == 0) {
        // 0x80800838: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(244, 0XA94) << 16);
            goto L_80800860;
    }
    // 0x80800838: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(244, 0XA94) << 16);
    // 0x8080083C: lwc1        $f12, 0xA94($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XA94));
    // 0x80800840: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(244, 0XA98) << 16);
    // 0x80800844: jal         0x800DC178
    // 0x80800848: lwc1        $f14, 0xA98($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XA98));
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800848: lwc1        $f14, 0xA98($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XA98));
    after_9:
    // 0x8080084C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800858: jal         0x8009DF94
    // 0x8080085C: addiu       $a3, $zero, 0x2328
    ctx->r7 = ADD32(0, 0X2328);
    func_8009DF94(rdram, ctx);
        goto after_10;
    // 0x8080085C: addiu       $a3, $zero, 0x2328
    ctx->r7 = ADD32(0, 0X2328);
    after_10:
L_80800860:
    // 0x80800860: lui         $a1, 0x3F38
    ctx->r5 = S32(0X3F38 << 16);
    // 0x80800864: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800868: jal         0x8008B348
    // 0x8080086C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x8080086C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x80800870: beq         $v0, $zero, L_8080089C
    if (ctx->r2 == 0) {
        // 0x80800874: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(244, 0XA9C) << 16);
            goto L_8080089C;
    }
    // 0x80800874: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(244, 0XA9C) << 16);
    // 0x80800878: lwc1        $f12, 0xA9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XA9C));
    // 0x8080087C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(244, 0XAA0) << 16);
    // 0x80800880: jal         0x800DC178
    // 0x80800884: lwc1        $f14, 0xAA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XAA0));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800884: lwc1        $f14, 0xAA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XAA0));
    after_12:
    // 0x80800888: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: addiu       $a1, $zero, 0x4431
    ctx->r5 = ADD32(0, 0X4431);
    // 0x80800894: jal         0x8009DF18
    // 0x80800898: addiu       $a3, $zero, 0x4268
    ctx->r7 = ADD32(0, 0X4268);
    func_8009DF18(rdram, ctx);
        goto after_13;
    // 0x80800898: addiu       $a3, $zero, 0x4268
    ctx->r7 = ADD32(0, 0X4268);
    after_13:
L_8080089C:
    // 0x8080089C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(244, 0XAA4) << 16);
    // 0x808008A0: lwc1        $f10, 0xAA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(244, 0XAA4));
    // 0x808008A4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808008B0: nop

    // 0x808008B4: bc1fl       L_808008D4
    if (!c1cs) {
        // 0x808008B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008D4;
    }
    goto skip_0;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808008BC: jal         0x80091A30
    // 0x808008C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_14;
    // 0x808008C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_14:
    // 0x808008C4: beq         $v0, $zero, L_808008D0
    if (ctx->r2 == 0) {
        // 0x808008C8: addiu       $t6, $zero, 0xDF
        ctx->r14 = ADD32(0, 0XDF);
            goto L_808008D0;
    }
    // 0x808008C8: addiu       $t6, $zero, 0xDF
    ctx->r14 = ADD32(0, 0XDF);
    // 0x808008CC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_808008D0:
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008D4:
    // 0x808008D4: jal         0x8008DF8C
    // 0x808008D8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8008DF8C(rdram, ctx);
        goto after_15;
    // 0x808008D8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_15:
    // 0x808008DC: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x808008E0: addiu       $t7, $zero, 0xDF
        ctx->r15 = ADD32(0, 0XDF);
            goto L_808008E8;
    }
    // 0x808008E0: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
    // 0x808008E4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_808008E8:
    // 0x808008E8: jal         0x80097FB8
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_16;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808008F0: beq         $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x808008F4: addiu       $t8, $zero, 0xC4
        ctx->r24 = ADD32(0, 0XC4);
            goto L_808008FC;
    }
    // 0x808008F4: addiu       $t8, $zero, 0xC4
    ctx->r24 = ADD32(0, 0XC4);
    // 0x808008F8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_808008FC:
    // 0x808008FC: jal         0x8008E35C
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_17;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800904: beq         $v0, $zero, L_80800914
    if (ctx->r2 == 0) {
        // 0x80800908: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800914;
    }
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080090C: addiu       $t9, $zero, 0x160
    ctx->r25 = ADD32(0, 0X160);
    // 0x80800910: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_80800914:
    // 0x80800914: jal         0x8009E5C8
    // 0x80800918: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80800918: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x8080091C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800920: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800924: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void suegg_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C3C: jal         0x800EE7F8
    // 0x80800C40: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800C40: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    after_0:
    // 0x80800C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C4C: jr          $ra
    // 0x80800C50: nop

    return;
    // 0x80800C50: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F28: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80800F2C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x80800F30: beql        $t6, $zero, L_80800F54
    if (ctx->r14 == 0) {
        // 0x80800F34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F54;
    }
    goto skip_0;
    // 0x80800F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800F38: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x80800F3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F40: beql        $t7, $at, L_80800F54
    if (ctx->r15 == ctx->r1) {
        // 0x80800F44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F54;
    }
    goto skip_1;
    // 0x80800F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800F48: jal         0x80800D38
    // 0x80800F4C: nop

    bafpctrl_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800F4C: nop

    after_0:
    // 0x80800F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F54:
    // 0x80800F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F58: jr          $ra
    // 0x80800F5C: nop

    return;
    // 0x80800F5C: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E40: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E40);
    return;
    // 0x80087E44: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void basnowball_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: lw          $t7, 0x110($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X110);
    // 0x808005D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808005D8: jr          $ra
    // 0x808005DC: sb          $t6, 0x2C($t7)
    MEM_B(0X2C, ctx->r15) = ctx->r14;
    return;
    // 0x808005DC: sb          $t6, 0x2C($t7)
    MEM_B(0X2C, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void bamovespline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808002C4: jr          $ra
    // 0x808002C8: lbu         $v0, 0x91($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X91);
    return;
    // 0x808002C8: lbu         $v0, 0x91($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X91);
;}
RECOMP_FUNC void sujiggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: jr          $ra
    // 0x80800110: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80800110: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
;}
RECOMP_FUNC void func_80800F10_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800F14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F20: jal         0x8008CABC
    // 0x80800F24: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800F24: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x80800F28: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800F2C: jal         0x80084C20
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800F34: jal         0x8009DDDC
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009DDDC(rdram, ctx);
        goto after_2;
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F3C: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800F40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F44: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800F48: beq         $v0, $at, L_80800F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F4C: lui         $a1, 0x3F30
        ctx->r5 = S32(0X3F30 << 16);
            goto L_80800F6C;
    }
    // 0x80800F4C: lui         $a1, 0x3F30
    ctx->r5 = S32(0X3F30 << 16);
    // 0x80800F50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F54: beq         $v0, $at, L_80800F8C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F58: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F8C;
    }
    // 0x80800F58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F5C: beq         $v0, $at, L_80801090
    if (ctx->r2 == ctx->r1) {
        // 0x80800F60: nop
    
            goto L_80801090;
    }
    // 0x80800F60: nop

    // 0x80800F64: b           L_8080111C
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080111C;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F6C:
    // 0x80800F6C: jal         0x8008B348
    // 0x80800F70: ori         $a1, $a1, 0xC49C
    ctx->r5 = ctx->r5 | 0XC49C;
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800F70: ori         $a1, $a1, 0xC49C
    ctx->r5 = ctx->r5 | 0XC49C;
    after_3:
    // 0x80800F74: beq         $v0, $zero, L_80801118
    if (ctx->r2 == 0) {
        // 0x80800F78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801118;
    }
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F7C: jal         0x80800A24
    // 0x80800F80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A24_bsbfly(rdram, ctx);
        goto after_4;
    // 0x80800F80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800F84: b           L_8080111C
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080111C;
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F8C:
    // 0x80800F8C: jal         0x80800C38
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C38_bsbfly(rdram, ctx);
        goto after_5;
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F94: jal         0x8008B324
    // 0x80800F98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800F98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x80800F9C: beq         $v0, $zero, L_80800FD0
    if (ctx->r2 == 0) {
        // 0x80800FA0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800FD0;
    }
    // 0x80800FA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800FA4: jal         0x8008AED4
    // 0x80800FA8: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x80800FA8: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_7:
    // 0x80800FAC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800FB0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800FB4: jal         0x8008B1BC
    // 0x80800FB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x80800FB8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x80800FBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800FC0: jal         0x8008B134
    // 0x80800FC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x80800FC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800FC8: jal         0x8008B064
    // 0x80800FCC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_start(rdram, ctx);
        goto after_10;
    // 0x80800FCC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_10:
L_80800FD0:
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD4: jal         0x8009C128
    // 0x80800FD8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_11;
    // 0x80800FD8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80800FDC: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800FE0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800FE4: jal         0x800EF3DC
    // 0x80800FE8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF3DC(rdram, ctx);
        goto after_12;
    // 0x80800FE8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_12:
    // 0x80800FEC: jal         0x800EEFD4
    // 0x80800FF0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EEFD4(rdram, ctx);
        goto after_13;
    // 0x80800FF0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x80800FF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D0C) << 16);
    // 0x80800FF8: lwc1        $f4, 0x1D0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D0C));
    // 0x80800FFC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801000: lui         $a2, 0x4B74
    ctx->r6 = S32(0X4B74 << 16);
    // 0x80801004: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80801008: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080100C: ori         $a2, $a2, 0x2400
    ctx->r6 = ctx->r6 | 0X2400;
    // 0x80801010: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801014: jal         0x800F10B4
    // 0x80801018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80801018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x8080101C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801020: jal         0x80084BF8
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801028: jal         0x800EEFD4
    // 0x8080102C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EEFD4(rdram, ctx);
        goto after_16;
    // 0x8080102C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_16:
    // 0x80801030: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D10) << 16);
    // 0x80801034: lwc1        $f6, 0x1D10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D10));
    // 0x80801038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080103C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80801040: nop

    // 0x80801044: bc1f        L_80801074
    if (!c1cs) {
        // 0x80801048: nop
    
            goto L_80801074;
    }
    // 0x80801048: nop

    // 0x8080104C: jal         0x800919F4
    // 0x80801050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_17;
    // 0x80801050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_17:
    // 0x80801054: beq         $v0, $zero, L_80801070
    if (ctx->r2 == 0) {
        // 0x80801058: addiu       $t6, $zero, 0x57
        ctx->r14 = ADD32(0, 0X57);
            goto L_80801070;
    }
    // 0x80801058: addiu       $t6, $zero, 0x57
    ctx->r14 = ADD32(0, 0X57);
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: jal         0x80800A24
    // 0x80801064: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800A24_bsbfly(rdram, ctx);
        goto after_18;
    // 0x80801064: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x80801068: b           L_80801074
    // 0x8080106C: nop

        goto L_80801074;
    // 0x8080106C: nop

L_80801070:
    // 0x80801070: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80801074:
    // 0x80801074: jal         0x80800000
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbfly(rdram, ctx);
        goto after_19;
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801080: jal         0x80800D80
    // 0x80801084: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800D80_bsbfly(rdram, ctx);
        goto after_20;
    // 0x80801084: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_20:
    // 0x80801088: b           L_80801118
    // 0x8080108C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
        goto L_80801118;
    // 0x8080108C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_80801090:
    // 0x80801090: jal         0x80800C38
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C38_bsbfly(rdram, ctx);
        goto after_21;
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080109C: jal         0x80091A30
    // 0x808010A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_released(rdram, ctx);
        goto after_22;
    // 0x808010A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_22:
    // 0x808010A4: beq         $v0, $zero, L_808010B8
    if (ctx->r2 == 0) {
        // 0x808010A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010B8;
    }
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010AC: addiu       $t7, $zero, 0x57
    ctx->r15 = ADD32(0, 0X57);
    // 0x808010B0: b           L_80801100
    // 0x808010B4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
        goto L_80801100;
    // 0x808010B4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_808010B8:
    // 0x808010B8: jal         0x800852F0
    // 0x808010BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_23;
    // 0x808010BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x808010C0: beq         $v0, $zero, L_80801100
    if (ctx->r2 == 0) {
        // 0x808010C4: nop
    
            goto L_80801100;
    }
    // 0x808010C4: nop

    // 0x808010C8: jal         0x80084C28
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_12(rdram, ctx);
        goto after_24;
    // 0x808010CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808010D0: beq         $v0, $zero, L_808010FC
    if (ctx->r2 == 0) {
        // 0x808010D4: addiu       $t8, $zero, 0x57
        ctx->r24 = ADD32(0, 0X57);
            goto L_808010FC;
    }
    // 0x808010D4: addiu       $t8, $zero, 0x57
    ctx->r24 = ADD32(0, 0X57);
    // 0x808010D8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x808010DC: jal         0x80085948
    // 0x808010E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x808010E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808010EC: jal         0x80085338
    // 0x808010F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_26;
    // 0x808010F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_26:
    // 0x808010F4: b           L_80801100
    // 0x808010F8: nop

        goto L_80801100;
    // 0x808010F8: nop

L_808010FC:
    // 0x808010FC: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_80801100:
    // 0x80801100: jal         0x80800000
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbfly(rdram, ctx);
        goto after_27;
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80801108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080110C: jal         0x80800D80
    // 0x80801110: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800D80_bsbfly(rdram, ctx);
        goto after_28;
    // 0x80801110: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_28:
    // 0x80801114: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_80801118:
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080111C:
    // 0x8080111C: jal         0x8009E5C8
    // 0x80801120: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_29;
    // 0x80801120: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_29:
    // 0x80801124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801128: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080112C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801130: jr          $ra
    // 0x80801134: nop

    return;
    // 0x80801134: nop

;}
RECOMP_FUNC void func_80800D58_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D64: jal         0x80101870
    // 0x80800D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D70: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800D74: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800D78: bgezl       $t8, L_80800DAC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800D7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DAC;
    }
    goto skip_0;
    // 0x80800D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D80: jal         0x80100094
    // 0x80800D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800D88: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80800D8C: beql        $t9, $zero, L_80800DAC
    if (ctx->r25 == 0) {
        // 0x80800D90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DAC;
    }
    goto skip_1;
    // 0x80800D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800D94: jal         0x80106790
    // 0x80800D98: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800D98: lw          $a0, 0x30($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X30);
    after_2:
    // 0x80800D9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DA0: jal         0x8010A764
    // 0x80800DA4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010A764(rdram, ctx);
        goto after_3;
    // 0x80800DA4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DAC:
    // 0x80800DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: nop

    return;
    // 0x80800DB4: nop

;}
RECOMP_FUNC void func_8009055C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009055C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090568: jal         0x800F54E4
    // 0x8009056C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009056C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80090570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090574: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80090578: jal         0x800F7C58
    // 0x8009057C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7C58(rdram, ctx);
        goto after_1;
    // 0x8009057C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80090580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090588: jr          $ra
    // 0x8009058C: nop

    return;
    // 0x8009058C: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089528: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089528);
    return;
    // 0x8008952C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void bsrest_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800500: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800504: jal         0x80084690
    // 0x80800508: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    _badata_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800508: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8080050C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800510: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800514: jal         0x8080020C
    // 0x80800518: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    static_344_8080020C(rdram, ctx);
        goto after_1;
    // 0x80800518: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void gczoomboxdata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800004: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800008: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8080000C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2686, 0XAA8) << 16);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: addiu       $t7, $t7, 0xAA8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2686, 0XAA8));
    // 0x80800018: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080001C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800020: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: beql        $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800248;
    }
    goto skip_0;
    // 0x8080002C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800030: lbu         $t8, 0x8($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X8);
    // 0x80800034: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800038: beql        $t8, $zero, L_80800248
    if (ctx->r24 == 0) {
        // 0x8080003C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800248;
    }
    goto skip_1;
    // 0x8080003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800044: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800048: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080004C: nop

    // 0x80800050: bc1fl       L_80800080
    if (!c1cs) {
        // 0x80800054: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800080;
    }
    goto skip_2;
    // 0x80800054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_2:
    // 0x80800058: jal         0x800FCCD4
    // 0x8080005C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_800FCCD4(rdram, ctx);
        goto after_0;
    // 0x8080005C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_0:
    // 0x80800060: bnel        $v0, $zero, L_80800248
    if (ctx->r2 != 0) {
        // 0x80800064: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800248;
    }
    goto skip_3;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800068: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8080006C: jal         0x800FC6B0
    // 0x80800070: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    func_800FC6B0(rdram, ctx);
        goto after_1;
    // 0x80800070: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    after_1:
    // 0x80800074: b           L_80800248
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800248;
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080007C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800080:
    // 0x80800080: jal         0x800DC214
    // 0x80800084: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    func_800DC214(rdram, ctx);
        goto after_2;
    // 0x80800084: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    after_2:
    // 0x80800088: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8080008C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80800090: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800094: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x80800098: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8080009C: beql        $a2, $zero, L_80800080
    if (ctx->r6 == 0) {
        // 0x808000A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800080;
    }
    goto skip_4;
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_4:
    // 0x808000A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2686, 0X3B0) << 16);
    // 0x808000A8: lwc1        $f16, 0x3B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2686, 0X3B0));
    // 0x808000AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2686, 0X3B4) << 16);
    // 0x808000B0: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808000B4: lwc1        $f8, 0x3B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2686, 0X3B4));
    // 0x808000B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808000BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000C0: sub.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x808000C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2686, 0X3B8) << 16);
    // 0x808000CC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808000D0: nop

    // 0x808000D4: bc1fl       L_808000E8
    if (!c1cs) {
        // 0x808000D8: swc1        $f0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
            goto L_808000E8;
    }
    goto skip_5;
    // 0x808000D8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    skip_5:
    // 0x808000DC: b           L_808000E8
    // 0x808000E0: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
        goto L_808000E8;
    // 0x808000E0: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x808000E4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_808000E8:
    // 0x808000E8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808000EC: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x808000F0: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x808000F4: nop

    // 0x808000F8: bc1fl       L_8080010C
    if (!c1cs) {
        // 0x808000FC: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8080010C;
    }
    goto skip_6;
    // 0x808000FC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_6:
    // 0x80800100: lwc1        $f18, 0x3B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2686, 0X3B8));
    // 0x80800104: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80800108: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8080010C:
    // 0x8080010C: nop

    // 0x80800110: bc1fl       L_80800124
    if (!c1cs) {
        // 0x80800114: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_80800124;
    }
    goto skip_7;
    // 0x80800114: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    skip_7:
    // 0x80800118: b           L_80800124
    // 0x8080011C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80800124;
    // 0x8080011C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800120: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_80800124:
    // 0x80800124: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80800128: nop

    // 0x8080012C: bc1tl       L_8080013C
    if (c1cs) {
        // 0x80800130: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_8080013C;
    }
    goto skip_8;
    // 0x80800130: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    skip_8:
    // 0x80800134: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80800138: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
L_8080013C:
    // 0x8080013C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800140: jal         0x800C2E04
    // 0x80800144: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_800C2E04(rdram, ctx);
        goto after_3;
    // 0x80800144: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80800148: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8080014C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80800150: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800154: beq         $v0, $zero, L_80800244
    if (ctx->r2 == 0) {
        // 0x80800158: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80800244;
    }
    // 0x80800158: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8080015C: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80800160: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80800164: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80800168: lh          $a1, 0x0($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X0);
    // 0x8080016C: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x80800170: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800174: sb          $a0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r4;
    // 0x80800178: jal         0x800C301C
    // 0x8080017C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800C301C(rdram, ctx);
        goto after_4;
    // 0x8080017C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800180: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80800184: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800188: addiu       $v0, $a2, -0x1770
    ctx->r2 = ADD32(ctx->r6, -0X1770);
    // 0x8080018C: bgezl       $v0, L_808001A0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800190: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001A0;
    }
    goto skip_9;
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    skip_9:
    // 0x80800194: b           L_808001A0
    // 0x80800198: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_808001A0;
    // 0x80800198: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808001A0:
    // 0x808001A0: bgez        $a2, L_808001B0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x808001A4: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_808001B0;
    }
    // 0x808001A4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x808001A8: b           L_808001B4
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808001B4;
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808001B0:
    // 0x808001B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808001B4:
    // 0x808001B4: jal         0x800DC214
    // 0x808001B8: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_800DC214(rdram, ctx);
        goto after_5;
    // 0x808001B8: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x808001BC: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x808001C0: jal         0x800C3058
    // 0x808001C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800C3058(rdram, ctx);
        goto after_6;
    // 0x808001C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x808001C8: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001CC: jal         0x800DC264
    // 0x808001D0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_800DC264(rdram, ctx);
        goto after_7;
    // 0x808001D0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_7:
    // 0x808001D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001D8: jal         0x800C31DC
    // 0x808001DC: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    func_800C31DC(rdram, ctx);
        goto after_8;
    // 0x808001DC: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    after_8:
    // 0x808001E0: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x808001E4: jal         0x800C330C
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C330C(rdram, ctx);
        goto after_9;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808001EC: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x808001F0: jal         0x800C3418
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_10;
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808001F8: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x808001FC: jal         0x800C34CC
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C34CC(rdram, ctx);
        goto after_11;
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800204: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80800208: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8080020C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80800210: jal         0x800C42E0
    // 0x80800214: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    func_800C42E0(rdram, ctx);
        goto after_12;
    // 0x80800214: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    after_12:
    // 0x80800218: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x8080021C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2686, 0X3BC) << 16);
            goto L_8080023C;
    }
    // 0x8080021C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2686, 0X3BC) << 16);
    // 0x80800220: lwc1        $f0, 0x3BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2686, 0X3BC));
    // 0x80800224: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x80800228: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8080022C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800230: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800234: jal         0x800C3A40
    // 0x80800238: nop

    func_800C3A40(rdram, ctx);
        goto after_13;
    // 0x80800238: nop

    after_13:
L_8080023C:
    // 0x8080023C: jal         0x800C3BDC
    // 0x80800240: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    func_800C3BDC(rdram, ctx);
        goto after_14;
    // 0x80800240: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    after_14:
L_80800244:
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800248:
    // 0x80800248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void func_80104D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104D80: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80104D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80104D88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80104D8C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80104D90: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80104D94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80104D98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80104D9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80104DA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104DA4: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80104DA8: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80104DAC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80104DB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80104DB4: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x80104DB8: nop

    // 0x80104DBC: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80104DC0: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80104DC4: beql        $v0, $a0, L_80104E08
    if (ctx->r2 == ctx->r4) {
        // 0x80104DC8: add.s       $f16, $f18, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
            goto L_80104E08;
    }
    goto skip_0;
    // 0x80104DC8: add.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
    skip_0:
    // 0x80104DCC: add.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
L_80104DD0:
    // 0x80104DD0: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80104DD4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80104DD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104DDC: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80104DE0: mtc1        $t6, $f14
    ctx->f14.u32l = ctx->r14;
    // 0x80104DE4: nop

    // 0x80104DE8: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80104DEC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80104DF0: nop

    // 0x80104DF4: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80104DF8: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80104DFC: bnel        $v0, $a0, L_80104DD0
    if (ctx->r2 != ctx->r4) {
        // 0x80104E00: add.s       $f16, $f18, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
            goto L_80104DD0;
    }
    goto skip_1;
    // 0x80104E00: add.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
    skip_1:
    // 0x80104E04: add.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
L_80104E08:
    // 0x80104E08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104E0C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80104E10: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80104E14: nop

    // 0x80104E18: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80104E1C: jr          $ra
    // 0x80104E20: nop

    return;
    // 0x80104E20: nop

;}
RECOMP_FUNC void chfirefx_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800858: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080085C: jal         0x80100094
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800864: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80800868: sh          $t6, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r14;
    // 0x8080086C: lh          $t7, 0x22($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X22);
    // 0x80800870: sh          $t7, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r15;
    // 0x80800874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080087C: jr          $ra
    // 0x80800880: nop

    return;
    // 0x80800880: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088860: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088860);
    return;
    // 0x80088864: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_80800D28_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800D2C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80800D30: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80800D34: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80800D38: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80800D3C: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80800D40: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80800D44: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80800D48: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80800D4C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80800D50: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80800D54: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80800D58: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80800D5C: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80800D60: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80800D64: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80800D68: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80800D6C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80800D70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800D74: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800D78: blez        $t6, L_80800F0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800D7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800F0C;
    }
    // 0x80800D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FC8) << 16);
    // 0x80800D84: lwc1        $f30, 0x2FC8($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FC8));
    // 0x80800D88: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800D8C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800D90: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800D94: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800D98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FCC) << 16);
    // 0x80800D9C: lwc1        $f24, 0x2FCC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FCC));
    // 0x80800DA0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800DA4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800DA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DAC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800DB0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800DB4: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80800DB8: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x80800DBC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80800DC0: addiu       $s5, $v0, 0x1
    ctx->r21 = ADD32(ctx->r2, 0X1);
L_80800DC4:
    // 0x80800DC4: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x80800DC8: lh          $t7, 0x256($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X256);
    // 0x80800DCC: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80800DD0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800DD4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80800DD8: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x80800DDC: lh          $a1, 0x1DC($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X1DC);
    // 0x80800DE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800DE4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800DE8: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80800DEC: sll         $t9, $a3, 14
    ctx->r25 = S32(ctx->r7 << 14);
    // 0x80800DF0: srl         $a3, $t9, 31
    ctx->r7 = S32(U32(ctx->r25) >> 31);
    // 0x80800DF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800DF8: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800DFC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800E00: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80800E04: jal         0x80087B08
    // 0x80800E08: nop

    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800E08: nop

    after_0:
    // 0x80800E0C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800E10: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80800E14: jal         0x80087C28
    // 0x80800E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gczoombox_entrypoint_41(rdram, ctx);
        goto after_1;
    // 0x80800E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800E1C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80800E20: jal         0x80087C30
    // 0x80800E24: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_42(rdram, ctx);
        goto after_2;
    // 0x80800E24: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80800E28: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800E2C: lh          $a1, 0x254($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X254);
    // 0x80800E30: lw          $a2, 0x258($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X258);
    // 0x80800E34: lw          $a3, 0x25C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X25C);
    // 0x80800E38: jal         0x80087BB0
    // 0x80800E3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _gczoombox_entrypoint_26(rdram, ctx);
        goto after_3;
    // 0x80800E3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800E40: lbu         $a1, 0x1D($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1D);
    // 0x80800E44: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800E48: srl         $t1, $a1, 7
    ctx->r9 = S32(U32(ctx->r5) >> 7);
    // 0x80800E4C: jal         0x80087C40
    // 0x80800E50: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _gczoombox_entrypoint_44(rdram, ctx);
        goto after_4;
    // 0x80800E50: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_4:
    // 0x80800E54: lh          $a1, 0x238($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X238);
    // 0x80800E58: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800E5C: sltiu       $t2, $a1, 0x1
    ctx->r10 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80800E60: jal         0x80087B98
    // 0x80800E64: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _gczoombox_entrypoint_23(rdram, ctx);
        goto after_5;
    // 0x80800E64: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x80800E68: lw          $t3, 0x1C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1C);
    // 0x80800E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800E70: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800E74: sll         $t5, $t3, 10
    ctx->r13 = S32(ctx->r11 << 10);
    // 0x80800E78: bgezl       $t5, L_80800E9C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800E7C: lbu         $t6, 0x1C($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X1C);
            goto L_80800E9C;
    }
    goto skip_0;
    // 0x80800E7C: lbu         $t6, 0x1C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1C);
    skip_0:
    // 0x80800E80: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800E84: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80800E88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800E8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800E90: jal         0x80087B80
    // 0x80800E94: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x80800E94: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_6:
    // 0x80800E98: lbu         $t6, 0x1C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1C);
L_80800E9C:
    // 0x80800E9C: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80800EA0: bnel        $s6, $t7, L_80800EC4
    if (ctx->r22 != ctx->r15) {
        // 0x80800EA4: lwc1        $f6, 0x14($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
            goto L_80800EC4;
    }
    goto skip_1;
    // 0x80800EA4: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    skip_1:
    // 0x80800EA8: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x80800EAC: jal         0x80087C28
    // 0x80800EB0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_41(rdram, ctx);
        goto after_7;
    // 0x80800EB0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_7:
    // 0x80800EB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800EB8: jal         0x80087B88
    // 0x80800EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gczoombox_entrypoint_21(rdram, ctx);
        goto after_8;
    // 0x80800EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800EC0: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
L_80800EC4:
    // 0x80800EC4: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80800EC8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800ECC: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80800ED0: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x80800ED4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800ED8: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80800EDC: sh          $s7, 0x58($s2)
    MEM_H(0X58, ctx->r18) = ctx->r23;
    // 0x80800EE0: lh          $v0, 0x58($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X58);
    // 0x80800EE4: sh          $v0, 0x56($s2)
    MEM_H(0X56, ctx->r18) = ctx->r2;
    // 0x80800EE8: sh          $v0, 0x54($s2)
    MEM_H(0X54, ctx->r18) = ctx->r2;
    // 0x80800EEC: lh          $t8, 0x1DA($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1DA);
    // 0x80800EF0: sh          $fp, 0x4E($s3)
    MEM_H(0X4E, ctx->r19) = ctx->r30;
    // 0x80800EF4: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80800EF8: sb          $t8, 0x77($s4)
    MEM_B(0X77, ctx->r20) = ctx->r24;
    // 0x80800EFC: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x80800F00: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800F04: bnel        $at, $zero, L_80800DC4
    if (ctx->r1 != 0) {
        // 0x80800F08: addiu       $s5, $v0, 0x1
        ctx->r21 = ADD32(ctx->r2, 0X1);
            goto L_80800DC4;
    }
    goto skip_2;
    // 0x80800F08: addiu       $s5, $v0, 0x1
    ctx->r21 = ADD32(ctx->r2, 0X1);
    skip_2:
L_80800F0C:
    // 0x80800F0C: lbu         $t0, 0x1C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1C);
    // 0x80800F10: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80800F14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FD0) << 16);
    // 0x80800F18: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x80800F1C: lwc1        $f30, 0x2FD0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FD0));
    // 0x80800F20: bne         $s6, $t1, L_80800F30
    if (ctx->r22 != ctx->r9) {
        // 0x80800F24: addiu       $fp, $zero, -0x1
        ctx->r30 = ADD32(0, -0X1);
            goto L_80800F30;
    }
    // 0x80800F24: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80800F28: b           L_80800F34
    // 0x80800F2C: sh          $fp, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r30;
        goto L_80800F34;
    // 0x80800F2C: sh          $fp, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r30;
L_80800F30:
    // 0x80800F30: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
L_80800F34:
    // 0x80800F34: lbu         $t2, 0x1C($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1C);
    // 0x80800F38: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80800F3C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800F40: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x80800F44: sb          $t3, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r11;
    // 0x80800F48: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x80800F4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800F54: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x80800F58: bgezl       $t6, L_80800F6C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800F5C: lh          $a1, 0x236($s1)
        ctx->r5 = MEM_H(ctx->r17, 0X236);
            goto L_80800F6C;
    }
    goto skip_3;
    // 0x80800F5C: lh          $a1, 0x236($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X236);
    skip_3:
    // 0x80800F60: b           L_80800FEC
    // 0x80800F64: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
        goto L_80800FEC;
    // 0x80800F64: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80800F68: lh          $a1, 0x236($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X236);
L_80800F6C:
    // 0x80800F6C: jal         0x80087B08
    // 0x80800F70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800F70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80800F74: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x80800F78: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
    // 0x80800F7C: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800F80: bltzl       $t9, L_80800FB0
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800F84: lh          $a1, 0x238($s1)
        ctx->r5 = MEM_H(ctx->r17, 0X238);
            goto L_80800FB0;
    }
    goto skip_4;
    // 0x80800F84: lh          $a1, 0x238($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X238);
    skip_4:
    // 0x80800F88: lbu         $t1, 0x1D($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X1D);
    // 0x80800F8C: lw          $a0, 0x23C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X23C);
    // 0x80800F90: lh          $a1, 0x26($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X26);
    // 0x80800F94: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80800F98: jal         0x80088720
    // 0x80800F9C: sb          $t2, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r10;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800F9C: sb          $t2, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r10;
    after_10:
    // 0x80800FA0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80800FA4: jal         0x80087B20
    // 0x80800FA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80800FA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x80800FAC: lh          $a1, 0x238($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X238);
L_80800FB0:
    // 0x80800FB0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80800FB4: sltiu       $t3, $a1, 0x1
    ctx->r11 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80800FB8: jal         0x80087B98
    // 0x80800FBC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    _gczoombox_entrypoint_23(rdram, ctx);
        goto after_12;
    // 0x80800FBC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_12:
    // 0x80800FC0: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x80800FC4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800FC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FCC: sll         $t6, $t4, 10
    ctx->r14 = S32(ctx->r12 << 10);
    // 0x80800FD0: bgez        $t6, L_80800FEC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800FD4: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_80800FEC;
    }
    // 0x80800FD4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800FD8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80800FDC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800FE0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800FE4: jal         0x80087B80
    // 0x80800FE8: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_13;
    // 0x80800FE8: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_13:
L_80800FEC:
    // 0x80800FEC: jal         0x80802A9C
    // 0x80800FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_14;
    // 0x80800FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800FF4: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80800FF8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80800FFC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80801000: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80801004: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80801008: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8080100C: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x80801010: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80801014: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80801018: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8080101C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80801020: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80801024: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80801028: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8080102C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x80801030: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80801034: jr          $ra
    // 0x80801038: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80801038: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void _bsdronewaitbabykaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831A0: syscall     49
    recomp_syscall_handler(rdram, ctx, 0x800831A0);
    return;
    // 0x800831A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void plcamera_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x800F5EF8
    // 0x80800170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800174: jal         0x80110014
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080017C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800180: jal         0x80110790
    // 0x80800184: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80110790(rdram, ctx);
        goto after_2;
    // 0x80800184: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_800E46D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E46D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E46D8: jr          $ra
    // 0x800E46DC: lhu         $v0, -0x2AB0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2AB0);
    return;
    // 0x800E46DC: lhu         $v0, -0x2AB0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2AB0);
;}
RECOMP_FUNC void func_80800874_idbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800874: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2890, 0XE50) << 16);
    // 0x80800878: addiu       $v1, $v0, 0xE50
    ctx->r3 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2890, 0XE50));
    // 0x8080087C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800880: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800884: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2890, 0XE50) << 16);
    // 0x80800888: beq         $a1, $t6, L_808008AC
    if (ctx->r5 == ctx->r14) {
        // 0x8080088C: addiu       $t7, $t7, 0xE50
        ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2890, 0XE50));
            goto L_808008AC;
    }
    // 0x8080088C: addiu       $t7, $t7, 0xE50
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2890, 0XE50));
    // 0x80800890: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
L_80800894:
    // 0x80800894: beq         $a0, $v0, L_808008AC
    if (ctx->r4 == ctx->r2) {
        // 0x80800898: nop
    
            goto L_808008AC;
    }
    // 0x80800898: nop

    // 0x8080089C: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x808008A0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x808008A4: bne         $a1, $v0, L_80800894
    if (ctx->r5 != ctx->r2) {
        // 0x808008A8: nop
    
            goto L_80800894;
    }
    // 0x808008A8: nop

L_808008AC:
    // 0x808008AC: jr          $ra
    // 0x808008B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808008B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void badrone_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800218: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800224: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80800228: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8080022C: jal         0x800EE7F8
    // 0x80800230: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800230: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x80800234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800238: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080023C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800240: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800244: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800248: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x8080024C: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x80800250: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x80800254: lw          $t9, 0x54($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X54);
    // 0x80800258: jal         0x800846E8
    // 0x8080025C: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    _badata_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x8080025C: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    after_1:
    // 0x80800260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: jal         0x8009E5C8
    // 0x80800268: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8080026C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AD8: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AD8);
    return;
    // 0x80083ADC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800664_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: jal         0x8080050C
    // 0x80800670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080050C_chfootwear(rdram, ctx);
        goto after_0;
    // 0x80800670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080067C: jr          $ra
    // 0x80800680: nop

    return;
    // 0x80800680: nop

;}
RECOMP_FUNC void func_8010E3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E3B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E3BC: jr          $ra
    // 0x8010E3C0: lw          $v0, 0x7074($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7074);
    return;
    // 0x8010E3C0: lw          $v0, 0x7074($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7074);
;}
RECOMP_FUNC void func_800FED0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FED0C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800FED10: sltiu       $at, $t6, 0x83
    ctx->r1 = ctx->r14 < 0X83 ? 1 : 0;
    // 0x800FED14: beq         $at, $zero, L_800FED68
    if (ctx->r1 == 0) {
        // 0x800FED18: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800FED68;
    }
    // 0x800FED18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FED1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FED20: addu        $at, $at, $t6
    gpr jr_addend_800FED28 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800FED24: lw          $t6, 0x6214($at)
    ctx->r14 = ADD32(ctx->r1, 0X6214);
    // 0x800FED28: jr          $t6
    // 0x800FED2C: nop

    switch (jr_addend_800FED28 >> 2) {
        case 0: goto L_800FED68; break;
        case 1: goto L_800FED30; break;
        case 2: goto L_800FED68; break;
        case 3: goto L_800FED68; break;
        case 4: goto L_800FED38; break;
        case 5: goto L_800FED68; break;
        case 6: goto L_800FED68; break;
        case 7: goto L_800FED68; break;
        case 8: goto L_800FED68; break;
        case 9: goto L_800FED38; break;
        case 10: goto L_800FED38; break;
        case 11: goto L_800FED38; break;
        case 12: goto L_800FED38; break;
        case 13: goto L_800FED68; break;
        case 14: goto L_800FED68; break;
        case 15: goto L_800FED68; break;
        case 16: goto L_800FED68; break;
        case 17: goto L_800FED38; break;
        case 18: goto L_800FED68; break;
        case 19: goto L_800FED68; break;
        case 20: goto L_800FED68; break;
        case 21: goto L_800FED38; break;
        case 22: goto L_800FED38; break;
        case 23: goto L_800FED38; break;
        case 24: goto L_800FED68; break;
        case 25: goto L_800FED68; break;
        case 26: goto L_800FED38; break;
        case 27: goto L_800FED68; break;
        case 28: goto L_800FED68; break;
        case 29: goto L_800FED68; break;
        case 30: goto L_800FED68; break;
        case 31: goto L_800FED68; break;
        case 32: goto L_800FED68; break;
        case 33: goto L_800FED68; break;
        case 34: goto L_800FED68; break;
        case 35: goto L_800FED68; break;
        case 36: goto L_800FED68; break;
        case 37: goto L_800FED68; break;
        case 38: goto L_800FED68; break;
        case 39: goto L_800FED68; break;
        case 40: goto L_800FED68; break;
        case 41: goto L_800FED68; break;
        case 42: goto L_800FED40; break;
        case 43: goto L_800FED68; break;
        case 44: goto L_800FED68; break;
        case 45: goto L_800FED38; break;
        case 46: goto L_800FED68; break;
        case 47: goto L_800FED68; break;
        case 48: goto L_800FED38; break;
        case 49: goto L_800FED68; break;
        case 50: goto L_800FED68; break;
        case 51: goto L_800FED68; break;
        case 52: goto L_800FED68; break;
        case 53: goto L_800FED68; break;
        case 54: goto L_800FED68; break;
        case 55: goto L_800FED68; break;
        case 56: goto L_800FED68; break;
        case 57: goto L_800FED38; break;
        case 58: goto L_800FED68; break;
        case 59: goto L_800FED68; break;
        case 60: goto L_800FED68; break;
        case 61: goto L_800FED68; break;
        case 62: goto L_800FED68; break;
        case 63: goto L_800FED68; break;
        case 64: goto L_800FED68; break;
        case 65: goto L_800FED68; break;
        case 66: goto L_800FED68; break;
        case 67: goto L_800FED38; break;
        case 68: goto L_800FED68; break;
        case 69: goto L_800FED68; break;
        case 70: goto L_800FED68; break;
        case 71: goto L_800FED68; break;
        case 72: goto L_800FED68; break;
        case 73: goto L_800FED68; break;
        case 74: goto L_800FED68; break;
        case 75: goto L_800FED68; break;
        case 76: goto L_800FED68; break;
        case 77: goto L_800FED68; break;
        case 78: goto L_800FED68; break;
        case 79: goto L_800FED68; break;
        case 80: goto L_800FED68; break;
        case 81: goto L_800FED68; break;
        case 82: goto L_800FED38; break;
        case 83: goto L_800FED68; break;
        case 84: goto L_800FED68; break;
        case 85: goto L_800FED68; break;
        case 86: goto L_800FED68; break;
        case 87: goto L_800FED68; break;
        case 88: goto L_800FED68; break;
        case 89: goto L_800FED68; break;
        case 90: goto L_800FED68; break;
        case 91: goto L_800FED68; break;
        case 92: goto L_800FED68; break;
        case 93: goto L_800FED68; break;
        case 94: goto L_800FED68; break;
        case 95: goto L_800FED38; break;
        case 96: goto L_800FED68; break;
        case 97: goto L_800FED68; break;
        case 98: goto L_800FED68; break;
        case 99: goto L_800FED68; break;
        case 100: goto L_800FED68; break;
        case 101: goto L_800FED68; break;
        case 102: goto L_800FED68; break;
        case 103: goto L_800FED40; break;
        case 104: goto L_800FED68; break;
        case 105: goto L_800FED68; break;
        case 106: goto L_800FED68; break;
        case 107: goto L_800FED68; break;
        case 108: goto L_800FED68; break;
        case 109: goto L_800FED68; break;
        case 110: goto L_800FED68; break;
        case 111: goto L_800FED68; break;
        case 112: goto L_800FED68; break;
        case 113: goto L_800FED68; break;
        case 114: goto L_800FED68; break;
        case 115: goto L_800FED68; break;
        case 116: goto L_800FED68; break;
        case 117: goto L_800FED68; break;
        case 118: goto L_800FED38; break;
        case 119: goto L_800FED68; break;
        case 120: goto L_800FED68; break;
        case 121: goto L_800FED68; break;
        case 122: goto L_800FED68; break;
        case 123: goto L_800FED68; break;
        case 124: goto L_800FED68; break;
        case 125: goto L_800FED68; break;
        case 126: goto L_800FED68; break;
        case 127: goto L_800FED68; break;
        case 128: goto L_800FED68; break;
        case 129: goto L_800FED68; break;
        case 130: goto L_800FED38; break;
        default: switch_error(__func__, 0x800FED28, 0x80126214);
    }
    // 0x800FED2C: nop

L_800FED30:
    // 0x800FED30: b           L_800FED44
    // 0x800FED34: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_800FED44;
    // 0x800FED34: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_800FED38:
    // 0x800FED38: b           L_800FED44
    // 0x800FED3C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_800FED44;
    // 0x800FED3C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800FED40:
    // 0x800FED40: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800FED44:
    // 0x800FED44: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FED48: addiu       $t7, $t7, 0x5A10
    ctx->r15 = ADD32(ctx->r15, 0X5A10);
    // 0x800FED4C: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800FED50: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800FED54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FED58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FED5C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800FED60: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800FED64: sw          $t0, 0x3E60($at)
    MEM_W(0X3E60, ctx->r1) = ctx->r8;
L_800FED68:
    // 0x800FED68: jr          $ra
    // 0x800FED6C: nop

    return;
    // 0x800FED6C: nop

;}
RECOMP_FUNC void bsdronevanish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080035C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800360: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800364: jal         0x80085160
    // 0x80800368: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    _bastatemem_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800368: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800374: jal         0x80084658
    // 0x80800378: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800378: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800384: jal         0x8008CB3C
    // 0x80800388: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800388: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8080038C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080039C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003A0: jal         0x8009FFD8
    // 0x808003A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x808003A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x800961AC
    // 0x808003B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800961AC(rdram, ctx);
        goto after_4;
    // 0x808003B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x808003B4: jal         0x8080021C
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_bsdronevanish(rdram, ctx);
        goto after_5;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003BC: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003C8: jal         0x80800000
    // 0x808003CC: sb          $zero, 0x18($t7)
    MEM_B(0X18, ctx->r15) = 0;
    func_80800000_bsdronevanish(rdram, ctx);
        goto after_6;
    // 0x808003CC: sb          $zero, 0x18($t7)
    MEM_B(0X18, ctx->r15) = 0;
    after_6:
    // 0x808003D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003DC: jr          $ra
    // 0x808003E0: nop

    return;
    // 0x808003E0: nop

;}
RECOMP_FUNC void func_800A4EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4EFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A4F00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4F04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A4F08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4F0C: beq         $a0, $zero, L_800A4FF0
    if (ctx->r4 == 0) {
        // 0x800A4F10: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_800A4FF0;
    }
    // 0x800A4F10: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A4F14: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800A4F18: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x800A4F1C: bnel        $t6, $zero, L_800A4FF4
    if (ctx->r14 != 0) {
        // 0x800A4F20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4FF4;
    }
    goto skip_0;
    // 0x800A4F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A4F24: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800A4F28: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4F2C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A4F30: nop

    // 0x800A4F34: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A4F38: jal         0x800F2100
    // 0x800A4F3C: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800A4F3C: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    after_0:
    // 0x800A4F40: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A4F44: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x800A4F48: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4F4C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x800A4F50: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A4F54: nop

    // 0x800A4F58: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A4F5C: jal         0x800F2100
    // 0x800A4F60: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800A4F60: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    after_1:
    // 0x800A4F64: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A4F68: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x800A4F6C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A4F70: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x800A4F74: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800A4F78: nop

    // 0x800A4F7C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A4F80: jal         0x800F2100
    // 0x800A4F84: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x800A4F84: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_2:
    // 0x800A4F88: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800A4F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A4F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A4F94: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x800A4F98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A4F9C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_800A4FA0:
    // 0x800A4FA0: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x800A4FA4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x800A4FA8: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800A4FAC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A4FB0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800A4FB4: nop

    // 0x800A4FB8: bc1fl       L_800A4FC8
    if (!c1cs) {
        // 0x800A4FBC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800A4FC8;
    }
    goto skip_1;
    // 0x800A4FBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800A4FC0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800A4FC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800A4FC8:
    // 0x800A4FC8: bne         $v0, $a1, L_800A4FA0
    if (ctx->r2 != ctx->r5) {
        // 0x800A4FCC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A4FA0;
    }
    // 0x800A4FCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A4FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4FD4: jal         0x80090E30
    // 0x800A4FD8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80090E30(rdram, ctx);
        goto after_3;
    // 0x800A4FD8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_3:
    // 0x800A4FDC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800A4FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A4FE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800A4FE8: jal         0x800A3D78
    // 0x800A4FEC: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    func_800A3D78(rdram, ctx);
        goto after_4;
    // 0x800A4FEC: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    after_4:
L_800A4FF0:
    // 0x800A4FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4FF4:
    // 0x800A4FF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4FF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A4FFC: jr          $ra
    // 0x800A5000: nop

    return;
    // 0x800A5000: nop

;}
RECOMP_FUNC void _suspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D78: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089D78);
    return;
    // 0x80089D7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void cheggfire_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800270: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800274: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800278: jal         0x8008A488
    // 0x8080027C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080027C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800280: addiu       $a0, $zero, 0x15B
    ctx->r4 = ADD32(0, 0X15B);
    // 0x80800284: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800288: jal         0x8008A3D0
    // 0x8080028C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080028C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800290: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2108, 0X3A4) << 16);
    // 0x80800294: lwc1        $f4, 0x3A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2108, 0X3A4));
    // 0x80800298: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080029C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002A0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808002A4: jal         0x8008A380
    // 0x808002A8: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _suegg_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002A8: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x8008A460
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808002B8: lui         $a1, 0xC509
    ctx->r5 = S32(0XC509 << 16);
    // 0x808002BC: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x808002C0: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x808002C4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808002C8: jal         0x8008A468
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: jal         0x8008A470
    // 0x808002D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808002D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808002DC: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x808002E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002E4: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x808002E8: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808002EC: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002FC: jr          $ra
    // 0x80800300: nop

    return;
    // 0x80800300: nop

;}
RECOMP_FUNC void func_80025E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025E88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80025E8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80025E90: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80025E94: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80025E98: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80025E9C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80025EA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80025EA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80025EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80025EB0: jal         0x80026500
    // 0x80025EB4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80025EB4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80025EB8: b           L_80025EC0
    // 0x80025EBC: nop

        goto L_80025EC0;
    // 0x80025EBC: nop

L_80025EC0:
    // 0x80025EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025EC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80025EC8: jr          $ra
    // 0x80025ECC: nop

    return;
    // 0x80025ECC: nop

;}
RECOMP_FUNC void func_80800A08_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800A0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A14: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80800A18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A20: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800A24: nop

    // 0x80800A28: bc1fl       L_80800C6C
    if (!c1cs) {
        // 0x80800A2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800C6C;
    }
    goto skip_0;
    // 0x80800A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A30: jal         0x800F54E4
    // 0x80800A34: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800A34: nop

    after_0:
    // 0x80800A38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A3C: jal         0x800F5A00
    // 0x80800A40: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800A40: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800A44: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800A48: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800A4C: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80800A50: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800A54: bgez        $t8, L_80800A6C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800A58: nop
    
            goto L_80800A6C;
    }
    // 0x80800A58: nop

    // 0x80800A5C: jal         0x800D91EC
    // 0x80800A60: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D91EC(rdram, ctx);
        goto after_2;
    // 0x80800A60: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_2:
    // 0x80800A64: b           L_80800A74
    // 0x80800A68: nop

        goto L_80800A74;
    // 0x80800A68: nop

L_80800A6C:
    // 0x80800A6C: jal         0x800D90F8
    // 0x80800A70: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    func_800D90F8(rdram, ctx);
        goto after_3;
    // 0x80800A70: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    after_3:
L_80800A74:
    // 0x80800A74: jal         0x800D8FF8
    // 0x80800A78: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800A78: nop

    after_4:
    // 0x80800A7C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800A80: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800A84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2120) << 16);
    // 0x80800A88: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800A8C: lwc1        $f12, 0x2120($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2120));
    // 0x80800A90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2124) << 16);
    // 0x80800A94: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800A98: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800A9C: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800AA0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80800AA4: nop

    // 0x80800AA8: bc1fl       L_80800AC0
    if (!c1cs) {
        // 0x80800AAC: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800AC0;
    }
    goto skip_1;
    // 0x80800AAC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x80800AB0: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800AB4: b           L_80800ADC
    // 0x80800AB8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800ADC;
    // 0x80800AB8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80800ABC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800AC0:
    // 0x80800AC0: nop

    // 0x80800AC4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80800AC8: nop

    // 0x80800ACC: bc1fl       L_80800AE0
    if (!c1cs) {
        // 0x80800AD0: lwc1        $f2, 0x44($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80800AE0;
    }
    goto skip_2;
    // 0x80800AD0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80800AD4: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800AD8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80800ADC:
    // 0x80800ADC: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_80800AE0:
    // 0x80800AE0: lwc1        $f8, 0x2124($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2124));
    // 0x80800AE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2128) << 16);
    // 0x80800AE8: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80800AEC: nop

    // 0x80800AF0: bc1f        L_80800BE0
    if (!c1cs) {
        // 0x80800AF4: nop
    
            goto L_80800BE0;
    }
    // 0x80800AF4: nop

    // 0x80800AF8: lwc1        $f16, 0x2128($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2128));
    // 0x80800AFC: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800B00: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80800B04: nop

    // 0x80800B08: bc1f        L_80800BE0
    if (!c1cs) {
        // 0x80800B0C: nop
    
            goto L_80800BE0;
    }
    // 0x80800B0C: nop

    // 0x80800B10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B14: nop

    // 0x80800B18: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800B1C: nop

    // 0x80800B20: bc1f        L_80800BE0
    if (!c1cs) {
        // 0x80800B24: nop
    
            goto L_80800BE0;
    }
    // 0x80800B24: nop

    // 0x80800B28: jal         0x800F54E4
    // 0x80800B2C: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800B2C: nop

    after_5:
    // 0x80800B30: jal         0x800F6C5C
    // 0x80800B34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_6;
    // 0x80800B34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800B38: beq         $v0, $zero, L_80800BE0
    if (ctx->r2 == 0) {
        // 0x80800B3C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2304, 0X212C) << 16);
            goto L_80800BE0;
    }
    // 0x80800B3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X212C) << 16);
    // 0x80800B40: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800B44: lwc1        $f10, 0x212C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X212C));
    // 0x80800B48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2130) << 16);
    // 0x80800B4C: lwc1        $f14, 0x2130($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2130));
    // 0x80800B50: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800B54: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800B58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B5C: lui         $a2, 0x45B9
    ctx->r6 = S32(0X45B9 << 16);
    // 0x80800B60: ori         $a2, $a2, 0xF000
    ctx->r6 = ctx->r6 | 0XF000;
    // 0x80800B64: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800B68: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800B6C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80800B70: jal         0x800F10B4
    // 0x80800B74: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800B74: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80800B78: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800B7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B80: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800B84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B88: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800B8C: nop

    // 0x80800B90: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800B94: jal         0x800138D0
    // 0x80800B98: nop

    func_800138D0(rdram, ctx);
        goto after_8;
    // 0x80800B98: nop

    after_8:
    // 0x80800B9C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800BA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BA4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800BA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BAC: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800BB0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800BB4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800BB8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800BBC: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80800BC0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800BC4: jal         0x800EFA4C
    // 0x80800BC8: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800BC8: nop

    after_9:
    // 0x80800BCC: jal         0x800F54E4
    // 0x80800BD0: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800BD0: nop

    after_10:
    // 0x80800BD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BD8: jal         0x800F48BC
    // 0x80800BDC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F48BC(rdram, ctx);
        goto after_11;
    // 0x80800BDC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
L_80800BE0:
    // 0x80800BE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2134) << 16);
    // 0x80800BE4: lui         $a2, 0x45B9
    ctx->r6 = S32(0X45B9 << 16);
    // 0x80800BE8: ori         $a2, $a2, 0xF000
    ctx->r6 = ctx->r6 | 0XF000;
    // 0x80800BEC: lwc1        $f14, 0x2134($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2134));
    // 0x80800BF0: jal         0x800F0D50
    // 0x80800BF4: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    func_800F0D50(rdram, ctx);
        goto after_12;
    // 0x80800BF4: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_12:
    // 0x80800BF8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800BFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C00: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800C04: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800C08: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2304, 0X2170) << 16);
    // 0x80800C0C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800C10: addiu       $a3, $a3, 0x2170
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2304, 0X2170));
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C18: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C20: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80800C24: jal         0x80089D50
    // 0x80800C28: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800C28: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x80800C2C: jal         0x800F2100
    // 0x80800C30: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    mlAbsF(rdram, ctx);
        goto after_14;
    // 0x80800C30: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    after_14:
    // 0x80800C34: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800C38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2304, 0X2138) << 16);
    // 0x80800C40: lwc1        $f6, 0x2138($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2304, 0X2138));
    // 0x80800C44: lui         $a3, 0x3F0C
    ctx->r7 = S32(0X3F0C << 16);
    // 0x80800C48: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800C4C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800C50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800C54: jal         0x800F10B4
    // 0x80800C58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80800C58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80800C5C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C60: jal         0x80089D30
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C6C:
    // 0x80800C6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800C74: jr          $ra
    // 0x80800C78: nop

    return;
    // 0x80800C78: nop

;}
