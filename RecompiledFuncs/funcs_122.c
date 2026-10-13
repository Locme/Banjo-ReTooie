#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chfantasycannon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876B8: syscall     606
    recomp_syscall_handler(rdram, ctx, 0x800876B8);
    return;
    // 0x800876BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802124_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080212C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802134: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x80802138: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080213C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80802140: beq         $v0, $zero, L_80802164
    if (ctx->r2 == 0) {
        // 0x80802144: addiu       $a1, $zero, 0x29
        ctx->r5 = ADD32(0, 0X29);
            goto L_80802164;
    }
    // 0x80802144: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x80802148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080214C: beq         $v0, $at, L_80802174
    if (ctx->r2 == ctx->r1) {
        // 0x80802150: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802174;
    }
    // 0x80802150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802154: beql        $v0, $at, L_80802180
    if (ctx->r2 == ctx->r1) {
        // 0x80802158: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_80802180;
    }
    goto skip_0;
    // 0x80802158: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8080215C: b           L_80802190
    // 0x80802160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802190;
    // 0x80802160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802164:
    // 0x80802164: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80802168: jal         0x800856B0
    // 0x8080216C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080216C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802170: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80802174:
    // 0x80802174: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80802178: sw          $t6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r14;
    // 0x8080217C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80802180:
    // 0x80802180: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80802184: jal         0x800856D0
    // 0x80802188: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80802188: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080218C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802190:
    // 0x80802190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802194: jr          $ra
    // 0x80802198: nop

    return;
    // 0x80802198: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B98: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B98);
    return;
    // 0x80087B9C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void vpwibble_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800520: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800524: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800528: addu        $s2, $t6, $a2
    ctx->r18 = ADD32(ctx->r14, ctx->r6);
    // 0x8080052C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800530: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800534: sltu        $at, $a2, $s2
    ctx->r1 = ctx->r6 < ctx->r18 ? 1 : 0;
    // 0x80800538: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080053C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800540: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800544: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800548: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080054C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800550: beq         $at, $zero, L_808006C4
    if (ctx->r1 == 0) {
        // 0x80800554: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_808006C4;
    }
    // 0x80800554: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800558: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8080055C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80800560: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
    // 0x80800564: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800568:
    // 0x80800568: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080056C: jal         0x808003F0
    // 0x80800570: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_808003F0_vpwibble(rdram, ctx);
        goto after_0;
    // 0x80800570: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x80800574: lbu         $v0, 0x31($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X31);
    // 0x80800578: bne         $s4, $v0, L_808005A4
    if (ctx->r20 != ctx->r2) {
        // 0x8080057C: nop
    
            goto L_808005A4;
    }
    // 0x8080057C: nop

    // 0x80800580: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x80800584: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800588: nop

    // 0x8080058C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800590: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800594: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800598: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8080059C: b           L_808005D0
    // 0x808005A0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_808005D0;
    // 0x808005A0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_808005A4:
    // 0x808005A4: bnel        $s5, $v0, L_808005D4
    if (ctx->r21 != ctx->r2) {
        // 0x808005A8: lbu         $t3, 0x32($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X32);
            goto L_808005D4;
    }
    goto skip_0;
    // 0x808005A8: lbu         $t3, 0x32($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X32);
    skip_0:
    // 0x808005AC: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x808005B0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x808005B4: nop

    // 0x808005B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808005BC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808005C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808005C4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x808005C8: nop

    // 0x808005CC: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_808005D0:
    // 0x808005D0: lbu         $t3, 0x32($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X32);
L_808005D4:
    // 0x808005D4: beql        $t3, $zero, L_80800654
    if (ctx->r11 == 0) {
        // 0x808005D8: lbu         $t5, 0x33($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X33);
            goto L_80800654;
    }
    goto skip_1;
    // 0x808005D8: lbu         $t5, 0x33($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X33);
    skip_1:
    // 0x808005DC: lbu         $t4, 0x30($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X30);
    // 0x808005E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808005E4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x808005E8: bgez        $t4, L_808005FC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808005EC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808005FC;
    }
    // 0x808005EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808005F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005F4: nop

    // 0x808005F8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_808005FC:
    // 0x808005FC: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80800600: lbu         $t6, 0xC($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XC);
    // 0x80800604: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x80800608: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8080060C: lbu         $t2, 0xE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XE);
    // 0x80800610: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800614: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800618: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8080061C: nop

    // 0x80800620: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800624: mflo        $t7
    ctx->r15 = lo;
    // 0x80800628: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8080062C: sb          $t8, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r24;
    // 0x80800630: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800634: mflo        $t0
    ctx->r8 = lo;
    // 0x80800638: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x8080063C: sb          $t1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r9;
    // 0x80800640: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800644: mflo        $t3
    ctx->r11 = lo;
    // 0x80800648: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x8080064C: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
    // 0x80800650: lbu         $t5, 0x33($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X33);
L_80800654:
    // 0x80800654: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800658: beql        $t5, $zero, L_808006B8
    if (ctx->r13 == 0) {
        // 0x8080065C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_808006B8;
    }
    goto skip_2;
    // 0x8080065C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_2:
    // 0x80800660: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80800664: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80800668: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8080066C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800670: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800674: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800678: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8080067C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800680: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800684: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800688: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8080068C: nop

    // 0x80800690: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    // 0x80800694: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80800698: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080069C: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808006A0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808006A4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808006A8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x808006AC: nop

    // 0x808006B0: sh          $t1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r9;
    // 0x808006B4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_808006B8:
    // 0x808006B8: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808006BC: bnel        $at, $zero, L_80800568
    if (ctx->r1 != 0) {
        // 0x808006C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800568;
    }
    goto skip_3;
    // 0x808006C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_808006C4:
    // 0x808006C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808006C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808006D8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808006DC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808006E0: jr          $ra
    // 0x808006E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808006E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808006E8: nop

    // 0x808006EC: nop

;}
RECOMP_FUNC void func_80013224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013224: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80013228: addiu       $v1, $v1, -0x3390
    ctx->r3 = ADD32(ctx->r3, -0X3390);
    // 0x8001322C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80013230: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013234: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013238: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001323C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80013240: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80013244: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80013248: sw          $a1, 0x69CC($at)
    MEM_W(0X69CC, ctx->r1) = ctx->r5;
    // 0x8001324C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80013250: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013254: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013258: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001325C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80013260: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80013264: sw          $a2, 0x69D0($at)
    MEM_W(0X69D0, ctx->r1) = ctx->r6;
    // 0x80013268: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8001326C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80013270: jal         0x8002E660
    // 0x80013274: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80013274: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80013278: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8001327C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80013280: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x80013284: addiu       $t1, $t1, 0x695C
    ctx->r9 = ADD32(ctx->r9, 0X695C);
    // 0x80013288: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8001328C: addiu       $a0, $a0, 0x6940
    ctx->r4 = ADD32(ctx->r4, 0X6940);
    // 0x80013290: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80013294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001329C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800132A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800132A4: jal         0x8002E450
    // 0x800132A8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x800132A8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_1:
    // 0x800132AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800132B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800132B4: jr          $ra
    // 0x800132B8: nop

    return;
    // 0x800132B8: nop

;}
RECOMP_FUNC void _chscorepoints_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086458: syscall     325
    recomp_syscall_handler(rdram, ctx, 0x80086458);
    return;
    // 0x8008645C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080349C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080349C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x808034A0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x808034A4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808034A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808034AC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x808034B0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x808034B4: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808034B8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808034BC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x808034C0: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808034C4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808034C8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808034CC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808034D0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808034D4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808034D8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808034DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808034E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808034E4: jal         0x80100094
    // 0x808034E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808034E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808034EC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808034F0: jal         0x80106790
    // 0x808034F4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808034F4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x808034F8: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x808034FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803500: jal         0x80100094
    // 0x80803504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80803504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80803508: lbu         $t6, 0xC2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC2);
    // 0x8080350C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80803510: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80803514: blez        $t6, L_808036E4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80803518: lui         $at, 0x4282
        ctx->r1 = S32(0X4282 << 16);
            goto L_808036E4;
    }
    // 0x80803518: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8080351C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80803520: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803524: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80803528: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080352C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80803530: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CBC) << 16);
    // 0x80803534: lwc1        $f24, 0x4CBC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CBC));
    // 0x80803538: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080353C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80803540: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80803544: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80803548: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x8080354C: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
L_80803550:
    // 0x80803550: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80803554: beql        $s3, $t8, L_808036D4
    if (ctx->r19 == ctx->r24) {
        // 0x80803558: lbu         $t9, 0xC2($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0XC2);
            goto L_808036D4;
    }
    goto skip_0;
    // 0x80803558: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
    skip_0:
    // 0x8080355C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803560: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80803564: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80803568: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080356C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80803570: nop

    // 0x80803574: bc1t        L_80803598
    if (c1cs) {
        // 0x80803578: nop
    
            goto L_80803598;
    }
    // 0x80803578: nop

    // 0x8080357C: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x80803580: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803584: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80803588: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x8080358C: nop

    // 0x80803590: bc1tl       L_808036D4
    if (c1cs) {
        // 0x80803594: lbu         $t9, 0xC2($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0XC2);
            goto L_808036D4;
    }
    goto skip_1;
    // 0x80803594: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
    skip_1:
L_80803598:
    // 0x80803598: jal         0x8080000C
    // 0x8080359C: addiu       $s4, $s0, 0x4
    ctx->r20 = ADD32(ctx->r16, 0X4);
    func_8080000C_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x8080359C: addiu       $s4, $s0, 0x4
    ctx->r20 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808035A0: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808035A4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808035A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808035AC: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x808035B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808035B4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808035B8: jal         0x800EEB9C
    // 0x808035BC: nop

    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x808035BC: nop

    after_4:
    // 0x808035C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808035C4: jal         0x800EF04C
    // 0x808035C8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808035C8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x808035CC: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x808035D0: addiu       $s5, $s1, 0x4
    ctx->r21 = ADD32(ctx->r17, 0X4);
    // 0x808035D4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x808035D8: jal         0x800F0064
    // 0x808035DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F0064(rdram, ctx);
        goto after_6;
    // 0x808035DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x808035E0: beql        $v0, $zero, L_80803640
    if (ctx->r2 == 0) {
        // 0x808035E4: lwc1        $f8, 0x48($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80803640;
    }
    goto skip_2;
    // 0x808035E4: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    skip_2:
    // 0x808035E8: swc1        $f28, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f28.u32l;
    // 0x808035EC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808035F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808035F4: sub.s       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f30.fl;
    // 0x808035F8: jal         0x8080460C
    // 0x808035FC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x808035FC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x80803600: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80803604: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803608: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8080360C: nop

    // 0x80803610: bc1fl       L_8080363C
    if (!c1cs) {
        // 0x80803614: swc1        $f20, 0x14($s6)
        MEM_W(0X14, ctx->r22) = ctx->f20.u32l;
            goto L_8080363C;
    }
    goto skip_3;
    // 0x80803614: swc1        $f20, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f20.u32l;
    skip_3:
    // 0x80803618: jal         0x8080458C
    // 0x8080361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_8;
    // 0x8080361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80803620: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80803624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803628: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080362C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80803630: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80803634: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80803638: swc1        $f20, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f20.u32l;
L_8080363C:
    // 0x8080363C: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_80803640:
    // 0x80803640: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80803644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803648: sub.s       $f16, $f8, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x8080364C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80803650: jal         0x800EEB9C
    // 0x80803654: nop

    func_800EEB9C(rdram, ctx);
        goto after_9;
    // 0x80803654: nop

    after_9:
    // 0x80803658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080365C: jal         0x800EF04C
    // 0x80803660: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80803660: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x80803664: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80803668: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080366C: jal         0x800F0064
    // 0x80803670: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800F0064(rdram, ctx);
        goto after_11;
    // 0x80803670: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_11:
    // 0x80803674: beql        $v0, $zero, L_808036D4
    if (ctx->r2 == 0) {
        // 0x80803678: lbu         $t9, 0xC2($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0XC2);
            goto L_808036D4;
    }
    goto skip_4;
    // 0x80803678: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
    skip_4:
    // 0x8080367C: swc1        $f28, 0x10($s6)
    MEM_W(0X10, ctx->r22) = ctx->f28.u32l;
    // 0x80803680: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803688: add.s       $f18, $f4, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x8080368C: jal         0x8080460C
    // 0x80803690: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_12;
    // 0x80803690: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_12:
    // 0x80803694: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80803698: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080369C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x808036A0: nop

    // 0x808036A4: bc1fl       L_808036D0
    if (!c1cs) {
        // 0x808036A8: swc1        $f20, 0x14($s6)
        MEM_W(0X14, ctx->r22) = ctx->f20.u32l;
            goto L_808036D0;
    }
    goto skip_5;
    // 0x808036A8: swc1        $f20, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f20.u32l;
    skip_5:
    // 0x808036AC: jal         0x8080458C
    // 0x808036B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_13;
    // 0x808036B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808036B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808036B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808036BC: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808036C0: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808036C4: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x808036C8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x808036CC: swc1        $f20, 0x14($s6)
    MEM_W(0X14, ctx->r22) = ctx->f20.u32l;
L_808036D0:
    // 0x808036D0: lbu         $t9, 0xC2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XC2);
L_808036D4:
    // 0x808036D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808036D8: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808036DC: bnel        $at, $zero, L_80803550
    if (ctx->r1 != 0) {
        // 0x808036E0: lw          $t7, 0x6C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X6C);
            goto L_80803550;
    }
    goto skip_6;
    // 0x808036E0: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    skip_6:
L_808036E4:
    // 0x808036E4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x808036E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808036EC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808036F0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808036F4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808036F8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808036FC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80803700: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80803704: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80803708: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8080370C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80803710: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80803714: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80803718: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8080371C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80803720: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80803724: jr          $ra
    // 0x80803728: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80803728: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void cheel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1792, 0X1644) << 16);
    // 0x808014E4: jr          $ra
    // 0x808014E8: addiu       $v0, $v0, 0x1644
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1792, 0X1644));
    return;
    // 0x808014E8: addiu       $v0, $v0, 0x1644
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1792, 0X1644));
    // 0x808014EC: nop

;}
RECOMP_FUNC void chfriesstand_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(940, 0XFA0) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xFA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XFA0));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xFA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XFA0));
;}
RECOMP_FUNC void func_800956B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800956B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800956BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800956C0: jal         0x8009C128
    // 0x800956C4: lw          $a1, 0x7C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X7C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800956C4: lw          $a1, 0x7C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X7C);
    after_0:
    // 0x800956C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800956CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800956D0: jr          $ra
    // 0x800956D4: nop

    return;
    // 0x800956D4: nop

    // 0x800956D8: nop

    // 0x800956DC: nop

;}
RECOMP_FUNC void func_800A93F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A93F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A93FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9400: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A9404: jr          $ra
    // 0x800A9408: lw          $v0, 0x7708($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7708);
    return;
    // 0x800A9408: lw          $v0, 0x7708($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7708);
;}
RECOMP_FUNC void _bsfirstp_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084358: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084358);
    return;
    // 0x8008435C: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085658: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085658);
    return;
    // 0x8008565C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void _chbouncycastle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EA8: syscall     255
    recomp_syscall_handler(rdram, ctx, 0x80085EA8);
    return;
    // 0x80085EAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void basub_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808007F8: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x808007FC: lbu         $v1, 0x5E($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5E);
    // 0x80800800: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80800804: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80800808: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8080080C: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80800810: beq         $at, $zero, L_8080082C
    if (ctx->r1 == 0) {
        // 0x80800814: nop
    
            goto L_8080082C;
    }
    // 0x80800814: nop

    // 0x80800818: sb          $t8, 0x5E($v0)
    MEM_B(0X5E, ctx->r2) = ctx->r24;
    // 0x8080081C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XBF0) << 16);
    // 0x80800820: lwc1        $f4, 0xBF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XBF0));
    // 0x80800824: lw          $t9, 0x130($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X130);
    // 0x80800828: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
L_8080082C:
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void bsbfly_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A6C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801A70: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1DB8) << 16);
    // 0x80801A74: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801A78: jr          $ra
    // 0x80801A7C: lw          $v0, 0x1DB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DB8));
    return;
    // 0x80801A7C: lw          $v0, 0x1DB8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DB8));
;}
RECOMP_FUNC void _batimer_isAt_rising(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085310: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085310);
    return;
    // 0x80085314: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800684_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080068C: jal         0x80800208
    // 0x80800690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800208_bscarry(rdram, ctx);
        goto after_0;
    // 0x80800690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800694: jal         0x80082FE0
    // 0x80800698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080069C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006A4: jr          $ra
    // 0x808006A8: nop

    return;
    // 0x808006A8: nop

;}
RECOMP_FUNC void func_80801DA0_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801DA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801DB0: jal         0x80100094
    // 0x80801DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801DB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801DBC: addiu       $a0, $zero, 0x45E
    ctx->r4 = ADD32(0, 0X45E);
    // 0x80801DC0: jal         0x801084B0
    // 0x80801DC4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80801DC4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80801DC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801DCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801DD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DD4: jal         0x80102FDC
    // 0x80801DD8: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80801DD8: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_2:
    // 0x80801DDC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801DE0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801DE4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80801DE8: sw          $t8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r24;
    // 0x80801DEC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801DF0: jal         0x80088848
    // 0x80801DF4: sw          $t9, 0x9C($t0)
    MEM_W(0X9C, ctx->r8) = ctx->r25;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80801DF4: sw          $t9, 0x9C($t0)
    MEM_W(0X9C, ctx->r8) = ctx->r25;
    after_3:
    // 0x80801DF8: beq         $v0, $zero, L_80801E10
    if (ctx->r2 == 0) {
        // 0x80801DFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E10;
    }
    // 0x80801DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E00: jal         0x80102424
    // 0x80801E04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80801E04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80801E08: b           L_80801E2C
    // 0x80801E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801E2C;
    // 0x80801E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E10:
    // 0x80801E10: jal         0x800DA298
    // 0x80801E14: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80801E14: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    after_5:
    // 0x80801E18: beq         $v0, $zero, L_80801E28
    if (ctx->r2 == 0) {
        // 0x80801E1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E28;
    }
    // 0x80801E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E20: jal         0x80102424
    // 0x80801E24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80801E24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_80801E28:
    // 0x80801E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E2C:
    // 0x80801E2C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80801E30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E34: jr          $ra
    // 0x80801E38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801E38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080031C_glrtc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800320: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800328: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080032C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800330: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800334: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800338: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080033C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800340: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800344: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x80800348: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8080034C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800350: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800354: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80800358: jal         0x80031BF0
    // 0x8080035C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _bcopy(rdram, ctx);
        goto after_0;
    // 0x8080035C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80800360: lhu         $v0, 0x64($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X64);
    // 0x80800364: lhu         $v1, 0x66($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X66);
    // 0x80800368: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8080036C: andi        $t7, $v0, 0xF800
    ctx->r15 = ctx->r2 & 0XF800;
    // 0x80800370: andi        $t9, $v0, 0x7C0
    ctx->r25 = ctx->r2 & 0X7C0;
    // 0x80800374: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80800378: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8080037C: sb          $t8, 0x54($sp)
    MEM_B(0X54, ctx->r29) = ctx->r24;
    // 0x80800380: sb          $t0, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r8;
    // 0x80800384: andi        $t1, $v0, 0x3E
    ctx->r9 = ctx->r2 & 0X3E;
    // 0x80800388: andi        $t4, $v1, 0xF800
    ctx->r12 = ctx->r3 & 0XF800;
    // 0x8080038C: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x80800390: andi        $t8, $v1, 0x3E
    ctx->r24 = ctx->r3 & 0X3E;
    // 0x80800394: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800398: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x8080039C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x808003A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808003A4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x808003A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x808003AC: sb          $t2, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r10;
    // 0x808003B0: sb          $t3, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r11;
    // 0x808003B4: sb          $t5, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r13;
    // 0x808003B8: sb          $t7, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r15;
    // 0x808003BC: sb          $t9, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r25;
    // 0x808003C0: sb          $t0, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r8;
    // 0x808003C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808003C8: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x808003CC: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
    // 0x808003D0: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_808003D4:
    // 0x808003D4: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x808003D8: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x808003DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003E0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808003E4: bne         $t1, $t2, L_808003F4
    if (ctx->r9 != ctx->r10) {
        // 0x808003E8: nop
    
            goto L_808003F4;
    }
    // 0x808003E8: nop

    // 0x808003EC: b           L_80800400
    // 0x808003F0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
        goto L_80800400;
    // 0x808003F0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_808003F4:
    // 0x808003F4: jal         0x80031BF0
    // 0x808003F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _bcopy(rdram, ctx);
        goto after_1;
    // 0x808003F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x808003FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80800400:
    // 0x80800400: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80800404: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800408: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x8080040C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800410: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800414: jal         0x808005B0
    // 0x80800418: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_808005B0_glrtc(rdram, ctx);
        goto after_2;
    // 0x80800418: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_2:
    // 0x8080041C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800420: bne         $s1, $s3, L_808003D4
    if (ctx->r17 != ctx->r19) {
        // 0x80800424: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808003D4;
    }
    // 0x80800424: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800428: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8080042C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800430: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    // 0x80800434: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800438: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8080043C: jal         0x808005B0
    // 0x80800440: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_808005B0_glrtc(rdram, ctx);
        goto after_3;
    // 0x80800440: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800444: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80800448: sw          $s2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r18;
    // 0x8080044C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800450: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800454: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800458: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080045C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800460: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800464: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: jr          $ra
    // 0x80800470: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800470: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C78: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084C78);
    return;
    // 0x80084C7C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _chdoormake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868A8: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868A8);
    return;
    // 0x800868AC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080064C_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800658: jal         0x8009CC68
    // 0x8080065C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x8080065C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800660: bne         $v0, $zero, L_80800688
    if (ctx->r2 != 0) {
        // 0x80800664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800688;
    }
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: jal         0x8009E674
    // 0x8080066C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x8080066C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800670: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(532, 0X10B0) << 16);
    // 0x80800674: addiu       $a3, $a3, 0x10B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(532, 0X10B0));
    // 0x80800678: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8080067C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800680: jal         0x8010D930
    // 0x80800684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_2;
    // 0x80800684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800688:
    // 0x80800688: jal         0x800A4CA8
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_3;
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800690: jal         0x80110C2C
    // 0x80800694: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110C2C(rdram, ctx);
        goto after_4;
    // 0x80800694: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x80095774
    // 0x808006A0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_clear(rdram, ctx);
        goto after_5;
    // 0x808006A0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_5:
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x80095774
    // 0x808006AC: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    baflag_clear(rdram, ctx);
        goto after_6;
    // 0x808006AC: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_6:
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x80095774
    // 0x808006B8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    baflag_clear(rdram, ctx);
        goto after_7;
    // 0x808006B8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_7:
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: jal         0x80095774
    // 0x808006C4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x808006C4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_8:
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: jal         0x80095774
    // 0x808006D0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    baflag_clear(rdram, ctx);
        goto after_9;
    // 0x808006D0: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_9:
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: jal         0x80800424
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800424_bafpctrl(rdram, ctx);
        goto after_10;
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808006E8: jal         0x808000DC
    // 0x808006EC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_808000DC_bafpctrl(rdram, ctx);
        goto after_11;
    // 0x808006EC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_11:
    // 0x808006F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void func_800F51A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F51A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F51AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F51B0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800F51B4: jal         0x800F47C0
    // 0x800F51B8: addiu       $a0, $a0, 0x3584
    ctx->r4 = ADD32(ctx->r4, 0X3584);
    func_800F47C0(rdram, ctx);
        goto after_0;
    // 0x800F51B8: addiu       $a0, $a0, 0x3584
    ctx->r4 = ADD32(ctx->r4, 0X3584);
    after_0:
    // 0x800F51BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F51C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F51C4: jr          $ra
    // 0x800F51C8: nop

    return;
    // 0x800F51C8: nop

;}
RECOMP_FUNC void bstimeout_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002E8: jal         0x800A0CF4
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002F0: jal         0x800A4E30
    // 0x808002F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x808002F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808002F8: jal         0x800FC7C4
    // 0x808002FC: nop

    func_800FC7C4(rdram, ctx);
        goto after_2;
    // 0x808002FC: nop

    after_2:
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

;}
RECOMP_FUNC void chstatuebossbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1424, 0X7C8) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x7C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X7C8));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x7C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X7C8));
;}
RECOMP_FUNC void _chpowerhutwitchy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086080: syscall     275
    recomp_syscall_handler(rdram, ctx, 0x80086080);
    return;
    // 0x80086084: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800148_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080014C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800158: jal         0x80101870
    // 0x8080015C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x8080015C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800160: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800164: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800168: bgezl       $t8, L_8080020C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080016C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080020C;
    }
    goto skip_0;
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800170: jal         0x80104130
    // 0x80800174: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x80800174: nop

    after_1:
    // 0x80800178: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x8080017C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800184: jal         0x800DBEFC
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8080018C: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80800190: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800194: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800198: bnel        $t0, $at, L_8080020C
    if (ctx->r8 != ctx->r1) {
        // 0x8080019C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080020C;
    }
    goto skip_1;
    // 0x8080019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808001A0: jal         0x800D674C
    // 0x808001A4: addiu       $a0, $zero, 0x9C6
    ctx->r4 = ADD32(0, 0X9C6);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x808001A4: addiu       $a0, $zero, 0x9C6
    ctx->r4 = ADD32(0, 0X9C6);
    after_3:
    // 0x808001A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(904, 0X680) << 16);
    // 0x808001AC: lwc1        $f0, 0x680($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(904, 0X680));
    // 0x808001B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001B4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001C4: jal         0x800EFA4C
    // 0x808001C8: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808001C8: nop

    after_4:
    // 0x808001CC: jal         0x800E2588
    // 0x808001D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_5;
    // 0x808001D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x808001D4: jal         0x800E24D8
    // 0x808001D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_6;
    // 0x808001D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x808001DC: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808001E0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808001E4: addiu       $t3, $sp, 0x34
    ctx->r11 = ADD32(ctx->r29, 0X34);
    // 0x808001E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001EC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808001F0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808001F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808001F8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808001FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800200: jal         0x800E2AA4
    // 0x80800204: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800E2AA4(rdram, ctx);
        goto after_7;
    // 0x80800204: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080020C:
    // 0x8080020C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void func_80800898_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800898: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080089C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x808008A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008A4: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x808008A8: nop

    // 0x808008AC: bc1f        L_808008CC
    if (!c1cs) {
        // 0x808008B0: nop
    
            goto L_808008CC;
    }
    // 0x808008B0: nop

    // 0x808008B4: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x808008B8: nop

    // 0x808008BC: bc1f        L_808008CC
    if (!c1cs) {
        // 0x808008C0: nop
    
            goto L_808008CC;
    }
    // 0x808008C0: nop

    // 0x808008C4: jr          $ra
    // 0x808008C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808008C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008CC:
    // 0x808008CC: jr          $ra
    // 0x808008D0: nop

    return;
    // 0x808008D0: nop

;}
RECOMP_FUNC void func_80800778_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080077C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800780: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800784: jal         0x8009E958
    // 0x80800788: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8009E958(rdram, ctx);
        goto after_0;
    // 0x80800788: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080078C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800790: beq         $v0, $at, L_808007C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800794: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808007C8;
    }
    // 0x80800794: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800798: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080079C: bne         $v0, $at, L_808007EC
    if (ctx->r2 != ctx->r1) {
        // 0x808007A0: nop
    
            goto L_808007EC;
    }
    // 0x808007A0: nop

    // 0x808007A4: jal         0x800EA05C
    // 0x808007A8: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808007A8: nop

    after_1:
    // 0x808007AC: addiu       $at, $zero, 0x116
    ctx->r1 = ADD32(0, 0X116);
    // 0x808007B0: bne         $v0, $at, L_808007EC
    if (ctx->r2 != ctx->r1) {
        // 0x808007B4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808007EC;
    }
    // 0x808007B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007B8: jal         0x8009EB18
    // 0x808007BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    func_8009EB18(rdram, ctx);
        goto after_2;
    // 0x808007BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_2:
    // 0x808007C0: b           L_808007EC
    // 0x808007C4: nop

        goto L_808007EC;
    // 0x808007C4: nop

L_808007C8:
    // 0x808007C8: jal         0x800EA068
    // 0x808007CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_3;
    // 0x808007CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x808007D0: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x808007D4: nop
    
            goto L_808007EC;
    }
    // 0x808007D4: nop

    // 0x808007D8: jal         0x800C6E38
    // 0x808007DC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_4;
    // 0x808007DC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_4:
    // 0x808007E0: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x808007E4: nop
    
            goto L_808007EC;
    }
    // 0x808007E4: nop

    // 0x808007E8: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_808007EC:
    // 0x808007EC: jal         0x800EA068
    // 0x808007F0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800EA068(rdram, ctx);
        goto after_5;
    // 0x808007F0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_5:
    // 0x808007F4: beql        $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x808007F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800834;
    }
    goto skip_0;
    // 0x808007F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007FC: jal         0x800EA05C
    // 0x80800800: nop

    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x80800800: nop

    after_6:
    // 0x80800804: addiu       $at, $zero, 0x182
    ctx->r1 = ADD32(0, 0X182);
    // 0x80800808: beq         $v0, $at, L_80800820
    if (ctx->r2 == ctx->r1) {
        // 0x8080080C: addiu       $at, $zero, 0x188
        ctx->r1 = ADD32(0, 0X188);
            goto L_80800820;
    }
    // 0x8080080C: addiu       $at, $zero, 0x188
    ctx->r1 = ADD32(0, 0X188);
    // 0x80800810: beq         $v0, $at, L_80800828
    if (ctx->r2 == ctx->r1) {
        // 0x80800814: addiu       $s0, $zero, 0x6
        ctx->r16 = ADD32(0, 0X6);
            goto L_80800828;
    }
    // 0x80800814: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x80800818: b           L_80800828
    // 0x8080081C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_80800828;
    // 0x8080081C: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_80800820:
    // 0x80800820: b           L_80800828
    // 0x80800824: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
        goto L_80800828;
    // 0x80800824: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
L_80800828:
    // 0x80800828: jal         0x8009E9D8
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E9D8(rdram, ctx);
        goto after_7;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800834:
    // 0x80800834: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080083C: jr          $ra
    // 0x80800840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808089BC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808089BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808089C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808089C4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808089C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808089CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808089D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808089D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808089D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808089DC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808089E0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808089E4: jal         0x80100094
    // 0x808089E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808089E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808089EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808089F0: bne         $s0, $at, L_80808B1C
    if (ctx->r16 != ctx->r1) {
        // 0x808089F4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80808B1C;
    }
    // 0x808089F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808089F8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808089FC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80808A00: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80808A04: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x80808A08: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80808A0C:
    // 0x80808A0C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80808A10: addiu       $a0, $zero, 0x50A
    ctx->r4 = ADD32(0, 0X50A);
    // 0x80808A14: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80808A18: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80808A1C: jal         0x80108528
    // 0x80808A20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80808A20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80808A24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80808A28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80808A2C: jal         0x80103110
    // 0x80808A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80808A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80808A34: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80808A38: jal         0x80102FDC
    // 0x80808A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x80808A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80808A40: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x80808A44: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x80808A48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80808A4C: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80808A50: ori         $t0, $t9, 0x2180
    ctx->r8 = ctx->r25 | 0X2180;
    // 0x80808A54: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x80808A58: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    // 0x80808A5C: sh          $t0, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r8;
    // 0x80808A60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80808A64: jal         0x80808BE4
    // 0x80808A68: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80808BE4_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80808A68: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x80808A6C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80808A70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80808A74: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80808A78: bne         $s1, $s3, L_80808A0C
    if (ctx->r17 != ctx->r19) {
        // 0x80808A7C: sw          $t1, 0xAC($s2)
        MEM_W(0XAC, ctx->r18) = ctx->r9;
            goto L_80808A0C;
    }
    // 0x80808A7C: sw          $t1, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r9;
    // 0x80808A80: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80808A84: beq         $at, $zero, L_80808B1C
    if (ctx->r1 == 0) {
        // 0x80808A88: lui         $at, 0x8081
        ctx->r1 = S32(RELOC_HI16(1480, 0X9C54) << 16);
            goto L_80808B1C;
    }
    // 0x80808A88: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C54) << 16);
    // 0x80808A8C: lwc1        $f20, -0x63AC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C54));
L_80808A90:
    // 0x80808A90: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80808A94: addiu       $a0, $zero, 0x50A
    ctx->r4 = ADD32(0, 0X50A);
    // 0x80808A98: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80808A9C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80808AA0: jal         0x80108528
    // 0x80808AA4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_5;
    // 0x80808AA4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80808AA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80808AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80808AB0: jal         0x80103110
    // 0x80808AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x80808AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80808AB8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80808ABC: jal         0x80102FDC
    // 0x80808AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80808AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80808AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808AC8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80808ACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80808AD0: jal         0x80089CF0
    // 0x80808AD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80808AD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80808AD8: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x80808ADC: lbu         $t2, 0x75($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X75);
    // 0x80808AE0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80808AE4: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x80808AE8: ori         $t6, $t5, 0x1F00
    ctx->r14 = ctx->r13 | 0X1F00;
    // 0x80808AEC: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x80808AF0: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
    // 0x80808AF4: sh          $t6, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r14;
    // 0x80808AF8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80808AFC: jal         0x80808BE4
    // 0x80808B00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80808BE4_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80808B00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x80808B04: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80808B08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80808B0C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80808B10: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80808B14: bne         $at, $zero, L_80808A90
    if (ctx->r1 != 0) {
        // 0x80808B18: sw          $t7, 0xAC($s2)
        MEM_W(0XAC, ctx->r18) = ctx->r15;
            goto L_80808A90;
    }
    // 0x80808B18: sw          $t7, 0xAC($s2)
    MEM_W(0XAC, ctx->r18) = ctx->r15;
L_80808B1C:
    // 0x80808B1C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80808B20: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80808B24: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80808B28: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80808B2C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80808B30: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80808B34: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80808B38: jr          $ra
    // 0x80808B3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80808B3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001A324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A324: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A328: lw          $a0, -0x4330($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4330);
    // 0x8001A32C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A334: beq         $a0, $zero, L_8001A388
    if (ctx->r4 == 0) {
        // 0x8001A338: nop
    
            goto L_8001A388;
    }
    // 0x8001A338: nop

    // 0x8001A33C: jal         0x8001B084
    // 0x8001A340: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x8001A340: nop

    after_0:
    // 0x8001A344: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A348: jal         0x8001B084
    // 0x8001A34C: lw          $a0, -0x432C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X432C);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x8001A34C: lw          $a0, -0x432C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X432C);
    after_1:
    // 0x8001A350: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A354: jal         0x8001B084
    // 0x8001A358: lw          $a0, -0x4328($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4328);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x8001A358: lw          $a0, -0x4328($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4328);
    after_2:
    // 0x8001A35C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A360: jal         0x8001B084
    // 0x8001A364: lw          $a0, -0x4324($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4324);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x8001A364: lw          $a0, -0x4324($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4324);
    after_3:
    // 0x8001A368: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A36C: jal         0x8001B084
    // 0x8001A370: lw          $a0, -0x4320($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4320);
    heap_free(rdram, ctx);
        goto after_4;
    // 0x8001A370: lw          $a0, -0x4320($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4320);
    after_4:
    // 0x8001A374: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A378: jal         0x8001B084
    // 0x8001A37C: lw          $a0, -0x431C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X431C);
    heap_free(rdram, ctx);
        goto after_5;
    // 0x8001A37C: lw          $a0, -0x431C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X431C);
    after_5:
    // 0x8001A380: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A384: sw          $zero, -0x4330($at)
    MEM_W(-0X4330, ctx->r1) = 0;
L_8001A388:
    // 0x8001A388: jal         0x8001A63C
    // 0x8001A38C: nop

    func_8001A63C(rdram, ctx);
        goto after_6;
    // 0x8001A38C: nop

    after_6:
    // 0x8001A390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A398: jr          $ra
    // 0x8001A39C: nop

    return;
    // 0x8001A39C: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084500: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084500);
    return;
    // 0x80084504: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bswasher_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AFC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801B00: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1EC4) << 16);
    // 0x80801B04: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801B08: jr          $ra
    // 0x80801B0C: lw          $v0, 0x1EC4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1EC4));
    return;
    // 0x80801B0C: lw          $v0, 0x1EC4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1EC4));
;}
RECOMP_FUNC void func_80026330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026330: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026338: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002633C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80026340: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80026344: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80026348: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8002634C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80026350: addiu       $t8, $zero, 0x51
    ctx->r24 = ADD32(0, 0X51);
    // 0x80026354: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80026358: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002635C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80026360: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80026364: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80026368: sb          $t1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r9;
    // 0x8002636C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80026370: andi        $t3, $t2, 0xFF00
    ctx->r11 = ctx->r10 & 0XFF00;
    // 0x80026374: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80026378: sb          $t4, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r12;
    // 0x8002637C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80026380: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80026384: sb          $t6, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r14;
    // 0x80026388: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002638C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80026390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80026398: jal         0x80026500
    // 0x8002639C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x8002639C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800263A0: b           L_800263A8
    // 0x800263A4: nop

        goto L_800263A8;
    // 0x800263A4: nop

L_800263A8:
    // 0x800263A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800263AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800263B0: jr          $ra
    // 0x800263B4: nop

    return;
    // 0x800263B4: nop

    // 0x800263B8: nop

    // 0x800263BC: nop

;}
RECOMP_FUNC void func_8080046C_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800474: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800478: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8080047C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800480: beq         $t6, $at, L_80800498
    if (ctx->r14 == ctx->r1) {
        // 0x80800484: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80800498;
    }
    // 0x80800484: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80800488: beq         $t6, $at, L_808004A8
    if (ctx->r14 == ctx->r1) {
        // 0x8080048C: addiu       $a1, $zero, 0x789
        ctx->r5 = ADD32(0, 0X789);
            goto L_808004A8;
    }
    // 0x8080048C: addiu       $a1, $zero, 0x789
    ctx->r5 = ADD32(0, 0X789);
    // 0x80800490: b           L_808004C4
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004C4;
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800498:
    // 0x80800498: jal         0x8008A148
    // 0x8080049C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080049C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808004A0: b           L_808004C4
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004C4;
    // 0x808004A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A8:
    // 0x808004A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004AC: jal         0x808009D8
    // 0x808004B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_1;
    // 0x808004B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808004B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004B8: jal         0x8008A148
    // 0x808004BC: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808004BC: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_2:
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004C4:
    // 0x808004C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void _badialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847D0: syscall     121
    recomp_syscall_handler(rdram, ctx, 0x800847D0);
    return;
    // 0x800847D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F5AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5AE0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5AE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5AF0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5AF4: jal         0x8009BFCC
    // 0x800F5AF8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x800F5AF8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5B00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5B04: jr          $ra
    // 0x800F5B08: nop

    return;
    // 0x800F5B08: nop

;}
RECOMP_FUNC void func_80800410_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800418: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080041C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800420: jal         0x8008A820
    // 0x80800424: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    _suquiz_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800424: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80800428: jal         0x8008A828
    // 0x8080042C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _suquiz_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x8080042C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800430: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800434: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800438: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080043C: lwc1        $f8, 0x54($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80800440: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80800444: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800448: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080044C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800450: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800454: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800458: jal         0x800EF214
    // 0x8080045C: nop

    func_800EF214(rdram, ctx);
        goto after_2;
    // 0x8080045C: nop

    after_2:
    // 0x80800460: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800464: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80800468: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080046C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800470: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800474: beq         $at, $zero, L_80800528
    if (ctx->r1 == 0) {
        // 0x80800478: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800528;
    }
    // 0x80800478: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080047C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1788, 0X634) << 16);
    // 0x80800480: addu        $at, $at, $t8
    gpr jr_addend_80800488 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800484: lw          $t8, 0x634($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1788, 0X634));
    // 0x80800488: jr          $t8
    // 0x8080048C: nop

    switch (jr_addend_80800488 >> 2) {
        case 0: goto L_80800490; break;
        case 1: goto L_808004CC; break;
        case 2: goto L_808004D8; break;
        case 3: goto L_80800510; break;
        case 4: goto L_80800510; break;
        default: switch_error(__func__, 0x80800488, 0x80800634);
    }
    // 0x8080048C: nop

L_80800490:
    // 0x80800490: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800494: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800498: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080049C: lwc1        $f12, 0x34($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X34);
    // 0x808004A0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808004A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004A8: jal         0x800F10B4
    // 0x808004AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808004AC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x808004B0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1788, 0X664) << 16);
    // 0x808004BC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808004C0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808004C4: b           L_80800528
    // 0x808004C8: swc1        $f4, 0x664($at)
    MEM_W((int16_t)RELOC_LO16(1788, 0X664), ctx->r1) = ctx->f4.u32l;
        goto L_80800528;
    // 0x808004C8: swc1        $f4, 0x664($at)
    MEM_W((int16_t)RELOC_LO16(1788, 0X664), ctx->r1) = ctx->f4.u32l;
L_808004CC:
    // 0x808004CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808004D0: b           L_80800528
    // 0x808004D4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
        goto L_80800528;
    // 0x808004D4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
L_808004D8:
    // 0x808004D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E0: lwc1        $f12, 0x34($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X34);
    // 0x808004E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808004EC: jal         0x800F10B4
    // 0x808004F0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808004F0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x808004F4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1788, 0X664) << 16);
    // 0x80800500: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800504: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800508: b           L_80800528
    // 0x8080050C: swc1        $f10, 0x664($at)
    MEM_W((int16_t)RELOC_LO16(1788, 0X664), ctx->r1) = ctx->f10.u32l;
        goto L_80800528;
    // 0x8080050C: swc1        $f10, 0x664($at)
    MEM_W((int16_t)RELOC_LO16(1788, 0X664), ctx->r1) = ctx->f10.u32l;
L_80800510:
    // 0x80800510: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800514: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800518: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080051C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1788, 0X664) << 16);
    // 0x80800520: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x80800524: swc1        $f16, 0x664($at)
    MEM_W((int16_t)RELOC_LO16(1788, 0X664), ctx->r1) = ctx->f16.u32l;
L_80800528:
    // 0x80800528: jal         0x800E41CC
    // 0x8080052C: nop

    func_800E41CC(rdram, ctx);
        goto after_5;
    // 0x8080052C: nop

    after_5:
    // 0x80800530: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800534: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800538: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8080053C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800540: jal         0x800E3C8C
    // 0x80800544: nop

    func_800E3C8C(rdram, ctx);
        goto after_6;
    // 0x80800544: nop

    after_6:
    // 0x80800548: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080054C: jal         0x800E39D8
    // 0x80800550: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800E39D8(rdram, ctx);
        goto after_7;
    // 0x80800550: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x80800554: jal         0x800E3CE8
    // 0x80800558: nop

    func_800E3CE8(rdram, ctx);
        goto after_8;
    // 0x80800558: nop

    after_8:
    // 0x8080055C: jal         0x800E44FC
    // 0x80800560: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800E44FC(rdram, ctx);
        goto after_9;
    // 0x80800560: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x80800564: jal         0x800E7C28
    // 0x80800568: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800E7C28(rdram, ctx);
        goto after_10;
    // 0x80800568: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_10:
    // 0x8080056C: jal         0x800E7CF4
    // 0x80800570: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800E7CF4(rdram, ctx);
        goto after_11;
    // 0x80800570: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_11:
    // 0x80800574: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800578: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080057C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800580: nop

    // 0x80800584: bc1fl       L_808005BC
    if (!c1cs) {
        // 0x80800588: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808005BC;
    }
    goto skip_0;
    // 0x80800588: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x8080058C: jal         0x800D674C
    // 0x80800590: addiu       $a0, $zero, 0x9A1
    ctx->r4 = ADD32(0, 0X9A1);
    func_800D674C(rdram, ctx);
        goto after_12;
    // 0x80800590: addiu       $a0, $zero, 0x9A1
    ctx->r4 = ADD32(0, 0X9A1);
    after_12:
    // 0x80800594: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1788, 0X650) << 16);
    // 0x80800598: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1788, 0X65C) << 16);
    // 0x8080059C: addiu       $a2, $a2, 0x65C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1788, 0X65C));
    // 0x808005A0: addiu       $a1, $a1, 0x650
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1788, 0X650));
    // 0x808005A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808005A8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808005AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808005B0: jal         0x800DE498
    // 0x808005B4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_13;
    // 0x808005B4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_13:
    // 0x808005B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_808005BC:
    // 0x808005BC: jal         0x80101870
    // 0x808005C0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101870(rdram, ctx);
        goto after_14;
    // 0x808005C0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_14:
    // 0x808005C4: jal         0x800E4208
    // 0x808005C8: nop

    func_800E4208(rdram, ctx);
        goto after_15;
    // 0x808005C8: nop

    after_15:
    // 0x808005CC: jal         0x800E44FC
    // 0x808005D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800E44FC(rdram, ctx);
        goto after_16;
    // 0x808005D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_16:
    // 0x808005D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808005DC: jr          $ra
    // 0x808005E0: nop

    return;
    // 0x808005E0: nop

;}
RECOMP_FUNC void func_80800394_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003A0: jal         0x800F8B88
    // 0x808003A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x808003A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003A8: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x808003AC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808003B0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x808003B4: jal         0x8008DAA8
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_1;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808003C0: jal         0x800A3274
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_2;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003C8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003CC: jal         0x8009E6F8
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003D4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808003D8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808003DC: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808003E0: beq         $t7, $zero, L_80800400
    if (ctx->r15 == 0) {
        // 0x808003E4: nop
    
            goto L_80800400;
    }
    // 0x808003E4: nop

    // 0x808003E8: beql        $t8, $zero, L_80800414
    if (ctx->r24 == 0) {
        // 0x808003EC: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80800414;
    }
    goto skip_0;
    // 0x808003EC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x808003F0: jal         0x808002D4
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D4_basetup(rdram, ctx);
        goto after_4;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003F8: b           L_80800414
    // 0x808003FC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
        goto L_80800414;
    // 0x808003FC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80800400:
    // 0x80800400: beql        $t9, $zero, L_80800414
    if (ctx->r25 == 0) {
        // 0x80800404: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80800414;
    }
    goto skip_1;
    // 0x80800404: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x80800408: jal         0x808002D4
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D4_basetup(rdram, ctx);
        goto after_5;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800410: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80800414:
    // 0x80800414: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800418: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080041C: bne         $t0, $zero, L_808004D4
    if (ctx->r8 != 0) {
        // 0x80800420: nop
    
            goto L_808004D4;
    }
    // 0x80800420: nop

    // 0x80800424: jal         0x800A3274
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_6;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080042C: jal         0x800F54E4
    // 0x80800430: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800430: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // 0x80800434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800438: jal         0x800F64A4
    // 0x8080043C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_8;
    // 0x8080043C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_8:
    // 0x80800440: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x80800444: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80800490;
    }
    // 0x80800444: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800448: jal         0x8008E23C
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_9;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800450: beq         $v0, $zero, L_80800474
    if (ctx->r2 == 0) {
        // 0x80800454: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80800474;
    }
    // 0x80800454: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800458: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080045C: bne         $t1, $at, L_80800474
    if (ctx->r9 != ctx->r1) {
        // 0x80800460: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800474;
    }
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: jal         0x800F457C
    // 0x80800468: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F457C(rdram, ctx);
        goto after_10;
    // 0x80800468: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x8080046C: b           L_808004B4
    // 0x80800470: nop

        goto L_808004B4;
    // 0x80800470: nop

L_80800474:
    // 0x80800474: jal         0x800848D0
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_29(rdram, ctx);
        goto after_11;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: jal         0x8009E5C8
    // 0x80800484: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80800484: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80800488: b           L_808004B4
    // 0x8080048C: nop

        goto L_808004B4;
    // 0x8080048C: nop

L_80800490:
    // 0x80800490: beq         $t2, $zero, L_808004AC
    if (ctx->r10 == 0) {
        // 0x80800494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004AC;
    }
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x8009E5C8
    // 0x808004A0: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808004A0: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    after_13:
    // 0x808004A4: b           L_808004B4
    // 0x808004A8: nop

        goto L_808004B4;
    // 0x808004A8: nop

L_808004AC:
    // 0x808004AC: jal         0x800F457C
    // 0x808004B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F457C(rdram, ctx);
        goto after_14;
    // 0x808004B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
L_808004B4:
    // 0x808004B4: jal         0x800F8DA8
    // 0x808004B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F8DA8(rdram, ctx);
        goto after_15;
    // 0x808004B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808004BC: beq         $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x808004C0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800520;
    }
    // 0x808004C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004C4: jal         0x800F8D50
    // 0x808004C8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8D50(rdram, ctx);
        goto after_16;
    // 0x808004C8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_16:
    // 0x808004CC: b           L_80800524
    // 0x808004D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800524;
    // 0x808004D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004D4:
    // 0x808004D4: beq         $v1, $at, L_808004F8
    if (ctx->r3 == ctx->r1) {
        // 0x808004D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808004F8;
    }
    // 0x808004D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004DC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808004E0: beq         $v1, $at, L_8080050C
    if (ctx->r3 == ctx->r1) {
        // 0x808004E4: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8080050C;
    }
    // 0x808004E4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808004E8: beql        $v1, $at, L_80800510
    if (ctx->r3 == ctx->r1) {
        // 0x808004EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800510;
    }
    goto skip_2;
    // 0x808004EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808004F0: b           L_80800510
    // 0x808004F4: nop

        goto L_80800510;
    // 0x808004F4: nop

L_808004F8:
    // 0x808004F8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x808004FC: beq         $t3, $zero, L_80800510
    if (ctx->r11 == 0) {
        // 0x80800500: nop
    
            goto L_80800510;
    }
    // 0x80800500: nop

    // 0x80800504: b           L_80800510
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800510;
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080050C:
    // 0x8080050C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800510:
    // 0x80800510: beql        $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x80800514: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800524;
    }
    goto skip_3;
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800518: jal         0x800F8128
    // 0x8080051C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8128(rdram, ctx);
        goto after_17;
    // 0x8080051C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_17:
L_80800520:
    // 0x80800520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800524:
    // 0x80800524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800528: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080052C: jr          $ra
    // 0x80800530: nop

    return;
    // 0x80800530: nop

;}
RECOMP_FUNC void func_80800B4C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B54: jal         0x80102424
    // 0x80800B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B64: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800B68: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800B6C: beq         $t6, $at, L_80800B84
    if (ctx->r14 == ctx->r1) {
        // 0x80800B70: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800B84;
    }
    // 0x80800B70: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800B74: beql        $t6, $at, L_80800BB4
    if (ctx->r14 == ctx->r1) {
        // 0x80800B78: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800BB4;
    }
    goto skip_0;
    // 0x80800B78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x80800B7C: b           L_80800BC0
    // 0x80800B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BC0;
    // 0x80800B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B84:
    // 0x80800B84: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800B88: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800B8C: bgezl       $t9, L_80800BC0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800B90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800BC0;
    }
    goto skip_1;
    // 0x80800B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800B94: lbu         $t0, 0x72($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X72);
    // 0x80800B98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B9C: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x80800BA0: ori         $t2, $t1, 0x28
    ctx->r10 = ctx->r9 | 0X28;
    // 0x80800BA4: sb          $t2, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r10;
    // 0x80800BA8: b           L_80800BBC
    // 0x80800BAC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
        goto L_80800BBC;
    // 0x80800BAC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80800BB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800BB4:
    // 0x80800BB4: nop

    // 0x80800BB8: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
L_80800BBC:
    // 0x80800BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC0:
    // 0x80800BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BC4: jr          $ra
    // 0x80800BC8: nop

    return;
    // 0x80800BC8: nop

;}
RECOMP_FUNC void func_8080110C_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080110C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801114: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801118: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080111C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80801120: jal         0x8010D254
    // 0x80801124: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80801124: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80801128: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080112C: jal         0x800F1DF4
    // 0x80801130: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x80801130: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80801134: jal         0x800F54E4
    // 0x80801138: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801138: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8080113C: jal         0x800F5F24
    // 0x80801140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_3;
    // 0x80801140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801144: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801148: jal         0x800F1DCC
    // 0x8080114C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x8080114C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801150: jal         0x800F2100
    // 0x80801154: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80801154: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x80801158: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8080115C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801164: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80801168: nop

    // 0x8080116C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801170: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801174: nop

    // 0x80801178: bc1f        L_80801184
    if (!c1cs) {
        // 0x8080117C: nop
    
            goto L_80801184;
    }
    // 0x8080117C: nop

    // 0x80801180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801184:
    // 0x80801184: jr          $ra
    // 0x80801188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808006D4_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D4: lb          $t6, 0x211($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X211);
    // 0x808006D8: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x808006DC: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x808006E0: beq         $at, $zero, L_80800704
    if (ctx->r1 == 0) {
        // 0x808006E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800704;
    }
    // 0x808006E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808006E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X29E0) << 16);
    // 0x808006EC: addu        $at, $at, $t7
    gpr jr_addend_808006F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808006F0: lw          $t7, 0x29E0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3094, 0X29E0));
    // 0x808006F4: jr          $t7
    // 0x808006F8: nop

    switch (jr_addend_808006F4 >> 2) {
        case 0: goto L_808006FC; break;
        case 1: goto L_808006FC; break;
        case 2: goto L_808006FC; break;
        case 3: goto L_80800704; break;
        case 4: goto L_808006FC; break;
        case 5: goto L_80800704; break;
        case 6: goto L_808006FC; break;
        case 7: goto L_808006FC; break;
        default: switch_error(__func__, 0x808006F4, 0x808029E0);
    }
    // 0x808006F8: nop

L_808006FC:
    // 0x808006FC: jr          $ra
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800708: jr          $ra
    // 0x8080070C: nop

    return;
    // 0x8080070C: nop

;}
RECOMP_FUNC void func_800F8B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F8B80: jr          $ra
    // 0x800F8B84: lbu         $v0, 0x54FD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54FD);
    return;
    // 0x800F8B84: lbu         $v0, 0x54FD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54FD);
;}
RECOMP_FUNC void func_8008D40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { int join = tooie_split_join_check(rdram, ctx); if (join >= 0) { ctx->r2 = join; return; } }
    // 0x8008D40C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008D410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D414: jal         0x800F8B88
    // 0x8008D418: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x8008D418: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008D41C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D420: bnel        $v0, $at, L_8008D534
    if (ctx->r2 != ctx->r1) {
        // 0x8008D424: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008D534;
    }
    goto skip_0;
    // 0x8008D424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8008D428: jal         0x800878A8
    // 0x8008D42C: nop

    _plsu_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8008D42C: nop

    after_1:
    // 0x8008D430: beql        $v0, $zero, L_8008D534
    if (ctx->r2 == 0) {
        // 0x8008D434: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008D534;
    }
    goto skip_1;
    // 0x8008D434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8008D438: jal         0x8008E0C8
    // 0x8008D43C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8008E0C8(rdram, ctx);
        goto after_2;
    // 0x8008D43C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8008D440: beq         $v0, $zero, L_8008D450
    if (ctx->r2 == 0) {
        // 0x8008D444: nop
    
            goto L_8008D450;
    }
    // 0x8008D444: nop

    // 0x8008D448: b           L_8008D534
    // 0x8008D44C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D534;
    // 0x8008D44C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D450:
    // 0x8008D450: jal         0x800F99E8
    // 0x8008D454: nop

    func_800F99E8(rdram, ctx);
        goto after_3;
    // 0x8008D454: nop

    after_3:
    // 0x8008D458: beq         $v0, $zero, L_8008D468
    if (ctx->r2 == 0) {
        // 0x8008D45C: nop
    
            goto L_8008D468;
    }
    // 0x8008D45C: nop

    // 0x8008D460: b           L_8008D534
    // 0x8008D464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D534;
    // 0x8008D464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D468:
    // 0x8008D468: jal         0x8009E6F8
    // 0x8008D46C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    bs_getCurrentState(rdram, ctx);
        goto after_4;
    // 0x8008D46C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x8008D470: addiu       $at, $zero, 0xB9
    ctx->r1 = ADD32(0, 0XB9);
    // 0x8008D474: beq         $v0, $at, L_8008D484
    if (ctx->r2 == ctx->r1) {
        // 0x8008D478: addiu       $at, $zero, 0xBA
        ctx->r1 = ADD32(0, 0XBA);
            goto L_8008D484;
    }
    // 0x8008D478: addiu       $at, $zero, 0xBA
    ctx->r1 = ADD32(0, 0XBA);
    // 0x8008D47C: bne         $v0, $at, L_8008D48C
    if (ctx->r2 != ctx->r1) {
        // 0x8008D480: nop
    
            goto L_8008D48C;
    }
    // 0x8008D480: nop

L_8008D484:
    // 0x8008D484: b           L_8008D534
    // 0x8008D488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D534;
    // 0x8008D488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D48C:
    // 0x8008D48C: jal         0x80084928
    // 0x8008D490: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _baduo_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8008D490: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8008D494: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8008D498: jal         0x8008E078
    // 0x8008D49C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    player_isStable(rdram, ctx);
        goto after_6;
    // 0x8008D49C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x8008D4A0: beq         $v0, $zero, L_8008D4B8
    if (ctx->r2 == 0) {
        // 0x8008D4A4: nop
    
            goto L_8008D4B8;
    }
    // 0x8008D4A4: nop

    // 0x8008D4A8: jal         0x800F6C5C
    // 0x8008D4AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F6C5C(rdram, ctx);
        goto after_7;
    // 0x8008D4AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8008D4B0: bne         $v0, $zero, L_8008D4C0
    if (ctx->r2 != 0) {
        // 0x8008D4B4: nop
    
            goto L_8008D4C0;
    }
    // 0x8008D4B4: nop

L_8008D4B8:
    // 0x8008D4B8: b           L_8008D534
    // 0x8008D4BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D534;
    // 0x8008D4BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D4C0:
    // 0x8008D4C0: jal         0x800F54E4
    // 0x8008D4C4: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x8008D4C4: nop

    after_8:
    // 0x8008D4C8: jal         0x800F6774
    // 0x8008D4CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6774(rdram, ctx);
        goto after_9;
    // 0x8008D4CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x8008D4D0: bne         $v0, $zero, L_8008D4E0
    if (ctx->r2 != 0) {
        // 0x8008D4D4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8008D4E0;
    }
    // 0x8008D4D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008D4D8: b           L_8008D534
    // 0x8008D4DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D534;
    // 0x8008D4DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D4E0:
    // 0x8008D4E0: jal         0x8009C128
    // 0x8008D4E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_10;
    // 0x8008D4E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_10:
    // 0x8008D4E8: jal         0x80084928
    // 0x8008D4EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _baduo_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x8008D4EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x8008D4F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008D4F4: jal         0x800F5A00
    // 0x8008D4F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_12;
    // 0x8008D4F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_12:
    // 0x8008D4FC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8008D500: jal         0x800EEB40
    // 0x8008D504: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEB40(rdram, ctx);
        goto after_13;
    // 0x8008D504: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_13:
    // 0x8008D508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D50C: lwc1        $f4, 0x4AD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4AD0);
    // 0x8008D510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D514: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8008D518: nop

    // 0x8008D51C: bc1fl       L_8008D538
    if (!c1cs) {
        // 0x8008D520: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008D538;
    }
    goto skip_2;
    // 0x8008D520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8008D524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008D528: b           L_8008D538
    // 0x8008D52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008D538;
    // 0x8008D52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D534:
    // 0x8008D534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008D538:
    // 0x8008D538: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008D53C: jr          $ra
    // 0x8008D540: nop

    return;
    // 0x8008D540: nop

;}
RECOMP_FUNC void _chping_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872A0: syscall     544
    recomp_syscall_handler(rdram, ctx, 0x800872A0);
    return;
    // 0x800872A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8002B7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B7C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002B7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B7D0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8002B7D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002B7D8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8002B7DC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8002B7E0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8002B7E4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8002B7E8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002B7EC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8002B7F0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002B7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B7F8: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8002B7FC: bne         $t9, $at, L_8002B810
    if (ctx->r25 != ctx->r1) {
        // 0x8002B800: nop
    
            goto L_8002B810;
    }
    // 0x8002B800: nop

    // 0x8002B804: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8002B808: bne         $t0, $zero, L_8002B818
    if (ctx->r8 != 0) {
        // 0x8002B80C: nop
    
            goto L_8002B818;
    }
    // 0x8002B80C: nop

L_8002B810:
    // 0x8002B810: b           L_8002BA9C
    // 0x8002B814: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_8002BA9C;
    // 0x8002B814: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_8002B818:
    // 0x8002B818: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002B81C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B820: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8002B824: jal         0x8002D030
    // 0x8002B828: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_8002D030(rdram, ctx);
        goto after_0;
    // 0x8002B828: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8002B82C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8002B830: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002B834: lw          $t2, 0x78($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X78);
    // 0x8002B838: beq         $t2, $zero, L_8002BA3C
    if (ctx->r10 == 0) {
        // 0x8002B83C: nop
    
            goto L_8002BA3C;
    }
    // 0x8002B83C: nop

    // 0x8002B840: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002B844: sw          $zero, 0x78($t3)
    MEM_W(0X78, ctx->r11) = 0;
    // 0x8002B848: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002B84C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002B850: lh          $t5, 0x58($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X58);
    // 0x8002B854: lh          $t8, 0x5A($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X5A);
    // 0x8002B858: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8002B85C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002B860: lh          $t7, 0x1290($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1290);
    // 0x8002B864: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B868: mflo        $t9
    ctx->r25 = lo;
    // 0x8002B86C: sra         $t0, $t9, 15
    ctx->r8 = S32(SIGNED(ctx->r25) >> 15);
    // 0x8002B870: sh          $t0, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r8;
    // 0x8002B874: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002B878: lh          $t2, 0x5C($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X5C);
    // 0x8002B87C: lh          $t3, 0x68($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X68);
    // 0x8002B880: lw          $a2, 0x74($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X74);
    // 0x8002B884: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8002B888: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002B88C: addiu       $a3, $t1, 0x64
    ctx->r7 = ADD32(ctx->r9, 0X64);
    // 0x8002B890: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002B894: jal         0x8002BAAC
    // 0x8002B898: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_8002BAAC(rdram, ctx);
        goto after_1;
    // 0x8002B898: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x8002B89C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002B8A0: sh          $v0, 0x66($t5)
    MEM_H(0X66, ctx->r13) = ctx->r2;
    // 0x8002B8A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8002B8A8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002B8AC: lh          $t7, 0x58($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X58);
    // 0x8002B8B0: lh          $t4, 0x5A($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X5A);
    // 0x8002B8B4: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8002B8B8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8002B8BC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002B8C0: lh          $t0, 0x138E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X138E);
    // 0x8002B8C4: multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B8C8: mflo        $t2
    ctx->r10 = lo;
    // 0x8002B8CC: sra         $t3, $t2, 15
    ctx->r11 = S32(SIGNED(ctx->r10) >> 15);
    // 0x8002B8D0: sh          $t3, 0x6E($t6)
    MEM_H(0X6E, ctx->r14) = ctx->r11;
    // 0x8002B8D4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002B8D8: lh          $t5, 0x5E($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X5E);
    // 0x8002B8DC: lh          $t7, 0x6E($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X6E);
    // 0x8002B8E0: lw          $a2, 0x74($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X74);
    // 0x8002B8E4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8002B8E8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8002B8EC: addiu       $a3, $t1, 0x6A
    ctx->r7 = ADD32(ctx->r9, 0X6A);
    // 0x8002B8F0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002B8F4: jal         0x8002BAAC
    // 0x8002B8F8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_8002BAAC(rdram, ctx);
        goto after_2;
    // 0x8002B8F8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_2:
    // 0x8002B8FC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002B900: sh          $v0, 0x6C($t8)
    MEM_H(0X6C, ctx->r24) = ctx->r2;
    // 0x8002B904: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8002B908: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8002B90C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8002B910: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8002B914: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002B918: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B91C: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x8002B920: lh          $t2, 0x5C($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X5C);
    // 0x8002B924: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8002B928: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x8002B92C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8002B930: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002B934: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B938: lh          $t1, 0x60($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X60);
    // 0x8002B93C: lh          $t0, 0x62($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X62);
    // 0x8002B940: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8002B944: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002B948: andi        $t4, $t0, 0xFFFF
    ctx->r12 = ctx->r8 & 0XFFFF;
    // 0x8002B94C: or          $t2, $t9, $t4
    ctx->r10 = ctx->r25 | ctx->r12;
    // 0x8002B950: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8002B954: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002B958: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x8002B95C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8002B960: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8002B964: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002B968: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002B96C: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x8002B970: lh          $t8, 0x6E($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X6E);
    // 0x8002B974: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8002B978: or          $t0, $t7, $at
    ctx->r8 = ctx->r15 | ctx->r1;
    // 0x8002B97C: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8002B980: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8002B984: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002B988: lh          $t2, 0x6C($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X6C);
    // 0x8002B98C: lhu         $t5, 0x6A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6A);
    // 0x8002B990: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8002B994: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x8002B998: andi        $t1, $t5, 0xFFFF
    ctx->r9 = ctx->r13 & 0XFFFF;
    // 0x8002B99C: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x8002B9A0: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8002B9A4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8002B9A8: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x8002B9AC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8002B9B0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8002B9B4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8002B9B8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002B9BC: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x8002B9C0: lh          $t3, 0x68($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X68);
    // 0x8002B9C4: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8002B9C8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8002B9CC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8002B9D0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002B9D4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8002B9D8: lh          $t8, 0x66($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X66);
    // 0x8002B9DC: lhu         $t9, 0x64($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X64);
    // 0x8002B9E0: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8002B9E4: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x8002B9E8: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8002B9EC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8002B9F0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8002B9F4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8002B9F8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002B9FC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8002BA00: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8002BA04: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002BA08: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002BA0C: lui         $at, 0x301
    ctx->r1 = S32(0X301 << 16);
    // 0x8002BA10: lh          $t7, 0x5E($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X5E);
    // 0x8002BA14: andi        $t1, $t7, 0xFFFF
    ctx->r9 = ctx->r15 & 0XFFFF;
    // 0x8002BA18: or          $t9, $t1, $at
    ctx->r25 = ctx->r9 | ctx->r1;
    // 0x8002BA1C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8002BA20: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8002BA24: jal         0x8002E330
    // 0x8002BA28: lw          $a0, 0x54($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X54);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8002BA28: lw          $a0, 0x54($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X54);
    after_3:
    // 0x8002BA2C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8002BA30: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8002BA34: b           L_8002BA6C
    // 0x8002BA38: nop

        goto L_8002BA6C;
    // 0x8002BA38: nop

L_8002BA3C:
    // 0x8002BA3C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8002BA40: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8002BA44: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8002BA48: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8002BA4C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BA50: lui         $t6, 0x300
    ctx->r14 = S32(0X300 << 16);
    // 0x8002BA54: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8002BA58: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002BA5C: jal         0x8002E330
    // 0x8002BA60: lw          $a0, 0x54($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X54);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8002BA60: lw          $a0, 0x54($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X54);
    after_4:
    // 0x8002BA64: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BA68: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
L_8002BA6C:
    // 0x8002BA6C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BA70: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8002BA74: addiu       $t2, $t0, 0x170
    ctx->r10 = ADD32(ctx->r8, 0X170);
    // 0x8002BA78: sh          $t2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r10;
    // 0x8002BA7C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002BA80: lw          $t4, 0x70($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X70);
    // 0x8002BA84: addiu       $t5, $t4, 0xB8
    ctx->r13 = ADD32(ctx->r12, 0XB8);
    // 0x8002BA88: sw          $t5, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->r13;
    // 0x8002BA8C: b           L_8002BA9C
    // 0x8002BA90: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
        goto L_8002BA9C;
    // 0x8002BA90: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8002BA94: b           L_8002BA9C
    // 0x8002BA98: nop

        goto L_8002BA9C;
    // 0x8002BA98: nop

L_8002BA9C:
    // 0x8002BA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BAA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002BAA4: jr          $ra
    // 0x8002BAA8: nop

    return;
    // 0x8002BAA8: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A208: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A208);
    return;
    // 0x8008A20C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8080084C_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800854: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800858: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080085C: jal         0x800EE88C
    // 0x80800860: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80800860: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800864: jal         0x800EEF94
    // 0x80800868: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x80800868: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8080086C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800870: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800874: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80800878: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8080087C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800880: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800884: jal         0x800136D0
    // 0x80800888: nop

    func_800136D0(rdram, ctx);
        goto after_2;
    // 0x80800888: nop

    after_2:
    // 0x8080088C: jal         0x800138BC
    // 0x80800890: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138BC(rdram, ctx);
        goto after_3;
    // 0x80800890: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80800894: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800898: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080089C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808008A0: lh          $t7, 0x5A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X5A);
    // 0x808008A4: lwc1        $f6, 0x24($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X24);
    // 0x808008A8: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x808008AC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x808008B0: nop

    // 0x808008B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808008B8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808008BC: nop

    // 0x808008C0: mul.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x808008C4: bc1t        L_808008F0
    if (c1cs) {
        // 0x808008C8: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_808008F0;
    }
    // 0x808008C8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808008CC: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    // 0x808008D0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808008D4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x808008D8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808008DC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x808008E0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808008E4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808008E8: b           L_80800908
    // 0x808008EC: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
        goto L_80800908;
    // 0x808008EC: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
L_808008F0:
    // 0x808008F0: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808008F4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x808008F8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x808008FC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800900: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800904: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_80800908:
    // 0x80800908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080090C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800910: jr          $ra
    // 0x80800914: nop

    return;
    // 0x80800914: nop

;}
RECOMP_FUNC void func_8008FD48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FD48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FD4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FD50: jal         0x800F54E4
    // 0x8008FD54: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FD54: nop

    after_0:
    // 0x8008FD58: jal         0x800F5410
    // 0x8008FD5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x8008FD5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FD64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FD68: jr          $ra
    // 0x8008FD6C: nop

    return;
    // 0x8008FD6C: nop

;}
