#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800024_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: jal         0x80089828
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800038: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800044: bnel        $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x80800048: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80800068;
    }
    goto skip_0;
    // 0x80800048: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080004C: jal         0x80088848
    // 0x80800050: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800050: nop

    after_2:
    // 0x80800054: bnel        $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x80800058: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80800068;
    }
    goto skip_1;
    // 0x80800058: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8080005C: jal         0x800D1824
    // 0x80800060: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1824(rdram, ctx);
        goto after_3;
    // 0x80800060: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_3:
    // 0x80800064: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_80800068:
    // 0x80800068: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080006C: jal         0x800897D8
    // 0x80800070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800074: jal         0x801022E4
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_5;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080007C: addiu       $at, $zero, 0x155
    ctx->r1 = ADD32(0, 0X155);
    // 0x80800080: bne         $v0, $at, L_80800090
    if (ctx->r2 != ctx->r1) {
        // 0x80800084: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80800090;
    }
    // 0x80800084: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800088: jal         0x80089818
    // 0x8080008C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x8080008C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80800090:
    // 0x80800090: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800094: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800098: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080009C: jal         0x800EE7F8
    // 0x808000A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808000A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_7:
    // 0x808000A4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808000A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000AC: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x808000B0: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808000B4: bgez        $t8, L_808000E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000B8: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_808000E4;
    }
    // 0x808000B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808000BC: jal         0x80085778
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chbadshad_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000C4: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000C8: lui         $a1, 0x437A
        ctx->r5 = S32(0X437A << 16);
            goto L_808000E4;
    }
    // 0x808000C8: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x808000CC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x808000D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808000DC: jal         0x80089F20
    // 0x808000E0: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808000E0: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_9:
L_808000E4:
    // 0x808000E4: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808000E8: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808000EC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x808000F0: sltiu       $at, $t2, 0x9
    ctx->r1 = ctx->r10 < 0X9 ? 1 : 0;
    // 0x808000F4: beq         $at, $zero, L_808002A4
    if (ctx->r1 == 0) {
        // 0x808000F8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808002A4;
    }
    // 0x808000F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1036, 0X11D0) << 16);
    // 0x80800100: addu        $at, $at, $t2
    gpr jr_addend_80800108 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800104: lw          $t2, 0x11D0($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1036, 0X11D0));
    // 0x80800108: jr          $t2
    // 0x8080010C: nop

    switch (jr_addend_80800108 >> 2) {
        case 0: goto L_80800110; break;
        case 1: goto L_808002A4; break;
        case 2: goto L_80800130; break;
        case 3: goto L_808001BC; break;
        case 4: goto L_808002A4; break;
        case 5: goto L_80800204; break;
        case 6: goto L_8080022C; break;
        case 7: goto L_8080022C; break;
        case 8: goto L_8080029C; break;
        default: switch_error(__func__, 0x80800108, 0x808011D0);
    }
    // 0x8080010C: nop

L_80800110:
    // 0x80800110: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1036, 0X1200) << 16);
    // 0x80800114: addiu       $a1, $a1, 0x1200
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1036, 0X1200));
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800120: jal         0x8080059C
    // 0x80800124: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8080059C_chjollyroger(rdram, ctx);
        goto after_10;
    // 0x80800124: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x80800128: b           L_808002A4
    // 0x8080012C: nop

        goto L_808002A4;
    // 0x8080012C: nop

L_80800130:
    // 0x80800130: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1036, 0X1238) << 16);
    // 0x80800134: addiu       $a1, $a1, 0x1238
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1036, 0X1238));
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800140: jal         0x8080059C
    // 0x80800144: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_8080059C_chjollyroger(rdram, ctx);
        goto after_11;
    // 0x80800144: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_11:
    // 0x80800148: bne         $v0, $zero, L_808002A4
    if (ctx->r2 != 0) {
        // 0x8080014C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800154: jal         0x80101E14
    // 0x80800158: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x80800158: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_12:
    // 0x8080015C: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800160: nop
    
            goto L_808002A4;
    }
    // 0x80800160: nop

    // 0x80800164: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800168: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x8080016C: bgez        $t5, L_80800184
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800170: nop
    
            goto L_80800184;
    }
    // 0x80800170: nop

    // 0x80800174: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800178: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x8080017C: b           L_808002A4
    // 0x80800180: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_808002A4;
    // 0x80800180: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800184:
    // 0x80800184: jal         0x800DA298
    // 0x80800188: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80800188: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    after_13:
    // 0x8080018C: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800190: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1036, 0X11F4) << 16);
            goto L_808002A4;
    }
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1036, 0X11F4) << 16);
    // 0x80800194: jal         0x800DC298
    // 0x80800198: lwc1        $f12, 0x11F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1036, 0X11F4));
    func_800DC298(rdram, ctx);
        goto after_14;
    // 0x80800198: lwc1        $f12, 0x11F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1036, 0X11F4));
    after_14:
    // 0x8080019C: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80102424
    // 0x808001A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x808001A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x808001AC: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808001B0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808001B4: b           L_808002A4
    // 0x808001B8: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_808002A4;
    // 0x808001B8: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_808001BC:
    // 0x808001BC: jal         0x80101DDC
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001C4: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E0;
    }
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80102424
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808001D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x808001D8: b           L_808001F4
    // 0x808001DC: nop

        goto L_808001F4;
    // 0x808001DC: nop

L_808001E0:
    // 0x808001E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1036, 0X1238) << 16);
    // 0x808001E4: addiu       $a1, $a1, 0x1238
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1036, 0X1238));
    // 0x808001E8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808001EC: jal         0x8080059C
    // 0x808001F0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_8080059C_chjollyroger(rdram, ctx);
        goto after_18;
    // 0x808001F0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_18:
L_808001F4:
    // 0x808001F4: jal         0x8080056C
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080056C_chjollyroger(rdram, ctx);
        goto after_19;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808001FC: b           L_808002A4
    // 0x80800200: nop

        goto L_808002A4;
    // 0x80800200: nop

L_80800204:
    // 0x80800204: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800208: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x8080020C: jal         0x80101E14
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_20;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800214: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80102424
    // 0x80800220: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_21;
    // 0x80800220: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_21:
    // 0x80800224: b           L_808002A4
    // 0x80800228: nop

        goto L_808002A4;
    // 0x80800228: nop

L_8080022C:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x80103DFC
    // 0x80800234: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80103DFC(rdram, ctx);
        goto after_22;
    // 0x80800234: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_22:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80100094
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_23;
    // 0x80800240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8080024C: jal         0x80089FE8
    // 0x80800250: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x80800250: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_24:
    // 0x80800254: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800258: addiu       $a1, $zero, 0x1004
        ctx->r5 = ADD32(0, 0X1004);
            goto L_808002A4;
    }
    // 0x80800258: addiu       $a1, $zero, 0x1004
    ctx->r5 = ADD32(0, 0X1004);
    // 0x8080025C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800260: addiu       $t1, $zero, 0x55
    ctx->r9 = ADD32(0, 0X55);
    // 0x80800264: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800268: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080026C: jal         0x8008A208
    // 0x80800270: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x80800270: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_25:
    // 0x80800274: jal         0x800DA298
    // 0x80800278: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x80800278: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_26:
    // 0x8080027C: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x80800280: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8080028C;
    }
    // 0x80800280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800284: b           L_8080028C
    // 0x80800288: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_8080028C;
    // 0x80800288: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8080028C:
    // 0x8080028C: jal         0x80102424
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_27;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800294: b           L_808002A4
    // 0x80800298: nop

        goto L_808002A4;
    // 0x80800298: nop

L_8080029C:
    // 0x8080029C: jal         0x8080056C
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080056C_chjollyroger(rdram, ctx);
        goto after_28;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
L_808002A4:
    // 0x808002A4: jal         0x801022E4
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_29;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808002AC: addiu       $at, $zero, 0x155
    ctx->r1 = ADD32(0, 0X155);
    // 0x808002B0: bnel        $v0, $at, L_808002CC
    if (ctx->r2 != ctx->r1) {
        // 0x808002B4: lbu         $t5, 0x94($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X94);
            goto L_808002CC;
    }
    goto skip_2;
    // 0x808002B4: lbu         $t5, 0x94($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X94);
    skip_2:
    // 0x808002B8: lbu         $t2, 0x94($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X94);
    // 0x808002BC: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808002C0: b           L_808002D4
    // 0x808002C4: sb          $t3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r11;
        goto L_808002D4;
    // 0x808002C4: sb          $t3, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r11;
    // 0x808002C8: lbu         $t5, 0x94($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X94);
L_808002CC:
    // 0x808002CC: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x808002D0: sb          $t6, 0x94($s0)
    MEM_B(0X94, ctx->r16) = ctx->r14;
L_808002D4:
    // 0x808002D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void _batranslate_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085360: syscall     158
    recomp_syscall_handler(rdram, ctx, 0x80085360);
    return;
    // 0x80085364: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chzubba_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865C0: syscall     342
    recomp_syscall_handler(rdram, ctx, 0x800865C0);
    return;
    // 0x800865C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8010B410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B410: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010B414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B41C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010B420: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8010B424: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8010B428: jal         0x8010C460
    // 0x8010B42C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_8010C460(rdram, ctx);
        goto after_0;
    // 0x8010B42C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B430: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010B434: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8010B438: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B43C: jal         0x800EE7F8
    // 0x8010B440: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8010B440: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x8010B444: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010B448: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010B44C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8010B450: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010B454: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B458: jal         0x800EE7F8
    // 0x8010B45C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010B45C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8010B460: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8010B464: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010B468: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010B46C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010B470: addiu       $a2, $a2, 0x6F40
    ctx->r6 = ADD32(ctx->r6, 0X6F40);
    // 0x8010B474: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010B478: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010B47C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010B480: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8010B484: jal         0x800BEF00
    // 0x8010B488: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x8010B488: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x8010B48C: beq         $v0, $zero, L_8010B4E4
    if (ctx->r2 == 0) {
        // 0x8010B490: nop
    
            goto L_8010B4E4;
    }
    // 0x8010B490: nop

    // 0x8010B494: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    // 0x8010B498: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B49C: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    // 0x8010B4A0: beq         $t6, $zero, L_8010B4B4
    if (ctx->r14 == 0) {
        // 0x8010B4A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010B4B4;
    }
    // 0x8010B4A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B4A8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8010B4AC: jal         0x801045AC
    // 0x8010B4B0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_801045AC(rdram, ctx);
        goto after_4;
    // 0x8010B4B0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_4:
L_8010B4B4:
    // 0x8010B4B4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010B4B8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010B4BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010B4C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8010B4C4: nop

    // 0x8010B4C8: bc1f        L_8010B4E4
    if (!c1cs) {
        // 0x8010B4CC: nop
    
            goto L_8010B4E4;
    }
    // 0x8010B4CC: nop

    // 0x8010B4D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010B4D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010B4D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010B4DC: b           L_8010B500
    // 0x8010B4E0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_8010B500;
    // 0x8010B4E0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_8010B4E4:
    // 0x8010B4E4: jal         0x8010C3E8
    // 0x8010B4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3E8(rdram, ctx);
        goto after_5;
    // 0x8010B4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8010B4EC: beql        $v0, $zero, L_8010B500
    if (ctx->r2 == 0) {
        // 0x8010B4F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B500;
    }
    goto skip_0;
    // 0x8010B4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8010B4F4: b           L_8010B500
    // 0x8010B4F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010B500;
    // 0x8010B4F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8010B4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B500:
    // 0x8010B500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B508: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010B50C: jr          $ra
    // 0x8010B510: nop

    return;
    // 0x8010B510: nop

;}
RECOMP_FUNC void _chmole_training_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A40: syscall     408
    recomp_syscall_handler(rdram, ctx, 0x80086A40);
    return;
    // 0x80086A44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D38: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D38);
    return;
    // 0x80083D3C: addi        $t0, $zero, 0xAC
    ctx->r8 = ADD32(0, 0XAC);
;}
RECOMP_FUNC void func_800D4E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4E1C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D4E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4E24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D4E28: bne         $a0, $at, L_800D4E34
    if (ctx->r4 != ctx->r1) {
        // 0x800D4E2C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800D4E34;
    }
    // 0x800D4E2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D4E30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D4E34:
    // 0x800D4E34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4E38: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x800D4E3C: bgezl       $t6, L_800D4E54
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D4E40: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800D4E54;
    }
    goto skip_0;
    // 0x800D4E40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x800D4E44: jal         0x800FC660
    // 0x800D4E48: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x800D4E48: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D4E4C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800D4E50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800D4E54:
    // 0x800D4E54: jal         0x800D4E7C
    // 0x800D4E58: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D4E7C(rdram, ctx);
        goto after_1;
    // 0x800D4E58: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800D4E5C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4E60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D4E64: jal         0x800D4FB8
    // 0x800D4E68: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    func_800D4FB8(rdram, ctx);
        goto after_2;
    // 0x800D4E68: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x800D4E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4E74: jr          $ra
    // 0x800D4E78: nop

    return;
    // 0x800D4E78: nop

;}
RECOMP_FUNC void bsdronebitten_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: lbu         $v0, 0x191($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X191);
    // 0x8080021C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800220: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800224: beq         $v0, $at, L_8080023C
    if (ctx->r2 == ctx->r1) {
        // 0x80800228: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080023C;
    }
    // 0x80800228: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080022C: beql        $v0, $at, L_80800248
    if (ctx->r2 == ctx->r1) {
        // 0x80800230: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800248;
    }
    goto skip_0;
    // 0x80800230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800234: b           L_80800260
    // 0x80800238: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80800260;
    // 0x80800238: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8080023C:
    // 0x8080023C: jr          $ra
    // 0x80800240: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80800240: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80800244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800248:
    // 0x80800248: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080024C: nop

    // 0x80800250: sub.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80800254: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800258: jr          $ra
    // 0x8080025C: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
    return;
    // 0x8080025C: sub.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f4.fl;
L_80800260:
    // 0x80800260: jr          $ra
    // 0x80800264: nop

    return;
    // 0x80800264: nop

;}
RECOMP_FUNC void func_8001DDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DDF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DDF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001DDF8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001DDFC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001DE00: addiu       $a1, $a1, -0x2770
    ctx->r5 = ADD32(ctx->r5, -0X2770);
    // 0x8001DE04: addiu       $a0, $a0, -0x2768
    ctx->r4 = ADD32(ctx->r4, -0X2768);
    // 0x8001DE08: jal         0x8002E070
    // 0x8001DE0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8001DE0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001DE10: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001DE14: addiu       $t6, $t6, -0x2490
    ctx->r14 = ADD32(ctx->r14, -0X2490);
    // 0x8001DE18: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001DE1C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001DE20: lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // 0x8001DE24: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8001DE28: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001DE2C: addiu       $a3, $a3, -0x219C
    ctx->r7 = ADD32(ctx->r7, -0X219C);
    // 0x8001DE30: addiu       $a1, $a1, -0x25A0
    ctx->r5 = ADD32(ctx->r5, -0X25A0);
    // 0x8001DE34: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x8001DE38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8001DE3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8001DE40: jal         0x8001DCB0
    // 0x8001DE44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_1;
    // 0x8001DE44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8001DE48: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001DE4C: jal         0x8002E510
    // 0x8001DE50: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8001DE50: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    after_2:
    // 0x8001DE54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001DE58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DE5C: jr          $ra
    // 0x8001DE60: nop

    return;
    // 0x8001DE60: nop

;}
RECOMP_FUNC void chpickups_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X8F8) << 16);
    // 0x80800040: jr          $ra
    // 0x80800044: addiu       $v0, $v0, 0x8F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X8F8));
    return;
    // 0x80800044: addiu       $v0, $v0, 0x8F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X8F8));
;}
RECOMP_FUNC void func_800AE1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE1F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AE1F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AE1F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800AE1FC: jal         0x800AE080
    // 0x800AE200: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x800AE200: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x800AE204: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800AE208: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800AE20C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800AE210: lh          $v1, 0x4($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X4);
    // 0x800AE214: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x800AE218: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AE21C: beq         $at, $zero, L_800AE244
    if (ctx->r1 == 0) {
        // 0x800AE220: sll         $a1, $v1, 6
        ctx->r5 = S32(ctx->r3 << 6);
            goto L_800AE244;
    }
    // 0x800AE220: sll         $a1, $v1, 6
    ctx->r5 = S32(ctx->r3 << 6);
    // 0x800AE224: jal         0x8001B710
    // 0x800AE228: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800AE228: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    after_1:
    // 0x800AE22C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800AE230: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800AE234: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x800AE238: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800AE23C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800AE240: lh          $v1, 0x4($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X4);
L_800AE244:
    // 0x800AE244: lh          $t2, 0xC($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XC);
    // 0x800AE248: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800AE24C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AE250: beq         $t2, $zero, L_800AE270
    if (ctx->r10 == 0) {
        // 0x800AE254: nop
    
            goto L_800AE270;
    }
    // 0x800AE254: nop

    // 0x800AE258: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
    // 0x800AE25C: jal         0x800E0A28
    // 0x800AE260: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800E0A28(rdram, ctx);
        goto after_2;
    // 0x800AE260: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800AE264: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE268: b           L_800AE270
    // 0x800AE26C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800AE270;
    // 0x800AE26C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800AE270:
    // 0x800AE270: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AE274: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800AE278: jal         0x800AE820
    // 0x800AE27C: addiu       $a2, $t0, 0x50
    ctx->r6 = ADD32(ctx->r8, 0X50);
    func_800AE820(rdram, ctx);
        goto after_3;
    // 0x800AE27C: addiu       $a2, $t0, 0x50
    ctx->r6 = ADD32(ctx->r8, 0X50);
    after_3:
    // 0x800AE280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE288: jr          $ra
    // 0x800AE28C: nop

    return;
    // 0x800AE28C: nop

;}
RECOMP_FUNC void func_80800B00_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800B04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800B08: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800B0C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800B10: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800B14: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800B18: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800B1C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800B20: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800B24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800B28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800B2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B30: jal         0x80100094
    // 0x80800B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B38: lbu         $v1, 0x8F5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8F5);
    // 0x80800B3C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1632, 0X4D84) << 16);
    // 0x80800B40: addiu       $t6, $t6, 0x4D84
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1632, 0X4D84));
    // 0x80800B44: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80800B48: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80800B4C: addu        $s1, $a0, $t6
    ctx->r17 = ADD32(ctx->r4, ctx->r14);
    // 0x80800B50: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80800B54: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800B58: beql        $t7, $zero, L_80800CA4
    if (ctx->r15 == 0) {
        // 0x80800B5C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800CA4;
    }
    goto skip_0;
    // 0x80800B5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800B60: lw          $t8, 0x7C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X7C);
    // 0x80800B64: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1632, 0X4D94) << 16);
    // 0x80800B68: addiu       $t0, $t0, 0x4D94
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1632, 0X4D94));
    // 0x80800B6C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800B70: beq         $t9, $zero, L_80800CA0
    if (ctx->r25 == 0) {
        // 0x80800B74: addu        $s5, $a0, $t0
        ctx->r21 = ADD32(ctx->r4, ctx->r8);
            goto L_80800CA0;
    }
    // 0x80800B74: addu        $s5, $a0, $t0
    ctx->r21 = ADD32(ctx->r4, ctx->r8);
    // 0x80800B78: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80800B7C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800B80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B84: blez        $t1, L_80800CA0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80800B88: addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
            goto L_80800CA0;
    }
    // 0x80800B88: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x80800B8C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80800B90: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80800B94: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
L_80800B98:
    // 0x80800B98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B9C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80800BA0: jal         0x80105998
    // 0x80800BA4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    func_80105998(rdram, ctx);
        goto after_1;
    // 0x80800BA4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_1:
    // 0x80800BA8: beql        $v0, $zero, L_80800C8C
    if (ctx->r2 == 0) {
        // 0x80800BAC: lw          $t8, 0x0($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X0);
            goto L_80800C8C;
    }
    goto skip_1;
    // 0x80800BAC: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x80800BB0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80800BB4: addu        $v1, $t4, $s0
    ctx->r3 = ADD32(ctx->r12, ctx->r16);
    // 0x80800BB8: lh          $a0, 0xC($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XC);
    // 0x80800BBC: beq         $a0, $s6, L_80800BDC
    if (ctx->r4 == ctx->r22) {
        // 0x80800BC0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80800BDC;
    }
    // 0x80800BC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800BC4: beql        $v0, $s7, L_80800C0C
    if (ctx->r2 == ctx->r23) {
        // 0x80800BC8: lbu         $t8, 0x8F8($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X8F8);
            goto L_80800C0C;
    }
    goto skip_2;
    // 0x80800BC8: lbu         $t8, 0x8F8($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X8F8);
    skip_2:
    // 0x80800BCC: beql        $v0, $fp, L_80800C3C
    if (ctx->r2 == ctx->r30) {
        // 0x80800BD0: lbu         $t1, 0x8F8($s2)
        ctx->r9 = MEM_BU(ctx->r18, 0X8F8);
            goto L_80800C3C;
    }
    goto skip_3;
    // 0x80800BD0: lbu         $t1, 0x8F8($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X8F8);
    skip_3:
    // 0x80800BD4: b           L_80800C88
    // 0x80800BD8: sb          $a0, 0x8F9($s2)
    MEM_B(0X8F9, ctx->r18) = ctx->r4;
        goto L_80800C88;
    // 0x80800BD8: sb          $a0, 0x8F9($s2)
    MEM_B(0X8F9, ctx->r18) = ctx->r4;
L_80800BDC:
    // 0x80800BDC: lbu         $t5, 0x8F8($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X8F8);
    // 0x80800BE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800BE4: beql        $t5, $zero, L_80800C88
    if (ctx->r13 == 0) {
        // 0x80800BE8: sb          $a0, 0x8F9($s2)
        MEM_B(0X8F9, ctx->r18) = ctx->r4;
            goto L_80800C88;
    }
    goto skip_4;
    // 0x80800BE8: sb          $a0, 0x8F9($s2)
    MEM_B(0X8F9, ctx->r18) = ctx->r4;
    skip_4:
    // 0x80800BEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800BF0: jal         0x80800A24
    // 0x80800BF4: lbu         $a1, 0x8F5($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8F5);
    func_80800A24_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800BF4: lbu         $a1, 0x8F5($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8F5);
    after_2:
    // 0x80800BF8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80800BFC: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800C00: b           L_80800C84
    // 0x80800C04: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
        goto L_80800C84;
    // 0x80800C04: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
    // 0x80800C08: lbu         $t8, 0x8F8($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X8F8);
L_80800C0C:
    // 0x80800C0C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800C10: beql        $t8, $zero, L_80800C88
    if (ctx->r24 == 0) {
        // 0x80800C14: sb          $a0, 0x8F9($s2)
        MEM_B(0X8F9, ctx->r18) = ctx->r4;
            goto L_80800C88;
    }
    goto skip_5;
    // 0x80800C14: sb          $a0, 0x8F9($s2)
    MEM_B(0X8F9, ctx->r18) = ctx->r4;
    skip_5:
    // 0x80800C18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800C1C: lh          $a1, 0xE($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XE);
    // 0x80800C20: jal         0x80800998
    // 0x80800C24: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    func_80800998_chhandcart(rdram, ctx);
        goto after_3;
    // 0x80800C24: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    after_3:
    // 0x80800C28: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80800C2C: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80800C30: b           L_80800C84
    // 0x80800C34: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
        goto L_80800C84;
    // 0x80800C34: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
    // 0x80800C38: lbu         $t1, 0x8F8($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X8F8);
L_80800C3C:
    // 0x80800C3C: beql        $t1, $zero, L_80800C88
    if (ctx->r9 == 0) {
        // 0x80800C40: sb          $a0, 0x8F9($s2)
        MEM_B(0X8F9, ctx->r18) = ctx->r4;
            goto L_80800C88;
    }
    goto skip_6;
    // 0x80800C40: sb          $a0, 0x8F9($s2)
    MEM_B(0X8F9, ctx->r18) = ctx->r4;
    skip_6:
    // 0x80800C44: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800C48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800C4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800C50: swc1        $f4, 0x8FC($s2)
    MEM_W(0X8FC, ctx->r18) = ctx->f4.u32l;
    // 0x80800C54: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80800C58: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80800C5C: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80800C60: swc1        $f6, 0x900($s2)
    MEM_W(0X900, ctx->r18) = ctx->f6.u32l;
    // 0x80800C64: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80800C68: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80800C6C: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80800C70: jal         0x8080090C
    // 0x80800C74: lh          $a1, 0xE($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XE);
    func_8080090C_chhandcart(rdram, ctx);
        goto after_4;
    // 0x80800C74: lh          $a1, 0xE($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XE);
    after_4:
    // 0x80800C78: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80800C7C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800C80: lh          $a0, 0xC($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XC);
L_80800C84:
    // 0x80800C84: sb          $a0, 0x8F9($s2)
    MEM_B(0X8F9, ctx->r18) = ctx->r4;
L_80800C88:
    // 0x80800C88: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80800C8C:
    // 0x80800C8C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800C90: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800C94: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800C98: bnel        $at, $zero, L_80800B98
    if (ctx->r1 != 0) {
        // 0x80800C9C: lw          $t2, 0x0($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X0);
            goto L_80800B98;
    }
    goto skip_7;
    // 0x80800C9C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    skip_7:
L_80800CA0:
    // 0x80800CA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800CA4:
    // 0x80800CA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800CB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800CB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800CB8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CBC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800CC0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800CC4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800CC8: jr          $ra
    // 0x80800CCC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800CCC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chmole_mine_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A30: syscall     407
    recomp_syscall_handler(rdram, ctx, 0x80086A30);
    return;
    // 0x80086A34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802140_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802140: jr          $ra
    // 0x80802144: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80802144: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_801069A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801069A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801069A8: lw          $a1, 0x6EE0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6EE0);
    // 0x801069AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801069B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801069B4: bne         $a1, $zero, L_801069C4
    if (ctx->r5 != 0) {
        // 0x801069B8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801069C4;
    }
    // 0x801069B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801069BC: b           L_80106A04
    // 0x801069C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106A04;
    // 0x801069C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801069C4:
    // 0x801069C4: beq         $a2, $zero, L_801069E0
    if (ctx->r6 == 0) {
        // 0x801069C8: nop
    
            goto L_801069E0;
    }
    // 0x801069C8: nop

    // 0x801069CC: lhu         $t6, 0x18($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X18);
    // 0x801069D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801069D4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801069D8: bne         $t7, $zero, L_801069E8
    if (ctx->r15 != 0) {
        // 0x801069DC: nop
    
            goto L_801069E8;
    }
    // 0x801069DC: nop

L_801069E0:
    // 0x801069E0: b           L_80106A04
    // 0x801069E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106A04;
    // 0x801069E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801069E8:
    // 0x801069E8: jal         0x800B2928
    // 0x801069EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    vector_size(rdram, ctx);
        goto after_0;
    // 0x801069EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801069F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801069F4: lhu         $t8, 0x1A($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X1A);
    // 0x801069F8: srl         $t9, $t8, 5
    ctx->r25 = S32(U32(ctx->r24) >> 5);
    // 0x801069FC: slt         $v1, $t9, $v0
    ctx->r3 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80106A00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80106A04:
    // 0x80106A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106A0C: jr          $ra
    // 0x80106A10: nop

    return;
    // 0x80106A10: nop

    // 0x80106A14: nop

    // 0x80106A18: nop

    // 0x80106A1C: nop

;}
RECOMP_FUNC void func_800A3910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3910: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3914: jr          $ra
    // 0x800A3918: sb          $a1, 0x3D($t6)
    MEM_B(0X3D, ctx->r14) = ctx->r5;
    return;
    // 0x800A3918: sb          $a1, 0x3D($t6)
    MEM_B(0X3D, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800BCC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BCC88: jr          $ra
    // 0x800BCC8C: lbu         $v0, -0x7D13($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7D13);
    return;
    // 0x800BCC8C: lbu         $v0, -0x7D13($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7D13);
;}
RECOMP_FUNC void func_8080005C_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080006C: jal         0x80100094
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800074: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800078: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8080007C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800080: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800084: bltzl       $t8, L_80800370
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800088: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800370;
    }
    goto skip_0;
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080008C: jal         0x8010D254
    // 0x80800090: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800090: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800094: jal         0x800D9078
    // 0x80800098: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800098: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x8080009C: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x808000A0: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808000A4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808000A8: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x808000AC: beq         $at, $zero, L_8080036C
    if (ctx->r1 == 0) {
        // 0x808000B0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8080036C;
    }
    // 0x808000B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1388, 0XB50) << 16);
    // 0x808000B8: addu        $at, $at, $t1
    gpr jr_addend_808000C0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808000BC: lw          $t1, 0xB50($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1388, 0XB50));
    // 0x808000C0: jr          $t1
    // 0x808000C4: nop

    switch (jr_addend_808000C0 >> 2) {
        case 0: goto L_808000C8; break;
        case 1: goto L_808000E8; break;
        case 2: goto L_80800228; break;
        case 3: goto L_80800284; break;
        case 4: goto L_808002FC; break;
        default: switch_error(__func__, 0x808000C0, 0x80800B50);
    }
    // 0x808000C4: nop

L_808000C8:
    // 0x808000C8: jal         0x808007F0
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007F0_chflowerbaddie(rdram, ctx);
        goto after_3;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D0: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x808000D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x80102424
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000E0: b           L_80800370
    // 0x808000E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800370;
    // 0x808000E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E8:
    // 0x808000E8: jal         0x80101F24
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_5;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1388, 0XB64) << 16);
    // 0x808000F4: lwc1        $f4, 0xB64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1388, 0XB64));
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1388, 0XC80) << 16);
    // 0x80800100: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800104: nop

    // 0x80800108: bc1fl       L_80800124
    if (!c1cs) {
        // 0x8080010C: lbu         $t5, 0x65($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X65);
            goto L_80800124;
    }
    goto skip_1;
    // 0x8080010C: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x80800110: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800114: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80800118: b           L_8080012C
    // 0x8080011C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_8080012C;
    // 0x8080011C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80800120: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
L_80800124:
    // 0x80800124: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x80800128: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_8080012C:
    // 0x8080012C: jal         0x80800980
    // 0x80800130: addiu       $a1, $a1, 0xC80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1388, 0XC80));
    func_80800980_chflowerbaddie(rdram, ctx);
        goto after_6;
    // 0x80800130: addiu       $a1, $a1, 0xC80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1388, 0XC80));
    after_6:
    // 0x80800134: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1388, 0XC5C) << 16);
    // 0x80800138: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x8080013C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800140: addiu       $a2, $a2, 0xC5C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1388, 0XC5C));
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80089D20
    // 0x8080014C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080014C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800150: jal         0x80101F24
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_8;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800158: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080015C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800160: nop

    // 0x80800164: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800168: nop

    // 0x8080016C: bc1fl       L_808001B4
    if (!c1cs) {
        // 0x80800170: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808001B4;
    }
    goto skip_2;
    // 0x80800170: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x80800174: jal         0x80101F24
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_9;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080017C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1388, 0XC68) << 16);
    // 0x80800180: addiu       $a1, $a1, 0xC68
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1388, 0XC68));
    // 0x80800184: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800188: jal         0x800F3780
    // 0x8080018C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_10;
    // 0x8080018C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_10:
    // 0x80800190: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x808009F0
    // 0x8080019C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808009F0_chflowerbaddie(rdram, ctx);
        goto after_11;
    // 0x8080019C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x808001A0: bne         $v0, $zero, L_80800208
    if (ctx->r2 != 0) {
        // 0x808001A4: nop
    
            goto L_80800208;
    }
    // 0x808001A4: nop

    // 0x808001A8: b           L_80800370
    // 0x808001AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800370;
    // 0x808001AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001B0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_808001B4:
    // 0x808001B4: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x808001B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808001BC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808001C0: bgez        $t9, L_808001D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D8;
    }
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80089BF0
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001D0: b           L_808001E4
    // 0x808001D4: nop

        goto L_808001E4;
    // 0x808001D4: nop

L_808001D8:
    // 0x808001D8: jal         0x80102D78
    // 0x808001DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102D78(rdram, ctx);
        goto after_13;
    // 0x808001DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808001E0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808001E4:
    // 0x808001E4: jal         0x800D8FF8
    // 0x808001E8: nop

    func_800D8FF8(rdram, ctx);
        goto after_14;
    // 0x808001E8: nop

    after_14:
    // 0x808001EC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808001F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808001FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800200: jal         0x80102B2C
    // 0x80800204: nop

    func_80102B2C(rdram, ctx);
        goto after_15;
    // 0x80800204: nop

    after_15:
L_80800208:
    // 0x80800208: jal         0x80101DDC
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800210: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x80102424
    // 0x8080021C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x8080021C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800220: b           L_80800370
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800370;
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800228:
    // 0x80800228: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1388, 0XC94) << 16);
    // 0x8080022C: addiu       $a1, $a1, 0xC94
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1388, 0XC94));
    // 0x80800230: jal         0x80800980
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800980_chflowerbaddie(rdram, ctx);
        goto after_18;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800238: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080023C: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800240: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800244: nop

    // 0x80800248: bc1tl       L_80800370
    if (c1cs) {
        // 0x8080024C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800370;
    }
    goto skip_3;
    // 0x8080024C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800250: jal         0x80101F24
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_19;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800258: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1388, 0XCA8) << 16);
    // 0x8080025C: addiu       $a1, $a1, 0xCA8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1388, 0XCA8));
    // 0x80800260: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800264: jal         0x800F3780
    // 0x80800268: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_20;
    // 0x80800268: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_20:
    // 0x8080026C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x808009F0
    // 0x80800278: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808009F0_chflowerbaddie(rdram, ctx);
        goto after_21;
    // 0x80800278: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_21:
    // 0x8080027C: b           L_80800370
    // 0x80800280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800370;
    // 0x80800280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800284:
    // 0x80800284: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1388, 0XC5C) << 16);
    // 0x80800288: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x8080028C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800290: addiu       $a2, $a2, 0xC5C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1388, 0XC5C));
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80089D20
    // 0x8080029C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x8080029C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x808002A0: jal         0x80101F24
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_23;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808002A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1388, 0XB68) << 16);
    // 0x808002AC: lwc1        $f4, 0xB68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1388, 0XB68));
    // 0x808002B0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808002B4: nop

    // 0x808002B8: bc1fl       L_808002D4
    if (!c1cs) {
        // 0x808002BC: lbu         $t3, 0x65($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X65);
            goto L_808002D4;
    }
    goto skip_4;
    // 0x808002BC: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    skip_4:
    // 0x808002C0: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808002C4: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808002C8: b           L_808002DC
    // 0x808002CC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_808002DC;
    // 0x808002CC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808002D0: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
L_808002D4:
    // 0x808002D4: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x808002D8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808002DC:
    // 0x808002DC: jal         0x80101DDC
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_24;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808002E4: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x808002E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: jal         0x80102424
    // 0x808002F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_25;
    // 0x808002F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808002F4: b           L_80800370
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800370;
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002FC:
    // 0x808002FC: jal         0x80101DDC
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_26;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800304: beql        $v0, $zero, L_80800370
    if (ctx->r2 == 0) {
        // 0x80800308: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800370;
    }
    goto skip_5;
    // 0x80800308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8080030C: jal         0x808007F0
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007F0_chflowerbaddie(rdram, ctx);
        goto after_27;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800314: bnel        $v0, $zero, L_8080034C
    if (ctx->r2 != 0) {
        // 0x80800318: lw          $t8, 0x64($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X64);
            goto L_8080034C;
    }
    goto skip_6;
    // 0x80800318: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x8080031C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800324: sll         $t7, $t5, 11
    ctx->r15 = S32(ctx->r13 << 11);
    // 0x80800328: bgez        $t7, L_80800338
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080032C: nop
    
            goto L_80800338;
    }
    // 0x8080032C: nop

    // 0x80800330: b           L_80800338
    // 0x80800334: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800338;
    // 0x80800334: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800338:
    // 0x80800338: jal         0x80102424
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800340: b           L_80800370
    // 0x80800344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800370;
    // 0x80800344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800348: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
L_8080034C:
    // 0x8080034C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800350: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800354: bgez        $t0, L_80800364
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800358: nop
    
            goto L_80800364;
    }
    // 0x80800358: nop

    // 0x8080035C: b           L_80800364
    // 0x80800360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80800364;
    // 0x80800360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80800364:
    // 0x80800364: jal         0x80102424
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_8080036C:
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800370:
    // 0x80800370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800374: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800378: jr          $ra
    // 0x8080037C: nop

    return;
    // 0x8080037C: nop

;}
RECOMP_FUNC void func_800B562C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B562C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5634: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B5638: jal         0x8001BAFC
    // 0x800B563C: lw          $a0, 0x7F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7F10);
    defrag(rdram, ctx);
        goto after_0;
    // 0x800B563C: lw          $a0, 0x7F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7F10);
    after_0:
    // 0x800B5640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5648: sw          $v0, 0x7F10($at)
    MEM_W(0X7F10, ctx->r1) = ctx->r2;
    // 0x800B564C: jr          $ra
    // 0x800B5650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B5650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fxstep_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808005CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808005D0: jal         0x808002B4
    // 0x808005D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_808002B4_fxstep(rdram, ctx);
        goto after_0;
    // 0x808005D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x808005D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E0: jr          $ra
    // 0x808005E4: nop

    return;
    // 0x808005E4: nop

;}
RECOMP_FUNC void func_80802B94_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802B98: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80802B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802BA0: beq         $a1, $at, L_80802BDC
    if (ctx->r5 == ctx->r1) {
        // 0x80802BA4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80802BDC;
    }
    // 0x80802BA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80802BA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80802BAC: jal         0x80088418
    // 0x80802BB0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _gczoomboxdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80802BB0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802BB4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80802BB8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80802BBC: jal         0x800D674C
    // 0x80802BC0: sh          $v0, 0x140($a2)
    MEM_H(0X140, ctx->r6) = ctx->r2;
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80802BC0: sh          $v0, 0x140($a2)
    MEM_H(0X140, ctx->r6) = ctx->r2;
    after_1:
    // 0x80802BC4: jal         0x800AF5A0
    // 0x80802BC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_2;
    // 0x80802BC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80802BCC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80802BD0: sb          $v0, 0x1D1($a2)
    MEM_B(0X1D1, ctx->r6) = ctx->r2;
    // 0x80802BD4: b           L_80802BE4
    // 0x80802BD8: sb          $zero, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = 0;
        goto L_80802BE4;
    // 0x80802BD8: sb          $zero, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = 0;
L_80802BDC:
    // 0x80802BDC: sh          $zero, 0x140($a2)
    MEM_H(0X140, ctx->r6) = 0;
    // 0x80802BE0: sb          $zero, 0x1D1($a2)
    MEM_B(0X1D1, ctx->r6) = 0;
L_80802BE4:
    // 0x80802BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802BEC: jr          $ra
    // 0x80802BF0: nop

    return;
    // 0x80802BF0: nop

;}
RECOMP_FUNC void func_8080000C_chintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800028: jal         0x80100094
    // 0x8080002C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080002C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800030: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: addiu       $t5, $zero, 0xC26
    ctx->r13 = ADD32(0, 0XC26);
    // 0x80800038: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080003C: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x80800040: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80800044: sh          $t5, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r13;
    // 0x80800048: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x8080004C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800050: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x80800054: beq         $t7, $zero, L_80800118
    if (ctx->r15 == 0) {
        // 0x80800058: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_80800118;
    }
    // 0x80800058: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8080005C: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80800060: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80800064: addiu       $t2, $zero, 0xC25
    ctx->r10 = ADD32(0, 0XC25);
    // 0x80800068: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
L_8080006C:
    // 0x8080006C: bne         $t1, $a0, L_808000C0
    if (ctx->r9 != ctx->r4) {
        // 0x80800070: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_808000C0;
    }
    // 0x80800070: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800074: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    // 0x80800078: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    // 0x8080007C: addu        $v1, $t0, $a1
    ctx->r3 = ADD32(ctx->r8, ctx->r5);
    // 0x80800080: beql        $t8, $zero, L_808000A8
    if (ctx->r24 == 0) {
        // 0x80800084: addu        $t9, $t0, $a1
        ctx->r25 = ADD32(ctx->r8, ctx->r5);
            goto L_808000A8;
    }
    goto skip_0;
    // 0x80800084: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    skip_0:
    // 0x80800088: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8080008C: sb          $a0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r4;
L_80800090:
    // 0x80800090: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80800094: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800098: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080009C: bnel        $a0, $zero, L_80800090
    if (ctx->r4 != 0) {
        // 0x808000A0: sb          $a0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r4;
            goto L_80800090;
    }
    goto skip_1;
    // 0x808000A0: sb          $a0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r4;
    skip_1:
    // 0x808000A4: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
L_808000A8:
    // 0x808000A8: sb          $zero, -0x1($t9)
    MEM_B(-0X1, ctx->r25) = 0;
    // 0x808000AC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808000B0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x808000B4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x808000B8: sh          $t2, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r10;
    // 0x808000BC: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
L_808000C0:
    // 0x808000C0: bne         $t3, $v1, L_80800104
    if (ctx->r11 != ctx->r3) {
        // 0x808000C4: addiu       $a1, $a3, 0x1
        ctx->r5 = ADD32(ctx->r7, 0X1);
            goto L_80800104;
    }
    // 0x808000C4: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    // 0x808000C8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x808000CC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x808000D0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x808000D4: sh          $a1, 0x16($t7)
    MEM_H(0X16, ctx->r15) = ctx->r5;
    // 0x808000D8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x808000DC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x808000E0: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x808000E4: sh          $t5, 0x2A($t6)
    MEM_H(0X2A, ctx->r14) = ctx->r13;
    // 0x808000E8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x808000EC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x808000F0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x808000F4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x808000F8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x808000FC: beq         $t4, $t9, L_80800118
    if (ctx->r12 == ctx->r25) {
        // 0x80800100: nop
    
            goto L_80800118;
    }
    // 0x80800100: nop

L_80800104:
    // 0x80800104: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    // 0x80800108: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080010C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800110: bne         $a0, $zero, L_8080006C
    if (ctx->r4 != 0) {
        // 0x80800114: nop
    
            goto L_8080006C;
    }
    // 0x80800114: nop

L_80800118:
    // 0x80800118: jal         0x800DA544
    // 0x8080011C: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x8080011C: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_2:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void func_808005AC_cadbmgrDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005C0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808005C4: jal         0x800A57EC
    // 0x808005C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A57EC(rdram, ctx);
        goto after_0;
    // 0x808005C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808005CC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808005D0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808005D4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x808005D8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x808005DC: lh          $a0, 0x1E($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X1E);
    // 0x808005E0: jal         0x8001B798
    // 0x808005E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x808005E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808005E8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808005EC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808005F0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808005F4: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808005F8: mflo        $t1
    ctx->r9 = lo;
    // 0x808005FC: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x80800600: nop

    // 0x80800604: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800608: mflo        $t3
    ctx->r11 = lo;
    // 0x8080060C: addu        $a1, $v0, $t3
    ctx->r5 = ADD32(ctx->r2, ctx->r11);
    // 0x80800610: jal         0x8001BBA0
    // 0x80800614: nop

    rare_memcpy(rdram, ctx);
        goto after_2;
    // 0x80800614: nop

    after_2:
    // 0x80800618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080061C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800620: jr          $ra
    // 0x80800624: nop

    return;
    // 0x80800624: nop

    // 0x80800628: nop

    // 0x8080062C: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A658: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A658);
    return;
    // 0x8008A65C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080185C_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080185C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801864: jal         0x80084C40
    // 0x80801868: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafly_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80801868: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080186C: jal         0x80800188
    // 0x80801870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bskazfly(rdram, ctx);
        goto after_1;
    // 0x80801870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080187C: jr          $ra
    // 0x80801880: nop

    return;
    // 0x80801880: nop

;}
RECOMP_FUNC void fxstep_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x80800524: jr          $ra
    // 0x80800528: sw          $a2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r6;
    return;
    // 0x80800528: sw          $a2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void _bsjump_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832C8: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832C8);
    return;
    // 0x800832CC: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void _bsbeemain_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828C0: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x800828C0);
    return;
    // 0x800828C4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808000F4_chmole_overworld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800100: jal         0x800899D0
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800110: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800114: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800118: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080011C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800120: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800124: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800128: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8080012C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800130: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800134: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800138: bgez        $t4, L_8080014C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080013C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080014C;
    }
    // 0x8080013C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800140: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800144: nop

    // 0x80800148: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080014C:
    // 0x8080014C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_8010CD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CD88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010CD8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CD90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010CD94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010CD98: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010CD9C: jal         0x8010CE28
    // 0x8010CDA0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8010CE28(rdram, ctx);
        goto after_0;
    // 0x8010CDA0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8010CDA4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8010CDA8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010CDAC: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x8010CDB0: jal         0x80013728
    // 0x8010CDB4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x8010CDB4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x8010CDB8: jal         0x800F2100
    // 0x8010CDBC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x8010CDBC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8010CDC0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8010CDC4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8010CDC8: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010CDCC: lwc1        $f8, 0x48($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X48);
    // 0x8010CDD0: jal         0x80013728
    // 0x8010CDD4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80013728(rdram, ctx);
        goto after_3;
    // 0x8010CDD4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_3:
    // 0x8010CDD8: jal         0x800F2100
    // 0x8010CDDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8010CDDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x8010CDE0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010CDE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010CDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CDEC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8010CDF0: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010CDF4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010CDF8: bc1f        L_8010CE04
    if (!c1cs) {
        // 0x8010CDFC: nop
    
            goto L_8010CE04;
    }
    // 0x8010CDFC: nop

    // 0x8010CE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010CE04:
    // 0x8010CE04: beq         $v0, $zero, L_8010CE20
    if (ctx->r2 == 0) {
        // 0x8010CE08: nop
    
            goto L_8010CE20;
    }
    // 0x8010CE08: nop

    // 0x8010CE0C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8010CE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010CE14: bc1f        L_8010CE20
    if (!c1cs) {
        // 0x8010CE18: nop
    
            goto L_8010CE20;
    }
    // 0x8010CE18: nop

    // 0x8010CE1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010CE20:
    // 0x8010CE20: jr          $ra
    // 0x8010CE24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010CE24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800540_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800544: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080054C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800550: jal         0x8008CABC
    // 0x80800554: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800554: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x80800558: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8080055C: jal         0x80084C10
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080056C: jal         0x80084C18
    // 0x80800570: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    _bafly_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800570: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_2:
    // 0x80800574: jal         0x80084C20
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800584: jal         0x80091A58
    // 0x80800588: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x80800588: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_4:
    // 0x8080058C: beq         $v0, $zero, L_808005A0
    if (ctx->r2 == 0) {
        // 0x80800590: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_808005A0;
    }
    // 0x80800590: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800594: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80800598: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080059C: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
L_808005A0:
    // 0x808005A0: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x808005A4: lbu         $t9, 0x1C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1C);
    // 0x808005A8: beq         $t9, $zero, L_808005E4
    if (ctx->r25 == 0) {
        // 0x808005AC: nop
    
            goto L_808005E4;
    }
    // 0x808005AC: nop

    // 0x808005B0: jal         0x8001211C
    // 0x808005B4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_5;
    // 0x808005B4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_5:
    // 0x808005B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005BC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x808005C0: mfhi        $t0
    ctx->r8 = hi;
    // 0x808005C4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808005C8: bne         $t0, $zero, L_808005E4
    if (ctx->r8 != 0) {
        // 0x808005CC: nop
    
            goto L_808005E4;
    }
    // 0x808005CC: nop

    // 0x808005D0: lw          $t1, 0x188($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X188);
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x80084C28
    // 0x808005DC: sb          $zero, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = 0;
    _bafly_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x808005DC: sb          $zero, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = 0;
    after_6:
    // 0x808005E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808005E4:
    // 0x808005E4: bne         $v1, $zero, L_808005F8
    if (ctx->r3 != 0) {
        // 0x808005E8: nop
    
            goto L_808005F8;
    }
    // 0x808005E8: nop

    // 0x808005EC: lw          $t2, 0x15C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X15C);
    // 0x808005F0: beq         $t2, $zero, L_80800648
    if (ctx->r10 == 0) {
        // 0x808005F4: nop
    
            goto L_80800648;
    }
    // 0x808005F4: nop

L_808005F8:
    // 0x808005F8: beq         $v1, $zero, L_80800618
    if (ctx->r3 == 0) {
        // 0x808005FC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800618;
    }
    // 0x808005FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800600: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800604: jal         0x8008B1BC
    // 0x80800608: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80800608: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_7:
    // 0x8080060C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800610: jal         0x80085948
    // 0x80800614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_80800618:
    // 0x80800618: lw          $t3, 0x15C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X15C);
    // 0x8080061C: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x80800620: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800624: beq         $t3, $zero, L_80800640
    if (ctx->r11 == 0) {
        // 0x80800628: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800640;
    }
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800630: jal         0x80084598
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800638: b           L_80800648
    // 0x8080063C: nop

        goto L_80800648;
    // 0x8080063C: nop

L_80800640:
    // 0x80800640: jal         0x80084598
    // 0x80800644: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800644: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
L_80800648:
    // 0x80800648: jal         0x80084590
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800650: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x80084C00
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafly_entrypoint_7(rdram, ctx);
        goto after_12;
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800660: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800664: beq         $v0, $zero, L_8080067C
    if (ctx->r2 == 0) {
        // 0x80800668: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080067C;
    }
    // 0x80800668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080066C: beq         $v0, $at, L_80800694
    if (ctx->r2 == ctx->r1) {
        // 0x80800670: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800694;
    }
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: b           L_80800760
    // 0x80800678: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
        goto L_80800760;
    // 0x80800678: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
L_8080067C:
    // 0x8080067C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80800680: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800684: beql        $t4, $zero, L_80800760
    if (ctx->r12 == 0) {
        // 0x80800688: lui         $a1, 0x3E0B
        ctx->r5 = S32(0X3E0B << 16);
            goto L_80800760;
    }
    goto skip_0;
    // 0x80800688: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
    skip_0:
    // 0x8080068C: b           L_8080075C
    // 0x80800690: sw          $t5, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r13;
        goto L_8080075C;
    // 0x80800690: sw          $t5, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r13;
L_80800694:
    // 0x80800694: jal         0x80084C00
    // 0x80800698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafly_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800698: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8080069C: jal         0x8009BFD8
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_14;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808006A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808006A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006AC: jal         0x800136E4
    // 0x808006B0: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_15;
    // 0x808006B0: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_15:
    // 0x808006B4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808006B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006BC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808006C0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808006C4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006C8: nop

    // 0x808006CC: bc1fl       L_808006F8
    if (!c1cs) {
        // 0x808006D0: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_808006F8;
    }
    goto skip_1;
    // 0x808006D0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x808006D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006D8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808006DC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808006E0: nop

    // 0x808006E4: bc1fl       L_808006F8
    if (!c1cs) {
        // 0x808006E8: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_808006F8;
    }
    goto skip_2;
    // 0x808006E8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x808006EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808006F0: nop

    // 0x808006F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_808006F8:
    // 0x808006F8: jal         0x8009BF5C
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BF5C(rdram, ctx);
        goto after_16;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800700: jal         0x80084C70
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_21(rdram, ctx);
        goto after_17;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800708: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8080070C: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800710: nop
    
            goto L_8080073C;
    }
    // 0x80800710: nop

    // 0x80800714: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800718: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080071C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800720: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080072C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800730: jal         0x8009BA58
    // 0x80800734: nop

    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_18;
    // 0x80800734: nop

    after_18:
    // 0x80800738: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8080073C:
    // 0x8080073C: bne         $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x80800740: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080075C;
    }
    // 0x80800740: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800744: lui         $a1, 0x3F1E
    ctx->r5 = S32(0X3F1E << 16);
    // 0x80800748: jal         0x8008B1BC
    // 0x8080074C: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    anctrl_setDuration(rdram, ctx);
        goto after_19;
    // 0x8080074C: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    after_19:
    // 0x80800750: jal         0x80084C68
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_20(rdram, ctx);
        goto after_20;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800758: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_8080075C:
    // 0x8080075C: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
L_80800760:
    // 0x80800760: ori         $a1, $a1, 0xF28
    ctx->r5 = ctx->r5 | 0XF28;
    // 0x80800764: jal         0x8008B348
    // 0x80800768: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    anctrl_isAt(rdram, ctx);
        goto after_21;
    // 0x80800768: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_21:
    // 0x8080076C: beq         $v0, $zero, L_8080079C
    if (ctx->r2 == 0) {
        // 0x80800770: lui         $a2, 0x3F19
        ctx->r6 = S32(0X3F19 << 16);
            goto L_8080079C;
    }
    // 0x80800770: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800774: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800778: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x8080077C: addiu       $t7, $zero, 0x2EE0
    ctx->r15 = ADD32(0, 0X2EE0);
    // 0x80800780: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800784: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800788: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080078C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: jal         0x8009DFD4
    // 0x80800798: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DFD4(rdram, ctx);
        goto after_22;
    // 0x80800798: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_22:
L_8080079C:
    // 0x8080079C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808007A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007A4: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x808007A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007AC: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x808007B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007B4: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x808007B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808007C4: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x808007C8: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x808007CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808007D0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x808007D4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x808007D8: jal         0x80084C08
    // 0x808007DC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    _bafly_entrypoint_8(rdram, ctx);
        goto after_23;
    // 0x808007DC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_23:
    // 0x808007E0: jal         0x800D8FF8
    // 0x808007E4: nop

    func_800D8FF8(rdram, ctx);
        goto after_24;
    // 0x808007E4: nop

    after_24:
    // 0x808007E8: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x808007EC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007F0: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x808007F4: jal         0x800F0E00
    // 0x808007F8: sub.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_25;
    // 0x808007F8: sub.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f0.fl;
    after_25:
    // 0x808007FC: lw          $t9, 0x188($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X188);
    // 0x80800800: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x8080080C: lw          $t0, 0x188($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X188);
    // 0x80800810: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80800814: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800818: nop

    // 0x8080081C: bc1f        L_80800858
    if (!c1cs) {
        // 0x80800820: nop
    
            goto L_80800858;
    }
    // 0x80800820: nop

    // 0x80800824: jal         0x80091A58
    // 0x80800828: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_26;
    // 0x80800828: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_26:
    // 0x8080082C: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800830: nop
    
            goto L_80800858;
    }
    // 0x80800830: nop

    // 0x80800834: jal         0x8008D0E0
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D0E0(rdram, ctx);
        goto after_27;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080083C: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800840: nop
    
            goto L_80800858;
    }
    // 0x80800840: nop

    // 0x80800844: jal         0x80084C28
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_12(rdram, ctx);
        goto after_28;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8080084C: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800850: addiu       $t1, $zero, 0x174
        ctx->r9 = ADD32(0, 0X174);
            goto L_80800858;
    }
    // 0x80800850: addiu       $t1, $zero, 0x174
    ctx->r9 = ADD32(0, 0X174);
    // 0x80800854: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80800858:
    // 0x80800858: jal         0x8008E35C
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_29;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800860: beq         $v0, $zero, L_8080086C
    if (ctx->r2 == 0) {
        // 0x80800864: addiu       $t2, $zero, 0x15D
        ctx->r10 = ADD32(0, 0X15D);
            goto L_8080086C;
    }
    // 0x80800864: addiu       $t2, $zero, 0x15D
    ctx->r10 = ADD32(0, 0X15D);
    // 0x80800868: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8080086C:
    // 0x8080086C: jal         0x80084BD8
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800874: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x80800878: addiu       $t3, $zero, 0xBB
        ctx->r11 = ADD32(0, 0XBB);
            goto L_80800880;
    }
    // 0x80800878: addiu       $t3, $zero, 0xBB
    ctx->r11 = ADD32(0, 0XBB);
    // 0x8080087C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_80800880:
    // 0x80800880: jal         0x800845B0
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baboost_entrypoint_5(rdram, ctx);
        goto after_31;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: jal         0x8009E5C8
    // 0x80800890: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_32;
    // 0x80800890: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_32:
    // 0x80800894: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800898: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080089C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808008A0: jr          $ra
    // 0x808008A4: nop

    return;
    // 0x808008A4: nop

;}
RECOMP_FUNC void func_800AAFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAFEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AAFF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800AAFF4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800AAFF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AAFFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800AB000: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800AB004: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800AB008: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800AB00C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_800AB010:
    // 0x800AB010: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AB014: lwc1        $f2, 0x0($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800AB018: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800AB01C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800AB020: nop

    // 0x800AB024: bc1fl       L_800AB054
    if (!c1cs) {
        // 0x800AB028: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_800AB054;
    }
    goto skip_0;
    // 0x800AB028: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_0:
    // 0x800AB02C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AB030: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800AB034: nop

    // 0x800AB038: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AB03C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800AB040: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800AB044: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800AB048: b           L_800AB074
    // 0x800AB04C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_800AB074;
    // 0x800AB04C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800AB050: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_800AB054:
    // 0x800AB054: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AB058: nop

    // 0x800AB05C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800AB060: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AB064: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800AB068: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AB06C: nop

    // 0x800AB070: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800AB074:
    // 0x800AB074: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AB078: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AB07C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AB080: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800AB084: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AB088: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AB08C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AB090: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AB094: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x800AB098: bne         $t2, $a0, L_800AB010
    if (ctx->r10 != ctx->r4) {
        // 0x800AB09C: sw          $t3, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r11;
            goto L_800AB010;
    }
    // 0x800AB09C: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
    // 0x800AB0A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AB0A4: jal         0x800EFB24
    // 0x800AB0A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800AB0A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800AB0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AB0B4: jr          $ra
    // 0x800AB0B8: nop

    return;
    // 0x800AB0B8: nop

;}
RECOMP_FUNC void func_8009D2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D2D8: lw          $t6, 0xFC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XFC);
    // 0x8009D2DC: jr          $ra
    // 0x8009D2E0: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
    return;
    // 0x8009D2E0: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800A5A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5A4C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5A50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5A54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5A58: addiu       $a1, $a1, 0x70F0
    ctx->r5 = ADD32(ctx->r5, 0X70F0);
    // 0x800A5A5C: lbu         $v0, 0x762C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X762C);
    // 0x800A5A60: addiu       $t6, $t6, -0x6440
    ctx->r14 = ADD32(ctx->r14, -0X6440);
    // 0x800A5A64: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A5A68: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A5A6C: lw          $t7, -0x6428($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6428);
    // 0x800A5A70: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A5A74: addiu       $v1, $t8, -0x6428
    ctx->r3 = ADD32(ctx->r24, -0X6428);
    // 0x800A5A78: beq         $t7, $zero, L_800A5AA4
    if (ctx->r15 == 0) {
        // 0x800A5A7C: nop
    
            goto L_800A5AA4;
    }
    // 0x800A5A7C: nop

    // 0x800A5A80: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_800A5A84:
    // 0x800A5A84: bnel        $v0, $a0, L_800A5A98
    if (ctx->r2 != ctx->r4) {
        // 0x800A5A88: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_800A5A98;
    }
    goto skip_0;
    // 0x800A5A88: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x800A5A8C: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800A5A90: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800A5A94: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_800A5A98:
    // 0x800A5A98: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A5A9C: bne         $a0, $zero, L_800A5A84
    if (ctx->r4 != 0) {
        // 0x800A5AA0: nop
    
            goto L_800A5A84;
    }
    // 0x800A5AA0: nop

L_800A5AA4:
    // 0x800A5AA4: jr          $ra
    // 0x800A5AA8: nop

    return;
    // 0x800A5AA8: nop

    // 0x800A5AAC: nop

;}
RECOMP_FUNC void func_80800128_bskazfly(uint8_t* rdram, recomp_context* ctx) {
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
    func_808000AC_bskazfly(rdram, ctx);
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
RECOMP_FUNC void chpowerhut_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808002B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808002C4: beq         $a1, $at, L_808002E0
    if (ctx->r5 == ctx->r1) {
        // 0x808002C8: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_808002E0;
    }
    // 0x808002C8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808002CC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002D0: beq         $a1, $at, L_80800354
    if (ctx->r5 == ctx->r1) {
        // 0x808002D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: b           L_808003EC
    // 0x808002DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003EC;
    // 0x808002DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002E0:
    // 0x808002E0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808002E4: jal         0x800DA298
    // 0x808002E8: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002E8: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    after_0:
    // 0x808002EC: bne         $v0, $zero, L_80800304
    if (ctx->r2 != 0) {
        // 0x808002F0: nop
    
            goto L_80800304;
    }
    // 0x808002F0: nop

    // 0x808002F4: jal         0x80088848
    // 0x808002F8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808002F8: nop

    after_1:
    // 0x808002FC: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800300: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800304:
    // 0x80800304: b           L_808003EC
    // 0x80800308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003EC;
    // 0x80800308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080030C:
    // 0x8080030C: jal         0x80101FDC
    // 0x80800310: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800310: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x8008A4B0
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x80103110
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080032C: jal         0x80800400
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800400_chpowerhut(rdram, ctx);
        goto after_5;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800334: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800338: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800340: lhu         $a2, 0x2($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X2);
    // 0x80800344: jal         0x80085708
    // 0x80800348: lhu         $a3, 0x4($t7)
    ctx->r7 = MEM_HU(ctx->r15, 0X4);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x80800348: lhu         $a3, 0x4($t7)
    ctx->r7 = MEM_HU(ctx->r15, 0X4);
    after_6:
    // 0x8080034C: b           L_808003EC
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003EC;
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800354:
    // 0x80800354: jal         0x80100094
    // 0x80800358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800358: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080035C: jal         0x800C8A98
    // 0x80800360: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    func_800C8A98(rdram, ctx);
        goto after_8;
    // 0x80800360: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    after_8:
    // 0x80800364: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1076, 0X950) << 16);
    // 0x80800368: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8080036C: addiu       $a1, $a1, 0x950
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1076, 0X950));
    // 0x80800370: jal         0x800C8D4C
    // 0x80800374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_9;
    // 0x80800374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800378: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080037C: jal         0x800C8CB8
    // 0x80800380: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800C8CB8(rdram, ctx);
        goto after_10;
    // 0x80800380: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_10:
    // 0x80800384: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800388: jal         0x800DA298
    // 0x8080038C: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x8080038C: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    after_11:
    // 0x80800390: bne         $v0, $zero, L_808003A8
    if (ctx->r2 != 0) {
        // 0x80800394: nop
    
            goto L_808003A8;
    }
    // 0x80800394: nop

    // 0x80800398: jal         0x80088848
    // 0x8080039C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_12;
    // 0x8080039C: nop

    after_12:
    // 0x808003A0: beq         $v0, $zero, L_808003B4
    if (ctx->r2 == 0) {
        // 0x808003A4: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1076, 0X958) << 16);
            goto L_808003B4;
    }
    // 0x808003A4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1076, 0X958) << 16);
L_808003A8:
    // 0x808003A8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1076, 0X964) << 16);
    // 0x808003AC: b           L_808003B8
    // 0x808003B0: addiu       $a1, $a1, 0x964
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1076, 0X964));
        goto L_808003B8;
    // 0x808003B0: addiu       $a1, $a1, 0x964
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1076, 0X964));
L_808003B4:
    // 0x808003B4: addiu       $a1, $a1, 0x958
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1076, 0X958));
L_808003B8:
    // 0x808003B8: jal         0x800C8E84
    // 0x808003BC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800C8E84(rdram, ctx);
        goto after_13;
    // 0x808003BC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_13:
    // 0x808003C0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x808003C4: jal         0x800DA298
    // 0x808003C8: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808003C8: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    after_14:
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80103110
    // 0x808003D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80103110(rdram, ctx);
        goto after_15;
    // 0x808003D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_15:
    // 0x808003D8: b           L_808003EC
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003EC;
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003E0: b           L_808003EC
    // 0x808003E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003EC;
    // 0x808003E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003EC:
    // 0x808003EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003F8: jr          $ra
    // 0x808003FC: nop

    return;
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_800A6DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_800A6DAC");
    // 0x800A6DAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6DB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A6DB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A6DB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6DBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A6DC0: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x800A6DC4: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A6DC8: jal         0x800F6438
    // 0x800A6DCC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x800A6DCC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800A6DD0: beql        $v0, $zero, L_800A6EE4
    if (ctx->r2 == 0) {
        // 0x800A6DD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_0;
    // 0x800A6DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A6DD8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A6DDC: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x800A6DE0: jal         0x800F6640
    // 0x800A6DE4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F6640(rdram, ctx);
        goto after_1;
    // 0x800A6DE4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800A6DE8: beql        $v0, $zero, L_800A6EE4
    if (ctx->r2 == 0) {
        // 0x800A6DEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_1;
    // 0x800A6DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800A6DF0: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A6DF4: srl         $t8, $a0, 7
    ctx->r24 = S32(U32(ctx->r4) >> 7);
    // 0x800A6DF8: jal         0x800F6E80
    // 0x800A6DFC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F6E80(rdram, ctx);
        goto after_2;
    // 0x800A6DFC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x800A6E00: beql        $v0, $zero, L_800A6EE4
    if (ctx->r2 == 0) {
        // 0x800A6E04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_2;
    // 0x800A6E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800A6E08: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A6E0C: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x800A6E10: jal         0x800F55FC
    // 0x800A6E14: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F55FC(rdram, ctx);
        goto after_3;
    // 0x800A6E14: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x800A6E18: sll         $t0, $v0, 0
    ctx->r8 = S32(ctx->r2 << 0);
    // 0x800A6E1C: bltzl       $t0, L_800A6EE4
    if (SIGNED(ctx->r8) < 0) {
        // 0x800A6E20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_3;
    // 0x800A6E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800A6E24: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A6E28: srl         $t1, $a0, 7
    ctx->r9 = S32(U32(ctx->r4) >> 7);
    // 0x800A6E2C: jal         0x800F65D0
    // 0x800A6E30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800F65D0(rdram, ctx);
        goto after_4;
    // 0x800A6E30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x800A6E34: bnel        $v0, $zero, L_800A6E94
    if (ctx->r2 != 0) {
        // 0x800A6E38: lhu         $a0, 0x76($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X76);
            goto L_800A6E94;
    }
    goto skip_4;
    // 0x800A6E38: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    skip_4:
    // 0x800A6E3C: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x800A6E40: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800A6E44: bgezl       $t4, L_800A6EE4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A6E48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_5;
    // 0x800A6E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800A6E4C: jal         0x800F8B88
    // 0x800A6E50: nop

    func_800F8B88(rdram, ctx);
        goto after_5;
    // 0x800A6E50: nop

    after_5:
    // 0x800A6E54: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A6E58: bnel        $at, $zero, L_800A6E94
    if (ctx->r1 != 0) {
        // 0x800A6E5C: lhu         $a0, 0x76($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X76);
            goto L_800A6E94;
    }
    goto skip_6;
    // 0x800A6E5C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    skip_6:
    // 0x800A6E60: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A6E64: srl         $t5, $a0, 7
    ctx->r13 = S32(U32(ctx->r4) >> 7);
    // 0x800A6E68: jal         0x800F5410
    // 0x800A6E6C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800F5410(rdram, ctx);
        goto after_6;
    // 0x800A6E6C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_6:
    // 0x800A6E70: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A6E74: bnel        $v0, $at, L_800A6EE4
    if (ctx->r2 != ctx->r1) {
        // 0x800A6E78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_7;
    // 0x800A6E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800A6E7C: jal         0x800878A0
    // 0x800A6E80: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x800A6E80: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_7:
    // 0x800A6E84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A6E88: beql        $v0, $at, L_800A6EE4
    if (ctx->r2 == ctx->r1) {
        // 0x800A6E8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6EE4;
    }
    goto skip_8;
    // 0x800A6E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800A6E90: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_800A6E94:
    // 0x800A6E94: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800A6E98: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A6E9C: jal         0x800F5A00
    // 0x800A6EA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F5A00(rdram, ctx);
        goto after_8;
    // 0x800A6EA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_8:
    // 0x800A6EA4: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x800A6EA8: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x800A6EAC: jal         0x800F5628
    // 0x800A6EB0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F5628(rdram, ctx);
        goto after_9;
    // 0x800A6EB0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_9:
    // 0x800A6EB4: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x800A6EB8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800A6EBC: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x800A6EC0: bgez        $t0, L_800A6ED8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A6EC4: nop
    
            goto L_800A6ED8;
    }
    // 0x800A6EC4: nop

    if (tooie_player_shadow_hidden()) goto L_800A6EE4;
    // 0x800A6EC8: jal         0x800A5DB0
    // 0x800A6ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A5DB0(rdram, ctx);
        goto after_10;
    // 0x800A6ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800A6ED0: b           L_800A6EE4
    // 0x800A6ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A6EE4;
    // 0x800A6ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6ED8:
    if (tooie_circle_shadow_draw(rdram, ctx)) goto L_800A6EE4;
    // 0x800A6ED8: jal         0x800A6B24
    // 0x800A6EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A6B24(rdram, ctx);
        goto after_11;
    // 0x800A6EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800A6EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6EE4:
    // 0x800A6EE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A6EE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6EEC: jr          $ra
    // 0x800A6EF0: nop

    return;
    // 0x800A6EF0: nop

;}
RECOMP_FUNC void func_80800008_badust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void bssnowball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X1054) << 16);
    // 0x808004D4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004D8: jr          $ra
    // 0x808004DC: lw          $v0, 0x1054($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1054));
    return;
    // 0x808004DC: lw          $v0, 0x1054($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1054));
;}
RECOMP_FUNC void func_800A16B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A16B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A16B4: jr          $ra
    // 0x800A16B8: lbu         $v0, 0x7099($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7099);
    return;
    // 0x800A16B8: lbu         $v0, 0x7099($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7099);
;}
RECOMP_FUNC void bskaztorpedo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800BE8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X1730) << 16);
    // 0x80800BEC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800BF0: jr          $ra
    // 0x80800BF4: lw          $v0, 0x1730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1730));
    return;
    // 0x80800BF4: lw          $v0, 0x1730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1730));
;}
RECOMP_FUNC void func_8080112C_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080112C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801134: jal         0x80100094
    // 0x80801138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080113C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801140: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80801144: jal         0x800DA564
    // 0x80801148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x80801148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080114C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801154: lh          $t7, 0x2C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2C);
    // 0x80801158: bnel        $v0, $t7, L_8080116C
    if (ctx->r2 != ctx->r15) {
        // 0x8080115C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080116C;
    }
    goto skip_0;
    // 0x8080115C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801160: b           L_8080116C
    // 0x80801164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080116C;
    // 0x80801164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080116C:
    // 0x8080116C: jr          $ra
    // 0x80801170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801784_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801784: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80801788: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080178C: jr          $ra
    // 0x80801790: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    return;
    // 0x80801790: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
;}
RECOMP_FUNC void baanim_defrag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C92C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C930: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008C934: jal         0x8008AEB4
    // 0x8008C938: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_8008AEB4(rdram, ctx);
        goto after_0;
    // 0x8008C938: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8008C93C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8008C940: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8008C944: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8008C948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C94C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C950: jr          $ra
    // 0x8008C954: nop

    return;
    // 0x8008C954: nop

;}
RECOMP_FUNC void _chboilerid_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860A8: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x800860A8);
    return;
    // 0x800860AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _babee_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084578: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084578);
    return;
    // 0x8008457C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800A1624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1628: beq         $a0, $zero, L_800A1640
    if (ctx->r4 == 0) {
        // 0x800A162C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800A1640;
    }
    // 0x800A162C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1630: jal         0x800A1294
    // 0x800A1634: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A1294(rdram, ctx);
        goto after_0;
    // 0x800A1634: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800A1638: b           L_800A164C
    // 0x800A163C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A164C;
    // 0x800A163C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1640:
    // 0x800A1640: jal         0x800D284C
    // 0x800A1644: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    func_800D284C(rdram, ctx);
        goto after_1;
    // 0x800A1644: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    after_1:
    // 0x800A1648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A164C:
    // 0x800A164C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1650: jr          $ra
    // 0x800A1654: nop

    return;
    // 0x800A1654: nop

;}
RECOMP_FUNC void func_8008C200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C20C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008C210: jal         0x8008BD1C
    // 0x8008C214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_0;
    // 0x8008C214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8008C218: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x8008C21C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C220: jal         0x800AE1E8
    // 0x8008C224: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800AE1E8(rdram, ctx);
        goto after_1;
    // 0x8008C224: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x8008C228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C22C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C230: jr          $ra
    // 0x8008C234: nop

    return;
    // 0x8008C234: nop

;}
RECOMP_FUNC void func_8080016C_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800170: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800174: addiu       $v1, $zero, 0x9E7
    ctx->r3 = ADD32(0, 0X9E7);
    // 0x80800178: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080017C: bne         $t7, $at, L_8080018C
    if (ctx->r15 != ctx->r1) {
        // 0x80800180: nop
    
            goto L_8080018C;
    }
    // 0x80800180: nop

    // 0x80800184: jr          $ra
    // 0x80800188: addiu       $v0, $zero, 0x9E6
    ctx->r2 = ADD32(0, 0X9E6);
    return;
    // 0x80800188: addiu       $v0, $zero, 0x9E6
    ctx->r2 = ADD32(0, 0X9E6);
L_8080018C:
    // 0x8080018C: jr          $ra
    // 0x80800190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void idtwinklecolour_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800210: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800214: lh          $t6, 0x1E($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X1E);
    // 0x80800218: lh          $v0, 0x1C($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1C);
    // 0x8080021C: bnel        $t6, $v0, L_80800244
    if (ctx->r14 != ctx->r2) {
        // 0x80800220: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80800244;
    }
    goto skip_0;
    // 0x80800220: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80800224: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80800228: lh          $v0, 0x1C($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1C);
    // 0x8080022C: sh          $t7, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r15;
    // 0x80800230: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x80800234: sh          $t8, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r24;
    // 0x80800238: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x8080023C: sh          $t9, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r25;
    // 0x80800240: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
L_80800244:
    // 0x80800244: jr          $ra
    // 0x80800248: sh          $t0, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r8;
    return;
    // 0x80800248: sh          $t0, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r8;
;}
