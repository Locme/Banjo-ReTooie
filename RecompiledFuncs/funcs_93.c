#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080011C_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: jal         0x800DA298
    // 0x80800128: addiu       $a0, $zero, 0x9C5
    ctx->r4 = ADD32(0, 0X9C5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800128: addiu       $a0, $zero, 0x9C5
    ctx->r4 = ADD32(0, 0X9C5);
    after_0:
    // 0x8080012C: bne         $v0, $zero, L_8080013C
    if (ctx->r2 != 0) {
        // 0x80800130: nop
    
            goto L_8080013C;
    }
    // 0x80800130: nop

    // 0x80800134: b           L_80800200
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080013C:
    // 0x8080013C: jal         0x800EA05C
    // 0x80800140: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800140: nop

    after_1:
    // 0x80800144: slti        $at, $v0, 0x13F
    ctx->r1 = SIGNED(ctx->r2) < 0X13F ? 1 : 0;
    // 0x80800148: bne         $at, $zero, L_80800180
    if (ctx->r1 != 0) {
        // 0x8080014C: addiu       $at, $zero, 0x13F
        ctx->r1 = ADD32(0, 0X13F);
            goto L_80800180;
    }
    // 0x8080014C: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x80800150: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x80800154: addiu       $at, $zero, 0x156
        ctx->r1 = ADD32(0, 0X156);
            goto L_808001EC;
    }
    // 0x80800154: addiu       $at, $zero, 0x156
    ctx->r1 = ADD32(0, 0X156);
    // 0x80800158: beq         $v0, $at, L_808001F4
    if (ctx->r2 == ctx->r1) {
        // 0x8080015C: addiu       $at, $zero, 0x171
        ctx->r1 = ADD32(0, 0X171);
            goto L_808001F4;
    }
    // 0x8080015C: addiu       $at, $zero, 0x171
    ctx->r1 = ADD32(0, 0X171);
    // 0x80800160: beq         $v0, $at, L_808001D4
    if (ctx->r2 == ctx->r1) {
        // 0x80800164: addiu       $at, $zero, 0x172
        ctx->r1 = ADD32(0, 0X172);
            goto L_808001D4;
    }
    // 0x80800164: addiu       $at, $zero, 0x172
    ctx->r1 = ADD32(0, 0X172);
    // 0x80800168: beq         $v0, $at, L_808001DC
    if (ctx->r2 == ctx->r1) {
        // 0x8080016C: addiu       $at, $zero, 0x176
        ctx->r1 = ADD32(0, 0X176);
            goto L_808001DC;
    }
    // 0x8080016C: addiu       $at, $zero, 0x176
    ctx->r1 = ADD32(0, 0X176);
    // 0x80800170: beq         $v0, $at, L_808001C4
    if (ctx->r2 == ctx->r1) {
        // 0x80800174: nop
    
            goto L_808001C4;
    }
    // 0x80800174: nop

    // 0x80800178: b           L_80800200
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: addiu       $at, $zero, 0xB7
    ctx->r1 = ADD32(0, 0XB7);
    // 0x80800184: beq         $v0, $at, L_808001B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800188: addiu       $at, $zero, 0xD9
        ctx->r1 = ADD32(0, 0XD9);
            goto L_808001B4;
    }
    // 0x80800188: addiu       $at, $zero, 0xD9
    ctx->r1 = ADD32(0, 0XD9);
    // 0x8080018C: beq         $v0, $at, L_808001BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800190: addiu       $at, $zero, 0xEF
        ctx->r1 = ADD32(0, 0XEF);
            goto L_808001BC;
    }
    // 0x80800190: addiu       $at, $zero, 0xEF
    ctx->r1 = ADD32(0, 0XEF);
    // 0x80800194: beq         $v0, $at, L_808001CC
    if (ctx->r2 == ctx->r1) {
        // 0x80800198: addiu       $at, $zero, 0x134
        ctx->r1 = ADD32(0, 0X134);
            goto L_808001CC;
    }
    // 0x80800198: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x8080019C: beq         $v0, $at, L_808001E4
    if (ctx->r2 == ctx->r1) {
        // 0x808001A0: addiu       $at, $zero, 0x13E
        ctx->r1 = ADD32(0, 0X13E);
            goto L_808001E4;
    }
    // 0x808001A0: addiu       $at, $zero, 0x13E
    ctx->r1 = ADD32(0, 0X13E);
    // 0x808001A4: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x808001A8: nop
    
            goto L_808001EC;
    }
    // 0x808001A8: nop

    // 0x808001AC: b           L_80800200
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800200;
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001B4:
    // 0x808001B4: b           L_80800200
    // 0x808001B8: addiu       $v0, $zero, 0x37F
    ctx->r2 = ADD32(0, 0X37F);
        goto L_80800200;
    // 0x808001B8: addiu       $v0, $zero, 0x37F
    ctx->r2 = ADD32(0, 0X37F);
L_808001BC:
    // 0x808001BC: b           L_80800200
    // 0x808001C0: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
        goto L_80800200;
    // 0x808001C0: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
L_808001C4:
    // 0x808001C4: b           L_80800200
    // 0x808001C8: addiu       $v0, $zero, 0x381
    ctx->r2 = ADD32(0, 0X381);
        goto L_80800200;
    // 0x808001C8: addiu       $v0, $zero, 0x381
    ctx->r2 = ADD32(0, 0X381);
L_808001CC:
    // 0x808001CC: b           L_80800200
    // 0x808001D0: addiu       $v0, $zero, 0x382
    ctx->r2 = ADD32(0, 0X382);
        goto L_80800200;
    // 0x808001D0: addiu       $v0, $zero, 0x382
    ctx->r2 = ADD32(0, 0X382);
L_808001D4:
    // 0x808001D4: b           L_80800200
    // 0x808001D8: addiu       $v0, $zero, 0x383
    ctx->r2 = ADD32(0, 0X383);
        goto L_80800200;
    // 0x808001D8: addiu       $v0, $zero, 0x383
    ctx->r2 = ADD32(0, 0X383);
L_808001DC:
    // 0x808001DC: b           L_80800200
    // 0x808001E0: addiu       $v0, $zero, 0x387
    ctx->r2 = ADD32(0, 0X387);
        goto L_80800200;
    // 0x808001E0: addiu       $v0, $zero, 0x387
    ctx->r2 = ADD32(0, 0X387);
L_808001E4:
    // 0x808001E4: b           L_80800200
    // 0x808001E8: addiu       $v0, $zero, 0x384
    ctx->r2 = ADD32(0, 0X384);
        goto L_80800200;
    // 0x808001E8: addiu       $v0, $zero, 0x384
    ctx->r2 = ADD32(0, 0X384);
L_808001EC:
    // 0x808001EC: b           L_80800200
    // 0x808001F0: addiu       $v0, $zero, 0x385
    ctx->r2 = ADD32(0, 0X385);
        goto L_80800200;
    // 0x808001F0: addiu       $v0, $zero, 0x385
    ctx->r2 = ADD32(0, 0X385);
L_808001F4:
    // 0x808001F4: b           L_80800200
    // 0x808001F8: addiu       $v0, $zero, 0x386
    ctx->r2 = ADD32(0, 0X386);
        goto L_80800200;
    // 0x808001F8: addiu       $v0, $zero, 0x386
    ctx->r2 = ADD32(0, 0X386);
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800200:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80800E3C_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E44: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800E48: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X1144) << 16);
    // 0x80800E4C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1012, 0X1154) << 16);
    // 0x80800E50: addiu       $a3, $a3, 0x1154
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1012, 0X1154));
    // 0x80800E54: addiu       $a2, $a2, 0x1144
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X1144));
    // 0x80800E58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800E5C: jal         0x80089D28
    // 0x80800E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E64: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X114C) << 16);
    // 0x80800E68: addiu       $a2, $a2, 0x114C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X114C));
    // 0x80800E6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E74: jal         0x80089D20
    // 0x80800E78: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800E78: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_1:
    // 0x80800E7C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X114C) << 16);
    // 0x80800E80: lui         $a3, 0x3F5E
    ctx->r7 = S32(0X3F5E << 16);
    // 0x80800E84: ori         $a3, $a3, 0xB852
    ctx->r7 = ctx->r7 | 0XB852;
    // 0x80800E88: addiu       $a2, $a2, 0x114C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X114C));
    // 0x80800E8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E90: jal         0x80089D20
    // 0x80800E94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800E94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EA0: jr          $ra
    // 0x80800EA4: nop

    return;
    // 0x80800EA4: nop

    // 0x80800EA8: nop

    // 0x80800EAC: nop

;}
RECOMP_FUNC void func_800BC474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC474: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BC478: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800BC47C: addiu       $t8, $t8, -0x58D0
    ctx->r24 = ADD32(ctx->r24, -0X58D0);
    // 0x800BC480: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BC484: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BC488: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800BC48C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BC490: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BC494: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BC498: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800BC49C: addu        $t3, $a1, $a3
    ctx->r11 = ADD32(ctx->r5, ctx->r7);
    // 0x800BC4A0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800BC4A4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BC4A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800BC4AC: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BC4B0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800BC4B4: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800BC4B8: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800BC4BC: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x800BC4C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC4C4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC4C8: andi        $t4, $t9, 0x7C0
    ctx->r12 = ctx->r25 & 0X7C0;
    // 0x800BC4CC: sra         $t8, $t6, 2
    ctx->r24 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800BC4D0: andi        $t9, $t8, 0x3E
    ctx->r25 = ctx->r24 & 0X3E;
    // 0x800BC4D4: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x800BC4D8: or          $t1, $t5, $t9
    ctx->r9 = ctx->r13 | ctx->r25;
    // 0x800BC4DC: ori         $t7, $t1, 0x1
    ctx->r15 = ctx->r9 | 0X1;
    // 0x800BC4E0: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800BC4E4: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800BC4E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800BC4EC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800BC4F0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800BC4F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC4F8: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800BC4FC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800BC500: blez        $t3, L_800BC510
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BC504: lw          $t5, 0x10($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X10);
            goto L_800BC510;
    }
    // 0x800BC504: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800BC508: b           L_800BC510
    // 0x800BC50C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800BC510;
    // 0x800BC50C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800BC510:
    // 0x800BC510: addu        $v1, $a2, $t5
    ctx->r3 = ADD32(ctx->r6, ctx->r13);
    // 0x800BC514: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800BC518: blez        $v1, L_800BC528
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BC51C: andi        $t6, $v0, 0x3FF
        ctx->r14 = ctx->r2 & 0X3FF;
            goto L_800BC528;
    }
    // 0x800BC51C: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x800BC520: b           L_800BC52C
    // 0x800BC524: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_800BC52C;
    // 0x800BC524: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800BC528:
    // 0x800BC528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC52C:
    // 0x800BC52C: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x800BC530: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800BC534: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x800BC538: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x800BC53C: or          $t5, $t4, $t8
    ctx->r13 = ctx->r12 | ctx->r24;
    // 0x800BC540: blez        $a1, L_800BC550
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800BC544: sw          $t5, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r13;
            goto L_800BC550;
    }
    // 0x800BC544: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x800BC548: b           L_800BC554
    // 0x800BC54C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800BC554;
    // 0x800BC54C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800BC550:
    // 0x800BC550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BC554:
    // 0x800BC554: blez        $a2, L_800BC564
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BC558: andi        $t6, $v0, 0x3FF
        ctx->r14 = ctx->r2 & 0X3FF;
            goto L_800BC564;
    }
    // 0x800BC558: andi        $t6, $v0, 0x3FF
    ctx->r14 = ctx->r2 & 0X3FF;
    // 0x800BC55C: b           L_800BC568
    // 0x800BC560: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_800BC568;
    // 0x800BC560: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800BC564:
    // 0x800BC564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC568:
    // 0x800BC568: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x800BC56C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800BC570: sll         $t4, $t6, 14
    ctx->r12 = S32(ctx->r14 << 14);
    // 0x800BC574: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800BC578: jr          $ra
    // 0x800BC57C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    return;
    // 0x800BC57C: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
;}
RECOMP_FUNC void func_80800DD8_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800DE8: jal         0x80088078
    // 0x80800DEC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800DEC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800DF0: beq         $v0, $zero, L_80800E1C
    if (ctx->r2 == 0) {
        // 0x80800DF4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800E1C;
    }
    // 0x80800DF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DF8: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800DFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800E04: beq         $t6, $at, L_80800E14
    if (ctx->r14 == ctx->r1) {
        // 0x80800E08: nop
    
            goto L_80800E14;
    }
    // 0x80800E08: nop

    // 0x80800E0C: jal         0x80800E6C
    // 0x80800E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800E6C_chjollyroger(rdram, ctx);
        goto after_1;
    // 0x80800E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800E14:
    // 0x80800E14: b           L_80800E20
    // 0x80800E18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800E20;
    // 0x80800E18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800E1C:
    // 0x80800E1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E20:
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E28: jr          $ra
    // 0x80800E2C: nop

    return;
    // 0x80800E2C: nop

;}
RECOMP_FUNC void func_800C68CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68CC: jr          $ra
    // 0x800C68D0: sw          $a1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r5;
    return;
    // 0x800C68D0: sw          $a1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80801808_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080180C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801810: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801814: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801818: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8080181C: jal         0x80100094
    // 0x80801820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801824: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80801828: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080182C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801830: addu        $t6, $v0, $a3
    ctx->r14 = ADD32(ctx->r2, ctx->r7);
    // 0x80801834: lbu         $v1, 0xA($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XA);
    // 0x80801838: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080183C: beql        $v1, $zero, L_80801878
    if (ctx->r3 == 0) {
        // 0x80801840: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801878;
    }
    goto skip_0;
    // 0x80801840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801844: beq         $v1, $at, L_80801868
    if (ctx->r3 == ctx->r1) {
        // 0x80801848: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_80801868;
    }
    // 0x80801848: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8080184C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801850: bnel        $v1, $at, L_80801878
    if (ctx->r3 != ctx->r1) {
        // 0x80801854: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801878;
    }
    goto skip_1;
    // 0x80801854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801858: jal         0x80800EBC
    // 0x8080185C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800EBC_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x8080185C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80801860: b           L_80801878
    // 0x80801864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801878;
    // 0x80801864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801868:
    // 0x80801868: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8080186C: jal         0x808017AC
    // 0x80801870: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    func_808017AC_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x80801870: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    after_2:
    // 0x80801874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801878:
    // 0x80801878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080187C: jr          $ra
    // 0x80801880: nop

    return;
    // 0x80801880: nop

;}
RECOMP_FUNC void func_80800278_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800278: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8080027C: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x80800280: addiu       $t7, $t6, -0xF
    ctx->r15 = ADD32(ctx->r14, -0XF);
    // 0x80800284: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x80800288: beq         $at, $zero, L_80800348
    if (ctx->r1 == 0) {
        // 0x8080028C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800348;
    }
    // 0x8080028C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800290: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X116C) << 16);
    // 0x80800294: addu        $at, $at, $t7
    gpr jr_addend_8080029C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800298: lw          $t7, 0x116C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1576, 0X116C));
    // 0x8080029C: jr          $t7
    // 0x808002A0: nop

    switch (jr_addend_8080029C >> 2) {
        case 0: goto L_808002C4; break;
        case 1: goto L_808002B4; break;
        case 2: goto L_80800348; break;
        case 3: goto L_808002D4; break;
        case 4: goto L_808002A4; break;
        case 5: goto L_808002E4; break;
        case 6: goto L_808002F4; break;
        case 7: goto L_80800300; break;
        case 8: goto L_80800310; break;
        case 9: goto L_8080031C; break;
        case 10: goto L_8080032C; break;
        case 11: goto L_80800338; break;
        default: switch_error(__func__, 0x8080029C, 0x8080116C);
    }
    // 0x808002A0: nop

L_808002A4:
    // 0x808002A4: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x808002A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

L_808002B4:
    // 0x808002B4: lui         $at, 0x43DC
    ctx->r1 = S32(0X43DC << 16);
    // 0x808002B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

L_808002C4:
    // 0x808002C4: lui         $at, 0x43E6
    ctx->r1 = S32(0X43E6 << 16);
    // 0x808002C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

L_808002D4:
    // 0x808002D4: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808002D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

L_808002E4:
    // 0x808002E4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808002E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

L_808002F4:
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X119C) << 16);
    // 0x808002F8: jr          $ra
    // 0x808002FC: lwc1        $f0, 0x119C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X119C));
    return;
    // 0x808002FC: lwc1        $f0, 0x119C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X119C));
L_80800300:
    // 0x80800300: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800304: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

L_80800310:
    // 0x80800310: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11A0) << 16);
    // 0x80800314: jr          $ra
    // 0x80800318: lwc1        $f0, 0x11A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11A0));
    return;
    // 0x80800318: lwc1        $f0, 0x11A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11A0));
L_8080031C:
    // 0x8080031C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80800320: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

L_8080032C:
    // 0x8080032C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X11A4) << 16);
    // 0x80800330: jr          $ra
    // 0x80800334: lwc1        $f0, 0x11A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11A4));
    return;
    // 0x80800334: lwc1        $f0, 0x11A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X11A4));
L_80800338:
    // 0x80800338: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080033C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

L_80800348:
    // 0x80800348: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080034C: nop

    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void func_80800370_chdiggerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800378: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080037C: jal         0x800BEA88
    // 0x80800380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80800380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800384: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800388: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808003A4;
    }
    // 0x80800388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080038C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800394: addiu       $a2, $a2, 0x67E8
    ctx->r6 = ADD32(ctx->r6, 0X67E8);
    // 0x80800398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080039C: jal         0x80088660
    // 0x808003A0: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808003A0: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_1:
L_808003A4:
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void badialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800010: lhu         $a0, 0x1A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1A);
    // 0x80800014: srl         $t6, $a0, 5
    ctx->r14 = S32(U32(ctx->r4) >> 5);
    // 0x80800018: jal         0x800F53D0
    // 0x8080001C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800020: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800028: jal         0x8009AD20
    // 0x8080002C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009AD20(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800030: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: jal         0x8009AD2C
    // 0x80800038: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD2C(rdram, ctx);
        goto after_2;
    // 0x80800038: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8080003C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: jal         0x8009E7C8
    // 0x80800044: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    func_8009E7C8(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    after_3:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_8080000C_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(784, 0X910) << 16);
    // 0x80800018: addiu       $a2, $a2, 0x910
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(784, 0X910));
    // 0x8080001C: jal         0x8008A1E8
    // 0x80800020: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void _gcdialogDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C90: syscall     656
    recomp_syscall_handler(rdram, ctx, 0x80087C90);
    return;
    // 0x80087C94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8001D340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D340: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001D344: lw          $t6, -0x2EA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2EA0);
    // 0x8001D348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D34C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001D350: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8001D354: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001D358: beq         $t7, $zero, L_8001D368
    if (ctx->r15 == 0) {
        // 0x8001D35C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001D368;
    }
    // 0x8001D35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D360: jal         0x8001DA00
    // 0x8001D364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8001DA00(rdram, ctx);
        goto after_0;
    // 0x8001D364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
L_8001D368:
    // 0x8001D368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D36C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D374: jr          $ra
    // 0x8001D378: nop

    return;
    // 0x8001D378: nop

;}
RECOMP_FUNC void func_800D284C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D284C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D2850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2854: jal         0x800D21D0
    // 0x800D2858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D2858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D285C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D2860: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800D2864: jal         0x800D21F0
    // 0x800D2868: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800D21F0(rdram, ctx);
        goto after_1;
    // 0x800D2868: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800D286C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2870: slti        $t6, $v0, 0x0
    ctx->r14 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800D2874: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
    // 0x800D2878: beq         $v0, $zero, L_800D2890
    if (ctx->r2 == 0) {
        // 0x800D287C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_800D2890;
    }
    // 0x800D287C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800D2880: jal         0x800FA818
    // 0x800D2884: lbu         $a1, 0x1($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X1);
    func_800FA818(rdram, ctx);
        goto after_2;
    // 0x800D2884: lbu         $a1, 0x1($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X1);
    after_2:
    // 0x800D2888: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800D288C: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
L_800D2890:
    // 0x800D2890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2894: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D2898: jr          $ra
    // 0x800D289C: nop

    return;
    // 0x800D289C: nop

;}
RECOMP_FUNC void _bapackctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084770: syscall     119
    recomp_syscall_handler(rdram, ctx, 0x80084770);
    return;
    // 0x80084774: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80020790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020790: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80020794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020798: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8002079C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800207A0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800207A4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800207A8: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800207AC: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x800207B0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800207B4: lh          $t6, 0x62($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X62);
    // 0x800207B8: beq         $t6, $zero, L_80020A28
    if (ctx->r14 == 0) {
        // 0x800207BC: nop
    
            goto L_80020A28;
    }
    // 0x800207BC: nop

L_800207C0:
    // 0x800207C0: lh          $a1, 0x62($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X62);
    // 0x800207C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800207C8: jal         0x800E9320
    // 0x800207CC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800E9320(rdram, ctx);
        goto after_0;
    // 0x800207CC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x800207D0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800207D4: jal         0x8002039C
    // 0x800207D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8002039C(rdram, ctx);
        goto after_1;
    // 0x800207D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x800207DC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800207E0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800207E4: beq         $t7, $zero, L_80020960
    if (ctx->r15 == 0) {
        // 0x800207E8: nop
    
            goto L_80020960;
    }
    // 0x800207E8: nop

    // 0x800207EC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800207F0: lw          $t9, 0x11DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11DC);
    // 0x800207F4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800207F8: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
    // 0x800207FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80020800: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x80020804: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80020808: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8002080C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80020810: lbu         $t2, 0x6B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6B);
    // 0x80020814: lbu         $t4, 0x41($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X41);
    // 0x80020818: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8002081C: addiu       $t6, $t5, -0x40
    ctx->r14 = ADD32(ctx->r13, -0X40);
    // 0x80020820: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80020824: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80020828: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x8002082C: bne         $at, $zero, L_80020840
    if (ctx->r1 != 0) {
        // 0x80020830: nop
    
            goto L_80020840;
    }
    // 0x80020830: nop

    // 0x80020834: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80020838: b           L_80020850
    // 0x8002083C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
        goto L_80020850;
    // 0x8002083C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_80020840:
    // 0x80020840: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80020844: bgez        $t9, L_80020850
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80020848: nop
    
            goto L_80020850;
    }
    // 0x80020848: nop

    // 0x8002084C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80020850:
    // 0x80020850: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80020854: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80020858: sb          $t0, 0x41($t1)
    MEM_B(0X41, ctx->r9) = ctx->r8;
    // 0x8002085C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80020860: lhu         $t3, 0x66($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X66);
    // 0x80020864: lh          $t4, 0x38($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X38);
    // 0x80020868: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002086C: mflo        $t5
    ctx->r13 = lo;
    // 0x80020870: srl         $t6, $t5, 15
    ctx->r14 = S32(U32(ctx->r13) >> 15);
    // 0x80020874: sh          $t6, 0x38($t2)
    MEM_H(0X38, ctx->r10) = ctx->r14;
    // 0x80020878: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8002087C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80020880: lwc1        $f4, 0x2C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x80020884: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80020888: swc1        $f8, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f8.u32l;
    // 0x8002088C: lbu         $t8, 0x73($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X73);
    // 0x80020890: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80020894: sb          $t8, 0x42($t9)
    MEM_B(0X42, ctx->r25) = ctx->r24;
    // 0x80020898: lbu         $t0, 0x77($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X77);
    // 0x8002089C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800208A0: sb          $t0, 0x43($t1)
    MEM_B(0X43, ctx->r9) = ctx->r8;
    // 0x800208A4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800208A8: lbu         $t4, 0x11($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X11);
    // 0x800208AC: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800208B0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800208B4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800208B8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800208BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800208C0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800208C4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800208C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800208CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800208D0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800208D4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800208D8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800208DC: lbu         $t2, 0x44($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X44);
    // 0x800208E0: andi        $t7, $t2, 0x10
    ctx->r15 = ctx->r10 & 0X10;
    // 0x800208E4: beq         $t7, $zero, L_80020938
    if (ctx->r15 == 0) {
        // 0x800208E8: nop
    
            goto L_80020938;
    }
    // 0x800208E8: nop

    // 0x800208EC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800208F0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800208F4: lbu         $t9, 0x44($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X44);
    // 0x800208F8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800208FC: sb          $t0, 0x44($t8)
    MEM_B(0X44, ctx->r24) = ctx->r8;
    // 0x80020900: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020904: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020908: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002090C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80020910: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020914: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80020918: jal         0x80026500
    // 0x8002091C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_80026500(rdram, ctx);
        goto after_2;
    // 0x8002091C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_2:
    // 0x80020920: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80020924: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80020928: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8002092C: lh          $t4, 0x62($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X62);
    // 0x80020930: b           L_80020958
    // 0x80020934: sh          $t4, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r12;
        goto L_80020958;
    // 0x80020934: sh          $t4, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r12;
L_80020938:
    // 0x80020938: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8002093C: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020940: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80020944: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80020948: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002094C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80020950: jal         0x80026500
    // 0x80020954: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_80026500(rdram, ctx);
        goto after_3;
    // 0x80020954: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_3:
L_80020958:
    // 0x80020958: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8002095C: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_80020960:
    // 0x80020960: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80020964: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80020968: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8002096C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80020970: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80020974: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80020978: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8002097C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80020980: lbu         $t3, 0x2($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X2);
    // 0x80020984: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x80020988: andi        $t4, $t3, 0xC0
    ctx->r12 = ctx->r11 & 0XC0;
    // 0x8002098C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80020990: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80020994: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
    // 0x80020998: lh          $t2, 0x62($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X62);
    // 0x8002099C: beq         $t2, $zero, L_800209B0
    if (ctx->r10 == 0) {
        // 0x800209A0: nop
    
            goto L_800209B0;
    }
    // 0x800209A0: nop

    // 0x800209A4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800209A8: bne         $t7, $zero, L_800207C0
    if (ctx->r15 != 0) {
        // 0x800209AC: nop
    
            goto L_800207C0;
    }
    // 0x800209AC: nop

L_800209B0:
    // 0x800209B0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800209B4: beq         $t9, $zero, L_80020A28
    if (ctx->r25 == 0) {
        // 0x800209B8: nop
    
            goto L_80020A28;
    }
    // 0x800209B8: nop

    // 0x800209BC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800209C0: lbu         $t8, 0x44($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X44);
    // 0x800209C4: ori         $t3, $t8, 0x1
    ctx->r11 = ctx->r24 | 0X1;
    // 0x800209C8: sb          $t3, 0x44($t0)
    MEM_B(0X44, ctx->r8) = ctx->r11;
    // 0x800209CC: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x800209D0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800209D4: sw          $t4, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r12;
    // 0x800209D8: lh          $t5, 0x4E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X4E);
    // 0x800209DC: beq         $t5, $zero, L_80020A28
    if (ctx->r13 == 0) {
        // 0x800209E0: nop
    
            goto L_80020A28;
    }
    // 0x800209E0: nop

    // 0x800209E4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800209E8: lbu         $t2, 0x44($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X44);
    // 0x800209EC: ori         $t7, $t2, 0x10
    ctx->r15 = ctx->r10 | 0X10;
    // 0x800209F0: sb          $t7, 0x44($t6)
    MEM_B(0X44, ctx->r14) = ctx->r15;
    // 0x800209F4: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x800209F8: sh          $t9, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r25;
    // 0x800209FC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80020A00: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80020A04: lh          $t3, 0x4E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4E);
    // 0x80020A08: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80020A0C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020A10: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020A14: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80020A18: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80020A1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020A20: jal         0x80026500
    // 0x80020A24: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_4;
    // 0x80020A24: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_4:
L_80020A28:
    // 0x80020A28: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80020A2C: beq         $t0, $zero, L_80020A40
    if (ctx->r8 == 0) {
        // 0x80020A30: nop
    
            goto L_80020A40;
    }
    // 0x80020A30: nop

    // 0x80020A34: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80020A38: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80020A3C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80020A40:
    // 0x80020A40: b           L_80020A50
    // 0x80020A44: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
        goto L_80020A50;
    // 0x80020A44: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80020A48: b           L_80020A50
    // 0x80020A4C: nop

        goto L_80020A50;
    // 0x80020A4C: nop

L_80020A50:
    // 0x80020A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020A54: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80020A58: jr          $ra
    // 0x80020A5C: nop

    return;
    // 0x80020A5C: nop

;}
RECOMP_FUNC void func_80800088_chalienbeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080008C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800094: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800098: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080009C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000A4: bnel        $t7, $at, L_80800100
    if (ctx->r15 != ctx->r1) {
        // 0x808000A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800100;
    }
    goto skip_0;
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000AC: jal         0x800D9078
    // 0x808000B0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808000B0: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x808000B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000BC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000C0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808000C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808000C8: jal         0x800F12D4
    // 0x808000CC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x808000CC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x808000D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000D8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808000DC: jal         0x800EFE50
    // 0x808000E0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x808000E0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x808000E4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: beql        $t8, $zero, L_80800100
    if (ctx->r24 == 0) {
        // 0x808000F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800100;
    }
    goto skip_1;
    // 0x808000F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808000F4: jal         0x80102424
    // 0x808000F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808000F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808000FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800100:
    // 0x80800100: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_808011B8_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808011BC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808011C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808011C4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x808011C8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808011CC: jr          $ra
    // 0x808011D0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    return;
    // 0x808011D0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
;}
RECOMP_FUNC void _suegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A378: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A378);
    return;
    // 0x8008A37C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bssnowball_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A58: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A58);
    return;
    // 0x80083A5C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800040_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: jal         0x8009EF04
    // 0x80800054: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x80800054: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800058: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080005C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800060: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800064: nop

    // 0x80800068: bc1f        L_80800080
    if (!c1cs) {
        // 0x8080006C: nop
    
            goto L_80800080;
    }
    // 0x8080006C: nop

    // 0x80800070: jal         0x800EFD24
    // 0x80800074: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80800078: b           L_80800198
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800198;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800080:
    // 0x80800080: jal         0x8009EEB8
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_2;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800088: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080008C: jal         0x800974FC
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800974FC(rdram, ctx);
        goto after_3;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800094: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800098: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080009C: jal         0x800F1DCC
    // 0x808000A0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x808000A0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_4:
    // 0x808000A4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808000A8: jal         0x800F2100
    // 0x808000AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x808000AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x808000B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808000B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808000BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808000C0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808000C4: nop

    // 0x808000C8: bc1f        L_808000DC
    if (!c1cs) {
        // 0x808000CC: nop
    
            goto L_808000DC;
    }
    // 0x808000CC: nop

    // 0x808000D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000D4: nop

    // 0x808000D8: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
L_808000DC:
    // 0x808000DC: jal         0x800F2100
    // 0x808000E0: nop

    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x808000E0: nop

    after_6:
    // 0x808000E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808000E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000EC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000F0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808000F4: nop

    // 0x808000F8: bc1fl       L_80800114
    if (!c1cs) {
        // 0x808000FC: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80800114;
    }
    goto skip_0;
    // 0x808000FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_0:
    // 0x80800100: jal         0x800EFD24
    // 0x80800104: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x80800104: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80800108: b           L_80800198
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800198;
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80800114:
    // 0x80800114: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800118: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080011C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800120: nop

    // 0x80800124: bc1fl       L_80800138
    if (!c1cs) {
        // 0x80800128: sw          $t7, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r15;
            goto L_80800138;
    }
    goto skip_1;
    // 0x80800128: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    skip_1:
    // 0x8080012C: b           L_80800138
    // 0x80800130: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800138;
    // 0x80800130: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
    // 0x80800134: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800138:
    // 0x80800138: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    // 0x8080013C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800140: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800144: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80800148: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8080014C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800150: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800154: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800158: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080015C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800160: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800164: jal         0x800F1214
    // 0x80800168: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_800F1214(rdram, ctx);
        goto after_8;
    // 0x80800168: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8080016C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800170: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800174: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800178: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x8080017C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800180: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800184: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800188: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080018C: jal         0x800EFCD8
    // 0x80800190: nop

    func_800EFCD8(rdram, ctx);
        goto after_9;
    // 0x80800190: nop

    after_9:
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800198:
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80801138_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801144: jal         0x80800A24
    // 0x80801148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800A24_bsbfly(rdram, ctx);
        goto after_0;
    // 0x80801148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080114C: jal         0x80800188
    // 0x80801150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bsbfly(rdram, ctx);
        goto after_1;
    // 0x80801150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080115C: jr          $ra
    // 0x80801160: nop

    return;
    // 0x80801160: nop

;}
RECOMP_FUNC void _sueggmove_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A480: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A480);
    return;
    // 0x8008A484: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bashoes_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x80800568: jr          $ra
    // 0x8080056C: sb          $a1, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r5;
    return;
    // 0x8080056C: sb          $a1, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800000_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x1AB
    ctx->r4 = ADD32(0, 0X1AB);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x8080001C: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80800050;
    }
    // 0x8080001C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: jal         0x80101FDC
    // 0x80800028: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080002C: jal         0x80103EF4
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_2;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2320, 0X4A0) << 16);
    // 0x80800038: lwc1        $f6, 0x4A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2320, 0X4A0));
    // 0x8080003C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800040: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800044: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800048: b           L_8080005C
    // 0x8080004C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_8080005C;
    // 0x8080004C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80800050:
    // 0x80800050: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800054: nop

    // 0x80800058: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_8080005C:
    // 0x8080005C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800060: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800338: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x8080033C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800340: jal         0x80016068
    // 0x80800344: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    func_80016068(rdram, ctx);
        goto after_0;
    // 0x80800344: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    after_0:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void func_80110588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110588: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8011058C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110590: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110594: lbu         $t6, 0x70($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X70);
    // 0x80110598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8011059C: beql        $t6, $zero, L_80110690
    if (ctx->r14 == 0) {
        // 0x801105A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80110690;
    }
    goto skip_0;
    // 0x801105A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801105A4: jal         0x8011607C
    // 0x801105A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8011607C(rdram, ctx);
        goto after_0;
    // 0x801105A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801105AC: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
    // 0x801105B0: bne         $t7, $zero, L_8011061C
    if (ctx->r15 != 0) {
        // 0x801105B4: nop
    
            goto L_8011061C;
    }
    // 0x801105B4: nop

    // 0x801105B8: jal         0x8011347C
    // 0x801105BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8011347C(rdram, ctx);
        goto after_1;
    // 0x801105BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801105C0: jal         0x801123D4
    // 0x801105C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801123D4(rdram, ctx);
        goto after_2;
    // 0x801105C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801105C8: jal         0x80115A9C
    // 0x801105CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115A9C(rdram, ctx);
        goto after_3;
    // 0x801105CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801105D0: jal         0x80112A84
    // 0x801105D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80112A84(rdram, ctx);
        goto after_4;
    // 0x801105D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801105D8: jal         0x801154A4
    // 0x801105DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801154A4(rdram, ctx);
        goto after_5;
    // 0x801105DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801105E0: jal         0x80112648
    // 0x801105E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80112648(rdram, ctx);
        goto after_6;
    // 0x801105E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801105E8: jal         0x80114DD8
    // 0x801105EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80114DD8(rdram, ctx);
        goto after_7;
    // 0x801105EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801105F0: jal         0x80113D30
    // 0x801105F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80113D30(rdram, ctx);
        goto after_8;
    // 0x801105F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801105F8: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x801105FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80110600: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80110604: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80110608: lw          $v0, 0x47A4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X47A4);
    // 0x8011060C: beq         $v0, $zero, L_8011061C
    if (ctx->r2 == 0) {
        // 0x80110610: nop
    
            goto L_8011061C;
    }
    // 0x80110610: nop

    // 0x80110614: jalr        $v0
    // 0x80110618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x80110618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8011061C:
    // 0x8011061C: jal         0x800EFD24
    // 0x80110620: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x80110620: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    after_10:
    // 0x80110624: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80110628: jal         0x800EE7F8
    // 0x8011062C: addiu       $a1, $s0, 0x74
    ctx->r5 = ADD32(ctx->r16, 0X74);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x8011062C: addiu       $a1, $s0, 0x74
    ctx->r5 = ADD32(ctx->r16, 0X74);
    after_11:
    // 0x80110630: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80110634: jal         0x800EE7F8
    // 0x80110638: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80110638: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_12:
    // 0x8011063C: lbu         $t0, 0x71($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X71);
    // 0x80110640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110644: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80110648: beql        $t0, $zero, L_8011065C
    if (ctx->r8 == 0) {
        // 0x8011064C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8011065C;
    }
    goto skip_1;
    // 0x8011064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80110650: jal         0x800893E0
    // 0x80110654: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _ncba1p_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80110654: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_13:
    // 0x80110658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8011065C:
    // 0x8011065C: jal         0x80116024
    // 0x80110660: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80116024(rdram, ctx);
        goto after_14;
    // 0x80110660: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_14:
    // 0x80110664: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x80110668: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8011066C: jal         0x8010FE14
    // 0x80110670: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8010FE14(rdram, ctx);
        goto after_15;
    // 0x80110670: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_15:
    // 0x80110674: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x80110678: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8011067C: beql        $t2, $zero, L_80110690
    if (ctx->r10 == 0) {
        // 0x80110680: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80110690;
    }
    goto skip_2;
    // 0x80110680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80110684: jal         0x80089458
    // 0x80110688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _ncbawaypoint_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80110688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8011068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110690:
    // 0x80110690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80110698: jr          $ra
    // 0x8011069C: nop

    return;
    // 0x8011069C: nop

;}
RECOMP_FUNC void func_80800D18_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D24: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800D28: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800D2C: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x80800D30: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800D34: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800D38: jal         0x800CC63C
    // 0x80800D3C: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x80800D3C: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x80800D40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800D48: jal         0x800EE7F8
    // 0x80800D4C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800D4C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_1:
    // 0x80800D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D58: jr          $ra
    // 0x80800D5C: nop

    return;
    // 0x80800D5C: nop

;}
RECOMP_FUNC void func_808002D0_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808002D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E0: jal         0x80100094
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002E8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808002F8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808002FC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80800300: jal         0x800D9078
    // 0x80800304: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800304: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x80800308: jal         0x8080220C
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080220C_chklungo(rdram, ctx);
        goto after_3;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800310: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800314: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800318: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080031C: sltiu       $at, $t8, 0x23
    ctx->r1 = ctx->r24 < 0X23 ? 1 : 0;
    // 0x80800320: beq         $at, $zero, L_80800FC8
    if (ctx->r1 == 0) {
        // 0x80800324: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800FC8;
    }
    // 0x80800324: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800328: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3590) << 16);
    // 0x8080032C: addu        $at, $at, $t8
    gpr jr_addend_80800334 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800330: lw          $t8, 0x3590($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3590));
    // 0x80800334: jr          $t8
    // 0x80800338: nop

    switch (jr_addend_80800334 >> 2) {
        case 0: goto L_8080033C; break;
        case 1: goto L_808003B0; break;
        case 2: goto L_80800424; break;
        case 3: goto L_80800494; break;
        case 4: goto L_808004B4; break;
        case 5: goto L_808004C4; break;
        case 6: goto L_808004EC; break;
        case 7: goto L_808004C4; break;
        case 8: goto L_80800558; break;
        case 9: goto L_80800664; break;
        case 10: goto L_80800674; break;
        case 11: goto L_80800740; break;
        case 12: goto L_808007CC; break;
        case 13: goto L_8080088C; break;
        case 14: goto L_808008AC; break;
        case 15: goto L_80800928; break;
        case 16: goto L_80800990; break;
        case 17: goto L_80800A80; break;
        case 18: goto L_80800ACC; break;
        case 19: goto L_80800B58; break;
        case 20: goto L_80800B68; break;
        case 21: goto L_80800B68; break;
        case 22: goto L_80800C18; break;
        case 23: goto L_80800D0C; break;
        case 24: goto L_80800FC8; break;
        case 25: goto L_80800D44; break;
        case 26: goto L_808004DC; break;
        case 27: goto L_80800D84; break;
        case 28: goto L_80800E84; break;
        case 29: goto L_80800FC8; break;
        case 30: goto L_80800EB4; break;
        case 31: goto L_80800EDC; break;
        case 32: goto L_80800F20; break;
        case 33: goto L_80800F50; break;
        case 34: goto L_80800F68; break;
        default: switch_error(__func__, 0x80800334, 0x80803590);
    }
    // 0x80800338: nop

L_8080033C:
    // 0x8080033C: jal         0x80801888
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_4;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800344: jal         0x80801910
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_5;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080034C: jal         0x808026CC
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_6;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800354: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80800358: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X391C) << 16);
    // 0x8080035C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800360: lh          $t0, 0x8($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X8);
    // 0x80800364: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80800368: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8080036C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800370: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80800374: jal         0x8010CA74
    // 0x80800378: lh          $a1, 0x391C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X391C));
    func_8010CA74(rdram, ctx);
        goto after_7;
    // 0x80800378: lh          $a1, 0x391C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X391C));
    after_7:
    // 0x8080037C: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800380: nop
    
            goto L_80800FC8;
    }
    // 0x80800380: nop

    // 0x80800384: jal         0x800F54E4
    // 0x80800388: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800388: nop

    after_8:
    // 0x8080038C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800390: jal         0x800F64A4
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_9;
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800398: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x8080039C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: jal         0x80801964
    // 0x808003A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801964_chklungo(rdram, ctx);
        goto after_10;
    // 0x808003A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x808003A8: b           L_80800FC8
    // 0x808003AC: nop

        goto L_80800FC8;
    // 0x808003AC: nop

L_808003B0:
    // 0x808003B0: jal         0x80801888
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_11;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808003B8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x808003BC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X391C) << 16);
    // 0x808003C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003C4: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x808003C8: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808003CC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x808003D0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808003D4: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x808003D8: jal         0x8010CA74
    // 0x808003DC: lh          $a1, 0x391C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X391C));
    func_8010CA74(rdram, ctx);
        goto after_12;
    // 0x808003DC: lh          $a1, 0x391C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X391C));
    after_12:
    // 0x808003E0: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x808003E4: nop
    
            goto L_80800FC8;
    }
    // 0x808003E4: nop

    // 0x808003E8: jal         0x800F54E4
    // 0x808003EC: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x808003EC: nop

    after_13:
    // 0x808003F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F4: jal         0x800F64A4
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_14;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808003FC: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: addiu       $a1, $zero, 0x1633
    ctx->r5 = ADD32(0, 0X1633);
    // 0x80800408: jal         0x80803158
    // 0x8080040C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80803158_chklungo(rdram, ctx);
        goto after_15;
    // 0x8080040C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_15:
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x80801964
    // 0x80800418: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801964_chklungo(rdram, ctx);
        goto after_16;
    // 0x80800418: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x8080041C: b           L_80800FC8
    // 0x80800420: nop

        goto L_80800FC8;
    // 0x80800420: nop

L_80800424:
    // 0x80800424: jal         0x800D8FF8
    // 0x80800428: nop

    func_800D8FF8(rdram, ctx);
        goto after_17;
    // 0x80800428: nop

    after_17:
    // 0x8080042C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800434: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800438: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080043C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800448: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8080044C: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x80800450: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800454: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800458: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8080045C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80800460: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80800464: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800468: lwc1        $f2, 0x3C($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x8080046C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80800470: nop

    // 0x80800474: bc1f        L_80800FC8
    if (!c1cs) {
        // 0x80800478: nop
    
            goto L_80800FC8;
    }
    // 0x80800478: nop

    // 0x8080047C: jal         0x80801964
    // 0x80800480: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    func_80801964_chklungo(rdram, ctx);
        goto after_18;
    // 0x80800480: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    after_18:
    // 0x80800484: jal         0x80802940
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802940_chklungo(rdram, ctx);
        goto after_19;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080048C: b           L_80800FC8
    // 0x80800490: nop

        goto L_80800FC8;
    // 0x80800490: nop

L_80800494:
    // 0x80800494: jal         0x80101DDC
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080049C: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80801964
    // 0x808004A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801964_chklungo(rdram, ctx);
        goto after_21;
    // 0x808004A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x808004AC: b           L_80800FC8
    // 0x808004B0: nop

        goto L_80800FC8;
    // 0x808004B0: nop

L_808004B4:
    // 0x808004B4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x808004B8: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x808004BC: bne         $t7, $zero, L_80800FC8
    if (ctx->r15 != 0) {
        // 0x808004C0: nop
    
            goto L_80800FC8;
    }
    // 0x808004C0: nop

L_808004C4:
    // 0x808004C4: jal         0x80801888
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_22;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808004CC: jal         0x808026CC
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_23;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808004D4: b           L_80800FC8
    // 0x808004D8: nop

        goto L_80800FC8;
    // 0x808004D8: nop

L_808004DC:
    // 0x808004DC: jal         0x808026CC
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_24;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808004E4: b           L_80800FC8
    // 0x808004E8: nop

        goto L_80800FC8;
    // 0x808004E8: nop

L_808004EC:
    // 0x808004EC: jal         0x80801888
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_25;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808004F4: jal         0x808026CC
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_26;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808004FC: jal         0x800DA298
    // 0x80800500: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x80800500: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_27:
    // 0x80800504: bne         $v0, $zero, L_80800FC8
    if (ctx->r2 != 0) {
        // 0x80800508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800510: jal         0x80802588
    // 0x80800514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802588_chklungo(rdram, ctx);
        goto after_28;
    // 0x80800514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x80800518: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8080051C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1240, 0X3914) << 16);
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x80800528: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080052C: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80800530: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80800534: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800538: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8080053C: jal         0x80803158
    // 0x80800540: lh          $a1, 0x3914($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3914));
    func_80803158_chklungo(rdram, ctx);
        goto after_29;
    // 0x80800540: lh          $a1, 0x3914($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1240, 0X3914));
    after_29:
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x80801964
    // 0x8080054C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801964_chklungo(rdram, ctx);
        goto after_30;
    // 0x8080054C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_30:
    // 0x80800550: b           L_80800FC8
    // 0x80800554: nop

        goto L_80800FC8;
    // 0x80800554: nop

L_80800558:
    // 0x80800558: jal         0x80802634
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802634_chklungo(rdram, ctx);
        goto after_31;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800560: jal         0x80101DDC
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_32;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800568: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x8080056C: nop
    
            goto L_80800FC8;
    }
    // 0x8080056C: nop

    // 0x80800570: jal         0x800FDC28
    // 0x80800574: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800FDC28(rdram, ctx);
        goto after_33;
    // 0x80800574: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_33:
    // 0x80800578: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8080057C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1240, 0X38A2) << 16);
    // 0x80800580: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x80800584: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80800588: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8080058C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800590: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80800594: jal         0x800DA544
    // 0x80800598: lh          $a0, 0x38A2($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A2));
    func_800DA544(rdram, ctx);
        goto after_34;
    // 0x80800598: lh          $a0, 0x38A2($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A2));
    after_34:
    // 0x8080059C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x808005A0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1240, 0X38A4) << 16);
    // 0x808005A4: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x808005A8: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x808005AC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x808005B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808005B4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x808005B8: jal         0x80088178
    // 0x808005BC: lh          $a0, 0x38A4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A4));
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_35;
    // 0x808005BC: lh          $a0, 0x38A4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A4));
    after_35:
    // 0x808005C0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x808005C4: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    // 0x808005C8: jal         0x800DA544
    // 0x808005CC: addiu       $a0, $a0, 0xC07
    ctx->r4 = ADD32(ctx->r4, 0XC07);
    func_800DA544(rdram, ctx);
        goto after_36;
    // 0x808005CC: addiu       $a0, $a0, 0xC07
    ctx->r4 = ADD32(ctx->r4, 0XC07);
    after_36:
    // 0x808005D0: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x808005D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: lh          $a1, 0x10($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X10);
    // 0x808005E0: beq         $a1, $at, L_80800604
    if (ctx->r5 == ctx->r1) {
        // 0x808005E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800604;
    }
    // 0x808005E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005E8: beq         $a1, $at, L_80800624
    if (ctx->r5 == ctx->r1) {
        // 0x808005EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800624;
    }
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005F4: beq         $a1, $at, L_80800644
    if (ctx->r5 == ctx->r1) {
        // 0x808005F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800644;
    }
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: b           L_80800FC8
    // 0x80800600: nop

        goto L_80800FC8;
    // 0x80800600: nop

L_80800604:
    // 0x80800604: jal         0x80801964
    // 0x80800608: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80801964_chklungo(rdram, ctx);
        goto after_37;
    // 0x80800608: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_37:
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: addiu       $a1, $zero, 0x1624
    ctx->r5 = ADD32(0, 0X1624);
    // 0x80800614: jal         0x80803158
    // 0x80800618: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803158_chklungo(rdram, ctx);
        goto after_38;
    // 0x80800618: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_38:
    // 0x8080061C: b           L_80800FC8
    // 0x80800620: nop

        goto L_80800FC8;
    // 0x80800620: nop

L_80800624:
    // 0x80800624: jal         0x80801964
    // 0x80800628: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80801964_chklungo(rdram, ctx);
        goto after_39;
    // 0x80800628: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_39:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: addiu       $a1, $zero, 0x1625
    ctx->r5 = ADD32(0, 0X1625);
    // 0x80800634: jal         0x80803158
    // 0x80800638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803158_chklungo(rdram, ctx);
        goto after_40;
    // 0x80800638: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_40:
    // 0x8080063C: b           L_80800FC8
    // 0x80800640: nop

        goto L_80800FC8;
    // 0x80800640: nop

L_80800644:
    // 0x80800644: jal         0x80801964
    // 0x80800648: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80801964_chklungo(rdram, ctx);
        goto after_41;
    // 0x80800648: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_41:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: addiu       $a1, $zero, 0x1626
    ctx->r5 = ADD32(0, 0X1626);
    // 0x80800654: jal         0x80803158
    // 0x80800658: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803158_chklungo(rdram, ctx);
        goto after_42;
    // 0x80800658: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_42:
    // 0x8080065C: b           L_80800FC8
    // 0x80800660: nop

        goto L_80800FC8;
    // 0x80800660: nop

L_80800664:
    // 0x80800664: jal         0x808026CC
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_43;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8080066C: b           L_80800FC8
    // 0x80800670: nop

        goto L_80800FC8;
    // 0x80800670: nop

L_80800674:
    // 0x80800674: jal         0x80101F24
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_44;
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x8080067C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800680: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800684: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080068C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800690: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800694: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800698: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080069C: jal         0x800F12D4
    // 0x808006A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_45;
    // 0x808006A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_45:
    // 0x808006A4: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808006AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006B0: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808006B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808006B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006BC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808006C0: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808006C4: nop

    // 0x808006C8: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808006CC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808006D0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808006D4: jal         0x8008FB58
    // 0x808006D8: nop

    func_8008FB58(rdram, ctx);
        goto after_46;
    // 0x808006D8: nop

    after_46:
    // 0x808006DC: jal         0x80802864
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802864_chklungo(rdram, ctx);
        goto after_47;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x808006E4: jal         0x80101DDC
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_48;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808006EC: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x808006F0: lw          $t9, 0x64($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X64);
            goto L_80800FC8;
    }
    // 0x808006F0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x808006F4: lh          $t0, 0x8($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X8);
    // 0x808006F8: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x808006FC: addiu       $t2, $t2, 0x38A0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x80800700: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80800704: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80800708: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8080070C: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80800710: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80800714: jal         0x800DC178
    // 0x80800718: lwc1        $f14, 0x64($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X64);
    func_800DC178(rdram, ctx);
        goto after_49;
    // 0x80800718: lwc1        $f14, 0x64($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X64);
    after_49:
    // 0x8080071C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: jal         0x80802558
    // 0x80800728: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    func_80802558_chklungo(rdram, ctx);
        goto after_50;
    // 0x80800728: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    after_50:
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: jal         0x80801964
    // 0x80800734: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80801964_chklungo(rdram, ctx);
        goto after_51;
    // 0x80800734: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_51:
    // 0x80800738: b           L_80800FC8
    // 0x8080073C: nop

        goto L_80800FC8;
    // 0x8080073C: nop

L_80800740:
    // 0x80800740: jal         0x80801888
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_52;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80800748: jal         0x808026CC
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_53;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80800750: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80800754: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800758: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8080075C: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x80800760: nop

    // 0x80800764: bc1f        L_808007AC
    if (!c1cs) {
        // 0x80800768: nop
    
            goto L_808007AC;
    }
    // 0x80800768: nop

    // 0x8080076C: jal         0x808018D4
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018D4_chklungo(rdram, ctx);
        goto after_54;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: jal         0x80801964
    // 0x8080077C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80801964_chklungo(rdram, ctx);
        goto after_55;
    // 0x8080077C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_55:
    // 0x80800780: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800784: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: lbu         $t5, 0x49($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X49);
    // 0x80800790: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800794: bne         $t5, $zero, L_80800FC8
    if (ctx->r13 != 0) {
        // 0x80800798: nop
    
            goto L_80800FC8;
    }
    // 0x80800798: nop

    // 0x8080079C: jal         0x808025CC
    // 0x808007A0: sb          $t6, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r14;
    func_808025CC_chklungo(rdram, ctx);
        goto after_56;
    // 0x808007A0: sb          $t6, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r14;
    after_56:
    // 0x808007A4: b           L_80800FC8
    // 0x808007A8: nop

        goto L_80800FC8;
    // 0x808007A8: nop

L_808007AC:
    // 0x808007AC: jal         0x800D9078
    // 0x808007B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_57;
    // 0x808007B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_57:
    // 0x808007B4: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x808007B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: jal         0x80801964
    // 0x808007C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80801964_chklungo(rdram, ctx);
        goto after_58;
    // 0x808007C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_58:
    // 0x808007C4: b           L_80800FC8
    // 0x808007C8: nop

        goto L_80800FC8;
    // 0x808007C8: nop

L_808007CC:
    // 0x808007CC: jal         0x80101F24
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_59;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x808007D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808007E0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808007E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808007E8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x808007EC: jal         0x800F12D4
    // 0x808007F0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F12D4(rdram, ctx);
        goto after_60;
    // 0x808007F0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_60:
    // 0x808007F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808007F8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808007FC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800800: jal         0x800EFE50
    // 0x80800804: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_61;
    // 0x80800804: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_61:
    // 0x80800808: jal         0x80802B10
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802B10_chklungo(rdram, ctx);
        goto after_62;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80800810: jal         0x80101DDC
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_63;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80800818: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x8080081C: lw          $t7, 0x64($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X64);
            goto L_80800FC8;
    }
    // 0x8080081C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80800820: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800824: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: c.eq.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl == ctx->f6.fl;
    // 0x80800830: nop

    // 0x80800834: bc1f        L_8080087C
    if (!c1cs) {
        // 0x80800838: nop
    
            goto L_8080087C;
    }
    // 0x80800838: nop

    // 0x8080083C: jal         0x808018D4
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018D4_chklungo(rdram, ctx);
        goto after_64;
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800848: jal         0x80801964
    // 0x8080084C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80801964_chklungo(rdram, ctx);
        goto after_65;
    // 0x8080084C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_65:
    // 0x80800850: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800854: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x80800860: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800864: bne         $t8, $zero, L_80800FC8
    if (ctx->r24 != 0) {
        // 0x80800868: nop
    
            goto L_80800FC8;
    }
    // 0x80800868: nop

    // 0x8080086C: jal         0x808025CC
    // 0x80800870: sb          $t9, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r25;
    func_808025CC_chklungo(rdram, ctx);
        goto after_66;
    // 0x80800870: sb          $t9, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r25;
    after_66:
    // 0x80800874: b           L_80800FC8
    // 0x80800878: nop

        goto L_80800FC8;
    // 0x80800878: nop

L_8080087C:
    // 0x8080087C: jal         0x80801964
    // 0x80800880: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80801964_chklungo(rdram, ctx);
        goto after_67;
    // 0x80800880: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_67:
    // 0x80800884: b           L_80800FC8
    // 0x80800888: nop

        goto L_80800FC8;
    // 0x80800888: nop

L_8080088C:
    // 0x8080088C: jal         0x80101DDC
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_68;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80800894: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800898: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: jal         0x80801964
    // 0x808008A0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80801964_chklungo(rdram, ctx);
        goto after_69;
    // 0x808008A0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_69:
    // 0x808008A4: b           L_80800FC8
    // 0x808008A8: nop

        goto L_80800FC8;
    // 0x808008A8: nop

L_808008AC:
    // 0x808008AC: jal         0x808028E8
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808028E8_chklungo(rdram, ctx);
        goto after_70;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x808008B4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x808008B8: lbu         $t1, 0x12($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X12);
    // 0x808008BC: beq         $t1, $zero, L_808008CC
    if (ctx->r9 == 0) {
        // 0x808008C0: nop
    
            goto L_808008CC;
    }
    // 0x808008C0: nop

    // 0x808008C4: jal         0x80801910
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_71;
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
L_808008CC:
    // 0x808008CC: jal         0x80101DDC
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_72;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
    // 0x808008D4: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x808008D8: nop
    
            goto L_80800FC8;
    }
    // 0x808008D8: nop

    // 0x808008DC: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E4: lbu         $t2, 0x12($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X12);
    // 0x808008E8: beql        $t2, $zero, L_80800904
    if (ctx->r10 == 0) {
        // 0x808008EC: lh          $t3, 0x22($v0)
        ctx->r11 = MEM_H(ctx->r2, 0X22);
            goto L_80800904;
    }
    goto skip_0;
    // 0x808008EC: lh          $t3, 0x22($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X22);
    skip_0:
    // 0x808008F0: jal         0x80801964
    // 0x808008F4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    func_80801964_chklungo(rdram, ctx);
        goto after_73;
    // 0x808008F4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_73:
    // 0x808008F8: b           L_80800FC8
    // 0x808008FC: nop

        goto L_80800FC8;
    // 0x808008FC: nop

    // 0x80800900: lh          $t3, 0x22($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X22);
L_80800904:
    // 0x80800904: beql        $t3, $zero, L_80800918
    if (ctx->r11 == 0) {
        // 0x80800908: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800918;
    }
    goto skip_1;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080090C: jal         0x80802558
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802558_chklungo(rdram, ctx);
        goto after_74;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800918:
    // 0x80800918: jal         0x80801964
    // 0x8080091C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801964_chklungo(rdram, ctx);
        goto after_75;
    // 0x8080091C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_75:
    // 0x80800920: b           L_80800FC8
    // 0x80800924: nop

        goto L_80800FC8;
    // 0x80800924: nop

L_80800928:
    // 0x80800928: jal         0x808026CC
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_76;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_76:
    // 0x80800930: jal         0x80089C90
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_77;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80800938: bne         $v0, $zero, L_80800FC8
    if (ctx->r2 != 0) {
        // 0x8080093C: nop
    
            goto L_80800FC8;
    }
    // 0x8080093C: nop

    // 0x80800940: jal         0x80802558
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802558_chklungo(rdram, ctx);
        goto after_78;
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80800948: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8080094C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x80800950: addiu       $t7, $t7, 0x38A0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x80800954: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x80800958: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8080095C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80800960: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800964: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800968: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x8080096C: jal         0x800DC178
    // 0x80800970: lwc1        $f14, 0x64($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X64);
    func_800DC178(rdram, ctx);
        goto after_79;
    // 0x80800970: lwc1        $f14, 0x64($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X64);
    after_79:
    // 0x80800974: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800980: jal         0x80801964
    // 0x80800984: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    func_80801964_chklungo(rdram, ctx);
        goto after_80;
    // 0x80800984: swc1        $f0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f0.u32l;
    after_80:
    // 0x80800988: b           L_80800FC8
    // 0x8080098C: nop

        goto L_80800FC8;
    // 0x8080098C: nop

L_80800990:
    // 0x80800990: jal         0x8080318C
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080318C_chklungo(rdram, ctx);
        goto after_81;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x80800998: jal         0x80803208
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803208_chklungo(rdram, ctx);
        goto after_82;
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x808009A0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x808009A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009AC: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x808009B0: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x808009B4: nop

    // 0x808009B8: bc1f        L_808009D4
    if (!c1cs) {
        // 0x808009BC: nop
    
            goto L_808009D4;
    }
    // 0x808009BC: nop

    // 0x808009C0: jal         0x808020F0
    // 0x808009C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808020F0_chklungo(rdram, ctx);
        goto after_83;
    // 0x808009C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_83:
    // 0x808009C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009CC: jal         0x80801964
    // 0x808009D0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801964_chklungo(rdram, ctx);
        goto after_84;
    // 0x808009D0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_84:
L_808009D4:
    // 0x808009D4: jal         0x808031E4
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808031E4_chklungo(rdram, ctx);
        goto after_85;
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x808009DC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808009E0: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808009E4: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x808009E8: addiu       $t0, $zero, 0x4802
    ctx->r8 = ADD32(0, 0X4802);
    // 0x808009EC: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
    // 0x808009F0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x808009F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808009F8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808009FC: jal         0x80089F90
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_86;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80800A04: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80800A08: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X361C) << 16);
    // 0x80800A0C: lwc1        $f10, 0x361C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X361C));
    // 0x80800A10: lhu         $a2, 0x82($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X82);
    // 0x80800A14: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x80800A18: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80800A1C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80800A20: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A2C: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80800A30: jal         0x80089F88
    // 0x80800A34: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_87;
    // 0x80800A34: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_87:
    // 0x80800A38: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800A3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A40: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80800A44: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800A48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A4C: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800A50: lhu         $a2, 0x82($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X82);
    // 0x80800A54: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A60: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800A64: jal         0x80089F80
    // 0x80800A68: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_88;
    // 0x80800A68: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_88:
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: jal         0x8010B990
    // 0x80800A74: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    func_8010B990(rdram, ctx);
        goto after_89;
    // 0x80800A74: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    after_89:
    // 0x80800A78: b           L_80800FC8
    // 0x80800A7C: nop

        goto L_80800FC8;
    // 0x80800A7C: nop

L_80800A80:
    // 0x80800A80: jal         0x80101DDC
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_90;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_90:
    // 0x80800A88: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800A8C: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_80800FC8;
    }
    // 0x80800A8C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80800A90: lbu         $t6, 0x12($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X12);
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: beq         $t6, $zero, L_80800AB0
    if (ctx->r14 == 0) {
        // 0x80800A9C: nop
    
            goto L_80800AB0;
    }
    // 0x80800A9C: nop

    // 0x80800AA0: jal         0x80801964
    // 0x80800AA4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    func_80801964_chklungo(rdram, ctx);
        goto after_91;
    // 0x80800AA4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_91:
    // 0x80800AA8: b           L_80800FC8
    // 0x80800AAC: nop

        goto L_80800FC8;
    // 0x80800AAC: nop

L_80800AB0:
    // 0x80800AB0: jal         0x80802558
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802558_chklungo(rdram, ctx);
        goto after_92;
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: jal         0x80801964
    // 0x80800AC0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801964_chklungo(rdram, ctx);
        goto after_93;
    // 0x80800AC0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_93:
    // 0x80800AC4: b           L_80800FC8
    // 0x80800AC8: nop

        goto L_80800FC8;
    // 0x80800AC8: nop

L_80800ACC:
    // 0x80800ACC: jal         0x800EFD24
    // 0x80800AD0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EFD24(rdram, ctx);
        goto after_94;
    // 0x80800AD0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_94:
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x80102D78
    // 0x80800ADC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80102D78(rdram, ctx);
        goto after_95;
    // 0x80800ADC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_95:
    // 0x80800AE0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800AE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AE8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800AEC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AF4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800AF8: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800AFC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B08: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800B0C: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
    // 0x80800B10: jal         0x80089F80
    // 0x80800B14: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_96;
    // 0x80800B14: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_96:
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: jal         0x8010B990
    // 0x80800B20: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    func_8010B990(rdram, ctx);
        goto after_97;
    // 0x80800B20: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    after_97:
    // 0x80800B24: jal         0x80803208
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803208_chklungo(rdram, ctx);
        goto after_98;
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_98:
    // 0x80800B2C: jal         0x808034CC
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808034CC_chklungo(rdram, ctx);
        goto after_99;
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_99:
    // 0x80800B34: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800B38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B3C: jal         0x80109FE8
    // 0x80800B40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_100;
    // 0x80800B40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_100:
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B48: jal         0x80801964
    // 0x80800B4C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80801964_chklungo(rdram, ctx);
        goto after_101;
    // 0x80800B4C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_101:
    // 0x80800B50: b           L_80800FC8
    // 0x80800B54: nop

        goto L_80800FC8;
    // 0x80800B54: nop

L_80800B58:
    // 0x80800B58: jal         0x808026CC
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_102;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_102:
    // 0x80800B60: b           L_80800FC8
    // 0x80800B64: nop

        goto L_80800FC8;
    // 0x80800B64: nop

L_80800B68:
    // 0x80800B68: jal         0x80802914
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802914_chklungo(rdram, ctx);
        goto after_103;
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_103:
    // 0x80800B70: jal         0x80101DDC
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_104;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_104:
    // 0x80800B78: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800B84: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B88: jal         0x8008A0D0
    // 0x80800B8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_105;
    // 0x80800B8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_105:
    // 0x80800B90: beql        $v0, $zero, L_80800BB0
    if (ctx->r2 == 0) {
        // 0x80800B94: lhu         $t7, 0x72($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X72);
            goto L_80800BB0;
    }
    goto skip_2;
    // 0x80800B94: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x80800B98: jal         0x800CBD84
    // 0x80800B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800CBD84(rdram, ctx);
        goto after_106;
    // 0x80800B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_106:
    // 0x80800BA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800BA4: bnel        $v0, $at, L_80800BF8
    if (ctx->r2 != ctx->r1) {
        // 0x80800BA8: addiu       $a0, $zero, 0x41E
        ctx->r4 = ADD32(0, 0X41E);
            goto L_80800BF8;
    }
    goto skip_3;
    // 0x80800BA8: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    skip_3:
    // 0x80800BAC: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
L_80800BB0:
    // 0x80800BB0: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80800BB4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800BB8: bne         $t8, $at, L_80800BCC
    if (ctx->r24 != ctx->r1) {
        // 0x80800BBC: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80800BCC;
    }
    // 0x80800BBC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800BC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BC4: b           L_80800BDC
    // 0x80800BC8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
        goto L_80800BDC;
    // 0x80800BC8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_80800BCC:
    // 0x80800BCC: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800BD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800BD4: nop

    // 0x80800BD8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_80800BDC:
    // 0x80800BDC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800BE0: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80800BE4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80800BE8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800BEC: jal         0x800EF1B8
    // 0x80800BF0: nop

    func_800EF1B8(rdram, ctx);
        goto after_107;
    // 0x80800BF0: nop

    after_107:
    // 0x80800BF4: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
L_80800BF8:
    // 0x80800BF8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800BFC: jal         0x80101180
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_108;
    // 0x80800C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_108:
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C08: jal         0x80801964
    // 0x80800C0C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_80801964_chklungo(rdram, ctx);
        goto after_109;
    // 0x80800C0C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_109:
    // 0x80800C10: b           L_80800FC8
    // 0x80800C14: nop

        goto L_80800FC8;
    // 0x80800C14: nop

L_80800C18:
    // 0x80800C18: jal         0x8080318C
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080318C_chklungo(rdram, ctx);
        goto after_110;
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_110:
    // 0x80800C20: jal         0x80803208
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803208_chklungo(rdram, ctx);
        goto after_111;
    // 0x80800C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_111:
    // 0x80800C28: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80800C2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800C30: lwc1        $f16, 0xC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80800C34: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x80800C38: nop

    // 0x80800C3C: bc1f        L_80800C60
    if (!c1cs) {
        // 0x80800C40: nop
    
            goto L_80800C60;
    }
    // 0x80800C40: nop

    // 0x80800C44: lh          $t0, 0x1A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1A);
    // 0x80800C48: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    // 0x80800C4C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800C50: bne         $t0, $zero, L_80800C60
    if (ctx->r8 != 0) {
        // 0x80800C54: nop
    
            goto L_80800C60;
    }
    // 0x80800C54: nop

    // 0x80800C58: jal         0x80101180
    // 0x80800C5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_112;
    // 0x80800C5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_112:
L_80800C60:
    // 0x80800C60: jal         0x808031E4
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808031E4_chklungo(rdram, ctx);
        goto after_113;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_113:
    // 0x80800C68: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800C6C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800C70: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800C74: addiu       $t1, $zero, 0x4802
    ctx->r9 = ADD32(0, 0X4802);
    // 0x80800C78: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
    // 0x80800C7C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800C80: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800C84: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800C88: jal         0x80089F90
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_114;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_114:
    // 0x80800C90: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80800C94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3620) << 16);
    // 0x80800C98: lwc1        $f6, 0x3620($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3620));
    // 0x80800C9C: lhu         $a2, 0x82($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X82);
    // 0x80800CA0: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x80800CA4: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80800CA8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80800CAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800CB8: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80800CBC: jal         0x80089F88
    // 0x80800CC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_115;
    // 0x80800CC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_115:
    // 0x80800CC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800CC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800CCC: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80800CD0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800CD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800CD8: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800CDC: lhu         $a2, 0x82($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X82);
    // 0x80800CE0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800CEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800CF0: jal         0x80089F80
    // 0x80800CF4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_116;
    // 0x80800CF4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_116:
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CFC: jal         0x8010B990
    // 0x80800D00: addiu       $a1, $zero, 0x1325
    ctx->r5 = ADD32(0, 0X1325);
    func_8010B990(rdram, ctx);
        goto after_117;
    // 0x80800D00: addiu       $a1, $zero, 0x1325
    ctx->r5 = ADD32(0, 0X1325);
    after_117:
    // 0x80800D04: b           L_80800FC8
    // 0x80800D08: nop

        goto L_80800FC8;
    // 0x80800D08: nop

L_80800D0C:
    // 0x80800D0C: jal         0x80101DDC
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_118;
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_118:
    // 0x80800D14: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800D18: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_80800FC8;
    }
    // 0x80800D18: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80800D1C: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x80800D20: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80800D24: beq         $t7, $zero, L_80800D34
    if (ctx->r15 == 0) {
        // 0x80800D28: nop
    
            goto L_80800D34;
    }
    // 0x80800D28: nop

    // 0x80800D2C: b           L_80800D34
    // 0x80800D30: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
        goto L_80800D34;
    // 0x80800D30: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
L_80800D34:
    // 0x80800D34: jal         0x80801964
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801964_chklungo(rdram, ctx);
        goto after_119;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_119:
    // 0x80800D3C: b           L_80800FC8
    // 0x80800D40: nop

        goto L_80800FC8;
    // 0x80800D40: nop

L_80800D44:
    // 0x80800D44: jal         0x80801888
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_120;
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_120:
    // 0x80800D4C: jal         0x808026CC
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_121;
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_121:
    // 0x80800D54: jal         0x80089C68
    // 0x80800D58: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_122;
    // 0x80800D58: addiu       $a0, $zero, 0x41E
    ctx->r4 = ADD32(0, 0X41E);
    after_122:
    // 0x80800D5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D60: bne         $v0, $at, L_80800FC8
    if (ctx->r2 != ctx->r1) {
        // 0x80800D64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: jal         0x80109FE8
    // 0x80800D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_123;
    // 0x80800D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_123:
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: jal         0x80801964
    // 0x80800D78: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801964_chklungo(rdram, ctx);
        goto after_124;
    // 0x80800D78: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_124:
    // 0x80800D7C: b           L_80800FC8
    // 0x80800D80: nop

        goto L_80800FC8;
    // 0x80800D80: nop

L_80800D84:
    // 0x80800D84: jal         0x80801888
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801888_chklungo(rdram, ctx);
        goto after_125;
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_125:
    // 0x80800D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D90: jal         0x80101E14
    // 0x80800D94: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_126;
    // 0x80800D94: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_126:
    // 0x80800D98: beq         $v0, $zero, L_80800DA8
    if (ctx->r2 == 0) {
        // 0x80800D9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DA8;
    }
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA0: jal         0x80108B04
    // 0x80800DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_127;
    // 0x80800DA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_127:
L_80800DA8:
    // 0x80800DA8: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80800DAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB4: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x80800DB8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800DBC: bne         $v0, $at, L_80800DC8
    if (ctx->r2 != ctx->r1) {
        // 0x80800DC0: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80800DC8;
    }
    // 0x80800DC0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80800DC4: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
L_80800DC8:
    // 0x80800DC8: jal         0x80101E14
    // 0x80800DCC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_128;
    // 0x80800DCC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_128:
    // 0x80800DD0: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800DD4: nop
    
            goto L_80800FC8;
    }
    // 0x80800DD4: nop

    // 0x80800DD8: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800DDC: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80800DE0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800DE4: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x80800DE8: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80800DEC: bne         $t1, $zero, L_80800E7C
    if (ctx->r9 != 0) {
        // 0x80800DF0: nop
    
            goto L_80800E7C;
    }
    // 0x80800DF0: nop

    // 0x80800DF4: lh          $a1, 0x10($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X10);
    // 0x80800DF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E00: beq         $a1, $at, L_80800E24
    if (ctx->r5 == ctx->r1) {
        // 0x80800E04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E24;
    }
    // 0x80800E04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E08: beq         $a1, $at, L_80800E34
    if (ctx->r5 == ctx->r1) {
        // 0x80800E0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E34;
    }
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E14: beq         $a1, $at, L_80800E44
    if (ctx->r5 == ctx->r1) {
        // 0x80800E18: nop
    
            goto L_80800E44;
    }
    // 0x80800E18: nop

    // 0x80800E1C: b           L_80800E68
    // 0x80800E20: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
        goto L_80800E68;
    // 0x80800E20: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
L_80800E24:
    // 0x80800E24: jal         0x80801964
    // 0x80800E28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80801964_chklungo(rdram, ctx);
        goto after_129;
    // 0x80800E28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_129:
    // 0x80800E2C: b           L_80800E68
    // 0x80800E30: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
        goto L_80800E68;
    // 0x80800E30: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
L_80800E34:
    // 0x80800E34: jal         0x80801964
    // 0x80800E38: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80801964_chklungo(rdram, ctx);
        goto after_130;
    // 0x80800E38: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_130:
    // 0x80800E3C: b           L_80800E68
    // 0x80800E40: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
        goto L_80800E68;
    // 0x80800E40: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
L_80800E44:
    // 0x80800E44: jal         0x808034CC
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808034CC_chklungo(rdram, ctx);
        goto after_131;
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_131:
    // 0x80800E4C: beq         $v0, $zero, L_80800E5C
    if (ctx->r2 == 0) {
        // 0x80800E50: addiu       $a1, $zero, 0x13
        ctx->r5 = ADD32(0, 0X13);
            goto L_80800E5C;
    }
    // 0x80800E50: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80800E54: b           L_80800E5C
    // 0x80800E58: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
        goto L_80800E5C;
    // 0x80800E58: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80800E5C:
    // 0x80800E5C: jal         0x80801964
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801964_chklungo(rdram, ctx);
        goto after_132;
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_132:
    // 0x80800E64: addiu       $a0, $zero, 0x421
    ctx->r4 = ADD32(0, 0X421);
L_80800E68:
    // 0x80800E68: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800E6C: jal         0x80101180
    // 0x80800E70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_133;
    // 0x80800E70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_133:
    // 0x80800E74: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800E78: sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
L_80800E7C:
    // 0x80800E7C: b           L_80800FC8
    // 0x80800E80: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
        goto L_80800FC8;
    // 0x80800E80: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
L_80800E84:
    // 0x80800E84: jal         0x80801910
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_134;
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_134:
    // 0x80800E8C: jal         0x80802798
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802798_chklungo(rdram, ctx);
        goto after_135;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_135:
    // 0x80800E94: jal         0x80101DDC
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_136;
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_136:
    // 0x80800E9C: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800EA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA4: jal         0x80801964
    // 0x80800EA8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80801964_chklungo(rdram, ctx);
        goto after_137;
    // 0x80800EA8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_137:
    // 0x80800EAC: b           L_80800FC8
    // 0x80800EB0: nop

        goto L_80800FC8;
    // 0x80800EB0: nop

L_80800EB4:
    // 0x80800EB4: jal         0x80801910
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_138;
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_138:
    // 0x80800EBC: jal         0x800D9078
    // 0x80800EC0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_139;
    // 0x80800EC0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_139:
    // 0x80800EC4: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800EC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ECC: jal         0x80801964
    // 0x80800ED0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80801964_chklungo(rdram, ctx);
        goto after_140;
    // 0x80800ED0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_140:
    // 0x80800ED4: b           L_80800FC8
    // 0x80800ED8: nop

        goto L_80800FC8;
    // 0x80800ED8: nop

L_80800EDC:
    // 0x80800EDC: jal         0x80801910
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_141;
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_141:
    // 0x80800EE4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1240, 0X3BB4) << 16);
    // 0x80800EE8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800EEC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800EF0: addiu       $a2, $a2, 0x3BB4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1240, 0X3BB4));
    // 0x80800EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF8: jal         0x80089D20
    // 0x80800EFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_142;
    // 0x80800EFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_142:
    // 0x80800F00: jal         0x80101DDC
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_143;
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_143:
    // 0x80800F08: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800F0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F10: jal         0x80801964
    // 0x80800F14: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_80801964_chklungo(rdram, ctx);
        goto after_144;
    // 0x80800F14: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_144:
    // 0x80800F18: b           L_80800FC8
    // 0x80800F1C: nop

        goto L_80800FC8;
    // 0x80800F1C: nop

L_80800F20:
    // 0x80800F20: jal         0x80801910
    // 0x80800F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_145;
    // 0x80800F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_145:
    // 0x80800F28: jal         0x808026CC
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_146;
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_146:
    // 0x80800F30: jal         0x800D9078
    // 0x80800F34: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_147;
    // 0x80800F34: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_147:
    // 0x80800F38: beq         $v0, $zero, L_80800FC8
    if (ctx->r2 == 0) {
        // 0x80800F3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F40: jal         0x80801964
    // 0x80800F44: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80801964_chklungo(rdram, ctx);
        goto after_148;
    // 0x80800F44: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_148:
    // 0x80800F48: b           L_80800FC8
    // 0x80800F4C: nop

        goto L_80800FC8;
    // 0x80800F4C: nop

L_80800F50:
    // 0x80800F50: jal         0x808026CC
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026CC_chklungo(rdram, ctx);
        goto after_149;
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_149:
    // 0x80800F58: jal         0x80801910
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_150;
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_150:
    // 0x80800F60: b           L_80800FC8
    // 0x80800F64: nop

        goto L_80800FC8;
    // 0x80800F64: nop

L_80800F68:
    // 0x80800F68: jal         0x80801910
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801910_chklungo(rdram, ctx);
        goto after_151;
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_151:
    // 0x80800F70: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800F74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F78: lh          $t3, 0x20($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X20);
    // 0x80800F7C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80800F80: sh          $t4, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r12;
    // 0x80800F84: lh          $t5, 0x20($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X20);
    // 0x80800F88: bne         $t5, $at, L_80800FC8
    if (ctx->r13 != ctx->r1) {
        // 0x80800F8C: nop
    
            goto L_80800FC8;
    }
    // 0x80800F8C: nop

    // 0x80800F90: lwc1        $f0, 0x5C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80800F94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800F98: addiu       $a1, $v0, 0x30
    ctx->r5 = ADD32(ctx->r2, 0X30);
    // 0x80800F9C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800FA0: jal         0x800EE7F8
    // 0x80800FA4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_152;
    // 0x80800FA4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    after_152:
    // 0x80800FA8: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80800FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80800FB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800FB8: jal         0x801058C4
    // 0x80800FBC: lh          $a1, 0x2C($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X2C);
    func_801058C4(rdram, ctx);
        goto after_153;
    // 0x80800FBC: lh          $a1, 0x2C($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X2C);
    after_153:
    // 0x80800FC0: jal         0x80105BAC
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_154;
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_154:
L_80800FC8:
    // 0x80800FC8: jal         0x808030A4
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808030A4_chklungo(rdram, ctx);
        goto after_155;
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_155:
    // 0x80800FD0: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80800FD4: beql        $t7, $zero, L_8080100C
    if (ctx->r15 == 0) {
        // 0x80800FD8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080100C;
    }
    goto skip_4;
    // 0x80800FD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80800FDC: jal         0x801022E4
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_156;
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_156:
    // 0x80800FE4: addiu       $at, $zero, 0x264
    ctx->r1 = ADD32(0, 0X264);
    // 0x80800FE8: beq         $v0, $at, L_80800FF8
    if (ctx->r2 == ctx->r1) {
        // 0x80800FEC: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800FF8;
    }
    // 0x80800FEC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800FF0: jal         0x80089818
    // 0x80800FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_157;
    // 0x80800FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_157:
L_80800FF8:
    // 0x80800FF8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800FFC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801000: jal         0x800897D8
    // 0x80801004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_158;
    // 0x80801004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_158:
    // 0x80801008: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080100C:
    // 0x8080100C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801010: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801014: jr          $ra
    // 0x80801018: nop

    return;
    // 0x80801018: nop

;}
RECOMP_FUNC void func_800B0CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0CFC: bnel        $a0, $zero, L_800B0D10
    if (ctx->r4 != 0) {
        // 0x800B0D00: lh          $v0, 0xE($a0)
        ctx->r2 = MEM_H(ctx->r4, 0XE);
            goto L_800B0D10;
    }
    goto skip_0;
    // 0x800B0D00: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800B0D04: jr          $ra
    // 0x800B0D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B0D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B0D0C: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
L_800B0D10:
    // 0x800B0D10: lh          $v1, 0xC($a0)
    ctx->r3 = MEM_H(ctx->r4, 0XC);
    // 0x800B0D14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B0D18: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B0D1C: beq         $at, $zero, L_800B0D2C
    if (ctx->r1 == 0) {
        // 0x800B0D20: nop
    
            goto L_800B0D2C;
    }
    // 0x800B0D20: nop

    // 0x800B0D24: b           L_800B0D2C
    // 0x800B0D28: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_800B0D2C;
    // 0x800B0D28: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800B0D2C:
    // 0x800B0D2C: bgtz        $a0, L_800B0D3C
    if (SIGNED(ctx->r4) > 0) {
        // 0x800B0D30: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B0D3C;
    }
    // 0x800B0D30: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B0D34: b           L_800B0D3C
    // 0x800B0D38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800B0D3C;
    // 0x800B0D38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800B0D3C:
    // 0x800B0D3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B0D40: jr          $ra
    // 0x800B0D44: nop

    return;
    // 0x800B0D44: nop

    // 0x800B0D48: nop

    // 0x800B0D4C: nop

;}
RECOMP_FUNC void func_800F9B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9B54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F9B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9B5C: jal         0x800F54E4
    // 0x800F9B60: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800F9B60: nop

    after_0:
    // 0x800F9B64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F9B68: jal         0x800878A0
    // 0x800F9B6C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x800F9B6C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_1:
    // 0x800F9B70: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800F9B74: jal         0x800F8128
    // 0x800F9B78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F8128(rdram, ctx);
        goto after_2;
    // 0x800F9B78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800F9B7C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F9B84: jal         0x800F8268
    // 0x800F9B88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_3;
    // 0x800F9B88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800F9B8C: jal         0x800F82C0
    // 0x800F9B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F82C0(rdram, ctx);
        goto after_4;
    // 0x800F9B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x800F9B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9B98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F9B9C: jr          $ra
    // 0x800F9BA0: nop

    return;
    // 0x800F9BA0: nop

;}
RECOMP_FUNC void func_8080101C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080101C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080102C: beq         $a1, $zero, L_80801050
    if (ctx->r5 == 0) {
        // 0x80801030: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80801050;
    }
    // 0x80801030: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801034: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801038: beq         $a1, $at, L_80801078
    if (ctx->r5 == ctx->r1) {
        // 0x8080103C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801078;
    }
    // 0x8080103C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801040: beq         $a1, $at, L_808010B8
    if (ctx->r5 == ctx->r1) {
        // 0x80801044: nop
    
            goto L_808010B8;
    }
    // 0x80801044: nop

    // 0x80801048: b           L_80801140
    // 0x8080104C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_80801140;
    // 0x8080104C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80801050:
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801054: jal         0x8009C914
    // 0x80801058: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    yaw_setIdeal(rdram, ctx);
        goto after_0;
    // 0x80801058: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_0:
    // 0x8080105C: jal         0x8009C974
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_1;
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801068: jal         0x800931AC
    // 0x8080106C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_2;
    // 0x8080106C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801070: b           L_80801140
    // 0x80801074: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_80801140;
    // 0x80801074: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80801078:
    // 0x80801078: jal         0x8009C984
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_3;
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801080: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801084: swc1        $f0, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f0.u32l;
    // 0x80801088: jal         0x8009328C
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009328C(rdram, ctx);
        goto after_4;
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801094: jal         0x800931AC
    // 0x80801098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800931AC(rdram, ctx);
        goto after_5;
    // 0x80801098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8080109C: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808010A0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808010A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A8: jal         0x80085338
    // 0x808010AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_6;
    // 0x808010AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808010B0: b           L_80801140
    // 0x808010B4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_80801140;
    // 0x808010B4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_808010B8:
    // 0x808010B8: jal         0x80092BE8
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BE8(rdram, ctx);
        goto after_7;
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808010C0: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x808010C4: lwc1        $f12, 0x174($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X174);
    // 0x808010C8: jal         0x800F1DCC
    // 0x808010CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_8;
    // 0x808010CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_8:
    // 0x808010D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808010D4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808010D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808010DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808010E0: nop

    // 0x808010E4: bc1fl       L_808010FC
    if (!c1cs) {
        // 0x808010E8: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_808010FC;
    }
    goto skip_0;
    // 0x808010E8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x808010EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010F0: nop

    // 0x808010F4: add.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808010F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_808010FC:
    // 0x808010FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801100: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80801104: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80801108: nop

    // 0x8080110C: bc1fl       L_80801124
    if (!c1cs) {
        // 0x80801110: lwc1        $f16, 0x170($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
            goto L_80801124;
    }
    goto skip_1;
    // 0x80801110: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    skip_1:
    // 0x80801114: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801118: nop

    // 0x8080111C: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80801120: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
L_80801124:
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080112C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80801130: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80801134: jal         0x80085338
    // 0x80801138: swc1        $f18, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f18.u32l;
    _batimer_set(rdram, ctx);
        goto after_9;
    // 0x80801138: swc1        $f18, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x8080113C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80801140:
    // 0x80801140: sb          $t7, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r15;
    // 0x80801144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080114C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801150: jr          $ra
    // 0x80801154: nop

    return;
    // 0x80801154: nop

;}
RECOMP_FUNC void func_808002C0_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x808002C4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x808002C8: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x808002CC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x808002D0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x808002D4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x808002D8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x808002DC: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x808002E0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x808002E4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x808002E8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x808002EC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x808002F0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x808002F4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808002F8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808002FC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800300: jal         0x80100094
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800308: lw          $t6, 0x6C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X6C);
    // 0x8080030C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800310: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800314: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800318: sw          $t7, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r15;
    // 0x8080031C: lw          $t8, 0x64($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X64);
    // 0x80800320: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800324: bgezl       $t0, L_8080036C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800328: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8080036C;
    }
    goto skip_0;
    // 0x80800328: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x8080032C: lwc1        $f4, 0x54($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X54);
    // 0x80800330: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800334: nop

    // 0x80800338: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080033C: nop

    // 0x80800340: bc1f        L_80800360
    if (!c1cs) {
        // 0x80800344: nop
    
            goto L_80800360;
    }
    // 0x80800344: nop

    // 0x80800348: jal         0x800D8FF8
    // 0x8080034C: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080034C: nop

    after_1:
    // 0x80800350: lwc1        $f8, 0x54($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X54);
    // 0x80800354: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80800358: b           L_80800368
    // 0x8080035C: swc1        $f10, 0x54($s7)
    MEM_W(0X54, ctx->r23) = ctx->f10.u32l;
        goto L_80800368;
    // 0x8080035C: swc1        $f10, 0x54($s7)
    MEM_W(0X54, ctx->r23) = ctx->f10.u32l;
L_80800360:
    // 0x80800360: jal         0x80089CA8
    // 0x80800364: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800364: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
L_80800368:
    // 0x80800368: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_8080036C:
    // 0x8080036C: jal         0x80100094
    // 0x80800370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800374: jal         0x8008A040
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8080037C: beql        $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800380: lw          $a1, 0x6C($s7)
        ctx->r5 = MEM_W(ctx->r23, 0X6C);
            goto L_80800424;
    }
    goto skip_1;
    // 0x80800380: lw          $a1, 0x6C($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X6C);
    skip_1:
    // 0x80800384: lw          $t1, 0x78($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X78);
    // 0x80800388: sll         $t3, $t1, 29
    ctx->r11 = S32(ctx->r9 << 29);
    // 0x8080038C: bltzl       $t3, L_808003B0
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800390: lhu         $t4, 0x76($s7)
        ctx->r12 = MEM_HU(ctx->r23, 0X76);
            goto L_808003B0;
    }
    goto skip_2;
    // 0x80800390: lhu         $t4, 0x76($s7)
    ctx->r12 = MEM_HU(ctx->r23, 0X76);
    skip_2:
    // 0x80800394: jal         0x80800068
    // 0x80800398: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80800068_chnewfreezy(rdram, ctx);
        goto after_5;
    // 0x80800398: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x8080039C: jal         0x808000AC
    // 0x808003A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_808000AC_chnewfreezy(rdram, ctx);
        goto after_6;
    // 0x808003A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_6:
    // 0x808003A4: b           L_80800424
    // 0x808003A8: lw          $a1, 0x6C($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X6C);
        goto L_80800424;
    // 0x808003A8: lw          $a1, 0x6C($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X6C);
    // 0x808003AC: lhu         $t4, 0x76($s7)
    ctx->r12 = MEM_HU(ctx->r23, 0X76);
L_808003B0:
    // 0x808003B0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x808003B4: addiu       $a0, $s7, 0x4
    ctx->r4 = ADD32(ctx->r23, 0X4);
    // 0x808003B8: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x808003BC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x808003C0: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x808003C4: bgez        $t5, L_808003DC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808003C8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_808003DC;
    }
    // 0x808003C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808003CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808003D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003D4: nop

    // 0x808003D8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_808003DC:
    // 0x808003DC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808003E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003E4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808003E8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x808003EC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808003F0: jal         0x80089F18
    // 0x808003F4: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808003F4: nop

    after_7:
    // 0x808003F8: jal         0x800D9078
    // 0x808003FC: addiu       $a0, $s7, 0x58
    ctx->r4 = ADD32(ctx->r23, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x808003FC: addiu       $a0, $s7, 0x58
    ctx->r4 = ADD32(ctx->r23, 0X58);
    after_8:
    // 0x80800400: beql        $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800404: lw          $a1, 0x6C($s7)
        ctx->r5 = MEM_W(ctx->r23, 0X6C);
            goto L_80800424;
    }
    goto skip_3;
    // 0x80800404: lw          $a1, 0x6C($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X6C);
    skip_3:
    // 0x80800408: jal         0x80800068
    // 0x8080040C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80800068_chnewfreezy(rdram, ctx);
        goto after_9;
    // 0x8080040C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x80800410: jal         0x808000D4
    // 0x80800414: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_808000D4_chnewfreezy(rdram, ctx);
        goto after_10;
    // 0x80800414: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x80800418: jal         0x808000AC
    // 0x8080041C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_808000AC_chnewfreezy(rdram, ctx);
        goto after_11;
    // 0x8080041C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_11:
    // 0x80800420: lw          $a1, 0x6C($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X6C);
L_80800424:
    // 0x80800424: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80800428: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080042C: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80800430: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800434: jal         0x800DC128
    // 0x80800438: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    func_800DC128(rdram, ctx);
        goto after_12;
    // 0x80800438: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_12:
    // 0x8080043C: sw          $v0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r2;
    // 0x80800440: lw          $v1, 0x6C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X6C);
    // 0x80800444: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80800448: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080044C: andi        $t8, $v1, 0x1FF
    ctx->r24 = ctx->r3 & 0X1FF;
    // 0x80800450: beq         $t8, $zero, L_80800788
    if (ctx->r24 == 0) {
        // 0x80800454: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80800788;
    }
    // 0x80800454: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80800458: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080045C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80800460: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800464: addiu       $s6, $sp, 0x98
    ctx->r22 = ADD32(ctx->r29, 0X98);
    // 0x80800468: addiu       $s5, $sp, 0xA4
    ctx->r21 = ADD32(ctx->r29, 0XA4);
    // 0x8080046C: addiu       $s4, $sp, 0xB0
    ctx->r20 = ADD32(ctx->r29, 0XB0);
    // 0x80800470: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80800474:
    // 0x80800474: lb          $t9, 0x5C($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X5C);
    // 0x80800478: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8080047C: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80800480: beq         $at, $zero, L_80800778
    if (ctx->r1 == 0) {
        // 0x80800484: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800778;
    }
    // 0x80800484: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800488: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X1924) << 16);
    // 0x8080048C: addu        $at, $at, $t0
    gpr jr_addend_80800494 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800490: lw          $t0, 0x1924($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1812, 0X1924));
    // 0x80800494: jr          $t0
    // 0x80800498: nop

    switch (jr_addend_80800494 >> 2) {
        case 0: goto L_80800534; break;
        case 1: goto L_8080049C; break;
        case 2: goto L_8080075C; break;
        case 3: goto L_808005C4; break;
        case 4: goto L_8080076C; break;
        default: switch_error(__func__, 0x80800494, 0x80801924);
    }
    // 0x80800498: nop

L_8080049C:
    // 0x8080049C: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x808004A0: bnel        $fp, $t1, L_8080077C
    if (ctx->r30 != ctx->r9) {
        // 0x808004A4: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_8080077C;
    }
    goto skip_4;
    // 0x808004A4: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    skip_4:
    // 0x808004A8: jal         0x800E3980
    // 0x808004AC: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    func_800E3980(rdram, ctx);
        goto after_13;
    // 0x808004AC: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    after_13:
    // 0x808004B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004B4: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x808004B8: jal         0x800F18FC
    // 0x808004BC: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    func_800F18FC(rdram, ctx);
        goto after_14;
    // 0x808004BC: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    after_14:
    // 0x808004C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808004C4:
    // 0x808004C4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808004C8: jal         0x800DC178
    // 0x808004CC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x808004CC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_15:
    // 0x808004D0: sub.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x808004D4: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x808004D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004DC: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808004E0: bne         $s0, $s2, L_808004C4
    if (ctx->r16 != ctx->r18) {
        // 0x808004E4: swc1        $f4, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
            goto L_808004C4;
    }
    // 0x808004E4: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x808004E8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808004EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004F0: lwc1        $f18, 0x4C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x808004F4: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x808004F8: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x808004FC: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800500: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800504: jal         0x800EEBF0
    // 0x80800508: nop

    func_800EEBF0(rdram, ctx);
        goto after_16;
    // 0x80800508: nop

    after_16:
    // 0x8080050C: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x80800510: jal         0x800EF04C
    // 0x80800514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_17;
    // 0x80800514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x80800518: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x8080051C: jal         0x80088AB0
    // 0x80800520: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    _fxtwinkle_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x80800520: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    after_18:
    // 0x80800524: lw          $v1, 0x6C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X6C);
    // 0x80800528: andi        $t2, $v1, 0x1FF
    ctx->r10 = ctx->r3 & 0X1FF;
    // 0x8080052C: b           L_80800778
    // 0x80800530: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
        goto L_80800778;
    // 0x80800530: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80800534:
    // 0x80800534: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080053C: lwc1        $f12, 0x24($s7)
    ctx->f12.u32l = MEM_W(ctx->r23, 0X24);
    // 0x80800540: lwc1        $f14, 0x54($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80800544: lw          $a2, 0x58($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X58);
    // 0x80800548: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080054C: jal         0x800F10B4
    // 0x80800550: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x80800550: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x80800554: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800558: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080055C: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x80800560: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80800564: nop

    // 0x80800568: bc1fl       L_80800578
    if (!c1cs) {
        // 0x8080056C: lwc1        $f4, 0x48($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
            goto L_80800578;
    }
    goto skip_5;
    // 0x8080056C: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
    skip_5:
    // 0x80800570: sb          $s2, 0x5C($s1)
    MEM_B(0X5C, ctx->r17) = ctx->r18;
    // 0x80800574: lwc1        $f4, 0x48($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X48);
L_80800578:
    // 0x80800578: lwc1        $f18, 0x50($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8080057C: addiu       $s0, $s1, 0x24
    ctx->r16 = ADD32(ctx->r17, 0X24);
    // 0x80800580: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800584: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800588: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x8080058C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800590: jal         0x800EFB24
    // 0x80800594: swc1        $f6, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f6.u32l;
    func_800EFB24(rdram, ctx);
        goto after_20;
    // 0x80800594: swc1        $f6, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f6.u32l;
    after_20:
    // 0x80800598: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x8080059C: jal         0x800EF334
    // 0x808005A0: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    func_800EF334(rdram, ctx);
        goto after_21;
    // 0x808005A0: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    after_21:
    // 0x808005A4: addiu       $a0, $s1, 0x3C
    ctx->r4 = ADD32(ctx->r17, 0X3C);
    // 0x808005A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005AC: jal         0x800EE780
    // 0x808005B0: addiu       $a2, $sp, 0xBC
    ctx->r6 = ADD32(ctx->r29, 0XBC);
    func_800EE780(rdram, ctx);
        goto after_22;
    // 0x808005B0: addiu       $a2, $sp, 0xBC
    ctx->r6 = ADD32(ctx->r29, 0XBC);
    after_22:
    // 0x808005B4: lw          $v1, 0x6C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X6C);
    // 0x808005B8: andi        $t3, $v1, 0x1FF
    ctx->r11 = ctx->r3 & 0X1FF;
    // 0x808005BC: b           L_80800778
    // 0x808005C0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
        goto L_80800778;
    // 0x808005C0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_808005C4:
    // 0x808005C4: jal         0x800D8FF8
    // 0x808005C8: nop

    func_800D8FF8(rdram, ctx);
        goto after_23;
    // 0x808005C8: nop

    after_23:
    // 0x808005CC: addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
    // 0x808005D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005D8: jal         0x800EFA20
    // 0x808005DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EFA20(rdram, ctx);
        goto after_24;
    // 0x808005DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_24:
    // 0x808005E0: addiu       $s3, $s1, 0x3C
    ctx->r19 = ADD32(ctx->r17, 0X3C);
    // 0x808005E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808005E8: jal         0x800EE7F8
    // 0x808005EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_25;
    // 0x808005EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_25:
    // 0x808005F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808005F4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808005F8: jal         0x800EE780
    // 0x808005FC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EE780(rdram, ctx);
        goto after_26;
    // 0x808005FC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_26:
    // 0x80800600: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800604: jal         0x800EF04C
    // 0x80800608: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_27;
    // 0x80800608: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_27:
    // 0x8080060C: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80800610: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80800614: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800618: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8080061C: jal         0x800BEF00
    // 0x80800620: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_800BEF00(rdram, ctx);
        goto after_28;
    // 0x80800620: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_28:
    // 0x80800624: beq         $v0, $zero, L_808006F0
    if (ctx->r2 == 0) {
        // 0x80800628: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1812, 0X1940) << 16);
            goto L_808006F0;
    }
    // 0x80800628: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X1940) << 16);
    // 0x8080062C: jal         0x800EEF94
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_29;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800634: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800638: jal         0x800EEF94
    // 0x8080063C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EEF94(rdram, ctx);
        goto after_30;
    // 0x8080063C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_30:
    // 0x80800640: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800644: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800648: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080064C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800650: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800654: jal         0x800EEAD4
    // 0x80800658: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
    func_800EEAD4(rdram, ctx);
        goto after_31;
    // 0x80800658: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
    after_31:
    // 0x8080065C: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800660: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800664: nop

    // 0x80800668: bc1fl       L_80800694
    if (!c1cs) {
        // 0x8080066C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800694;
    }
    goto skip_6;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x80800670: div.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X1938) << 16);
    // 0x80800678: lwc1        $f16, 0x1938($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1812, 0X1938));
    // 0x8080067C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800680: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800684: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800688: jal         0x800EF334
    // 0x8080068C: nop

    func_800EF334(rdram, ctx);
        goto after_32;
    // 0x8080068C: nop

    after_32:
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800694:
    // 0x80800694: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800698: jal         0x800EFDE8
    // 0x8080069C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_800EFDE8(rdram, ctx);
        goto after_33;
    // 0x8080069C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_33:
    // 0x808006A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X193C) << 16);
    // 0x808006A4: lwc1        $f18, 0x193C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1812, 0X193C));
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: mul.s       $f6, $f20, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x808006B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808006B4: jal         0x800EF368
    // 0x808006B8: nop

    func_800EF368(rdram, ctx);
        goto after_34;
    // 0x808006B8: nop

    after_34:
    // 0x808006BC: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808006C0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808006C4: jal         0x800EF334
    // 0x808006C8: addiu       $a0, $s1, 0x30
    ctx->r4 = ADD32(ctx->r17, 0X30);
    func_800EF334(rdram, ctx);
        goto after_35;
    // 0x808006C8: addiu       $a0, $s1, 0x30
    ctx->r4 = ADD32(ctx->r17, 0X30);
    after_35:
    // 0x808006CC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808006D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006D4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x808006D8: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x808006DC: nop

    // 0x808006E0: bc1fl       L_80800744
    if (!c1cs) {
        // 0x808006E4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800744;
    }
    goto skip_7;
    // 0x808006E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_7:
    // 0x808006E8: b           L_80800740
    // 0x808006EC: sb          $t4, 0x5C($s1)
    MEM_B(0X5C, ctx->r17) = ctx->r12;
        goto L_80800740;
    // 0x808006EC: sb          $t4, 0x5C($s1)
    MEM_B(0X5C, ctx->r17) = ctx->r12;
L_808006F0:
    // 0x808006F0: lwc1        $f0, 0x1940($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1812, 0X1940));
    // 0x808006F4: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x808006F8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x808006FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800700: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800708: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8080070C: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800710: addiu       $s0, $s1, 0x30
    ctx->r16 = ADD32(ctx->r17, 0X30);
    // 0x80800714: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080071C: swc1        $f16, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f16.u32l;
    // 0x80800720: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x80800724: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x80800728: jal         0x800EF04C
    // 0x8080072C: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    func_800EF04C(rdram, ctx);
        goto after_36;
    // 0x8080072C: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_36:
    // 0x80800730: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80800734: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80800738: jal         0x800EF334
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_37;
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
L_80800740:
    // 0x80800740: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800744:
    // 0x80800744: jal         0x800EF04C
    // 0x80800748: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_38;
    // 0x80800748: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_38:
    // 0x8080074C: lw          $v1, 0x6C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X6C);
    // 0x80800750: andi        $t5, $v1, 0x1FF
    ctx->r13 = ctx->r3 & 0X1FF;
    // 0x80800754: b           L_80800778
    // 0x80800758: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
        goto L_80800778;
    // 0x80800758: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8080075C:
    // 0x8080075C: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x80800760: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800764: b           L_80800778
    // 0x80800768: sw          $t7, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r15;
        goto L_80800778;
    // 0x80800768: sw          $t7, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r15;
L_8080076C:
    // 0x8080076C: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x80800770: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800774: sw          $t9, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r25;
L_80800778:
    // 0x80800778: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_8080077C:
    // 0x8080077C: sltu        $at, $fp, $v1
    ctx->r1 = ctx->r30 < ctx->r3 ? 1 : 0;
    // 0x80800780: bne         $at, $zero, L_80800474
    if (ctx->r1 != 0) {
        // 0x80800784: addiu       $s1, $s1, 0x60
        ctx->r17 = ADD32(ctx->r17, 0X60);
            goto L_80800474;
    }
    // 0x80800784: addiu       $s1, $s1, 0x60
    ctx->r17 = ADD32(ctx->r17, 0X60);
L_80800788:
    // 0x80800788: lw          $t0, 0xF0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF0);
    // 0x8080078C: bne         $t0, $zero, L_808007A4
    if (ctx->r8 != 0) {
        // 0x80800790: nop
    
            goto L_808007A4;
    }
    // 0x80800790: nop

    // 0x80800794: jal         0x80089CA8
    // 0x80800798: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_39;
    // 0x80800798: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_39:
    // 0x8080079C: b           L_808007D0
    // 0x808007A0: nop

        goto L_808007D0;
    // 0x808007A0: nop

L_808007A4:
    // 0x808007A4: jal         0x800D8FF8
    // 0x808007A8: nop

    func_800D8FF8(rdram, ctx);
        goto after_40;
    // 0x808007A8: nop

    after_40:
    // 0x808007AC: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808007B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007B4: lwc1        $f18, 0x34($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X34);
    // 0x808007B8: lwc1        $f8, 0x24($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X24);
    // 0x808007BC: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808007C0: nop

    // 0x808007C4: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x808007C8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808007CC: swc1        $f10, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->f10.u32l;
L_808007D0:
    // 0x808007D0: jal         0x800D8FF8
    // 0x808007D4: nop

    func_800D8FF8(rdram, ctx);
        goto after_41;
    // 0x808007D4: nop

    after_41:
    // 0x808007D8: lwc1        $f16, 0x50($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X50);
    // 0x808007DC: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x808007E0: swc1        $f4, 0x50($s7)
    MEM_W(0X50, ctx->r23) = ctx->f4.u32l;
    // 0x808007E4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x808007E8: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x808007EC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x808007F0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x808007F4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x808007F8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x808007FC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800800: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800804: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800808: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8080080C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800810: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800814: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800818: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080081C: jr          $ra
    // 0x80800820: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80800820: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_8080146C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080146C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801474: jal         0x808002D4
    // 0x80801478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080147C: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80801480: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801488: jal         0x8008CCBC
    // 0x8080148C: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x8080148C: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    after_1:
    // 0x80801490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801494: jal         0x800845D8
    // 0x80801498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80801498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080149C: jal         0x80801178
    // 0x808014A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801178_bsbansack(rdram, ctx);
        goto after_3;
    // 0x808014A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808014A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014AC: jr          $ra
    // 0x808014B0: nop

    return;
    // 0x808014B0: nop

;}
RECOMP_FUNC void func_800D54F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D54F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D54F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D54F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D54FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D5500: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800D5504: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800D5508: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D550C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D5510: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D5514: addiu       $s3, $s3, -0x4808
    ctx->r19 = ADD32(ctx->r19, -0X4808);
    // 0x800D5518: addiu       $s2, $s2, -0x4810
    ctx->r18 = ADD32(ctx->r18, -0X4810);
L_800D551C:
    // 0x800D551C: jal         0x800B296C
    // 0x800D5520: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    vector_end(rdram, ctx);
        goto after_0;
    // 0x800D5520: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x800D5524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D5528: jal         0x800B28C4
    // 0x800D552C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800D552C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x800D5530: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x800D5534: beq         $at, $zero, L_800D5564
    if (ctx->r1 == 0) {
        // 0x800D5538: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D5564;
    }
    // 0x800D5538: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D553C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800D5540: beql        $s1, $t6, L_800D5568
    if (ctx->r17 == ctx->r14) {
        // 0x800D5544: sltu        $at, $v1, $s0
        ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
            goto L_800D5568;
    }
    goto skip_0;
    // 0x800D5544: sltu        $at, $v1, $s0
    ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
    skip_0:
    // 0x800D5548: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800D554C:
    // 0x800D554C: sltu        $at, $v1, $s0
    ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x800D5550: beql        $at, $zero, L_800D5568
    if (ctx->r1 == 0) {
        // 0x800D5554: sltu        $at, $v1, $s0
        ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
            goto L_800D5568;
    }
    goto skip_1;
    // 0x800D5554: sltu        $at, $v1, $s0
    ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
    skip_1:
    // 0x800D5558: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800D555C: bnel        $s1, $t7, L_800D554C
    if (ctx->r17 != ctx->r15) {
        // 0x800D5560: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800D554C;
    }
    goto skip_2;
    // 0x800D5560: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_2:
L_800D5564:
    // 0x800D5564: sltu        $at, $v1, $s0
    ctx->r1 = ctx->r3 < ctx->r16 ? 1 : 0;
L_800D5568:
    // 0x800D5568: beq         $at, $zero, L_800D5578
    if (ctx->r1 == 0) {
        // 0x800D556C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800D5578;
    }
    // 0x800D556C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800D5570: b           L_800D5584
    // 0x800D5574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D5584;
    // 0x800D5574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D5578:
    // 0x800D5578: bne         $s2, $s3, L_800D551C
    if (ctx->r18 != ctx->r19) {
        // 0x800D557C: nop
    
            goto L_800D551C;
    }
    // 0x800D557C: nop

    // 0x800D5580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D5584:
    // 0x800D5584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D5588: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D558C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D5590: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5594: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D5598: jr          $ra
    // 0x800D559C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D559C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _gccubeDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C60: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C60);
    return;
    // 0x80087C64: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chjigsaw_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800748: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(704, 0X7B8) << 16);
    // 0x8080074C: jr          $ra
    // 0x80800750: addiu       $v0, $v0, 0x7B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(704, 0X7B8));
    return;
    // 0x80800750: addiu       $v0, $v0, 0x7B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(704, 0X7B8));
    // 0x80800754: nop

    // 0x80800758: nop

    // 0x8080075C: nop

;}
RECOMP_FUNC void _basudie_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085248: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085248);
    return;
    // 0x8008524C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bskazspring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083600: syscall     69
    recomp_syscall_handler(rdram, ctx, 0x80083600);
    return;
    // 0x80083604: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CE1A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE1A8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800CE1AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CE1B0: lwc1        $f8, 0x59B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X59B0);
    // 0x800CE1B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE1B8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800CE1BC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800CE1C0: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800CE1C4: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800CE1C8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800CE1CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800CE1D0: subu        $a3, $t1, $t2
    ctx->r7 = SUB32(ctx->r9, ctx->r10);
    // 0x800CE1D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CE1D8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800CE1DC: nop

    // 0x800CE1E0: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x800CE1E4: addu        $t0, $v1, $a3
    ctx->r8 = ADD32(ctx->r3, ctx->r7);
    // 0x800CE1E8: bltz        $t0, L_800CE1FC
    if (SIGNED(ctx->r8) < 0) {
        // 0x800CE1EC: sll         $a1, $v0, 1
        ctx->r5 = S32(ctx->r2 << 1);
            goto L_800CE1FC;
    }
    // 0x800CE1EC: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x800CE1F0: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CE1F4: beq         $at, $zero, L_800CE204
    if (ctx->r1 == 0) {
        // 0x800CE1F8: subu        $a0, $v1, $a3
        ctx->r4 = SUB32(ctx->r3, ctx->r7);
            goto L_800CE204;
    }
    // 0x800CE1F8: subu        $a0, $v1, $a3
    ctx->r4 = SUB32(ctx->r3, ctx->r7);
L_800CE1FC:
    // 0x800CE1FC: jr          $ra
    // 0x800CE200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE204:
    // 0x800CE204: slt         $v0, $zero, $a0
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CE208: beq         $v0, $zero, L_800CE214
    if (ctx->r2 == 0) {
        // 0x800CE20C: nop
    
            goto L_800CE214;
    }
    // 0x800CE20C: nop

    // 0x800CE210: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_800CE214:
    // 0x800CE214: jr          $ra
    // 0x800CE218: nop

    return;
    // 0x800CE218: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C78: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C78);
    return;
    // 0x80082C7C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void bawobble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800E488C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E488C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E4890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E4894: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E4898: jal         0x800E4730
    // 0x800E489C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800E4730(rdram, ctx);
        goto after_0;
    // 0x800E489C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800E48A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E48A4: bne         $v0, $at, L_800E4900
    if (ctx->r2 != ctx->r1) {
        // 0x800E48A8: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_800E4900;
    }
    // 0x800E48A8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800E48AC: jal         0x800E47CC
    // 0x800E48B0: nop

    func_800E47CC(rdram, ctx);
        goto after_1;
    // 0x800E48B0: nop

    after_1:
    // 0x800E48B4: bgez        $v0, L_800E48C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E48B8: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_800E48C4;
    }
    // 0x800E48B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800E48BC: b           L_800E4ADC
    // 0x800E48C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4ADC;
    // 0x800E48C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E48C4:
    // 0x800E48C4: jal         0x8001ACCC
    // 0x800E48C8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x800E48C8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_2:
    // 0x800E48CC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800E48D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E48D4: addiu       $t8, $t8, -0x2AA0
    ctx->r24 = ADD32(ctx->r24, -0X2AA0);
    // 0x800E48D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E48DC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800E48E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800E48E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E48E8: sb          $t9, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r25;
    // 0x800E48EC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800E48F0: addiu       $t1, $zero, 0x9C4
    ctx->r9 = ADD32(0, 0X9C4);
    // 0x800E48F4: sh          $s0, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r16;
    // 0x800E48F8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800E48FC: sh          $t1, 0x3C($t2)
    MEM_H(0X3C, ctx->r10) = ctx->r9;
L_800E4900:
    // 0x800E4900: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800E4904: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E4908: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800E490C: addu        $s0, $s0, $t4
    ctx->r16 = ADD32(ctx->r16, ctx->r12);
    // 0x800E4910: lw          $s0, -0x2AA0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2AA0);
    // 0x800E4914: lbu         $v0, 0x38($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X38);
    // 0x800E4918: bne         $v0, $zero, L_800E4928
    if (ctx->r2 != 0) {
        // 0x800E491C: sltiu       $at, $v0, 0x5
        ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
            goto L_800E4928;
    }
    // 0x800E491C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800E4920: b           L_800E4ADC
    // 0x800E4924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E4ADC;
    // 0x800E4924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E4928:
    // 0x800E4928: beq         $at, $zero, L_800E4AD8
    if (ctx->r1 == 0) {
        // 0x800E492C: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_800E4AD8;
    }
    // 0x800E492C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800E4930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E4934: addu        $at, $at, $t5
    gpr jr_addend_800E493C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800E4938: lw          $t5, 0x5DA0($at)
    ctx->r13 = ADD32(ctx->r1, 0X5DA0);
    // 0x800E493C: jr          $t5
    // 0x800E4940: nop

    switch (jr_addend_800E493C >> 2) {
        case 0: goto L_800E4AD0; break;
        case 1: goto L_800E4944; break;
        case 2: goto L_800E49DC; break;
        case 3: goto L_800E4A50; break;
        case 4: goto L_800E4A6C; break;
        default: switch_error(__func__, 0x800E493C, 0x80125DA0);
    }
    // 0x800E4940: nop

L_800E4944:
    // 0x800E4944: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x800E4948: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800E494C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800E4950: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800E4954: jal         0x8001ACCC
    // 0x800E4958: addiu       $a0, $zero, 0x2800
    ctx->r4 = ADD32(0, 0X2800);
    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x800E4958: addiu       $a0, $zero, 0x2800
    ctx->r4 = ADD32(0, 0X2800);
    after_3:
    // 0x800E495C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x800E4960: jal         0x800D5A6C
    // 0x800E4964: lh          $a0, 0x3A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X3A);
    func_800D5A6C(rdram, ctx);
        goto after_4;
    // 0x800E4964: lh          $a0, 0x3A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X3A);
    after_4:
    // 0x800E4968: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800E496C: jal         0x8001ACCC
    // 0x800E4970: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    heap_alloc(rdram, ctx);
        goto after_5;
    // 0x800E4970: addiu       $a0, $zero, 0x1800
    ctx->r4 = ADD32(0, 0X1800);
    after_5:
    // 0x800E4974: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800E4978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E497C: jal         0x8001311C
    // 0x800E4980: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_6;
    // 0x800E4980: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_6:
    // 0x800E4984: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800E4988: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800E498C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800E4990: addiu       $t7, $t6, 0x1800
    ctx->r15 = ADD32(ctx->r14, 0X1800);
    // 0x800E4994: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x800E4998: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800E499C: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800E49A0: srl         $t9, $a0, 16
    ctx->r25 = S32(U32(ctx->r4) >> 16);
    // 0x800E49A4: jal         0x8001ACCC
    // 0x800E49A8: sll         $a0, $t9, 4
    ctx->r4 = S32(ctx->r25 << 4);
    heap_alloc(rdram, ctx);
        goto after_7;
    // 0x800E49A8: sll         $a0, $t9, 4
    ctx->r4 = S32(ctx->r25 << 4);
    after_7:
    // 0x800E49AC: bne         $v0, $zero, L_800E49C4
    if (ctx->r2 != 0) {
        // 0x800E49B0: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_800E49C4;
    }
    // 0x800E49B0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800E49B4: jal         0x800E4B1C
    // 0x800E49B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800E4B1C(rdram, ctx);
        goto after_8;
    // 0x800E49B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x800E49BC: b           L_800E4ADC
    // 0x800E49C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4ADC;
    // 0x800E49C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E49C4:
    // 0x800E49C4: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x800E49C8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800E49CC: sb          $t3, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r11;
    // 0x800E49D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E49D4: b           L_800E4ADC
    // 0x800E49D8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
        goto L_800E4ADC;
    // 0x800E49D8: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
L_800E49DC:
    // 0x800E49DC: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800E49E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800E49E4: jal         0x800E4D28
    // 0x800E49E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E4D28(rdram, ctx);
        goto after_9;
    // 0x800E49E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800E49EC: beq         $v0, $zero, L_800E4A20
    if (ctx->r2 == 0) {
        // 0x800E49F0: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800E4A20;
    }
    // 0x800E49F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800E49F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E49F8: beq         $v0, $at, L_800E4A38
    if (ctx->r2 == ctx->r1) {
        // 0x800E49FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800E4A38;
    }
    // 0x800E49FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E4A00: bne         $v0, $at, L_800E4A48
    if (ctx->r2 != ctx->r1) {
        // 0x800E4A04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E4A48;
    }
    // 0x800E4A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E4A08: jal         0x800E5EC0
    // 0x800E4A0C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800E5EC0(rdram, ctx);
        goto after_10;
    // 0x800E4A0C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x800E4A10: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800E4A14: sb          $t4, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r12;
    // 0x800E4A18: b           L_800E4ADC
    // 0x800E4A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4ADC;
    // 0x800E4A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4A20:
    // 0x800E4A20: jal         0x800E6728
    // 0x800E4A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E6728(rdram, ctx);
        goto after_11;
    // 0x800E4A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800E4A28: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800E4A2C: sb          $t5, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r13;
    // 0x800E4A30: b           L_800E4ADC
    // 0x800E4A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4ADC;
    // 0x800E4A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4A38:
    // 0x800E4A38: jal         0x800E659C
    // 0x800E4A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E659C(rdram, ctx);
        goto after_12;
    // 0x800E4A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800E4A40: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800E4A44: sb          $t6, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r14;
L_800E4A48:
    // 0x800E4A48: b           L_800E4ADC
    // 0x800E4A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4ADC;
    // 0x800E4A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4A50:
    // 0x800E4A50: jal         0x800E4E54
    // 0x800E4A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E4E54(rdram, ctx);
        goto after_13;
    // 0x800E4A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800E4A58: bne         $v0, $zero, L_800E4A64
    if (ctx->r2 != 0) {
        // 0x800E4A5C: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_800E4A64;
    }
    // 0x800E4A5C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800E4A60: sb          $t7, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r15;
L_800E4A64:
    // 0x800E4A64: b           L_800E4ADC
    // 0x800E4A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4ADC;
    // 0x800E4A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4A6C:
    // 0x800E4A6C: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x800E4A70: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800E4A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E4A78: beq         $t8, $zero, L_800E4AC8
    if (ctx->r24 == 0) {
        // 0x800E4A7C: nop
    
            goto L_800E4AC8;
    }
    // 0x800E4A7C: nop

    // 0x800E4A80: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x800E4A84: beql        $a0, $zero, L_800E4A9C
    if (ctx->r4 == 0) {
        // 0x800E4A88: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800E4A9C;
    }
    goto skip_0;
    // 0x800E4A88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800E4A8C: jal         0x8001B084
    // 0x800E4A90: nop

    heap_free(rdram, ctx);
        goto after_14;
    // 0x800E4A90: nop

    after_14:
    // 0x800E4A94: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800E4A98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800E4A9C:
    // 0x800E4A9C: beql        $a0, $zero, L_800E4AB4
    if (ctx->r4 == 0) {
        // 0x800E4AA0: sb          $zero, 0x38($s0)
        MEM_B(0X38, ctx->r16) = 0;
            goto L_800E4AB4;
    }
    goto skip_1;
    // 0x800E4AA0: sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
    skip_1:
    // 0x800E4AA4: jal         0x8001B084
    // 0x800E4AA8: nop

    heap_free(rdram, ctx);
        goto after_15;
    // 0x800E4AA8: nop

    after_15:
    // 0x800E4AAC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800E4AB0: sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
L_800E4AB4:
    // 0x800E4AB4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x800E4AB8: jal         0x8002E660
    // 0x800E4ABC: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_16;
    // 0x800E4ABC: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    after_16:
    // 0x800E4AC0: b           L_800E4ADC
    // 0x800E4AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E4ADC;
    // 0x800E4AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E4AC8:
    // 0x800E4AC8: b           L_800E4ADC
    // 0x800E4ACC: sb          $t9, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r25;
        goto L_800E4ADC;
    // 0x800E4ACC: sb          $t9, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r25;
L_800E4AD0:
    // 0x800E4AD0: b           L_800E4ADC
    // 0x800E4AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E4ADC;
    // 0x800E4AD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E4AD8:
    // 0x800E4AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4ADC:
    // 0x800E4ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4AE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E4AE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E4AE8: jr          $ra
    // 0x800E4AEC: nop

    return;
    // 0x800E4AEC: nop

;}
RECOMP_FUNC void func_808000D0_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: jr          $ra
    // 0x808000D4: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x808000D4: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void bainput_func_80097E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097E7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097E80: jal         0x800919F4
    // 0x80097E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_0;
    // 0x80097E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80097E88: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097E8C: beq         $t6, $zero, L_80097EB8
    if (ctx->r14 == 0) {
        // 0x80097E90: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097EB8;
    }
    // 0x80097E90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097E94: jal         0x800C6E38
    // 0x80097E98: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x80097E98: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_1:
    // 0x80097E9C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097EA0: beq         $t7, $zero, L_80097EB8
    if (ctx->r15 == 0) {
        // 0x80097EA4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80097EB8;
    }
    // 0x80097EA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80097EA8: jal         0x8008E39C
    // 0x80097EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E39C(rdram, ctx);
        goto after_2;
    // 0x80097EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80097EB0: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80097EB4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80097EB8:
    // 0x80097EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097EC0: jr          $ra
    // 0x80097EC4: nop

    return;
    // 0x80097EC4: nop

;}
RECOMP_FUNC void func_800CAD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAD9C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800CADA0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CADA4: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800CADA8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CADAC: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800CADB0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CADB4: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CADB8: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800CADBC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CADC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CADC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CADC8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800CADCC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CADD0: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800CADD4: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800CADD8: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CADDC: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800CADE0: nop

    // 0x800CADE4: bc1f        L_800CAE9C
    if (!c1cs) {
        // 0x800CADE8: nop
    
            goto L_800CAE9C;
    }
    // 0x800CADE8: nop

    // 0x800CADEC: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800CADF0: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800CADF4: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800CADF8: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800CADFC: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800CAE00: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800CAE04: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800CAE08: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800CAE0C: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800CAE10: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CAE14: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800CAE18: nop

    // 0x800CAE1C: bc1f        L_800CAE9C
    if (!c1cs) {
        // 0x800CAE20: nop
    
            goto L_800CAE9C;
    }
    // 0x800CAE20: nop

    // 0x800CAE24: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800CAE28: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800CAE2C: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800CAE30: lwc1        $f18, 0x4C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800CAE34: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CAE38: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800CAE3C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800CAE40: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800CAE44: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800CAE48: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CAE4C: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800CAE50: nop

    // 0x800CAE54: bc1f        L_800CAE9C
    if (!c1cs) {
        // 0x800CAE58: nop
    
            goto L_800CAE9C;
    }
    // 0x800CAE58: nop

    // 0x800CAE5C: lwc1        $f16, 0x54($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800CAE60: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800CAE64: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800CAE68: lwc1        $f16, 0x5C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800CAE6C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CAE70: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CAE74: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800CAE78: lwc1        $f10, 0x60($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800CAE7C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800CAE80: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CAE84: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800CAE88: nop

    // 0x800CAE8C: bc1f        L_800CAE9C
    if (!c1cs) {
        // 0x800CAE90: nop
    
            goto L_800CAE9C;
    }
    // 0x800CAE90: nop

    // 0x800CAE94: jr          $ra
    // 0x800CAE98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CAE98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CAE9C:
    // 0x800CAE9C: jr          $ra
    // 0x800CAEA0: nop

    return;
    // 0x800CAEA0: nop

;}
RECOMP_FUNC void func_808006A0_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006B0: jal         0x80100094
    // 0x808006B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006B8: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808006BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808006C4: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808006C8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808006CC: bgez        $t7, L_808006E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808006D0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808006E0;
    }
    // 0x808006D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006D8: nop

    // 0x808006DC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808006E0:
    // 0x808006E0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x808006E4: jal         0x8008A098
    // 0x808006E8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808006E8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x808006EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808006F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808006FC: blez        $t8, L_80800734
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800700: nop
    
            goto L_80800734;
    }
    // 0x80800700: nop

    // 0x80800704: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800708: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8080070C: lbu         $t9, 0x15($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X15);
L_80800710:
    // 0x80800710: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80800714: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800718: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x8080071C: sb          $t0, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r8;
    // 0x80800720: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80800724: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80800728: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8080072C: bnel        $at, $zero, L_80800710
    if (ctx->r1 != 0) {
        // 0x80800730: lbu         $t9, 0x15($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X15);
            goto L_80800710;
    }
    goto skip_0;
    // 0x80800730: lbu         $t9, 0x15($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X15);
    skip_0:
L_80800734:
    // 0x80800734: jal         0x80101FDC
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080073C: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    // 0x80800740: jal         0x800D2770
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_3;
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800748: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080074C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800750: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800754: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800758: andi        $t2, $a0, 0x1FF
    ctx->r10 = ctx->r4 & 0X1FF;
    // 0x8080075C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80800760: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800764: jal         0x800CE8D8
    // 0x80800768: nop

    func_800CE8D8(rdram, ctx);
        goto after_4;
    // 0x80800768: nop

    after_4:
    // 0x8080076C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800774: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x80800778: jal         0x800CE88C
    // 0x8080077C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800CE88C(rdram, ctx);
        goto after_5;
    // 0x8080077C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x80800780: jal         0x800DA524
    // 0x80800784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800788: jal         0x800FDC28
    // 0x8080078C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_7;
    // 0x8080078C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_7:
    // 0x80800790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800794: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800798: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080079C: jr          $ra
    // 0x808007A0: nop

    return;
    // 0x808007A0: nop

;}
RECOMP_FUNC void func_80016B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B78: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80016B7C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80016B80: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80016B84: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80016B88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80016B8C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016B90: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80016B94: jr          $ra
    // 0x80016B98: lw          $v0, -0x65FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65FC);
    return;
    // 0x80016B98: lw          $v0, -0x65FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65FC);
;}
RECOMP_FUNC void func_800B38E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B38E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B38EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B38F0: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800B38F4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x800B38F8: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x800B38FC: addiu       $t8, $t7, -0x18
    ctx->r24 = ADD32(ctx->r15, -0X18);
    // 0x800B3900: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800B3904: mflo        $t9
    ctx->r25 = lo;
    // 0x800B3908: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B390C: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
    // 0x800B3910: bne         $v0, $zero, L_800B391C
    if (ctx->r2 != 0) {
        // 0x800B3914: nop
    
            goto L_800B391C;
    }
    // 0x800B3914: nop

    // 0x800B3918: break       7
    do_break(2148219160);
L_800B391C:
    // 0x800B391C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3920: bne         $v0, $at, L_800B3934
    if (ctx->r2 != ctx->r1) {
        // 0x800B3924: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3934;
    }
    // 0x800B3924: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3928: bne         $t8, $at, L_800B3934
    if (ctx->r24 != ctx->r1) {
        // 0x800B392C: nop
    
            goto L_800B3934;
    }
    // 0x800B392C: nop

    // 0x800B3930: break       6
    do_break(2148219184);
L_800B3934:
    // 0x800B3934: subu        $t1, $t0, $a0
    ctx->r9 = SUB32(ctx->r8, ctx->r4);
    // 0x800B3938: addiu       $t2, $t1, -0x18
    ctx->r10 = ADD32(ctx->r9, -0X18);
    // 0x800B393C: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800B3940: mflo        $t3
    ctx->r11 = lo;
    // 0x800B3944: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800B3948: bne         $v0, $zero, L_800B3954
    if (ctx->r2 != 0) {
        // 0x800B394C: nop
    
            goto L_800B3954;
    }
    // 0x800B394C: nop

    // 0x800B3950: break       7
    do_break(2148219216);
L_800B3954:
    // 0x800B3954: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3958: bne         $v0, $at, L_800B396C
    if (ctx->r2 != ctx->r1) {
        // 0x800B395C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B396C;
    }
    // 0x800B395C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3960: bne         $t2, $at, L_800B396C
    if (ctx->r10 != ctx->r1) {
        // 0x800B3964: nop
    
            goto L_800B396C;
    }
    // 0x800B3964: nop

    // 0x800B3968: break       6
    do_break(2148219240);
L_800B396C:
    // 0x800B396C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B3970: jal         0x8001BAFC
    // 0x800B3974: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800B3974: nop

    after_0:
    // 0x800B3978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B397C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3980: beq         $v0, $a0, L_800B39B8
    if (ctx->r2 == ctx->r4) {
        // 0x800B3984: addiu       $v1, $zero, 0x1C
        ctx->r3 = ADD32(0, 0X1C);
            goto L_800B39B8;
    }
    // 0x800B3984: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // 0x800B3988: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B398C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B3990: mflo        $t5
    ctx->r13 = lo;
    // 0x800B3994: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800B3998: addiu       $t7, $t6, 0x18
    ctx->r15 = ADD32(ctx->r14, 0X18);
    // 0x800B399C: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x800B39A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B39A4: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B39A8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B39AC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800B39B0: addiu       $t1, $t0, 0x18
    ctx->r9 = ADD32(ctx->r8, 0X18);
    // 0x800B39B4: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
L_800B39B8:
    // 0x800B39B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B39BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B39C0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B39C4: jr          $ra
    // 0x800B39C8: nop

    return;
    // 0x800B39C8: nop

    // 0x800B39CC: nop

;}
RECOMP_FUNC void func_8080111C_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080111C: lh          $v1, 0x4E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4E);
    // 0x80801120: lbu         $t8, 0x51($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X51);
    // 0x80801124: addiu       $t6, $zero, 0x5C
    ctx->r14 = ADD32(0, 0X5C);
    // 0x80801128: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8080112C: addiu       $v0, $t7, 0x5C
    ctx->r2 = ADD32(ctx->r15, 0X5C);
    // 0x80801130: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
    // 0x80801134: sh          $t6, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r14;
    // 0x80801138: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8080113C: blez        $t8, L_8080117C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80801140: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080117C;
    }
    // 0x80801140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801144: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80801148: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080114C: sh          $v0, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r2;
L_80801150:
    // 0x80801150: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
    // 0x80801154: lbu         $t1, 0x51($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X51);
    // 0x80801158: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080115C: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801160: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80801164: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80801168: mflo        $t0
    ctx->r8 = lo;
    // 0x8080116C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80801170: bnel        $at, $zero, L_80801150
    if (ctx->r1 != 0) {
        // 0x80801174: sh          $v0, 0x36($v1)
        MEM_H(0X36, ctx->r3) = ctx->r2;
            goto L_80801150;
    }
    goto skip_0;
    // 0x80801174: sh          $v0, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r2;
    skip_0:
    // 0x80801178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080117C:
    // 0x8080117C: lbu         $t2, 0x52($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X52);
    // 0x80801180: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80801184: blez        $t2, L_808011B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80801188: nop
    
            goto L_808011B0;
    }
    // 0x80801188: nop

L_8080118C:
    // 0x8080118C: sh          $v0, 0x3E($v1)
    MEM_H(0X3E, ctx->r3) = ctx->r2;
    // 0x80801190: lbu         $t5, 0x52($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X52);
    // 0x80801194: lh          $t3, 0x4E($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4E);
    // 0x80801198: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080119C: slt         $at, $a1, $t5
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808011A0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808011A4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808011A8: bne         $at, $zero, L_8080118C
    if (ctx->r1 != 0) {
        // 0x808011AC: addu        $v0, $v0, $t4
        ctx->r2 = ADD32(ctx->r2, ctx->r12);
            goto L_8080118C;
    }
    // 0x808011AC: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
L_808011B0:
    // 0x808011B0: jr          $ra
    // 0x808011B4: sh          $v0, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r2;
    return;
    // 0x808011B4: sh          $v0, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void gspropsDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002A8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808002AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808002B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002B4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808002B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808002C0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808002C4: beq         $a0, $zero, L_808004C0
    if (ctx->r4 == 0) {
        // 0x808002C8: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_808004C0;
    }
    // 0x808002C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002CC: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x808002D0: beql        $t6, $zero, L_808004C4
    if (ctx->r14 == 0) {
        // 0x808002D4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808004C4;
    }
    goto skip_0;
    // 0x808002D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x808002D8: jal         0x800E9D68
    // 0x808002DC: nop

    func_800E9D68(rdram, ctx);
        goto after_0;
    // 0x808002DC: nop

    after_0:
    // 0x808002E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002E4: jal         0x800E9D90
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E9D90(rdram, ctx);
        goto after_1;
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808002EC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x808002F0: beq         $at, $zero, L_808004C0
    if (ctx->r1 == 0) {
        // 0x808002F4: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_808004C0;
    }
    // 0x808002F4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808002F8: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x808002FC: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80800300: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_80800304:
    // 0x80800304: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800308: sll         $t8, $t7, 25
    ctx->r24 = S32(ctx->r15 << 25);
    // 0x8080030C: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x80800310: bne         $t9, $at, L_808003B4
    if (ctx->r25 != ctx->r1) {
        // 0x80800314: nop
    
            goto L_808003B4;
    }
    // 0x80800314: nop

    // 0x80800318: beq         $s3, $zero, L_80800328
    if (ctx->r19 == 0) {
        // 0x8080031C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800328;
    }
    // 0x8080031C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800320: b           L_80800328
    // 0x80800324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80800328;
    // 0x80800324: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800328:
    // 0x80800328: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8080032C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800334: sll         $t0, $v0, 25
    ctx->r8 = S32(ctx->r2 << 25);
    // 0x80800338: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x8080033C: beq         $t1, $zero, L_8080034C
    if (ctx->r9 == 0) {
        // 0x80800340: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_8080034C;
    }
    // 0x80800340: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80800344: b           L_8080034C
    // 0x80800348: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x80800348: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080034C:
    // 0x8080034C: bne         $v1, $a0, L_808003B4
    if (ctx->r3 != ctx->r4) {
        // 0x80800350: sll         $t6, $v0, 26
        ctx->r14 = S32(ctx->r2 << 26);
            goto L_808003B4;
    }
    // 0x80800350: sll         $t6, $v0, 26
    ctx->r14 = S32(ctx->r2 << 26);
    // 0x80800354: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x80800358: lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6);
    // 0x8080035C: sll         $t8, $v0, 22
    ctx->r24 = S32(ctx->r2 << 22);
    // 0x80800360: srl         $t4, $t3, 23
    ctx->r12 = S32(U32(ctx->r11) >> 23);
    // 0x80800364: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800368: srl         $t2, $a2, 7
    ctx->r10 = S32(U32(ctx->r6) >> 7);
    // 0x8080036C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80800370: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80800374: srl         $t7, $v0, 21
    ctx->r15 = S32(U32(ctx->r2) >> 21);
    // 0x80800378: mflo        $a3
    ctx->r7 = lo;
    // 0x8080037C: bne         $a3, $zero, L_80800388
    if (ctx->r7 != 0) {
        // 0x80800380: nop
    
            goto L_80800388;
    }
    // 0x80800380: nop

    // 0x80800384: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80800388:
    // 0x80800388: bgezl       $t6, L_808003A4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080038C: lhu         $a0, 0x8($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X8);
            goto L_808003A4;
    }
    goto skip_1;
    // 0x8080038C: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    skip_1:
    // 0x80800390: multu       $a2, $s2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800394: mflo        $a2
    ctx->r6 = lo;
    // 0x80800398: nop

    // 0x8080039C: nop

    // 0x808003A0: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
L_808003A4:
    // 0x808003A4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x808003A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808003AC: jal         0x800CBA68
    // 0x808003B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800CBA68(rdram, ctx);
        goto after_2;
    // 0x808003B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
L_808003B4:
    // 0x808003B4: bnel        $s3, $zero, L_808004B4
    if (ctx->r19 != 0) {
        // 0x808003B8: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_808004B4;
    }
    goto skip_2;
    // 0x808003B8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_2:
    // 0x808003BC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x808003C0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x808003C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003C8: sll         $t1, $v0, 25
    ctx->r9 = S32(ctx->r2 << 25);
    // 0x808003CC: srl         $v0, $t1, 26
    ctx->r2 = S32(U32(ctx->r9) >> 26);
    // 0x808003D0: bnel        $v0, $at, L_8080043C
    if (ctx->r2 != ctx->r1) {
        // 0x808003D4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8080043C;
    }
    goto skip_3;
    // 0x808003D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_3:
    // 0x808003D8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x808003DC: lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6);
    // 0x808003E0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x808003E4: srl         $t5, $t4, 23
    ctx->r13 = S32(U32(ctx->r12) >> 23);
    // 0x808003E8: multu       $t5, $s1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003EC: srl         $t3, $a2, 7
    ctx->r11 = S32(U32(ctx->r6) >> 7);
    // 0x808003F0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x808003F4: sll         $t7, $v0, 26
    ctx->r15 = S32(ctx->r2 << 26);
    // 0x808003F8: andi        $a3, $v0, 0x3
    ctx->r7 = ctx->r2 & 0X3;
    // 0x808003FC: mflo        $v1
    ctx->r3 = lo;
    // 0x80800400: bne         $v1, $zero, L_8080040C
    if (ctx->r3 != 0) {
        // 0x80800404: nop
    
            goto L_8080040C;
    }
    // 0x80800404: nop

    // 0x80800408: addiu       $v1, $zero, 0x12C
    ctx->r3 = ADD32(0, 0X12C);
L_8080040C:
    // 0x8080040C: bgezl       $t7, L_80800428
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800410: lhu         $a0, 0x8($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X8);
            goto L_80800428;
    }
    goto skip_4;
    // 0x80800410: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    skip_4:
    // 0x80800414: multu       $a2, $s2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800418: mflo        $a2
    ctx->r6 = lo;
    // 0x8080041C: nop

    // 0x80800420: nop

    // 0x80800424: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
L_80800428:
    // 0x80800428: jal         0x800CBAC8
    // 0x8080042C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_800CBAC8(rdram, ctx);
        goto after_3;
    // 0x8080042C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800430: b           L_808004B4
    // 0x80800434: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
        goto L_808004B4;
    // 0x80800434: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800438: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_8080043C:
    // 0x8080043C: beq         $v0, $at, L_808004B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800440: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_808004B0;
    }
    // 0x80800440: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800444: bne         $v0, $at, L_808004B0
    if (ctx->r2 != ctx->r1) {
        // 0x80800448: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_808004B0;
    }
    // 0x80800448: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080044C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80800450: lhu         $a2, 0x6($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X6);
    // 0x80800454: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80800458: srl         $t1, $t9, 23
    ctx->r9 = S32(U32(ctx->r25) >> 23);
    // 0x8080045C: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800460: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x80800464: sll         $t5, $v0, 22
    ctx->r13 = S32(ctx->r2 << 22);
    // 0x80800468: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8080046C: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80800470: sll         $t3, $v0, 26
    ctx->r11 = S32(ctx->r2 << 26);
    // 0x80800474: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x80800478: mflo        $a3
    ctx->r7 = lo;
    // 0x8080047C: bne         $a3, $zero, L_80800488
    if (ctx->r7 != 0) {
        // 0x80800480: nop
    
            goto L_80800488;
    }
    // 0x80800480: nop

    // 0x80800484: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80800488:
    // 0x80800488: bgezl       $t3, L_808004A4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080048C: lhu         $a0, 0x8($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X8);
            goto L_808004A4;
    }
    goto skip_5;
    // 0x8080048C: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
    skip_5:
    // 0x80800490: multu       $a2, $s2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800494: mflo        $a2
    ctx->r6 = lo;
    // 0x80800498: nop

    // 0x8080049C: nop

    // 0x808004A0: lhu         $a0, 0x8($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X8);
L_808004A4:
    // 0x808004A4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808004A8: jal         0x800CBB18
    // 0x808004AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800CBB18(rdram, ctx);
        goto after_4;
    // 0x808004AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
L_808004B0:
    // 0x808004B0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_808004B4:
    // 0x808004B4: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x808004B8: bnel        $at, $zero, L_80800304
    if (ctx->r1 != 0) {
        // 0x808004BC: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_80800304;
    }
    goto skip_6;
    // 0x808004BC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_6:
L_808004C0:
    // 0x808004C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808004C4:
    // 0x808004C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808004C8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808004CC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808004D0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808004D4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808004D8: jr          $ra
    // 0x808004DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808004DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
