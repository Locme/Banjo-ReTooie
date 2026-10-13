#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80109C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109C20: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80109C24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109C28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80109C2C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80109C30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80109C34: jal         0x801099D0
    // 0x80109C38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_801099D0(rdram, ctx);
        goto after_0;
    // 0x80109C38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x80109C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80109C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80109C44: jr          $ra
    // 0x80109C48: nop

    return;
    // 0x80109C48: nop

;}
RECOMP_FUNC void func_800CB534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB534: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800CB538: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800CB53C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800CB540: addiu       $t8, $t8, -0x5490
    ctx->r24 = ADD32(ctx->r24, -0X5490);
    // 0x800CB544: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800CB548: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB54C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800CB550: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800CB554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB558: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB55C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CB560: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CB564: jalr        $t9
    // 0x800CB568: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CB568: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x800CB56C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800CB570: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800CB574: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CB578: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800CB57C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CB580: jalr        $t9
    // 0x800CB584: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CB584: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
    after_1:
    // 0x800CB588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB58C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB590: jr          $ra
    // 0x800CB594: nop

    return;
    // 0x800CB594: nop

;}
RECOMP_FUNC void func_80802240_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802244: slti        $at, $a1, 0x3E
    ctx->r1 = SIGNED(ctx->r5) < 0X3E ? 1 : 0;
    // 0x80802248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080224C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802250: bne         $at, $zero, L_8080226C
    if (ctx->r1 != 0) {
        // 0x80802254: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080226C;
    }
    // 0x80802254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802258: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080225C: beq         $a1, $at, L_808022F4
    if (ctx->r5 == ctx->r1) {
        // 0x80802260: nop
    
            goto L_808022F4;
    }
    // 0x80802260: nop

    // 0x80802264: b           L_80802388
    // 0x80802268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802388;
    // 0x80802268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080226C:
    // 0x8080226C: addiu       $t6, $a1, -0x1F
    ctx->r14 = ADD32(ctx->r5, -0X1F);
    // 0x80802270: sltiu       $at, $t6, 0x1F
    ctx->r1 = ctx->r14 < 0X1F ? 1 : 0;
    // 0x80802274: beq         $at, $zero, L_8080237C
    if (ctx->r1 == 0) {
        // 0x80802278: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080237C;
    }
    // 0x80802278: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080227C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X2808) << 16);
    // 0x80802280: addu        $at, $at, $t6
    gpr jr_addend_80802288 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80802284: lw          $t6, 0x2808($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1140, 0X2808));
    // 0x80802288: jr          $t6
    // 0x8080228C: nop

    switch (jr_addend_80802288 >> 2) {
        case 0: goto L_808022E0; break;
        case 1: goto L_8080237C; break;
        case 2: goto L_8080237C; break;
        case 3: goto L_8080237C; break;
        case 4: goto L_8080237C; break;
        case 5: goto L_8080237C; break;
        case 6: goto L_8080237C; break;
        case 7: goto L_8080237C; break;
        case 8: goto L_8080237C; break;
        case 9: goto L_8080237C; break;
        case 10: goto L_80802304; break;
        case 11: goto L_80802358; break;
        case 12: goto L_8080237C; break;
        case 13: goto L_8080237C; break;
        case 14: goto L_8080237C; break;
        case 15: goto L_808022D0; break;
        case 16: goto L_8080237C; break;
        case 17: goto L_8080237C; break;
        case 18: goto L_8080237C; break;
        case 19: goto L_8080237C; break;
        case 20: goto L_8080237C; break;
        case 21: goto L_8080237C; break;
        case 22: goto L_8080237C; break;
        case 23: goto L_8080237C; break;
        case 24: goto L_8080237C; break;
        case 25: goto L_8080237C; break;
        case 26: goto L_8080237C; break;
        case 27: goto L_8080237C; break;
        case 28: goto L_8080237C; break;
        case 29: goto L_8080237C; break;
        case 30: goto L_80802290; break;
        default: switch_error(__func__, 0x80802288, 0x80802808);
    }
    // 0x8080228C: nop

L_80802290:
    // 0x80802290: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802294: addiu       $a0, $zero, 0x3BE
    ctx->r4 = ADD32(0, 0X3BE);
    // 0x80802298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080229C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x808022A0: jal         0x80108528
    // 0x808022A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x808022A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x808022A8: beq         $v0, $zero, L_80802384
    if (ctx->r2 == 0) {
        // 0x808022AC: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80802384;
    }
    // 0x808022AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808022B0: lhu         $t8, 0x76($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X76);
    // 0x808022B4: lhu         $t2, 0x76($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X76);
    // 0x808022B8: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808022BC: sll         $t1, $t9, 7
    ctx->r9 = S32(ctx->r25 << 7);
    // 0x808022C0: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x808022C4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x808022C8: b           L_80802384
    // 0x808022CC: sh          $t4, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r12;
        goto L_80802384;
    // 0x808022CC: sh          $t4, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r12;
L_808022D0:
    // 0x808022D0: jal         0x80085710
    // 0x808022D4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808022D4: nop

    after_1:
    // 0x808022D8: b           L_80802388
    // 0x808022DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802388;
    // 0x808022DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808022E0:
    // 0x808022E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808022E4: jal         0x808021D4
    // 0x808022E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808021D4_chfactoryrobot(rdram, ctx);
        goto after_2;
    // 0x808022E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808022EC: b           L_80802388
    // 0x808022F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802388;
    // 0x808022F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808022F4:
    // 0x808022F4: jal         0x808025D4
    // 0x808022F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808025D4_chfactoryrobot(rdram, ctx);
        goto after_3;
    // 0x808022F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808022FC: b           L_80802388
    // 0x80802300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802388;
    // 0x80802300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802304:
    // 0x80802304: jal         0x800E8B74
    // 0x80802308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E8B74(rdram, ctx);
        goto after_4;
    // 0x80802308: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8080230C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80802310: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802314: sb          $v0, 0x28($t5)
    MEM_B(0X28, ctx->r13) = ctx->r2;
    // 0x80802318: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080231C: jal         0x800E8DB0
    // 0x80802320: lbu         $a0, 0x28($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X28);
    func_800E8DB0(rdram, ctx);
        goto after_5;
    // 0x80802320: lbu         $a0, 0x28($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X28);
    after_5:
    // 0x80802324: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80802328: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x8080232C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80802330: jal         0x800E8D28
    // 0x80802334: lbu         $a0, 0x28($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X28);
    func_800E8D28(rdram, ctx);
        goto after_6;
    // 0x80802334: lbu         $a0, 0x28($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X28);
    after_6:
    // 0x80802338: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080233C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1140, 0X2AF4) << 16);
    // 0x80802340: addiu       $a1, $a1, 0x2AF4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1140, 0X2AF4));
    // 0x80802344: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80802348: jal         0x800E8D5C
    // 0x8080234C: lbu         $a0, 0x28($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X28);
    func_800E8D5C(rdram, ctx);
        goto after_7;
    // 0x8080234C: lbu         $a0, 0x28($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X28);
    after_7:
    // 0x80802350: b           L_80802388
    // 0x80802354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802388;
    // 0x80802354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802358:
    // 0x80802358: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080235C: lbu         $a0, 0x28($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X28);
    // 0x80802360: beql        $a0, $zero, L_80802388
    if (ctx->r4 == 0) {
        // 0x80802364: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802388;
    }
    goto skip_0;
    // 0x80802364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80802368: jal         0x800E8C08
    // 0x8080236C: nop

    func_800E8C08(rdram, ctx);
        goto after_8;
    // 0x8080236C: nop

    after_8:
    // 0x80802370: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80802374: b           L_80802384
    // 0x80802378: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
        goto L_80802384;
    // 0x80802378: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
L_8080237C:
    // 0x8080237C: b           L_80802388
    // 0x80802380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802388;
    // 0x80802380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802384:
    // 0x80802384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802388:
    // 0x80802388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080238C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802390: jr          $ra
    // 0x80802394: nop

    return;
    // 0x80802394: nop

;}
RECOMP_FUNC void _bschokedie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E90: syscall     32
    recomp_syscall_handler(rdram, ctx, 0x80082E90);
    return;
    // 0x80082E94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chcollballcontrol_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801758: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X4DA8) << 16);
    // 0x8080175C: jr          $ra
    // 0x80801760: addiu       $v0, $v0, 0x4DA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4DA8));
    return;
    // 0x80801760: addiu       $v0, $v0, 0x4DA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4DA8));
;}
RECOMP_FUNC void func_80800D8C_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D94: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800D98: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1184) << 16);
    // 0x80800D9C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(892, 0X11AC) << 16);
    // 0x80800DA0: addiu       $a3, $a3, 0x11AC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(892, 0X11AC));
    // 0x80800DA4: addiu       $a2, $a2, 0x1184
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1184));
    // 0x80800DA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800DAC: jal         0x80089D28
    // 0x80800DB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800DB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DB4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1194) << 16);
    // 0x80800DB8: addiu       $a2, $a2, 0x1194
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1194));
    // 0x80800DBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DC4: jal         0x80089D20
    // 0x80800DC8: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800DC8: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_1:
    // 0x80800DCC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X11A0) << 16);
    // 0x80800DD0: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800DD4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800DD8: addiu       $a2, $a2, 0x11A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X11A0));
    // 0x80800DDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DE0: jal         0x80089D20
    // 0x80800DE4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800DE4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DF0: jr          $ra
    // 0x80800DF4: nop

    return;
    // 0x80800DF4: nop

;}
RECOMP_FUNC void func_8080069C_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808006A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808006AC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808006B0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808006B4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808006B8: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808006BC: beq         $at, $zero, L_80800730
    if (ctx->r1 == 0) {
        // 0x808006C0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800730;
    }
    // 0x808006C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808006C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(960, 0X8B0) << 16);
    // 0x808006C8: addu        $at, $at, $t8
    gpr jr_addend_808006D0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808006CC: lw          $t8, 0x8B0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(960, 0X8B0));
    // 0x808006D0: jr          $t8
    // 0x808006D4: nop

    switch (jr_addend_808006D0 >> 2) {
        case 0: goto L_808006D8; break;
        case 1: goto L_808006D8; break;
        case 2: goto L_808006F0; break;
        case 3: goto L_80800720; break;
        case 4: goto L_80800720; break;
        default: switch_error(__func__, 0x808006D0, 0x808008B0);
    }
    // 0x808006D4: nop

L_808006D8:
    // 0x808006D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8E8) << 16);
    // 0x808006DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808006E0: jal         0x800F2E60
    // 0x808006E4: addiu       $a1, $a1, 0x8E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8E8));
    func_800F2E60(rdram, ctx);
        goto after_0;
    // 0x808006E4: addiu       $a1, $a1, 0x8E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8E8));
    after_0:
    // 0x808006E8: b           L_80800734
    // 0x808006EC: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
        goto L_80800734;
    // 0x808006EC: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
L_808006F0:
    // 0x808006F0: jal         0x80100094
    // 0x808006F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808006F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808006F8: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808006FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8E8) << 16);
    // 0x80800700: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(960, 0X8F4) << 16);
    // 0x80800704: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800708: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080070C: addiu       $a2, $a2, 0x8F4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(960, 0X8F4));
    // 0x80800710: jal         0x800F3214
    // 0x80800714: addiu       $a1, $a1, 0x8E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8E8));
    func_800F3214(rdram, ctx);
        goto after_2;
    // 0x80800714: addiu       $a1, $a1, 0x8E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8E8));
    after_2:
    // 0x80800718: b           L_80800734
    // 0x8080071C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
        goto L_80800734;
    // 0x8080071C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
L_80800720:
    // 0x80800720: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8F4) << 16);
    // 0x80800724: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800728: jal         0x800F2E60
    // 0x8080072C: addiu       $a1, $a1, 0x8F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8F4));
    func_800F2E60(rdram, ctx);
        goto after_3;
    // 0x8080072C: addiu       $a1, $a1, 0x8F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8F4));
    after_3:
L_80800730:
    // 0x80800730: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
L_80800734:
    // 0x80800734: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x80800738: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080073C: jal         0x80089C30
    // 0x80800740: addiu       $a0, $zero, 0x336
    ctx->r4 = ADD32(0, 0X336);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800740: addiu       $a0, $zero, 0x336
    ctx->r4 = ADD32(0, 0X336);
    after_4:
    // 0x80800744: beq         $v0, $zero, L_80800768
    if (ctx->r2 == 0) {
        // 0x80800748: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800768;
    }
    // 0x80800748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080074C:
    // 0x8080074C: jal         0x80089CE8
    // 0x80800750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80800754: addiu       $a0, $zero, 0x336
    ctx->r4 = ADD32(0, 0X336);
    // 0x80800758: jal         0x80089C38
    // 0x8080075C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8080075C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800760: bne         $v0, $zero, L_8080074C
    if (ctx->r2 != 0) {
        // 0x80800764: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080074C;
    }
    // 0x80800764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800768:
    // 0x80800768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080076C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800770: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800774: jr          $ra
    // 0x80800778: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800778: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chalienkids_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086578: syscall     337
    recomp_syscall_handler(rdram, ctx, 0x80086578);
    return;
    // 0x8008657C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808002FC_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800300: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800308: beq         $a1, $at, L_8080032C
    if (ctx->r5 == ctx->r1) {
        // 0x8080030C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080032C;
    }
    // 0x8080030C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800310: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800314: bne         $a1, $at, L_8080033C
    if (ctx->r5 != ctx->r1) {
        // 0x80800318: nop
    
            goto L_8080033C;
    }
    // 0x80800318: nop

    // 0x8080031C: jal         0x8080015C
    // 0x80800320: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8080015C_chtntbox(rdram, ctx);
        goto after_0;
    // 0x80800320: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800324: b           L_80800348
    // 0x80800328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800348;
    // 0x80800328: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080032C:
    // 0x8080032C: jal         0x808004F8
    // 0x80800330: nop

    func_808004F8_chtntbox(rdram, ctx);
        goto after_1;
    // 0x80800330: nop

    after_1:
    // 0x80800334: b           L_80800348
    // 0x80800338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800348;
    // 0x80800338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080033C:
    // 0x8080033C: b           L_80800348
    // 0x80800340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800348;
    // 0x80800340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800348:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void func_8008CA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CAA0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CAA4: jal         0x8008B304
    // 0x8008CAA8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8008B304(rdram, ctx);
        goto after_0;
    // 0x8008CAA8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CAB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CAB4: jr          $ra
    // 0x8008CAB8: nop

    return;
    // 0x8008CAB8: nop

;}
RECOMP_FUNC void func_80802B10_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802B18: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80802B1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802B20: jal         0x80101E14
    // 0x80802B24: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80802B24: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80802B28: beql        $v0, $zero, L_80802B78
    if (ctx->r2 == 0) {
        // 0x80802B2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802B78;
    }
    goto skip_0;
    // 0x80802B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802B30: jal         0x8080299C
    // 0x80802B34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080299C_chklungo(rdram, ctx);
        goto after_1;
    // 0x80802B34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802B38: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80802B3C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80802B40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802B44: jal         0x800E15CC
    // 0x80802B48: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_2;
    // 0x80802B48: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_2:
    // 0x80802B4C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80802B50: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80802B54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802B58: jal         0x80018820
    // 0x80802B5C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    func_80018820(rdram, ctx);
        goto after_3;
    // 0x80802B5C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_3:
    // 0x80802B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802B64: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3CF4) << 16);
    // 0x80802B68: addiu       $a2, $a2, 0x3CF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3CF4));
    // 0x80802B6C: jal         0x80089D18
    // 0x80802B70: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80802B70: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80802B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802B78:
    // 0x80802B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802B7C: jr          $ra
    // 0x80802B80: nop

    return;
    // 0x80802B80: nop

;}
RECOMP_FUNC void _idworldmake_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F30: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F30);
    return;
    // 0x80088F34: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8002CC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CC9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CCA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002CCA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002CCA8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002CCAC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002CCB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002CCB4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002CCB8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8002CCBC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CCC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002CCC4: beq         $s0, $at, L_8002CDD8
    if (ctx->r16 == ctx->r1) {
        // 0x8002CCC8: nop
    
            goto L_8002CDD8;
    }
    // 0x8002CCC8: nop

    // 0x8002CCCC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002CCD0: beq         $s0, $at, L_8002CCE0
    if (ctx->r16 == ctx->r1) {
        // 0x8002CCD4: nop
    
            goto L_8002CCE0;
    }
    // 0x8002CCD4: nop

    // 0x8002CCD8: b           L_8002CE44
    // 0x8002CCDC: nop

        goto L_8002CE44;
    // 0x8002CCDC: nop

L_8002CCE0:
    // 0x8002CCE0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002CCE4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002CCE8: sw          $t7, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r15;
    // 0x8002CCEC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002CCF0: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8002CCF4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8002CCF8: sw          $t1, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r9;
    // 0x8002CCFC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD00: sw          $zero, 0x30($t2)
    MEM_W(0X30, ctx->r10) = 0;
    // 0x8002CD04: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8002CD0C: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x8002CD10: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8002CD14: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8002CD18: mflo        $t6
    ctx->r14 = lo;
    // 0x8002CD1C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8002CD20: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002CD24: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8002CD28: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD2C: lw          $t0, 0x20($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X20);
    // 0x8002CD30: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x8002CD34: lw          $t2, 0xB8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XB8);
    // 0x8002CD38: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x8002CD3C: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD40: mflo        $t3
    ctx->r11 = lo;
    // 0x8002CD44: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8002CD48: sw          $t5, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r13;
    // 0x8002CD4C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD50: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    // 0x8002CD54: jal         0x8002C5C0
    // 0x8002CD58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8002C5C0(rdram, ctx);
        goto after_0;
    // 0x8002CD58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8002CD5C: beq         $v0, $zero, L_8002CDB4
    if (ctx->r2 == 0) {
        // 0x8002CD60: nop
    
            goto L_8002CDB4;
    }
    // 0x8002CD60: nop

    // 0x8002CD64: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD68: lw          $t4, 0x20($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X20);
    // 0x8002CD6C: lw          $t1, 0x8($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X8);
    // 0x8002CD70: sw          $t1, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r9;
    // 0x8002CD74: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD78: lw          $t9, 0x20($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X20);
    // 0x8002CD7C: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8002CD80: sw          $t2, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r10;
    // 0x8002CD84: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD88: lw          $t5, 0x20($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X20);
    // 0x8002CD8C: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x8002CD90: sw          $t8, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r24;
    // 0x8002CD94: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002CD98: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8002CD9C: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    // 0x8002CDA0: lw          $a1, 0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X10);
    // 0x8002CDA4: jal         0x80031BF0
    // 0x8002CDA8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    _bcopy(rdram, ctx);
        goto after_1;
    // 0x8002CDA8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8002CDAC: b           L_8002CDD0
    // 0x8002CDB0: nop

        goto L_8002CDD0;
    // 0x8002CDB0: nop

L_8002CDB4:
    // 0x8002CDB4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDB8: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
    // 0x8002CDBC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDC0: lw          $s0, 0x1C($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X1C);
    // 0x8002CDC4: sw          $s0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r16;
    // 0x8002CDC8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDCC: sw          $s0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r16;
L_8002CDD0:
    // 0x8002CDD0: b           L_8002CE4C
    // 0x8002CDD4: nop

        goto L_8002CE4C;
    // 0x8002CDD4: nop

L_8002CDD8:
    // 0x8002CDD8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDDC: sw          $zero, 0x34($t9)
    MEM_W(0X34, ctx->r25) = 0;
    // 0x8002CDE0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002CDE8: sw          $t2, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r10;
    // 0x8002CDEC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDF0: sw          $zero, 0x30($t5)
    MEM_W(0X30, ctx->r13) = 0;
    // 0x8002CDF4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002CDF8: lw          $t3, 0x20($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X20);
    // 0x8002CDFC: beq         $t3, $zero, L_8002CE3C
    if (ctx->r11 == 0) {
        // 0x8002CE00: nop
    
            goto L_8002CE3C;
    }
    // 0x8002CE00: nop

    // 0x8002CE04: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002CE08: lw          $t4, 0x20($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X20);
    // 0x8002CE0C: lw          $t1, 0x0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X0);
    // 0x8002CE10: sw          $t1, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r9;
    // 0x8002CE14: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002CE18: lw          $a0, 0x20($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X20);
    // 0x8002CE1C: jal         0x8002C5C0
    // 0x8002CE20: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8002C5C0(rdram, ctx);
        goto after_2;
    // 0x8002CE20: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x8002CE24: beq         $v0, $zero, L_8002CE3C
    if (ctx->r2 == 0) {
        // 0x8002CE28: nop
    
            goto L_8002CE3C;
    }
    // 0x8002CE28: nop

    // 0x8002CE2C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002CE30: lw          $t2, 0x20($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X20);
    // 0x8002CE34: lw          $t0, 0x10($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X10);
    // 0x8002CE38: sw          $t0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r8;
L_8002CE3C:
    // 0x8002CE3C: b           L_8002CE4C
    // 0x8002CE40: nop

        goto L_8002CE4C;
    // 0x8002CE40: nop

L_8002CE44:
    // 0x8002CE44: b           L_8002CE4C
    // 0x8002CE48: nop

        goto L_8002CE4C;
    // 0x8002CE48: nop

L_8002CE4C:
    // 0x8002CE4C: b           L_8002CE5C
    // 0x8002CE50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002CE5C;
    // 0x8002CE50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002CE54: b           L_8002CE5C
    // 0x8002CE58: nop

        goto L_8002CE5C;
    // 0x8002CE58: nop

L_8002CE5C:
    // 0x8002CE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CE60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002CE64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002CE68: jr          $ra
    // 0x8002CE6C: nop

    return;
    // 0x8002CE6C: nop

;}
RECOMP_FUNC void func_808026D0_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808026D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808026D8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808026DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808026E0: beq         $a1, $at, L_80802708
    if (ctx->r5 == ctx->r1) {
        // 0x808026E4: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80802708;
    }
    // 0x808026E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808026E8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808026EC: beq         $a1, $at, L_8080278C
    if (ctx->r5 == ctx->r1) {
        // 0x808026F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080278C;
    }
    // 0x808026F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026F4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808026F8: beq         $a1, $at, L_8080279C
    if (ctx->r5 == ctx->r1) {
        // 0x808026FC: nop
    
            goto L_8080279C;
    }
    // 0x808026FC: nop

    // 0x80802700: b           L_80802850
    // 0x80802704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802850;
    // 0x80802704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802708:
    // 0x80802708: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080270C: beq         $a2, $at, L_80802774
    if (ctx->r6 == ctx->r1) {
        // 0x80802710: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_80802774;
    }
    // 0x80802710: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80802714: beq         $a2, $at, L_8080272C
    if (ctx->r6 == ctx->r1) {
        // 0x80802718: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_8080272C;
    }
    // 0x80802718: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8080271C: beq         $a2, $at, L_80802758
    if (ctx->r6 == ctx->r1) {
        // 0x80802720: addiu       $a0, $zero, 0x115
        ctx->r4 = ADD32(0, 0X115);
            goto L_80802758;
    }
    // 0x80802720: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    // 0x80802724: b           L_80802850
    // 0x80802728: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80802850;
    // 0x80802728: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080272C:
    // 0x8080272C: jal         0x80085710
    // 0x80802730: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80802730: nop

    after_0:
    // 0x80802734: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080273C: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    // 0x80802740: jal         0x80085708
    // 0x80802744: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80802744: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    after_1:
    // 0x80802748: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x8080274C: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80802750: b           L_80802850
    // 0x80802754: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802850;
    // 0x80802754: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80802758:
    // 0x80802758: addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // 0x8080275C: jal         0x80088868
    // 0x80802760: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x80802760: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    after_2:
    // 0x80802764: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80802768: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x8080276C: b           L_80802850
    // 0x80802770: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80802850;
    // 0x80802770: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80802774:
    // 0x80802774: jal         0x80088830
    // 0x80802778: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80802778: nop

    after_3:
    // 0x8080277C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802780: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x80802784: b           L_80802850
    // 0x80802788: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80802850;
    // 0x80802788: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080278C:
    // 0x8080278C: jal         0x80802864
    // 0x80802790: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80802864_chdinoboss(rdram, ctx);
        goto after_4;
    // 0x80802790: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80802794: b           L_80802850
    // 0x80802798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802850;
    // 0x80802798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080279C:
    // 0x8080279C: jal         0x800EA05C
    // 0x808027A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x808027A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_5:
    // 0x808027A4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808027A8: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808027AC: beql        $a2, $at, L_808027C0
    if (ctx->r6 == ctx->r1) {
        // 0x808027B0: addiu       $at, $zero, 0x112
        ctx->r1 = ADD32(0, 0X112);
            goto L_808027C0;
    }
    goto skip_0;
    // 0x808027B0: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    skip_0:
    // 0x808027B4: b           L_80802850
    // 0x808027B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802850;
    // 0x808027B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808027BC: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
L_808027C0:
    // 0x808027C0: beq         $v0, $at, L_808027DC
    if (ctx->r2 == ctx->r1) {
        // 0x808027C4: addiu       $t9, $zero, 0x1D
        ctx->r25 = ADD32(0, 0X1D);
            goto L_808027DC;
    }
    // 0x808027C4: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x808027C8: addiu       $at, $zero, 0x115
    ctx->r1 = ADD32(0, 0X115);
    // 0x808027CC: beq         $v0, $at, L_80802824
    if (ctx->r2 == ctx->r1) {
        // 0x808027D0: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_80802824;
    }
    // 0x808027D0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x808027D4: b           L_80802850
    // 0x808027D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802850;
    // 0x808027D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808027DC:
    // 0x808027DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X2A1C) << 16);
    // 0x808027E0: lwc1        $f4, 0x2A1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X2A1C));
    // 0x808027E4: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x808027E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808027EC: addiu       $t0, $zero, 0x57
    ctx->r8 = ADD32(0, 0X57);
    // 0x808027F0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808027F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808027F8: addiu       $a1, $zero, 0x17FB
    ctx->r5 = ADD32(0, 0X17FB);
    // 0x808027FC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80802800: jal         0x8008A208
    // 0x80802804: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80802804: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80802808: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080280C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802810: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80802814: jal         0x80085708
    // 0x80802818: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80802818: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    after_7:
    // 0x8080281C: b           L_80802850
    // 0x80802820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802850;
    // 0x80802820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802824:
    // 0x80802824: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x80802828: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080282C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802830: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80802834: jal         0x80085708
    // 0x80802838: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x80802838: addiu       $a3, $zero, 0x2820
    ctx->r7 = ADD32(0, 0X2820);
    after_8:
    // 0x8080283C: b           L_80802850
    // 0x80802840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802850;
    // 0x80802840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802844: b           L_80802850
    // 0x80802848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802850;
    // 0x80802848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080284C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802850:
    // 0x80802850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802854: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802858: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080285C: jr          $ra
    // 0x80802860: nop

    return;
    // 0x80802860: nop

;}
RECOMP_FUNC void func_80800AA4_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AA8: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AB0: beq         $a1, $at, L_80800AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80800AB4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800AD4;
    }
    // 0x80800AB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800AB8: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800ABC: beq         $a1, $at, L_80800AE4
    if (ctx->r5 == ctx->r1) {
        // 0x80800AC0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800AE4;
    }
    // 0x80800AC0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800AC4: beq         $a1, $at, L_80800B40
    if (ctx->r5 == ctx->r1) {
        // 0x80800AC8: nop
    
            goto L_80800B40;
    }
    // 0x80800AC8: nop

    // 0x80800ACC: b           L_80800B5C
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B5C;
    // 0x80800AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AD4:
    // 0x80800AD4: jal         0x808000A8
    // 0x80800AD8: nop

    func_808000A8_chstonedartgunhead(rdram, ctx);
        goto after_0;
    // 0x80800AD8: nop

    after_0:
    // 0x80800ADC: b           L_80800B5C
    // 0x80800AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B5C;
    // 0x80800AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AE4:
    // 0x80800AE4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800AE8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800AEC: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80800AF0: bne         $at, $zero, L_80800B04
    if (ctx->r1 != 0) {
        // 0x80800AF4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800B04;
    }
    // 0x80800AF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800AF8: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80800AFC: bnel        $at, $zero, L_80800B5C
    if (ctx->r1 != 0) {
        // 0x80800B00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B5C;
    }
    goto skip_0;
    // 0x80800B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_80800B04:
    // 0x80800B04: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800B08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B0C: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80800B10: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80800B14: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x80800B18: bne         $t0, $at, L_80800B58
    if (ctx->r8 != ctx->r1) {
        // 0x80800B1C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800B58;
    }
    // 0x80800B1C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800B20: beq         $v0, $at, L_80800B58
    if (ctx->r2 == ctx->r1) {
        // 0x80800B24: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800B58;
    }
    // 0x80800B24: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800B28: beql        $v0, $at, L_80800B5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B5C;
    }
    goto skip_1;
    // 0x80800B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800B30: jal         0x80800224
    // 0x80800B34: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800224_chstonedartgunhead(rdram, ctx);
        goto after_1;
    // 0x80800B34: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800B38: b           L_80800B5C
    // 0x80800B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B5C;
    // 0x80800B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B40:
    // 0x80800B40: jal         0x80800908
    // 0x80800B44: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800908_chstonedartgunhead(rdram, ctx);
        goto after_2;
    // 0x80800B44: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800B48: b           L_80800B5C
    // 0x80800B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B5C;
    // 0x80800B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800B50: b           L_80800B5C
    // 0x80800B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B5C;
    // 0x80800B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B58:
    // 0x80800B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B5C:
    // 0x80800B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B64: jr          $ra
    // 0x80800B68: nop

    return;
    // 0x80800B68: nop

;}
RECOMP_FUNC void func_80803CF0_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803CF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803CFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803D00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80803D04: jal         0x80100094
    // 0x80803D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803D0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803D10: lh          $t6, 0x72($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X72);
    // 0x80803D14: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80803D18: beql        $t6, $zero, L_80803D38
    if (ctx->r14 == 0) {
        // 0x80803D1C: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80803D38;
    }
    goto skip_0;
    // 0x80803D1C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80803D20: jal         0x80085710
    // 0x80803D24: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80803D24: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x80803D28: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80803D2C: ori         $t7, $a3, 0x2000
    ctx->r15 = ctx->r7 | 0X2000;
    // 0x80803D30: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80803D34: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_80803D38:
    // 0x80803D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803D3C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80803D40: jal         0x80085708
    // 0x80803D44: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80803D44: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x80803D48: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80803D4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80803D50: sh          $t9, 0x72($t0)
    MEM_H(0X72, ctx->r8) = ctx->r25;
    // 0x80803D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803D5C: jr          $ra
    // 0x80803D60: nop

    return;
    // 0x80803D60: nop

;}
RECOMP_FUNC void gcsectionskip_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003AC: addiu       $at, $zero, 0xDAA
    ctx->r1 = ADD32(0, 0XDAA);
    // 0x808003B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003B8: bne         $a1, $at, L_808003C8
    if (ctx->r5 != ctx->r1) {
        // 0x808003BC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003C8;
    }
    // 0x808003BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003C0: jal         0x800DA524
    // 0x808003C4: addiu       $a0, $zero, 0x6C9
    ctx->r4 = ADD32(0, 0X6C9);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x808003C4: addiu       $a0, $zero, 0x6C9
    ctx->r4 = ADD32(0, 0X6C9);
    after_0:
L_808003C8:
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void _sucoasterflydata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A280: syscall     832
    recomp_syscall_handler(rdram, ctx, 0x8008A280);
    return;
    // 0x8008A284: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800A266C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A266C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2674: lw          $t6, 0xB4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB4);
    // 0x800A2678: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A267C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800A2680: beq         $a1, $zero, L_800A269C
    if (ctx->r5 == 0) {
        // 0x800A2684: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800A269C;
    }
    // 0x800A2684: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A2688: jal         0x800B38E8
    // 0x800A268C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800B38E8(rdram, ctx);
        goto after_0;
    // 0x800A268C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A2690: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A2694: lw          $t7, 0xB4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XB4);
    // 0x800A2698: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
L_800A269C:
    // 0x800A269C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A26A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A26A4: jr          $ra
    // 0x800A26A8: nop

    return;
    // 0x800A26A8: nop

    // 0x800A26AC: nop

;}
RECOMP_FUNC void func_8080152C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080152C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801534: lbu         $a1, 0x1C($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X1C);
    // 0x80801538: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080153C: beq         $a1, $zero, L_80801554
    if (ctx->r5 == 0) {
        // 0x80801540: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80801554;
    }
    // 0x80801540: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80801544: jal         0x800E8C08
    // 0x80801548: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800E8C08(rdram, ctx);
        goto after_0;
    // 0x80801548: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080154C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801550: sb          $zero, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = 0;
L_80801554:
    // 0x80801554: lbu         $a0, 0x1D($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1D);
    // 0x80801558: beql        $a0, $zero, L_80801574
    if (ctx->r4 == 0) {
        // 0x8080155C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801574;
    }
    goto skip_0;
    // 0x8080155C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801560: jal         0x800E8C08
    // 0x80801564: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800E8C08(rdram, ctx);
        goto after_1;
    // 0x80801564: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80801568: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080156C: sb          $zero, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = 0;
    // 0x80801570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801574:
    // 0x80801574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801578: jr          $ra
    // 0x8080157C: nop

    return;
    // 0x8080157C: nop

;}
RECOMP_FUNC void func_8009B27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B27C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009B280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B284: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B288: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009B28C: jal         0x80098590
    // 0x8009B290: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80098590(rdram, ctx);
        goto after_0;
    // 0x8009B290: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8009B294: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009B298: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B29C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009B2A0: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x8009B2A4: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B2A8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009B2AC: jal         0x8009861C
    // 0x8009B2B0: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    func_8009861C(rdram, ctx);
        goto after_1;
    // 0x8009B2B0: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    after_1:
    // 0x8009B2B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009B2B8: bne         $v0, $at, L_8009B308
    if (ctx->r2 != ctx->r1) {
        // 0x8009B2BC: nop
    
            goto L_8009B308;
    }
    // 0x8009B2BC: nop

    // 0x8009B2C0: jal         0x80098610
    // 0x8009B2C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098610(rdram, ctx);
        goto after_2;
    // 0x8009B2C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009B2C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009B2CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B2D0: jal         0x800136E4
    // 0x8009B2D4: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x8009B2D4: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    after_3:
    // 0x8009B2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009B2DC: jal         0x80098628
    // 0x8009B2E0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80098628(rdram, ctx);
        goto after_4;
    // 0x8009B2E0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8009B2E4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009B2E8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8009B2EC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8009B2F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009B2F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8009B2F8: jal         0x800EEB9C
    // 0x8009B2FC: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x8009B2FC: nop

    after_5:
    // 0x8009B300: b           L_8009B33C
    // 0x8009B304: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B33C;
    // 0x8009B304: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B308:
    // 0x8009B308: jal         0x8009C984
    // 0x8009B30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_6;
    // 0x8009B30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8009B310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009B314: jal         0x80098628
    // 0x8009B318: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80098628(rdram, ctx);
        goto after_7;
    // 0x8009B318: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8009B31C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009B320: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8009B324: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8009B328: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8009B32C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8009B330: jal         0x800EEB9C
    // 0x8009B334: nop

    func_800EEB9C(rdram, ctx);
        goto after_8;
    // 0x8009B334: nop

    after_8:
    // 0x8009B338: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B33C:
    // 0x8009B33C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009B340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009B344: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009B348: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009B34C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8009B350: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B354: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009B358: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009B35C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8009B360: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009B364: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8009B368: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B36C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8009B370: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009B374: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8009B378: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8009B37C: lw          $t8, 0xC8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B380: swc1        $f8, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f8.u32l;
    // 0x8009B384: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B388: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8009B38C: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x8009B390: lw          $t9, 0xC8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B394: swc1        $f2, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f2.u32l;
    // 0x8009B398: lw          $t0, 0xC8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B39C: jal         0x8009B08C
    // 0x8009B3A0: swc1        $f2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f2.u32l;
    func_8009B08C(rdram, ctx);
        goto after_9;
    // 0x8009B3A0: swc1        $f2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f2.u32l;
    after_9:
    // 0x8009B3A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B3A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B3AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8009B3B0: jr          $ra
    // 0x8009B3B4: nop

    return;
    // 0x8009B3B4: nop

;}
RECOMP_FUNC void _chbonfirecavern_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086168: syscall     282
    recomp_syscall_handler(rdram, ctx, 0x80086168);
    return;
    // 0x8008616C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800C7C_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C7C: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80800C80: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80800C84: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800C88: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800C8C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80800C90: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80800C94: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800C98: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80800C9C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80800CA0: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800CA4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80800CA8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800CAC: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800CB0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800CB4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800CB8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800CBC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800CC0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800CC4: jal         0x80101870
    // 0x80800CC8: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800CC8: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800CCC: lw          $t6, 0x7C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X7C);
    // 0x80800CD0: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800CD4: bgezl       $t8, L_80800F88
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800CD8: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_80800F88;
    }
    goto skip_0;
    // 0x80800CD8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x80800CDC: jal         0x800D674C
    // 0x80800CE0: addiu       $a0, $zero, 0x9D0
    ctx->r4 = ADD32(0, 0X9D0);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800CE0: addiu       $a0, $zero, 0x9D0
    ctx->r4 = ADD32(0, 0X9D0);
    after_1:
    // 0x80800CE4: sw          $v0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r2;
    // 0x80800CE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800CEC: jal         0x80100094
    // 0x80800CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800CF4: addiu       $s7, $s2, 0x18
    ctx->r23 = ADD32(ctx->r18, 0X18);
    // 0x80800CF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800CFC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80800D00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D04: jal         0x8008A0D8
    // 0x80800D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800D0C: addiu       $s6, $sp, 0x11C
    ctx->r22 = ADD32(ctx->r29, 0X11C);
    // 0x80800D10: jal         0x800E3980
    // 0x80800D14: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E3980(rdram, ctx);
        goto after_4;
    // 0x80800D14: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x80800D18: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800D1C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800D20: jal         0x800F18FC
    // 0x80800D24: addiu       $a2, $sp, 0x108
    ctx->r6 = ADD32(ctx->r29, 0X108);
    func_800F18FC(rdram, ctx);
        goto after_5;
    // 0x80800D24: addiu       $a2, $sp, 0x108
    ctx->r6 = ADD32(ctx->r29, 0X108);
    after_5:
    // 0x80800D28: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800D2C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800D30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X140C) << 16);
    // 0x80800D34: lwc1        $f28, 0x140C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X140C));
    // 0x80800D38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D3C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800D40: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800D44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800D48: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80800D4C: addiu       $fp, $sp, 0x9C
    ctx->r30 = ADD32(ctx->r29, 0X9C);
    // 0x80800D50: addiu       $s5, $sp, 0x110
    ctx->r21 = ADD32(ctx->r29, 0X110);
L_80800D54:
    // 0x80800D54: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80800D58: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x80800D5C: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80800D60: c.eq.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl == ctx->f0.fl;
    // 0x80800D64: addiu       $s4, $s4, -0x6400
    ctx->r20 = ADD32(ctx->r20, -0X6400);
    // 0x80800D68: addu        $s0, $fp, $t9
    ctx->r16 = ADD32(ctx->r30, ctx->r25);
    // 0x80800D6C: bc1tl       L_80800F78
    if (c1cs) {
        // 0x80800D70: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80800F78;
    }
    goto skip_1;
    // 0x80800D70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x80800D74: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80800D78: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D7C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800D80: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80800D84: jal         0x800F10B4
    // 0x80800D88: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800D88: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_6:
    // 0x80800D8C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2300, 0X14D0) << 16);
    // 0x80800D90: addiu       $t0, $t0, 0x14D0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2300, 0X14D0));
    // 0x80800D94: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800D98: addiu       $t2, $t0, 0x48
    ctx->r10 = ADD32(ctx->r8, 0X48);
    // 0x80800D9C: or          $t3, $fp, $zero
    ctx->r11 = ctx->r30 | 0;
L_80800DA0:
    // 0x80800DA0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80800DA4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80800DA8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80800DAC: sw          $at, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r1;
    // 0x80800DB0: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x80800DB4: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x80800DB8: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x80800DBC: bne         $t0, $t2, L_80800DA0
    if (ctx->r8 != ctx->r10) {
        // 0x80800DC0: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_80800DA0;
    }
    // 0x80800DC0: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x80800DC4: lw          $t4, 0x64($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X64);
    // 0x80800DC8: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80800DCC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800DD0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80800DD4: bgezl       $t6, L_80800DF0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800DD8: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800DF0;
    }
    goto skip_2;
    // 0x80800DD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80800DDC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800DE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800DE4: b           L_80800DF8
    // 0x80800DE8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
        goto L_80800DF8;
    // 0x80800DE8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800DEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800DF0:
    // 0x80800DF0: nop

    // 0x80800DF4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
L_80800DF8:
    // 0x80800DF8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800DFC: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80800E00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800E04: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800E08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800E0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800E10: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800E14: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800E18: jal         0x800EEC30
    // 0x80800E1C: nop

    func_800EEC30(rdram, ctx);
        goto after_7;
    // 0x80800E1C: nop

    after_7:
    // 0x80800E20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800E24: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80800E28: jal         0x800EE780
    // 0x80800E2C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x80800E2C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_8:
    // 0x80800E30: lw          $t7, 0x64($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X64);
    // 0x80800E34: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800E38: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800E3C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800E40: bgezl       $t9, L_80800E64
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800E44: lwc1        $f22, 0x38($s2)
        ctx->f22.u32l = MEM_W(ctx->r18, 0X38);
            goto L_80800E64;
    }
    goto skip_3;
    // 0x80800E44: lwc1        $f22, 0x38($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X38);
    skip_3:
    // 0x80800E48: lwc1        $f4, 0x38($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80800E4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E50: nop

    // 0x80800E54: mul.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800E58: b           L_80800E68
    // 0x80800E5C: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
        goto L_80800E68;
    // 0x80800E5C: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80800E60: lwc1        $f22, 0x38($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X38);
L_80800E64:
    // 0x80800E64: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
L_80800E68:
    // 0x80800E68: jal         0x800F1214
    // 0x80800E6C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    func_800F1214(rdram, ctx);
        goto after_9;
    // 0x80800E6C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    after_9:
    // 0x80800E70: mul.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800E74: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x80800E78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X1410) << 16);
    // 0x80800E7C: swc1        $f2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f2.u32l;
    // 0x80800E80: swc1        $f2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f2.u32l;
    // 0x80800E84: bc1f        L_80800EB4
    if (!c1cs) {
        // 0x80800E88: swc1        $f2, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f2.u32l;
            goto L_80800EB4;
    }
    // 0x80800E88: swc1        $f2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f2.u32l;
    // 0x80800E8C: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80800E90: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800E94: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800E98: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800E9C: jal         0x800F10B4
    // 0x80800EA0: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800EA0: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    after_10:
    // 0x80800EA4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800EA8: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x80800EAC: b           L_80800EFC
    // 0x80800EB0: lw          $t0, 0x78($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X78);
        goto L_80800EFC;
    // 0x80800EB0: lw          $t0, 0x78($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X78);
L_80800EB4:
    // 0x80800EB4: lwc1        $f10, 0x1410($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1410));
    // 0x80800EB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X1414) << 16);
    // 0x80800EBC: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x80800EC0: nop

    // 0x80800EC4: bc1fl       L_80800ED8
    if (!c1cs) {
        // 0x80800EC8: mfc1        $a2, $f26
        ctx->r6 = (int32_t)ctx->f26.u32l;
            goto L_80800ED8;
    }
    goto skip_4;
    // 0x80800EC8: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    skip_4:
    // 0x80800ECC: b           L_80800EF8
    // 0x80800ED0: addiu       $s0, $zero, 0x8C
    ctx->r16 = ADD32(0, 0X8C);
        goto L_80800EF8;
    // 0x80800ED0: addiu       $s0, $zero, 0x8C
    ctx->r16 = ADD32(0, 0X8C);
    // 0x80800ED4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
L_80800ED8:
    // 0x80800ED8: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80800EDC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800EE0: lwc1        $f14, 0x1414($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X1414));
    // 0x80800EE4: jal         0x800F10B4
    // 0x80800EE8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800EE8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_11:
    // 0x80800EEC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800EF0: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x80800EF4: nop

L_80800EF8:
    // 0x80800EF8: lw          $t0, 0x78($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X78);
L_80800EFC:
    // 0x80800EFC: sra         $t5, $s0, 1
    ctx->r13 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80800F00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800F04: sll         $t4, $t0, 29
    ctx->r12 = S32(ctx->r8 << 29);
    // 0x80800F08: bgez        $t4, L_80800F14
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800F0C: nop
    
            goto L_80800F14;
    }
    // 0x80800F0C: nop

    // 0x80800F10: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_80800F14:
    // 0x80800F14: jal         0x800E24E4
    // 0x80800F18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800E24E4(rdram, ctx);
        goto after_12;
    // 0x80800F18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x80800F1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800F20: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800F24: jal         0x800E24F8
    // 0x80800F28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800E24F8(rdram, ctx);
        goto after_13;
    // 0x80800F28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x80800F2C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800F30: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800F34: jal         0x800E2440
    // 0x80800F38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800E2440(rdram, ctx);
        goto after_14;
    // 0x80800F38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_14:
    // 0x80800F3C: jal         0x800E257C
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E257C(rdram, ctx);
        goto after_15;
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800F44: jal         0x800E24B4
    // 0x80800F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E24B4(rdram, ctx);
        goto after_16;
    // 0x80800F48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80800F4C: jal         0x800E2588
    // 0x80800F50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_17;
    // 0x80800F50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x80800F54: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80800F58: addiu       $t6, $sp, 0xEC
    ctx->r14 = ADD32(ctx->r29, 0XEC);
    // 0x80800F5C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800F60: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80800F64: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x80800F68: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x80800F6C: jal         0x800E2AA4
    // 0x80800F70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800E2AA4(rdram, ctx);
        goto after_18;
    // 0x80800F70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80800F74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80800F78:
    // 0x80800F78: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800F7C: bne         $s3, $at, L_80800D54
    if (ctx->r19 != ctx->r1) {
        // 0x80800F80: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_80800D54;
    }
    // 0x80800F80: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x80800F84: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80800F88:
    // 0x80800F88: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800F8C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800F90: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800F94: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800F98: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800F9C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800FA0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800FA4: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80800FA8: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80800FAC: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80800FB0: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800FB4: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80800FB8: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80800FBC: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80800FC0: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80800FC4: jr          $ra
    // 0x80800FC8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x80800FC8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_80800358_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080035C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800360: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800364: jal         0x80101870
    // 0x80800368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080036C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800370: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800374: bgezl       $t8, L_808003E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800378: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003E0;
    }
    goto skip_0;
    // 0x80800378: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080037C: jal         0x80101970
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_1;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800384: jal         0x800DF830
    // 0x80800388: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x80800388: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8080038C: jal         0x80089C90
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800394: jal         0x800DF410
    // 0x80800398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_4;
    // 0x80800398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8080039C: jal         0x801027F4
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801027F4(rdram, ctx);
        goto after_5;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003A4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808003A8: jal         0x800D674C
    // 0x808003AC: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x808003AC: addiu       $a0, $zero, 0x6AC
    ctx->r4 = ADD32(0, 0X6AC);
    after_6:
    // 0x808003B0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003B8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808003BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808003C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003C8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808003CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808003D0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808003D4: jal         0x800DE448
    // 0x808003D8: nop

    func_800DE448(rdram, ctx);
        goto after_7;
    // 0x808003D8: nop

    after_7:
    // 0x808003DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003E0:
    // 0x808003E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void sufreezy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800004: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800018: jal         0x800DC178
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800020: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: swc1        $f0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f0.u32l;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void _baeggfire_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B40: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B40);
    return;
    // 0x80084B44: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800FCC_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FD4: jal         0x80800130
    // 0x80800FD8: nop

    func_80800130_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800FD8: nop

    after_0:
    // 0x80800FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FE4: jr          $ra
    // 0x80800FE8: nop

    return;
    // 0x80800FE8: nop

;}
RECOMP_FUNC void func_8010E334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E334: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E33C: jal         0x800B3310
    // 0x8010E340: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B3310(rdram, ctx);
        goto after_0;
    // 0x8010E340: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8010E344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E348: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E34C: sw          $v0, 0x7074($at)
    MEM_W(0X7074, ctx->r1) = ctx->r2;
    // 0x8010E350: jr          $ra
    // 0x8010E354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010E354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800E3F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3F8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E3F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3F94: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800E3F98: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x800E3F9C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E3FA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3FA4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3FA8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800E3FAC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3FB0: jal         0x800CAEA4
    // 0x800E3FB4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800CAEA4(rdram, ctx);
        goto after_0;
    // 0x800E3FB4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x800E3FB8: jal         0x800BCC58
    // 0x800E3FBC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800BCC58(rdram, ctx);
        goto after_1;
    // 0x800E3FBC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E3FC0: beq         $v0, $zero, L_800E4008
    if (ctx->r2 == 0) {
        // 0x800E3FC4: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_800E4008;
    }
    // 0x800E3FC4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800E3FC8: bne         $v1, $zero, L_800E4008
    if (ctx->r3 != 0) {
        // 0x800E3FCC: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800E4008;
    }
    // 0x800E3FCC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800E3FD0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800E3FD4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3FD8: jal         0x800EFA4C
    // 0x800E3FDC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x800E3FDC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800E3FE0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800E3FE4: jal         0x800BCC28
    // 0x800E3FE8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800BCC28(rdram, ctx);
        goto after_3;
    // 0x800E3FE8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800E3FEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3FF0: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3FF4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800E3FF8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E3FFC: jal         0x800CAEA4
    // 0x800E4000: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800CAEA4(rdram, ctx);
        goto after_4;
    // 0x800E4000: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x800E4004: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E4008:
    // 0x800E4008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E400C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E4010: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E4014: jr          $ra
    // 0x800E4018: nop

    return;
    // 0x800E4018: nop

;}
RECOMP_FUNC void subaddiemulti_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808002E0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808002E4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x808002E8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x808002EC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x808002F0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808002F4: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x808002F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808002FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800300: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800304: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080030C: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80800310: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_80800314:
    // 0x80800314: jal         0x800F6438
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080031C: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x800F5A00
    // 0x80800328: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800328: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8080032C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800330: jal         0x800EFC7C
    // 0x80800334: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x80800334: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800338: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x8080033C: lwc1        $f20, 0x54($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800340: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800344: bc1fl       L_80800390
    if (!c1cs) {
        // 0x80800348: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800390;
    }
    goto skip_0;
    // 0x80800348: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080034C: jal         0x800F1DF4
    // 0x80800350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80800350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800354: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800358: jal         0x8002DCA0
    // 0x8080035C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8080035C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_4:
    // 0x80800360: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800364: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800368: jal         0x800EEB9C
    // 0x8080036C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x8080036C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800374: jal         0x800EF04C
    // 0x80800378: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800378: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x8080037C: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x800F8418
    // 0x80800388: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F8418(rdram, ctx);
        goto after_7;
    // 0x80800388: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
L_8080038C:
    // 0x8080038C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800390:
    // 0x80800390: bne         $s0, $s3, L_80800314
    if (ctx->r16 != ctx->r19) {
        // 0x80800394: nop
    
            goto L_80800314;
    }
    // 0x80800394: nop

    // 0x80800398: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080039C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808003A0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808003A4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808003A8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x808003AC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x808003B0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x808003B4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x808003B8: jr          $ra
    // 0x808003BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808003BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void capod_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003FC: jal         0x8008FFE8
    // 0x80800400: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800400: nop

    after_0:
    // 0x80800404: beq         $v0, $zero, L_8080041C
    if (ctx->r2 == 0) {
        // 0x80800408: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080041C;
    }
    // 0x80800408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080040C: jal         0x80089598
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _ncpod_entrypoint_27(rdram, ctx);
        goto after_1;
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800414: b           L_80800424
    // 0x80800418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800424;
    // 0x80800418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080041C:
    // 0x8080041C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800424:
    // 0x80800424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

;}
RECOMP_FUNC void func_80800358_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080035C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800360: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800364: jal         0x80801020
    // 0x80800368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80801020_chbilldrillplate(rdram, ctx);
        goto after_0;
    // 0x80800368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080036C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x80100094
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080037C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800380: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800388: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080038C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800390: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800394: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800398: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8080039C: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x808003A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x808003A4: bgez        $t7, L_808003B8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808003A8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_808003B8;
    }
    // 0x808003A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003B0: nop

    // 0x808003B4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_808003B8:
    // 0x808003B8: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808003BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003C0: jal         0x8008A020
    // 0x808003C4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808003C4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x808003C8: jal         0x80089D00
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003D0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808003D4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808003D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808003DC: lhu         $t9, 0x10($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X10);
    // 0x808003E0: beql        $t9, $zero, L_808003F8
    if (ctx->r25 == 0) {
        // 0x808003E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003F8;
    }
    goto skip_0;
    // 0x808003E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003EC: nop

    // 0x808003F0: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F8:
    // 0x808003F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800400: jr          $ra
    // 0x80800404: nop

    return;
    // 0x80800404: nop

;}
RECOMP_FUNC void func_80112E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112E90: jr          $ra
    // 0x80112E94: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    return;
    // 0x80112E94: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
;}
RECOMP_FUNC void chaliendad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1364, 0X26BC) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x26BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X26BC));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x26BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X26BC));
;}
RECOMP_FUNC void func_80803048_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803048: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080304C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80803050: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80803054: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803058: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080305C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80803060: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803064: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803068: jal         0x80100094
    // 0x8080306C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080306C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80803070: lw          $t6, 0x2C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X2C);
    // 0x80803074: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803078: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080307C: blez        $t6, L_808030C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80803080: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808030C4;
    }
    // 0x80803080: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803084:
    // 0x80803084: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803088: jal         0x80087CF8
    // 0x8080308C: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x8080308C: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    after_1:
    // 0x80803090: lb          $t7, 0x2($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X2);
    // 0x80803094: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080309C: bltzl       $t7, L_808030B0
    if (SIGNED(ctx->r15) < 0) {
        // 0x808030A0: lw          $t8, 0x2C($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X2C);
            goto L_808030B0;
    }
    goto skip_0;
    // 0x808030A0: lw          $t8, 0x2C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X2C);
    skip_0:
    // 0x808030A4: jal         0x8080401C
    // 0x808030A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080401C_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808030A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808030AC: lw          $t8, 0x2C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X2C);
L_808030B0:
    // 0x808030B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808030B4: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x808030B8: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808030BC: bnel        $at, $zero, L_80803084
    if (ctx->r1 != 0) {
        // 0x808030C0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803084;
    }
    goto skip_1;
    // 0x808030C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_808030C4:
    // 0x808030C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808030C8: jal         0x80087DE0
    // 0x808030CC: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_3;
    // 0x808030CC: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    after_3:
    // 0x808030D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808030D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808030D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808030DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808030E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808030E4: jr          $ra
    // 0x808030E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808030E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084030: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084030);
    return;
    // 0x80084034: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800D2EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2EE4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D2EE8: lw          $a0, -0x4CA0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CA0);
    // 0x800D2EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2EF4: beql        $a0, $zero, L_800D2F10
    if (ctx->r4 == 0) {
        // 0x800D2EF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D2F10;
    }
    goto skip_0;
    // 0x800D2EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D2EFC: jal         0x8001BAFC
    // 0x800D2F00: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800D2F00: nop

    after_0:
    // 0x800D2F04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D2F08: sw          $v0, -0x4CA0($at)
    MEM_W(-0X4CA0, ctx->r1) = ctx->r2;
    // 0x800D2F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D2F10:
    // 0x800D2F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2F14: jr          $ra
    // 0x800D2F18: nop

    return;
    // 0x800D2F18: nop

    // 0x800D2F1C: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083790: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083790);
    return;
    // 0x80083794: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800000_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800014: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800020: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800024: beq         $t6, $zero, L_80800048
    if (ctx->r14 == 0) {
        // 0x80800028: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80800048;
    }
    // 0x80800028: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080002C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800030: beq         $t6, $at, L_80800050
    if (ctx->r14 == ctx->r1) {
        // 0x80800034: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800050;
    }
    // 0x80800034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800038: beql        $t6, $at, L_80800094
    if (ctx->r14 == ctx->r1) {
        // 0x8080003C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800094;
    }
    goto skip_0;
    // 0x8080003C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800040: b           L_808000A0
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000A0;
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800048:
    // 0x80800048: jal         0x800856B0
    // 0x8080004C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080004C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80800050:
    // 0x80800050: jal         0x800856E0
    // 0x80800054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800058: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080005C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1612, 0X124C) << 16);
    // 0x80800060: addiu       $a0, $a0, 0x124C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1612, 0X124C));
    // 0x80800064: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800068: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8080006C: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x80800070: jal         0x80088090
    // 0x80800074: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800078: jal         0x80088098
    // 0x8080007C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800080: jal         0x800880A0
    // 0x80800084: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800088: jal         0x800880B8
    // 0x8080008C: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x8080008C: nop

    after_5:
    // 0x80800090: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800094:
    // 0x80800094: jal         0x800856D8
    // 0x80800098: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800098: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007F4: jal         0x8080051C
    // 0x808007F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x808007F8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808007FC: bne         $v0, $zero, L_8080080C
    if (ctx->r2 != 0) {
        // 0x80800800: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080080C;
    }
    // 0x80800800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800804: b           L_8080081C
    // 0x80800808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080081C;
    // 0x80800808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080080C:
    // 0x8080080C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800810: jal         0x808004C8
    // 0x80800814: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    gsmaker_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x80800814: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080081C:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

    // 0x8080082C: nop

;}
RECOMP_FUNC void func_80800000_sumole(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800004: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800008: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8080000C: nop

    // 0x80800010: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800014: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80800018: jr          $ra
    // 0x8080001C: lhu         $v0, 0xC($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0XC);
    return;
    // 0x8080001C: lhu         $v0, 0xC($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0XC);
;}
RECOMP_FUNC void _bavan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085378: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085378);
    return;
    // 0x8008537C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chpowerhutwitchy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1080, 0XB70) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xB70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XB70));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xB70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XB70));
;}
RECOMP_FUNC void boot_osWritebackDCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8008AEE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AEE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008AEE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AEEC: jal         0x8008C1D4
    // 0x8008AEF0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C1D4(rdram, ctx);
        goto after_0;
    // 0x8008AEF0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008AEF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AEF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AEFC: jr          $ra
    // 0x8008AF00: nop

    return;
    // 0x8008AF00: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083688: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083688);
    return;
    // 0x8008368C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800F0C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F0C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F0C74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F0C78: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800F0C7C: jal         0x800EF2A0
    // 0x800F0C80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_0;
    // 0x800F0C80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800F0C84: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F0C88: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F0C8C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F0C90: nop

    // 0x800F0C94: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F0C98: jal         0x8002DCA0
    // 0x800F0C9C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800F0C9C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800F0CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0CA4: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F0CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F0CAC: jr          $ra
    // 0x800F0CB0: div.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    return;
    // 0x800F0CB0: div.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
;}
RECOMP_FUNC void func_800EE0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE0F8: jr          $ra
    // 0x800EE0FC: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    return;
    // 0x800EE0FC: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bsbtrot_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808027C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808027C8: jal         0x8009BC6C
    // 0x808027CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808027CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808027D0: jal         0x8080061C
    // 0x808027D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x808027D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808027D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808027DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808027E0: jr          $ra
    // 0x808027E4: nop

    return;
    // 0x808027E4: nop

;}
RECOMP_FUNC void func_800E2588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2588: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E258C: jr          $ra
    // 0x800E2590: sb          $a0, -0x2B72($at)
    MEM_B(-0X2B72, ctx->r1) = ctx->r4;
    return;
    // 0x800E2590: sb          $a0, -0x2B72($at)
    MEM_B(-0X2B72, ctx->r1) = ctx->r4;
;}
