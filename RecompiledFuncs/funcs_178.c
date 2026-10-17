#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800124_chbubbleelevator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800128: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800130: jal         0x808008A8
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808008A8_chbubbleelevator(rdram, ctx);
        goto after_0;
    // 0x80800134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800138: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080013C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800140: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800144: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800148: beq         $at, $zero, L_808004C8
    if (ctx->r1 == 0) {
        // 0x8080014C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004C8;
    }
    // 0x8080014C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800150: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2368, 0XBD0) << 16);
    // 0x80800154: addu        $at, $at, $t8
    gpr jr_addend_8080015C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800158: lw          $t8, 0xBD0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2368, 0XBD0));
    // 0x8080015C: jr          $t8
    // 0x80800160: nop

    switch (jr_addend_8080015C >> 2) {
        case 0: goto L_80800164; break;
        case 1: goto L_808001FC; break;
        case 2: goto L_80800218; break;
        case 3: goto L_80800264; break;
        case 4: goto L_8080030C; break;
        case 5: goto L_80800348; break;
        case 6: goto L_808003E4; break;
        case 7: goto L_808004C8; break;
        case 8: goto L_8080047C; break;
        default: switch_error(__func__, 0x8080015C, 0x80800BD0);
    }
    // 0x80800160: nop

L_80800164:
    // 0x80800164: jal         0x800D90A4
    // 0x80800168: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80800168: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x8080016C: beq         $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x80800170: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080017C;
    }
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x808004DC
    // 0x80800178: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_2;
    // 0x80800178: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_8080017C:
    // 0x8080017C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800180: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2368, 0XC50) << 16);
    // 0x80800184: addiu       $a3, $a3, 0xC50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2368, 0XC50));
    // 0x80800188: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x80089D50
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800198: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x8080019C: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x808001A0: addiu       $t2, $t2, 0xC20
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x808001A4: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x808001A8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808001AC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x808001B0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x808001B4: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x808001B8: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x808001BC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001C4: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x808001C8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808001CC: jal         0x800F12D4
    // 0x808001D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_4;
    // 0x808001D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808001D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001D8: jal         0x80089D30
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001E0: jal         0x800F54E4
    // 0x808001E4: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808001E4: nop

    after_6:
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001EC: jal         0x800F8294
    // 0x808001F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F8294(rdram, ctx);
        goto after_7;
    // 0x808001F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808001F4: b           L_808004CC
    // 0x808001F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x808001F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001FC:
    // 0x808001FC: jal         0x800F54E4
    // 0x80800200: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800200: nop

    after_8:
    // 0x80800204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800208: jal         0x800F8294
    // 0x8080020C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800F8294(rdram, ctx);
        goto after_9;
    // 0x8080020C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800210: b           L_808004CC
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800218:
    // 0x80800218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080021C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800220: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800224: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800228: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    // 0x8080022C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800230: lui         $a2, 0x430C
    ctx->r6 = S32(0X430C << 16);
    // 0x80800234: bc1f        L_80800244
    if (!c1cs) {
        // 0x80800238: nop
    
            goto L_80800244;
    }
    // 0x80800238: nop

    // 0x8080023C: jal         0x80089F18
    // 0x80800240: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800240: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_10:
L_80800244:
    // 0x80800244: jal         0x800D90A4
    // 0x80800248: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_11;
    // 0x80800248: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_11:
    // 0x8080024C: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C8;
    }
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x808004DC
    // 0x80800258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_12;
    // 0x80800258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x8080025C: b           L_808004CC
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800264:
    // 0x80800264: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80800268: jal         0x8010C500
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_13;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800270: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x80800274: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_808002E4;
    }
    // 0x80800274: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800278: jal         0x800F54E4
    // 0x8080027C: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x8080027C: nop

    after_14:
    // 0x80800280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800284: jal         0x800F64A4
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_15;
    // 0x80800288: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x8080028C: beq         $v0, $zero, L_808002A4
    if (ctx->r2 == 0) {
        // 0x80800290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A4;
    }
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x808004DC
    // 0x80800298: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_16;
    // 0x80800298: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x8080029C: b           L_808002EC
    // 0x808002A0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
        goto L_808002EC;
    // 0x808002A0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_808002A4:
    // 0x808002A4: jal         0x800DA298
    // 0x808002A8: addiu       $a0, $zero, 0x6EA
    ctx->r4 = ADD32(0, 0X6EA);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x808002A8: addiu       $a0, $zero, 0x6EA
    ctx->r4 = ADD32(0, 0X6EA);
    after_17:
    // 0x808002AC: bnel        $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x808002B0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_808002DC;
    }
    goto skip_0;
    // 0x808002B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_0:
    // 0x808002B4: jal         0x800DA544
    // 0x808002B8: addiu       $a0, $zero, 0x6EA
    ctx->r4 = ADD32(0, 0X6EA);
    func_800DA544(rdram, ctx);
        goto after_18;
    // 0x808002B8: addiu       $a0, $zero, 0x6EA
    ctx->r4 = ADD32(0, 0X6EA);
    after_18:
    // 0x808002BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002C0: addiu       $t3, $zero, 0x6F
    ctx->r11 = ADD32(0, 0X6F);
    // 0x808002C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808002C8: addiu       $a1, $zero, 0x1229
    ctx->r5 = ADD32(0, 0X1229);
    // 0x808002CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808002D0: jal         0x8008A208
    // 0x808002D4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x808002D4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_19:
    // 0x808002D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_808002DC:
    // 0x808002DC: b           L_808002E8
    // 0x808002E0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_808002E8;
    // 0x808002E0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_808002E4:
    // 0x808002E4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_808002E8:
    // 0x808002E8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_808002EC:
    // 0x808002EC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002F0: lui         $a1, 0x4296
    ctx->r5 = S32(0X4296 << 16);
    // 0x808002F4: beq         $t6, $zero, L_808004C8
    if (ctx->r14 == 0) {
        // 0x808002F8: lui         $a2, 0x430C
        ctx->r6 = S32(0X430C << 16);
            goto L_808004C8;
    }
    // 0x808002F8: lui         $a2, 0x430C
    ctx->r6 = S32(0X430C << 16);
    // 0x808002FC: jal         0x80089F18
    // 0x80800300: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80800300: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_20:
    // 0x80800304: b           L_808004CC
    // 0x80800308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x80800308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080030C:
    // 0x8080030C: jal         0x800F54E4
    // 0x80800310: nop

    func_800F54E4(rdram, ctx);
        goto after_21;
    // 0x80800310: nop

    after_21:
    // 0x80800314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800318: jal         0x800F5A00
    // 0x8080031C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_22;
    // 0x8080031C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_22:
    // 0x80800320: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800324: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800328: jal         0x800EFFB4
    // 0x8080032C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800EFFB4(rdram, ctx);
        goto after_23;
    // 0x8080032C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_23:
    // 0x80800330: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x80800334: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C8;
    }
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x808004DC
    // 0x8080033C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_24;
    // 0x8080033C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_24:
    // 0x80800340: b           L_808004CC
    // 0x80800344: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x80800344: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800348:
    // 0x80800348: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8080034C: jal         0x800D91EC
    // 0x80800350: lui         $a1, 0x4098
    ctx->r5 = S32(0X4098 << 16);
    func_800D91EC(rdram, ctx);
        goto after_25;
    // 0x80800350: lui         $a1, 0x4098
    ctx->r5 = S32(0X4098 << 16);
    after_25:
    // 0x80800354: beq         $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800358: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800364;
    }
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x808004DC
    // 0x80800360: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_26;
    // 0x80800360: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_26:
L_80800364:
    // 0x80800364: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800368: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2368, 0XC50) << 16);
    // 0x8080036C: addiu       $a3, $a3, 0xC50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2368, 0XC50));
    // 0x80800370: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x80089D50
    // 0x8080037C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x8080037C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80800380: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x80800384: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x80800388: addiu       $t0, $t0, 0xC20
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x8080038C: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x80800390: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800394: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800398: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8080039C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x808003A0: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x808003A4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003A8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003AC: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x808003B0: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808003B4: jal         0x800F12D4
    // 0x808003B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_28;
    // 0x808003B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_28:
    // 0x808003BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003C0: jal         0x80089D30
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_29;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808003C8: jal         0x800F54E4
    // 0x808003CC: nop

    func_800F54E4(rdram, ctx);
        goto after_30;
    // 0x808003CC: nop

    after_30:
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003D4: jal         0x800F8294
    // 0x808003D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F8294(rdram, ctx);
        goto after_31;
    // 0x808003D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_31:
    // 0x808003DC: b           L_808004CC
    // 0x808003E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x808003E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003E4:
    // 0x808003E4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808003E8: jal         0x800D91EC
    // 0x808003EC: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_800D91EC(rdram, ctx);
        goto after_32;
    // 0x808003EC: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_32:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x808004DC
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_33;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x808003FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800400: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2368, 0XC50) << 16);
    // 0x80800404: addiu       $a3, $a3, 0xC50
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2368, 0XC50));
    // 0x80800408: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: jal         0x80089D50
    // 0x80800414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_34;
    // 0x80800414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
    // 0x80800418: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x8080041C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x80800420: addiu       $t4, $t4, 0xC20
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x80800424: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x80800428: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8080042C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80800430: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80800434: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80800438: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8080043C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800440: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800444: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x80800448: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x8080044C: jal         0x800F12D4
    // 0x80800450: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_35;
    // 0x80800450: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_35:
    // 0x80800454: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800458: jal         0x80089D30
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_36;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800460: jal         0x800F54E4
    // 0x80800464: nop

    func_800F54E4(rdram, ctx);
        goto after_37;
    // 0x80800464: nop

    after_37:
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080046C: jal         0x800F8294
    // 0x80800470: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F8294(rdram, ctx);
        goto after_38;
    // 0x80800470: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_38:
    // 0x80800474: b           L_808004CC
    // 0x80800478: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004CC;
    // 0x80800478: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080047C:
    // 0x8080047C: jal         0x800D90A4
    // 0x80800480: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D90A4(rdram, ctx);
        goto after_39;
    // 0x80800480: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_39:
    // 0x80800484: beql        $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800488: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808004A4;
    }
    goto skip_1;
    // 0x80800488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x8080048C: jal         0x800DA544
    // 0x80800490: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    func_800DA544(rdram, ctx);
        goto after_40;
    // 0x80800490: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    after_40:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x808004DC
    // 0x8080049C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_41;
    // 0x8080049C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_41:
    // 0x808004A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_808004A4:
    // 0x808004A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004A8: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808004AC: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808004B0: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x808004B4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808004B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004BC: jal         0x800F12D4
    // 0x808004C0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_42;
    // 0x808004C0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_42:
    // 0x808004C4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_808004C8:
    // 0x808004C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004CC:
    // 0x808004CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void _chclockworkmouse_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086948: syscall     398
    recomp_syscall_handler(rdram, ctx, 0x80086948);
    return;
    // 0x8008694C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chlavaentrancebridgeswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1984, 0XA0) << 16);
    // 0x8080008C: jr          $ra
    // 0x80800090: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1984, 0XA0));
    return;
    // 0x80800090: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1984, 0XA0));
    // 0x80800094: nop

    // 0x80800098: nop

    // 0x8080009C: nop

;}
RECOMP_FUNC void func_800016DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016DC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800016E0: addiu       $v0, $v0, 0x4244
    ctx->r2 = ADD32(ctx->r2, 0X4244);
    // 0x800016E4: jr          $ra
    // 0x800016E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    return;
    // 0x800016E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
;}
RECOMP_FUNC void func_80802F20_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802F28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802F2C: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    // 0x80802F30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802F34: jal         0x8009E674
    // 0x80802F38: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x80802F38: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x80802F3C: bnel        $v0, $zero, L_80802F6C
    if (ctx->r2 != 0) {
        // 0x80802F40: lh          $t7, 0xE0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XE0);
            goto L_80802F6C;
    }
    goto skip_0;
    // 0x80802F40: lh          $t7, 0xE0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE0);
    skip_0:
    // 0x80802F44: lh          $t6, 0xE0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE0);
    // 0x80802F48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802F4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802F50: beql        $t6, $at, L_808030D0
    if (ctx->r14 == ctx->r1) {
        // 0x80802F54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808030D0;
    }
    goto skip_1;
    // 0x80802F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80802F58: jal         0x80803124
    // 0x80802F5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80803124_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80802F5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80802F60: b           L_808030D0
    // 0x80802F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808030D0;
    // 0x80802F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802F68: lh          $t7, 0xE0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE0);
L_80802F6C:
    // 0x80802F6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802F70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802F74: bnel        $t7, $at, L_80802F88
    if (ctx->r15 != ctx->r1) {
        // 0x80802F78: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80802F88;
    }
    goto skip_2;
    // 0x80802F78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80802F7C: jal         0x80803124
    // 0x80802F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80803124_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80802F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802F84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80802F88:
    // 0x80802F88: jal         0x80091A58
    // 0x80802F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_3;
    // 0x80802F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80802F90: beq         $v0, $zero, L_80802FA0
    if (ctx->r2 == 0) {
        // 0x80802F94: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80802FA0;
    }
    // 0x80802F94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802F98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802F9C: sh          $t8, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r24;
L_80802FA0:
    // 0x80802FA0: jal         0x800919F4
    // 0x80802FA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    bakey_held(rdram, ctx);
        goto after_4;
    // 0x80802FA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80802FA8: beq         $v0, $zero, L_80802FB8
    if (ctx->r2 == 0) {
        // 0x80802FAC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80802FB8;
    }
    // 0x80802FAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802FB0: b           L_80802FBC
    // 0x80802FB4: sh          $t9, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r25;
        goto L_80802FBC;
    // 0x80802FB4: sh          $t9, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r25;
L_80802FB8:
    // 0x80802FB8: sh          $zero, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = 0;
L_80802FBC:
    // 0x80802FBC: jal         0x800D9004
    // 0x80802FC0: nop

    func_800D9004(rdram, ctx);
        goto after_5;
    // 0x80802FC0: nop

    after_5:
    // 0x80802FC4: lh          $v0, 0xE0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE0);
    // 0x80802FC8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80802FCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802FD0: beql        $v0, $zero, L_80803000
    if (ctx->r2 == 0) {
        // 0x80802FD4: lh          $t0, 0xD4($s0)
        ctx->r8 = MEM_H(ctx->r16, 0XD4);
            goto L_80803000;
    }
    goto skip_3;
    // 0x80802FD4: lh          $t0, 0xD4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XD4);
    skip_3:
    // 0x80802FD8: beq         $v0, $at, L_8080303C
    if (ctx->r2 == ctx->r1) {
        // 0x80802FDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080303C;
    }
    // 0x80802FDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802FE0: beq         $v0, $at, L_80803070
    if (ctx->r2 == ctx->r1) {
        // 0x80802FE4: addiu       $a0, $s0, 0xD8
        ctx->r4 = ADD32(ctx->r16, 0XD8);
            goto L_80803070;
    }
    // 0x80802FE4: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x80802FE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802FEC: beq         $v0, $at, L_808030A8
    if (ctx->r2 == ctx->r1) {
        // 0x80802FF0: addiu       $a0, $s0, 0xD8
        ctx->r4 = ADD32(ctx->r16, 0XD8);
            goto L_808030A8;
    }
    // 0x80802FF0: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x80802FF4: b           L_808030D0
    // 0x80802FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808030D0;
    // 0x80802FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802FFC: lh          $t0, 0xD4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XD4);
L_80803000:
    // 0x80803000: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80803004: beql        $t0, $zero, L_80803020
    if (ctx->r8 == 0) {
        // 0x80803008: lh          $t1, 0xD6($s0)
        ctx->r9 = MEM_H(ctx->r16, 0XD6);
            goto L_80803020;
    }
    goto skip_4;
    // 0x80803008: lh          $t1, 0xD6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XD6);
    skip_4:
    // 0x8080300C: jal         0x808030E0
    // 0x80803010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808030E0_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80803010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80803014: b           L_808030D0
    // 0x80803018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808030D0;
    // 0x80803018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080301C: lh          $t1, 0xD6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XD6);
L_80803020:
    // 0x80803020: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80803024: beql        $t1, $zero, L_808030D0
    if (ctx->r9 == 0) {
        // 0x80803028: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808030D0;
    }
    goto skip_5;
    // 0x80803028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8080302C: jal         0x808030E0
    // 0x80803030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808030E0_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80803030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80803034: b           L_808030D0
    // 0x80803038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808030D0;
    // 0x80803038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080303C:
    // 0x8080303C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80803040: jal         0x800F1574
    // 0x80803044: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    func_800F1574(rdram, ctx);
        goto after_8;
    // 0x80803044: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    after_8:
    // 0x80803048: beq         $v0, $zero, L_80803054
    if (ctx->r2 == 0) {
        // 0x8080304C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80803054;
    }
    // 0x8080304C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803050: sh          $zero, 0xE0($s0)
    MEM_H(0XE0, ctx->r16) = 0;
L_80803054:
    // 0x80803054: lh          $t2, 0xD4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XD4);
    // 0x80803058: beql        $t2, $zero, L_808030D0
    if (ctx->r10 == 0) {
        // 0x8080305C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808030D0;
    }
    goto skip_6;
    // 0x8080305C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80803060: jal         0x808030E0
    // 0x80803064: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808030E0_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80803064: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x80803068: b           L_808030D0
    // 0x8080306C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808030D0;
    // 0x8080306C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803070:
    // 0x80803070: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80803074: jal         0x800F1574
    // 0x80803078: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_800F1574(rdram, ctx);
        goto after_10;
    // 0x80803078: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_10:
    // 0x8080307C: beq         $v0, $zero, L_8080308C
    if (ctx->r2 == 0) {
        // 0x80803080: lwc1        $f2, 0x20($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
            goto L_8080308C;
    }
    // 0x80803080: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80803084: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80803088: sh          $t3, 0xE0($s0)
    MEM_H(0XE0, ctx->r16) = ctx->r11;
L_8080308C:
    // 0x8080308C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80803090: jal         0x800F1574
    // 0x80803094: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    func_800F1574(rdram, ctx);
        goto after_11;
    // 0x80803094: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    after_11:
    // 0x80803098: beql        $v0, $zero, L_808030D0
    if (ctx->r2 == 0) {
        // 0x8080309C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808030D0;
    }
    goto skip_7;
    // 0x8080309C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x808030A0: b           L_808030CC
    // 0x808030A4: sh          $zero, 0xE0($s0)
    MEM_H(0XE0, ctx->r16) = 0;
        goto L_808030CC;
    // 0x808030A4: sh          $zero, 0xE0($s0)
    MEM_H(0XE0, ctx->r16) = 0;
L_808030A8:
    // 0x808030A8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808030AC: jal         0x800F1574
    // 0x808030B0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_800F1574(rdram, ctx);
        goto after_12;
    // 0x808030B0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x808030B4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808030B8: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    // 0x808030BC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808030C0: jal         0x800F1574
    // 0x808030C4: nop

    func_800F1574(rdram, ctx);
        goto after_13;
    // 0x808030C4: nop

    after_13:
    // 0x808030C8: sh          $zero, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = 0;
L_808030CC:
    // 0x808030CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808030D0:
    // 0x808030D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808030D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808030D8: jr          $ra
    // 0x808030DC: nop

    return;
    // 0x808030DC: nop

;}
RECOMP_FUNC void susplinet_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808010F4: sb          $t6, 0x58($a0)
    MEM_B(0X58, ctx->r4) = ctx->r14;
    // 0x808010F8: lw          $a1, 0x44($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X44);
    // 0x808010FC: jal         0x80800D3C
    // 0x80801100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800D3C_susplinet(rdram, ctx);
        goto after_0;
    // 0x80801100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801108: sb          $zero, 0x58($a0)
    MEM_B(0X58, ctx->r4) = 0;
    // 0x8080110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801114: jr          $ra
    // 0x80801118: nop

    return;
    // 0x80801118: nop

;}
RECOMP_FUNC void func_80027200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027200: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80027204: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x80027208: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8002720C: jr          $ra
    // 0x80027210: nop

    return;
    // 0x80027210: nop

;}
RECOMP_FUNC void _fxleaves_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088930: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088930);
    return;
    // 0x80088934: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080088C_chmoley(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080088C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800894: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800898: jal         0x80100094
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808008A0: beq         $v0, $zero, L_808008B0
    if (ctx->r2 == 0) {
        // 0x808008A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808008B0;
    }
    // 0x808008A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008A8: jal         0x800897C8
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808008B0:
    // 0x808008B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008B8: jr          $ra
    // 0x808008BC: nop

    return;
    // 0x808008BC: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E60: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E60);
    return;
    // 0x80082E64: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_808005B8_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: jal         0x808001A8
    // 0x808005C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x808005C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005CC: lui         $a2, 0x43D2
    ctx->r6 = S32(0X43D2 << 16);
    // 0x808005D0: lui         $a3, 0xC496
    ctx->r7 = S32(0XC496 << 16);
    // 0x808005D4: jal         0x80085210
    // 0x808005D8: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    _basudie_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808005D8: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    after_1:
    // 0x808005DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808005E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005EC: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x808005F0: jal         0x8080042C
    // 0x808005F4: swc1        $f4, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f4.u32l;
    func_8080042C_bswasher(rdram, ctx);
        goto after_2;
    // 0x808005F4: swc1        $f4, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x808005F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800600: jr          $ra
    // 0x80800604: nop

    return;
    // 0x80800604: nop

;}
RECOMP_FUNC void func_80800864_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080086C: jal         0x80800114
    // 0x80800870: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800114_bsvanswim(rdram, ctx);
        goto after_0;
    // 0x80800870: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800874: jal         0x800839C8
    // 0x80800878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void func_800C301C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C301C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3024: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3028: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C302C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3030: beq         $t6, $zero, L_800C3048
    if (ctx->r14 == 0) {
        // 0x800C3034: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3048;
    }
    // 0x800C3034: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3038: jal         0x800C1414
    // 0x800C303C: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C303C: nop

    after_0:
    // 0x800C3040: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3044: sh          $t7, 0x58($v0)
    MEM_H(0X58, ctx->r2) = ctx->r15;
L_800C3048:
    // 0x800C3048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C304C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3050: jr          $ra
    // 0x800C3054: nop

    return;
    // 0x800C3054: nop

;}
RECOMP_FUNC void _chstadiumdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B48: syscall     420
    recomp_syscall_handler(rdram, ctx, 0x80086B48);
    return;
    // 0x80086B4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801EE4_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EE4: jr          $ra
    // 0x80801EE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801EE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chdrawbridgeswitches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2060, 0X258) << 16);
    // 0x80800178: jr          $ra
    // 0x8080017C: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2060, 0X258));
    return;
    // 0x8080017C: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2060, 0X258));
;}
RECOMP_FUNC void suquiz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E0: jal         0x800DA298
    // 0x808004E4: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808004E4: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x808004E8: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004EC: nop
    
            goto L_808004F8;
    }
    // 0x808004EC: nop

    // 0x808004F0: b           L_80800574
    // 0x808004F4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800574;
    // 0x808004F4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808004F8:
    // 0x808004F8: jal         0x800DA298
    // 0x808004FC: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808004FC: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    after_1:
    // 0x80800500: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x80800504: addiu       $a0, $zero, 0x442
        ctx->r4 = ADD32(0, 0X442);
            goto L_80800520;
    }
    // 0x80800504: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x80800508: jal         0x800DA524
    // 0x8080050C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x8080050C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    after_2:
    // 0x80800510: jal         0x800DA524
    // 0x80800514: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800514: addiu       $a0, $zero, 0x6EB
    ctx->r4 = ADD32(0, 0X6EB);
    after_3:
    // 0x80800518: b           L_80800574
    // 0x8080051C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800574;
    // 0x8080051C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800520:
    // 0x80800520: jal         0x800DA564
    // 0x80800524: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_4;
    // 0x80800524: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800528: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8080052C: beq         $at, $zero, L_80800570
    if (ctx->r1 == 0) {
        // 0x80800530: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80800570;
    }
    // 0x80800530: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800534: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF1C) << 16);
    // 0x80800538: addu        $at, $at, $t6
    gpr jr_addend_80800540 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080053C: lw          $t6, 0xF1C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF1C));
    // 0x80800540: jr          $t6
    // 0x80800544: nop

    switch (jr_addend_80800540 >> 2) {
        case 0: goto L_80800548; break;
        case 1: goto L_80800550; break;
        case 2: goto L_80800558; break;
        case 3: goto L_80800560; break;
        case 4: goto L_80800568; break;
        default: switch_error(__func__, 0x80800540, 0x80800F1C);
    }
    // 0x80800544: nop

L_80800548:
    // 0x80800548: b           L_80800574
    // 0x8080054C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800574;
    // 0x8080054C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800550:
    // 0x80800550: b           L_80800574
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800574;
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800558:
    // 0x80800558: b           L_80800574
    // 0x8080055C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800574;
    // 0x8080055C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800560:
    // 0x80800560: b           L_80800574
    // 0x80800564: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800574;
    // 0x80800564: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800568:
    // 0x80800568: b           L_80800574
    // 0x8080056C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80800574;
    // 0x8080056C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80800570:
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800574:
    // 0x80800574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080057C: jr          $ra
    // 0x80800580: nop

    return;
    // 0x80800580: nop

;}
RECOMP_FUNC void bakey_getStructSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800918F0: jr          $ra
    // 0x800918F4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x800918F4: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _suexpression_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089810: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089810);
    return;
    // 0x80089814: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void chkingjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1296, 0X11A8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x11A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1296, 0X11A8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x11A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1296, 0X11A8));
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A560: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A560);
    return;
    // 0x8008A564: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80012B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012B7C: jal         0x8002E3B0
    // 0x80012B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osAiGetLength_recomp(rdram, ctx);
        goto after_0;
    // 0x80012B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80012B84: srl         $t6, $v0, 2
    ctx->r14 = S32(U32(ctx->r2) >> 2);
    // 0x80012B88: bne         $t6, $zero, L_80012BA4
    if (ctx->r14 != 0) {
        // 0x80012B8C: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_80012BA4;
    }
    // 0x80012B8C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80012B90: lw          $t7, -0x339C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X339C);
    // 0x80012B94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012B98: bnel        $t7, $zero, L_80012BA8
    if (ctx->r15 != 0) {
        // 0x80012B9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012BA8;
    }
    goto skip_0;
    // 0x80012B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80012BA0: sw          $zero, -0x339C($at)
    MEM_W(-0X339C, ctx->r1) = 0;
L_80012BA4:
    // 0x80012BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80012BA8:
    // 0x80012BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012BAC: jr          $ra
    // 0x80012BB0: nop

    return;
    // 0x80012BB0: nop

;}
RECOMP_FUNC void func_800F1434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F1438: lwc1        $f4, 0x5EC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EC0);
    // 0x800F143C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F1440: lwc1        $f8, 0x5EC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5EC4);
    // 0x800F1444: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800F1448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F144C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1450: jal         0x8001395C
    // 0x800F1454: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_8001395C(rdram, ctx);
        goto after_0;
    // 0x800F1454: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x800F1458: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F145C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F1460: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F1464: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F1468: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800F146C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1474: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800F1478: jr          $ra
    // 0x800F147C: nop

    return;
    // 0x800F147C: nop

;}
RECOMP_FUNC void ncpod_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EFC: jal         0x80110024
    // 0x80800F00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800F00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    if (tooie_null_guard(rdram, ctx, "ncpod_entrypoint_29")) { ctx->r2 = 0; ctx->r29 = ADD32(ctx->r29, 0X18); return; }
    // 0x80800F04: jal         0x80089638
    // 0x80800F08: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800F08: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x80800F0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F10: jal         0x80089678
    // 0x80800F14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _ncpoducam_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800F14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F20: jr          $ra
    // 0x80800F24: nop

    return;
    // 0x80800F24: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A510: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A510);
    return;
    // 0x8008A514: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800354_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800358: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080035C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800364: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(836, 0X50C) << 16);
    // 0x80800368: addiu       $t7, $t7, 0x50C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(836, 0X50C));
    // 0x8080036C: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80800370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800374: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800378: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080037C: jal         0x800BBCB8
    // 0x80800380: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800380: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x80800384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_8080077C_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800780: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800784: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800788: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080078C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800790: jal         0x80100094
    // 0x80800794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800798: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080079C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1172, 0X11F4) << 16);
    // 0x808007A0: addiu       $t7, $t7, 0x11F4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1172, 0X11F4));
    // 0x808007A4: bne         $t6, $t7, L_808007C4
    if (ctx->r14 != ctx->r15) {
        // 0x808007A8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808007C4;
    }
    // 0x808007A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007AC: jal         0x800FC660
    // 0x808007B0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x808007B0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x808007B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808007B8: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
    // 0x808007BC: b           L_80800908
    // 0x808007C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800908;
    // 0x808007C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007C4:
    // 0x808007C4: jal         0x800FC660
    // 0x808007C8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x808007C8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x808007CC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808007D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007D4: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x808007D8: beq         $v0, $at, L_808007F8
    if (ctx->r2 == ctx->r1) {
        // 0x808007DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808007F8;
    }
    // 0x808007DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007E0: beq         $v0, $at, L_80800808
    if (ctx->r2 == ctx->r1) {
        // 0x808007E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800808;
    }
    // 0x808007E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007E8: beq         $v0, $at, L_80800818
    if (ctx->r2 == ctx->r1) {
        // 0x808007EC: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_80800818;
    }
    // 0x808007EC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x808007F0: b           L_80800890
    // 0x808007F4: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
        goto L_80800890;
    // 0x808007F4: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
L_808007F8:
    // 0x808007F8: jal         0x800D3F2C
    // 0x808007FC: lhu         $a0, 0x6($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X6);
    func_800D3F2C(rdram, ctx);
        goto after_3;
    // 0x808007FC: lhu         $a0, 0x6($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X6);
    after_3:
    // 0x80800800: b           L_8080088C
    // 0x80800804: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_8080088C;
    // 0x80800804: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80800808:
    // 0x80800808: jal         0x80088178
    // 0x8080080C: lhu         $a0, 0x6($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X6);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080080C: lhu         $a0, 0x6($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X6);
    after_4:
    // 0x80800810: b           L_8080088C
    // 0x80800814: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_8080088C;
    // 0x80800814: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80800818:
    // 0x80800818: jal         0x80088178
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800820: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800824: slti        $at, $s0, 0x2D
    ctx->r1 = SIGNED(ctx->r16) < 0X2D ? 1 : 0;
    // 0x80800828: bne         $at, $zero, L_80800818
    if (ctx->r1 != 0) {
        // 0x8080082C: nop
    
            goto L_80800818;
    }
    // 0x8080082C: nop

    // 0x80800830: addiu       $s0, $zero, 0x60
    ctx->r16 = ADD32(0, 0X60);
L_80800834:
    // 0x80800834: jal         0x80088178
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080083C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800840: slti        $at, $s0, 0x77
    ctx->r1 = SIGNED(ctx->r16) < 0X77 ? 1 : 0;
    // 0x80800844: bne         $at, $zero, L_80800834
    if (ctx->r1 != 0) {
        // 0x80800848: nop
    
            goto L_80800834;
    }
    // 0x80800848: nop

    // 0x8080084C: addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
L_80800850:
    // 0x80800850: jal         0x80088178
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800858: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080085C: addiu       $at, $zero, 0x86
    ctx->r1 = ADD32(0, 0X86);
    // 0x80800860: bne         $s0, $at, L_80800850
    if (ctx->r16 != ctx->r1) {
        // 0x80800864: nop
    
            goto L_80800850;
    }
    // 0x80800864: nop

    // 0x80800868: jal         0x800DA544
    // 0x8080086C: addiu       $a0, $zero, 0xC08
    ctx->r4 = ADD32(0, 0XC08);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x8080086C: addiu       $a0, $zero, 0xC08
    ctx->r4 = ADD32(0, 0XC08);
    after_8:
    // 0x80800870: jal         0x800DA544
    // 0x80800874: addiu       $a0, $zero, 0xC09
    ctx->r4 = ADD32(0, 0XC09);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800874: addiu       $a0, $zero, 0xC09
    ctx->r4 = ADD32(0, 0XC09);
    after_9:
    // 0x80800878: jal         0x800DA544
    // 0x8080087C: addiu       $a0, $zero, 0xC0A
    ctx->r4 = ADD32(0, 0XC0A);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x8080087C: addiu       $a0, $zero, 0xC0A
    ctx->r4 = ADD32(0, 0XC0A);
    after_10:
    // 0x80800880: jal         0x800DA544
    // 0x80800884: addiu       $a0, $zero, 0xC0C
    ctx->r4 = ADD32(0, 0XC0C);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80800884: addiu       $a0, $zero, 0xC0C
    ctx->r4 = ADD32(0, 0XC0C);
    after_11:
    // 0x80800888: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_8080088C:
    // 0x8080088C: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
L_80800890:
    // 0x80800890: beql        $t9, $zero, L_80800908
    if (ctx->r25 == 0) {
        // 0x80800894: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800908;
    }
    goto skip_0;
    // 0x80800894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800898: jal         0x80800FDC
    // 0x8080089C: nop

    func_80800FDC_chcoderoombits(rdram, ctx);
        goto after_12;
    // 0x8080089C: nop

    after_12:
    // 0x808008A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008A4: bne         $v0, $at, L_808008D0
    if (ctx->r2 != ctx->r1) {
        // 0x808008A8: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_808008D0;
    }
    // 0x808008A8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808008AC: lbu         $t1, 0xA($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XA);
    // 0x808008B0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808008B4: addiu       $a1, $zero, 0x115B
    ctx->r5 = ADD32(0, 0X115B);
    // 0x808008B8: bne         $t1, $zero, L_808008D0
    if (ctx->r9 != 0) {
        // 0x808008BC: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_808008D0;
    }
    // 0x808008BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808008C0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x808008C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808008C8: jal         0x8008A208
    // 0x808008CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x808008CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
L_808008D0:
    // 0x808008D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808008D4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x808008D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808008DC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808008E0: lhu         $a1, 0x8($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X8);
    // 0x808008E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808008E8: jal         0x8008A208
    // 0x808008EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x808008EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x808008F0: jal         0x800F54E4
    // 0x808008F4: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x808008F4: nop

    after_15:
    // 0x808008F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008FC: jal         0x800F7F98
    // 0x80800900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_16;
    // 0x80800900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800908:
    // 0x80800908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080090C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800910: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800914: jr          $ra
    // 0x80800918: nop

    return;
    // 0x80800918: nop

;}
RECOMP_FUNC void func_80800824_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800828: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8080082C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800830: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800834: addiu       $s5, $sp, 0x74
    ctx->r21 = ADD32(ctx->r29, 0X74);
    // 0x80800838: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8080083C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800840: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80800844: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80800848: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8080084C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80800850: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80800854: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800858: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8080085C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800860: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800864: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800868: jal         0x800EE7F8
    // 0x8080086C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080086C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x80800870: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x80800874: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800878: jal         0x800EE7F8
    // 0x8080087C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080087C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80800880: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800884: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800888: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8080088C: jal         0x800B53A4
    // 0x80800890: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800890: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800894: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800898: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080089C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808008A0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808008A4: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808008A8: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(824, 0XDD8) << 16);
    // 0x808008AC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808008B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808008B4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808008B8: addiu       $s2, $s2, 0xDD8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(824, 0XDD8));
    // 0x808008BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808008C0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x808008C4: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x808008C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_808008CC:
    // 0x808008CC: jal         0x800DC178
    // 0x808008D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808008D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_3:
    // 0x808008D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008D8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808008DC: jal         0x800EEB9C
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: jal         0x800EF04C
    // 0x808008EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808008EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x808008F0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x808008F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808008F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808008FC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800900: jal         0x800BABB8
    // 0x80800904: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800904: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_6:
    // 0x80800908: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080090C: bnel        $s1, $s3, L_808008CC
    if (ctx->r17 != ctx->r19) {
        // 0x80800910: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_808008CC;
    }
    goto skip_0;
    // 0x80800910: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x80800914: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800918: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080091C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800920: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800924: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800928: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8080092C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800930: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800934: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800938: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8080093C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80800940: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80800944: jr          $ra
    // 0x80800948: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800948: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80800000_suexpressjoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3134, 0X1820) << 16);
    // 0x80800004: lh          $t6, 0x1820($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(3134, 0X1820));
    // 0x80800008: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3134, 0X1830) << 16);
    // 0x8080000C: bne         $a0, $t6, L_8080001C
    if (ctx->r4 != ctx->r14) {
        // 0x80800010: nop
    
            goto L_8080001C;
    }
    // 0x80800010: nop

    // 0x80800014: jr          $ra
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080001C:
    // 0x8080001C: lh          $t7, 0x1830($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(3134, 0X1830));
    // 0x80800020: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3134, 0X1838) << 16);
    // 0x80800024: addiu       $v0, $v0, 0x1838
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3134, 0X1838));
    // 0x80800028: bne         $a0, $t7, L_80800038
    if (ctx->r4 != ctx->r15) {
        // 0x8080002C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80800038;
    }
    // 0x8080002C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800030: jr          $ra
    // 0x80800034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800038:
    // 0x80800038: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_8080003C:
    // 0x8080003C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80800040: bnel        $a0, $t8, L_80800054
    if (ctx->r4 != ctx->r24) {
        // 0x80800044: lh          $t9, 0x18($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X18);
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800044: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    skip_0:
    // 0x80800048: jr          $ra
    // 0x8080004C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8080004C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800050: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
L_80800054:
    // 0x80800054: bnel        $a0, $t9, L_80800068
    if (ctx->r4 != ctx->r25) {
        // 0x80800058: lh          $t0, 0x28($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X28);
            goto L_80800068;
    }
    goto skip_1;
    // 0x80800058: lh          $t0, 0x28($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X28);
    skip_1:
    // 0x8080005C: jr          $ra
    // 0x80800060: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800060: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80800064: lh          $t0, 0x28($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X28);
L_80800068:
    // 0x80800068: bnel        $a0, $t0, L_8080007C
    if (ctx->r4 != ctx->r8) {
        // 0x8080006C: lh          $t1, 0x38($v0)
        ctx->r9 = MEM_H(ctx->r2, 0X38);
            goto L_8080007C;
    }
    goto skip_2;
    // 0x8080006C: lh          $t1, 0x38($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X38);
    skip_2:
    // 0x80800070: jr          $ra
    // 0x80800074: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x80800074: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80800078: lh          $t1, 0x38($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X38);
L_8080007C:
    // 0x8080007C: bnel        $a0, $t1, L_80800090
    if (ctx->r4 != ctx->r9) {
        // 0x80800080: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800090;
    }
    goto skip_3;
    // 0x80800080: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x80800084: jr          $ra
    // 0x80800088: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x80800088: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x8080008C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800090:
    // 0x80800090: bne         $v1, $a1, L_8080003C
    if (ctx->r3 != ctx->r5) {
        // 0x80800094: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_8080003C;
    }
    // 0x80800094: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80800098: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_800F2704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F2708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F270C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F2710: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F2714: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800F2718: jal         0x800F274C
    // 0x800F271C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F274C(rdram, ctx);
        goto after_0;
    // 0x800F271C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F2720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F2724: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F2728: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800F272C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2730: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800F2734: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2738: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x800F273C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F2744: jr          $ra
    // 0x800F2748: nop

    return;
    // 0x800F2748: nop

;}
RECOMP_FUNC void chburgerstand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(936, 0XC70) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xC70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XC70));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xC70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XC70));
;}
RECOMP_FUNC void func_800C427C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C427C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4284: jal         0x800C2718
    // 0x800C4288: nop

    func_800C2718(rdram, ctx);
        goto after_0;
    // 0x800C4288: nop

    after_0:
    // 0x800C428C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C4294: jr          $ra
    // 0x800C4298: nop

    return;
    // 0x800C4298: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A840: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A840);
    return;
    // 0x8008A844: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void bsbansack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801008: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080100C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E40) << 16);
    // 0x80801010: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801014: jr          $ra
    // 0x80801018: lw          $v0, 0x1E40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E40));
    return;
    // 0x80801018: lw          $v0, 0x1E40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E40));
;}
RECOMP_FUNC void func_80096694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009669C: jal         0x80096628
    // 0x800966A0: nop

    func_80096628(rdram, ctx);
        goto after_0;
    // 0x800966A0: nop

    after_0:
    // 0x800966A4: jal         0x800C84B0
    // 0x800966A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C84B0(rdram, ctx);
        goto after_1;
    // 0x800966A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800966AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800966B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800966B4: jr          $ra
    // 0x800966B8: nop

    return;
    // 0x800966B8: nop

;}
RECOMP_FUNC void func_800D0DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0DAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D0DB0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800D0DB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D0DB8: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800D0DBC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D0DC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0DC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D0DC8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800D0DCC: beq         $at, $zero, L_800D0F28
    if (ctx->r1 == 0) {
        // 0x800D0DD0: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_800D0F28;
    }
    // 0x800D0DD0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800D0DD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D0DD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D0DDC: addu        $at, $at, $t7
    gpr jr_addend_800D0DE4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D0DE0: lw          $t7, 0x5AB4($at)
    ctx->r15 = ADD32(ctx->r1, 0X5AB4);
    // 0x800D0DE4: jr          $t7
    // 0x800D0DE8: nop

    switch (jr_addend_800D0DE4 >> 2) {
        case 0: goto L_800D0E38; break;
        case 1: goto L_800D0DEC; break;
        case 2: goto L_800D0EA8; break;
        case 3: goto L_800D0EC8; break;
        case 4: goto L_800D0E70; break;
        case 5: goto L_800D0F28; break;
        case 6: goto L_800D0F28; break;
        case 7: goto L_800D0EE8; break;
        case 8: goto L_800D0F08; break;
        default: switch_error(__func__, 0x800D0DE4, 0x80125AB4);
    }
    // 0x800D0DE8: nop

L_800D0DEC:
    // 0x800D0DEC: addiu       $a0, $zero, 0x21F
    ctx->r4 = ADD32(0, 0X21F);
    // 0x800D0DF0: jal         0x800D0CE0
    // 0x800D0DF4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_0;
    // 0x800D0DF4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800D0DF8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800D0DFC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0E00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0E04: bne         $t8, $zero, L_800D0E14
    if (ctx->r24 != 0) {
        // 0x800D0E08: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_800D0E14;
    }
    // 0x800D0E08: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800D0E0C: jal         0x8010108C
    // 0x800D0E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x800D0E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800D0E14:
    // 0x800D0E14: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0E18: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0E1C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x800D0E20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D0E24: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800D0E28: jal         0x800D05E4
    // 0x800D0E2C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    func_800D05E4(rdram, ctx);
        goto after_2;
    // 0x800D0E2C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x800D0E30: b           L_800D0F38
    // 0x800D0E34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_800D0F38;
    // 0x800D0E34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_800D0E38:
    // 0x800D0E38: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    // 0x800D0E3C: jal         0x800D0CE0
    // 0x800D0E40: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_3;
    // 0x800D0E40: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x800D0E44: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800D0E48: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0E4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0E50: bne         $t1, $zero, L_800D0E60
    if (ctx->r9 != 0) {
        // 0x800D0E54: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_800D0E60;
    }
    // 0x800D0E54: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800D0E58: jal         0x8010108C
    // 0x800D0E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x800D0E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_800D0E60:
    // 0x800D0E60: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0E64: andi        $t2, $s0, 0xFFFF
    ctx->r10 = ctx->r16 & 0XFFFF;
    // 0x800D0E68: b           L_800D0F34
    // 0x800D0E6C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_800D0F34;
    // 0x800D0E6C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_800D0E70:
    // 0x800D0E70: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    // 0x800D0E74: jal         0x800D0CE0
    // 0x800D0E78: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_5;
    // 0x800D0E78: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x800D0E7C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800D0E80: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0E84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0E88: bne         $t3, $zero, L_800D0E98
    if (ctx->r11 != 0) {
        // 0x800D0E8C: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_800D0E98;
    }
    // 0x800D0E8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800D0E90: jal         0x8010108C
    // 0x800D0E94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x800D0E94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
L_800D0E98:
    // 0x800D0E98: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0E9C: andi        $t4, $s0, 0xFFFF
    ctx->r12 = ctx->r16 & 0XFFFF;
    // 0x800D0EA0: b           L_800D0F34
    // 0x800D0EA4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
        goto L_800D0F34;
    // 0x800D0EA4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_800D0EA8:
    // 0x800D0EA8: addiu       $a0, $zero, 0x220
    ctx->r4 = ADD32(0, 0X220);
    // 0x800D0EAC: jal         0x800D0CE0
    // 0x800D0EB0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_7;
    // 0x800D0EB0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x800D0EB4: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0EB8: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x800D0EBC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0EC0: b           L_800D0F34
    // 0x800D0EC4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_800D0F34;
    // 0x800D0EC4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_800D0EC8:
    // 0x800D0EC8: addiu       $a0, $zero, 0x21B
    ctx->r4 = ADD32(0, 0X21B);
    // 0x800D0ECC: jal         0x800D0CE0
    // 0x800D0ED0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_8;
    // 0x800D0ED0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x800D0ED4: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0ED8: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x800D0EDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0EE0: b           L_800D0F34
    // 0x800D0EE4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_800D0F34;
    // 0x800D0EE4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_800D0EE8:
    // 0x800D0EE8: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    // 0x800D0EEC: jal         0x800D0CE0
    // 0x800D0EF0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_9;
    // 0x800D0EF0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x800D0EF4: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0EF8: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x800D0EFC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0F00: b           L_800D0F34
    // 0x800D0F04: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_800D0F34;
    // 0x800D0F04: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_800D0F08:
    // 0x800D0F08: addiu       $a0, $zero, 0x3C6
    ctx->r4 = ADD32(0, 0X3C6);
    // 0x800D0F0C: jal         0x800D0CE0
    // 0x800D0F10: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_800D0CE0(rdram, ctx);
        goto after_10;
    // 0x800D0F10: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_10:
    // 0x800D0F14: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0F18: andi        $t8, $s0, 0xFFFF
    ctx->r24 = ctx->r16 & 0XFFFF;
    // 0x800D0F1C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D0F20: b           L_800D0F34
    // 0x800D0F24: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
        goto L_800D0F34;
    // 0x800D0F24: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_800D0F28:
    // 0x800D0F28: sra         $s0, $s1, 16
    ctx->r16 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800D0F2C: andi        $t9, $s0, 0xFFFF
    ctx->r25 = ctx->r16 & 0XFFFF;
    // 0x800D0F30: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800D0F34:
    // 0x800D0F34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_800D0F38:
    // 0x800D0F38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D0F3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D0F40: jal         0x800CFBC8
    // 0x800D0F44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800CFBC8(rdram, ctx);
        goto after_11;
    // 0x800D0F44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x800D0F48: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800D0F4C: beql        $t0, $zero, L_800D0F84
    if (ctx->r8 == 0) {
        // 0x800D0F50: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_800D0F84;
    }
    goto skip_0;
    // 0x800D0F50: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800D0F54: lhu         $t1, 0x18($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X18);
    // 0x800D0F58: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0F5C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800D0F60: beql        $t2, $zero, L_800D0F84
    if (ctx->r10 == 0) {
        // 0x800D0F64: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_800D0F84;
    }
    goto skip_1;
    // 0x800D0F64: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800D0F68: jal         0x80101074
    // 0x800D0F6C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_80101074(rdram, ctx);
        goto after_12;
    // 0x800D0F6C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_12:
    // 0x800D0F70: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800D0F74: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x800D0F78: jal         0x8010114C
    // 0x800D0F7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8010114C(rdram, ctx);
        goto after_13;
    // 0x800D0F7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_13:
    // 0x800D0F80: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
L_800D0F84:
    // 0x800D0F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0F88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D0F8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D0F90: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800D0F94: jr          $ra
    // 0x800D0F98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D0F98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chswitch_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085840: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085840);
    return;
    // 0x80085844: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800BEB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEB5C: jr          $ra
    // 0x800BEB60: sw          $a0, -0x78A0($at)
    MEM_W(-0X78A0, ctx->r1) = ctx->r4;
    return;
    // 0x800BEB60: sw          $a0, -0x78A0($at)
    MEM_W(-0X78A0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800A7380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7388: jal         0x800EA0A8
    // 0x800A738C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA0A8(rdram, ctx);
        goto after_0;
    // 0x800A738C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A7390: jal         0x800A8F68
    // 0x800A7394: nop

    func_800A8F68(rdram, ctx);
        goto after_1;
    // 0x800A7394: nop

    after_1:
    // 0x800A7398: jal         0x800C2AB8
    // 0x800A739C: nop

    func_800C2AB8(rdram, ctx);
        goto after_2;
    // 0x800A739C: nop

    after_2:
    // 0x800A73A0: jal         0x800FB968
    // 0x800A73A4: nop

    func_800FB968(rdram, ctx);
        goto after_3;
    // 0x800A73A4: nop

    after_3:
    // 0x800A73A8: jal         0x8001A2B0
    // 0x800A73AC: nop

    func_8001A2B0(rdram, ctx);
        goto after_4;
    // 0x800A73AC: nop

    after_4:
    // 0x800A73B0: jal         0x800D6C64
    // 0x800A73B4: nop

    func_800D6C64(rdram, ctx);
        goto after_5;
    // 0x800A73B4: nop

    after_5:
    // 0x800A73B8: jal         0x800D58CC
    // 0x800A73BC: nop

    func_800D58CC(rdram, ctx);
        goto after_6;
    // 0x800A73BC: nop

    after_6:
    // 0x800A73C0: jal         0x8008B768
    // 0x800A73C4: nop

    func_8008B768(rdram, ctx);
        goto after_7;
    // 0x800A73C4: nop

    after_7:
    // 0x800A73C8: jal         0x80081724
    // 0x800A73CC: nop

    func_80081724(rdram, ctx);
        goto after_8;
    // 0x800A73CC: nop

    after_8:
    // 0x800A73D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A73D4: beql        $t6, $zero, L_800A73E8
    if (ctx->r14 == 0) {
        // 0x800A73D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A73E8;
    }
    goto skip_0;
    // 0x800A73D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A73DC: jal         0x800A71E0
    // 0x800A73E0: nop

    func_800A71E0(rdram, ctx);
        goto after_9;
    // 0x800A73E0: nop

    after_9:
    // 0x800A73E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A73E8:
    // 0x800A73E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A73EC: jr          $ra
    // 0x800A73F0: nop

    return;
    // 0x800A73F0: nop

;}
RECOMP_FUNC void sucoasterflydata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000A0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x808000A4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3286, 0X290) << 16);
    // 0x808000A8: addiu       $t7, $t7, 0x290
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3286, 0X290));
    // 0x808000AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808000B0: jr          $ra
    // 0x808000B4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x808000B4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void func_8080171C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080171C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801728: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080172C: jal         0x80100094
    // 0x80801730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801734: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801738: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080173C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801740: jal         0x8010A3E8
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801748: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080174C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801750: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801754: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801758: bne         $t7, $at, L_80801854
    if (ctx->r15 != ctx->r1) {
        // 0x8080175C: addiu       $a2, $s0, 0x4
        ctx->r6 = ADD32(ctx->r16, 0X4);
            goto L_80801854;
    }
    // 0x8080175C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801760: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80801764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801768: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080176C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X2190) << 16);
    // 0x80801770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801774: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801778: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8080177C: lwc1        $f10, 0x2190($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2190));
    // 0x80801780: jal         0x80801ED0
    // 0x80801784: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    func_80801ED0_chfactorytwinklies(rdram, ctx);
        goto after_2;
    // 0x80801784: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x80801788: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8080178C: jal         0x80801FAC
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801FAC_chfactorytwinklies(rdram, ctx);
        goto after_3;
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801794: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80801798: jal         0x8008A498
    // 0x8080179C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080179C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808017A0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808017A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808017A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017AC: jal         0x80089F70
    // 0x808017B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808017B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808017B4: jal         0x80089F60
    // 0x808017B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808017B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808017BC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808017C0: jal         0x800C8A98
    // 0x808017C4: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    func_800C8A98(rdram, ctx);
        goto after_7;
    // 0x808017C4: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    after_7:
    // 0x808017C8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x808017CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808017D0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808017D4: jal         0x800C8E54
    // 0x808017D8: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    func_800C8E54(rdram, ctx);
        goto after_8;
    // 0x808017D8: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_8:
    // 0x808017DC: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x808017E0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1308, 0X23C8) << 16);
    // 0x808017E4: addiu       $t1, $t1, 0x23C8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1308, 0X23C8));
    // 0x808017E8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x808017EC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x808017F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808017F4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x808017F8: jal         0x800C8E84
    // 0x808017FC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800C8E84(rdram, ctx);
        goto after_9;
    // 0x808017FC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_9:
    // 0x80801800: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80801804: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801808: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1308, 0X23EC) << 16);
    // 0x8080180C: lw          $t3, 0x28($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X28);
    // 0x80801810: sll         $t5, $t3, 18
    ctx->r13 = S32(ctx->r11 << 18);
    // 0x80801814: bgezl       $t5, L_80801838
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801818: lw          $a1, 0x70($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X70);
            goto L_80801838;
    }
    goto skip_0;
    // 0x80801818: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x8080181C: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x80801820: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x80801824: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801828: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8080182C: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    // 0x80801830: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80801834: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
L_80801838:
    // 0x80801838: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080183C: addiu       $a3, $a3, 0x23EC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1308, 0X23EC));
    // 0x80801840: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80801844: jal         0x8010D930
    // 0x80801848: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8010D930(rdram, ctx);
        goto after_10;
    // 0x80801848: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_10:
    // 0x8080184C: b           L_80801890
    // 0x80801850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801890;
    // 0x80801850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801854:
    // 0x80801854: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801858: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1308, 0X2400) << 16);
    // 0x8080185C: addiu       $a3, $a3, 0x2400
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1308, 0X2400));
    // 0x80801860: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x80801864: jal         0x8010D930
    // 0x80801868: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_8010D930(rdram, ctx);
        goto after_11;
    // 0x80801868: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_11:
    // 0x8080186C: jal         0x8010A570
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801874: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x80801878: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X2194) << 16);
    // 0x8080187C: lwc1        $f18, 0x2194($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1308, 0X2194));
    // 0x80801880: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80801884: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    // 0x80801888: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x8080188C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801890:
    // 0x80801890: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801894: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801898: jr          $ra
    // 0x8080189C: nop

    return;
    // 0x8080189C: nop

;}
RECOMP_FUNC void chmole_factory_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1832, 0XF0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1832, 0XF0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1832, 0XF0));
;}
RECOMP_FUNC void func_80807E3C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807E3C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80807E40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807E44: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80807E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807E4C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80807E50: jal         0x80100094
    // 0x80807E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807E58: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80807E5C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80807E60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80807E64: bnel        $t6, $at, L_80807FC8
    if (ctx->r14 != ctx->r1) {
        // 0x80807E68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80807FC8;
    }
    goto skip_0;
    // 0x80807E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80807E6C: jal         0x80802248
    // 0x80807E70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80807E70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80807E74: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80807E78: jal         0x800EFD24
    // 0x80807E7C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80807E7C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80807E80: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80807E84: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80807E88: addiu       $a2, $s0, 0xC0
    ctx->r6 = ADD32(ctx->r16, 0XC0);
    // 0x80807E8C: jal         0x800F1E6C
    // 0x80807E90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1E6C(rdram, ctx);
        goto after_3;
    // 0x80807E90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80807E94: bne         $v0, $zero, L_80807EEC
    if (ctx->r2 != 0) {
        // 0x80807E98: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80807EEC;
    }
    // 0x80807E98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80807E9C: jal         0x8010CD50
    // 0x80807EA0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8010CD50(rdram, ctx);
        goto after_4;
    // 0x80807EA0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x80807EA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80807EA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80807EAC: jal         0x800DC298
    // 0x80807EB0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80807EB0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80807EB4: beq         $v0, $zero, L_80807ECC
    if (ctx->r2 == 0) {
        // 0x80807EB8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80807ECC;
    }
    // 0x80807EB8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80807EBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80807EC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80807EC4: b           L_80807ED8
    // 0x80807EC8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
        goto L_80807ED8;
    // 0x80807EC8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
L_80807ECC:
    // 0x80807ECC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80807ED0: nop

    // 0x80807ED4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
L_80807ED8:
    // 0x80807ED8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80807EDC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80807EE0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80807EE4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80807EE8: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
L_80807EEC:
    // 0x80807EEC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80807EF0: addiu       $a0, $s0, 0xB4
    ctx->r4 = ADD32(ctx->r16, 0XB4);
    // 0x80807EF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80807EF8: jal         0x800EE7F8
    // 0x80807EFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80807EFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_6:
    // 0x80807F00: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80807F04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80807F08: lwc1        $f16, 0xB8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80807F0C: addiu       $a0, $s0, 0xA8
    ctx->r4 = ADD32(ctx->r16, 0XA8);
    // 0x80807F10: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80807F14: swc1        $f4, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f4.u32l;
    // 0x80807F18: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80807F1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80807F20: jal         0x800EE7F8
    // 0x80807F24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80807F24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80807F28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807F2C: lw          $a1, 0xC0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC0);
    // 0x80807F30: jal         0x800EF1B8
    // 0x80807F34: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x80807F34: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_8:
    // 0x80807F38: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80807F3C: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x80807F40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80807F44: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80807F48: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80807F4C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80807F50: jal         0x80108528
    // 0x80807F54: nop

    func_80108528(rdram, ctx);
        goto after_9;
    // 0x80807F54: nop

    after_9:
    // 0x80807F58: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80807F5C: lbu         $t8, 0x75($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X75);
    // 0x80807F60: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C30) << 16);
    // 0x80807F64: andi        $t9, $t8, 0xFFFD
    ctx->r25 = ctx->r24 & 0XFFFD;
    // 0x80807F68: sb          $t9, 0x75($v0)
    MEM_B(0X75, ctx->r2) = ctx->r25;
    // 0x80807F6C: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80807F70: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x80807F74: lwc1        $f12, -0x63D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C30));
    // 0x80807F78: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C34) << 16);
    // 0x80807F7C: jal         0x800DC178
    // 0x80807F80: lwc1        $f14, -0x63CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C34));
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80807F80: lwc1        $f14, -0x63CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C34));
    after_10:
    // 0x80807F84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80807F88: jal         0x80102FDC
    // 0x80807F8C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80102FDC(rdram, ctx);
        goto after_11;
    // 0x80807F8C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x80807F90: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80807F94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80807F98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80807F9C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80807FA0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80807FA4: sb          $t2, 0xA4($s0)
    MEM_B(0XA4, ctx->r16) = ctx->r10;
    // 0x80807FA8: sw          $t1, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r9;
    // 0x80807FAC: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x80807FB0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80807FB4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA154) << 16);
    // 0x80807FB8: addiu       $a2, $a2, -0x5EAC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA154));
    // 0x80807FBC: jal         0x80089D18
    // 0x80807FC0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80807FC0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_12:
    // 0x80807FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807FC8:
    // 0x80807FC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807FCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80807FD0: jr          $ra
    // 0x80807FD4: nop

    return;
    // 0x80807FD4: nop

;}
RECOMP_FUNC void chonearmbandit_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(896, 0X1304) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1304
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(896, 0X1304));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1304
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(896, 0X1304));
;}
RECOMP_FUNC void _sumultiscore_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899B0: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x800899B0);
    return;
    // 0x800899B4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800030_chtrashcompactor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800044: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800048: jal         0x800EE7F8
    // 0x8080004C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80800050: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: jal         0x800EE7F8
    // 0x80800058: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800058: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x8080005C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800060: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800064: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800068: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080006C: bne         $t7, $at, L_80800080
    if (ctx->r15 != ctx->r1) {
        // 0x80800070: swc1        $f4, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
            goto L_80800080;
    }
    // 0x80800070: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80800074: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80800078: b           L_80800088
    // 0x8080007C: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
        goto L_80800088;
    // 0x8080007C: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
L_80800080:
    // 0x80800080: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80800084: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
L_80800088:
    // 0x80800088: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8080008C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800090: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800094: jal         0x800C87DC
    // 0x80800098: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    func_800C87DC(rdram, ctx);
        goto after_2;
    // 0x80800098: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x80089CE8
    // 0x808000A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808000A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void baeggfire_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x800F53D0
    // 0x80800068: nop

    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800068: nop

    after_0:
    // 0x8080006C: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800078: jal         0x80800008
    // 0x8080007C: sb          $zero, 0x13($t6)
    MEM_B(0X13, ctx->r14) = 0;
    func_80800008_baeggfire(rdram, ctx);
        goto after_1;
    // 0x8080007C: sb          $zero, 0x13($t6)
    MEM_B(0X13, ctx->r14) = 0;
    after_1:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080024C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800250: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x80800254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080025C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800260: beq         $a2, $zero, L_808002C0
    if (ctx->r6 == 0) {
        // 0x80800264: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_808002C0;
    }
    // 0x80800264: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800268: bne         $s0, $zero, L_80800290
    if (ctx->r16 != 0) {
        // 0x8080026C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80800290;
    }
    // 0x8080026C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800270: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3198, 0X3C0) << 16);
    // 0x80800274: jal         0x800C4350
    // 0x80800278: addiu       $a2, $a2, 0x3C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3198, 0X3C0));
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800278: addiu       $a2, $a2, 0x3C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3198, 0X3C0));
    after_0:
    // 0x8080027C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80800280: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800284: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800288: jal         0x800C4350
    // 0x8080028C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x8080028C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
L_80800290:
    // 0x80800290: beq         $s0, $zero, L_808002D4
    if (ctx->r16 == 0) {
        // 0x80800294: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_808002D4;
    }
    // 0x80800294: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800298: jal         0x80089D08
    // 0x8080029C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080029C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x808002A0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808002A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: jal         0x800C4350
    // 0x808002AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x808002AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808002B0: jal         0x800C3BDC
    // 0x808002B4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_4;
    // 0x808002B4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x808002B8: b           L_808002D8
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D8;
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C0:
    // 0x808002C0: beql        $s0, $zero, L_808002D8
    if (ctx->r16 == 0) {
        // 0x808002C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002D8;
    }
    goto skip_0;
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002C8: jal         0x800C2FDC
    // 0x808002CC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C2FDC(rdram, ctx);
        goto after_5;
    // 0x808002CC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x808002D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808002D4:
    // 0x808002D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D8:
    // 0x808002D8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002E0: jr          $ra
    // 0x808002E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
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
