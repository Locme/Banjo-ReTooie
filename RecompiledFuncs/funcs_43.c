#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void rom_dma_read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80012F7C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80012F80: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80012F84: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80012F88: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80012F8C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80012F90: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80012F94: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80012F98: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80012F9C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80012FA0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80012FA4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80012FA8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80012FAC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80012FB0: jal         0x8002E660
    // 0x80012FB4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80012FB4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80012FB8: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80012FBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80012FC0: lui         $s7, 0x2
    ctx->r23 = S32(0X2 << 16);
    // 0x80012FC4: bgez        $v0, L_80012FDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012FC8: sra         $t6, $v0, 17
        ctx->r14 = S32(SIGNED(ctx->r2) >> 17);
            goto L_80012FDC;
    }
    // 0x80012FC8: sra         $t6, $v0, 17
    ctx->r14 = S32(SIGNED(ctx->r2) >> 17);
    // 0x80012FCC: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80012FD0: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80012FD4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80012FD8: sra         $t6, $at, 17
    ctx->r14 = S32(SIGNED(ctx->r1) >> 17);
L_80012FDC:
    // 0x80012FDC: blez        $t6, L_80013060
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80012FE0: or          $s5, $t6, $zero
        ctx->r21 = ctx->r14 | 0;
            goto L_80013060;
    }
    // 0x80012FE0: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80012FE4: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x80012FE8: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x80012FEC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80012FF0: addiu       $s1, $s1, -0x3390
    ctx->r17 = ADD32(ctx->r17, -0X3390);
    // 0x80012FF4: addiu       $s4, $s4, 0x695C
    ctx->r20 = ADD32(ctx->r20, 0X695C);
    // 0x80012FF8: addiu       $s6, $s6, 0x6940
    ctx->r22 = ADD32(ctx->r22, 0X6940);
    // 0x80012FFC: lui         $fp, 0x2
    ctx->r30 = S32(0X2 << 16);
L_80013000:
    // 0x80013000: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80013004: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80013008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001300C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80013010: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80013014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013018: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001301C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80013020: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x80013024: jal         0x8002E450
    // 0x80013028: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80013028: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_1:
    // 0x8001302C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80013030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013034: jal         0x8002E1F0
    // 0x80013038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80013038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8001303C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80013040: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80013044: addu        $s3, $s3, $at
    ctx->r19 = ADD32(ctx->r19, ctx->r1);
    // 0x80013048: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001304C: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80013050: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80013054: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x80013058: bne         $at, $zero, L_80013000
    if (ctx->r1 != 0) {
        // 0x8001305C: sw          $t0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r8;
            goto L_80013000;
    }
    // 0x8001305C: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80013060:
    // 0x80013060: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80013064: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80013068: addiu       $s1, $s1, -0x3390
    ctx->r17 = ADD32(ctx->r17, -0X3390);
    // 0x8001306C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80013070: lui         $s4, 0x8007
    ctx->r20 = S32(0X8007 << 16);
    // 0x80013074: lui         $s6, 0x8007
    ctx->r22 = S32(0X8007 << 16);
    // 0x80013078: addiu       $s6, $s6, 0x6940
    ctx->r22 = ADD32(ctx->r22, 0X6940);
    // 0x8001307C: addiu       $s4, $s4, 0x695C
    ctx->r20 = ADD32(ctx->r20, 0X695C);
    // 0x80013080: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80013084: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80013088: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8001308C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80013090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013098: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001309C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800130A0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800130A4: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x800130A8: bgez        $t3, L_800130BC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800130AC: and         $t4, $t3, $at
        ctx->r12 = ctx->r11 & ctx->r1;
            goto L_800130BC;
    }
    // 0x800130AC: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800130B0: beq         $t4, $zero, L_800130BC
    if (ctx->r12 == 0) {
        // 0x800130B4: addiu       $at, $at, 0x1
        ctx->r1 = ADD32(ctx->r1, 0X1);
            goto L_800130BC;
    }
    // 0x800130B4: addiu       $at, $at, 0x1
    ctx->r1 = ADD32(ctx->r1, 0X1);
    // 0x800130B8: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
L_800130BC:
    // 0x800130BC: jal         0x8002E450
    // 0x800130C0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x800130C0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x800130C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800130C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800130CC: jal         0x8002E1F0
    // 0x800130D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800130D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800130D4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800130D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800130DC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800130E0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800130E4: jal         0x8002E6E0
    // 0x800130E8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    osInvalDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x800130E8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    after_5:
    // 0x800130EC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800130F0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800130F4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800130F8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800130FC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80013100: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80013104: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80013108: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8001310C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80013110: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80013114: jr          $ra
    // 0x80013118: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80013118: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800F5A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, 1);
    // 0x800F5A2C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5A34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5A3C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5A40: jal         0x800F3BD0
    // 0x800F5A44: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3BD0(rdram, ctx);
        goto after_0;
    // 0x800F5A44: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5A50: jr          $ra
    // 0x800F5A54: nop

    return;
    // 0x800F5A54: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AA0: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087AA0);
    return;
    // 0x80087AA4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsdronebitten_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: jal         0x8008E95C
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800074: jal         0x8009EF60
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bastick_popZone(rdram, ctx);
        goto after_1;
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void chpickups_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0XA18) << 16);
    // 0x80800070: jr          $ra
    // 0x80800074: addiu       $v0, $v0, 0xA18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0XA18));
    return;
    // 0x80800074: addiu       $v0, $v0, 0xA18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0XA18));
;}
RECOMP_FUNC void gclevel_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8080023C: lbu         $v1, 0x762C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X762C);
    // 0x80800240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800244: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x80800248: bne         $at, $zero, L_80800268
    if (ctx->r1 != 0) {
        // 0x8080024C: slti        $at, $v1, 0x1C
        ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
            goto L_80800268;
    }
    // 0x8080024C: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x80800250: beq         $at, $zero, L_80800268
    if (ctx->r1 == 0) {
        // 0x80800254: lui         $t6, 0x8080
        ctx->r14 = S32(RELOC_HI16(2662, 0X3B3) << 16);
            goto L_80800268;
    }
    // 0x80800254: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2662, 0X3B3) << 16);
    // 0x80800258: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8080025C: lbu         $t6, 0x3B3($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(2662, 0X3B3));
    // 0x80800260: jr          $ra
    // 0x80800264: and         $v0, $t6, $a0
    ctx->r2 = ctx->r14 & ctx->r4;
    return;
    // 0x80800264: and         $v0, $t6, $a0
    ctx->r2 = ctx->r14 & ctx->r4;
L_80800268:
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void func_8080040C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800410: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800414: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800418: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080041C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800420: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800424: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800428: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8080042C: jal         0x80100094
    // 0x80800430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800434: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800438: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080043C: slti        $at, $a2, 0xC
    ctx->r1 = SIGNED(ctx->r6) < 0XC ? 1 : 0;
    // 0x80800440: bne         $at, $zero, L_80800468
    if (ctx->r1 != 0) {
        // 0x80800444: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_80800468;
    }
    // 0x80800444: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x80800448: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x8080044C: beq         $at, $zero, L_80800474
    if (ctx->r1 == 0) {
        // 0x80800450: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800474;
    }
    // 0x80800450: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800454: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1308, 0X20D8) << 16);
    // 0x80800458: addu        $at, $at, $t6
    gpr jr_addend_80800460 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080045C: lw          $t6, 0x20D8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1308, 0X20D8));
    // 0x80800460: jr          $t6
    // 0x80800464: nop

    switch (jr_addend_80800460 >> 2) {
        case 0: goto L_8080047C; break;
        case 1: goto L_80800474; break;
        case 2: goto L_80800498; break;
        case 3: goto L_80800474; break;
        case 4: goto L_808005E8; break;
        case 5: goto L_80800474; break;
        case 6: goto L_80800474; break;
        case 7: goto L_80800474; break;
        case 8: goto L_80800474; break;
        case 9: goto L_80800474; break;
        case 10: goto L_80800474; break;
        case 11: goto L_80800474; break;
        case 12: goto L_80800474; break;
        case 13: goto L_80800474; break;
        case 14: goto L_80800474; break;
        case 15: goto L_808004B4; break;
        case 16: goto L_80800474; break;
        case 17: goto L_80800474; break;
        case 18: goto L_80800474; break;
        case 19: goto L_80800474; break;
        case 20: goto L_80800474; break;
        case 21: goto L_80800474; break;
        case 22: goto L_80800474; break;
        case 23: goto L_80800474; break;
        case 24: goto L_80800474; break;
        case 25: goto L_80800474; break;
        case 26: goto L_80800474; break;
        case 27: goto L_80800514; break;
        case 28: goto L_80800474; break;
        case 29: goto L_80800474; break;
        case 30: goto L_80800474; break;
        case 31: goto L_80800474; break;
        case 32: goto L_80800474; break;
        case 33: goto L_80800474; break;
        case 34: goto L_80800474; break;
        case 35: goto L_80800474; break;
        case 36: goto L_80800474; break;
        case 37: goto L_80800474; break;
        case 38: goto L_80800474; break;
        case 39: goto L_80800474; break;
        case 40: goto L_80800474; break;
        case 41: goto L_808005B4; break;
        default: switch_error(__func__, 0x80800460, 0x808020D8);
    }
    // 0x80800464: nop

L_80800468:
    // 0x80800468: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080046C: beq         $a2, $at, L_808004C8
    if (ctx->r6 == ctx->r1) {
        // 0x80800470: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_808004C8;
    }
    // 0x80800470: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
L_80800474:
    // 0x80800474: b           L_80800638
    // 0x80800478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800638;
    // 0x80800478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080047C:
    // 0x8080047C: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80800480: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800484: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800488: jal         0x80800748
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800748_chfactorytwinklies(rdram, ctx);
        goto after_1;
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800490: b           L_80800638
    // 0x80800494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800638;
    // 0x80800494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800498:
    // 0x80800498: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x8080049C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808004A0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808004A4: jal         0x808009EC
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009EC_chfactorytwinklies(rdram, ctx);
        goto after_2;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004AC: b           L_8080063C
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080063C;
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004B4:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x80800A84
    // 0x808004BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80800A84_chfactorytwinklies(rdram, ctx);
        goto after_3;
    // 0x808004BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x808004C0: b           L_80800638
    // 0x808004C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800638;
    // 0x808004C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004C8:
    // 0x808004C8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x808004CC: bne         $t7, $at, L_8080050C
    if (ctx->r15 != ctx->r1) {
        // 0x808004D0: nop
    
            goto L_8080050C;
    }
    // 0x808004D0: nop

    // 0x808004D4: jal         0x800F54E4
    // 0x808004D8: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808004D8: nop

    after_4:
    // 0x808004DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004E0: jal         0x800F82D4
    // 0x808004E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_5;
    // 0x808004E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x80101FDC
    // 0x808004F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808004F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x808004F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x8008A2C0
    // 0x80800500: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800500: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_7:
    // 0x80800504: b           L_80800638
    // 0x80800508: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800638;
    // 0x80800508: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080050C:
    // 0x8080050C: b           L_80800638
    // 0x80800510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800638;
    // 0x80800510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800514:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080051C: addiu       $a2, $zero, 0x320
    ctx->r6 = ADD32(0, 0X320);
    // 0x80800520: jal         0x8008A2F0
    // 0x80800524: addiu       $a3, $zero, 0x1C8
    ctx->r7 = ADD32(0, 0X1C8);
    _susubgame_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800524: addiu       $a3, $zero, 0x1C8
    ctx->r7 = ADD32(0, 0X1C8);
    after_8:
    // 0x80800528: beq         $v0, $zero, L_80800558
    if (ctx->r2 == 0) {
        // 0x8080052C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800558;
    }
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800538: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8080053C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800540: jal         0x8008A2D0
    // 0x80800544: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x80800544: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_9:
    // 0x80800548: jal         0x800861A8
    // 0x8080054C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x8080054C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800550: b           L_80800638
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800638;
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800558:
    // 0x80800558: jal         0x80086B58
    // 0x8080055C: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x8080055C: nop

    after_11:
    // 0x80800560: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8080056C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800570: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800574: jal         0x8008A2C8
    // 0x80800578: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x80800578: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_12:
    // 0x8080057C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800580: addiu       $t8, $zero, 0xA3
    ctx->r24 = ADD32(0, 0XA3);
    // 0x80800584: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800588: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x8080058C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800590: jal         0x8008A208
    // 0x80800594: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800594: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80800598: jal         0x800F54E4
    // 0x8080059C: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x8080059C: nop

    after_14:
    // 0x808005A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A4: jal         0x800F82D4
    // 0x808005A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_15;
    // 0x808005A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x808005AC: b           L_80800638
    // 0x808005B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800638;
    // 0x808005B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B4:
    // 0x808005B4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808005B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808005BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808005C0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808005C4: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x808005C8: and         $t0, $a3, $at
    ctx->r8 = ctx->r7 & ctx->r1;
    // 0x808005CC: srl         $a3, $t0, 16
    ctx->r7 = S32(U32(ctx->r8) >> 16);
    // 0x808005D0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x8008A2B8
    // 0x808005DC: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808005DC: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_16:
    // 0x808005E0: b           L_8080063C
    // 0x808005E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080063C;
    // 0x808005E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005E8:
    // 0x808005E8: jal         0x80086B58
    // 0x808005EC: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x808005EC: nop

    after_17:
    // 0x808005F0: jal         0x800D395C
    // 0x808005F4: nop

    func_800D395C(rdram, ctx);
        goto after_18;
    // 0x808005F4: nop

    after_18:
    // 0x808005F8: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x808005FC: addiu       $a2, $zero, 0x46
        ctx->r6 = ADD32(0, 0X46);
            goto L_80800608;
    }
    // 0x808005FC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800600: b           L_8080060C
    // 0x80800604: addiu       $a1, $zero, 0x1385
    ctx->r5 = ADD32(0, 0X1385);
        goto L_8080060C;
    // 0x80800604: addiu       $a1, $zero, 0x1385
    ctx->r5 = ADD32(0, 0X1385);
L_80800608:
    // 0x80800608: addiu       $a1, $zero, 0x1344
    ctx->r5 = ADD32(0, 0X1344);
L_8080060C:
    // 0x8080060C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800610: addiu       $t2, $zero, 0xA3
    ctx->r10 = ADD32(0, 0XA3);
    // 0x80800614: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800618: jal         0x8008A208
    // 0x8080061C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x8080061C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_19:
    // 0x80800620: jal         0x800F54E4
    // 0x80800624: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x80800624: nop

    after_20:
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080062C: jal         0x800F82D4
    // 0x80800630: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_21;
    // 0x80800630: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x80800634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800638:
    // 0x80800638: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080063C:
    // 0x8080063C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800640: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void _scradar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089740: syscall     792
    recomp_syscall_handler(rdram, ctx, 0x80089740);
    return;
    // 0x80089744: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void batranslate_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800074: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800078: lw          $a0, 0x140($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X140);
    // 0x8080007C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800080: jal         0x800EFD24
    // 0x80800084: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800084: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x80800088: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: lw          $a0, 0x140($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X140);
    // 0x80800090: jal         0x800EFD24
    // 0x80800094: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800094: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x80800098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A0: lw          $t6, 0x140($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X140);
    // 0x808000A4: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x808000A8: lw          $t7, 0x140($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X140);
    // 0x808000AC: jal         0x808000C4
    // 0x808000B0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    batranslate_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000B0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    after_2:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_800F7364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7364: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7368: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F736C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800F7370: lw          $a1, 0x5490($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5490);
    // 0x800F7374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F737C: beql        $a1, $zero, L_800F7390
    if (ctx->r5 == 0) {
        // 0x800F7380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F7390;
    }
    goto skip_0;
    // 0x800F7380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F7384: jal         0x80092AA4
    // 0x800F7388: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80092AA4(rdram, ctx);
        goto after_0;
    // 0x800F7388: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800F738C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F7390:
    // 0x800F7390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F7394: jr          $ra
    // 0x800F7398: nop

    return;
    // 0x800F7398: nop

;}
RECOMP_FUNC void func_80801A38_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801A44: jal         0x8008CABC
    // 0x80801A48: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801A48: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801A4C: lui         $a1, 0x3E0B
    ctx->r5 = S32(0X3E0B << 16);
    // 0x80801A50: ori         $a1, $a1, 0xF28
    ctx->r5 = ctx->r5 | 0XF28;
    // 0x80801A54: jal         0x8008B348
    // 0x80801A58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80801A58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801A5C: beq         $v0, $zero, L_80801A8C
    if (ctx->r2 == 0) {
        // 0x80801A60: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801A8C;
    }
    // 0x80801A60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801A64: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801A68: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80801A6C: addiu       $t6, $zero, 0x2710
    ctx->r14 = ADD32(0, 0X2710);
    // 0x80801A70: addiu       $t7, $zero, 0x2EE0
    ctx->r15 = ADD32(0, 0X2EE0);
    // 0x80801A74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801A78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801A7C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801A80: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801A84: jal         0x8009DEC0
    // 0x80801A88: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    func_8009DEC0(rdram, ctx);
        goto after_2;
    // 0x80801A88: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    after_2:
L_80801A8C:
    // 0x80801A8C: jal         0x8008E124
    // 0x80801A90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008E124(rdram, ctx);
        goto after_3;
    // 0x80801A90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80801A94: bne         $v0, $zero, L_80801AA0
    if (ctx->r2 != 0) {
        // 0x80801A98: addiu       $t8, $zero, 0x162
        ctx->r24 = ADD32(0, 0X162);
            goto L_80801AA0;
    }
    // 0x80801A98: addiu       $t8, $zero, 0x162
    ctx->r24 = ADD32(0, 0X162);
    // 0x80801A9C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80801AA0:
    // 0x80801AA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801AA4: jal         0x8009E5C8
    // 0x80801AA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801AA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801AB4: jr          $ra
    // 0x80801AB8: nop

    return;
    // 0x80801AB8: nop

;}
RECOMP_FUNC void func_80802458_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080245C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802460: jal         0x800A3280
    // 0x80802464: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802464: nop

    after_0:
    // 0x80802468: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080246C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802470: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XABF0) << 16);
    // 0x80802474: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802478: lw          $v0, -0x5410($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XABF0));
    // 0x8080247C: jr          $ra
    // 0x80802480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80802480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080058C_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080058C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800590: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800594: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800598: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080059C: lui         $a0, 0xFFFE
    ctx->r4 = S32(0XFFFE << 16);
    // 0x808005A0: jal         0x80090178
    // 0x808005A4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x808005A4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_0:
    // 0x808005A8: beql        $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x808005AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800658;
    }
    goto skip_0;
    // 0x808005AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808005B0: jal         0x800DA298
    // 0x808005B4: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808005B4: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
    after_1:
    // 0x808005B8: bne         $v0, $zero, L_808005E0
    if (ctx->r2 != 0) {
        // 0x808005BC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808005E0;
    }
    // 0x808005BC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005C8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x808005CC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x808005D0: jal         0x8008A1C0
    // 0x808005D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808005D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x808005D8: b           L_808005F4
    // 0x808005DC: nop

        goto L_808005F4;
    // 0x808005DC: nop

L_808005E0:
    // 0x808005E0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x808005E4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x808005E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808005EC: jal         0x8008A1D8
    // 0x808005F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808005F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
L_808005F4:
    // 0x808005F4: beql        $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x808005F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800658;
    }
    goto skip_1;
    // 0x808005F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808005FC: jal         0x800DA544
    // 0x80800600: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800600: addiu       $a0, $zero, 0xD3
    ctx->r4 = ADD32(0, 0XD3);
    after_4:
    // 0x80800604: jal         0x80800800
    // 0x80800608: nop

    func_80800800_chcheatomenu(rdram, ctx);
        goto after_5;
    // 0x80800608: nop

    after_5:
    // 0x8080060C: bne         $v0, $zero, L_8080064C
    if (ctx->r2 != 0) {
        // 0x80800610: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080064C;
    }
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800618: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x8080061C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800620: addiu       $a1, $zero, 0x1149
    ctx->r5 = ADD32(0, 0X1149);
    // 0x80800624: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800628: jal         0x8008A208
    // 0x8080062C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080062C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x80101FDC
    // 0x80800638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080063C: jal         0x80800720
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800720_chcheatomenu(rdram, ctx);
        goto after_8;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800644: b           L_80800658
    // 0x80800648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800658;
    // 0x80800648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080064C:
    // 0x8080064C: jal         0x80101FDC
    // 0x80800650: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80800650: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800658:
    // 0x80800658: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080065C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800660: jr          $ra
    // 0x80800664: nop

    return;
    // 0x80800664: nop

;}
RECOMP_FUNC void func_8080015C_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800160: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800164: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800168: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080016C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800170: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x80800174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800178: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8080017C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800180: jal         0x800EE7F8
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800188: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080018C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800190: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8B4) << 16);
    // 0x80800198: lwc1        $f16, 0x8B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8B4));
    // 0x8080019C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001A0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1892, 0X8D0) << 16);
    // 0x808001A4: addiu       $t6, $t6, 0x8D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1892, 0X8D0));
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808001B0: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    // 0x808001B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001BC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808001C0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808001C4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808001C8: jal         0x800BBCB8
    // 0x808001CC: nop

    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808001CC: nop

    after_1:
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8B8) << 16);
    // 0x808001D4: lwc1        $f6, 0x8B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8B8));
    // 0x808001D8: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x808001DC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1892, 0X8F4) << 16);
    // 0x808001E0: addiu       $t7, $t7, 0x8F4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1892, 0X8F4));
    // 0x808001E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808001F8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808001FC: jal         0x800BBCB8
    // 0x80800200: nop

    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800200: nop

    after_2:
    // 0x80800204: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1892, 0XA18) << 16);
    // 0x80800208: addiu       $t8, $t8, 0xA18
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1892, 0XA18));
    // 0x8080020C: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x80800210: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080021C: jal         0x800BBCB8
    // 0x80800220: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800220: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_3:
    // 0x80800224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800228: jal         0x808003F0
    // 0x8080022C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808003F0_chtntbox(rdram, ctx);
        goto after_4;
    // 0x8080022C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800230: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80800234: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800238: jal         0x80800824
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800824_chtntbox(rdram, ctx);
        goto after_5;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800240: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1892, 0X938) << 16);
    // 0x80800244: addiu       $a2, $a2, 0x938
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1892, 0X938));
    // 0x80800248: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080024C: jal         0x80089D18
    // 0x80800250: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800250: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800254: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800258: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080025C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800260: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800264: jal         0x800E1610
    // 0x80800268: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800E1610(rdram, ctx);
        goto after_7;
    // 0x80800268: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_7:
    // 0x8080026C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800270: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800274: jal         0x80018820
    // 0x80800278: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_8;
    // 0x80800278: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_8:
    // 0x8080027C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800280: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800284: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080028C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800290: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800294: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800298: jal         0x8010CEF8
    // 0x8080029C: nop

    func_8010CEF8(rdram, ctx);
        goto after_9;
    // 0x8080029C: nop

    after_9:
    // 0x808002A0: beql        $v0, $zero, L_808002D0
    if (ctx->r2 == 0) {
        // 0x808002A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002D0;
    }
    goto skip_0;
    // 0x808002A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x808002A8: jal         0x800F54E4
    // 0x808002AC: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x808002AC: nop

    after_10:
    // 0x808002B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808002B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808002BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808002C0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808002C4: jal         0x800F7A7C
    // 0x808002C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800F7A7C(rdram, ctx);
        goto after_11;
    // 0x808002C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_11:
    // 0x808002CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808002D0:
    // 0x808002D0: jal         0x80107070
    // 0x808002D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_12;
    // 0x808002D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808002D8: bnel        $v0, $zero, L_808002EC
    if (ctx->r2 != 0) {
        // 0x808002DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002EC;
    }
    goto skip_1;
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002E0: jal         0x800FFAB0
    // 0x808002E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x808002E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x808002E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002EC:
    // 0x808002EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808002F4: jr          $ra
    // 0x808002F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808002F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808000A0_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808000A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808000AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808000C8: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_808000CC:
    // 0x808000CC: lbu         $t7, 0x114($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X114);
    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808000D8: blezl       $t7, L_80800108
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808000DC: sb          $zero, 0x114($s0)
        MEM_B(0X114, ctx->r16) = 0;
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000DC: sb          $zero, 0x114($s0)
    MEM_B(0X114, ctx->r16) = 0;
    skip_0:
    // 0x808000E0: lw          $t8, 0x104($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X104);
L_808000E4:
    // 0x808000E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808000E8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x808000EC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x808000F0: lbu         $t0, 0x114($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X114);
    // 0x808000F4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x808000F8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808000FC: bnel        $at, $zero, L_808000E4
    if (ctx->r1 != 0) {
        // 0x80800100: lw          $t8, 0x104($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X104);
            goto L_808000E4;
    }
    goto skip_1;
    // 0x80800100: lw          $t8, 0x104($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X104);
    skip_1:
    // 0x80800104: sb          $zero, 0x114($s0)
    MEM_B(0X114, ctx->r16) = 0;
L_80800108:
    // 0x80800108: jal         0x8001B084
    // 0x8080010C: lw          $a0, 0x104($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X104);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x8080010C: lw          $a0, 0x104($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X104);
    after_0:
    // 0x80800110: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800114: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800118: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080011C: bne         $s2, $s3, L_808000CC
    if (ctx->r18 != ctx->r19) {
        // 0x80800120: sw          $zero, 0x100($s1)
        MEM_W(0X100, ctx->r17) = 0;
            goto L_808000CC;
    }
    // 0x80800120: sw          $zero, 0x100($s1)
    MEM_W(0X100, ctx->r17) = 0;
    // 0x80800124: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800128: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080012C: lh          $a0, 0x162($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X162);
    // 0x80800130: beql        $a0, $at, L_80800144
    if (ctx->r4 == ctx->r1) {
        // 0x80800134: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800144;
    }
    goto skip_2;
    // 0x80800134: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800138: jal         0x80088758
    // 0x8080013C: nop

    _gldialog_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080013C: nop

    after_1:
    // 0x80800140: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_80800144:
    // 0x80800144: sw          $zero, 0x100($t2)
    MEM_W(0X100, ctx->r10) = 0;
    // 0x80800148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800150: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800154: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800158: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: jr          $ra
    // 0x80800160: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800160: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void fxstep_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800674: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800678: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080067C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800680: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80800684: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x80800688: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080068C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800690: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80800694: jal         0x80800754
    // 0x80800698: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    fxstep_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80800698: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8080069C: beql        $v0, $zero, L_80800744
    if (ctx->r2 == 0) {
        // 0x808006A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800744;
    }
    goto skip_0;
    // 0x808006A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808006A4: jal         0x800C2E04
    // 0x808006A8: nop

    func_800C2E04(rdram, ctx);
        goto after_1;
    // 0x808006A8: nop

    after_1:
    // 0x808006AC: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x808006B0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808006B4: jal         0x800C330C
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808006BC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808006C0: jal         0x800C35E8
    // 0x808006C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800C35E8(rdram, ctx);
        goto after_3;
    // 0x808006C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x808006C8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808006CC: jal         0x800C301C
    // 0x808006D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800C301C(rdram, ctx);
        goto after_4;
    // 0x808006D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x808006D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2830, 0X820) << 16);
    // 0x808006D8: lwc1        $f12, 0x820($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2830, 0X820));
    // 0x808006DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2830, 0X824) << 16);
    // 0x808006E0: jal         0x800DC178
    // 0x808006E4: lwc1        $f14, 0x824($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2830, 0X824));
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808006E4: lwc1        $f14, 0x824($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2830, 0X824));
    after_5:
    // 0x808006E8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808006EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x808006F0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808006F4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808006F8: jal         0x800C31DC
    // 0x808006FC: nop

    func_800C31DC(rdram, ctx);
        goto after_6;
    // 0x808006FC: nop

    after_6:
    // 0x80800700: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800704: jal         0x800C3058
    // 0x80800708: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800C3058(rdram, ctx);
        goto after_7;
    // 0x80800708: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x8080070C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80800710: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800714: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80800718: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8080071C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80800720: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800724: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800728: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080072C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800730: jal         0x800C3584
    // 0x80800734: nop

    func_800C3584(rdram, ctx);
        goto after_8;
    // 0x80800734: nop

    after_8:
    // 0x80800738: jal         0x800C3BDC
    // 0x8080073C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_9;
    // 0x8080073C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_9:
    // 0x80800740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800744:
    // 0x80800744: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800748: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080074C: jr          $ra
    // 0x80800750: nop

    return;
    // 0x80800750: nop

;}
RECOMP_FUNC void func_808009B8_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C0: jal         0x800EA05C
    // 0x808009C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808009C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009C8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x808009CC: lh          $t6, 0xBC0($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x808009D0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808009D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808009D8: beq         $v0, $t6, L_808009F0
    if (ctx->r2 == ctx->r14) {
        // 0x808009DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009F0;
    }
    // 0x808009DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009E0: bne         $a2, $zero, L_808009F0
    if (ctx->r6 != 0) {
        // 0x808009E4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808009F0;
    }
    // 0x808009E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808009E8: b           L_80800A84
    // 0x808009EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A84;
    // 0x808009EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009F0:
    // 0x808009F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009F4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x808009F8: addiu       $t8, $t8, 0xBC0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x808009FC: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80800A00: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80800A04: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80800A08: beql        $v0, $t9, L_80800A28
    if (ctx->r2 == ctx->r25) {
        // 0x80800A0C: lh          $t0, 0x8($a0)
        ctx->r8 = MEM_H(ctx->r4, 0X8);
            goto L_80800A28;
    }
    goto skip_0;
    // 0x80800A0C: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    skip_0:
    // 0x80800A10: bnel        $a2, $v1, L_80800A24
    if (ctx->r6 != ctx->r3) {
        // 0x80800A14: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800A24;
    }
    goto skip_1;
    // 0x80800A14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80800A18: b           L_80800A84
    // 0x80800A1C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80800A84;
    // 0x80800A1C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80800A20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800A24:
    // 0x80800A24: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
L_80800A28:
    // 0x80800A28: beql        $v0, $t0, L_80800A48
    if (ctx->r2 == ctx->r8) {
        // 0x80800A2C: lh          $t1, 0x10($a0)
        ctx->r9 = MEM_H(ctx->r4, 0X10);
            goto L_80800A48;
    }
    goto skip_2;
    // 0x80800A2C: lh          $t1, 0x10($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X10);
    skip_2:
    // 0x80800A30: bnel        $a2, $v1, L_80800A44
    if (ctx->r6 != ctx->r3) {
        // 0x80800A34: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800A44;
    }
    goto skip_3;
    // 0x80800A34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x80800A38: b           L_80800A84
    // 0x80800A3C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_80800A84;
    // 0x80800A3C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80800A40: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800A44:
    // 0x80800A44: lh          $t1, 0x10($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X10);
L_80800A48:
    // 0x80800A48: beql        $v0, $t1, L_80800A68
    if (ctx->r2 == ctx->r9) {
        // 0x80800A4C: lh          $t2, 0x18($a0)
        ctx->r10 = MEM_H(ctx->r4, 0X18);
            goto L_80800A68;
    }
    goto skip_4;
    // 0x80800A4C: lh          $t2, 0x18($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X18);
    skip_4:
    // 0x80800A50: bnel        $a2, $v1, L_80800A64
    if (ctx->r6 != ctx->r3) {
        // 0x80800A54: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800A64;
    }
    goto skip_5;
    // 0x80800A54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x80800A58: b           L_80800A84
    // 0x80800A5C: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
        goto L_80800A84;
    // 0x80800A5C: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    // 0x80800A60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800A64:
    // 0x80800A64: lh          $t2, 0x18($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X18);
L_80800A68:
    // 0x80800A68: beql        $v0, $t2, L_80800A84
    if (ctx->r2 == ctx->r10) {
        // 0x80800A6C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800A84;
    }
    goto skip_6;
    // 0x80800A6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_6:
    // 0x80800A70: bnel        $a2, $v1, L_80800A84
    if (ctx->r6 != ctx->r3) {
        // 0x80800A74: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800A84;
    }
    goto skip_7;
    // 0x80800A74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_7:
    // 0x80800A78: b           L_80800A84
    // 0x80800A7C: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
        goto L_80800A84;
    // 0x80800A7C: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
    // 0x80800A80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800A84:
    // 0x80800A84: jr          $ra
    // 0x80800A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chclinker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2208, 0X1550) << 16);
    // 0x80800FF4: jr          $ra
    // 0x80800FF8: addiu       $v0, $v0, 0x1550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2208, 0X1550));
    return;
    // 0x80800FF8: addiu       $v0, $v0, 0x1550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2208, 0X1550));
;}
RECOMP_FUNC void _bsbtrot_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C88: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C88);
    return;
    // 0x80082C8C: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void bstrexlarge_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010FC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801100: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X1A00) << 16);
    // 0x80801104: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801108: jr          $ra
    // 0x8080110C: lw          $v0, 0x1A00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A00));
    return;
    // 0x8080110C: lw          $v0, 0x1A00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A00));
;}
RECOMP_FUNC void func_80800670_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800674: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800678: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080067C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80800680: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800684: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800688: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080068C: jal         0x800EE7F8
    // 0x80800690: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800690: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800694: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800698: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080069C: jal         0x800EF1B8
    // 0x808006A0: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808006A0: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_1:
    // 0x808006A4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808006A8: sltiu       $at, $v1, 0x8
    ctx->r1 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x808006AC: beq         $at, $zero, L_80800770
    if (ctx->r1 == 0) {
        // 0x808006B0: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_80800770;
    }
    // 0x808006B0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x808006B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(916, 0XABC) << 16);
    // 0x808006B8: addu        $at, $at, $t7
    gpr jr_addend_808006C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808006BC: lw          $t7, 0xABC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(916, 0XABC));
    // 0x808006C0: jr          $t7
    // 0x808006C4: nop

    switch (jr_addend_808006C0 >> 2) {
        case 0: goto L_808006C8; break;
        case 1: goto L_808006FC; break;
        case 2: goto L_808006FC; break;
        case 3: goto L_808006FC; break;
        case 4: goto L_808006FC; break;
        case 5: goto L_808006FC; break;
        case 6: goto L_80800730; break;
        case 7: goto L_80800754; break;
        default: switch_error(__func__, 0x808006C0, 0x80800ABC);
    }
    // 0x808006C4: nop

L_808006C8:
    // 0x808006C8: jal         0x800D3EF4
    // 0x808006CC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800D3EF4(rdram, ctx);
        goto after_2;
    // 0x808006CC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x808006D0: jal         0x800FC660
    // 0x808006D4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x808006D4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x808006D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006DC: addiu       $t8, $zero, 0x43
    ctx->r24 = ADD32(0, 0X43);
    // 0x808006E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808006E4: addiu       $a1, $zero, 0x10A9
    ctx->r5 = ADD32(0, 0X10A9);
    // 0x808006E8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006EC: jal         0x8008A208
    // 0x808006F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808006F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x808006F4: b           L_80800774
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800774;
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006FC:
    // 0x808006FC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80800700: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80800704: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(916, 0XAF0) << 16);
    // 0x80800708: addiu       $t0, $t0, 0xAF0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(916, 0XAF0));
    // 0x8080070C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800710: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80800714: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80800718: jal         0x800D175C
    // 0x8080071C: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    func_800D175C(rdram, ctx);
        goto after_5;
    // 0x8080071C: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    after_5:
    // 0x80800720: jal         0x808002BC
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002BC_chmadamegrunty(rdram, ctx);
        goto after_6;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800728: b           L_80800774
    // 0x8080072C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800774;
    // 0x8080072C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800730:
    // 0x80800730: jal         0x800F54E4
    // 0x80800734: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800734: nop

    after_7:
    // 0x80800738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080073C: jal         0x800F4924
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F4924(rdram, ctx);
        goto after_8;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800744: jal         0x808002BC
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002BC_chmadamegrunty(rdram, ctx);
        goto after_9;
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080074C: b           L_80800774
    // 0x80800750: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800774;
    // 0x80800750: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800754:
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80101FDC
    // 0x8080075C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x8080075C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80800760: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800764: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800768: nop

    // 0x8080076C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800770:
    // 0x80800770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800774:
    // 0x80800774: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080077C: jr          $ra
    // 0x80800780: nop

    return;
    // 0x80800780: nop

;}
RECOMP_FUNC void func_80803724_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803724: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80803728: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080372C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80803730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803734: jal         0x80100094
    // 0x80803738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080373C: jal         0x800D8FF8
    // 0x80803740: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80803740: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x80803744: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80803748: jal         0x80106790
    // 0x8080374C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x8080374C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80803750: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80803754: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80803758: jal         0x800BD2D0
    // 0x8080375C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BD2D0(rdram, ctx);
        goto after_3;
    // 0x8080375C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x80803760: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80803764: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80803768: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8080376C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80803770: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x80803774: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80803778: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080377C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80803780: sltiu       $at, $t0, 0xC
    ctx->r1 = ctx->r8 < 0XC ? 1 : 0;
    // 0x80803784: beq         $at, $zero, L_80803F68
    if (ctx->r1 == 0) {
        // 0x80803788: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80803F68;
    }
    // 0x80803788: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8080378C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F58) << 16);
    // 0x80803790: addu        $at, $at, $t0
    gpr jr_addend_80803798 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80803794: lw          $t0, 0x4F58($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F58));
    // 0x80803798: jr          $t0
    // 0x8080379C: nop

    switch (jr_addend_80803798 >> 2) {
        case 0: goto L_80803C18; break;
        case 1: goto L_80803B30; break;
        case 2: goto L_80803C9C; break;
        case 3: goto L_80803CE8; break;
        case 4: goto L_80803E18; break;
        case 5: goto L_80803E3C; break;
        case 6: goto L_80803E78; break;
        case 7: goto L_808038F8; break;
        case 8: goto L_80803EDC; break;
        case 9: goto L_808037A0; break;
        case 10: goto L_80803F68; break;
        case 11: goto L_80803AA4; break;
        default: switch_error(__func__, 0x80803798, 0x80804F58);
    }
    // 0x8080379C: nop

L_808037A0:
    // 0x808037A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808037A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037A8: jal         0x80089BC0
    // 0x808037AC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808037AC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x808037B0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808037B4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808037B8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808037BC: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x808037C0: jal         0x80089AF8
    // 0x808037C4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808037C4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_5:
    // 0x808037C8: beq         $v0, $zero, L_808037F8
    if (ctx->r2 == 0) {
        // 0x808037CC: nop
    
            goto L_808037F8;
    }
    // 0x808037CC: nop

    // 0x808037D0: jal         0x80800070
    // 0x808037D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800070_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x808037D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808037D8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808037DC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808037E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808037E4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808037E8: jal         0x800F10B4
    // 0x808037EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808037EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x808037F0: b           L_8080381C
    // 0x808037F4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_8080381C;
    // 0x808037F4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808037F8:
    // 0x808037F8: jal         0x80800040
    // 0x808037FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_8;
    // 0x808037FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80803800: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803804: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803808: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080380C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803810: jal         0x800F10B4
    // 0x80803814: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80803814: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x80803818: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8080381C:
    // 0x8080381C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803820: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803824: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x80803828: jal         0x80089AF8
    // 0x8080382C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x8080382C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_10:
    // 0x80803830: beq         $v0, $zero, L_808038A4
    if (ctx->r2 == 0) {
        // 0x80803834: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_808038A4;
    }
    // 0x80803834: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80803838: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8080383C: jal         0x800BCFC4
    // 0x80803840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BCFC4(rdram, ctx);
        goto after_11;
    // 0x80803840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80803844: beq         $v0, $zero, L_808038A4
    if (ctx->r2 == 0) {
        // 0x80803848: lw          $t4, 0x64($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X64);
            goto L_808038A4;
    }
    // 0x80803848: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8080384C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80803850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803854: jal         0x800BCD78
    // 0x80803858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800BCD78(rdram, ctx);
        goto after_12;
    // 0x80803858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8080385C: jal         0x800D8FF8
    // 0x80803860: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x80803860: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_13:
    // 0x80803864: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80803868: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8080386C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803870: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80803874: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803878: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080387C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80803880: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x80803884: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80803888: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080388C: jal         0x800F10B4
    // 0x80803890: nop

    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80803890: nop

    after_14:
    // 0x80803894: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80803898: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8080389C: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808038A0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808038A4:
    // 0x808038A4: jal         0x80804B60
    // 0x808038A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804B60_chstoneballcontrol(rdram, ctx);
        goto after_15;
    // 0x808038A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808038AC: jal         0x8080009C
    // 0x808038B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_16;
    // 0x808038B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808038B4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808038B8: jal         0x80800040
    // 0x808038BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_17;
    // 0x808038BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808038C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808038C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038C8: jal         0x80089AA8
    // 0x808038CC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x808038CC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_18:
    // 0x808038D0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x808038D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808038D8: jal         0x800BD030
    // 0x808038DC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800BD030(rdram, ctx);
        goto after_19;
    // 0x808038DC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_19:
    // 0x808038E0: beq         $v0, $zero, L_80803F68
    if (ctx->r2 == 0) {
        // 0x808038E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F68;
    }
    // 0x808038E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038E8: jal         0x80800B4C
    // 0x808038EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_20;
    // 0x808038EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x808038F0: b           L_80803F6C
    // 0x808038F4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x808038F4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_808038F8:
    // 0x808038F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808038FC: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80803900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803904: lui         $a1, 0x3E9D
    ctx->r5 = S32(0X3E9D << 16);
    // 0x80803908: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8080390C: nop

    // 0x80803910: bc1fl       L_808039A4
    if (!c1cs) {
        // 0x80803914: c.eq.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
            goto L_808039A4;
    }
    goto skip_0;
    // 0x80803914: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    skip_0:
    // 0x80803918: jal         0x80101E14
    // 0x8080391C: ori         $a1, $a1, 0x8ADB
    ctx->r5 = ctx->r5 | 0X8ADB;
    func_80101E14(rdram, ctx);
        goto after_21;
    // 0x8080391C: ori         $a1, $a1, 0x8ADB
    ctx->r5 = ctx->r5 | 0X8ADB;
    after_21:
    // 0x80803920: beql        $v0, $zero, L_80803998
    if (ctx->r2 == 0) {
        // 0x80803924: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80803998;
    }
    goto skip_1;
    // 0x80803924: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_1:
    // 0x80803928: jal         0x80104248
    // 0x8080392C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_22;
    // 0x8080392C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80803930: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803934: jal         0x8008B134
    // 0x80803938: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_23;
    // 0x80803938: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_23:
    // 0x8080393C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803944: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F88) << 16);
    // 0x80803948: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080394C: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80803950: lwc1        $f6, 0x4F88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F88));
    // 0x80803954: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80803958: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080395C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x80803960: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1608, 0X5418) << 16);
    // 0x80803964: addiu       $t0, $zero, 0x7D
    ctx->r8 = ADD32(0, 0X7D);
    // 0x80803968: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x8080396C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80803970: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80803974: addiu       $a2, $a2, 0x5418
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1608, 0X5418));
    // 0x80803978: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8080397C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803984: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80803988: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8080398C: jal         0x800B4470
    // 0x80803990: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800B4470(rdram, ctx);
        goto after_24;
    // 0x80803990: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x80803994: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80803998:
    // 0x80803998: b           L_80803A24
    // 0x8080399C: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80803A24;
    // 0x8080399C: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808039A0: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
L_808039A4:
    // 0x808039A4: nop

    // 0x808039A8: bc1tl       L_80803A28
    if (c1cs) {
        // 0x808039AC: lwc1        $f16, 0x24($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80803A28;
    }
    goto skip_2;
    // 0x808039AC: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x808039B0: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808039B4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808039B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808039BC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808039C0: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x808039C4: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808039C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039CC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808039D0: nop

    // 0x808039D4: bc1t        L_808039F8
    if (c1cs) {
        // 0x808039D8: nop
    
            goto L_808039F8;
    }
    // 0x808039D8: nop

    // 0x808039DC: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808039E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808039E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F8C) << 16);
    // 0x808039E8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808039EC: nop

    // 0x808039F0: bc1f        L_80803A18
    if (!c1cs) {
        // 0x808039F4: nop
    
            goto L_80803A18;
    }
    // 0x808039F4: nop

L_808039F8:
    // 0x808039F8: jal         0x80800B4C
    // 0x808039FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_25;
    // 0x808039FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x80803A00: jal         0x8080009C
    // 0x80803A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_26;
    // 0x80803A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80803A08: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803A0C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80803A10: b           L_80803A24
    // 0x80803A14: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80803A24;
    // 0x80803A14: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
L_80803A18:
    // 0x80803A18: lwc1        $f8, 0x4F8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F8C));
    // 0x80803A1C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80803A20: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80803A24:
    // 0x80803A24: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
L_80803A28:
    // 0x80803A28: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
    // 0x80803A2C: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x80803A30: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80803A34: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80803A38: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80803A3C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80803A40: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80803A44: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80803A48: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80803A4C: jal         0x800EEB9C
    // 0x80803A50: nop

    func_800EEB9C(rdram, ctx);
        goto after_27;
    // 0x80803A50: nop

    after_27:
    // 0x80803A54: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80803A58: jal         0x800EF04C
    // 0x80803A5C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800EF04C(rdram, ctx);
        goto after_28;
    // 0x80803A5C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_28:
    // 0x80803A60: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80803A64: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80803A68: bgez        $t5, L_80803A94
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80803A6C: nop
    
            goto L_80803A94;
    }
    // 0x80803A6C: nop

    // 0x80803A70: jal         0x80089BC0
    // 0x80803A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x80803A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80803A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A7C: jal         0x80102CF4
    // 0x80803A80: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_30;
    // 0x80803A80: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_30:
    // 0x80803A84: bne         $v0, $zero, L_80803A94
    if (ctx->r2 != 0) {
        // 0x80803A88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803A94;
    }
    // 0x80803A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A8C: jal         0x80102B2C
    // 0x80803A90: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102B2C(rdram, ctx);
        goto after_31;
    // 0x80803A90: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_31:
L_80803A94:
    // 0x80803A94: jal         0x80804304
    // 0x80803A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804304_chstoneballcontrol(rdram, ctx);
        goto after_32;
    // 0x80803A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80803A9C: b           L_80803F6C
    // 0x80803AA0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803AA0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803AA4:
    // 0x80803AA4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803AA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803AAC: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F90) << 16);
    // 0x80803AB8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80803ABC: nop

    // 0x80803AC0: bc1f        L_80803AE4
    if (!c1cs) {
        // 0x80803AC4: nop
    
            goto L_80803AE4;
    }
    // 0x80803AC4: nop

    // 0x80803AC8: jal         0x80800B4C
    // 0x80803ACC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_33;
    // 0x80803ACC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x80803AD0: jal         0x8080009C
    // 0x80803AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_34;
    // 0x80803AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80803AD8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803ADC: b           L_80803AF0
    // 0x80803AE0: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80803AF0;
    // 0x80803AE0: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
L_80803AE4:
    // 0x80803AE4: lwc1        $f6, 0x4F90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F90));
    // 0x80803AE8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803AEC: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80803AF0:
    // 0x80803AF0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803AF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803AF8: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x80803AFC: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80803B00: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80803B04: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80803B08: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80803B0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80803B10: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80803B14: jal         0x800EEB9C
    // 0x80803B18: nop

    func_800EEB9C(rdram, ctx);
        goto after_35;
    // 0x80803B18: nop

    after_35:
    // 0x80803B1C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80803B20: jal         0x800EF04C
    // 0x80803B24: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_36;
    // 0x80803B24: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_36:
    // 0x80803B28: b           L_80803F6C
    // 0x80803B2C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803B2C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803B30:
    // 0x80803B30: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80803B34: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80803B38: bgez        $t8, L_80803B58
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80803B3C: nop
    
            goto L_80803B58;
    }
    // 0x80803B3C: nop

    // 0x80803B40: lbu         $t9, 0x72($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X72);
    // 0x80803B44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803B48: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80803B4C: ori         $t1, $t0, 0x28
    ctx->r9 = ctx->r8 | 0X28;
    // 0x80803B50: sb          $t1, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r9;
    // 0x80803B54: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80803B58:
    // 0x80803B58: jal         0x80804810
    // 0x80803B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804810_chstoneballcontrol(rdram, ctx);
        goto after_37;
    // 0x80803B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80803B60: bne         $v0, $zero, L_80803B70
    if (ctx->r2 != 0) {
        // 0x80803B64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803B70;
    }
    // 0x80803B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B68: jal         0x80800B4C
    // 0x80803B6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_38;
    // 0x80803B6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
L_80803B70:
    // 0x80803B70: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803B74: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803B78: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x80803B7C: jal         0x80089AF8
    // 0x80803B80: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_39;
    // 0x80803B80: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_39:
    // 0x80803B84: beq         $v0, $zero, L_80803BE4
    if (ctx->r2 == 0) {
        // 0x80803B88: nop
    
            goto L_80803BE4;
    }
    // 0x80803B88: nop

    // 0x80803B8C: jal         0x800DC0C0
    // 0x80803B90: nop

    func_800DC0C0(rdram, ctx);
        goto after_40;
    // 0x80803B90: nop

    after_40:
    // 0x80803B94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F94) << 16);
    // 0x80803B98: lwc1        $f6, 0x4F94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F94));
    // 0x80803B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BA0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80803BA4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80803BA8: nop

    // 0x80803BAC: bc1fl       L_80803BC8
    if (!c1cs) {
        // 0x80803BB0: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80803BC8;
    }
    goto skip_3;
    // 0x80803BB0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_3:
    // 0x80803BB4: jal         0x80800B4C
    // 0x80803BB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_41;
    // 0x80803BB8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_41:
    // 0x80803BBC: b           L_80803BE4
    // 0x80803BC0: nop

        goto L_80803BE4;
    // 0x80803BC0: nop

    // 0x80803BC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80803BC8:
    // 0x80803BC8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803BCC: jal         0x800DC178
    // 0x80803BD0: nop

    func_800DC178(rdram, ctx);
        goto after_42;
    // 0x80803BD0: nop

    after_42:
    // 0x80803BD4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80803BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BDC: jal         0x80800B4C
    // 0x80803BE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_43;
    // 0x80803BE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_43:
L_80803BE4:
    // 0x80803BE4: jal         0x80804B60
    // 0x80803BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804B60_chstoneballcontrol(rdram, ctx);
        goto after_44;
    // 0x80803BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80803BEC: jal         0x8080009C
    // 0x80803BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_45;
    // 0x80803BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80803BF4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803BF8: jal         0x80800040
    // 0x80803BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_46;
    // 0x80803BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80803C00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C08: jal         0x80089AA8
    // 0x80803C0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_47;
    // 0x80803C0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_47:
    // 0x80803C10: b           L_80803F6C
    // 0x80803C14: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803C14: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803C18:
    // 0x80803C18: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803C1C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80803C20: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803C24: andi        $t3, $a0, 0x1FF
    ctx->r11 = ctx->r4 & 0X1FF;
    // 0x80803C28: jal         0x80089B18
    // 0x80803C2C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_48;
    // 0x80803C2C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_48:
    // 0x80803C30: jal         0x80804B60
    // 0x80803C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804B60_chstoneballcontrol(rdram, ctx);
        goto after_49;
    // 0x80803C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80803C38: jal         0x8080009C
    // 0x80803C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_50;
    // 0x80803C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80803C40: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803C44: jal         0x80800040
    // 0x80803C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_51;
    // 0x80803C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80803C4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C54: jal         0x80089AA8
    // 0x80803C58: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x80803C58: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_52:
    // 0x80803C5C: jal         0x80804810
    // 0x80803C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804810_chstoneballcontrol(rdram, ctx);
        goto after_53;
    // 0x80803C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80803C64: beq         $v0, $zero, L_80803C74
    if (ctx->r2 == 0) {
        // 0x80803C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803C74;
    }
    // 0x80803C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C6C: jal         0x80800B4C
    // 0x80803C70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_54;
    // 0x80803C70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_54:
L_80803C74:
    // 0x80803C74: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803C78: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80803C7C: jal         0x800EFFB4
    // 0x80803C80: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800EFFB4(rdram, ctx);
        goto after_55;
    // 0x80803C80: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_55:
    // 0x80803C84: beq         $v0, $zero, L_80803F68
    if (ctx->r2 == 0) {
        // 0x80803C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F68;
    }
    // 0x80803C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C8C: jal         0x80800B4C
    // 0x80803C90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_56;
    // 0x80803C90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_56:
    // 0x80803C94: b           L_80803F6C
    // 0x80803C98: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803C98: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803C9C:
    // 0x80803C9C: jal         0x80804810
    // 0x80803CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804810_chstoneballcontrol(rdram, ctx);
        goto after_57;
    // 0x80803CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80803CA4: beq         $v0, $zero, L_80803CB4
    if (ctx->r2 == 0) {
        // 0x80803CA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803CB4;
    }
    // 0x80803CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CAC: jal         0x80800B4C
    // 0x80803CB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_58;
    // 0x80803CB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_58:
L_80803CB4:
    // 0x80803CB4: jal         0x80089B08
    // 0x80803CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_14(rdram, ctx);
        goto after_59;
    // 0x80803CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80803CBC: jal         0x8080009C
    // 0x80803CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_60;
    // 0x80803CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80803CC4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803CC8: jal         0x80800040
    // 0x80803CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_61;
    // 0x80803CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80803CD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CD8: jal         0x80089AA8
    // 0x80803CDC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_62;
    // 0x80803CDC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_62:
    // 0x80803CE0: b           L_80803F6C
    // 0x80803CE4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803CE4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803CE8:
    // 0x80803CE8: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1608, 0X540C) << 16);
    // 0x80803CEC: addiu       $t5, $t5, 0x540C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1608, 0X540C));
    // 0x80803CF0: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80803CF4: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x80803CF8: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80803CFC: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80803D00: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80803D04: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80803D08: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80803D0C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80803D10: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803D14: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80803D18: nop

    // 0x80803D1C: bc1fl       L_80803D34
    if (!c1cs) {
        // 0x80803D20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803D34;
    }
    goto skip_4;
    // 0x80803D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80803D24: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80803D28: b           L_80803D3C
    // 0x80803D2C: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
        goto L_80803D3C;
    // 0x80803D2C: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x80803D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803D34:
    // 0x80803D34: jal         0x80800B4C
    // 0x80803D38: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_63;
    // 0x80803D38: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_63:
L_80803D3C:
    // 0x80803D3C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803D40: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803D44: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x80803D48: jal         0x80089AF8
    // 0x80803D4C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_64;
    // 0x80803D4C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_64:
    // 0x80803D50: bne         $v0, $zero, L_80803D60
    if (ctx->r2 != 0) {
        // 0x80803D54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803D60;
    }
    // 0x80803D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D58: jal         0x80800B4C
    // 0x80803D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_65;
    // 0x80803D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_65:
L_80803D60:
    // 0x80803D60: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803D64: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80803D68: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803D6C: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80803D70: jal         0x80089B18
    // 0x80803D74: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_66;
    // 0x80803D74: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_66:
    // 0x80803D78: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803D7C: andi        $t1, $a0, 0x1FF
    ctx->r9 = ctx->r4 & 0X1FF;
    // 0x80803D80: jal         0x80089B10
    // 0x80803D84: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    _sukickball_entrypoint_15(rdram, ctx);
        goto after_67;
    // 0x80803D84: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_67:
    // 0x80803D88: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80803D8C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80803D90: jal         0x800EFCD8
    // 0x80803D94: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    func_800EFCD8(rdram, ctx);
        goto after_68;
    // 0x80803D94: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    after_68:
    // 0x80803D98: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80803D9C: jal         0x800EF04C
    // 0x80803DA0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EF04C(rdram, ctx);
        goto after_69;
    // 0x80803DA0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_69:
    // 0x80803DA4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803DA8: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80803DAC: jal         0x800F0064
    // 0x80803DB0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800F0064(rdram, ctx);
        goto after_70;
    // 0x80803DB0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_70:
    // 0x80803DB4: bnel        $v0, $zero, L_80803DDC
    if (ctx->r2 != 0) {
        // 0x80803DB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DDC;
    }
    goto skip_5;
    // 0x80803DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80803DBC: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803DC0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803DC4: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x80803DC8: jal         0x80089AF8
    // 0x80803DCC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_71;
    // 0x80803DCC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_71:
    // 0x80803DD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803DD4: bne         $v0, $at, L_80803DE4
    if (ctx->r2 != ctx->r1) {
        // 0x80803DD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DE4;
    }
    // 0x80803DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803DDC:
    // 0x80803DDC: jal         0x80800B4C
    // 0x80803DE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_72;
    // 0x80803DE0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_72:
L_80803DE4:
    // 0x80803DE4: jal         0x80804B60
    // 0x80803DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804B60_chstoneballcontrol(rdram, ctx);
        goto after_73;
    // 0x80803DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x80803DEC: jal         0x8080009C
    // 0x80803DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_74;
    // 0x80803DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80803DF4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803DF8: jal         0x80800040
    // 0x80803DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_75;
    // 0x80803DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x80803E00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E08: jal         0x80089AA8
    // 0x80803E0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_76;
    // 0x80803E0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_76:
    // 0x80803E10: b           L_80803F6C
    // 0x80803E14: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803E14: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803E18:
    // 0x80803E18: jal         0x808040B8
    // 0x80803E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808040B8_chstoneballcontrol(rdram, ctx);
        goto after_77;
    // 0x80803E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80803E20: jal         0x80804218
    // 0x80803E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804218_chstoneballcontrol(rdram, ctx);
        goto after_78;
    // 0x80803E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80803E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E2C: jal         0x80800B4C
    // 0x80803E30: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_79;
    // 0x80803E30: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_79:
    // 0x80803E34: b           L_80803F6C
    // 0x80803E38: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803E38: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803E3C:
    // 0x80803E3C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803E40: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803E44: andi        $t3, $a1, 0x1FF
    ctx->r11 = ctx->r5 & 0X1FF;
    // 0x80803E48: jal         0x80089AF8
    // 0x80803E4C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_80;
    // 0x80803E4C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_80:
    // 0x80803E50: beq         $v0, $zero, L_80803E68
    if (ctx->r2 == 0) {
        // 0x80803E54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803E68;
    }
    // 0x80803E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E58: jal         0x80804218
    // 0x80803E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804218_chstoneballcontrol(rdram, ctx);
        goto after_81;
    // 0x80803E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x80803E60: b           L_80803F6C
    // 0x80803E64: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803E64: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803E68:
    // 0x80803E68: jal         0x80800B4C
    // 0x80803E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_82;
    // 0x80803E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_82:
    // 0x80803E70: b           L_80803F6C
    // 0x80803E74: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803E74: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803E78:
    // 0x80803E78: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803E7C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80803E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E84: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80803E88: nop

    // 0x80803E8C: bc1f        L_80803EA0
    if (!c1cs) {
        // 0x80803E90: nop
    
            goto L_80803EA0;
    }
    // 0x80803E90: nop

    // 0x80803E94: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80803E98: b           L_80803EA8
    // 0x80803E9C: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
        goto L_80803EA8;
    // 0x80803E9C: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80803EA0:
    // 0x80803EA0: jal         0x80800B4C
    // 0x80803EA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_83;
    // 0x80803EA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_83:
L_80803EA8:
    // 0x80803EA8: jal         0x80804B60
    // 0x80803EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804B60_chstoneballcontrol(rdram, ctx);
        goto after_84;
    // 0x80803EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_84:
    // 0x80803EB0: jal         0x8080009C
    // 0x80803EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_85;
    // 0x80803EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x80803EB8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803EBC: jal         0x80800040
    // 0x80803EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_86;
    // 0x80803EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80803EC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803ECC: jal         0x80089AA8
    // 0x80803ED0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_87;
    // 0x80803ED0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_87:
    // 0x80803ED4: b           L_80803F6C
    // 0x80803ED8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803F6C;
    // 0x80803ED8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803EDC:
    // 0x80803EDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803EE0: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803EE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803EE8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803EEC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80803EF0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80803EF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803EF8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80803EFC: andi        $t6, $t7, 0xFFEF
    ctx->r14 = ctx->r15 & 0XFFEF;
    // 0x80803F00: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80803F04: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80803F08: bc1f        L_80803F24
    if (!c1cs) {
        // 0x80803F0C: swc1        $f8, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
            goto L_80803F24;
    }
    // 0x80803F0C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80803F10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F98) << 16);
    // 0x80803F14: lwc1        $f16, 0x4F98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F98));
    // 0x80803F18: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80803F1C: b           L_80803F68
    // 0x80803F20: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
        goto L_80803F68;
    // 0x80803F20: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80803F24:
    // 0x80803F24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80803F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803F2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F9C) << 16);
    // 0x80803F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F34: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80803F38: nop

    // 0x80803F3C: bc1f        L_80803F54
    if (!c1cs) {
        // 0x80803F40: nop
    
            goto L_80803F54;
    }
    // 0x80803F40: nop

    // 0x80803F44: lwc1        $f6, 0x4F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F9C));
    // 0x80803F48: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803F4C: b           L_80803F68
    // 0x80803F50: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
        goto L_80803F68;
    // 0x80803F50: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_80803F54:
    // 0x80803F54: jal         0x80800B4C
    // 0x80803F58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_88;
    // 0x80803F58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_88:
    // 0x80803F5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803F60: nop

    // 0x80803F64: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
L_80803F68:
    // 0x80803F68: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803F6C:
    // 0x80803F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F70: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80803F74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80803F78: jal         0x80089AC0
    // 0x80803F7C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    _sukickball_entrypoint_5(rdram, ctx);
        goto after_89;
    // 0x80803F7C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_89:
    // 0x80803F80: beq         $v0, $zero, L_80803FD4
    if (ctx->r2 == 0) {
        // 0x80803F84: lw          $a2, 0x3C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3C);
            goto L_80803FD4;
    }
    // 0x80803F84: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80803F88: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x80803F8C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80803F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F94: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x80803F98: bnel        $t5, $at, L_80803FB4
    if (ctx->r13 != ctx->r1) {
        // 0x80803F9C: lw          $t8, 0x64($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X64);
            goto L_80803FB4;
    }
    goto skip_6;
    // 0x80803F9C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x80803FA0: jal         0x80800B4C
    // 0x80803FA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_90;
    // 0x80803FA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_90:
    // 0x80803FA8: b           L_80803FE4
    // 0x80803FAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80803FE4;
    // 0x80803FAC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80803FB0: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
L_80803FB4:
    // 0x80803FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FB8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80803FBC: bltzl       $t0, L_80803FE4
    if (SIGNED(ctx->r8) < 0) {
        // 0x80803FC0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80803FE4;
    }
    goto skip_7;
    // 0x80803FC0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_7:
    // 0x80803FC4: jal         0x80800BCC
    // 0x80803FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800BCC_chstoneballcontrol(rdram, ctx);
        goto after_91;
    // 0x80803FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_91:
    // 0x80803FCC: b           L_80803FE4
    // 0x80803FD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80803FE4;
    // 0x80803FD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80803FD4:
    // 0x80803FD4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80803FD8: jal         0x800EE7F8
    // 0x80803FDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_92;
    // 0x80803FDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_92:
    // 0x80803FE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80803FE4:
    // 0x80803FE4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80803FE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80803FEC: jr          $ra
    // 0x80803FF0: nop

    return;
    // 0x80803FF0: nop

;}
RECOMP_FUNC void bsvanswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080095C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800960: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(431, 0X9C0) << 16);
    // 0x80800964: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800968: jr          $ra
    // 0x8080096C: lw          $v0, 0x9C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X9C0));
    return;
    // 0x8080096C: lw          $v0, 0x9C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(431, 0X9C0));
;}
RECOMP_FUNC void func_80800080_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: jal         0x80084FE0
    // 0x8080008C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080008C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800090: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: jal         0x800F40EC
    // 0x80800098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F40EC(rdram, ctx);
        goto after_1;
    // 0x80800098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080009C: beq         $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x808000A0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800130;
    }
    // 0x808000A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: jal         0x800A3274
    // 0x808000AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800A3274(rdram, ctx);
        goto after_2;
    // 0x808000AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808000B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B4: beq         $v0, $at, L_808000D0
    if (ctx->r2 == ctx->r1) {
        // 0x808000B8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000D0;
    }
    // 0x808000B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808000C0: beql        $v0, $at, L_8080010C
    if (ctx->r2 == ctx->r1) {
        // 0x808000C4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x808000C8: b           L_80800134
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800134;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D0:
    // 0x808000D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D4: beq         $v1, $at, L_808000F8
    if (ctx->r3 == ctx->r1) {
        // 0x808000D8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000F8;
    }
    // 0x808000D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E0: beq         $v1, $at, L_808000F8
    if (ctx->r3 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808000F8;
    }
    // 0x808000E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000E8: beq         $v1, $at, L_808000F8
    if (ctx->r3 == ctx->r1) {
        // 0x808000EC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808000F8;
    }
    // 0x808000EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000F0: bnel        $v1, $at, L_80800134
    if (ctx->r3 != ctx->r1) {
        // 0x808000F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800134;
    }
    goto skip_1;
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_808000F8:
    // 0x808000F8: jal         0x80085008
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800100: b           L_80800134
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800134;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8080010C:
    // 0x8080010C: beq         $v1, $at, L_80800128
    if (ctx->r3 == ctx->r1) {
        // 0x80800110: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800128;
    }
    // 0x80800110: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800118: beq         $v1, $at, L_80800128
    if (ctx->r3 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800128;
    }
    // 0x8080011C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800120: bnel        $v1, $at, L_80800134
    if (ctx->r3 != ctx->r1) {
        // 0x80800124: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800134;
    }
    goto skip_2;
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_80800128:
    // 0x80800128: jal         0x80085008
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_80800130:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800134:
    // 0x80800134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_8002645C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002645C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026464: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80026468: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002646C: jal         0x8002FEC0
    // 0x80026470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026474: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026478: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002647C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80026480: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80026484: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80026488: beq         $t8, $zero, L_800264C8
    if (ctx->r24 == 0) {
        // 0x8002648C: nop
    
            goto L_800264C8;
    }
    // 0x8002648C: nop

    // 0x80026490: jal         0x80020E74
    // 0x80026494: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x80026494: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80026498: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002649C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800264A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800264A4: jal         0x80031BF0
    // 0x800264A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    _bcopy(rdram, ctx);
        goto after_2;
    // 0x800264A8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x800264AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800264B0: jal         0x80020E40
    // 0x800264B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80020E40(rdram, ctx);
        goto after_3;
    // 0x800264B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x800264B8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800264BC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800264C0: b           L_800264D8
    // 0x800264C4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_800264D8;
    // 0x800264C4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_800264C8:
    // 0x800264C8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800264CC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800264D0: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x800264D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800264D8:
    // 0x800264D8: jal         0x8002FEC0
    // 0x800264DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x800264DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x800264E0: b           L_800264F0
    // 0x800264E4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_800264F0;
    // 0x800264E4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800264E8: b           L_800264F0
    // 0x800264EC: nop

        goto L_800264F0;
    // 0x800264EC: nop

L_800264F0:
    // 0x800264F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800264F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800264F8: jr          $ra
    // 0x800264FC: nop

    return;
    // 0x800264FC: nop

;}
RECOMP_FUNC void fxstep_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800430: jal         0x800C2FDC
    // 0x80800434: lbu         $a0, 0x24($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X24);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800434: lbu         $a0, 0x24($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X24);
    after_0:
    // 0x80800438: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080043C: jal         0x800C2FDC
    // 0x80800440: lbu         $a0, 0x25($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X25);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80800440: lbu         $a0, 0x25($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X25);
    after_1:
    // 0x80800444: jal         0x8001B084
    // 0x80800448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x80800448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800454: jr          $ra
    // 0x80800458: nop

    return;
    // 0x80800458: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(364, 0X710) << 16);
    // 0x808003F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003F8: jr          $ra
    // 0x808003FC: lw          $v0, 0x710($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X710));
    return;
    // 0x808003FC: lw          $v0, 0x710($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X710));
;}
RECOMP_FUNC void _chgoldfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087540: syscall     586
    recomp_syscall_handler(rdram, ctx, 0x80087540);
    return;
    // 0x80087544: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808056F8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808056F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808056FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805700: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80805704: jal         0x80100094
    // 0x80805708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080570C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80805710: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80805714: lbu         $t6, 0x25($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X25);
    // 0x80805718: beql        $t6, $zero, L_80805780
    if (ctx->r14 == 0) {
        // 0x8080571C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80805780;
    }
    goto skip_0;
    // 0x8080571C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80805720: jal         0x808026F8
    // 0x80805724: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808026F8_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80805724: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80805728: jal         0x80802248
    // 0x8080572C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x8080572C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80805730: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80805734: jal         0x800F6478
    // 0x80805738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_3;
    // 0x80805738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080573C: beql        $v0, $zero, L_80805770
    if (ctx->r2 == 0) {
        // 0x80805740: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80805770;
    }
    goto skip_1;
    // 0x80805740: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80805744: jal         0x800F8004
    // 0x80805748: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F8004(rdram, ctx);
        goto after_4;
    // 0x80805748: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8080574C: bne         $v0, $zero, L_8080576C
    if (ctx->r2 != 0) {
        // 0x80805750: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8080576C;
    }
    // 0x80805750: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80805754: jal         0x800D90A4
    // 0x80805758: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x80805758: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_5:
    // 0x8080575C: beq         $v0, $zero, L_8080577C
    if (ctx->r2 == 0) {
        // 0x80805760: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8080577C;
    }
    // 0x80805760: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80805764: b           L_8080577C
    // 0x80805768: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_8080577C;
    // 0x80805768: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8080576C:
    // 0x8080576C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80805770:
    // 0x80805770: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80805774: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80805778: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
L_8080577C:
    // 0x8080577C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80805780:
    // 0x80805780: jal         0x8010A5B0
    // 0x80805784: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8010A5B0(rdram, ctx);
        goto after_6;
    // 0x80805784: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80805788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080578C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80805790: jr          $ra
    // 0x80805794: nop

    return;
    // 0x80805794: nop

;}
RECOMP_FUNC void func_80800E10_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80800E14: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800E18: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    // 0x80800E1C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800E20: and         $a2, $a0, $at
    ctx->r6 = ctx->r4 & ctx->r1;
    // 0x80800E24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E28: srl         $t6, $a2, 16
    ctx->r14 = S32(U32(ctx->r6) >> 16);
    // 0x80800E2C: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x80800E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E38: beq         $t7, $zero, L_80800E70
    if (ctx->r15 == 0) {
        // 0x80800E3C: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80800E70;
    }
    // 0x80800E3C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800E40: srl         $a0, $a3, 2
    ctx->r4 = S32(U32(ctx->r7) >> 2);
    // 0x80800E44: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80800E48: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80800E4C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800E50: jal         0x8001E210
    // 0x80800E54: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x80800E54: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800E58: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E5C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800E60: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800E64: and         $t9, $s0, $at
    ctx->r25 = ctx->r16 & ctx->r1;
    // 0x80800E68: b           L_80800E90
    // 0x80800E6C: srl         $s0, $t9, 16
    ctx->r16 = S32(U32(ctx->r25) >> 16);
        goto L_80800E90;
    // 0x80800E6C: srl         $s0, $t9, 16
    ctx->r16 = S32(U32(ctx->r25) >> 16);
L_80800E70:
    // 0x80800E70: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800E74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800E78: jal         0x8001E210
    // 0x80800E7C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x80800E7C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800E80: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E84: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800E88: andi        $t1, $s0, 0xFFFF
    ctx->r9 = ctx->r16 & 0XFFFF;
    // 0x80800E8C: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_80800E90:
    // 0x80800E90: beq         $a2, $zero, L_80800EE4
    if (ctx->r6 == 0) {
        // 0x80800E94: lui         $at, 0xB000
        ctx->r1 = S32(0XB000 << 16);
            goto L_80800EE4;
    }
    // 0x80800E94: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800E98: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80800E9C: andi        $t2, $a2, 0x2
    ctx->r10 = ctx->r6 & 0X2;
    // 0x80800EA0: beq         $t2, $zero, L_80800ED0
    if (ctx->r10 == 0) {
        // 0x80800EA4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800ED0;
    }
    // 0x80800EA4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800EA8: srl         $t3, $a2, 2
    ctx->r11 = S32(U32(ctx->r6) >> 2);
    // 0x80800EAC: sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11 << 2);
    // 0x80800EB0: jal         0x8001E210
    // 0x80800EB4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    rom_read_word(rdram, ctx);
        goto after_2;
    // 0x80800EB4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800EB8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EBC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800EC0: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80800EC4: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80800EC8: b           L_80800EE4
    // 0x80800ECC: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
        goto L_80800EE4;
    // 0x80800ECC: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
L_80800ED0:
    // 0x80800ED0: jal         0x8001E210
    // 0x80800ED4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    rom_read_word(rdram, ctx);
        goto after_3;
    // 0x80800ED4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800ED8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EDC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80800EE0: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
L_80800EE4:
    // 0x80800EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EE8: addiu       $v0, $s0, 0xA0
    ctx->r2 = ADD32(ctx->r16, 0XA0);
    // 0x80800EEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EF0: jr          $ra
    // 0x80800EF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800EF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800FF060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF060: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800FF064: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800FF068: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800FF06C: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800FF070: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800FF074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FF078: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800FF07C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x800FF080: bc1f        L_800FF090
    if (!c1cs) {
        // 0x800FF084: sw          $a3, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r7;
            goto L_800FF090;
    }
    // 0x800FF084: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800FF088: b           L_800FF094
    // 0x800FF08C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800FF094;
    // 0x800FF08C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800FF090:
    // 0x800FF090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FF094:
    // 0x800FF094: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800FF098: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800FF09C: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800FF0A0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FF0A4: mul.s       $f22, $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x800FF0A8: nop

    // 0x800FF0AC: mul.s       $f20, $f6, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800FF0B0: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x800FF0B4: nop

    // 0x800FF0B8: bc1f        L_800FF130
    if (!c1cs) {
        // 0x800FF0BC: nop
    
            goto L_800FF130;
    }
    // 0x800FF0BC: nop

    // 0x800FF0C0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800FF0C4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800FF0C8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800FF0CC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800FF0D0: nop

    // 0x800FF0D4: bc1fl       L_800FF0E8
    if (!c1cs) {
        // 0x800FF0D8: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_800FF0E8;
    }
    goto skip_0;
    // 0x800FF0D8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    skip_0:
    // 0x800FF0DC: b           L_800FF0E8
    // 0x800FF0E0: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
        goto L_800FF0E8;
    // 0x800FF0E0: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    // 0x800FF0E4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_800FF0E8:
    // 0x800FF0E8: div.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800FF0EC: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800FF0F0: sub.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800FF0F4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800FF0F8: nop

    // 0x800FF0FC: bc1f        L_800FF108
    if (!c1cs) {
        // 0x800FF100: nop
    
            goto L_800FF108;
    }
    // 0x800FF100: nop

    // 0x800FF104: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_800FF108:
    // 0x800FF108: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800FF10C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FF110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FF114: add.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800FF118: add.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x800FF11C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800FF120: nop

    // 0x800FF124: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800FF128: b           L_800FF144
    // 0x800FF12C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
        goto L_800FF144;
    // 0x800FF12C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_800FF130:
    // 0x800FF130: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FF134: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800FF138: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800FF13C: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800FF140: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
L_800FF144:
    // 0x800FF144: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800FF148: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800FF14C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FF150: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FF154: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800FF158: sub.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x800FF15C: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800FF160: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800FF164: sub.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800FF168: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FF16C: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800FF170: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800FF174: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800FF178: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800FF17C: div.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800FF180: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800FF184: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x800FF188: bc1fl       L_800FF224
    if (!c1cs) {
        // 0x800FF18C: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_800FF224;
    }
    goto skip_1;
    // 0x800FF18C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    skip_1:
    // 0x800FF190: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FF194: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800FF198: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800FF19C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800FF1A0: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x800FF1A4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800FF1A8: jal         0x8002DCA0
    // 0x800FF1AC: add.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800FF1AC: add.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f4.fl;
    after_0:
    // 0x800FF1B0: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800FF1B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800FF1B8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800FF1BC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800FF1C0: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800FF1C4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800FF1C8: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800FF1CC: bc1fl       L_800FF1DC
    if (!c1cs) {
        // 0x800FF1D0: sub.s       $f10, $f2, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_800FF1DC;
    }
    goto skip_2;
    // 0x800FF1D0: sub.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f20.fl;
    skip_2:
    // 0x800FF1D4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x800FF1D8: sub.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f20.fl;
L_800FF1DC:
    // 0x800FF1DC: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800FF1E0: div.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800FF1E4: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800FF1E8: nop

    // 0x800FF1EC: bc1f        L_800FF1F8
    if (!c1cs) {
        // 0x800FF1F0: nop
    
            goto L_800FF1F8;
    }
    // 0x800FF1F0: nop

    // 0x800FF1F4: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_800FF1F8:
    // 0x800FF1F8: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800FF1FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FF200: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FF204: add.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800FF208: add.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x800FF20C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800FF210: nop

    // 0x800FF214: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800FF218: b           L_800FF22C
    // 0x800FF21C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
        goto L_800FF22C;
    // 0x800FF21C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x800FF220: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_800FF224:
    // 0x800FF224: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x800FF228: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
L_800FF22C:
    // 0x800FF22C: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x800FF230: nop

    // 0x800FF234: bc1fl       L_800FF258
    if (!c1cs) {
        // 0x800FF238: sub.s       $f16, $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f12.fl;
            goto L_800FF258;
    }
    goto skip_3;
    // 0x800FF238: sub.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f12.fl;
    skip_3:
    // 0x800FF23C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800FF240: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800FF244: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FF248: mul.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800FF24C: b           L_800FF37C
    // 0x800FF250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800FF37C;
    // 0x800FF250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FF254: sub.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f12.fl;
L_800FF258:
    // 0x800FF258: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800FF25C: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800FF260: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FF264: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800FF268: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800FF26C: sub.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x800FF270: bc1fl       L_800FF2DC
    if (!c1cs) {
        // 0x800FF274: swc1        $f18, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
            goto L_800FF2DC;
    }
    goto skip_4;
    // 0x800FF274: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    skip_4:
    // 0x800FF278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FF27C: nop

    // 0x800FF280: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800FF284: nop

    // 0x800FF288: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800FF28C: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800FF290: div.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800FF294: c.lt.s      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.fl < ctx->f22.fl;
    // 0x800FF298: nop

    // 0x800FF29C: bc1f        L_800FF2CC
    if (!c1cs) {
        // 0x800FF2A0: nop
    
            goto L_800FF2CC;
    }
    // 0x800FF2A0: nop

    // 0x800FF2A4: sub.s       $f10, $f22, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f14.fl;
    // 0x800FF2A8: div.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800FF2AC: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800FF2B0: nop

    // 0x800FF2B4: bc1f        L_800FF2C0
    if (!c1cs) {
        // 0x800FF2B8: nop
    
            goto L_800FF2C0;
    }
    // 0x800FF2B8: nop

    // 0x800FF2BC: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_800FF2C0:
    // 0x800FF2C0: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800FF2C4: b           L_800FF2E0
    // 0x800FF2C8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
        goto L_800FF2E0;
    // 0x800FF2C8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
L_800FF2CC:
    // 0x800FF2CC: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x800FF2D0: b           L_800FF2E0
    // 0x800FF2D4: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
        goto L_800FF2E0;
    // 0x800FF2D4: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x800FF2D8: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_800FF2DC:
    // 0x800FF2DC: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
L_800FF2E0:
    // 0x800FF2E0: sub.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800FF2E4: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800FF2E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FF2EC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800FF2F0: nop

    // 0x800FF2F4: bc1fl       L_800FF348
    if (!c1cs) {
        // 0x800FF2F8: mov.s       $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
            goto L_800FF348;
    }
    goto skip_5;
    // 0x800FF2F8: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    skip_5:
    // 0x800FF2FC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800FF300: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x800FF304: add.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800FF308: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800FF30C: nop

    // 0x800FF310: bc1fl       L_800FF328
    if (!c1cs) {
        // 0x800FF314: add.s       $f4, $f20, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f2.fl;
            goto L_800FF328;
    }
    goto skip_6;
    // 0x800FF314: add.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f2.fl;
    skip_6:
    // 0x800FF318: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x800FF31C: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
    // 0x800FF320: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800FF324: add.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f2.fl;
L_800FF328:
    // 0x800FF328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FF32C: nop

    // 0x800FF330: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800FF334: nop

    // 0x800FF338: mul.s       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800FF33C: b           L_800FF348
    // 0x800FF340: nop

        goto L_800FF348;
    // 0x800FF340: nop

    // 0x800FF344: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
L_800FF348:
    // 0x800FF348: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FF34C: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800FF350: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800FF354: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800FF358: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800FF35C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800FF360: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800FF364: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800FF368: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FF36C: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800FF370: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800FF374: nop

    // 0x800FF378: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800FF37C:
    // 0x800FF37C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800FF380: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800FF384: jr          $ra
    // 0x800FF388: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800FF388: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800FF38C: nop

;}
RECOMP_FUNC void _bsbshock_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B30: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B30);
    return;
    // 0x80082B34: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800D3A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3A54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3A58: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D3A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3A60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3A64: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800D3A68: addiu       $a1, $a1, 0x70B0
    ctx->r5 = ADD32(ctx->r5, 0X70B0);
    // 0x800D3A6C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800D3A70: jal         0x800D3B6C
    // 0x800D3A74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D3B6C(rdram, ctx);
        goto after_0;
    // 0x800D3A74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x800D3A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3A80: jr          $ra
    // 0x800D3A84: nop

    return;
    // 0x800D3A84: nop

;}
RECOMP_FUNC void func_80800234_chklungodoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800234: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800238: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080023C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800240: jal         0x80086240
    // 0x80800244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800248: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8080024C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1252, 0X49E) << 16);
    // 0x80800250: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800254: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800258: lbu         $t8, 0x49E($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(1252, 0X49E));
    // 0x8080025C: beql        $t8, $zero, L_808002F0
    if (ctx->r24 == 0) {
        // 0x80800260: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002F0;
    }
    goto skip_0;
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800264: jal         0x80089C90
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080026C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1252, 0X550) << 16);
    // 0x80800270: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800274: addiu       $a3, $a3, 0x550
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1252, 0X550));
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800280: jal         0x80089D50
    // 0x80800284: slt         $a2, $zero, $v0
    ctx->r6 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800284: slt         $a2, $zero, $v0
    ctx->r6 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    after_2:
    // 0x80800288: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080028C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1252, 0X480) << 16);
    // 0x80800290: lwc1        $f6, 0x480($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1252, 0X480));
    // 0x80800294: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800298: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080029C: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808002A0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808002A4: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    // 0x808002A8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808002AC: jal         0x800F10B4
    // 0x808002B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808002B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_3:
    // 0x808002B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002B8: jal         0x80089D30
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002C0: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808002C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002C8: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808002CC: bnel        $t1, $at, L_808002F0
    if (ctx->r9 != ctx->r1) {
        // 0x808002D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002F0;
    }
    goto skip_1;
    // 0x808002D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002D4: jal         0x800D9078
    // 0x808002D8: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x808002D8: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_5:
    // 0x808002DC: beql        $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002F0;
    }
    goto skip_2;
    // 0x808002E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808002E4: jal         0x8010A590
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_6;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808002EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002F0:
    // 0x808002F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void bskaztorpedo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801190: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801194: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X17E4) << 16);
    // 0x80801198: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080119C: jr          $ra
    // 0x808011A0: lw          $v0, 0x17E4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X17E4));
    return;
    // 0x808011A0: lw          $v0, 0x17E4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X17E4));
;}
RECOMP_FUNC void _baattach_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084448: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084448);
    return;
    // 0x8008444C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _glzone_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088788: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088788);
    return;
    // 0x8008878C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800C7C_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C7C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800C80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C84: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80800C88: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80800C8C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800C90: jal         0x80800C00
    // 0x80800C94: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_80800C00_chwaspnestgame(rdram, ctx);
        goto after_0;
    // 0x80800C94: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80800C98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1E6C) << 16);
    // 0x80800C9C: lwc1        $f6, 0x1E6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E6C));
    // 0x80800CA0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800CA4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800CA8: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800CAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800CB0: jal         0x80800C00
    // 0x80800CB4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_80800C00_chwaspnestgame(rdram, ctx);
        goto after_1;
    // 0x80800CB4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800CB8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800CBC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800CC0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800CC4: jal         0x800EE7B4
    // 0x80800CC8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    func_800EE7B4(rdram, ctx);
        goto after_2;
    // 0x80800CC8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_2:
    // 0x80800CCC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80800CD0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800CD4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800CD8: jal         0x800EE7B4
    // 0x80800CDC: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    func_800EE7B4(rdram, ctx);
        goto after_3;
    // 0x80800CDC: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    after_3:
    // 0x80800CE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800CE4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800CE8: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    // 0x80800CEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800CF4: jal         0x800EFA4C
    // 0x80800CF8: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800CF8: nop

    after_4:
    // 0x80800CFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1E70) << 16);
    // 0x80800D00: lwc1        $f10, 0x1E70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E70));
    // 0x80800D04: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80800D08: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x80800D0C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800D10: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800D14: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80800D18: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80800D1C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80800D20: lui         $a3, 0x457A
    ctx->r7 = S32(0X457A << 16);
    // 0x80800D24: jal         0x800F0734
    // 0x80800D28: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F0734(rdram, ctx);
        goto after_5;
    // 0x80800D28: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80800D2C: beq         $v0, $zero, L_80800D6C
    if (ctx->r2 == 0) {
        // 0x80800D30: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_80800D6C;
    }
    // 0x80800D30: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800D34: jal         0x800EF3DC
    // 0x80800D38: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF3DC(rdram, ctx);
        goto after_6;
    // 0x80800D38: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800D3C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800D40: jal         0x800EF04C
    // 0x80800D44: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800D44: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80800D48: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80800D4C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800D50: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80800D54: jal         0x80800AF8
    // 0x80800D58: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    func_80800AF8_chwaspnestgame(rdram, ctx);
        goto after_8;
    // 0x80800D58: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    after_8:
    // 0x80800D5C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80800D60: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x80800D64: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80800D68: sw          $t0, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r8;
L_80800D6C:
    // 0x80800D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D70: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80800D74: jr          $ra
    // 0x80800D78: nop

    return;
    // 0x80800D78: nop

;}
RECOMP_FUNC void func_80801ABC_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AC4: jal         0x80800188
    // 0x80801AC8: nop

    func_80800188_bskazfly(rdram, ctx);
        goto after_0;
    // 0x80801AC8: nop

    after_0:
    // 0x80801ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AD4: jr          $ra
    // 0x80801AD8: nop

    return;
    // 0x80801AD8: nop

;}
RECOMP_FUNC void func_80800B68_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800B6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B74: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800B78: jal         0x80100094
    // 0x80800B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B84: jal         0x80087F28
    // 0x80800B88: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    _gcmapsects_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800B88: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x80800B8C: beql        $v0, $zero, L_80800D2C
    if (ctx->r2 == 0) {
        // 0x80800B90: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D2C;
    }
    goto skip_0;
    // 0x80800B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800B94: lh          $a2, 0x10($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X10);
    // 0x80800B98: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B9C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800BA0: sltiu       $t6, $a2, 0x1
    ctx->r14 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80800BA4: bne         $t6, $zero, L_80800BBC
    if (ctx->r14 != 0) {
        // 0x80800BA8: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80800BBC;
    }
    // 0x80800BA8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800BAC: bne         $t6, $zero, L_80800BD0
    if (ctx->r14 != 0) {
        // 0x80800BB0: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80800BD0;
    }
    // 0x80800BB0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800BB4: lbu         $t8, 0x5F($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5F);
    // 0x80800BB8: beq         $t8, $zero, L_80800BD0
    if (ctx->r24 == 0) {
        // 0x80800BBC: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(1092, 0X1594) << 16);
            goto L_80800BD0;
    }
L_80800BBC:
    // 0x80800BBC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1092, 0X1594) << 16);
    // 0x80800BC0: addiu       $t0, $t0, 0x1594
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1092, 0X1594));
    // 0x80800BC4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800BC8: jal         0x80089D58
    // 0x80800BCC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800BCC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
L_80800BD0:
    // 0x80800BD0: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x80800BD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BD8: beq         $v0, $at, L_80800BF0
    if (ctx->r2 == ctx->r1) {
        // 0x80800BDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BF0;
    }
    // 0x80800BDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BE0: beq         $v0, $at, L_80800C38
    if (ctx->r2 == ctx->r1) {
        // 0x80800BE4: nop
    
            goto L_80800C38;
    }
    // 0x80800BE4: nop

    // 0x80800BE8: b           L_80800C94
    // 0x80800BEC: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
        goto L_80800C94;
    // 0x80800BEC: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
L_80800BF0:
    // 0x80800BF0: jal         0x800D9078
    // 0x80800BF4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80800BF4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800BF8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800BFC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800C00: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800C04: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800C08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800C0C: jal         0x800F12D4
    // 0x80800C10: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_4;
    // 0x80800C10: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80800C14: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80800C18: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80800C1C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800C20: beq         $t1, $zero, L_80800C30
    if (ctx->r9 == 0) {
        // 0x80800C24: nop
    
            goto L_80800C30;
    }
    // 0x80800C24: nop

    // 0x80800C28: sh          $t2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r10;
    // 0x80800C2C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_80800C30:
    // 0x80800C30: b           L_80800C94
    // 0x80800C34: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
        goto L_80800C94;
    // 0x80800C34: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
L_80800C38:
    // 0x80800C38: jal         0x800D9078
    // 0x80800C3C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x80800C3C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800C40: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800C44: jal         0x808011A8
    // 0x80800C48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_808011A8_chpoolkids(rdram, ctx);
        goto after_6;
    // 0x80800C48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x80800C4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800C50: jal         0x800BF744
    // 0x80800C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_7;
    // 0x80800C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800C58: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800C5C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800C60: lui         $a2, 0x4006
    ctx->r6 = S32(0X4006 << 16);
    // 0x80800C64: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800C68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800C6C: jal         0x800F12D4
    // 0x80800C70: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_8;
    // 0x80800C70: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x80800C74: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800C78: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80800C7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800C80: beql        $t3, $zero, L_80800C94
    if (ctx->r11 == 0) {
        // 0x80800C84: lh          $v0, 0x10($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X10);
            goto L_80800C94;
    }
    goto skip_1;
    // 0x80800C84: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    skip_1:
    // 0x80800C88: sh          $t4, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r12;
    // 0x80800C8C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80800C90: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
L_80800C94:
    // 0x80800C94: beq         $v0, $zero, L_80800CA8
    if (ctx->r2 == 0) {
        // 0x80800C98: nop
    
            goto L_80800CA8;
    }
    // 0x80800C98: nop

    // 0x80800C9C: lh          $t5, 0x24($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X24);
    // 0x80800CA0: bnel        $t5, $zero, L_80800D2C
    if (ctx->r13 != 0) {
        // 0x80800CA4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D2C;
    }
    goto skip_2;
    // 0x80800CA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_80800CA8:
    // 0x80800CA8: jal         0x800BEA88
    // 0x80800CAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_9;
    // 0x80800CAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x80800CB0: beq         $v0, $zero, L_80800D28
    if (ctx->r2 == 0) {
        // 0x80800CB4: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80800D28;
    }
    // 0x80800CB4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800CB8: lh          $t6, 0x24($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X24);
    // 0x80800CBC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800CC0: bnel        $t6, $zero, L_80800CF4
    if (ctx->r14 != 0) {
        // 0x80800CC4: lh          $t8, 0x10($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X10);
            goto L_80800CF4;
    }
    goto skip_3;
    // 0x80800CC4: lh          $t8, 0x10($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X10);
    skip_3:
    // 0x80800CC8: jal         0x800E3DC0
    // 0x80800CCC: addiu       $a1, $s0, 0x2E
    ctx->r5 = ADD32(ctx->r16, 0X2E);
    func_800E3DC0(rdram, ctx);
        goto after_10;
    // 0x80800CCC: addiu       $a1, $s0, 0x2E
    ctx->r5 = ADD32(ctx->r16, 0X2E);
    after_10:
    // 0x80800CD0: beq         $v0, $zero, L_80800CF0
    if (ctx->r2 == 0) {
        // 0x80800CD4: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800CF0;
    }
    // 0x80800CD4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CD8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800CDC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800CE0: addiu       $a2, $a2, 0x60F8
    ctx->r6 = ADD32(ctx->r6, 0X60F8);
    // 0x80800CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CE8: jal         0x80088660
    // 0x80800CEC: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800CEC: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_11:
L_80800CF0:
    // 0x80800CF0: lh          $t8, 0x10($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X10);
L_80800CF4:
    // 0x80800CF4: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80800CF8: bnel        $t8, $zero, L_80800D2C
    if (ctx->r24 != 0) {
        // 0x80800CFC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D2C;
    }
    goto skip_4;
    // 0x80800CFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800D00: jal         0x800E3DC0
    // 0x80800D04: addiu       $a1, $s0, 0x1A
    ctx->r5 = ADD32(ctx->r16, 0X1A);
    func_800E3DC0(rdram, ctx);
        goto after_12;
    // 0x80800D04: addiu       $a1, $s0, 0x1A
    ctx->r5 = ADD32(ctx->r16, 0X1A);
    after_12:
    // 0x80800D08: beq         $v0, $zero, L_80800D28
    if (ctx->r2 == 0) {
        // 0x80800D0C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D28;
    }
    // 0x80800D0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D10: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80800D14: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800D18: addiu       $a2, $a2, 0x60F8
    ctx->r6 = ADD32(ctx->r6, 0X60F8);
    // 0x80800D1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D20: jal         0x80088660
    // 0x80800D24: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80800D24: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    after_13:
L_80800D28:
    // 0x80800D28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D2C:
    // 0x80800D2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D30: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800D34: jr          $ra
    // 0x80800D38: nop

    return;
    // 0x80800D38: nop

;}
RECOMP_FUNC void _gcintrotext_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880F0: syscall     671
    recomp_syscall_handler(rdram, ctx, 0x800880F0);
    return;
    // 0x800880F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808000EC_chgobicommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000FC: jal         0x800C0638
    // 0x80800100: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x80800100: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800104: bne         $v0, $zero, L_80800124
    if (ctx->r2 != 0) {
        // 0x80800108: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800124;
    }
    // 0x80800108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080010C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X264) << 16);
    // 0x80800110: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1448, 0X270) << 16);
    // 0x80800114: addiu       $a3, $a3, 0x270
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1448, 0X270));
    // 0x80800118: addiu       $a2, $a2, 0x264
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X264));
    // 0x8080011C: jal         0x80089D28
    // 0x80800120: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800120: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_1:
L_80800124:
    // 0x80800124: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80800128: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X200) << 16);
    // 0x8080012C: lui         $a3, 0x3E85
    ctx->r7 = S32(0X3E85 << 16);
    // 0x80800130: ori         $a3, $a3, 0x1EB8
    ctx->r7 = ctx->r7 | 0X1EB8;
    // 0x80800134: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X200));
    // 0x80800138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080013C: jal         0x80089D20
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800144: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X210) << 16);
    // 0x80800148: lui         $a3, 0x3ED1
    ctx->r7 = S32(0X3ED1 << 16);
    // 0x8080014C: ori         $a3, $a3, 0xEB85
    ctx->r7 = ctx->r7 | 0XEB85;
    // 0x80800150: addiu       $a2, $a2, 0x210
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X210));
    // 0x80800154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800158: jal         0x80089D20
    // 0x8080015C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080015C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800160: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X200) << 16);
    // 0x80800164: lui         $a3, 0x3F0C
    ctx->r7 = S32(0X3F0C << 16);
    // 0x80800168: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080016C: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X200));
    // 0x80800170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800174: jal         0x80089D20
    // 0x80800178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800178: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8080017C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X200) << 16);
    // 0x80800180: lui         $a3, 0x3F1E
    ctx->r7 = S32(0X3F1E << 16);
    // 0x80800184: ori         $a3, $a3, 0xB852
    ctx->r7 = ctx->r7 | 0XB852;
    // 0x80800188: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X200));
    // 0x8080018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800190: jal         0x80089D20
    // 0x80800194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080019C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001A4: jr          $ra
    // 0x808001A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808001A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800BAA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAA68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BAA6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BAA70: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BAA74: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800BAA78: sb          $t0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r8;
    // 0x800BAA7C: sh          $a2, 0xC4($a0)
    MEM_H(0XC4, ctx->r4) = ctx->r6;
    // 0x800BAA80: sh          $a3, 0xC6($a0)
    MEM_H(0XC6, ctx->r4) = ctx->r7;
    // 0x800BAA84: jal         0x800EE940
    // 0x800BAA88: addiu       $a0, $a0, 0xC8
    ctx->r4 = ADD32(ctx->r4, 0XC8);
    func_800EE940(rdram, ctx);
        goto after_0;
    // 0x800BAA88: addiu       $a0, $a0, 0xC8
    ctx->r4 = ADD32(ctx->r4, 0XC8);
    after_0:
    // 0x800BAA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BAA94: jr          $ra
    // 0x800BAA98: nop

    return;
    // 0x800BAA98: nop

;}
RECOMP_FUNC void func_8080000C_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800024: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800028: beq         $t6, $at, L_8080005C
    if (ctx->r14 == ctx->r1) {
        // 0x8080002C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080005C;
    }
    // 0x8080002C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800030: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800034: beq         $t6, $at, L_808000D0
    if (ctx->r14 == ctx->r1) {
        // 0x80800038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800040: beq         $t6, $at, L_808000FC
    if (ctx->r14 == ctx->r1) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000FC;
    }
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080004C: beq         $t6, $at, L_80800168
    if (ctx->r14 == ctx->r1) {
        // 0x80800050: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800168;
    }
    // 0x80800050: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800054: b           L_808001D8
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001D8;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080005C:
    // 0x8080005C: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800064: jal         0x8008A1D0
    // 0x80800068: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800070: addiu       $a1, $zero, 0x17C7
        ctx->r5 = ADD32(0, 0X17C7);
            goto L_8080008C;
    }
    // 0x80800070: addiu       $a1, $zero, 0x17C7
    ctx->r5 = ADD32(0, 0X17C7);
    // 0x80800074: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800078: addiu       $t7, $zero, 0x39
    ctx->r15 = ADD32(0, 0X39);
    // 0x8080007C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800080: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800084: jal         0x8008A208
    // 0x80800088: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800088: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
L_8080008C:
    // 0x8080008C: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80800090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800094: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800098: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x8080009C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000A4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x808000A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000AC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808000B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808000B8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808000BC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808000C0: jal         0x80089F20
    // 0x808000C4: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808000C4: nop

    after_2:
    // 0x808000C8: b           L_808001D8
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001D8;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D0:
    // 0x808000D0: jal         0x8008A500
    // 0x808000D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _subaddietaxi_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808000D8: beql        $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x808000DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D8;
    }
    goto skip_0;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000E0: jal         0x800DA544
    // 0x808000E4: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808000E4: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_4:
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80102424
    // 0x808000F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808000F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x808000F4: b           L_808001D8
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001D8;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000FC:
    // 0x808000FC: jal         0x8008A550
    // 0x80800100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _subaddietaxi_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800104: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800124;
    }
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x8008A520
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _subaddietaxi_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800114: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800124;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80102424
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800124:
    // 0x80800124: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80800128: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080012C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800130: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x80800134: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800138: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080013C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80800140: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800144: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800148: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080014C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800150: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800154: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800158: jal         0x80089F20
    // 0x8080015C: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x8080015C: nop

    after_9:
    // 0x80800160: b           L_808001D8
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001D8;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800168:
    // 0x80800168: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x8080016C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800170: jal         0x8008A1D0
    // 0x80800174: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800174: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_10:
    // 0x80800178: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x8080017C: addiu       $a1, $zero, 0x17C8
        ctx->r5 = ADD32(0, 0X17C8);
            goto L_80800198;
    }
    // 0x8080017C: addiu       $a1, $zero, 0x17C8
    ctx->r5 = ADD32(0, 0X17C8);
    // 0x80800180: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800184: addiu       $t0, $zero, 0x39
    ctx->r8 = ADD32(0, 0X39);
    // 0x80800188: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080018C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800190: jal         0x8008A208
    // 0x80800194: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800194: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_11:
L_80800198:
    // 0x80800198: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x8080019C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001A0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808001A4: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x808001A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001AC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808001B0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x808001B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001B8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808001C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808001C8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808001CC: jal         0x80089F20
    // 0x808001D0: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808001D0: nop

    after_12:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001D8:
    // 0x808001D8: jal         0x8008A540
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _subaddietaxi_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x808001E0: jal         0x80087738
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void idtwinklecolour_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808007E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808007EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808007F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808007F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808007F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808007FC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800800: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800804: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800808: jal         0x800D8FF8
    // 0x8080080C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080080C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800814: addiu       $a1, $s2, 0x6
    ctx->r5 = ADD32(ctx->r18, 0X6);
    // 0x80800818: jal         0x800E3DC0
    // 0x8080081C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800E3DC0(rdram, ctx);
        goto after_1;
    // 0x8080081C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800820: beq         $v0, $zero, L_80800948
    if (ctx->r2 == 0) {
        // 0x80800824: lwc1        $f14, 0x34($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80800948;
    }
    // 0x80800824: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800828: lh          $t6, 0x22($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X22);
    // 0x8080082C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800830: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800834: blez        $t6, L_808008EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800838: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_808008EC;
    }
    // 0x80800838: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080083C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800840: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800844: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800848: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080084C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800850: lw          $t7, 0x24($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X24);
L_80800854:
    // 0x80800854: addu        $v0, $t7, $s0
    ctx->r2 = ADD32(ctx->r15, ctx->r16);
    // 0x80800858: lb          $t8, 0xB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XB);
    // 0x8080085C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800860: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800864: nop

    // 0x80800868: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080086C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80800870: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80800874: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80800878: lw          $t9, 0x24($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X24);
    // 0x8080087C: addu        $v0, $t9, $s0
    ctx->r2 = ADD32(ctx->r25, ctx->r16);
    // 0x80800880: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800884: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800888: nop

    // 0x8080088C: bc1fl       L_808008B4
    if (!c1cs) {
        // 0x80800890: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_808008B4;
    }
    goto skip_0;
    // 0x80800890: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80800894: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80800898: lw          $t0, 0x24($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X24);
    // 0x8080089C: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x808008A0: lb          $t1, 0xB($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XB);
    // 0x808008A4: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x808008A8: b           L_808008D0
    // 0x808008AC: sb          $t2, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r10;
        goto L_808008D0;
    // 0x808008AC: sb          $t2, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r10;
    // 0x808008B0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_808008B4:
    // 0x808008B4: nop

    // 0x808008B8: bc1fl       L_808008D4
    if (!c1cs) {
        // 0x808008BC: lh          $t5, 0x22($s2)
        ctx->r13 = MEM_H(ctx->r18, 0X22);
            goto L_808008D4;
    }
    goto skip_1;
    // 0x808008BC: lh          $t5, 0x22($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X22);
    skip_1:
    // 0x808008C0: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x808008C4: lw          $t3, 0x24($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X24);
    // 0x808008C8: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x808008CC: sb          $v1, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r3;
L_808008D0:
    // 0x808008D0: lh          $t5, 0x22($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X22);
L_808008D4:
    // 0x808008D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808008D8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808008DC: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808008E0: bnel        $at, $zero, L_80800854
    if (ctx->r1 != 0) {
        // 0x808008E4: lw          $t7, 0x24($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X24);
            goto L_80800854;
    }
    goto skip_2;
    // 0x808008E4: lw          $t7, 0x24($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X24);
    skip_2:
    // 0x808008E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808008EC:
    // 0x808008EC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808008F0: addiu       $a2, $a2, -0x7130
    ctx->r6 = ADD32(ctx->r6, -0X7130);
    // 0x808008F4: jal         0x80088660
    // 0x808008F8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808008F8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_2:
    // 0x808008FC: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
    // 0x80800900: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800904: blezl       $v0, L_8080094C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800908: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080094C;
    }
    goto skip_3;
    // 0x80800908: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
L_8080090C:
    // 0x8080090C: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x80800910: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800918: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8080091C: lbu         $t8, 0xD($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XD);
    // 0x80800920: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800924: beql        $t8, $zero, L_8080093C
    if (ctx->r24 == 0) {
        // 0x80800928: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080093C;
    }
    goto skip_4;
    // 0x80800928: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8080092C: jal         0x80800574
    // 0x80800930: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_80800574_idtwinklecolour(rdram, ctx);
        goto after_3;
    // 0x80800930: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
    // 0x80800934: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
    // 0x80800938: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080093C:
    // 0x8080093C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800940: bne         $at, $zero, L_8080090C
    if (ctx->r1 != 0) {
        // 0x80800944: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8080090C;
    }
    // 0x80800944: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80800948:
    // 0x80800948: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080094C:
    // 0x8080094C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800950: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800954: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800958: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080095C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800960: jr          $ra
    // 0x80800964: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800964: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800968: nop

    // 0x8080096C: nop

;}
RECOMP_FUNC void _chmrsboggyhome_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866F8: syscall     356
    recomp_syscall_handler(rdram, ctx, 0x800866F8);
    return;
    // 0x800866FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800070_ncbabee(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: jal         0x80112550
    // 0x8080007C: nop

    func_80112550(rdram, ctx);
        goto after_0;
    // 0x8080007C: nop

    after_0:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_8009E994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E994: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E998: jr          $ra
    // 0x8009E99C: lbu         $v0, 0x7075($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7075);
    return;
    // 0x8009E99C: lbu         $v0, 0x7075($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7075);
;}
RECOMP_FUNC void func_8008FC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FC00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FC04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FC08: jal         0x800F54E4
    // 0x8008FC0C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FC0C: nop

    after_0:
    // 0x8008FC10: jal         0x800F5578
    // 0x8008FC14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5578(rdram, ctx);
        goto after_1;
    // 0x8008FC14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FC20: jr          $ra
    // 0x8008FC24: nop

    return;
    // 0x8008FC24: nop

;}
RECOMP_FUNC void mlwave_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080010C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800110: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    // 0x80800114: jr          $ra
    // 0x80800118: swc1        $f14, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x80800118: swc1        $f14, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f14.u32l;
;}
