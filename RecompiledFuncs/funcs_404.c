#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _idflame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E30: syscall     743
    recomp_syscall_handler(rdram, ctx, 0x80088E30);
    return;
    // 0x80088E34: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802020_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802020: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80802024: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80802028: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8080202C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80802030: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80802034: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80802038: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080203C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80802040: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80802044: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80802048: lhu         $s0, 0x15E($a0)
    ctx->r16 = MEM_HU(ctx->r4, 0X15E);
    // 0x8080204C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802050: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80802054: srl         $t6, $s0, 15
    ctx->r14 = S32(U32(ctx->r16) >> 15);
    // 0x80802058: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080205C: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80802060: lbu         $t8, 0x116($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X116);
    // 0x80802064: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80802068: lw          $t2, 0x104($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X104);
    // 0x8080206C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80802070: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80802074: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80802078: jal         0x808002E4
    // 0x8080207C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    func_808002E4_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x8080207C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    after_0:
    // 0x80802080: lhu         $s0, 0x15E($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X15E);
    // 0x80802084: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80802088: srl         $t4, $s0, 15
    ctx->r12 = S32(U32(ctx->r16) >> 15);
    // 0x8080208C: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x80802090: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80802094: lbu         $t6, 0x116($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X116);
    // 0x80802098: addu        $t0, $s2, $t8
    ctx->r8 = ADD32(ctx->r18, ctx->r24);
    // 0x8080209C: lw          $t1, 0x104($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X104);
    // 0x808020A0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808020A4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x808020A8: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x808020AC: jal         0x80088738
    // 0x808020B0: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808020B0: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_1:
    // 0x808020B4: sb          $zero, 0x64($sp)
    MEM_B(0X64, ctx->r29) = 0;
    // 0x808020B8: lw          $t2, 0x178($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X178);
    // 0x808020BC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808020C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808020C4: beql        $t2, $zero, L_808021AC
    if (ctx->r10 == 0) {
        // 0x808020C8: lw          $a0, 0x168($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X168);
            goto L_808021AC;
    }
    goto skip_0;
    // 0x808020C8: lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X168);
    skip_0:
    // 0x808020CC: blez        $s5, L_808021A8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x808020D0: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_808021A8;
    }
    // 0x808020D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808020D4: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x808020D8: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
L_808020DC:
    // 0x808020DC: lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X168);
    // 0x808020E0: bne         $a0, $zero, L_8080211C
    if (ctx->r4 != 0) {
        // 0x808020E4: nop
    
            goto L_8080211C;
    }
    // 0x808020E4: nop

    // 0x808020E8: lbu         $v0, 0x15E($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15E);
    // 0x808020EC: lw          $t9, 0x178($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X178);
    // 0x808020F0: lh          $a1, 0x162($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X162);
    // 0x808020F4: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x808020F8: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x808020FC: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80802100: andi        $t5, $v0, 0xFFFC
    ctx->r13 = ctx->r2 & 0XFFFC;
    // 0x80802104: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80802108: sb          $t6, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r14;
    // 0x8080210C: jalr        $t9
    // 0x80802110: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80802110: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    after_2:
    // 0x80802114: b           L_80802160
    // 0x80802118: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80802160;
    // 0x80802118: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8080211C:
    // 0x8080211C: jal         0x80800000
    // 0x80802120: lw          $a1, 0x16C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_3;
    // 0x80802120: lw          $a1, 0x16C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X16C);
    after_3:
    // 0x80802124: beql        $v0, $zero, L_80802164
    if (ctx->r2 == 0) {
        // 0x80802128: addu        $a0, $s7, $s1
        ctx->r4 = ADD32(ctx->r23, ctx->r17);
            goto L_80802164;
    }
    goto skip_1;
    // 0x80802128: addu        $a0, $s7, $s1
    ctx->r4 = ADD32(ctx->r23, ctx->r17);
    skip_1:
    // 0x8080212C: lbu         $v0, 0x15E($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15E);
    // 0x80802130: lw          $t9, 0x178($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X178);
    // 0x80802134: lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X168);
    // 0x80802138: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8080213C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80802140: andi        $t0, $t8, 0x3
    ctx->r8 = ctx->r24 & 0X3;
    // 0x80802144: andi        $t7, $v0, 0xFFFC
    ctx->r15 = ctx->r2 & 0XFFFC;
    // 0x80802148: or          $t1, $t0, $t7
    ctx->r9 = ctx->r8 | ctx->r15;
    // 0x8080214C: sb          $t1, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r9;
    // 0x80802150: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80802154: jalr        $t9
    // 0x80802158: lh          $a1, 0x162($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X162);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80802158: lh          $a1, 0x162($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X162);
    after_4:
    // 0x8080215C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80802160:
    // 0x80802160: addu        $a0, $s7, $s1
    ctx->r4 = ADD32(ctx->r23, ctx->r17);
L_80802164:
    // 0x80802164: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80802168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080216C: jal         0x800E6DD8
    // 0x80802170: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_800E6DD8(rdram, ctx);
        goto after_5;
    // 0x80802170: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x80802174: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x80802178: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8080217C: beql        $t2, $zero, L_8080219C
    if (ctx->r10 == 0) {
        // 0x80802180: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080219C;
    }
    goto skip_2;
    // 0x80802180: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80802184: lbu         $t3, 0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1);
L_80802188:
    // 0x80802188: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080218C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802190: bnel        $t3, $zero, L_80802188
    if (ctx->r11 != 0) {
        // 0x80802194: lbu         $t3, 0x1($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X1);
            goto L_80802188;
    }
    goto skip_3;
    // 0x80802194: lbu         $t3, 0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1);
    skip_3:
    // 0x80802198: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080219C:
    // 0x8080219C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808021A0: bne         $s4, $s5, L_808020DC
    if (ctx->r20 != ctx->r21) {
        // 0x808021A4: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_808020DC;
    }
    // 0x808021A4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_808021A8:
    // 0x808021A8: lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X168);
L_808021AC:
    // 0x808021AC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x808021B0: beql        $a0, $zero, L_80802268
    if (ctx->r4 == 0) {
        // 0x808021B4: lhu         $s0, 0x15E($s2)
        ctx->r16 = MEM_HU(ctx->r18, 0X15E);
            goto L_80802268;
    }
    goto skip_4;
    // 0x808021B4: lhu         $s0, 0x15E($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X15E);
    skip_4:
    // 0x808021B8: jal         0x80800000
    // 0x808021BC: lw          $a1, 0x16C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_6;
    // 0x808021BC: lw          $a1, 0x16C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X16C);
    after_6:
    // 0x808021C0: beql        $v0, $zero, L_80802268
    if (ctx->r2 == 0) {
        // 0x808021C4: lhu         $s0, 0x15E($s2)
        ctx->r16 = MEM_HU(ctx->r18, 0X15E);
            goto L_80802268;
    }
    goto skip_5;
    // 0x808021C4: lhu         $s0, 0x15E($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X15E);
    skip_5:
    // 0x808021C8: lw          $t4, 0x168($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X168);
    // 0x808021CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808021D0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808021D4: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x808021D8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x808021DC: beql        $t6, $zero, L_80802268
    if (ctx->r14 == 0) {
        // 0x808021E0: lhu         $s0, 0x15E($s2)
        ctx->r16 = MEM_HU(ctx->r18, 0X15E);
            goto L_80802268;
    }
    goto skip_6;
    // 0x808021E0: lhu         $s0, 0x15E($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X15E);
    skip_6:
    // 0x808021E4: blez        $s5, L_80802264
    if (SIGNED(ctx->r21) <= 0) {
        // 0x808021E8: sb          $zero, 0x64($sp)
        MEM_B(0X64, ctx->r29) = 0;
            goto L_80802264;
    }
    // 0x808021E8: sb          $zero, 0x64($sp)
    MEM_B(0X64, ctx->r29) = 0;
    // 0x808021EC: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
L_808021F0:
    // 0x808021F0: lbu         $v0, 0x15E($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15E);
    // 0x808021F4: lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X168);
    // 0x808021F8: lh          $a1, 0x162($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X162);
    // 0x808021FC: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x80802200: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80802204: andi        $t0, $t8, 0x3
    ctx->r8 = ctx->r24 & 0X3;
    // 0x80802208: andi        $t7, $v0, 0xFFFC
    ctx->r15 = ctx->r2 & 0XFFFC;
    // 0x8080220C: or          $t1, $t0, $t7
    ctx->r9 = ctx->r8 | ctx->r15;
    // 0x80802210: sb          $t1, 0x15E($s2)
    MEM_B(0X15E, ctx->r18) = ctx->r9;
    // 0x80802214: jal         0x8008A220
    // 0x80802218: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    _subaddiedialog_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x80802218: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    after_7:
    // 0x8080221C: addu        $a0, $s7, $s1
    ctx->r4 = ADD32(ctx->r23, ctx->r17);
    // 0x80802220: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802228: jal         0x800E6DD8
    // 0x8080222C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_800E6DD8(rdram, ctx);
        goto after_8;
    // 0x8080222C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_8:
    // 0x80802230: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80802234: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80802238: beql        $t9, $zero, L_80802258
    if (ctx->r25 == 0) {
        // 0x8080223C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80802258;
    }
    goto skip_7;
    // 0x8080223C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x80802240: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
L_80802244:
    // 0x80802244: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80802248: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080224C: bnel        $t2, $zero, L_80802244
    if (ctx->r10 != 0) {
        // 0x80802250: lbu         $t2, 0x1($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X1);
            goto L_80802244;
    }
    goto skip_8;
    // 0x80802250: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    skip_8:
    // 0x80802254: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80802258:
    // 0x80802258: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080225C: bne         $s3, $s5, L_808021F0
    if (ctx->r19 != ctx->r21) {
        // 0x80802260: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_808021F0;
    }
    // 0x80802260: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80802264:
    // 0x80802264: lhu         $s0, 0x15E($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X15E);
L_80802268:
    // 0x80802268: srl         $t3, $s0, 15
    ctx->r11 = S32(U32(ctx->r16) >> 15);
    // 0x8080226C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80802270: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80802274: lbu         $t5, 0x116($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X116);
    // 0x80802278: addu        $t0, $s2, $t8
    ctx->r8 = ADD32(ctx->r18, ctx->r24);
    // 0x8080227C: lw          $t7, 0x104($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X104);
    // 0x80802280: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80802284: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80802288: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x8080228C: jal         0x80088738
    // 0x80802290: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80802290: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_9:
    // 0x80802294: lhu         $s0, 0x15E($s2)
    ctx->r16 = MEM_HU(ctx->r18, 0X15E);
    // 0x80802298: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080229C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x808022A0: srl         $t9, $s0, 15
    ctx->r25 = S32(U32(ctx->r16) >> 15);
    // 0x808022A4: addu        $t2, $s2, $t9
    ctx->r10 = ADD32(ctx->r18, ctx->r25);
    // 0x808022A8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x808022AC: lbu         $t3, 0x116($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X116);
    // 0x808022B0: addu        $t8, $s2, $t5
    ctx->r24 = ADD32(ctx->r18, ctx->r13);
    // 0x808022B4: lw          $t0, 0x104($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X104);
    // 0x808022B8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x808022BC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x808022C0: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x808022C4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x808022C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808022CC: jal         0x80800350
    // 0x808022D0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80800350_gcdialogexec(rdram, ctx);
        goto after_10;
    // 0x808022D0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_10:
    // 0x808022D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808022D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808022DC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808022E0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808022E4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808022E8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808022EC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808022F0: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x808022F4: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x808022F8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x808022FC: jr          $ra
    // 0x80802300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80802300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800167F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800167F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800167F8: jr          $ra
    // 0x800167FC: lbu         $v0, -0x646D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X646D);
    return;
    // 0x800167FC: lbu         $v0, -0x646D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X646D);
;}
RECOMP_FUNC void gsmaker_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800658: jal         0x8080051C
    // 0x8080065C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x8080065C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800660: bne         $v0, $zero, L_80800670
    if (ctx->r2 != 0) {
        // 0x80800664: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800670;
    }
    // 0x80800664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800668: b           L_8080067C
    // 0x8080066C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080067C;
    // 0x8080066C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800670:
    // 0x80800670: jal         0x808002A4
    // 0x80800674: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    gsmaker_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800674: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080067C:
    // 0x8080067C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800684: jr          $ra
    // 0x80800688: nop

    return;
    // 0x80800688: nop

;}
RECOMP_FUNC void _bstimeout_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F38: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F38);
    return;
    // 0x80083F3C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800C2FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C2FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2FE8: jal         0x800C1414
    // 0x800C2FEC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C2FEC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_0:
    // 0x800C2FF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C2FF4: jal         0x800C3CE8
    // 0x800C2FF8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C3CE8(rdram, ctx);
        goto after_1;
    // 0x800C2FF8: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_1:
    // 0x800C2FFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3000: jal         0x800C1210
    // 0x800C3004: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C1210(rdram, ctx);
        goto after_2;
    // 0x800C3004: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800C3008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C300C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C3014: jr          $ra
    // 0x800C3018: nop

    return;
    // 0x800C3018: nop

;}
RECOMP_FUNC void _mlwave_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FD8: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FD8);
    return;
    // 0x80088FDC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _inantab_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F80: syscall     750
    recomp_syscall_handler(rdram, ctx, 0x80088F80);
    return;
    // 0x80088F84: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EEB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002EEB8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8002EEBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EEC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002EEC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002EEC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002EECC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8002EED0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8002EED4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8002EED8:
    // 0x8002EED8: bnel        $v0, $zero, L_8002EEEC
    if (ctx->r2 != 0) {
        // 0x8002EEDC: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_8002EEEC;
    }
    goto skip_0;
    // 0x8002EEDC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x8002EEE0: b           L_8002EEEC
    // 0x8002EEE4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8002EEEC;
    // 0x8002EEE4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8002EEE8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_8002EEEC:
    // 0x8002EEEC: bnel        $v0, $a0, L_8002EF00
    if (ctx->r2 != ctx->r4) {
        // 0x8002EEF0: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_8002EF00;
    }
    goto skip_1;
    // 0x8002EEF0: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x8002EEF4: b           L_8002EF00
    // 0x8002EEF8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_8002EF00;
    // 0x8002EEF8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8002EEFC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_8002EF00:
    // 0x8002EF00: bnel        $v0, $a1, L_8002EF14
    if (ctx->r2 != ctx->r5) {
        // 0x8002EF04: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_8002EF14;
    }
    goto skip_2;
    // 0x8002EF04: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x8002EF08: b           L_8002EF14
    // 0x8002EF0C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_8002EF14;
    // 0x8002EF0C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8002EF10: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_8002EF14:
    // 0x8002EF14: bnel        $v0, $a2, L_8002EF28
    if (ctx->r2 != ctx->r6) {
        // 0x8002EF18: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_8002EF28;
    }
    goto skip_3;
    // 0x8002EF18: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x8002EF1C: b           L_8002EF28
    // 0x8002EF20: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_8002EF28;
    // 0x8002EF20: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002EF24: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_8002EF28:
    // 0x8002EF28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002EF2C: bne         $v0, $a3, L_8002EED8
    if (ctx->r2 != ctx->r7) {
        // 0x8002EF30: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002EED8;
    }
    // 0x8002EF30: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002EF34: jr          $ra
    // 0x8002EF38: nop

    return;
    // 0x8002EF38: nop

;}
RECOMP_FUNC void func_80800000_bsbreegullbash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(112, 0X540) << 16);
    // 0x80800004: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800008: lwc1        $f4, 0x540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(112, 0X540));
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80800018: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080001C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800020: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800024: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800028: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080002C: jal         0x80084510
    // 0x80800030: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    _babackpack_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800030: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800034: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080003C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800040: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800044: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800048: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080004C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800050: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800054: jal         0x800EFCD8
    // 0x80800058: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_800EFCD8(rdram, ctx);
        goto after_1;
    // 0x80800058: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8080005C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(112, 0X544) << 16);
    // 0x80800060: lwc1        $f18, 0x544($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(112, 0X544));
    // 0x80800064: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(112, 0X548) << 16);
    // 0x80800068: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080006C: lwc1        $f4, 0x548($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(112, 0X548));
    // 0x80800070: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800074: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800078: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080007C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800080: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800084: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800088: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8080008C: jal         0x800849D8
    // 0x80800090: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    _badust_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800090: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void chswitch_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B5C: jal         0x800D8FF8
    // 0x80800B60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800B60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B64: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800B68: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B70: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800B74: beq         $t6, $at, L_80800BA0
    if (ctx->r14 == ctx->r1) {
        // 0x80800B78: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BA0;
    }
    // 0x80800B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B7C: beq         $t6, $at, L_80800C00
    if (ctx->r14 == ctx->r1) {
        // 0x80800B80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C00;
    }
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B88: beq         $t6, $at, L_80800C5C
    if (ctx->r14 == ctx->r1) {
        // 0x80800B8C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800C5C;
    }
    // 0x80800B8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800B90: beq         $t6, $at, L_80800CBC
    if (ctx->r14 == ctx->r1) {
        // 0x80800B94: nop
    
            goto L_80800CBC;
    }
    // 0x80800B94: nop

    // 0x80800B98: b           L_80800CF4
    // 0x80800B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CF4;
    // 0x80800B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BA0:
    // 0x80800BA0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800BA4: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800BA8: bgezl       $t9, L_80800BC8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800BAC: lwc1        $f0, 0x58($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80800BC8;
    }
    goto skip_0;
    // 0x80800BAC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x80800BB0: jal         0x800880D0
    // 0x80800BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BBC: jal         0x80102424
    // 0x80800BC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800BC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800BC4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
L_80800BC8:
    // 0x80800BC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800BD4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800BD8: nop

    // 0x80800BDC: bc1fl       L_80800BF8
    if (!c1cs) {
        // 0x80800BE0: sub.s       $f8, $f0, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
            goto L_80800BF8;
    }
    goto skip_1;
    // 0x80800BE0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    skip_1:
    // 0x80800BE4: jal         0x80103110
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800BEC: b           L_80800CF4
    // 0x80800BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CF4;
    // 0x80800BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BF4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
L_80800BF8:
    // 0x80800BF8: b           L_80800CF0
    // 0x80800BFC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800CF0;
    // 0x80800BFC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800C00:
    // 0x80800C00: jal         0x80101E14
    // 0x80800C04: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x80800C04: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x80800C08: beq         $v0, $zero, L_80800CF0
    if (ctx->r2 == 0) {
        // 0x80800C0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CF0;
    }
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C10: jal         0x80102424
    // 0x80800C14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800C14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C1C: jal         0x80101EE4
    // 0x80800C20: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101EE4(rdram, ctx);
        goto after_6;
    // 0x80800C20: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_6:
    // 0x80800C24: jal         0x800F54E4
    // 0x80800C28: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800C28: nop

    after_7:
    // 0x80800C2C: jal         0x800F6CC8
    // 0x80800C30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6CC8(rdram, ctx);
        goto after_8;
    // 0x80800C30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800C34: bnel        $v0, $zero, L_80800CF4
    if (ctx->r2 != 0) {
        // 0x80800C38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_2;
    // 0x80800C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800C3C: jal         0x800DA544
    // 0x80800C40: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800C40: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_9:
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C48: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800C4C: jal         0x8010108C
    // 0x80800C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_10;
    // 0x80800C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800C54: b           L_80800CF4
    // 0x80800C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CF4;
    // 0x80800C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C5C:
    // 0x80800C5C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80800C60: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80800C64: bltzl       $t2, L_80800C84
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800C68: lwc1        $f0, 0x58($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
            goto L_80800C84;
    }
    goto skip_3;
    // 0x80800C68: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    skip_3:
    // 0x80800C6C: jal         0x800880D0
    // 0x80800C70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800C70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: jal         0x80102424
    // 0x80800C7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800C7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80800C80: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
L_80800C84:
    // 0x80800C84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800C90: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80800C94: nop

    // 0x80800C98: bc1fl       L_80800CB4
    if (!c1cs) {
        // 0x80800C9C: sub.s       $f18, $f0, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_80800CB4;
    }
    goto skip_4;
    // 0x80800C9C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    skip_4:
    // 0x80800CA0: jal         0x80103110
    // 0x80800CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_13;
    // 0x80800CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800CA8: b           L_80800CF4
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CF4;
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
L_80800CB4:
    // 0x80800CB4: b           L_80800CF0
    // 0x80800CB8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80800CF0;
    // 0x80800CB8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800CBC:
    // 0x80800CBC: jal         0x80101DDC
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800CC4: beql        $v0, $zero, L_80800CF4
    if (ctx->r2 == 0) {
        // 0x80800CC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_5;
    // 0x80800CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800CCC: jal         0x800DA524
    // 0x80800CD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA524(rdram, ctx);
        goto after_15;
    // 0x80800CD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_15:
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: jal         0x80102424
    // 0x80800CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800CE8: jal         0x8010108C
    // 0x80800CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_17;
    // 0x80800CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
L_80800CF0:
    // 0x80800CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CF4:
    // 0x80800CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: nop

    return;
    // 0x80800D00: nop

;}
RECOMP_FUNC void func_800A9670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9670: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A9674: lbu         $t6, 0x76D4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X76D4);
    // 0x800A9678: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A967C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A9680: bne         $t6, $zero, L_800A9690
    if (ctx->r14 != 0) {
        // 0x800A9684: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A9690;
    }
    // 0x800A9684: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A9688: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800A968C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800A9690:
    // 0x800A9690: lbu         $t7, 0x76D5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X76D5);
    // 0x800A9694: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9698: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A969C: bne         $t7, $zero, L_800A96B0
    if (ctx->r15 != 0) {
        // 0x800A96A0: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800A96B0;
    }
    // 0x800A96A0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800A96A4: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800A96A8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800A96AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800A96B0:
    // 0x800A96B0: lbu         $t1, 0x76D6($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X76D6);
    // 0x800A96B4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800A96B8: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800A96BC: bne         $t1, $zero, L_800A96CC
    if (ctx->r9 != 0) {
        // 0x800A96C0: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800A96CC;
    }
    // 0x800A96C0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A96C4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A96C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800A96CC:
    // 0x800A96CC: lbu         $t5, 0x76D7($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X76D7);
    // 0x800A96D0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800A96D4: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x800A96D8: bne         $t5, $zero, L_800A96E8
    if (ctx->r13 != 0) {
        // 0x800A96DC: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800A96E8;
    }
    // 0x800A96DC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800A96E0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A96E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800A96E8:
    // 0x800A96E8: jr          $ra
    // 0x800A96EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800A96EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808003EC_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F4: jal         0x800A587C
    // 0x808003F8: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x808003F8: nop

    after_0:
    // 0x808003FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800400: beq         $v0, $at, L_80800418
    if (ctx->r2 == ctx->r1) {
        // 0x80800404: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800418;
    }
    // 0x80800404: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800408: beq         $v0, $at, L_80800428
    if (ctx->r2 == ctx->r1) {
        // 0x8080040C: nop
    
            goto L_80800428;
    }
    // 0x8080040C: nop

    // 0x80800410: b           L_80800438
    // 0x80800414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800438;
    // 0x80800414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800418:
    // 0x80800418: jal         0x800A586C
    // 0x8080041C: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x8080041C: nop

    after_1:
    // 0x80800420: b           L_80800438
    // 0x80800424: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_80800438;
    // 0x80800424: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_80800428:
    // 0x80800428: jal         0x800A586C
    // 0x8080042C: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x8080042C: nop

    after_2:
    // 0x80800430: b           L_80800438
    // 0x80800434: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
        goto L_80800438;
    // 0x80800434: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_80800438:
    // 0x80800438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080043C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800440: jr          $ra
    // 0x80800444: nop

    return;
    // 0x80800444: nop

;}
RECOMP_FUNC void func_8080193C_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080193C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080194C: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80801950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801954: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80801958: bgez        $t9, L_80801968
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080195C: nop
    
            goto L_80801968;
    }
    // 0x8080195C: nop

    // 0x80801960: b           L_80801968
    // 0x80801964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80801968;
    // 0x80801964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80801968:
    // 0x80801968: jal         0x800DF744
    // 0x8080196C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x8080196C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80801970: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801974: jal         0x800DF744
    // 0x80801978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80801978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080197C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801980: jal         0x800DF744
    // 0x80801984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80801984: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080198C: jal         0x80101870
    // 0x80801990: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_3;
    // 0x80801990: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080199C: jr          $ra
    // 0x808019A0: nop

    return;
    // 0x808019A0: nop

;}
RECOMP_FUNC void func_80800180_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080018C: jal         0x8009E6EC
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800194: slti        $at, $v0, 0x2F
    ctx->r1 = SIGNED(ctx->r2) < 0X2F ? 1 : 0;
    // 0x80800198: bne         $at, $zero, L_808001FC
    if (ctx->r1 != 0) {
        // 0x8080019C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001FC;
    }
    // 0x8080019C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x808001A4: bne         $at, $zero, L_808001BC
    if (ctx->r1 != 0) {
        // 0x808001A8: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_808001BC;
    }
    // 0x808001A8: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x808001AC: beq         $v0, $at, L_80800218
    if (ctx->r2 == ctx->r1) {
        // 0x808001B0: nop
    
            goto L_80800218;
    }
    // 0x808001B0: nop

    // 0x808001B4: b           L_80800234
    // 0x808001B8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
        goto L_80800234;
    // 0x808001B8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_808001BC:
    // 0x808001BC: slti        $at, $v0, 0x5D
    ctx->r1 = SIGNED(ctx->r2) < 0X5D ? 1 : 0;
    // 0x808001C0: bne         $at, $zero, L_808001DC
    if (ctx->r1 != 0) {
        // 0x808001C4: addiu       $t6, $v0, -0x4E
        ctx->r14 = ADD32(ctx->r2, -0X4E);
            goto L_808001DC;
    }
    // 0x808001C4: addiu       $t6, $v0, -0x4E
    ctx->r14 = ADD32(ctx->r2, -0X4E);
    // 0x808001C8: addiu       $at, $zero, 0x7E
    ctx->r1 = ADD32(0, 0X7E);
    // 0x808001CC: beq         $v0, $at, L_80800228
    if (ctx->r2 == ctx->r1) {
        // 0x808001D0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80800228;
    }
    // 0x808001D0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808001D4: b           L_80800234
    // 0x808001D8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
        goto L_80800234;
    // 0x808001D8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_808001DC:
    // 0x808001DC: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x808001E0: beq         $at, $zero, L_80800230
    if (ctx->r1 == 0) {
        // 0x808001E4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800230;
    }
    // 0x808001E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808001E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(412, 0X1940) << 16);
    // 0x808001EC: addu        $at, $at, $t6
    gpr jr_addend_808001F4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001F0: lw          $t6, 0x1940($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(412, 0X1940));
    // 0x808001F4: jr          $t6
    // 0x808001F8: nop

    switch (jr_addend_808001F4 >> 2) {
        case 0: goto L_80800218; break;
        case 1: goto L_80800230; break;
        case 2: goto L_80800230; break;
        case 3: goto L_80800218; break;
        case 4: goto L_80800218; break;
        case 5: goto L_80800230; break;
        case 6: goto L_80800230; break;
        case 7: goto L_80800230; break;
        case 8: goto L_80800230; break;
        case 9: goto L_80800230; break;
        case 10: goto L_80800230; break;
        case 11: goto L_80800218; break;
        case 12: goto L_80800218; break;
        case 13: goto L_80800218; break;
        case 14: goto L_80800218; break;
        default: switch_error(__func__, 0x808001F4, 0x80801940);
    }
    // 0x808001F8: nop

L_808001FC:
    // 0x808001FC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800200: beq         $v0, $at, L_80800218
    if (ctx->r2 == ctx->r1) {
        // 0x80800204: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_80800218;
    }
    // 0x80800204: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80800208: beq         $v0, $at, L_80800218
    if (ctx->r2 == ctx->r1) {
        // 0x8080020C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80800218;
    }
    // 0x8080020C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800210: bnel        $v0, $at, L_80800234
    if (ctx->r2 != ctx->r1) {
        // 0x80800214: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800234;
    }
    goto skip_0;
    // 0x80800214: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80800218:
    // 0x80800218: jal         0x8009E830
    // 0x8080021C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x8080021C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800220: b           L_80800240
    // 0x80800224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800240;
    // 0x80800224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800228:
    // 0x80800228: b           L_8080023C
    // 0x8080022C: sb          $t7, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = ctx->r15;
        goto L_8080023C;
    // 0x8080022C: sb          $t7, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = ctx->r15;
L_80800230:
    // 0x80800230: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80800234:
    // 0x80800234: jalr        $t9
    // 0x80800238: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800238: nop

    after_2:
L_8080023C:
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800240:
    // 0x80800240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_800A3360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3360: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3364: jr          $ra
    // 0x800A3368: lbu         $v0, 0x55($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X55);
    return;
    // 0x800A3368: lbu         $v0, 0x55($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X55);
;}
RECOMP_FUNC void gcdialogexec_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D1C: jal         0x80800D30
    // 0x80801D20: nop

    func_80800D30_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80801D20: nop

    after_0:
    // 0x80801D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D2C: jr          $ra
    // 0x80801D30: nop

    return;
    // 0x80801D30: nop

;}
RECOMP_FUNC void func_808059CC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808059CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808059D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808059D4: jal         0x80100094
    // 0x808059D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808059D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808059DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808059E0: jal         0x80089D48
    // 0x808059E4: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808059E4: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    after_1:
    // 0x808059E8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808059EC: sb          $v0, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r2;
    // 0x808059F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808059F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808059F8: jr          $ra
    // 0x808059FC: nop

    return;
    // 0x808059FC: nop

;}
RECOMP_FUNC void func_80801198_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801198: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080119C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808011A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808011AC: jal         0x8008CB10
    // 0x808011B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808011B0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x808011B4: beq         $v0, $zero, L_808011C4
    if (ctx->r2 == 0) {
        // 0x808011B8: nop
    
            goto L_808011C4;
    }
    // 0x808011B8: nop

    // 0x808011BC: jal         0x800951B4
    // 0x808011C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x808011C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808011C4:
    // 0x808011C4: jal         0x800845C8
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808011CC: beq         $v0, $zero, L_808011DC
    if (ctx->r2 == 0) {
        // 0x808011D0: nop
    
            goto L_808011DC;
    }
    // 0x808011D0: nop

    // 0x808011D4: jal         0x80800000
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsvan(rdram, ctx);
        goto after_3;
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_808011DC:
    // 0x808011DC: jal         0x80084600
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808011E4: beq         $v0, $zero, L_808011F4
    if (ctx->r2 == 0) {
        // 0x808011E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011F4;
    }
    // 0x808011E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011EC: addiu       $t6, $zero, 0x11A
    ctx->r14 = ADD32(0, 0X11A);
    // 0x808011F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808011F4:
    // 0x808011F4: jal         0x8009E5C8
    // 0x808011F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x808011F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808011FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801208: jr          $ra
    // 0x8080120C: nop

    return;
    // 0x8080120C: nop

;}
RECOMP_FUNC void func_808037C8_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808037C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808037CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808037D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808037D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808037D8: jal         0x80100094
    // 0x808037DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808037DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808037E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CC0) << 16);
    // 0x808037E4: lwc1        $f12, 0x4CC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CC0));
    // 0x808037E8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808037EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808037F0: jal         0x800DC178
    // 0x808037F4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808037F4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808037F8: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x808037FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803800: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80803804: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1752, 0X4FA0) << 16);
    // 0x80803808: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080380C: lui         $at, 0xC434
    ctx->r1 = S32(0XC434 << 16);
    // 0x80803810: addiu       $t6, $t6, 0x4FA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1752, 0X4FA0));
    // 0x80803814: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80803818: nop

    // 0x8080381C: bc1tl       L_80803868
    if (c1cs) {
        // 0x80803820: lw          $at, 0x0($t6)
        ctx->r1 = MEM_W(ctx->r14, 0X0);
            goto L_80803868;
    }
    goto skip_0;
    // 0x80803820: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80803824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803828: nop

    // 0x8080382C: mul.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80803830: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80803834: nop

    // 0x80803838: bc1tl       L_80803868
    if (c1cs) {
        // 0x8080383C: lw          $at, 0x0($t6)
        ctx->r1 = MEM_W(ctx->r14, 0X0);
            goto L_80803868;
    }
    goto skip_1;
    // 0x8080383C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    skip_1:
    // 0x80803840: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80803844: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80803848: nop

    // 0x8080384C: bc1tl       L_80803868
    if (c1cs) {
        // 0x80803850: lw          $at, 0x0($t6)
        ctx->r1 = MEM_W(ctx->r14, 0X0);
            goto L_80803868;
    }
    goto skip_2;
    // 0x80803850: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    skip_2:
    // 0x80803854: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80803858: nop

    // 0x8080385C: bc1f        L_80803968
    if (!c1cs) {
        // 0x80803860: nop
    
            goto L_80803968;
    }
    // 0x80803860: nop

    // 0x80803864: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
L_80803868:
    // 0x80803868: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080386C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803870: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80803874: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80803878: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8080387C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80803880: jal         0x80102D78
    // 0x80803884: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_80102D78(rdram, ctx);
        goto after_2;
    // 0x80803884: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_2:
    // 0x80803888: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080388C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803890: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80803894: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803898: jal         0x800DC178
    // 0x8080389C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x8080389C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x808038A0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808038A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808038A8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808038AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808038B0: jal         0x800DC178
    // 0x808038B4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808038B4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x808038B8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808038BC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808038C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038C4: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x808038C8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808038CC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808038D0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808038D4: jal         0x8080372C
    // 0x808038D8: nop

    func_8080372C_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x808038D8: nop

    after_5:
    // 0x808038DC: jal         0x8080460C
    // 0x808038E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x808038E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808038E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808038E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808038EC: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808038F0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808038F4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808038F8: nop

    // 0x808038FC: bc1f        L_80803918
    if (!c1cs) {
        // 0x80803900: nop
    
            goto L_80803918;
    }
    // 0x80803900: nop

    // 0x80803904: jal         0x8080458C
    // 0x80803908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x80803908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080390C: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803910: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80803914: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80803918:
    // 0x80803918: jal         0x8080460C
    // 0x8080391C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_8;
    // 0x8080391C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80803920: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803924: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803928: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080392C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80803930: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80803934: nop

    // 0x80803938: bc1fl       L_80803958
    if (!c1cs) {
        // 0x8080393C: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80803958;
    }
    goto skip_3;
    // 0x8080393C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_3:
    // 0x80803940: jal         0x8080458C
    // 0x80803944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_9;
    // 0x80803944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80803948: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080394C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80803950: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80803954: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803958:
    // 0x80803958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080395C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80803960: b           L_808039A4
    // 0x80803964: swc1        $f10, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f10.u32l;
        goto L_808039A4;
    // 0x80803964: swc1        $f10, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f10.u32l;
L_80803968:
    // 0x80803968: jal         0x8080460C
    // 0x8080396C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_10;
    // 0x8080396C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80803970: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80803974: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803978: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080397C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80803980: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80803984: nop

    // 0x80803988: bc1fl       L_808039A8
    if (!c1cs) {
        // 0x8080398C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808039A8;
    }
    goto skip_4;
    // 0x8080398C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80803990: jal         0x8080458C
    // 0x80803994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_11;
    // 0x80803994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80803998: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080399C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808039A0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_808039A4:
    // 0x808039A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808039A8:
    // 0x808039A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808039AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808039B0: jr          $ra
    // 0x808039B4: nop

    return;
    // 0x808039B4: nop

;}
RECOMP_FUNC void func_80801C20_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C28: jal         0x80100094
    // 0x80801C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801C34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801C38: addiu       $a2, $zero, 0x1E0
    ctx->r6 = ADD32(0, 0X1E0);
    // 0x80801C3C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
L_80801C40:
    // 0x80801C40: lhu         $t6, 0x4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X4);
    // 0x80801C44: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x80801C48: beql        $a0, $t6, L_80801C5C
    if (ctx->r4 == ctx->r14) {
        // 0x80801C4C: lhu         $t7, 0x1C($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X1C);
            goto L_80801C5C;
    }
    goto skip_0;
    // 0x80801C4C: lhu         $t7, 0x1C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1C);
    skip_0:
    // 0x80801C50: b           L_80801CA0
    // 0x80801C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CA0;
    // 0x80801C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801C58: lhu         $t7, 0x1C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1C);
L_80801C5C:
    // 0x80801C5C: beql        $a0, $t7, L_80801C70
    if (ctx->r4 == ctx->r15) {
        // 0x80801C60: lhu         $t8, 0x34($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X34);
            goto L_80801C70;
    }
    goto skip_1;
    // 0x80801C60: lhu         $t8, 0x34($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X34);
    skip_1:
    // 0x80801C64: b           L_80801CA0
    // 0x80801C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CA0;
    // 0x80801C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801C6C: lhu         $t8, 0x34($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X34);
L_80801C70:
    // 0x80801C70: beql        $a0, $t8, L_80801C84
    if (ctx->r4 == ctx->r24) {
        // 0x80801C74: lhu         $t9, 0x4C($v1)
        ctx->r25 = MEM_HU(ctx->r3, 0X4C);
            goto L_80801C84;
    }
    goto skip_2;
    // 0x80801C74: lhu         $t9, 0x4C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4C);
    skip_2:
    // 0x80801C78: b           L_80801CA0
    // 0x80801C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CA0;
    // 0x80801C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801C80: lhu         $t9, 0x4C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4C);
L_80801C84:
    // 0x80801C84: beq         $a0, $t9, L_80801C94
    if (ctx->r4 == ctx->r25) {
        // 0x80801C88: nop
    
            goto L_80801C94;
    }
    // 0x80801C88: nop

    // 0x80801C8C: b           L_80801CA0
    // 0x80801C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CA0;
    // 0x80801C90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C94:
    // 0x80801C94: bne         $a1, $a2, L_80801C40
    if (ctx->r5 != ctx->r6) {
        // 0x80801C98: addiu       $v1, $v1, 0x60
        ctx->r3 = ADD32(ctx->r3, 0X60);
            goto L_80801C40;
    }
    // 0x80801C98: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x80801C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CA0:
    // 0x80801CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801CA8: jr          $ra
    // 0x80801CAC: nop

    return;
    // 0x80801CAC: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B20: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B20);
    return;
    // 0x80087B24: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800EDC_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800EE8: jal         0x80100094
    // 0x80800EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EF0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800EF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800EF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800EFC: lhu         $t6, 0x6E($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X6E);
    // 0x80800F00: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800F04: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800F08: ori         $t8, $t7, 0x5
    ctx->r24 = ctx->r15 | 0X5;
    // 0x80800F0C: sh          $t8, 0x6E($a2)
    MEM_H(0X6E, ctx->r6) = ctx->r24;
    // 0x80800F10: jal         0x8008A0A0
    // 0x80800F14: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    _subaddiemulti_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800F14: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    after_1:
    // 0x80800F18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F1C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80800F20: jal         0x80089980
    // 0x80800F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800F28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F2C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800F30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F34: jal         0x80089988
    // 0x80800F38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800F38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F44: jr          $ra
    // 0x80800F48: nop

    return;
    // 0x80800F48: nop

;}
RECOMP_FUNC void _chcrusher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AA0: syscall     413
    recomp_syscall_handler(rdram, ctx, 0x80086AA0);
    return;
    // 0x80086AA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DBE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBE28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBE2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBE30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DBE34: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800DBE38: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800DBE3C: jal         0x800DB9D0
    // 0x800DBE40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DB9D0(rdram, ctx);
        goto after_0;
    // 0x800DBE40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DBE44: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBE4C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800DBE50: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800DBE54: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
    // 0x800DBE58: jr          $ra
    // 0x800DBE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800DBE5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800200_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800204: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080020C: jal         0x80083F68
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x8009BCB4
    // 0x8080021C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x8080021C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800220: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x80800224: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x80800228: jal         0x8009BCC4
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x800961AC
    // 0x80800238: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x8009BC5C
    // 0x80800244: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_4;
    // 0x80800244: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x80800248: jal         0x800A046C
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_5;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800250: jal         0x800A3298
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3298(rdram, ctx);
        goto after_6;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800258: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80800264: jal         0x8008CB3C
    // 0x80800268: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_7;
    // 0x80800268: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_7:
    // 0x8080026C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800270: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800274: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80800278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080027C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800280: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800284: lui         $a3, 0xC396
    ctx->r7 = S32(0XC396 << 16);
    // 0x80800288: jal         0x800F10B4
    // 0x8080028C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x8080028C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800290: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800294: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800298: jal         0x8009BA58
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002A0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808002A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808002B4: jal         0x8009FFD8
    // 0x808002B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x808002B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x808002BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void _batimer_increment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852F8: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x800852F8);
    return;
    // 0x800852FC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808002DC_chgobiwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002EC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    // 0x808002F0: jal         0x800DA298
    // 0x808002F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808002F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808002F8: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x808002FC: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8080035C;
    }
    // 0x808002FC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800300: jal         0x800DB9B0
    // 0x80800304: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80800304: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800308: bne         $v0, $zero, L_80800384
    if (ctx->r2 != 0) {
        // 0x8080030C: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80800384;
    }
    // 0x8080030C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800310: jal         0x800F54E4
    // 0x80800314: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800314: nop

    after_2:
    // 0x80800318: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080031C: jal         0x800F82D4
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_3;
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800324: jal         0x800DA524
    // 0x80800328: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800328: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    after_4:
    // 0x8080032C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800330: addiu       $t6, $zero, 0x38
    ctx->r14 = ADD32(0, 0X38);
    // 0x80800334: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800338: addiu       $a1, $zero, 0x107B
    ctx->r5 = ADD32(0, 0X107B);
    // 0x8080033C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800340: jal         0x8008A208
    // 0x80800344: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800344: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x80101FDC
    // 0x80800350: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800350: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800354: b           L_80800384
    // 0x80800358: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800384;
    // 0x80800358: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080035C:
    // 0x8080035C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(844, 0X468) << 16);
    // 0x80800360: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(844, 0X3C0) << 16);
    // 0x80800364: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80800368: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080036C: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(844, 0X3C0));
    // 0x80800370: addiu       $a2, $a2, 0x468
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(844, 0X468));
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x8008A1F0
    // 0x8080037C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x8080037C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800380: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800384:
    // 0x80800384: beq         $v1, $zero, L_8080039C
    if (ctx->r3 == 0) {
        // 0x80800388: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080039C;
    }
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080038C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800390: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800394: jal         0x80085748
    // 0x80800398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_8;
    // 0x80800398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
L_8080039C:
    // 0x8080039C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void func_80800F28_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800F38: jal         0x800DA298
    // 0x80800F3C: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800F3C: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_0:
    // 0x80800F40: bne         $v0, $zero, L_80800F60
    if (ctx->r2 != 0) {
        // 0x80800F44: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F60;
    }
    // 0x80800F44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F48: jal         0x80800F70
    // 0x80800F4C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_1;
    // 0x80800F4C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x80800F50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F54: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80800F58: jal         0x8080248C
    // 0x80800F5C: addiu       $a2, $zero, 0x438
    ctx->r6 = ADD32(0, 0X438);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_2;
    // 0x80800F5C: addiu       $a2, $zero, 0x438
    ctx->r6 = ADD32(0, 0X438);
    after_2:
L_80800F60:
    // 0x80800F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F68: jr          $ra
    // 0x80800F6C: nop

    return;
    // 0x80800F6C: nop

;}
RECOMP_FUNC void func_8008D790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D790: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008D794: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008D798: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008D79C: jal         0x80084938
    // 0x8008D7A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _baduo_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8008D7A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8008D7A4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D7A8: beq         $t6, $zero, L_8008D83C
    if (ctx->r14 == 0) {
        // 0x8008D7AC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D83C;
    }
    // 0x8008D7AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D7B0: jal         0x8008E39C
    // 0x8008D7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_1;
    // 0x8008D7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008D7B8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008D7BC: beq         $t7, $zero, L_8008D83C
    if (ctx->r15 == 0) {
        // 0x8008D7C0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008D83C;
    }
    // 0x8008D7C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008D7C4: jal         0x8008E078
    // 0x8008D7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x8008D7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008D7CC: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D7D0: beq         $t8, $zero, L_8008D83C
    if (ctx->r24 == 0) {
        // 0x8008D7D4: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008D83C;
    }
    // 0x8008D7D4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008D7D8: jal         0x800C954C
    // 0x8008D7DC: nop

    func_800C954C(rdram, ctx);
        goto after_3;
    // 0x8008D7DC: nop

    after_3:
    // 0x8008D7E0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008D7E4: beq         $t9, $zero, L_8008D83C
    if (ctx->r25 == 0) {
        // 0x8008D7E8: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8008D83C;
    }
    // 0x8008D7E8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008D7EC: jal         0x800DB9B0
    // 0x8008D7F0: nop

    func_800DB9B0(rdram, ctx);
        goto after_4;
    // 0x8008D7F0: nop

    after_4:
    // 0x8008D7F4: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008D7F8: beq         $t0, $zero, L_8008D83C
    if (ctx->r8 == 0) {
        // 0x8008D7FC: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8008D83C;
    }
    // 0x8008D7FC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8008D800: jal         0x800F8004
    // 0x8008D804: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8004(rdram, ctx);
        goto after_5;
    // 0x8008D804: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_5:
    // 0x8008D808: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008D80C: beq         $t1, $zero, L_8008D83C
    if (ctx->r9 == 0) {
        // 0x8008D810: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8008D83C;
    }
    // 0x8008D810: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8008D814: jal         0x800F6D24
    // 0x8008D818: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F6D24(rdram, ctx);
        goto after_6;
    // 0x8008D818: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_6:
    // 0x8008D81C: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008D820: beq         $t2, $zero, L_8008D83C
    if (ctx->r10 == 0) {
        // 0x8008D824: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8008D83C;
    }
    // 0x8008D824: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8008D828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008D82C: jal         0x80095748
    // 0x8008D830: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    baflag_isFalse(rdram, ctx);
        goto after_7;
    // 0x8008D830: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_7:
    // 0x8008D834: sltu        $t3, $zero, $v0
    ctx->r11 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D838: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_8008D83C:
    // 0x8008D83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008D848: jr          $ra
    // 0x8008D84C: nop

    return;
    // 0x8008D84C: nop

;}
RECOMP_FUNC void bsdie_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080062C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800634: jal         0x80085230
    // 0x80800638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080063C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: jal         0x8009BF5C
    // 0x80800644: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800644: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080064C: jal         0x8009C4CC
    // 0x80800650: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800650: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800654: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800658: jal         0x800A0CF4
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800668: jr          $ra
    // 0x8080066C: nop

    return;
    // 0x8080066C: nop

;}
RECOMP_FUNC void bsjump_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(216, 0X1150) << 16);
    // 0x808010F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808010FC: jr          $ra
    // 0x80801100: lw          $v0, 0x1150($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1150));
    return;
    // 0x80801100: lw          $v0, 0x1150($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1150));
    // 0x80801104: nop

    // 0x80801108: nop

    // 0x8080110C: nop

;}
RECOMP_FUNC void func_8008C0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0D0: jr          $ra
    // 0x8008C0D4: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    return;
    // 0x8008C0D4: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
;}
RECOMP_FUNC void _bsstand_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B40: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B40);
    return;
    // 0x80083B44: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bashoes_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085028: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085028);
    return;
    // 0x8008502C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800328_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080032C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800330: jal         0x8010C500
    // 0x80800334: nop

    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800334: nop

    after_0:
    // 0x80800338: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x8080033C: nop
    
            goto L_80800348;
    }
    // 0x8080033C: nop

    // 0x80800340: b           L_808003C8
    // 0x80800344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C8;
    // 0x80800344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800348:
    // 0x80800348: jal         0x800D1A04
    // 0x8080034C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x8080034C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_1:
    // 0x80800350: bne         $v0, $zero, L_80800360
    if (ctx->r2 != 0) {
        // 0x80800354: nop
    
            goto L_80800360;
    }
    // 0x80800354: nop

    // 0x80800358: b           L_808003C8
    // 0x8080035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C8;
    // 0x8080035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800360:
    // 0x80800360: jal         0x800F54E4
    // 0x80800364: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800364: nop

    after_2:
    // 0x80800368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080036C: jal         0x800F64A4
    // 0x80800370: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800370: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_3:
    // 0x80800374: bne         $v0, $zero, L_80800384
    if (ctx->r2 != 0) {
        // 0x80800378: nop
    
            goto L_80800384;
    }
    // 0x80800378: nop

    // 0x8080037C: b           L_808003C8
    // 0x80800380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C8;
    // 0x80800380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800384:
    // 0x80800384: jal         0x800F54E4
    // 0x80800388: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800388: nop

    after_4:
    // 0x8080038C: jal         0x800F6720
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6720(rdram, ctx);
        goto after_5;
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800394: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800398: nop
    
            goto L_808003A4;
    }
    // 0x80800398: nop

    // 0x8080039C: b           L_808003C8
    // 0x808003A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C8;
    // 0x808003A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003A4:
    // 0x808003A4: jal         0x800F54E4
    // 0x808003A8: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808003A8: nop

    after_6:
    // 0x808003AC: jal         0x800F66F0
    // 0x808003B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F66F0(rdram, ctx);
        goto after_7;
    // 0x808003B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808003B4: beql        $v0, $zero, L_808003C8
    if (ctx->r2 == 0) {
        // 0x808003B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808003C8;
    }
    goto skip_0;
    // 0x808003B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808003BC: b           L_808003C8
    // 0x808003C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C8;
    // 0x808003C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C8:
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void func_80800168_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080016C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800170: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80800174: jal         0x80800100
    // 0x80800178: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    func_80800100_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    after_0:
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void func_800BBD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBD18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BBD1C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800BBD20: beq         $a0, $zero, L_800BBD44
    if (ctx->r4 == 0) {
        // 0x800BBD24: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800BBD44;
    }
    // 0x800BBD24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BBD28: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800BBD2C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800BBD30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BBD34: jal         0x800BABB8
    // 0x800BBD38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x800BBD38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800BBD3C: jal         0x800B4790
    // 0x800BBD40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800B4790(rdram, ctx);
        goto after_1;
    // 0x800BBD40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_800BBD44:
    // 0x800BBD44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BBD48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BBD4C: jr          $ra
    // 0x800BBD50: nop

    return;
    // 0x800BBD50: nop

    // 0x800BBD54: nop

    // 0x800BBD58: nop

    // 0x800BBD5C: nop

;}
RECOMP_FUNC void func_80800274_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800278: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080027C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800280: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800284: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800288: beq         $a1, $zero, L_808002B8
    if (ctx->r5 == 0) {
        // 0x8080028C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_808002B8;
    }
    // 0x8080028C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800294: beq         $a1, $at, L_8080039C
    if (ctx->r5 == ctx->r1) {
        // 0x80800298: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080039C;
    }
    // 0x80800298: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080029C: beq         $a1, $at, L_808002C8
    if (ctx->r5 == ctx->r1) {
        // 0x808002A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002C8;
    }
    // 0x808002A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002A8: beq         $a1, $at, L_808002EC
    if (ctx->r5 == ctx->r1) {
        // 0x808002AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002EC;
    }
    // 0x808002AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002B0: b           L_808003A0
    // 0x808002B4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_808003A0;
    // 0x808002B4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_808002B8:
    // 0x808002B8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808002BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002C0: b           L_8080039C
    // 0x808002C4: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
        goto L_8080039C;
    // 0x808002C4: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
L_808002C8:
    // 0x808002C8: jal         0x8080086C
    // 0x808002CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_0;
    // 0x808002CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808002D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002D4: jal         0x80101CDC
    // 0x808002D8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101CDC(rdram, ctx);
        goto after_1;
    // 0x808002D8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_1:
    // 0x808002DC: jal         0x8010A570
    // 0x808002E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808002E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808002E4: b           L_808003A0
    // 0x808002E8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
        goto L_808003A0;
    // 0x808002E8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_808002EC:
    // 0x808002EC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x808002F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2240, 0X1288) << 16);
    // 0x808002F4: addiu       $a2, $a2, 0x1288
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2240, 0X1288));
    // 0x808002F8: jal         0x80089D18
    // 0x808002FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808002FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800300: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2240, 0X1238) << 16);
    // 0x80800304: addiu       $t7, $t7, 0x1238
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2240, 0X1238));
    // 0x80800308: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x8080030C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800318: jal         0x800BBCB8
    // 0x8080031C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x8080031C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_4:
    // 0x80800320: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2240, 0X119C) << 16);
    // 0x80800324: addiu       $t8, $t8, 0x119C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2240, 0X119C));
    // 0x80800328: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x8080032C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800338: jal         0x800BBCB8
    // 0x8080033C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x8080033C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80800340: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2240, 0X11D0) << 16);
    // 0x80800344: addiu       $t9, $t9, 0x11D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2240, 0X11D0));
    // 0x80800348: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x8080034C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800354: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800358: jal         0x800BBCB8
    // 0x8080035C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x8080035C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
    // 0x80800360: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2240, 0X1204) << 16);
    // 0x80800364: addiu       $t0, $t0, 0x1204
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2240, 0X1204));
    // 0x80800368: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x8080036C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800378: jal         0x800BBCB8
    // 0x8080037C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x8080037C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_7:
    // 0x80800380: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800384: jal         0x80107070
    // 0x80800388: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_8;
    // 0x80800388: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080038C: bnel        $v0, $zero, L_808003A0
    if (ctx->r2 != 0) {
        // 0x80800390: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_808003A0;
    }
    goto skip_0;
    // 0x80800390: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800394: jal         0x800FFAB0
    // 0x80800398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
L_8080039C:
    // 0x8080039C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_808003A0:
    // 0x808003A0: lbu         $t5, 0x79($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X79);
    // 0x808003A4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x808003A8: andi        $t6, $t5, 0xFF0F
    ctx->r14 = ctx->r13 & 0XFF0F;
    // 0x808003AC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x808003B0: sb          $t7, 0x79($s1)
    MEM_B(0X79, ctx->r17) = ctx->r15;
    // 0x808003B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808003BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C0: jr          $ra
    // 0x808003C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808003C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bstnt_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801910: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801914: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X257C) << 16);
    // 0x80801918: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080191C: jr          $ra
    // 0x80801920: lw          $v0, 0x257C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X257C));
    return;
    // 0x80801920: lw          $v0, 0x257C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X257C));
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082808: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x80082808);
    return;
    // 0x8008280C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800CC4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC4D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CC4D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC4DC: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CC4E0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800CC4E4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800CC4E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CC4EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC4F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CC4F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CC4F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CC4FC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800CC500: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x800CC504: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CC508: bne         $t8, $zero, L_800CC518
    if (ctx->r24 != 0) {
        // 0x800CC50C: nop
    
            goto L_800CC518;
    }
    // 0x800CC50C: nop

    // 0x800CC510: b           L_800CC5D0
    // 0x800CC514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CC5D0;
    // 0x800CC514: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CC518:
    // 0x800CC518: jal         0x800CB948
    // 0x800CC51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CB948(rdram, ctx);
        goto after_0;
    // 0x800CC51C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CC520: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800CC524: jal         0x800CB968
    // 0x800CC528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CB968(rdram, ctx);
        goto after_1;
    // 0x800CC528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800CC52C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CC530: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CC534: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800CC538: beql        $at, $zero, L_800CC5D0
    if (ctx->r1 == 0) {
        // 0x800CC53C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CC5D0;
    }
    goto skip_0;
    // 0x800CC53C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800CC540: lh          $t0, 0xE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE);
L_800CC544:
    // 0x800CC544: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC548: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC54C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800CC550: nop

    // 0x800CC554: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CC558: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800CC55C: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800CC560: nop

    // 0x800CC564: bc1fl       L_800CC5C0
    if (!c1cs) {
        // 0x800CC568: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC5C0;
    }
    goto skip_1;
    // 0x800CC568: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_1:
    // 0x800CC56C: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CC570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC574: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800CC578: nop

    // 0x800CC57C: bc1fl       L_800CC5C0
    if (!c1cs) {
        // 0x800CC580: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC5C0;
    }
    goto skip_2;
    // 0x800CC580: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x800CC584: jal         0x800EFC7C
    // 0x800CC588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x800CC588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800CC58C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC590: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CC594: nop

    // 0x800CC598: bc1fl       L_800CC5C0
    if (!c1cs) {
        // 0x800CC59C: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_800CC5C0;
    }
    goto skip_3;
    // 0x800CC59C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    skip_3:
    // 0x800CC5A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CC5A4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CC5A8: subu        $v0, $s0, $t1
    ctx->r2 = SUB32(ctx->r16, ctx->r9);
    // 0x800CC5AC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC5B0: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC5B4: b           L_800CC5D4
    // 0x800CC5B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800CC5D4;
    // 0x800CC5B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CC5BC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800CC5C0:
    // 0x800CC5C0: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800CC5C4: bnel        $at, $zero, L_800CC544
    if (ctx->r1 != 0) {
        // 0x800CC5C8: lh          $t0, 0xE($s0)
        ctx->r8 = MEM_H(ctx->r16, 0XE);
            goto L_800CC544;
    }
    goto skip_4;
    // 0x800CC5C8: lh          $t0, 0xE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE);
    skip_4:
    // 0x800CC5CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CC5D0:
    // 0x800CC5D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800CC5D4:
    // 0x800CC5D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CC5D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC5DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CC5E0: jr          $ra
    // 0x800CC5E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CC5E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bstnt_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F58: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F58);
    return;
    // 0x80083F5C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808003F0_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808003F4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808003F8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x808003FC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80800400: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800404: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80800408: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x8080040C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800410: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800414: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800418: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080041C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800420: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800424: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800428: jal         0x800B53A4
    // 0x8080042C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x8080042C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80800430: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8BC) << 16);
    // 0x80800434: lwc1        $f26, 0x8BC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8BC));
    // 0x80800438: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8080043C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800440: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800444: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800448: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080044C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1892, 0XA3C) << 16);
    // 0x80800450: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800454: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800458: addiu       $s3, $s3, 0xA3C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1892, 0XA3C));
    // 0x8080045C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800460: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80800464: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800468: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_8080046C:
    // 0x8080046C: jal         0x800DC178
    // 0x80800470: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800470: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x80800474: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80800478: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800484: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80800488: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080048C: jal         0x800EEB9C
    // 0x80800490: nop

    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x80800490: nop

    after_2:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x800EF04C
    // 0x8080049C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x8080049C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x808004A0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x808004A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004AC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808004B0: jal         0x800BABB8
    // 0x808004B4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808004B4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_4:
    // 0x808004B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808004BC: bnel        $s1, $s4, L_8080046C
    if (ctx->r17 != ctx->r20) {
        // 0x808004C0: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_8080046C;
    }
    goto skip_0;
    // 0x808004C0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x808004C4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x808004C8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808004CC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808004D0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808004D4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808004D8: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808004DC: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808004E0: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808004E4: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808004E8: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808004EC: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x808004F0: jr          $ra
    // 0x808004F4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808004F4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void idwibble_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808003E8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808003EC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x808003F0: jal         0x80800324
    // 0x808003F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800324_idwibble(rdram, ctx);
        goto after_0;
    // 0x808003F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808003F8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x808003FC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800400: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800404: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80800408: mfhi        $t7
    ctx->r15 = hi;
    // 0x8080040C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80800410: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800414: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800418: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x8080041C: jal         0x80088888
    // 0x80800420: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800420: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800424: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x80800428: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x8080042C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800438: bgez        $t0, L_80800448
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8080043C: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80800448;
    }
    // 0x8080043C: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80800440: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80800444: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80800448:
    // 0x80800448: sh          $t1, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r9;
    // 0x8080044C: jal         0x800EE88C
    // 0x80800450: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800450: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800454: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80800458: jal         0x800EE88C
    // 0x8080045C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x8080045C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800460: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80800464: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800468: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080046C: lbu         $t2, 0xD($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XD);
    // 0x80800470: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80800474: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800478: nop

    // 0x8080047C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800480: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80800484: lbu         $t4, 0xD($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XD);
    // 0x80800488: beql        $t4, $zero, L_808004A0
    if (ctx->r12 == 0) {
        // 0x8080048C: sb          $zero, 0x33($s0)
        MEM_B(0X33, ctx->r16) = 0;
            goto L_808004A0;
    }
    goto skip_0;
    // 0x8080048C: sb          $zero, 0x33($s0)
    MEM_B(0X33, ctx->r16) = 0;
    skip_0:
    // 0x80800490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800494: b           L_808004A0
    // 0x80800498: sb          $a0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r4;
        goto L_808004A0;
    // 0x80800498: sb          $a0, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r4;
    // 0x8080049C: sb          $zero, 0x33($s0)
    MEM_B(0X33, ctx->r16) = 0;
L_808004A0:
    // 0x808004A0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808004A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808004A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808004AC: nop

    // 0x808004B0: bc1fl       L_808004D8
    if (!c1cs) {
        // 0x808004B4: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_808004D8;
    }
    goto skip_1;
    // 0x808004B4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x808004B8: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x808004BC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808004C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004C4: sb          $t7, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r15;
    // 0x808004C8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x808004CC: b           L_80800524
    // 0x808004D0: sh          $t6, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r14;
        goto L_80800524;
    // 0x808004D0: sh          $t6, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r14;
    // 0x808004D4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_808004D8:
    // 0x808004D8: nop

    // 0x808004DC: bc1fl       L_808004FC
    if (!c1cs) {
        // 0x808004E0: lwc1        $f18, 0x10($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
            goto L_808004FC;
    }
    goto skip_2;
    // 0x808004E0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    skip_2:
    // 0x808004E4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808004E8: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x808004EC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x808004F0: b           L_80800524
    // 0x808004F4: sh          $t9, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r25;
        goto L_80800524;
    // 0x808004F4: sh          $t9, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r25;
    // 0x808004F8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
L_808004FC:
    // 0x808004FC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800500: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800504: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800508: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8080050C: sb          $a0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r4;
    // 0x80800510: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800514: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800518: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8080051C: nop

    // 0x80800520: sh          $t1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r9;
L_80800524:
    // 0x80800524: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x80800528: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080052C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80800530: nop

    // 0x80800534: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800538: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8080053C: nop

    // 0x80800540: bc1fl       L_80800560
    if (!c1cs) {
        // 0x80800544: lbu         $t5, 0xC($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0XC);
            goto L_80800560;
    }
    goto skip_3;
    // 0x80800544: lbu         $t5, 0xC($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XC);
    skip_3:
    // 0x80800548: sh          $t3, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r11;
    // 0x8080054C: lh          $t4, 0x1A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A);
    // 0x80800550: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800554: nop

    // 0x80800558: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080055C: lbu         $t5, 0xC($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XC);
L_80800560:
    // 0x80800560: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80800564: bgez        $t5, L_80800578
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800568: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800578;
    }
    // 0x80800568: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080056C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800570: nop

    // 0x80800574: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800578:
    // 0x80800578: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080057C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80800580: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2938, 0X764) << 16);
    // 0x80800584: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x80800588: lbu         $t6, 0xC($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XC);
    // 0x8080058C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80800590: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x80800594: lbu         $t9, 0xC($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XC);
    // 0x80800598: beql        $t9, $zero, L_808005AC
    if (ctx->r25 == 0) {
        // 0x8080059C: sb          $zero, 0x32($s0)
        MEM_B(0X32, ctx->r16) = 0;
            goto L_808005AC;
    }
    goto skip_4;
    // 0x8080059C: sb          $zero, 0x32($s0)
    MEM_B(0X32, ctx->r16) = 0;
    skip_4:
    // 0x808005A0: b           L_808005AC
    // 0x808005A4: sb          $a0, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r4;
        goto L_808005AC;
    // 0x808005A4: sb          $a0, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r4;
    // 0x808005A8: sb          $zero, 0x32($s0)
    MEM_B(0X32, ctx->r16) = 0;
L_808005AC:
    // 0x808005AC: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x808005B0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808005B4: lwc1        $f18, 0x764($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2938, 0X764));
    // 0x808005B8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808005BC: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x808005C0: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808005C4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x808005C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808005CC: nop

    // 0x808005D0: bc1fl       L_808005E8
    if (!c1cs) {
        // 0x808005D4: mtc1        $t0, $f8
        ctx->f8.u32l = ctx->r8;
            goto L_808005E8;
    }
    goto skip_5;
    // 0x808005D4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    skip_5:
    // 0x808005D8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x808005DC: b           L_808005F8
    // 0x808005E0: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
        goto L_808005F8;
    // 0x808005E0: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x808005E4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
L_808005E8:
    // 0x808005E8: nop

    // 0x808005EC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808005F0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808005F4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_808005F8:
    // 0x808005F8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x808005FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800600: sh          $zero, 0x34($s0)
    MEM_H(0X34, ctx->r16) = 0;
    // 0x80800604: beq         $v0, $at, L_8080061C
    if (ctx->r2 == ctx->r1) {
        // 0x80800608: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080061C;
    }
    // 0x80800608: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080060C: beql        $v0, $at, L_80800620
    if (ctx->r2 == ctx->r1) {
        // 0x80800610: sb          $zero, 0x37($s0)
        MEM_B(0X37, ctx->r16) = 0;
            goto L_80800620;
    }
    goto skip_6;
    // 0x80800610: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    skip_6:
    // 0x80800614: b           L_80800620
    // 0x80800618: sb          $a0, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r4;
        goto L_80800620;
    // 0x80800618: sb          $a0, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r4;
L_8080061C:
    // 0x8080061C: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
L_80800620:
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800624: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800628: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080062C: jr          $ra
    // 0x80800630: nop

    return;
    // 0x80800630: nop

;}
RECOMP_FUNC void func_80800BF8_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C04: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80800C08: jal         0x800D0A9C
    // 0x80800C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80800C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800C10: bne         $v0, $zero, L_80800C58
    if (ctx->r2 != 0) {
        // 0x80800C14: addiu       $a0, $zero, 0x16C
        ctx->r4 = ADD32(0, 0X16C);
            goto L_80800C58;
    }
    // 0x80800C14: addiu       $a0, $zero, 0x16C
    ctx->r4 = ADD32(0, 0X16C);
    // 0x80800C18: jal         0x800DA980
    // 0x80800C1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_1;
    // 0x80800C1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800C20: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x80800C24: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800C28: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800C2C: addiu       $a0, $zero, 0x324
    ctx->r4 = ADD32(0, 0X324);
    // 0x80800C30: jal         0x800DA980
    // 0x80800C34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_2;
    // 0x80800C34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800C38: xori        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 ^ 0X3;
    // 0x80800C3C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C40: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800C44: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800C48: beq         $t7, $zero, L_80800C5C
    if (ctx->r15 == 0) {
        // 0x80800C4C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800C5C;
    }
    // 0x80800C4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800C50: b           L_80800C5C
    // 0x80800C54: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
        goto L_80800C5C;
    // 0x80800C54: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
L_80800C58:
    // 0x80800C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C5C:
    // 0x80800C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C64: jr          $ra
    // 0x80800C68: nop

    return;
    // 0x80800C68: nop

;}
RECOMP_FUNC void func_800178C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800178C4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800178C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800178CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800178D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800178D4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800178D8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800178DC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800178E0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800178E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800178E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800178EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800178F0: jal         0x80017810
    // 0x800178F4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    func_80017810(rdram, ctx);
        goto after_0;
    // 0x800178F4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_0:
    // 0x800178F8: bne         $v0, $zero, L_80017908
    if (ctx->r2 != 0) {
        // 0x800178FC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80017908;
    }
    // 0x800178FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80017900: b           L_80017D4C
    // 0x80017904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017D4C;
    // 0x80017904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017908:
    // 0x80017908: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8001790C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80017910: addiu       $t8, $t8, -0x5118
    ctx->r24 = ADD32(ctx->r24, -0X5118);
    // 0x80017914: beq         $t6, $zero, L_80017C84
    if (ctx->r14 == 0) {
        // 0x80017918: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80017C84;
    }
    // 0x80017918: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001791C: jal         0x800260B0
    // 0x80017920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800260B0(rdram, ctx);
        goto after_1;
    // 0x80017920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80017924: lw          $t7, 0x18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18);
    // 0x80017928: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001792C: lwc1        $f6, 0x1720($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1720);
    // 0x80017930: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80017934: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80017938: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001793C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80017940: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80017944: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80017948: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8001794C: bgez        $t8, L_80017960
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80017950: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80017960;
    }
    // 0x80017950: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80017954: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017958: nop

    // 0x8001795C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80017960:
    // 0x80017960: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80017964: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80017968: bgez        $v0, L_8001797C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001796C: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8001797C;
    }
    // 0x8001796C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80017970: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017974: nop

    // 0x80017978: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8001797C:
    // 0x8001797C: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80017980: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80017984: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80017988: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001798C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80017990: nop

    // 0x80017994: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80017998: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x8001799C: nop

    // 0x800179A0: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x800179A4: beql        $v1, $zero, L_800179F4
    if (ctx->r3 == 0) {
        // 0x800179A8: mfc1        $v1, $f16
        ctx->r3 = (int32_t)ctx->f16.u32l;
            goto L_800179F4;
    }
    goto skip_0;
    // 0x800179A8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800179AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800179B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800179B4: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800179B8: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x800179BC: nop

    // 0x800179C0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800179C4: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x800179C8: nop

    // 0x800179CC: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x800179D0: bne         $v1, $zero, L_800179E8
    if (ctx->r3 != 0) {
        // 0x800179D4: nop
    
            goto L_800179E8;
    }
    // 0x800179D4: nop

    // 0x800179D8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800179DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800179E0: b           L_80017A00
    // 0x800179E4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80017A00;
    // 0x800179E4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_800179E8:
    // 0x800179E8: b           L_80017A00
    // 0x800179EC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80017A00;
    // 0x800179EC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800179F0: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
L_800179F4:
    // 0x800179F4: nop

    // 0x800179F8: bltz        $v1, L_800179E8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800179FC: nop
    
            goto L_800179E8;
    }
    // 0x800179FC: nop

L_80017A00:
    // 0x80017A00: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80017A04: bnel        $v1, $zero, L_80017AD8
    if (ctx->r3 != 0) {
        // 0x80017A08: lw          $v1, 0x4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X4);
            goto L_80017AD8;
    }
    goto skip_1;
    // 0x80017A08: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x80017A0C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80017A10: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80017A14: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x80017A18: beq         $v1, $zero, L_80017ABC
    if (ctx->r3 == 0) {
        // 0x80017A1C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80017ABC;
    }
    // 0x80017A1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017A20: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80017A24: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80017A28: addiu       $s3, $s3, -0x5180
    ctx->r19 = ADD32(ctx->r19, -0X5180);
    // 0x80017A2C: addiu       $s6, $s6, -0x5130
    ctx->r22 = ADD32(ctx->r22, -0X5130);
    // 0x80017A30: addu        $s4, $s5, $t1
    ctx->r20 = ADD32(ctx->r21, ctx->r9);
    // 0x80017A34: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
L_80017A38:
    // 0x80017A38: sll         $t5, $s5, 2
    ctx->r13 = S32(ctx->r21 << 2);
    // 0x80017A3C: addu        $t6, $s6, $t5
    ctx->r14 = ADD32(ctx->r22, ctx->r13);
    // 0x80017A40: bne         $t2, $zero, L_80017A5C
    if (ctx->r10 != 0) {
        // 0x80017A44: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80017A5C;
    }
    // 0x80017A44: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80017A48: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80017A4C: sllv        $v0, $t3, $s0
    ctx->r2 = S32(ctx->r11 << (ctx->r16 & 31));
    // 0x80017A50: and         $t4, $s2, $v0
    ctx->r12 = ctx->r18 & ctx->r2;
    // 0x80017A54: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x80017A58: beq         $t4, $t8, L_80017AAC
    if (ctx->r12 == ctx->r24) {
        // 0x80017A5C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80017AAC;
    }
L_80017A5C:
    // 0x80017A5C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017A60: sllv        $t1, $t9, $s0
    ctx->r9 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x80017A64: and         $t2, $s2, $t1
    ctx->r10 = ctx->r18 & ctx->r9;
    // 0x80017A68: beq         $t2, $zero, L_80017A94
    if (ctx->r10 == 0) {
        // 0x80017A6C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80017A94;
    }
    // 0x80017A6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017A70: addu        $t3, $s3, $s0
    ctx->r11 = ADD32(ctx->r19, ctx->r16);
    // 0x80017A74: lbu         $a2, 0x0($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X0);
    // 0x80017A78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017A7C: jal         0x800262DC
    // 0x80017A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800262DC(rdram, ctx);
        goto after_2;
    // 0x80017A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80017A84: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    // 0x80017A88: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80017A8C: b           L_80017AAC
    // 0x80017A90: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
        goto L_80017AAC;
    // 0x80017A90: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
L_80017A94:
    // 0x80017A94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017A98: jal         0x800262DC
    // 0x80017A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800262DC(rdram, ctx);
        goto after_3;
    // 0x80017A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80017AA0: lw          $t7, 0x18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18);
    // 0x80017AA4: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80017AA8: lw          $v1, 0x4($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X4);
L_80017AAC:
    // 0x80017AAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017AB0: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80017AB4: bnel        $at, $zero, L_80017A38
    if (ctx->r1 != 0) {
        // 0x80017AB8: lbu         $t2, 0x0($s4)
        ctx->r10 = MEM_BU(ctx->r20, 0X0);
            goto L_80017A38;
    }
    goto skip_2;
    // 0x80017AB8: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    skip_2:
L_80017ABC:
    // 0x80017ABC: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80017AC0: addiu       $s6, $s6, -0x5130
    ctx->r22 = ADD32(ctx->r22, -0X5130);
    // 0x80017AC4: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x80017AC8: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x80017ACC: b           L_80017C34
    // 0x80017AD0: sw          $s2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r18;
        goto L_80017C34;
    // 0x80017AD0: sw          $s2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r18;
    // 0x80017AD4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
L_80017AD8:
    // 0x80017AD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017ADC: beq         $v1, $zero, L_80017C20
    if (ctx->r3 == 0) {
        // 0x80017AE0: lui         $t1, 0x8008
        ctx->r9 = S32(0X8008 << 16);
            goto L_80017C20;
    }
    // 0x80017AE0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80017AE4: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x80017AE8: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80017AEC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80017AF0: addiu       $s3, $s3, -0x5180
    ctx->r19 = ADD32(ctx->r19, -0X5180);
    // 0x80017AF4: addiu       $s6, $s6, -0x5130
    ctx->r22 = ADD32(ctx->r22, -0X5130);
    // 0x80017AF8: addu        $s4, $s5, $t1
    ctx->r20 = ADD32(ctx->r21, ctx->r9);
    // 0x80017AFC: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
L_80017B00:
    // 0x80017B00: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x80017B04: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x80017B08: bne         $t2, $zero, L_80017B24
    if (ctx->r10 != 0) {
        // 0x80017B0C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80017B24;
    }
    // 0x80017B0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80017B10: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80017B14: sllv        $v0, $t3, $s0
    ctx->r2 = S32(ctx->r11 << (ctx->r16 & 31));
    // 0x80017B18: and         $t5, $s2, $v0
    ctx->r13 = ctx->r18 & ctx->r2;
    // 0x80017B1C: and         $t8, $t4, $v0
    ctx->r24 = ctx->r12 & ctx->r2;
    // 0x80017B20: beq         $t5, $t8, L_80017C10
    if (ctx->r13 == ctx->r24) {
        // 0x80017B24: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80017C10;
    }
L_80017B24:
    // 0x80017B24: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80017B28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017B2C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80017B30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80017B34: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
    // 0x80017B38: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80017B3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80017B40: sllv        $t2, $t1, $s0
    ctx->r10 = S32(ctx->r9 << (ctx->r16 & 31));
    // 0x80017B44: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x80017B48: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80017B4C: and         $t3, $s2, $t2
    ctx->r11 = ctx->r18 & ctx->r10;
    // 0x80017B50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80017B54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80017B58: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80017B5C: addu        $t6, $s3, $s0
    ctx->r14 = ADD32(ctx->r19, ctx->r16);
    // 0x80017B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017B64: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80017B68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017B6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017B70: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80017B74: nop

    // 0x80017B78: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80017B7C: beql        $t0, $zero, L_80017BCC
    if (ctx->r8 == 0) {
        // 0x80017B80: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_80017BCC;
    }
    goto skip_3;
    // 0x80017B80: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x80017B84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017B88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80017B8C: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80017B90: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80017B94: nop

    // 0x80017B98: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80017B9C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80017BA0: nop

    // 0x80017BA4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80017BA8: bne         $t0, $zero, L_80017BC0
    if (ctx->r8 != 0) {
        // 0x80017BAC: nop
    
            goto L_80017BC0;
    }
    // 0x80017BAC: nop

    // 0x80017BB0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80017BB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80017BB8: b           L_80017BD8
    // 0x80017BBC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80017BD8;
    // 0x80017BBC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80017BC0:
    // 0x80017BC0: b           L_80017BD8
    // 0x80017BC4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80017BD8;
    // 0x80017BC4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80017BC8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_80017BCC:
    // 0x80017BCC: nop

    // 0x80017BD0: bltz        $t0, L_80017BC0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80017BD4: nop
    
            goto L_80017BC0;
    }
    // 0x80017BD4: nop

L_80017BD8:
    // 0x80017BD8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80017BDC: beq         $t3, $zero, L_80017BEC
    if (ctx->r11 == 0) {
        // 0x80017BE0: nop
    
            goto L_80017BEC;
    }
    // 0x80017BE0: nop

    // 0x80017BE4: b           L_80017BEC
    // 0x80017BE8: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
        goto L_80017BEC;
    // 0x80017BE8: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
L_80017BEC:
    // 0x80017BEC: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    // 0x80017BF0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x80017BF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80017BF8: addu        $t4, $t7, $v1
    ctx->r12 = ADD32(ctx->r15, ctx->r3);
    // 0x80017BFC: jal         0x80026238
    // 0x80017C00: sb          $t0, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r8;
    func_80026238(rdram, ctx);
        goto after_4;
    // 0x80017C00: sb          $t0, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r8;
    after_4:
    // 0x80017C04: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    // 0x80017C08: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80017C0C: lw          $v1, 0x4($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X4);
L_80017C10:
    // 0x80017C10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017C14: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80017C18: bnel        $at, $zero, L_80017B00
    if (ctx->r1 != 0) {
        // 0x80017C1C: lbu         $t2, 0x0($s4)
        ctx->r10 = MEM_BU(ctx->r20, 0X0);
            goto L_80017B00;
    }
    goto skip_4;
    // 0x80017C1C: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    skip_4:
L_80017C20:
    // 0x80017C20: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80017C24: addiu       $s6, $s6, -0x5130
    ctx->r22 = ADD32(ctx->r22, -0X5130);
    // 0x80017C28: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80017C2C: addu        $t1, $s6, $t9
    ctx->r9 = ADD32(ctx->r22, ctx->r25);
    // 0x80017C30: sw          $s2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r18;
L_80017C34:
    // 0x80017C34: lw          $t2, 0x18($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X18);
    // 0x80017C38: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80017C3C: addiu       $v0, $v0, -0x5180
    ctx->r2 = ADD32(ctx->r2, -0X5180);
    // 0x80017C40: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80017C44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017C48: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80017C4C: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x80017C50: beq         $t6, $zero, L_80017C7C
    if (ctx->r14 == 0) {
        // 0x80017C54: nop
    
            goto L_80017C7C;
    }
    // 0x80017C54: nop

    // 0x80017C58: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80017C5C:
    // 0x80017C5C: lw          $t7, 0x18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18);
    // 0x80017C60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017C64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017C68: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80017C6C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80017C70: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x80017C74: bnel        $at, $zero, L_80017C5C
    if (ctx->r1 != 0) {
        // 0x80017C78: sb          $v1, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r3;
            goto L_80017C5C;
    }
    goto skip_5;
    // 0x80017C78: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    skip_5:
L_80017C7C:
    // 0x80017C7C: b           L_80017D4C
    // 0x80017C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80017D4C;
    // 0x80017C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017C84:
    // 0x80017C84: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80017C88: addiu       $t1, $t1, -0x5130
    ctx->r9 = ADD32(ctx->r9, -0X5130);
    // 0x80017C8C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80017C90: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80017C94: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80017C98: addiu       $s3, $s3, -0x5180
    ctx->r19 = ADD32(ctx->r19, -0X5180);
    // 0x80017C9C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80017CA0: addu        $s4, $s5, $t8
    ctx->r20 = ADD32(ctx->r21, ctx->r24);
    // 0x80017CA4: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
L_80017CA8:
    // 0x80017CA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80017CAC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80017CB0: bne         $t3, $zero, L_80017CD0
    if (ctx->r11 != 0) {
        // 0x80017CB4: sllv        $t1, $t9, $s0
        ctx->r9 = S32(ctx->r25 << (ctx->r16 & 31));
            goto L_80017CD0;
    }
    // 0x80017CB4: sllv        $t1, $t9, $s0
    ctx->r9 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x80017CB8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80017CBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80017CC0: sllv        $v0, $t6, $s0
    ctx->r2 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x80017CC4: and         $t7, $s2, $v0
    ctx->r15 = ctx->r18 & ctx->r2;
    // 0x80017CC8: and         $t8, $t5, $v0
    ctx->r24 = ctx->r13 & ctx->r2;
    // 0x80017CCC: beq         $t7, $t8, L_80017D04
    if (ctx->r15 == ctx->r24) {
        // 0x80017CD0: and         $t2, $s2, $t1
        ctx->r10 = ctx->r18 & ctx->r9;
            goto L_80017D04;
    }
L_80017CD0:
    // 0x80017CD0: and         $t2, $s2, $t1
    ctx->r10 = ctx->r18 & ctx->r9;
    // 0x80017CD4: beq         $t2, $zero, L_80017CF8
    if (ctx->r10 == 0) {
        // 0x80017CD8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80017CF8;
    }
    // 0x80017CD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017CDC: addu        $t3, $s3, $s0
    ctx->r11 = ADD32(ctx->r19, ctx->r16);
    // 0x80017CE0: lbu         $a2, 0x0($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X0);
    // 0x80017CE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017CE8: jal         0x800262DC
    // 0x80017CEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800262DC(rdram, ctx);
        goto after_5;
    // 0x80017CEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80017CF0: b           L_80017D08
    // 0x80017CF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80017D08;
    // 0x80017CF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80017CF8:
    // 0x80017CF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017CFC: jal         0x800262DC
    // 0x80017D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800262DC(rdram, ctx);
        goto after_6;
    // 0x80017D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80017D04:
    // 0x80017D04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80017D08:
    // 0x80017D08: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x80017D0C: bnel        $at, $zero, L_80017CA8
    if (ctx->r1 != 0) {
        // 0x80017D10: lbu         $t3, 0x0($s4)
        ctx->r11 = MEM_BU(ctx->r20, 0X0);
            goto L_80017CA8;
    }
    goto skip_6;
    // 0x80017D10: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    skip_6:
    // 0x80017D14: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80017D18: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80017D1C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80017D20: addiu       $a0, $a0, -0x5160
    ctx->r4 = ADD32(ctx->r4, -0X5160);
    // 0x80017D24: addiu       $v0, $v0, -0x5180
    ctx->r2 = ADD32(ctx->r2, -0X5180);
    // 0x80017D28: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80017D2C: sw          $s2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r18;
L_80017D30:
    // 0x80017D30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80017D34: sb          $v1, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r3;
    // 0x80017D38: sb          $v1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r3;
    // 0x80017D3C: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
    // 0x80017D40: bne         $v0, $a0, L_80017D30
    if (ctx->r2 != ctx->r4) {
        // 0x80017D44: sb          $v1, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = ctx->r3;
            goto L_80017D30;
    }
    // 0x80017D44: sb          $v1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r3;
    // 0x80017D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80017D4C:
    // 0x80017D4C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80017D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017D54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80017D58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80017D5C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80017D60: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80017D64: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80017D68: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80017D6C: jr          $ra
    // 0x80017D70: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80017D70: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80800304_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080030C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800314: jal         0x80100094
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080031C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800320: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800324: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800328: bnel        $t6, $at, L_80800350
    if (ctx->r14 != ctx->r1) {
        // 0x8080032C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800350;
    }
    goto skip_0;
    // 0x8080032C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800330: jal         0x8010A570
    // 0x80800334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80800334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: jal         0x8008A4B0
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800344: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800348: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x8080034C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800350:
    // 0x80800350: jal         0x80101FDC
    // 0x80800354: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800354: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080035C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800360: jr          $ra
    // 0x80800364: nop

    return;
    // 0x80800364: nop

;}
RECOMP_FUNC void func_800D725C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D725C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D7260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7264: jal         0x800D6254
    // 0x800D7268: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D7268: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D726C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7270: bne         $v0, $at, L_800D7288
    if (ctx->r2 != ctx->r1) {
        // 0x800D7274: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D7288;
    }
    // 0x800D7274: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D7278: jal         0x800D674C
    // 0x800D727C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x800D727C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800D7280: b           L_800D7310
    // 0x800D7284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D7310;
    // 0x800D7284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D7288:
    // 0x800D7288: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D728C: sh          $a1, -0x46F0($at)
    MEM_H(-0X46F0, ctx->r1) = ctx->r5;
    // 0x800D7290: jal         0x8001211C
    // 0x800D7294: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x800D7294: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x800D7298: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800D729C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D72A0: addiu       $t7, $t7, -0x4800
    ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x800D72A4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D72A8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800D72AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D72B0: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x800D72B4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800D72B8: lui         $at, 0x7FF
    ctx->r1 = S32(0X7FF << 16);
    // 0x800D72BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D72C0: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800D72C4: srl         $t9, $v1, 5
    ctx->r25 = S32(U32(ctx->r3) >> 5);
    // 0x800D72C8: xor         $t0, $t8, $t9
    ctx->r8 = ctx->r24 ^ ctx->r25;
    // 0x800D72CC: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800D72D0: xor         $t2, $t1, $v1
    ctx->r10 = ctx->r9 ^ ctx->r3;
    // 0x800D72D4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800D72D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800D72DC: jal         0x800D5950
    // 0x800D72E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800D5950(rdram, ctx);
        goto after_3;
    // 0x800D72E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800D72E4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D72E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D72EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D72F0: jal         0x800D5EB4
    // 0x800D72F4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    func_800D5EB4(rdram, ctx);
        goto after_4;
    // 0x800D72F4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_4:
    // 0x800D72F8: beq         $v0, $zero, L_800D7308
    if (ctx->r2 == 0) {
        // 0x800D72FC: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_800D7308;
    }
    // 0x800D72FC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7300: b           L_800D730C
    // 0x800D7304: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
        goto L_800D730C;
    // 0x800D7304: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
L_800D7308:
    // 0x800D7308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D730C:
    // 0x800D730C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D7310:
    // 0x800D7310: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D7314: jr          $ra
    // 0x800D7318: nop

    return;
    // 0x800D7318: nop

;}
RECOMP_FUNC void func_8009BAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BAE8: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BAEC: jr          $ra
    // 0x8009BAF0: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    return;
    // 0x8009BAF0: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
;}
