#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808017DC_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017E4: jal         0x8080064C
    // 0x808017E8: nop

    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808017E8: nop

    after_0:
    // 0x808017EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017F4: jr          $ra
    // 0x808017F8: nop

    return;
    // 0x808017F8: nop

;}
RECOMP_FUNC void func_800E4290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4290: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4294: addiu       $v0, $v0, -0x2AFC
    ctx->r2 = ADD32(ctx->r2, -0X2AFC);
    // 0x800E4298: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800E429C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E42A0: jr          $ra
    // 0x800E42A4: sw          $zero, -0x2B00($at)
    MEM_W(-0X2B00, ctx->r1) = 0;
    return;
    // 0x800E42A4: sw          $zero, -0x2B00($at)
    MEM_W(-0X2B00, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8008FD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FD70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FD74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FD78: jal         0x800F54E4
    // 0x8008FD7C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FD7C: nop

    after_0:
    // 0x8008FD80: jal         0x800F543C
    // 0x8008FD84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F543C(rdram, ctx);
        goto after_1;
    // 0x8008FD84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FD8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FD90: jr          $ra
    // 0x8008FD94: nop

    return;
    // 0x8008FD94: nop

;}
RECOMP_FUNC void func_80800668_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080066C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800670: jal         0x8009E474
    // 0x80800674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E474(rdram, ctx);
        goto after_0;
    // 0x80800674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800678: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080067C: jal         0x80095774
    // 0x80800680: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x80800680: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_1:
    // 0x80800684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

;}
RECOMP_FUNC void yaw_setIdeal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C91C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C920: jal         0x800136E4
    // 0x8009C924: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009C924: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C928: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009C92C: lw          $t7, 0xF8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XF8);
    // 0x8009C930: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x8009C934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C93C: jr          $ra
    // 0x8009C940: nop

    return;
    // 0x8009C940: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089240: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089240);
    return;
    // 0x80089244: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _bsdronewaitbabykaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083190: syscall     49
    recomp_syscall_handler(rdram, ctx, 0x80083190);
    return;
    // 0x80083194: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void plcamera_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800204: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800208: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080020C: jal         0x800F5EF8
    // 0x80800210: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800210: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800214: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800248;
    }
    // 0x80800218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080021C: jal         0x80110014
    // 0x80800220: nop

    func_80110014(rdram, ctx);
        goto after_1;
    // 0x80800220: nop

    after_1:
    // 0x80800224: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800228: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800248;
    }
    // 0x80800228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080022C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800238: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080023C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800240: jal         0x80089448
    // 0x80800244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _ncbadeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
L_80800248:
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080024C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void _bsturn_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084100: syscall     103
    recomp_syscall_handler(rdram, ctx, 0x80084100);
    return;
    // 0x80084104: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800260_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800264: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800268: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080026C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800274: beq         $a1, $at, L_808002A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800278: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808002A8;
    }
    // 0x80800278: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080027C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800280: beq         $a1, $at, L_808002E8
    if (ctx->r5 == ctx->r1) {
        // 0x80800284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E8;
    }
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8080028C: beq         $a1, $at, L_80800330
    if (ctx->r5 == ctx->r1) {
        // 0x80800290: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1204, 0XA2C) << 16);
            goto L_80800330;
    }
    // 0x80800290: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1204, 0XA2C) << 16);
    // 0x80800294: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800298: beq         $a1, $at, L_80800344
    if (ctx->r5 == ctx->r1) {
        // 0x8080029C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800344;
    }
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: b           L_808003A8
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003A8;
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A8:
    // 0x808002A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1204, 0X8F0) << 16);
    // 0x808002AC: lh          $a1, 0x30($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X30);
    // 0x808002B0: addiu       $a2, $a2, 0x8F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1204, 0X8F0));
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x8008A1F8
    // 0x808002BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808002BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x808002C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002C4: bnel        $v0, $at, L_808002D8
    if (ctx->r2 != ctx->r1) {
        // 0x808002C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D8;
    }
    goto skip_0;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002CC: jal         0x8010A590
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D8:
    // 0x808002D8: jal         0x80102424
    // 0x808002DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808002DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x808002E0: b           L_808003A8
    // 0x808002E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x808002E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002E8:
    // 0x808002E8: jal         0x8008A4B8
    // 0x808002EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808002EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808002F0: beq         $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x808002F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800320;
    }
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: jal         0x80103110
    // 0x808002FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808002FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x8008A4B0
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x80102424
    // 0x80800314: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800314: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x80800318: b           L_808003A8
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800320:
    // 0x80800320: jal         0x808006C4
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C4_chmrsicecube(rdram, ctx);
        goto after_7;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800328: b           L_808003A8
    // 0x8080032C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x8080032C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800330:
    // 0x80800330: addiu       $a0, $a0, 0xA2C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1204, 0XA2C));
    // 0x80800334: jal         0x80088090
    // 0x80800338: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800338: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x8080033C: b           L_808003A8
    // 0x80800340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x80800340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800344:
    // 0x80800344: jal         0x80100094
    // 0x80800348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080034C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800350: jal         0x80800508
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800508_chmrsicecube(rdram, ctx);
        goto after_10;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800358: beq         $v0, $zero, L_80800370
    if (ctx->r2 == 0) {
        // 0x8080035C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800370;
    }
    // 0x8080035C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800360: jal         0x8008A028
    // 0x80800364: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800364: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x80800368: b           L_808003A8
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800370:
    // 0x80800370: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80800374: bne         $t6, $zero, L_8080038C
    if (ctx->r14 != 0) {
        // 0x80800378: nop
    
            goto L_8080038C;
    }
    // 0x80800378: nop

    // 0x8080037C: jal         0x80088848
    // 0x80800380: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_12;
    // 0x80800380: nop

    after_12:
    // 0x80800384: bnel        $v0, $zero, L_808003A8
    if (ctx->r2 != 0) {
        // 0x80800388: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003A8;
    }
    goto skip_1;
    // 0x80800388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_8080038C:
    // 0x8080038C: jal         0x800FFAB0
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800394: b           L_808003A8
    // 0x80800398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x80800398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080039C: b           L_808003A8
    // 0x808003A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003A8;
    // 0x808003A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A8:
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80800C40_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C48: jal         0x80800234
    // 0x80800C4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800C4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C54: jal         0x800845D8
    // 0x80800C58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800C58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800C5C: lui         $a2, 0x3F03
    ctx->r6 = S32(0X3F03 << 16);
    // 0x80800C60: ori         $a2, $a2, 0x46DC
    ctx->r6 = ctx->r6 | 0X46DC;
    // 0x80800C64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C68: jal         0x800845E0
    // 0x80800C6C: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800C6C: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_2:
    // 0x80800C70: jal         0x8008CABC
    // 0x80800C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80800C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800C78: lui         $a1, 0x3DD2
    ctx->r5 = S32(0X3DD2 << 16);
    // 0x80800C7C: ori         $a1, $a1, 0x1FF3
    ctx->r5 = ctx->r5 | 0X1FF3;
    // 0x80800C80: jal         0x8008B10C
    // 0x80800C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80800C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C90: jr          $ra
    // 0x80800C94: nop

    return;
    // 0x80800C94: nop

;}
RECOMP_FUNC void func_800AF2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF2F0: lhu         $t4, 0xC($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XC);
    // 0x800AF2F4: srl         $t5, $t4, 5
    ctx->r13 = S32(U32(ctx->r12) >> 5);
    // 0x800AF2F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800AF2FC: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800AF300: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800AF304: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AF308: andi        $t4, $t4, 0x1F
    ctx->r12 = ctx->r12 & 0X1F;
    // 0x800AF30C: sllv        $t5, $t5, $t4
    ctx->r13 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800AF310: and         $t6, $t6, $t5
    ctx->r14 = ctx->r14 & ctx->r13;
    // 0x800AF314: beq         $t6, $zero, L_800AF58C
    if (ctx->r14 == 0) {
        // 0x800AF318: nop
    
            goto L_800AF58C;
    }
    // 0x800AF318: nop

    // 0x800AF31C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AF320: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, -0X5B60);
    // 0x800AF324: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x800AF328: swc1        $f1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f_odd[(1 - 1) * 2];
    // 0x800AF32C: swc1        $f2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f2.u32l;
    // 0x800AF330: swc1        $f3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f_odd[(3 - 1) * 2];
    // 0x800AF334: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
    // 0x800AF338: swc1        $f5, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f_odd[(5 - 1) * 2];
    // 0x800AF33C: swc1        $f6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f6.u32l;
    // 0x800AF340: swc1        $f7, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f_odd[(7 - 1) * 2];
    // 0x800AF344: swc1        $f8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f8.u32l;
    // 0x800AF348: swc1        $f9, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f_odd[(9 - 1) * 2];
    // 0x800AF34C: swc1        $f10, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f10.u32l;
    // 0x800AF350: swc1        $f11, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f_odd[(11 - 1) * 2];
    // 0x800AF354: swc1        $f12, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f12.u32l;
    // 0x800AF358: swc1        $f13, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f_odd[(13 - 1) * 2];
    // 0x800AF35C: swc1        $f14, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f14.u32l;
    // 0x800AF360: swc1        $f15, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f_odd[(15 - 1) * 2];
    // 0x800AF364: swc1        $f16, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f16.u32l;
    // 0x800AF368: swc1        $f17, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f_odd[(17 - 1) * 2];
    // 0x800AF36C: swc1        $f18, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f18.u32l;
    // 0x800AF370: swc1        $f19, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f_odd[(19 - 1) * 2];
    // 0x800AF374: swc1        $f20, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f20.u32l;
    // 0x800AF378: swc1        $f21, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AF37C: swc1        $f22, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f22.u32l;
    // 0x800AF380: swc1        $f23, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AF384: swc1        $f24, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f24.u32l;
    // 0x800AF388: swc1        $f25, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AF38C: swc1        $f26, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->f26.u32l;
    // 0x800AF390: swc1        $f27, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AF394: swc1        $f28, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->f28.u32l;
    // 0x800AF398: swc1        $f29, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->f_odd[(29 - 1) * 2];
    // 0x800AF39C: swc1        $f30, 0x78($t4)
    MEM_W(0X78, ctx->r12) = ctx->f30.u32l;
    // 0x800AF3A0: swc1        $f31, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f_odd[(31 - 1) * 2];
    // 0x800AF3A4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800AF3A8: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800AF3AC: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x800AF3B0: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x800AF3B4: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x800AF3B8: sw          $v1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r3;
    // 0x800AF3BC: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x800AF3C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800AF3C4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AF3C8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800AF3CC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800AF3D0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800AF3D4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800AF3D8: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AF3DC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800AF3E0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800AF3E4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800AF3E8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800AF3EC: sw          $k0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r26;
    // 0x800AF3F0: sw          $k1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r27;
    // 0x800AF3F4: sw          $gp, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r28;
    // 0x800AF3F8: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800AF3FC: sdc1        $f0, 0x58($sp)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X58, ctx->r29);
    // 0x800AF400: sdc1        $f2, 0x60($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X60, ctx->r29);
    // 0x800AF404: sdc1        $f4, 0x68($sp)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X68, ctx->r29);
    // 0x800AF408: sdc1        $f6, 0x70($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X70, ctx->r29);
    // 0x800AF40C: sdc1        $f8, 0x78($sp)
    CHECK_FR(ctx, 8);
    SD(ctx->f8.u64, 0X78, ctx->r29);
    // 0x800AF410: sdc1        $f10, 0x80($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X80, ctx->r29);
    // 0x800AF414: sdc1        $f12, 0x88($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X88, ctx->r29);
    // 0x800AF418: sdc1        $f14, 0x90($sp)
    CHECK_FR(ctx, 14);
    SD(ctx->f14.u64, 0X90, ctx->r29);
    // 0x800AF41C: sdc1        $f16, 0x98($sp)
    CHECK_FR(ctx, 16);
    SD(ctx->f16.u64, 0X98, ctx->r29);
    // 0x800AF420: sdc1        $f18, 0xA0($sp)
    CHECK_FR(ctx, 18);
    SD(ctx->f18.u64, 0XA0, ctx->r29);
    // 0x800AF424: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AF428: lhu         $a1, 0xC($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XC);
    // 0x800AF42C: addiu       $a2, $a2, -0x5A60
    ctx->r6 = ADD32(ctx->r6, -0X5A60);
    // 0x800AF430: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800AF434: swc1        $f15, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f_odd[(15 - 1) * 2];
    // 0x800AF438: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x800AF43C: swc1        $f17, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f_odd[(17 - 1) * 2];
    // 0x800AF440: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AF444: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AF448: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x800AF44C: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x800AF450: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AF454: jal         0x800E0FE8
    // 0x800AF458: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    func_800E0FE8(rdram, ctx);
        goto after_0;
    // 0x800AF458: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    after_0:
    // 0x800AF45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800AF460: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AF464: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AF468: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800AF46C: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AF470: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF474: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AF478: addiu       $t4, $t4, -0x5B60
    ctx->r12 = ADD32(ctx->r12, -0X5B60);
    // 0x800AF47C: ldc1        $f0, 0x58($sp)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r29, 0X58);
    // 0x800AF480: ldc1        $f2, 0x60($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X60);
    // 0x800AF484: ldc1        $f4, 0x68($sp)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r29, 0X68);
    // 0x800AF488: ldc1        $f6, 0x70($sp)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r29, 0X70);
    // 0x800AF48C: ldc1        $f8, 0x78($sp)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r29, 0X78);
    // 0x800AF490: ldc1        $f10, 0x80($sp)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r29, 0X80);
    // 0x800AF494: ldc1        $f12, 0x88($sp)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r29, 0X88);
    // 0x800AF498: ldc1        $f14, 0x90($sp)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r29, 0X90);
    // 0x800AF49C: ldc1        $f16, 0x98($sp)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r29, 0X98);
    // 0x800AF4A0: ldc1        $f18, 0xA0($sp)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r29, 0XA0);
    // 0x800AF4A4: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800AF4A8: lwc1        $f1, 0x4($t4)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r12, 0X4);
    // 0x800AF4AC: lwc1        $f2, 0x8($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800AF4B0: lwc1        $f3, 0xC($t4)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r12, 0XC);
    // 0x800AF4B4: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800AF4B8: lwc1        $f5, 0x14($t4)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r12, 0X14);
    // 0x800AF4BC: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x800AF4C0: lwc1        $f7, 0x1C($t4)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r12, 0X1C);
    // 0x800AF4C4: lwc1        $f8, 0x20($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800AF4C8: lwc1        $f9, 0x24($t4)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r12, 0X24);
    // 0x800AF4CC: lwc1        $f10, 0x28($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X28);
    // 0x800AF4D0: lwc1        $f11, 0x2C($t4)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r12, 0X2C);
    // 0x800AF4D4: lwc1        $f12, 0x30($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X30);
    // 0x800AF4D8: lwc1        $f13, 0x34($t4)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r12, 0X34);
    // 0x800AF4DC: lwc1        $f14, 0x38($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800AF4E0: lwc1        $f15, 0x3C($t4)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r12, 0X3C);
    // 0x800AF4E4: lwc1        $f16, 0x40($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X40);
    // 0x800AF4E8: lwc1        $f17, 0x44($t4)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r12, 0X44);
    // 0x800AF4EC: lwc1        $f18, 0x48($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X48);
    // 0x800AF4F0: lwc1        $f19, 0x4C($t4)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r12, 0X4C);
    // 0x800AF4F4: lwc1        $f20, 0x50($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0X50);
    // 0x800AF4F8: lwc1        $f21, 0x54($t4)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r12, 0X54);
    // 0x800AF4FC: lwc1        $f22, 0x58($t4)
    ctx->f22.u32l = MEM_W(ctx->r12, 0X58);
    // 0x800AF500: lwc1        $f23, 0x5C($t4)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r12, 0X5C);
    // 0x800AF504: lwc1        $f24, 0x60($t4)
    ctx->f24.u32l = MEM_W(ctx->r12, 0X60);
    // 0x800AF508: lwc1        $f25, 0x64($t4)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r12, 0X64);
    // 0x800AF50C: lwc1        $f26, 0x68($t4)
    ctx->f26.u32l = MEM_W(ctx->r12, 0X68);
    // 0x800AF510: lwc1        $f27, 0x6C($t4)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r12, 0X6C);
    // 0x800AF514: lwc1        $f28, 0x70($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X70);
    // 0x800AF518: lwc1        $f29, 0x74($t4)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r12, 0X74);
    // 0x800AF51C: lwc1        $f30, 0x78($t4)
    ctx->f30.u32l = MEM_W(ctx->r12, 0X78);
    // 0x800AF520: lwc1        $f31, 0x7C($t4)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r12, 0X7C);
    // 0x800AF524: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AF528: addiu       $t4, $t4, -0x5A60
    ctx->r12 = ADD32(ctx->r12, -0X5A60);
    // 0x800AF52C: lw          $at, 0x0($sp)
    ctx->r1 = MEM_W(ctx->r29, 0X0);
    // 0x800AF530: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800AF534: lw          $v1, 0x8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8);
    // 0x800AF538: lw          $a0, 0xC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC);
    // 0x800AF53C: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x800AF540: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x800AF544: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800AF548: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF54C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800AF550: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800AF554: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800AF558: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800AF55C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800AF560: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AF564: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF568: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800AF56C: lw          $k0, 0x44($sp)
    ctx->r26 = MEM_W(ctx->r29, 0X44);
    // 0x800AF570: lw          $k1, 0x48($sp)
    ctx->r27 = MEM_W(ctx->r29, 0X48);
    // 0x800AF574: lw          $gp, 0x4C($sp)
    ctx->r28 = MEM_W(ctx->r29, 0X4C);
    // 0x800AF578: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x800AF57C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800AF580: lwc1        $f15, 0x0($t4)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r12, 0X0);
    // 0x800AF584: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800AF588: lwc1        $f17, 0x8($t4)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r12, 0X8);
L_800AF58C:
    // 0x800AF58C: jr          $ra
    // 0x800AF590: nop

    return;
    // 0x800AF590: nop

;}
RECOMP_FUNC void func_80800C20_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C2C: jal         0x808005F0
    // 0x80800C30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800C30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800C34: jal         0x8080009C
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C40: addiu       $a1, $zero, 0x132
    ctx->r5 = ADD32(0, 0X132);
    // 0x80800C44: jal         0x8008CB3C
    // 0x80800C48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800C48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80800C4C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800C50: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: jal         0x8008C9BC
    // 0x80800C5C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80800C5C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_3:
    // 0x80800C60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(296, 0X172C) << 16);
    // 0x80800C64: lwc1        $f4, 0x172C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(296, 0X172C));
    // 0x80800C68: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x80800C6C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C74: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800C78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800C7C: jal         0x8008C9F0
    // 0x80800C80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x80800C80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C88: jal         0x8008CA4C
    // 0x80800C8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_5;
    // 0x80800C8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800C90: jal         0x800909CC
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_6;
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CA4: jr          $ra
    // 0x80800CA8: nop

    return;
    // 0x80800CA8: nop

;}
RECOMP_FUNC void badata_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A7C: jal         0x80800000
    // 0x80800A80: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800A80: nop

    after_0:
    // 0x80800A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(473, 0X1664) << 16);
    // 0x80800A8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80800A90: lbu         $v0, 0x1664($at)
    ctx->r2 = MEM_BU(ctx->r1, (int16_t)RELOC_LO16(473, 0X1664));
    // 0x80800A94: jr          $ra
    // 0x80800A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800C18_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800C1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C24: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800C28: jal         0x80100094
    // 0x80800C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C30: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80800C34: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80800C38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800C3C: bnel        $t6, $zero, L_80800C6C
    if (ctx->r14 != 0) {
        // 0x80800C40: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_80800C6C;
    }
    goto skip_0;
    // 0x80800C40: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80800C44: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80800C48: lui         $a1, 0x3FCC
    ctx->r5 = S32(0X3FCC << 16);
    // 0x80800C4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800C50: beq         $t7, $zero, L_80800E88
    if (ctx->r15 == 0) {
        // 0x80800C54: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800E88;
    }
    // 0x80800C54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800C58: jal         0x800863E8
    // 0x80800C5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800C5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800C60: b           L_80800E88
    // 0x80800C64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_80800E88;
    // 0x80800C64: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800C68: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_80800C6C:
    // 0x80800C6C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800C70: bnel        $t8, $zero, L_80800D58
    if (ctx->r24 != 0) {
        // 0x80800C74: lw          $a2, 0x58($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X58);
            goto L_80800D58;
    }
    goto skip_1;
    // 0x80800C74: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x80800C78: jal         0x800C8A98
    // 0x80800C7C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800C7C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800C80: lhu         $t9, 0x10($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X10);
    // 0x80800C84: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C88: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800C8C: andi        $t0, $t9, 0x20
    ctx->r8 = ctx->r25 & 0X20;
    // 0x80800C90: bne         $t0, $zero, L_80800C9C
    if (ctx->r8 != 0) {
        // 0x80800C94: nop
    
            goto L_80800C9C;
    }
    // 0x80800C94: nop

    // 0x80800C98: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_80800C9C:
    // 0x80800C9C: jal         0x800C8F64
    // 0x80800CA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80800CA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800CA4: lh          $t1, 0x12($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X12);
    // 0x80800CA8: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800CAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CB0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800CB4: jal         0x800F0E00
    // 0x80800CB8: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800F0E00(rdram, ctx);
        goto after_4;
    // 0x80800CB8: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x80800CBC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800CC0: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x80800CC4: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800CC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CCC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800CD0: jal         0x800F0E00
    // 0x80800CD4: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x80800CD4: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x80800CD8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800CDC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800CE0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800CE4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800CE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800CEC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800CF0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CF4: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800CF8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800CFC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800D00: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800D04: jal         0x800C8E54
    // 0x80800D08: nop

    func_800C8E54(rdram, ctx);
        goto after_6;
    // 0x80800D08: nop

    after_6:
    // 0x80800D0C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800D10: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800D14: jal         0x800EE7F8
    // 0x80800D18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800D18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80800D1C: lh          $t3, 0x12($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X12);
    // 0x80800D20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11E8) << 16);
    // 0x80800D24: lwc1        $f10, 0x11E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11E8));
    // 0x80800D28: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80800D2C: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800D30: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800D34: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800D38: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800D3C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800D40: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80800D44: jal         0x800C8CB8
    // 0x80800D48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80800D48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80800D4C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800D50: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x80800D54: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
L_80800D58:
    // 0x80800D58: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800D5C: lw          $v1, 0x7C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X7C);
    // 0x80800D60: sll         $t5, $v1, 19
    ctx->r13 = S32(ctx->r3 << 19);
    // 0x80800D64: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80800D68: sltu        $v1, $zero, $t6
    ctx->r3 = 0 < ctx->r14 ? 1 : 0;
    // 0x80800D6C: bnel        $v1, $zero, L_80800DC8
    if (ctx->r3 != 0) {
        // 0x80800D70: lbu         $t1, 0x78($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X78);
            goto L_80800DC8;
    }
    goto skip_2;
    // 0x80800D70: lbu         $t1, 0x78($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X78);
    skip_2:
    // 0x80800D74: lh          $t8, 0x12($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X12);
    // 0x80800D78: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D7C: addiu       $t9, $a2, 0x4
    ctx->r25 = ADD32(ctx->r6, 0X4);
    // 0x80800D80: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800D84: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80800D88: jal         0x800F0E00
    // 0x80800D8C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800F0E00(rdram, ctx);
        goto after_9;
    // 0x80800D8C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_9:
    // 0x80800D90: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800D94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D98: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800D9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800DA0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA8: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800DAC: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800DB0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800DB4: jal         0x8010CAC0
    // 0x80800DB8: nop

    func_8010CAC0(rdram, ctx);
        goto after_10;
    // 0x80800DB8: nop

    after_10:
    // 0x80800DBC: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800DC0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800DC4: lbu         $t1, 0x78($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X78);
L_80800DC8:
    // 0x80800DC8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80800DCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800DD0: beql        $t1, $zero, L_80800DF0
    if (ctx->r9 == 0) {
        // 0x80800DD4: lw          $t2, 0x44($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X44);
            goto L_80800DF0;
    }
    goto skip_3;
    // 0x80800DD4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80800DD8: jal         0x8008A7B0
    // 0x80800DDC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    _subaddiezone_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800DDC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_11:
    // 0x80800DE0: bne         $v0, $zero, L_80800DEC
    if (ctx->r2 != 0) {
        // 0x80800DE4: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_80800DEC;
    }
    // 0x80800DE4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800DE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800DEC:
    // 0x80800DEC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_80800DF0:
    // 0x80800DF0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800DF4: bnel        $t2, $zero, L_80800E08
    if (ctx->r10 != 0) {
        // 0x80800DF8: lw          $t3, 0x74($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X74);
            goto L_80800E08;
    }
    goto skip_4;
    // 0x80800DF8: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    skip_4:
    // 0x80800DFC: beql        $a1, $zero, L_80800E8C
    if (ctx->r5 == 0) {
        // 0x80800E00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E8C;
    }
    goto skip_5;
    // 0x80800E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800E04: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
L_80800E08:
    // 0x80800E08: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800E0C: sll         $t5, $t3, 26
    ctx->r13 = S32(ctx->r11 << 26);
    // 0x80800E10: bltz        $t5, L_80800E50
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800E14: nop
    
            goto L_80800E50;
    }
    // 0x80800E14: nop

    // 0x80800E18: jal         0x800EE7F8
    // 0x80800E1C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80800E1C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_12:
    // 0x80800E20: lh          $t6, 0x12($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X12);
    // 0x80800E24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11EC) << 16);
    // 0x80800E28: lwc1        $f10, 0x11EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11EC));
    // 0x80800E2C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800E30: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800E34: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800E38: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800E3C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800E40: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800E44: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80800E48: jal         0x800C8CB8
    // 0x80800E4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C8CB8(rdram, ctx);
        goto after_13;
    // 0x80800E4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
L_80800E50:
    // 0x80800E50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11F0) << 16);
    // 0x80800E54: lwc1        $f12, 0x11F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11F0));
    // 0x80800E58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E5C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E60: jal         0x800DC178
    // 0x80800E64: nop

    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80800E64: nop

    after_14:
    // 0x80800E68: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1104, 0X12A8) << 16);
    // 0x80800E6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800E70: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1104, 0X12A8));
    // 0x80800E74: jal         0x800F2F60
    // 0x80800E78: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800F2F60(rdram, ctx);
        goto after_15;
    // 0x80800E78: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_15:
    // 0x80800E7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E80: jal         0x800C8E84
    // 0x80800E84: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8E84(rdram, ctx);
        goto after_16;
    // 0x80800E84: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_16:
L_80800E88:
    // 0x80800E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E8C:
    // 0x80800E8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E90: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800E94: jr          $ra
    // 0x80800E98: nop

    return;
    // 0x80800E98: nop

;}
RECOMP_FUNC void sukickball_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D44: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800D48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800D4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800D50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800D58: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800D5C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800D60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800D64: jal         0x800F0064
    // 0x80800D68: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F0064(rdram, ctx);
        goto after_0;
    // 0x80800D68: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80800D6C: beq         $v0, $zero, L_80800EB4
    if (ctx->r2 == 0) {
        // 0x80800D70: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(3166, 0X1228) << 16);
            goto L_80800EB4;
    }
    // 0x80800D70: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3166, 0X1228) << 16);
    // 0x80800D74: addiu       $t7, $t7, 0x1228
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3166, 0X1228));
    // 0x80800D78: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800D7C: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x80800D80: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80800D84: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800D88: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800D8C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80800D90: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800D94: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800D98: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800D9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800DA0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80800DA4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80800DA8: jal         0x800EE7F8
    // 0x80800DAC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800DAC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800DB0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800DB4: jal         0x800EE7F8
    // 0x80800DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800DBC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800DC0: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80800DC4: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80800DC8: nop

    // 0x80800DCC: bc1fl       L_80800E3C
    if (!c1cs) {
        // 0x80800DD0: sub.s       $f8, $f12, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80800E3C;
    }
    goto skip_0;
    // 0x80800DD0: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    skip_0:
    // 0x80800DD4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800DD8: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800DDC: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80800DE0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80800DE4: nop

    // 0x80800DE8: bc1fl       L_80800E3C
    if (!c1cs) {
        // 0x80800DEC: sub.s       $f8, $f12, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80800E3C;
    }
    goto skip_1;
    // 0x80800DEC: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    skip_1:
    // 0x80800DF0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800DF4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800DF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800DFC: jal         0x800DC178
    // 0x80800E00: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800E00: nop

    after_3:
    // 0x80800E04: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800E08: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80800E0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800E10: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800E14: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800E18: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E1C: jal         0x800DC178
    // 0x80800E20: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800E20: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x80800E24: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800E28: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800E2C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800E30: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80800E34: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80800E38: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
L_80800E3C:
    // 0x80800E3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11FC) << 16);
    // 0x80800E40: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800E44: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80800E48: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800E4C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80800E50: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800E54: lwc1        $f16, 0x11FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11FC));
    // 0x80800E58: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800E5C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x80800E60: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800E64: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800E68: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800E6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800E70: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800E74: jal         0x800EF368
    // 0x80800E78: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x80800E78: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E80: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800E84: jal         0x800EFB24
    // 0x80800E88: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80800E88: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x80800E8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E90: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800E94: jal         0x800EE780
    // 0x80800E98: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EE780(rdram, ctx);
        goto after_7;
    // 0x80800E98: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80800E9C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800EA4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80800EA8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800EAC: b           L_80800EB8
    // 0x80800EB0: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
        goto L_80800EB8;
    // 0x80800EB0: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80800EB4:
    // 0x80800EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EB8:
    // 0x80800EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800EC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800EC4: jr          $ra
    // 0x80800EC8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800EC8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void chfactoryempspell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808010B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808010B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808010BC: jal         0x800DA298
    // 0x808010C0: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808010C0: addiu       $a0, $zero, 0x329
    ctx->r4 = ADD32(0, 0X329);
    after_0:
    // 0x808010C4: bne         $v0, $zero, L_808010FC
    if (ctx->r2 != 0) {
        // 0x808010C8: nop
    
            goto L_808010FC;
    }
    // 0x808010C8: nop

    // 0x808010CC: jal         0x80086B58
    // 0x808010D0: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808010D0: nop

    after_1:
    // 0x808010D4: addiu       $t6, $zero, 0xA3
    ctx->r14 = ADD32(0, 0XA3);
    // 0x808010D8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x808010DC: addiu       $a0, $zero, 0x133A
    ctx->r4 = ADD32(0, 0X133A);
    // 0x808010E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808010E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808010E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808010EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808010F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808010F4: jal         0x800C0534
    // 0x808010F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C0534(rdram, ctx);
        goto after_2;
    // 0x808010F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
L_808010FC:
    // 0x808010FC: jal         0x800EA05C
    // 0x80801100: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80801100: nop

    after_3:
    // 0x80801104: addiu       $at, $zero, 0x10B
    ctx->r1 = ADD32(0, 0X10B);
    // 0x80801108: beq         $v0, $at, L_80801118
    if (ctx->r2 == ctx->r1) {
        // 0x8080110C: nop
    
            goto L_80801118;
    }
    // 0x8080110C: nop

    // 0x80801110: jal         0x800DA524
    // 0x80801114: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80801114: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_4:
L_80801118:
    // 0x80801118: jal         0x800DA524
    // 0x8080111C: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x8080111C: addiu       $a0, $zero, 0xA05
    ctx->r4 = ADD32(0, 0XA05);
    after_5:
    // 0x80801120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801128: jr          $ra
    // 0x8080112C: nop

    return;
    // 0x8080112C: nop

;}
RECOMP_FUNC void func_808001CC_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x808001E8: jal         0x80084120
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsvan_entrypoint_0(rdram, ctx);
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
RECOMP_FUNC void cheggnormal_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2124, 0X4D0) << 16);
    // 0x80800308: jr          $ra
    // 0x8080030C: addiu       $v0, $v0, 0x4D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2124, 0X4D0));
    return;
    // 0x8080030C: addiu       $v0, $v0, 0x4D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2124, 0X4D0));
;}
RECOMP_FUNC void bskazcrouch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800234: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080023C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800240: jal         0x8008CABC
    // 0x80800244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800248: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080024C: jal         0x800832E0
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800254: jal         0x8009E710
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080025C: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80800260: beq         $v0, $at, L_8080027C
    if (ctx->r2 == ctx->r1) {
        // 0x80800264: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_8080027C;
    }
    // 0x80800264: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80800268: beq         $v0, $at, L_8080027C
    if (ctx->r2 == ctx->r1) {
        // 0x8080026C: nop
    
            goto L_8080027C;
    }
    // 0x8080026C: nop

    // 0x80800270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800274: b           L_80800288
    // 0x80800278: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_80800288;
    // 0x80800278: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_8080027C:
    // 0x8080027C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(224, 0X7A4) << 16);
    // 0x80800280: lwc1        $f6, 0x7A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(224, 0X7A4));
    // 0x80800284: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80800288:
    // 0x80800288: jal         0x8008AF24
    // 0x8080028C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x8080028C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80800290: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800294: jal         0x8008AED4
    // 0x80800298: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800298: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    after_4:
    // 0x8080029C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002A0: jal         0x8008B1BC
    // 0x808002A4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808002A4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x808002A8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002AC: jal         0x8008B134
    // 0x808002B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808002B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808002B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002B8: jal         0x8008B24C
    // 0x808002BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x808002BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808002C0: jal         0x8008B064
    // 0x808002C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808002C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x8008CA4C
    // 0x808002D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_9;
    // 0x808002D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x8009C908
    // 0x808002DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_10;
    // 0x808002DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x808002E8: jal         0x8009C99C
    // 0x808002EC: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_11;
    // 0x808002EC: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_11:
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: jal         0x8009D2D8
    // 0x808002F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8009D2D8(rdram, ctx);
        goto after_12;
    // 0x808002F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x8009CFD8
    // 0x80800304: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_8009CFD8(rdram, ctx);
        goto after_13;
    // 0x80800304: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_13:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x8009B800
    // 0x80800310: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_14;
    // 0x80800310: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800314: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800318: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: jal         0x80085338
    // 0x80800324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_15;
    // 0x80800324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800328: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8080032C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: jal         0x80085338
    // 0x80800338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_16;
    // 0x80800338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x8009BB24
    // 0x80800344: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009BB24(rdram, ctx);
        goto after_17;
    // 0x80800344: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_17:
    // 0x80800348: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080034C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800350: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800354: nop

    // 0x80800358: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8080035C: jal         0x8002DCA0
    // 0x80800360: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_18;
    // 0x80800360: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_18:
    // 0x80800364: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800368: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080036C: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800370: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800374: nop

    // 0x80800378: bc1fl       L_8080038C
    if (!c1cs) {
        // 0x8080037C: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_8080038C;
    }
    goto skip_0;
    // 0x8080037C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    skip_0:
    // 0x80800380: jal         0x8009D658
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_19;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800388: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_8080038C:
    // 0x8080038C: jal         0x800F1EA4
    // 0x80800390: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F1EA4(rdram, ctx);
        goto after_20;
    // 0x80800390: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_20:
    // 0x80800394: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A4;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x8009B9C0
    // 0x808003A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_21;
    // 0x808003A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_21:
L_808003A4:
    // 0x808003A4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void _bcopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BF0: beq         $a2, $zero, L_80031C5C
    if (ctx->r6 == 0) {
        // 0x80031BF4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80031C5C;
    }
    // 0x80031BF4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80031BF8: beq         $a0, $a1, L_80031C5C
    if (ctx->r4 == ctx->r5) {
        // 0x80031BFC: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80031C5C;
    }
    // 0x80031BFC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031C00: bnel        $at, $zero, L_80031C24
    if (ctx->r1 != 0) {
        // 0x80031C04: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031C24;
    }
    goto skip_0;
    // 0x80031C04: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x80031C08: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x80031C0C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80031C10: beql        $at, $zero, L_80031C24
    if (ctx->r1 == 0) {
        // 0x80031C14: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031C24;
    }
    goto skip_1;
    // 0x80031C14: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x80031C18: b           L_80031D88
    // 0x80031C1C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_80031D88;
    // 0x80031C1C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80031C20: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031C24:
    // 0x80031C24: bne         $at, $zero, L_80031C3C
    if (ctx->r1 != 0) {
        // 0x80031C28: nop
    
            goto L_80031C3C;
    }
    // 0x80031C28: nop

    // 0x80031C2C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80031C30: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80031C34: beq         $v0, $v1, L_80031C64
    if (ctx->r2 == ctx->r3) {
        // 0x80031C38: nop
    
            goto L_80031C64;
    }
    // 0x80031C38: nop

L_80031C3C:
    // 0x80031C3C: beq         $a2, $zero, L_80031C5C
    if (ctx->r6 == 0) {
        // 0x80031C40: nop
    
            goto L_80031C5C;
    }
    // 0x80031C40: nop

    // 0x80031C44: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_80031C48:
    // 0x80031C48: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80031C4C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031C50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80031C54: bne         $a0, $v1, L_80031C48
    if (ctx->r4 != ctx->r3) {
        // 0x80031C58: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_80031C48;
    }
    // 0x80031C58: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_80031C5C:
    // 0x80031C5C: jr          $ra
    // 0x80031C60: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80031C60: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80031C64:
    // 0x80031C64: beq         $v0, $zero, L_80031CC8
    if (ctx->r2 == 0) {
        // 0x80031C68: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80031CC8;
    }
    // 0x80031C68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80031C6C: beq         $v0, $at, L_80031CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80031C70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80031CAC;
    }
    // 0x80031C70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031C74: beql        $v0, $at, L_80031C98
    if (ctx->r2 == ctx->r1) {
        // 0x80031C78: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_80031C98;
    }
    goto skip_2;
    // 0x80031C78: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x80031C7C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80031C80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031C84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80031C88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80031C8C: b           L_80031CC8
    // 0x80031C90: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_80031CC8;
    // 0x80031C90: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x80031C94: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_80031C98:
    // 0x80031C98: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80031C9C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80031CA0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80031CA4: b           L_80031CC8
    // 0x80031CA8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_80031CC8;
    // 0x80031CA8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_80031CAC:
    // 0x80031CAC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80031CB0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x80031CB4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80031CB8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80031CBC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80031CC0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x80031CC4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_80031CC8:
    // 0x80031CC8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80031CCC: bnel        $at, $zero, L_80031D28
    if (ctx->r1 != 0) {
        // 0x80031CD0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031D28;
    }
    goto skip_3;
    // 0x80031CD0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x80031CD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80031CD8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80031CDC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80031CE0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80031CE4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x80031CE8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80031CEC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x80031CF0: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x80031CF4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80031CF8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80031CFC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80031D00: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x80031D04: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x80031D08: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x80031D0C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x80031D10: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x80031D14: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x80031D18: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x80031D1C: b           L_80031CC8
    // 0x80031D20: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_80031CC8;
    // 0x80031D20: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_80031D24:
    // 0x80031D24: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031D28:
    // 0x80031D28: bnel        $at, $zero, L_80031D64
    if (ctx->r1 != 0) {
        // 0x80031D2C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80031D64;
    }
    goto skip_4;
    // 0x80031D2C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x80031D30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80031D34: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80031D38: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80031D3C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80031D40: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80031D44: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80031D48: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x80031D4C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x80031D50: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x80031D54: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x80031D58: b           L_80031D24
    // 0x80031D5C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_80031D24;
    // 0x80031D5C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_80031D60:
    // 0x80031D60: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80031D64:
    // 0x80031D64: bne         $at, $zero, L_80031C3C
    if (ctx->r1 != 0) {
        // 0x80031D68: nop
    
            goto L_80031C3C;
    }
    // 0x80031D68: nop

    // 0x80031D6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80031D70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80031D74: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80031D78: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80031D7C: b           L_80031D60
    // 0x80031D80: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_80031D60;
    // 0x80031D80: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80031D84: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031D88:
    // 0x80031D88: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80031D8C: bne         $at, $zero, L_80031DA4
    if (ctx->r1 != 0) {
        // 0x80031D90: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_80031DA4;
    }
    // 0x80031D90: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80031D94: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80031D98: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80031D9C: beq         $v0, $v1, L_80031DD4
    if (ctx->r2 == ctx->r3) {
        // 0x80031DA0: nop
    
            goto L_80031DD4;
    }
    // 0x80031DA0: nop

L_80031DA4:
    // 0x80031DA4: beq         $a2, $zero, L_80031C5C
    if (ctx->r6 == 0) {
        // 0x80031DA8: nop
    
            goto L_80031C5C;
    }
    // 0x80031DA8: nop

    // 0x80031DAC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80031DB0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80031DB4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_80031DB8:
    // 0x80031DB8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80031DBC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80031DC0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80031DC4: bne         $a0, $v1, L_80031DB8
    if (ctx->r4 != ctx->r3) {
        // 0x80031DC8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_80031DB8;
    }
    // 0x80031DC8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x80031DCC: jr          $ra
    // 0x80031DD0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80031DD0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80031DD4:
    // 0x80031DD4: beq         $v0, $zero, L_80031E38
    if (ctx->r2 == 0) {
        // 0x80031DD8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80031E38;
    }
    // 0x80031DD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80031DDC: beq         $v0, $at, L_80031E1C
    if (ctx->r2 == ctx->r1) {
        // 0x80031DE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80031E1C;
    }
    // 0x80031DE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031DE4: beql        $v0, $at, L_80031E08
    if (ctx->r2 == ctx->r1) {
        // 0x80031DE8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_80031E08;
    }
    goto skip_5;
    // 0x80031DE8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x80031DEC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80031DF0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80031DF4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80031DF8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80031DFC: b           L_80031E38
    // 0x80031E00: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80031E38;
    // 0x80031E00: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80031E04: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_80031E08:
    // 0x80031E08: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x80031E0C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80031E10: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80031E14: b           L_80031E38
    // 0x80031E18: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_80031E38;
    // 0x80031E18: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80031E1C:
    // 0x80031E1C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80031E20: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80031E24: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80031E28: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x80031E2C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80031E30: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80031E34: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80031E38:
    // 0x80031E38: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80031E3C: bnel        $at, $zero, L_80031E98
    if (ctx->r1 != 0) {
        // 0x80031E40: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80031E98;
    }
    goto skip_6;
    // 0x80031E40: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x80031E44: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80031E48: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80031E4C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80031E50: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80031E54: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80031E58: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x80031E5C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x80031E60: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x80031E64: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x80031E68: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x80031E6C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80031E70: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x80031E74: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x80031E78: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x80031E7C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x80031E80: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80031E84: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x80031E88: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80031E8C: b           L_80031E38
    // 0x80031E90: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80031E38;
    // 0x80031E90: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_80031E94:
    // 0x80031E94: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80031E98:
    // 0x80031E98: bnel        $at, $zero, L_80031ED4
    if (ctx->r1 != 0) {
        // 0x80031E9C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80031ED4;
    }
    goto skip_7;
    // 0x80031E9C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x80031EA0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80031EA4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80031EA8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80031EAC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80031EB0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80031EB4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x80031EB8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x80031EBC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80031EC0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x80031EC4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80031EC8: b           L_80031E94
    // 0x80031ECC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_80031E94;
    // 0x80031ECC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80031ED0:
    // 0x80031ED0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80031ED4:
    // 0x80031ED4: bne         $at, $zero, L_80031DA4
    if (ctx->r1 != 0) {
        // 0x80031ED8: nop
    
            goto L_80031DA4;
    }
    // 0x80031ED8: nop

    // 0x80031EDC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80031EE0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80031EE4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80031EE8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80031EEC: b           L_80031ED0
    // 0x80031EF0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80031ED0;
    // 0x80031EF0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void bainput_should_shoot_egg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097C44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097C48: jal         0x80091A58
    // 0x80097C4C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097C4C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80097C50: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097C54: beq         $t6, $zero, L_80097C6C
    if (ctx->r14 == 0) {
        // 0x80097C58: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097C6C;
    }
    // 0x80097C58: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097C5C: jal         0x8008D280
    // 0x80097C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D280(rdram, ctx);
        goto after_1;
    // 0x80097C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097C64: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097C68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097C6C:
    // 0x80097C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097C74: jr          $ra
    // 0x80097C78: nop

    return;
    // 0x80097C78: nop

;}
RECOMP_FUNC void _ncbakaztorp_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089730: syscall     791
    recomp_syscall_handler(rdram, ctx, 0x80089730);
    return;
    // 0x80089734: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800540_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080054C: jal         0x80800238
    // 0x80800550: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800238_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800550: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800554: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x80800558: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: bgez        $t6, L_80800570
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800564: lui         $a2, 0x3FA6
        ctx->r6 = S32(0X3FA6 << 16);
            goto L_80800570;
    }
    // 0x80800564: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800568: b           L_80800570
    // 0x8080056C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
        goto L_80800570;
    // 0x8080056C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
L_80800570:
    // 0x80800570: jal         0x8008CCBC
    // 0x80800574: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800574: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    after_1:
    // 0x80800578: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x8080057C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800588: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080058C: jal         0x8009FFD8
    // 0x80800590: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800590: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: jal         0x80800488
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800488_bsledge(rdram, ctx);
        goto after_3;
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: jal         0x800A0CF4
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005B4: jal         0x8009E55C
    // 0x808005B8: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x808005B8: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_5:
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005C4: jal         0x8009E53C
    // 0x808005C8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_8009E53C(rdram, ctx);
        goto after_6;
    // 0x808005C8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_6:
    // 0x808005CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005D8: jr          $ra
    // 0x808005DC: nop

    return;
    // 0x808005DC: nop

;}
RECOMP_FUNC void func_800EC124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EC128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EC12C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EC130: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EC134: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EC138: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800EC13C: jal         0x800136E4
    // 0x800EC140: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x800EC140: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    after_0:
    // 0x800EC144: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800EC148: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800EC14C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800EC150: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800EC154: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800EC158: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800EC15C: nop

    // 0x800EC160: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800EC164: beql        $t8, $zero, L_800EC1B4
    if (ctx->r24 == 0) {
        // 0x800EC168: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_800EC1B4;
    }
    goto skip_0;
    // 0x800EC168: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x800EC16C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EC170: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800EC174: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800EC178: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800EC17C: nop

    // 0x800EC180: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800EC184: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800EC188: nop

    // 0x800EC18C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800EC190: bne         $t8, $zero, L_800EC1A8
    if (ctx->r24 != 0) {
        // 0x800EC194: nop
    
            goto L_800EC1A8;
    }
    // 0x800EC194: nop

    // 0x800EC198: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800EC19C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800EC1A0: b           L_800EC1C0
    // 0x800EC1A4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800EC1C0;
    // 0x800EC1A4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800EC1A8:
    // 0x800EC1A8: b           L_800EC1C0
    // 0x800EC1AC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800EC1C0;
    // 0x800EC1AC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800EC1B0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_800EC1B4:
    // 0x800EC1B4: nop

    // 0x800EC1B8: bltz        $t8, L_800EC1A8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800EC1BC: nop
    
            goto L_800EC1A8;
    }
    // 0x800EC1BC: nop

L_800EC1C0:
    // 0x800EC1C0: lhu         $t2, 0x26($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X26);
    // 0x800EC1C4: sll         $t1, $t8, 7
    ctx->r9 = S32(ctx->r24 << 7);
    // 0x800EC1C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800EC1CC: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x800EC1D0: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800EC1D4: sh          $t4, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r12;
    // 0x800EC1D8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800EC1DC: jal         0x800136E4
    // 0x800EC1E0: lwc1        $f12, 0x4($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X4);
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x800EC1E0: lwc1        $f12, 0x4($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X4);
    after_1:
    // 0x800EC1E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800EC1E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800EC1EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800EC1F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800EC1F4: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800EC1F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800EC1FC: nop

    // 0x800EC200: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800EC204: beql        $t7, $zero, L_800EC254
    if (ctx->r15 == 0) {
        // 0x800EC208: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_800EC254;
    }
    goto skip_1;
    // 0x800EC208: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800EC20C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800EC210: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800EC214: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800EC218: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800EC21C: nop

    // 0x800EC220: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800EC224: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800EC228: nop

    // 0x800EC22C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800EC230: bne         $t7, $zero, L_800EC248
    if (ctx->r15 != 0) {
        // 0x800EC234: nop
    
            goto L_800EC248;
    }
    // 0x800EC234: nop

    // 0x800EC238: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800EC23C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800EC240: b           L_800EC260
    // 0x800EC244: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800EC260;
    // 0x800EC244: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800EC248:
    // 0x800EC248: b           L_800EC260
    // 0x800EC24C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800EC260;
    // 0x800EC24C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800EC250: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_800EC254:
    // 0x800EC254: nop

    // 0x800EC258: bltz        $t7, L_800EC248
    if (SIGNED(ctx->r15) < 0) {
        // 0x800EC25C: nop
    
            goto L_800EC248;
    }
    // 0x800EC25C: nop

L_800EC260:
    // 0x800EC260: lhu         $t2, 0x28($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X28);
    // 0x800EC264: sll         $t0, $t7, 7
    ctx->r8 = S32(ctx->r15 << 7);
    // 0x800EC268: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800EC26C: andi        $t1, $t2, 0x7F
    ctx->r9 = ctx->r10 & 0X7F;
    // 0x800EC270: or          $t3, $t0, $t1
    ctx->r11 = ctx->r8 | ctx->r9;
    // 0x800EC274: sh          $t3, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r11;
    // 0x800EC278: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800EC27C: jal         0x800136E4
    // 0x800EC280: lwc1        $f12, 0x8($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X8);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x800EC280: lwc1        $f12, 0x8($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X8);
    after_2:
    // 0x800EC284: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800EC288: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800EC28C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800EC290: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x800EC294: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800EC298: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800EC29C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EC2A0: srl         $t8, $v0, 14
    ctx->r24 = S32(U32(ctx->r2) >> 14);
    // 0x800EC2A4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800EC2A8: nop

    // 0x800EC2AC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800EC2B0: beql        $t6, $zero, L_800EC300
    if (ctx->r14 == 0) {
        // 0x800EC2B4: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_800EC300;
    }
    goto skip_2;
    // 0x800EC2B4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x800EC2B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EC2BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800EC2C0: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800EC2C4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800EC2C8: nop

    // 0x800EC2CC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800EC2D0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800EC2D4: nop

    // 0x800EC2D8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800EC2DC: bne         $t6, $zero, L_800EC2F4
    if (ctx->r14 != 0) {
        // 0x800EC2E0: nop
    
            goto L_800EC2F4;
    }
    // 0x800EC2E0: nop

    // 0x800EC2E4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800EC2E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800EC2EC: b           L_800EC30C
    // 0x800EC2F0: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800EC30C;
    // 0x800EC2F0: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800EC2F4:
    // 0x800EC2F4: b           L_800EC30C
    // 0x800EC2F8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800EC30C;
    // 0x800EC2F8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800EC2FC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_800EC300:
    // 0x800EC300: nop

    // 0x800EC304: bltz        $t6, L_800EC2F4
    if (SIGNED(ctx->r14) < 0) {
        // 0x800EC308: nop
    
            goto L_800EC2F4;
    }
    // 0x800EC308: nop

L_800EC30C:
    // 0x800EC30C: xor         $t9, $t6, $t8
    ctx->r25 = ctx->r14 ^ ctx->r24;
    // 0x800EC310: sll         $t2, $t9, 23
    ctx->r10 = S32(ctx->r25 << 23);
    // 0x800EC314: srl         $t0, $t2, 9
    ctx->r8 = S32(U32(ctx->r10) >> 9);
    // 0x800EC318: xor         $t1, $t0, $v0
    ctx->r9 = ctx->r8 ^ ctx->r2;
    // 0x800EC31C: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x800EC320: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800EC324: jal         0x800EC0EC
    // 0x800EC328: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EC0EC(rdram, ctx);
        goto after_3;
    // 0x800EC328: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x800EC32C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EC330: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EC334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EC338: jr          $ra
    // 0x800EC33C: nop

    return;
    // 0x800EC33C: nop

;}
RECOMP_FUNC void func_800A8424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8424: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A8428: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A842C: addiu       $t7, $t7, -0x5BE0
    ctx->r15 = ADD32(ctx->r15, -0X5BE0);
    // 0x800A8430: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800A8434: addiu       $t0, $t0, 0x7670
    ctx->r8 = ADD32(ctx->r8, 0X7670);
    // 0x800A8438: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800A843C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800A8440: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x800A8444: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A8448: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A844C: mflo        $t2
    ctx->r10 = lo;
    // 0x800A8450: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800A8454: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800A8458: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x800A845C: bnel        $t1, $t3, L_800A846C
    if (ctx->r9 != ctx->r11) {
        // 0x800A8460: lh          $t6, 0x2($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X2);
            goto L_800A846C;
    }
    goto skip_0;
    // 0x800A8460: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    skip_0:
    // 0x800A8464: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800A8468: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
L_800A846C:
    // 0x800A846C: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x800A8470: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8474: mflo        $t8
    ctx->r24 = lo;
    // 0x800A8478: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800A847C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800A8480: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x800A8484: beql        $t9, $zero, L_800A8494
    if (ctx->r25 == 0) {
        // 0x800A8488: lh          $t4, 0x4($v0)
        ctx->r12 = MEM_H(ctx->r2, 0X4);
            goto L_800A8494;
    }
    goto skip_1;
    // 0x800A8488: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    skip_1:
    // 0x800A848C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800A8490: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
L_800A8494:
    // 0x800A8494: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x800A8498: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A849C: mflo        $t6
    ctx->r14 = lo;
    // 0x800A84A0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800A84A4: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800A84A8: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x800A84AC: bnel        $t1, $t7, L_800A84BC
    if (ctx->r9 != ctx->r15) {
        // 0x800A84B0: lh          $t2, 0x6($v0)
        ctx->r10 = MEM_H(ctx->r2, 0X6);
            goto L_800A84BC;
    }
    goto skip_2;
    // 0x800A84B0: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    skip_2:
    // 0x800A84B4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800A84B8: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
L_800A84BC:
    // 0x800A84BC: lw          $t3, 0x10($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X10);
    // 0x800A84C0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800A84C4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A84C8: mflo        $t4
    ctx->r12 = lo;
    // 0x800A84CC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800A84D0: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x800A84D4: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800A84D8: bne         $t1, $t5, L_800A84E4
    if (ctx->r9 != ctx->r13) {
        // 0x800A84DC: nop
    
            goto L_800A84E4;
    }
    // 0x800A84DC: nop

    // 0x800A84E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800A84E4:
    // 0x800A84E4: jr          $ra
    // 0x800A84E8: nop

    return;
    // 0x800A84E8: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800434: beq         $a1, $zero, L_8080045C
    if (ctx->r5 == 0) {
        // 0x80800438: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080045C;
    }
    // 0x80800438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080043C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80800440: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80800444: beql        $t6, $at, L_80800478
    if (ctx->r14 == ctx->r1) {
        // 0x80800448: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800478;
    }
    goto skip_0;
    // 0x80800448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080044C: jal         0x80800144
    // 0x80800450: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    func_80800144_scinfobar(rdram, ctx);
        goto after_0;
    // 0x80800450: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    after_0:
    // 0x80800454: b           L_80800478
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800478;
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080045C:
    // 0x8080045C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80800460: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800464: beql        $t7, $at, L_80800478
    if (ctx->r15 == ctx->r1) {
        // 0x80800468: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800478;
    }
    goto skip_1;
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8080046C: jal         0x80800144
    // 0x80800470: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    func_80800144_scinfobar(rdram, ctx);
        goto after_1;
    // 0x80800470: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    after_1:
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800478:
    // 0x80800478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080047C: jr          $ra
    // 0x80800480: nop

    return;
    // 0x80800480: nop

;}
RECOMP_FUNC void _suspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DA8: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DA8);
    return;
    // 0x80089DAC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bstntswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080041C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(408, 0X9B0) << 16);
    // 0x80800420: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800424: jr          $ra
    // 0x80800428: lw          $v0, 0x9B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9B0));
    return;
    // 0x80800428: lw          $v0, 0x9B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9B0));
;}
RECOMP_FUNC void _bsblongleg_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A40: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A40);
    return;
    // 0x80082A44: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_800F5D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5D18: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5D20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5D28: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5D2C: jal         0x800F40EC
    // 0x800F5D30: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F40EC(rdram, ctx);
        goto after_0;
    // 0x800F5D30: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5D3C: jr          $ra
    // 0x800F5D40: nop

    return;
    // 0x800F5D40: nop

;}
RECOMP_FUNC void baanim_setEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CED8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008CEDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CEE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008CEE4: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008CEE8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8008CEEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008CEF0: jal         0x8008B1D4
    // 0x8008CEF4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_0;
    // 0x8008CEF4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8008CEF8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008CEFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CF00: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8008CF04: jal         0x8008B134
    // 0x8008CF08: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_1;
    // 0x8008CF08: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8008CF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CF10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CF14: jr          $ra
    // 0x8008CF18: nop

    return;
    // 0x8008CF18: nop

;}
RECOMP_FUNC void _sudeflect_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F28: syscall     816
    recomp_syscall_handler(rdram, ctx, 0x80089F28);
    return;
    // 0x80089F2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800AA0_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800AA4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80800AA8: bgez        $t6, L_80800AB8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800AAC: nop
    
            goto L_80800AB8;
    }
    // 0x80800AAC: nop

    // 0x80800AB0: jr          $ra
    // 0x80800AB4: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
    return;
    // 0x80800AB4: addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
L_80800AB8:
    // 0x80800AB8: jr          $ra
    // 0x80800ABC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800ABC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800D8070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8070: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D8074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D8078: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D807C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800D8080: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800D8084: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800D8088: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800D808C: jal         0x80105494
    // 0x800D8090: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x800D8090: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_0:
    // 0x800D8094: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800D8098: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D809C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D80A0: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800D80A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D80A8: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800D80AC: sra         $t8, $t7, 22
    ctx->r24 = S32(SIGNED(ctx->r15) >> 22);
    // 0x800D80B0: bnel        $t8, $at, L_800D80C4
    if (ctx->r24 != ctx->r1) {
        // 0x800D80B4: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_800D80C4;
    }
    goto skip_0;
    // 0x800D80B4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800D80B8: b           L_800D8574
    // 0x800D80BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D8574;
    // 0x800D80BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D80C0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
L_800D80C4:
    // 0x800D80C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D80C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D80CC: sll         $t9, $a0, 21
    ctx->r25 = S32(ctx->r4 << 21);
    // 0x800D80D0: sra         $a0, $t9, 22
    ctx->r4 = S32(SIGNED(ctx->r25) >> 22);
    // 0x800D80D4: jal         0x800D75DC
    // 0x800D80D8: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    func_800D75DC(rdram, ctx);
        goto after_1;
    // 0x800D80D8: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800D80DC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800D80E0: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800D80E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D80E8: nop

    // 0x800D80EC: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x800D80F0: nop

    // 0x800D80F4: bc1fl       L_800D81B0
    if (!c1cs) {
        // 0x800D80F8: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800D81B0;
    }
    goto skip_1;
    // 0x800D80F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_1:
    // 0x800D80FC: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x800D8100: sll         $t2, $t1, 19
    ctx->r10 = S32(ctx->r9 << 19);
    // 0x800D8104: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x800D8108: bnel        $t3, $zero, L_800D81B0
    if (ctx->r11 != 0) {
        // 0x800D810C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800D81B0;
    }
    goto skip_2;
    // 0x800D810C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x800D8110: lhu         $t4, 0x2A($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2A);
    // 0x800D8114: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x800D8118: bnel        $t5, $zero, L_800D81B0
    if (ctx->r13 != 0) {
        // 0x800D811C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800D81B0;
    }
    goto skip_3;
    // 0x800D811C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_3:
    // 0x800D8120: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800D8124: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800D8128: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x800D812C: bnel        $t8, $zero, L_800D81B0
    if (ctx->r24 != 0) {
        // 0x800D8130: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800D81B0;
    }
    goto skip_4;
    // 0x800D8130: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_4:
    // 0x800D8134: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D8138: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D813C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D8140: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800D8144: nop

    // 0x800D8148: bc1fl       L_800D81B0
    if (!c1cs) {
        // 0x800D814C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800D81B0;
    }
    goto skip_5;
    // 0x800D814C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_5:
    // 0x800D8150: jal         0x8001B798
    // 0x800D8154: lh          $a0, -0x400C($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400C);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x800D8154: lh          $a0, -0x400C($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400C);
    after_2:
    // 0x800D8158: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800D815C: sll         $t0, $t9, 21
    ctx->r8 = S32(ctx->r25 << 21);
    // 0x800D8160: sra         $t1, $t0, 22
    ctx->r9 = S32(SIGNED(ctx->r8) >> 22);
    // 0x800D8164: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800D8168: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800D816C: jal         0x8001B798
    // 0x800D8170: lh          $a0, 0x0($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X0);
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x800D8170: lh          $a0, 0x0($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X0);
    after_3:
    // 0x800D8174: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800D8178: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800D817C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D8180: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800D8184: jal         0x800C8070
    // 0x800D8188: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_800C8070(rdram, ctx);
        goto after_4;
    // 0x800D8188: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_4:
    // 0x800D818C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800D8190: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800D8194: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D8198: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800D819C: jal         0x800C7A68
    // 0x800D81A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800C7A68(rdram, ctx);
        goto after_5;
    // 0x800D81A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_5:
    // 0x800D81A4: b           L_800D82EC
    // 0x800D81A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_800D82EC;
    // 0x800D81A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D81AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_800D81B0:
    // 0x800D81B0: nop

    // 0x800D81B4: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800D81B8: nop

    // 0x800D81BC: bc1tl       L_800D8220
    if (c1cs) {
        // 0x800D81C0: lhu         $v0, 0x2A($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X2A);
            goto L_800D8220;
    }
    goto skip_6;
    // 0x800D81C0: lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2A);
    skip_6:
    // 0x800D81C4: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800D81C8: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D81CC: bgez        $t6, L_800D81E4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D81D0: nop
    
            goto L_800D81E4;
    }
    // 0x800D81D0: nop

    // 0x800D81D4: jal         0x800885F8
    // 0x800D81D8: nop

    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x800D81D8: nop

    after_6:
    // 0x800D81DC: b           L_800D81F0
    // 0x800D81E0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
        goto L_800D81F0;
    // 0x800D81E0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
L_800D81E4:
    // 0x800D81E4: jal         0x800D8FF8
    // 0x800D81E8: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x800D81E8: nop

    after_7:
    // 0x800D81EC: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
L_800D81F0:
    // 0x800D81F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D81F4: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800D81F8: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800D81FC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800D8200: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800D8204: nop

    // 0x800D8208: bc1fl       L_800D8220
    if (!c1cs) {
        // 0x800D820C: lhu         $v0, 0x2A($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X2A);
            goto L_800D8220;
    }
    goto skip_7;
    // 0x800D820C: lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2A);
    skip_7:
    // 0x800D8210: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D8214: nop

    // 0x800D8218: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800D821C: lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2A);
L_800D8220:
    // 0x800D8220: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x800D8224: beql        $t7, $zero, L_800D8288
    if (ctx->r15 == 0) {
        // 0x800D8228: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800D8288;
    }
    goto skip_8;
    // 0x800D8228: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_8:
    // 0x800D822C: jal         0x80082668
    // 0x800D8230: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    _seqdefine_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x800D8230: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    after_8:
    // 0x800D8234: jal         0x800DA298
    // 0x800D8238: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x800D8238: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x800D823C: beql        $v0, $zero, L_800D8288
    if (ctx->r2 == 0) {
        // 0x800D8240: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800D8288;
    }
    goto skip_9;
    // 0x800D8240: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_9:
    // 0x800D8244: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800D8248: sll         $t0, $t8, 25
    ctx->r8 = S32(ctx->r24 << 25);
    // 0x800D824C: bgezl       $t0, L_800D827C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D8250: lhu         $t4, 0x2A($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X2A);
            goto L_800D827C;
    }
    goto skip_10;
    // 0x800D8250: lhu         $t4, 0x2A($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2A);
    skip_10:
    // 0x800D8254: lbu         $t1, 0x2B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2B);
    // 0x800D8258: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x800D825C: sb          $t2, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r10;
    // 0x800D8260: lhu         $a0, 0x2A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2A);
    // 0x800D8264: srl         $t3, $a0, 7
    ctx->r11 = S32(U32(ctx->r4) >> 7);
    // 0x800D8268: jal         0x80082668
    // 0x800D826C: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
    _seqdefine_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x800D826C: addiu       $a0, $t3, -0x1
    ctx->r4 = ADD32(ctx->r11, -0X1);
    after_10:
    // 0x800D8270: jal         0x800DA524
    // 0x800D8274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x800D8274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x800D8278: lhu         $t4, 0x2A($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2A);
L_800D827C:
    // 0x800D827C: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x800D8280: sh          $t5, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r13;
    // 0x800D8284: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800D8288:
    // 0x800D8288: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D828C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D8290: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800D8294: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x800D8298: beq         $t7, $zero, L_800D82B8
    if (ctx->r15 == 0) {
        // 0x800D829C: addu        $t8, $t8, $t7
        ctx->r24 = ADD32(ctx->r24, ctx->r15);
            goto L_800D82B8;
    }
    // 0x800D829C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800D82A0: lbu         $t8, -0x4191($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4191);
    // 0x800D82A4: bnel        $t8, $zero, L_800D82BC
    if (ctx->r24 != 0) {
        // 0x800D82A8: lwc1        $f12, 0x2C($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_800D82BC;
    }
    goto skip_11;
    // 0x800D82A8: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    skip_11:
    // 0x800D82AC: lhu         $t9, 0x28($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X28);
    // 0x800D82B0: andi        $t0, $t9, 0xFC03
    ctx->r8 = ctx->r25 & 0XFC03;
    // 0x800D82B4: sh          $t0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r8;
L_800D82B8:
    // 0x800D82B8: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
L_800D82BC:
    // 0x800D82BC: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800D82C0: nop

    // 0x800D82C4: bc1fl       L_800D82EC
    if (!c1cs) {
        // 0x800D82C8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800D82EC;
    }
    goto skip_12;
    // 0x800D82C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_12:
    // 0x800D82CC: jal         0x80085720
    // 0x800D82D0: nop

    _capod_entrypoint_16(rdram, ctx);
        goto after_12;
    // 0x800D82D0: nop

    after_12:
    // 0x800D82D4: beql        $v0, $zero, L_800D82EC
    if (ctx->r2 == 0) {
        // 0x800D82D8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800D82EC;
    }
    goto skip_13;
    // 0x800D82D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x800D82DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D82E0: nop

    // 0x800D82E4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x800D82E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800D82EC:
    // 0x800D82EC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800D82F0: sll         $t1, $a0, 21
    ctx->r9 = S32(ctx->r4 << 21);
    // 0x800D82F4: jal         0x800D75DC
    // 0x800D82F8: sra         $a0, $t1, 22
    ctx->r4 = S32(SIGNED(ctx->r9) >> 22);
    func_800D75DC(rdram, ctx);
        goto after_13;
    // 0x800D82F8: sra         $a0, $t1, 22
    ctx->r4 = S32(SIGNED(ctx->r9) >> 22);
    after_13:
    // 0x800D82FC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800D8300: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800D8304: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800D8308: bnel        $t4, $zero, L_800D8334
    if (ctx->r12 != 0) {
        // 0x800D830C: lw          $t8, 0x5C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X5C);
            goto L_800D8334;
    }
    goto skip_14;
    // 0x800D830C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    skip_14:
    // 0x800D8310: lbu         $t6, 0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3);
    // 0x800D8314: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8318: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800D831C: sb          $t7, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r15;
    // 0x800D8320: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800D8324: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800D8328: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x800D832C: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x800D8330: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
L_800D8334:
    // 0x800D8334: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8338: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800D833C: bne         $t8, $v0, L_800D8360
    if (ctx->r24 != ctx->r2) {
        // 0x800D8340: nop
    
            goto L_800D8360;
    }
    // 0x800D8340: nop

    // 0x800D8344: bne         $t9, $zero, L_800D8360
    if (ctx->r25 != 0) {
        // 0x800D8348: lw          $a1, 0x64($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X64);
            goto L_800D8360;
    }
    // 0x800D8348: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D834C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800D8350: jal         0x800D7948
    // 0x800D8354: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    func_800D7948(rdram, ctx);
        goto after_14;
    // 0x800D8354: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    after_14:
    // 0x800D8358: b           L_800D8574
    // 0x800D835C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D8574;
    // 0x800D835C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D8360:
    // 0x800D8360: jal         0x800D7DE8
    // 0x800D8364: nop

    func_800D7DE8(rdram, ctx);
        goto after_15;
    // 0x800D8364: nop

    after_15:
    // 0x800D8368: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D836C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800D8370: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800D8374: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800D8378: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800D837C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800D8380: bc1fl       L_800D845C
    if (!c1cs) {
        // 0x800D8384: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_800D845C;
    }
    goto skip_15;
    // 0x800D8384: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_15:
    // 0x800D8388: bne         $t0, $zero, L_800D83D0
    if (ctx->r8 != 0) {
        // 0x800D838C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D83D0;
    }
    // 0x800D838C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8390: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D8394: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D8398: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800D839C: sll         $t1, $a1, 21
    ctx->r9 = S32(ctx->r5 << 21);
    // 0x800D83A0: sra         $a1, $t1, 22
    ctx->r5 = S32(SIGNED(ctx->r9) >> 22);
    // 0x800D83A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D83A8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D83AC: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800D83B0: jal         0x800D7E38
    // 0x800D83B4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    func_800D7E38(rdram, ctx);
        goto after_16;
    // 0x800D83B4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    after_16:
    // 0x800D83B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D83BC: bne         $v0, $at, L_800D8508
    if (ctx->r2 != ctx->r1) {
        // 0x800D83C0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800D8508;
    }
    // 0x800D83C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D83C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D83C8: b           L_800D8508
    // 0x800D83CC: sw          $t4, -0x4004($at)
    MEM_W(-0X4004, ctx->r1) = ctx->r12;
        goto L_800D8508;
    // 0x800D83CC: sw          $t4, -0x4004($at)
    MEM_W(-0X4004, ctx->r1) = ctx->r12;
L_800D83D0:
    // 0x800D83D0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D83D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D83D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D83DC: sll         $t5, $a1, 21
    ctx->r13 = S32(ctx->r5 << 21);
    // 0x800D83E0: sra         $a1, $t5, 22
    ctx->r5 = S32(SIGNED(ctx->r13) >> 22);
    // 0x800D83E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D83E8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800D83EC: jal         0x800D7E38
    // 0x800D83F0: addiu       $a3, $zero, -0x270F
    ctx->r7 = ADD32(0, -0X270F);
    func_800D7E38(rdram, ctx);
        goto after_17;
    // 0x800D83F0: addiu       $a3, $zero, -0x270F
    ctx->r7 = ADD32(0, -0X270F);
    after_17:
    // 0x800D83F4: bne         $v0, $zero, L_800D8508
    if (ctx->r2 != 0) {
        // 0x800D83F8: nop
    
            goto L_800D8508;
    }
    // 0x800D83F8: nop

    // 0x800D83FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D8400: sll         $t8, $a0, 21
    ctx->r24 = S32(ctx->r4 << 21);
    // 0x800D8404: jal         0x800D7520
    // 0x800D8408: sra         $a0, $t8, 22
    ctx->r4 = S32(SIGNED(ctx->r24) >> 22);
    func_800D7520(rdram, ctx);
        goto after_18;
    // 0x800D8408: sra         $a0, $t8, 22
    ctx->r4 = S32(SIGNED(ctx->r24) >> 22);
    after_18:
    // 0x800D840C: jal         0x800C7E28
    // 0x800D8410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C7E28(rdram, ctx);
        goto after_19;
    // 0x800D8410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x800D8414: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D8418: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D841C: sll         $t0, $a0, 21
    ctx->r8 = S32(ctx->r4 << 21);
    // 0x800D8420: jal         0x800D75DC
    // 0x800D8424: sra         $a0, $t0, 22
    ctx->r4 = S32(SIGNED(ctx->r8) >> 22);
    func_800D75DC(rdram, ctx);
        goto after_20;
    // 0x800D8424: sra         $a0, $t0, 22
    ctx->r4 = S32(SIGNED(ctx->r8) >> 22);
    after_20:
    // 0x800D8428: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D842C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D8430: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800D8434: sll         $t2, $a1, 21
    ctx->r10 = S32(ctx->r5 << 21);
    // 0x800D8438: sra         $a1, $t2, 22
    ctx->r5 = S32(SIGNED(ctx->r10) >> 22);
    // 0x800D843C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D8440: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8444: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D8448: jal         0x800D7E38
    // 0x800D844C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    func_800D7E38(rdram, ctx);
        goto after_21;
    // 0x800D844C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    after_21:
    // 0x800D8450: b           L_800D8508
    // 0x800D8454: nop

        goto L_800D8508;
    // 0x800D8454: nop

    // 0x800D8458: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800D845C:
    // 0x800D845C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800D8460: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800D8464: nop

    // 0x800D8468: bc1f        L_800D8508
    if (!c1cs) {
        // 0x800D846C: nop
    
            goto L_800D8508;
    }
    // 0x800D846C: nop

    // 0x800D8470: bne         $t5, $zero, L_800D84B0
    if (ctx->r13 != 0) {
        // 0x800D8474: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D84B0;
    }
    // 0x800D8474: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8478: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D847C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800D8480: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800D8484: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D8488: sll         $t6, $a1, 21
    ctx->r14 = S32(ctx->r5 << 21);
    // 0x800D848C: sra         $a1, $t6, 22
    ctx->r5 = S32(SIGNED(ctx->r14) >> 22);
    // 0x800D8490: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800D8494: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D8498: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D849C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800D84A0: jal         0x800D7E38
    // 0x800D84A4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    func_800D7E38(rdram, ctx);
        goto after_22;
    // 0x800D84A4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_22:
    // 0x800D84A8: b           L_800D8508
    // 0x800D84AC: nop

        goto L_800D8508;
    // 0x800D84AC: nop

L_800D84B0:
    // 0x800D84B0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D84B4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800D84B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D84BC: sll         $t9, $a1, 21
    ctx->r25 = S32(ctx->r5 << 21);
    // 0x800D84C0: sra         $a1, $t9, 22
    ctx->r5 = S32(SIGNED(ctx->r25) >> 22);
    // 0x800D84C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800D84C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D84CC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800D84D0: jal         0x800D7E38
    // 0x800D84D4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_800D7E38(rdram, ctx);
        goto after_23;
    // 0x800D84D4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_23:
    // 0x800D84D8: bne         $v0, $zero, L_800D8508
    if (ctx->r2 != 0) {
        // 0x800D84DC: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D8508;
    }
    // 0x800D84DC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D84E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800D84E4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800D84E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800D84EC: sll         $t2, $a1, 21
    ctx->r10 = S32(ctx->r5 << 21);
    // 0x800D84F0: sra         $a1, $t2, 22
    ctx->r5 = S32(SIGNED(ctx->r10) >> 22);
    // 0x800D84F4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800D84F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D84FC: addiu       $a2, $zero, -0x270F
    ctx->r6 = ADD32(0, -0X270F);
    // 0x800D8500: jal         0x800D7E38
    // 0x800D8504: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    func_800D7E38(rdram, ctx);
        goto after_24;
    // 0x800D8504: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_24:
L_800D8508:
    // 0x800D8508: jal         0x800D7DE8
    // 0x800D850C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800D7DE8(rdram, ctx);
        goto after_25;
    // 0x800D850C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_25:
    // 0x800D8510: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800D8514: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D8518: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D851C: beq         $t5, $v0, L_800D8538
    if (ctx->r13 == ctx->r2) {
        // 0x800D8520: lw          $a1, 0x64($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X64);
            goto L_800D8538;
    }
    // 0x800D8520: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D8524: beq         $t5, $v0, L_800D854C
    if (ctx->r13 == ctx->r2) {
        // 0x800D8528: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_800D854C;
    }
    // 0x800D8528: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800D852C: andi        $t7, $t6, 0x3F00
    ctx->r15 = ctx->r14 & 0X3F00;
    // 0x800D8530: beql        $t5, $t7, L_800D8550
    if (ctx->r13 == ctx->r15) {
        // 0x800D8534: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_800D8550;
    }
    goto skip_16;
    // 0x800D8534: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    skip_16:
L_800D8538:
    // 0x800D8538: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800D853C: jal         0x800D7948
    // 0x800D8540: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    func_800D7948(rdram, ctx);
        goto after_26;
    // 0x800D8540: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    after_26:
    // 0x800D8544: b           L_800D8574
    // 0x800D8548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D8574;
    // 0x800D8548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D854C:
    // 0x800D854C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_800D8550:
    // 0x800D8550: addiu       $at, $zero, -0x3F01
    ctx->r1 = ADD32(0, -0X3F01);
    // 0x800D8554: andi        $t0, $v1, 0x3F00
    ctx->r8 = ctx->r3 & 0X3F00;
    // 0x800D8558: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D855C: or          $a1, $t9, $t0
    ctx->r5 = ctx->r25 | ctx->r8;
    // 0x800D8560: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8564: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800D8568: jal         0x800D7948
    // 0x800D856C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    func_800D7948(rdram, ctx);
        goto after_27;
    // 0x800D856C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    after_27:
    // 0x800D8570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D8574:
    // 0x800D8574: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D8578: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D857C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800D8580: jr          $ra
    // 0x800D8584: nop

    return;
    // 0x800D8584: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(256, 0XC40) << 16);
    // 0x808004B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004BC: jr          $ra
    // 0x808004C0: lw          $v0, 0xC40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC40));
    return;
    // 0x808004C0: lw          $v0, 0xC40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC40));
;}
RECOMP_FUNC void func_808000A8_chfactorysmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000AC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1184, 0X148) << 16);
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000B8: addiu       $t6, $t6, 0x148
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1184, 0X148));
    // 0x808000BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000CC: jal         0x800BBCB8
    // 0x808000D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

    // 0x808000E4: nop

    // 0x808000E8: nop

    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800544_chwaspstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800548: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080054C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800550: jal         0x800F54E4
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800558: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080055C: jal         0x800F64A4
    // 0x80800560: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800560: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x80800564: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800568: beq         $a1, $zero, L_8080057C
    if (ctx->r5 == 0) {
        // 0x8080056C: nop
    
            goto L_8080057C;
    }
    // 0x8080056C: nop

    // 0x80800570: jal         0x800DA298
    // 0x80800574: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800574: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    after_2:
    // 0x80800578: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
L_8080057C:
    // 0x8080057C: jal         0x800DA3B8
    // 0x80800580: addiu       $a0, $zero, 0x9FD
    ctx->r4 = ADD32(0, 0X9FD);
    func_800DA3B8(rdram, ctx);
        goto after_3;
    // 0x80800580: addiu       $a0, $zero, 0x9FD
    ctx->r4 = ADD32(0, 0X9FD);
    after_3:
    // 0x80800584: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800588: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080058C: lui         $at, 0x43AD
    ctx->r1 = S32(0X43AD << 16);
    // 0x80800590: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800594: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800598: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080059C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808005A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808005A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808005A8: addiu       $t6, $zero, 0x83
    ctx->r14 = ADD32(0, 0X83);
    // 0x808005AC: addiu       $t7, $zero, 0x9FD
    ctx->r15 = ADD32(0, 0X9FD);
    // 0x808005B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808005B4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808005B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005BC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808005C0: jal         0x80086898
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x800868A8
    // 0x808005D0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808005D0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x800868B0
    // 0x808005DC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x808005DC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_6:
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E4: jal         0x800868C0
    // 0x808005E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x808005E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005F4: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x808005F8: jal         0x800868C8
    // 0x808005FC: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808005FC: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    after_8:
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800608: jal         0x800868D0
    // 0x8080060C: addiu       $a2, $zero, 0x3DF
    ctx->r6 = ADD32(0, 0X3DF);
    _chdoormake_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x8080060C: addiu       $a2, $zero, 0x3DF
    ctx->r6 = ADD32(0, 0X3DF);
    after_9:
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void func_8009700C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009700C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80097010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80097018: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009701C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80097020: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80097024: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80097028: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8009702C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80097030: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80097034: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80097038: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8009703C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80097040: jal         0x800EFA4C
    // 0x80097044: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80097044: nop

    after_0:
    // 0x80097048: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009704C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80097050: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80097054: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80097058: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8009705C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80097060: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80097064: jal         0x800EFA4C
    // 0x80097068: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80097068: nop

    after_1:
    // 0x8009706C: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x80097070: ori         $a3, $a3, 0x25
    ctx->r7 = ctx->r7 | 0X25;
    // 0x80097074: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80097078: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8009707C: jal         0x800C6A7C
    // 0x80097080: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x80097080: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80097084: beq         $v0, $zero, L_80097094
    if (ctx->r2 == 0) {
        // 0x80097088: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80097094;
    }
    // 0x80097088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009708C: b           L_80097098
    // 0x80097090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80097098;
    // 0x80097090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80097094:
    // 0x80097094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097098:
    // 0x80097098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009709C: jr          $ra
    // 0x800970A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800970A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808002A4_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808002A8: lbu         $t6, 0x7610($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7610);
    // 0x808002AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: bne         $t6, $zero, L_808002CC
    if (ctx->r14 != 0) {
        // 0x808002B8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808002CC;
    }
    // 0x808002B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002BC: jal         0x80800710
    // 0x808002C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800710_chcredits(rdram, ctx);
        goto after_0;
    // 0x808002C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808002C4: b           L_808002D8
    // 0x808002C8: nop

        goto L_808002D8;
    // 0x808002C8: nop

L_808002CC:
    // 0x808002CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: jal         0x80800710
    // 0x808002D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800710_chcredits(rdram, ctx);
        goto after_1;
    // 0x808002D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_808002D8:
    // 0x808002D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808002DC: jal         0x8080003C
    // 0x808002E0: lbu         $a0, 0x7610($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7610);
    func_8080003C_chcredits(rdram, ctx);
        goto after_2;
    // 0x808002E0: lbu         $a0, 0x7610($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7610);
    after_2:
    // 0x808002E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002E8: jal         0x808003E8
    // 0x808002EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808003E8_chcredits(rdram, ctx);
        goto after_3;
    // 0x808002EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x808002F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void func_800A6FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6FF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6FF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A6FFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7000: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x800A7004: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800A7008: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A700C: jal         0x800F5A00
    // 0x800A7010: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x800A7010: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800A7014: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A7018: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x800A701C: jal         0x800F5628
    // 0x800A7020: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F5628(rdram, ctx);
        goto after_1;
    // 0x800A7020: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800A7024: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x800A7028: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x800A702C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A7030: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A7034: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x800A7038: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800A703C: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x800A7040: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x800A7044: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800A7048: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A704C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800A7050: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x800A7054: jal         0x800F8874
    // 0x800A7058: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F8874(rdram, ctx);
        goto after_2;
    // 0x800A7058: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x800A705C: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x800A7060: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x800A7064: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x800A7068: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x800A706C: or          $t3, $t9, $t1
    ctx->r11 = ctx->r25 | ctx->r9;
    // 0x800A7070: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x800A7074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A707C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7080: jr          $ra
    // 0x800A7084: nop

    return;
    // 0x800A7084: nop

;}
RECOMP_FUNC void func_800B5DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5DF4: jr          $ra
    // 0x800B5DF8: nop

    return;
    // 0x800B5DF8: nop

;}
RECOMP_FUNC void func_808011BC_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808011C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808011C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808011CC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808011D0: jal         0x8008A0D0
    // 0x808011D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808011D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x808011D8: jal         0x800DF410
    // 0x808011DC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800DF410(rdram, ctx);
        goto after_1;
    // 0x808011DC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x808011E0: jal         0x800DF830
    // 0x808011E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x808011E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x808011E8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808011EC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808011F0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808011F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808011F8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x808011FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801200: jal         0x800DE498
    // 0x80801204: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800DE498(rdram, ctx);
        goto after_3;
    // 0x80801204: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_3:
    // 0x80801208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080120C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801210: jr          $ra
    // 0x80801214: nop

    return;
    // 0x80801214: nop

;}
RECOMP_FUNC void _chdiggerfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CB0: syscall     221
    recomp_syscall_handler(rdram, ctx, 0x80085CB0);
    return;
    // 0x80085CB4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8002BD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BD40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002BD44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BD48: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8002BD4C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8002BD50: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8002BD54: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8002BD58: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8002BD5C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002BD60: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002BD64: lw          $t7, 0x11F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F4);
    // 0x8002BD68: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002BD6C: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x8002BD70: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8002BD74: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002BD78: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002BD7C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002BD80: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8002BD84: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002BD88: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x8002BD8C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8002BD90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8002BD94: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002BD98: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8002BD9C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002BDA0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002BDA4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002BDA8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8002BDAC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002BDB0: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8002BDB4: ori         $t7, $t7, 0x7C0
    ctx->r15 = ctx->r15 | 0X7C0;
    // 0x8002BDB8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8002BDBC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002BDC0: addiu       $t8, $zero, 0x2E0
    ctx->r24 = ADD32(0, 0X2E0);
    // 0x8002BDC4: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8002BDC8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8002BDCC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8002BDD0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002BDD4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8002BDD8: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8002BDDC: beq         $t3, $zero, L_8002BEE4
    if (ctx->r11 == 0) {
        // 0x8002BDE0: nop
    
            goto L_8002BEE4;
    }
    // 0x8002BDE0: nop

L_8002BDE4:
    // 0x8002BDE4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8002BDE8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BDEC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002BDF0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8002BDF4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8002BDF8: lw          $t8, 0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X8);
    // 0x8002BDFC: beq         $t8, $zero, L_8002BEC4
    if (ctx->r24 == 0) {
        // 0x8002BE00: nop
    
            goto L_8002BEC4;
    }
    // 0x8002BE00: nop

    // 0x8002BE04: lh          $t0, 0x18($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X18);
    // 0x8002BE08: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002BE0C: bne         $t0, $t1, L_8002BEC4
    if (ctx->r8 != ctx->r9) {
        // 0x8002BE10: nop
    
            goto L_8002BEC4;
    }
    // 0x8002BE10: nop

    // 0x8002BE14: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x8002BE18: beq         $t2, $zero, L_8002BEC4
    if (ctx->r10 == 0) {
        // 0x8002BE1C: nop
    
            goto L_8002BEC4;
    }
    // 0x8002BE1C: nop

    // 0x8002BE20: lbu         $t3, 0x8C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X8C);
    // 0x8002BE24: slti        $at, $t3, 0x40
    ctx->r1 = SIGNED(ctx->r11) < 0X40 ? 1 : 0;
    // 0x8002BE28: bne         $at, $zero, L_8002BEC4
    if (ctx->r1 != 0) {
        // 0x8002BE2C: nop
    
            goto L_8002BEC4;
    }
    // 0x8002BE2C: nop

    // 0x8002BE30: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE34: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BE38: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002BE3C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002BE40: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8002BE44: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8002BE48: jal         0x8002AD60
    // 0x8002BE4C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_8002AD60(rdram, ctx);
        goto after_0;
    // 0x8002BE4C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_0:
    // 0x8002BE50: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002BE54: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002BE58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8002BE5C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8002BE60: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8002BE64: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8002BE68: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x8002BE6C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8002BE70: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE74: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BE78: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002BE7C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002BE80: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8002BE84: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002BE88: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x8002BE8C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8002BE90: lbu         $t9, 0x8C($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X8C);
    // 0x8002BE94: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x8002BE98: beq         $at, $zero, L_8002BEC4
    if (ctx->r1 == 0) {
        // 0x8002BE9C: nop
    
            goto L_8002BEC4;
    }
    // 0x8002BE9C: nop

    // 0x8002BEA0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002BEA4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BEA8: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8002BEAC: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8002BEB0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8002BEB4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8002BEB8: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x8002BEBC: lbu         $t1, 0x8C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X8C);
    // 0x8002BEC0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_8002BEC4:
    // 0x8002BEC4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002BEC8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002BECC: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8002BED0: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8002BED4: lw          $t2, 0x14($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X14);
    // 0x8002BED8: sltu        $at, $t8, $t2
    ctx->r1 = ctx->r24 < ctx->r10 ? 1 : 0;
    // 0x8002BEDC: bne         $at, $zero, L_8002BDE4
    if (ctx->r1 != 0) {
        // 0x8002BEE0: nop
    
            goto L_8002BDE4;
    }
    // 0x8002BEE0: nop

L_8002BEE4:
    // 0x8002BEE4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002BEE8: beq         $t3, $zero, L_8002C10C
    if (ctx->r11 == 0) {
        // 0x8002BEEC: nop
    
            goto L_8002C10C;
    }
    // 0x8002BEEC: nop

    // 0x8002BEF0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002BEF4: addiu       $t6, $t5, -0x3E
    ctx->r14 = ADD32(ctx->r13, -0X3E);
    // 0x8002BEF8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8002BEFC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002BF00: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8002BF04: bne         $at, $zero, L_8002BFD4
    if (ctx->r1 != 0) {
        // 0x8002BF08: nop
    
            goto L_8002BFD4;
    }
    // 0x8002BF08: nop

    // 0x8002BF0C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8002BF10: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002BF14: bgez        $t0, L_8002BF2C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8002BF18: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8002BF2C;
    }
    // 0x8002BF18: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002BF1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002BF20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002BF24: nop

    // 0x8002BF28: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_8002BF2C:
    // 0x8002BF2C: jal         0x8002DCA0
    // 0x8002BF30: nop

    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002BF30: nop

    after_1:
    // 0x8002BF34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002BF38: lwc1        $f8, 0x1D90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1D90);
    // 0x8002BF3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002BF40: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8002BF44: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002BF48: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002BF4C: nop

    // 0x8002BF50: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002BF54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002BF58: nop

    // 0x8002BF5C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8002BF60: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8002BF64: beq         $t9, $zero, L_8002BFB8
    if (ctx->r25 == 0) {
        // 0x8002BF68: nop
    
            goto L_8002BFB8;
    }
    // 0x8002BF68: nop

    // 0x8002BF6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002BF70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002BF74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002BF78: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002BF7C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002BF80: nop

    // 0x8002BF84: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002BF88: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002BF8C: nop

    // 0x8002BF90: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x8002BF94: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8002BF98: bne         $t9, $zero, L_8002BFB0
    if (ctx->r25 != 0) {
        // 0x8002BF9C: nop
    
            goto L_8002BFB0;
    }
    // 0x8002BF9C: nop

    // 0x8002BFA0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8002BFA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002BFA8: b           L_8002BFC8
    // 0x8002BFAC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8002BFC8;
    // 0x8002BFAC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8002BFB0:
    // 0x8002BFB0: b           L_8002BFC8
    // 0x8002BFB4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8002BFC8;
    // 0x8002BFB4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_8002BFB8:
    // 0x8002BFB8: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8002BFBC: nop

    // 0x8002BFC0: bltz        $t9, L_8002BFB0
    if (SIGNED(ctx->r25) < 0) {
        // 0x8002BFC4: nop
    
            goto L_8002BFB0;
    }
    // 0x8002BFC4: nop

L_8002BFC8:
    // 0x8002BFC8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002BFCC: b           L_8002C094
    // 0x8002BFD0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_8002C094;
    // 0x8002BFD0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8002BFD4:
    // 0x8002BFD4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002BFD8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8002BFDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002BFE0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8002BFE4: bgez        $t4, L_8002BFFC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002BFE8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8002BFFC;
    }
    // 0x8002BFE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002BFEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002BFF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002BFF4: nop

    // 0x8002BFF8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8002BFFC:
    // 0x8002BFFC: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002C000: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002C004: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002C008: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002C00C: nop

    // 0x8002C010: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002C014: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002C018: nop

    // 0x8002C01C: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002C020: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002C024: beq         $t2, $zero, L_8002C078
    if (ctx->r10 == 0) {
        // 0x8002C028: nop
    
            goto L_8002C078;
    }
    // 0x8002C028: nop

    // 0x8002C02C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002C030: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002C034: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002C038: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002C03C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002C040: nop

    // 0x8002C044: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002C048: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002C04C: nop

    // 0x8002C050: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002C054: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002C058: bne         $t2, $zero, L_8002C070
    if (ctx->r10 != 0) {
        // 0x8002C05C: nop
    
            goto L_8002C070;
    }
    // 0x8002C05C: nop

    // 0x8002C060: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8002C064: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002C068: b           L_8002C088
    // 0x8002C06C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8002C088;
    // 0x8002C06C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8002C070:
    // 0x8002C070: b           L_8002C088
    // 0x8002C074: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8002C088;
    // 0x8002C074: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8002C078:
    // 0x8002C078: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8002C07C: nop

    // 0x8002C080: bltz        $t2, L_8002C070
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002C084: nop
    
            goto L_8002C070;
    }
    // 0x8002C084: nop

L_8002C088:
    // 0x8002C088: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002C08C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8002C090: nop

L_8002C094:
    // 0x8002C094: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8002C098: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8002C09C: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8002C0A0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8002C0A4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002C0A8: addiu       $t6, $zero, 0x4E0
    ctx->r14 = ADD32(0, 0X4E0);
    // 0x8002C0AC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8002C0B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C0B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002C0B8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002C0BC: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8002C0C0: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002C0C4: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x8002C0C8: or          $t2, $t9, $t8
    ctx->r10 = ctx->r25 | ctx->r24;
    // 0x8002C0CC: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8002C0D0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002C0D4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002C0D8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002C0DC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8002C0E0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0E4: addiu       $t7, $zero, 0x650
    ctx->r15 = ADD32(0, 0X650);
    // 0x8002C0E8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8002C0EC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C0F0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002C0F4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0F8: andi        $t4, $t1, 0xFFFF
    ctx->r12 = ctx->r9 & 0XFFFF;
    // 0x8002C0FC: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8002C100: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x8002C104: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x8002C108: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
L_8002C10C:
    // 0x8002C10C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8002C110: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8002C114: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8002C118: beq         $t7, $zero, L_8002C204
    if (ctx->r15 == 0) {
        // 0x8002C11C: nop
    
            goto L_8002C204;
    }
    // 0x8002C11C: nop

L_8002C120:
    // 0x8002C120: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8002C124: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C128: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8002C12C: addu        $t8, $t0, $t4
    ctx->r24 = ADD32(ctx->r8, ctx->r12);
    // 0x8002C130: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C134: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x8002C138: beq         $t2, $zero, L_8002C16C
    if (ctx->r10 == 0) {
        // 0x8002C13C: nop
    
            goto L_8002C16C;
    }
    // 0x8002C13C: nop

    // 0x8002C140: lh          $t3, 0x18($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X18);
    // 0x8002C144: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002C148: bne         $t3, $t5, L_8002C16C
    if (ctx->r11 != ctx->r13) {
        // 0x8002C14C: nop
    
            goto L_8002C16C;
    }
    // 0x8002C14C: nop

    // 0x8002C150: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8002C154: beq         $t6, $zero, L_8002C198
    if (ctx->r14 == 0) {
        // 0x8002C158: nop
    
            goto L_8002C198;
    }
    // 0x8002C158: nop

    // 0x8002C15C: lbu         $t7, 0x8C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8C);
    // 0x8002C160: slti        $at, $t7, 0x40
    ctx->r1 = SIGNED(ctx->r15) < 0X40 ? 1 : 0;
    // 0x8002C164: bne         $at, $zero, L_8002C198
    if (ctx->r1 != 0) {
        // 0x8002C168: nop
    
            goto L_8002C198;
    }
    // 0x8002C168: nop

L_8002C16C:
    // 0x8002C16C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8002C170: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C174: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8002C178: addu        $t8, $t1, $t4
    ctx->r24 = ADD32(ctx->r9, ctx->r12);
    // 0x8002C17C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C180: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8002C184: bne         $t3, $zero, L_8002C1E4
    if (ctx->r11 != 0) {
        // 0x8002C188: nop
    
            goto L_8002C1E4;
    }
    // 0x8002C188: nop

    // 0x8002C18C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002C190: bne         $t5, $zero, L_8002C1E4
    if (ctx->r13 != 0) {
        // 0x8002C194: nop
    
            goto L_8002C1E4;
    }
    // 0x8002C194: nop

L_8002C198:
    // 0x8002C198: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002C19C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8002C1A0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002C1A4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C1A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002C1AC: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8002C1B0: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8002C1B4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8002C1B8: jal         0x8002AD60
    // 0x8002C1BC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_8002AD60(rdram, ctx);
        goto after_2;
    // 0x8002C1BC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x8002C1C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8002C1C4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8002C1C8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C1CC: beq         $t4, $t8, L_8002C1E4
    if (ctx->r12 == ctx->r24) {
        // 0x8002C1D0: nop
    
            goto L_8002C1E4;
    }
    // 0x8002C1D0: nop

    // 0x8002C1D4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002C1D8: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8002C1DC: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8002C1E0: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
L_8002C1E4:
    // 0x8002C1E4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002C1E8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8002C1EC: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x8002C1F0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8002C1F4: lw          $t0, 0x14($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X14);
    // 0x8002C1F8: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x8002C1FC: bne         $at, $zero, L_8002C120
    if (ctx->r1 != 0) {
        // 0x8002C200: nop
    
            goto L_8002C120;
    }
    // 0x8002C200: nop

L_8002C204:
    // 0x8002C204: b           L_8002C214
    // 0x8002C208: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
        goto L_8002C214;
    // 0x8002C208: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8002C20C: b           L_8002C214
    // 0x8002C210: nop

        goto L_8002C214;
    // 0x8002C210: nop

L_8002C214:
    // 0x8002C214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C218: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8002C21C: jr          $ra
    // 0x8002C220: nop

    return;
    // 0x8002C220: nop

    // 0x8002C224: nop

    // 0x8002C228: nop

    // 0x8002C22C: nop

;}
RECOMP_FUNC void func_8001B50C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B50C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B510: jr          $ra
    // 0x8001B514: sw          $zero, -0x3920($at)
    MEM_W(-0X3920, ctx->r1) = 0;
    return;
    // 0x8001B514: sw          $zero, -0x3920($at)
    MEM_W(-0X3920, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800F14_chjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F1C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800F20: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800F24: jal         0x80101E14
    // 0x80800F28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80800F28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F2C: beq         $v0, $zero, L_80800F70
    if (ctx->r2 == 0) {
        // 0x80800F30: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F70;
    }
    // 0x80800F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F34: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800F38: addiu       $at, $zero, 0x48F
    ctx->r1 = ADD32(0, 0X48F);
    // 0x80800F3C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800F40: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800F44: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800F48: bne         $t8, $at, L_80800F68
    if (ctx->r24 != ctx->r1) {
        // 0x80800F4C: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1672, 0X133C) << 16);
            goto L_80800F68;
    }
    // 0x80800F4C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1672, 0X133C) << 16);
    // 0x80800F50: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1672, 0X1348) << 16);
    // 0x80800F54: addiu       $a2, $a2, 0x1348
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X1348));
    // 0x80800F58: jal         0x80089D18
    // 0x80800F5C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800F5C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800F60: b           L_80800F74
    // 0x80800F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F74;
    // 0x80800F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F68:
    // 0x80800F68: jal         0x80089D18
    // 0x80800F6C: addiu       $a2, $a2, 0x133C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X133C));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800F6C: addiu       $a2, $a2, 0x133C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1672, 0X133C));
    after_2:
L_80800F70:
    // 0x80800F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F74:
    // 0x80800F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F78: jr          $ra
    // 0x80800F7C: nop

    return;
    // 0x80800F7C: nop

;}
RECOMP_FUNC void func_8009EB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EB10: jr          $ra
    // 0x8009EB14: swc1        $f12, 0x7044($at)
    MEM_W(0X7044, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8009EB14: swc1        $f12, 0x7044($at)
    MEM_W(0X7044, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800DD504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD504: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DD508: lw          $t6, -0x37BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X37BC);
    // 0x800DD50C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DD510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD514: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800DD518: beq         $t6, $zero, L_800DD55C
    if (ctx->r14 == 0) {
        // 0x800DD51C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800DD55C;
    }
    // 0x800DD51C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800DD520: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DD524: lw          $a2, -0x36B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X36B8);
    // 0x800DD528: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800DD52C: jal         0x800EFA20
    // 0x800DD530: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EFA20(rdram, ctx);
        goto after_0;
    // 0x800DD530: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800DD534: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DD538: lw          $a1, -0x36B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B4);
    // 0x800DD53C: jal         0x800EF04C
    // 0x800DD540: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x800DD540: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800DD544: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD548: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD54C: lw          $a0, -0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37BC);
    // 0x800DD550: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800DD554: jal         0x800DC028
    // 0x800DD558: lh          $a1, 0x8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X8);
    func_800DC028(rdram, ctx);
        goto after_2;
    // 0x800DD558: lh          $a1, 0x8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X8);
    after_2:
L_800DD55C:
    // 0x800DD55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD560: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DD564: jr          $ra
    // 0x800DD568: nop

    return;
    // 0x800DD568: nop

;}
RECOMP_FUNC void func_800A33F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A33F8: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A33FC: jr          $ra
    // 0x800A3400: lbu         $v0, 0x28($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X28);
    return;
    // 0x800A3400: lbu         $v0, 0x28($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X28);
;}
