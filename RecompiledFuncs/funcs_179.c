#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chfactorysmoke_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1184, 0X100) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1184, 0X100));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1184, 0X100));
;}
RECOMP_FUNC void func_80800064_bsbflip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800078: jal         0x8008CABC
    // 0x8080007C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080007C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800080: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800084: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800088: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8080008C: beq         $at, $zero, L_80800398
    if (ctx->r1 == 0) {
        // 0x80800090: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800398;
    }
    // 0x80800090: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800094: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(93, 0X600) << 16);
    // 0x80800098: addu        $at, $at, $t6
    gpr jr_addend_808000A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080009C: lw          $t6, 0x600($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(93, 0X600));
    // 0x808000A0: jr          $t6
    // 0x808000A4: nop

    switch (jr_addend_808000A0 >> 2) {
        case 0: goto L_808000A8; break;
        case 1: goto L_808000DC; break;
        case 2: goto L_8080019C; break;
        case 3: goto L_808002C0; break;
        case 4: goto L_8080030C; break;
        default: switch_error(__func__, 0x808000A0, 0x80800600);
    }
    // 0x808000A4: nop

L_808000A8:
    // 0x808000A8: jal         0x800C6DA0
    // 0x808000AC: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x808000AC: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    after_1:
    // 0x808000B0: jal         0x8009BC6C
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000B8: jal         0x8009BC90
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x800A0D44
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0D44(rdram, ctx);
        goto after_4;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000CC: jal         0x8009F1E0
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_5;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000D4: b           L_8080039C
    // 0x808000D8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
        goto L_8080039C;
    // 0x808000D8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_808000DC:
    // 0x808000DC: jal         0x8008AF24
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808000E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000E8: jal         0x8008B1A0
    // 0x808000EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_7;
    // 0x808000EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808000F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000F4: jal         0x8008AED4
    // 0x808000F8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    anctrl_setIndex(rdram, ctx);
        goto after_8;
    // 0x808000F8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_8:
    // 0x808000FC: lui         $a1, 0x4013
    ctx->r5 = S32(0X4013 << 16);
    // 0x80800100: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800104: jal         0x8008B1BC
    // 0x80800108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x80800108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8080010C: lui         $a2, 0x3F49
    ctx->r6 = S32(0X3F49 << 16);
    // 0x80800110: ori         $a2, $a2, 0x5E9E
    ctx->r6 = ctx->r6 | 0X5E9E;
    // 0x80800114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800118: jal         0x8008B1D4
    // 0x8080011C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_10;
    // 0x8080011C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800124: jal         0x8008B24C
    // 0x80800128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x80800128: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800130: jal         0x8008B134
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800138: jal         0x8008B064
    // 0x8080013C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x8080013C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800140: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80800144: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800154: jal         0x8009FFD8
    // 0x80800158: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_14;
    // 0x80800158: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x8080015C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800160: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x8009F1C8
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_15;
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800178: jal         0x8009F1C8
    // 0x8080017C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_16;
    // 0x8080017C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_16:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x800A0CF4
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_17;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x8080018C: jal         0x8009D874
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_18;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800194: b           L_8080039C
    // 0x80800198: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
        goto L_8080039C;
    // 0x80800198: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8080019C:
    // 0x8080019C: jal         0x8009EF04
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_19;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808001A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808001B4: nop

    // 0x808001B8: bc1t        L_8080025C
    if (c1cs) {
        // 0x808001BC: nop
    
            goto L_8080025C;
    }
    // 0x808001BC: nop

    // 0x808001C0: jal         0x8009C908
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setUpdateType(rdram, ctx);
        goto after_20;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x8009D2D8
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_21;
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_21:
    // 0x808001D4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x808001D8: addiu       $t8, $t8, -0x10FC
    ctx->r24 = ADD32(ctx->r24, -0X10FC);
    // 0x808001DC: beql        $t8, $zero, L_808001FC
    if (ctx->r24 == 0) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001E4: jal         0x8009EEB8
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_22;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808001EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F0: jal         0x8009C914
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_23;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001FC:
    // 0x808001FC: jal         0x8009C9C8
    // 0x80800200: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    yaw_rotateTimed(rdram, ctx);
        goto after_24;
    // 0x80800200: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_24:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x8009B800
    // 0x8080020C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_25;
    // 0x8080020C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_25:
    // 0x80800210: jal         0x8009C990
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_26;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800218: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080021C: jal         0x8009B9C0
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_27;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: jal         0x8009B9B0
    // 0x8080022C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_28;
    // 0x8080022C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_28:
    // 0x80800230: jal         0x8009C990
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_29;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800238: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8080023C: jal         0x8009BB00
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_30;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800244: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x8009BA68
    // 0x80800250: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_31;
    // 0x80800250: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_31:
    // 0x80800254: b           L_80800274
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800274;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080025C:
    // 0x8080025C: jal         0x8009B800
    // 0x80800260: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_32;
    // 0x80800260: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_32:
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x8009B9B0
    // 0x8080026C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_33;
    // 0x8080026C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_33:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800274:
    // 0x80800274: jal         0x8009BA58
    // 0x80800278: lui         $a1, 0x4466
    ctx->r5 = S32(0X4466 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_34;
    // 0x80800278: lui         $a1, 0x4466
    ctx->r5 = S32(0X4466 << 16);
    after_34:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x8009BCB4
    // 0x80800284: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_35;
    // 0x80800284: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_35:
    // 0x80800288: lui         $a1, 0xC405
    ctx->r5 = S32(0XC405 << 16);
    // 0x8080028C: ori         $a1, $a1, 0x5333
    ctx->r5 = ctx->r5 | 0X5333;
    // 0x80800290: jal         0x8009BCC4
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_36;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800298: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x8080029C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808002A0: jal         0x8008B1BC
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_37;
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: addiu       $a1, $zero, 0x5A6
    ctx->r5 = ADD32(0, 0X5A6);
    // 0x808002B0: jal         0x8009DE38
    // 0x808002B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_38;
    // 0x808002B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_38:
    // 0x808002B8: b           L_8080039C
    // 0x808002BC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
        goto L_8080039C;
    // 0x808002BC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_808002C0:
    // 0x808002C0: jal         0x8008AF24
    // 0x808002C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_39;
    // 0x808002C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_39:
    // 0x808002C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002CC: jal         0x8008B1A0
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_40;
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x808002D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002D8: jal         0x8008AED4
    // 0x808002DC: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    anctrl_setIndex(rdram, ctx);
        goto after_41;
    // 0x808002DC: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_41:
    // 0x808002E0: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
    // 0x808002E4: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    // 0x808002E8: jal         0x8008B1BC
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_42;
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_42:
    // 0x808002F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002F4: jal         0x8008B134
    // 0x808002F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_43;
    // 0x808002F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_43:
    // 0x808002FC: jal         0x8008B064
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_44;
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_44:
    // 0x80800304: b           L_8080039C
    // 0x80800308: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
        goto L_8080039C;
    // 0x80800308: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8080030C:
    // 0x8080030C: jal         0x8008AF24
    // 0x80800310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_45;
    // 0x80800310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_45:
    // 0x80800314: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800318: jal         0x8008AED4
    // 0x8080031C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    anctrl_setIndex(rdram, ctx);
        goto after_46;
    // 0x8080031C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_46:
    // 0x80800320: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x80800324: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800328: jal         0x8008B1BC
    // 0x8080032C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_47;
    // 0x8080032C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_47:
    // 0x80800330: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x80800334: ori         $a1, $a1, 0x4A23
    ctx->r5 = ctx->r5 | 0X4A23;
    // 0x80800338: jal         0x8008B24C
    // 0x8080033C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_48;
    // 0x8080033C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_48:
    // 0x80800340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800344: jal         0x8008B134
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_49;
    // 0x80800348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x8080034C: jal         0x8008B064
    // 0x80800350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_50;
    // 0x80800350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x8009B800
    // 0x8080035C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_51;
    // 0x8080035C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_51:
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x8009B9B0
    // 0x80800368: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_52;
    // 0x80800368: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_52:
    // 0x8080036C: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x80800370: jal         0x800EFD24
    // 0x80800374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFD24(rdram, ctx);
        goto after_53;
    // 0x80800374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_53:
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x8009BA9C
    // 0x80800380: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_54;
    // 0x80800380: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_54:
    // 0x80800384: jal         0x8009FE58
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_55;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x800A0CF4
    // 0x80800394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_56;
    // 0x80800394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_56:
L_80800398:
    // 0x80800398: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_8080039C:
    // 0x8080039C: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
    // 0x808003A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808003A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: jr          $ra
    // 0x808003B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808003B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800C5C_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C64: jal         0x80082838
    // 0x80800C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C6C: jal         0x8080039C
    // 0x80800C70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080039C_bsbeefly(rdram, ctx);
        goto after_1;
    // 0x80800C70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C78: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80800C7C: jal         0x80084C48
    // 0x80800C80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _bafly_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80800C80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80800C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C8C: jr          $ra
    // 0x80800C90: nop

    return;
    // 0x80800C90: nop

;}
RECOMP_FUNC void func_800B27BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27BC: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x800B27C0: bne         $v1, $zero, L_800B27D0
    if (ctx->r3 != 0) {
        // 0x800B27C4: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B27D0;
    }
    // 0x800B27C4: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B27C8: jr          $ra
    // 0x800B27CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B27CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B27D0:
    // 0x800B27D0: jr          $ra
    // 0x800B27D4: nop

    return;
    // 0x800B27D4: nop

;}
RECOMP_FUNC void func_800BD5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD5DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD5E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD5E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD5E8: jal         0x80087C60
    // 0x800BD5EC: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800BD5EC: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BD5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD5F8: jr          $ra
    // 0x800BD5FC: nop

    return;
    // 0x800BD5FC: nop

;}
RECOMP_FUNC void chboggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2072, 0X888) << 16);
    // 0x80800684: jr          $ra
    // 0x80800688: addiu       $v0, $v0, 0x888
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2072, 0X888));
    return;
    // 0x80800688: addiu       $v0, $v0, 0x888
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2072, 0X888));
    // 0x8080068C: nop

;}
RECOMP_FUNC void func_8010A73C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A73C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A744: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010A748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010A74C: jal         0x801039E4
    // 0x8010A750: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x8010A750: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8010A754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A75C: jr          $ra
    // 0x8010A760: nop

    return;
    // 0x8010A760: nop

;}
RECOMP_FUNC void fxdialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2858, 0X290) << 16);
    // 0x80800008: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2858, 0X290));
    // 0x8080000C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800010: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80800014: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800018: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080001C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80800020: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80800024: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80800028: jr          $ra
    // 0x8080002C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8080002C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_808000AC_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000C4: jal         0x80100094
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808000D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808000D4: addiu       $t7, $t6, -0x3
    ctx->r15 = ADD32(ctx->r14, -0X3);
    // 0x808000D8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x808000DC: beq         $at, $zero, L_80800240
    if (ctx->r1 == 0) {
        // 0x808000E0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800240;
    }
    // 0x808000E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0XDF0) << 16);
    // 0x808000E8: addu        $at, $at, $t7
    gpr jr_addend_808000F0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000EC: lw          $t7, 0xDF0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2168, 0XDF0));
    // 0x808000F0: jr          $t7
    // 0x808000F4: nop

    switch (jr_addend_808000F0 >> 2) {
        case 0: goto L_808000F8; break;
        case 1: goto L_8080013C; break;
        case 2: goto L_80800154; break;
        case 3: goto L_8080016C; break;
        case 4: goto L_80800184; break;
        case 5: goto L_80800184; break;
        default: switch_error(__func__, 0x808000F0, 0x80800DF0);
    }
    // 0x808000F4: nop

L_808000F8:
    // 0x808000F8: jal         0x8080000C
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080000C_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800100: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: addiu       $a1, $zero, 0x83B
    ctx->r5 = ADD32(0, 0X83B);
    // 0x8080010C: jal         0x801032B0
    // 0x80800110: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    func_801032B0(rdram, ctx);
        goto after_2;
    // 0x80800110: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    after_2:
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80102424
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080011C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800120: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XF80) << 16);
    // 0x80800124: addiu       $a2, $a2, 0xF80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XF80));
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80089D18
    // 0x80800130: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800130: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800134: b           L_80800244
    // 0x80800138: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800244;
    // 0x80800138: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_8080013C:
    // 0x8080013C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800144: jal         0x80800068
    // 0x80800148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800068_chfactoryworkerdirty(rdram, ctx);
        goto after_5;
    // 0x80800148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8080014C: b           L_80800244
    // 0x80800150: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800244;
    // 0x80800150: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800154:
    // 0x80800154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080015C: jal         0x80800068
    // 0x80800160: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800068_chfactoryworkerdirty(rdram, ctx);
        goto after_6;
    // 0x80800160: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x80800164: b           L_80800244
    // 0x80800168: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800244;
    // 0x80800168: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_8080016C:
    // 0x8080016C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800174: jal         0x80800068
    // 0x80800178: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800068_chfactoryworkerdirty(rdram, ctx);
        goto after_7;
    // 0x80800178: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x8080017C: b           L_80800244
    // 0x80800180: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800244;
    // 0x80800180: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800184:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80102424
    // 0x8080018C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x8080018C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800190: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: addiu       $a1, $zero, 0x803
    ctx->r5 = ADD32(0, 0X803);
    // 0x8080019C: jal         0x801032B0
    // 0x808001A0: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_801032B0(rdram, ctx);
        goto after_9;
    // 0x808001A0: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_9:
    // 0x808001A4: lbu         $v1, 0x10($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X10);
    // 0x808001A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001AC: beq         $v1, $at, L_808001F0
    if (ctx->r3 == ctx->r1) {
        // 0x808001B0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808001F0;
    }
    // 0x808001B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808001B4: bnel        $v1, $at, L_80800244
    if (ctx->r3 != ctx->r1) {
        // 0x808001B8: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80800244;
    }
    goto skip_0;
    // 0x808001B8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001BC: jal         0x8080002C
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080002C_chfactoryworkerdirty(rdram, ctx);
        goto after_10;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808001C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x808001D8: jal         0x80800AF8
    // 0x808001DC: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    func_80800AF8_chfactoryworkerdirty(rdram, ctx);
        goto after_11;
    // 0x808001DC: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    after_11:
    // 0x808001E0: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x808001E4: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x808001E8: b           L_80800240
    // 0x808001EC: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
        goto L_80800240;
    // 0x808001EC: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
L_808001F0:
    // 0x808001F0: jal         0x80088848
    // 0x808001F4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_12;
    // 0x808001F4: nop

    after_12:
    // 0x808001F8: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800204: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800208: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080020C: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x80800210: b           L_80800224
    // 0x80800214: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
        goto L_80800224;
    // 0x80800214: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
L_80800218:
    // 0x80800218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080021C: nop

    // 0x80800220: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
L_80800224:
    // 0x80800224: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800228: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8080022C: addiu       $a1, $zero, 0x803
    ctx->r5 = ADD32(0, 0X803);
    // 0x80800230: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80800234: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    // 0x80800238: jal         0x801032B0
    // 0x8080023C: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    func_801032B0(rdram, ctx);
        goto after_13;
    // 0x8080023C: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    after_13:
L_80800240:
    // 0x80800240: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800244:
    // 0x80800244: sb          $t6, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r14;
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080024C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800254: jr          $ra
    // 0x80800258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800034_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800040: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800044: lh          $a1, 0x10($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X10);
    // 0x80800048: beq         $a1, $zero, L_8080006C
    if (ctx->r5 == 0) {
        // 0x8080004C: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_8080006C;
    }
    // 0x8080004C: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80800050: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800054: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80800058: jal         0x800ADFE0
    // 0x8080005C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800ADFE0(rdram, ctx);
        goto after_0;
    // 0x8080005C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800060: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80800068: sh          $zero, 0x10($t8)
    MEM_H(0X10, ctx->r24) = 0;
L_8080006C:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_8010F9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F9C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010F9C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010F9C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010F9CC: lh          $v1, 0x16($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X16);
    // 0x8010F9D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010F9D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010F9D8: beq         $a1, $v1, L_8010FAD0
    if (ctx->r5 == ctx->r3) {
        // 0x8010F9DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8010FAD0;
    }
    // 0x8010F9DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010F9E0: beq         $v1, $at, L_8010FA54
    if (ctx->r3 == ctx->r1) {
        // 0x8010F9E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8010FA54;
    }
    // 0x8010F9E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010F9E8: beq         $v1, $at, L_8010FA38
    if (ctx->r3 == ctx->r1) {
        // 0x8010F9EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8010FA38;
    }
    // 0x8010F9EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010F9F0: beq         $v1, $at, L_8010FA08
    if (ctx->r3 == ctx->r1) {
        // 0x8010F9F4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8010FA08;
    }
    // 0x8010F9F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8010F9F8: beql        $v1, $at, L_8010FA24
    if (ctx->r3 == ctx->r1) {
        // 0x8010F9FC: lh          $a0, 0x14($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X14);
            goto L_8010FA24;
    }
    goto skip_0;
    // 0x8010F9FC: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
    skip_0:
    // 0x8010FA00: b           L_8010FA58
    // 0x8010FA04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8010FA58;
    // 0x8010FA04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8010FA08:
    // 0x8010FA08: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8010FA0C: jal         0x800891E0
    // 0x8010FA10: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    _ncfixposrot_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8010FA10: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010FA14: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8010FA18: b           L_8010FA54
    // 0x8010FA1C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
        goto L_8010FA54;
    // 0x8010FA1C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8010FA20: lh          $a0, 0x14($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X14);
L_8010FA24:
    // 0x8010FA24: jal         0x800894C8
    // 0x8010FA28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    _ncpod_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8010FA28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8010FA2C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8010FA30: b           L_8010FA54
    // 0x8010FA34: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
        goto L_8010FA54;
    // 0x8010FA34: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
L_8010FA38:
    // 0x8010FA38: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8010FA3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010FA40: beql        $a0, $zero, L_8010FA58
    if (ctx->r4 == 0) {
        // 0x8010FA44: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8010FA58;
    }
    goto skip_1;
    // 0x8010FA44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x8010FA48: jal         0x80110B68
    // 0x8010FA4C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80110B68(rdram, ctx);
        goto after_2;
    // 0x8010FA4C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8010FA50: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8010FA54:
    // 0x8010FA54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8010FA58:
    // 0x8010FA58: beq         $a2, $at, L_8010FAD0
    if (ctx->r6 == ctx->r1) {
        // 0x8010FA5C: sh          $a2, 0x16($s0)
        MEM_H(0X16, ctx->r16) = ctx->r6;
            goto L_8010FAD0;
    }
    // 0x8010FA5C: sh          $a2, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r6;
    // 0x8010FA60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010FA64: beq         $a2, $at, L_8010FA94
    if (ctx->r6 == ctx->r1) {
        // 0x8010FA68: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8010FA94;
    }
    // 0x8010FA68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010FA6C: beq         $a2, $at, L_8010FA84
    if (ctx->r6 == ctx->r1) {
        // 0x8010FA70: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8010FA84;
    }
    // 0x8010FA70: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8010FA74: beq         $a2, $at, L_8010FAC4
    if (ctx->r6 == ctx->r1) {
        // 0x8010FA78: nop
    
            goto L_8010FAC4;
    }
    // 0x8010FA78: nop

    // 0x8010FA7C: b           L_8010FAD4
    // 0x8010FA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8010FAD4;
    // 0x8010FA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010FA84:
    // 0x8010FA84: jal         0x800891D8
    // 0x8010FA88: nop

    _ncfixposrot_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8010FA88: nop

    after_3:
    // 0x8010FA8C: b           L_8010FAD0
    // 0x8010FA90: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_8010FAD0;
    // 0x8010FA90: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8010FA94:
    // 0x8010FA94: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8010FA98: beql        $a0, $zero, L_8010FAB4
    if (ctx->r4 == 0) {
        // 0x8010FA9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010FAB4;
    }
    goto skip_2;
    // 0x8010FA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8010FAA0: jal         0x80110B68
    // 0x8010FAA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80110B68(rdram, ctx);
        goto after_4;
    // 0x8010FAA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8010FAA8: b           L_8010FAD4
    // 0x8010FAAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8010FAD4;
    // 0x8010FAAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010FAB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8010FAB4:
    // 0x8010FAB4: jal         0x80110424
    // 0x8010FAB8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    func_80110424(rdram, ctx);
        goto after_5;
    // 0x8010FAB8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_5:
    // 0x8010FABC: b           L_8010FAD0
    // 0x8010FAC0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_8010FAD0;
    // 0x8010FAC0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_8010FAC4:
    // 0x8010FAC4: jal         0x800894C0
    // 0x8010FAC8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    _ncpod_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x8010FAC8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_6:
    // 0x8010FACC: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
L_8010FAD0:
    // 0x8010FAD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010FAD4:
    // 0x8010FAD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010FAD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010FADC: jr          $ra
    // 0x8010FAE0: nop

    return;
    // 0x8010FAE0: nop

;}
RECOMP_FUNC void chdinofamilysick_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D58: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2408, 0XF78) << 16);
    // 0x80800D5C: jr          $ra
    // 0x80800D60: addiu       $v0, $v0, 0xF78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2408, 0XF78));
    return;
    // 0x80800D60: addiu       $v0, $v0, 0xF78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2408, 0XF78));
    // 0x80800D64: nop

    // 0x80800D68: nop

    // 0x80800D6C: nop

;}
RECOMP_FUNC void func_808006FC_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800704: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x80800708: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080070C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800710: beq         $a1, $at, L_80800738
    if (ctx->r5 == ctx->r1) {
        // 0x80800714: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800738;
    }
    // 0x80800714: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800718: addiu       $at, $zero, 0x353
    ctx->r1 = ADD32(0, 0X353);
    // 0x8080071C: beq         $a1, $at, L_80800758
    if (ctx->r5 == ctx->r1) {
        // 0x80800720: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800758;
    }
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: addiu       $at, $zero, 0x354
    ctx->r1 = ADD32(0, 0X354);
    // 0x80800728: beq         $a1, $at, L_80800774
    if (ctx->r5 == ctx->r1) {
        // 0x8080072C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800774;
    }
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: b           L_808007AC
    // 0x80800734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007AC;
    // 0x80800734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800738:
    // 0x80800738: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800744: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800748: jal         0x80108528
    // 0x8080074C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x8080074C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_0:
    // 0x80800750: b           L_808007AC
    // 0x80800754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007AC;
    // 0x80800754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800758:
    // 0x80800758: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080075C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800760: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800764: jal         0x80108528
    // 0x80800768: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80800768: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_1:
    // 0x8080076C: b           L_808007AC
    // 0x80800770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007AC;
    // 0x80800770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800774:
    // 0x80800774: jal         0x801084B0
    // 0x80800778: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_2;
    // 0x80800778: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8080077C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800780: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800788: jal         0x80102FDC
    // 0x8080078C: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x8080078C: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_3:
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: jal         0x80108944
    // 0x80800798: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80108944(rdram, ctx);
        goto after_4;
    // 0x80800798: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080079C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x808007A0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808007A4: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x808007A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007AC:
    // 0x808007AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007B4: jr          $ra
    // 0x808007B8: nop

    return;
    // 0x808007B8: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800224: jal         0x80800450
    // 0x80800228: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80800450_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x80800228: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080022C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80800230: beq         $at, $zero, L_808002CC
    if (ctx->r1 == 0) {
        // 0x80800234: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808002CC;
    }
    // 0x80800234: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800238: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8080023C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800240: jal         0x800D3CF8
    // 0x80800244: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800D3CF8(rdram, ctx);
        goto after_1;
    // 0x80800244: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800248: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8080024C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x80800250: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x80800254: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80800258: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8080025C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800260: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80800264: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800268: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8080026C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800270: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800274: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80800278: beq         $v1, $at, L_80800290
    if (ctx->r3 == ctx->r1) {
        // 0x8080027C: subu        $a0, $a0, $t8
        ctx->r4 = SUB32(ctx->r4, ctx->r24);
            goto L_80800290;
    }
    // 0x8080027C: subu        $a0, $a0, $t8
    ctx->r4 = SUB32(ctx->r4, ctx->r24);
    // 0x80800280: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x80800284: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x80800288: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8080028C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80800290:
    // 0x80800290: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x80800294: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2650, 0XDA4) << 16);
    // 0x80800298: addiu       $t4, $t4, 0xDA4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2650, 0XDA4));
    // 0x8080029C: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x808002A0: bne         $v0, $t4, L_808002AC
    if (ctx->r2 != ctx->r12) {
        // 0x808002A4: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_808002AC;
    }
    // 0x808002A4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x808002A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_808002AC:
    // 0x808002AC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808002B0: jal         0x800D3D10
    // 0x808002B4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800D3D10(rdram, ctx);
        goto after_2;
    // 0x808002B4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x808002B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808002BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808002C4: jal         0x80800738
    // 0x808002C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800738_gcfrontend(rdram, ctx);
        goto after_3;
    // 0x808002C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_80800C00_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C00: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800C04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C0C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C14: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C1C: jal         0x800DC178
    // 0x80800C20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800C20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800C24: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800C28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C2C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800C30: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C38: jal         0x800DC178
    // 0x80800C3C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800C3C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    after_1:
    // 0x80800C40: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800C44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800C48: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800C4C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C54: jal         0x800DC178
    // 0x80800C58: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800C58: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    after_2:
    // 0x80800C5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C60: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80800C64: jal         0x800EF368
    // 0x80800C68: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EF368(rdram, ctx);
        goto after_3;
    // 0x80800C68: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C74: jr          $ra
    // 0x80800C78: nop

    return;
    // 0x80800C78: nop

;}
RECOMP_FUNC void bssub_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808012E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X18C0) << 16);
    // 0x808012E4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808012E8: jr          $ra
    // 0x808012EC: lw          $v0, 0x18C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18C0));
    return;
    // 0x808012EC: lw          $v0, 0x18C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18C0));
;}
RECOMP_FUNC void bsstatue_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801468: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080146C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X1610) << 16);
    // 0x80801470: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801474: jr          $ra
    // 0x80801478: lw          $v0, 0x1610($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X1610));
    return;
    // 0x80801478: lw          $v0, 0x1610($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X1610));
;}
RECOMP_FUNC void bskazeggass_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B4: jal         0x8008CABC
    // 0x808000B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808000BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000C0: jal         0x80094BC0
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094BC0(rdram, ctx);
        goto after_1;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000CC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808000D0: jal         0x80097BFC
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_poop_egg(rdram, ctx);
        goto after_2;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D8: beql        $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000DC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800110;
    }
    goto skip_0;
    // 0x808000DC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000E0: jal         0x80094B14
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_3;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000E8: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080010C;
    }
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x800944E0
    // 0x808000F4: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    func_800944E0(rdram, ctx);
        goto after_4;
    // 0x808000F4: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_4:
    // 0x808000F8: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    // 0x808000FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800100: jal         0x800F1418
    // 0x80800104: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800F1418(rdram, ctx);
        goto after_5;
    // 0x80800104: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_5:
    // 0x80800108: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
L_8080010C:
    // 0x8080010C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800110:
    // 0x80800110: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800114: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x80800118: beq         $t7, $zero, L_808001B4
    if (ctx->r15 == 0) {
        // 0x8080011C: nop
    
            goto L_808001B4;
    }
    // 0x8080011C: nop

    // 0x80800120: jal         0x8008B348
    // 0x80800124: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80800124: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_6:
    // 0x80800128: beql        $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x8080012C: lui         $a1, 0x3F19
        ctx->r5 = S32(0X3F19 << 16);
            goto L_80800158;
    }
    goto skip_1;
    // 0x8080012C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    skip_1:
    // 0x80800130: jal         0x80084A80
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    // 0x80800140: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x80800144: jal         0x80084A48
    // 0x80800148: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    _baeggsetup_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800148: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    after_8:
    // 0x8080014C: jal         0x800C6DA0
    // 0x80800150: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800C6DA0(rdram, ctx);
        goto after_9;
    // 0x80800150: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_9:
    // 0x80800154: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
L_80800158:
    // 0x80800158: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080015C: jal         0x8008B348
    // 0x80800160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80800164: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x80800168: nop
    
            goto L_808001B4;
    }
    // 0x80800168: nop

    // 0x8080016C: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x80800170: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x80800174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800178: lui         $a1, 0x3EFF
    ctx->r5 = S32(0X3EFF << 16);
    // 0x8080017C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800180: beq         $at, $zero, L_808001B4
    if (ctx->r1 == 0) {
        // 0x80800184: nop
    
            goto L_808001B4;
    }
    // 0x80800184: nop

    // 0x80800188: jal         0x8008B1BC
    // 0x8080018C: ori         $a1, $a1, 0x15EF
    ctx->r5 = ctx->r5 | 0X15EF;
    anctrl_setDuration(rdram, ctx);
        goto after_11;
    // 0x8080018C: ori         $a1, $a1, 0x15EF
    ctx->r5 = ctx->r5 | 0X15EF;
    after_11:
    // 0x80800190: lui         $a1, 0x3EA3
    ctx->r5 = S32(0X3EA3 << 16);
    // 0x80800194: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800198: jal         0x8008B24C
    // 0x8080019C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_setStart(rdram, ctx);
        goto after_12;
    // 0x8080019C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x808001A0: jal         0x8008B064
    // 0x808001A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x808001A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x808001A8: lw          $t0, 0x160($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X160);
    // 0x808001AC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x808001B0: sw          $t1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r9;
L_808001B4:
    // 0x808001B4: jal         0x8008DD04
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_14;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001BC: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: addiu       $t2, $zero, 0xDF
    ctx->r10 = ADD32(0, 0XDF);
    // 0x808001C8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_808001CC:
    // 0x808001CC: jal         0x800919F4
    // 0x808001D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_15;
    // 0x808001D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808001D4: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808001D8: nop
    
            goto L_80800224;
    }
    // 0x808001D8: nop

    // 0x808001DC: jal         0x8008B324
    // 0x808001E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_16;
    // 0x808001E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x808001E4: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001E8: addiu       $t3, $zero, 0xDD
        ctx->r11 = ADD32(0, 0XDD);
            goto L_808001F0;
    }
    // 0x808001E8: addiu       $t3, $zero, 0xDD
    ctx->r11 = ADD32(0, 0XDD);
    // 0x808001EC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_808001F0:
    // 0x808001F0: jal         0x8008B2B4
    // 0x808001F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_17;
    // 0x808001F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x808001F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(228, 0X2B0) << 16);
    // 0x808001FC: lwc1        $f4, 0x2B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X2B0));
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800208: nop

    // 0x8080020C: bc1fl       L_8080023C
    if (!c1cs) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_2;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800214: jal         0x80083300
    // 0x80800218: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _bskazcrouch_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80800218: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x8080021C: b           L_80800238
    // 0x80800220: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80800238;
    // 0x80800220: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800224:
    // 0x80800224: jal         0x8008B324
    // 0x80800228: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_19;
    // 0x80800228: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_19:
    // 0x8080022C: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x80800230: addiu       $t4, $zero, 0xBB
        ctx->r12 = ADD32(0, 0XBB);
            goto L_80800238;
    }
    // 0x80800230: addiu       $t4, $zero, 0xBB
    ctx->r12 = ADD32(0, 0XBB);
    // 0x80800234: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80800238:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080023C:
    // 0x8080023C: jal         0x8009E5C8
    // 0x80800240: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x80800240: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void func_8080029C_chkingjinjobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808002A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A8: beq         $a1, $at, L_80800314
    if (ctx->r5 == ctx->r1) {
        // 0x808002AC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800314;
    }
    // 0x808002AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808002B4: beq         $a1, $at, L_808002E0
    if (ctx->r5 == ctx->r1) {
        // 0x808002B8: lh          $a2, 0x22($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X22);
            goto L_808002E0;
    }
    // 0x808002B8: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x808002BC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808002C0: beq         $a1, $at, L_808002F0
    if (ctx->r5 == ctx->r1) {
        // 0x808002C4: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808002F0;
    }
    // 0x808002C4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002C8: bne         $a1, $at, L_80800338
    if (ctx->r5 != ctx->r1) {
        // 0x808002CC: nop
    
            goto L_80800338;
    }
    // 0x808002CC: nop

    // 0x808002D0: jal         0x80800354
    // 0x808002D4: nop

    func_80800354_chkingjinjobits(rdram, ctx);
        goto after_0;
    // 0x808002D4: nop

    after_0:
    // 0x808002D8: b           L_80800344
    // 0x808002DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800344;
    // 0x808002DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002E0:
    // 0x808002E0: jal         0x80800744
    // 0x808002E4: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    func_80800744_chkingjinjobits(rdram, ctx);
        goto after_1;
    // 0x808002E4: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    after_1:
    // 0x808002E8: b           L_80800344
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800344;
    // 0x808002EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002F0:
    // 0x808002F0: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x808002F4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808002F8: jal         0x800F54E4
    // 0x808002FC: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808002FC: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_2:
    // 0x80800300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800304: jal         0x800F82D4
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F82D4(rdram, ctx);
        goto after_3;
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080030C: b           L_80800344
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800344;
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800314:
    // 0x80800314: jal         0x800EA05C
    // 0x80800318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x80800318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x8080031C: addiu       $at, $zero, 0x14F
    ctx->r1 = ADD32(0, 0X14F);
    // 0x80800320: bne         $v0, $at, L_80800330
    if (ctx->r2 != ctx->r1) {
        // 0x80800324: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800330;
    }
    // 0x80800324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: jal         0x800FFAB0
    // 0x8080032C: nop

    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x8080032C: nop

    after_5:
L_80800330:
    // 0x80800330: b           L_80800344
    // 0x80800334: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800344;
    // 0x80800334: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800338:
    // 0x80800338: b           L_80800344
    // 0x8080033C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800344;
    // 0x8080033C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800344:
    // 0x80800344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080034C: jr          $ra
    // 0x80800350: nop

    return;
    // 0x80800350: nop

;}
RECOMP_FUNC void func_80802288_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802288: lhu         $v0, 0x64($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X64);
    // 0x8080228C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80802290: jr          $ra
    // 0x80802294: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80802294: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80800804_chswampplatform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800804: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80800808: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080080C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80800810: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800814: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80800818: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8080081C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80800820: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800824: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80800828: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080082C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800830: jal         0x80103EAC
    // 0x80800834: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    func_80103EAC(rdram, ctx);
        goto after_0;
    // 0x80800834: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    after_0:
    // 0x80800838: lwc1        $f2, 0x2C($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X2C);
    // 0x8080083C: lwc1        $f12, 0x28($s7)
    ctx->f12.u32l = MEM_W(ctx->r23, 0X28);
    // 0x80800840: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80800844: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800848: nop

    // 0x8080084C: bc1fl       L_80800860
    if (!c1cs) {
        // 0x80800850: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80800860;
    }
    goto skip_0;
    // 0x80800850: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x80800854: b           L_80800860
    // 0x80800858: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80800860;
    // 0x80800858: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8080085C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800860:
    // 0x80800860: lwc1        $f14, 0x30($s7)
    ctx->f14.u32l = MEM_W(ctx->r23, 0X30);
    // 0x80800864: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80800868: nop

    // 0x8080086C: bc1fl       L_8080089C
    if (!c1cs) {
        // 0x80800870: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8080089C;
    }
    goto skip_1;
    // 0x80800870: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_1:
    // 0x80800874: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800878: nop

    // 0x8080087C: bc1fl       L_80800890
    if (!c1cs) {
        // 0x80800880: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80800890;
    }
    goto skip_2;
    // 0x80800880: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x80800884: b           L_8080089C
    // 0x80800888: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8080089C;
    // 0x80800888: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8080088C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800890:
    // 0x80800890: b           L_8080089C
    // 0x80800894: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8080089C;
    // 0x80800894: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800898: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8080089C:
    // 0x8080089C: mul.s       $f20, $f2, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808008A0: addiu       $a0, $zero, 0x28E
    ctx->r4 = ADD32(0, 0X28E);
    // 0x808008A4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x808008A8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808008AC: jal         0x80089C40
    // 0x808008B0: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808008B0: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x808008B4: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x808008B8: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x808008BC: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808008C0: lwc1        $f2, 0x34($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X34);
    // 0x808008C4: mflo        $s5
    ctx->r21 = lo;
    // 0x808008C8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808008CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808008D0: bne         $v0, $zero, L_808008DC
    if (ctx->r2 != 0) {
        // 0x808008D4: nop
    
            goto L_808008DC;
    }
    // 0x808008D4: nop

    // 0x808008D8: break       7
    do_break(2155874520);
L_808008DC:
    // 0x808008DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808008E0: bne         $v0, $at, L_808008F4
    if (ctx->r2 != ctx->r1) {
        // 0x808008E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808008F4;
    }
    // 0x808008E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808008E8: bne         $t6, $at, L_808008F4
    if (ctx->r14 != ctx->r1) {
        // 0x808008EC: nop
    
            goto L_808008F4;
    }
    // 0x808008EC: nop

    // 0x808008F0: break       6
    do_break(2155874544);
L_808008F4:
    // 0x808008F4: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
    // 0x808008F8: bc1f        L_80800908
    if (!c1cs) {
        // 0x808008FC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800908;
    }
    // 0x808008FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800900: b           L_8080090C
    // 0x80800904: swc1        $f0, 0x34($s7)
    MEM_W(0X34, ctx->r23) = ctx->f0.u32l;
        goto L_8080090C;
    // 0x80800904: swc1        $f0, 0x34($s7)
    MEM_W(0X34, ctx->r23) = ctx->f0.u32l;
L_80800908:
    // 0x80800908: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_8080090C:
    // 0x8080090C: blez        $v0, L_8080096C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800910: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_8080096C;
    }
    // 0x80800910: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80800914: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80800918: addiu       $s4, $sp, 0x78
    ctx->r20 = ADD32(ctx->r29, 0X78);
L_8080091C:
    // 0x8080091C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800920: jal         0x80103DFC
    // 0x80800924: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x80800924: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80800928: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080092C: jal         0x80100094
    // 0x80800930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800934: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800938: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080093C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800940: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800944: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800948: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080094C: jal         0x80089878
    // 0x80800950: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800950: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_4:
    // 0x80800954: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x80800958: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080095C: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
    // 0x80800960: addu        $s3, $s3, $s5
    ctx->r19 = ADD32(ctx->r19, ctx->r21);
    // 0x80800964: bne         $s2, $s6, L_8080091C
    if (ctx->r18 != ctx->r22) {
        // 0x80800968: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8080091C;
    }
    // 0x80800968: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080096C:
    // 0x8080096C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800970: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800974: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800978: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8080097C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800980: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80800984: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80800988: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8080098C: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80800990: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80800994: jr          $ra
    // 0x80800998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80800194_chcheatopage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800198: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001A0: lhu         $a1, 0x1A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X1A);
    // 0x808001A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A8: srl         $t6, $a1, 5
    ctx->r14 = S32(U32(ctx->r5) >> 5);
    // 0x808001AC: jal         0x8010A6B0
    // 0x808001B0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8010A6B0(rdram, ctx);
        goto after_0;
    // 0x808001B0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x808001B4: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x808001B8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080028C;
    }
    // 0x808001B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001BC: jal         0x800888C8
    // 0x808001C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808001C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x808001C4: jal         0x800D1844
    // 0x808001C8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800D1844(rdram, ctx);
        goto after_2;
    // 0x808001C8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_2:
    // 0x808001CC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x808001D0: jal         0x800D0BD4
    // 0x808001D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0BD4(rdram, ctx);
        goto after_3;
    // 0x808001D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808001D8: jal         0x800FC660
    // 0x808001DC: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808001DC: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_4:
    // 0x808001E0: jal         0x800D035C
    // 0x808001E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800D035C(rdram, ctx);
        goto after_5;
    // 0x808001E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x808001E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808001EC: bne         $v0, $at, L_80800208
    if (ctx->r2 != ctx->r1) {
        // 0x808001F0: addiu       $a1, $zero, 0x114A
        ctx->r5 = ADD32(0, 0X114A);
            goto L_80800208;
    }
    // 0x808001F0: addiu       $a1, $zero, 0x114A
    ctx->r5 = ADD32(0, 0X114A);
    // 0x808001F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808001FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800200: jal         0x8008A208
    // 0x80800204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800204: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
L_80800208:
    // 0x80800208: jal         0x808002F0
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002F0_chcheatopage(rdram, ctx);
        goto after_7;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800210: bne         $v0, $zero, L_80800284
    if (ctx->r2 != 0) {
        // 0x80800214: addiu       $a0, $zero, 0x67
        ctx->r4 = ADD32(0, 0X67);
            goto L_80800284;
    }
    // 0x80800214: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x80800218: jal         0x800DA9E4
    // 0x8080021C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_8;
    // 0x8080021C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800220: bne         $v0, $zero, L_80800284
    if (ctx->r2 != 0) {
        // 0x80800224: nop
    
            goto L_80800284;
    }
    // 0x80800224: nop

    // 0x80800228: jal         0x800F54E4
    // 0x8080022C: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x8080022C: nop

    after_9:
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800234: jal         0x800F82D4
    // 0x80800238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x80800238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x8080023C: jal         0x8010A570
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_11;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80101FDC
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800250: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800260: jal         0x80103110
    // 0x80800264: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80103110(rdram, ctx);
        goto after_13;
    // 0x80800264: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_13:
    // 0x80800268: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x8080026C: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x80800270: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800274: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800278: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x8080027C: b           L_8080028C
    // 0x80800280: sb          $t0, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r8;
        goto L_8080028C;
    // 0x80800280: sb          $t0, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r8;
L_80800284:
    // 0x80800284: jal         0x800FFAB0
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_8080028C:
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800290: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C70: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C70);
    return;
    // 0x80083C74: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_8001A0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A0C0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8001A0C4: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8001A0C8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001A0CC: lw          $t6, -0x433C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X433C);
    // 0x8001A0D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001A0D4: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8001A0D8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8001A0DC: sll         $t0, $a0, 1
    ctx->r8 = S32(ctx->r4 << 1);
    // 0x8001A0E0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001A0E4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001A0E8: jr          $ra
    // 0x8001A0EC: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
    return;
    // 0x8001A0EC: lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X0);
;}
RECOMP_FUNC void func_808005D4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005E4: jal         0x8080000C
    // 0x808005E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8080000C_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x808005E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808005EC: jal         0x8080081C
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808005F4: jal         0x8008CAEC
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_2;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808005FC: beq         $v0, $zero, L_8080060C
    if (ctx->r2 == 0) {
        // 0x80800600: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080060C;
    }
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: addiu       $t6, $zero, 0x151
    ctx->r14 = ADD32(0, 0X151);
    // 0x80800608: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080060C:
    // 0x8080060C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800610: jal         0x808003C4
    // 0x80800614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808003C4_bstrexlarge(rdram, ctx);
        goto after_3;
    // 0x80800614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: jal         0x8009E5C8
    // 0x80800620: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800620: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800628: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080062C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800630: jr          $ra
    // 0x80800634: nop

    return;
    // 0x80800634: nop

;}
RECOMP_FUNC void func_800EDCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDCB8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EDCBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDCC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EDCC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800EDCC8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800EDCCC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800EDCD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800EDCD4: jal         0x800EDC10
    // 0x800EDCD8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EDC10(rdram, ctx);
        goto after_0;
    // 0x800EDCD8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x800EDCDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDCE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDCE4: jr          $ra
    // 0x800EDCE8: nop

    return;
    // 0x800EDCE8: nop

;}
RECOMP_FUNC void func_80090494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009049C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800904A0: jal         0x800F54E4
    // 0x800904A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800904A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800904A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800904AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800904B0: jal         0x800F7A2C
    // 0x800904B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7A2C(rdram, ctx);
        goto after_1;
    // 0x800904B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800904B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800904BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800904C0: jr          $ra
    // 0x800904C4: nop

    return;
    // 0x800904C4: nop

;}
RECOMP_FUNC void func_80800224_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800230: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800234: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800238: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080023C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800240: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800244: bnel        $t7, $at, L_80800258
    if (ctx->r15 != ctx->r1) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    goto skip_0;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080024C: jal         0x8008A4B0
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800258:
    // 0x80800258: jal         0x80102424
    // 0x8080025C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080025C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800260: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800264: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800268: addiu       $t0, $t9, -0x3
    ctx->r8 = ADD32(ctx->r25, -0X3);
    // 0x8080026C: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x80800270: beq         $at, $zero, L_80800350
    if (ctx->r1 == 0) {
        // 0x80800274: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800350;
    }
    // 0x80800274: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800278: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDB4) << 16);
    // 0x8080027C: addu        $at, $at, $t0
    gpr jr_addend_80800284 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800280: lw          $t0, 0xDB4($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDB4));
    // 0x80800284: jr          $t0
    // 0x80800288: nop

    switch (jr_addend_80800284 >> 2) {
        case 0: goto L_808002B4; break;
        case 1: goto L_8080028C; break;
        case 2: goto L_8080029C; break;
        case 3: goto L_808002CC; break;
        case 4: goto L_80800350; break;
        case 5: goto L_80800340; break;
        default: switch_error(__func__, 0x80800284, 0x80800DB4);
    }
    // 0x80800288: nop

L_8080028C:
    // 0x8080028C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800290: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800294: b           L_80800350
    // 0x80800298: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800350;
    // 0x80800298: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080029C:
    // 0x8080029C: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x808002A0: ori         $a1, $a1, 0x22D1
    ctx->r5 = ctx->r5 | 0X22D1;
    // 0x808002A4: jal         0x80101EE4
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_2;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002AC: b           L_80800354
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B4:
    // 0x808002B4: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x808002B8: ori         $a1, $a1, 0x22D1
    ctx->r5 = ctx->r5 | 0X22D1;
    // 0x808002BC: jal         0x80101EE4
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_3;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002C4: b           L_80800354
    // 0x808002C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x808002C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002CC:
    // 0x808002CC: jal         0x800E3AA4
    // 0x808002D0: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800E3AA4(rdram, ctx);
        goto after_4;
    // 0x808002D0: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_4:
    // 0x808002D4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808002D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808002DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002E8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808002EC: nop

    // 0x808002F0: bc1fl       L_8080030C
    if (!c1cs) {
        // 0x808002F4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8080030C;
    }
    goto skip_1;
    // 0x808002F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x808002F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808002FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800300: b           L_80800314
    // 0x80800304: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
        goto L_80800314;
    // 0x80800304: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80800308: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8080030C:
    // 0x8080030C: nop

    // 0x80800310: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_80800314:
    // 0x80800314: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800318: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080031C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XDCC) << 16);
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80800328: lwc1        $f6, 0xDCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XDCC));
    // 0x8080032C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800330: jal         0x8008A4B0
    // 0x80800334: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800334: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x80800338: b           L_80800354
    // 0x8080033C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x8080033C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800340:
    // 0x80800340: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800348: nop

    // 0x8080034C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800350:
    // 0x80800350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800354:
    // 0x80800354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void func_80800000_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80091A58
    // 0x8080000C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800010: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800014: beq         $t6, $zero, L_8080002C
    if (ctx->r14 == 0) {
        // 0x80800018: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8080002C;
    }
    // 0x80800018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8080001C: jal         0x800C6E38
    // 0x80800020: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x80800024: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800028: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080002C:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083838: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083838);
    return;
    // 0x8008383C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void gccubesearch_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808004E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808004E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808004EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808004F0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808004F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808004F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808004FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800500: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80800504: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800508: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080050C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800510: jal         0x800BE52C
    // 0x80800514: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800BE52C(rdram, ctx);
        goto after_0;
    // 0x80800514: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80800518: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080051C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800520: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80800524: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x80800528: beql        $at, $zero, L_80800570
    if (ctx->r1 == 0) {
        // 0x8080052C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800570;
    }
    goto skip_0;
    // 0x8080052C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80800530:
    // 0x80800530: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800534: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800538: subu        $a3, $s3, $s0
    ctx->r7 = SUB32(ctx->r19, ctx->r16);
    // 0x8080053C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800540: mflo        $t7
    ctx->r15 = lo;
    // 0x80800544: addu        $a2, $t7, $s2
    ctx->r6 = ADD32(ctx->r15, ctx->r18);
    // 0x80800548: jal         0x80088C48
    // 0x8080054C: nop

    _gspropmarker_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080054C: nop

    after_1:
    // 0x80800550: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800554: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800558: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8080055C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80800560: sltu        $at, $a0, $t8
    ctx->r1 = ctx->r4 < ctx->r24 ? 1 : 0;
    // 0x80800564: bne         $at, $zero, L_80800530
    if (ctx->r1 != 0) {
        // 0x80800568: nop
    
            goto L_80800530;
    }
    // 0x80800568: nop

    // 0x8080056C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800570:
    // 0x80800570: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800574: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800578: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080057C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800580: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800584: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800588: jr          $ra
    // 0x8080058C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080058C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chlakemonster_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808019D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808019DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808019E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808019E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808019E8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808019EC: jal         0x800B53A4
    // 0x808019F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808019F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808019F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808019F8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808019FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801A00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801A04: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80801A08: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80801A0C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1748, 0X229C) << 16);
    // 0x80801A10: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801A14: addiu       $t6, $t6, 0x229C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1748, 0X229C));
    // 0x80801A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801A20: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80801A24: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80801A28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801A2C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80801A30: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80801A34: jal         0x800BABB8
    // 0x80801A38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80801A38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80801A3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801A40: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801A44: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A48: jal         0x800BA1D0
    // 0x80801A4C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BA1D0(rdram, ctx);
        goto after_2;
    // 0x80801A4C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80801A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A58: jr          $ra
    // 0x80801A5C: nop

    return;
    // 0x80801A5C: nop

;}
RECOMP_FUNC void _bstrexsmall_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840C8: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840C8);
    return;
    // 0x800840CC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800740_chmumbohealspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800740: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800744: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2424, 0X8DC) << 16);
    // 0x80800748: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080074C: addiu       $t7, $t7, 0x8DC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2424, 0X8DC));
    // 0x80800750: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800754: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x80800758: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080075C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800760: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800764: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2424, 0X8E8) << 16);
    // 0x80800768: addiu       $t2, $t2, 0x8E8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2424, 0X8E8));
    // 0x8080076C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800770: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800774: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80800778: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x8080077C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800780: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80800784: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80800788: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2424, 0X8F4) << 16);
    // 0x8080078C: addiu       $t8, $t8, 0x8F4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2424, 0X8F4));
    // 0x80800790: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80800794: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80800798: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x8080079C: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x808007A0: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x808007A4: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x808007A8: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007B0: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x808007B4: jal         0x80100094
    // 0x808007B8: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007B8: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    after_0:
    // 0x808007BC: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x808007C0: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x808007C4: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x808007C8: addiu       $t2, $sp, 0x44
    ctx->r10 = ADD32(ctx->r29, 0X44);
    // 0x808007CC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x808007D0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x808007D4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808007D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808007DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007E0: lui         $a1, 0x44AF
    ctx->r5 = S32(0X44AF << 16);
    // 0x808007E4: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808007E8: jal         0x80089870
    // 0x808007EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808007EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808007F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808007F8: jr          $ra
    // 0x808007FC: nop

    return;
    // 0x808007FC: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D08: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084D08);
    return;
    // 0x80084D0C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80801860_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801868: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080186C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A2C) << 16);
    // 0x80801870: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801874: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801878: addiu       $a2, $a2, 0x2A2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A2C));
    // 0x8080187C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801880: jal         0x80089D20
    // 0x80801884: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801884: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801888: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2C68) << 16);
    // 0x8080188C: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80801890: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801894: addiu       $a2, $a2, 0x2C68
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2C68));
    // 0x80801898: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080189C: jal         0x80089D20
    // 0x808018A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808018A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808018A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2C78) << 16);
    // 0x808018A8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1060, 0X2C88) << 16);
    // 0x808018AC: addiu       $a3, $a3, 0x2C88
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1060, 0X2C88));
    // 0x808018B0: addiu       $a2, $a2, 0x2C78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2C78));
    // 0x808018B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808018B8: jal         0x80089D28
    // 0x808018BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808018BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018C8: jr          $ra
    // 0x808018CC: nop

    return;
    // 0x808018CC: nop

;}
RECOMP_FUNC void func_8009BF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BF34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BF38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BF3C: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BF40: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x8009BF44: jal         0x8009BE28
    // 0x8009BF48: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    func_8009BE28(rdram, ctx);
        goto after_0;
    // 0x8009BF48: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_0:
    // 0x8009BF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BF50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BF54: jr          $ra
    // 0x8009BF58: nop

    return;
    // 0x8009BF58: nop

;}
RECOMP_FUNC void _bskazwingwhack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837A0: syscall     73
    recomp_syscall_handler(rdram, ctx, 0x800837A0);
    return;
    // 0x800837A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void glhittableDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080036C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80800370: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800374: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800378: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x8080037C: addiu       $t9, $t9, 0x530
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x80800380: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800384: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x80800388: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8080038C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80800390: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80800394: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x80800398: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x8080039C: sll         $t4, $t3, 25
    ctx->r12 = S32(ctx->r11 << 25);
    // 0x808003A0: sll         $t7, $t6, 25
    ctx->r15 = S32(ctx->r14 << 25);
    // 0x808003A4: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x808003A8: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x808003AC: jr          $ra
    // 0x808003B0: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
    return;
    // 0x808003B0: or          $v0, $t5, $t8
    ctx->r2 = ctx->r13 | ctx->r24;
;}
RECOMP_FUNC void func_808004D4_chbilldrillboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D4: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808004D8: addiu       $at, $zero, 0x3CF
    ctx->r1 = ADD32(0, 0X3CF);
    // 0x808004DC: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808004E0: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808004E4: bnel        $t8, $at, L_808004F8
    if (ctx->r24 != ctx->r1) {
        // 0x808004E8: lhu         $v1, 0x76($a0)
        ctx->r3 = MEM_HU(ctx->r4, 0X76);
            goto L_808004F8;
    }
    goto skip_0;
    // 0x808004E8: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    skip_0:
    // 0x808004EC: jr          $ra
    // 0x808004F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808004F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004F4: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
L_808004F8:
    // 0x808004F8: srl         $t9, $v1, 7
    ctx->r25 = S32(U32(ctx->r3) >> 7);
    // 0x808004FC: addiu       $v1, $t9, -0x33
    ctx->r3 = ADD32(ctx->r25, -0X33);
    // 0x80800500: bltz        $v1, L_80800510
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800504: slti        $at, $v1, 0x1E
        ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
            goto L_80800510;
    }
    // 0x80800504: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x80800508: bne         $at, $zero, L_80800518
    if (ctx->r1 != 0) {
        // 0x8080050C: addiu       $v0, $v1, 0x514
        ctx->r2 = ADD32(ctx->r3, 0X514);
            goto L_80800518;
    }
    // 0x8080050C: addiu       $v0, $v1, 0x514
    ctx->r2 = ADD32(ctx->r3, 0X514);
L_80800510:
    // 0x80800510: jr          $ra
    // 0x80800514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800518:
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void func_80801BB4_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801BBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801BC0: jal         0x8009E6EC
    // 0x80801BC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801BC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801BC8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801BCC: beq         $v0, $at, L_80801BE8
    if (ctx->r2 == ctx->r1) {
        // 0x80801BD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801BE8;
    }
    // 0x80801BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BD4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80801BD8: beq         $v0, $at, L_80801C0C
    if (ctx->r2 == ctx->r1) {
        // 0x80801BDC: nop
    
            goto L_80801C0C;
    }
    // 0x80801BDC: nop

    // 0x80801BE0: b           L_80801C3C
    // 0x80801BE4: nop

        goto L_80801C3C;
    // 0x80801BE4: nop

L_80801BE8:
    // 0x80801BE8: jal         0x8009E830
    // 0x80801BEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80801BEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BF4: jal         0x80095760
    // 0x80801BF8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80801BF8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x80801BFC: jal         0x800A046C
    // 0x80801C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_3;
    // 0x80801C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801C04: b           L_80801C48
    // 0x80801C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801C48;
    // 0x80801C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801C0C:
    // 0x80801C0C: jal         0x8009E6F8
    // 0x80801C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_4;
    // 0x80801C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801C14: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80801C18: bne         $v0, $at, L_80801C44
    if (ctx->r2 != ctx->r1) {
        // 0x80801C1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C44;
    }
    // 0x80801C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C20: jal         0x80084598
    // 0x80801C24: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80801C24: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_5:
    // 0x80801C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C2C: jal         0x8009E830
    // 0x80801C30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_6;
    // 0x80801C30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801C34: b           L_80801C48
    // 0x80801C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801C48;
    // 0x80801C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801C3C:
    // 0x80801C3C: jal         0x80099B94
    // 0x80801C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_7;
    // 0x80801C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80801C44:
    // 0x80801C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801C48:
    // 0x80801C48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C50: jr          $ra
    // 0x80801C54: nop

    return;
    // 0x80801C54: nop

;}
RECOMP_FUNC void func_80014258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014258: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001425C: lw          $t6, -0x7B74($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B74);
    // 0x80014260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014264: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80014268: bne         $t6, $at, L_800142CC
    if (ctx->r14 != ctx->r1) {
        // 0x8001426C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800142CC;
    }
    // 0x8001426C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014270: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80014274: lw          $t7, -0x7B7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B7C);
    // 0x80014278: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001427C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80014280: bne         $t7, $at, L_800142CC
    if (ctx->r15 != ctx->r1) {
        // 0x80014284: addiu       $t8, $t8, -0x7158
        ctx->r24 = ADD32(ctx->r24, -0X7158);
            goto L_800142CC;
    }
    // 0x80014284: addiu       $t8, $t8, -0x7158
    ctx->r24 = ADD32(ctx->r24, -0X7158);
    // 0x80014288: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001428C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80014290: addiu       $t0, $t0, -0x7154
    ctx->r8 = ADD32(ctx->r8, -0X7154);
    // 0x80014294: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80014298: bne         $t9, $t1, L_800142CC
    if (ctx->r25 != ctx->r9) {
        // 0x8001429C: nop
    
            goto L_800142CC;
    }
    // 0x8001429C: nop

    // 0x800142A0: jal         0x8002F240
    // 0x800142A4: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_0;
    // 0x800142A4: nop

    after_0:
    // 0x800142A8: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x800142AC: bne         $t2, $zero, L_800142CC
    if (ctx->r10 != 0) {
        // 0x800142B0: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_800142CC;
    }
    // 0x800142B0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800142B4: addiu       $a0, $a0, -0x7BC8
    ctx->r4 = ADD32(ctx->r4, -0X7BC8);
    // 0x800142B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800142BC: jal         0x8002EAD0
    // 0x800142C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800142C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800142C4: b           L_800142E4
    // 0x800142C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800142E4;
    // 0x800142C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800142CC:
    // 0x800142CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800142D0: addiu       $v0, $v0, -0x7B84
    ctx->r2 = ADD32(ctx->r2, -0X7B84);
    // 0x800142D4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800142D8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800142DC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800142E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800142E4:
    // 0x800142E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800142E8: jr          $ra
    // 0x800142EC: nop

    return;
    // 0x800142EC: nop

;}
RECOMP_FUNC void _bafly_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C08: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C08);
    return;
    // 0x80084C0C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bskazmove_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(260, 0XC70) << 16);
    // 0x808005B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005B4: jr          $ra
    // 0x808005B8: lw          $v0, 0xC70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(260, 0XC70));
    return;
    // 0x808005B8: lw          $v0, 0xC70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(260, 0XC70));
;}
RECOMP_FUNC void func_808000BC_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: lbu         $v1, 0x95($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X95);
    // 0x808000D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: beql        $v1, $zero, L_80800118
    if (ctx->r3 == 0) {
        // 0x808000E0: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80800118;
    }
    goto skip_0;
    // 0x808000E0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    skip_0:
    // 0x808000E4: beq         $v1, $at, L_80800108
    if (ctx->r3 == ctx->r1) {
        // 0x808000E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800108;
    }
    // 0x808000E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000F0: beq         $v1, $at, L_80800108
    if (ctx->r3 == ctx->r1) {
        // 0x808000F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800108;
    }
    // 0x808000F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000F8: beql        $v1, $at, L_80800118
    if (ctx->r3 == ctx->r1) {
        // 0x808000FC: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80800118;
    }
    goto skip_1;
    // 0x808000FC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    skip_1:
    // 0x80800100: b           L_8080012C
    // 0x80800104: nop

        goto L_8080012C;
    // 0x80800104: nop

L_80800108:
    // 0x80800108: jal         0x80800098
    // 0x8080010C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800098_chevilmumbo(rdram, ctx);
        goto after_1;
    // 0x8080010C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800110: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800114: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
L_80800118:
    // 0x80800118: jal         0x800F54E4
    // 0x8080011C: sb          $t6, 0x95($a1)
    MEM_B(0X95, ctx->r5) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080011C: sb          $t6, 0x95($a1)
    MEM_B(0X95, ctx->r5) = ctx->r14;
    after_2:
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800124: jal         0x800F4AF4
    // 0x80800128: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800F4AF4(rdram, ctx);
        goto after_3;
    // 0x80800128: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
L_8080012C:
    // 0x8080012C: jal         0x80800000
    // 0x80800130: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_chevilmumbo(rdram, ctx);
        goto after_4;
    // 0x80800130: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void chseaweedbaddy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1024, 0XEFC) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xEFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1024, 0XEFC));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xEFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1024, 0XEFC));
;}
RECOMP_FUNC void _bsstonehead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BE0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083BE0);
    return;
    // 0x80083BE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BA4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA4B0: jr          $ra
    // 0x800BA4B4: sb          $a1, 0x83($a0)
    MEM_B(0X83, ctx->r4) = ctx->r5;
    return;
    // 0x800BA4B4: sb          $a1, 0x83($a0)
    MEM_B(0X83, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void scinfobar_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800568: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x8080056C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80800570: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800574: nop

    // 0x80800578: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080057C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800580: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800584: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void func_801106A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801106A0: jr          $ra
    // 0x801106A4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    return;
    // 0x801106A4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
;}
