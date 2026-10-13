#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _suspline_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DF0: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DF0);
    return;
    // 0x80089DF4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _suspline_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E18: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089E18);
    return;
    // 0x80089E1C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void sulights_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080068C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800690: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800698: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080069C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808006A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808006A4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808006A8: jal         0x80800000
    // 0x808006AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80800000_sulights(rdram, ctx);
        goto after_0;
    // 0x808006AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x808006B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3374, 0X9EC) << 16);
    // 0x808006B4: lwc1        $f0, 0x9EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3374, 0X9EC));
    // 0x808006B8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808006BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808006C4: nop

    // 0x808006C8: bc1fl       L_808006DC
    if (!c1cs) {
        // 0x808006CC: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_808006DC;
    }
    goto skip_0;
    // 0x808006CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x808006D0: b           L_808006E8
    // 0x808006D4: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
        goto L_808006E8;
    // 0x808006D4: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x808006D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_808006DC:
    // 0x808006DC: nop

    // 0x808006E0: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808006E4: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
L_808006E8:
    // 0x808006E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808006EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808006F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x808006F8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x808006FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800700: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800704: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x80800708: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8080070C: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80800710: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800714:
    // 0x80800714: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80800718: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8080071C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800720: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800724: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80800728: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8080072C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800730: bne         $v1, $a3, L_80800714
    if (ctx->r3 != ctx->r7) {
        // 0x80800734: sw          $t1, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->r9;
            goto L_80800714;
    }
    // 0x80800734: sw          $t1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r9;
    // 0x80800738: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080073C: jal         0x800C8E84
    // 0x80800740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x80800740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800748: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080074C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800750: jr          $ra
    // 0x80800754: nop

    return;
    // 0x80800754: nop

;}
RECOMP_FUNC void _ncbapivot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089470: syscall     781
    recomp_syscall_handler(rdram, ctx, 0x80089470);
    return;
    // 0x80089474: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _baeggcursor_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AE8: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AE8);
    return;
    // 0x80084AEC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bstaxi_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E4: jal         0x8009E74C
    // 0x808000E8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x808000E8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x808000EC: bne         $v0, $zero, L_80800130
    if (ctx->r2 != 0) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800130;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x800A0CD0
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_1;
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80084538
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x8009BF5C
    // 0x80800110: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_3;
    // 0x80800110: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x8009C4CC
    // 0x8080011C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_4;
    // 0x8080011C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800120: jal         0x8009EF60
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_5;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800128: jal         0x8009E474
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_6;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80800130:
    // 0x80800130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void sukickball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800078: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800080: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: jal         0x80100094
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800090: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3166, 0X120C) << 16);
    // 0x80800094: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800098: addiu       $t7, $t7, 0x120C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3166, 0X120C));
    // 0x8080009C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808000A0: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x808000A4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x808000A8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x808000AC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808000B0: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x808000B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000B8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808000BC: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808000C0: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x808000C4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x808000C8: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x808000CC: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808000D0: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x808000D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000D8: jal         0x800DF47C
    // 0x808000DC: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    func_800DF47C(rdram, ctx);
        goto after_1;
    // 0x808000DC: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808000E0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x808000E4: jal         0x800138D0
    // 0x808000E8: lwc1        $f12, 0x14($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X14);
    func_800138D0(rdram, ctx);
        goto after_2;
    // 0x808000E8: lwc1        $f12, 0x14($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X14);
    after_2:
    // 0x808000EC: lbu         $t2, 0x9B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X9B);
    // 0x808000F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808000F8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800100: bgez        $t2, L_80800114
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800104: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800114;
    }
    // 0x80800104: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800108: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080010C: nop

    // 0x80800110: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800114:
    // 0x80800114: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800118: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080011C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80800120: nop

    // 0x80800124: bgezl       $v0, L_80800134
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800128: slti        $at, $v0, 0x61
        ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
            goto L_80800134;
    }
    goto skip_0;
    // 0x80800128: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    skip_0:
    // 0x8080012C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80800130: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
L_80800134:
    // 0x80800134: bne         $at, $zero, L_80800198
    if (ctx->r1 != 0) {
        // 0x80800138: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_80800198;
    }
    // 0x80800138: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080013C: jal         0x800DF744
    // 0x80800140: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800140: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800144: jal         0x800DF410
    // 0x80800148: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800DF410(rdram, ctx);
        goto after_4;
    // 0x80800148: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8080014C: jal         0x8010347C
    // 0x80800150: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_5;
    // 0x80800150: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80800154: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800158: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8080015C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800160: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800164: jal         0x800DE448
    // 0x80800168: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_6;
    // 0x80800168: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8080016C: jal         0x800DF350
    // 0x80800170: nop

    func_800DF350(rdram, ctx);
        goto after_7;
    // 0x80800170: nop

    after_7:
    // 0x80800174: beql        $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800178: lw          $v0, 0x44($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X44);
            goto L_8080019C;
    }
    goto skip_1;
    // 0x80800178: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8080017C: jal         0x80104130
    // 0x80800180: nop

    func_80104130(rdram, ctx);
        goto after_8;
    // 0x80800180: nop

    after_8:
    // 0x80800184: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800190: jal         0x800DBEFC
    // 0x80800194: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    func_800DBEFC(rdram, ctx);
        goto after_9;
    // 0x80800194: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    after_9:
L_80800198:
    // 0x80800198: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_8080019C:
    // 0x8080019C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808001A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001A4: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    // 0x808001A8: beq         $at, $zero, L_80800218
    if (ctx->r1 == 0) {
        // 0x808001AC: addiu       $t4, $s0, 0x4
        ctx->r12 = ADD32(ctx->r16, 0X4);
            goto L_80800218;
    }
    // 0x808001AC: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x808001B0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x808001B4: jal         0x800DF744
    // 0x808001B8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x808001B8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_10:
    // 0x808001BC: lbu         $t5, 0x9B($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9B);
    // 0x808001C0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x808001C4: jal         0x800DF410
    // 0x808001C8: subu        $a0, $t5, $t9
    ctx->r4 = SUB32(ctx->r13, ctx->r25);
    func_800DF410(rdram, ctx);
        goto after_11;
    // 0x808001C8: subu        $a0, $t5, $t9
    ctx->r4 = SUB32(ctx->r13, ctx->r25);
    after_11:
    // 0x808001CC: jal         0x8010347C
    // 0x808001D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_12;
    // 0x808001D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x808001D4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808001D8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808001DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808001E4: jal         0x800DE448
    // 0x808001E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_13;
    // 0x808001E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x808001EC: jal         0x800DF350
    // 0x808001F0: nop

    func_800DF350(rdram, ctx);
        goto after_14;
    // 0x808001F0: nop

    after_14:
    // 0x808001F4: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001F8: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_80800218;
    }
    // 0x808001F8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808001FC: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80800200: jal         0x80104130
    // 0x80800204: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80104130(rdram, ctx);
        goto after_15;
    // 0x80800204: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_15:
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080020C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800210: jal         0x800DBEFC
    // 0x80800214: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800DBEFC(rdram, ctx);
        goto after_16;
    // 0x80800214: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_16:
L_80800218:
    // 0x80800218: jal         0x800DF350
    // 0x8080021C: nop

    func_800DF350(rdram, ctx);
        goto after_17;
    // 0x8080021C: nop

    after_17:
    // 0x80800220: beql        $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x80800224: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800268;
    }
    goto skip_2;
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800228: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080022C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800230: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800234: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80800238: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080023C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800240: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800244: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80800248: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8080024C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800250: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80800254: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800258: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8080025C: jal         0x80800000
    // 0x80800260: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800000_sukickball(rdram, ctx);
        goto after_18;
    // 0x80800260: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_18:
    // 0x80800264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800268:
    // 0x80800268: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080026C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800270: jr          $ra
    // 0x80800274: nop

    return;
    // 0x80800274: nop

;}
RECOMP_FUNC void func_80801800_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801808: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A48) << 16);
    // 0x8080180C: lui         $a3, 0x3E6B
    ctx->r7 = S32(0X3E6B << 16);
    // 0x80801810: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x80801814: addiu       $a2, $a2, 0x2A48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A48));
    // 0x80801818: jal         0x80089D20
    // 0x8080181C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080181C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801828: jr          $ra
    // 0x8080182C: nop

    return;
    // 0x8080182C: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855B0: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855B0);
    return;
    // 0x800855B4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800394_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800398: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003A4: jal         0x80100094
    // 0x808003A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808003B0: jal         0x80800C98
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C98_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003B8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808003BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003C4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808003C8: bne         $t7, $at, L_808003F8
    if (ctx->r15 != ctx->r1) {
        // 0x808003CC: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2168, 0XFA0) << 16);
            goto L_808003F8;
    }
    // 0x808003CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XFA0) << 16);
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: addiu       $a2, $a2, 0xFA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XFA0));
    // 0x808003D8: jal         0x80089D20
    // 0x808003DC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808003DC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_2:
    // 0x808003E0: jal         0x80101DDC
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_3;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003E8: beq         $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x808003EC: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_808003F8;
    }
    // 0x808003EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808003F0: jal         0x80102424
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808003F8:
    // 0x808003F8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808003FC: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x80800400: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800404: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x80800408: beq         $at, $zero, L_80800608
    if (ctx->r1 == 0) {
        // 0x8080040C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800608;
    }
    // 0x8080040C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800410: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0XE08) << 16);
    // 0x80800414: addu        $at, $at, $t0
    gpr jr_addend_8080041C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800418: lw          $t0, 0xE08($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2168, 0XE08));
    // 0x8080041C: jr          $t0
    // 0x80800420: nop

    switch (jr_addend_8080041C >> 2) {
        case 0: goto L_80800424; break;
        case 1: goto L_808004D8; break;
        case 2: goto L_808004FC; break;
        case 3: goto L_80800608; break;
        case 4: goto L_80800608; break;
        case 5: goto L_80800608; break;
        case 6: goto L_80800510; break;
        case 7: goto L_80800510; break;
        default: switch_error(__func__, 0x8080041C, 0x80800E08);
    }
    // 0x80800420: nop

L_80800424:
    // 0x80800424: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800428: jal         0x800C0638
    // 0x8080042C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    func_800C0638(rdram, ctx);
        goto after_5;
    // 0x8080042C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_5:
    // 0x80800430: bne         $v0, $zero, L_808004AC
    if (ctx->r2 != 0) {
        // 0x80800434: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004AC;
    }
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: lui         $a1, 0x3E05
    ctx->r5 = S32(0X3E05 << 16);
    // 0x8080043C: jal         0x80101E14
    // 0x80800440: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    func_80101E14(rdram, ctx);
        goto after_6;
    // 0x80800440: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_6:
    // 0x80800444: bne         $v0, $zero, L_80800488
    if (ctx->r2 != 0) {
        // 0x80800448: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800488;
    }
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: lui         $a1, 0x3E5C
    ctx->r5 = S32(0X3E5C << 16);
    // 0x80800450: jal         0x80101E14
    // 0x80800454: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80800454: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    after_7:
    // 0x80800458: bne         $v0, $zero, L_80800488
    if (ctx->r2 != 0) {
        // 0x8080045C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800488;
    }
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: lui         $a1, 0x3E8A
    ctx->r5 = S32(0X3E8A << 16);
    // 0x80800464: jal         0x80101E14
    // 0x80800468: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80800468: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    after_8:
    // 0x8080046C: bne         $v0, $zero, L_80800488
    if (ctx->r2 != 0) {
        // 0x80800470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800488;
    }
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: lui         $a1, 0x3EAE
    ctx->r5 = S32(0X3EAE << 16);
    // 0x80800478: jal         0x80101E14
    // 0x8080047C: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x8080047C: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    after_9:
    // 0x80800480: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x80800484: nop
    
            goto L_80800490;
    }
    // 0x80800484: nop

L_80800488:
    // 0x80800488: jal         0x8080036C
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080036C_chfactoryworkerdirty(rdram, ctx);
        goto after_10;
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800490:
    // 0x80800490: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XFB0) << 16);
    // 0x80800494: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800498: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080049C: addiu       $a2, $a2, 0xFB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XFB0));
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80089D20
    // 0x808004A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808004A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_11:
L_808004AC:
    // 0x808004AC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x808004B0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808004B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004B8: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x808004BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004C0: jal         0x80089F20
    // 0x808004C4: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808004C4: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_12:
    // 0x808004C8: jal         0x8080061C
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080061C_chfactoryworkerdirty(rdram, ctx);
        goto after_13;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808004D0: b           L_8080060C
    // 0x808004D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080060C;
    // 0x808004D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004D8:
    // 0x808004D8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x808004DC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808004E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004E4: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x808004E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808004EC: jal         0x80089F20
    // 0x808004F0: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808004F0: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_14:
    // 0x808004F4: b           L_8080060C
    // 0x808004F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080060C;
    // 0x808004F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004FC:
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: jal         0x808000AC
    // 0x80800504: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_15;
    // 0x80800504: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x80800508: b           L_8080060C
    // 0x8080050C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080060C;
    // 0x8080050C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800510:
    // 0x80800510: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x80800514: jal         0x800C0638
    // 0x80800518: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    func_800C0638(rdram, ctx);
        goto after_16;
    // 0x80800518: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_16:
    // 0x8080051C: bne         $v0, $zero, L_80800548
    if (ctx->r2 != 0) {
        // 0x80800520: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800548;
    }
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: lui         $a1, 0x3EEB
    ctx->r5 = S32(0X3EEB << 16);
    // 0x80800528: jal         0x80101E14
    // 0x8080052C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x8080052C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_17:
    // 0x80800530: beq         $v0, $zero, L_80800548
    if (ctx->r2 == 0) {
        // 0x80800534: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800548;
    }
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0XFC0) << 16);
    // 0x8080053C: addiu       $a2, $a2, 0xFC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0XFC0));
    // 0x80800540: jal         0x80089D18
    // 0x80800544: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80800544: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_18:
L_80800548:
    // 0x80800548: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8080054C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800550: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80800554: lwc1        $f12, 0x8($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80800558: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080055C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80800560: nop

    // 0x80800564: bc1fl       L_808005E0
    if (!c1cs) {
        // 0x80800568: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_808005E0;
    }
    goto skip_0;
    // 0x80800568: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    skip_0:
    // 0x8080056C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800570: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800574: jal         0x800F10B4
    // 0x80800578: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x80800578: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x8080057C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800580: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2168, 0XF40) << 16);
    // 0x80800584: addiu       $t7, $t7, 0xF40
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2168, 0XF40));
    // 0x80800588: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080058C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800590: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800594: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800598: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8080059C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808005A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808005A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005A8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808005AC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808005B0: jal         0x800BBCB8
    // 0x808005B4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800BBCB8(rdram, ctx);
        goto after_20;
    // 0x808005B4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_20:
    // 0x808005B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808005BC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808005C0: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x808005C4: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x808005C8: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x808005CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005D0: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808005D4: jal         0x800D9078
    // 0x808005D8: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    func_800D9078(rdram, ctx);
        goto after_21;
    // 0x808005D8: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    after_21:
    // 0x808005DC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
L_808005E0:
    // 0x808005E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808005E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005E8: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x808005EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808005F0: jal         0x80089F20
    // 0x808005F4: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x808005F4: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_22:
    // 0x808005F8: jal         0x80800994
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800994_chfactoryworkerdirty(rdram, ctx);
        goto after_23;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800600: jal         0x80800700
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800700_chfactoryworkerdirty(rdram, ctx);
        goto after_24;
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
L_80800608:
    // 0x80800608: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080060C:
    // 0x8080060C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800610: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800614: jr          $ra
    // 0x80800618: nop

    return;
    // 0x80800618: nop

;}
RECOMP_FUNC void _plcamera_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878C0: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878C0);
    return;
    // 0x800878C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcextra_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: jr          $ra
    // 0x80800028: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80800028: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
;}
RECOMP_FUNC void func_80800194_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x808001A0: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x808001A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808001A8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x808001AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001B0: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x808001B4: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001B8: lwc1        $f14, 0x28($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X28);
    // 0x808001BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808001C0: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x808001C4: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x808001C8: beql        $v0, $a0, L_808001F8
    if (ctx->r2 == ctx->r4) {
        // 0x808001CC: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_808001F8;
    }
    goto skip_0;
    // 0x808001CC: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_0:
    // 0x808001D0: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_808001D4:
    // 0x808001D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808001D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001DC: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x808001E0: lwc1        $f14, 0x28($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X28);
    // 0x808001E4: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x808001E8: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x808001EC: bnel        $v0, $a0, L_808001D4
    if (ctx->r2 != ctx->r4) {
        // 0x808001F0: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_808001D4;
    }
    goto skip_1;
    // 0x808001F0: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_1:
    // 0x808001F4: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_808001F8:
    // 0x808001F8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001FC: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x80800200: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    // 0x80800204: jal         0x800C8D4C
    // 0x80800208: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800C8D4C(rdram, ctx);
        goto after_0;
    // 0x80800208: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800210: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void baairbar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0xE9
    ctx->r4 = ADD32(0, 0XE9);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_80800030
    if (ctx->r2 == 0) {
        // 0x8080001C: nop
    
            goto L_80800030;
    }
    // 0x8080001C: nop

    // 0x80800020: jal         0x80088240
    // 0x80800024: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    _gclevel_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80800028: bnel        $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x8080002C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800090;
    }
    goto skip_0;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800030:
    // 0x80800030: jal         0x8008DAA8
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008DAA8(rdram, ctx);
        goto after_2;
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800038: beql        $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x8080003C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800090;
    }
    goto skip_1;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800040: jal         0x800F8B88
    // 0x80800044: nop

    func_800F8B88(rdram, ctx);
        goto after_3;
    // 0x80800044: nop

    after_3:
    // 0x80800048: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080004C: beql        $v0, $at, L_80800090
    if (ctx->r2 == ctx->r1) {
        // 0x80800050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800090;
    }
    goto skip_2;
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800054: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080005C: beq         $v0, $at, L_80800074
    if (ctx->r2 == ctx->r1) {
        // 0x80800060: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800074;
    }
    // 0x80800060: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800064: beq         $v0, $at, L_80800084
    if (ctx->r2 == ctx->r1) {
        // 0x80800068: nop
    
            goto L_80800084;
    }
    // 0x80800068: nop

    // 0x8080006C: b           L_80800090
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800090;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: jal         0x800CF494
    // 0x80800078: nop

    func_800CF494(rdram, ctx);
        goto after_4;
    // 0x80800078: nop

    after_4:
    // 0x8080007C: b           L_80800090
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800090;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800084:
    // 0x80800084: jal         0x800CF2D4
    // 0x80800088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CF2D4(rdram, ctx);
        goto after_5;
    // 0x80800088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800090:
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_800E9054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9054: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800E9058: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800E905C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800E9060: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E9064: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800E9068: jr          $ra
    // 0x800E906C: lh          $v0, 0x1CF6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X1CF6);
    return;
    // 0x800E906C: lh          $v0, 0x1CF6($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X1CF6);
;}
RECOMP_FUNC void func_80800000_chhoneycarrier(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X1A);
    // 0x80800010: srl         $t6, $a0, 5
    ctx->r14 = S32(U32(ctx->r4) >> 5);
    // 0x80800014: jal         0x800F4B4C
    // 0x80800018: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F4B4C(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8080001C: beql        $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $zero, 0x663
    ctx->r4 = ADD32(0, 0X663);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $zero, 0x663
    ctx->r4 = ADD32(0, 0X663);
    after_1:
    // 0x8080002C: bne         $v0, $zero, L_808000B4
    if (ctx->r2 != 0) {
        // 0x80800030: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808000B4;
    }
    // 0x80800030: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: lw          $v0, 0x6C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X6C);
    // 0x80800038: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x8080003C: beql        $t8, $zero, L_80800050
    if (ctx->r24 == 0) {
        // 0x80800040: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800050;
    }
    goto skip_1;
    // 0x80800040: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80800044: jal         0x800C8B84
    // 0x80800048: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800C8B84(rdram, ctx);
        goto after_2;
    // 0x80800048: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x8080004C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80800050:
    // 0x80800050: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800054: lwc1        $f4, 0x50($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X50);
    // 0x80800058: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080005C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800060: jal         0x800D0BD4
    // 0x80800064: nop

    func_800D0BD4(rdram, ctx);
        goto after_3;
    // 0x80800064: nop

    after_3:
    // 0x80800068: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8080006C: jal         0x800FC63C
    // 0x80800070: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    func_800FC63C(rdram, ctx);
        goto after_4;
    // 0x80800070: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    after_4:
    // 0x80800074: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800078: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080007C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80800080: addiu       $a1, $a1, -0x5D68
    ctx->r5 = ADD32(ctx->r5, -0X5D68);
    // 0x80800084: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800088: jal         0x800C9E20
    // 0x8080008C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C9E20(rdram, ctx);
        goto after_5;
    // 0x8080008C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800090: jal         0x800D1844
    // 0x80800094: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    func_800D1844(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_6:
    // 0x80800098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A0: jal         0x800888C8
    // 0x808000A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808000A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x808000A8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: jal         0x800FFA88
    // 0x808000B0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808000B0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_8:
L_808000B4:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B8:
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_800DD4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD4AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DD4B0: lw          $t6, -0x37BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X37BC);
    // 0x800DD4B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DD4B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD4BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800DD4C0: beq         $t6, $zero, L_800DD4F4
    if (ctx->r14 == 0) {
        // 0x800DD4C4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800DD4F4;
    }
    // 0x800DD4C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800DD4C8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DD4CC: lw          $a2, -0x36B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X36B8);
    // 0x800DD4D0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800DD4D4: jal         0x800EFA20
    // 0x800DD4D8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EFA20(rdram, ctx);
        goto after_0;
    // 0x800DD4D8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800DD4DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD4E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD4E4: lw          $a0, -0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37BC);
    // 0x800DD4E8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800DD4EC: jal         0x800DC028
    // 0x800DD4F0: lh          $a1, 0x8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X8);
    func_800DC028(rdram, ctx);
        goto after_1;
    // 0x800DD4F0: lh          $a1, 0x8($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X8);
    after_1:
L_800DD4F4:
    // 0x800DD4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD4F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DD4FC: jr          $ra
    // 0x800DD500: nop

    return;
    // 0x800DD500: nop

;}
RECOMP_FUNC void _badrone_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084870: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084870);
    return;
    // 0x80084874: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void bsstand_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800CAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800124_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800128: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080012C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800130: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800134: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800138: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080013C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800140: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800144: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800148: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080014C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800150: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800154: jal         0x80087D98
    // 0x80800158: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_0;
    // 0x80800158: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_0:
    // 0x8080015C: lw          $t6, 0x1C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1C);
    // 0x80800160: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800164: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80800168: blez        $t6, L_808001D0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080016C: lui         $s3, 0x8080
        ctx->r19 = S32(RELOC_HI16(780, 0X10B0) << 16);
            goto L_808001D0;
    }
    // 0x8080016C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(780, 0X10B0) << 16);
    // 0x80800170: addiu       $s3, $s3, 0x10B0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(780, 0X10B0));
    // 0x80800174: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800178:
    // 0x80800178: jal         0x80800064
    // 0x8080017C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800064_chwarppad(rdram, ctx);
        goto after_1;
    // 0x8080017C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800180: beql        $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x80800184: lw          $t2, 0x1C($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X1C);
            goto L_808001C0;
    }
    goto skip_0;
    // 0x80800184: lw          $t2, 0x1C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1C);
    skip_0:
    // 0x80800188: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080018C: lw          $t7, 0x28($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X28);
    // 0x80800190: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800194: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800198: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080019C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808001A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001A4: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x808001A8: mflo        $t0
    ctx->r8 = lo;
    // 0x808001AC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x808001B0: jal         0x80087D90
    // 0x808001B4: lbu         $a2, 0x5($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X5);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x808001B4: lbu         $a2, 0x5($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X5);
    after_2:
    // 0x808001B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808001BC: lw          $t2, 0x1C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1C);
L_808001C0:
    // 0x808001C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001C4: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x808001C8: beql        $at, $zero, L_80800178
    if (ctx->r1 == 0) {
        // 0x808001CC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800178;
    }
    goto skip_1;
    // 0x808001CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_808001D0:
    // 0x808001D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808001E8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808001EC: jr          $ra
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8008E4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E4B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008E4BC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008E4C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008E4C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008E4C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008E4CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8008E4D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008E4D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008E4D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008E4DC: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_8008E4E0:
    // 0x8008E4E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008E4E4: jal         0x8009E138
    // 0x8008E4E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8009E138(rdram, ctx);
        goto after_0;
    // 0x8008E4E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8008E4EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8008E4F0: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x8008E4F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008E4F8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8008E4FC: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8008E500: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8008E504: bne         $s0, $s3, L_8008E4E0
    if (ctx->r16 != ctx->r19) {
        // 0x8008E508: sw          $t7, 0xC($t9)
        MEM_W(0XC, ctx->r25) = ctx->r15;
            goto L_8008E4E0;
    }
    // 0x8008E508: sw          $t7, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r15;
    // 0x8008E50C: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x8008E510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008E514: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E518: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008E51C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008E520: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008E524: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008E528: jr          $ra
    // 0x8008E52C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    return;
    // 0x8008E52C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
;}
RECOMP_FUNC void func_8080145C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80801460: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801464: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080146C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80801470: jal         0x8009D3A8
    // 0x80801474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80801474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801478: lui         $a1, 0x3C47
    ctx->r5 = S32(0X3C47 << 16);
    // 0x8080147C: ori         $a1, $a1, 0xE282
    ctx->r5 = ctx->r5 | 0XE282;
    // 0x80801480: jal         0x8008CB10
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801488: bne         $v0, $zero, L_808014A4
    if (ctx->r2 != 0) {
        // 0x8080148C: lui         $a1, 0x3F03
        ctx->r5 = S32(0X3F03 << 16);
            goto L_808014A4;
    }
    // 0x8080148C: lui         $a1, 0x3F03
    ctx->r5 = S32(0X3F03 << 16);
    // 0x80801490: ori         $a1, $a1, 0x1F8A
    ctx->r5 = ctx->r5 | 0X1F8A;
    // 0x80801494: jal         0x8008CB10
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80801498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080149C: beq         $v0, $zero, L_808015A8
    if (ctx->r2 == 0) {
        // 0x808014A0: nop
    
            goto L_808015A8;
    }
    // 0x808014A0: nop

L_808014A4:
    // 0x808014A4: jal         0x800B5BE4
    // 0x808014A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_3;
    // 0x808014A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x808014AC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014B4: jal         0x8009C128
    // 0x808014B8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x808014B8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808014C4: jal         0x80092C90
    // 0x808014C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80092C90(rdram, ctx);
        goto after_5;
    // 0x808014C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x808014CC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808014D0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808014D4: jal         0x800EFB24
    // 0x808014D8: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x808014D8: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_6:
    // 0x808014DC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808014E0: jal         0x800F1A88
    // 0x808014E4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800F1A88(rdram, ctx);
        goto after_7;
    // 0x808014E4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_7:
    // 0x808014E8: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808014EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808014F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808014F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808014F8: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808014FC: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80801500: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x80801504: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801508: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8080150C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801510: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80801514: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80801518: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    // 0x8080151C: add.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80801520: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801524: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801528: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080152C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801530: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80801534: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80801538: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8080153C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80801540: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80801544: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80801548: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x8080154C: jal         0x800BA994
    // 0x80801550: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800BA994(rdram, ctx);
        goto after_8;
    // 0x80801550: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_8:
    // 0x80801554: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801558: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1B58) << 16);
    // 0x8080155C: jal         0x800DC178
    // 0x80801560: lwc1        $f14, 0x1B58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1B58));
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80801560: lwc1        $f14, 0x1B58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1B58));
    after_9:
    // 0x80801564: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801568: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080156C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801574: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80801578: nop

    // 0x8080157C: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80801580: jal         0x800BA77C
    // 0x80801584: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_10;
    // 0x80801584: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    after_10:
    // 0x80801588: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(427, 0X1D0C) << 16);
    // 0x8080158C: addiu       $t8, $t8, 0x1D0C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(427, 0X1D0C));
    // 0x80801590: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801594: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801598: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8080159C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808015A0: jal         0x800BABB8
    // 0x808015A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_11;
    // 0x808015A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_11:
L_808015A8:
    // 0x808015A8: jal         0x808000BC
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bsvan(rdram, ctx);
        goto after_12;
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808015B0: jal         0x8009EF10
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_13;
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808015B8: blez        $v0, L_808015C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808015BC: addiu       $t9, $zero, 0x116
        ctx->r25 = ADD32(0, 0X116);
            goto L_808015C4;
    }
    // 0x808015BC: addiu       $t9, $zero, 0x116
    ctx->r25 = ADD32(0, 0X116);
    // 0x808015C0: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
L_808015C4:
    // 0x808015C4: jal         0x8008E148
    // 0x808015C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_14;
    // 0x808015C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808015CC: beq         $v0, $zero, L_808015E0
    if (ctx->r2 == 0) {
        // 0x808015D0: nop
    
            goto L_808015E0;
    }
    // 0x808015D0: nop

    // 0x808015D4: jal         0x800848B0
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_15;
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808015DC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
L_808015E0:
    // 0x808015E0: jal         0x8008E35C
    // 0x808015E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_16;
    // 0x808015E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808015E8: beq         $v0, $zero, L_808015F8
    if (ctx->r2 == 0) {
        // 0x808015EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015F8;
    }
    // 0x808015EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015F0: addiu       $t0, $zero, 0x11D
    ctx->r8 = ADD32(0, 0X11D);
    // 0x808015F4: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
L_808015F8:
    // 0x808015F8: jal         0x80800064
    // 0x808015FC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    func_80800064_bsvan(rdram, ctx);
        goto after_17;
    // 0x808015FC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_17:
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801604: jal         0x800A02DC
    // 0x80801608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A02DC(rdram, ctx);
        goto after_18;
    // 0x80801608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x8080160C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80801610: jal         0x808003BC
    // 0x80801614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsvan_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80801614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080161C: jal         0x8009E5C8
    // 0x80801620: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x80801620: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_20:
    // 0x80801624: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801628: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080162C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80801630: jr          $ra
    // 0x80801634: nop

    return;
    // 0x80801634: nop

;}
RECOMP_FUNC void func_80800824_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800828: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080082C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800830: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800834: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800838: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8080083C: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80800840: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800844: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800848: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080084C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800850: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800854: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800858: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080085C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800860: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800864: jal         0x80100094
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080086C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800870: blez        $s6, L_80800940
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80800874: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800940;
    }
    // 0x80800874: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800878: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8080087C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800880: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x80800884: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80800888: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080088C: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80800890: addu        $fp, $t8, $t7
    ctx->r30 = ADD32(ctx->r24, ctx->r15);
    // 0x80800894: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80800898: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
L_8080089C:
    // 0x8080089C: sll         $t9, $s2, 4
    ctx->r25 = S32(ctx->r18 << 4);
    // 0x808008A0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x808008A4: beql        $fp, $v0, L_80800938
    if (ctx->r30 == ctx->r2) {
        // 0x808008A8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800938;
    }
    goto skip_0;
    // 0x808008A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x808008AC: multu       $s2, $s4
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008B0: mflo        $t1
    ctx->r9 = lo;
    // 0x808008B4: addu        $s1, $t1, $s5
    ctx->r17 = ADD32(ctx->r9, ctx->r21);
    // 0x808008B8: lwc1        $f4, 0x58($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X58);
    // 0x808008BC: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x808008C0: nop

    // 0x808008C4: bc1fl       L_80800938
    if (!c1cs) {
        // 0x808008C8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800938;
    }
    goto skip_1;
    // 0x808008C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x808008CC: lh          $t2, 0xE($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XE);
    // 0x808008D0: beq         $s7, $t2, L_808008E4
    if (ctx->r23 == ctx->r10) {
        // 0x808008D4: nop
    
            goto L_808008E4;
    }
    // 0x808008D4: nop

    // 0x808008D8: lh          $t3, 0xE($fp)
    ctx->r11 = MEM_H(ctx->r30, 0XE);
    // 0x808008DC: bnel        $s2, $t3, L_80800938
    if (ctx->r18 != ctx->r11) {
        // 0x808008E0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800938;
    }
    goto skip_2;
    // 0x808008E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
L_808008E4:
    // 0x808008E4: multu       $s7, $s4
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008EC: addiu       $s3, $s1, 0x24
    ctx->r19 = ADD32(ctx->r17, 0X24);
    // 0x808008F0: mflo        $t4
    ctx->r12 = lo;
    // 0x808008F4: addu        $s0, $t4, $s5
    ctx->r16 = ADD32(ctx->r12, ctx->r21);
    // 0x808008F8: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800900: jal         0x800EEAD4
    // 0x80800904: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x80800904: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x80800908: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080090C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800910: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800914: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800918: jal         0x800EE7F8
    // 0x8080091C: swc1        $f10, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080091C: swc1        $f10, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f10.u32l;
    after_2:
    // 0x80800920: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800924: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80800928: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8080092C: jal         0x80800824
    // 0x80800930: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_80800824_chnewfreezy(rdram, ctx);
        goto after_3;
    // 0x80800930: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80800934: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800938:
    // 0x80800938: bnel        $s2, $s6, L_8080089C
    if (ctx->r18 != ctx->r22) {
        // 0x8080093C: lw          $t0, 0x48($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X48);
            goto L_8080089C;
    }
    goto skip_3;
    // 0x8080093C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    skip_3:
L_80800940:
    // 0x80800940: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800944: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800948: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080094C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800950: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800954: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800958: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080095C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800960: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800964: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80800968: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8080096C: jr          $ra
    // 0x80800970: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800970: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80801178_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801178: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080117C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801188: jal         0x80100094
    // 0x8080118C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080118C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801190: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801194: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080119C: jal         0x8008A0E8
    // 0x808011A0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808011A0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808011AC: jal         0x80089FE8
    // 0x808011B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808011B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x808011B4: beq         $v0, $zero, L_808011E8
    if (ctx->r2 == 0) {
        // 0x808011B8: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_808011E8;
    }
    // 0x808011B8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808011BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808011C0: jal         0x800F54E4
    // 0x808011C4: sw          $t6, 0x824($t7)
    MEM_W(0X824, ctx->r15) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808011C4: sw          $t6, 0x824($t7)
    MEM_W(0X824, ctx->r15) = ctx->r14;
    after_3:
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808011D0: jal         0x800F8300
    // 0x808011D4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_4;
    // 0x808011D4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808011D8: jal         0x800DA544
    // 0x808011DC: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808011DC: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_5:
    // 0x808011E0: b           L_808011EC
    // 0x808011E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011EC;
    // 0x808011E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011E8:
    // 0x808011E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011EC:
    // 0x808011EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808011F8: jr          $ra
    // 0x808011FC: nop

    return;
    // 0x808011FC: nop

;}
RECOMP_FUNC void func_800B52EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B52EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B52F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B52F4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800B52F8: addiu       $s3, $s3, 0x7F18
    ctx->r19 = ADD32(ctx->r19, 0X7F18);
    // 0x800B52FC: lh          $t6, 0x0($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X0);
    // 0x800B5300: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B5304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B5308: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800B530C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B5310: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B5314: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B5318: blez        $t6, L_800B535C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B531C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B535C;
    }
    // 0x800B531C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B5320: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800B5324: addiu       $s4, $s4, 0x7F10
    ctx->r20 = ADD32(ctx->r20, 0X7F10);
    // 0x800B5328: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B532C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
L_800B5330:
    // 0x800B5330: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B5334: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B5338: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800B533C: jal         0x800BC358
    // 0x800B5340: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800BC358(rdram, ctx);
        goto after_0;
    // 0x800B5340: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x800B5344: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x800B5348: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B534C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800B5350: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B5354: bnel        $at, $zero, L_800B5330
    if (ctx->r1 != 0) {
        // 0x800B5358: lw          $t7, 0x0($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X0);
            goto L_800B5330;
    }
    goto skip_0;
    // 0x800B5358: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    skip_0:
L_800B535C:
    // 0x800B535C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B5364: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5368: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B536C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B5370: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B5374: jr          $ra
    // 0x800B5378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B5378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080093C_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800940: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800948: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080094C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800950: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800954: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800958: jal         0x8008A0E0
    // 0x8080095C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080095C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x80800960: beq         $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800964: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_80800A9C;
    }
    // 0x80800964: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800968: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080096C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800970: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800974: jal         0x800DC178
    // 0x80800978: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800978: nop

    after_1:
    // 0x8080097C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800980: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800984: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800988: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080098C: jal         0x800DC178
    // 0x80800990: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800990: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800994: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800998: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080099C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808009A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009A4: jal         0x800DC178
    // 0x808009A8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808009A8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x808009AC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808009B0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808009B4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808009B8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808009BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808009C0: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808009C4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808009C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808009CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808009D0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808009D4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808009D8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808009DC: jal         0x800EFA4C
    // 0x808009E0: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808009E0: nop

    after_4:
    // 0x808009E4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808009E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808009EC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808009F0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808009F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808009F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808009FC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800A00: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800A04: jal         0x800889D0
    // 0x80800A08: nop

    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800A08: nop

    after_5:
    // 0x80800A0C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800A10: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800A14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A18: lwc1        $f2, 0x48($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800A1C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800A20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A24: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800A28: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800A2C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A34: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800A38: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800A3C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800A40: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800A44: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80800A48: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800A4C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800A50: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80800A54: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800A58: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80800A5C: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800A60: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800A64: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x80800A68: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800A6C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800A70: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800A74: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80800A78: sll         $t3, $a3, 16
    ctx->r11 = S32(ctx->r7 << 16);
    // 0x80800A7C: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800A80: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80800A84: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800A88: jal         0x800BA994
    // 0x80800A8C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_800BA994(rdram, ctx);
        goto after_6;
    // 0x80800A8C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_6:
    // 0x80800A90: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800A94: jal         0x800BA22C
    // 0x80800A98: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80800A98: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_7:
L_80800A9C:
    // 0x80800A9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AA0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800AA4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800AA8: jr          $ra
    // 0x80800AAC: nop

    return;
    // 0x80800AAC: nop

;}
RECOMP_FUNC void func_8001E4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4B0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001E4B4: lw          $t6, -0x16B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X16B8);
    // 0x8001E4B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E4BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E4C0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x8001E4C4: beq         $at, $zero, L_8001E560
    if (ctx->r1 == 0) {
        // 0x8001E4C8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8001E560;
    }
    // 0x8001E4C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E4CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001E4D0: addu        $at, $at, $t6
    gpr jr_addend_8001E4D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001E4D4: lw          $t6, 0x1920($at)
    ctx->r14 = ADD32(ctx->r1, 0X1920);
    // 0x8001E4D8: jr          $t6
    // 0x8001E4DC: nop

    switch (jr_addend_8001E4D8 >> 2) {
        case 0: goto L_8001E4E0; break;
        case 1: goto L_8001E4F0; break;
        case 2: goto L_8001E500; break;
        case 3: goto L_8001E510; break;
        case 4: goto L_8001E520; break;
        case 5: goto L_8001E530; break;
        case 6: goto L_8001E540; break;
        case 7: goto L_8001E550; break;
        default: switch_error(__func__, 0x8001E4D8, 0x80041920);
    }
    // 0x8001E4DC: nop

L_8001E4E0:
    // 0x8001E4E0: jal         0x8001E2C8
    // 0x8001E4E4: nop

    func_8001E2C8(rdram, ctx);
        goto after_0;
    // 0x8001E4E4: nop

    after_0:
    // 0x8001E4E8: b           L_8001E56C
    // 0x8001E4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E4F0:
    // 0x8001E4F0: jal         0x8001E304
    // 0x8001E4F4: nop

    func_8001E304(rdram, ctx);
        goto after_1;
    // 0x8001E4F4: nop

    after_1:
    // 0x8001E4F8: b           L_8001E56C
    // 0x8001E4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E500:
    // 0x8001E500: jal         0x8001E34C
    // 0x8001E504: nop

    func_8001E34C(rdram, ctx);
        goto after_2;
    // 0x8001E504: nop

    after_2:
    // 0x8001E508: b           L_8001E56C
    // 0x8001E50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E510:
    // 0x8001E510: jal         0x8001E380
    // 0x8001E514: nop

    func_8001E380(rdram, ctx);
        goto after_3;
    // 0x8001E514: nop

    after_3:
    // 0x8001E518: b           L_8001E56C
    // 0x8001E51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E520:
    // 0x8001E520: jal         0x8001E418
    // 0x8001E524: nop

    func_8001E418(rdram, ctx);
        goto after_4;
    // 0x8001E524: nop

    after_4:
    // 0x8001E528: b           L_8001E56C
    // 0x8001E52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E530:
    // 0x8001E530: jal         0x8001E3E0
    // 0x8001E534: nop

    func_8001E3E0(rdram, ctx);
        goto after_5;
    // 0x8001E534: nop

    after_5:
    // 0x8001E538: b           L_8001E56C
    // 0x8001E53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E540:
    // 0x8001E540: jal         0x8001E44C
    // 0x8001E544: nop

    func_8001E44C(rdram, ctx);
        goto after_6;
    // 0x8001E544: nop

    after_6:
    // 0x8001E548: b           L_8001E56C
    // 0x8001E54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E550:
    // 0x8001E550: jal         0x8001E490
    // 0x8001E554: nop

    func_8001E490(rdram, ctx);
        goto after_7;
    // 0x8001E554: nop

    after_7:
    // 0x8001E558: b           L_8001E56C
    // 0x8001E55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001E56C;
    // 0x8001E55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E560:
    // 0x8001E560: jal         0x8001E3A0
    // 0x8001E564: nop

    func_8001E3A0(rdram, ctx);
        goto after_8;
    // 0x8001E564: nop

    after_8:
    // 0x8001E568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E56C:
    // 0x8001E56C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E570: jr          $ra
    // 0x8001E574: nop

    return;
    // 0x8001E574: nop

;}
RECOMP_FUNC void func_800EC75C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC75C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800EC760: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EC764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EC768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EC76C: jal         0x800EC708
    // 0x800EC770: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800EC708(rdram, ctx);
        goto after_0;
    // 0x800EC770: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800EC774: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800EC778: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800EC77C: jal         0x800EE88C
    // 0x800EC780: addiu       $a1, $s0, 0x1E
    ctx->r5 = ADD32(ctx->r16, 0X1E);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x800EC780: addiu       $a1, $s0, 0x1E
    ctx->r5 = ADD32(ctx->r16, 0X1E);
    after_1:
    // 0x800EC784: lhu         $t6, 0x18($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X18);
    // 0x800EC788: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800EC78C: beql        $t7, $zero, L_800EC7AC
    if (ctx->r15 == 0) {
        // 0x800EC790: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800EC7AC;
    }
    goto skip_0;
    // 0x800EC790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800EC794: jal         0x80106790
    // 0x800EC798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x800EC798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800EC79C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800EC7A0: jal         0x800EF334
    // 0x800EC7A4: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x800EC7A4: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_3:
    // 0x800EC7A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800EC7AC:
    // 0x800EC7AC: jal         0x800EC398
    // 0x800EC7B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EC398(rdram, ctx);
        goto after_4;
    // 0x800EC7B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x800EC7B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800EC7B8: jal         0x800EF04C
    // 0x800EC7BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x800EC7BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x800EC7C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EC7C4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800EC7C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EC7CC: jr          $ra
    // 0x800EC7D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800EC7D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void baattach_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800054: jal         0x80800098
    // 0x80800058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    baattach_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_80800068_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800074: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800078: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800084: bnel        $t7, $at, L_80800098
    if (ctx->r15 != ctx->r1) {
        // 0x80800088: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800098;
    }
    goto skip_0;
    // 0x80800088: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8080008C: jal         0x80800214
    // 0x80800090: nop

    func_80800214_chboggykidshome(rdram, ctx);
        goto after_0;
    // 0x80800090: nop

    after_0:
    // 0x80800094: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800098:
    // 0x80800098: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8080009C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x808000A0: jal         0x80089F18
    // 0x808000A4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000A4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_1:
    // 0x808000A8: jal         0x80089828
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000B8: jal         0x800897D8
    // 0x808000BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808000C0: jal         0x80800300
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_chboggykidshome(rdram, ctx);
        goto after_4;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_808000C8_gcintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2642, 0X250) << 16);
    // 0x808000CC: lw          $t6, 0x250($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(2642, 0X250));
    // 0x808000D0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2642, 0X254) << 16);
    // 0x808000D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2642, 0X250) << 16);
    // 0x808000D8: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x808000DC: bne         $a0, $t7, L_808000EC
    if (ctx->r4 != ctx->r15) {
        // 0x808000E0: nop
    
            goto L_808000EC;
    }
    // 0x808000E0: nop

    // 0x808000E4: jr          $ra
    // 0x808000E8: addiu       $v0, $v0, 0x250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X250));
    return;
    // 0x808000E8: addiu       $v0, $v0, 0x250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X250));
L_808000EC:
    // 0x808000EC: lw          $t8, 0x254($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(2642, 0X254));
    // 0x808000F0: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2642, 0X258) << 16);
    // 0x808000F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2642, 0X254) << 16);
    // 0x808000F8: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x808000FC: bne         $a0, $t9, L_8080010C
    if (ctx->r4 != ctx->r25) {
        // 0x80800100: nop
    
            goto L_8080010C;
    }
    // 0x80800100: nop

    // 0x80800104: jr          $ra
    // 0x80800108: addiu       $v0, $v0, 0x254
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X254));
    return;
    // 0x80800108: addiu       $v0, $v0, 0x254
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X254));
L_8080010C:
    // 0x8080010C: lw          $t0, 0x258($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(2642, 0X258));
    // 0x80800110: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2642, 0X25C) << 16);
    // 0x80800114: addiu       $v1, $v1, 0x25C
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2642, 0X25C));
    // 0x80800118: srl         $t1, $t0, 22
    ctx->r9 = S32(U32(ctx->r8) >> 22);
    // 0x8080011C: bne         $a0, $t1, L_80800130
    if (ctx->r4 != ctx->r9) {
        // 0x80800120: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(2642, 0X56C) << 16);
            goto L_80800130;
    }
    // 0x80800120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2642, 0X56C) << 16);
    // 0x80800124: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2642, 0X258) << 16);
    // 0x80800128: jr          $ra
    // 0x8080012C: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X258));
    return;
    // 0x8080012C: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X258));
L_80800130:
    // 0x80800130: addiu       $v0, $v0, 0x56C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2642, 0X56C));
    // 0x80800134: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
L_80800138:
    // 0x80800138: srl         $t3, $t2, 22
    ctx->r11 = S32(U32(ctx->r10) >> 22);
    // 0x8080013C: bnel        $a0, $t3, L_80800150
    if (ctx->r4 != ctx->r11) {
        // 0x80800140: lw          $t4, 0x4($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X4);
            goto L_80800150;
    }
    goto skip_0;
    // 0x80800140: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80800144: jr          $ra
    // 0x80800148: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800148: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080014C: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
L_80800150:
    // 0x80800150: srl         $t5, $t4, 22
    ctx->r13 = S32(U32(ctx->r12) >> 22);
    // 0x80800154: bnel        $a0, $t5, L_80800168
    if (ctx->r4 != ctx->r13) {
        // 0x80800158: lw          $t6, 0x8($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X8);
            goto L_80800168;
    }
    goto skip_1;
    // 0x80800158: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x8080015C: jr          $ra
    // 0x80800160: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    return;
    // 0x80800160: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x80800164: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
L_80800168:
    // 0x80800168: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x8080016C: bnel        $a0, $t7, L_80800180
    if (ctx->r4 != ctx->r15) {
        // 0x80800170: lw          $t8, 0xC($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XC);
            goto L_80800180;
    }
    goto skip_2;
    // 0x80800170: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    skip_2:
    // 0x80800174: jr          $ra
    // 0x80800178: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    return;
    // 0x80800178: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8080017C: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
L_80800180:
    // 0x80800180: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800184: bnel        $a0, $t9, L_80800198
    if (ctx->r4 != ctx->r25) {
        // 0x80800188: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80800198;
    }
    goto skip_3;
    // 0x80800188: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_3:
    // 0x8080018C: jr          $ra
    // 0x80800190: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    return;
    // 0x80800190: addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // 0x80800194: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80800198:
    // 0x80800198: bnel        $v1, $v0, L_80800138
    if (ctx->r3 != ctx->r2) {
        // 0x8080019C: lw          $t2, 0x0($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X0);
            goto L_80800138;
    }
    goto skip_4;
    // 0x8080019C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x808001A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void cheggice_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080033C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800340: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800344: jal         0x8008A488
    // 0x80800348: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800348: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080034C: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    // 0x80800350: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800354: jal         0x8008A3D0
    // 0x80800358: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800358: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8080035C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800360: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800364: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080036C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800370: jal         0x8008A460
    // 0x80800374: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800374: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x80800378: lui         $a2, 0xC7C3
    ctx->r6 = S32(0XC7C3 << 16);
    // 0x8080037C: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x8008A468
    // 0x80800388: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800388: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x8008A380
    // 0x80800394: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _suegg_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800394: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_4:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x8008A470
    // 0x808003A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808003A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808003A4: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x808003A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808003AC: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x808003B0: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x808003B4: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x808003B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003C4: jr          $ra
    // 0x808003C8: nop

    return;
    // 0x808003C8: nop

    // 0x808003CC: nop

;}
RECOMP_FUNC void func_80800018_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: jal         0x800F54E4
    // 0x80800034: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800034: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080003C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800040: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x80800044: jal         0x8010D12C
    // 0x80800048: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_8010D12C(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x8080004C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800050: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80800054: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800058: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080005C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800060: beq         $v1, $a0, L_80800090
    if (ctx->r3 == ctx->r4) {
        // 0x80800064: lwc1        $f18, -0x4($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
            goto L_80800090;
    }
    // 0x80800064: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80800068: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
L_8080006C:
    // 0x8080006C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800070: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800074: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800078: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8080007C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800080: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x80800084: lwc1        $f18, -0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80800088: bnel        $v1, $a0, L_8080006C
    if (ctx->r3 != ctx->r4) {
        // 0x8080008C: sub.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
            goto L_8080006C;
    }
    goto skip_0;
    // 0x8080008C: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    skip_0:
L_80800090:
    // 0x80800090: sub.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800094: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800098: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080009C: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x808000A0: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x808000A4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808000A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000AC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808000B0: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808000B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000B8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808000BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000C0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808000C4: jal         0x800DC298
    // 0x808000C8: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x808000C8: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x808000CC: beq         $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000D0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808000E0;
    }
    // 0x808000D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808000D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000D8: b           L_808000F0
    // 0x808000DC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
        goto L_808000F0;
    // 0x808000DC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
L_808000E0:
    // 0x808000E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000E8: nop

    // 0x808000EC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
L_808000F0:
    // 0x808000F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000F4: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808000F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000FC: jal         0x800DC178
    // 0x80800100: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800100: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80800104: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800108: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080010C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800110: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800114: jal         0x800DC298
    // 0x80800118: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80800118: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x8080011C: beq         $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x80800120: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800134;
    }
    // 0x80800120: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800124: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800128: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080012C: b           L_80800140
    // 0x80800130: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
        goto L_80800140;
    // 0x80800130: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_80800134:
    // 0x80800134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800138: nop

    // 0x8080013C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_80800140:
    // 0x80800140: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800144: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800148: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080014C: jal         0x800DC178
    // 0x80800150: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800150: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x80800154: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800158: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080015C: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800160: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80800164: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800168: jal         0x800EE7F8
    // 0x8080016C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080016C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80800170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XBF0) << 16);
    // 0x80800174: lwc1        $f4, 0xBF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XBF0));
    // 0x80800178: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080017C: jal         0x800C8A98
    // 0x80800180: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    func_800C8A98(rdram, ctx);
        goto after_8;
    // 0x80800180: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    after_8:
    // 0x80800184: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800188: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1244, 0XCC0) << 16);
    // 0x8080018C: addiu       $a1, $a1, 0xCC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1244, 0XCC0));
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800194: jal         0x800C8E84
    // 0x80800198: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    func_800C8E84(rdram, ctx);
        goto after_9;
    // 0x80800198: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    after_9:
    // 0x8080019C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A0: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x808001A4: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x808001A8: jal         0x800C8E54
    // 0x808001AC: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    func_800C8E54(rdram, ctx);
        goto after_10;
    // 0x808001AC: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    after_10:
    // 0x808001B0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808001B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001B8: jal         0x800C8CB8
    // 0x808001BC: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    func_800C8CB8(rdram, ctx);
        goto after_11;
    // 0x808001BC: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    after_11:
    // 0x808001C0: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    // 0x808001C4: jal         0x80089C30
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808001CC: bne         $v0, $zero, L_808001F0
    if (ctx->r2 != 0) {
        // 0x808001D0: addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
            goto L_808001F0;
    }
    // 0x808001D0: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x808001D4: jal         0x800EFD24
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_13;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001DC: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    // 0x808001E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808001E8: jal         0x80108A30
    // 0x808001EC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_80108A30(rdram, ctx);
        goto after_14;
    // 0x808001EC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_14:
L_808001F0:
    // 0x808001F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_800C4308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C430C: swc1        $f12, -0x5790($at)
    MEM_W(-0X5790, ctx->r1) = ctx->f12.u32l;
    // 0x800C4310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4314: jr          $ra
    // 0x800C4318: swc1        $f14, -0x578C($at)
    MEM_W(-0X578C, ctx->r1) = ctx->f14.u32l;
    return;
    // 0x800C4318: swc1        $f14, -0x578C($at)
    MEM_W(-0X578C, ctx->r1) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80800000_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800A587C
    // 0x8080000C: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800014: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80800018: beq         $at, $zero, L_80800094
    if (ctx->r1 == 0) {
        // 0x8080001C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800094;
    }
    // 0x8080001C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(672, 0X1000) << 16);
    // 0x80800024: addu        $at, $at, $t6
    gpr jr_addend_8080002C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800028: lw          $t6, 0x1000($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(672, 0X1000));
    // 0x8080002C: jr          $t6
    // 0x80800030: nop

    switch (jr_addend_8080002C >> 2) {
        case 0: goto L_80800044; break;
        case 1: goto L_80800054; break;
        case 2: goto L_80800034; break;
        case 3: goto L_80800094; break;
        case 4: goto L_80800064; break;
        case 5: goto L_80800074; break;
        case 6: goto L_80800094; break;
        case 7: goto L_80800084; break;
        default: switch_error(__func__, 0x8080002C, 0x80801000);
    }
    // 0x80800030: nop

L_80800034:
    // 0x80800034: jal         0x800A586C
    // 0x80800038: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800038: nop

    after_1:
    // 0x8080003C: b           L_8080009C
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080009C;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: jal         0x800A586C
    // 0x80800048: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800048: nop

    after_2:
    // 0x8080004C: b           L_8080009C
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080009C;
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800054:
    // 0x80800054: jal         0x800A586C
    // 0x80800058: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x80800058: nop

    after_3:
    // 0x8080005C: b           L_8080009C
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080009C;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800064:
    // 0x80800064: jal         0x800A586C
    // 0x80800068: nop

    func_800A586C(rdram, ctx);
        goto after_4;
    // 0x80800068: nop

    after_4:
    // 0x8080006C: b           L_8080009C
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080009C;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: jal         0x800A586C
    // 0x80800078: nop

    func_800A586C(rdram, ctx);
        goto after_5;
    // 0x80800078: nop

    after_5:
    // 0x8080007C: b           L_8080009C
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080009C;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800084:
    // 0x80800084: jal         0x800A586C
    // 0x80800088: nop

    func_800A586C(rdram, ctx);
        goto after_6;
    // 0x80800088: nop

    after_6:
    // 0x8080008C: b           L_8080009C
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080009C;
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800094:
    // 0x80800094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_8080035C_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800364: jal         0x8010C500
    // 0x80800368: nop

    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800368: nop

    after_0:
    // 0x8080036C: beql        $v0, $zero, L_80800380
    if (ctx->r2 == 0) {
        // 0x80800370: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800380;
    }
    goto skip_0;
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800374: jal         0x800B7D28
    // 0x80800378: nop

    func_800B7D28(rdram, ctx);
        goto after_1;
    // 0x80800378: nop

    after_1:
    // 0x8080037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800380:
    // 0x80800380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800384: jr          $ra
    // 0x80800388: nop

    return;
    // 0x80800388: nop

;}
RECOMP_FUNC void bsvan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: jal         0x8009E74C
    // 0x80800104: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800104: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x80800108: bnel        $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x8080010C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800198;
    }
    goto skip_0;
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800110: jal         0x80085168
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bastatemem_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80092864
    // 0x80800120: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_2;
    // 0x80800120: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080012C: jal         0x800947EC
    // 0x80800130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_3;
    // 0x80800130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x8009BF5C
    // 0x8080013C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x8080013C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x8009C4CC
    // 0x80800148: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80800148: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x8080014C: jal         0x8009C000
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C000(rdram, ctx);
        goto after_6;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800154: jal         0x8009C570
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_resetAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080015C: jal         0x8009EF60
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_8;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800164: jal         0x80095A40
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_9;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080016C: jal         0x8009E474
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_10;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80095774
    // 0x8080017C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_11;
    // 0x8080017C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80095774
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_clear(rdram, ctx);
        goto after_12;
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x8080018C: jal         0x80085378
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bavan_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800198:
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void baanim_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C2A0: jr          $ra
    // 0x8008C2A4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    return;
    // 0x8008C2A4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80090938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009093C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090940: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80090944: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80090948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009094C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80090950: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80090954: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x80090958: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x8009095C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x80090960: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x80090964: jal         0x800908F0
    // 0x80090968: sb          $zero, 0x9($t9)
    MEM_B(0X9, ctx->r25) = 0;
    func_800908F0(rdram, ctx);
        goto after_0;
    // 0x80090968: sb          $zero, 0x9($t9)
    MEM_B(0X9, ctx->r25) = 0;
    after_0:
    // 0x8009096C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090974: jr          $ra
    // 0x80090978: nop

    return;
    // 0x80090978: nop

;}
RECOMP_FUNC void bsdronebubbled_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800258: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8080025C: jal         0x80084640
    // 0x80800260: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    _badata_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800260: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800264: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800268: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080026C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800270: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800274: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800278: jal         0x8008CB3C
    // 0x8080027C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080027C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800280: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800284: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800288: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800294: jal         0x8009FFD8
    // 0x80800298: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800298: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080038C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1E60) << 16);
    // 0x80800390: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800394: jr          $ra
    // 0x80800398: lw          $v0, 0x1E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E60));
    return;
    // 0x80800398: lw          $v0, 0x1E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E60));
;}
RECOMP_FUNC void func_80800338_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080033C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800344: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800348: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x8080034C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800354: bne         $t6, $at, L_8080056C
    if (ctx->r14 != ctx->r1) {
        // 0x80800358: sb          $a2, 0x210($a0)
        MEM_B(0X210, ctx->r4) = ctx->r6;
            goto L_8080056C;
    }
    // 0x80800358: sb          $a2, 0x210($a0)
    MEM_B(0X210, ctx->r4) = ctx->r6;
    // 0x8080035C: lbu         $t7, 0x215($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X215);
    // 0x80800360: bnel        $t7, $zero, L_80800374
    if (ctx->r15 != 0) {
        // 0x80800364: lbu         $v1, 0x213($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X213);
            goto L_80800374;
    }
    goto skip_0;
    // 0x80800364: lbu         $v1, 0x213($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X213);
    skip_0:
    // 0x80800368: jal         0x8080008C
    // 0x8080036C: nop

    func_8080008C_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x8080036C: nop

    after_0:
    // 0x80800370: lbu         $v1, 0x213($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X213);
L_80800374:
    // 0x80800374: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: beq         $v1, $zero, L_808003B0
    if (ctx->r3 == 0) {
        // 0x80800380: swc1        $f4, 0x154($s0)
        MEM_W(0X154, ctx->r16) = ctx->f4.u32l;
            goto L_808003B0;
    }
    // 0x80800380: swc1        $f4, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f4.u32l;
    // 0x80800384: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800388: beq         $v1, $at, L_808003A0
    if (ctx->r3 == ctx->r1) {
        // 0x8080038C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003A0;
    }
    // 0x8080038C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800390: beql        $v1, $at, L_808003B4
    if (ctx->r3 == ctx->r1) {
        // 0x80800394: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_808003B4;
    }
    goto skip_1;
    // 0x80800394: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x80800398: b           L_808003BC
    // 0x8080039C: nop

        goto L_808003BC;
    // 0x8080039C: nop

L_808003A0:
    // 0x808003A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003A8: b           L_808003BC
    // 0x808003AC: swc1        $f6, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f6.u32l;
        goto L_808003BC;
    // 0x808003AC: swc1        $f6, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f6.u32l;
L_808003B0:
    // 0x808003B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_808003B4:
    // 0x808003B4: nop

    // 0x808003B8: swc1        $f8, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f8.u32l;
L_808003BC:
    // 0x808003BC: jal         0x808017F4
    // 0x808003C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808017F4_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x808003C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x808003C4: lb          $a0, 0x211($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X211);
    // 0x808003C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003CC: beq         $a0, $zero, L_808003E8
    if (ctx->r4 == 0) {
        // 0x808003D0: nop
    
            goto L_808003E8;
    }
    // 0x808003D0: nop

    // 0x808003D4: beq         $a0, $at, L_808003E8
    if (ctx->r4 == ctx->r1) {
        // 0x808003D8: addiu       $a1, $s0, 0xC4
        ctx->r5 = ADD32(ctx->r16, 0XC4);
            goto L_808003E8;
    }
    // 0x808003D8: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: jal         0x80800D10
    // 0x808003E4: addiu       $a2, $s0, 0x13C
    ctx->r6 = ADD32(ctx->r16, 0X13C);
    func_80800D10_ncpoddialog(rdram, ctx);
        goto after_2;
    // 0x808003E4: addiu       $a2, $s0, 0x13C
    ctx->r6 = ADD32(ctx->r16, 0X13C);
    after_2:
L_808003E8:
    // 0x808003E8: jal         0x80801B98
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B98_ncpoddialog(rdram, ctx);
        goto after_3;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003F0: jal         0x808013C0
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808013C0_ncpoddialog(rdram, ctx);
        goto after_4;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80801504
    // 0x80800400: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80801504_ncpoddialog(rdram, ctx);
        goto after_5;
    // 0x80800400: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800404: lb          $a0, 0x211($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X211);
    // 0x80800408: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080040C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800410: beql        $a0, $at, L_80800570
    if (ctx->r4 == ctx->r1) {
        // 0x80800414: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80800570;
    }
    goto skip_2;
    // 0x80800414: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_2:
    // 0x80800418: lbu         $t8, 0x212($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X212);
    // 0x8080041C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800420: beql        $t8, $zero, L_808004D8
    if (ctx->r24 == 0) {
        // 0x80800424: lbu         $v1, 0x213($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X213);
            goto L_808004D8;
    }
    goto skip_3;
    // 0x80800424: lbu         $v1, 0x213($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X213);
    skip_3:
    // 0x80800428: bnel        $a0, $at, L_808004D8
    if (ctx->r4 != ctx->r1) {
        // 0x8080042C: lbu         $v1, 0x213($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X213);
            goto L_808004D8;
    }
    goto skip_4;
    // 0x8080042C: lbu         $v1, 0x213($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X213);
    skip_4:
    // 0x80800430: bnel        $a1, $zero, L_808004D8
    if (ctx->r5 != 0) {
        // 0x80800434: lbu         $v1, 0x213($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0X213);
            goto L_808004D8;
    }
    goto skip_5;
    // 0x80800434: lbu         $v1, 0x213($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X213);
    skip_5:
    // 0x80800438: jal         0x80110024
    // 0x8080043C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80110024(rdram, ctx);
        goto after_6;
    // 0x8080043C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800440: lb          $a3, 0x211($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X211);
    // 0x80800444: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80800448: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080044C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800450: jal         0x800894E8
    // 0x80800454: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800454: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    after_7:
    // 0x80800458: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080045C: beq         $v0, $at, L_808004B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800460: addiu       $t9, $zero, 0x9
        ctx->r25 = ADD32(0, 0X9);
            goto L_808004B0;
    }
    // 0x80800460: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80800464: jal         0x80110024
    // 0x80800468: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80110024(rdram, ctx);
        goto after_8;
    // 0x80800468: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x8080046C: lb          $a3, 0x211($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X211);
    // 0x80800470: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800474: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800478: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080047C: jal         0x800894E8
    // 0x80800480: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800480: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_9:
    // 0x80800484: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800488: bne         $v0, $at, L_80800498
    if (ctx->r2 != ctx->r1) {
        // 0x8080048C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800498;
    }
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: b           L_80800574
    // 0x80800494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800574;
    // 0x80800494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800498:
    // 0x80800498: sb          $zero, 0x212($s0)
    MEM_B(0X212, ctx->r16) = 0;
    // 0x8080049C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808004A0: jal         0x80800338
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_10;
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x808004A8: b           L_80800570
    // 0x808004AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800570;
    // 0x808004AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004B0:
    // 0x808004B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808004B4: sb          $t9, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r25;
    // 0x808004B8: sb          $t0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r8;
    // 0x808004BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x80800338
    // 0x808004C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_11;
    // 0x808004C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x808004CC: b           L_80800570
    // 0x808004D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800570;
    // 0x808004D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808004D4: lbu         $v1, 0x213($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X213);
L_808004D8:
    // 0x808004D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004DC: beq         $v1, $zero, L_808004F4
    if (ctx->r3 == 0) {
        // 0x808004E0: nop
    
            goto L_808004F4;
    }
    // 0x808004E0: nop

    // 0x808004E4: beq         $v1, $at, L_80800518
    if (ctx->r3 == ctx->r1) {
        // 0x808004E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800518;
    }
    // 0x808004E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004EC: bnel        $v1, $at, L_80800570
    if (ctx->r3 != ctx->r1) {
        // 0x808004F0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80800570;
    }
    goto skip_6;
    // 0x808004F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_6:
L_808004F4:
    // 0x808004F4: bne         $v0, $zero, L_80800518
    if (ctx->r2 != 0) {
        // 0x808004F8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800518;
    }
    // 0x808004F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808004FC: sb          $t1, 0x213($s0)
    MEM_B(0X213, ctx->r16) = ctx->r9;
    // 0x80800500: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: jal         0x80800338
    // 0x8080050C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_12;
    // 0x8080050C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80800510: b           L_80800570
    // 0x80800514: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800570;
    // 0x80800514: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800518:
    // 0x80800518: bne         $a1, $zero, L_80800560
    if (ctx->r5 != 0) {
        // 0x8080051C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800560;
    }
    // 0x8080051C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800520: beq         $a0, $at, L_8080053C
    if (ctx->r4 == ctx->r1) {
        // 0x80800524: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8080053C;
    }
    // 0x80800524: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800528: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080052C: beq         $a0, $at, L_8080053C
    if (ctx->r4 == ctx->r1) {
        // 0x80800530: addiu       $t2, $zero, 0x8
        ctx->r10 = ADD32(0, 0X8);
            goto L_8080053C;
    }
    // 0x80800530: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80800534: b           L_80800544
    // 0x80800538: sb          $t2, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r10;
        goto L_80800544;
    // 0x80800538: sb          $t2, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r10;
L_8080053C:
    // 0x8080053C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80800540: sb          $t3, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r11;
L_80800544:
    // 0x80800544: sb          $t4, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r12;
    // 0x80800548: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x80800338
    // 0x80800554: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800338_ncpoddialog(rdram, ctx);
        goto after_13;
    // 0x80800554: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_13:
    // 0x80800558: b           L_80800570
    // 0x8080055C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800570;
    // 0x8080055C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800560:
    // 0x80800560: addiu       $a0, $s0, 0x200
    ctx->r4 = ADD32(ctx->r16, 0X200);
    // 0x80800564: jal         0x800EE7F8
    // 0x80800568: addiu       $a1, $s0, 0x1F4
    ctx->r5 = ADD32(ctx->r16, 0X1F4);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x80800568: addiu       $a1, $s0, 0x1F4
    ctx->r5 = ADD32(ctx->r16, 0X1F4);
    after_14:
L_8080056C:
    // 0x8080056C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800570:
    // 0x80800570: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800574:
    // 0x80800574: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080057C: jr          $ra
    // 0x80800580: nop

    return;
    // 0x80800580: nop

;}
RECOMP_FUNC void boot___osProbeTLB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_808000C0_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000CC: jal         0x80082838
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: addiu       $a1, $zero, 0x1DE
    ctx->r5 = ADD32(0, 0X1DE);
    // 0x808000DC: jal         0x8008CB3C
    // 0x808000E0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808000E0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_1:
    // 0x808000E4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808000E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000F8: jal         0x8009FFD8
    // 0x808000FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808000FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: jal         0x8009B9B0
    // 0x80800108: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800108: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080010C: jal         0x800909CC
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800118: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080011C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_80800398_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080039C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003AC: jal         0x80100094
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808003B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003BC: jal         0x80088718
    // 0x808003C0: addiu       $a1, $zero, 0x186C
    ctx->r5 = ADD32(0, 0X186C);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808003C0: addiu       $a1, $zero, 0x186C
    ctx->r5 = ADD32(0, 0X186C);
    after_1:
    // 0x808003C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808003C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808003CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003D0: lhu         $v1, 0x76($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X76);
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D8: srl         $t7, $v1, 7
    ctx->r15 = S32(U32(ctx->r3) >> 7);
    // 0x808003DC: addiu       $v1, $t7, -0x32
    ctx->r3 = ADD32(ctx->r15, -0X32);
    // 0x808003E0: beq         $v1, $at, L_80800424
    if (ctx->r3 == ctx->r1) {
        // 0x808003E4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80800424;
    }
    // 0x808003E4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808003E8: bne         $v1, $at, L_80800468
    if (ctx->r3 != ctx->r1) {
        // 0x808003EC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800468;
    }
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F0: jal         0x80088720
    // 0x808003F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808003F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x800E715C
    // 0x80800400: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E715C(rdram, ctx);
        goto after_3;
    // 0x80800400: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800408: jal         0x80088720
    // 0x8080040C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080040C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800410: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80800414: jal         0x800E715C
    // 0x80800418: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E715C(rdram, ctx);
        goto after_5;
    // 0x80800418: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8080041C: b           L_80800468
    // 0x80800420: nop

        goto L_80800468;
    // 0x80800420: nop

L_80800424:
    // 0x80800424: jal         0x80088720
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x800E715C
    // 0x80800434: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E715C(rdram, ctx);
        goto after_7;
    // 0x80800434: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80800438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080043C: jal         0x80088720
    // 0x80800440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800444: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80800448: jal         0x800E715C
    // 0x8080044C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E715C(rdram, ctx);
        goto after_9;
    // 0x8080044C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80800450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800454: jal         0x80088720
    // 0x80800458: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800458: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x8080045C: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x80800460: jal         0x800E715C
    // 0x80800464: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E715C(rdram, ctx);
        goto after_11;
    // 0x80800464: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
L_80800468:
    // 0x80800468: jal         0x80088728
    // 0x8080046C: addiu       $a0, $zero, 0x186C
    ctx->r4 = ADD32(0, 0X186C);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x8080046C: addiu       $a0, $zero, 0x186C
    ctx->r4 = ADD32(0, 0X186C);
    after_12:
    // 0x80800470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800474: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800478: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080047C: jr          $ra
    // 0x80800480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800480: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080004C_chcamerawibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800054: jal         0x8080006C
    // 0x80800058: nop

    func_8080006C_chcamerawibble(rdram, ctx);
        goto after_0;
    // 0x80800058: nop

    after_0:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_80806A78_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806A78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806A7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806A80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806A84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806A88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806A8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80806A90: jal         0x80100094
    // 0x80806A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806A98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80806A9C: addiu       $a0, $v0, 0x68
    ctx->r4 = ADD32(ctx->r2, 0X68);
    // 0x80806AA0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80806AA4: jal         0x8001BBA0
    // 0x80806AA8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x80806AA8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80806AAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80806AB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80806AB4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80806AB8: sb          $t6, 0x5E($s0)
    MEM_B(0X5E, ctx->r16) = ctx->r14;
    // 0x80806ABC: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x80806AC0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80806AC4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80806AC8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80806ACC: sb          $t8, 0x5D($s0)
    MEM_B(0X5D, ctx->r16) = ctx->r24;
    // 0x80806AD0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80806AD4: jal         0x80803BE8
    // 0x80806AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80806AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80806ADC: jal         0x808027F4
    // 0x80806AE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80806AE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80806AE4: jal         0x800F54E4
    // 0x80806AE8: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80806AE8: nop

    after_4:
    // 0x80806AEC: jal         0x800F5410
    // 0x80806AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_5;
    // 0x80806AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80806AF4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80806AF8: bne         $v0, $at, L_80806B1C
    if (ctx->r2 != ctx->r1) {
        // 0x80806AFC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80806B1C;
    }
    // 0x80806AFC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80806B00: jal         0x800F54E4
    // 0x80806B04: sb          $t9, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r25;
    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80806B04: sb          $t9, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r25;
    after_6:
    // 0x80806B08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80806B0C: jal         0x800F7B9C
    // 0x80806B10: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x80806B10: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    after_7:
    // 0x80806B14: b           L_80806B28
    // 0x80806B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806B28;
    // 0x80806B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806B1C:
    // 0x80806B1C: jal         0x80806B38
    // 0x80806B20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80806B38_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80806B20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80806B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806B28:
    // 0x80806B28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806B2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806B30: jr          $ra
    // 0x80806B34: nop

    return;
    // 0x80806B34: nop

;}
RECOMP_FUNC void func_80803CA0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803CA8: jal         0x800FC660
    // 0x80803CAC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x80803CAC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x80803CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803CB8: jr          $ra
    // 0x80803CBC: nop

    return;
    // 0x80803CBC: nop

;}
RECOMP_FUNC void func_808022E0_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808022E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808022E8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808022EC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808022F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808022F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808022F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808022FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802304: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80802308: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080230C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80802310: blez        $t6, L_808023F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80802314: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_808023F0;
    }
    // 0x80802314: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80802318: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080231C:
    // 0x8080231C: jal         0x80800070
    // 0x80802320: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800070_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802320: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x80802324: lh          $t7, 0x6($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X6);
    // 0x80802328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080232C: beql        $v0, $t7, L_808023E0
    if (ctx->r2 == ctx->r15) {
        // 0x80802330: lh          $t6, 0x2($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X2);
            goto L_808023E0;
    }
    goto skip_0;
    // 0x80802330: lh          $t6, 0x2($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X2);
    skip_0:
    // 0x80802334: jal         0x80800000
    // 0x80802338: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80802338: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x8080233C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80802340: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80802344: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802348: jal         0x80087AF8
    // 0x8080234C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080234C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_2:
    // 0x80802350: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80802354: beq         $at, $zero, L_808023D4
    if (ctx->r1 == 0) {
        // 0x80802358: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_808023D4;
    }
    // 0x80802358: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8080235C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80802360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X3014) << 16);
    // 0x80802364: addu        $at, $at, $t0
    gpr jr_addend_8080236C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80802368: lw          $t0, 0x3014($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X3014));
    // 0x8080236C: jr          $t0
    // 0x80802370: nop

    switch (jr_addend_8080236C >> 2) {
        case 0: goto L_80802374; break;
        case 1: goto L_808023D4; break;
        case 2: goto L_80802374; break;
        case 3: goto L_80802374; break;
        case 4: goto L_808023A4; break;
        case 5: goto L_808023CC; break;
        default: switch_error(__func__, 0x8080236C, 0x80803014);
    }
    // 0x80802370: nop

L_80802374:
    // 0x80802374: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x80802378: lb          $t1, 0x94($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X94);
    // 0x8080237C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80802380: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80802384: beq         $v0, $t1, L_808023D8
    if (ctx->r2 == ctx->r9) {
        // 0x80802388: addu        $s3, $s2, $t2
        ctx->r19 = ADD32(ctx->r18, ctx->r10);
            goto L_808023D8;
    }
    // 0x80802388: addu        $s3, $s2, $t2
    ctx->r19 = ADD32(ctx->r18, ctx->r10);
    // 0x8080238C: jal         0x80087B40
    // 0x80802390: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80802390: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    after_3:
    // 0x80802394: jal         0x80087B30
    // 0x80802398: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80802398: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    after_4:
    // 0x8080239C: b           L_808023DC
    // 0x808023A0: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
        goto L_808023DC;
    // 0x808023A0: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
L_808023A4:
    // 0x808023A4: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x808023A8: lb          $t3, 0x94($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X94);
    // 0x808023AC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x808023B0: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x808023B4: beql        $v0, $t3, L_808023DC
    if (ctx->r2 == ctx->r11) {
        // 0x808023B8: sb          $s5, 0x94($s1)
        MEM_B(0X94, ctx->r17) = ctx->r21;
            goto L_808023DC;
    }
    goto skip_1;
    // 0x808023B8: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
    skip_1:
    // 0x808023BC: jal         0x80087B30
    // 0x808023C0: lw          $a0, 0x3C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X3C);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808023C0: lw          $a0, 0x3C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X3C);
    after_5:
    // 0x808023C4: b           L_808023DC
    // 0x808023C8: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
        goto L_808023DC;
    // 0x808023C8: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
L_808023CC:
    // 0x808023CC: b           L_808023D8
    // 0x808023D0: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
        goto L_808023D8;
    // 0x808023D0: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
L_808023D4:
    // 0x808023D4: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
L_808023D8:
    // 0x808023D8: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
L_808023DC:
    // 0x808023DC: lh          $t6, 0x2($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X2);
L_808023E0:
    // 0x808023E0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808023E4: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808023E8: bnel        $at, $zero, L_8080231C
    if (ctx->r1 != 0) {
        // 0x808023EC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080231C;
    }
    goto skip_2;
    // 0x808023EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_808023F0:
    // 0x808023F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808023F4: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x808023F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808023FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802400: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802404: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802408: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080240C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802410: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80802414: jr          $ra
    // 0x80802418: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80802418: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835C8: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835C8);
    return;
    // 0x800835CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
