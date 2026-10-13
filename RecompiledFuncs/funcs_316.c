#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080000C_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080001C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800028: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080002C: jal         0x80102FDC
    // 0x80800030: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800030: nop

    after_0:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x8080003C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800040: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800044: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_800F5F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5F7C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5F84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5F8C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5F90: jal         0x8009C150
    // 0x800F5F94: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x800F5F94: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5FA0: jr          $ra
    // 0x800F5FA4: nop

    return;
    // 0x800F5FA4: nop

;}
RECOMP_FUNC void func_808000C4_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000DC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000E0: beq         $t6, $at, L_808000F0
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000F0;
    }
    // 0x808000E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E8: bne         $t6, $at, L_808000FC
    if (ctx->r14 != ctx->r1) {
        // 0x808000EC: nop
    
            goto L_808000FC;
    }
    // 0x808000EC: nop

L_808000F0:
    // 0x808000F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000F4: nop

    // 0x808000F8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_808000FC:
    // 0x808000FC: jal         0x80101FDC
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800104: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800108: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080010C: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x80800110: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x80800114: beq         $at, $zero, L_80800230
    if (ctx->r1 == 0) {
        // 0x80800118: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800230;
    }
    // 0x80800118: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080011C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFC8) << 16);
    // 0x80800120: addu        $at, $at, $t9
    gpr jr_addend_80800128 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800124: lw          $t9, 0xFC8($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFC8));
    // 0x80800128: jr          $t9
    // 0x8080012C: nop

    switch (jr_addend_80800128 >> 2) {
        case 0: goto L_808001AC; break;
        case 1: goto L_80800170; break;
        case 2: goto L_808001F4; break;
        case 3: goto L_808001E8; break;
        case 4: goto L_808001E8; break;
        case 5: goto L_80800130; break;
        case 6: goto L_80800150; break;
        default: switch_error(__func__, 0x80800128, 0x80800FC8);
    }
    // 0x8080012C: nop

L_80800130:
    // 0x80800130: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800138: addiu       $a1, $zero, 0xCE6
    ctx->r5 = ADD32(0, 0XCE6);
    // 0x8080013C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800140: jal         0x8008A208
    // 0x80800144: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800144: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800148: b           L_80800234
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800234;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800154: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800158: addiu       $a1, $zero, 0xCE7
    ctx->r5 = ADD32(0, 0XCE7);
    // 0x8080015C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800160: jal         0x8008A208
    // 0x80800164: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800164: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800168: b           L_80800234
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800234;
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800170:
    // 0x80800170: jal         0x80090708
    // 0x80800174: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x80800174: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800178: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080017C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80800180: jal         0x800CE8D8
    // 0x80800184: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CE8D8(rdram, ctx);
        goto after_4;
    // 0x80800184: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_4:
    // 0x80800188: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080018C: jal         0x800CE88C
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_5;
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800198: jal         0x800FA9F4
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FA9F4(rdram, ctx);
        goto after_6;
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808001A0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808001A4: b           L_80800230
    // 0x808001A8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800230;
    // 0x808001A8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808001AC:
    // 0x808001AC: jal         0x80090708
    // 0x808001B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_7;
    // 0x808001B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x808001B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808001B8: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x808001BC: jal         0x800CE8D8
    // 0x808001C0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CE8D8(rdram, ctx);
        goto after_8;
    // 0x808001C0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_8:
    // 0x808001C4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808001C8: jal         0x800CE88C
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_9;
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808001D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001D4: jal         0x800FA9F4
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FA9F4(rdram, ctx);
        goto after_10;
    // 0x808001D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808001DC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808001E0: b           L_80800230
    // 0x808001E4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800230;
    // 0x808001E4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808001E8:
    // 0x808001E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808001EC: b           L_80800230
    // 0x808001F0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800230;
    // 0x808001F0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_808001F4:
    // 0x808001F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001F8: jal         0x800FA9F4
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FA9F4(rdram, ctx);
        goto after_11;
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800200: jal         0x8008FC00
    // 0x80800204: nop

    func_8008FC00(rdram, ctx);
        goto after_12;
    // 0x80800204: nop

    after_12:
    // 0x80800208: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080020C: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x80800210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800214: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800218: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8080021C: jal         0x8008FC70
    // 0x80800220: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    func_8008FC70(rdram, ctx);
        goto after_13;
    // 0x80800220: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    after_13:
    // 0x80800224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFE4) << 16);
    // 0x80800228: lwc1        $f16, 0xFE4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFE4));
    // 0x8080022C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800230:
    // 0x80800230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800234:
    // 0x80800234: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void func_8080007C_chmumboskulls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800088: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1352, 0X108) << 16);
    // 0x8080008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800090: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800094: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80800098: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8080009C: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x808000A0: jal         0x80103140
    // 0x808000A4: lhu         $a1, 0x108($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1352, 0X108));
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x808000A4: lhu         $a1, 0x108($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1352, 0X108));
    after_0:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

    // 0x808000B8: nop

    // 0x808000BC: nop

;}
RECOMP_FUNC void func_80800464_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800468: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8080046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800470: beq         $a1, $at, L_8080048C
    if (ctx->r5 == ctx->r1) {
        // 0x80800474: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080048C;
    }
    // 0x80800474: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800478: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8080047C: beq         $a1, $at, L_808004A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800480: addiu       $a0, $zero, 0xAC2
        ctx->r4 = ADD32(0, 0XAC2);
            goto L_808004A0;
    }
    // 0x80800480: addiu       $a0, $zero, 0xAC2
    ctx->r4 = ADD32(0, 0XAC2);
    // 0x80800484: b           L_808004CC
    // 0x80800488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004CC;
    // 0x80800488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080048C:
    // 0x8080048C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800490: jal         0x808003C4
    // 0x80800494: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808003C4_chpodiumbankaz(rdram, ctx);
        goto after_0;
    // 0x80800494: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800498: b           L_808004CC
    // 0x8080049C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004CC;
    // 0x8080049C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004A0:
    // 0x808004A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808004A4: jal         0x800DA298
    // 0x808004A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808004A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808004AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808004B0: beq         $v0, $zero, L_808004C4
    if (ctx->r2 == 0) {
        // 0x808004B4: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_808004C4;
    }
    // 0x808004B4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808004B8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x808004BC: jal         0x80800318
    // 0x808004C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800318_chpodiumbankaz(rdram, ctx);
        goto after_2;
    // 0x808004C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
L_808004C4:
    // 0x808004C4: b           L_808004CC
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004CC;
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004CC:
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_80800348_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080034C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800354: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800358: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080035C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800360: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800364: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800368: jal         0x80089F40
    // 0x8080036C: nop

    _subaddiesect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080036C: nop

    after_0:
    // 0x80800370: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080037C: sll         $t7, $a2, 19
    ctx->r15 = S32(ctx->r6 << 19);
    // 0x80800380: jal         0x80800AC4
    // 0x80800384: srl         $a2, $t7, 31
    ctx->r6 = S32(U32(ctx->r15) >> 31);
    func_80800AC4_chtransparentfish(rdram, ctx);
        goto after_1;
    // 0x80800384: srl         $a2, $t7, 31
    ctx->r6 = S32(U32(ctx->r15) >> 31);
    after_1:
    // 0x80800388: jal         0x800F54E4
    // 0x8080038C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080038C: nop

    after_2:
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800394: jal         0x800F52B8
    // 0x80800398: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_3;
    // 0x80800398: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8080039C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x808003A0: beql        $v0, $at, L_80800464
    if (ctx->r2 == ctx->r1) {
        // 0x808003A4: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800464;
    }
    goto skip_0;
    // 0x808003A4: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x808003A8: jal         0x800F54E4
    // 0x808003AC: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808003AC: nop

    after_4:
    // 0x808003B0: jal         0x800F690C
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F690C(rdram, ctx);
        goto after_5;
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808003B8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808003BC: jal         0x80103EAC
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_6;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003C4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x808003C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808003CC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003D0: beql        $t9, $zero, L_808003EC
    if (ctx->r25 == 0) {
        // 0x808003D4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_808003EC;
    }
    goto skip_1;
    // 0x808003D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x808003D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003E0: b           L_808003F0
    // 0x808003E4: nop

        goto L_808003F0;
    // 0x808003E4: nop

    // 0x808003E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_808003EC:
    // 0x808003EC: nop

L_808003F0:
    // 0x808003F0: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808003F4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003F8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x808003FC: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80800400: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80800404: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800408: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080040C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800410: jal         0x800EFA4C
    // 0x80800414: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800414: nop

    after_7:
    // 0x80800418: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8080041C: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800420: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800424: beql        $t0, $zero, L_80800440
    if (ctx->r8 == 0) {
        // 0x80800428: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800440;
    }
    goto skip_2;
    // 0x80800428: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x8080042C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800430: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800434: b           L_80800444
    // 0x80800438: nop

        goto L_80800444;
    // 0x80800438: nop

    // 0x8080043C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800440:
    // 0x80800440: nop

L_80800444:
    // 0x80800444: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800448: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080044C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800450: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x80800454: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800458: jal         0x80089F18
    // 0x8080045C: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x8080045C: nop

    after_8:
    // 0x80800460: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800464:
    // 0x80800464: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800468: jal         0x80101E14
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800470: beql        $v0, $zero, L_80800544
    if (ctx->r2 == 0) {
        // 0x80800474: lhu         $t5, 0x72($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X72);
            goto L_80800544;
    }
    goto skip_3;
    // 0x80800474: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80800478: jal         0x80102CCC
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102CCC(rdram, ctx);
        goto after_10;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800480: beql        $v0, $zero, L_80800544
    if (ctx->r2 == 0) {
        // 0x80800484: lhu         $t5, 0x72($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X72);
            goto L_80800544;
    }
    goto skip_4;
    // 0x80800484: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    skip_4:
    // 0x80800488: jal         0x800B53A4
    // 0x8080048C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_11;
    // 0x8080048C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_11:
    // 0x80800490: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800494: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2232, 0X1050) << 16);
    // 0x80800498: addiu       $t1, $t1, 0x1050
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2232, 0X1050));
    // 0x8080049C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808004A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808004A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808004AC: jal         0x800BABB8
    // 0x808004B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_12;
    // 0x808004B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808004B4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x808004B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004BC: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808004C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2232, 0XF6C) << 16);
    // 0x808004C4: lwc1        $f16, 0xF6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF6C));
    // 0x808004C8: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x808004CC: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808004D0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808004D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808004D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004DC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808004E0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808004E4: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808004E8: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x808004EC: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808004F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808004F4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808004F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808004FC: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800500: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800504: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80800508: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080050C: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800510: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80800514: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800518: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8080051C: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800520: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80800524: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80800528: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8080052C: jal         0x800BA994
    // 0x80800530: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_800BA994(rdram, ctx);
        goto after_13;
    // 0x80800530: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_13:
    // 0x80800534: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800538: jal         0x800BA22C
    // 0x8080053C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_14;
    // 0x8080053C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_14:
    // 0x80800540: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
L_80800544:
    // 0x80800544: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800548: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x8080054C: bnel        $t6, $at, L_80800680
    if (ctx->r14 != ctx->r1) {
        // 0x80800550: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800680;
    }
    goto skip_5;
    // 0x80800550: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80800554: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800558: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8080055C: bgez        $t9, L_808005A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800560: nop
    
            goto L_808005A0;
    }
    // 0x80800560: nop

    // 0x80800564: jal         0x80800204
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800204_chtransparentfish(rdram, ctx);
        goto after_15;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080056C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800570: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800574: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800578: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080057C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80800580: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80800584: jal         0x800F10B4
    // 0x80800588: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800588: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x8080058C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800590: jal         0x80101CDC
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_17;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800598: b           L_80800628
    // 0x8080059C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
        goto L_80800628;
    // 0x8080059C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
L_808005A0:
    // 0x808005A0: jal         0x80800000
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chtransparentfish(rdram, ctx);
        goto after_18;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808005A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2232, 0XF70) << 16);
    // 0x808005AC: lwc1        $f0, 0xF70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF70));
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x808005B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005C0: jal         0x80102BAC
    // 0x808005C4: nop

    func_80102BAC(rdram, ctx);
        goto after_19;
    // 0x808005C4: nop

    after_19:
    // 0x808005C8: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x808005CC: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x808005D0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x808005D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x80102C58
    // 0x808005E0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_80102C58(rdram, ctx);
        goto after_20;
    // 0x808005E0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_20:
    // 0x808005E4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005E8: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808005EC: jal         0x800F15F8
    // 0x808005F0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_800F15F8(rdram, ctx);
        goto after_21;
    // 0x808005F0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_21:
    // 0x808005F4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80800600: jal         0x8010BA80
    // 0x80800604: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8010BA80(rdram, ctx);
        goto after_22;
    // 0x80800604: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_22:
    // 0x80800608: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x8080060C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80800624;
    }
    // 0x8080060C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800610: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800618: nop

    // 0x8080061C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800620: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
L_80800624:
    // 0x80800624: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
L_80800628:
    // 0x80800628: jal         0x800F1DCC
    // 0x8080062C: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    func_800F1DCC(rdram, ctx);
        goto after_23;
    // 0x8080062C: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    after_23:
    // 0x80800630: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800634: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800638: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080063C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800640: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800644: jal         0x800F0DC0
    // 0x80800648: nop

    func_800F0DC0(rdram, ctx);
        goto after_24;
    // 0x80800648: nop

    after_24:
    // 0x8080064C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800650: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2232, 0XF74) << 16);
    // 0x80800654: lwc1        $f16, 0xF74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF74));
    // 0x80800658: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8080065C: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800660: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x80800664: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800668: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8080066C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800670: jal         0x800F1FF0
    // 0x80800674: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_25;
    // 0x80800674: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_25:
    // 0x80800678: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8080067C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800680:
    // 0x80800680: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800684: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800688: jr          $ra
    // 0x8080068C: nop

    return;
    // 0x8080068C: nop

;}
RECOMP_FUNC void func_80800F54_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F60: jal         0x80800110
    // 0x80800F64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80800110_chchuffy(rdram, ctx);
        goto after_0;
    // 0x80800F64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800F68: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1700, 0X247C) << 16);
    // 0x80800F6C: addiu       $t0, $t0, 0x247C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1700, 0X247C));
    // 0x80800F70: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800F74: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80800F78: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80800F7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800F80: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800F84: beq         $t8, $at, L_80800FAC
    if (ctx->r24 == ctx->r1) {
        // 0x80800F88: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800FAC;
    }
    // 0x80800F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F8C: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80800F90: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800F94: lh          $a2, 0x6($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X6);
    // 0x80800F98: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800F9C: jal         0x80085708
    // 0x80800FA0: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800FA0: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_1:
    // 0x80800FA4: jal         0x800861A8
    // 0x80800FA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800FA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
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
RECOMP_FUNC void _cadbfunc_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855B8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855B8);
    return;
    // 0x800855BC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808001B0_chfactorylinkgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001BC: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x808001C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001C4: jal         0x80086880
    // 0x808001C8: addiu       $a3, $zero, 0x1D9
    ctx->r7 = ADD32(0, 0X1D9);
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001C8: addiu       $a3, $zero, 0x1D9
    ctx->r7 = ADD32(0, 0X1D9);
    after_0:
    // 0x808001CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D0: jal         0x800868A8
    // 0x808001D4: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808001D4: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_1:
    // 0x808001D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001DC: jal         0x800868C0
    // 0x808001E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808001E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void func_808008CC_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008D8: jal         0x800910BC
    // 0x808008DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800910BC(rdram, ctx);
        goto after_0;
    // 0x808008DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808008E0: jal         0x80800104
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C80: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C80);
    return;
    // 0x80083C84: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void _basetup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FA0: syscall     146
    recomp_syscall_handler(rdram, ctx, 0x80084FA0);
    return;
    // 0x80084FA4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _plcamera_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878B8: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878B8);
    return;
    // 0x800878BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gcextra_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: jal         0x80800000
    // 0x80800038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcextra_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080003C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800040: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x80800044: jal         0x80800024
    // 0x80800048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcextra_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080004C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    // 0x80800054: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800058: beq         $at, $zero, L_80800064
    if (ctx->r1 == 0) {
        // 0x8080005C: nop
    
            goto L_80800064;
    }
    // 0x8080005C: nop

    // 0x80800060: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800064:
    // 0x80800064: jal         0x800DA7A8
    // 0x80800068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x8080006C: jal         0x800D517C
    // 0x80800070: nop

    func_800D517C(rdram, ctx);
        goto after_3;
    // 0x80800070: nop

    after_3:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

    // 0x80800084: nop

    // 0x80800088: nop

    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80802560_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802568: jal         0x800A3280
    // 0x8080256C: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x8080256C: nop

    after_0:
    // 0x80802570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802574: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80802578: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8080257C: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB038) << 16);
    // 0x80802580: addiu       $t7, $t7, -0x4FC8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB038));
    // 0x80802584: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80802588: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8080258C: jr          $ra
    // 0x80802590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80115580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115580: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80115584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115588: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8011558C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80115590: jal         0x801107F0
    // 0x80115594: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80115594: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80115598: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8011559C: jal         0x800EEB40
    // 0x801155A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x801155A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801155A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801155A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801155AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801155B0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801155B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801155B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801155BC: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x801155C0: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801155C4: nop

    // 0x801155C8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801155CC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801155D0: nop

    // 0x801155D4: bc1f        L_801155E0
    if (!c1cs) {
        // 0x801155D8: nop
    
            goto L_801155E0;
    }
    // 0x801155D8: nop

    // 0x801155DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801155E0:
    // 0x801155E0: jr          $ra
    // 0x801155E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801155E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _badrone_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084868: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084868);
    return;
    // 0x8008486C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_808001F8_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001FC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: beq         $a1, $at, L_80800230
    if (ctx->r5 == ctx->r1) {
        // 0x80800208: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800230;
    }
    // 0x80800208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080020C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800210: beq         $a1, $at, L_80800298
    if (ctx->r5 == ctx->r1) {
        // 0x80800214: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_80800298;
    }
    // 0x80800214: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800218: bne         $a1, $at, L_808002A8
    if (ctx->r5 != ctx->r1) {
        // 0x8080021C: nop
    
            goto L_808002A8;
    }
    // 0x8080021C: nop

    // 0x80800220: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800224: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800228: b           L_808002B0
    // 0x8080022C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
        goto L_808002B0;
    // 0x8080022C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
L_80800230:
    // 0x80800230: jal         0x80101080
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800238: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x8080023C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800240: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800244: beq         $a2, $zero, L_80800278
    if (ctx->r6 == 0) {
        // 0x80800248: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800278;
    }
    // 0x80800248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080024C: beq         $a2, $at, L_80800288
    if (ctx->r6 == ctx->r1) {
        // 0x80800250: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800288;
    }
    // 0x80800250: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800254: bne         $a2, $at, L_808002B0
    if (ctx->r6 != ctx->r1) {
        // 0x80800258: lh          $a1, 0x20($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X20);
            goto L_808002B0;
    }
    // 0x80800258: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x8080025C: jal         0x80800620
    // 0x80800260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800620_chchuffycont(rdram, ctx);
        goto after_1;
    // 0x80800260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: jal         0x80800000
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chchuffycont(rdram, ctx);
        goto after_2;
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800270: b           L_808002B4
    // 0x80800274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002B4;
    // 0x80800274: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800278:
    // 0x80800278: jal         0x80800494
    // 0x8080027C: nop

    func_80800494_chchuffycont(rdram, ctx);
        goto after_3;
    // 0x8080027C: nop

    after_3:
    // 0x80800280: b           L_808002B4
    // 0x80800284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002B4;
    // 0x80800284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800288:
    // 0x80800288: jal         0x80800000
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chchuffycont(rdram, ctx);
        goto after_4;
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800290: b           L_808002B4
    // 0x80800294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002B4;
    // 0x80800294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800298:
    // 0x80800298: jal         0x80800000
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chchuffycont(rdram, ctx);
        goto after_5;
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808002A0: b           L_808002B4
    // 0x808002A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002B4;
    // 0x808002A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002A8:
    // 0x808002A8: b           L_808002B4
    // 0x808002AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002B4;
    // 0x808002AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002B0:
    // 0x808002B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002B4:
    // 0x808002B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

;}
RECOMP_FUNC void bsstand_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(368, 0XDA8) << 16);
    // 0x80800CB8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CBC: jr          $ra
    // 0x80800CC0: lw          $v0, 0xDA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XDA8));
    return;
    // 0x80800CC0: lw          $v0, 0xDA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XDA8));
;}
RECOMP_FUNC void _chdodgemdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D08: syscall     446
    recomp_syscall_handler(rdram, ctx, 0x80086D08);
    return;
    // 0x80086D0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801F34_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F3C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801F40: jal         0x80100094
    // 0x80801F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801F48: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801F4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80801F50: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80801F54: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801F58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80801F5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801F60: addu        $a3, $v0, $t7
    ctx->r7 = ADD32(ctx->r2, ctx->r15);
    // 0x80801F64: addiu       $a3, $a3, 0x568
    ctx->r7 = ADD32(ctx->r7, 0X568);
    // 0x80801F68: jal         0x8001211C
    // 0x80801F6C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x80801F6C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801F70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80801F74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801F78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801F7C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80801F80: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80801F84: blezl       $a2, L_80801FB8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801F88: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80801FB8;
    }
    goto skip_0;
    // 0x80801F88: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80801F8C:
    // 0x80801F8C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80801F90: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80801F94: beql        $at, $zero, L_80801FA8
    if (ctx->r1 == 0) {
        // 0x80801F98: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80801FA8;
    }
    goto skip_1;
    // 0x80801F98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80801F9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801FA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80801FA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801FA8:
    // 0x80801FA8: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80801FAC: bne         $at, $zero, L_80801F8C
    if (ctx->r1 != 0) {
        // 0x80801FB0: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80801F8C;
    }
    // 0x80801FB0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80801FB4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80801FB8:
    // 0x80801FB8: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80801FBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801FC0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80801FC4: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x80801FC8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80801FCC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80801FD0: jal         0x8010114C
    // 0x80801FD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80801FD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801FD8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80801FDC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FE0: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80801FE4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80801FE8: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x80801FEC: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80801FF0: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80801FF4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80801FF8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80801FFC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80802000: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80802004: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80802008: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8080200C: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x80802010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802014: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802018: jr          $ra
    // 0x8080201C: nop

    return;
    // 0x8080201C: nop

;}
RECOMP_FUNC void func_80800068_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080006C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800070: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800074: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080007C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800080: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800088: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080008C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800090: jal         0x80089F18
    // 0x80800094: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800094: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x80800098: jal         0x808006B8
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006B8_chcheato(rdram, ctx);
        goto after_1;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000A0: jal         0x8080078C
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080078C_chcheato(rdram, ctx);
        goto after_2;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000A8: jal         0x800D1824
    // 0x808000AC: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800D1824(rdram, ctx);
        goto after_3;
    // 0x808000AC: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_3:
    // 0x808000B0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000B4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000B8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000BC: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x808000C0: beq         $at, $zero, L_808001F0
    if (ctx->r1 == 0) {
        // 0x808000C4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808001F0;
    }
    // 0x808000C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(868, 0XDC0) << 16);
    // 0x808000CC: addu        $at, $at, $t8
    gpr jr_addend_808000D4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000D0: lw          $t8, 0xDC0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(868, 0XDC0));
    // 0x808000D4: jr          $t8
    // 0x808000D8: nop

    switch (jr_addend_808000D4 >> 2) {
        case 0: goto L_808000DC; break;
        case 1: goto L_808001F0; break;
        case 2: goto L_80800124; break;
        case 3: goto L_80800180; break;
        case 4: goto L_808001AC; break;
        case 5: goto L_808001C8; break;
        default: switch_error(__func__, 0x808000D4, 0x80800DC0);
    }
    // 0x808000D8: nop

L_808000DC:
    // 0x808000DC: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808000E0: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x808000E4: bltzl       $t1, L_808001F4
    if (SIGNED(ctx->r9) < 0) {
        // 0x808000E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001F4;
    }
    goto skip_0;
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000EC: jal         0x8010D23C
    // 0x808000F0: nop

    func_8010D23C(rdram, ctx);
        goto after_4;
    // 0x808000F0: nop

    after_4:
    // 0x808000F4: beql        $v0, $zero, L_808001F4
    if (ctx->r2 == 0) {
        // 0x808000F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001F4;
    }
    goto skip_1;
    // 0x808000F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808000FC: jal         0x8010CD28
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_5;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800104: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80102B2C
    // 0x80800110: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_6;
    // 0x80800110: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_6:
    // 0x80800114: jal         0x808003C4
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003C4_chcheato(rdram, ctx);
        goto after_7;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080011C: b           L_808001F4
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F4;
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800124:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80103DFC
    // 0x8080012C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80103DFC(rdram, ctx);
        goto after_8;
    // 0x8080012C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80100094
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800144: jal         0x80089FE8
    // 0x80800148: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800148: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_10:
    // 0x8080014C: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x80800150: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80102424
    // 0x80800158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x8080015C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800160: addiu       $t2, $zero, 0x37
    ctx->r10 = ADD32(0, 0X37);
    // 0x80800164: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800168: addiu       $a1, $zero, 0x115D
    ctx->r5 = ADD32(0, 0X115D);
    // 0x8080016C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800170: jal         0x8008A208
    // 0x80800174: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800174: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800178: b           L_808001F4
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F4;
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800180:
    // 0x80800180: jal         0x800C0638
    // 0x80800184: nop

    func_800C0638(rdram, ctx);
        goto after_13;
    // 0x80800184: nop

    after_13:
    // 0x80800188: bne         $v0, $zero, L_808001F0
    if (ctx->r2 != 0) {
        // 0x8080018C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800194: jal         0x80800D08
    // 0x80800198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800D08_chcheato(rdram, ctx);
        goto after_14;
    // 0x80800198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x8080019C: jal         0x80800B00
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B00_chcheato(rdram, ctx);
        goto after_15;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001A4: b           L_808001F4
    // 0x808001A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F4;
    // 0x808001A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001AC:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x80100094
    // 0x808001B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x808001B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808001B8: jal         0x80087C98
    // 0x808001BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x808001BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x808001C0: b           L_808001F4
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001F4;
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C8:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x80087CC8
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_18;
    // 0x808001D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x808001D4: jal         0x80090708
    // 0x808001D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_19;
    // 0x808001D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x80102424
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808001E8: jal         0x80800CC0
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC0_chcheato(rdram, ctx);
        goto after_21;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
L_808001F0:
    // 0x808001F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001F4:
    // 0x808001F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_80013C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013C80: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80013C84: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80013C88: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80013C8C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80013C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013C94: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80013C98: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80013C9C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80013CA0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80013CA4: jal         0x800EFA4C
    // 0x80013CA8: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80013CA8: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    after_0:
    // 0x80013CAC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80013CB0: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x80013CB4: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80013CB8: jal         0x800EFA4C
    // 0x80013CBC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80013CBC: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    after_1:
    // 0x80013CC0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80013CC4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x80013CC8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x80013CCC: jal         0x800EFA4C
    // 0x80013CD0: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80013CD0: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    after_2:
    // 0x80013CD4: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80013CD8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80013CDC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80013CE0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80013CE4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80013CE8: jal         0x800F2984
    // 0x80013CEC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800F2984(rdram, ctx);
        goto after_3;
    // 0x80013CEC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80013CF0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80013CF4: jal         0x8002ED00
    // 0x80013CF8: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    guMtxF2L(rdram, ctx);
        goto after_4;
    // 0x80013CF8: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_4:
    // 0x80013CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013D00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80013D04: jr          $ra
    // 0x80013D08: nop

    return;
    // 0x80013D08: nop

    // 0x80013D0C: nop

;}
RECOMP_FUNC void baattach_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80800030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800034: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
    // 0x80800038: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8080003C: jr          $ra
    // 0x80800040: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
    return;
    // 0x80800040: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void func_80103D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103D78: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80103D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80103D80: jal         0x800D70F8
    // 0x80103D84: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D70F8(rdram, ctx);
        goto after_0;
    // 0x80103D84: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_0:
    // 0x80103D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103D90: jr          $ra
    // 0x80103D94: nop

    return;
    // 0x80103D94: nop

;}
RECOMP_FUNC void bsjump_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800908: jr          $ra
    // 0x8080090C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080090C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chbeanstalkseed_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087610: syscall     597
    recomp_syscall_handler(rdram, ctx, 0x80087610);
    return;
    // 0x80087614: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B5680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5680: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B5684: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5688: sb          $t6, 0x7F1D($at)
    MEM_B(0X7F1D, ctx->r1) = ctx->r14;
    // 0x800B568C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5690: jr          $ra
    // 0x800B5694: sh          $a0, 0x7F1A($at)
    MEM_H(0X7F1A, ctx->r1) = ctx->r4;
    return;
    // 0x800B5694: sh          $a0, 0x7F1A($at)
    MEM_H(0X7F1A, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void vpglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800014: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80800018: jal         0x8001ACCC
    // 0x8080001C: addiu       $a0, $t7, 0xC
    ctx->r4 = ADD32(ctx->r15, 0XC);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $t7, 0xC
    ctx->r4 = ADD32(ctx->r15, 0XC);
    after_0:
    // 0x80800020: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800028: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080002C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800030: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80800034: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80800038: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080003C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80800040: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800044: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800048: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8080004C: mfhi        $t2
    ctx->r10 = hi;
    // 0x80800050: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800054: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800058: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080005C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800060: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2990, 0X410) << 16);
    // 0x80800064: lwc1        $f18, 0x410($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2990, 0X410));
    // 0x80800068: addu        $a1, $t0, $a2
    ctx->r5 = ADD32(ctx->r8, ctx->r6);
    // 0x8080006C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x80800070: addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // 0x80800074: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800078: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8080007C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800080: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800084: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800088: beq         $at, $zero, L_808000D0
    if (ctx->r1 == 0) {
        // 0x8080008C: swc1        $f4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
            goto L_808000D0;
    }
    // 0x8080008C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800090: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
L_80800094:
    // 0x80800094: beql        $t3, $zero, L_808000C4
    if (ctx->r11 == 0) {
        // 0x80800098: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808000C4;
    }
    goto skip_0;
    // 0x80800098: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x8080009C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x808000A0: subu        $t4, $v1, $a0
    ctx->r12 = SUB32(ctx->r3, ctx->r4);
    // 0x808000A4: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x808000A8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x808000AC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x808000B0: sh          $t5, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r13;
    // 0x808000B4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x808000B8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x808000BC: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x808000C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808000C4:
    // 0x808000C4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x808000C8: bnel        $at, $zero, L_80800094
    if (ctx->r1 != 0) {
        // 0x808000CC: lhu         $t3, 0x2($v1)
        ctx->r11 = MEM_HU(ctx->r3, 0X2);
            goto L_80800094;
    }
    goto skip_1;
    // 0x808000CC: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    skip_1:
L_808000D0:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_8008BCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BCB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BCB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BCBC: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x8008BCC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008BCC4: beq         $t6, $zero, L_8008BCD4
    if (ctx->r14 == 0) {
        // 0x8008BCC8: nop
    
            goto L_8008BCD4;
    }
    // 0x8008BCC8: nop

    // 0x8008BCCC: b           L_8008BCD4
    // 0x8008BCD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8008BCD4;
    // 0x8008BCD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008BCD4:
    // 0x8008BCD4: jal         0x8008BC6C
    // 0x8008BCD8: nop

    func_8008BC6C(rdram, ctx);
        goto after_0;
    // 0x8008BCD8: nop

    after_0:
    // 0x8008BCDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BCE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BCE4: jr          $ra
    // 0x8008BCE8: nop

    return;
    // 0x8008BCE8: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089428: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089428);
    return;
    // 0x8008942C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80801838_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801838: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080183C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801840: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801844: jal         0x800D8FF8
    // 0x80801848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80801848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080184C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801850: jal         0x800DA298
    // 0x80801854: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801854: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80801858: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080185C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801860: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80801864: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80801868: jal         0x80089C90
    // 0x8080186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801870: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80801874: bne         $v0, $at, L_80801884
    if (ctx->r2 != ctx->r1) {
        // 0x80801878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801884;
    }
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080187C: b           L_80801888
    // 0x80801880: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80801888;
    // 0x80801880: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80801884:
    // 0x80801884: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80801888:
    // 0x80801888: jal         0x8010A800
    // 0x8080188C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x8080188C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x80801890: jal         0x800D90A4
    // 0x80801894: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80801894: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x80801898: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080189C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808018A0: bnel        $t7, $zero, L_808018D0
    if (ctx->r15 != 0) {
        // 0x808018A4: lhu         $a2, 0x72($s0)
        ctx->r6 = MEM_HU(ctx->r16, 0X72);
            goto L_808018D0;
    }
    goto skip_0;
    // 0x808018A4: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808018A8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808018AC: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x808018B0: jal         0x800CEAD0
    // 0x808018B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_5;
    // 0x808018B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_5:
    // 0x808018B8: beql        $v0, $zero, L_808018D0
    if (ctx->r2 == 0) {
        // 0x808018BC: lhu         $a2, 0x72($s0)
        ctx->r6 = MEM_HU(ctx->r16, 0X72);
            goto L_808018D0;
    }
    goto skip_1;
    // 0x808018BC: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x808018C0: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808018C4: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808018C8: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808018CC: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
L_808018D0:
    // 0x808018D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808018D4: srl         $t2, $a2, 10
    ctx->r10 = S32(U32(ctx->r6) >> 10);
    // 0x808018D8: beq         $t2, $at, L_80801920
    if (ctx->r10 == ctx->r1) {
        // 0x808018DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801920;
    }
    // 0x808018DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808018E0: beq         $t2, $at, L_80801910
    if (ctx->r10 == ctx->r1) {
        // 0x808018E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801910;
    }
    // 0x808018E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808018E8: beq         $t2, $at, L_80801900
    if (ctx->r10 == ctx->r1) {
        // 0x808018EC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80801900;
    }
    // 0x808018EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808018F0: beq         $t2, $at, L_80801930
    if (ctx->r10 == ctx->r1) {
        // 0x808018F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801930;
    }
    // 0x808018F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F8: b           L_8080195C
    // 0x808018FC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
        goto L_8080195C;
    // 0x808018FC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80801900:
    // 0x80801900: jal         0x800DA298
    // 0x80801904: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801904: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80801908: b           L_80801958
    // 0x8080190C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80801958;
    // 0x8080190C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80801910:
    // 0x80801910: jal         0x800DA298
    // 0x80801914: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80801914: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80801918: b           L_80801958
    // 0x8080191C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80801958;
    // 0x8080191C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80801920:
    // 0x80801920: jal         0x800DA298
    // 0x80801924: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80801924: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80801928: b           L_80801958
    // 0x8080192C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80801958;
    // 0x8080192C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80801930:
    // 0x80801930: jal         0x80089C90
    // 0x80801934: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80801934: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_9:
    // 0x80801938: bnel        $v0, $zero, L_8080195C
    if (ctx->r2 != 0) {
        // 0x8080193C: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_8080195C;
    }
    goto skip_2;
    // 0x8080193C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80801940: jal         0x80801DCC
    // 0x80801944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DCC_chhoopswoop(rdram, ctx);
        goto after_10;
    // 0x80801944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801948: jal         0x800FFAB0
    // 0x8080194C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x8080194C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801950: b           L_80801A00
    // 0x80801954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801A00;
    // 0x80801954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801958:
    // 0x80801958: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_8080195C:
    // 0x8080195C: bnel        $t3, $zero, L_80801970
    if (ctx->r11 != 0) {
        // 0x80801960: lwc1        $f4, 0x50($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80801970;
    }
    goto skip_3;
    // 0x80801960: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    skip_3:
    // 0x80801964: jal         0x80801AB4
    // 0x80801968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AB4_chhoopswoop(rdram, ctx);
        goto after_12;
    // 0x80801968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080196C: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
L_80801970:
    // 0x80801970: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801974: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80801978: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080197C: jal         0x800136E4
    // 0x80801980: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_13;
    // 0x80801980: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_13:
    // 0x80801984: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80801988: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8080198C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80801990: beql        $t4, $zero, L_80801A00
    if (ctx->r12 == 0) {
        // 0x80801994: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A00;
    }
    goto skip_4;
    // 0x80801994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80801998: bne         $t5, $zero, L_808019BC
    if (ctx->r13 != 0) {
        // 0x8080199C: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_808019BC;
    }
    // 0x8080199C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808019A0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808019A4: bne         $t6, $zero, L_808019DC
    if (ctx->r14 != 0) {
        // 0x808019A8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808019DC;
    }
    // 0x808019A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808019AC: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808019B0: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808019B4: bltz        $t9, L_808019DC
    if (SIGNED(ctx->r25) < 0) {
        // 0x808019B8: nop
    
            goto L_808019DC;
    }
    // 0x808019B8: nop

L_808019BC:
    // 0x808019BC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808019C0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808019C4: beql        $t0, $zero, L_80801A00
    if (ctx->r8 == 0) {
        // 0x808019C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A00;
    }
    goto skip_5;
    // 0x808019C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808019CC: beq         $t1, $zero, L_808019FC
    if (ctx->r9 == 0) {
        // 0x808019D0: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_808019FC;
    }
    // 0x808019D0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808019D4: sltu        $t2, $zero, $v0
    ctx->r10 = 0 < ctx->r2 ? 1 : 0;
    // 0x808019D8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_808019DC:
    // 0x808019DC: beq         $v0, $zero, L_808019F0
    if (ctx->r2 == 0) {
        // 0x808019E0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_808019F0;
    }
    // 0x808019E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808019E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808019E8: sltiu       $t3, $a2, 0x1
    ctx->r11 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x808019EC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_808019F0:
    // 0x808019F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019F4: jal         0x80801A10
    // 0x808019F8: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_80801A10_chhoopswoop(rdram, ctx);
        goto after_14;
    // 0x808019F8: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_14:
L_808019FC:
    // 0x808019FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A00:
    // 0x80801A00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801A08: jr          $ra
    // 0x80801A0C: nop

    return;
    // 0x80801A0C: nop

;}
RECOMP_FUNC void func_80800454_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080045C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800464: jal         0x80095774
    // 0x80800468: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x80800468: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_0:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80095774
    // 0x80800474: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x80800474: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_1:
    // 0x80800478: jal         0x8009E704
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getNextState(rdram, ctx);
        goto after_2;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800480: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800484: beq         $v0, $at, L_8080049C
    if (ctx->r2 == ctx->r1) {
        // 0x80800488: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_8080049C;
    }
    // 0x80800488: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8080048C: beq         $v0, $at, L_8080049C
    if (ctx->r2 == ctx->r1) {
        // 0x80800490: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_8080049C;
    }
    // 0x80800490: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800494: bne         $v0, $at, L_808004D0
    if (ctx->r2 != ctx->r1) {
        // 0x80800498: nop
    
            goto L_808004D0;
    }
    // 0x80800498: nop

L_8080049C:
    // 0x8080049C: jal         0x80084C98
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004A8: bne         $v0, $at, L_808004D0
    if (ctx->r2 != ctx->r1) {
        // 0x808004AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D0;
    }
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x80095760
    // 0x808004B4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    baflag_set(rdram, ctx);
        goto after_4;
    // 0x808004B4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_4:
    // 0x808004B8: jal         0x80084CA0
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004C0: beq         $v0, $zero, L_808004D0
    if (ctx->r2 == 0) {
        // 0x808004C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D0;
    }
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x80095760
    // 0x808004CC: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_set(rdram, ctx);
        goto after_6;
    // 0x808004CC: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_6:
L_808004D0:
    // 0x808004D0: jal         0x80084D00
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x80084BF8
    // 0x808004E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _bafly_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808004E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x80084C00
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafly_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808004F0: jal         0x80800188
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800188_bsbfly(rdram, ctx);
        goto after_10;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808004F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800500: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800504: jr          $ra
    // 0x80800508: nop

    return;
    // 0x80800508: nop

;}
RECOMP_FUNC void func_8009CF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CF90: jr          $ra
    // 0x8009CF94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x8009CF94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801310_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801310: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801318: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080131C: jal         0x80110024
    // 0x80801320: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80801320: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801324: jal         0x800894E0
    // 0x80801328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpod_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080132C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80801330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801334: addiu       $a1, $v1, 0x158
    ctx->r5 = ADD32(ctx->r3, 0X158);
    // 0x80801338: addiu       $a2, $v1, 0x164
    ctx->r6 = ADD32(ctx->r3, 0X164);
    // 0x8080133C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80801340: jal         0x808012A0
    // 0x80801344: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_808012A0_ncpoddialog(rdram, ctx);
        goto after_2;
    // 0x80801344: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80801348: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080134C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801350: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    // 0x80801354: jal         0x800EE7F8
    // 0x80801358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80801358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x8080135C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801360: jal         0x800EE7F8
    // 0x80801364: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801364: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80801368: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080136C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801370: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80801374: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80801378: lui         $a3, 0xC3FA
    ctx->r7 = S32(0XC3FA << 16);
    // 0x8080137C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801380: jal         0x800EF214
    // 0x80801384: nop

    func_800EF214(rdram, ctx);
        goto after_5;
    // 0x80801384: nop

    after_5:
    // 0x80801388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080138C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801390: jr          $ra
    // 0x80801394: nop

    return;
    // 0x80801394: nop

;}
RECOMP_FUNC void func_800260B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800260B0: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800260B4: bne         $t6, $zero, L_800260C4
    if (ctx->r14 != 0) {
        // 0x800260B8: nop
    
            goto L_800260C4;
    }
    // 0x800260B8: nop

    // 0x800260BC: jr          $ra
    // 0x800260C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800260C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800260C4:
    // 0x800260C4: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x800260C8: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x800260CC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800260D0: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800260D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800260D8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800260DC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800260E0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800260E4: jr          $ra
    // 0x800260E8: nop

    return;
    // 0x800260E8: nop

;}
RECOMP_FUNC void bskazstill_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080067C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800680: jal         0x808001A4
    // 0x80800684: nop

    func_808001A4_bskazstill(rdram, ctx);
        goto after_0;
    // 0x80800684: nop

    after_0:
    // 0x80800688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080068C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800690: jr          $ra
    // 0x80800694: nop

    return;
    // 0x80800694: nop

;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835C0: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835C0);
    return;
    // 0x800835C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80093864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093864: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80093868: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009386C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80093870: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80093874: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80093878: beq         $a2, $zero, L_80093894
    if (ctx->r6 == 0) {
        // 0x8009387C: sw          $a2, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r6;
            goto L_80093894;
    }
    // 0x8009387C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80093880: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80093884: beql        $a2, $at, L_80093974
    if (ctx->r6 == ctx->r1) {
        // 0x80093888: lw          $t2, 0x50($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X50);
            goto L_80093974;
    }
    goto skip_0;
    // 0x80093888: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x8009388C: b           L_80093A40
    // 0x80093890: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
        goto L_80093A40;
    // 0x80093890: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
L_80093894:
    // 0x80093894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093898: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8009389C: jal         0x8009216C
    // 0x800938A0: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_8009216C(rdram, ctx);
        goto after_0;
    // 0x800938A0: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x800938A4: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x800938A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800938AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800938B0: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800938B4: jal         0x80092B04
    // 0x800938B8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    func_80092B04(rdram, ctx);
        goto after_1;
    // 0x800938B8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800938BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800938C0: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x800938C4: jal         0x800AE080
    // 0x800938C8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    func_800AE080(rdram, ctx);
        goto after_2;
    // 0x800938C8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    after_2:
    // 0x800938CC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800938D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800938D4: beql        $t9, $zero, L_80093A40
    if (ctx->r25 == 0) {
        // 0x800938D8: lw          $a1, 0x50($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X50);
            goto L_80093A40;
    }
    goto skip_1;
    // 0x800938D8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    skip_1:
    // 0x800938DC: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800938E0: lbu         $v1, 0x12($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X12);
    // 0x800938E4: beq         $v1, $zero, L_8009391C
    if (ctx->r3 == 0) {
        // 0x800938E8: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_8009391C;
    }
    // 0x800938E8: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x800938EC: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800938F0: jal         0x80100AC4
    // 0x800938F4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80100AC4(rdram, ctx);
        goto after_3;
    // 0x800938F4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x800938F8: jal         0x800DF720
    // 0x800938FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_4;
    // 0x800938FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80093900: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x80093904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093908: jal         0x80100A74
    // 0x8009390C: lbu         $a0, 0x12($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X12);
    func_80100A74(rdram, ctx);
        goto after_5;
    // 0x8009390C: lbu         $a0, 0x12($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X12);
    after_5:
    // 0x80093910: jal         0x800DF818
    // 0x80093914: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_6;
    // 0x80093914: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80093918: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
L_8009391C:
    // 0x8009391C: jal         0x800DF714
    // 0x80093920: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_800DF714(rdram, ctx);
        goto after_7;
    // 0x80093920: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_7:
    // 0x80093924: jal         0x800DF72C
    // 0x80093928: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800DF72C(rdram, ctx);
        goto after_8;
    // 0x80093928: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x8009392C: jal         0x800A06E8
    // 0x80093930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A06E8(rdram, ctx);
        goto after_9;
    // 0x80093930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80093934: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80093938: addiu       $a0, $a0, 0x2234
    ctx->r4 = ADD32(ctx->r4, 0X2234);
    // 0x8009393C: jal         0x800DF47C
    // 0x80093940: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_10;
    // 0x80093940: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x80093944: jal         0x800DF440
    // 0x80093948: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_11;
    // 0x80093948: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8009394C: jal         0x800A946C
    // 0x80093950: nop

    func_800A946C(rdram, ctx);
        goto after_12;
    // 0x80093950: nop

    after_12:
    // 0x80093954: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80093958: bnel        $v0, $at, L_80093A40
    if (ctx->r2 != ctx->r1) {
        // 0x8009395C: lw          $a1, 0x50($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X50);
            goto L_80093A40;
    }
    goto skip_2;
    // 0x8009395C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    skip_2:
    // 0x80093960: jal         0x800DF574
    // 0x80093964: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF574(rdram, ctx);
        goto after_13;
    // 0x80093964: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80093968: b           L_80093A40
    // 0x8009396C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
        goto L_80093A40;
    // 0x8009396C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093970: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
L_80093974:
    // 0x80093974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093978: lwc1        $f6, 0x98($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X98);
    // 0x8009397C: jal         0x80093738
    // 0x80093980: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    func_80093738(rdram, ctx);
        goto after_14;
    // 0x80093980: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80093984: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80093988: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x8009398C: jal         0x800AE080
    // 0x80093990: lh          $a0, 0x90($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X90);
    func_800AE080(rdram, ctx);
        goto after_15;
    // 0x80093990: lh          $a0, 0x90($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X90);
    after_15:
    // 0x80093994: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80093998: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x8009399C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800939A0: jal         0x800EE7F8
    // 0x800939A4: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x800939A4: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_16:
    // 0x800939A8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800939AC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800939B0: jal         0x800EE7F8
    // 0x800939B4: addiu       $a1, $a1, 0xB8
    ctx->r5 = ADD32(ctx->r5, 0XB8);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x800939B4: addiu       $a1, $a1, 0xB8
    ctx->r5 = ADD32(ctx->r5, 0XB8);
    after_17:
    // 0x800939B8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800939BC: beql        $t4, $zero, L_80093A40
    if (ctx->r12 == 0) {
        // 0x800939C0: lw          $a1, 0x50($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X50);
            goto L_80093A40;
    }
    goto skip_3;
    // 0x800939C0: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    skip_3:
    // 0x800939C4: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800939C8: lbu         $v1, 0xA0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA0);
    // 0x800939CC: beq         $v1, $zero, L_80093A04
    if (ctx->r3 == 0) {
        // 0x800939D0: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_80093A04;
    }
    // 0x800939D0: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x800939D4: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800939D8: jal         0x80100AC4
    // 0x800939DC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80100AC4(rdram, ctx);
        goto after_18;
    // 0x800939DC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_18:
    // 0x800939E0: jal         0x800DF720
    // 0x800939E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_19;
    // 0x800939E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x800939E8: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x800939EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800939F0: jal         0x80100A74
    // 0x800939F4: lbu         $a0, 0xA0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XA0);
    func_80100A74(rdram, ctx);
        goto after_20;
    // 0x800939F4: lbu         $a0, 0xA0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0XA0);
    after_20:
    // 0x800939F8: jal         0x800DF818
    // 0x800939FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_21;
    // 0x800939FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x80093A00: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
L_80093A04:
    // 0x80093A04: jal         0x800DF714
    // 0x80093A08: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    func_800DF714(rdram, ctx);
        goto after_22;
    // 0x80093A08: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    after_22:
    // 0x80093A0C: jal         0x800DF72C
    // 0x80093A10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800DF72C(rdram, ctx);
        goto after_23;
    // 0x80093A10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_23:
    // 0x80093A14: jal         0x800DF3E0
    // 0x80093A18: nop

    func_800DF3E0(rdram, ctx);
        goto after_24;
    // 0x80093A18: nop

    after_24:
    // 0x80093A1C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80093A20: addiu       $a0, $a0, 0x2224
    ctx->r4 = ADD32(ctx->r4, 0X2224);
    // 0x80093A24: jal         0x800DF47C
    // 0x80093A28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_25;
    // 0x80093A28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_25:
    // 0x80093A2C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80093A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093A34: jal         0x800A0714
    // 0x80093A38: lh          $a1, 0x9C($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X9C);
    func_800A0714(rdram, ctx);
        goto after_26;
    // 0x80093A38: lh          $a1, 0x9C($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X9C);
    after_26:
    // 0x80093A3C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
L_80093A40:
    // 0x80093A40: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80093A44: jal         0x800EE7F8
    // 0x80093A48: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_27;
    // 0x80093A48: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_27:
    // 0x80093A4C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093A50: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80093A54: jal         0x800EF04C
    // 0x80093A58: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_28;
    // 0x80093A58: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_28:
    // 0x80093A5C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093A60: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80093A64: jal         0x800EF04C
    // 0x80093A68: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_29;
    // 0x80093A68: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_29:
    // 0x80093A6C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80093A70: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80093A74: beq         $t8, $zero, L_80093AA4
    if (ctx->r24 == 0) {
        // 0x80093A78: sltiu       $t9, $a1, 0x1
        ctx->r25 = ctx->r5 < 0X1 ? 1 : 0;
            goto L_80093AA4;
    }
    // 0x80093A78: sltiu       $t9, $a1, 0x1
    ctx->r25 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80093A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093A80: jal         0x800923A8
    // 0x80093A84: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800923A8(rdram, ctx);
        goto after_30;
    // 0x80093A84: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_30:
    // 0x80093A88: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80093A8C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80093A90: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80093A94: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80093A98: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x80093A9C: jal         0x800DE448
    // 0x80093AA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800DE448(rdram, ctx);
        goto after_31;
    // 0x80093AA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_31:
L_80093AA4:
    // 0x80093AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80093AA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80093AAC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80093AB0: jr          $ra
    // 0x80093AB4: nop

    return;
    // 0x80093AB4: nop

;}
RECOMP_FUNC void chbanjoctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F4: jal         0x800F54E4
    // 0x808005F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808005F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800600: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800604: jal         0x800F798C
    // 0x80800608: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F798C(rdram, ctx);
        goto after_1;
    // 0x80800608: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8080060C: beql        $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x80800610: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800628;
    }
    goto skip_0;
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800614: jal         0x80800544
    // 0x80800618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800544_chbanjoctrl(rdram, ctx);
        goto after_2;
    // 0x80800618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080061C: b           L_80800628
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800628;
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800628:
    // 0x80800628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080062C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800630: jr          $ra
    // 0x80800634: nop

    return;
    // 0x80800634: nop

;}
RECOMP_FUNC void func_800EEF24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEF24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EEF28: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEF2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEF30: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800EEF34: nop

    // 0x800EEF38: bc1t        L_800EEF44
    if (c1cs) {
        // 0x800EEF3C: nop
    
            goto L_800EEF44;
    }
    // 0x800EEF3C: nop

    // 0x800EEF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEF44:
    // 0x800EEF44: bne         $v0, $zero, L_800EEF8C
    if (ctx->r2 != 0) {
        // 0x800EEF48: nop
    
            goto L_800EEF8C;
    }
    // 0x800EEF48: nop

    // 0x800EEF4C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEF50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEF54: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800EEF58: nop

    // 0x800EEF5C: bc1t        L_800EEF68
    if (c1cs) {
        // 0x800EEF60: nop
    
            goto L_800EEF68;
    }
    // 0x800EEF60: nop

    // 0x800EEF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEF68:
    // 0x800EEF68: bne         $v0, $zero, L_800EEF8C
    if (ctx->r2 != 0) {
        // 0x800EEF6C: nop
    
            goto L_800EEF8C;
    }
    // 0x800EEF6C: nop

    // 0x800EEF70: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEF78: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800EEF7C: nop

    // 0x800EEF80: bc1t        L_800EEF8C
    if (c1cs) {
        // 0x800EEF84: nop
    
            goto L_800EEF8C;
    }
    // 0x800EEF84: nop

    // 0x800EEF88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEF8C:
    // 0x800EEF8C: jr          $ra
    // 0x800EEF90: nop

    return;
    // 0x800EEF90: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x808005FC: xori        $t6, $v0, 0x65
    ctx->r14 = ctx->r2 ^ 0X65;
    // 0x80800600: jr          $ra
    // 0x80800604: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x80800604: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80800000_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1118) << 16);
    // 0x80800010: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800014: lw          $a2, 0x24($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X24);
    // 0x80800018: addiu       $v0, $v0, 0x1118
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1118));
    // 0x8080001C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800020: srl         $t7, $a2, 22
    ctx->r15 = S32(U32(ctx->r6) >> 22);
    // 0x80800024: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_80800028:
    // 0x80800028: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8080002C: beql        $a2, $t8, L_80800048
    if (ctx->r6 == ctx->r24) {
        // 0x80800030: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80800048;
    }
    goto skip_0;
    // 0x80800030: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_0:
    // 0x80800034: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800038: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8080003C: bne         $at, $zero, L_80800028
    if (ctx->r1 != 0) {
        // 0x80800040: addiu       $v0, $v0, 0xE
        ctx->r2 = ADD32(ctx->r2, 0XE);
            goto L_80800028;
    }
    // 0x80800040: addiu       $v0, $v0, 0xE
    ctx->r2 = ADD32(ctx->r2, 0XE);
    // 0x80800044: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_80800048:
    // 0x80800048: bnel        $v1, $at, L_80800064
    if (ctx->r3 != ctx->r1) {
        // 0x8080004C: sw          $v1, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->r3;
            goto L_80800064;
    }
    goto skip_1;
    // 0x8080004C: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
    skip_1:
    // 0x80800050: jal         0x800FFAB0
    // 0x80800054: nop

    func_800FFAB0(rdram, ctx);
        goto after_0;
    // 0x80800054: nop

    after_0:
    // 0x80800058: b           L_8080008C
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080008C;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800060: sw          $v1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r3;
L_80800064:
    // 0x80800064: jal         0x80089F48
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080006C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800070: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800074: beq         $v0, $at, L_80800088
    if (ctx->r2 == ctx->r1) {
        // 0x80800078: sw          $v0, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r2;
            goto L_80800088;
    }
    // 0x80800078: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // 0x8080007C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800080: jal         0x80089F50
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800088:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_80800178_chdiggerbossinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080017C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800180: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800184: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800188: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080018C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800190: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800194: jal         0x8008A0C8
    // 0x80800198: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800198: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8080019C: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001A0: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80800210;
    }
    // 0x808001A0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001A4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001A8: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x808001AC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001B0: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x808001B4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808001B8: jal         0x80108528
    // 0x808001BC: nop

    func_80108528(rdram, ctx);
        goto after_1;
    // 0x808001BC: nop

    after_1:
    // 0x808001C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001C4: lhu         $t3, 0x76($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X76);
    // 0x808001C8: lbu         $t9, 0x65($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X65);
    // 0x808001CC: lbu         $t1, 0x75($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X75);
    // 0x808001D0: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x808001D4: ori         $t5, $t4, 0x3200
    ctx->r13 = ctx->r12 | 0X3200;
    // 0x808001D8: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x808001DC: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x808001E0: sb          $t0, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r8;
    // 0x808001E4: sb          $t2, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r10;
    // 0x808001E8: sh          $t5, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r13;
    // 0x808001EC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808001F0: jal         0x80102FDC
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808001F8: lui         $a1, 0x2000
    ctx->r5 = S32(0X2000 << 16);
    // 0x808001FC: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x80800200: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800208: jal         0x80108658
    // 0x8080020C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80108658(rdram, ctx);
        goto after_3;
    // 0x8080020C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_80800210:
    // 0x80800210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800214: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800218: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

    // 0x80800224: nop

    // 0x80800228: nop

    // 0x8080022C: nop

;}
RECOMP_FUNC void func_80801834_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801838: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080183C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801840: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80801844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801848: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080184C: jal         0x800EE7F8
    // 0x80801850: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801850: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80801854: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801858: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080185C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801860: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801864: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801868: jal         0x800EFA4C
    // 0x8080186C: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080186C: nop

    after_1:
    // 0x80801870: jal         0x800DA298
    // 0x80801874: addiu       $a0, $zero, 0x187
    ctx->r4 = ADD32(0, 0X187);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80801874: addiu       $a0, $zero, 0x187
    ctx->r4 = ADD32(0, 0X187);
    after_2:
    // 0x80801878: beq         $v0, $zero, L_80801894
    if (ctx->r2 == 0) {
        // 0x8080187C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801894;
    }
    // 0x8080187C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801884: jal         0x80801790
    // 0x80801888: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801790_chlakemonster(rdram, ctx);
        goto after_3;
    // 0x80801888: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8080188C: b           L_808018A0
    // 0x80801890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808018A0;
    // 0x80801890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801894:
    // 0x80801894: jal         0x80801790
    // 0x80801898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801790_chlakemonster(rdram, ctx);
        goto after_4;
    // 0x80801898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080189C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808018A0:
    // 0x808018A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018A4: jr          $ra
    // 0x808018A8: nop

    return;
    // 0x808018A8: nop

;}
RECOMP_FUNC void _bsbanshack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082710: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082710);
    return;
    // 0x80082714: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808001E0_sumole(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808001F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001FC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800200: jal         0x800EE7F8
    // 0x80800204: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800204: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800208: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080020C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800210: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800214: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800218: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x8080021C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800220: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800224: jal         0x800EF1B8
    // 0x80800228: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800228: nop

    after_1:
    // 0x8080022C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800230: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3158, 0X2530) << 16);
    // 0x80800234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800238: beq         $a3, $zero, L_80800290
    if (ctx->r7 == 0) {
        // 0x8080023C: addiu       $a0, $a0, 0x2530
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3158, 0X2530));
            goto L_80800290;
    }
    // 0x8080023C: addiu       $a0, $a0, 0x2530
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3158, 0X2530));
    // 0x80800240: beq         $a3, $at, L_80800268
    if (ctx->r7 == ctx->r1) {
        // 0x80800244: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3158, 0X2510) << 16);
            goto L_80800268;
    }
    // 0x80800244: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3158, 0X2510) << 16);
    // 0x80800248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080024C: beq         $a3, $at, L_8080027C
    if (ctx->r7 == ctx->r1) {
        // 0x80800250: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3158, 0X2520) << 16);
            goto L_8080027C;
    }
    // 0x80800250: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3158, 0X2520) << 16);
    // 0x80800254: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800258: beq         $a3, $at, L_8080027C
    if (ctx->r7 == ctx->r1) {
        // 0x8080025C: nop
    
            goto L_8080027C;
    }
    // 0x8080025C: nop

    // 0x80800260: b           L_8080029C
    // 0x80800264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8080029C;
    // 0x80800264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800268:
    // 0x80800268: addiu       $a0, $a0, 0x2510
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3158, 0X2510));
    // 0x8080026C: jal         0x80088090
    // 0x80800270: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800270: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800274: b           L_8080029C
    // 0x80800278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8080029C;
    // 0x80800278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080027C:
    // 0x8080027C: addiu       $a0, $a0, 0x2520
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3158, 0X2520));
    // 0x80800280: jal         0x80088090
    // 0x80800284: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800284: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80800288: b           L_8080029C
    // 0x8080028C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8080029C;
    // 0x8080028C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800290:
    // 0x80800290: jal         0x80088090
    // 0x80800294: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800294: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80800298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080029C:
    // 0x8080029C: jal         0x800856F0
    // 0x808002A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _capod_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808002A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808002A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002A8: jal         0x800856F8
    // 0x808002AC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    _capod_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808002AC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_6:
    // 0x808002B0: jal         0x80085700
    // 0x808002B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x808002B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x808002B8: jal         0x800880B8
    // 0x808002BC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x808002BC: nop

    after_8:
    // 0x808002C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808002C4: jal         0x800856F0
    // 0x808002C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _capod_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x808002C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_8009E970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E974: jr          $ra
    // 0x8009E978: lwc1        $f0, 0x7048($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7048);
    return;
    // 0x8009E978: lwc1        $f0, 0x7048($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7048);
;}
RECOMP_FUNC void func_80800B7C_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B80: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B84: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B94: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800B98: jal         0x80100094
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BA0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800BA8: slti        $at, $a2, 0x97
    ctx->r1 = SIGNED(ctx->r6) < 0X97 ? 1 : 0;
    // 0x80800BAC: bne         $at, $zero, L_80800BD0
    if (ctx->r1 != 0) {
        // 0x80800BB0: addiu       $t6, $a2, -0xA
        ctx->r14 = ADD32(ctx->r6, -0XA);
            goto L_80800BD0;
    }
    // 0x80800BB0: addiu       $t6, $a2, -0xA
    ctx->r14 = ADD32(ctx->r6, -0XA);
    // 0x80800BB4: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80800BB8: beq         $a2, $at, L_80800E10
    if (ctx->r6 == ctx->r1) {
        // 0x80800BBC: addiu       $at, $zero, 0xA2
        ctx->r1 = ADD32(0, 0XA2);
            goto L_80800E10;
    }
    // 0x80800BBC: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80800BC0: beq         $a2, $at, L_80800E2C
    if (ctx->r6 == ctx->r1) {
        // 0x80800BC4: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800E2C;
    }
    // 0x80800BC4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800BC8: b           L_80800F04
    // 0x80800BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BD0:
    // 0x80800BD0: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x80800BD4: bne         $at, $zero, L_80800BEC
    if (ctx->r1 != 0) {
        // 0x80800BD8: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80800BEC;
    }
    // 0x80800BD8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80800BDC: beq         $a2, $at, L_80800DD4
    if (ctx->r6 == ctx->r1) {
        // 0x80800BE0: nop
    
            goto L_80800DD4;
    }
    // 0x80800BE0: nop

    // 0x80800BE4: b           L_80800F04
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BEC:
    // 0x80800BEC: slti        $at, $a2, 0x4A
    ctx->r1 = SIGNED(ctx->r6) < 0X4A ? 1 : 0;
    // 0x80800BF0: bne         $at, $zero, L_80800C08
    if (ctx->r1 != 0) {
        // 0x80800BF4: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800C08;
    }
    // 0x80800BF4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800BF8: beq         $a2, $at, L_80800D8C
    if (ctx->r6 == ctx->r1) {
        // 0x80800BFC: addiu       $a0, $zero, 0x377
        ctx->r4 = ADD32(0, 0X377);
            goto L_80800D8C;
    }
    // 0x80800BFC: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    // 0x80800C00: b           L_80800F04
    // 0x80800C04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800C04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C08:
    // 0x80800C08: sltiu       $at, $t6, 0x40
    ctx->r1 = ctx->r14 < 0X40 ? 1 : 0;
    // 0x80800C0C: beq         $at, $zero, L_80800EF8
    if (ctx->r1 == 0) {
        // 0x80800C10: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800EF8;
    }
    // 0x80800C10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800C14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2B8C) << 16);
    // 0x80800C18: addu        $at, $at, $t6
    gpr jr_addend_80800C20 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800C1C: lw          $t6, 0x2B8C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2B8C));
    // 0x80800C20: jr          $t6
    // 0x80800C24: nop

    switch (jr_addend_80800C20 >> 2) {
        case 0: goto L_80800D14; break;
        case 1: goto L_80800CB4; break;
        case 2: goto L_80800EF8; break;
        case 3: goto L_80800EF8; break;
        case 4: goto L_80800EF8; break;
        case 5: goto L_80800EF8; break;
        case 6: goto L_80800EF8; break;
        case 7: goto L_80800EF8; break;
        case 8: goto L_80800EF8; break;
        case 9: goto L_80800EF8; break;
        case 10: goto L_80800EF8; break;
        case 11: goto L_80800EF8; break;
        case 12: goto L_80800EF8; break;
        case 13: goto L_80800EF8; break;
        case 14: goto L_80800EF8; break;
        case 15: goto L_80800EF8; break;
        case 16: goto L_80800EF8; break;
        case 17: goto L_80800EF8; break;
        case 18: goto L_80800EF8; break;
        case 19: goto L_80800EF8; break;
        case 20: goto L_80800EF8; break;
        case 21: goto L_80800EE0; break;
        case 22: goto L_80800EF8; break;
        case 23: goto L_80800EF8; break;
        case 24: goto L_80800EF8; break;
        case 25: goto L_80800EF8; break;
        case 26: goto L_80800EF8; break;
        case 27: goto L_80800EF8; break;
        case 28: goto L_80800EF8; break;
        case 29: goto L_80800EF8; break;
        case 30: goto L_80800EF8; break;
        case 31: goto L_80800EF8; break;
        case 32: goto L_80800EF8; break;
        case 33: goto L_80800EF8; break;
        case 34: goto L_80800EF8; break;
        case 35: goto L_80800EF8; break;
        case 36: goto L_80800C98; break;
        case 37: goto L_80800EF8; break;
        case 38: goto L_80800EF8; break;
        case 39: goto L_80800EF8; break;
        case 40: goto L_80800D6C; break;
        case 41: goto L_80800EF8; break;
        case 42: goto L_80800EF8; break;
        case 43: goto L_80800EF8; break;
        case 44: goto L_80800EF8; break;
        case 45: goto L_80800EF8; break;
        case 46: goto L_80800EF8; break;
        case 47: goto L_80800EF8; break;
        case 48: goto L_80800EF8; break;
        case 49: goto L_80800EF8; break;
        case 50: goto L_80800EF8; break;
        case 51: goto L_80800C28; break;
        case 52: goto L_80800EF8; break;
        case 53: goto L_80800EF8; break;
        case 54: goto L_80800CFC; break;
        case 55: goto L_80800EF8; break;
        case 56: goto L_80800EF8; break;
        case 57: goto L_80800EF8; break;
        case 58: goto L_80800EF8; break;
        case 59: goto L_80800EF8; break;
        case 60: goto L_80800EF8; break;
        case 61: goto L_80800EF8; break;
        case 62: goto L_80800EF8; break;
        case 63: goto L_80800D3C; break;
        default: switch_error(__func__, 0x80800C20, 0x80802B8C);
    }
    // 0x80800C24: nop

L_80800C28:
    // 0x80800C28: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800C2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C30: beq         $a0, $zero, L_80800C58
    if (ctx->r4 == 0) {
        // 0x80800C34: nop
    
            goto L_80800C58;
    }
    // 0x80800C34: nop

    // 0x80800C38: beq         $a0, $at, L_80800C68
    if (ctx->r4 == ctx->r1) {
        // 0x80800C3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C68;
    }
    // 0x80800C3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C40: beq         $a0, $at, L_80800C78
    if (ctx->r4 == ctx->r1) {
        // 0x80800C44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800C78;
    }
    // 0x80800C44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C48: beq         $a0, $at, L_80800C88
    if (ctx->r4 == ctx->r1) {
        // 0x80800C4C: nop
    
            goto L_80800C88;
    }
    // 0x80800C4C: nop

    // 0x80800C50: b           L_80800F04
    // 0x80800C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C58:
    // 0x80800C58: jal         0x80801D0C
    // 0x80800C5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801D0C_changlerboss(rdram, ctx);
        goto after_1;
    // 0x80800C5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800C60: b           L_80800F04
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C68:
    // 0x80800C68: jal         0x80801E3C
    // 0x80800C6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801E3C_changlerboss(rdram, ctx);
        goto after_2;
    // 0x80800C6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800C70: b           L_80800F04
    // 0x80800C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C78:
    // 0x80800C78: jal         0x80801F54
    // 0x80800C7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801F54_changlerboss(rdram, ctx);
        goto after_3;
    // 0x80800C7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800C80: b           L_80800F04
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C88:
    // 0x80800C88: jal         0x80802108
    // 0x80800C8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802108_changlerboss(rdram, ctx);
        goto after_4;
    // 0x80800C8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800C90: b           L_80800F04
    // 0x80800C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800C94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C98:
    // 0x80800C98: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800C9C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800CA0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800CA4: jal         0x8080170C
    // 0x80800CA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080170C_changlerboss(rdram, ctx);
        goto after_5;
    // 0x80800CA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800CAC: b           L_80800F04
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB4:
    // 0x80800CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800CB8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800CBC: beq         $a0, $at, L_80800CF0
    if (ctx->r4 == ctx->r1) {
        // 0x80800CC0: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80800CF0;
    }
    // 0x80800CC0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80800CC4: bne         $a0, $at, L_80800CF4
    if (ctx->r4 != ctx->r1) {
        // 0x80800CC8: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80800CF4;
    }
    // 0x80800CC8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800CCC: addiu       $a0, $zero, 0x46C
    ctx->r4 = ADD32(0, 0X46C);
    // 0x80800CD0: jal         0x80101180
    // 0x80800CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800CD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CDC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800CE0: jal         0x808021E4
    // 0x80800CE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_7;
    // 0x80800CE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_7:
    // 0x80800CE8: b           L_80800F04
    // 0x80800CEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F04;
    // 0x80800CEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800CF0:
    // 0x80800CF0: sb          $zero, 0x12B($v0)
    MEM_B(0X12B, ctx->r2) = 0;
L_80800CF4:
    // 0x80800CF4: b           L_80800F04
    // 0x80800CF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F04;
    // 0x80800CF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800CFC:
    // 0x80800CFC: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800D00: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D04: jal         0x80801070
    // 0x80800D08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801070_changlerboss(rdram, ctx);
        goto after_8;
    // 0x80800D08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800D0C: b           L_80800F04
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D14:
    // 0x80800D14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800D18: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800D1C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800D20: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800D24: bnel        $t8, $at, L_80800F04
    if (ctx->r24 != ctx->r1) {
        // 0x80800D28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F04;
    }
    goto skip_0;
    // 0x80800D28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800D2C: jal         0x808012E0
    // 0x80800D30: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_9;
    // 0x80800D30: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_9:
    // 0x80800D34: b           L_80800F04
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D3C:
    // 0x80800D3C: jal         0x800DA298
    // 0x80800D40: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800D40: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_10:
    // 0x80800D44: beq         $v0, $zero, L_80800D5C
    if (ctx->r2 == 0) {
        // 0x80800D48: nop
    
            goto L_80800D5C;
    }
    // 0x80800D48: nop

    // 0x80800D4C: jal         0x80088848
    // 0x80800D50: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_11;
    // 0x80800D50: nop

    after_11:
    // 0x80800D54: beql        $v0, $zero, L_80800F04
    if (ctx->r2 == 0) {
        // 0x80800D58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F04;
    }
    goto skip_1;
    // 0x80800D58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_80800D5C:
    // 0x80800D5C: jal         0x80801DA0
    // 0x80800D60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801DA0_changlerboss(rdram, ctx);
        goto after_12;
    // 0x80800D60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800D64: b           L_80800F04
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D6C:
    // 0x80800D6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800D70: jal         0x800F54E4
    // 0x80800D74: sb          $t9, 0x12C($a3)
    MEM_B(0X12C, ctx->r7) = ctx->r25;
    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800D74: sb          $t9, 0x12C($a3)
    MEM_B(0X12C, ctx->r7) = ctx->r25;
    after_13:
    // 0x80800D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D7C: jal         0x800F82D4
    // 0x80800D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_14;
    // 0x80800D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800D84: b           L_80800F04
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D8C:
    // 0x80800D8C: jal         0x800DA298
    // 0x80800D90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800D90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_15:
    // 0x80800D94: bne         $v0, $zero, L_80800DB0
    if (ctx->r2 != 0) {
        // 0x80800D98: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800DB0;
    }
    // 0x80800D98: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800D9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DA4: jal         0x80108B04
    // 0x80800DA8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80108B04(rdram, ctx);
        goto after_16;
    // 0x80800DA8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_16:
    // 0x80800DAC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800DB0:
    // 0x80800DB0: lbu         $t0, 0x12A($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X12A);
    // 0x80800DB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DB8: beql        $t0, $zero, L_80800F04
    if (ctx->r8 == 0) {
        // 0x80800DBC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800F04;
    }
    goto skip_2;
    // 0x80800DBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800DC0: jal         0x800FDC28
    // 0x80800DC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800FDC28(rdram, ctx);
        goto after_17;
    // 0x80800DC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_17:
    // 0x80800DC8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800DCC: b           L_80800F00
    // 0x80800DD0: sb          $zero, 0x12A($a3)
    MEM_B(0X12A, ctx->r7) = 0;
        goto L_80800F00;
    // 0x80800DD0: sb          $zero, 0x12A($a3)
    MEM_B(0X12A, ctx->r7) = 0;
L_80800DD4:
    // 0x80800DD4: jal         0x800D395C
    // 0x80800DD8: nop

    func_800D395C(rdram, ctx);
        goto after_18;
    // 0x80800DD8: nop

    after_18:
    // 0x80800DDC: bne         $v0, $zero, L_80800DEC
    if (ctx->r2 != 0) {
        // 0x80800DE0: addiu       $a1, $zero, 0xCEB
        ctx->r5 = ADD32(0, 0XCEB);
            goto L_80800DEC;
    }
    // 0x80800DE0: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800DE4: b           L_80800F04
    // 0x80800DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DEC:
    // 0x80800DEC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800DF0: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80800DF4: addiu       $a2, $zero, 0x146
    ctx->r6 = ADD32(0, 0X146);
    // 0x80800DF8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800DFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800E00: jal         0x8008A208
    // 0x80800E04: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x80800E04: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_19:
    // 0x80800E08: b           L_80800F04
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E10:
    // 0x80800E10: jal         0x800FDC28
    // 0x80800E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x80800E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80800E18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800E1C: jal         0x808012E0
    // 0x80800E20: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_21;
    // 0x80800E20: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_21:
    // 0x80800E24: b           L_80800F04
    // 0x80800E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E2C:
    // 0x80800E2C: lw          $t3, 0x7C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X7C);
    // 0x80800E30: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    // 0x80800E34: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x80800E38: bgez        $t5, L_80800E50
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800E3C: nop
    
            goto L_80800E50;
    }
    // 0x80800E3C: nop

    // 0x80800E40: jal         0x800DA298
    // 0x80800E44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_22;
    // 0x80800E44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_22:
    // 0x80800E48: beq         $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800E4C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800E58;
    }
    // 0x80800E4C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800E50:
    // 0x80800E50: b           L_80800F04
    // 0x80800E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E58:
    // 0x80800E58: lh          $t6, 0x92($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X92);
    // 0x80800E5C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E64: bne         $t6, $zero, L_80800EC4
    if (ctx->r14 != 0) {
        // 0x80800E68: addiu       $a0, $a0, 0x30B0
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
            goto L_80800EC4;
    }
    // 0x80800E68: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    // 0x80800E6C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80800E70: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80800E74:
    // 0x80800E74: lbu         $t7, 0x1B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1B);
    // 0x80800E78: bne         $t7, $zero, L_80800EB0
    if (ctx->r15 != 0) {
        // 0x80800E7C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80800EB0;
    }
    // 0x80800E7C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800E80: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80800E84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800E88: addu        $a1, $a3, $t8
    ctx->r5 = ADD32(ctx->r7, ctx->r24);
    // 0x80800E8C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800E90: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    // 0x80800E94: jal         0x800EE7F8
    // 0x80800E98: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x80800E98: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    after_23:
    // 0x80800E9C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800EA0: jal         0x80101074
    // 0x80800EA4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    func_80101074(rdram, ctx);
        goto after_24;
    // 0x80800EA4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    after_24:
    // 0x80800EA8: b           L_80800F04
    // 0x80800EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EB0:
    // 0x80800EB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800EB4: bne         $v0, $a0, L_80800E74
    if (ctx->r2 != ctx->r4) {
        // 0x80800EB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800E74;
    }
    // 0x80800EB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800EBC: b           L_80800F04
    // 0x80800EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EC4:
    // 0x80800EC4: jal         0x800EE7F8
    // 0x80800EC8: addiu       $a1, $a3, 0x84
    ctx->r5 = ADD32(ctx->r7, 0X84);
    func_800EE7F8(rdram, ctx);
        goto after_25;
    // 0x80800EC8: addiu       $a1, $a3, 0x84
    ctx->r5 = ADD32(ctx->r7, 0X84);
    after_25:
    // 0x80800ECC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1332, 0X30B0) << 16);
    // 0x80800ED0: jal         0x80101074
    // 0x80800ED4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    func_80101074(rdram, ctx);
        goto after_26;
    // 0x80800ED4: addiu       $a0, $a0, 0x30B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1332, 0X30B0));
    after_26:
    // 0x80800ED8: b           L_80800F04
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE0:
    // 0x80800EE0: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800EE4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800EE8: jal         0x80800F14
    // 0x80800EEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800F14_changlerboss(rdram, ctx);
        goto after_27;
    // 0x80800EEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_27:
    // 0x80800EF0: b           L_80800F04
    // 0x80800EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F04;
    // 0x80800EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EF8:
    // 0x80800EF8: b           L_80800F04
    // 0x80800EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F04;
    // 0x80800EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F00:
    // 0x80800F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F04:
    // 0x80800F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F0C: jr          $ra
    // 0x80800F10: nop

    return;
    // 0x80800F10: nop

;}
RECOMP_FUNC void func_80800FD4_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FD4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FE0: jal         0x800D8FF8
    // 0x80800FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800FE8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80800FEC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800FF0: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80800FF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FF8: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800FFC: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80801000: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x80801004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801008: lui         $at, 0x4520
    ctx->r1 = S32(0X4520 << 16);
    // 0x8080100C: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801010: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801014: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80801018: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8080101C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801020: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80801024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801028: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8080102C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80801030: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80801034: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80801038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080103C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80801040: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80801044: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80801048: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080104C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80801050: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_80801054:
    // 0x80801054: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801058: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080105C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80801060: nop

    // 0x80801064: bc1f        L_80801074
    if (!c1cs) {
        // 0x80801068: nop
    
            goto L_80801074;
    }
    // 0x80801068: nop

    // 0x8080106C: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801070: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
L_80801074:
    // 0x80801074: bne         $v1, $a0, L_80801054
    if (ctx->r3 != ctx->r4) {
        // 0x80801078: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80801054;
    }
    // 0x80801078: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080107C: jal         0x80100094
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801084: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80801088: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8080108C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801090: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801094: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801098: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080109C: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808010A0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808010A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(748, 0X1BB0) << 16);
    // 0x808010AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(748, 0X1BBC) << 16);
    // 0x808010B0: addiu       $a2, $a2, 0x1BBC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1BBC));
    // 0x808010B4: addiu       $a1, $a1, 0x1BB0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X1BB0));
    // 0x808010B8: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808010BC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808010C0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x808010C4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808010C8: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808010CC: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808010D0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x808010D4: jal         0x800F3214
    // 0x808010D8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    func_800F3214(rdram, ctx);
        goto after_2;
    // 0x808010D8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x808010DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808010E0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808010E4: jal         0x800C8D4C
    // 0x808010E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C8D4C(rdram, ctx);
        goto after_3;
    // 0x808010E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x808010EC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x808010F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808010F4: jal         0x800C8E84
    // 0x808010F8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x808010F8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x808010FC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801104: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80801108: beq         $t8, $at, L_80801134
    if (ctx->r24 == ctx->r1) {
        // 0x8080110C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801134;
    }
    // 0x8080110C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801110: beq         $t8, $at, L_8080116C
    if (ctx->r24 == ctx->r1) {
        // 0x80801114: lwc1        $f10, 0x5C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_8080116C;
    }
    // 0x80801114: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80801118: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080111C: beq         $t8, $at, L_808011B0
    if (ctx->r24 == ctx->r1) {
        // 0x80801120: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808011B0;
    }
    // 0x80801120: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801124: beq         $t8, $at, L_808011D0
    if (ctx->r24 == ctx->r1) {
        // 0x80801128: lwc1        $f4, 0x5C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_808011D0;
    }
    // 0x80801128: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080112C: b           L_80801208
    // 0x80801130: nop

        goto L_80801208;
    // 0x80801130: nop

L_80801134:
    // 0x80801134: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x80801138: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801140: addiu       $v0, $t9, -0x1
    ctx->r2 = ADD32(ctx->r25, -0X1);
    // 0x80801144: andi        $t0, $v0, 0x1FF
    ctx->r8 = ctx->r2 & 0X1FF;
    // 0x80801148: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x8080114C: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80801150: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80801154: bne         $t0, $zero, L_80801208
    if (ctx->r8 != 0) {
        // 0x80801158: sh          $t4, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r12;
            goto L_80801208;
    }
    // 0x80801158: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x8080115C: jal         0x80800E80
    // 0x80801160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_5;
    // 0x80801160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801164: b           L_80801208
    // 0x80801168: nop

        goto L_80801208;
    // 0x80801168: nop

L_8080116C:
    // 0x8080116C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801170: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801174: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801178: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8080117C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801184: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80801188: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8080118C: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801190: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80801194: nop

    // 0x80801198: bc1f        L_80801208
    if (!c1cs) {
        // 0x8080119C: nop
    
            goto L_80801208;
    }
    // 0x8080119C: nop

    // 0x808011A0: jal         0x80800E80
    // 0x808011A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_6;
    // 0x808011A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808011A8: b           L_80801208
    // 0x808011AC: nop

        goto L_80801208;
    // 0x808011AC: nop

L_808011B0:
    // 0x808011B0: jal         0x800DA298
    // 0x808011B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808011B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808011B8: beq         $v0, $zero, L_80801208
    if (ctx->r2 == 0) {
        // 0x808011BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801208;
    }
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C0: jal         0x80800E80
    // 0x808011C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_8;
    // 0x808011C4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x808011C8: b           L_80801208
    // 0x808011CC: nop

        goto L_80801208;
    // 0x808011CC: nop

L_808011D0:
    // 0x808011D0: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808011D4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011DC: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808011E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808011E4: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x808011E8: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x808011EC: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808011F0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x808011F4: nop

    // 0x808011F8: bc1f        L_80801208
    if (!c1cs) {
        // 0x808011FC: nop
    
            goto L_80801208;
    }
    // 0x808011FC: nop

    // 0x80801200: jal         0x80800E80
    // 0x80801204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E80_chlagoonufoint(rdram, ctx);
        goto after_9;
    // 0x80801204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80801208:
    // 0x80801208: jal         0x800BEA88
    // 0x8080120C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_10;
    // 0x8080120C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80801210: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801214: lhu         $v1, 0x76($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X76);
    // 0x80801218: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8080121C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801220: srl         $t5, $v1, 7
    ctx->r13 = S32(U32(ctx->r3) >> 7);
    // 0x80801224: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80801228: addiu       $v1, $t6, -0x4
    ctx->r3 = ADD32(ctx->r14, -0X4);
    // 0x8080122C: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80801230: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80801234: addiu       $a2, $a2, 0x5A60
    ctx->r6 = ADD32(ctx->r6, 0X5A60);
    // 0x80801238: jal         0x80088660
    // 0x8080123C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x8080123C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80801240: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801244: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801248: addiu       $a2, $a2, 0x5A68
    ctx->r6 = ADD32(ctx->r6, 0X5A68);
    // 0x8080124C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801250: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801254: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801258: jal         0x80088660
    // 0x8080125C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    _glid_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x8080125C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_12:
    // 0x80801260: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801264: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801268: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080126C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801270: jal         0x80088660
    // 0x80801274: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    _glid_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80801274: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    after_13:
    // 0x80801278: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080127C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801280: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801284: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80801288: jal         0x80088660
    // 0x8080128C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _glid_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080128C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_14:
    // 0x80801290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801298: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080129C: jr          $ra
    // 0x808012A0: nop

    return;
    // 0x808012A0: nop

;}
