#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chbaddiesetup_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D78: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D78);
    return;
    // 0x80086D7C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _glidmake_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088888: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x80088888);
    return;
    // 0x8008888C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _cadbmgrDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085568: syscall     167
    recomp_syscall_handler(rdram, ctx, 0x80085568);
    return;
    // 0x8008556C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chjadestatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087350: syscall     553
    recomp_syscall_handler(rdram, ctx, 0x80087350);
    return;
    // 0x80087354: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void vplight_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x808007F8: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x808007FC: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x80800800: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800804: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80800808: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080080C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800810: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800814: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800818: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8080081C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800820: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800824: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800828: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080082C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800830: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800834: beq         $at, $zero, L_808009F0
    if (ctx->r1 == 0) {
        // 0x80800838: sw          $v0, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r2;
            goto L_808009F0;
    }
    // 0x80800838: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x8080083C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80800840: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800844: addiu       $fp, $zero, 0x4000
    ctx->r30 = ADD32(0, 0X4000);
    // 0x80800848: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x8080084C: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x80800850: addiu       $s5, $sp, 0x6C
    ctx->r21 = ADD32(ctx->r29, 0X6C);
    // 0x80800854: lbu         $s2, 0xC($s1)
    ctx->r18 = MEM_BU(ctx->r17, 0XC);
L_80800858:
    // 0x80800858: lbu         $s3, 0xD($s1)
    ctx->r19 = MEM_BU(ctx->r17, 0XD);
    // 0x8080085C: lbu         $s4, 0xE($s1)
    ctx->r20 = MEM_BU(ctx->r17, 0XE);
    // 0x80800860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800864: jal         0x800C8760
    // 0x80800868: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C8760(rdram, ctx);
        goto after_0;
    // 0x80800868: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080086C: beq         $v0, $zero, L_808009A0
    if (ctx->r2 == 0) {
        // 0x80800870: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808009A0;
    }
    // 0x80800870: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800874:
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800878: jal         0x808004B0
    // 0x8080087C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_808004B0_vplight(rdram, ctx);
        goto after_1;
    // 0x8080087C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: jal         0x80800518
    // 0x80800888: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80800518_vplight(rdram, ctx);
        goto after_2;
    // 0x80800888: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: jal         0x800C8900
    // 0x80800894: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800C8900(rdram, ctx);
        goto after_3;
    // 0x80800894: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_3:
    // 0x80800898: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8080089C: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x808008A0: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x808008A4: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x808008A8: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    // 0x808008AC: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008B0: subu        $v1, $t9, $t0
    ctx->r3 = SUB32(ctx->r25, ctx->r8);
    // 0x808008B4: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x808008B8: lh          $t2, 0x4($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X4);
    // 0x808008BC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x808008C0: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    // 0x808008C4: mflo        $t3
    ctx->r11 = lo;
    // 0x808008C8: nop

    // 0x808008CC: nop

    // 0x808008D0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008D4: mflo        $t4
    ctx->r12 = lo;
    // 0x808008D8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x808008DC: nop

    // 0x808008E0: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808008E4: mflo        $t6
    ctx->r14 = lo;
    // 0x808008E8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x808008EC: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808008F0: beq         $at, $zero, L_80800988
    if (ctx->r1 == 0) {
        // 0x808008F4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80800988;
    }
    // 0x808008F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808008F8: beql        $a1, $zero, L_80800920
    if (ctx->r5 == 0) {
        // 0x808008FC: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800920;
    }
    goto skip_0;
    // 0x808008FC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x80800900: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80800904: jal         0x8002DCA0
    // 0x80800908: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80800908: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x8080090C: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800910: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800914: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800918: nop

    // 0x8080091C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_80800920:
    // 0x80800920: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80800924: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80800928: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8080092C: beq         $at, $zero, L_80800950
    if (ctx->r1 == 0) {
        // 0x80800930: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_80800950;
    }
    // 0x80800930: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80800934: subu        $t0, $a2, $a0
    ctx->r8 = SUB32(ctx->r6, ctx->r4);
    // 0x80800938: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080093C: mflo        $t1
    ctx->r9 = lo;
    // 0x80800940: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80800944: subu        $v1, $fp, $t2
    ctx->r3 = SUB32(ctx->r30, ctx->r10);
    // 0x80800948: b           L_80800950
    // 0x8080094C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
        goto L_80800950;
    // 0x8080094C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_80800950:
    // 0x80800950: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800954: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80800958: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8080095C: mflo        $t4
    ctx->r12 = lo;
    // 0x80800960: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80800964: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x80800968: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080096C: mflo        $t7
    ctx->r15 = lo;
    // 0x80800970: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800974: addu        $s3, $s3, $t8
    ctx->r19 = ADD32(ctx->r19, ctx->r24);
    // 0x80800978: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080097C: mflo        $t0
    ctx->r8 = lo;
    // 0x80800980: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80800984: addu        $s4, $s4, $t1
    ctx->r20 = ADD32(ctx->r20, ctx->r9);
L_80800988:
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080098C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800990: jal         0x800C878C
    // 0x80800994: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800C878C(rdram, ctx);
        goto after_5;
    // 0x80800994: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80800998: bne         $v0, $zero, L_80800874
    if (ctx->r2 != 0) {
        // 0x8080099C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800874;
    }
    // 0x8080099C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808009A0:
    // 0x808009A0: slti        $at, $s2, 0x100
    ctx->r1 = SIGNED(ctx->r18) < 0X100 ? 1 : 0;
    // 0x808009A4: bnel        $at, $zero, L_808009B4
    if (ctx->r1 != 0) {
        // 0x808009A8: slti        $at, $s3, 0x100
        ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
            goto L_808009B4;
    }
    goto skip_1;
    // 0x808009A8: slti        $at, $s3, 0x100
    ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
    skip_1:
    // 0x808009AC: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x808009B0: slti        $at, $s3, 0x100
    ctx->r1 = SIGNED(ctx->r19) < 0X100 ? 1 : 0;
L_808009B4:
    // 0x808009B4: bnel        $at, $zero, L_808009C4
    if (ctx->r1 != 0) {
        // 0x808009B8: slti        $at, $s4, 0x100
        ctx->r1 = SIGNED(ctx->r20) < 0X100 ? 1 : 0;
            goto L_808009C4;
    }
    goto skip_2;
    // 0x808009B8: slti        $at, $s4, 0x100
    ctx->r1 = SIGNED(ctx->r20) < 0X100 ? 1 : 0;
    skip_2:
    // 0x808009BC: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x808009C0: slti        $at, $s4, 0x100
    ctx->r1 = SIGNED(ctx->r20) < 0X100 ? 1 : 0;
L_808009C4:
    // 0x808009C4: bnel        $at, $zero, L_808009D4
    if (ctx->r1 != 0) {
        // 0x808009C8: sb          $s2, 0xC($s1)
        MEM_B(0XC, ctx->r17) = ctx->r18;
            goto L_808009D4;
    }
    goto skip_3;
    // 0x808009C8: sb          $s2, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r18;
    skip_3:
    // 0x808009CC: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x808009D0: sb          $s2, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r18;
L_808009D4:
    // 0x808009D4: sb          $s3, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r19;
    // 0x808009D8: sb          $s4, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r20;
    // 0x808009DC: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x808009E0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808009E4: sltu        $at, $s1, $t2
    ctx->r1 = ctx->r17 < ctx->r10 ? 1 : 0;
    // 0x808009E8: bnel        $at, $zero, L_80800858
    if (ctx->r1 != 0) {
        // 0x808009EC: lbu         $s2, 0xC($s1)
        ctx->r18 = MEM_BU(ctx->r17, 0XC);
            goto L_80800858;
    }
    goto skip_4;
    // 0x808009EC: lbu         $s2, 0xC($s1)
    ctx->r18 = MEM_BU(ctx->r17, 0XC);
    skip_4:
L_808009F0:
    // 0x808009F0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808009F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808009F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800A00: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800A04: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A08: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800A0C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800A10: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800A14: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A18: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800A20: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80800A24: nop

    // 0x80800A28: nop

    // 0x80800A2C: nop

;}
RECOMP_FUNC void _glrtc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088870: syscall     706
    recomp_syscall_handler(rdram, ctx, 0x80088870);
    return;
    // 0x80088874: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80103938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010393C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103940: lh          $t6, 0x8E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8E);
    // 0x80103944: beql        $t6, $zero, L_80103958
    if (ctx->r14 == 0) {
        // 0x80103948: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103958;
    }
    goto skip_0;
    // 0x80103948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010394C: jal         0x80104504
    // 0x80103950: nop

    func_80104504(rdram, ctx);
        goto after_0;
    // 0x80103950: nop

    after_0:
    // 0x80103954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103958:
    // 0x80103958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010395C: jr          $ra
    // 0x80103960: nop

    return;
    // 0x80103960: nop

;}
RECOMP_FUNC void bainput_func_80097C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097C84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80097C88: jal         0x800F424C
    // 0x80097C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F424C(rdram, ctx);
        goto after_0;
    // 0x80097C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80097C90: bne         $v0, $zero, L_80097CA0
    if (ctx->r2 != 0) {
        // 0x80097C94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80097CA0;
    }
    // 0x80097C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097C98: b           L_80097D14
    // 0x80097C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D14;
    // 0x80097C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097CA0:
    // 0x80097CA0: jal         0x80098024
    // 0x80097CA4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    bainput_isEnabled(rdram, ctx);
        goto after_1;
    // 0x80097CA4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80097CA8: beq         $v0, $zero, L_80097CB8
    if (ctx->r2 == 0) {
        // 0x80097CAC: nop
    
            goto L_80097CB8;
    }
    // 0x80097CAC: nop

    // 0x80097CB0: b           L_80097D14
    // 0x80097CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D14;
    // 0x80097CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097CB8:
    // 0x80097CB8: jal         0x800F8004
    // 0x80097CBC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8004(rdram, ctx);
        goto after_2;
    // 0x80097CBC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_2:
    // 0x80097CC0: beq         $v0, $zero, L_80097CD0
    if (ctx->r2 == 0) {
        // 0x80097CC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80097CD0;
    }
    // 0x80097CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097CC8: b           L_80097D14
    // 0x80097CCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D14;
    // 0x80097CCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097CD0:
    // 0x80097CD0: jal         0x80091E80
    // 0x80097CD4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80091E80(rdram, ctx);
        goto after_3;
    // 0x80097CD4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x80097CD8: bne         $v0, $zero, L_80097CE8
    if (ctx->r2 != 0) {
        // 0x80097CDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80097CE8;
    }
    // 0x80097CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097CE0: b           L_80097D14
    // 0x80097CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097D14;
    // 0x80097CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097CE8:
    // 0x80097CE8: jal         0x80091A94
    // 0x80097CEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bakey_newlyReleased(rdram, ctx);
        goto after_4;
    // 0x80097CEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80097CF0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097CF4: beq         $t6, $zero, L_80097D14
    if (ctx->r14 == 0) {
        // 0x80097CF8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097D14;
    }
    // 0x80097CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097D00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80097D04: jal         0x80091940
    // 0x80097D08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bakey_func_80091940(rdram, ctx);
        goto after_5;
    // 0x80097D08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80097D0C: slti        $t7, $v0, 0x9
    ctx->r15 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80097D10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097D14:
    // 0x80097D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80097D18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097D1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097D20: jr          $ra
    // 0x80097D24: nop

    return;
    // 0x80097D24: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088130: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088130);
    return;
    // 0x80088134: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DC298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC2A0: jal         0x800DC0C0
    // 0x800DC2A4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x800DC2A4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800DC2A8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800DC2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC2B4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800DC2B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800DC2BC: bc1f        L_800DC2CC
    if (!c1cs) {
        // 0x800DC2C0: nop
    
            goto L_800DC2CC;
    }
    // 0x800DC2C0: nop

    // 0x800DC2C4: b           L_800DC2CC
    // 0x800DC2C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800DC2CC;
    // 0x800DC2C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800DC2CC:
    // 0x800DC2CC: jr          $ra
    // 0x800DC2D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800DC2D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _gcmapsects_lagoonbot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088000: syscall     665
    recomp_syscall_handler(rdram, ctx, 0x80088000);
    return;
    // 0x80088004: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080007C_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800088: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8080008C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800090: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800094: bltzl       $t8, L_80800510
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800098: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_0;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080009C: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x808000A0: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808000A4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808000A8: sltiu       $at, $t1, 0x7
    ctx->r1 = ctx->r9 < 0X7 ? 1 : 0;
    // 0x808000AC: beq         $at, $zero, L_8080050C
    if (ctx->r1 == 0) {
        // 0x808000B0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8080050C;
    }
    // 0x808000B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(896, 0X11C0) << 16);
    // 0x808000B8: addu        $at, $at, $t1
    gpr jr_addend_808000C0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808000BC: lw          $t1, 0x11C0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(896, 0X11C0));
    // 0x808000C0: jr          $t1
    // 0x808000C4: nop

    switch (jr_addend_808000C0 >> 2) {
        case 0: goto L_808000C8; break;
        case 1: goto L_80800110; break;
        case 2: goto L_808001B4; break;
        case 3: goto L_80800278; break;
        case 4: goto L_80800384; break;
        case 5: goto L_8080048C; break;
        case 6: goto L_8080046C; break;
        default: switch_error(__func__, 0x808000C0, 0x808011C0);
    }
    // 0x808000C4: nop

L_808000C8:
    // 0x808000C8: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x808000CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000D4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x808000D8: bgez        $t4, L_808000F0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808000DC: nop
    
            goto L_808000F0;
    }
    // 0x808000DC: nop

    // 0x808000E0: jal         0x80800680
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_0;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000E8: b           L_80800510
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: jal         0x8010C9B0
    // 0x808000F4: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010C9B0(rdram, ctx);
        goto after_1;
    // 0x808000F4: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_1:
    // 0x808000F8: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x808000FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080050C;
    }
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80800680
    // 0x80800104: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800108: b           L_80800510
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800110:
    // 0x80800110: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X11F0) << 16);
    // 0x80800114: addiu       $a2, $a2, 0x11F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X11F0));
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800120: jal         0x80089D20
    // 0x80800124: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800124: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_3:
    // 0x80800128: beq         $v0, $zero, L_80800144
    if (ctx->r2 == 0) {
        // 0x8080012C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800144;
    }
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800134: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800138: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080013C: jal         0x80089BF8
    // 0x80800140: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800140: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_4:
L_80800144:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x808008E0
    // 0x8080014C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_808008E0_chonearmbandit(rdram, ctx);
        goto after_5;
    // 0x8080014C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80089BD8
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080015C: beq         $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x80800160: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800178;
    }
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80800680
    // 0x8080016C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_7;
    // 0x8080016C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800170: b           L_80800194
    // 0x80800174: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
        goto L_80800194;
    // 0x80800174: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_80800178:
    // 0x80800178: jal         0x80089BD8
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800180: beq         $v0, $zero, L_80800190
    if (ctx->r2 == 0) {
        // 0x80800184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800190;
    }
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80800680
    // 0x8080018C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_9;
    // 0x8080018C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
L_80800190:
    // 0x80800190: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_80800194:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8080019C: bltzl       $t7, L_80800510
    if (SIGNED(ctx->r15) < 0) {
        // 0x808001A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_1;
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001A4: jal         0x80800680
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_10;
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x808001AC: b           L_80800510
    // 0x808001B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x808001B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B4:
    // 0x808001B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X11F0) << 16);
    // 0x808001BC: addiu       $a2, $a2, 0x11F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X11F0));
    // 0x808001C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80089D20
    // 0x808001CC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808001CC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_11:
    // 0x808001D0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001EC;
    }
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808001DC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808001E0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001E4: jal         0x80089BF8
    // 0x808001E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x808001E8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_12:
L_808001EC:
    // 0x808001EC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808001F0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808001F4: jal         0x80800A14
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A14_chonearmbandit(rdram, ctx);
        goto after_13;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x808008E0
    // 0x80800204: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_808008E0_chonearmbandit(rdram, ctx);
        goto after_14;
    // 0x80800204: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_14:
    // 0x80800208: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080020C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800210: jal         0x80101E14
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800218: beql        $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x8080021C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_2;
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800220: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800228: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080022C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80800230: bgez        $t0, L_80800258
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800234: nop
    
            goto L_80800258;
    }
    // 0x80800234: nop

    // 0x80800238: jal         0x80089BD8
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_16;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800240: bne         $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x80800244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080050C;
    }
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80800680
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_17;
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80800250: b           L_80800510
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800258:
    // 0x80800258: jal         0x8010C9B0
    // 0x8080025C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010C9B0(rdram, ctx);
        goto after_18;
    // 0x8080025C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_18:
    // 0x80800260: bne         $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x80800264: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080050C;
    }
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x80800680
    // 0x8080026C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_19;
    // 0x8080026C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
    // 0x80800270: b           L_80800510
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800278:
    // 0x80800278: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080027C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X11F0) << 16);
    // 0x80800280: addiu       $a2, $a2, 0x11F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X11F0));
    // 0x80800284: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80089D20
    // 0x80800290: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x80800290: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_20:
    // 0x80800294: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800298: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x8080029C: jal         0x80101E14
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_21;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808002A4: beq         $v0, $zero, L_80800334
    if (ctx->r2 == 0) {
        // 0x808002A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800334;
    }
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x808002B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002B8: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x808002BC: bgez        $t3, L_808002D4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808002C0: nop
    
            goto L_808002D4;
    }
    // 0x808002C0: nop

    // 0x808002C4: jal         0x80800680
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_22;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808002CC: b           L_80800510
    // 0x808002D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x808002D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D4:
    // 0x808002D4: jal         0x8010C9B0
    // 0x808002D8: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010C9B0(rdram, ctx);
        goto after_23;
    // 0x808002D8: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_23:
    // 0x808002DC: bne         $v0, $zero, L_808002F8
    if (ctx->r2 != 0) {
        // 0x808002E0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808002F8;
    }
    // 0x808002E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x80800680
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_24;
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808002F0: b           L_80800510
    // 0x808002F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x808002F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002F8:
    // 0x808002F8: jal         0x8010C9B0
    // 0x808002FC: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010C9B0(rdram, ctx);
        goto after_25;
    // 0x808002FC: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_25:
    // 0x80800300: beql        $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x80800304: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_3;
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800308: jal         0x8010D278
    // 0x8080030C: nop

    func_8010D278(rdram, ctx);
        goto after_26;
    // 0x8080030C: nop

    after_26:
    // 0x80800310: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800314: bne         $v0, $at, L_80800324
    if (ctx->r2 != ctx->r1) {
        // 0x80800318: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800324;
    }
    // 0x80800318: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080031C: b           L_80800324
    // 0x80800320: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80800324;
    // 0x80800320: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80800324:
    // 0x80800324: jal         0x80800680
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_27;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080032C: b           L_80800510
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800334:
    // 0x80800334: jal         0x80800740
    // 0x80800338: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80800740_chonearmbandit(rdram, ctx);
        goto after_28;
    // 0x80800338: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_28:
    // 0x8080033C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800340: jal         0x8010C9B0
    // 0x80800344: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010C9B0(rdram, ctx);
        goto after_29;
    // 0x80800344: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_29:
    // 0x80800348: beq         $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x8080034C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800374;
    }
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: jal         0x80102CF4
    // 0x80800358: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_30;
    // 0x80800358: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_30:
    // 0x8080035C: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x80800360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080050C;
    }
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80800680
    // 0x80800368: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_31;
    // 0x80800368: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_31:
    // 0x8080036C: b           L_80800510
    // 0x80800370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800374:
    // 0x80800374: jal         0x80800680
    // 0x80800378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_32;
    // 0x80800378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x8080037C: b           L_80800510
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800384:
    // 0x80800384: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800388: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X134C) << 16);
    // 0x8080038C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800390: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800394: addiu       $a2, $a2, 0x134C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X134C));
    // 0x80800398: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080039C: jal         0x80089D20
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_33;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x80101E14
    // 0x808003AC: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80101E14(rdram, ctx);
        goto after_34;
    // 0x808003AC: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_34:
    // 0x808003B0: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C0;
    }
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: jal         0x80108B04
    // 0x808003BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_35;
    // 0x808003BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
L_808003C0:
    // 0x808003C0: jal         0x80101DDC
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_36;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x808003C8: beql        $v0, $zero, L_80800510
    if (ctx->r2 == 0) {
        // 0x808003CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_4;
    // 0x808003CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808003D0: jal         0x800D8FF8
    // 0x808003D4: nop

    func_800D8FF8(rdram, ctx);
        goto after_37;
    // 0x808003D4: nop

    after_37:
    // 0x808003D8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808003E0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808003E4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808003E8: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003EC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808003F0: nop

    // 0x808003F4: bc1fl       L_80800510
    if (!c1cs) {
        // 0x808003F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800510;
    }
    goto skip_5;
    // 0x808003F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808003FC: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80800400: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800404: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800408: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8080040C: bgez        $t6, L_80800424
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800410: nop
    
            goto L_80800424;
    }
    // 0x80800410: nop

    // 0x80800414: jal         0x80800680
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_38;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8080041C: b           L_80800510
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800424:
    // 0x80800424: jal         0x8010C9B0
    // 0x80800428: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010C9B0(rdram, ctx);
        goto after_39;
    // 0x80800428: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_39:
    // 0x8080042C: beq         $v0, $zero, L_8080045C
    if (ctx->r2 == 0) {
        // 0x80800430: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8080045C;
    }
    // 0x80800430: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800434: jal         0x8010D278
    // 0x80800438: nop

    func_8010D278(rdram, ctx);
        goto after_40;
    // 0x80800438: nop

    after_40:
    // 0x8080043C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800440: bnel        $v0, $at, L_80800454
    if (ctx->r2 != ctx->r1) {
        // 0x80800444: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80800454;
    }
    goto skip_6;
    // 0x80800444: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_6:
    // 0x80800448: b           L_8080045C
    // 0x8080044C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_8080045C;
    // 0x8080044C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800450: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800454:
    // 0x80800454: b           L_8080045C
    // 0x80800458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8080045C;
    // 0x80800458: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8080045C:
    // 0x8080045C: jal         0x80800680
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_41;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800464: b           L_80800510
    // 0x80800468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080046C:
    // 0x8080046C: jal         0x80101DDC
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_42;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800474: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x80800478: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080050C;
    }
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x80800680
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_43;
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x80800484: b           L_80800510
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800510;
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080048C:
    // 0x8080048C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800490: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X11F0) << 16);
    // 0x80800494: addiu       $a2, $a2, 0x11F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X11F0));
    // 0x80800498: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: jal         0x80089D20
    // 0x808004A4: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_44;
    // 0x808004A4: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    after_44:
    // 0x808004A8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808004AC: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808004B0: jal         0x80101E14
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_45;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x808004B8: beql        $v0, $zero, L_80800504
    if (ctx->r2 == 0) {
        // 0x808004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800504;
    }
    goto skip_7;
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x808004C0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808004C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808004CC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808004D0: bgez        $t9, L_808004E8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808004D4: nop
    
            goto L_808004E8;
    }
    // 0x808004D4: nop

    // 0x808004D8: jal         0x80800680
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_46;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808004E0: b           L_80800504
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800504;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004E8:
    // 0x808004E8: jal         0x8010C9B0
    // 0x808004EC: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010C9B0(rdram, ctx);
        goto after_47;
    // 0x808004EC: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_47:
    // 0x808004F0: bne         $v0, $zero, L_80800500
    if (ctx->r2 != 0) {
        // 0x808004F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800500;
    }
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x80800680
    // 0x808004FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_48;
    // 0x808004FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_48:
L_80800500:
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800504:
    // 0x80800504: jal         0x808008E0
    // 0x80800508: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    func_808008E0_chonearmbandit(rdram, ctx);
        goto after_49;
    // 0x80800508: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_49:
L_8080050C:
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800510:
    // 0x80800510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x80800084: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800088: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8080008C: jal         0x80015F28
    // 0x80800090: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    func_80015F28(rdram, ctx);
        goto after_0;
    // 0x80800090: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    after_0:
    // 0x80800094: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x808000A4: jr          $ra
    // 0x808000A8: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    return;
    // 0x808000A8: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80808AAC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808AAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808AB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808AB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808AB8: jal         0x80807D48
    // 0x80808ABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808ABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80808AC0: jal         0x80808E78
    // 0x80808AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808E78_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808ACC: jal         0x8080633C
    // 0x80808AD0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808AD0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80808AD4: jal         0x80808B24
    // 0x80808AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808B24_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80808ADC: beq         $v0, $zero, L_80808AF4
    if (ctx->r2 == 0) {
        // 0x80808AE0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80808AF4;
    }
    // 0x80808AE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80808AE4: jal         0x8009E5C8
    // 0x80808AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80808AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80808AEC: b           L_80808B00
    // 0x80808AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80808B00;
    // 0x80808AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808AF4:
    // 0x80808AF4: jal         0x80808B8C
    // 0x80808AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808B8C_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80808AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80808AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808B00:
    // 0x80808B00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808B04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808B08: jr          $ra
    // 0x80808B0C: nop

    return;
    // 0x80808B0C: nop

;}
RECOMP_FUNC void gcboundDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800C70: jal         0x80800F6C
    // 0x80800C74: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    func_80800F6C_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80800C74: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C7C: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x80800C80: jal         0x80800F6C
    // 0x80800C84: addiu       $a2, $a0, 0xC
    ctx->r6 = ADD32(ctx->r4, 0XC);
    func_80800F6C_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x80800C84: addiu       $a2, $a0, 0xC
    ctx->r6 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x80800C88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C8C: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    // 0x80800C90: jal         0x80800F6C
    // 0x80800C94: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    func_80800F6C_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x80800C94: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    after_2:
    // 0x80800C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CA0: jr          $ra
    // 0x80800CA4: nop

    return;
    // 0x80800CA4: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1A0: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A1A0);
    return;
    // 0x8008A1A4: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_808002E0_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808002EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808002F0: jal         0x8008CABC
    // 0x808002F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808002F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002FC: jal         0x808001DC
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808001DC_bsswim(rdram, ctx);
        goto after_1;
    // 0x80800300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800304: jal         0x8009E710
    // 0x80800308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x80800308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8080030C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80800310: bne         $v0, $at, L_80800328
    if (ctx->r2 != ctx->r1) {
        // 0x80800314: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800328;
    }
    // 0x80800314: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800318: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(384, 0XB70) << 16);
    // 0x8080031C: lwc1        $f4, 0xB70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0XB70));
    // 0x80800320: b           L_80800338
    // 0x80800324: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_80800338;
    // 0x80800324: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_80800328:
    // 0x80800328: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080032C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800330: nop

    // 0x80800334: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80800338:
    // 0x80800338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080033C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800340: jal         0x8009CA70
    // 0x80800344: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_8009CA70(rdram, ctx);
        goto after_3;
    // 0x80800344: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800348: beq         $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x8080034C: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808003E0;
    }
    // 0x8080034C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800350: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80800354: bne         $t6, $at, L_80800378
    if (ctx->r14 != ctx->r1) {
        // 0x80800358: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80800378;
    }
    // 0x80800358: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080035C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800360: addiu       $a1, $zero, 0x461
    ctx->r5 = ADD32(0, 0X461);
    // 0x80800364: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800368: jal         0x8009DF18
    // 0x8080036C: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x8080036C: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_4:
    // 0x80800370: b           L_808003D0
    // 0x80800374: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
        goto L_808003D0;
    // 0x80800374: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
L_80800378:
    // 0x80800378: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x8080037C: beql        $t7, $at, L_808003D0
    if (ctx->r15 == ctx->r1) {
        // 0x80800380: lui         $a2, 0x3F33
        ctx->r6 = S32(0X3F33 << 16);
            goto L_808003D0;
    }
    goto skip_0;
    // 0x80800380: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    skip_0:
    // 0x80800384: jal         0x800CF67C
    // 0x80800388: nop

    func_800CF67C(rdram, ctx);
        goto after_5;
    // 0x80800388: nop

    after_5:
    // 0x8080038C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800390: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800394: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(384, 0XB74) << 16);
    // 0x80800398: lwc1        $f8, 0xB74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0XB74));
    // 0x8080039C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808003A4: lui         $a3, 0x45FA
    ctx->r7 = S32(0X45FA << 16);
    // 0x808003A8: jal         0x800F10B4
    // 0x808003AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x808003AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x808003B0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808003B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003B8: addiu       $a1, $zero, 0x461
    ctx->r5 = ADD32(0, 0X461);
    // 0x808003BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003C0: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808003C4: jal         0x8009DF18
    // 0x808003C8: nop

    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x808003C8: nop

    after_7:
    // 0x808003CC: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
L_808003D0:
    // 0x808003D0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D8: jal         0x80098188
    // 0x808003DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bainput_setDiveCooldown(rdram, ctx);
        goto after_8;
    // 0x808003DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
L_808003E0:
    // 0x808003E0: jal         0x8008B264
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_9;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003E8: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x808003EC: bne         $v0, $at, L_80800414
    if (ctx->r2 != ctx->r1) {
        // 0x808003F0: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80800414;
    }
    // 0x808003F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808003F4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x808003F8: beq         $t9, $at, L_80800414
    if (ctx->r25 == ctx->r1) {
        // 0x808003FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800414;
    }
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80800404: jal         0x8008B1BC
    // 0x80800408: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_setDuration(rdram, ctx);
        goto after_10;
    // 0x80800408: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_10:
    // 0x8080040C: b           L_8080046C
    // 0x80800410: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_8080046C;
    // 0x80800410: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80800414:
    // 0x80800414: jal         0x8008AF24
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_11;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x8008B1C8
    // 0x80800424: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8008B1C8(rdram, ctx);
        goto after_12;
    // 0x80800424: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x8008AED4
    // 0x80800430: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    anctrl_setIndex(rdram, ctx);
        goto after_13;
    // 0x80800430: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    after_13:
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: jal         0x8008B134
    // 0x8080043C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_14;
    // 0x8080043C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800440: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800444: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800448: jal         0x8008B24C
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_15;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800450: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80800454: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800458: jal         0x8008B1BC
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_16;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800460: jal         0x8008B064
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_17;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800468: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8080046C:
    // 0x8080046C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800478: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080047C: jal         0x8009FFD8
    // 0x80800480: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_18;
    // 0x80800480: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_18:
    // 0x80800484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800488: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x8080048C: jal         0x8009C99C
    // 0x80800490: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_19;
    // 0x80800490: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_19:
    // 0x80800494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800498: jal         0x8009B9B0
    // 0x8080049C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x8080049C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_20:
    // 0x808004A0: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x808004A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004A8: jal         0x800A4DA4
    // 0x808004AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A4DA4(rdram, ctx);
        goto after_21;
    // 0x808004AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808004B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808004BC: jr          $ra
    // 0x808004C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808004C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _suegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A380: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A380);
    return;
    // 0x8008A384: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chdoormake_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868E0: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868E0);
    return;
    // 0x800868E4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800000_chicekeydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800018: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080001C: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80800020: beq         $at, $zero, L_80800304
    if (ctx->r1 == 0) {
        // 0x80800024: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800304;
    }
    // 0x80800024: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2468, 0X8E0) << 16);
    // 0x8080002C: addu        $at, $at, $t8
    gpr jr_addend_80800034 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800030: lw          $t8, 0x8E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2468, 0X8E0));
    // 0x80800034: jr          $t8
    // 0x80800038: nop

    switch (jr_addend_80800034 >> 2) {
        case 0: goto L_80800304; break;
        case 1: goto L_8080003C; break;
        case 2: goto L_80800094; break;
        case 3: goto L_808000A4; break;
        case 4: goto L_80800108; break;
        case 5: goto L_8080016C; break;
        case 6: goto L_80800234; break;
        case 7: goto L_80800304; break;
        default: switch_error(__func__, 0x80800034, 0x808008E0);
    }
    // 0x80800038: nop

L_8080003C:
    // 0x8080003C: jal         0x8010C500
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800044: beql        $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800308;
    }
    goto skip_0;
    // 0x80800048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080004C: jal         0x8008F8B0
    // 0x80800050: nop

    func_8008F8B0(rdram, ctx);
        goto after_1;
    // 0x80800050: nop

    after_1:
    // 0x80800054: jal         0x8008F8D8
    // 0x80800058: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_2;
    // 0x80800058: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8080005C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800060: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800064: jal         0x8008F904
    // 0x80800068: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_3;
    // 0x80800068: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8080006C: jal         0x8008F938
    // 0x80800070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_4;
    // 0x80800070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800074: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800078: jal         0x8008F990
    // 0x8080007C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_8008F990(rdram, ctx);
        goto after_5;
    // 0x8080007C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_5:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: jal         0x80101FDC
    // 0x80800088: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800088: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x8080008C: b           L_80800308
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800308;
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800094:
    // 0x80800094: jal         0x800D1824
    // 0x80800098: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1824(rdram, ctx);
        goto after_7;
    // 0x80800098: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_7:
    // 0x8080009C: b           L_80800308
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800308;
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A4:
    // 0x808000A4: jal         0x800D90A4
    // 0x808000A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x808000A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x808000AC: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F8;
    }
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80108B04
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000C8: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x808000CC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808000D0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808000D4: jal         0x80085708
    // 0x808000D8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x808000D8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x808000DC: jal         0x800FC660
    // 0x808000E0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_11;
    // 0x808000E0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_11:
    // 0x808000E4: jal         0x800D1804
    // 0x808000E8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1804(rdram, ctx);
        goto after_12;
    // 0x808000E8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_12:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x80101FDC
    // 0x808000F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x808000F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
L_808000F8:
    // 0x808000F8: jal         0x800D1824
    // 0x808000FC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1824(rdram, ctx);
        goto after_14;
    // 0x808000FC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_14:
    // 0x80800100: b           L_80800308
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800308;
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800108:
    // 0x80800108: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080010C: beq         $a0, $zero, L_8080015C
    if (ctx->r4 == 0) {
        // 0x80800110: nop
    
            goto L_8080015C;
    }
    // 0x80800110: nop

    // 0x80800114: jal         0x80106790
    // 0x80800118: nop

    func_80106790(rdram, ctx);
        goto after_15;
    // 0x80800118: nop

    after_15:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80800640
    // 0x80800124: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800640_chicekeydoor(rdram, ctx);
        goto after_16;
    // 0x80800124: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80800128: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x8080012C: lui         $a0, 0x7FFB
        ctx->r4 = S32(0X7FFB << 16);
            goto L_8080015C;
    }
    // 0x8080012C: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800130: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800134: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800138: ori         $a0, $a0, 0x5D6D
    ctx->r4 = ctx->r4 | 0X5D6D;
    // 0x8080013C: jal         0x800C4140
    // 0x80800140: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_17;
    // 0x80800140: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x80800144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800148: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800154: jal         0x80101FDC
    // 0x80800158: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x80800158: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_18:
L_8080015C:
    // 0x8080015C: jal         0x800D1824
    // 0x80800160: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1824(rdram, ctx);
        goto after_19;
    // 0x80800160: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_19:
    // 0x80800164: b           L_80800308
    // 0x80800168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800308;
    // 0x80800168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080016C:
    // 0x8080016C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800170: beq         $a0, $zero, L_80800224
    if (ctx->r4 == 0) {
        // 0x80800174: nop
    
            goto L_80800224;
    }
    // 0x80800174: nop

    // 0x80800178: jal         0x80106790
    // 0x8080017C: nop

    func_80106790(rdram, ctx);
        goto after_20;
    // 0x8080017C: nop

    after_20:
    // 0x80800180: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800184: jal         0x800D90A4
    // 0x80800188: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_21;
    // 0x80800188: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_21:
    // 0x8080018C: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x80800190: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808001F8;
    }
    // 0x80800190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800194: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800198: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x8080019C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x808001A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808001A4: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x808001A8: jal         0x800EFB24
    // 0x808001AC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_22;
    // 0x808001AC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_22:
    // 0x808001B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808001B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001BC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001C0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808001C4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x808001C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001CC: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x808001D0: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808001D4: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808001D8: ori         $a0, $a0, 0x5C56
    ctx->r4 = ctx->r4 | 0X5C56;
    // 0x808001DC: jal         0x800C4140
    // 0x808001E0: swc1        $f10, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f10.u32l;
    func_800C4140(rdram, ctx);
        goto after_23;
    // 0x808001E0: swc1        $f10, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f10.u32l;
    after_23:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80101FDC
    // 0x808001EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_24;
    // 0x808001EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_24:
    // 0x808001F0: b           L_80800224
    // 0x808001F4: nop

        goto L_80800224;
    // 0x808001F4: nop

L_808001F8:
    // 0x808001F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808001FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800200: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800204: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800208: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080020C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800210: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800214: jal         0x800F12D4
    // 0x80800218: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_25;
    // 0x80800218: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_25:
    // 0x8080021C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800220: swc1        $f0, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f0.u32l;
L_80800224:
    // 0x80800224: jal         0x800D1824
    // 0x80800228: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1824(rdram, ctx);
        goto after_26;
    // 0x80800228: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_26:
    // 0x8080022C: b           L_80800308
    // 0x80800230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800308;
    // 0x80800230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800234:
    // 0x80800234: jal         0x800D90A4
    // 0x80800238: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_27;
    // 0x80800238: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_27:
    // 0x8080023C: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800240: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_808002A8;
    }
    // 0x80800240: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800244: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800248: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080024C: jal         0x800F54E4
    // 0x80800250: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    func_800F54E4(rdram, ctx);
        goto after_28;
    // 0x80800250: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    after_28:
    // 0x80800254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800258: jal         0x800F82D4
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_29;
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80800260: jal         0x800DA544
    // 0x80800264: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    func_800DA544(rdram, ctx);
        goto after_30;
    // 0x80800264: addiu       $a0, $zero, 0x3E2
    ctx->r4 = ADD32(0, 0X3E2);
    after_30:
    // 0x80800268: jal         0x80089D40
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800270: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800274: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800278: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080027C: ori         $a0, $a0, 0x5CC7
    ctx->r4 = ctx->r4 | 0X5CC7;
    // 0x80800280: jal         0x800C4140
    // 0x80800284: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_32;
    // 0x80800284: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_32:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x8008A4B0
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80101FDC
    // 0x8080029C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_34;
    // 0x8080029C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_34:
    // 0x808002A0: b           L_808002FC
    // 0x808002A4: nop

        goto L_808002FC;
    // 0x808002A4: nop

L_808002A8:
    // 0x808002A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808002AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002B8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002C4: jal         0x800F12D4
    // 0x808002C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_35;
    // 0x808002C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_35:
    // 0x808002CC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2468, 0X920) << 16);
    // 0x808002D0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808002D4: addiu       $a3, $a3, 0x920
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2468, 0X920));
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002E0: jal         0x80089D50
    // 0x808002E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x808002E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_36:
    // 0x808002E8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808002EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002F0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808002F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808002F8: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_808002FC:
    // 0x808002FC: jal         0x800D1824
    // 0x80800300: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800D1824(rdram, ctx);
        goto after_37;
    // 0x80800300: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_37:
L_80800304:
    // 0x80800304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800308:
    // 0x80800308: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080030C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800310: jr          $ra
    // 0x80800314: nop

    return;
    // 0x80800314: nop

;}
RECOMP_FUNC void chboggyfatboy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1540, 0X11DC) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x11DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1540, 0X11DC));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x11DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1540, 0X11DC));
;}
RECOMP_FUNC void func_80800090_chmole_witchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1680, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1680, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1680, 0XC0));
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_8080086C_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800874: jal         0x800897C8
    // 0x80800878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void bashoes_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800570: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800574: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x80800578: jr          $ra
    // 0x8080057C: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8080057C: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800CEAA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEAA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEAAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEAB0: jal         0x800CE3E0
    // 0x800CEAB4: nop

    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CEAB4: nop

    after_0:
    // 0x800CEAB8: lb          $v0, 0x12($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X12);
    // 0x800CEABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEAC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEAC4: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CEAC8: jr          $ra
    // 0x800CEACC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800CEACC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F60: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F60);
    return;
    // 0x80089F64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800094_chcastleshockpadswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800098: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000A4: beq         $a1, $at, L_808000C0
    if (ctx->r5 == ctx->r1) {
        // 0x808000A8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808000C0;
    }
    // 0x808000A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000AC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808000B0: beq         $a1, $at, L_808000EC
    if (ctx->r5 == ctx->r1) {
        // 0x808000B4: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_808000EC;
    }
    // 0x808000B4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808000B8: b           L_80800140
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800140;
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808000C0:
    // 0x808000C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: jal         0x80108B04
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000D4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808000D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808000DC: jal         0x80085708
    // 0x808000E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808000E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808000E4: b           L_80800154
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800154;
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000EC:
    // 0x808000EC: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x808000F0: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x808000F4: addiu       $a1, $t7, 0x18
    ctx->r5 = ADD32(ctx->r15, 0X18);
    // 0x808000F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808000FC: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800100: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800104: jal         0x80108528
    // 0x80800108: nop

    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80800108: nop

    after_2:
    // 0x8080010C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800114: beql        $t9, $zero, L_80800154
    if (ctx->r25 == 0) {
        // 0x80800118: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800154;
    }
    goto skip_0;
    // 0x80800118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080011C: jal         0x80089CA0
    // 0x80800120: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800120: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800124: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8080012C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800130: jal         0x800862D8
    // 0x80800134: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800134: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800138: b           L_80800154
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800154;
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800140:
    // 0x80800140: jal         0x80085820
    // 0x80800144: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800144: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800148: b           L_80800158
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800158;
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800154:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void func_800F14D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F14D4: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x800F14D8: nop

    // 0x800F14DC: bc1fl       L_800F14F4
    if (!c1cs) {
        // 0x800F14E0: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_800F14F4;
    }
    goto skip_0;
    // 0x800F14E0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_0:
    // 0x800F14E4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800F14E8: jr          $ra
    // 0x800F14EC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800F14EC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F14F0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800F14F4:
    // 0x800F14F4: jr          $ra
    // 0x800F14F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800F14F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_800CE438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE43C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CE440: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CE444: lh          $t7, 0x10($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X10);
    // 0x800CE448: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x800CE44C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800CE450: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800CE454: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800CE458: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CE45C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CE460: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800CE464: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CE468: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800CE46C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE470: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800CE474: jal         0x800F10B4
    // 0x800CE478: nop

    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800CE478: nop

    after_0:
    // 0x800CE47C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CE480: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800CE484: jal         0x800CE3F4
    // 0x800CE488: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800CE3F4(rdram, ctx);
        goto after_1;
    // 0x800CE488: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800CE48C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CE494: jr          $ra
    // 0x800CE498: nop

    return;
    // 0x800CE498: nop

;}
RECOMP_FUNC void func_80801954_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801954: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801958: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080195C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801964: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801968: jal         0x800EEB40
    // 0x8080196C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EEB40(rdram, ctx);
        goto after_0;
    // 0x8080196C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80801970: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801974: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801978: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080197C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801980: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801984: nop

    // 0x80801988: bc1f        L_808019A0
    if (!c1cs) {
        // 0x8080198C: nop
    
            goto L_808019A0;
    }
    // 0x8080198C: nop

    // 0x80801990: jal         0x80801364
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_1;
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801998: b           L_808019A8
    // 0x8080199C: nop

        goto L_808019A8;
    // 0x8080199C: nop

L_808019A0:
    // 0x808019A0: jal         0x80801364
    // 0x808019A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_2;
    // 0x808019A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808019A8:
    // 0x808019A8: jal         0x800DA298
    // 0x808019AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808019AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808019B0: beql        $v0, $zero, L_808019C4
    if (ctx->r2 == 0) {
        // 0x808019B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808019C4;
    }
    goto skip_0;
    // 0x808019B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808019B8: jal         0x8010A570
    // 0x808019BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x808019BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808019C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019C4:
    // 0x808019C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808019CC: jr          $ra
    // 0x808019D0: nop

    return;
    // 0x808019D0: nop

;}
RECOMP_FUNC void _bsbeggass_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828D8: syscall     18
    recomp_syscall_handler(rdram, ctx, 0x800828D8);
    return;
    // 0x800828DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsbfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082958: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082958);
    return;
    // 0x8008295C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gccubeDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C58: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C58);
    return;
    // 0x80087C5C: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void func_80800B38_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B40: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X156C) << 16);
    // 0x80800B44: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X157C) << 16);
    // 0x80800B48: addiu       $a3, $a3, 0x157C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X157C));
    // 0x80800B4C: addiu       $a2, $a2, 0x156C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X156C));
    // 0x80800B50: jal         0x80089D28
    // 0x80800B54: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800B54: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B60: jr          $ra
    // 0x80800B64: nop

    return;
    // 0x80800B64: nop

;}
RECOMP_FUNC void func_800B62CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B62CC: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800B62D0: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x800B62D4: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    // 0x800B62D8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800B62DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B62E0: sw          $a0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r4;
    // 0x800B62E4: sw          $a3, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r7;
    // 0x800B62E8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800B62EC: lw          $a3, 0x160($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X160);
    // 0x800B62F0: jal         0x800B5FE4
    // 0x800B62F4: lbu         $a0, 0x157($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X157);
    func_800B5FE4(rdram, ctx);
        goto after_0;
    // 0x800B62F4: lbu         $a0, 0x157($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X157);
    after_0:
    // 0x800B62F8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B62FC: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B6300: lh          $t6, 0x28($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X28);
    // 0x800B6304: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800B6308: sw          $v0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r2;
    // 0x800B630C: beq         $t6, $zero, L_800B6354
    if (ctx->r14 == 0) {
        // 0x800B6310: nop
    
            goto L_800B6354;
    }
    // 0x800B6310: nop

    // 0x800B6314: lh          $t7, 0x2A($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X2A);
    // 0x800B6318: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x800B631C: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800B6320: beq         $t7, $zero, L_800B6354
    if (ctx->r15 == 0) {
        // 0x800B6324: nop
    
            goto L_800B6354;
    }
    // 0x800B6324: nop

    // 0x800B6328: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800B632C: jal         0x800B60C0
    // 0x800B6330: lw          $a2, 0x15C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X15C);
    func_800B60C0(rdram, ctx);
        goto after_1;
    // 0x800B6330: lw          $a2, 0x15C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X15C);
    after_1:
    // 0x800B6334: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B6338: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B633C: jal         0x800D3724
    // 0x800B6340: lbu         $a0, 0x20($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X20);
    func_800D3724(rdram, ctx);
        goto after_2;
    // 0x800B6340: lbu         $a0, 0x20($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X20);
    after_2:
    // 0x800B6344: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B6348: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B634C: b           L_800B7164
    // 0x800B6350: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
        goto L_800B7164;
    // 0x800B6350: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
L_800B6354:
    // 0x800B6354: bltz        $v0, L_800B7164
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B6358: lw          $a0, 0x150($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X150);
            goto L_800B7164;
    }
    // 0x800B6358: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x800B635C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6360: jal         0x800E7828
    // 0x800B6364: addiu       $a1, $a1, -0x7E5C
    ctx->r5 = ADD32(ctx->r5, -0X7E5C);
    func_800E7828(rdram, ctx);
        goto after_3;
    // 0x800B6364: addiu       $a1, $a1, -0x7E5C
    ctx->r5 = ADD32(ctx->r5, -0X7E5C);
    after_3:
    // 0x800B6368: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800B636C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B6370: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B6374: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x800B6378: lbu         $a0, 0x20($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X20);
    // 0x800B637C: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800B6380: addiu       $a2, $sp, 0x144
    ctx->r6 = ADD32(ctx->r29, 0X144);
    // 0x800B6384: addiu       $a3, $sp, 0x140
    ctx->r7 = ADD32(ctx->r29, 0X140);
    // 0x800B6388: jal         0x800B5C10
    // 0x800B638C: sw          $v1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r3;
    func_800B5C10(rdram, ctx);
        goto after_4;
    // 0x800B638C: sw          $v1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r3;
    after_4:
    // 0x800B6390: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B6394: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B6398: lbu         $t9, 0x21($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X21);
    // 0x800B639C: lw          $v1, 0x12C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X12C);
    // 0x800B63A0: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800B63A4: beq         $t9, $zero, L_800B63E0
    if (ctx->r25 == 0) {
        // 0x800B63A8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800B63E0;
    }
    // 0x800B63A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B63AC: lbu         $a0, 0x20($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X20);
    // 0x800B63B0: sw          $v1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r3;
    // 0x800B63B4: jal         0x800D35BC
    // 0x800B63B8: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    func_800D35BC(rdram, ctx);
        goto after_5;
    // 0x800B63B8: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    after_5:
    // 0x800B63BC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B63C0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B63C4: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B63C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B63CC: lw          $v1, 0x12C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X12C);
    // 0x800B63D0: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x800B63D4: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800B63D8: b           L_800B6404
    // 0x800B63DC: swc1        $f6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f6.u32l;
        goto L_800B6404;
    // 0x800B63DC: swc1        $f6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f6.u32l;
L_800B63E0:
    // 0x800B63E0: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x800B63E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B63E8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800B63EC: bgez        $t5, L_800B6400
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B63F0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800B6400;
    }
    // 0x800B63F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B63F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B63F8: nop

    // 0x800B63FC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800B6400:
    // 0x800B6400: swc1        $f10, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f10.u32l;
L_800B6404:
    // 0x800B6404: lbu         $t6, 0x1F($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X1F);
    // 0x800B6408: bne         $t6, $zero, L_800B6438
    if (ctx->r14 != 0) {
        // 0x800B640C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800B6438;
    }
    // 0x800B640C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B6410: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6414: lwc1        $f6, 0x130($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X130);
    // 0x800B6418: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800B641C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B6420: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B6424: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800B6428: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B642C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B6430: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x800B6434: sb          $t8, 0x1F($t3)
    MEM_B(0X1F, ctx->r11) = ctx->r24;
L_800B6438:
    // 0x800B6438: lbu         $t6, 0x1E($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X1E);
    // 0x800B643C: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800B6440: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x800B6444: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800B6448: beq         $t6, $zero, L_800B64C0
    if (ctx->r14 == 0) {
        // 0x800B644C: lwc1        $f2, 0x0($t5)
        ctx->f2.u32l = MEM_W(ctx->r13, 0X0);
            goto L_800B64C0;
    }
    // 0x800B644C: lwc1        $f2, 0x0($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800B6450: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800B6454: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B6458: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B645C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B6460: sw          $v1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r3;
    // 0x800B6464: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    // 0x800B6468: swc1        $f2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f2.u32l;
    // 0x800B646C: jal         0x800DC178
    // 0x800B6470: swc1        $f16, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x800B6470: swc1        $f16, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x800B6474: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800B6478: lwc1        $f16, 0x13C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800B647C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800B6480: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B6484: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B6488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B648C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B6490: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800B6494: jal         0x800DC178
    // 0x800B6498: swc1        $f16, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x800B6498: swc1        $f16, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800B649C: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800B64A0: lwc1        $f2, 0x138($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800B64A4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B64A8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B64AC: addiu       $t3, $t3, -0x7E80
    ctx->r11 = ADD32(ctx->r11, -0X7E80);
    // 0x800B64B0: lw          $v1, 0x12C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X12C);
    // 0x800B64B4: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x800B64B8: lwc1        $f16, 0x13C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800B64BC: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_800B64C0:
    // 0x800B64C0: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B64C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800B64C8: lwc1        $f10, 0x130($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X130);
    // 0x800B64CC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B64D0: bgez        $t7, L_800B64E8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B64D4: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800B64E8;
    }
    // 0x800B64D4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B64D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B64DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B64E0: nop

    // 0x800B64E4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800B64E8:
    // 0x800B64E8: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800B64EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B64F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B64F4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x800B64F8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800B64FC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800B6500: nop

    // 0x800B6504: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B6508: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B650C: bgez        $t8, L_800B6524
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B6510: add.s       $f16, $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
            goto L_800B6524;
    }
    // 0x800B6510: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800B6514: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6518: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B651C: nop

    // 0x800B6520: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800B6524:
    // 0x800B6524: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B6528: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B652C: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x800B6530: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x800B6534: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B6538: lw          $v0, 0x144($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X144);
    // 0x800B653C: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B6540: bne         $t9, $at, L_800B6690
    if (ctx->r25 != ctx->r1) {
        // 0x800B6544: sub.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
            goto L_800B6690;
    }
    // 0x800B6544: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800B6548: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800B654C: lui         $at, 0xFD18
    ctx->r1 = S32(0XFD18 << 16);
    // 0x800B6550: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6554: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B6558: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B655C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B6560: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6564: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800B6568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B656C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6570: addu        $t5, $t9, $at
    ctx->r13 = ADD32(ctx->r25, ctx->r1);
    // 0x800B6574: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6578: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B657C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6580: lui         $t0, 0xF518
    ctx->r8 = S32(0XF518 << 16);
    // 0x800B6584: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B6588: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x800B658C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800B6590: andi        $t5, $t9, 0x1FF
    ctx->r13 = ctx->r25 & 0X1FF;
    // 0x800B6594: sll         $t6, $t5, 9
    ctx->r14 = S32(ctx->r13 << 9);
    // 0x800B6598: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800B659C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B65A0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B65A4: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x800B65A8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B65AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B65B0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B65B4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B65B8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800B65BC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B65C0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B65C4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B65C8: lui         $t5, 0xF400
    ctx->r13 = S32(0XF400 << 16);
    // 0x800B65CC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800B65D0: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x800B65D4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B65D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B65DC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B65E0: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B65E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B65E8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B65EC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B65F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B65F4: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800B65F8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B65FC: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800B6600: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800B6604: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800B6608: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B660C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800B6610: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6614: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6618: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800B661C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6620: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6624: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x800B6628: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x800B662C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B6630: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800B6634: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x800B6638: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B663C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B6640: or          $t5, $t9, $t0
    ctx->r13 = ctx->r25 | ctx->r8;
    // 0x800B6644: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6648: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B664C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B6650: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6654: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B6658: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B665C: lbu         $t8, 0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6660: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6664: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6668: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B666C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6670: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B6674: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6678: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B667C: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6680: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x800B6684: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B6688: b           L_800B6D0C
    // 0x800B668C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
        goto L_800B6D0C;
    // 0x800B668C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
L_800B6690:
    // 0x800B6690: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x800B6694: bne         $v0, $at, L_800B67E0
    if (ctx->r2 != ctx->r1) {
        // 0x800B6698: lui         $t0, 0xF570
        ctx->r8 = S32(0XF570 << 16);
            goto L_800B67E0;
    }
    // 0x800B6698: lui         $t0, 0xF570
    ctx->r8 = S32(0XF570 << 16);
    // 0x800B669C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B66A0: lui         $at, 0xFD70
    ctx->r1 = S32(0XFD70 << 16);
    // 0x800B66A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B66A8: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800B66AC: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B66B0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800B66B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B66B8: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800B66BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B66C0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B66C4: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800B66C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B66CC: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B66D0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B66D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B66D8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800B66DC: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800B66E0: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B66E4: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B66E8: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x800B66EC: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800B66F0: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B66F4: or          $t6, $t5, $t0
    ctx->r14 = ctx->r13 | ctx->r8;
    // 0x800B66F8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B66FC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6700: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B6704: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6708: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B670C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B6710: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B6714: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B6718: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x800B671C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800B6720: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6724: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B6728: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B672C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B6730: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6734: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6738: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B673C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B6740: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6744: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B6748: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B674C: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x800B6750: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800B6754: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800B6758: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B675C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B6760: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6764: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6768: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B676C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6770: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6774: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B6778: addiu       $t5, $t9, 0x7
    ctx->r13 = ADD32(ctx->r25, 0X7);
    // 0x800B677C: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x800B6780: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800B6784: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800B6788: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800B678C: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x800B6790: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x800B6794: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6798: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B679C: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800B67A0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B67A4: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800B67A8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800B67AC: lbu         $t7, 0x3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X3);
    // 0x800B67B0: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B67B4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B67B8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B67BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B67C0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B67C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B67C8: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B67CC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B67D0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800B67D4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800B67D8: b           L_800B6D0C
    // 0x800B67DC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
        goto L_800B6D0C;
    // 0x800B67DC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_800B67E0:
    // 0x800B67E0: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800B67E4: bne         $v0, $at, L_800B6928
    if (ctx->r2 != ctx->r1) {
        // 0x800B67E8: lui         $t0, 0xF568
        ctx->r8 = S32(0XF568 << 16);
            goto L_800B6928;
    }
    // 0x800B67E8: lui         $t0, 0xF568
    ctx->r8 = S32(0XF568 << 16);
    // 0x800B67EC: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800B67F0: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x800B67F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B67F8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B67FC: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6800: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B6804: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6808: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x800B680C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6810: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6814: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800B6818: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B681C: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6820: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6824: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6828: addiu       $t5, $t9, 0x7
    ctx->r13 = ADD32(ctx->r25, 0X7);
    // 0x800B682C: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x800B6830: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800B6834: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800B6838: lui         $t5, 0x708
    ctx->r13 = S32(0X708 << 16);
    // 0x800B683C: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x800B6840: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x800B6844: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6848: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B684C: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800B6850: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6854: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B6858: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800B685C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B6860: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B6864: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x800B6868: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800B686C: lbu         $t8, 0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6870: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B6874: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6878: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B687C: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6880: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6884: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B6888: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B688C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6890: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800B6894: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B6898: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800B689C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800B68A0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800B68A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B68A8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800B68AC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B68B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B68B4: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B68B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B68BC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B68C0: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800B68C4: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B68C8: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B68CC: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x800B68D0: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800B68D4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B68D8: or          $t6, $t5, $t0
    ctx->r14 = ctx->r13 | ctx->r8;
    // 0x800B68DC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B68E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B68E4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B68E8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B68EC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B68F0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B68F4: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B68F8: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B68FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6900: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800B6904: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B6908: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B690C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6910: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B6914: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B6918: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800B691C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800B6920: b           L_800B6D0C
    // 0x800B6924: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
        goto L_800B6D0C;
    // 0x800B6924: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
L_800B6928:
    // 0x800B6928: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800B692C: bne         $v0, $at, L_800B6A70
    if (ctx->r2 != ctx->r1) {
        // 0x800B6930: lui         $t4, 0xF588
        ctx->r12 = S32(0XF588 << 16);
            goto L_800B6A70;
    }
    // 0x800B6930: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x800B6934: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6938: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x800B693C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6940: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B6944: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B6948: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B694C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6950: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800B6954: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6958: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B695C: addu        $t5, $t9, $at
    ctx->r13 = ADD32(ctx->r25, ctx->r1);
    // 0x800B6960: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6964: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6968: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B696C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6970: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800B6974: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B6978: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B697C: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x800B6980: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800B6984: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B6988: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x800B698C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6990: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6994: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B6998: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B699C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B69A0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B69A4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B69A8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B69AC: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x800B69B0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800B69B4: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x800B69B8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B69BC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B69C0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B69C4: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B69C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B69CC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B69D0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B69D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B69D8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B69DC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B69E0: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x800B69E4: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800B69E8: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800B69EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B69F0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B69F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B69F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B69FC: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6A00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6A04: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6A08: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800B6A0C: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B6A10: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x800B6A14: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800B6A18: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800B6A1C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800B6A20: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x800B6A24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6A28: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6A2C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800B6A30: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6A34: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800B6A38: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B6A3C: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6A40: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6A44: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6A48: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B6A4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B6A50: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B6A54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6A58: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B6A5C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B6A60: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x800B6A64: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800B6A68: b           L_800B6D0C
    // 0x800B6A6C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
        goto L_800B6D0C;
    // 0x800B6A6C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
L_800B6A70:
    // 0x800B6A70: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B6A74: bne         $v0, $at, L_800B6BC8
    if (ctx->r2 != ctx->r1) {
        // 0x800B6A78: lui         $t4, 0xF588
        ctx->r12 = S32(0XF588 << 16);
            goto L_800B6BC8;
    }
    // 0x800B6A78: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x800B6A7C: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6A80: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x800B6A84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6A88: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800B6A8C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B6A90: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6A94: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B6A98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6A9C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x800B6AA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6AA4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6AA8: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800B6AAC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B6AB0: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6AB4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6AB8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6ABC: sra         $t5, $t9, 1
    ctx->r13 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B6AC0: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x800B6AC4: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B6AC8: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800B6ACC: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x800B6AD0: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800B6AD4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B6AD8: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800B6ADC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6AE0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6AE4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B6AE8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6AEC: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B6AF0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B6AF4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B6AF8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B6AFC: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x800B6B00: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800B6B04: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6B08: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B6B0C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6B10: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800B6B14: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6B18: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B6B1C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B6B20: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800B6B24: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800B6B28: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B6B2C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B6B30: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800B6B34: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x800B6B38: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x800B6B3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6B40: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B6B44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6B48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6B4C: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6B50: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6B54: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6B58: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800B6B5C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800B6B60: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B6B64: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x800B6B68: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800B6B6C: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800B6B70: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x800B6B74: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B6B78: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800B6B7C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6B80: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800B6B84: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6B88: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6B8C: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800B6B90: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B6B94: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6B98: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6B9C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6BA0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B6BA4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B6BA8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B6BAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6BB0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B6BB4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B6BB8: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x800B6BBC: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800B6BC0: b           L_800B6D0C
    // 0x800B6BC4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
        goto L_800B6D0C;
    // 0x800B6BC4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
L_800B6BC8:
    // 0x800B6BC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B6BCC: bne         $v0, $at, L_800B6D0C
    if (ctx->r2 != ctx->r1) {
        // 0x800B6BD0: lui         $t0, 0xF548
        ctx->r8 = S32(0XF548 << 16);
            goto L_800B6D0C;
    }
    // 0x800B6BD0: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x800B6BD4: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6BD8: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x800B6BDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6BE0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B6BE4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B6BE8: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800B6BEC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6BF0: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x800B6BF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6BF8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6BFC: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800B6C00: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B6C04: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6C08: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6C0C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6C10: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800B6C14: sra         $t5, $t9, 3
    ctx->r13 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B6C18: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x800B6C1C: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800B6C20: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800B6C24: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800B6C28: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x800B6C2C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6C30: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6C34: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800B6C38: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6C3C: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800B6C40: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B6C44: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B6C48: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B6C4C: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x800B6C50: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800B6C54: lbu         $t7, 0x3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6C58: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B6C5C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6C60: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B6C64: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6C68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6C6C: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6C70: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B6C74: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6C78: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B6C7C: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6C80: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x800B6C84: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B6C88: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800B6C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6C90: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800B6C94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6C98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6C9C: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6CA0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6CA4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6CA8: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x800B6CAC: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800B6CB0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800B6CB4: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x800B6CB8: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B6CBC: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B6CC0: or          $t5, $t9, $t0
    ctx->r13 = ctx->r25 | ctx->r8;
    // 0x800B6CC4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6CC8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6CCC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B6CD0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6CD4: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800B6CD8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B6CDC: lbu         $t8, 0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6CE0: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6CE4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6CE8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B6CEC: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6CF0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B6CF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B6CF8: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B6CFC: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6D00: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x800B6D04: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B6D08: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
L_800B6D0C:
    // 0x800B6D0C: lh          $a2, 0x22($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X22);
    // 0x800B6D10: addiu       $at, $zero, -0x7FFF
    ctx->r1 = ADD32(0, -0X7FFF);
    // 0x800B6D14: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x800B6D18: beql        $a2, $at, L_800B6EBC
    if (ctx->r6 == ctx->r1) {
        // 0x800B6D1C: lbu         $t7, 0x2($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X2);
            goto L_800B6EBC;
    }
    goto skip_0;
    // 0x800B6D1C: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    skip_0:
    // 0x800B6D20: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800B6D24: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x800B6D28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6D2C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B6D30: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800B6D34: lui         $t5, 0xFD88
    ctx->r13 = S32(0XFD88 << 16);
    // 0x800B6D38: lui         $t6, 0x13
    ctx->r14 = S32(0X13 << 16);
    // 0x800B6D3C: addiu       $t6, $t6, -0x7E50
    ctx->r14 = ADD32(ctx->r14, -0X7E50);
    // 0x800B6D40: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B6D44: ori         $t5, $t5, 0x1F
    ctx->r13 = ctx->r13 | 0X1F;
    // 0x800B6D48: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6D4C: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800B6D50: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B6D54: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B6D58: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800B6D5C: nop

    // 0x800B6D60: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x800B6D64: bgezl       $t1, L_800B6D74
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800B6D68: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800B6D74;
    }
    goto skip_1;
    // 0x800B6D68: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x800B6D6C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B6D70: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
L_800B6D74:
    // 0x800B6D74: beq         $at, $zero, L_800B6D80
    if (ctx->r1 == 0) {
        // 0x800B6D78: nop
    
            goto L_800B6D80;
    }
    // 0x800B6D78: nop

    // 0x800B6D7C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
L_800B6D80:
    // 0x800B6D80: bgez        $t0, L_800B6D8C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B6D84: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800B6D8C;
    }
    // 0x800B6D84: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6D88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800B6D8C:
    // 0x800B6D8C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B6D90: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B6D94: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6D98: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6D9C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B6DA0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800B6DA4: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800B6DA8: andi        $t5, $t9, 0x1FF
    ctx->r13 = ctx->r25 & 0X1FF;
    // 0x800B6DAC: sll         $t6, $t5, 9
    ctx->r14 = S32(ctx->r13 << 9);
    // 0x800B6DB0: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800B6DB4: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x800B6DB8: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800B6DBC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800B6DC0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6DC4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800B6DC8: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x800B6DCC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B6DD0: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800B6DD4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6DD8: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800B6DDC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B6DE0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B6DE4: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B6DE8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B6DEC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800B6DF0: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6DF4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B6DF8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6DFC: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6E00: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800B6E04: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B6E08: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800B6E0C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800B6E10: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800B6E14: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B6E18: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800B6E1C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800B6E20: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800B6E24: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800B6E28: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800B6E2C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800B6E30: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6E34: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6E38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B6E3C: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x800B6E40: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800B6E44: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800B6E48: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800B6E4C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800B6E50: ori         $t8, $t5, 0x100
    ctx->r24 = ctx->r13 | 0X100;
    // 0x800B6E54: addu        $t7, $t1, $t0
    ctx->r15 = ADD32(ctx->r9, ctx->r8);
    // 0x800B6E58: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B6E5C: lui         $t6, 0x108
    ctx->r14 = S32(0X108 << 16);
    // 0x800B6E60: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B6E64: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6E68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B6E6C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6E70: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800B6E74: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x800B6E78: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B6E7C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B6E80: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6E84: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B6E88: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800B6E8C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6E90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B6E94: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x800B6E98: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800B6E9C: sll         $t5, $t9, 12
    ctx->r13 = S32(ctx->r25 << 12);
    // 0x800B6EA0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800B6EA4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B6EA8: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x800B6EAC: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B6EB0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800B6EB4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B6EB8: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
L_800B6EBC:
    // 0x800B6EBC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B6EC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B6EC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B6EC8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B6ECC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6ED0: bgez        $t7, L_800B6EE8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B6ED4: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800B6EE8;
    }
    // 0x800B6ED4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B6ED8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6EDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6EE0: nop

    // 0x800B6EE4: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800B6EE8:
    // 0x800B6EE8: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B6EEC: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800B6EF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B6EF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6EF8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B6EFC: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B6F00: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800B6F04: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B6F08: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800B6F0C: nop

    // 0x800B6F10: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800B6F14: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B6F18: blez        $t5, L_800B6F28
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B6F1C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B6F28;
    }
    // 0x800B6F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B6F20: b           L_800B6F28
    // 0x800B6F24: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
        goto L_800B6F28;
    // 0x800B6F24: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
L_800B6F28:
    // 0x800B6F28: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x800B6F2C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800B6F30: bgez        $t6, L_800B6F44
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B6F34: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800B6F44;
    }
    // 0x800B6F34: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B6F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6F3C: nop

    // 0x800B6F40: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800B6F44:
    // 0x800B6F44: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B6F48: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800B6F4C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800B6F50: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B6F54: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B6F58: nop

    // 0x800B6F5C: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B6F60: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800B6F64: nop

    // 0x800B6F68: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x800B6F6C: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800B6F70: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B6F74: blez        $t8, L_800B6F84
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B6F78: trunc.w.s   $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
            goto L_800B6F84;
    }
    // 0x800B6F78: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B6F7C: b           L_800B6F84
    // 0x800B6F80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800B6F84;
    // 0x800B6F80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800B6F84:
    // 0x800B6F84: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B6F88: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x800B6F8C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800B6F90: andi        $t5, $v0, 0xFFF
    ctx->r13 = ctx->r2 & 0XFFF;
    // 0x800B6F94: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B6F98: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B6F9C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B6FA0: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800B6FA4: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800B6FA8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800B6FAC: blez        $t6, L_800B6FBC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B6FB0: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800B6FBC;
    }
    // 0x800B6FB0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800B6FB4: b           L_800B6FC0
    // 0x800B6FB8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
        goto L_800B6FC0;
    // 0x800B6FB8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800B6FBC:
    // 0x800B6FBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B6FC0:
    // 0x800B6FC0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800B6FC4: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x800B6FC8: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800B6FCC: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800B6FD0: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800B6FD4: blez        $t8, L_800B6FE4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B6FD8: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800B6FE4;
    }
    // 0x800B6FD8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B6FDC: b           L_800B6FE8
    // 0x800B6FE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800B6FE8;
    // 0x800B6FE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800B6FE4:
    // 0x800B6FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B6FE8:
    // 0x800B6FE8: andi        $t5, $v0, 0xFFF
    ctx->r13 = ctx->r2 & 0XFFF;
    // 0x800B6FEC: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x800B6FF0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800B6FF4: lui         $t8, 0xE100
    ctx->r24 = S32(0XE100 << 16);
    // 0x800B6FF8: bgez        $a1, L_800B7080
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B6FFC: sw          $t8, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r24;
            goto L_800B7080;
    }
    // 0x800B6FFC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800B7000: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B7004: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B7008: nop

    // 0x800B700C: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B7010: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B7014: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800B7018: nop

    // 0x800B701C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800B7020: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B7024: bgez        $t5, L_800B7054
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B7028: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_800B7054;
    }
    // 0x800B7028: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800B702C: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7034: mflo        $v0
    ctx->r2 = lo;
    // 0x800B7038: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B703C: blez        $t6, L_800B704C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B7040: nop
    
            goto L_800B704C;
    }
    // 0x800B7040: nop

    // 0x800B7044: b           L_800B709C
    // 0x800B7048: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
        goto L_800B709C;
    // 0x800B7048: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800B704C:
    // 0x800B704C: b           L_800B709C
    // 0x800B7050: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
        goto L_800B709C;
    // 0x800B7050: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
L_800B7054:
    // 0x800B7054: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B705C: mflo        $v0
    ctx->r2 = lo;
    // 0x800B7060: sra         $t9, $v0, 7
    ctx->r25 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B7064: bgez        $t9, L_800B7074
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B7068: nop
    
            goto L_800B7074;
    }
    // 0x800B7068: nop

    // 0x800B706C: b           L_800B7074
    // 0x800B7070: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
        goto L_800B7074;
    // 0x800B7070: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_800B7074:
    // 0x800B7074: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B7078: b           L_800B709C
    // 0x800B707C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_800B709C;
    // 0x800B707C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_800B7080:
    // 0x800B7080: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B7084: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B7088: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B708C: div.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B7090: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B7094: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800B7098: nop

L_800B709C:
    // 0x800B709C: bgez        $t0, L_800B7108
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B70A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B7108;
    }
    // 0x800B70A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B70A4: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800B70A8: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B70AC: bgez        $t7, L_800B70DC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B70B0: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800B70DC;
    }
    // 0x800B70B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B70B4: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B70B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B70BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800B70C0: sra         $t5, $v0, 7
    ctx->r13 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B70C4: blez        $t5, L_800B70D4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B70C8: nop
    
            goto L_800B70D4;
    }
    // 0x800B70C8: nop

    // 0x800B70CC: b           L_800B7108
    // 0x800B70D0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800B7108;
    // 0x800B70D0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800B70D4:
    // 0x800B70D4: b           L_800B7108
    // 0x800B70D8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800B7108;
    // 0x800B70D8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B70DC:
    // 0x800B70DC: multu       $a2, $a0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B70E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B70E4: mflo        $v0
    ctx->r2 = lo;
    // 0x800B70E8: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B70EC: bgez        $t6, L_800B70FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B70F0: nop
    
            goto L_800B70FC;
    }
    // 0x800B70F0: nop

    // 0x800B70F4: b           L_800B70FC
    // 0x800B70F8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
        goto L_800B70FC;
    // 0x800B70F8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800B70FC:
    // 0x800B70FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B7100: b           L_800B7108
    // 0x800B7104: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800B7108;
    // 0x800B7104: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800B7108:
    // 0x800B7108: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800B710C: negu        $t5, $t1
    ctx->r13 = SUB32(0, ctx->r9);
    // 0x800B7110: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800B7114: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B7118: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800B711C: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x800B7120: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800B7124: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B7128: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800B712C: or          $t8, $t5, $a1
    ctx->r24 = ctx->r13 | ctx->r5;
    // 0x800B7130: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x800B7134: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B7138: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B713C: lwc1        $f8, 0x130($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X130);
    // 0x800B7140: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x800B7144: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B7148: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B714C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800B7150: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7154: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x800B7158: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800B715C: jal         0x800E7694
    // 0x800B7160: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    func_800E7694(rdram, ctx);
        goto after_8;
    // 0x800B7160: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    after_8:
L_800B7164:
    // 0x800B7164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7168: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    // 0x800B716C: jr          $ra
    // 0x800B7170: nop

    return;
    // 0x800B7170: nop

;}
RECOMP_FUNC void _basudie_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085240: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085240);
    return;
    // 0x80085244: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8008EEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EEC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008EEC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008EECC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008EED0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008EED4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008EED8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008EEDC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8008EEE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008EEE4: jal         0x800CB840
    // 0x8008EEE8: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    func_800CB840(rdram, ctx);
        goto after_0;
    // 0x8008EEE8: lw          $a1, 0x184($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X184);
    after_0:
    // 0x8008EEEC: jal         0x8008E938
    // 0x8008EEF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008E938(rdram, ctx);
        goto after_1;
    // 0x8008EEF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8008EEF4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8008EEF8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8008EEFC: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8008EF00: lw          $t8, 0x184($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X184);
    // 0x8008EF04: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8008EF08: addiu       $a3, $a3, -0x11E4
    ctx->r7 = ADD32(ctx->r7, -0X11E4);
    // 0x8008EF0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EF10: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008EF14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008EF18: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008EF1C: jal         0x80109C4C
    // 0x8008EF20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80109C4C(rdram, ctx);
        goto after_2;
    // 0x8008EF20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x8008EF24: jal         0x800CB870
    // 0x8008EF28: nop

    func_800CB870(rdram, ctx);
        goto after_3;
    // 0x8008EF28: nop

    after_3:
    // 0x8008EF2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008EF30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008EF34: jr          $ra
    // 0x8008EF38: nop

    return;
    // 0x8008EF38: nop

;}
RECOMP_FUNC void func_8080065C_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800664: jal         0x80082FF0
    // 0x80800668: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800668: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080066C: jal         0x808001D4
    // 0x80800670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001D4_bscarry(rdram, ctx);
        goto after_1;
    // 0x80800670: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080067C: jr          $ra
    // 0x80800680: nop

    return;
    // 0x80800680: nop

;}
RECOMP_FUNC void _chbadshad_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085788: syscall     173
    recomp_syscall_handler(rdram, ctx, 0x80085788);
    return;
    // 0x8008578C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800D8FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8FF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D8FFC: jr          $ra
    // 0x800D9000: lwc1        $f0, -0x38A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X38A0);
    return;
    // 0x800D9000: lwc1        $f0, -0x38A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X38A0);
;}
RECOMP_FUNC void func_800F43A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F43A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F43AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800F43B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F43B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F43B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800F43BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800F43C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800F43C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F43C8: addiu       $s1, $zero, 0x19C
    ctx->r17 = ADD32(0, 0X19C);
    // 0x800F43CC: jal         0x8001ACCC
    // 0x800F43D0: addiu       $a0, $zero, 0x19C
    ctx->r4 = ADD32(0, 0X19C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800F43D0: addiu       $a0, $zero, 0x19C
    ctx->r4 = ADD32(0, 0X19C);
    after_0:
    // 0x800F43D4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800F43D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800F43DC: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_800F43E0:
    // 0x800F43E0: jal         0x800F4354
    // 0x800F43E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F4354(rdram, ctx);
        goto after_1;
    // 0x800F43E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800F43E8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800F43EC: bgez        $v0, L_800F4400
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F43F0: andi        $v1, $v0, 0x3
        ctx->r3 = ctx->r2 & 0X3;
            goto L_800F4400;
    }
    // 0x800F43F0: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x800F43F4: beq         $v1, $zero, L_800F4400
    if (ctx->r3 == 0) {
        // 0x800F43F8: nop
    
            goto L_800F4400;
    }
    // 0x800F43F8: nop

    // 0x800F43FC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
L_800F4400:
    // 0x800F4400: beq         $v1, $zero, L_800F4410
    if (ctx->r3 == 0) {
        // 0x800F4404: addu        $t6, $s1, $a3
        ctx->r14 = ADD32(ctx->r17, ctx->r7);
            goto L_800F4410;
    }
    // 0x800F4404: addu        $t6, $s1, $a3
    ctx->r14 = ADD32(ctx->r17, ctx->r7);
    // 0x800F4408: b           L_800F4414
    // 0x800F440C: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
        goto L_800F4414;
    // 0x800F440C: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
L_800F4410:
    // 0x800F4410: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800F4414:
    // 0x800F4414: addu        $s1, $t6, $a2
    ctx->r17 = ADD32(ctx->r14, ctx->r6);
    // 0x800F4418: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F441C: jal         0x8001B208
    // 0x800F4420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    heap_realloc(rdram, ctx);
        goto after_2;
    // 0x800F4420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800F4424: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F4428: sltiu       $at, $s0, 0x56
    ctx->r1 = ctx->r16 < 0X56 ? 1 : 0;
    // 0x800F442C: bne         $at, $zero, L_800F43E0
    if (ctx->r1 != 0) {
        // 0x800F4430: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800F43E0;
    }
    // 0x800F4430: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800F4434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F4438: jal         0x8002D6E0
    // 0x800F443C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _bzero(rdram, ctx);
        goto after_3;
    // 0x800F443C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800F4440: addiu       $s1, $zero, 0x19C
    ctx->r17 = ADD32(0, 0X19C);
    // 0x800F4444: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800F4448: addiu       $s3, $zero, 0x56
    ctx->r19 = ADD32(0, 0X56);
L_800F444C:
    // 0x800F444C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800F4450: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x800F4454: addu        $t7, $s2, $s1
    ctx->r15 = ADD32(ctx->r18, ctx->r17);
    // 0x800F4458: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800F445C: jal         0x800F4354
    // 0x800F4460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F4354(rdram, ctx);
        goto after_4;
    // 0x800F4460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800F4464: bgez        $v0, L_800F4478
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F4468: andi        $v1, $v0, 0x3
        ctx->r3 = ctx->r2 & 0X3;
            goto L_800F4478;
    }
    // 0x800F4468: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x800F446C: beq         $v1, $zero, L_800F4478
    if (ctx->r3 == 0) {
        // 0x800F4470: nop
    
            goto L_800F4478;
    }
    // 0x800F4470: nop

    // 0x800F4474: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
L_800F4478:
    // 0x800F4478: beq         $v1, $zero, L_800F4488
    if (ctx->r3 == 0) {
        // 0x800F447C: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800F4488;
    }
    // 0x800F447C: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    // 0x800F4480: b           L_800F448C
    // 0x800F4484: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
        goto L_800F448C;
    // 0x800F4484: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
L_800F4488:
    // 0x800F4488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800F448C:
    // 0x800F448C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F4490: bne         $s0, $s3, L_800F444C
    if (ctx->r16 != ctx->r19) {
        // 0x800F4494: addu        $s1, $t0, $a2
        ctx->r17 = ADD32(ctx->r8, ctx->r6);
            goto L_800F444C;
    }
    // 0x800F4494: addu        $s1, $t0, $a2
    ctx->r17 = ADD32(ctx->r8, ctx->r6);
    // 0x800F4498: sw          $zero, 0x180($s2)
    MEM_W(0X180, ctx->r18) = 0;
    // 0x800F449C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800F44A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800F44A4: jal         0x80098C48
    // 0x800F44A8: sw          $t1, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->r9;
    func_80098C48(rdram, ctx);
        goto after_5;
    // 0x800F44A8: sw          $t1, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->r9;
    after_5:
    // 0x800F44AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800F44B0: jal         0x800F44DC
    // 0x800F44B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F44DC(rdram, ctx);
        goto after_6;
    // 0x800F44B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x800F44B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800F44BC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800F44C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800F44C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F44C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F44CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800F44D0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800F44D4: jr          $ra
    // 0x800F44D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800F44D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gspropsDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808006A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808006AC: jal         0x800EE8CC
    // 0x808006B0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE8CC(rdram, ctx);
        goto after_0;
    // 0x808006B0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808006B4: jal         0x800BDBC4
    // 0x808006B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800BDBC4(rdram, ctx);
        goto after_1;
    // 0x808006B8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808006BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808006C0: jal         0x800E9A24
    // 0x808006C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E9A24(rdram, ctx);
        goto after_2;
    // 0x808006C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808006C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006CC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808006D0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x808006D4: jal         0x8001BBC8
    // 0x808006D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    aligned4_memcpy(rdram, ctx);
        goto after_3;
    // 0x808006D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x808006DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E0: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x808006E4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808006E8: bne         $t7, $zero, L_808006FC
    if (ctx->r15 != 0) {
        // 0x808006EC: nop
    
            goto L_808006FC;
    }
    // 0x808006EC: nop

    // 0x808006F0: lbu         $t9, 0x12($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X12);
    // 0x808006F4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x808006F8: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
L_808006FC:
    // 0x808006FC: jal         0x80800524
    // 0x80800700: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80800524_gspropsDll(rdram, ctx);
        goto after_4;
    // 0x80800700: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800708: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void func_808000B8_gccubeDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000C0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808000C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808000D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808000D8: jal         0x800825D0
    // 0x808000DC: addiu       $a2, $sp, 0x3F
    ctx->r6 = ADD32(ctx->r29, 0X3F);
    _gsmaker_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a2, $sp, 0x3F
    ctx->r6 = ADD32(ctx->r29, 0X3F);
    after_0:
    // 0x808000E0: beq         $v0, $zero, L_80800170
    if (ctx->r2 == 0) {
        // 0x808000E4: lbu         $t6, 0x3F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X3F);
            goto L_80800170;
    }
    // 0x808000E4: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x808000E8: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x808000EC: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000F0: mflo        $a0
    ctx->r4 = lo;
    // 0x808000F4: jal         0x8001ACCC
    // 0x808000F8: nop

    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x808000F8: nop

    after_1:
    // 0x808000FC: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x80800100: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800104: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800108: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080010C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800110: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800114: mflo        $a3
    ctx->r7 = lo;
    // 0x80800118: jal         0x800825D8
    // 0x8080011C: nop

    _gsmaker_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x8080011C: nop

    after_2:
    // 0x80800120: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x80800124: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800128: blez        $t8, L_80800168
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8080012C: nop
    
            goto L_80800168;
    }
    // 0x8080012C: nop

    // 0x80800130: bne         $s2, $zero, L_80800168
    if (ctx->r18 != 0) {
        // 0x80800134: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_80800168;
    }
    // 0x80800134: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800138: sll         $t9, $zero, 4
    ctx->r25 = S32(0 << 4);
    // 0x8080013C: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
L_80800140:
    // 0x80800140: jal         0x80088B98
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropsDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800148: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x8080014C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800150: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800154: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800158: beq         $at, $zero, L_80800168
    if (ctx->r1 == 0) {
        // 0x8080015C: nop
    
            goto L_80800168;
    }
    // 0x8080015C: nop

    // 0x80800160: beq         $s2, $zero, L_80800140
    if (ctx->r18 == 0) {
        // 0x80800164: nop
    
            goto L_80800140;
    }
    // 0x80800164: nop

L_80800168:
    // 0x80800168: jal         0x8001B084
    // 0x8080016C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    heap_free(rdram, ctx);
        goto after_4;
    // 0x8080016C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
L_80800170:
    // 0x80800170: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800174: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800178: jal         0x800825D0
    // 0x8080017C: addiu       $a2, $sp, 0x3F
    ctx->r6 = ADD32(ctx->r29, 0X3F);
    _gsmaker_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080017C: addiu       $a2, $sp, 0x3F
    ctx->r6 = ADD32(ctx->r29, 0X3F);
    after_5:
    // 0x80800180: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x80800184: lbu         $t2, 0x3F($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X3F);
            goto L_80800218;
    }
    // 0x80800184: lbu         $t2, 0x3F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3F);
    // 0x80800188: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x8080018C: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800190: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800194: mflo        $a0
    ctx->r4 = lo;
    // 0x80800198: jal         0x8001ACCC
    // 0x8080019C: nop

    heap_alloc(rdram, ctx);
        goto after_6;
    // 0x8080019C: nop

    after_6:
    // 0x808001A0: lbu         $t3, 0x3F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3F);
    // 0x808001A4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001AC: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808001B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808001B8: mflo        $a3
    ctx->r7 = lo;
    // 0x808001BC: jal         0x800825D8
    // 0x808001C0: nop

    _gsmaker_entrypoint_18(rdram, ctx);
        goto after_7;
    // 0x808001C0: nop

    after_7:
    // 0x808001C4: lbu         $t4, 0x3F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3F);
    // 0x808001C8: blez        $t4, L_80800210
    if (SIGNED(ctx->r12) <= 0) {
        // 0x808001CC: nop
    
            goto L_80800210;
    }
    // 0x808001CC: nop

    // 0x808001D0: bne         $s2, $zero, L_80800210
    if (ctx->r18 != 0) {
        // 0x808001D4: sll         $t5, $s1, 2
        ctx->r13 = S32(ctx->r17 << 2);
            goto L_80800210;
    }
    // 0x808001D4: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x808001D8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808001DC: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x808001E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x808001E4: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_808001E8:
    // 0x808001E8: jal         0x80088BA0
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropsDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001F0: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x808001F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808001F8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808001FC: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800200: beq         $at, $zero, L_80800210
    if (ctx->r1 == 0) {
        // 0x80800204: nop
    
            goto L_80800210;
    }
    // 0x80800204: nop

    // 0x80800208: beq         $s2, $zero, L_808001E8
    if (ctx->r18 == 0) {
        // 0x8080020C: nop
    
            goto L_808001E8;
    }
    // 0x8080020C: nop

L_80800210:
    // 0x80800210: jal         0x8001B084
    // 0x80800214: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    heap_free(rdram, ctx);
        goto after_9;
    // 0x80800214: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
L_80800218:
    // 0x80800218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080021C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800220: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800224: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800228: jr          $ra
    // 0x8080022C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080022C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chsabreman_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1232, 0X1D30) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1D30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1D30));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1D30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1D30));
;}
RECOMP_FUNC void func_800BE9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE9B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE9B4: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BE9B8: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x800BE9BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BE9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE9C4: beql        $t6, $zero, L_800BE9D8
    if (ctx->r14 == 0) {
        // 0x800BE9C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BE9D8;
    }
    goto skip_0;
    // 0x800BE9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BE9CC: jal         0x80087F88
    // 0x800BE9D0: nop

    _gcmapsects_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x800BE9D0: nop

    after_0:
    // 0x800BE9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BE9D8:
    // 0x800BE9D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BE9DC: jr          $ra
    // 0x800BE9E0: nop

    return;
    // 0x800BE9E0: nop

;}
RECOMP_FUNC void func_800F84FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F84FC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800F8500: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800F8504: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800F8508: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800F850C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800F8510: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800F8514: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F8518: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800F851C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800F8520: addiu       $s5, $s5, 0x5490
    ctx->r21 = ADD32(ctx->r21, 0X5490);
    // 0x800F8524: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800F8528: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x800F852C: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_800F8530:
    // 0x800F8530: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x800F8534: beql        $t6, $zero, L_800F85C0
    if (ctx->r14 == 0) {
        // 0x800F8538: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800F85C0;
    }
    goto skip_0;
    // 0x800F8538: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800F853C: jal         0x800F5924
    // 0x800F8540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F5924(rdram, ctx);
        goto after_0;
    // 0x800F8540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800F8544: beq         $v0, $zero, L_800F85BC
    if (ctx->r2 == 0) {
        // 0x800F8548: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800F85BC;
    }
    // 0x800F8548: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800F854C: jal         0x800F5A00
    // 0x800F8550: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x800F8550: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x800F8554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800F8558: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800F855C: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x800F8560: jal         0x800F5950
    // 0x800F8564: addiu       $a3, $sp, 0x64
    ctx->r7 = ADD32(ctx->r29, 0X64);
    func_800F5950(rdram, ctx);
        goto after_2;
    // 0x800F8564: addiu       $a3, $sp, 0x64
    ctx->r7 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x800F8568: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F856C: addiu       $s1, $s1, 0x5490
    ctx->r17 = ADD32(ctx->r17, 0X5490);
    // 0x800F8570: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800F8574:
    // 0x800F8574: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800F8578: beql        $t7, $zero, L_800F85B4
    if (ctx->r15 == 0) {
        // 0x800F857C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800F85B4;
    }
    goto skip_1;
    // 0x800F857C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800F8580: beql        $s2, $s0, L_800F85B4
    if (ctx->r18 == ctx->r16) {
        // 0x800F8584: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800F85B4;
    }
    goto skip_2;
    // 0x800F8584: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800F8588: jal         0x800F58F8
    // 0x800F858C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F58F8(rdram, ctx);
        goto after_3;
    // 0x800F858C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F8590: beq         $v0, $zero, L_800F85B0
    if (ctx->r2 == 0) {
        // 0x800F8594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F85B0;
    }
    // 0x800F8594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F8598: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800F859C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800F85A0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800F85A4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800F85A8: jal         0x800F4EC8
    // 0x800F85AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_4;
    // 0x800F85AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
L_800F85B0:
    // 0x800F85B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800F85B4:
    // 0x800F85B4: bne         $s0, $s4, L_800F8574
    if (ctx->r16 != ctx->r20) {
        // 0x800F85B8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800F8574;
    }
    // 0x800F85B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800F85BC:
    // 0x800F85BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800F85C0:
    // 0x800F85C0: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x800F85C4: bne         $at, $zero, L_800F8530
    if (ctx->r1 != 0) {
        // 0x800F85C8: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800F8530;
    }
    // 0x800F85C8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800F85CC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800F85D0: addiu       $s2, $s2, 0x5490
    ctx->r18 = ADD32(ctx->r18, 0X5490);
    // 0x800F85D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F85D8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F85DC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F85E0: sb          $t8, 0x49($s2)
    MEM_B(0X49, ctx->r18) = ctx->r24;
    // 0x800F85E4: addiu       $s1, $s1, 0x54B0
    ctx->r17 = ADD32(ctx->r17, 0X54B0);
    // 0x800F85E8: addiu       $s0, $s0, 0x5490
    ctx->r16 = ADD32(ctx->r16, 0X5490);
    // 0x800F85EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800F85F0:
    // 0x800F85F0: beql        $a0, $zero, L_800F8604
    if (ctx->r4 == 0) {
        // 0x800F85F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800F8604;
    }
    goto skip_3;
    // 0x800F85F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_3:
    // 0x800F85F8: jal         0x800F468C
    // 0x800F85FC: nop

    func_800F468C(rdram, ctx);
        goto after_5;
    // 0x800F85FC: nop

    after_5:
    // 0x800F8600: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800F8604:
    // 0x800F8604: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800F8608: bnel        $at, $zero, L_800F85F0
    if (ctx->r1 != 0) {
        // 0x800F860C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800F85F0;
    }
    goto skip_4;
    // 0x800F860C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800F8610: jal         0x800F9198
    // 0x800F8614: sb          $zero, 0x49($s2)
    MEM_B(0X49, ctx->r18) = 0;
    func_800F9198(rdram, ctx);
        goto after_6;
    // 0x800F8614: sb          $zero, 0x49($s2)
    MEM_B(0X49, ctx->r18) = 0;
    after_6:
    // 0x800F8618: jal         0x800F54E4
    // 0x800F861C: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x800F861C: nop

    after_7:
    // 0x800F8620: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800F8624: jal         0x800F5410
    // 0x800F8628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_8;
    // 0x800F8628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x800F862C: lh          $v1, 0x50($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X50);
    // 0x800F8630: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F8634: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800F8638: beq         $v1, $at, L_800F866C
    if (ctx->r3 == ctx->r1) {
        // 0x800F863C: nop
    
            goto L_800F866C;
    }
    // 0x800F863C: nop

    // 0x800F8640: bne         $s3, $v1, L_800F8654
    if (ctx->r19 != ctx->r3) {
        // 0x800F8644: nop
    
            goto L_800F8654;
    }
    // 0x800F8644: nop

    // 0x800F8648: lh          $t9, 0x52($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X52);
    // 0x800F864C: beq         $v0, $t9, L_800F866C
    if (ctx->r2 == ctx->r25) {
        // 0x800F8650: nop
    
            goto L_800F866C;
    }
    // 0x800F8650: nop

L_800F8654:
    // 0x800F8654: jal         0x800D5240
    // 0x800F8658: nop

    func_800D5240(rdram, ctx);
        goto after_9;
    // 0x800F8658: nop

    after_9:
    // 0x800F865C: bne         $v0, $zero, L_800F866C
    if (ctx->r2 != 0) {
        // 0x800F8660: nop
    
            goto L_800F866C;
    }
    // 0x800F8660: nop

    // 0x800F8664: jal         0x800A1658
    // 0x800F8668: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800A1658(rdram, ctx);
        goto after_10;
    // 0x800F8668: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
L_800F866C:
    // 0x800F866C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F8670: addiu       $s0, $s0, 0x5490
    ctx->r16 = ADD32(ctx->r16, 0X5490);
    // 0x800F8674: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800F8678:
    // 0x800F8678: lbu         $t0, 0x20($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X20);
    // 0x800F867C: beql        $t0, $zero, L_800F8690
    if (ctx->r8 == 0) {
        // 0x800F8680: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800F8690;
    }
    goto skip_5;
    // 0x800F8680: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x800F8684: jal         0x800F759C
    // 0x800F8688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F759C(rdram, ctx);
        goto after_11;
    // 0x800F8688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800F868C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800F8690:
    // 0x800F8690: bne         $s1, $s4, L_800F8678
    if (ctx->r17 != ctx->r20) {
        // 0x800F8694: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800F8678;
    }
    // 0x800F8694: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F8698: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F869C: sh          $s3, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r19;
    // 0x800F86A0: sh          $s5, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r21;
    // 0x800F86A4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800F86A8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800F86AC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800F86B0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800F86B4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800F86B8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800F86BC: jr          $ra
    // 0x800F86C0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800F86C0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void chdiggerground_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(856, 0X408) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x408
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(856, 0X408));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x408
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(856, 0X408));
;}
RECOMP_FUNC void func_80801208_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080120C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801210: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801218: jal         0x8008CABC
    // 0x8080121C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080121C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80801220: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801224: jal         0x8008AF24
    // 0x80801228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80801228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080122C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801230: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801234: jal         0x8008B1C8
    // 0x80801238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_2;
    // 0x80801238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8080123C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801240: jal         0x8008AED4
    // 0x80801244: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80801244: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    after_3:
    // 0x80801248: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x8080124C: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80801250: jal         0x8008B1BC
    // 0x80801254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80801254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80801258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080125C: jal         0x8008B134
    // 0x80801260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80801260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80801264: jal         0x8008B064
    // 0x80801268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80801268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8080126C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801270: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080127C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801280: jal         0x8009FFD8
    // 0x80801284: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x80801284: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x80801288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080128C: jal         0x800A0CF4
    // 0x80801290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_8;
    // 0x80801290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80801294: jal         0x80800128
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bsbfly(rdram, ctx);
        goto after_9;
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080129C: jal         0x80095A40
    // 0x808012A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_10;
    // 0x808012A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A8: jal         0x800961AC
    // 0x808012AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_11;
    // 0x808012AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808012B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B4: jal         0x8009C4CC
    // 0x808012B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_12;
    // 0x808012B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x808012BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C0: jal         0x8009BF5C
    // 0x808012C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_13;
    // 0x808012C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x808012C8: jal         0x8009BC6C
    // 0x808012CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_14;
    // 0x808012CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808012D0: jal         0x8009BC90
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_15;
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012DC: jal         0x80093360
    // 0x808012E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_16;
    // 0x808012E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x808012E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012E8: addiu       $a1, $zero, 0x420
    ctx->r5 = ADD32(0, 0X420);
    // 0x808012EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808012F0: jal         0x8009DF94
    // 0x808012F4: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF94(rdram, ctx);
        goto after_17;
    // 0x808012F4: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_17:
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012FC: addiu       $a1, $zero, 0x444
    ctx->r5 = ADD32(0, 0X444);
    // 0x80801300: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801304: jal         0x8009DB04
    // 0x80801308: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_18;
    // 0x80801308: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_18:
    // 0x8080130C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(96, 0X1D14) << 16);
    // 0x80801310: lwc1        $f4, 0x1D14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(96, 0X1D14));
    // 0x80801314: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80801318: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8080131C: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80801320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801324: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801328: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080132C: jr          $ra
    // 0x80801330: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801330: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808000C0_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808000C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000CC: beq         $a1, $at, L_80800104
    if (ctx->r5 == ctx->r1) {
        // 0x808000D0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800104;
    }
    // 0x808000D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000D4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000D8: beq         $a1, $at, L_80800114
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0xAB
        ctx->r1 = ADD32(0, 0XAB);
            goto L_80800114;
    }
    // 0x808000DC: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x808000E0: bne         $a1, $at, L_80800138
    if (ctx->r5 != ctx->r1) {
        // 0x808000E4: nop
    
            goto L_80800138;
    }
    // 0x808000E4: nop

    // 0x808000E8: jal         0x80101080
    // 0x808000EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x808000EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: jal         0x801018A4
    // 0x808000F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_801018A4(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808000FC: b           L_80800144
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800144;
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800104:
    // 0x80800104: jal         0x80800154
    // 0x80800108: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800154_chexploder(rdram, ctx);
        goto after_2;
    // 0x80800108: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080010C: b           L_80800144
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800144;
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800114:
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800118: jal         0x80100094
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x80800128: jal         0x80103140
    // 0x8080012C: lhu         $a2, 0x16($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X16);
    func_80103140(rdram, ctx);
        goto after_4;
    // 0x8080012C: lhu         $a2, 0x16($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X16);
    after_4:
    // 0x80800130: b           L_80800144
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800144;
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800138:
    // 0x80800138: b           L_80800144
    // 0x8080013C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800144;
    // 0x8080013C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800144:
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_80800648_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800648: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8080064C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80800650: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800654: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800658: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8080065C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80800660: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // 0x80800664: jal         0x80100094
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080066C: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80800670: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80800674: slti        $at, $a2, 0x53
    ctx->r1 = SIGNED(ctx->r6) < 0X53 ? 1 : 0;
    // 0x80800678: bne         $at, $zero, L_80800694
    if (ctx->r1 != 0) {
        // 0x8080067C: addiu       $t6, $a2, -0xA
        ctx->r14 = ADD32(ctx->r6, -0XA);
            goto L_80800694;
    }
    // 0x8080067C: addiu       $t6, $a2, -0xA
    ctx->r14 = ADD32(ctx->r6, -0XA);
    // 0x80800680: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800684: beq         $a2, $at, L_80800C78
    if (ctx->r6 == ctx->r1) {
        // 0x80800688: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80800C78;
    }
    // 0x80800688: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8080068C: b           L_80800D48
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D48;
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800694:
    // 0x80800694: sltiu       $at, $t6, 0x49
    ctx->r1 = ctx->r14 < 0X49 ? 1 : 0;
    // 0x80800698: beq         $at, $zero, L_80800D3C
    if (ctx->r1 == 0) {
        // 0x8080069C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800D3C;
    }
    // 0x8080069C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808006A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1D04) << 16);
    // 0x808006A4: addu        $at, $at, $t6
    gpr jr_addend_808006AC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808006A8: lw          $t6, 0x1D04($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1D04));
    // 0x808006AC: jr          $t6
    // 0x808006B0: nop

    switch (jr_addend_808006AC >> 2) {
        case 0: goto L_808007D8; break;
        case 1: goto L_808009A0; break;
        case 2: goto L_80800D3C; break;
        case 3: goto L_80800D3C; break;
        case 4: goto L_80800D3C; break;
        case 5: goto L_80800D3C; break;
        case 6: goto L_80800D3C; break;
        case 7: goto L_80800D3C; break;
        case 8: goto L_80800D3C; break;
        case 9: goto L_80800D3C; break;
        case 10: goto L_80800D3C; break;
        case 11: goto L_80800D3C; break;
        case 12: goto L_80800D3C; break;
        case 13: goto L_80800D3C; break;
        case 14: goto L_808008E4; break;
        case 15: goto L_80800D3C; break;
        case 16: goto L_80800D3C; break;
        case 17: goto L_80800D3C; break;
        case 18: goto L_80800D3C; break;
        case 19: goto L_80800D3C; break;
        case 20: goto L_80800D3C; break;
        case 21: goto L_80800D3C; break;
        case 22: goto L_80800D3C; break;
        case 23: goto L_80800D3C; break;
        case 24: goto L_80800D3C; break;
        case 25: goto L_80800D3C; break;
        case 26: goto L_80800D3C; break;
        case 27: goto L_80800D3C; break;
        case 28: goto L_80800D3C; break;
        case 29: goto L_80800D3C; break;
        case 30: goto L_80800D3C; break;
        case 31: goto L_80800C58; break;
        case 32: goto L_80800C68; break;
        case 33: goto L_80800D3C; break;
        case 34: goto L_80800D3C; break;
        case 35: goto L_80800D3C; break;
        case 36: goto L_80800984; break;
        case 37: goto L_80800D3C; break;
        case 38: goto L_80800D3C; break;
        case 39: goto L_80800D3C; break;
        case 40: goto L_80800D3C; break;
        case 41: goto L_80800D3C; break;
        case 42: goto L_80800D3C; break;
        case 43: goto L_80800D3C; break;
        case 44: goto L_80800D3C; break;
        case 45: goto L_80800D3C; break;
        case 46: goto L_80800D3C; break;
        case 47: goto L_80800D3C; break;
        case 48: goto L_80800D3C; break;
        case 49: goto L_80800D3C; break;
        case 50: goto L_80800D3C; break;
        case 51: goto L_808006B4; break;
        case 52: goto L_80800D3C; break;
        case 53: goto L_80800D3C; break;
        case 54: goto L_80800D3C; break;
        case 55: goto L_80800D3C; break;
        case 56: goto L_80800D3C; break;
        case 57: goto L_80800D3C; break;
        case 58: goto L_80800D3C; break;
        case 59: goto L_80800D3C; break;
        case 60: goto L_80800D3C; break;
        case 61: goto L_80800D3C; break;
        case 62: goto L_80800D3C; break;
        case 63: goto L_80800D3C; break;
        case 64: goto L_80800AA4; break;
        case 65: goto L_80800BA0; break;
        case 66: goto L_80800BF4; break;
        case 67: goto L_80800D3C; break;
        case 68: goto L_80800C08; break;
        case 69: goto L_80800D3C; break;
        case 70: goto L_80800D3C; break;
        case 71: goto L_80800D3C; break;
        case 72: goto L_80800D20; break;
        default: switch_error(__func__, 0x808006AC, 0x80801D04);
    }
    // 0x808006B0: nop

L_808006B4:
    // 0x808006B4: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x808006B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006BC: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    // 0x808006C0: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x808006C4: nop
    
            goto L_808006EC;
    }
    // 0x808006C4: nop

    // 0x808006C8: beq         $v0, $at, L_808006EC
    if (ctx->r2 == ctx->r1) {
        // 0x808006CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808006EC;
    }
    // 0x808006CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006D0: beq         $v0, $at, L_8080076C
    if (ctx->r2 == ctx->r1) {
        // 0x808006D4: lw          $a1, 0x70($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X70);
            goto L_8080076C;
    }
    // 0x808006D4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x808006D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006DC: beq         $v0, $at, L_808007B4
    if (ctx->r2 == ctx->r1) {
        // 0x808006E0: addiu       $a0, $zero, 0x466
        ctx->r4 = ADD32(0, 0X466);
            goto L_808007B4;
    }
    // 0x808006E0: addiu       $a0, $zero, 0x466
    ctx->r4 = ADD32(0, 0X466);
    // 0x808006E4: b           L_80800D48
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006EC:
    // 0x808006EC: jal         0x801084B0
    // 0x808006F0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808006F0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x808006F4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808006F8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x808006FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800700: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800704: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    // 0x80800708: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8080070C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800710: addiu       $t2, $zero, 0x6B4
    ctx->r10 = ADD32(0, 0X6B4);
    // 0x80800714: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800718: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x8080071C: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    // 0x80800720: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
    // 0x80800724: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80800728: bnel        $t1, $at, L_8080073C
    if (ctx->r9 != ctx->r1) {
        // 0x8080072C: sw          $zero, 0x50($v0)
        MEM_W(0X50, ctx->r2) = 0;
            goto L_8080073C;
    }
    goto skip_0;
    // 0x8080072C: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
    skip_0:
    // 0x80800730: b           L_8080073C
    // 0x80800734: sw          $t2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r10;
        goto L_8080073C;
    // 0x80800734: sw          $t2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r10;
    // 0x80800738: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
L_8080073C:
    // 0x8080073C: jal         0x800DA298
    // 0x80800740: sw          $a1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800740: sw          $a1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800744: bne         $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x80800748: lw          $a1, 0x68($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X68);
            goto L_8080075C;
    }
    // 0x80800748: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8080074C: jal         0x8010A570
    // 0x80800750: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800750: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80800754: b           L_80800D48
    // 0x80800758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080075C:
    // 0x8080075C: lbu         $t3, 0x65($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X65);
    // 0x80800760: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80800764: b           L_80800D44
    // 0x80800768: sb          $t4, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r12;
        goto L_80800D44;
    // 0x80800768: sb          $t4, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r12;
L_8080076C:
    // 0x8080076C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800770: jal         0x800EE7F8
    // 0x80800774: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800774: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x80800778: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8080077C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800780: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800784: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x80800788: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080078C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800790: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80800794: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800798: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8080079C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x808007A0: jal         0x80086590
    // 0x808007A4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    _chlifeforcespell_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808007A4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_5:
    // 0x808007A8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x808007AC: b           L_80800D44
    // 0x808007B0: sw          $v0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r2;
        goto L_80800D44;
    // 0x808007B0: sw          $v0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r2;
L_808007B4:
    // 0x808007B4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x808007B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007BC: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // 0x808007C0: jal         0x80108528
    // 0x808007C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_6;
    // 0x808007C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_6:
    // 0x808007C8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808007CC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x808007D0: b           L_80800D44
    // 0x808007D4: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
        goto L_80800D44;
    // 0x808007D4: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
L_808007D8:
    // 0x808007D8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x808007DC: addiu       $at, $zero, 0x456
    ctx->r1 = ADD32(0, 0X456);
    // 0x808007E0: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1324, 0X220C) << 16);
    // 0x808007E4: lw          $v0, 0x6C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X6C);
    // 0x808007E8: addiu       $t3, $t3, 0x220C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1324, 0X220C));
    // 0x808007EC: sll         $t0, $v0, 11
    ctx->r8 = S32(ctx->r2 << 11);
    // 0x808007F0: srl         $v0, $t0, 20
    ctx->r2 = S32(U32(ctx->r8) >> 20);
    // 0x808007F4: bnel        $v0, $at, L_80800868
    if (ctx->r2 != ctx->r1) {
        // 0x808007F8: addiu       $at, $zero, 0x457
        ctx->r1 = ADD32(0, 0X457);
            goto L_80800868;
    }
    goto skip_1;
    // 0x808007F8: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
    skip_1:
    // 0x808007FC: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80800800: addiu       $t2, $sp, 0x4C
    ctx->r10 = ADD32(ctx->r29, 0X4C);
    // 0x80800804: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80800808: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8080080C: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80800810: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80800814: jal         0x800F54E4
    // 0x80800818: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800818: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    after_7:
    // 0x8080081C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800820: jal         0x800F77E8
    // 0x80800824: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F77E8(rdram, ctx);
        goto after_8;
    // 0x80800824: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x80800828: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8080082C: jal         0x80102424
    // 0x80800830: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800830: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80800834: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080083C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80800840: lbu         $t7, 0x77($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X77);
    // 0x80800844: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80800848: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x8080084C: sb          $t8, 0x77($t6)
    MEM_B(0X77, ctx->r14) = ctx->r24;
    // 0x80800850: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80800854: jal         0x80085708
    // 0x80800858: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80800858: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_10:
    // 0x8080085C: b           L_808008DC
    // 0x80800860: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_808008DC;
    // 0x80800860: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80800864: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
L_80800868:
    // 0x80800868: bne         $v0, $at, L_808008D8
    if (ctx->r2 != ctx->r1) {
        // 0x8080086C: lui         $t1, 0x8080
        ctx->r9 = S32(RELOC_HI16(1324, 0X2218) << 16);
            goto L_808008D8;
    }
    // 0x8080086C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1324, 0X2218) << 16);
    // 0x80800870: addiu       $t1, $t1, 0x2218
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1324, 0X2218));
    // 0x80800874: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800878: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x8080087C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80800880: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80800884: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80800888: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8080088C: jal         0x800F54E4
    // 0x80800890: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800890: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_11:
    // 0x80800894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800898: jal         0x800F77E8
    // 0x8080089C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F77E8(rdram, ctx);
        goto after_12;
    // 0x8080089C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x808008A0: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x808008A4: addiu       $t5, $zero, 0xB7
    ctx->r13 = ADD32(0, 0XB7);
    // 0x808008A8: addiu       $a1, $zero, 0x12CE
    ctx->r5 = ADD32(0, 0X12CE);
    // 0x808008AC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808008B0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808008B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808008B8: jal         0x8008A208
    // 0x808008BC: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x808008BC: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    after_13:
    // 0x808008C0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x808008C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008C8: addiu       $a2, $zero, 0x5D
    ctx->r6 = ADD32(0, 0X5D);
    // 0x808008CC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x808008D0: jal         0x80085708
    // 0x808008D4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x808008D4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_14:
L_808008D8:
    // 0x808008D8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_808008DC:
    // 0x808008DC: b           L_80800D44
    // 0x808008E0: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
        goto L_80800D44;
    // 0x808008E0: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
L_808008E4:
    // 0x808008E4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x808008E8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008EC: jal         0x800EE7F8
    // 0x808008F0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x808008F0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_15:
    // 0x808008F4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x808008F8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808008FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800900: lwc1        $f16, 0x48($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80800904: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800908: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x8080090C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800910: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800914: jal         0x800EF1B8
    // 0x80800918: nop

    func_800EF1B8(rdram, ctx);
        goto after_16;
    // 0x80800918: nop

    after_16:
    // 0x8080091C: jal         0x800F54E4
    // 0x80800920: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80800920: nop

    after_17:
    // 0x80800924: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800928: jal         0x800F77E8
    // 0x8080092C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F77E8(rdram, ctx);
        goto after_18;
    // 0x8080092C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_18:
    // 0x80800930: jal         0x800F54E4
    // 0x80800934: nop

    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800934: nop

    after_19:
    // 0x80800938: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800940: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800944: jal         0x800F8300
    // 0x80800948: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800F8300(rdram, ctx);
        goto after_20;
    // 0x80800948: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_20:
    // 0x8080094C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80800950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800954: addiu       $a2, $zero, 0x65
    ctx->r6 = ADD32(0, 0X65);
    // 0x80800958: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8080095C: jal         0x80085708
    // 0x80800960: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_21;
    // 0x80800960: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_21:
    // 0x80800964: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800968: jal         0x80102424
    // 0x8080096C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x8080096C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_22:
    // 0x80800970: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800974: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800978: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8080097C: b           L_80800D44
    // 0x80800980: swc1        $f6, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f6.u32l;
        goto L_80800D44;
    // 0x80800980: swc1        $f6, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f6.u32l;
L_80800984:
    // 0x80800984: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x80800988: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080098C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800990: jal         0x80800DB8
    // 0x80800994: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_80800DB8_chalienkids(rdram, ctx);
        goto after_23;
    // 0x80800994: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_23:
    // 0x80800998: b           L_80800D48
    // 0x8080099C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x8080099C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009A0:
    // 0x808009A0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x808009A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808009A8: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    // 0x808009AC: beq         $v0, $at, L_808009E0
    if (ctx->r2 == ctx->r1) {
        // 0x808009B0: addiu       $a1, $zero, 0x4A
        ctx->r5 = ADD32(0, 0X4A);
            goto L_808009E0;
    }
    // 0x808009B0: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x808009B4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808009B8: beq         $v0, $at, L_808009F0
    if (ctx->r2 == ctx->r1) {
        // 0x808009BC: addiu       $a0, $zero, 0x458
        ctx->r4 = ADD32(0, 0X458);
            goto L_808009F0;
    }
    // 0x808009BC: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    // 0x808009C0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808009C4: beq         $v0, $at, L_80800A04
    if (ctx->r2 == ctx->r1) {
        // 0x808009C8: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80800A04;
    }
    // 0x808009C8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808009CC: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x808009D0: beq         $v0, $at, L_80800A50
    if (ctx->r2 == ctx->r1) {
        // 0x808009D4: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80800A50;
    }
    // 0x808009D4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808009D8: b           L_80800D48
    // 0x808009DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800D48;
    // 0x808009DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808009E0:
    // 0x808009E0: jal         0x80101180
    // 0x808009E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_24;
    // 0x808009E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x808009E8: b           L_80800D48
    // 0x808009EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800D48;
    // 0x808009EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808009F0:
    // 0x808009F0: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x808009F4: jal         0x80101180
    // 0x808009F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_25;
    // 0x808009F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x808009FC: b           L_80800D48
    // 0x80800A00: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800D48;
    // 0x80800A00: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A04:
    // 0x80800A04: jal         0x808014B0
    // 0x80800A08: addiu       $a1, $zero, 0x372
    ctx->r5 = ADD32(0, 0X372);
    func_808014B0_chalienkids(rdram, ctx);
        goto after_26;
    // 0x80800A08: addiu       $a1, $zero, 0x372
    ctx->r5 = ADD32(0, 0X372);
    after_26:
    // 0x80800A0C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800A10: jal         0x8008A4B0
    // 0x80800A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80800A18: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800A1C: jal         0x80102424
    // 0x80800A20: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x80800A20: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_28:
    // 0x80800A24: jal         0x80085710
    // 0x80800A28: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_29;
    // 0x80800A28: nop

    after_29:
    // 0x80800A2C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80800A30: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x80800A34: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800A38: lw          $a2, 0x6C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X6C);
    // 0x80800A3C: sll         $t1, $a2, 11
    ctx->r9 = S32(ctx->r6 << 11);
    // 0x80800A40: jal         0x80101180
    // 0x80800A44: srl         $a2, $t1, 20
    ctx->r6 = S32(U32(ctx->r9) >> 20);
    func_80101180(rdram, ctx);
        goto after_30;
    // 0x80800A44: srl         $a2, $t1, 20
    ctx->r6 = S32(U32(ctx->r9) >> 20);
    after_30:
    // 0x80800A48: b           L_80800D48
    // 0x80800A4C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800D48;
    // 0x80800A4C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A50:
    // 0x80800A50: jal         0x808014B0
    // 0x80800A54: addiu       $a1, $zero, 0x373
    ctx->r5 = ADD32(0, 0X373);
    func_808014B0_chalienkids(rdram, ctx);
        goto after_31;
    // 0x80800A54: addiu       $a1, $zero, 0x373
    ctx->r5 = ADD32(0, 0X373);
    after_31:
    // 0x80800A58: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800A5C: jal         0x8008A4B0
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80800A64: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800A68: jal         0x80102424
    // 0x80800A6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_33;
    // 0x80800A6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_33:
    // 0x80800A70: jal         0x80085710
    // 0x80800A74: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_34;
    // 0x80800A74: nop

    after_34:
    // 0x80800A78: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80800A7C: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x80800A80: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800A84: lw          $a2, 0x6C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X6C);
    // 0x80800A88: sll         $t5, $a2, 11
    ctx->r13 = S32(ctx->r6 << 11);
    // 0x80800A8C: jal         0x80101180
    // 0x80800A90: srl         $a2, $t5, 20
    ctx->r6 = S32(U32(ctx->r13) >> 20);
    func_80101180(rdram, ctx);
        goto after_35;
    // 0x80800A90: srl         $a2, $t5, 20
    ctx->r6 = S32(U32(ctx->r13) >> 20);
    after_35:
    // 0x80800A94: b           L_80800D48
    // 0x80800A98: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800D48;
    // 0x80800A98: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800A9C: b           L_80800D48
    // 0x80800AA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800D48;
    // 0x80800AA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800AA4:
    // 0x80800AA4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800AA8: jal         0x80102424
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_36;
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_36:
    // 0x80800AB0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800AB4: jal         0x80103110
    // 0x80800AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_37;
    // 0x80800AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x80800ABC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800AC0: jal         0x8008A4B0
    // 0x80800AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_38;
    // 0x80800AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x80800AC8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80800ACC: addiu       $at, $zero, 0x456
    ctx->r1 = ADD32(0, 0X456);
    // 0x80800AD0: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80800AD4: lw          $v1, 0x6C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X6C);
    // 0x80800AD8: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x80800ADC: srl         $t9, $t6, 20
    ctx->r25 = S32(U32(ctx->r14) >> 20);
    // 0x80800AE0: beq         $t9, $at, L_80800B04
    if (ctx->r25 == ctx->r1) {
        // 0x80800AE4: addiu       $at, $zero, 0x457
        ctx->r1 = ADD32(0, 0X457);
            goto L_80800B04;
    }
    // 0x80800AE4: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
    // 0x80800AE8: beq         $t9, $at, L_80800B30
    if (ctx->r25 == ctx->r1) {
        // 0x80800AEC: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_80800B30;
    }
    // 0x80800AEC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80800AF0: addiu       $at, $zero, 0x458
    ctx->r1 = ADD32(0, 0X458);
    // 0x80800AF4: beq         $t9, $at, L_80800B60
    if (ctx->r25 == ctx->r1) {
        // 0x80800AF8: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_80800B60;
    }
    // 0x80800AF8: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80800AFC: b           L_80800D48
    // 0x80800B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B04:
    // 0x80800B04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800B08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B10: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800B14: swc1        $f8, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f8.u32l;
    // 0x80800B18: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80800B1C: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x80800B20: jal         0x80085708
    // 0x80800B24: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_39;
    // 0x80800B24: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_39:
    // 0x80800B28: b           L_80800D48
    // 0x80800B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B30:
    // 0x80800B30: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800B34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B38: jal         0x80085710
    // 0x80800B3C: swc1        $f10, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f10.u32l;
    _capod_entrypoint_14(rdram, ctx);
        goto after_40;
    // 0x80800B3C: swc1        $f10, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f10.u32l;
    after_40:
    // 0x80800B40: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80800B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B48: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800B4C: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x80800B50: jal         0x80085708
    // 0x80800B54: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_41;
    // 0x80800B54: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_41:
    // 0x80800B58: b           L_80800D48
    // 0x80800B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B60:
    // 0x80800B60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800B64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B68: nop

    // 0x80800B6C: swc1        $f16, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f16.u32l;
    // 0x80800B70: jal         0x8010A63C
    // 0x80800B74: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_8010A63C(rdram, ctx);
        goto after_42;
    // 0x80800B74: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_42:
    // 0x80800B78: jal         0x80085710
    // 0x80800B7C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_43;
    // 0x80800B7C: nop

    after_43:
    // 0x80800B80: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80800B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B88: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80800B8C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x80800B90: jal         0x80085708
    // 0x80800B94: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_44;
    // 0x80800B94: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_44:
    // 0x80800B98: b           L_80800D48
    // 0x80800B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BA0:
    // 0x80800BA0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800BA4: jal         0x80108B04
    // 0x80800BA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_45;
    // 0x80800BA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_45:
    // 0x80800BAC: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80800BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BB4: addiu       $a2, $zero, 0x31
    ctx->r6 = ADD32(0, 0X31);
    // 0x80800BB8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80800BBC: jal         0x80085708
    // 0x80800BC0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_46;
    // 0x80800BC0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_46:
    // 0x80800BC4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800BC8: jal         0x8008A4B0
    // 0x80800BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_47;
    // 0x80800BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_47:
    // 0x80800BD0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800BD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BD8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80800BDC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800BE0: swc1        $f18, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f18.u32l;
    // 0x80800BE4: jal         0x80102424
    // 0x80800BE8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_80102424(rdram, ctx);
        goto after_48;
    // 0x80800BE8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_48:
    // 0x80800BEC: b           L_80800D48
    // 0x80800BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BF4:
    // 0x80800BF4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800BF8: jal         0x80100094
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_49;
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_49:
    // 0x80800C00: b           L_80800D44
    // 0x80800C04: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
        goto L_80800D44;
    // 0x80800C04: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
L_80800C08:
    // 0x80800C08: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80800C0C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800C10: lhu         $t9, 0x72($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X72);
    // 0x80800C14: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800C18: srl         $t4, $t9, 10
    ctx->r12 = S32(U32(ctx->r25) >> 10);
    // 0x80800C1C: bnel        $t4, $at, L_80800D48
    if (ctx->r12 != ctx->r1) {
        // 0x80800C20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D48;
    }
    goto skip_2;
    // 0x80800C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80800C24: jal         0x8008A4B0
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_50;
    // 0x80800C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
    // 0x80800C2C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800C30: jal         0x80102424
    // 0x80800C34: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80102424(rdram, ctx);
        goto after_51;
    // 0x80800C34: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_51:
    // 0x80800C38: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800C3C: jal         0x80108B04
    // 0x80800C40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80108B04(rdram, ctx);
        goto after_52;
    // 0x80800C40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_52:
    // 0x80800C44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1E28) << 16);
    // 0x80800C48: lwc1        $f4, 0x1E28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1E28));
    // 0x80800C4C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80800C50: b           L_80800D44
    // 0x80800C54: swc1        $f4, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f4.u32l;
        goto L_80800D44;
    // 0x80800C54: swc1        $f4, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f4.u32l;
L_80800C58:
    // 0x80800C58: jal         0x8080193C
    // 0x80800C5C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_8080193C_chalienkids(rdram, ctx);
        goto after_53;
    // 0x80800C5C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_53:
    // 0x80800C60: b           L_80800D48
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C68:
    // 0x80800C68: jal         0x80801994
    // 0x80800C6C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    func_80801994_chalienkids(rdram, ctx);
        goto after_54;
    // 0x80800C6C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_54:
    // 0x80800C70: b           L_80800D48
    // 0x80800C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C78:
    // 0x80800C78: jal         0x80100094
    // 0x80800C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_55;
    // 0x80800C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_55:
    // 0x80800C80: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80800C84: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80800C88: addiu       $at, $zero, 0x456
    ctx->r1 = ADD32(0, 0X456);
    // 0x80800C8C: lw          $v1, 0x6C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X6C);
    // 0x80800C90: sll         $t2, $v1, 11
    ctx->r10 = S32(ctx->r3 << 11);
    // 0x80800C94: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x80800C98: beq         $t3, $at, L_80800CB0
    if (ctx->r11 == ctx->r1) {
        // 0x80800C9C: addiu       $at, $zero, 0x457
        ctx->r1 = ADD32(0, 0X457);
            goto L_80800CB0;
    }
    // 0x80800C9C: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
    // 0x80800CA0: beq         $t3, $at, L_80800CE0
    if (ctx->r11 == ctx->r1) {
        // 0x80800CA4: nop
    
            goto L_80800CE0;
    }
    // 0x80800CA4: nop

    // 0x80800CA8: b           L_80800D48
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB0:
    // 0x80800CB0: jal         0x800DA298
    // 0x80800CB4: addiu       $a0, $zero, 0x372
    ctx->r4 = ADD32(0, 0X372);
    func_800DA298(rdram, ctx);
        goto after_56;
    // 0x80800CB4: addiu       $a0, $zero, 0x372
    ctx->r4 = ADD32(0, 0X372);
    after_56:
    // 0x80800CB8: bnel        $v0, $zero, L_80800D48
    if (ctx->r2 != 0) {
        // 0x80800CBC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D48;
    }
    goto skip_3;
    // 0x80800CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800CC0: jal         0x80088848
    // 0x80800CC4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_57;
    // 0x80800CC4: nop

    after_57:
    // 0x80800CC8: bne         $v0, $zero, L_80800D44
    if (ctx->r2 != 0) {
        // 0x80800CCC: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80800D44;
    }
    // 0x80800CCC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800CD0: jal         0x80108B04
    // 0x80800CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_58;
    // 0x80800CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_58:
    // 0x80800CD8: b           L_80800D48
    // 0x80800CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CE0:
    // 0x80800CE0: jal         0x800DA298
    // 0x80800CE4: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    func_800DA298(rdram, ctx);
        goto after_59;
    // 0x80800CE4: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    after_59:
    // 0x80800CE8: bnel        $v0, $zero, L_80800D48
    if (ctx->r2 != 0) {
        // 0x80800CEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D48;
    }
    goto skip_4;
    // 0x80800CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x80800CF0: jal         0x800DA298
    // 0x80800CF4: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    func_800DA298(rdram, ctx);
        goto after_60;
    // 0x80800CF4: addiu       $a0, $zero, 0x6B4
    ctx->r4 = ADD32(0, 0X6B4);
    after_60:
    // 0x80800CF8: bnel        $v0, $zero, L_80800D48
    if (ctx->r2 != 0) {
        // 0x80800CFC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D48;
    }
    goto skip_5;
    // 0x80800CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x80800D00: jal         0x80088848
    // 0x80800D04: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_61;
    // 0x80800D04: nop

    after_61:
    // 0x80800D08: bne         $v0, $zero, L_80800D44
    if (ctx->r2 != 0) {
        // 0x80800D0C: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80800D44;
    }
    // 0x80800D0C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800D10: jal         0x80108B04
    // 0x80800D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_62;
    // 0x80800D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x80800D18: b           L_80800D48
    // 0x80800D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D20:
    // 0x80800D20: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80800D24: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1324, 0X2224) << 16);
    // 0x80800D28: addiu       $a0, $a0, 0x2224
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1324, 0X2224));
    // 0x80800D2C: jal         0x80088090
    // 0x80800D30: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_63;
    // 0x80800D30: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    after_63:
    // 0x80800D34: b           L_80800D48
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D48;
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D3C:
    // 0x80800D3C: b           L_80800D48
    // 0x80800D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D48;
    // 0x80800D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D44:
    // 0x80800D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D48:
    // 0x80800D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800D50: jr          $ra
    // 0x80800D54: nop

    return;
    // 0x80800D54: nop

;}
