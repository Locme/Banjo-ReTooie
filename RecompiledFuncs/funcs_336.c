#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chbaddieDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808000AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000B0: lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X4);
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000BC: blezl       $v1, L_80800208
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808000C0: sb          $zero, 0x4($s0)
        MEM_B(0X4, ctx->r16) = 0;
            goto L_80800208;
    }
    goto skip_0;
    // 0x808000C0: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    skip_0:
    // 0x808000C4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_808000C8:
    // 0x808000C8: addu        $v0, $t6, $s1
    ctx->r2 = ADD32(ctx->r14, ctx->r17);
    // 0x808000CC: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x808000D0: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x808000D4: beq         $at, $zero, L_808001F0
    if (ctx->r1 == 0) {
        // 0x808000D8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808001F0;
    }
    // 0x808000D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(716, 0X220) << 16);
    // 0x808000E0: addu        $at, $at, $t7
    gpr jr_addend_808000E8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000E4: lw          $t7, 0x220($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(716, 0X220));
    // 0x808000E8: jr          $t7
    // 0x808000EC: nop

    switch (jr_addend_808000E8 >> 2) {
        case 0: goto L_808000F0; break;
        case 1: goto L_80800108; break;
        case 2: goto L_80800124; break;
        case 3: goto L_80800144; break;
        case 4: goto L_80800164; break;
        case 5: goto L_80800188; break;
        case 6: goto L_808001B8; break;
        default: switch_error(__func__, 0x808000E8, 0x80800220);
    }
    // 0x808000EC: nop

L_808000F0:
    // 0x808000F0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808000F4: jalr        $t9
    // 0x808000F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x808000F8: nop

    after_0:
    // 0x808000FC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x80800100: b           L_808001F4
    // 0x80800104: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800104: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800108:
    // 0x80800108: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8080010C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80800110: jalr        $t9
    // 0x80800114: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800114: nop

    after_1:
    // 0x80800118: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8080011C: b           L_808001F4
    // 0x80800120: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800120: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800124:
    // 0x80800124: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800128: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080012C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800130: jalr        $t9
    // 0x80800134: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800134: nop

    after_2:
    // 0x80800138: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8080013C: b           L_808001F4
    // 0x80800140: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800140: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800144:
    // 0x80800144: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800148: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080014C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800150: jalr        $t9
    // 0x80800154: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80800154: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_3:
    // 0x80800158: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x8080015C: b           L_808001F4
    // 0x80800160: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800160: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800164:
    // 0x80800164: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800168: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080016C: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800170: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800174: jalr        $t9
    // 0x80800178: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80800178: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    after_4:
    // 0x8080017C: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x80800180: b           L_808001F4
    // 0x80800184: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x80800184: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_80800188:
    // 0x80800188: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8080018C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80800190: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800194: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800198: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x8080019C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808001A0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808001A4: jalr        $t9
    // 0x808001A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x808001A8: nop

    after_5:
    // 0x808001AC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x808001B0: b           L_808001F4
    // 0x808001B4: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x808001B4: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_808001B8:
    // 0x808001B8: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x808001BC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x808001C0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x808001C4: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x808001C8: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x808001CC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808001D0: lw          $t1, 0x18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X18);
    // 0x808001D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808001D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808001DC: jalr        $t9
    // 0x808001E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x808001E0: nop

    after_6:
    // 0x808001E4: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x808001E8: b           L_808001F4
    // 0x808001EC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
        goto L_808001F4;
    // 0x808001EC: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_808001F0:
    // 0x808001F0: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
L_808001F4:
    // 0x808001F4: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x808001F8: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808001FC: bnel        $at, $zero, L_808000C8
    if (ctx->r1 != 0) {
        // 0x80800200: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_808000C8;
    }
    goto skip_1;
    // 0x80800200: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800204: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
L_80800208:
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080020C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800214: jr          $ra
    // 0x80800218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080021C: nop

;}
RECOMP_FUNC void func_8080025C_chLagoonInnBlockedWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800260: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800264: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80800270: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800278: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080027C: jal         0x800EE7F8
    // 0x80800280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800284: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800288: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080028C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800290: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3E8) << 16);
    // 0x80800294: lwc1        $f16, 0x3E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3E8));
    // 0x80800298: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080029C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2020, 0X528) << 16);
    // 0x808002A0: addiu       $t6, $t6, 0x528
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2020, 0X528));
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808002AC: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808002BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x808002C0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808002C4: jal         0x800BBCB8
    // 0x808002C8: nop

    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808002C8: nop

    after_1:
    // 0x808002CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3EC) << 16);
    // 0x808002D0: lwc1        $f6, 0x3EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3EC));
    // 0x808002D4: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002D8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2020, 0X4C8) << 16);
    // 0x808002DC: addiu       $t7, $t7, 0x4C8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2020, 0X4C8));
    // 0x808002E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808002E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002F0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808002F4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808002F8: jal         0x800BBCB8
    // 0x808002FC: nop

    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808002FC: nop

    after_2:
    // 0x80800300: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2020, 0X54C) << 16);
    // 0x80800304: addiu       $t8, $t8, 0x54C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2020, 0X54C));
    // 0x80800308: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080030C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800314: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800318: jal         0x800BBCB8
    // 0x8080031C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x8080031C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_3:
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2020, 0X3F0) << 16);
    // 0x80800324: lwc1        $f10, 0x3F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2020, 0X3F0));
    // 0x80800328: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8080032C: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80800330: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80800334: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80800338: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8080033C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800348: addiu       $a2, $zero, -0x28
    ctx->r6 = ADD32(0, -0X28);
    // 0x8080034C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80800350: jal         0x80109704
    // 0x80800354: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80109704(rdram, ctx);
        goto after_4;
    // 0x80800354: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800358: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2020, 0X514) << 16);
    // 0x8080035C: addiu       $a2, $a2, 0x514
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2020, 0X514));
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80089D18
    // 0x80800368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8080036C: jal         0x800FFAB0
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800374: addiu       $a0, $zero, 0x488
    ctx->r4 = ADD32(0, 0X488);
    // 0x80800378: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080037C: jal         0x80101180
    // 0x80800380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800384: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800388: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080038C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800390: jr          $ra
    // 0x80800394: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800394: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808000BC_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000D4: beq         $a1, $at, L_80800138
    if (ctx->r5 == ctx->r1) {
        // 0x808000D8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800138;
    }
    // 0x808000D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000E0: bnel        $a1, $at, L_8080014C
    if (ctx->r5 != ctx->r1) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080014C;
    }
    goto skip_0;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000E8: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x808000EC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808000F8: bne         $t8, $at, L_80800108
    if (ctx->r24 != ctx->r1) {
        // 0x808000FC: addiu       $v0, $zero, 0x7B8
        ctx->r2 = ADD32(0, 0X7B8);
            goto L_80800108;
    }
    // 0x808000FC: addiu       $v0, $zero, 0x7B8
    ctx->r2 = ADD32(0, 0X7B8);
    // 0x80800100: b           L_80800108
    // 0x80800104: addiu       $v0, $zero, 0x7B9
    ctx->r2 = ADD32(0, 0X7B9);
        goto L_80800108;
    // 0x80800104: addiu       $v0, $zero, 0x7B9
    ctx->r2 = ADD32(0, 0X7B9);
L_80800108:
    // 0x80800108: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8080010C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800110: jal         0x801032B0
    // 0x80800114: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_801032B0(rdram, ctx);
        goto after_0;
    // 0x80800114: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_0:
    // 0x80800118: jal         0x800DA298
    // 0x8080011C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080011C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_1:
    // 0x80800120: beq         $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800148;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80103110
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800130: b           L_8080014C
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080014C;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800138:
    // 0x80800138: addiu       $a0, $zero, 0x3D2
    ctx->r4 = ADD32(0, 0X3D2);
    // 0x8080013C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800140: jal         0x80101180
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80800148:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080014C:
    // 0x8080014C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800150: jal         0x80085820
    // 0x80800154: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800154: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void func_80800280_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800288: jal         0x800DA298
    // 0x8080028C: nop

    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080028C: nop

    after_0:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_80800DD0_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800DE4: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80800DE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800DEC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800DF0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800DF4: nop

    // 0x80800DF8: bc1tl       L_80800E4C
    if (c1cs) {
        // 0x80800DFC: lbu         $t8, 0x6($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X6);
            goto L_80800E4C;
    }
    goto skip_0;
    // 0x80800DFC: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    skip_0:
    // 0x80800E00: jal         0x800D8FF8
    // 0x80800E04: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800E04: nop

    after_0:
    // 0x80800E08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E0C: jal         0x800F1574
    // 0x80800E10: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x80800E10: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_1:
    // 0x80800E14: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x80800E18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800E1C: bnel        $t6, $zero, L_80800E34
    if (ctx->r14 != 0) {
        // 0x80800E20: lbu         $a0, 0x5($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X5);
            goto L_80800E34;
    }
    goto skip_1;
    // 0x80800E20: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    skip_1:
    // 0x80800E24: sb          $t7, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r15;
    // 0x80800E28: b           L_80800E70
    // 0x80800E2C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
        goto L_80800E70;
    // 0x80800E2C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x80800E30: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
L_80800E34:
    // 0x80800E34: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800E38: jal         0x800F1418
    // 0x80800E3C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    func_800F1418(rdram, ctx);
        goto after_2;
    // 0x80800E3C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
    // 0x80800E40: b           L_80800E70
    // 0x80800E44: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
        goto L_80800E70;
    // 0x80800E44: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // 0x80800E48: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
L_80800E4C:
    // 0x80800E4C: beql        $t8, $zero, L_80800E74
    if (ctx->r24 == 0) {
        // 0x80800E50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E74;
    }
    goto skip_2;
    // 0x80800E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800E54: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80800E58: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80800E5C: bne         $at, $zero, L_80800E6C
    if (ctx->r1 != 0) {
        // 0x80800E60: addiu       $t9, $v0, -0x20
        ctx->r25 = ADD32(ctx->r2, -0X20);
            goto L_80800E6C;
    }
    // 0x80800E60: addiu       $t9, $v0, -0x20
    ctx->r25 = ADD32(ctx->r2, -0X20);
    // 0x80800E64: b           L_80800E70
    // 0x80800E68: sb          $t9, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r25;
        goto L_80800E70;
    // 0x80800E68: sb          $t9, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r25;
L_80800E6C:
    // 0x80800E6C: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
L_80800E70:
    // 0x80800E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E74:
    // 0x80800E74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E7C: jr          $ra
    // 0x80800E80: nop

    return;
    // 0x80800E80: nop

;}
RECOMP_FUNC void sudeflect_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808004AC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808004B0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808004B4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x808004B8: addiu       $s1, $s1, 0x1020
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x808004BC: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x808004C0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808004C4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808004C8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808004CC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808004D0: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x808004D4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808004D8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808004DC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x808004E0: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x808004E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808004E8: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x808004EC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808004F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808004F4: beq         $t7, $zero, L_80800560
    if (ctx->r15 == 0) {
        // 0x808004F8: sw          $zero, 0x24($s1)
        MEM_W(0X24, ctx->r17) = 0;
            goto L_80800560;
    }
    // 0x808004F8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x808004FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800500: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
L_80800504:
    // 0x80800504: jal         0x800F6438
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080050C: beq         $v0, $zero, L_80800554
    if (ctx->r2 == 0) {
        // 0x80800510: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800554;
    }
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800518: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080051C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80800520: jal         0x800F4E5C
    // 0x80800524: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    func_800F4E5C(rdram, ctx);
        goto after_1;
    // 0x80800524: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_1:
    // 0x80800528: beql        $v0, $zero, L_80800558
    if (ctx->r2 == 0) {
        // 0x8080052C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800558;
    }
    goto skip_0;
    // 0x8080052C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800530: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x80800534: ori         $t3, $s2, 0x2
    ctx->r11 = ctx->r18 | 0X2;
    // 0x80800538: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x8080053C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800540: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80800544: sw          $s0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r16;
    // 0x80800548: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x8080054C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80800550: sw          $t2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r10;
L_80800554:
    // 0x80800554: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800558:
    // 0x80800558: bne         $s0, $s7, L_80800504
    if (ctx->r16 != ctx->r23) {
        // 0x8080055C: nop
    
            goto L_80800504;
    }
    // 0x8080055C: nop

L_80800560:
    // 0x80800560: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800564: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800568: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080056C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800570: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800578: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8080057C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800580: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800584: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800588: jr          $ra
    // 0x8080058C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080058C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800648_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800648: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080064C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800654: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800658: jal         0x80100094
    // 0x8080065C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080065C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800660: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800664: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1732, 0X4158) << 16);
    // 0x80800668: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080066C: lhu         $t6, 0x76($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X76);
    // 0x80800670: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800674: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80800678: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8080067C: lw          $t9, 0x4158($v1)
    ctx->r25 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(1732, 0X4158));
    // 0x80800680: andi        $t0, $t9, 0x20
    ctx->r8 = ctx->r25 & 0X20;
    // 0x80800684: beq         $t0, $zero, L_808006B0
    if (ctx->r8 == 0) {
        // 0x80800688: nop
    
            goto L_808006B0;
    }
    // 0x80800688: nop

    // 0x8080068C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80800690: lh          $a0, 0x10($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X10);
    // 0x80800694: beq         $a0, $zero, L_808006B0
    if (ctx->r4 == 0) {
        // 0x80800698: nop
    
            goto L_808006B0;
    }
    // 0x80800698: nop

    // 0x8080069C: jal         0x800ADFE0
    // 0x808006A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800ADFE0(rdram, ctx);
        goto after_1;
    // 0x808006A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x808006A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808006A8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x808006AC: sh          $zero, 0x10($t2)
    MEM_H(0X10, ctx->r10) = 0;
L_808006B0:
    // 0x808006B0: jal         0x800859A8
    // 0x808006B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _chanim_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808006B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x808006B8: lh          $a0, 0xC0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC0);
    // 0x808006BC: beql        $a0, $zero, L_808006D0
    if (ctx->r4 == 0) {
        // 0x808006C0: lh          $a0, 0xC2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0XC2);
            goto L_808006D0;
    }
    goto skip_0;
    // 0x808006C0: lh          $a0, 0xC2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC2);
    skip_0:
    // 0x808006C4: jal         0x80082640
    // 0x808006C8: nop

    _anseq_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808006C8: nop

    after_3:
    // 0x808006CC: lh          $a0, 0xC2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC2);
L_808006D0:
    // 0x808006D0: beql        $a0, $zero, L_808006E4
    if (ctx->r4 == 0) {
        // 0x808006D4: lh          $a0, 0xC4($s0)
        ctx->r4 = MEM_H(ctx->r16, 0XC4);
            goto L_808006E4;
    }
    goto skip_1;
    // 0x808006D4: lh          $a0, 0xC4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC4);
    skip_1:
    // 0x808006D8: jal         0x800857C0
    // 0x808006DC: nop

    _chblink_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808006DC: nop

    after_4:
    // 0x808006E0: lh          $a0, 0xC4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC4);
L_808006E4:
    // 0x808006E4: beql        $a0, $zero, L_808006F8
    if (ctx->r4 == 0) {
        // 0x808006E8: lh          $a0, 0xC6($s0)
        ctx->r4 = MEM_H(ctx->r16, 0XC6);
            goto L_808006F8;
    }
    goto skip_2;
    // 0x808006E8: lh          $a0, 0xC6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC6);
    skip_2:
    // 0x808006EC: jal         0x800857C0
    // 0x808006F0: nop

    _chblink_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808006F0: nop

    after_5:
    // 0x808006F4: lh          $a0, 0xC6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC6);
L_808006F8:
    // 0x808006F8: beql        $a0, $zero, L_8080070C
    if (ctx->r4 == 0) {
        // 0x808006FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080070C;
    }
    goto skip_3;
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800700: jal         0x8001B754
    // 0x80800704: nop

    func_8001B754(rdram, ctx);
        goto after_6;
    // 0x80800704: nop

    after_6:
    // 0x80800708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080070C:
    // 0x8080070C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800714: jr          $ra
    // 0x80800718: nop

    return;
    // 0x80800718: nop

;}
RECOMP_FUNC void func_80800000_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80089B70
    // 0x8080000C: nop

    _sufreezy_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void func_808001C8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808001D8: jal         0x8008CABC
    // 0x808001DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808001E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001E4: jal         0x8008AF24
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x8008AED4
    // 0x808001F4: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808001F4: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_2:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x8008B1BC
    // 0x80800200: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800200: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_3:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x8008B1C8
    // 0x8080020C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x8080020C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x8008B134
    // 0x80800218: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800218: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080021C: jal         0x8008B064
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800224: jal         0x80800000
    // 0x80800228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_7;
    // 0x80800228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8080022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800230: jal         0x8009B94C
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_8;
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800238: jal         0x80800030
    // 0x8080023C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_9;
    // 0x8080023C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80800240: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800244: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800248: jal         0x8009BC5C
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009BC5C(rdram, ctx);
        goto after_10;
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800254: jal         0x800852A8
    // 0x80800258: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80800258: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_11:
    // 0x8080025C: jal         0x8008E23C
    // 0x80800260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E23C(rdram, ctx);
        goto after_12;
    // 0x80800260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800264: beq         $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800268: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800274;
    }
    // 0x80800268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080026C: jal         0x800A0CF4
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_13;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_80800274:
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800278: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080027C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800280: jr          $ra
    // 0x80800284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bskazshock_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: jal         0x8008CABC
    // 0x808001D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808001DC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001E0: jal         0x8008E078
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001E8: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808001EC: nop
    
            goto L_80800224;
    }
    // 0x808001EC: nop

    // 0x808001F0: jal         0x8001211C
    // 0x808001F4: nop

    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x808001F4: nop

    after_2:
    // 0x808001F8: bgez        $v0, L_8080020C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x808001FC: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_8080020C;
    }
    // 0x808001FC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800200: beq         $t6, $zero, L_8080020C
    if (ctx->r14 == 0) {
        // 0x80800204: nop
    
            goto L_8080020C;
    }
    // 0x80800204: nop

    // 0x80800208: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_8080020C:
    // 0x8080020C: beq         $t6, $zero, L_8080022C
    if (ctx->r14 == 0) {
        // 0x80800210: nop
    
            goto L_8080022C;
    }
    // 0x80800210: nop

    // 0x80800214: jal         0x80800000
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bskazshock_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080021C: b           L_8080022C
    // 0x80800220: nop

        goto L_8080022C;
    // 0x80800220: nop

L_80800224:
    // 0x80800224: jal         0x80800000
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bskazshock_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8080022C:
    // 0x8080022C: jal         0x800834B0
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x8009BB24
    // 0x8080023C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_6;
    // 0x8080023C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80091A30
    // 0x80800248: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_7;
    // 0x80800248: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x8080024C: beq         $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800250: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800274;
    }
    // 0x80800250: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800258: nop

    // 0x8080025C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800260: nop

    // 0x80800264: bc1fl       L_80800278
    if (!c1cs) {
        // 0x80800268: lw          $v0, 0x160($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X160);
            goto L_80800278;
    }
    goto skip_0;
    // 0x80800268: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x8080026C: jal         0x8009BC6C
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_8;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800274:
    // 0x80800274: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
L_80800278:
    // 0x80800278: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x8080027C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800290;
    }
    // 0x8080027C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800280: beq         $v0, $at, L_808002EC
    if (ctx->r2 == ctx->r1) {
        // 0x80800284: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808002EC;
    }
    // 0x80800284: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800288: b           L_80800344
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800344;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800290:
    // 0x80800290: jal         0x8008E260
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_9;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800298: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x8080029C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A8;
    }
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x808002A4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808002A8:
    // 0x808002A8: jal         0x8008DF8C
    // 0x808002AC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x808002AC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x808002B0: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x808002B4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800340;
    }
    // 0x808002B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808002BC: jal         0x8008B1D4
    // 0x808002C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_11;
    // 0x808002C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x808002C4: lui         $a1, 0x4033
    ctx->r5 = S32(0X4033 << 16);
    // 0x808002C8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808002CC: jal         0x8008B1BC
    // 0x808002D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setDuration(rdram, ctx);
        goto after_12;
    // 0x808002D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x808002D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002D8: jal         0x8008B134
    // 0x808002DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_13;
    // 0x808002DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808002E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002E4: b           L_80800340
    // 0x808002E8: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
        goto L_80800340;
    // 0x808002E8: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
L_808002EC:
    // 0x808002EC: lui         $a1, 0x3DE1
    ctx->r5 = S32(0X3DE1 << 16);
    // 0x808002F0: jal         0x8008B348
    // 0x808002F4: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    anctrl_isAt(rdram, ctx);
        goto after_14;
    // 0x808002F4: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_14:
    // 0x808002F8: beql        $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808002FC: lui         $a1, 0x3ECE
        ctx->r5 = S32(0X3ECE << 16);
            goto L_8080030C;
    }
    goto skip_1;
    // 0x808002FC: lui         $a1, 0x3ECE
    ctx->r5 = S32(0X3ECE << 16);
    skip_1:
    // 0x80800300: jal         0x800C3BDC
    // 0x80800304: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    func_800C3BDC(rdram, ctx);
        goto after_15;
    // 0x80800304: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    after_15:
    // 0x80800308: lui         $a1, 0x3ECE
    ctx->r5 = S32(0X3ECE << 16);
L_8080030C:
    // 0x8080030C: ori         $a1, $a1, 0xA4A9
    ctx->r5 = ctx->r5 | 0XA4A9;
    // 0x80800310: jal         0x8008B348
    // 0x80800314: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_16;
    // 0x80800314: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_16:
    // 0x80800318: beq         $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x8080031C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080032C;
    }
    // 0x8080031C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800320: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800324: jal         0x8008B1BC
    // 0x80800328: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    anctrl_setDuration(rdram, ctx);
        goto after_17;
    // 0x80800328: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_17:
L_8080032C:
    // 0x8080032C: jal         0x8008B324
    // 0x80800330: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800330: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x80800334: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x80800338: addiu       $t9, $zero, 0xBB
        ctx->r25 = ADD32(0, 0XBB);
            goto L_80800340;
    }
    // 0x80800338: addiu       $t9, $zero, 0xBB
    ctx->r25 = ADD32(0, 0XBB);
    // 0x8080033C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800340:
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800344:
    // 0x80800344: jal         0x8008DF8C
    // 0x80800348: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_8008DF8C(rdram, ctx);
        goto after_19;
    // 0x80800348: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_19:
    // 0x8080034C: beql        $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x80800350: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808003A8;
    }
    goto skip_2;
    // 0x80800350: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x80800354: jal         0x8008B2B4
    // 0x80800358: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_20;
    // 0x80800358: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_20:
    // 0x8080035C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080036C: nop

    // 0x80800370: bc1f        L_8080038C
    if (!c1cs) {
        // 0x80800374: nop
    
            goto L_8080038C;
    }
    // 0x80800374: nop

    // 0x80800378: jal         0x80091A30
    // 0x8080037C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_21;
    // 0x8080037C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x80800380: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800384: nop
    
            goto L_8080038C;
    }
    // 0x80800384: nop

    // 0x80800388: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_8080038C:
    // 0x8080038C: jal         0x8008E078
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_22;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800394: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A4;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x8009B9B0
    // 0x808003A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_23;
    // 0x808003A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_23:
L_808003A4:
    // 0x808003A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808003A8:
    // 0x808003A8: jal         0x8008B348
    // 0x808003AC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_isAt(rdram, ctx);
        goto after_24;
    // 0x808003AC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_24:
    // 0x808003B0: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x808003B4: lui         $a1, 0x3F0E
        ctx->r5 = S32(0X3F0E << 16);
            goto L_808003CC;
    }
    // 0x808003B4: lui         $a1, 0x3F0E
    ctx->r5 = S32(0X3F0E << 16);
    // 0x808003B8: lw          $t0, 0x15C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X15C);
    // 0x808003BC: addiu       $t1, $zero, 0xC1
    ctx->r9 = ADD32(0, 0XC1);
    // 0x808003C0: beql        $t0, $zero, L_808003D0
    if (ctx->r8 == 0) {
        // 0x808003C4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808003D0;
    }
    goto skip_3;
    // 0x808003C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x808003C8: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_808003CC:
    // 0x808003CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808003D0:
    // 0x808003D0: jal         0x8008B348
    // 0x808003D4: ori         $a1, $a1, 0x1B09
    ctx->r5 = ctx->r5 | 0X1B09;
    anctrl_isAt(rdram, ctx);
        goto after_25;
    // 0x808003D4: ori         $a1, $a1, 0x1B09
    ctx->r5 = ctx->r5 | 0X1B09;
    after_25:
    // 0x808003D8: beq         $v0, $zero, L_808003E8
    if (ctx->r2 == 0) {
        // 0x808003DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E8;
    }
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: jal         0x8009BA58
    // 0x808003E4: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_26;
    // 0x808003E4: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_26:
L_808003E8:
    // 0x808003E8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808003EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808003F0: nop

    // 0x808003F4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808003F8: nop

    // 0x808003FC: bc1fl       L_8080041C
    if (!c1cs) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080041C;
    }
    goto skip_4;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800404: jal         0x8008E35C
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_27;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080040C: beq         $v0, $zero, L_80800418
    if (ctx->r2 == 0) {
        // 0x80800410: addiu       $t2, $zero, 0x160
        ctx->r10 = ADD32(0, 0X160);
            goto L_80800418;
    }
    // 0x80800410: addiu       $t2, $zero, 0x160
    ctx->r10 = ADD32(0, 0X160);
    // 0x80800414: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800418:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080041C:
    // 0x8080041C: jal         0x8009E5C8
    // 0x80800420: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_28;
    // 0x80800420: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_28:
    // 0x80800424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080042C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A540: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A540);
    return;
    // 0x8008A544: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800FB350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FB354: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800FB358: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB360: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FB364: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800FB368: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x800FB36C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800FB370: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800FB374: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FB378: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800FB37C: jal         0x800EE7F8
    // 0x800FB380: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800FB380: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    after_0:
    // 0x800FB384: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800FB388: jal         0x800FB2AC
    // 0x800FB38C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800FB2AC(rdram, ctx);
        goto after_1;
    // 0x800FB38C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_1:
    // 0x800FB390: bne         $v0, $zero, L_800FB3A0
    if (ctx->r2 != 0) {
        // 0x800FB394: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800FB3A0;
    }
    // 0x800FB394: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FB398: b           L_800FB3B0
    // 0x800FB39C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FB3B0;
    // 0x800FB39C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FB3A0:
    // 0x800FB3A0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800FB3A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB3A8: jal         0x800FB338
    // 0x800FB3AC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800FB338(rdram, ctx);
        goto after_2;
    // 0x800FB3AC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_2:
L_800FB3B0:
    // 0x800FB3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB3B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FB3B8: jr          $ra
    // 0x800FB3BC: nop

    return;
    // 0x800FB3BC: nop

;}
RECOMP_FUNC void func_800F9EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9EC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F9ECC: bgez        $a1, L_800F9EDC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800F9ED0: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800F9EDC;
    }
    // 0x800F9ED0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F9ED4: jal         0x800FC660
    // 0x800F9ED8: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x800F9ED8: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    after_0:
L_800F9EDC:
    // 0x800F9EDC: jal         0x800F9F04
    // 0x800F9EE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F9F04(rdram, ctx);
        goto after_1;
    // 0x800F9EE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F9EE4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9EE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F9EEC: jal         0x800F9F2C
    // 0x800F9EF0: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    func_800F9F2C(rdram, ctx);
        goto after_2;
    // 0x800F9EF0: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x800F9EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9EFC: jr          $ra
    // 0x800F9F00: nop

    return;
    // 0x800F9F00: nop

;}
RECOMP_FUNC void func_808005E4_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808005E8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808005EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808005F4: beq         $a1, $at, L_80800610
    if (ctx->r5 == ctx->r1) {
        // 0x808005F8: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800610;
    }
    // 0x808005F8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808005FC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800600: beq         $a1, $at, L_80800694
    if (ctx->r5 == ctx->r1) {
        // 0x80800604: nop
    
            goto L_80800694;
    }
    // 0x80800604: nop

    // 0x80800608: b           L_808006F4
    // 0x8080060C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F4;
    // 0x8080060C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800610:
    // 0x80800610: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800614: lw          $a0, 0x6C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X6C);
    // 0x80800618: sll         $t7, $a0, 11
    ctx->r15 = S32(ctx->r4 << 11);
    // 0x8080061C: jal         0x80089C68
    // 0x80800620: srl         $a0, $t7, 20
    ctx->r4 = S32(U32(ctx->r15) >> 20);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800620: srl         $a0, $t7, 20
    ctx->r4 = S32(U32(ctx->r15) >> 20);
    after_0:
    // 0x80800624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800628: bne         $v0, $at, L_80800664
    if (ctx->r2 != ctx->r1) {
        // 0x8080062C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800664;
    }
    // 0x8080062C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800630: jal         0x80103DFC
    // 0x80800634: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80103DFC(rdram, ctx);
        goto after_1;
    // 0x80800634: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800638: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8080063C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800640: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800644: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800648: lw          $t1, 0x48($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X48);
    // 0x8080064C: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80800650: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800654: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800658: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080065C: jal         0x80086D50
    // 0x80800660: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800660: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_2:
L_80800664:
    // 0x80800664: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800668: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x8080066C: jal         0x80800748
    // 0x80800670: addiu       $a2, $zero, 0x95C
    ctx->r6 = ADD32(0, 0X95C);
    func_80800748_chphlegm(rdram, ctx);
        goto after_3;
    // 0x80800670: addiu       $a2, $zero, 0x95C
    ctx->r6 = ADD32(0, 0X95C);
    after_3:
    // 0x80800674: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80800678: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080067C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80800680: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80800684: jal         0x80086678
    // 0x80800688: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800688: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x8080068C: b           L_808006F4
    // 0x80800690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F4;
    // 0x80800690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800694:
    // 0x80800694: jal         0x80101080
    // 0x80800698: nop

    func_80101080(rdram, ctx);
        goto after_5;
    // 0x80800698: nop

    after_5:
    // 0x8080069C: jal         0x80106790
    // 0x808006A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x808006A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808006A4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006B0: jal         0x800866A0
    // 0x808006B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808006B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808006B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808006C0: jal         0x800866A0
    // 0x808006C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808006C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x808006C8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1064, 0XC50) << 16);
    // 0x808006CC: addiu       $a1, $a1, 0xC50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1064, 0XC50));
    // 0x808006D0: jal         0x800866A8
    // 0x808006D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x808006D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x808006D8: jal         0x80089CA8
    // 0x808006DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808006DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x808006E0: b           L_808006F4
    // 0x808006E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F4;
    // 0x808006E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006E8: b           L_808006F4
    // 0x808006EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F4;
    // 0x808006EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006F4:
    // 0x808006F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void _mlspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089100: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089100);
    return;
    // 0x80089104: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chbottlesfamily_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1300, 0XE28) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xE28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1300, 0XE28));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xE28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1300, 0XE28));
;}
RECOMP_FUNC void func_800CE83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE844: jal         0x800CE3E0
    // 0x800CE848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CE84C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE850: sb          $t6, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r14;
    // 0x800CE854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE85C: jr          $ra
    // 0x800CE860: nop

    return;
    // 0x800CE860: nop

;}
RECOMP_FUNC void func_808000B8_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x808000BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808000C0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x808000C4: beq         $t6, $zero, L_808000E0
    if (ctx->r14 == 0) {
        // 0x808000C8: nop
    
            goto L_808000E0;
    }
    // 0x808000C8: nop

    // 0x808000CC: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
L_808000D0:
    // 0x808000D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808000D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808000D8: bnel        $t7, $zero, L_808000D0
    if (ctx->r15 != 0) {
        // 0x808000DC: lbu         $t7, 0x1($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X1);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000DC: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    skip_0:
L_808000E0:
    // 0x808000E0: jr          $ra
    // 0x808000E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808000E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808001A8_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808001B0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808001B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808001BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808001C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808001C8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x808001CC: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x808001D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808001D4:
    // 0x808001D4: jal         0x8080015C
    // 0x808001D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080015C_chsilo(rdram, ctx);
        goto after_0;
    // 0x808001D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x808001DC: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001E0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808001E8;
    }
    // 0x808001E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808001E8:
    // 0x808001E8: bnel        $s0, $s3, L_808001D4
    if (ctx->r16 != ctx->r19) {
        // 0x808001EC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001D4;
    }
    goto skip_0;
    // 0x808001EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808001F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001F4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808001F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800204: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800208: jr          $ra
    // 0x8080020C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080020C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sucoasterplayer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808004C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004CC: lui         $at, 0xFFF7
    ctx->r1 = S32(0XFFF7 << 16);
    // 0x808004D0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808004D4: bltzl       $t8, L_8080059C
    if (SIGNED(ctx->r24) < 0) {
        // 0x808004D8: lhu         $t0, 0x72($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X72);
            goto L_8080059C;
    }
    goto skip_0;
    // 0x808004D8: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808004DC: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x808004E0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808004E4: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808004E8: beql        $t0, $at, L_80800608
    if (ctx->r8 == ctx->r1) {
        // 0x808004EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800608;
    }
    goto skip_1;
    // 0x808004EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808004F0: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x808004F4: srl         $t1, $v0, 25
    ctx->r9 = S32(U32(ctx->r2) >> 25);
    // 0x808004F8: beq         $t1, $zero, L_80800604
    if (ctx->r9 == 0) {
        // 0x808004FC: sll         $t2, $v0, 22
        ctx->r10 = S32(ctx->r2 << 22);
            goto L_80800604;
    }
    // 0x808004FC: sll         $t2, $v0, 22
    ctx->r10 = S32(ctx->r2 << 22);
    // 0x80800500: srl         $t3, $t2, 26
    ctx->r11 = S32(U32(ctx->r10) >> 26);
    // 0x80800504: beql        $t3, $zero, L_80800608
    if (ctx->r11 == 0) {
        // 0x80800508: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800608;
    }
    goto skip_2;
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080050C: jal         0x8008A4A8
    // 0x80800510: nop

    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800510: nop

    after_0:
    // 0x80800514: beq         $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x80800518: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800560;
    }
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x80800520: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800524: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x80800528: bne         $t5, $at, L_80800584
    if (ctx->r13 != ctx->r1) {
        // 0x8080052C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800584;
    }
    // 0x8080052C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800530: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800534: jal         0x800DC298
    // 0x80800538: nop

    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800538: nop

    after_1:
    // 0x8080053C: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080054C;
    }
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: b           L_80800550
    // 0x80800548: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800550;
    // 0x80800548: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8080054C:
    // 0x8080054C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80800550:
    // 0x80800550: jal         0x8008A140
    // 0x80800554: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800554: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x80800558: b           L_80800588
    // 0x8080055C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
        goto L_80800588;
    // 0x8080055C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
L_80800560:
    // 0x80800560: jal         0x80107070
    // 0x80800564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_3;
    // 0x80800564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800568: bnel        $v0, $zero, L_80800588
    if (ctx->r2 != 0) {
        // 0x8080056C: lw          $t6, 0x14($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X14);
            goto L_80800588;
    }
    goto skip_3;
    // 0x8080056C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    skip_3:
    // 0x80800570: jal         0x80089CA8
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x8008A148
    // 0x80800580: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800580: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_5:
L_80800584:
    // 0x80800584: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
L_80800588:
    // 0x80800588: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8080058C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80800590: b           L_808005FC
    // 0x80800594: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
        goto L_808005FC;
    // 0x80800594: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80800598: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
L_8080059C:
    // 0x8080059C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x808005A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x808005A4: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808005A8: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x808005AC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x808005B0: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x808005B4: beq         $at, $zero, L_808005FC
    if (ctx->r1 == 0) {
        // 0x808005B8: sw          $t9, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r25;
            goto L_808005FC;
    }
    // 0x808005B8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x808005BC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808005C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3298, 0X824) << 16);
    // 0x808005C4: addu        $at, $at, $t2
    gpr jr_addend_808005CC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x808005C8: lw          $t2, 0x824($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3298, 0X824));
    // 0x808005CC: jr          $t2
    // 0x808005D0: nop

    switch (jr_addend_808005CC >> 2) {
        case 0: goto L_808005EC; break;
        case 1: goto L_808005D4; break;
        case 2: goto L_808005D4; break;
        case 3: goto L_808005D4; break;
        case 4: goto L_808005FC; break;
        case 5: goto L_808005FC; break;
        case 6: goto L_808005D4; break;
        default: switch_error(__func__, 0x808005CC, 0x80800824);
    }
    // 0x808005D0: nop

L_808005D4:
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005DC: jal         0x8008A140
    // 0x808005E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808005E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x808005E4: b           L_80800600
    // 0x808005E8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
        goto L_80800600;
    // 0x808005E8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
L_808005EC:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005F4: jal         0x8008A140
    // 0x808005F8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808005F8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_7:
L_808005FC:
    // 0x808005FC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
L_80800600:
    // 0x80800600: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_80800604:
    // 0x80800604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800608:
    // 0x80800608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080060C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void func_800C0BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0BB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C0BB8: jr          $ra
    // 0x800C0BBC: lw          $v0, -0x750C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X750C);
    return;
    // 0x800C0BBC: lw          $v0, -0x750C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X750C);
;}
RECOMP_FUNC void func_8008D1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D1F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D1FC: jal         0x800C6E38
    // 0x8008D200: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D200: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8008D204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D20C: jr          $ra
    // 0x8008D210: nop

    return;
    // 0x8008D210: nop

;}
RECOMP_FUNC void func_800C8898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C889C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C88A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C88A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C88A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C88AC: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C88B0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800C88B4: jal         0x800B28CC
    // 0x800C88B8: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C88B8: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    after_0:
    // 0x800C88BC: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800C88C0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C88C4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C88C8: nop

    // 0x800C88CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C88D0: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800C88D4: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x800C88D8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C88DC: nop

    // 0x800C88E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C88E4: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x800C88E8: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800C88EC: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x800C88F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C88F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C88F8: jr          $ra
    // 0x800C88FC: nop

    return;
    // 0x800C88FC: nop

;}
RECOMP_FUNC void badronemem_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: jr          $ra
    // 0x8080005C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080005C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bafly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BD8: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BD8);
    return;
    // 0x80084BDC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80108BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80108BDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80108BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108BE4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80108BE8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80108BEC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108BF0: addiu       $a0, $a0, -0x7474
    ctx->r4 = ADD32(ctx->r4, -0X7474);
    // 0x80108BF4: lhu         $a3, 0x12($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X12);
    // 0x80108BF8: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x80108BFC: jal         0x80086D40
    // 0x80108C00: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    _chbaddiesetup_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80108C00: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    after_0:
    // 0x80108C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108C0C: jr          $ra
    // 0x80108C10: nop

    return;
    // 0x80108C10: nop

;}
RECOMP_FUNC void _chlavagargoyle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087580: syscall     589
    recomp_syscall_handler(rdram, ctx, 0x80087580);
    return;
    // 0x80087584: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void glhittableDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x808000F4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000F8: beq         $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000FC: nop
    
            goto L_80800108;
    }
    // 0x808000FC: nop

    // 0x80800100: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x80800104: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_80800108:
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void bainvisible_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800498: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080049C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004A0: lw          $a1, 0xA8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA8);
    // 0x808004A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004AC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x808004B0: jal         0x80800000
    // 0x808004B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_bainvisible(rdram, ctx);
        goto after_0;
    // 0x808004B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808004B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004C4: jal         0x80800000
    // 0x808004C8: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_80800000_bainvisible(rdram, ctx);
        goto after_1;
    // 0x808004C8: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x808004CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: jal         0x80091788
    // 0x808004D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bastatetimer_clear(rdram, ctx);
        goto after_2;
    // 0x808004D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C10: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C10);
    return;
    // 0x80083C14: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void scinfobar_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: jr          $ra
    // 0x808005BC: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
    return;
    // 0x808005BC: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
;}
RECOMP_FUNC void func_8001B710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B710: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8001B714: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001B718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B71C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001B720: addiu       $t8, $t8, -0x40F0
    ctx->r24 = ADD32(ctx->r24, -0X40F0);
    // 0x8001B724: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8001B728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B72C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B730: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001B734: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001B738: jal         0x8001B208
    // 0x8001B73C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x8001B73C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001B740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B744: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B748: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B74C: jr          $ra
    // 0x8001B750: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x8001B750: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_8080995C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080995C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80809960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809964: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80809968: jal         0x80802458
    // 0x8080996C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080996C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80809970: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80809974: addiu       $a0, $v0, 0x74
    ctx->r4 = ADD32(ctx->r2, 0X74);
    // 0x80809978: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8080997C: jal         0x80031BF0
    // 0x80809980: addiu       $a1, $v1, 0x230
    ctx->r5 = ADD32(ctx->r3, 0X230);
    _bcopy(rdram, ctx);
        goto after_1;
    // 0x80809980: addiu       $a1, $v1, 0x230
    ctx->r5 = ADD32(ctx->r3, 0X230);
    after_1:
    // 0x80809984: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80809988: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080998C: sh          $zero, 0x248($v1)
    MEM_H(0X248, ctx->r3) = 0;
    // 0x80809990: swc1        $f0, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = ctx->f0.u32l;
    // 0x80809994: swc1        $f0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->f0.u32l;
    // 0x80809998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080999C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808099A0: jr          $ra
    // 0x808099A4: nop

    return;
    // 0x808099A4: nop

;}
RECOMP_FUNC void func_800ADEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADEC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800ADEC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ADECC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800ADED0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800ADED4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ADED8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ADEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ADEE0: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x800ADEE4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800ADEE8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800ADEEC: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800ADEF0: bne         $v1, $t6, L_800ADF3C
    if (ctx->r3 != ctx->r14) {
        // 0x800ADEF4: addiu       $s1, $a1, 0x8
        ctx->r17 = ADD32(ctx->r5, 0X8);
            goto L_800ADF3C;
    }
    // 0x800ADEF4: addiu       $s1, $a1, 0x8
    ctx->r17 = ADD32(ctx->r5, 0X8);
    // 0x800ADEF8: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x800ADEFC: addu        $s2, $t7, $a0
    ctx->r18 = ADD32(ctx->r15, ctx->r4);
    // 0x800ADF00: addiu       $s0, $a0, 0x50
    ctx->r16 = ADD32(ctx->r4, 0X50);
    // 0x800ADF04: addiu       $s2, $s2, 0x50
    ctx->r18 = ADD32(ctx->r18, 0X50);
    // 0x800ADF08: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800ADF0C: beql        $at, $zero, L_800ADF40
    if (ctx->r1 == 0) {
        // 0x800ADF10: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800ADF40;
    }
    goto skip_0;
    // 0x800ADF10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_800ADF14:
    // 0x800ADF14: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x800ADF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ADF1C: bnel        $s3, $t8, L_800ADF30
    if (ctx->r19 != ctx->r24) {
        // 0x800ADF20: addiu       $s0, $s0, 0x40
        ctx->r16 = ADD32(ctx->r16, 0X40);
            goto L_800ADF30;
    }
    goto skip_1;
    // 0x800ADF20: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    skip_1:
    // 0x800ADF24: jal         0x800F293C
    // 0x800ADF28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800F293C(rdram, ctx);
        goto after_0;
    // 0x800ADF28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x800ADF2C: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
L_800ADF30:
    // 0x800ADF30: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800ADF34: bne         $at, $zero, L_800ADF14
    if (ctx->r1 != 0) {
        // 0x800ADF38: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800ADF14;
    }
    // 0x800ADF38: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_800ADF3C:
    // 0x800ADF3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800ADF40:
    // 0x800ADF40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ADF44: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF48: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ADF4C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800ADF50: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800ADF54: jr          $ra
    // 0x800ADF58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800ADF58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808000CC_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D8: jal         0x8008E35C
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000E0: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800124;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: lui         $a1, 0x435C
    ctx->r5 = S32(0X435C << 16);
    // 0x808000F0: jal         0x8009BFE4
    // 0x808000F4: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_1;
    // 0x808000F4: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_1:
    // 0x808000F8: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808000FC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: jal         0x8009C554
    // 0x80800108: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_2;
    // 0x80800108: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_2:
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: lui         $a1, 0x4391
    ctx->r5 = S32(0X4391 << 16);
    // 0x80800114: jal         0x8009C99C
    // 0x80800118: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800118: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x8080011C: b           L_8080015C
    // 0x80800120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800124:
    // 0x80800124: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800128: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080012C: jal         0x8009BFE4
    // 0x80800130: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    func_8009BFE4(rdram, ctx);
        goto after_4;
    // 0x80800130: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_4:
    // 0x80800134: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800138: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x8009C554
    // 0x80800144: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_5;
    // 0x80800144: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_5:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80800150: jal         0x8009C99C
    // 0x80800154: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x80800154: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_6:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080015C:
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void func_8009E5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E5C0: jr          $ra
    // 0x8009E5C4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x8009E5C4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800F838C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F838C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8394: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F839C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F83A0: jal         0x8008F748
    // 0x800F83A4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008F748(rdram, ctx);
        goto after_0;
    // 0x800F83A4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F83A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F83AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F83B0: jr          $ra
    // 0x800F83B4: nop

    return;
    // 0x800F83B4: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843F8: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843F8);
    return;
    // 0x800843FC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chlifeforcespell_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002E8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808002EC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808002F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002F4: jal         0x80108528
    // 0x808002F8: addiu       $a0, $zero, 0x45C
    ctx->r4 = ADD32(0, 0X45C);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x808002F8: addiu       $a0, $zero, 0x45C
    ctx->r4 = ADD32(0, 0X45C);
    after_0:
    // 0x808002FC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800300: lhu         $t0, 0x6E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X6E);
    // 0x80800304: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1328, 0X454) << 16);
    // 0x80800308: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8080030C: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800310: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800314: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x80800318: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8080031C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800320: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800324: sh          $t2, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r10;
    // 0x80800328: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080032C: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x80800330: lwc1        $f10, 0x454($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1328, 0X454));
    // 0x80800334: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80800338: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8080033C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80800340: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80800344: sw          $t5, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r13;
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80800350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_8080483C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080483C: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80804840: jr          $ra
    // 0x80804844: sw          $a1, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r5;
    return;
    // 0x80804844: sw          $a1, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80800B54_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B64: jal         0x8008CABC
    // 0x80800B68: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800B68: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800B6C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800B70: jal         0x80800694
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x80095738
    // 0x80800B80: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800B80: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x80800B84: beq         $v0, $zero, L_80800B9C
    if (ctx->r2 == 0) {
        // 0x80800B88: nop
    
            goto L_80800B9C;
    }
    // 0x80800B88: nop

    // 0x80800B8C: jal         0x8009B7C0
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_3;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B94: b           L_80800BA8
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800BA8;
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B9C:
    // 0x80800B9C: jal         0x80800134
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800134_bsbabykaz(rdram, ctx);
        goto after_4;
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800BA8:
    // 0x80800BA8: jal         0x8009BB24
    // 0x80800BAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_5;
    // 0x80800BAC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x80091A30
    // 0x80800BB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x80800BB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80800BBC: beq         $v0, $zero, L_80800BDC
    if (ctx->r2 == 0) {
        // 0x80800BC0: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800BDC;
    }
    // 0x80800BC0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800BC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800BC8: nop

    // 0x80800BCC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800BD0: nop

    // 0x80800BD4: bc1t        L_80800BEC
    if (c1cs) {
        // 0x80800BD8: nop
    
            goto L_80800BEC;
    }
    // 0x80800BD8: nop

L_80800BDC:
    // 0x80800BDC: jal         0x8008D544
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D544(rdram, ctx);
        goto after_7;
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800BE4: bnel        $v0, $zero, L_80800BF8
    if (ctx->r2 != 0) {
        // 0x80800BE8: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800BF8;
    }
    goto skip_0;
    // 0x80800BE8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
L_80800BEC:
    // 0x80800BEC: jal         0x8009BC6C
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_8;
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800BF4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800BF8:
    // 0x80800BF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BFC: beq         $v0, $zero, L_80800C1C
    if (ctx->r2 == 0) {
        // 0x80800C00: nop
    
            goto L_80800C1C;
    }
    // 0x80800C00: nop

    // 0x80800C04: beq         $v0, $at, L_80800C74
    if (ctx->r2 == ctx->r1) {
        // 0x80800C08: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C74;
    }
    // 0x80800C08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C0C: beq         $v0, $at, L_80800CB0
    if (ctx->r2 == ctx->r1) {
        // 0x80800C10: nop
    
            goto L_80800CB0;
    }
    // 0x80800C10: nop

    // 0x80800C14: b           L_80800CB0
    // 0x80800C18: nop

        goto L_80800CB0;
    // 0x80800C18: nop

L_80800C1C:
    // 0x80800C1C: jal         0x8008B324
    // 0x80800C20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x80800C20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x80800C24: beq         $v0, $zero, L_80800C44
    if (ctx->r2 == 0) {
        // 0x80800C28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C44;
    }
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C2C: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x80800C30: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x80800C34: jal         0x8008CF1C
    // 0x80800C38: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_10;
    // 0x80800C38: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_10:
    // 0x80800C3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800C40: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800C44:
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C48: jal         0x8008DF8C
    // 0x80800C4C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_11;
    // 0x80800C4C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_11:
    // 0x80800C50: beq         $v0, $zero, L_80800CB0
    if (ctx->r2 == 0) {
        // 0x80800C54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB0;
    }
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800C5C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800C60: jal         0x8008CF1C
    // 0x80800C64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_12;
    // 0x80800C64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
    // 0x80800C68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800C6C: b           L_80800CB0
    // 0x80800C70: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800CB0;
    // 0x80800C70: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800C74:
    // 0x80800C74: jal         0x8008CAEC
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800C7C: beq         $v0, $zero, L_80800C8C
    if (ctx->r2 == 0) {
        // 0x80800C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C8C;
    }
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: addiu       $t8, $zero, 0x133
    ctx->r24 = ADD32(0, 0X133);
    // 0x80800C88: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800C8C:
    // 0x80800C8C: jal         0x8008DF8C
    // 0x80800C90: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_14;
    // 0x80800C90: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_14:
    // 0x80800C94: beq         $v0, $zero, L_80800CB0
    if (ctx->r2 == 0) {
        // 0x80800C98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB0;
    }
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C9C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800CA0: jal         0x8008CF1C
    // 0x80800CA4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_15;
    // 0x80800CA4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_15:
    // 0x80800CA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800CAC: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_80800CB0:
    // 0x80800CB0: jal         0x8008E078
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_16;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800CB8: beq         $v0, $zero, L_80800CD0
    if (ctx->r2 == 0) {
        // 0x80800CBC: nop
    
            goto L_80800CD0;
    }
    // 0x80800CBC: nop

    // 0x80800CC0: jal         0x8009FE58
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_17;
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800CC8: addiu       $t0, $zero, 0x132
    ctx->r8 = ADD32(0, 0X132);
    // 0x80800CCC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800CD0:
    // 0x80800CD0: jal         0x808000F8
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000F8_bsbabykaz(rdram, ctx);
        goto after_18;
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800CD8: beq         $v0, $zero, L_80800CE8
    if (ctx->r2 == 0) {
        // 0x80800CDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CE8;
    }
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE0: addiu       $t1, $zero, 0x94
    ctx->r9 = ADD32(0, 0X94);
    // 0x80800CE4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800CE8:
    // 0x80800CE8: jal         0x8009E5C8
    // 0x80800CEC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800CEC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x80800CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: nop

    return;
    // 0x80800D00: nop

;}
RECOMP_FUNC void _chsecreteggs_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877C0: syscall     626
    recomp_syscall_handler(rdram, ctx, 0x800877C0);
    return;
    // 0x800877C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void fxegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080024C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800250: jal         0x800B5BE4
    // 0x80800254: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800254: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x80800258: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800260: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800264: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    // 0x80800268: jal         0x808000F8
    // 0x8080026C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_808000F8_fxegg(rdram, ctx);
        goto after_1;
    // 0x8080026C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800274: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

;}
RECOMP_FUNC void func_801007B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801007B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801007BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801007C0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801007C4: addiu       $s0, $s0, 0x5A60
    ctx->r16 = ADD32(ctx->r16, 0X5A60);
    // 0x801007C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801007CC: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x801007D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801007D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801007D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801007DC: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x801007E0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x801007E4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801007E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801007EC: beq         $s1, $zero, L_80100898
    if (ctx->r17 == 0) {
        // 0x801007F0: sw          $a0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r4;
            goto L_80100898;
    }
    // 0x801007F0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801007F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801007F8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801007FC: jal         0x800B3034
    // 0x80100800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    freelist_capacity(rdram, ctx);
        goto after_0;
    // 0x80100800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80100804: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80100808: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010080C: beq         $at, $zero, L_80100898
    if (ctx->r1 == 0) {
        // 0x80100810: nop
    
            goto L_80100898;
    }
    // 0x80100810: nop

    // 0x80100814: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80100818:
    // 0x80100818: jal         0x800B31B8
    // 0x8010081C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    freelist_is_element_alive(rdram, ctx);
        goto after_1;
    // 0x8010081C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80100820: beq         $v0, $zero, L_80100874
    if (ctx->r2 == 0) {
        // 0x80100824: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_80100874;
    }
    // 0x80100824: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80100828: jal         0x800B301C
    // 0x8010082C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    freelist_at(rdram, ctx);
        goto after_2;
    // 0x8010082C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x80100830: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80100834: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80100838: bnel        $s4, $t8, L_80100878
    if (ctx->r20 != ctx->r24) {
        // 0x8010083C: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80100878;
    }
    goto skip_0;
    // 0x8010083C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80100840: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80100844: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80100848: bnel        $s2, $t9, L_80100878
    if (ctx->r18 != ctx->r25) {
        // 0x8010084C: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80100878;
    }
    goto skip_1;
    // 0x8010084C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80100850: jal         0x8010072C
    // 0x80100854: addiu       $a1, $v0, 0x9
    ctx->r5 = ADD32(ctx->r2, 0X9);
    func_8010072C(rdram, ctx);
        goto after_3;
    // 0x80100854: addiu       $a1, $v0, 0x9
    ctx->r5 = ADD32(ctx->r2, 0X9);
    after_3:
    // 0x80100858: beql        $v0, $zero, L_80100878
    if (ctx->r2 == 0) {
        // 0x8010085C: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_80100878;
    }
    goto skip_2;
    // 0x8010085C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80100860: lbu         $t0, 0x8($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8);
    // 0x80100864: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80100868: sb          $t1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r9;
    // 0x8010086C: b           L_80100918
    // 0x80100870: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80100918;
    // 0x80100870: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80100874:
    // 0x80100874: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
L_80100878:
    // 0x80100878: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8010087C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80100880: jal         0x800B3034
    // 0x80100884: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    freelist_capacity(rdram, ctx);
        goto after_4;
    // 0x80100884: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    after_4:
    // 0x80100888: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8010088C: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80100890: bnel        $at, $zero, L_80100818
    if (ctx->r1 != 0) {
        // 0x80100894: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80100818;
    }
    goto skip_3;
    // 0x80100894: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_3:
L_80100898:
    // 0x80100898: jal         0x801006E0
    // 0x8010089C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_801006E0(rdram, ctx);
        goto after_5;
    // 0x8010089C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x801008A0: beq         $s2, $zero, L_801008B8
    if (ctx->r18 == 0) {
        // 0x801008A4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_801008B8;
    }
    // 0x801008A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801008A8: jal         0x800D674C
    // 0x801008AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x801008AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x801008B0: b           L_801008BC
    // 0x801008B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_801008BC;
    // 0x801008B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_801008B8:
    // 0x801008B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801008BC:
    // 0x801008BC: jal         0x800B2840
    // 0x801008C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800B2840(rdram, ctx);
        goto after_7;
    // 0x801008C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x801008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801008C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801008CC: jal         0x80088798
    // 0x801008D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _glpackvtx_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x801008D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_8:
    // 0x801008D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801008D8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x801008DC: sh          $s4, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r20;
    // 0x801008E0: sh          $s2, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r18;
    // 0x801008E4: beq         $s3, $zero, L_80100900
    if (ctx->r19 == 0) {
        // 0x801008E8: sb          $t5, 0x8($s1)
        MEM_B(0X8, ctx->r17) = ctx->r13;
            goto L_80100900;
    }
    // 0x801008E8: sb          $t5, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r13;
    // 0x801008EC: addiu       $a0, $s1, 0x9
    ctx->r4 = ADD32(ctx->r17, 0X9);
    // 0x801008F0: jal         0x800F2F20
    // 0x801008F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F2F20(rdram, ctx);
        goto after_9;
    // 0x801008F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x801008F8: b           L_80100918
    // 0x801008FC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80100918;
    // 0x801008FC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80100900:
    // 0x80100900: addiu       $a0, $s1, 0x9
    ctx->r4 = ADD32(ctx->r17, 0X9);
    // 0x80100904: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80100908: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8010090C: jal         0x800F31EC
    // 0x80100910: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800F31EC(rdram, ctx);
        goto after_10;
    // 0x80100910: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_10:
    // 0x80100914: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80100918:
    // 0x80100918: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010091C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100920: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80100924: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80100928: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010092C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80100930: jr          $ra
    // 0x80100934: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80100934: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808002A0_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B0: beq         $a1, $at, L_808002E4
    if (ctx->r5 == ctx->r1) {
        // 0x808002B4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808002E4;
    }
    // 0x808002B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002B8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x808002BC: beq         $a1, $at, L_808002FC
    if (ctx->r5 == ctx->r1) {
        // 0x808002C0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808002FC;
    }
    // 0x808002C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808002C4: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808002C8: beq         $a1, $at, L_80800310
    if (ctx->r5 == ctx->r1) {
        // 0x808002CC: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(948, 0X6E8) << 16);
            goto L_80800310;
    }
    // 0x808002CC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(948, 0X6E8) << 16);
    // 0x808002D0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002D4: beq         $a1, $at, L_80800324
    if (ctx->r5 == ctx->r1) {
        // 0x808002D8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800324;
    }
    // 0x808002D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808002DC: b           L_80800364
    // 0x808002E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800364;
    // 0x808002E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002E4:
    // 0x808002E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808002E8: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808002EC: jal         0x80800374
    // 0x808002F0: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800374_chconga(rdram, ctx);
        goto after_0;
    // 0x808002F0: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x808002F4: b           L_80800364
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800364;
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002FC:
    // 0x808002FC: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800300: jal         0x80800478
    // 0x80800304: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800478_chconga(rdram, ctx);
        goto after_1;
    // 0x80800304: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x80800308: b           L_80800368
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800368;
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800310:
    // 0x80800310: addiu       $a0, $a0, 0x6E8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(948, 0X6E8));
    // 0x80800314: jal         0x80088090
    // 0x80800318: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800318: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x8080031C: b           L_80800364
    // 0x80800320: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800364;
    // 0x80800320: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800324:
    // 0x80800324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800328: addiu       $a2, $zero, 0x52
    ctx->r6 = ADD32(0, 0X52);
    // 0x8080032C: jal         0x800897C0
    // 0x80800330: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800330: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: jal         0x80100094
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800344: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80800348: jal         0x800897E8
    // 0x8080034C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x8080034C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_5:
    // 0x80800350: b           L_80800364
    // 0x80800354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800364;
    // 0x80800354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800358: b           L_80800364
    // 0x8080035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800364;
    // 0x8080035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800364:
    // 0x80800364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800368:
    // 0x80800368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

;}
RECOMP_FUNC void func_800DF330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF330: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF334: jr          $ra
    // 0x800DF338: addiu       $v0, $v0, -0x37C0
    ctx->r2 = ADD32(ctx->r2, -0X37C0);
    return;
    // 0x800DF338: addiu       $v0, $v0, -0x37C0
    ctx->r2 = ADD32(ctx->r2, -0X37C0);
;}
RECOMP_FUNC void func_8080104C_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080104C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80801050: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80801054: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80801058: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080105C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80801060: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80801064: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80801068: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8080106C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80801070: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80801074: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80801078: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080107C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801080: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801084: jal         0x80100094
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080108C: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x80801090: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801094: jal         0x8010D254
    // 0x80801098: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80801098: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8080109C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(924, 0X21A0) << 16);
    // 0x808010A0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x808010A4: lwc1        $f22, 0x21A0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(924, 0X21A0));
    // 0x808010A8: jal         0x800BE444
    // 0x808010AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800BE444(rdram, ctx);
        goto after_2;
    // 0x808010AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x808010B0: sh          $zero, 0x8($s4)
    MEM_H(0X8, ctx->r20) = 0;
    // 0x808010B4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808010B8: beq         $t6, $zero, L_808011D8
    if (ctx->r14 == 0) {
        // 0x808010BC: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_808011D8;
    }
    // 0x808010BC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808010C0: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_808010C4:
    // 0x808010C4: jal         0x800E9E88
    // 0x808010C8: nop

    func_800E9E88(rdram, ctx);
        goto after_3;
    // 0x808010C8: nop

    after_3:
    // 0x808010CC: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x808010D0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808010D4: jal         0x800E9EB4
    // 0x808010D8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_4;
    // 0x808010D8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x808010DC: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x808010E0: beq         $at, $zero, L_808011C0
    if (ctx->r1 == 0) {
        // 0x808010E4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_808011C0;
    }
    // 0x808010E4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808010E8: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
L_808010EC:
    // 0x808010EC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808010F0: beql        $t9, $zero, L_808011B4
    if (ctx->r25 == 0) {
        // 0x808010F4: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808011B4;
    }
    goto skip_0;
    // 0x808010F4: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    skip_0:
    // 0x808010F8: lw          $s2, 0x0($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X0);
    // 0x808010FC: lhu         $t0, 0x18($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X18);
    // 0x80801100: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80801104: beql        $t1, $zero, L_808011B4
    if (ctx->r9 == 0) {
        // 0x80801108: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808011B4;
    }
    goto skip_1;
    // 0x80801108: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    skip_1:
    // 0x8080110C: jal         0x80106790
    // 0x80801110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80801110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80801114: lbu         $t2, 0x64($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X64);
    // 0x80801118: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080111C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80801120: beql        $t3, $zero, L_808011B4
    if (ctx->r11 == 0) {
        // 0x80801124: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808011B4;
    }
    goto skip_2;
    // 0x80801124: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    skip_2:
    // 0x80801128: jal         0x801072A8
    // 0x8080112C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801072A8(rdram, ctx);
        goto after_6;
    // 0x8080112C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80801130: bne         $v0, $zero, L_808011B0
    if (ctx->r2 != 0) {
        // 0x80801134: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808011B0;
    }
    // 0x80801134: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801138: jal         0x800EEB40
    // 0x8080113C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x8080113C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80801140: jal         0x800BDC5C
    // 0x80801144: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800BDC5C(rdram, ctx);
        goto after_8;
    // 0x80801144: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_8:
    // 0x80801148: jal         0x800BDC5C
    // 0x8080114C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800BDC5C(rdram, ctx);
        goto after_9;
    // 0x8080114C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_9:
    // 0x80801150: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801154: mflo        $t4
    ctx->r12 = lo;
    // 0x80801158: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8080115C: nop

    // 0x80801160: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801164: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x80801168: nop

    // 0x8080116C: bc1fl       L_808011B4
    if (!c1cs) {
        // 0x80801170: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808011B4;
    }
    goto skip_3;
    // 0x80801170: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    skip_3:
    // 0x80801174: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80801178: nop

    // 0x8080117C: bc1f        L_8080118C
    if (!c1cs) {
        // 0x80801180: nop
    
            goto L_8080118C;
    }
    // 0x80801180: nop

    // 0x80801184: or          $fp, $s0, $zero
    ctx->r30 = ctx->r16 | 0;
    // 0x80801188: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_8080118C:
    // 0x8080118C: beql        $s7, $zero, L_808011B4
    if (ctx->r23 == 0) {
        // 0x80801190: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808011B4;
    }
    goto skip_4;
    // 0x80801190: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    skip_4:
    // 0x80801194: lh          $t5, 0x8($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X8);
    // 0x80801198: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8080119C: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x808011A0: sw          $s2, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r18;
    // 0x808011A4: lh          $t8, 0x8($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X8);
    // 0x808011A8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808011AC: sh          $t9, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r25;
L_808011B0:
    // 0x808011B0: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_808011B4:
    // 0x808011B4: sltu        $at, $s3, $s5
    ctx->r1 = ctx->r19 < ctx->r21 ? 1 : 0;
    // 0x808011B8: bnel        $at, $zero, L_808010EC
    if (ctx->r1 != 0) {
        // 0x808011BC: lw          $t8, 0x8($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X8);
            goto L_808010EC;
    }
    goto skip_5;
    // 0x808011BC: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    skip_5:
L_808011C0:
    // 0x808011C0: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x808011C4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x808011C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808011CC: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x808011D0: bne         $a0, $zero, L_808010C4
    if (ctx->r4 != 0) {
        // 0x808011D4: nop
    
            goto L_808010C4;
    }
    // 0x808011D4: nop

L_808011D8:
    // 0x808011D8: beq         $s7, $zero, L_80801284
    if (ctx->r23 == 0) {
        // 0x808011DC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801284;
    }
    // 0x808011DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808011E0: lh          $t0, 0x8($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X8);
    // 0x808011E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808011E8: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x808011EC: bne         $at, $zero, L_80801284
    if (ctx->r1 != 0) {
        // 0x808011F0: nop
    
            goto L_80801284;
    }
    // 0x808011F0: nop

L_808011F4:
    // 0x808011F4: blez        $a3, L_80801270
    if (SIGNED(ctx->r7) <= 0) {
        // 0x808011F8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80801270;
    }
    // 0x808011F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808011FC: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x80801200: addu        $v0, $s4, $t1
    ctx->r2 = ADD32(ctx->r20, ctx->r9);
    // 0x80801204: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80801208: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8080120C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80801210: lhu         $t3, 0x1A($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X1A);
    // 0x80801214: lhu         $t6, 0x1A($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X1A);
    // 0x80801218: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8080121C: srl         $t4, $t3, 5
    ctx->r12 = S32(U32(ctx->r11) >> 5);
    // 0x80801220: srl         $t7, $t6, 5
    ctx->r15 = S32(U32(ctx->r14) >> 5);
    // 0x80801224: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80801228: beql        $at, $zero, L_80801274
    if (ctx->r1 == 0) {
        // 0x8080122C: lh          $t3, 0x8($s4)
        ctx->r11 = MEM_H(ctx->r20, 0X8);
            goto L_80801274;
    }
    goto skip_6;
    // 0x8080122C: lh          $t3, 0x8($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X8);
    skip_6:
    // 0x80801230: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80801234: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80801238: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8080123C:
    // 0x8080123C: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x80801240: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80801244: blez        $a0, L_80801270
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80801248: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80801270;
    }
    // 0x80801248: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8080124C: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80801250: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80801254: lhu         $t9, 0x1A($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X1A);
    // 0x80801258: lhu         $t1, 0x1A($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X1A);
    // 0x8080125C: srl         $t0, $t9, 5
    ctx->r8 = S32(U32(ctx->r25) >> 5);
    // 0x80801260: srl         $t2, $t1, 5
    ctx->r10 = S32(U32(ctx->r9) >> 5);
    // 0x80801264: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80801268: bnel        $at, $zero, L_8080123C
    if (ctx->r1 != 0) {
        // 0x8080126C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8080123C;
    }
    goto skip_7;
    // 0x8080126C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_7:
L_80801270:
    // 0x80801270: lh          $t3, 0x8($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X8);
L_80801274:
    // 0x80801274: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80801278: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8080127C: bne         $at, $zero, L_808011F4
    if (ctx->r1 != 0) {
        // 0x80801280: nop
    
            goto L_808011F4;
    }
    // 0x80801280: nop

L_80801284:
    // 0x80801284: beq         $fp, $zero, L_80801294
    if (ctx->r30 == 0) {
        // 0x80801288: ldc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
            goto L_80801294;
    }
    // 0x80801288: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080128C: b           L_80801294
    // 0x80801290: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
        goto L_80801294;
    // 0x80801290: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
L_80801294:
    // 0x80801294: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80801298: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8080129C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808012A0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808012A4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808012A8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808012AC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808012B0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808012B4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x808012B8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x808012BC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x808012C0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x808012C4: jr          $ra
    // 0x808012C8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808012C8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void _bamovegoto_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E18: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084E18);
    return;
    // 0x80084E1C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808013BC_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808013C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808013C8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808013CC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808013D0: jal         0x80100094
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013D8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808013DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808013E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808013E4: beq         $t6, $zero, L_80801448
    if (ctx->r14 == 0) {
        // 0x808013E8: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_80801448;
    }
    // 0x808013E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808013EC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808013F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808013F4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x808013F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808013FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80801400: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80801404: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80801408: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8080140C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80801410: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80801414: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801418: bnel        $t5, $zero, L_8080144C
    if (ctx->r13 != 0) {
        // 0x8080141C: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8080144C;
    }
    goto skip_0;
    // 0x8080141C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80801420: beq         $a0, $zero, L_80801440
    if (ctx->r4 == 0) {
        // 0x80801424: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80801440;
    }
    // 0x80801424: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801428: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2336, 0X24FC) << 16);
    // 0x8080142C: addiu       $t6, $t6, 0x24FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2336, 0X24FC));
    // 0x80801430: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801434: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801438: jal         0x800BBCB8
    // 0x8080143C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x8080143C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_1:
L_80801440:
    // 0x80801440: jal         0x800FC660
    // 0x80801444: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x80801444: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_2:
L_80801448:
    // 0x80801448: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_8080144C:
    // 0x8080144C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801450: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80801454: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80801458: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x8080145C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80801460: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80801464: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80801468: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8080146C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80801470: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80801474: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80801478: addu        $t6, $t4, $a2
    ctx->r14 = ADD32(ctx->r12, ctx->r6);
    // 0x8080147C: jal         0x80801870
    // 0x80801480: sb          $a3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r7;
    func_80801870_chpotogoldgame(rdram, ctx);
        goto after_3;
    // 0x80801480: sb          $a3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r7;
    after_3:
    // 0x80801484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801488: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080148C: jr          $ra
    // 0x80801490: nop

    return;
    // 0x80801490: nop

;}
RECOMP_FUNC void func_808006E0_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808006E4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x808006E8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808006EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808006F0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808006F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808006F8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x808006FC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800700: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80800704: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800708: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8080070C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800710: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800714: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800718: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080071C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800720: blez        $a1, L_808007B4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800724: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_808007B4;
    }
    // 0x80800724: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800728: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080072C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800730: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DC0) << 16);
    // 0x80800734: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2578, 0X3E80) << 16);
    // 0x80800738: addiu       $s4, $s4, 0x3E80
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2578, 0X3E80));
    // 0x8080073C: lwc1        $f20, 0x3DC0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DC0));
    // 0x80800740: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80800744:
    // 0x80800744: beq         $s2, $zero, L_80800794
    if (ctx->r18 == 0) {
        // 0x80800748: addu        $t6, $s4, $s2
        ctx->r14 = ADD32(ctx->r20, ctx->r18);
            goto L_80800794;
    }
    // 0x80800748: addu        $t6, $s4, $s2
    ctx->r14 = ADD32(ctx->r20, ctx->r18);
    // 0x8080074C: jal         0x800DC1AC
    // 0x80800750: nop

    func_800DC1AC(rdram, ctx);
        goto after_0;
    // 0x80800750: nop

    after_0:
    // 0x80800754: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800758: nop

    // 0x8080075C: bc1fl       L_808007A0
    if (!c1cs) {
        // 0x80800760: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808007A0;
    }
    goto skip_0;
    // 0x80800760: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x80800764: jal         0x800DC1AC
    // 0x80800768: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    func_800DC1AC(rdram, ctx);
        goto after_1;
    // 0x80800768: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    after_1:
    // 0x8080076C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800770: nop

    // 0x80800774: bc1fl       L_8080078C
    if (!c1cs) {
        // 0x80800778: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8080078C;
    }
    goto skip_1;
    // 0x80800778: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    skip_1:
    // 0x8080077C: sb          $s7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r23;
    // 0x80800780: b           L_8080079C
    // 0x80800784: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8080079C;
    // 0x80800784: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800788: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8080078C:
    // 0x8080078C: b           L_8080079C
    // 0x80800790: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8080079C;
    // 0x80800790: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800794:
    // 0x80800794: sb          $s7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r23;
    // 0x80800798: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080079C:
    // 0x8080079C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808007A0:
    // 0x808007A0: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808007A4: beq         $at, $zero, L_808007B4
    if (ctx->r1 == 0) {
        // 0x808007A8: slti        $at, $s2, 0x20
        ctx->r1 = SIGNED(ctx->r18) < 0X20 ? 1 : 0;
            goto L_808007B4;
    }
    // 0x808007A8: slti        $at, $s2, 0x20
    ctx->r1 = SIGNED(ctx->r18) < 0X20 ? 1 : 0;
    // 0x808007AC: bne         $at, $zero, L_80800744
    if (ctx->r1 != 0) {
        // 0x808007B0: nop
    
            goto L_80800744;
    }
    // 0x808007B0: nop

L_808007B4:
    // 0x808007B4: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2578, 0X3E80) << 16);
    // 0x808007B8: addiu       $s4, $s4, 0x3E80
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2578, 0X3E80));
    // 0x808007BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808007C0: addu        $t7, $s4, $s2
    ctx->r15 = ADD32(ctx->r20, ctx->r18);
    // 0x808007C4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808007C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808007CC: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x808007D0: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x808007D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808007D8: blez        $s2, L_808008B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x808007DC: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_808008B4;
    }
    // 0x808007DC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808007E0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2578, 0X3E80) << 16);
    // 0x808007E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DC4) << 16);
    // 0x808007E8: lwc1        $f20, 0x3DC4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DC4));
    // 0x808007EC: addiu       $s1, $s1, 0x3E80
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2578, 0X3E80));
    // 0x808007F0: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x808007F4: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x808007F8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_808007FC:
    // 0x808007FC: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80800800: bnel        $s4, $t8, L_808008A0
    if (ctx->r20 != ctx->r24) {
        // 0x80800804: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_808008A0;
    }
    goto skip_2;
    // 0x80800804: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_2:
    // 0x80800808: lbu         $t9, 0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1);
    // 0x8080080C: bnel        $s4, $t9, L_8080088C
    if (ctx->r20 != ctx->r25) {
        // 0x80800810: lbu         $t4, 0x1D1($fp)
        ctx->r12 = MEM_BU(ctx->r30, 0X1D1);
            goto L_8080088C;
    }
    goto skip_3;
    // 0x80800810: lbu         $t4, 0x1D1($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X1D1);
    skip_3:
    // 0x80800814: lbu         $t0, 0x2($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X2);
    // 0x80800818: bne         $s4, $t0, L_80800848
    if (ctx->r20 != ctx->r8) {
        // 0x8080081C: nop
    
            goto L_80800848;
    }
    // 0x8080081C: nop

    // 0x80800820: jal         0x800DC1AC
    // 0x80800824: nop

    func_800DC1AC(rdram, ctx);
        goto after_2;
    // 0x80800824: nop

    after_2:
    // 0x80800828: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8080082C: nop

    // 0x80800830: bc1f        L_80800840
    if (!c1cs) {
        // 0x80800834: nop
    
            goto L_80800840;
    }
    // 0x80800834: nop

    // 0x80800838: b           L_80800894
    // 0x8080083C: sb          $s7, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r23;
        goto L_80800894;
    // 0x8080083C: sb          $s7, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r23;
L_80800840:
    // 0x80800840: b           L_80800894
    // 0x80800844: sb          $s6, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r22;
        goto L_80800894;
    // 0x80800844: sb          $s6, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r22;
L_80800848:
    // 0x80800848: jal         0x800DC1AC
    // 0x8080084C: nop

    func_800DC1AC(rdram, ctx);
        goto after_3;
    // 0x8080084C: nop

    after_3:
    // 0x80800850: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800854: nop

    // 0x80800858: bc1fl       L_8080086C
    if (!c1cs) {
        // 0x8080085C: lbu         $t1, 0x1D1($fp)
        ctx->r9 = MEM_BU(ctx->r30, 0X1D1);
            goto L_8080086C;
    }
    goto skip_4;
    // 0x8080085C: lbu         $t1, 0x1D1($fp)
    ctx->r9 = MEM_BU(ctx->r30, 0X1D1);
    skip_4:
    // 0x80800860: b           L_80800894
    // 0x80800864: sb          $s6, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r22;
        goto L_80800894;
    // 0x80800864: sb          $s6, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r22;
    // 0x80800868: lbu         $t1, 0x1D1($fp)
    ctx->r9 = MEM_BU(ctx->r30, 0X1D1);
L_8080086C:
    // 0x8080086C: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80800870: bgez        $t2, L_80800880
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800874: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80800880;
    }
    // 0x80800874: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80800878: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8080087C: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80800880:
    // 0x80800880: b           L_80800894
    // 0x80800884: sb          $t3, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r11;
        goto L_80800894;
    // 0x80800884: sb          $t3, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r11;
    // 0x80800888: lbu         $t4, 0x1D1($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X1D1);
L_8080088C:
    // 0x8080088C: addiu       $t5, $t4, -0x6
    ctx->r13 = ADD32(ctx->r12, -0X6);
    // 0x80800890: sb          $t5, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r13;
L_80800894:
    // 0x80800894: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800898: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080089C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_808008A0:
    // 0x808008A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808008A4: sb          $zero, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = 0;
    // 0x808008A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808008AC: bne         $s5, $s2, L_808007FC
    if (ctx->r21 != ctx->r18) {
        // 0x808008B0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808007FC;
    }
    // 0x808008B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808008B4:
    // 0x808008B4: sb          $s3, 0x1D2($fp)
    MEM_B(0X1D2, ctx->r30) = ctx->r19;
    // 0x808008B8: sb          $zero, 0x1D0($fp)
    MEM_B(0X1D0, ctx->r30) = 0;
    // 0x808008BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808008C0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x808008C4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x808008C8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x808008CC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x808008D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808008D4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808008D8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808008DC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808008E0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808008E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808008E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808008EC: jr          $ra
    // 0x808008F0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808008F0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
