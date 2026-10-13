#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808000BC_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: lhu         $v1, 0x72($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X72);
    // 0x808000E0: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x808000E4: beq         $t7, $at, L_808002C4
    if (ctx->r15 == ctx->r1) {
        // 0x808000E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002C4;
    }
    // 0x808000E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000EC: beq         $t7, $at, L_8080010C
    if (ctx->r15 == ctx->r1) {
        // 0x808000F0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080010C;
    }
    // 0x808000F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000F4: beq         $t7, $at, L_8080021C
    if (ctx->r15 == ctx->r1) {
        // 0x808000F8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8080021C;
    }
    // 0x808000F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808000FC: beq         $t7, $at, L_8080027C
    if (ctx->r15 == ctx->r1) {
        // 0x80800100: addiu       $a0, $zero, 0x2E
        ctx->r4 = ADD32(0, 0X2E);
            goto L_8080027C;
    }
    // 0x80800100: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80800104: b           L_808002C8
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080010C:
    // 0x8080010C: jal         0x800F54E4
    // 0x80800110: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800110: nop

    after_1:
    // 0x80800114: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800118: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080011C: addiu       $a0, $zero, 0xF7
    ctx->r4 = ADD32(0, 0XF7);
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800124: jal         0x800D2498
    // 0x80800128: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x80800128: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8080012C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800130: lw          $a0, 0x6C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X6C);
    // 0x80800134: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80800138: jal         0x800CEAD0
    // 0x8080013C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x80800140: beq         $v0, $zero, L_80800194
    if (ctx->r2 == 0) {
        // 0x80800144: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800194;
    }
    // 0x80800144: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800148: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800150: jal         0x80800C38
    // 0x80800154: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80800C38_chmonsterinterior(rdram, ctx);
        goto after_4;
    // 0x80800154: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_4:
    // 0x80800158: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8080015C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800164: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80800168: jal         0x800F8300
    // 0x8080016C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x8080016C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800174: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80800178: jal         0x800F7C0C
    // 0x8080017C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7C0C(rdram, ctx);
        goto after_6;
    // 0x8080017C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x80800180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800184: jal         0x80101FDC
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x8080018C: b           L_808002C8
    // 0x80800190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800194:
    // 0x80800194: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080019C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001A0: jal         0x800DC178
    // 0x808001A4: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808001A4: nop

    after_8:
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: jal         0x800D9154
    // 0x808001B4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9154(rdram, ctx);
        goto after_9;
    // 0x808001B4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_9:
    // 0x808001B8: beql        $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808001BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C8;
    }
    goto skip_0;
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C0: jal         0x800DC0C0
    // 0x808001C4: nop

    func_800DC0C0(rdram, ctx);
        goto after_10;
    // 0x808001C4: nop

    after_10:
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1CD0) << 16);
    // 0x808001CC: lwc1        $f4, 0x1CD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1CD0));
    // 0x808001D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001D8: nop

    // 0x808001DC: bc1fl       L_808001F0
    if (!c1cs) {
        // 0x808001E0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808001F0;
    }
    goto skip_1;
    // 0x808001E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x808001E4: b           L_8080020C
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8080020C;
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808001F0:
    // 0x808001F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808001F8: nop

    // 0x808001FC: bc1f        L_8080020C
    if (!c1cs) {
        // 0x80800200: nop
    
            goto L_8080020C;
    }
    // 0x80800200: nop

    // 0x80800204: b           L_8080020C
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080020C:
    // 0x8080020C: jal         0x80108B04
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x80800214: b           L_808002C8
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080021C:
    // 0x8080021C: jal         0x8008A2E8
    // 0x80800220: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800220: nop

    after_12:
    // 0x80800224: beq         $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x80800228: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808002C4;
    }
    // 0x80800228: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080022C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800230: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800234: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800238: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080023C: jal         0x8008A2C8
    // 0x80800240: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80800240: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_13:
    // 0x80800244: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800248: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8080024C: addiu       $t3, $zero, 0xB3
    ctx->r11 = ADD32(0, 0XB3);
    // 0x80800250: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800254: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800258: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8080025C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800260: jal         0x8008A208
    // 0x80800264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800268: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080026C: jal         0x80101FDC
    // 0x80800270: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x80800270: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x80800274: b           L_808002C8
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080027C:
    // 0x8080027C: jal         0x800D0B68
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_16;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800284: beql        $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x80800288: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C8;
    }
    goto skip_2;
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080028C: jal         0x800F54E4
    // 0x80800290: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80800290: nop

    after_17:
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080029C: jal         0x800F8300
    // 0x808002A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_18;
    // 0x808002A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x808002A4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: addiu       $t4, $zero, 0xCEB
    ctx->r12 = ADD32(0, 0XCEB);
    // 0x808002AC: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x808002B0: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x808002B4: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x808002B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002BC: jal         0x80101FDC
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
L_808002C4:
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C8:
    // 0x808002C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_80800928_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080092C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800930: jal         0x80800164
    // 0x80800934: nop

    func_80800164_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800934: nop

    after_0:
    // 0x80800938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080093C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800940: jr          $ra
    // 0x80800944: nop

    return;
    // 0x80800944: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B58) << 16);
    // 0x808010DC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808010E0: jr          $ra
    // 0x808010E4: lw          $v0, 0x1B58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B58));
    return;
    // 0x808010E4: lw          $v0, 0x1B58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B58));
;}
RECOMP_FUNC void func_808010B4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010BC: jal         0x80800130
    // 0x808010C0: nop

    func_80800130_bsstatue(rdram, ctx);
        goto after_0;
    // 0x808010C0: nop

    after_0:
    // 0x808010C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010CC: jr          $ra
    // 0x808010D0: nop

    return;
    // 0x808010D0: nop

;}
RECOMP_FUNC void func_808000EC_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000F4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808000F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800100: beq         $a1, $at, L_8080014C
    if (ctx->r5 == ctx->r1) {
        // 0x80800104: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8080014C;
    }
    // 0x80800104: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800108: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080010C: beq         $a1, $at, L_80800134
    if (ctx->r5 == ctx->r1) {
        // 0x80800110: addiu       $v0, $sp, 0x30
        ctx->r2 = ADD32(ctx->r29, 0X30);
            goto L_80800134;
    }
    // 0x80800110: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800114: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800118: beq         $a1, $at, L_8080019C
    if (ctx->r5 == ctx->r1) {
        // 0x8080011C: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8080019C;
    }
    // 0x8080011C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800120: addiu       $at, $zero, 0x7D
    ctx->r1 = ADD32(0, 0X7D);
    // 0x80800124: beq         $a1, $at, L_8080018C
    if (ctx->r5 == ctx->r1) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: b           L_8080020C
    // 0x80800130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080020C;
    // 0x80800130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800134:
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080013C: jal         0x80800054
    // 0x80800140: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800054_chboggy(rdram, ctx);
        goto after_0;
    // 0x80800140: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x80800144: b           L_8080020C
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080014C:
    // 0x8080014C: jal         0x800DF3E0
    // 0x80800150: nop

    func_800DF3E0(rdram, ctx);
        goto after_1;
    // 0x80800150: nop

    after_1:
    // 0x80800154: jal         0x801015D0
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080015C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800168: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080016C: bne         $t7, $at, L_8080017C
    if (ctx->r15 != ctx->r1) {
        // 0x80800170: nop
    
            goto L_8080017C;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_8080017C
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080017C;
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080017C:
    // 0x8080017C: jal         0x800DF744
    // 0x80800180: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800180: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80800184: b           L_8080020C
    // 0x80800188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x80800188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080018C:
    // 0x8080018C: jal         0x80101FDC
    // 0x80800190: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800190: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800194: b           L_8080020C
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080019C:
    // 0x8080019C: addiu       $at, $zero, 0x22B
    ctx->r1 = ADD32(0, 0X22B);
    // 0x808001A0: bne         $t8, $at, L_80800208
    if (ctx->r24 != ctx->r1) {
        // 0x808001A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800208;
    }
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X820) << 16);
    // 0x808001AC: addiu       $a2, $a2, 0x820
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X820));
    // 0x808001B0: jal         0x80089D18
    // 0x808001B4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808001B4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x808001B8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808001BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001C0: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808001C4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001D0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808001D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001D8: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x808001DC: jal         0x800D10D4
    // 0x808001E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D10D4(rdram, ctx);
        goto after_6;
    // 0x808001E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x808001E4: jal         0x80106790
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808001EC: jal         0x80085910
    // 0x808001F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chbounce_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808001F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x808001F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808001F8: b           L_80800208
    // 0x808001FC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_80800208;
    // 0x808001FC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800200: b           L_8080020C
    // 0x80800204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080020C;
    // 0x80800204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800208:
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080020C:
    // 0x8080020C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800210: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800218: jr          $ra
    // 0x8080021C: nop

    return;
    // 0x8080021C: nop

;}
RECOMP_FUNC void func_801006E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801006E0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801006E4: lw          $t6, 0x5A64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5A64);
    // 0x801006E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801006EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801006F0: bne         $t6, $zero, L_8010070C
    if (ctx->r14 != 0) {
        // 0x801006F4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8010070C;
    }
    // 0x801006F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801006F8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801006FC: jal         0x800B3268
    // 0x80100700: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x80100700: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80100704: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100708: sw          $v0, 0x5A64($at)
    MEM_W(0X5A64, ctx->r1) = ctx->r2;
L_8010070C:
    // 0x8010070C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100710: addiu       $a0, $a0, 0x5A64
    ctx->r4 = ADD32(ctx->r4, 0X5A64);
    // 0x80100714: jal         0x800B3044
    // 0x80100718: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    freelist_next(rdram, ctx);
        goto after_1;
    // 0x80100718: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8010071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100724: jr          $ra
    // 0x80100728: nop

    return;
    // 0x80100728: nop

;}
RECOMP_FUNC void subaddieskeleton_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080013C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800140: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800144: jal         0x80106790
    // 0x80800148: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800148: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080014C: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x80800150: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800154: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800158: bgezl       $t8, L_80800188
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080015C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800188;
    }
    goto skip_0;
    // 0x8080015C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800160: jal         0x8080020C
    // 0x80800164: nop

    subaddieskeleton_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800164: nop

    after_1:
    // 0x80800168: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x8080016C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800184;
    }
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800170: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800174: jal         0x800DBEFC
    // 0x80800178: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800178: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080017C: b           L_80800188
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800188;
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800188:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_808004D4_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808004D8: addiu       $t6, $a1, -0xA
    ctx->r14 = ADD32(ctx->r5, -0XA);
    // 0x808004DC: sltiu       $at, $t6, 0x49
    ctx->r1 = ctx->r14 < 0X49 ? 1 : 0;
    // 0x808004E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004E8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x808004EC: beq         $at, $zero, L_80800820
    if (ctx->r1 == 0) {
        // 0x808004F0: sw          $a2, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r6;
            goto L_80800820;
    }
    // 0x808004F0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x808004F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808004F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1216, 0XF0C) << 16);
    // 0x808004FC: addu        $at, $at, $t6
    gpr jr_addend_80800504 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800500: lw          $t6, 0xF0C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1216, 0XF0C));
    // 0x80800504: jr          $t6
    // 0x80800508: nop

    switch (jr_addend_80800504 >> 2) {
        case 0: goto L_8080080C; break;
        case 1: goto L_80800528; break;
        case 2: goto L_80800820; break;
        case 3: goto L_80800820; break;
        case 4: goto L_80800560; break;
        case 5: goto L_80800820; break;
        case 6: goto L_80800820; break;
        case 7: goto L_80800820; break;
        case 8: goto L_80800820; break;
        case 9: goto L_80800820; break;
        case 10: goto L_80800820; break;
        case 11: goto L_80800820; break;
        case 12: goto L_80800820; break;
        case 13: goto L_80800820; break;
        case 14: goto L_80800820; break;
        case 15: goto L_80800820; break;
        case 16: goto L_80800820; break;
        case 17: goto L_80800820; break;
        case 18: goto L_80800820; break;
        case 19: goto L_80800820; break;
        case 20: goto L_80800820; break;
        case 21: goto L_80800660; break;
        case 22: goto L_80800820; break;
        case 23: goto L_80800820; break;
        case 24: goto L_80800820; break;
        case 25: goto L_80800820; break;
        case 26: goto L_80800820; break;
        case 27: goto L_80800820; break;
        case 28: goto L_80800820; break;
        case 29: goto L_80800820; break;
        case 30: goto L_80800820; break;
        case 31: goto L_80800820; break;
        case 32: goto L_80800820; break;
        case 33: goto L_80800820; break;
        case 34: goto L_80800820; break;
        case 35: goto L_80800820; break;
        case 36: goto L_8080050C; break;
        case 37: goto L_80800820; break;
        case 38: goto L_80800820; break;
        case 39: goto L_80800820; break;
        case 40: goto L_80800820; break;
        case 41: goto L_80800820; break;
        case 42: goto L_80800820; break;
        case 43: goto L_80800820; break;
        case 44: goto L_80800820; break;
        case 45: goto L_80800820; break;
        case 46: goto L_80800820; break;
        case 47: goto L_80800820; break;
        case 48: goto L_80800820; break;
        case 49: goto L_80800820; break;
        case 50: goto L_80800820; break;
        case 51: goto L_808006F8; break;
        case 52: goto L_80800820; break;
        case 53: goto L_808005DC; break;
        case 54: goto L_80800820; break;
        case 55: goto L_80800820; break;
        case 56: goto L_80800820; break;
        case 57: goto L_80800820; break;
        case 58: goto L_80800820; break;
        case 59: goto L_80800820; break;
        case 60: goto L_80800820; break;
        case 61: goto L_80800820; break;
        case 62: goto L_80800820; break;
        case 63: goto L_80800820; break;
        case 64: goto L_80800820; break;
        case 65: goto L_80800820; break;
        case 66: goto L_80800820; break;
        case 67: goto L_80800820; break;
        case 68: goto L_80800820; break;
        case 69: goto L_80800820; break;
        case 70: goto L_80800820; break;
        case 71: goto L_80800820; break;
        case 72: goto L_808006DC; break;
        default: switch_error(__func__, 0x80800504, 0x80800F0C);
    }
    // 0x80800508: nop

L_8080050C:
    // 0x8080050C: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80800510: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800514: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800518: jal         0x80800840
    // 0x8080051C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80800840_chbiggafoot(rdram, ctx);
        goto after_0;
    // 0x8080051C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_0:
    // 0x80800520: b           L_8080082C
    // 0x80800524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x80800524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800528:
    // 0x80800528: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8080052C: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80800530: bne         $t7, $at, L_80800558
    if (ctx->r15 != ctx->r1) {
        // 0x80800534: nop
    
            goto L_80800558;
    }
    // 0x80800534: nop

    // 0x80800538: jal         0x800DA544
    // 0x8080053C: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x8080053C: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    after_1:
    // 0x80800540: jal         0x800FFAB0
    // 0x80800544: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800544: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x80800548: jal         0x800856B8
    // 0x8080054C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080054C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800550: b           L_8080082C
    // 0x80800554: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080082C;
    // 0x80800554: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800558:
    // 0x80800558: b           L_8080082C
    // 0x8080055C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080082C;
    // 0x8080055C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800560:
    // 0x80800560: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80800564: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80800568: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8080056C: bne         $t8, $at, L_808005D4
    if (ctx->r24 != ctx->r1) {
        // 0x80800570: nop
    
            goto L_808005D4;
    }
    // 0x80800570: nop

    // 0x80800574: jal         0x80106790
    // 0x80800578: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80800578: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_4:
    // 0x8080057C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1216, 0X1154) << 16);
    // 0x80800580: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80800584: addiu       $s0, $s0, 0x1154
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1216, 0X1154));
L_80800588:
    // 0x80800588: jal         0x80085728
    // 0x8080058C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080058C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80800590: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x80800594: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808005C4;
    }
    // 0x80800594: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800598: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8080059C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1216, 0X115C) << 16);
    // 0x808005A0: addiu       $a3, $a3, 0x115C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1216, 0X115C));
    // 0x808005A4: lw          $a1, 0x70($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X70);
    // 0x808005A8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808005AC: addiu       $a2, $t0, 0x4
    ctx->r6 = ADD32(ctx->r8, 0X4);
    // 0x808005B0: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x808005B4: jal         0x8010D930
    // 0x808005B8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_8010D930(rdram, ctx);
        goto after_6;
    // 0x808005B8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_6:
    // 0x808005BC: b           L_8080082C
    // 0x808005C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080082C;
    // 0x808005C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005C4:
    // 0x808005C4: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1216, 0X115C) << 16);
    // 0x808005C8: addiu       $t2, $t2, 0x115C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1216, 0X115C));
    // 0x808005CC: bne         $s0, $t2, L_80800588
    if (ctx->r16 != ctx->r10) {
        // 0x808005D0: nop
    
            goto L_80800588;
    }
    // 0x808005D0: nop

L_808005D4:
    // 0x808005D4: b           L_8080082C
    // 0x808005D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080082C;
    // 0x808005D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005DC:
    // 0x808005DC: jal         0x8010A570
    // 0x808005E0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x808005E0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_7:
    // 0x808005E4: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x808005E8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1216, 0X1170) << 16);
    // 0x808005EC: addiu       $a3, $a3, 0x1170
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1216, 0X1170));
    // 0x808005F0: lbu         $t5, 0x65($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X65);
    // 0x808005F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808005F8: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x808005FC: sb          $t6, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r14;
    // 0x80800600: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80800604: lw          $a1, 0x70($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X70);
    // 0x80800608: addiu       $a2, $t7, 0x4
    ctx->r6 = ADD32(ctx->r15, 0X4);
    // 0x8080060C: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80800610: jal         0x8010D930
    // 0x80800614: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8010D930(rdram, ctx);
        goto after_8;
    // 0x80800614: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_8:
    // 0x80800618: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8080061C: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x80800620: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80800624: bltzl       $t2, L_8080082C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800628: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080082C;
    }
    goto skip_0;
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080062C: lbu         $t5, 0x65($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X65);
    // 0x80800630: addiu       $t8, $zero, 0xA8
    ctx->r24 = ADD32(0, 0XA8);
    // 0x80800634: addiu       $a1, $zero, 0x12B1
    ctx->r5 = ADD32(0, 0X12B1);
    // 0x80800638: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x8080063C: sb          $t6, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r14;
    // 0x80800640: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80800644: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800648: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8080064C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800650: jal         0x8008A208
    // 0x80800654: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800654: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    after_9:
    // 0x80800658: b           L_8080082C
    // 0x8080065C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x8080065C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800660:
    // 0x80800660: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80800664: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80800668: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080066C: lwc1        $f4, 0x2C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x80800670: lwc1        $f6, 0x28($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X28);
    // 0x80800674: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80800678: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080067C: jal         0x800F0D50
    // 0x80800680: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800F0D50(rdram, ctx);
        goto after_10;
    // 0x80800680: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_10:
    // 0x80800684: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80800688: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8080068C: jal         0x800B2768
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2768(rdram, ctx);
        goto after_11;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800694: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800698: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8080069C: jal         0x80103CB8
    // 0x808006A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80103CB8(rdram, ctx);
        goto after_12;
    // 0x808006A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x808006A4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808006A8: jal         0x800B2840
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2840(rdram, ctx);
        goto after_13;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808006B0: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x808006B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808006B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808006BC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808006C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808006C4: jal         0x80087990
    // 0x808006C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _dbmorph_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x808006C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x808006CC: jal         0x801015D0
    // 0x808006D0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_801015D0(rdram, ctx);
        goto after_15;
    // 0x808006D0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_15:
    // 0x808006D4: b           L_8080082C
    // 0x808006D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x808006D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006DC:
    // 0x808006DC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x808006E0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1216, 0X1188) << 16);
    // 0x808006E4: addiu       $a0, $a0, 0x1188
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1216, 0X1188));
    // 0x808006E8: jal         0x80088090
    // 0x808006EC: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808006EC: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    after_16:
    // 0x808006F0: b           L_8080082C
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006F8:
    // 0x808006F8: jal         0x800F54E4
    // 0x808006FC: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x808006FC: nop

    after_17:
    // 0x80800700: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800704: jal         0x800F7F98
    // 0x80800708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_18;
    // 0x80800708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8080070C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800710: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800714: jal         0x800EE7F8
    // 0x80800718: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_19;
    // 0x80800718: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_19:
    // 0x8080071C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80800720: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800724: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800728: lwc1        $f8, 0x50($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X50);
    // 0x8080072C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800730: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800734: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800738: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080073C: jal         0x800EF1B8
    // 0x80800740: nop

    func_800EF1B8(rdram, ctx);
        goto after_20;
    // 0x80800740: nop

    after_20:
    // 0x80800744: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800748: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080074C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800750: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800754: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800758: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080075C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800760: jal         0x800F1DF4
    // 0x80800764: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_21;
    // 0x80800764: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x80800768: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080076C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800770: addiu       $a0, $zero, 0x44E
    ctx->r4 = ADD32(0, 0X44E);
    // 0x80800774: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // 0x80800778: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080077C: jal         0x80108528
    // 0x80800780: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_80108528(rdram, ctx);
        goto after_22;
    // 0x80800780: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_22:
    // 0x80800784: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80800788: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8080078C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800790: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80800794: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800798: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8080079C: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x808007A0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x808007A4: jal         0x800EE7F8
    // 0x808007A8: sw          $t9, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r25;
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x808007A8: sw          $t9, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r25;
    after_23:
    // 0x808007AC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x808007B0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808007B4: jal         0x800EE7F8
    // 0x808007B8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_24;
    // 0x808007B8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_24:
    // 0x808007BC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808007C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808007C4: jal         0x800EEAD4
    // 0x808007C8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EEAD4(rdram, ctx);
        goto after_25;
    // 0x808007C8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_25:
    // 0x808007CC: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x808007D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007D4: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x808007D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007DC: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808007E0: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x808007E4: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    // 0x808007E8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x808007EC: jal         0x800856B0
    // 0x808007F0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x808007F0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_26:
    // 0x808007F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007F8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x808007FC: jal         0x800856D0
    // 0x80800800: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    _capod_entrypoint_6(rdram, ctx);
        goto after_27;
    // 0x80800800: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_27:
    // 0x80800804: b           L_8080082C
    // 0x80800808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x80800808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080080C:
    // 0x8080080C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800810: jal         0x80102424
    // 0x80800814: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x80800814: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x80800818: b           L_8080082C
    // 0x8080081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080082C;
    // 0x8080081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800820:
    // 0x80800820: b           L_8080082C
    // 0x80800824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080082C;
    // 0x80800824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080082C:
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800830: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800834: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void func_80800700_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800708: jal         0x80800654
    // 0x8080070C: nop

    func_80800654_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x8080070C: nop

    after_0:
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: nop

    return;
    // 0x8080071C: nop

;}
RECOMP_FUNC void _gemarkersDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089750: syscall     793
    recomp_syscall_handler(rdram, ctx, 0x80089750);
    return;
    // 0x80089754: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _basetup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FB0: syscall     146
    recomp_syscall_handler(rdram, ctx, 0x80084FB0);
    return;
    // 0x80084FB4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80110A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110A9C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80110AA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110AA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80110AA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110AAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80110AB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80110AB4: jal         0x800F6BE4
    // 0x80110AB8: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    func_800F6BE4(rdram, ctx);
        goto after_0;
    // 0x80110AB8: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    after_0:
    // 0x80110ABC: beq         $v0, $zero, L_80110AF4
    if (ctx->r2 == 0) {
        // 0x80110AC0: nop
    
            goto L_80110AF4;
    }
    // 0x80110AC0: nop

    // 0x80110AC4: jal         0x800F6438
    // 0x80110AC8: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80110AC8: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x80110ACC: beq         $v0, $zero, L_80110AF4
    if (ctx->r2 == 0) {
        // 0x80110AD0: nop
    
            goto L_80110AF4;
    }
    // 0x80110AD0: nop

    // 0x80110AD4: jal         0x800F6640
    // 0x80110AD8: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F6640(rdram, ctx);
        goto after_2;
    // 0x80110AD8: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_2:
    // 0x80110ADC: beq         $v0, $zero, L_80110AF4
    if (ctx->r2 == 0) {
        // 0x80110AE0: nop
    
            goto L_80110AF4;
    }
    // 0x80110AE0: nop

    // 0x80110AE4: jal         0x800F6690
    // 0x80110AE8: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F6690(rdram, ctx);
        goto after_3;
    // 0x80110AE8: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_3:
    // 0x80110AEC: bne         $v0, $zero, L_80110AFC
    if (ctx->r2 != 0) {
        // 0x80110AF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80110AFC;
    }
    // 0x80110AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80110AF4:
    // 0x80110AF4: b           L_80110B54
    // 0x80110AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80110B54;
    // 0x80110AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80110AFC:
    // 0x80110AFC: jal         0x80112550
    // 0x80110B00: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80112550(rdram, ctx);
        goto after_4;
    // 0x80110B00: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80110B04: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80110B08: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80110B0C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80110B10: jal         0x800EFB24
    // 0x80110B14: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x80110B14: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x80110B18: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80110B1C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80110B20: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80110B24: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80110B28: nop

    // 0x80110B2C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80110B30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80110B34: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80110B38: jal         0x8002DCA0
    // 0x80110B3C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x80110B3C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_6:
    // 0x80110B40: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80110B44: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80110B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80110B4C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80110B50: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
L_80110B54:
    // 0x80110B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80110B58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110B5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80110B60: jr          $ra
    // 0x80110B64: nop

    return;
    // 0x80110B64: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F84: jal         0x80800F3C
    // 0x80800F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800F3C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F8C: bne         $v0, $zero, L_80800F9C
    if (ctx->r2 != 0) {
        // 0x80800F90: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800F9C;
    }
    // 0x80800F90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800F94: b           L_80800FAC
    // 0x80800F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FAC;
    // 0x80800F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F9C:
    // 0x80800F9C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800FA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800FA8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800FAC:
    // 0x80800FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FB4: jr          $ra
    // 0x80800FB8: nop

    return;
    // 0x80800FB8: nop

;}
RECOMP_FUNC void func_808006A8_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808006B0: beq         $a1, $at, L_8080071C
    if (ctx->r5 == ctx->r1) {
        // 0x808006B4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080071C;
    }
    // 0x808006B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B8: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808006BC: bne         $a1, $at, L_80800740
    if (ctx->r5 != ctx->r1) {
        // 0x808006C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800740;
    }
    // 0x808006C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006C4: slti        $at, $a2, 0x7A
    ctx->r1 = SIGNED(ctx->r6) < 0X7A ? 1 : 0;
    // 0x808006C8: bne         $at, $zero, L_8080070C
    if (ctx->r1 != 0) {
        // 0x808006CC: slti        $at, $a2, 0x84
        ctx->r1 = SIGNED(ctx->r6) < 0X84 ? 1 : 0;
            goto L_8080070C;
    }
    // 0x808006CC: slti        $at, $a2, 0x84
    ctx->r1 = SIGNED(ctx->r6) < 0X84 ? 1 : 0;
    // 0x808006D0: beq         $at, $zero, L_8080070C
    if (ctx->r1 == 0) {
        // 0x808006D4: addiu       $t7, $a2, -0x7A
        ctx->r15 = ADD32(ctx->r6, -0X7A);
            goto L_8080070C;
    }
    // 0x808006D4: addiu       $t7, $a2, -0x7A
    ctx->r15 = ADD32(ctx->r6, -0X7A);
    // 0x808006D8: lbu         $t0, 0x79($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X79);
    // 0x808006DC: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006E4: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x808006E8: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808006EC: sb          $t2, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r10;
    // 0x808006F0: jal         0x8010A800
    // 0x808006F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A800(rdram, ctx);
        goto after_0;
    // 0x808006F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006FC: jal         0x80800214
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800214_chworlddoors(rdram, ctx);
        goto after_1;
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800704: b           L_80800740
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800740;
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080070C:
    // 0x8080070C: jal         0x800FFAB0
    // 0x80800710: nop

    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800710: nop

    after_2:
    // 0x80800714: b           L_80800740
    // 0x80800718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800740;
    // 0x80800718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080071C:
    // 0x8080071C: lhu         $t3, 0x72($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X72);
    // 0x80800720: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800724: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x80800728: bne         $t4, $at, L_80800738
    if (ctx->r12 != ctx->r1) {
        // 0x8080072C: nop
    
            goto L_80800738;
    }
    // 0x8080072C: nop

    // 0x80800730: jal         0x80800214
    // 0x80800734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800214_chworlddoors(rdram, ctx);
        goto after_3;
    // 0x80800734: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_80800738:
    // 0x80800738: b           L_80800740
    // 0x8080073C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800740;
    // 0x8080073C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800740:
    // 0x80800740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800748: jr          $ra
    // 0x8080074C: nop

    return;
    // 0x8080074C: nop

;}
RECOMP_FUNC void func_80802068_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080206C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802074: jal         0x80800090
    // 0x80802078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800090_chhandcart(rdram, ctx);
        goto after_0;
    // 0x80802078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080207C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80802080: bne         $v0, $v1, L_8080208C
    if (ctx->r2 != ctx->r3) {
        // 0x80802084: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080208C;
    }
    // 0x80802084: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802088: subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
L_8080208C:
    // 0x8080208C: beq         $a1, $zero, L_808020B8
    if (ctx->r5 == 0) {
        // 0x80802090: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808020B8;
    }
    // 0x80802090: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802094: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802098: addiu       $a0, $zero, 0x314
    ctx->r4 = ADD32(0, 0X314);
    // 0x8080209C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808020A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808020A4: jal         0x80088280
    // 0x808020A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808020A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808020AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808020B0: b           L_808020D4
    // 0x808020B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_808020D4;
    // 0x808020B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808020B8:
    // 0x808020B8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808020BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808020C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808020C4: jal         0x80088280
    // 0x808020C8: addiu       $a0, $zero, 0x313
    ctx->r4 = ADD32(0, 0X313);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808020C8: addiu       $a0, $zero, 0x313
    ctx->r4 = ADD32(0, 0X313);
    after_2:
    // 0x808020CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808020D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808020D4:
    // 0x808020D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808020D8: jal         0x800EE88C
    // 0x808020DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x808020DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x808020E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808020E4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808020E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808020EC: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x808020F0: srl         $t7, $t6, 23
    ctx->r15 = S32(U32(ctx->r14) >> 23);
    // 0x808020F4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808020F8: bgez        $t7, L_8080210C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808020FC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080210C;
    }
    // 0x808020FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802104: nop

    // 0x80802108: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080210C:
    // 0x8080210C: swc1        $f6, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f6.u32l;
    // 0x80802110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802118: jr          $ra
    // 0x8080211C: nop

    return;
    // 0x8080211C: nop

;}
RECOMP_FUNC void func_808001E8_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F0: jal         0x8009E6EC
    // 0x808001F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808001F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001F8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x808001FC: bne         $v0, $at, L_80800214
    if (ctx->r2 != ctx->r1) {
        // 0x80800200: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800214;
    }
    // 0x80800200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: jal         0x8009E830
    // 0x80800208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080020C: b           L_80800220
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800220;
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800214:
    // 0x80800214: jal         0x80099B94
    // 0x80800218: nop

    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x80800218: nop

    after_2:
    // 0x8080021C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800220:
    // 0x80800220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

;}
RECOMP_FUNC void func_80800944_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080094C: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80800950: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800954: beq         $t6, $zero, L_80800970
    if (ctx->r14 == 0) {
        // 0x80800958: nop
    
            goto L_80800970;
    }
    // 0x80800958: nop

    // 0x8080095C: jal         0x800885F8
    // 0x80800960: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800960: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800964: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800968: b           L_80800980
    // 0x8080096C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_80800980;
    // 0x8080096C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_80800970:
    // 0x80800970: jal         0x800D8FF8
    // 0x80800974: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800974: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800978: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080097C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_80800980:
    // 0x80800980: lbu         $v0, 0x60($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X60);
    // 0x80800984: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800988: beq         $v0, $at, L_808009F8
    if (ctx->r2 == ctx->r1) {
        // 0x8080098C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808009F8;
    }
    // 0x8080098C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800990: beq         $v0, $at, L_808009F8
    if (ctx->r2 == ctx->r1) {
        // 0x80800994: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808009F8;
    }
    // 0x80800994: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800998: bnel        $v0, $at, L_80800A0C
    if (ctx->r2 != ctx->r1) {
        // 0x8080099C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A0C;
    }
    goto skip_0;
    // 0x8080099C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009A0: jal         0x8001B798
    // 0x808009A4: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x808009A4: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    after_2:
    // 0x808009A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808009AC: jal         0x80089E68
    // 0x808009B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _susplinet_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808009B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808009B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009BC: jal         0x80089E78
    // 0x808009C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    _susplinet_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808009C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x808009C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808009C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009CC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808009D0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808009D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808009DC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808009E0: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808009E4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808009E8: jal         0x80089EA0
    // 0x808009EC: nop

    _susplinet_entrypoint_16(rdram, ctx);
        goto after_5;
    // 0x808009EC: nop

    after_5:
    // 0x808009F0: b           L_80800A0C
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A0C;
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009F8:
    // 0x808009F8: jal         0x8001B798
    // 0x808009FC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_8001B798(rdram, ctx);
        goto after_6;
    // 0x808009FC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_6:
    // 0x80800A00: jal         0x80089DF8
    // 0x80800A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_16(rdram, ctx);
        goto after_7;
    // 0x80800A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A0C:
    // 0x80800A0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A10: jr          $ra
    // 0x80800A14: nop

    return;
    // 0x80800A14: nop

;}
RECOMP_FUNC void chsmalltrexdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2264, 0X2E0) << 16);
    // 0x808002D8: jr          $ra
    // 0x808002DC: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2264, 0X2E0));
    return;
    // 0x808002DC: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2264, 0X2E0));
;}
RECOMP_FUNC void func_80800FC0_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800FCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800FD0: jal         0x80100094
    // 0x80800FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FDC: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80800FE0: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x80800FE4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800FE8: lhu         $v1, 0x22($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X22);
    // 0x80800FEC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80800FF0: srl         $t8, $v1, 15
    ctx->r24 = S32(U32(ctx->r3) >> 15);
    // 0x80800FF4: beql        $t8, $zero, L_80801078
    if (ctx->r24 == 0) {
        // 0x80800FF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801078;
    }
    goto skip_0;
    // 0x80800FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800FFC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80801000: andi        $t3, $v1, 0x7FFF
    ctx->r11 = ctx->r3 & 0X7FFF;
    // 0x80801004: addu        $v1, $t1, $t0
    ctx->r3 = ADD32(ctx->r9, ctx->r8);
    // 0x80801008: andi        $t2, $t9, 0x80
    ctx->r10 = ctx->r25 & 0X80;
    // 0x8080100C: beq         $t2, $zero, L_80801060
    if (ctx->r10 == 0) {
        // 0x80801010: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80801060;
    }
    // 0x80801010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801014: beql        $t3, $zero, L_80801064
    if (ctx->r11 == 0) {
        // 0x80801018: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80801064;
    }
    goto skip_1;
    // 0x80801018: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x8080101C: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80801020: lhu         $a0, 0x22($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X22);
    // 0x80801024: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80801028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080102C: andi        $t4, $a0, 0x7FFF
    ctx->r12 = ctx->r4 & 0X7FFF;
    // 0x80801030: jal         0x800DA9E4
    // 0x80801034: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_1;
    // 0x80801034: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_1:
    // 0x80801038: bne         $v0, $zero, L_80801074
    if (ctx->r2 != 0) {
        // 0x8080103C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80801074;
    }
    // 0x8080103C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801040: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80801044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801048: lbu         $a2, 0x21($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X21);
    // 0x8080104C: lhu         $a3, 0x1E($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X1E);
    // 0x80801050: jal         0x80085708
    // 0x80801054: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80801054: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_2:
    // 0x80801058: b           L_80801078
    // 0x8080105C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801078;
    // 0x8080105C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801060:
    // 0x80801060: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
L_80801064:
    // 0x80801064: lbu         $a2, 0x21($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X21);
    // 0x80801068: lhu         $a3, 0x1E($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X1E);
    // 0x8080106C: jal         0x80085708
    // 0x80801070: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80801070: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
L_80801074:
    // 0x80801074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801078:
    // 0x80801078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080107C: jr          $ra
    // 0x80801080: nop

    return;
    // 0x80801080: nop

;}
RECOMP_FUNC void func_80091EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091EB0: jal         0x80091F74
    // 0x80091EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80091F74(rdram, ctx);
        goto after_0;
    // 0x80091EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80091EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091EC0: jr          $ra
    // 0x80091EC4: nop

    return;
    // 0x80091EC4: nop

;}
RECOMP_FUNC void func_808003C8_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808003D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808003D8: bgezl       $t8, L_808003F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808003DC: lbu         $t0, 0x74($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X74);
            goto L_808003F8;
    }
    goto skip_0;
    // 0x808003DC: lbu         $t0, 0x74($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X74);
    skip_0:
    // 0x808003E0: jal         0x80089BD8
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808003E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003E8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x808003EC: b           L_8080041C
    // 0x808003F0: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
        goto L_8080041C;
    // 0x808003F0: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x808003F4: lbu         $t0, 0x74($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X74);
L_808003F8:
    // 0x808003F8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x808003FC: beq         $t1, $zero, L_8080040C
    if (ctx->r9 == 0) {
        // 0x80800400: nop
    
            goto L_8080040C;
    }
    // 0x80800400: nop

    // 0x80800404: b           L_8080041C
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080041C;
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080040C:
    // 0x8080040C: jal         0x8008A160
    // 0x80800410: nop

    _sucoaster_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800410: nop

    after_1:
    // 0x80800414: xori        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 ^ 0X1;
    // 0x80800418: sltiu       $v0, $t2, 0x1
    ctx->r2 = ctx->r10 < 0X1 ? 1 : 0;
L_8080041C:
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800424: jr          $ra
    // 0x80800428: nop

    return;
    // 0x80800428: nop

;}
RECOMP_FUNC void bastick_getStructSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ED00: jr          $ra
    // 0x8009ED04: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    return;
    // 0x8009ED04: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
;}
RECOMP_FUNC void __yaw_update_limitless(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C5A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009C5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C5B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009C5B4: jal         0x800D8FF8
    // 0x8009C5B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009C5B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009C5BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009C5C0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C5C4: lw          $v0, 0xF8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XF8);
    // 0x8009C5C8: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8009C5CC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C5D0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C5D4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009C5D8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8009C5DC: jal         0x800F2100
    // 0x8009C5E0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8009C5E0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8009C5E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009C5E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009C5EC: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009C5F0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C5F4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8009C5F8: nop

    // 0x8009C5FC: bc1fl       L_8009C63C
    if (!c1cs) {
        // 0x8009C600: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_8009C63C;
    }
    goto skip_0;
    // 0x8009C600: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_0:
    // 0x8009C604: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009C608: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8009C60C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8009C610: nop

    // 0x8009C614: bc1fl       L_8009C630
    if (!c1cs) {
        // 0x8009C618: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8009C630;
    }
    goto skip_1;
    // 0x8009C618: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x8009C61C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009C620: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009C624: b           L_8009C638
    // 0x8009C628: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
        goto L_8009C638;
    // 0x8009C628: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8009C62C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8009C630:
    // 0x8009C630: nop

    // 0x8009C634: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
L_8009C638:
    // 0x8009C638: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8009C63C:
    // 0x8009C63C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8009C640: jal         0x800F2100
    // 0x8009C644: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x8009C644: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8009C648: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009C64C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009C650: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009C654: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C658: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8009C65C: nop

    // 0x8009C660: bc1fl       L_8009C674
    if (!c1cs) {
        // 0x8009C664: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8009C674;
    }
    goto skip_2;
    // 0x8009C664: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_2:
    // 0x8009C668: b           L_8009C698
    // 0x8009C66C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
        goto L_8009C698;
    // 0x8009C66C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8009C670: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8009C674:
    // 0x8009C674: nop

    // 0x8009C678: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x8009C67C: nop

    // 0x8009C680: bc1fl       L_8009C694
    if (!c1cs) {
        // 0x8009C684: mov.s       $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
            goto L_8009C694;
    }
    goto skip_3;
    // 0x8009C684: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    skip_3:
    // 0x8009C688: b           L_8009C694
    // 0x8009C68C: neg.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = -ctx->f16.fl;
        goto L_8009C694;
    // 0x8009C68C: neg.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = -ctx->f16.fl;
    // 0x8009C690: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8009C694:
    // 0x8009C694: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
L_8009C698:
    // 0x8009C698: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009C69C: jal         0x800F2100
    // 0x8009C6A0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x8009C6A0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8009C6A4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009C6A8: jal         0x800F2100
    // 0x8009C6AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8009C6AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8009C6B0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009C6B4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009C6B8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8009C6BC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8009C6C0: nop

    // 0x8009C6C4: bc1fl       L_8009C6E8
    if (!c1cs) {
        // 0x8009C6C8: lw          $v0, 0xF8($t8)
        ctx->r2 = MEM_W(ctx->r24, 0XF8);
            goto L_8009C6E8;
    }
    goto skip_4;
    // 0x8009C6C8: lw          $v0, 0xF8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF8);
    skip_4:
    // 0x8009C6CC: lw          $v0, 0xF8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XF8);
    // 0x8009C6D0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009C6D4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C6D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8009C6DC: b           L_8009C6F0
    // 0x8009C6E0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_8009C6F0;
    // 0x8009C6E0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8009C6E4: lw          $v0, 0xF8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF8);
L_8009C6E8:
    // 0x8009C6E8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C6EC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_8009C6F0:
    // 0x8009C6F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009C6F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009C6F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009C6FC: lw          $v0, 0xF8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XF8);
    // 0x8009C700: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009C704: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009C708: nop

    // 0x8009C70C: bc1fl       L_8009C73C
    if (!c1cs) {
        // 0x8009C710: sub.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8009C73C;
    }
    goto skip_5;
    // 0x8009C710: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
    // 0x8009C714: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009C718: nop

    // 0x8009C71C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8009C720: nop

    // 0x8009C724: bc1fl       L_8009C744
    if (!c1cs) {
        // 0x8009C728: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009C744;
    }
    goto skip_6;
    // 0x8009C728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8009C72C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8009C730: b           L_8009C740
    // 0x8009C734: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8009C740;
    // 0x8009C734: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8009C738: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
L_8009C73C:
    // 0x8009C73C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8009C740:
    // 0x8009C740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C744:
    // 0x8009C744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009C748: jr          $ra
    // 0x8009C74C: nop

    return;
    // 0x8009C74C: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E00: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E00);
    return;
    // 0x80082E04: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void bamum_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void baanim_getTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CAD0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CAD4: jal         0x8008B2B4
    // 0x8008CAD8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_0;
    // 0x8008CAD8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CAE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CAE4: jr          $ra
    // 0x8008CAE8: nop

    return;
    // 0x8008CAE8: nop

;}
RECOMP_FUNC void _bsbanswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082770: syscall     10
    recomp_syscall_handler(rdram, ctx, 0x80082770);
    return;
    // 0x80082774: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808001BC_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x808001C0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808001C4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x808001C8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808001CC: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x808001D0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x808001D4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808001D8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808001DC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808001E0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808001E4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808001E8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808001EC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808001F0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808001F4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808001F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808001FC: jal         0x80100094
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800204: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800208: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080020C: jal         0x800D8FF8
    // 0x80800210: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800210: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800214: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80800218: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080021C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800220: lwc1        $f2, 0x58($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X58);
    // 0x80800224: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80800228: nop

    // 0x8080022C: bc1f        L_80800240
    if (!c1cs) {
        // 0x80800230: nop
    
            goto L_80800240;
    }
    // 0x80800230: nop

    // 0x80800234: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80800238: b           L_80800248
    // 0x8080023C: swc1        $f6, 0x58($s5)
    MEM_W(0X58, ctx->r21) = ctx->f6.u32l;
        goto L_80800248;
    // 0x8080023C: swc1        $f6, 0x58($s5)
    MEM_W(0X58, ctx->r21) = ctx->f6.u32l;
L_80800240:
    // 0x80800240: jal         0x80089CA8
    // 0x80800244: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800244: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
L_80800248:
    // 0x80800248: lw          $v0, 0x6C($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X6C);
    // 0x8080024C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80800250: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1808, 0X1080) << 16);
    // 0x80800254: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800258: beq         $t7, $zero, L_80800488
    if (ctx->r15 == 0) {
        // 0x8080025C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800488;
    }
    // 0x8080025C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800260: lwc1        $f26, 0x1080($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1808, 0X1080));
    // 0x80800264: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1808, 0X1084) << 16);
    // 0x80800268: lwc1        $f24, 0x1084($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1808, 0X1084));
    // 0x8080026C: addiu       $s7, $sp, 0xB8
    ctx->r23 = ADD32(ctx->r29, 0XB8);
    // 0x80800270: addiu       $s6, $sp, 0x90
    ctx->r22 = ADD32(ctx->r29, 0X90);
    // 0x80800274: addiu       $s4, $sp, 0x84
    ctx->r20 = ADD32(ctx->r29, 0X84);
    // 0x80800278: addiu       $s3, $sp, 0xAC
    ctx->r19 = ADD32(ctx->r29, 0XAC);
    // 0x8080027C: lbu         $t8, 0x3C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3C);
L_80800280:
    // 0x80800280: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800284: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800288: beq         $t8, $at, L_80800298
    if (ctx->r24 == ctx->r1) {
        // 0x8080028C: addiu       $s1, $s0, 0x24
        ctx->r17 = ADD32(ctx->r16, 0X24);
            goto L_80800298;
    }
    // 0x8080028C: addiu       $s1, $s0, 0x24
    ctx->r17 = ADD32(ctx->r16, 0X24);
    // 0x80800290: b           L_80800478
    // 0x80800294: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
        goto L_80800478;
    // 0x80800294: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_80800298:
    // 0x80800298: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080029C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808002A0: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    // 0x808002A4: jal         0x800EFA20
    // 0x808002A8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    func_800EFA20(rdram, ctx);
        goto after_3;
    // 0x808002A8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    after_3:
    // 0x808002AC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808002B0: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x808002B4: jal         0x800EE780
    // 0x808002B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x808002B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x808002BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808002C0: jal         0x800EF04C
    // 0x808002C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808002C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x808002C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808002CC: jal         0x800EE7F8
    // 0x808002D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808002D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_6:
    // 0x808002D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808002D8: jal         0x800EE7F8
    // 0x808002DC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808002DC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_7:
    // 0x808002E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808002E4: jal         0x800EF04C
    // 0x808002E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x808002E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_8:
    // 0x808002EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808002F0: jal         0x800EF04C
    // 0x808002F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x808002F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x808002F8: lwc1        $f10, 0x8($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X8);
    // 0x808002FC: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800300: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800304: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800308: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080030C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800310: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800314: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800318: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8080031C: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x80800320: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80800324: bc1f        L_80800334
    if (!c1cs) {
        // 0x80800328: nop
    
            goto L_80800334;
    }
    // 0x80800328: nop

    // 0x8080032C: b           L_8080045C
    // 0x80800330: sb          $t9, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r25;
        goto L_8080045C;
    // 0x80800330: sb          $t9, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r25;
L_80800334:
    // 0x80800334: jal         0x800BEF00
    // 0x80800338: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    func_800BEF00(rdram, ctx);
        goto after_10;
    // 0x80800338: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    after_10:
    // 0x8080033C: beql        $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x80800340: lwc1        $f4, 0x24($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
            goto L_8080040C;
    }
    goto skip_0;
    // 0x80800340: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x80800344: jal         0x800EEF94
    // 0x80800348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF94(rdram, ctx);
        goto after_11;
    // 0x80800348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8080034C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800350: jal         0x800EEF94
    // 0x80800354: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EEF94(rdram, ctx);
        goto after_12;
    // 0x80800354: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80800358: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080035C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800360: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800364: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800368: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080036C: jal         0x800EEAD4
    // 0x80800370: nop

    func_800EEAD4(rdram, ctx);
        goto after_13;
    // 0x80800370: nop

    after_13:
    // 0x80800374: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800378: nop

    // 0x8080037C: bc1fl       L_808003A8
    if (!c1cs) {
        // 0x80800380: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808003A8;
    }
    goto skip_1;
    // 0x80800380: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80800384: div.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800388: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1808, 0X1088) << 16);
    // 0x8080038C: lwc1        $f10, 0x1088($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1808, 0X1088));
    // 0x80800390: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800394: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800398: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080039C: jal         0x800EF334
    // 0x808003A0: nop

    func_800EF334(rdram, ctx);
        goto after_14;
    // 0x808003A0: nop

    after_14:
    // 0x808003A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808003A8:
    // 0x808003A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003AC: jal         0x800EFDE8
    // 0x808003B0: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    func_800EFDE8(rdram, ctx);
        goto after_15;
    // 0x808003B0: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    after_15:
    // 0x808003B4: mul.s       $f8, $f22, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x808003B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003BC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808003C0: jal         0x800EF368
    // 0x808003C4: nop

    func_800EF368(rdram, ctx);
        goto after_16;
    // 0x808003C4: nop

    after_16:
    // 0x808003C8: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x808003CC: jal         0x800EF334
    // 0x808003D0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800EF334(rdram, ctx);
        goto after_17;
    // 0x808003D0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_17:
    // 0x808003D4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808003D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003DC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x808003E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808003E4: c.lt.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl < ctx->f18.fl;
    // 0x808003E8: nop

    // 0x808003EC: bc1f        L_808003F8
    if (!c1cs) {
        // 0x808003F0: nop
    
            goto L_808003F8;
    }
    // 0x808003F0: nop

    // 0x808003F4: sb          $t0, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r8;
L_808003F8:
    // 0x808003F8: jal         0x8080007C
    // 0x808003FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_8080007C_chskeletonexplode(rdram, ctx);
        goto after_18;
    // 0x808003FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_18:
    // 0x80800400: b           L_80800460
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800460;
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
L_8080040C:
    // 0x8080040C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800410: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80800414: nop

    // 0x80800418: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8080041C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80800420: jal         0x800D8FF8
    // 0x80800424: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_19;
    // 0x80800424: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    after_19:
    // 0x80800428: lwc1        $f18, 0x34($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X34);
    // 0x8080042C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800430: addiu       $s1, $s0, 0x30
    ctx->r17 = ADD32(ctx->r16, 0X30);
    // 0x80800434: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800438: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080043C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800440: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800444: jal         0x800EF04C
    // 0x80800448: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80800448: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    after_20:
    // 0x8080044C: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80800450: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80800454: jal         0x800EF334
    // 0x80800458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF334(rdram, ctx);
        goto after_21;
    // 0x80800458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
L_8080045C:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800460:
    // 0x80800460: jal         0x800EF04C
    // 0x80800464: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x80800464: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_22:
    // 0x80800468: lw          $v0, 0x6C($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X6C);
    // 0x8080046C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80800470: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x80800474: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80800478:
    // 0x80800478: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8080047C: sltu        $at, $fp, $v0
    ctx->r1 = ctx->r30 < ctx->r2 ? 1 : 0;
    // 0x80800480: bnel        $at, $zero, L_80800280
    if (ctx->r1 != 0) {
        // 0x80800484: lbu         $t8, 0x3C($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X3C);
            goto L_80800280;
    }
    goto skip_2;
    // 0x80800484: lbu         $t8, 0x3C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3C);
    skip_2:
L_80800488:
    // 0x80800488: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8080048C: beql        $t2, $zero, L_808004A0
    if (ctx->r10 == 0) {
        // 0x80800490: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A0;
    }
    goto skip_3;
    // 0x80800490: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_3:
    // 0x80800494: jal         0x80089CA8
    // 0x80800498: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80800498: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_23:
    // 0x8080049C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_808004A0:
    // 0x808004A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808004A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808004A8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808004AC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808004B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808004B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808004B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808004BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808004C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808004C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x808004C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x808004CC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x808004D0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x808004D4: jr          $ra
    // 0x808004D8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x808004D8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void bskazegghead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800832E0
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800018: addiu       $a1, $zero, 0x28D
    ctx->r5 = ADD32(0, 0X28D);
    // 0x8080001C: jal         0x8008CDB8
    // 0x80800020: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_1;
    // 0x80800020: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_1:
    // 0x80800024: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800034: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800038: jal         0x8009FFD8
    // 0x8080003C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80800048: jal         0x8009C99C
    // 0x8080004C: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x8080004C: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_3:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x8009B9B0
    // 0x80800058: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800058: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x800A0CF4
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080006C: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800070: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x80800074: jal         0x80094510
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_6;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080007C: sw          $v0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r2;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800088: jal         0x80098140
    // 0x8080008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_7;
    // 0x8080008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800094: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80801338_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801338: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8080133C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801340: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801344: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801348: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080134C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801354: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80801358: jal         0x80100094
    // 0x8080135C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080135C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801360: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801364: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80801368: jal         0x80088368
    // 0x8080136C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080136C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x80801370: blez        $v0, L_808013CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801374: addiu       $s2, $s4, 0x30
        ctx->r18 = ADD32(ctx->r20, 0X30);
            goto L_808013CC;
    }
    // 0x80801374: addiu       $s2, $s4, 0x30
    ctx->r18 = ADD32(ctx->r20, 0X30);
    // 0x80801378: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8080137C: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x80801380: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80801384: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80801388:
    // 0x80801388: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080138C: jal         0x800899A8
    // 0x80801390: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80801390: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x80801394: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801398: beq         $at, $zero, L_808013A4
    if (ctx->r1 == 0) {
        // 0x8080139C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_808013A4;
    }
    // 0x8080139C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x808013A0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_808013A4:
    // 0x808013A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808013A8: jal         0x800AA20C
    // 0x808013AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800AA20C(rdram, ctx);
        goto after_3;
    // 0x808013AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808013B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808013B4: jal         0x80088368
    // 0x808013B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808013B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808013BC: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808013C0: bnel        $at, $zero, L_80801388
    if (ctx->r1 != 0) {
        // 0x808013C4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801388;
    }
    goto skip_0;
    // 0x808013C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808013C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808013CC:
    // 0x808013CC: jal         0x80088368
    // 0x808013D0: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808013D0: nop

    after_5:
    // 0x808013D4: blez        $v0, L_80801418
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808013D8: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_80801418;
    }
    // 0x808013D8: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x808013DC: addiu       $t9, $sp, 0x5C
    ctx->r25 = ADD32(ctx->r29, 0X5C);
    // 0x808013E0: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x808013E4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_808013E8:
    // 0x808013E8: addiu       $a0, $s4, 0x30
    ctx->r4 = ADD32(ctx->r20, 0X30);
    // 0x808013EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808013F0: bne         $s3, $t0, L_80801400
    if (ctx->r19 != ctx->r8) {
        // 0x808013F4: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80801400;
    }
    // 0x808013F4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808013F8: jal         0x800899C0
    // 0x808013FC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    _sumultiscore_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808013FC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_6:
L_80801400:
    // 0x80801400: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801404: jal         0x80088368
    // 0x80801408: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80801408: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x8080140C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801410: bnel        $at, $zero, L_808013E8
    if (ctx->r1 != 0) {
        // 0x80801414: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_808013E8;
    }
    goto skip_1;
    // 0x80801414: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80801418:
    // 0x80801418: jal         0x80088368
    // 0x8080141C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x8080141C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_8:
    // 0x80801420: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80801424: bne         $at, $zero, L_808014A0
    if (ctx->r1 != 0) {
        // 0x80801428: addiu       $s2, $sp, 0x5C
        ctx->r18 = ADD32(ctx->r29, 0X5C);
            goto L_808014A0;
    }
    // 0x80801428: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x8080142C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_80801430:
    // 0x80801430: blez        $s0, L_8080148C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80801434: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_8080148C;
    }
    // 0x80801434: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80801438: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8080143C: addu        $v0, $s2, $t1
    ctx->r2 = ADD32(ctx->r18, ctx->r9);
    // 0x80801440: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x80801444: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80801448: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8080144C: addu        $v0, $s2, $t4
    ctx->r2 = ADD32(ctx->r18, ctx->r12);
    // 0x80801450: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80801454: beq         $at, $zero, L_8080148C
    if (ctx->r1 == 0) {
        // 0x80801458: nop
    
            goto L_8080148C;
    }
    // 0x80801458: nop

    // 0x8080145C: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x80801460: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801464: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80801468:
    // 0x80801468: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x8080146C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80801470: bne         $at, $zero, L_8080148C
    if (ctx->r1 != 0) {
        // 0x80801474: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_8080148C;
    }
    // 0x80801474: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80801478: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x8080147C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801480: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80801484: bnel        $at, $zero, L_80801468
    if (ctx->r1 != 0) {
        // 0x80801488: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80801468;
    }
    goto skip_2;
    // 0x80801488: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    skip_2:
L_8080148C:
    // 0x8080148C: jal         0x80088368
    // 0x80801490: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80801490: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_9:
    // 0x80801494: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801498: bne         $at, $zero, L_80801430
    if (ctx->r1 != 0) {
        // 0x8080149C: addiu       $a2, $sp, 0x60
        ctx->r6 = ADD32(ctx->r29, 0X60);
            goto L_80801430;
    }
    // 0x8080149C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_808014A0:
    // 0x808014A0: jal         0x800FC6B0
    // 0x808014A4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_10;
    // 0x808014A4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x808014A8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x808014AC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x808014B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808014B4: addiu       $s2, $s4, 0x30
    ctx->r18 = ADD32(ctx->r20, 0X30);
    // 0x808014B8: beq         $t5, $t6, L_80801508
    if (ctx->r13 == ctx->r14) {
        // 0x808014BC: addiu       $s0, $zero, 0x10D0
        ctx->r16 = ADD32(0, 0X10D0);
            goto L_80801508;
    }
    // 0x808014BC: addiu       $s0, $zero, 0x10D0
    ctx->r16 = ADD32(0, 0X10D0);
    // 0x808014C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808014C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808014C8: jal         0x800899A8
    // 0x808014CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x808014CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_11:
    // 0x808014D0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x808014D4: beql        $v0, $t7, L_80801500
    if (ctx->r2 == ctx->r15) {
        // 0x808014D8: sw          $s1, 0x8($s4)
        MEM_W(0X8, ctx->r20) = ctx->r17;
            goto L_80801500;
    }
    goto skip_3;
    // 0x808014D8: sw          $s1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r17;
    skip_3:
    // 0x808014DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808014E0:
    // 0x808014E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808014E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808014E8: jal         0x800899A8
    // 0x808014EC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x808014EC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_12:
    // 0x808014F0: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x808014F4: bnel        $v0, $t8, L_808014E0
    if (ctx->r2 != ctx->r24) {
        // 0x808014F8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808014E0;
    }
    goto skip_4;
    // 0x808014F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x808014FC: sw          $s1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r17;
L_80801500:
    // 0x80801500: b           L_80801508
    // 0x80801504: addiu       $s0, $zero, 0x10CF
    ctx->r16 = ADD32(0, 0X10CF);
        goto L_80801508;
    // 0x80801504: addiu       $s0, $zero, 0x10CF
    ctx->r16 = ADD32(0, 0X10CF);
L_80801508:
    // 0x80801508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080150C: jal         0x8008A090
    // 0x80801510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80801510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801514: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80801518: sw          $s0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r16;
    // 0x8080151C: sw          $t9, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r25;
    // 0x80801520: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80801524: jal         0x80101FDC
    // 0x80801528: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80801528: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x8080152C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801530: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801534: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801538: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080153C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801540: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801544: jr          $ra
    // 0x80801548: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80801548: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_808003AC_chcrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $v0, $a0, -0x32
    ctx->r2 = ADD32(ctx->r4, -0X32);
    // 0x808003B0: blez        $v0, L_808003C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808003B4: sll         $t6, $v0, 1
        ctx->r14 = S32(ctx->r2 << 1);
            goto L_808003C8;
    }
    // 0x808003B4: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x808003B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1912, 0X53C) << 16);
    // 0x808003BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003C0: jr          $ra
    // 0x808003C4: lh          $v0, 0x53C($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1912, 0X53C));
    return;
    // 0x808003C4: lh          $v0, 0x53C($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1912, 0X53C));
L_808003C8:
    // 0x808003C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

    // 0x808003D4: nop

    // 0x808003D8: nop

    // 0x808003DC: nop

;}
RECOMP_FUNC void badeathmatch_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x808003B0: jr          $ra
    // 0x808003B4: sb          $a1, 0x20($t6)
    MEM_B(0X20, ctx->r14) = ctx->r5;
    return;
    // 0x808003B4: sb          $a1, 0x20($t6)
    MEM_B(0X20, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800F362C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F362C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800F3630: bgez        $v0, L_800F3640
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F3634: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F3640;
    }
    // 0x800F3634: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F3638: b           L_800F3654
    // 0x800F363C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_800F3654;
    // 0x800F363C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_800F3640:
    // 0x800F3640: bne         $at, $zero, L_800F3650
    if (ctx->r1 != 0) {
        // 0x800F3644: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F3650;
    }
    // 0x800F3644: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F3648: b           L_800F3650
    // 0x800F364C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F3650;
    // 0x800F364C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F3650:
    // 0x800F3650: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_800F3654:
    // 0x800F3654: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800F3658: bgez        $v0, L_800F3668
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F365C: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F3668;
    }
    // 0x800F365C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F3660: b           L_800F367C
    // 0x800F3664: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
        goto L_800F367C;
    // 0x800F3664: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
L_800F3668:
    // 0x800F3668: bne         $at, $zero, L_800F3678
    if (ctx->r1 != 0) {
        // 0x800F366C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F3678;
    }
    // 0x800F366C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F3670: b           L_800F3678
    // 0x800F3674: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F3678;
    // 0x800F3674: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F3678:
    // 0x800F3678: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
L_800F367C:
    // 0x800F367C: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800F3680: bgez        $v0, L_800F3690
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F3684: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F3690;
    }
    // 0x800F3684: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F3688: b           L_800F36A4
    // 0x800F368C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
        goto L_800F36A4;
    // 0x800F368C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_800F3690:
    // 0x800F3690: bne         $at, $zero, L_800F36A0
    if (ctx->r1 != 0) {
        // 0x800F3694: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F36A0;
    }
    // 0x800F3694: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F3698: b           L_800F36A0
    // 0x800F369C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F36A0;
    // 0x800F369C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F36A0:
    // 0x800F36A0: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
L_800F36A4:
    // 0x800F36A4: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800F36A8: bgez        $v0, L_800F36B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F36AC: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_800F36B8;
    }
    // 0x800F36AC: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800F36B0: jr          $ra
    // 0x800F36B4: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    return;
    // 0x800F36B4: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
L_800F36B8:
    // 0x800F36B8: bne         $at, $zero, L_800F36C8
    if (ctx->r1 != 0) {
        // 0x800F36BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F36C8;
    }
    // 0x800F36BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F36C0: b           L_800F36C8
    // 0x800F36C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_800F36C8;
    // 0x800F36C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800F36C8:
    // 0x800F36C8: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x800F36CC: jr          $ra
    // 0x800F36D0: nop

    return;
    // 0x800F36D0: nop

;}
RECOMP_FUNC void func_800FC8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC8EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC8F4: jal         0x800FB5F8
    // 0x800FC8F8: nop

    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC8F8: nop

    after_0:
    // 0x800FC8FC: beq         $v0, $zero, L_800FC924
    if (ctx->r2 == 0) {
        // 0x800FC900: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800FC924;
    }
    // 0x800FC900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FC904: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800FC908: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800FC90C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FC910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FC914: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x800FC918: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800FC91C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800FC920: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
L_800FC924:
    // 0x800FC924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC92C: jr          $ra
    // 0x800FC930: nop

    return;
    // 0x800FC930: nop

;}
RECOMP_FUNC void _bashoessuck_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085098: syscall     149
    recomp_syscall_handler(rdram, ctx, 0x80085098);
    return;
    // 0x8008509C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80802A40_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802A4C: jal         0x800A3280
    // 0x80802A50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802A50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802A54: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80802A58: lui         $v1, 0x8081
    ctx->r3 = S32(RELOC_HI16(439, 0XB45C) << 16);
    // 0x80802A5C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80802A60: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80802A64: lw          $v1, -0x4BA4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(439, 0XB45C));
    // 0x80802A68: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80802A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802A70: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80802A74: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    // 0x80802A78: bnel        $a3, $zero, L_80802A8C
    if (ctx->r7 != 0) {
        // 0x80802A7C: lh          $a1, 0x0($v1)
        ctx->r5 = MEM_H(ctx->r3, 0X0);
            goto L_80802A8C;
    }
    goto skip_0;
    // 0x80802A7C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    skip_0:
    // 0x80802A80: b           L_80802A98
    // 0x80802A84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802A98;
    // 0x80802A84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802A88: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
L_80802A8C:
    // 0x80802A8C: jal         0x8009DF18
    // 0x80802A90: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    func_8009DF18(rdram, ctx);
        goto after_1;
    // 0x80802A90: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x80802A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802A98:
    // 0x80802A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802AA0: jr          $ra
    // 0x80802AA4: nop

    return;
    // 0x80802AA4: nop

;}
RECOMP_FUNC void func_808002A0_gcsectionskip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808002A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x808002AC: beq         $a1, $zero, L_80800364
    if (ctx->r5 == 0) {
        // 0x808002B0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80800364;
    }
    // 0x808002B0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808002B4: lbu         $t6, 0x13($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X13);
    // 0x808002B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002BC: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808002C0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x808002C4: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x808002C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808002CC: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808002D0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808002D4: bgez        $t9, L_808002E8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808002D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808002E8;
    }
    // 0x808002D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002E0: nop

    // 0x808002E4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808002E8:
    // 0x808002E8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x808002EC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808002F0: jal         0x800F5D9C
    // 0x808002F4: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    func_800F5D9C(rdram, ctx);
        goto after_0;
    // 0x808002F4: sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    after_0:
    // 0x808002F8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808002FC: jal         0x800F5D70
    // 0x80800300: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5D70(rdram, ctx);
        goto after_1;
    // 0x80800300: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800304: jal         0x800D8FF8
    // 0x80800308: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800308: nop

    after_2:
    // 0x8080030C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800310: jal         0x800EF334
    // 0x80800314: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800314: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80800318: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080031C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800320: jal         0x800EFB24
    // 0x80800324: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x80800324: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x80800328: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080032C: jal         0x800EE88C
    // 0x80800330: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800EE88C(rdram, ctx);
        goto after_5;
    // 0x80800330: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x80800334: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800338: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080033C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800340: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80800344: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x80800348: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080034C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800350: jal         0x8080019C
    // 0x80800354: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8080019C_gcsectionskip(rdram, ctx);
        goto after_6;
    // 0x80800354: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80800358: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8080035C: jal         0x800F8418
    // 0x80800360: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F8418(rdram, ctx);
        goto after_7;
    // 0x80800360: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_7:
L_80800364:
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800368: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

;}
RECOMP_FUNC void func_80800A30_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A38: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800A3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A40: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800A44: addiu       $t6, $zero, 0x2812
    ctx->r14 = ADD32(0, 0X2812);
    // 0x80800A48: addiu       $t7, $zero, 0xA02
    ctx->r15 = ADD32(0, 0XA02);
    // 0x80800A4C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800A54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A5C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800A60: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800A64: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800A68: jal         0x80086898
    // 0x80800A6C: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800A6C: nop

    after_0:
    // 0x80800A70: beq         $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A74: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800A8C;
    }
    // 0x80800A74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A78: jal         0x800868A8
    // 0x80800A7C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800A7C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x80800A80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A84: jal         0x800868B8
    // 0x80800A88: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800A88: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
L_80800A8C:
    // 0x80800A8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A94: jr          $ra
    // 0x80800A98: nop

    return;
    // 0x80800A98: nop

    // 0x80800A9C: nop

;}
RECOMP_FUNC void func_80800D00_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D00: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800D04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D0C: jal         0x80101080
    // 0x80800D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800D14: jal         0x80106790
    // 0x80800D18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800D18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800D1C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800D28: jal         0x800866A0
    // 0x80800D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800D30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800D34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800D38: jal         0x800866A0
    // 0x80800D3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800D3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800D40: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800D44: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800D48: jal         0x80086688
    // 0x80800D4C: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800D4C: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    after_4:
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: jal         0x80089CD8
    // 0x80800D58: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800D58: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x80800D5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800D60: jal         0x80089CE8
    // 0x80800D64: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800D64: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x80800D68: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D6C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X139C) << 16);
    // 0x80800D70: addiu       $a2, $a2, 0x139C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X139C));
    // 0x80800D74: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800D78: jal         0x80089D18
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800D80: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800D84: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800D88: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800D8C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800D90: jal         0x80089BF8
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800D98: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA0: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800DA4: jal         0x80800E78
    // 0x80800DA8: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    func_80800E78_chonearmbandit(rdram, ctx);
        goto after_9;
    // 0x80800DA8: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    after_9:
    // 0x80800DAC: beq         $v0, $zero, L_80800DD0
    if (ctx->r2 == 0) {
        // 0x80800DB0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800DD0;
    }
    // 0x80800DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800DB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800DBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800DC0: jal         0x800D1000
    // 0x80800DC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_10;
    // 0x80800DC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x80800DC8: b           L_80800E4C
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800E4C;
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800DD0:
    // 0x80800DD0: jal         0x8010A430
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A430(rdram, ctx);
        goto after_11;
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800DD8: beq         $v0, $zero, L_80800E48
    if (ctx->r2 == 0) {
        // 0x80800DDC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(896, 0X11E4) << 16);
            goto L_80800E48;
    }
    // 0x80800DDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(896, 0X11E4) << 16);
    // 0x80800DE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800DE4: jal         0x800DC178
    // 0x80800DE8: lwc1        $f14, 0x11E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(896, 0X11E4));
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800DE8: lwc1        $f14, 0x11E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(896, 0X11E4));
    after_12:
    // 0x80800DEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800DF0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800DF4: jal         0x800DC298
    // 0x80800DF8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800DC298(rdram, ctx);
        goto after_13;
    // 0x80800DF8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80800DFC: beq         $v0, $zero, L_80800E10
    if (ctx->r2 == 0) {
        // 0x80800E00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E10;
    }
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E04: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80800E08: b           L_80800E18
    // 0x80800E0C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80800E18;
    // 0x80800E0C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80800E10:
    // 0x80800E10: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    // 0x80800E14: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
L_80800E18:
    // 0x80800E18: jal         0x80103DFC
    // 0x80800E1C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80103DFC(rdram, ctx);
        goto after_14;
    // 0x80800E1C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_14:
    // 0x80800E20: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800E24: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800E28: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800E2C: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80800E30: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800E34: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800E38: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E3C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800E40: jal         0x80086D50
    // 0x80800E44: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800E44: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_15:
L_80800E48:
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E4C:
    // 0x80800E4C: jal         0x80107070
    // 0x80800E50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_16;
    // 0x80800E50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
    // 0x80800E54: bnel        $v0, $zero, L_80800E68
    if (ctx->r2 != 0) {
        // 0x80800E58: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E68;
    }
    goto skip_0;
    // 0x80800E58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800E5C: jal         0x800FFAB0
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800E64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E68:
    // 0x80800E68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E6C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800E70: jr          $ra
    // 0x80800E74: nop

    return;
    // 0x80800E74: nop

;}
RECOMP_FUNC void _chonearmbandit_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D08: syscall     229
    recomp_syscall_handler(rdram, ctx, 0x80085D08);
    return;
    // 0x80085D0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080118C_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080118C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801198: jal         0x80082840
    // 0x8080119C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080119C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808011A0: jal         0x80082FE8
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808011A8: jal         0x80084800
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808011B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011B4: bne         $v0, $at, L_808011D4
    if (ctx->r2 != ctx->r1) {
        // 0x808011B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011D4;
    }
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011BC: jal         0x800919F4
    // 0x808011C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_3;
    // 0x808011C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808011C4: beql        $v0, $zero, L_808011D8
    if (ctx->r2 == 0) {
        // 0x808011C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011D8;
    }
    goto skip_0;
    // 0x808011C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808011CC: jal         0x80084550
    // 0x808011D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808011D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808011D4:
    // 0x808011D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011D8:
    // 0x808011D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011E0: jr          $ra
    // 0x808011E4: nop

    return;
    // 0x808011E4: nop

;}
RECOMP_FUNC void func_808005BC_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005C8: jal         0x8008CABC
    // 0x808005CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808005CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808005D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808005D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005E0: jal         0x80098140
    // 0x808005E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_1;
    // 0x808005E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808005E8: lui         $a1, 0x3E42
    ctx->r5 = S32(0X3E42 << 16);
    // 0x808005EC: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x808005F0: jal         0x8008B348
    // 0x808005F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x808005F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808005F8: beq         $v0, $zero, L_8080060C
    if (ctx->r2 == 0) {
        // 0x808005FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080060C;
    }
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: addiu       $a1, $zero, 0x57C
    ctx->r5 = ADD32(0, 0X57C);
    // 0x80800604: jal         0x8009DE38
    // 0x80800608: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_3;
    // 0x80800608: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
L_8080060C:
    // 0x8080060C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800610: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800614: jal         0x8008B348
    // 0x80800618: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x80800618: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8080061C: beq         $v0, $zero, L_80800634
    if (ctx->r2 == 0) {
        // 0x80800620: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_80800634;
    }
    // 0x80800620: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800624: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x8009DBF0
    // 0x80800630: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DBF0(rdram, ctx);
        goto after_5;
    // 0x80800630: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_5:
L_80800634:
    // 0x80800634: lui         $a1, 0x3EF5
    ctx->r5 = S32(0X3EF5 << 16);
    // 0x80800638: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x8080063C: jal         0x8008B348
    // 0x80800640: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80800640: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800644: beql        $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x80800648: lui         $a1, 0x3F05
        ctx->r5 = S32(0X3F05 << 16);
            goto L_80800658;
    }
    goto skip_0;
    // 0x80800648: lui         $a1, 0x3F05
    ctx->r5 = S32(0X3F05 << 16);
    skip_0:
    // 0x8080064C: jal         0x8009FE58
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_7;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800654: lui         $a1, 0x3F05
    ctx->r5 = S32(0X3F05 << 16);
L_80800658:
    // 0x80800658: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x8080065C: jal         0x8008B348
    // 0x80800660: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x80800660: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800664: beq         $v0, $zero, L_80800678
    if (ctx->r2 == 0) {
        // 0x80800668: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800678;
    }
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    // 0x80800670: jal         0x8009DE38
    // 0x80800674: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_9;
    // 0x80800674: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
L_80800678:
    // 0x80800678: lui         $a1, 0x3DFB
    ctx->r5 = S32(0X3DFB << 16);
    // 0x8080067C: ori         $a1, $a1, 0xE76D
    ctx->r5 = ctx->r5 | 0XE76D;
    // 0x80800680: jal         0x8008B348
    // 0x80800684: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800684: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800688: beq         $v0, $zero, L_808006A4
    if (ctx->r2 == 0) {
        // 0x8080068C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006A4;
    }
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x800A0CD0
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_11;
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x80084538
    // 0x808006A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babackpack_set_state(rdram, ctx);
        goto after_12;
    // 0x808006A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
L_808006A4:
    // 0x808006A4: lui         $a1, 0x3F03
    ctx->r5 = S32(0X3F03 << 16);
    // 0x808006A8: ori         $a1, $a1, 0xB646
    ctx->r5 = ctx->r5 | 0XB646;
    // 0x808006AC: jal         0x8008B348
    // 0x808006B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x808006B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808006B4: beq         $v0, $zero, L_808006C8
    if (ctx->r2 == 0) {
        // 0x808006B8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808006C8;
    }
    // 0x808006B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808006BC: sb          $t6, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r14;
    // 0x808006C0: jal         0x808002D4
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_14;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808006C8:
    // 0x808006C8: jal         0x8008CAEC
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_15;
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808006D0: beq         $v0, $zero, L_808006E0
    if (ctx->r2 == 0) {
        // 0x808006D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E0;
    }
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: addiu       $t7, $zero, 0x165
    ctx->r15 = ADD32(0, 0X165);
    // 0x808006DC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_808006E0:
    // 0x808006E0: jal         0x8009E5C8
    // 0x808006E4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x808006E4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x808006E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006F4: jr          $ra
    // 0x808006F8: nop

    return;
    // 0x808006F8: nop

;}
RECOMP_FUNC void func_80800914_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800918: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080091C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800920: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800924: jal         0x80100094
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080092C: jal         0x800F54E4
    // 0x80800930: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800930: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800934: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80800938: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8080093C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800940: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80800944: beq         $v1, $at, L_8080095C
    if (ctx->r3 == ctx->r1) {
        // 0x80800948: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080095C;
    }
    // 0x80800948: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080094C: beq         $v1, $at, L_80800A20
    if (ctx->r3 == ctx->r1) {
        // 0x80800950: nop
    
            goto L_80800A20;
    }
    // 0x80800950: nop

    // 0x80800954: b           L_80800AE4
    // 0x80800958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AE4;
    // 0x80800958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080095C:
    // 0x8080095C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XEA0) << 16);
    // 0x80800960: lwc1        $f4, 0xEA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XEA0));
    // 0x80800964: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80800968: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080096C: nop

    // 0x80800970: bc1fl       L_80800AE4
    if (!c1cs) {
        // 0x80800974: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800AE4;
    }
    goto skip_0;
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800978: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080097C: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800980: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800984: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800988: bltz        $t8, L_80800AE0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080098C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE0;
    }
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800990: jal         0x8080070C
    // 0x80800994: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_8080070C_chcablecar(rdram, ctx);
        goto after_2;
    // 0x80800994: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_2:
    // 0x80800998: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x8080099C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x808009A0: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x808009A4: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x808009A8: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x808009AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808009B0: ori         $a3, $a3, 0x2010
    ctx->r7 = ctx->r7 | 0X2010;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x808009BC: jal         0x8008A2E0
    // 0x808009C0: addiu       $a1, $t0, 0x2C
    ctx->r5 = ADD32(ctx->r8, 0X2C);
    _susubgame_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808009C0: addiu       $a1, $t0, 0x2C
    ctx->r5 = ADD32(ctx->r8, 0X2C);
    after_3:
    // 0x808009C4: lui         $a2, 0xC3D4
    ctx->r6 = S32(0XC3D4 << 16);
    // 0x808009C8: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808009CC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808009D0: lui         $a1, 0xC2A0
    ctx->r5 = S32(0XC2A0 << 16);
    // 0x808009D4: jal         0x800EFA4C
    // 0x808009D8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808009D8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x808009DC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808009E0: jal         0x800EF04C
    // 0x808009E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808009E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808009E8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808009EC: jal         0x800F8294
    // 0x808009F0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F8294(rdram, ctx);
        goto after_6;
    // 0x808009F0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x808009F4: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800A00: lui         $a2, 0x4387
    ctx->r6 = S32(0X4387 << 16);
    // 0x80800A04: jal         0x800EFA4C
    // 0x80800A08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800A08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_7:
    // 0x80800A0C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A10: jal         0x800F8444
    // 0x80800A14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F8444(rdram, ctx);
        goto after_8;
    // 0x80800A14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80800A18: b           L_80800AE4
    // 0x80800A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AE4;
    // 0x80800A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A20:
    // 0x80800A20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XEA4) << 16);
    // 0x80800A24: lwc1        $f10, 0xEA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XEA4));
    // 0x80800A28: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80800A2C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800A30: nop

    // 0x80800A34: bc1fl       L_80800AE4
    if (!c1cs) {
        // 0x80800A38: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800AE4;
    }
    goto skip_1;
    // 0x80800A38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800A3C: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800A40: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800A44: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800A48: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800A4C: bltz        $t5, L_80800AE0
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800A50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE0;
    }
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A54: jal         0x8080070C
    // 0x80800A58: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    func_8080070C_chcablecar(rdram, ctx);
        goto after_9;
    // 0x80800A58: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    after_9:
    // 0x80800A5C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A60: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80800A64: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80800A68: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800A6C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800A70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A74: ori         $a3, $a3, 0x2010
    ctx->r7 = ctx->r7 | 0X2010;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    // 0x80800A80: jal         0x8008A2E0
    // 0x80800A84: addiu       $a1, $t0, 0x2C
    ctx->r5 = ADD32(ctx->r8, 0X2C);
    _susubgame_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x80800A84: addiu       $a1, $t0, 0x2C
    ctx->r5 = ADD32(ctx->r8, 0X2C);
    after_10:
    // 0x80800A88: lui         $a2, 0xC3D4
    ctx->r6 = S32(0XC3D4 << 16);
    // 0x80800A8C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800A90: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800A94: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800A98: jal         0x800EFA4C
    // 0x80800A9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x80800A9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x80800AA0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800AA4: jal         0x800EF04C
    // 0x80800AA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800AA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80800AAC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800AB0: jal         0x800F8294
    // 0x80800AB4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F8294(rdram, ctx);
        goto after_13;
    // 0x80800AB4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x80800AB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800ABC: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800ACC: jal         0x800EFA4C
    // 0x80800AD0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x80800AD0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_14:
    // 0x80800AD4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800AD8: jal         0x800F8444
    // 0x80800ADC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F8444(rdram, ctx);
        goto after_15;
    // 0x80800ADC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
L_80800AE0:
    // 0x80800AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AE4:
    // 0x80800AE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800AEC: jr          $ra
    // 0x80800AF0: nop

    return;
    // 0x80800AF0: nop

;}
RECOMP_FUNC void func_800CE9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE9F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE9F4: jal         0x800CE3E0
    // 0x800CE9F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE9F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CE9FC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEA00: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x800CEA04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CEA08: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800CEA0C: beql        $at, $zero, L_800CEA1C
    if (ctx->r1 == 0) {
        // 0x800CEA10: sh          $a2, 0x8($a0)
        MEM_H(0X8, ctx->r4) = ctx->r6;
            goto L_800CEA1C;
    }
    goto skip_0;
    // 0x800CEA10: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800CEA14: sh          $a2, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r6;
    // 0x800CEA18: sh          $a2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r6;
L_800CEA1C:
    // 0x800CEA1C: sh          $a2, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r6;
    // 0x800CEA20: jal         0x800CE438
    // 0x800CEA24: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800CE438(rdram, ctx);
        goto after_1;
    // 0x800CEA24: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800CEA28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEA2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEA30: jr          $ra
    // 0x800CEA34: nop

    return;
    // 0x800CEA34: nop

;}
RECOMP_FUNC void func_80800358_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080035C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800360: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800364: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800368: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080036C: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800370: beq         $t6, $zero, L_808003AC
    if (ctx->r14 == 0) {
        // 0x80800374: nop
    
            goto L_808003AC;
    }
    // 0x80800374: nop

    // 0x80800378: bne         $t6, $at, L_808003B4
    if (ctx->r14 != ctx->r1) {
        // 0x8080037C: addiu       $a0, $a0, 0x2C
        ctx->r4 = ADD32(ctx->r4, 0X2C);
            goto L_808003B4;
    }
    // 0x8080037C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x80800380: jal         0x800D90A4
    // 0x80800384: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800384: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800388: beq         $v0, $zero, L_808003B4
    if (ctx->r2 == 0) {
        // 0x8080038C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808003B4;
    }
    // 0x8080038C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: lhu         $t7, 0x6E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X6E);
    // 0x80800394: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800398: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x8080039C: jal         0x80800564
    // 0x808003A0: sh          $t8, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r24;
    func_80800564_chsquits(rdram, ctx);
        goto after_1;
    // 0x808003A0: sh          $t8, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r24;
    after_1:
    // 0x808003A4: b           L_808003B8
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B8;
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003AC:
    // 0x808003AC: jal         0x808003C4
    // 0x808003B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_808003C4_chsquits(rdram, ctx);
        goto after_2;
    // 0x808003B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_808003B4:
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B8:
    // 0x808003B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_47(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D38: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D38);
    return;
    // 0x80082D3C: addi        $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
;}
RECOMP_FUNC void func_800903F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800903F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800903FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090404: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80090408: jal         0x800F54E4
    // 0x8009040C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009040C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80090410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090414: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80090418: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8009041C: jal         0x800F7844
    // 0x80090420: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800F7844(rdram, ctx);
        goto after_1;
    // 0x80090420: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80090424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009042C: jr          $ra
    // 0x80090430: nop

    return;
    // 0x80090430: nop

;}
RECOMP_FUNC void subaddiesect_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800144: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080014C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800150: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800154: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800158: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8080015C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800160: jal         0x800EE7F8
    // 0x80800164: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800164: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x80800168: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080016C: jal         0x800EE7F8
    // 0x80800170: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800170: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x80800174: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800178: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080017C: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800180: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800184: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800188: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080018C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80800190: jal         0x800BF704
    // 0x80800194: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    func_800BF704(rdram, ctx);
        goto after_2;
    // 0x80800194: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800198: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x8080019C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001A0: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x808001AC: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x808001B0: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x808001B4: jal         0x80087FC8
    // 0x808001B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    _gcmapsects_entrypoint_25(rdram, ctx);
        goto after_3;
    // 0x808001B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x808001BC: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x808001C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800220;
    }
    // 0x808001C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808001C4: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x808001C8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808001CC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001D0: beq         $t8, $zero, L_80800204
    if (ctx->r24 == 0) {
        // 0x808001D4: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_80800204;
    }
    // 0x808001D4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808001D8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x808001DC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808001E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808001E4: jal         0x800F1B78
    // 0x808001E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F1B78(rdram, ctx);
        goto after_4;
    // 0x808001E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x808001EC: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_80800204;
    }
    // 0x808001F0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x808001F4: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808001F8: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x808001FC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800200: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
L_80800204:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8080020C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80800210: jal         0x801045AC
    // 0x80800214: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_801045AC(rdram, ctx);
        goto after_5;
    // 0x80800214: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_5:
    // 0x80800218: b           L_80800224
    // 0x8080021C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800224;
    // 0x8080021C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800220:
    // 0x80800220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800224:
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800228: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080022C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

    // 0x80800238: nop

    // 0x8080023C: nop

;}
RECOMP_FUNC void _bsdronefired_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830B0: syscall     42
    recomp_syscall_handler(rdram, ctx, 0x800830B0);
    return;
    // 0x800830B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idbounce_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C20: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800C24: jal         0x800D8FF8
    // 0x80800C28: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800C28: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800C2C: jal         0x800F54E4
    // 0x80800C30: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800C30: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80800C34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800C38: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800C3C: jal         0x800F5A00
    // 0x80800C40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800C40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800C44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C48: jal         0x800EF3DC
    // 0x80800C4C: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    func_800EF3DC(rdram, ctx);
        goto after_3;
    // 0x80800C4C: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    after_3:
    // 0x80800C50: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800C54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C58: nop

    // 0x80800C5C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80800C60: nop

    // 0x80800C64: bc1t        L_80800C78
    if (c1cs) {
        // 0x80800C68: nop
    
            goto L_80800C78;
    }
    // 0x80800C68: nop

    // 0x80800C6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C70: jal         0x800EF334
    // 0x80800C74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x80800C74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_80800C78:
    // 0x80800C78: jal         0x80800000
    // 0x80800C7C: nop

    func_80800000_idbounce(rdram, ctx);
        goto after_5;
    // 0x80800C7C: nop

    after_5:
    // 0x80800C80: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800C84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2890, 0XE40) << 16);
    // 0x80800C88: lwc1        $f16, 0xE40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2890, 0XE40));
    // 0x80800C8C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80800C90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80800C94: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800C98: nop

    // 0x80800C9C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800CA0: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x80800CA4: lbu         $t6, 0x5480($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5480);
    // 0x80800CA8: beq         $t6, $zero, L_80800CF0
    if (ctx->r14 == 0) {
        // 0x80800CAC: nop
    
            goto L_80800CF0;
    }
    // 0x80800CAC: nop

    // 0x80800CB0: jal         0x800F54E4
    // 0x80800CB4: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800CB4: nop

    after_6:
    // 0x80800CB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CBC: jal         0x800F5D70
    // 0x80800CC0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5D70(rdram, ctx);
        goto after_7;
    // 0x80800CC0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80800CC4: jal         0x80800000
    // 0x80800CC8: nop

    func_80800000_idbounce(rdram, ctx);
        goto after_8;
    // 0x80800CC8: nop

    after_8:
    // 0x80800CCC: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800CD0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800CD4: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800CD8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800CDC: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800CE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800CE4: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800CE8: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80800CEC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_80800CF0:
    // 0x80800CF0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80800CF4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80800CF8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800CFC: beq         $v0, $zero, L_80800D30
    if (ctx->r2 == 0) {
        // 0x80800D00: sw          $t7, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r15;
            goto L_80800D30;
    }
    // 0x80800D00: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x80800D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D08: beq         $v0, $at, L_80800D4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D0C: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80800D4C;
    }
    // 0x80800D0C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800D10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D14: beq         $v0, $at, L_80800D68
    if (ctx->r2 == ctx->r1) {
        // 0x80800D18: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80800D68;
    }
    // 0x80800D18: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800D1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800D20: beq         $v0, $at, L_80800D68
    if (ctx->r2 == ctx->r1) {
        // 0x80800D24: nop
    
            goto L_80800D68;
    }
    // 0x80800D24: nop

    // 0x80800D28: b           L_80800D80
    // 0x80800D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D80;
    // 0x80800D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D30:
    // 0x80800D30: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800D34: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800D38: addiu       $a2, $a2, -0x7368
    ctx->r6 = ADD32(ctx->r6, -0X7368);
    // 0x80800D3C: jal         0x80088660
    // 0x80800D40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800D40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_9:
    // 0x80800D44: b           L_80800D80
    // 0x80800D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D80;
    // 0x80800D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D4C:
    // 0x80800D4C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800D50: addiu       $a2, $a2, -0x7360
    ctx->r6 = ADD32(ctx->r6, -0X7360);
    // 0x80800D54: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800D58: jal         0x80088660
    // 0x80800D5C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800D5C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_10:
    // 0x80800D60: b           L_80800D80
    // 0x80800D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D80;
    // 0x80800D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D68:
    // 0x80800D68: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800D6C: addiu       $a2, $a2, -0x7358
    ctx->r6 = ADD32(ctx->r6, -0X7358);
    // 0x80800D70: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800D74: jal         0x80088668
    // 0x80800D78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800D78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_11:
    // 0x80800D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D80:
    // 0x80800D80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800D88: jr          $ra
    // 0x80800D8C: nop

    return;
    // 0x80800D8C: nop

;}
