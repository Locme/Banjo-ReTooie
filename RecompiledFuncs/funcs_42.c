#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _suegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A388: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A388);
    return;
    // 0x8008A38C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chdoormake_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868D8: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868D8);
    return;
    // 0x800868DC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8080000C_chwaterfallfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800020: jal         0x800F22B4
    // 0x80800024: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800F22B4(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x80800028: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080002C: jal         0x800F23AC
    // 0x80800030: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F23AC(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x80800034: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800038: jal         0x800EE8E8
    // 0x8080003C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE8E8(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80800040: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800044: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800048: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080004C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800050: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800054: bgez        $t7, L_80800068
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800058: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800068;
    }
    // 0x80800058: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080005C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800060: nop

    // 0x80800064: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800068:
    // 0x80800068: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080006C: jal         0x800EF334
    // 0x80800070: nop

    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800070: nop

    after_3:
    // 0x80800074: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800078: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080007C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800080: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800084: jal         0x800EE780
    // 0x80800088: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x80800088: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x8080008C: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    // 0x80800090: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800094: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800098: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080009C: jal         0x800EFB24
    // 0x808000A0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x808000A0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x808000A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000A8: jal         0x800EEAD4
    // 0x808000AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x808000AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808000B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1524, 0X400) << 16);
    // 0x808000B4: lwc1        $f8, 0x400($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1524, 0X400));
    // 0x808000B8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808000BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808000C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000C8: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808000CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808000D0: lw          $t0, 0x70($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X70);
    // 0x808000D4: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808000D8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808000DC: lbu         $t6, 0x73($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X73);
    // 0x808000E0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x808000E4: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x808000E8: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x808000EC: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808000F0: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808000F4: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x808000F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808000FC: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80800100: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800104: sb          $t7, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r15;
    // 0x80800108: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x8080010C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800110: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800114: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800118: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8080011C: nop

    // 0x80800120: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800124: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80800128: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080012C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800130: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_808001E4_chweldarhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808001EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808001F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808001F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001FC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800200: jal         0x80100094
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800208: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080020C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800210: slti        $at, $a2, 0xC
    ctx->r1 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
    // 0x80800214: bne         $at, $zero, L_8080023C
    if (ctx->r1 != 0) {
        // 0x80800218: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_8080023C;
    }
    // 0x80800218: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x8080021C: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x80800220: beq         $at, $zero, L_80800248
    if (ctx->r1 == 0) {
        // 0x80800224: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800248;
    }
    // 0x80800224: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800228: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1404, 0X430) << 16);
    // 0x8080022C: addu        $at, $at, $t6
    gpr jr_addend_80800234 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800230: lw          $t6, 0x430($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1404, 0X430));
    // 0x80800234: jr          $t6
    // 0x80800238: nop

    switch (jr_addend_80800234 >> 2) {
        case 0: goto L_80800250; break;
        case 1: goto L_80800248; break;
        case 2: goto L_80800248; break;
        case 3: goto L_80800248; break;
        case 4: goto L_808002BC; break;
        case 5: goto L_80800248; break;
        case 6: goto L_80800248; break;
        case 7: goto L_80800248; break;
        case 8: goto L_80800248; break;
        case 9: goto L_80800248; break;
        case 10: goto L_80800248; break;
        case 11: goto L_80800248; break;
        case 12: goto L_80800248; break;
        case 13: goto L_80800248; break;
        case 14: goto L_80800248; break;
        case 15: goto L_8080031C; break;
        case 16: goto L_80800248; break;
        case 17: goto L_80800248; break;
        case 18: goto L_80800248; break;
        case 19: goto L_80800248; break;
        case 20: goto L_80800248; break;
        case 21: goto L_80800248; break;
        case 22: goto L_80800248; break;
        case 23: goto L_80800248; break;
        case 24: goto L_80800248; break;
        case 25: goto L_80800248; break;
        case 26: goto L_80800248; break;
        case 27: goto L_80800248; break;
        case 28: goto L_80800248; break;
        case 29: goto L_80800248; break;
        case 30: goto L_80800248; break;
        case 31: goto L_80800248; break;
        case 32: goto L_80800248; break;
        case 33: goto L_80800248; break;
        case 34: goto L_80800248; break;
        case 35: goto L_80800248; break;
        case 36: goto L_808002A0; break;
        case 37: goto L_80800248; break;
        case 38: goto L_80800248; break;
        case 39: goto L_80800248; break;
        case 40: goto L_80800248; break;
        case 41: goto L_8080026C; break;
        default: switch_error(__func__, 0x80800234, 0x80800430);
    }
    // 0x80800238: nop

L_8080023C:
    // 0x8080023C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800240: beq         $a2, $at, L_808002E4
    if (ctx->r6 == ctx->r1) {
        // 0x80800244: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_808002E4;
    }
    // 0x80800244: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_80800248:
    // 0x80800248: b           L_8080037C
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080037C;
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800250:
    // 0x80800250: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800254: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800258: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8080025C: jal         0x8080038C
    // 0x80800260: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080038C_chweldarhead(rdram, ctx);
        goto after_1;
    // 0x80800260: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800264: b           L_8080037C
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080037C;
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080026C:
    // 0x8080026C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800270: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800274: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800278: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080027C: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80800280: and         $t8, $a3, $at
    ctx->r24 = ctx->r7 & ctx->r1;
    // 0x80800284: srl         $a3, $t8, 16
    ctx->r7 = S32(U32(ctx->r24) >> 16);
    // 0x80800288: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8080028C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800290: jal         0x8008A2B8
    // 0x80800294: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800294: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_2:
    // 0x80800298: b           L_80800380
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800380;
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A0:
    // 0x808002A0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808002A4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1404, 0X4E0) << 16);
    // 0x808002A8: addiu       $a0, $a0, 0x4E0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1404, 0X4E0));
    // 0x808002AC: jal         0x80088090
    // 0x808002B0: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808002B0: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    after_3:
    // 0x808002B4: b           L_8080037C
    // 0x808002B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080037C;
    // 0x808002B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002BC:
    // 0x808002BC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808002C0: addiu       $t2, $zero, 0xB5
    ctx->r10 = ADD32(0, 0XB5);
    // 0x808002C4: addiu       $a1, $zero, 0x1360
    ctx->r5 = ADD32(0, 0X1360);
    // 0x808002C8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808002CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808002D0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808002D4: jal         0x8008A208
    // 0x808002D8: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808002D8: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    after_4:
    // 0x808002DC: b           L_8080037C
    // 0x808002E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080037C;
    // 0x808002E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002E4:
    // 0x808002E4: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x808002E8: bne         $t3, $at, L_80800314
    if (ctx->r11 != ctx->r1) {
        // 0x808002EC: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_80800314;
    }
    // 0x808002EC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x808002F0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x808002F4: addiu       $t5, $zero, 0xB5
    ctx->r13 = ADD32(0, 0XB5);
    // 0x808002F8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808002FC: addiu       $a1, $zero, 0x1384
    ctx->r5 = ADD32(0, 0X1384);
    // 0x80800300: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800304: jal         0x8008A208
    // 0x80800308: addiu       $a3, $t4, 0x4
    ctx->r7 = ADD32(ctx->r12, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800308: addiu       $a3, $t4, 0x4
    ctx->r7 = ADD32(ctx->r12, 0X4);
    after_5:
    // 0x8080030C: b           L_8080037C
    // 0x80800310: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080037C;
    // 0x80800310: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800314:
    // 0x80800314: b           L_8080037C
    // 0x80800318: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080037C;
    // 0x80800318: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080031C:
    // 0x8080031C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800320: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x80800324: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80800328: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8080032C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800330: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800334: jal         0x80108528
    // 0x80800338: nop

    func_80108528(rdram, ctx);
        goto after_6;
    // 0x80800338: nop

    after_6:
    // 0x8080033C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800340: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800348: jal         0x80102FDC
    // 0x8080034C: lw          $a1, 0x14($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X14);
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x8080034C: lw          $a1, 0x14($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X14);
    after_7:
    // 0x80800350: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800354: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800358: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8080035C: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80800360: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800364: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80800368: bgezl       $t2, L_8080037C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8080036C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080037C;
    }
    goto skip_0;
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800370: jal         0x800862D8
    // 0x80800374: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800374: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80800378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080037C:
    // 0x8080037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800380:
    // 0x80800380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void func_800B42A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B42A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B42A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B42A8: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
    // 0x800B42AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B42B0: beq         $a2, $zero, L_800B42C8
    if (ctx->r6 == 0) {
        // 0x800B42B4: nop
    
            goto L_800B42C8;
    }
    // 0x800B42B4: nop

    // 0x800B42B8: jal         0x800B39D0
    // 0x800B42BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B42BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800B42C0: b           L_800B42C8
    // 0x800B42C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B42C8;
    // 0x800B42C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B42C8:
    // 0x800B42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B42CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B42D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B42D4: jr          $ra
    // 0x800B42D8: nop

    return;
    // 0x800B42D8: nop

;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F98: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F98);
    return;
    // 0x80089F9C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bashoes_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080058C: lw          $v0, 0x10C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10C);
    // 0x80800590: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800594: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80800598: beql        $v1, $zero, L_808005B0
    if (ctx->r3 == 0) {
        // 0x8080059C: lbu         $t6, 0x4($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X4);
            goto L_808005B0;
    }
    goto skip_0;
    // 0x8080059C: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    skip_0:
    // 0x808005A0: jalr        $v1
    // 0x808005A4: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x808005A4: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
    after_0:
    // 0x808005A8: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
    // 0x808005AC: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
L_808005B0:
    // 0x808005B0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808005B4: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808005B8: beq         $at, $zero, L_8080073C
    if (ctx->r1 == 0) {
        // 0x808005BC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080073C;
    }
    // 0x808005BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808005C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(592, 0XAB4) << 16);
    // 0x808005C4: addu        $at, $at, $t7
    gpr jr_addend_808005CC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808005C8: lw          $t7, 0xAB4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(592, 0XAB4));
    // 0x808005CC: jr          $t7
    // 0x808005D0: nop

    switch (jr_addend_808005CC >> 2) {
        case 0: goto L_8080073C; break;
        case 1: goto L_808005D4; break;
        case 2: goto L_80800640; break;
        case 3: goto L_80800694; break;
        case 4: goto L_808006F0; break;
        default: switch_error(__func__, 0x808005CC, 0x80800AB4);
    }
    // 0x808005D0: nop

L_808005D4:
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x80095738
    // 0x808005DC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x808005DC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x808005E0: beq         $v0, $zero, L_808005FC
    if (ctx->r2 == 0) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005FC;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x80800384
    // 0x808005F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808005F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808005F4: b           L_80800740
    // 0x808005F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x808005F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005FC:
    // 0x808005FC: jal         0x80095738
    // 0x80800600: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    baflag_isTrue(rdram, ctx);
        goto after_3;
    // 0x80800600: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_3:
    // 0x80800604: beq         $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x80800608: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800620;
    }
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: jal         0x80800384
    // 0x80800614: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800614: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800618: b           L_80800740
    // 0x8080061C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x8080061C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800620:
    // 0x80800620: jal         0x80095738
    // 0x80800624: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baflag_isTrue(rdram, ctx);
        goto after_5;
    // 0x80800624: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_5:
    // 0x80800628: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x8080062C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080073C;
    }
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x80800384
    // 0x80800634: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80800634: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800638: b           L_80800740
    // 0x8080063C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x8080063C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800640:
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x80800180
    // 0x80800648: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80800180_bashoes(rdram, ctx);
        goto after_7;
    // 0x80800648: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x80095738
    // 0x80800654: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    baflag_isTrue(rdram, ctx);
        goto after_8;
    // 0x80800654: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_8:
    // 0x80800658: beq         $v0, $zero, L_80800674
    if (ctx->r2 == 0) {
        // 0x8080065C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800674;
    }
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: jal         0x80800384
    // 0x80800668: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x80800668: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x8080066C: b           L_80800740
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800674:
    // 0x80800674: jal         0x80095738
    // 0x80800678: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baflag_isTrue(rdram, ctx);
        goto after_10;
    // 0x80800678: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_10:
    // 0x8080067C: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800680: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080073C;
    }
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x80800384
    // 0x80800688: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x80800688: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x8080068C: b           L_80800740
    // 0x80800690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x80800690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800694:
    // 0x80800694: jal         0x800D9078
    // 0x80800698: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    func_800D9078(rdram, ctx);
        goto after_12;
    // 0x80800698: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    after_12:
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A0: jal         0x80800180
    // 0x808006A4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    func_80800180_bashoes(rdram, ctx);
        goto after_13;
    // 0x808006A4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_13:
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x80095738
    // 0x808006B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baflag_isTrue(rdram, ctx);
        goto after_14;
    // 0x808006B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x808006B4: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x808006B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D0;
    }
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: jal         0x80800384
    // 0x808006C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x808006C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x808006C8: b           L_80800740
    // 0x808006CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x808006CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006D0:
    // 0x808006D0: jal         0x80095738
    // 0x808006D4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baflag_isTrue(rdram, ctx);
        goto after_16;
    // 0x808006D4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_16:
    // 0x808006D8: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x808006DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080073C;
    }
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: jal         0x80800384
    // 0x808006E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x808006E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_17:
    // 0x808006E8: b           L_80800740
    // 0x808006EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x808006EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006F0:
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: jal         0x80800180
    // 0x808006F8: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    func_80800180_bashoes(rdram, ctx);
        goto after_18;
    // 0x808006F8: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_18:
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x80095738
    // 0x80800704: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baflag_isTrue(rdram, ctx);
        goto after_19;
    // 0x80800704: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_19:
    // 0x80800708: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x8080070C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800724;
    }
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800714: jal         0x80800384
    // 0x80800718: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x80800718: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_20:
    // 0x8080071C: b           L_80800740
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800740;
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800724:
    // 0x80800724: jal         0x80095738
    // 0x80800728: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    baflag_isTrue(rdram, ctx);
        goto after_21;
    // 0x80800728: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_21:
    // 0x8080072C: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080073C;
    }
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x80800384
    // 0x80800738: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_22;
    // 0x80800738: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_22:
L_8080073C:
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800740:
    // 0x80800740: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800748: jr          $ra
    // 0x8080074C: nop

    return;
    // 0x8080074C: nop

;}
RECOMP_FUNC void func_808001AC_gcintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2642, 0X56C) << 16);
    // 0x808001B0: lhu         $t6, 0x56C($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(2642, 0X56C));
    // 0x808001B4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2642, 0X56E) << 16);
    // 0x808001B8: bne         $a0, $t6, L_808001C8
    if (ctx->r4 != ctx->r14) {
        // 0x808001BC: nop
    
            goto L_808001C8;
    }
    // 0x808001BC: nop

    // 0x808001C0: jr          $ra
    // 0x808001C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808001C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001C8:
    // 0x808001C8: lhu         $t7, 0x56E($t7)
    ctx->r15 = MEM_HU(ctx->r15, (int16_t)RELOC_LO16(2642, 0X56E));
    // 0x808001CC: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2642, 0X570) << 16);
    // 0x808001D0: addiu       $v1, $v1, 0x570
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2642, 0X570));
    // 0x808001D4: bne         $a0, $t7, L_808001E4
    if (ctx->r4 != ctx->r15) {
        // 0x808001D8: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(2642, 0X5A0) << 16);
            goto L_808001E4;
    }
    // 0x808001D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2642, 0X5A0) << 16);
    // 0x808001DC: jr          $ra
    // 0x808001E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808001E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001E4:
    // 0x808001E4: addiu       $v0, $v0, 0x5A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X5A0));
    // 0x808001E8: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
L_808001EC:
    // 0x808001EC: bnel        $a0, $t8, L_80800200
    if (ctx->r4 != ctx->r24) {
        // 0x808001F0: lhu         $t9, 0x2($v1)
        ctx->r25 = MEM_HU(ctx->r3, 0X2);
            goto L_80800200;
    }
    goto skip_0;
    // 0x808001F0: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    skip_0:
    // 0x808001F4: jr          $ra
    // 0x808001F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808001F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001FC: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
L_80800200:
    // 0x80800200: bnel        $a0, $t9, L_80800214
    if (ctx->r4 != ctx->r25) {
        // 0x80800204: lhu         $t0, 0x4($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X4);
            goto L_80800214;
    }
    goto skip_1;
    // 0x80800204: lhu         $t0, 0x4($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4);
    skip_1:
    // 0x80800208: jr          $ra
    // 0x8080020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800210: lhu         $t0, 0x4($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4);
L_80800214:
    // 0x80800214: bnel        $a0, $t0, L_80800228
    if (ctx->r4 != ctx->r8) {
        // 0x80800218: lhu         $t1, 0x6($v1)
        ctx->r9 = MEM_HU(ctx->r3, 0X6);
            goto L_80800228;
    }
    goto skip_2;
    // 0x80800218: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
    skip_2:
    // 0x8080021C: jr          $ra
    // 0x80800220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800224: lhu         $t1, 0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X6);
L_80800228:
    // 0x80800228: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8080022C: bne         $a0, $t1, L_8080023C
    if (ctx->r4 != ctx->r9) {
        // 0x80800230: nop
    
            goto L_8080023C;
    }
    // 0x80800230: nop

    // 0x80800234: jr          $ra
    // 0x80800238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080023C:
    // 0x8080023C: bnel        $v1, $v0, L_808001EC
    if (ctx->r3 != ctx->r2) {
        // 0x80800240: lhu         $t8, 0x0($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X0);
            goto L_808001EC;
    }
    goto skip_3;
    // 0x80800240: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    skip_3:
    // 0x80800244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void bsbbuster_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800328: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800334: jal         0x8008CABC
    // 0x80800338: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800338: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x8080033C: lui         $a1, 0x3E75
    ctx->r5 = S32(0X3E75 << 16);
    // 0x80800340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800344: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800348: jal         0x8008CB10
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800350: beql        $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800354: lbu         $t6, 0x161($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X161);
            goto L_80800364;
    }
    goto skip_0;
    // 0x80800354: lbu         $t6, 0x161($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X161);
    skip_0:
    // 0x80800358: jal         0x8009D874
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_2;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800360: lbu         $t6, 0x161($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X161);
L_80800364:
    // 0x80800364: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800368: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8080036C: beq         $at, $zero, L_80800684
    if (ctx->r1 == 0) {
        // 0x80800370: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800684;
    }
    // 0x80800370: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(65, 0X71C) << 16);
    // 0x80800378: addu        $at, $at, $t7
    gpr jr_addend_80800380 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080037C: lw          $t7, 0x71C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(65, 0X71C));
    // 0x80800380: jr          $t7
    // 0x80800384: nop

    switch (jr_addend_80800380 >> 2) {
        case 0: goto L_80800388; break;
        case 1: goto L_808003E8; break;
        case 2: goto L_80800430; break;
        case 3: goto L_808005AC; break;
        case 4: goto L_8080061C; break;
        default: switch_error(__func__, 0x80800380, 0x8080071C);
    }
    // 0x80800384: nop

L_80800388:
    // 0x80800388: jal         0x800841D8
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800390: jal         0x8008CAEC
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_4;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800398: beq         $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x8080039C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A8;
    }
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: jal         0x80800000
    // 0x808003A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bsbbuster_setSubstate(rdram, ctx);
        goto after_5;
    // 0x808003A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_808003A8:
    // 0x808003A8: lui         $a1, 0x3EBA
    ctx->r5 = S32(0X3EBA << 16);
    // 0x808003AC: ori         $a1, $a1, 0x36E3
    ctx->r5 = ctx->r5 | 0X36E3;
    // 0x808003B0: jal         0x8008CB10
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003B8: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x808003BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800684;
    }
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x800919F4
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_7;
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808003C8: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x808003CC: nop
    
            goto L_80800684;
    }
    // 0x808003CC: nop

    // 0x808003D0: jal         0x800C6E38
    // 0x808003D4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800C6E38(rdram, ctx);
        goto after_8;
    // 0x808003D4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_8:
    // 0x808003D8: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x808003DC: addiu       $t8, $zero, 0xB6
        ctx->r24 = ADD32(0, 0XB6);
            goto L_80800684;
    }
    // 0x808003DC: addiu       $t8, $zero, 0xB6
    ctx->r24 = ADD32(0, 0XB6);
    // 0x808003E0: b           L_80800684
    // 0x808003E4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
        goto L_80800684;
    // 0x808003E4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_808003E8:
    // 0x808003E8: jal         0x800841D8
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003F0: jal         0x800D8FF8
    // 0x808003F4: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x808003F4: nop

    after_10:
    // 0x808003F8: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808003FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800408: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
    // 0x8080040C: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800410: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80800414: nop

    // 0x80800418: bc1f        L_80800684
    if (!c1cs) {
        // 0x8080041C: nop
    
            goto L_80800684;
    }
    // 0x8080041C: nop

    // 0x80800420: jal         0x80800000
    // 0x80800424: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bsbbuster_setSubstate(rdram, ctx);
        goto after_11;
    // 0x80800424: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800428: b           L_80800684
    // 0x8080042C: nop

        goto L_80800684;
    // 0x8080042C: nop

L_80800430:
    // 0x80800430: lbu         $t9, 0x15C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800434: bnel        $t9, $zero, L_8080047C
    if (ctx->r25 != 0) {
        // 0x80800438: lbu         $t2, 0x162($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X162);
            goto L_8080047C;
    }
    goto skip_1;
    // 0x80800438: lbu         $t2, 0x162($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X162);
    skip_1:
    // 0x8080043C: jal         0x8009BB50
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_12;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800444: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800448: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x8080044C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800450: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: addiu       $a1, $zero, 0x442F
    ctx->r5 = ADD32(0, 0X442F);
    // 0x8080045C: bc1fl       L_8080047C
    if (!c1cs) {
        // 0x80800460: lbu         $t2, 0x162($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X162);
            goto L_8080047C;
    }
    goto skip_2;
    // 0x80800460: lbu         $t2, 0x162($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X162);
    skip_2:
    // 0x80800464: jal         0x8009DF94
    // 0x80800468: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF94(rdram, ctx);
        goto after_13;
    // 0x80800468: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_13:
    // 0x8080046C: lbu         $t0, 0x15C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800470: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800474: sb          $t1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r9;
    // 0x80800478: lbu         $t2, 0x162($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X162);
L_8080047C:
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: bnel        $t2, $zero, L_808004B4
    if (ctx->r10 != 0) {
        // 0x80800484: lbu         $t5, 0x15F($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X15F);
            goto L_808004B4;
    }
    goto skip_3;
    // 0x80800484: lbu         $t5, 0x15F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X15F);
    skip_3:
    // 0x80800488: jal         0x8008DF8C
    // 0x8080048C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_8008DF8C(rdram, ctx);
        goto after_14;
    // 0x8080048C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_14:
    // 0x80800490: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x80800494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B0;
    }
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: addiu       $a1, $zero, 0x40D
    ctx->r5 = ADD32(0, 0X40D);
    // 0x8080049C: jal         0x8009DE38
    // 0x808004A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_15;
    // 0x808004A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_15:
    // 0x808004A4: lbu         $t3, 0x162($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X162);
    // 0x808004A8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x808004AC: sb          $t4, 0x162($s0)
    MEM_B(0X162, ctx->r16) = ctx->r12;
L_808004B0:
    // 0x808004B0: lbu         $t5, 0x15F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X15F);
L_808004B4:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: bnel        $t5, $zero, L_808004F8
    if (ctx->r13 != 0) {
        // 0x808004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F8;
    }
    goto skip_4;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x808004C0: jal         0x8008DF8C
    // 0x808004C4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    func_8008DF8C(rdram, ctx);
        goto after_16;
    // 0x808004C4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_16:
    // 0x808004C8: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F4;
    }
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808004D4: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x808004D8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808004DC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808004E0: jal         0x80085490
    // 0x808004E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_17;
    // 0x808004E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_17:
    // 0x808004E8: lbu         $t6, 0x15F($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15F);
    // 0x808004EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808004F0: sb          $t7, 0x15F($s0)
    MEM_B(0X15F, ctx->r16) = ctx->r15;
L_808004F4:
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F8:
    // 0x808004F8: jal         0x80095738
    // 0x808004FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    baflag_isTrue(rdram, ctx);
        goto after_18;
    // 0x808004FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x80800500: sb          $v0, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r2;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: jal         0x80096394
    // 0x8080050C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80096394(rdram, ctx);
        goto after_19;
    // 0x8080050C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x80800510: jal         0x800F2100
    // 0x80800514: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    mlAbsF(rdram, ctx);
        goto after_20;
    // 0x80800514: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800518: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080051C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800520: nop

    // 0x80800524: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800528: nop

    // 0x8080052C: bc1fl       L_80800548
    if (!c1cs) {
        // 0x80800530: sb          $zero, 0x160($s0)
        MEM_B(0X160, ctx->r16) = 0;
            goto L_80800548;
    }
    goto skip_5;
    // 0x80800530: sb          $zero, 0x160($s0)
    MEM_B(0X160, ctx->r16) = 0;
    skip_5:
    // 0x80800534: lbu         $t8, 0x160($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X160);
    // 0x80800538: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8080053C: b           L_80800548
    // 0x80800540: sb          $t9, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r25;
        goto L_80800548;
    // 0x80800540: sb          $t9, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r25;
    // 0x80800544: sb          $zero, 0x160($s0)
    MEM_B(0X160, ctx->r16) = 0;
L_80800548:
    // 0x80800548: lbu         $t0, 0x15E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X15E);
    // 0x8080054C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800550: bne         $t0, $at, L_8080055C
    if (ctx->r8 != ctx->r1) {
        // 0x80800554: nop
    
            goto L_8080055C;
    }
    // 0x80800554: nop

    // 0x80800558: sb          $zero, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = 0;
L_8080055C:
    // 0x8080055C: jal         0x8008E078
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_21;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800564: bne         $v0, $zero, L_80800588
    if (ctx->r2 != 0) {
        // 0x80800568: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800588;
    }
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: lbu         $t1, 0x15D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X15D);
    // 0x80800570: bne         $t1, $zero, L_80800588
    if (ctx->r9 != 0) {
        // 0x80800574: nop
    
            goto L_80800588;
    }
    // 0x80800574: nop

    // 0x80800578: lbu         $t2, 0x160($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X160);
    // 0x8080057C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80800580: bne         $at, $zero, L_80800684
    if (ctx->r1 != 0) {
        // 0x80800584: nop
    
            goto L_80800684;
    }
    // 0x80800584: nop

L_80800588:
    // 0x80800588: jal         0x80800000
    // 0x8080058C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bsbbuster_setSubstate(rdram, ctx);
        goto after_22;
    // 0x8080058C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_22:
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: jal         0x800954E8
    // 0x80800598: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800954E8(rdram, ctx);
        goto after_23;
    // 0x80800598: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_23:
    // 0x8080059C: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x808005A0: addiu       $t3, $zero, 0x72
        ctx->r11 = ADD32(0, 0X72);
            goto L_80800684;
    }
    // 0x808005A0: addiu       $t3, $zero, 0x72
    ctx->r11 = ADD32(0, 0X72);
    // 0x808005A4: b           L_80800684
    // 0x808005A8: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
        goto L_80800684;
    // 0x808005A8: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
L_808005AC:
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: jal         0x80095774
    // 0x808005B4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    baflag_clear(rdram, ctx);
        goto after_24;
    // 0x808005B4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_24:
    // 0x808005B8: sb          $zero, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = 0;
    // 0x808005BC: jal         0x8009BD44
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_25;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808005C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005C8: bne         $v0, $at, L_808005DC
    if (ctx->r2 != ctx->r1) {
        // 0x808005CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005DC;
    }
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808005D4: jal         0x8009BDAC
    // 0x808005D8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_8009BDAC(rdram, ctx);
        goto after_26;
    // 0x808005D8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_26:
L_808005DC:
    // 0x808005DC: jal         0x800D8FF8
    // 0x808005E0: nop

    func_800D8FF8(rdram, ctx);
        goto after_27;
    // 0x808005E0: nop

    after_27:
    // 0x808005E4: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808005E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808005F4: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
    // 0x808005F8: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808005FC: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80800600: nop

    // 0x80800604: bc1f        L_80800684
    if (!c1cs) {
        // 0x80800608: nop
    
            goto L_80800684;
    }
    // 0x80800608: nop

    // 0x8080060C: jal         0x80800000
    // 0x80800610: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bsbbuster_setSubstate(rdram, ctx);
        goto after_28;
    // 0x80800610: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x80800614: b           L_80800684
    // 0x80800618: nop

        goto L_80800684;
    // 0x80800618: nop

L_8080061C:
    // 0x8080061C: jal         0x800841D8
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_29;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800624: jal         0x8008CAEC
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_30;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080062C: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x80800630: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800644;
    }
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: lui         $a1, 0x3F3D
    ctx->r5 = S32(0X3F3D << 16);
    // 0x80800638: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x8080063C: jal         0x8008CF1C
    // 0x80800640: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_31;
    // 0x80800640: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_31:
L_80800644:
    // 0x80800644: jal         0x8008E078
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_32;
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x8080064C: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x80800650: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800684;
    }
    // 0x80800650: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800654: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800658: jal         0x8008B1D4
    // 0x8080065C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_33;
    // 0x8080065C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_33:
    // 0x80800660: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800664: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800668: jal         0x8008B1BC
    // 0x8080066C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_setDuration(rdram, ctx);
        goto after_34;
    // 0x8080066C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_34:
    // 0x80800670: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800674: jal         0x8008B134
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_35;
    // 0x80800678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x8080067C: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80800680: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80800684:
    // 0x80800684: jal         0x8008E35C
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_36;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8080068C: beq         $v0, $zero, L_80800698
    if (ctx->r2 == 0) {
        // 0x80800690: addiu       $t5, $zero, 0x4C
        ctx->r13 = ADD32(0, 0X4C);
            goto L_80800698;
    }
    // 0x80800690: addiu       $t5, $zero, 0x4C
    ctx->r13 = ADD32(0, 0X4C);
    // 0x80800694: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_80800698:
    // 0x80800698: lbu         $t6, 0x15E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15E);
    // 0x8080069C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: beq         $t6, $zero, L_808006BC
    if (ctx->r14 == 0) {
        // 0x808006A8: nop
    
            goto L_808006BC;
    }
    // 0x808006A8: nop

    // 0x808006AC: jal         0x80095760
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baflag_set(rdram, ctx);
        goto after_37;
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808006B4: b           L_808006C8
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006C8;
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006BC:
    // 0x808006BC: jal         0x80095774
    // 0x808006C0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    baflag_clear(rdram, ctx);
        goto after_38;
    // 0x808006C0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_38:
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006C8:
    // 0x808006C8: jal         0x8009E5C8
    // 0x808006CC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_39;
    // 0x808006CC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_39:
    // 0x808006D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006DC: jr          $ra
    // 0x808006E0: nop

    return;
    // 0x808006E0: nop

;}
RECOMP_FUNC void _bsbeggass_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828E0: syscall     18
    recomp_syscall_handler(rdram, ctx, 0x800828E0);
    return;
    // 0x800828E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801484_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801484: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801488: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080148C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801490: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801498: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080149C: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x808014A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808014A4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808014A8: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x808014AC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808014B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808014B4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808014B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808014BC: jal         0x800EE88C
    // 0x808014C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x808014C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x808014C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C8: jal         0x80800654
    // 0x808014CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800654_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x808014CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x808014D0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808014D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D8: jal         0x80800630
    // 0x808014DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800630_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x808014DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808014E0: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x808014E4: beq         $at, $zero, L_8080156C
    if (ctx->r1 == 0) {
        // 0x808014E8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080156C;
    }
    // 0x808014E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808014EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2606, 0X15A0) << 16);
    // 0x808014F0: lwc1        $f20, 0x15A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2606, 0X15A0));
    // 0x808014F4: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x808014F8: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
L_808014FC:
    // 0x808014FC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801500: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80801504: nop

    // 0x80801508: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080150C: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80801510: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80801514: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x80801518: nop

    // 0x8080151C: bc1fl       L_80801560
    if (!c1cs) {
        // 0x80801520: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80801560;
    }
    goto skip_0;
    // 0x80801520: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_0:
    // 0x80801524: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x80801528: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080152C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801530: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80801534: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80801538: nop

    // 0x8080153C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801540: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801544: jal         0x800F0064
    // 0x80801548: nop

    func_800F0064(rdram, ctx);
        goto after_3;
    // 0x80801548: nop

    after_3:
    // 0x8080154C: beql        $v0, $zero, L_80801560
    if (ctx->r2 == 0) {
        // 0x80801550: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80801560;
    }
    goto skip_1;
    // 0x80801550: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_1:
    // 0x80801554: b           L_80801570
    // 0x80801558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801570;
    // 0x80801558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080155C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_80801560:
    // 0x80801560: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80801564: bnel        $at, $zero, L_808014FC
    if (ctx->r1 != 0) {
        // 0x80801568: lh          $t6, 0x2($s3)
        ctx->r14 = MEM_H(ctx->r19, 0X2);
            goto L_808014FC;
    }
    goto skip_2;
    // 0x80801568: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    skip_2:
L_8080156C:
    // 0x8080156C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801570:
    // 0x80801570: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801574: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801578: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080157C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801580: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801584: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801588: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080158C: jr          $ra
    // 0x80801590: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801590: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801594: nop

    // 0x80801598: nop

    // 0x8080159C: nop

;}
RECOMP_FUNC void _gccubeDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C50: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C50);
    return;
    // 0x80087C54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsbfly_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082990: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082990);
    return;
    // 0x80082994: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _basudie_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085238: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085238);
    return;
    // 0x8008523C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gldbstring_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088720: syscall     701
    recomp_syscall_handler(rdram, ctx, 0x80088720);
    return;
    // 0x80088724: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8080000C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800014: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800018: jal         0x8009FFD8
    // 0x8080001C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_80800818_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800818: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080081C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800824: jal         0x8008CABC
    // 0x80800828: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800828: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080082C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800830: jal         0x80085228
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: jal         0x8009B9B0
    // 0x80800840: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800840: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x80800844: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800848: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x80800854: nop
    
            goto L_80800878;
    }
    // 0x80800854: nop

    // 0x80800858: beq         $v0, $at, L_80800890
    if (ctx->r2 == ctx->r1) {
        // 0x8080085C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800890;
    }
    // 0x8080085C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800860: beq         $v0, $at, L_80800900
    if (ctx->r2 == ctx->r1) {
        // 0x80800864: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800900;
    }
    // 0x80800864: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800868: beql        $v0, $at, L_80800968
    if (ctx->r2 == ctx->r1) {
        // 0x8080086C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800968;
    }
    goto skip_0;
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800870: b           L_80800968
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800968;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800878:
    // 0x80800878: jal         0x8008DF8C
    // 0x8080087C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_3;
    // 0x8080087C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_3:
    // 0x80800880: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x80800884: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800964;
    }
    // 0x80800884: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800888: b           L_80800964
    // 0x8080088C: sb          $t6, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r14;
        goto L_80800964;
    // 0x8080088C: sb          $t6, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r14;
L_80800890:
    // 0x80800890: jal         0x8008E078
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x80800894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800898: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x8080089C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800964;
    }
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x808008A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808008A8: jal         0x8009DF18
    // 0x808008AC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x808008AC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_5:
    // 0x808008B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808008B8: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808008BC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808008C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808008C8: jal         0x80085490
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808008D0: jal         0x80800680
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_bstrexsmall(rdram, ctx);
        goto after_7;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808008D8: jal         0x8009E058
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E058(rdram, ctx);
        goto after_8;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008E0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808008E4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: jal         0x8008CF1C
    // 0x808008F0: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x808008F0: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_9:
    // 0x808008F4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808008F8: b           L_80800964
    // 0x808008FC: sb          $t7, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r15;
        goto L_80800964;
    // 0x808008FC: sb          $t7, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r15;
L_80800900:
    // 0x80800900: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800908: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080090C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800910: jal         0x800F0E00
    // 0x80800914: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_10;
    // 0x80800914: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_10:
    // 0x80800918: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8080091C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800920: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800924: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800928: nop

    // 0x8080092C: bc1f        L_8080093C
    if (!c1cs) {
        // 0x80800930: nop
    
            goto L_8080093C;
    }
    // 0x80800930: nop

    // 0x80800934: jal         0x80084A10
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_8080093C:
    // 0x8080093C: jal         0x8008B324
    // 0x80800940: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_12;
    // 0x80800940: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800944: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x80800948: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800964;
    }
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: jal         0x8008CED4
    // 0x80800950: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_13;
    // 0x80800950: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x80800954: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800958: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8080095C: sb          $t8, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r24;
    // 0x80800960: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
L_80800964:
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800968:
    // 0x80800968: jal         0x8009E5C8
    // 0x8080096C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x8080096C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080097C: jr          $ra
    // 0x80800980: nop

    return;
    // 0x80800980: nop

;}
RECOMP_FUNC void func_80093388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009338C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093390: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093394: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80093398: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8009339C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800933A0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800933A4: jal         0x800F2100
    // 0x800933A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800933A8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800933AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800933B0: lwc1        $f8, 0x4D40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4D40);
    // 0x800933B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800933B8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800933BC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800933C0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800933C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800933C8: bc1fl       L_800933E4
    if (!c1cs) {
        // 0x800933CC: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_800933E4;
    }
    goto skip_0;
    // 0x800933CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x800933D0: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x800933D4: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x800933D8: b           L_80093438
    // 0x800933DC: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
        goto L_80093438;
    // 0x800933DC: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x800933E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_800933E4:
    // 0x800933E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800933E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800933EC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800933F0: nop

    // 0x800933F4: bc1fl       L_80093408
    if (!c1cs) {
        // 0x800933F8: c.lt.s      $f18, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
            goto L_80093408;
    }
    goto skip_1;
    // 0x800933F8: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    skip_1:
    // 0x800933FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80093400: nop

    // 0x80093404: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
L_80093408:
    // 0x80093408: nop

    // 0x8009340C: bc1fl       L_8009342C
    if (!c1cs) {
        // 0x80093410: lw          $v0, 0x50($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X50);
            goto L_8009342C;
    }
    goto skip_2;
    // 0x80093410: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    skip_2:
    // 0x80093414: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093418: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8009341C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80093420: b           L_80093438
    // 0x80093424: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
        goto L_80093438;
    // 0x80093424: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x80093428: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
L_8009342C:
    // 0x8009342C: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80093430: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80093434: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
L_80093438:
    // 0x80093438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009343C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80093440: jr          $ra
    // 0x80093444: nop

    return;
    // 0x80093444: nop

;}
RECOMP_FUNC void func_8080078C_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800798: lh          $t8, 0x7E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7E);
    // 0x8080079C: bltz        $t8, L_808007AC
    if (SIGNED(ctx->r24) < 0) {
        // 0x808007A0: nop
    
            goto L_808007AC;
    }
    // 0x808007A0: nop

    // 0x808007A4: b           L_8080081C
    // 0x808007A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x808007A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007AC:
    // 0x808007AC: jal         0x80104544
    // 0x808007B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80104544(rdram, ctx);
        goto after_0;
    // 0x808007B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808007B4: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007B8: nop
    
            goto L_808007C4;
    }
    // 0x808007B8: nop

    // 0x808007BC: b           L_8080081C
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007C4:
    // 0x808007C4: jal         0x800DB9B0
    // 0x808007C8: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x808007C8: nop

    after_1:
    // 0x808007CC: beq         $v0, $zero, L_808007DC
    if (ctx->r2 == 0) {
        // 0x808007D0: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_808007DC;
    }
    // 0x808007D0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808007D4: b           L_8080081C
    // 0x808007D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x808007D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007DC:
    // 0x808007DC: lhu         $t0, 0x7A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X7A);
    // 0x808007E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007E4: srl         $t1, $t0, 14
    ctx->r9 = S32(U32(ctx->r8) >> 14);
    // 0x808007E8: bne         $t1, $at, L_808007F8
    if (ctx->r9 != ctx->r1) {
        // 0x808007EC: nop
    
            goto L_808007F8;
    }
    // 0x808007EC: nop

    // 0x808007F0: b           L_8080081C
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007F8:
    // 0x808007F8: jal         0x8001211C
    // 0x808007FC: nop

    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x808007FC: nop

    after_2:
    // 0x80800800: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800804: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80800808: lhu         $t4, 0x1A($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X1A);
    // 0x8080080C: srl         $t5, $t4, 5
    ctx->r13 = S32(U32(ctx->r12) >> 5);
    // 0x80800810: xor         $v0, $v0, $t5
    ctx->r2 = ctx->r2 ^ ctx->r13;
    // 0x80800814: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80800818: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
L_8080081C:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void chdinofoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1040, 0X818) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1040, 0X818));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1040, 0X818));
;}
RECOMP_FUNC void gspropsDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800718: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080071C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800724: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800728: jal         0x800EE8CC
    // 0x8080072C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE8CC(rdram, ctx);
        goto after_0;
    // 0x8080072C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800730: jal         0x800BDBC4
    // 0x80800734: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800BDBC4(rdram, ctx);
        goto after_1;
    // 0x80800734: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800738: jal         0x800E98C0
    // 0x8080073C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E98C0(rdram, ctx);
        goto after_2;
    // 0x8080073C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800740: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800744: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800748: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080074C: jal         0x8001BBC8
    // 0x80800750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    aligned4_memcpy(rdram, ctx);
        goto after_3;
    // 0x80800750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800754: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800758: lbu         $t6, 0xB($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XB);
    // 0x8080075C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800760: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800764: sb          $t8, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r24;
    // 0x80800768: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8080076C: andi        $t3, $t8, 0xDF
    ctx->r11 = ctx->r24 & 0XDF;
    // 0x80800770: sll         $t1, $t9, 30
    ctx->r9 = S32(ctx->r25 << 30);
    // 0x80800774: bgezl       $t1, L_80800784
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800778: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800784;
    }
    goto skip_0;
    // 0x80800778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080077C: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x80800780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800784:
    // 0x80800784: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800788: jr          $ra
    // 0x8080078C: nop

    return;
    // 0x8080078C: nop

;}
RECOMP_FUNC void chsabreman_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1232, 0X1BE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1BE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1BE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1BE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1BE0));
;}
RECOMP_FUNC void glgamestore_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: jal         0x80800038
    // 0x808000C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800038_glgamestore(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: jal         0x8080006C
    // 0x808000D4: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    func_8080006C_glgamestore(rdram, ctx);
        goto after_1;
    // 0x808000D4: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    after_1:
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_80800890_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800894: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080089C: bne         $a1, $at, L_808008E0
    if (ctx->r5 != ctx->r1) {
        // 0x808008A0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808008E0;
    }
    // 0x808008A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008A4: addiu       $at, $zero, 0x86
    ctx->r1 = ADD32(0, 0X86);
    // 0x808008A8: bne         $a2, $at, L_808008D8
    if (ctx->r6 != ctx->r1) {
        // 0x808008AC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808008D8;
    }
    // 0x808008AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008B0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808008B4: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x808008B8: jal         0x80085708
    // 0x808008BC: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808008BC: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    after_0:
    // 0x808008C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808008C8: jal         0x80086248
    // 0x808008CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808008CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808008D0: b           L_808008EC
    // 0x808008D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008EC;
    // 0x808008D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008D8:
    // 0x808008D8: b           L_808008E8
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008E8;
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E0:
    // 0x808008E0: jal         0x80086248
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_808008E8:
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008EC:
    // 0x808008EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void func_80800CF0_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800CF4: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80800CF8: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80800CFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D00: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800D04: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D08: beq         $t7, $zero, L_80800DD4
    if (ctx->r15 == 0) {
        // 0x80800D0C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800DD4;
    }
    // 0x80800D0C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800D10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X12A0) << 16);
    // 0x80800D14: lwc1        $f6, 0x12A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X12A0));
    // 0x80800D18: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800D1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D20: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800D24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800D28: lui         $a2, 0x12C0
    ctx->r6 = S32(0X12C0 << 16);
    // 0x80800D2C: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800D30: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800D34: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800D38: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800D3C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D40: nop

    // 0x80800D44: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800D48: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800D4C: nop

    // 0x80800D50: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800D54: beql        $a0, $zero, L_80800DA4
    if (ctx->r4 == 0) {
        // 0x80800D58: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_80800DA4;
    }
    goto skip_0;
    // 0x80800D58: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x80800D5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800D64: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800D68: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800D6C: nop

    // 0x80800D70: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800D74: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800D78: nop

    // 0x80800D7C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800D80: bne         $a0, $zero, L_80800D98
    if (ctx->r4 != 0) {
        // 0x80800D84: nop
    
            goto L_80800D98;
    }
    // 0x80800D84: nop

    // 0x80800D88: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800D8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800D90: b           L_80800DB0
    // 0x80800D94: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800DB0;
    // 0x80800D94: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800D98:
    // 0x80800D98: b           L_80800DB0
    // 0x80800D9C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800DB0;
    // 0x80800D9C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800DA0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_80800DA4:
    // 0x80800DA4: nop

    // 0x80800DA8: bltz        $a0, L_80800D98
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800DAC: nop
    
            goto L_80800D98;
    }
    // 0x80800DAC: nop

L_80800DB0:
    // 0x80800DB0: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80800DB4: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x80800DB8: ori         $at, $at, 0xC608
    ctx->r1 = ctx->r1 | 0XC608;
    // 0x80800DBC: sll         $t0, $t9, 21
    ctx->r8 = S32(ctx->r25 << 21);
    // 0x80800DC0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800DC4: addu        $a0, $t0, $at
    ctx->r4 = ADD32(ctx->r8, ctx->r1);
    // 0x80800DC8: jal         0x800C4140
    // 0x80800DCC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800C4140(rdram, ctx);
        goto after_0;
    // 0x80800DCC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80800DD0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80800DD4:
    // 0x80800DD4: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    // 0x80800DD8: beq         $t1, $zero, L_80800EA0
    if (ctx->r9 == 0) {
        // 0x80800DDC: lwc1        $f16, 0x30($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80800EA0;
    }
    // 0x80800DDC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800DE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X12A4) << 16);
    // 0x80800DE4: lwc1        $f18, 0x12A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X12A4));
    // 0x80800DE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800DF0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800DF4: lui         $a2, 0x12C0
    ctx->r6 = S32(0X12C0 << 16);
    // 0x80800DF8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800DFC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800E00: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800E04: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800E08: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800E0C: nop

    // 0x80800E10: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800E14: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800E18: nop

    // 0x80800E1C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800E20: beql        $a0, $zero, L_80800E70
    if (ctx->r4 == 0) {
        // 0x80800E24: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_80800E70;
    }
    goto skip_1;
    // 0x80800E24: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80800E28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800E30: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800E34: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800E38: nop

    // 0x80800E3C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800E40: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800E44: nop

    // 0x80800E48: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800E4C: bne         $a0, $zero, L_80800E64
    if (ctx->r4 != 0) {
        // 0x80800E50: nop
    
            goto L_80800E64;
    }
    // 0x80800E50: nop

    // 0x80800E54: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800E58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800E5C: b           L_80800E7C
    // 0x80800E60: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800E7C;
    // 0x80800E60: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80800E64:
    // 0x80800E64: b           L_80800E7C
    // 0x80800E68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800E7C;
    // 0x80800E68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800E6C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_80800E70:
    // 0x80800E70: nop

    // 0x80800E74: bltz        $a0, L_80800E64
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800E78: nop
    
            goto L_80800E64;
    }
    // 0x80800E78: nop

L_80800E7C:
    // 0x80800E7C: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x80800E80: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x80800E84: ori         $at, $at, 0xC609
    ctx->r1 = ctx->r1 | 0XC609;
    // 0x80800E88: sll         $t4, $t3, 21
    ctx->r12 = S32(ctx->r11 << 21);
    // 0x80800E8C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800E90: addu        $a0, $t4, $at
    ctx->r4 = ADD32(ctx->r12, ctx->r1);
    // 0x80800E94: jal         0x800C4140
    // 0x80800E98: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800C4140(rdram, ctx);
        goto after_1;
    // 0x80800E98: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800E9C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80800EA0:
    // 0x80800EA0: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x80800EA4: beq         $t5, $zero, L_80800EF8
    if (ctx->r13 == 0) {
        // 0x80800EA8: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80800EF8;
    }
    // 0x80800EA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800EAC: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x80800EB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EB4: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80800EB8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800EBC: nop

    // 0x80800EC0: bc1fl       L_80800EFC
    if (!c1cs) {
        // 0x80800EC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EFC;
    }
    goto skip_2;
    // 0x80800EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800EC8: jal         0x8001210C
    // 0x80800ECC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_2;
    // 0x80800ECC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800ED0: beq         $v0, $zero, L_80800EF8
    if (ctx->r2 == 0) {
        // 0x80800ED4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800EF8;
    }
    // 0x80800ED4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800ED8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2412, 0X1450) << 16);
    // 0x80800EDC: addiu       $t7, $t7, 0x1450
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2412, 0X1450));
    // 0x80800EE0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800EE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800EE8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800EEC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800EF0: jal         0x800BBCB8
    // 0x80800EF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800EF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
L_80800EF8:
    // 0x80800EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EFC:
    // 0x80800EFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F00: jr          $ra
    // 0x80800F04: nop

    return;
    // 0x80800F04: nop

;}
RECOMP_FUNC void func_80800A4C_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A58: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x80800A5C: jal         0x800DA980
    // 0x80800A60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x80800A60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800A64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A68: bne         $v0, $at, L_80800A78
    if (ctx->r2 != ctx->r1) {
        // 0x80800A6C: addiu       $a1, $zero, 0x1098
        ctx->r5 = ADD32(0, 0X1098);
            goto L_80800A78;
    }
    // 0x80800A6C: addiu       $a1, $zero, 0x1098
    ctx->r5 = ADD32(0, 0X1098);
    // 0x80800A70: b           L_80800A78
    // 0x80800A74: addiu       $a1, $zero, 0x1099
    ctx->r5 = ADD32(0, 0X1099);
        goto L_80800A78;
    // 0x80800A74: addiu       $a1, $zero, 0x1099
    ctx->r5 = ADD32(0, 0X1099);
L_80800A78:
    // 0x80800A78: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800A7C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80800A80: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800A84: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800A88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A8C: jal         0x8008A208
    // 0x80800A90: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800A90: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x80800A94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A98: jal         0x80100094
    // 0x80800A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800AA0: lbu         $t8, 0x16($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X16);
    // 0x80800AA4: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80800AA8: sb          $t9, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r25;
    // 0x80800AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AB4: jr          $ra
    // 0x80800AB8: nop

    return;
    // 0x80800AB8: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800008: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8080000C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800010: addiu       $s3, $s3, -0x4C00
    ctx->r19 = ADD32(ctx->r19, -0X4C00);
    // 0x80800014: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080001C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800020: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2674, 0X230) << 16);
    // 0x80800024: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800028: sb          $t6, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r14;
    // 0x8080002C: addiu       $s1, $s1, 0x230
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2674, 0X230));
    // 0x80800030: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800034: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80800038:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: jal         0x808000B0
    // 0x80800040: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800040: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_0:
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x808000D8
    // 0x8080004C: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    gcstatusDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080004C: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    after_1:
    // 0x80800050: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800054: bne         $s0, $s2, L_80800038
    if (ctx->r16 != ctx->r18) {
        // 0x80800058: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80800038;
    }
    // 0x80800058: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8080005C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800060: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800064: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800068: addiu       $t9, $zero, 0x173
    ctx->r25 = ADD32(0, 0X173);
    // 0x8080006C: sb          $t7, 0x9($s3)
    MEM_B(0X9, ctx->r19) = ctx->r15;
    // 0x80800070: sb          $zero, 0xF($s3)
    MEM_B(0XF, ctx->r19) = 0;
    // 0x80800074: sb          $zero, 0x10($s3)
    MEM_B(0X10, ctx->r19) = 0;
    // 0x80800078: sb          $t8, 0x11($s3)
    MEM_B(0X11, ctx->r19) = ctx->r24;
    // 0x8080007C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80800080: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: jr          $ra
    // 0x80800094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chweather_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859F0: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859F0);
    return;
    // 0x800859F4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8009EB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EB90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EB94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EB98: jal         0x8009EC3C
    // 0x8009EB9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8009EC3C(rdram, ctx);
        goto after_0;
    // 0x8009EB9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009EBA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EBA4: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, 0X7040);
    // 0x8009EBA8: lbu         $t6, 0x20($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X20);
    // 0x8009EBAC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    // 0x8009EBB0: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x8009EBB4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009EBB8: jal         0x8009EC60
    // 0x8009EBBC: sb          $t7, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r15;
    func_8009EC60(rdram, ctx);
        goto after_1;
    // 0x8009EBBC: sb          $t7, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r15;
    after_1:
    // 0x8009EBC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EBC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EBC8: jr          $ra
    // 0x8009EBCC: nop

    return;
    // 0x8009EBCC: nop

;}
RECOMP_FUNC void func_808001F0_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001F4: bnel        $a1, $at, L_80800208
    if (ctx->r5 != ctx->r1) {
        // 0x808001F8: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_80800208;
    }
    goto skip_0;
    // 0x808001F8: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x808001FC: jr          $ra
    // 0x80800200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800204: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_80800208:
    // 0x80800208: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8080020C: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x80800210: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800214: jr          $ra
    // 0x80800218: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800218: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808005F4_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800604: jal         0x8009C128
    // 0x80800608: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800608: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800614: jal         0x80084FC8
    // 0x80800618: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800618: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800620: addiu       $a1, $zero, 0x413
    ctx->r5 = ADD32(0, 0X413);
    // 0x80800624: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800628: jal         0x8009DB04
    // 0x8080062C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_2;
    // 0x8080062C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_2:
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x808004F8
    // 0x80800638: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_808004F8_bstnt(rdram, ctx);
        goto after_3;
    // 0x80800638: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x8080030C
    // 0x80800644: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8080030C_bstnt(rdram, ctx);
        goto after_4;
    // 0x80800644: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x808002AC
    // 0x80800650: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_808002AC_bstnt(rdram, ctx);
        goto after_5;
    // 0x80800650: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080065C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800660: jr          $ra
    // 0x80800664: nop

    return;
    // 0x80800664: nop

;}
RECOMP_FUNC void func_80096254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096254: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096258: jr          $ra
    // 0x8009625C: sw          $a1, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->r5;
    return;
    // 0x8009625C: sw          $a1, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void glrtc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800004: addiu       $t6, $a0, 0x3
    ctx->r14 = ADD32(ctx->r4, 0X3);
    // 0x80800008: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800010: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800014: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800018: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080001C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800020: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800024: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800028: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080002C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800030: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80800034: lbu         $s1, 0x1($a0)
    ctx->r17 = MEM_BU(ctx->r4, 0X1);
    // 0x80800038: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8080003C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800040: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80800044: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800048: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080004C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80800050: blez        $t8, L_80800140
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800054: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80800140;
    }
    // 0x80800054: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800058: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8080005C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80800060: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x80800064: lbu         $t9, 0x1($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X1);
L_80800068:
    // 0x80800068: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080006C: blezl       $t9, L_80800130
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800070: lbu         $t8, 0x2($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X2);
            goto L_80800130;
    }
    goto skip_0;
    // 0x80800070: lbu         $t8, 0x2($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X2);
    skip_0:
    // 0x80800074: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
L_80800078:
    // 0x80800078: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x8080007C: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800080: nop
    
            goto L_8080009C;
    }
    // 0x80800080: nop

    // 0x80800084: beq         $v0, $s7, L_808000C8
    if (ctx->r2 == ctx->r23) {
        // 0x80800088: sll         $t6, $s3, 2
        ctx->r14 = S32(ctx->r19 << 2);
            goto L_808000C8;
    }
    // 0x80800088: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8080008C: beq         $v0, $fp, L_808000F4
    if (ctx->r2 == ctx->r30) {
        // 0x80800090: sll         $t2, $s3, 2
        ctx->r10 = S32(ctx->r19 << 2);
            goto L_808000F4;
    }
    // 0x80800090: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80800094: b           L_8080011C
    // 0x80800098: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
        goto L_8080011C;
    // 0x80800098: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_8080009C:
    // 0x8080009C: multu       $t0, $s1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000A0: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x808000A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808000A8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808000AC: mflo        $t1
    ctx->r9 = lo;
    // 0x808000B0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x808000B4: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x808000B8: jal         0x80800170
    // 0x808000BC: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    func_80800170_glrtc(rdram, ctx);
        goto after_0;
    // 0x808000BC: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    after_0:
    // 0x808000C0: b           L_8080011C
    // 0x808000C4: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
        goto L_8080011C;
    // 0x808000C4: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_808000C8:
    // 0x808000C8: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000CC: sll         $t1, $s0, 4
    ctx->r9 = S32(ctx->r16 << 4);
    // 0x808000D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808000D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808000D8: mflo        $t7
    ctx->r15 = lo;
    // 0x808000DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808000E0: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x808000E4: jal         0x8080031C
    // 0x808000E8: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    func_8080031C_glrtc(rdram, ctx);
        goto after_1;
    // 0x808000E8: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_1:
    // 0x808000EC: b           L_8080011C
    // 0x808000F0: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
        goto L_8080011C;
    // 0x808000F0: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_808000F4:
    // 0x808000F4: multu       $t2, $s1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000F8: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x808000FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800100: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800104: mflo        $t4
    ctx->r12 = lo;
    // 0x80800108: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8080010C: addu        $t5, $s4, $t3
    ctx->r13 = ADD32(ctx->r20, ctx->r11);
    // 0x80800110: jal         0x80800474
    // 0x80800114: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    func_80800474_glrtc(rdram, ctx);
        goto after_2;
    // 0x80800114: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    after_2:
    // 0x80800118: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_8080011C:
    // 0x8080011C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800120: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800124: bnel        $at, $zero, L_80800078
    if (ctx->r1 != 0) {
        // 0x80800128: lbu         $v0, 0x0($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X0);
            goto L_80800078;
    }
    goto skip_1;
    // 0x80800128: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    skip_1:
    // 0x8080012C: lbu         $t8, 0x2($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X2);
L_80800130:
    // 0x80800130: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800134: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800138: bnel        $at, $zero, L_80800068
    if (ctx->r1 != 0) {
        // 0x8080013C: lbu         $t9, 0x1($s6)
        ctx->r25 = MEM_BU(ctx->r22, 0X1);
            goto L_80800068;
    }
    goto skip_2;
    // 0x8080013C: lbu         $t9, 0x1($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X1);
    skip_2:
L_80800140:
    // 0x80800140: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080014C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800150: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800154: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800158: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080015C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800160: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800164: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800168: jr          $ra
    // 0x8080016C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8080016C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800DA054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA054: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DA058: addiu       $t7, $t7, -0x3890
    ctx->r15 = ADD32(ctx->r15, -0X3890);
    // 0x800DA05C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800DA060: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800DA064: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800DA068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA070: bne         $a3, $zero, L_800DA094
    if (ctx->r7 != 0) {
        // 0x800DA074: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800DA094;
    }
    // 0x800DA074: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DA078: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800DA07C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DA080: jal         0x8001ACEC
    // 0x800DA084: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x800DA084: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800DA088: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA08C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800DA090: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800DA094:
    // 0x800DA094: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800DA098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DA09C: jal         0x8001BCF8
    // 0x800DA0A0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    rare_memset(rdram, ctx);
        goto after_1;
    // 0x800DA0A0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800DA0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA0A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DA0AC: jr          $ra
    // 0x800DA0B0: nop

    return;
    // 0x800DA0B0: nop

;}
RECOMP_FUNC void func_80800000_cheggnormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800004: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8080000C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800010: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80800014: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80800018: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8080001C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800020: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800024: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800028: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080002C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800030: jal         0x80100094
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: jal         0x800D8FF8
    // 0x8080003C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80800040: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80800044: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2124, 0X4C0) << 16);
    // 0x80800048: lwc1        $f12, 0x30($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X30);
    // 0x8080004C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800050: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800054: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80800058: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x8080005C: swc1        $f6, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f6.u32l;
    // 0x80800060: lwc1        $f8, 0x4C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2124, 0X4C0));
    // 0x80800064: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800068: jal         0x800F10B4
    // 0x8080006C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x8080006C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800070: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80800074: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80800078: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8080007C: addiu       $s4, $s1, 0x4
    ctx->r20 = ADD32(ctx->r17, 0X4);
    // 0x80800080: c.le.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl <= ctx->f26.fl;
    // 0x80800084: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80800088: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x8080008C: bc1fl       L_80800168
    if (!c1cs) {
        // 0x80800090: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80800168;
    }
    goto skip_0;
    // 0x80800090: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80800094: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800098: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080009C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808000A0: addiu       $s0, $sp, 0x74
    ctx->r16 = ADD32(ctx->r29, 0X74);
    // 0x808000A4: add.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f24.fl;
L_808000A8:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808000B0: jal         0x800EE7F8
    // 0x808000B4: swc1        $f10, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808000B4: swc1        $f10, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f10.u32l;
    after_3:
    // 0x808000B8: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x808000BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000C0: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808000C4: bgez        $t8, L_8080011C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000C8: nop
    
            goto L_8080011C;
    }
    // 0x808000C8: nop

    // 0x808000CC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808000D0: jal         0x800EFA20
    // 0x808000D4: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x808000D4: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    after_4:
    // 0x808000D8: jal         0x800DC0C0
    // 0x808000DC: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x808000DC: nop

    after_5:
    // 0x808000E0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808000EC: bc1f        L_8080010C
    if (!c1cs) {
        // 0x808000F0: nop
    
            goto L_8080010C;
    }
    // 0x808000F0: nop

    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808000FC: jal         0x80088A98
    // 0x80800100: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800100: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    after_6:
    // 0x80800104: b           L_80800154
    // 0x80800108: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
        goto L_80800154;
    // 0x80800108: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
L_8080010C:
    // 0x8080010C: jal         0x80088AA0
    // 0x80800110: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800110: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    after_7:
    // 0x80800114: b           L_80800154
    // 0x80800118: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
        goto L_80800154;
    // 0x80800118: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
L_8080011C:
    // 0x8080011C: jal         0x800DC0C0
    // 0x80800120: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x80800120: nop

    after_8:
    // 0x80800124: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: bc1f        L_80800148
    if (!c1cs) {
        // 0x80800130: nop
    
            goto L_80800148;
    }
    // 0x80800130: nop

    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80088A70
    // 0x8080013C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x8080013C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_9:
    // 0x80800140: b           L_80800154
    // 0x80800144: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
        goto L_80800154;
    // 0x80800144: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
L_80800148:
    // 0x80800148: jal         0x80088A68
    // 0x8080014C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    _fxegg_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x8080014C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_10:
    // 0x80800150: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
L_80800154:
    // 0x80800154: c.le.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl <= ctx->f26.fl;
    // 0x80800158: nop

    // 0x8080015C: bc1tl       L_808000A8
    if (c1cs) {
        // 0x80800160: add.s       $f10, $f2, $f24
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f24.fl;
            goto L_808000A8;
    }
    goto skip_1;
    // 0x80800160: add.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f24.fl;
    skip_1:
    // 0x80800164: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80800168:
    // 0x80800168: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080016C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800170: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800174: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800178: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8080017C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800180: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800184: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800188: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8080018C: jr          $ra
    // 0x80800190: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800190: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80800AF0_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800AFC: jal         0x800848D8
    // 0x80800B00: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _badrone_entrypoint_30(rdram, ctx);
        goto after_0;
    // 0x80800B00: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800B04: beq         $v0, $zero, L_80800B10
    if (ctx->r2 == 0) {
        // 0x80800B08: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800B10;
    }
    // 0x80800B08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800B0C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800B10:
    // 0x80800B10: jal         0x80082FE8
    // 0x80800B14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800B14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800B18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B1C: jal         0x8009E5C8
    // 0x80800B20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800B20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B2C: jr          $ra
    // 0x80800B30: nop

    return;
    // 0x80800B30: nop

;}
RECOMP_FUNC void func_80800180_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800190: bne         $a1, $at, L_808001B0
    if (ctx->r5 != ctx->r1) {
        // 0x80800194: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808001B0;
    }
    // 0x80800194: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800198: jal         0x80085710
    // 0x8080019C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080019C: nop

    after_0:
    // 0x808001A0: jal         0x800FFAB0
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808001A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001A8: b           L_808001B8
    // 0x808001AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001B8;
    // 0x808001AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001B0:
    // 0x808001B0: b           L_808001B8
    // 0x808001B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001B8;
    // 0x808001B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001B8:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800F9214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F921C: jal         0x800F6720
    // 0x800F9220: nop

    func_800F6720(rdram, ctx);
        goto after_0;
    // 0x800F9220: nop

    after_0:
    // 0x800F9224: beq         $v0, $zero, L_800F9234
    if (ctx->r2 == 0) {
        // 0x800F9228: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F9234;
    }
    // 0x800F9228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F922C: b           L_800F9238
    // 0x800F9230: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800F9238;
    // 0x800F9230: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800F9234:
    // 0x800F9234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F9238:
    // 0x800F9238: jr          $ra
    // 0x800F923C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F923C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8010ACE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010ACE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010ACE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010ACE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010ACEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010ACF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010ACF4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010ACF8: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x8010ACFC: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x8010AD00: beq         $v1, $zero, L_8010AD28
    if (ctx->r3 == 0) {
        // 0x8010AD04: addiu       $a0, $v1, -0x1
        ctx->r4 = ADD32(ctx->r3, -0X1);
            goto L_8010AD28;
    }
    // 0x8010AD04: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x8010AD08: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x8010AD0C: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x8010AD10: jal         0x800CC6CC
    // 0x8010AD14: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC6CC(rdram, ctx);
        goto after_0;
    // 0x8010AD14: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x8010AD18: bnel        $v0, $zero, L_8010AD2C
    if (ctx->r2 != 0) {
        // 0x8010AD1C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010AD2C;
    }
    goto skip_0;
    // 0x8010AD1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8010AD20: b           L_8010AD3C
    // 0x8010AD24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010AD3C;
    // 0x8010AD24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010AD28:
    // 0x8010AD28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8010AD2C:
    // 0x8010AD2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AD30: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8010AD34: jal         0x8010AAC0
    // 0x8010AD38: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8010AAC0(rdram, ctx);
        goto after_1;
    // 0x8010AD38: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_8010AD3C:
    // 0x8010AD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AD44: jr          $ra
    // 0x8010AD48: nop

    return;
    // 0x8010AD48: nop

;}
RECOMP_FUNC void func_80800064_suegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800070: jal         0x80100094
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800078: jal         0x800D8FF8
    // 0x8080007C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080007C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800080: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800084: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800088: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8080008C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800090: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800094: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800098: nop

    // 0x8080009C: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000A0: jal         0x800F13C4
    // 0x808000A4: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x808000A4: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    after_2:
    // 0x808000A8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808000AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x808000B4: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x808000B8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x808000BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808000C0: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x808000C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x808000C8: mfhi        $t2
    ctx->r10 = hi;
    // 0x808000CC: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x808000D0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x808000D4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x808000D8: andi        $t5, $t4, 0xF8
    ctx->r13 = ctx->r12 & 0XF8;
    // 0x808000DC: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x808000E0: bne         $t1, $zero, L_808000EC
    if (ctx->r9 != 0) {
        // 0x808000E4: nop
    
            goto L_808000EC;
    }
    // 0x808000E4: nop

    // 0x808000E8: break       7
    do_break(2155872488);
L_808000EC:
    // 0x808000EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000F0: bne         $t1, $at, L_80800104
    if (ctx->r9 != ctx->r1) {
        // 0x808000F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800104;
    }
    // 0x808000F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000F8: bne         $t0, $at, L_80800104
    if (ctx->r8 != ctx->r1) {
        // 0x808000FC: nop
    
            goto L_80800104;
    }
    // 0x808000FC: nop

    // 0x80800100: break       6
    do_break(2155872512);
L_80800104:
    // 0x80800104: andi        $t7, $t6, 0xFF07
    ctx->r15 = ctx->r14 & 0XFF07;
    // 0x80800108: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8080010C: sb          $t8, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r24;
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_80800890_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080089C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808008A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808008A8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808008AC: jal         0x801084B0
    // 0x808008B0: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x808008B0: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    after_0:
    // 0x808008B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808008B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008BC: jal         0x80100094
    // 0x808008C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808008C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808008C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808008C8: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x808008CC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808008D0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808008D4: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808008D8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808008DC: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x808008E0: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x808008E4: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x808008E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808008EC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x808008F0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808008F4: jal         0x800EE7F8
    // 0x808008F8: addu        $a1, $v0, $t4
    ctx->r5 = ADD32(ctx->r2, ctx->r12);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808008F8: addu        $a1, $v0, $t4
    ctx->r5 = ADD32(ctx->r2, ctx->r12);
    after_2:
    // 0x808008FC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80800900: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1644, 0X9A8) << 16);
    // 0x80800904: addiu       $t1, $t1, 0x9A8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1644, 0X9A8));
    // 0x80800908: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8080090C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    // 0x80800910: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800914: lhu         $t9, 0x76($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X76);
    // 0x80800918: srl         $t8, $t9, 7
    ctx->r24 = S32(U32(ctx->r25) >> 7);
    // 0x8080091C: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x80800920: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80800924: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800928: jal         0x800DC178
    // 0x8080092C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x8080092C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x80800930: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800934: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800938: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080093C: beq         $v0, $zero, L_80800954
    if (ctx->r2 == 0) {
        // 0x80800940: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800954;
    }
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: beq         $v0, $at, L_80800964
    if (ctx->r2 == ctx->r1) {
        // 0x80800948: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800964;
    }
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: b           L_80800970
    // 0x80800950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800970;
    // 0x80800950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800954:
    // 0x80800954: jal         0x8008A4B0
    // 0x80800958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800958: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080095C: b           L_80800970
    // 0x80800960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800970;
    // 0x80800960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800964:
    // 0x80800964: jal         0x80800570
    // 0x80800968: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800570_chjigsawbitcont(rdram, ctx);
        goto after_5;
    // 0x80800968: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x8080096C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800970:
    // 0x80800970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800974: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void chfootwear_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2448, 0X818) << 16);
    // 0x808006A0: jr          $ra
    // 0x808006A4: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X818));
    return;
    // 0x808006A4: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X818));
;}
RECOMP_FUNC void chstatueboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801688: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1312, 0X27E8) << 16);
    // 0x8080168C: jr          $ra
    // 0x80801690: addiu       $v0, $v0, 0x27E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1312, 0X27E8));
    return;
    // 0x80801690: addiu       $v0, $v0, 0x27E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1312, 0X27E8));
;}
RECOMP_FUNC void func_808014C0_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808014CC: jal         0x80100094
    // 0x808014D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014D4: beq         $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x808014D8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808014F0;
    }
    // 0x808014D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808014DC: jal         0x80100094
    // 0x808014E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808014E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808014E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808014E8: jal         0x8008A058
    // 0x808014EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808014EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_808014F0:
    // 0x808014F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014F8: jr          $ra
    // 0x808014FC: nop

    return;
    // 0x808014FC: nop

;}
RECOMP_FUNC void func_808008FC_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800908: jal         0x80100094
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800910: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800914: jal         0x8008A058
    // 0x80800918: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800918: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8080091C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800924: jr          $ra
    // 0x80800928: nop

    return;
    // 0x80800928: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004AC: jr          $ra
    // 0x808004B0: sh          $a0, 0x75E8($at)
    MEM_H(0X75E8, ctx->r1) = ctx->r4;
    return;
    // 0x808004B0: sh          $a0, 0x75E8($at)
    MEM_H(0X75E8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _glgamedata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088598: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x80088598);
    return;
    // 0x8008859C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bstwirl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800298: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(424, 0X2C0) << 16);
    // 0x8080029C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002A0: jr          $ra
    // 0x808002A4: lw          $v0, 0x2C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(424, 0X2C0));
    return;
    // 0x808002A4: lw          $v0, 0x2C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(424, 0X2C0));
;}
RECOMP_FUNC void _bsmummove_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838B8: syscall     78
    recomp_syscall_handler(rdram, ctx, 0x800838B8);
    return;
    // 0x800838BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
