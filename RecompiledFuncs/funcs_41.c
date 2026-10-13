#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808003A8_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003BC: jal         0x8009EF10
    // 0x808003C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x808003C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x808003C4: blez        $v0, L_808003D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808003C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D0;
    }
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: addiu       $s1, $zero, 0x1C
    ctx->r17 = ADD32(0, 0X1C);
L_808003D0:
    // 0x808003D0: jal         0x80091A30
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_1;
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808003D8: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808003DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E4;
    }
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: addiu       $s1, $zero, 0x1E
    ctx->r17 = ADD32(0, 0X1E);
L_808003E4:
    // 0x808003E4: jal         0x80091A58
    // 0x808003E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x808003E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x808003EC: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003F0: nop
    
            goto L_80800408;
    }
    // 0x808003F0: nop

    // 0x808003F4: jal         0x8008E078
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003FC: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x80800400: nop
    
            goto L_80800408;
    }
    // 0x80800400: nop

    // 0x80800404: addiu       $s1, $zero, 0x1D
    ctx->r17 = ADD32(0, 0X1D);
L_80800408:
    // 0x80800408: jal         0x8008E35C
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_4;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800410: beq         $v0, $zero, L_8080041C
    if (ctx->r2 == 0) {
        // 0x80800414: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_8080041C;
    }
    // 0x80800414: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_8080041C:
    // 0x8080041C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800420: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800424: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: jr          $ra
    // 0x8080042C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080042C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808000B0_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000B4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808000B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808000C0: beq         $a1, $at, L_808000F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000C4: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808000F8;
    }
    // 0x808000C4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808000C8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x808000CC: beq         $a1, $at, L_808001F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000D0: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_808001F8;
    }
    // 0x808000D0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x808000D4: beq         $a1, $at, L_808001E8
    if (ctx->r5 == ctx->r1) {
        // 0x808000D8: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_808001E8;
    }
    // 0x808000D8: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808000DC: beq         $a1, $at, L_80800274
    if (ctx->r5 == ctx->r1) {
        // 0x808000E0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800274;
    }
    // 0x808000E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000E4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000E8: beq         $a1, $at, L_80800240
    if (ctx->r5 == ctx->r1) {
        // 0x808000EC: nop
    
            goto L_80800240;
    }
    // 0x808000EC: nop

    // 0x808000F0: b           L_80800304
    // 0x808000F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800304;
    // 0x808000F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000F8:
    // 0x808000F8: lh          $v1, 0x40($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X40);
    // 0x808000FC: addiu       $at, $zero, 0x1505
    ctx->r1 = ADD32(0, 0X1505);
    // 0x80800100: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800104: beq         $v1, $at, L_80800124
    if (ctx->r3 == ctx->r1) {
        // 0x80800108: addiu       $at, $zero, 0x1506
        ctx->r1 = ADD32(0, 0X1506);
            goto L_80800124;
    }
    // 0x80800108: addiu       $at, $zero, 0x1506
    ctx->r1 = ADD32(0, 0X1506);
    // 0x8080010C: beq         $v1, $at, L_80800124
    if (ctx->r3 == ctx->r1) {
        // 0x80800110: addiu       $at, $zero, 0x1507
        ctx->r1 = ADD32(0, 0X1507);
            goto L_80800124;
    }
    // 0x80800110: addiu       $at, $zero, 0x1507
    ctx->r1 = ADD32(0, 0X1507);
    // 0x80800114: beq         $v1, $at, L_80800188
    if (ctx->r3 == ctx->r1) {
        // 0x80800118: nop
    
            goto L_80800188;
    }
    // 0x80800118: nop

    // 0x8080011C: b           L_808001BC
    // 0x80800120: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
        goto L_808001BC;
    // 0x80800120: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_80800124:
    // 0x80800124: jal         0x8008A720
    // 0x80800128: nop

    _sujiggy_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80800128: nop

    after_0:
    // 0x8080012C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800130: beq         $v0, $at, L_80800150
    if (ctx->r2 == ctx->r1) {
        // 0x80800134: addiu       $t6, $zero, 0x1509
        ctx->r14 = ADD32(0, 0X1509);
            goto L_80800150;
    }
    // 0x80800134: addiu       $t6, $zero, 0x1509
    ctx->r14 = ADD32(0, 0X1509);
    // 0x80800138: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x8080013C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800158;
    }
    // 0x8080013C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800140: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x80800144: addiu       $t9, $zero, 0x1507
        ctx->r25 = ADD32(0, 0X1507);
            goto L_80800180;
    }
    // 0x80800144: addiu       $t9, $zero, 0x1507
    ctx->r25 = ADD32(0, 0X1507);
    // 0x80800148: b           L_808001BC
    // 0x8080014C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
        goto L_808001BC;
    // 0x8080014C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_80800150:
    // 0x80800150: b           L_808001B8
    // 0x80800154: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
        goto L_808001B8;
    // 0x80800154: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80800158:
    // 0x80800158: jal         0x8008A718
    // 0x8080015C: nop

    _sujiggy_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080015C: nop

    after_1:
    // 0x80800160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800164: bne         $v0, $at, L_80800178
    if (ctx->r2 != ctx->r1) {
        // 0x80800168: addiu       $t8, $zero, 0x1508
        ctx->r24 = ADD32(0, 0X1508);
            goto L_80800178;
    }
    // 0x80800168: addiu       $t8, $zero, 0x1508
    ctx->r24 = ADD32(0, 0X1508);
    // 0x8080016C: addiu       $t7, $zero, 0x154A
    ctx->r15 = ADD32(0, 0X154A);
    // 0x80800170: b           L_808001B8
    // 0x80800174: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_808001B8;
    // 0x80800174: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800178:
    // 0x80800178: b           L_808001B8
    // 0x8080017C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_808001B8;
    // 0x8080017C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800180:
    // 0x80800180: b           L_808001B8
    // 0x80800184: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_808001B8;
    // 0x80800184: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800188:
    // 0x80800188: jal         0x800DA298
    // 0x8080018C: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080018C: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    after_2:
    // 0x80800190: bne         $v0, $zero, L_808001B0
    if (ctx->r2 != 0) {
        // 0x80800194: addiu       $a0, $zero, 0x6B
        ctx->r4 = ADD32(0, 0X6B);
            goto L_808001B0;
    }
    // 0x80800194: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80800198: jal         0x800DA544
    // 0x8080019C: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080019C: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    after_3:
    // 0x808001A0: jal         0x80085710
    // 0x808001A4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x808001A4: nop

    after_4:
    // 0x808001A8: b           L_808001BC
    // 0x808001AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
        goto L_808001BC;
    // 0x808001AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_808001B0:
    // 0x808001B0: jal         0x800C01A8
    // 0x808001B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_5;
    // 0x808001B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_808001B8:
    // 0x808001B8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_808001BC:
    // 0x808001BC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x808001C0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808001C4: beq         $t0, $zero, L_80800300
    if (ctx->r8 == 0) {
        // 0x808001C8: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_80800300;
    }
    // 0x808001C8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x808001CC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808001D0: addiu       $t2, $zero, 0x98
    ctx->r10 = ADD32(0, 0X98);
    // 0x808001D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808001D8: jal         0x8008A208
    // 0x808001DC: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808001DC: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    after_6:
    // 0x808001E0: b           L_80800304
    // 0x808001E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x808001E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001E8:
    // 0x808001E8: jal         0x8008A718
    // 0x808001EC: nop

    _sujiggy_entrypoint_16(rdram, ctx);
        goto after_7;
    // 0x808001EC: nop

    after_7:
    // 0x808001F0: b           L_80800308
    // 0x808001F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x808001F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F8:
    // 0x808001F8: jal         0x800DA298
    // 0x808001FC: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808001FC: addiu       $a0, $zero, 0x532
    ctx->r4 = ADD32(0, 0X532);
    after_8:
    // 0x80800200: bne         $v0, $zero, L_80800300
    if (ctx->r2 != 0) {
        // 0x80800204: addiu       $a0, $zero, 0x1E7
        ctx->r4 = ADD32(0, 0X1E7);
            goto L_80800300;
    }
    // 0x80800204: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    // 0x80800208: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080020C: jal         0x80101180
    // 0x80800210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80800210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800214: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80800218: jal         0x800C01A8
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_10;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800220: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800228: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080022C: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    // 0x80800230: jal         0x80085708
    // 0x80800234: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800234: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_11:
    // 0x80800238: b           L_80800304
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x8080023C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800240:
    // 0x80800240: jal         0x8008A720
    // 0x80800244: nop

    _sujiggy_entrypoint_17(rdram, ctx);
        goto after_12;
    // 0x80800244: nop

    after_12:
    // 0x80800248: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x8080024C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800264;
    }
    // 0x8080024C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800250: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800254: jal         0x80102424
    // 0x80800258: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800258: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x8080025C: b           L_80800304
    // 0x80800260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x80800260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800264:
    // 0x80800264: jal         0x80102424
    // 0x80800268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080026C: b           L_80800304
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x80800270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800274:
    // 0x80800274: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080027C: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800280: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800288: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080028C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800290: jal         0x80103EAC
    // 0x80800294: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_80103EAC(rdram, ctx);
        goto after_15;
    // 0x80800294: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x80800298: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8080029C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808002A0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x808002A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002A8: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808002AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808002B4: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    // 0x808002B8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x808002BC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808002C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002C4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x808002C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x808002CC: lwc1        $f10, 0x38($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X38);
    // 0x808002D0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002D4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808002D8: jal         0x80088098
    // 0x808002DC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x808002DC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x808002E0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808002E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808002E8: jal         0x80088090
    // 0x808002EC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x808002EC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_17:
    // 0x808002F0: b           L_80800304
    // 0x808002F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x808002F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002F8: b           L_80800304
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800304;
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800300:
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800304:
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800308:
    // 0x80800308: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void func_80800128_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080012C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800138: jal         0x8009E77C
    // 0x8080013C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x8080013C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800140: bne         $v0, $zero, L_80800174
    if (ctx->r2 != 0) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80085160
    // 0x8080014C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    _bastatemem_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080014C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x80800150: jal         0x80084BF0
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800158: jal         0x808000AC
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_bsbfly(rdram, ctx);
        goto after_3;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800160: jal         0x800845A0
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x800845A8
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baboost_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80800174:
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080081C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800820: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800824: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800828: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3354, 0X8F3) << 16);
    // 0x8080082C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800830: jr          $ra
    // 0x80800834: lbu         $v0, 0x8F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F3));
    return;
    // 0x80800834: lbu         $v0, 0x8F3($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8F3));
;}
RECOMP_FUNC void func_80800438_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080043C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800444: jal         0x80100094
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080044C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800450: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800454: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80800458: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8080045C: bltz        $t9, L_8080046C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800460: nop
    
            goto L_8080046C;
    }
    // 0x80800460: nop

    // 0x80800464: b           L_80800494
    // 0x80800468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800494;
    // 0x80800468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080046C:
    // 0x8080046C: jal         0x800F5EF8
    // 0x80800470: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x80800470: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    after_1:
    // 0x80800474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800478: jal         0x80089548
    // 0x8080047C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x8080047C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800480: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800488: lbu         $t0, 0x74($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X74);
    // 0x8080048C: andi        $t1, $t0, 0xFFDF
    ctx->r9 = ctx->r8 & 0XFFDF;
    // 0x80800490: sb          $t1, 0x74($v1)
    MEM_B(0X74, ctx->r3) = ctx->r9;
L_80800494:
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void func_808045E4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808045E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808045E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808045EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808045F0: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x808045F4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x808045F8: bnel        $at, $zero, L_80804614
    if (ctx->r1 != 0) {
        // 0x808045FC: lbu         $t7, 0x65($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X65);
            goto L_80804614;
    }
    goto skip_0;
    // 0x808045FC: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    skip_0:
    // 0x80804600: jal         0x80800478
    // 0x80804604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804608: b           L_80804620
    // 0x8080460C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804620;
    // 0x8080460C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804610: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
L_80804614:
    // 0x80804614: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80804618: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x8080461C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804620:
    // 0x80804620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804624: jr          $ra
    // 0x80804628: nop

    return;
    // 0x80804628: nop

;}
RECOMP_FUNC void func_80803C18_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803C18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803C1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803C20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803C24: jal         0x80100094
    // 0x80803C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803C2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803C30: jal         0x8008A040
    // 0x80803C34: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80803C34: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    after_1:
    // 0x80803C38: jal         0x800D8FF8
    // 0x80803C3C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80803C3C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80803C40: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80803C44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803C48: lwc1        $f4, 0x80($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80803C4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80803C50: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803C54: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80803C58: beq         $a0, $zero, L_80803CDC
    if (ctx->r4 == 0) {
        // 0x80803C5C: swc1        $f10, 0x80($s0)
        MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
            goto L_80803CDC;
    }
    // 0x80803C5C: swc1        $f10, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f10.u32l;
    // 0x80803C60: jal         0x80100094
    // 0x80803C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80803C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80803C68: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80803C6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803C70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80803C74: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80803C78: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80803C7C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803C80: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80803C84: bne         $t8, $at, L_80803C94
    if (ctx->r24 != ctx->r1) {
        // 0x80803C88: lui         $a3, 0x4080
        ctx->r7 = S32(0X4080 << 16);
            goto L_80803C94;
    }
    // 0x80803C88: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80803C8C: b           L_80803CDC
    // 0x80803C90: sw          $t9, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r25;
        goto L_80803CDC;
    // 0x80803C90: sw          $t9, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r25;
L_80803C94:
    // 0x80803C94: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803C98: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80803C9C: jal         0x800F10B4
    // 0x80803CA0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80803CA0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80803CA4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80803CA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80803CAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803CB0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80803CB4: nop

    // 0x80803CB8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80803CBC: jal         0x800F13C4
    // 0x80803CC0: lwc1        $f12, 0x80($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X80);
    func_800F13C4(rdram, ctx);
        goto after_5;
    // 0x80803CC0: lwc1        $f12, 0x80($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X80);
    after_5:
    // 0x80803CC4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80803CC8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80803CCC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80803CD0: nop

    // 0x80803CD4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80803CD8: sw          $t5, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r13;
L_80803CDC:
    // 0x80803CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803CE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803CE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803CE8: jr          $ra
    // 0x80803CEC: nop

    return;
    // 0x80803CEC: nop

;}
RECOMP_FUNC void bastatemem_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8001ACCC
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800014: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: sw          $v0, 0x188($t6)
    MEM_W(0X188, ctx->r14) = ctx->r2;
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void chgate1doors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1916, 0X500) << 16);
    // 0x8080045C: jr          $ra
    // 0x80800460: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1916, 0X500));
    return;
    // 0x80800460: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1916, 0X500));
    // 0x80800464: nop

    // 0x80800468: nop

    // 0x8080046C: nop

;}
RECOMP_FUNC void func_800D2A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2A44: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D2A48: addiu       $a2, $a2, -0x4CE0
    ctx->r6 = ADD32(ctx->r6, -0X4CE0);
    // 0x800D2A4C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800D2A50: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D2A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2A58: beq         $t6, $zero, L_800D2C44
    if (ctx->r14 == 0) {
        // 0x800D2A5C: sw          $a0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r4;
            goto L_800D2C44;
    }
    // 0x800D2A5C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D2A60: jal         0x800A89F8
    // 0x800D2A64: nop

    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800D2A64: nop

    after_0:
    // 0x800D2A68: jal         0x800A9478
    // 0x800D2A6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x800D2A6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D2A70: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800D2A74: jal         0x800F6BE4
    // 0x800D2A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_2;
    // 0x800D2A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800D2A7C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D2A80: beq         $v0, $zero, L_800D2AA8
    if (ctx->r2 == 0) {
        // 0x800D2A84: addiu       $a2, $a2, -0x4CE0
        ctx->r6 = ADD32(ctx->r6, -0X4CE0);
            goto L_800D2AA8;
    }
    // 0x800D2A84: addiu       $a2, $a2, -0x4CE0
    ctx->r6 = ADD32(ctx->r6, -0X4CE0);
    // 0x800D2A88: jal         0x800A93E4
    // 0x800D2A8C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800A93E4(rdram, ctx);
        goto after_3;
    // 0x800D2A8C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800D2A90: jal         0x8010FFD8
    // 0x800D2A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFD8(rdram, ctx);
        goto after_4;
    // 0x800D2A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800D2A98: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D2A9C: addiu       $a2, $a2, -0x4CE0
    ctx->r6 = ADD32(ctx->r6, -0X4CE0);
    // 0x800D2AA0: b           L_800D2AAC
    // 0x800D2AA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D2AAC;
    // 0x800D2AA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D2AA8:
    // 0x800D2AA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D2AAC:
    // 0x800D2AAC: lbu         $t7, 0x18($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X18);
    // 0x800D2AB0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800D2AB4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800D2AB8: beql        $t7, $zero, L_800D2AD4
    if (ctx->r15 == 0) {
        // 0x800D2ABC: lbu         $t8, 0x4($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0X4);
            goto L_800D2AD4;
    }
    goto skip_0;
    // 0x800D2ABC: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    skip_0:
    // 0x800D2AC0: beql        $v1, $zero, L_800D2AD4
    if (ctx->r3 == 0) {
        // 0x800D2AC4: lbu         $t8, 0x4($a2)
        ctx->r24 = MEM_BU(ctx->r6, 0X4);
            goto L_800D2AD4;
    }
    goto skip_1;
    // 0x800D2AC4: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    skip_1:
    // 0x800D2AC8: b           L_800D2AE4
    // 0x800D2ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D2AE4;
    // 0x800D2ACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D2AD0: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
L_800D2AD4:
    // 0x800D2AD4: beql        $t8, $zero, L_800D2C48
    if (ctx->r24 == 0) {
        // 0x800D2AD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D2C48;
    }
    goto skip_2;
    // 0x800D2AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D2ADC: bne         $v1, $zero, L_800D2C44
    if (ctx->r3 != 0) {
        // 0x800D2AE0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D2C44;
    }
    // 0x800D2AE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D2AE4:
    // 0x800D2AE4: jal         0x800E3CB8
    // 0x800D2AE8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_800E3CB8(rdram, ctx);
        goto after_5;
    // 0x800D2AE8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_5:
    // 0x800D2AEC: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D2AF0: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D2AF4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800D2AF8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800D2AFC: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x800D2B00: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800D2B04: sub.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800D2B08: addiu       $a2, $a2, -0x4CE0
    ctx->r6 = ADD32(ctx->r6, -0X4CE0);
    // 0x800D2B0C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800D2B10: bc1t        L_800D2C44
    if (c1cs) {
        // 0x800D2B14: swc1        $f4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
            goto L_800D2C44;
    }
    // 0x800D2B14: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800D2B18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D2B1C: addu        $v0, $a2, $t9
    ctx->r2 = ADD32(ctx->r6, ctx->r25);
    // 0x800D2B20: lh          $t1, 0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X6);
    // 0x800D2B24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D2B28: lui         $t8, 0xDB08
    ctx->r24 = S32(0XDB08 << 16);
    // 0x800D2B2C: sh          $t1, 0x2C($a2)
    MEM_H(0X2C, ctx->r6) = ctx->r9;
    // 0x800D2B30: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x800D2B34: sh          $t2, 0x2E($a2)
    MEM_H(0X2E, ctx->r6) = ctx->r10;
    // 0x800D2B38: lh          $t3, 0xA($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XA);
    // 0x800D2B3C: sh          $t3, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r11;
    // 0x800D2B40: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x800D2B44: sh          $t4, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r12;
    // 0x800D2B48: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800D2B4C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800D2B50: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D2B54: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800D2B58: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D2B5C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800D2B60: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D2B64: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x800D2B68: nop

    // 0x800D2B6C: bc1fl       L_800D2B80
    if (!c1cs) {
        // 0x800D2B70: div.s       $f10, $f18, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
            goto L_800D2B80;
    }
    goto skip_3;
    // 0x800D2B70: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    skip_3:
    // 0x800D2B74: b           L_800D2BF0
    // 0x800D2B78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800D2BF0;
    // 0x800D2B78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D2B7C: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
L_800D2B80:
    // 0x800D2B80: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D2B84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D2B88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D2B8C: add.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x800D2B90: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D2B94: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800D2B98: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D2B9C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800D2BA0: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800D2BA4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D2BA8: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800D2BAC: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800D2BB0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D2BB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D2BB8: lui         $at, 0xC380
    ctx->r1 = S32(0XC380 << 16);
    // 0x800D2BBC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800D2BC0: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800D2BC4: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800D2BC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D2BCC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D2BD0: nop

    // 0x800D2BD4: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800D2BD8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D2BDC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D2BE0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800D2BE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D2BE8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800D2BEC: nop

L_800D2BF0:
    // 0x800D2BF0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800D2BF4: addiu       $a1, $zero, -0x7FFF
    ctx->r5 = ADD32(0, -0X7FFF);
    // 0x800D2BF8: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x800D2BFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D2C00: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800D2C04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D2C08: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800D2C0C: jal         0x800F0D90
    // 0x800D2C10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F0D90(rdram, ctx);
        goto after_6;
    // 0x800D2C10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_6:
    // 0x800D2C14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D2C18: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D2C1C: addiu       $a1, $zero, -0x7FFF
    ctx->r5 = ADD32(0, -0X7FFF);
    // 0x800D2C20: jal         0x800F0D90
    // 0x800D2C24: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_800F0D90(rdram, ctx);
        goto after_7;
    // 0x800D2C24: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_7:
    // 0x800D2C28: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D2C2C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D2C30: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800D2C34: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800D2C38: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800D2C3C: jal         0x800D2CC4
    // 0x800D2C40: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    func_800D2CC4(rdram, ctx);
        goto after_8;
    // 0x800D2C40: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    after_8:
L_800D2C44:
    // 0x800D2C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D2C48:
    // 0x800D2C48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D2C4C: jr          $ra
    // 0x800D2C50: nop

    return;
    // 0x800D2C50: nop

;}
RECOMP_FUNC void chelectricfence_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1180, 0X4C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1180, 0X4C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1180, 0X4C0));
;}
RECOMP_FUNC void gcmapsects_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080089C: jal         0x800BF704
    // 0x808008A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x808008A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808008A4: lh          $t7, 0x1A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1A);
    // 0x808008A8: lw          $t6, 0x68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X68);
    // 0x808008AC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808008B4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808008B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808008BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808008C0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x808008C4: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x808008C8: lbu         $t3, 0x4C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4C);
    // 0x808008CC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x808008D0: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x808008D4: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x808008D8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808008DC: sb          $t5, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r13;
    // 0x808008E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void _dbmorph_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087978: syscall     643
    recomp_syscall_handler(rdram, ctx, 0x80087978);
    return;
    // 0x8008797C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chlavaentrancebridgeswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: bne         $a1, $at, L_80800044
    if (ctx->r5 != ctx->r1) {
        // 0x80800010: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800044;
    }
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: addiu       $a0, $zero, 0x38E
    ctx->r4 = ADD32(0, 0X38E);
    // 0x80800018: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x8080001C: jal         0x80101180
    // 0x80800020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800024: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080002C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800030: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800034: jal         0x80085708
    // 0x80800038: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800038: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x8080003C: b           L_8080004C
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080004C;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: jal         0x80085820
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8080004C:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085678: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085678);
    return;
    // 0x8008567C: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void func_80115858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115858: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8011585C: jr          $ra
    // 0x80115860: sw          $a1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r5;
    return;
    // 0x80115860: sw          $a1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _chlagoonufoext_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A30: syscall     189
    recomp_syscall_handler(rdram, ctx, 0x80085A30);
    return;
    // 0x80085A34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800120_bsbflap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: jal         0x8008CABC
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800130: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800134: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800138: jal         0x8008B348
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800140: beql        $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x80800144: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080015C;
    }
    goto skip_0;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800148: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080014C: lw          $t6, 0x160($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X160);
    // 0x80800150: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800154: sw          $t7, 0x160($v0)
    MEM_W(0X160, ctx->r2) = ctx->r15;
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080015C:
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088178: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088178);
    return;
    // 0x8008817C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80805BFC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805BFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80805C00: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80805C04: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80805C08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80805C0C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80805C10: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80805C14: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80805C18: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80805C1C: jal         0x80088150
    // 0x80805C20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80805C20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80805C24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80805C28: jal         0x80088158
    // 0x80805C2C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80805C2C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80805C30: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80805C34: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80805C38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80805C3C: jal         0x80802D40
    // 0x80805C40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802D40_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80805C40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80805C44: blez        $s2, L_80805C94
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80805C48: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80805C94;
    }
    // 0x80805C48: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80805C4C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
L_80805C50:
    // 0x80805C50: jal         0x80088148
    // 0x80805C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80805C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80805C58: beql        $v0, $zero, L_80805C8C
    if (ctx->r2 == 0) {
        // 0x80805C5C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80805C8C;
    }
    goto skip_0;
    // 0x80805C5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80805C60: jal         0x800881A0
    // 0x80805C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80805C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80805C68: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80805C6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80805C70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80805C74: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80805C78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805C7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80805C80: jal         0x80802DB4
    // 0x80805C84: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80805C84: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_5:
    // 0x80805C88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80805C8C:
    // 0x80805C8C: bne         $s1, $s2, L_80805C50
    if (ctx->r17 != ctx->r18) {
        // 0x80805C90: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80805C50;
    }
    // 0x80805C90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80805C94:
    // 0x80805C94: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80805C98: addiu       $a1, $zero, 0x18E4
    ctx->r5 = ADD32(0, 0X18E4);
    // 0x80805C9C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80805CA0: jal         0x80802E38
    // 0x80805CA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80802E38_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80805CA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80805CA8: lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X2C);
    // 0x80805CAC: jal         0x808026C8
    // 0x80805CB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80805CB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80805CB4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80805CB8: sw          $t7, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r15;
    // 0x80805CBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80805CC0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80805CC4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80805CC8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80805CCC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80805CD0: jr          $ra
    // 0x80805CD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80805CD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void cadbfunc_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800584: jal         0x808004E0
    // 0x80800588: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_808004E0_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800588: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8080058C: bne         $v0, $zero, L_8080059C
    if (ctx->r2 != 0) {
        // 0x80800590: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080059C;
    }
    // 0x80800590: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800594: b           L_808005A8
    // 0x80800598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005A8;
    // 0x80800598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080059C:
    // 0x8080059C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808005A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005A4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_808005A8:
    // 0x808005A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void func_80801AC4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801ACC: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801AD4: jal         0x80801B64
    // 0x80801AD8: sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801AD8: sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    after_0:
    // 0x80801ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AE4: jr          $ra
    // 0x80801AE8: nop

    return;
    // 0x80801AE8: nop

;}
RECOMP_FUNC void chmumbopad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1720, 0X1086) << 16);
    // 0x80800008: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080000C: jr          $ra
    // 0x80800010: lh          $v0, 0x1086($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1720, 0X1086));
    return;
    // 0x80800010: lh          $v0, 0x1086($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1720, 0X1086));
;}
RECOMP_FUNC void func_800B53A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B53A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B53A8: addiu       $v1, $v1, 0x7F18
    ctx->r3 = ADD32(ctx->r3, 0X7F18);
    // 0x800B53AC: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800B53B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B53B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B53B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B53BC: lw          $a0, 0x7F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7F10);
    // 0x800B53C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B53C4: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800B53C8: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x800B53CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B53D0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800B53D4: jal         0x8001B208
    // 0x800B53D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x800B53D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_0:
    // 0x800B53DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B53E0: addiu       $a1, $a1, 0x7F10
    ctx->r5 = ADD32(ctx->r5, 0X7F10);
    // 0x800B53E4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800B53E8: jal         0x800BA2E8
    // 0x800B53EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800BA2E8(rdram, ctx);
        goto after_1;
    // 0x800B53EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800B53F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B53F4: addiu       $v1, $v1, 0x7F18
    ctx->r3 = ADD32(ctx->r3, 0X7F18);
    // 0x800B53F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B53FC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B5400: addiu       $a1, $a1, 0x7F10
    ctx->r5 = ADD32(ctx->r5, 0X7F10);
    // 0x800B5404: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B5408: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B540C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B5410: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800B5414: sw          $v0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r2;
    // 0x800B5418: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800B541C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800B5420: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B5424: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800B5428: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800B542C: sb          $t3, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r11;
    // 0x800B5430: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800B5434: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800B5438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B543C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800B5440: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B5444: lw          $v0, -0x4($t2)
    ctx->r2 = MEM_W(ctx->r10, -0X4);
    // 0x800B5448: jr          $ra
    // 0x800B544C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B544C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsbansnooze_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082758: syscall     9
    recomp_syscall_handler(rdram, ctx, 0x80082758);
    return;
    // 0x8008275C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void gldialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: jal         0x800D674C
    // 0x8080005C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x8080005C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800060: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800064: sw          $v0, 0x7600($at)
    MEM_W(0X7600, ctx->r1) = ctx->r2;
    // 0x80800068: jal         0x800D70D0
    // 0x8080006C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_1;
    // 0x8080006C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800070: jal         0x800D71F4
    // 0x80800074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_2;
    // 0x80800074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800078: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8080007C: lw          $v1, 0x7600($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7600);
    // 0x80800080: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800084: jal         0x80800000
    // 0x80800088: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gldialog_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800088: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x8080008C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8080009C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x808000A0: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x808000A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x808000A8: lw          $t9, 0x7600($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7600);
    // 0x808000AC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x808000B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808000B8: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x808000BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: addu        $v0, $t9, $a0
    ctx->r2 = ADD32(ctx->r25, ctx->r4);
    // 0x808000C8: jr          $ra
    // 0x808000CC: sw          $t0, 0x7604($at)
    MEM_W(0X7604, ctx->r1) = ctx->r8;
    return;
    // 0x808000CC: sw          $t0, 0x7604($at)
    MEM_W(0X7604, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void baflag_clearAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800956E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800956EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800956F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800956F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800956F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800956FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80095700: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80095704: addiu       $s2, $zero, 0x42
    ctx->r18 = ADD32(0, 0X42);
    // 0x80095708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009570C:
    // 0x8009570C: jal         0x80095774
    // 0x80095710: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x80095710: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80095714: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80095718: bnel        $s0, $s2, L_8009570C
    if (ctx->r16 != ctx->r18) {
        // 0x8009571C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009570C;
    }
    goto skip_0;
    // 0x8009571C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80095720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80095724: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80095728: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009572C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80095730: jr          $ra
    // 0x80095734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80095734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080018C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800194: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800198: jal         0x80800100
    // 0x8080019C: addiu       $a1, $a1, 0x2FF8
    ctx->r5 = ADD32(ctx->r5, 0X2FF8);
    func_80800100_bsbansack(rdram, ctx);
        goto after_0;
    // 0x8080019C: addiu       $a1, $a1, 0x2FF8
    ctx->r5 = ADD32(ctx->r5, 0X2FF8);
    after_0:
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_80801B30_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801B34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80801B3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801B40: jal         0x80100094
    // 0x80801B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B48: lbu         $t6, 0x558($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X558);
    // 0x80801B4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801B50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801B54: beql        $t6, $zero, L_80801C4C
    if (ctx->r14 == 0) {
        // 0x80801B58: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801C4C;
    }
    goto skip_0;
    // 0x80801B58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80801B5C: lwc1        $f4, 0x560($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X560);
    // 0x80801B60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801B64: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x80801B68: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    // 0x80801B6C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801B70: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801B74: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80801B78: nop

    // 0x80801B7C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80801B80: nop

    // 0x80801B84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801B88: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80801B8C: jal         0x80088B38
    // 0x80801B90: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    _fxdialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801B90: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80801B94: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801B98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801B9C: jal         0x80088B40
    // 0x80801BA0: nop

    _fxdialog_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801BA0: nop

    after_2:
    // 0x80801BA4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801BA8: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801BAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801BB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801BB4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801BB8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801BBC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80801BC0: lbu         $t0, 0x559($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X559);
    // 0x80801BC4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801BC8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80801BCC: addiu       $a1, $zero, 0xB4F
    ctx->r5 = ADD32(0, 0XB4F);
    // 0x80801BD0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801BD4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801BD8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801BDC: jal         0x80088B50
    // 0x80801BE0: nop

    _fxdialog_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80801BE0: nop

    after_3:
    // 0x80801BE4: jal         0x800B8C50
    // 0x80801BE8: nop

    func_800B8C50(rdram, ctx);
        goto after_4;
    // 0x80801BE8: nop

    after_4:
    // 0x80801BEC: jal         0x800B8C8C
    // 0x80801BF0: lbu         $a0, 0x559($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X559);
    func_800B8C8C(rdram, ctx);
        goto after_5;
    // 0x80801BF0: lbu         $a0, 0x559($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X559);
    after_5:
    // 0x80801BF4: jal         0x800B8C98
    // 0x80801BF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B8C98(rdram, ctx);
        goto after_6;
    // 0x80801BF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80801BFC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80801C00: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80801C04: jal         0x800B8CBC
    // 0x80801C08: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800B8CBC(rdram, ctx);
        goto after_7;
    // 0x80801C08: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x80801C0C: jal         0x800B7F14
    // 0x80801C10: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B7F14(rdram, ctx);
        goto after_8;
    // 0x80801C10: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_8:
    // 0x80801C14: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2216, 0X20E0) << 16);
    // 0x80801C18: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2216, 0X20E0));
    // 0x80801C1C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801C20: lbu         $a2, 0x55A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X55A);
    // 0x80801C24: jal         0x8002DC20
    // 0x80801C28: lbu         $a3, 0x55B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X55B);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80801C28: lbu         $a3, 0x55B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X55B);
    after_9:
    // 0x80801C2C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801C30: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    // 0x80801C34: addiu       $a2, $zero, 0x72
    ctx->r6 = ADD32(0, 0X72);
    // 0x80801C38: jal         0x800B8E28
    // 0x80801C3C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_800B8E28(rdram, ctx);
        goto after_10;
    // 0x80801C3C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_10:
    // 0x80801C40: jal         0x800B811C
    // 0x80801C44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B811C(rdram, ctx);
        goto after_11;
    // 0x80801C44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x80801C48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801C4C:
    // 0x80801C4C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801C50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801C54: jr          $ra
    // 0x80801C58: nop

    return;
    // 0x80801C58: nop

;}
RECOMP_FUNC void func_808001CC_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001D8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808001DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808001E8: beq         $t6, $at, L_80800204
    if (ctx->r14 == ctx->r1) {
        // 0x808001EC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800204;
    }
    // 0x808001EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001F4: beq         $t6, $at, L_80800240
    if (ctx->r14 == ctx->r1) {
        // 0x808001F8: nop
    
            goto L_80800240;
    }
    // 0x808001F8: nop

    // 0x808001FC: b           L_80800270
    // 0x80800200: nop

        goto L_80800270;
    // 0x80800200: nop

L_80800204:
    // 0x80800204: jal         0x800D90A4
    // 0x80800208: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800208: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x8080020C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800210: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800218: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080021C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800220: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80800224: jal         0x800F10B4
    // 0x80800228: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800228: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080022C: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800234: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800238: b           L_80800270
    // 0x8080023C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80800270;
    // 0x8080023C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80800240:
    // 0x80800240: jal         0x800D90A4
    // 0x80800244: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80800244: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800248: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080024C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800250: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80800254: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    // 0x80800258: jal         0x800F10B4
    // 0x8080025C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x8080025C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80800260: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800264: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800268: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080026C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80800270:
    // 0x80800270: bne         $a2, $zero, L_80800288
    if (ctx->r6 != 0) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: bnel        $a2, $zero, L_8080029C
    if (ctx->r6 != 0) {
        // 0x8080027C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080029C;
    }
    goto skip_0;
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800280: lbu         $t7, 0x5F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800284: beq         $t7, $zero, L_80800298
    if (ctx->r15 == 0) {
        // 0x80800288: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(944, 0X798) << 16);
            goto L_80800298;
    }
L_80800288:
    // 0x80800288: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(944, 0X798) << 16);
    // 0x8080028C: addiu       $a3, $a3, 0x798
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(944, 0X798));
    // 0x80800290: jal         0x80089D50
    // 0x80800294: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800294: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
L_80800298:
    // 0x80800298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080029C:
    // 0x8080029C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void _chbkcart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877B0: syscall     624
    recomp_syscall_handler(rdram, ctx, 0x800877B0);
    return;
    // 0x800877B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E28A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E28A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E28A8: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800E28AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E28B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E28B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E28B8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800E28BC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800E28C0: beq         $t6, $zero, L_800E28E4
    if (ctx->r14 == 0) {
        // 0x800E28C4: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_800E28E4;
    }
    // 0x800E28C4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800E28C8: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800E28CC: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800E28D0: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800E28D4: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800E28D8: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800E28DC: b           L_800E28FC
    // 0x800E28E0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_800E28FC;
    // 0x800E28E0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_800E28E4:
    // 0x800E28E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E28E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E28EC: nop

    // 0x800E28F0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800E28F4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800E28F8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_800E28FC:
    // 0x800E28FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E2900: addiu       $t7, $sp, 0x38
    ctx->r15 = ADD32(ctx->r29, 0X38);
    // 0x800E2904: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800E2908: lw          $a0, -0x2B10($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B10);
    // 0x800E290C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2910: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800E2914: jal         0x800E1C00
    // 0x800E2918: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800E1C00(rdram, ctx);
        goto after_0;
    // 0x800E2918: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800E291C: bne         $v0, $zero, L_800E292C
    if (ctx->r2 != 0) {
        // 0x800E2920: nop
    
            goto L_800E292C;
    }
    // 0x800E2920: nop

    // 0x800E2924: b           L_800E2A00
    // 0x800E2928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E2A00;
    // 0x800E2928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E292C:
    // 0x800E292C: jal         0x80019CD4
    // 0x800E2930: nop

    func_80019CD4(rdram, ctx);
        goto after_1;
    // 0x800E2930: nop

    after_1:
    // 0x800E2934: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800E2938: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800E293C: jal         0x800191F8
    // 0x800E2940: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800191F8(rdram, ctx);
        goto after_2;
    // 0x800E2940: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800E2944: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800E2948: beql        $v0, $zero, L_800E2964
    if (ctx->r2 == 0) {
        // 0x800E294C: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_800E2964;
    }
    goto skip_0;
    // 0x800E294C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x800E2950: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E2954: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800E2958: jal         0x80019110
    // 0x800E295C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    mlMtxRotatePYR(rdram, ctx);
        goto after_3;
    // 0x800E295C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x800E2960: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_800E2964:
    // 0x800E2964: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800E2968: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800E296C: bne         $t8, $zero, L_800E297C
    if (ctx->r24 != 0) {
        // 0x800E2970: lwc1        $f14, 0x48($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800E297C;
    }
    // 0x800E2970: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800E2974: beq         $t9, $zero, L_800E2998
    if (ctx->r25 == 0) {
        // 0x800E2978: nop
    
            goto L_800E2998;
    }
    // 0x800E2978: nop

L_800E297C:
    // 0x800E297C: beq         $t0, $zero, L_800E2990
    if (ctx->r8 == 0) {
        // 0x800E2980: lwc1        $f12, 0x4C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_800E2990;
    }
    // 0x800E2980: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800E2984: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800E2988: b           L_800E2990
    // 0x800E298C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800E2990;
    // 0x800E298C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800E2990:
    // 0x800E2990: jal         0x80019D30
    // 0x800E2994: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    mlMtxScale_xyz(rdram, ctx);
        goto after_4;
    // 0x800E2994: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_4:
L_800E2998:
    // 0x800E2998: jal         0x80018C28
    // 0x800E299C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_5;
    // 0x800E299C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_5:
    // 0x800E29A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E29A4: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x800E29A8: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800E29AC: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800E29B0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800E29B4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800E29B8: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800E29BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E29C0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E29C4: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x800E29C8: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x800E29CC: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800E29D0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800E29D4: jal         0x800E2630
    // 0x800E29D8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800E2630(rdram, ctx);
        goto after_6;
    // 0x800E29D8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_6:
    // 0x800E29DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E29E0: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800E29E4: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800E29E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E29EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E29F0: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800E29F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E29F8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E29FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800E2A00:
    // 0x800E2A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E2A04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E2A08: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800E2A0C: jr          $ra
    // 0x800E2A10: nop

    return;
    // 0x800E2A10: nop

;}
RECOMP_FUNC void func_80092DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092DC8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092DCC: jal         0x800921E0
    // 0x80092DD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092DD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80092DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092DDC: jr          $ra
    // 0x80092DE0: nop

    return;
    // 0x80092DE0: nop

;}
RECOMP_FUNC void ncbadive_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808044A4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808044A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808044A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808044AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808044B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808044B4: jal         0x80803D60
    // 0x808044B8: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    func_80803D60_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808044B8: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x808044BC: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x808044C0: jal         0x8080218C
    // 0x808044C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8080218C_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808044C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808044C8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808044CC: jal         0x80801658
    // 0x808044D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801658_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808044D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808044D4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808044D8: jal         0x808015DC
    // 0x808044DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808015DC_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808044DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808044E0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808044E4: jal         0x808016A0
    // 0x808044E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808016A0_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808044E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808044EC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808044F0: jal         0x808016E8
    // 0x808044F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808016E8_chgameselect(rdram, ctx);
        goto after_5;
    // 0x808044F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x808044F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808044FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804500: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804504: jr          $ra
    // 0x80804508: nop

    return;
    // 0x80804508: nop

;}
RECOMP_FUNC void func_80803910_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803918: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x8080391C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80803920: beq         $a1, $zero, L_80803938
    if (ctx->r5 == 0) {
        // 0x80803924: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80803938;
    }
    // 0x80803924: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80803928: jal         0x800C8B84
    // 0x8080392C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x8080392C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80803930: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80803934: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
L_80803938:
    // 0x80803938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080393C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803940: jr          $ra
    // 0x80803944: nop

    return;
    // 0x80803944: nop

;}
RECOMP_FUNC void func_80802AA8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802AB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802AB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802AB8: jal         0x800A3280
    // 0x80802ABC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802ABC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802AC0: lh          $v1, 0x1E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1E);
    // 0x80802AC4: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x80802AC8: lui         $t0, 0x8081
    ctx->r8 = S32(RELOC_HI16(439, 0XAE44) << 16);
    // 0x80802ACC: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80802AD0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80802AD4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80802AD8: addiu       $t0, $t0, -0x51BC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(439, 0XAE44));
    // 0x80802ADC: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80802AE0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802AE4: lw          $t1, -0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X20);
    // 0x80802AE8: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x80802AEC: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80802AF0: lui         $t5, 0x8081
    ctx->r13 = S32(RELOC_HI16(439, 0XADF4) << 16);
    // 0x80802AF4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80802AF8: addiu       $t5, $t5, -0x520C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(439, 0XADF4));
    // 0x80802AFC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80802B00: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80802B04: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x80802B08: lh          $t6, -0x10($a1)
    ctx->r14 = MEM_H(ctx->r5, -0X10);
    // 0x80802B0C: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x80802B10: lw          $t7, -0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X1C);
    // 0x80802B14: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x80802B18: lh          $t8, -0xE($a1)
    ctx->r24 = MEM_H(ctx->r5, -0XE);
    // 0x80802B1C: sh          $t8, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r24;
    // 0x80802B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802B28: jr          $ra
    // 0x80802B2C: nop

    return;
    // 0x80802B2C: nop

;}
RECOMP_FUNC void func_8080040C_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800418: jal         0x8009E710
    // 0x8080041C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x8080041C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800420: jal         0x80800390
    // 0x80800424: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800390_bsbanswim(rdram, ctx);
        goto after_1;
    // 0x80800424: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800428: bne         $v0, $zero, L_80800488
    if (ctx->r2 != 0) {
        // 0x8080042C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800488;
    }
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    // 0x80800434: jal         0x8008CB3C
    // 0x80800438: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800438: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_2:
    // 0x8080043C: jal         0x80800000
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbanswim(rdram, ctx);
        goto after_3;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800444: jal         0x80800030
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbanswim(rdram, ctx);
        goto after_4;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: jal         0x800852B8
    // 0x80800454: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800454: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x800852A8
    // 0x80800460: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800460: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_6:
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x8009BC5C
    // 0x8080046C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_7;
    // 0x8080046C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_7:
    // 0x80800470: jal         0x8008E0E8
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_8;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800478: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x8080047C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800488;
    }
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x80084788
    // 0x80800484: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800484: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
L_80800488:
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080048C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800494: jr          $ra
    // 0x80800498: nop

    return;
    // 0x80800498: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003F8: jal         0x800C2E04
    // 0x808003FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x808003FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800400: sb          $v0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r2;
    // 0x80800404: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800408: jal         0x800C301C
    // 0x8080040C: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    func_800C301C(rdram, ctx);
        goto after_1;
    // 0x8080040C: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    after_1:
    // 0x80800410: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    // 0x80800414: jal         0x800C330C
    // 0x80800418: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x80800418: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080041C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800420: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800424: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80800428: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080042C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800430: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800434: jal         0x800C3730
    // 0x80800438: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    func_800C3730(rdram, ctx);
        goto after_3;
    // 0x80800438: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    after_3:
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x80095774
    // 0x80800444: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    baflag_clear(rdram, ctx);
        goto after_4;
    // 0x80800444: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x80800448: jal         0x8009E710
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_5;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800458: jal         0x8009CA70
    // 0x8080045C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_6;
    // 0x8080045C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
    // 0x80800460: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x80800464: nop
    
            goto L_80800478;
    }
    // 0x80800464: nop

    // 0x80800468: jal         0x808002D8
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_bsblongleg(rdram, ctx);
        goto after_7;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800470: b           L_80800484
    // 0x80800474: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
        goto L_80800484;
    // 0x80800474: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80800478:
    // 0x80800478: jal         0x80800378
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800378_bsblongleg(rdram, ctx);
        goto after_8;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800480: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80800484:
    // 0x80800484: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800490: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800494: jal         0x8009FFD8
    // 0x80800498: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800498: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: jal         0x8009B9B0
    // 0x808004A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x808004A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x808004A8: jal         0x8080013C
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080013C_bsblongleg(rdram, ctx);
        goto after_11;
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004B0: jal         0x8009D874
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_12;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808004B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void bstalk_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080010C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(388, 0X170) << 16);
    // 0x80800110: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800114: jr          $ra
    // 0x80800118: lw          $v0, 0x170($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(388, 0X170));
    return;
    // 0x80800118: lw          $v0, 0x170($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(388, 0X170));
;}
RECOMP_FUNC void func_8080045C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800464: jal         0x808002D4
    // 0x80800468: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800468: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080046C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: addiu       $a1, $zero, 0x28B
    ctx->r5 = ADD32(0, 0X28B);
    // 0x80800474: jal         0x8008CB3C
    // 0x80800478: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800478: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_1:
    // 0x8080047C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800480: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800484: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080048C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800490: jal         0x8009FFD8
    // 0x80800494: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800494: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800498: jal         0x808003C0
    // 0x8080049C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808003C0_bsbansack(rdram, ctx);
        goto after_3;
    // 0x8080049C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004A8: jr          $ra
    // 0x808004AC: nop

    return;
    // 0x808004AC: nop

;}
RECOMP_FUNC void func_8009AD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD20: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AD24: jr          $ra
    // 0x8009AD28: sw          $a1, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r5;
    return;
    // 0x8009AD28: sw          $a1, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _bapackctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084780: syscall     119
    recomp_syscall_handler(rdram, ctx, 0x80084780);
    return;
    // 0x80084784: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800DCD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCD10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DCD14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DCD18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DCD1C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DCD20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DCD24: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCD28: addiu       $a0, $a0, -0x30C0
    ctx->r4 = ADD32(ctx->r4, -0X30C0);
    // 0x800DCD2C: jal         0x800DC5BC
    // 0x800DCD30: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800DC5BC(rdram, ctx);
        goto after_0;
    // 0x800DCD30: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x800DCD34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCD38: addiu       $a0, $a0, -0x30B0
    ctx->r4 = ADD32(ctx->r4, -0X30B0);
    // 0x800DCD3C: jal         0x800DC5BC
    // 0x800DCD40: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_800DC5BC(rdram, ctx);
        goto after_1;
    // 0x800DCD40: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_1:
    // 0x800DCD44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCD48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DCD4C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DCD50: addiu       $a2, $a2, -0x30C0
    ctx->r6 = ADD32(ctx->r6, -0X30C0);
    // 0x800DCD54: addiu       $a1, $a1, -0x30B0
    ctx->r5 = ADD32(ctx->r5, -0X30B0);
    // 0x800DCD58: jal         0x800EFB24
    // 0x800DCD5C: addiu       $a0, $a0, -0x30D0
    ctx->r4 = ADD32(ctx->r4, -0X30D0);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800DCD5C: addiu       $a0, $a0, -0x30D0
    ctx->r4 = ADD32(ctx->r4, -0X30D0);
    after_2:
    // 0x800DCD60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCD64: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DCD68: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DCD6C: jal         0x800EF3DC
    // 0x800DCD70: addiu       $a0, $a0, -0x30C0
    ctx->r4 = ADD32(ctx->r4, -0X30C0);
    func_800EF3DC(rdram, ctx);
        goto after_3;
    // 0x800DCD70: addiu       $a0, $a0, -0x30C0
    ctx->r4 = ADD32(ctx->r4, -0X30C0);
    after_3:
    // 0x800DCD74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DCD78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DCD7C: addiu       $v1, $v1, -0x30C0
    ctx->r3 = ADD32(ctx->r3, -0X30C0);
    // 0x800DCD80: addiu       $v0, $v0, -0x30D0
    ctx->r2 = ADD32(ctx->r2, -0X30D0);
    // 0x800DCD84: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DCD88: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DCD8C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DCD90: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DCD94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DCD98: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DCD9C: lbu         $t6, 0x21($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X21);
    // 0x800DCDA0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DCDA4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800DCDA8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800DCDAC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800DCDB0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800DCDB4: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800DCDB8: beq         $t7, $zero, L_800DCE30
    if (ctx->r15 == 0) {
        // 0x800DCDBC: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800DCE30;
    }
    // 0x800DCDBC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800DCDC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DCDC4: nop

    // 0x800DCDC8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800DCDCC: nop

    // 0x800DCDD0: bc1fl       L_800DCE00
    if (!c1cs) {
        // 0x800DCDD4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800DCE00;
    }
    goto skip_0;
    // 0x800DCDD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x800DCDD8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800DCDDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCDE0: beq         $v0, $zero, L_800DCDFC
    if (ctx->r2 == 0) {
        // 0x800DCDE4: addu        $a1, $s0, $v0
        ctx->r5 = ADD32(ctx->r16, ctx->r2);
            goto L_800DCDFC;
    }
    // 0x800DCDE4: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x800DCDE8: swc1        $f0, -0x30D4($at)
    MEM_W(-0X30D4, ctx->r1) = ctx->f0.u32l;
    // 0x800DCDEC: jal         0x800DE2A4
    // 0x800DCDF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800DE2A4(rdram, ctx);
        goto after_4;
    // 0x800DCDF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800DCDF4: b           L_800DCEB8
    // 0x800DCDF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCEB8;
    // 0x800DCDF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCDFC:
    // 0x800DCDFC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800DCE00:
    // 0x800DCE00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCE04: swc1        $f0, -0x30D4($at)
    MEM_W(-0X30D4, ctx->r1) = ctx->f0.u32l;
    // 0x800DCE08: bc1fl       L_800DCEB8
    if (!c1cs) {
        // 0x800DCE0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCEB8;
    }
    goto skip_1;
    // 0x800DCE0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DCE10: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    // 0x800DCE14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCE18: beql        $v0, $zero, L_800DCEB8
    if (ctx->r2 == 0) {
        // 0x800DCE1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCEB8;
    }
    goto skip_2;
    // 0x800DCE1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800DCE20: jal         0x800DE2A4
    // 0x800DCE24: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_5;
    // 0x800DCE24: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_5:
    // 0x800DCE28: b           L_800DCEB8
    // 0x800DCE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCEB8;
    // 0x800DCE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCE30:
    // 0x800DCE30: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DCE34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCE38: swc1        $f0, -0x30D4($at)
    MEM_W(-0X30D4, ctx->r1) = ctx->f0.u32l;
    // 0x800DCE3C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800DCE40: nop

    // 0x800DCE44: bc1fl       L_800DCE88
    if (!c1cs) {
        // 0x800DCE48: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DCE88;
    }
    goto skip_3;
    // 0x800DCE48: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x800DCE4C: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    // 0x800DCE50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCE54: beql        $v0, $zero, L_800DCE68
    if (ctx->r2 == 0) {
        // 0x800DCE58: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DCE68;
    }
    goto skip_4;
    // 0x800DCE58: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_4:
    // 0x800DCE5C: jal         0x800DE2A4
    // 0x800DCE60: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_6;
    // 0x800DCE60: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_6:
    // 0x800DCE64: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DCE68:
    // 0x800DCE68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCE6C: beql        $v0, $zero, L_800DCEB8
    if (ctx->r2 == 0) {
        // 0x800DCE70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCEB8;
    }
    goto skip_5;
    // 0x800DCE70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800DCE74: jal         0x800DE2A4
    // 0x800DCE78: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DCE78: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_7:
    // 0x800DCE7C: b           L_800DCEB8
    // 0x800DCE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCEB8;
    // 0x800DCE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DCE84: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DCE88:
    // 0x800DCE88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCE8C: beql        $v0, $zero, L_800DCEA0
    if (ctx->r2 == 0) {
        // 0x800DCE90: lh          $v0, 0x22($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X22);
            goto L_800DCEA0;
    }
    goto skip_6;
    // 0x800DCE90: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    skip_6:
    // 0x800DCE94: jal         0x800DE2A4
    // 0x800DCE98: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_8;
    // 0x800DCE98: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_8:
    // 0x800DCE9C: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
L_800DCEA0:
    // 0x800DCEA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCEA4: beql        $v0, $zero, L_800DCEB8
    if (ctx->r2 == 0) {
        // 0x800DCEA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCEB8;
    }
    goto skip_7;
    // 0x800DCEA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800DCEAC: jal         0x800DE2A4
    // 0x800DCEB0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_9;
    // 0x800DCEB0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_9:
    // 0x800DCEB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCEB8:
    // 0x800DCEB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DCEBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DCEC0: jr          $ra
    // 0x800DCEC4: nop

    return;
    // 0x800DCEC4: nop

;}
RECOMP_FUNC void _bamotor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085488: syscall     163
    recomp_syscall_handler(rdram, ctx, 0x80085488);
    return;
    // 0x8008548C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800768_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800768: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080076C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800770: jal         0x8008E35C
    // 0x80800774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x80800774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800778: beq         $v0, $zero, L_80800798
    if (ctx->r2 == 0) {
        // 0x8080077C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800798;
    }
    // 0x8080077C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800780: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16D4) << 16);
    // 0x80800784: lwc1        $f2, 0x16D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16D4));
    // 0x80800788: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8080078C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800790: b           L_808007B0
    // 0x80800794: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
        goto L_808007B0;
    // 0x80800794: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
L_80800798:
    // 0x80800798: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16D8) << 16);
    // 0x8080079C: lwc1        $f2, 0x16D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16D8));
    // 0x808007A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808007A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007A8: nop

    // 0x808007AC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
L_808007B0:
    // 0x808007B0: jal         0x8009EF34
    // 0x808007B4: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    bastick_getY(rdram, ctx);
        goto after_1;
    // 0x808007B4: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x808007B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808007BC: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808007C0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808007C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808007C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808007CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808007D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808007D4: bc1f        L_8080080C
    if (!c1cs) {
        // 0x808007D8: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_8080080C;
    }
    // 0x808007D8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808007DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808007E0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808007E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007E8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808007EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808007F0: jal         0x800F10B4
    // 0x808007F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808007F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x808007F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007FC: jal         0x8009BF5C
    // 0x80800800: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8009BF5C(rdram, ctx);
        goto after_3;
    // 0x80800800: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80800804: b           L_80800828
    // 0x80800808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800828;
    // 0x80800808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080080C:
    // 0x8080080C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800810: jal         0x800F10B4
    // 0x80800814: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800814: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80800818: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080081C: jal         0x8009BF5C
    // 0x80800820: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8009BF5C(rdram, ctx);
        goto after_5;
    // 0x80800820: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800828:
    // 0x80800828: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void func_800EDDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDDDC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EDDE0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EDDE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EDDE8: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x800EDDEC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EDDF0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800EDDF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EDDF8: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x800EDDFC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EDE00: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800EDE04: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x800EDE08: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800EDE0C: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    // 0x800EDE10: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EDE14: swc1        $f16, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f16.u32l;
    // 0x800EDE18: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EDE1C: swc1        $f18, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f18.u32l;
    // 0x800EDE20: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EDE24: swc1        $f4, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f4.u32l;
    // 0x800EDE28: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800EDE2C: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800EDE30: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x800EDE34: bc1f        L_800EDE44
    if (!c1cs) {
        // 0x800EDE38: swc1        $f6, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
            goto L_800EDE44;
    }
    // 0x800EDE38: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x800EDE3C: b           L_800EDE4C
    // 0x800EDE40: swc1        $f12, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f12.u32l;
        goto L_800EDE4C;
    // 0x800EDE40: swc1        $f12, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f12.u32l;
L_800EDE44:
    // 0x800EDE44: lwc1        $f8, 0x5E68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E68);
    // 0x800EDE48: swc1        $f8, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f8.u32l;
L_800EDE4C:
    // 0x800EDE4C: jr          $ra
    // 0x800EDE50: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    return;
    // 0x800EDE50: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800E1218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1218: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E121C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E1220: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800E1224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E1228: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E122C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x800E1230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E1234: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E1238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800E123C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800E1240: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E1244: jal         0x800EFA4C
    // 0x800E1248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800E1248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800E124C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800E1250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E1254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E1258: jal         0x800EF8BC
    // 0x800E125C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    func_800EF8BC(rdram, ctx);
        goto after_1;
    // 0x800E125C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x800E1260: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800E1264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E1268: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E126C: jal         0x800EF934
    // 0x800E1270: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x800E1270: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_2:
    // 0x800E1274: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E1278: jal         0x800EF04C
    // 0x800E127C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800E127C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800E1280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E1288: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E128C: jr          $ra
    // 0x800E1290: nop

    return;
    // 0x800E1290: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A48: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A48);
    return;
    // 0x80083A4C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800C75B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C75B8: jr          $ra
    // 0x800C75BC: lbu         $v0, 0x760C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X760C);
    return;
    // 0x800C75BC: lbu         $v0, 0x760C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X760C);
;}
