#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F9198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9198: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F919C: lbu         $t6, 0x54FA($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X54FA);
    // 0x800F91A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F91A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F91A8: bne         $t6, $zero, L_800F91D4
    if (ctx->r14 != 0) {
        // 0x800F91AC: nop
    
            goto L_800F91D4;
    }
    // 0x800F91AC: nop

    // 0x800F91B0: jal         0x800F90F8
    // 0x800F91B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F90F8(rdram, ctx);
        goto after_0;
    // 0x800F91B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800F91B8: jal         0x800F9104
    // 0x800F91BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F9104(rdram, ctx);
        goto after_1;
    // 0x800F91BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800F91C0: jal         0x800F9110
    // 0x800F91C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F9110(rdram, ctx);
        goto after_2;
    // 0x800F91C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800F91C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800F91CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F91D0: sb          $t7, 0x54FA($at)
    MEM_B(0X54FA, ctx->r1) = ctx->r15;
L_800F91D4:
    // 0x800F91D4: jal         0x800F9C6C
    // 0x800F91D8: nop

    func_800F9C6C(rdram, ctx);
        goto after_3;
    // 0x800F91D8: nop

    after_3:
    // 0x800F91DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F91E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F91E4: jr          $ra
    // 0x800F91E8: nop

    return;
    // 0x800F91E8: nop

;}
RECOMP_FUNC void func_80801724_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801724: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080172C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801730: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801734: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801738: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080173C: jal         0x80100094
    // 0x80801740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801744: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801748: lh          $v1, 0x820($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X820);
    // 0x8080174C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801750: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80801754: beq         $v1, $zero, L_80801774
    if (ctx->r3 == 0) {
        // 0x80801758: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80801774;
    }
    // 0x80801758: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080175C: beq         $v1, $at, L_8080177C
    if (ctx->r3 == ctx->r1) {
        // 0x80801760: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080177C;
    }
    // 0x80801760: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801764: beql        $v1, $at, L_808017BC
    if (ctx->r3 == ctx->r1) {
        // 0x80801768: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808017BC;
    }
    goto skip_0;
    // 0x80801768: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080176C: b           L_808017C8
    // 0x80801770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808017C8;
    // 0x80801770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801774:
    // 0x80801774: jal         0x800856B0
    // 0x80801778: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801778: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
L_8080177C:
    // 0x8080177C: jal         0x800856E0
    // 0x80801780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80801780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80801784: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80801788: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080178C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1232, 0X1BE8) << 16);
    // 0x80801790: sh          $t6, 0x820($t7)
    MEM_H(0X820, ctx->r15) = ctx->r14;
    // 0x80801794: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80801798: jal         0x80088090
    // 0x8080179C: addiu       $a0, $a0, 0x1BE8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1232, 0X1BE8));
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080179C: addiu       $a0, $a0, 0x1BE8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1232, 0X1BE8));
    after_3:
    // 0x808017A0: jal         0x80088098
    // 0x808017A4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808017A4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808017A8: jal         0x800880A0
    // 0x808017AC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808017AC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_5:
    // 0x808017B0: jal         0x800880B8
    // 0x808017B4: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808017B4: nop

    after_6:
    // 0x808017B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808017BC:
    // 0x808017BC: jal         0x800856D8
    // 0x808017C0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _capod_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x808017C0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808017C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017C8:
    // 0x808017C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808017D0: jr          $ra
    // 0x808017D4: nop

    return;
    // 0x808017D4: nop

;}
RECOMP_FUNC void _idflash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D50: syscall     737
    recomp_syscall_handler(rdram, ctx, 0x80088D50);
    return;
    // 0x80088D54: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void boot___osEPiRawStartDma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800268D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800268D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800268D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800268D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800268DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800268E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800268E4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800268E8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800268EC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800268F0: sh          $t7, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r15;
    // 0x800268F4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800268F8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800268FC: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x80026900: sh          $t0, 0x1A($t1)
    MEM_H(0X1A, ctx->r9) = ctx->r8;
    // 0x80026904: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80026908: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x8002690C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80026910: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80026914: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80026918: sh          $t4, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r12;
    // 0x8002691C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80026920: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x80026924: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80026928: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x8002692C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80026930: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80026934: jal         0x80026AA4
    // 0x80026938: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    func_80026AA4(rdram, ctx);
        goto after_0;
    // 0x80026938: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    after_0:
    // 0x8002693C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026940: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80026944: beq         $t9, $zero, L_80026A80
    if (ctx->r25 == 0) {
        // 0x80026948: nop
    
            goto L_80026A80;
    }
    // 0x80026948: nop

    // 0x8002694C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80026950: beq         $t0, $zero, L_80026A60
    if (ctx->r8 == 0) {
        // 0x80026954: nop
    
            goto L_80026A60;
    }
    // 0x80026954: nop

    // 0x80026958: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8002695C: addiu       $t1, $zero, 0x228
    ctx->r9 = ADD32(0, 0X228);
    // 0x80026960: sw          $t1, 0x88($t2)
    MEM_W(0X88, ctx->r10) = ctx->r9;
    // 0x80026964: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80026968: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8002696C: sw          $zero, 0x8($t4)
    MEM_W(0X8, ctx->r12) = 0;
    // 0x80026970: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80026974: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80026978: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x8002697C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80026980: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80026984: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80026988: jal         0x80021794
    // 0x8002698C: nop

    func_80021794(rdram, ctx);
        goto after_1;
    // 0x8002698C: nop

    after_1:
    // 0x80026990: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80026994: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80026998: beq         $t9, $zero, L_800269F0
    if (ctx->r25 == 0) {
        // 0x8002699C: nop
    
            goto L_800269F0;
    }
    // 0x8002699C: nop

    // 0x800269A0: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800269A4: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x800269A8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800269AC: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800269B0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800269B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800269B8: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800269BC: sh          $t3, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r11;
    // 0x800269C0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800269C4: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x800269C8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800269CC: addiu       $t6, $zero, 0x170
    ctx->r14 = ADD32(0, 0X170);
    // 0x800269D0: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x800269D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800269D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800269DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800269E0: jal         0x8002B684
    // 0x800269E4: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    func_8002B684(rdram, ctx);
        goto after_2;
    // 0x800269E4: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_2:
    // 0x800269E8: b           L_800269F0
    // 0x800269EC: nop

        goto L_800269F0;
    // 0x800269EC: nop

L_800269F0:
    // 0x800269F0: jal         0x80021794
    // 0x800269F4: nop

    func_80021794(rdram, ctx);
        goto after_3;
    // 0x800269F4: nop

    after_3:
    // 0x800269F8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800269FC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80026A00: beq         $t9, $zero, L_80026A58
    if (ctx->r25 == 0) {
        // 0x80026A04: nop
    
            goto L_80026A58;
    }
    // 0x80026A04: nop

    // 0x80026A08: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80026A0C: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x80026A10: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80026A14: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80026A18: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x80026A1C: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80026A20: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80026A24: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80026A28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80026A2C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80026A30: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80026A34: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80026A38: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80026A3C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80026A40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80026A44: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80026A48: jal         0x8002B684
    // 0x80026A4C: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    func_8002B684(rdram, ctx);
        goto after_4;
    // 0x80026A4C: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    after_4:
    // 0x80026A50: b           L_80026A58
    // 0x80026A54: nop

        goto L_80026A58;
    // 0x80026A54: nop

L_80026A58:
    // 0x80026A58: b           L_80026A80
    // 0x80026A5C: nop

        goto L_80026A80;
    // 0x80026A5C: nop

L_80026A60:
    // 0x80026A60: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80026A64: sw          $zero, 0x88($t0)
    MEM_W(0X88, ctx->r8) = 0;
    // 0x80026A68: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80026A6C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80026A70: sw          $t2, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r10;
    // 0x80026A74: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80026A78: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80026A7C: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_80026A80:
    // 0x80026A80: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80026A84: b           L_80026A94
    // 0x80026A88: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
        goto L_80026A94;
    // 0x80026A88: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80026A8C: b           L_80026A94
    // 0x80026A90: nop

        goto L_80026A94;
    // 0x80026A90: nop

L_80026A94:
    // 0x80026A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026A98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026A9C: jr          $ra
    // 0x80026AA0: nop

    return;
    // 0x80026AA0: nop

;}
RECOMP_FUNC void func_8080000C_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800028: jal         0x80085CE0
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chboggykids_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800030: bne         $v0, $zero, L_80800048
    if (ctx->r2 != 0) {
        // 0x80800034: lui         $at, 0x4370
        ctx->r1 = S32(0X4370 << 16);
            goto L_80800048;
    }
    // 0x80800034: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80800038: jal         0x800FFAB0
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800040: b           L_80800098
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800098;
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800048:
    // 0x80800048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x8008A498
    // 0x80800054: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800054: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800058: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800064: jal         0x80089F70
    // 0x80800068: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_4:
    // 0x8080006C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: addiu       $a1, $zero, 0x3CB
    ctx->r5 = ADD32(0, 0X3CB);
    // 0x80800074: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80800078: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080007C: jal         0x80089FD0
    // 0x80800080: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800080: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_5:
    // 0x80800084: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x8080093C
    // 0x80800090: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    func_8080093C_chboggygirl(rdram, ctx);
        goto after_6;
    // 0x80800090: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    after_6:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800098:
    // 0x80800098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_800D10D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D10D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D10D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D10DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D10E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D10E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D10E8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800D10EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D10F0: jal         0x800D0A9C
    // 0x800D10F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x800D10F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D10F8: beq         $v0, $zero, L_800D1108
    if (ctx->r2 == 0) {
        // 0x800D10FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D1108;
    }
    // 0x800D10FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D1100: b           L_800D1188
    // 0x800D1104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D1188;
    // 0x800D1104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1108:
    // 0x800D1108: jal         0x800D0B68
    // 0x800D110C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x800D110C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800D1110: beq         $v0, $zero, L_800D1120
    if (ctx->r2 == 0) {
        // 0x800D1114: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D1120;
    }
    // 0x800D1114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D1118: b           L_800D1188
    // 0x800D111C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D1188;
    // 0x800D111C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1120:
    // 0x800D1120: jal         0x800D0B08
    // 0x800D1124: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B08(rdram, ctx);
        goto after_2;
    // 0x800D1124: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D1128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D112C: jal         0x800D053C
    // 0x800D1130: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D053C(rdram, ctx);
        goto after_3;
    // 0x800D1130: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800D1134: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800D1138: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800D113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D1140: beq         $a1, $zero, L_800D1164
    if (ctx->r5 == 0) {
        // 0x800D1144: addiu       $a2, $sp, 0x20
        ctx->r6 = ADD32(ctx->r29, 0X20);
            goto L_800D1164;
    }
    // 0x800D1144: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800D1148: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x800D114C: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x800D1150: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1154: jal         0x800D0DAC
    // 0x800D1158: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800D0DAC(rdram, ctx);
        goto after_4;
    // 0x800D1158: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800D115C: b           L_800D118C
    // 0x800D1160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D118C;
    // 0x800D1160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D1164:
    // 0x800D1164: jal         0x800D07CC
    // 0x800D1168: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D07CC(rdram, ctx);
        goto after_5;
    // 0x800D1168: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800D116C: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x800D1170: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800D1174: or          $a0, $t8, $t9
    ctx->r4 = ctx->r24 | ctx->r25;
    // 0x800D1178: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800D117C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800D1180: jal         0x800D0DAC
    // 0x800D1184: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800D0DAC(rdram, ctx);
        goto after_6;
    // 0x800D1184: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_6:
L_800D1188:
    // 0x800D1188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D118C:
    // 0x800D118C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D1190: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D1194: jr          $ra
    // 0x800D1198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D1198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800B3784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3784: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800B3788: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800B378C: subu        $v0, $t6, $a0
    ctx->r2 = SUB32(ctx->r14, ctx->r4);
    // 0x800B3790: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x800B3794: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800B3798: mflo        $v0
    ctx->r2 = lo;
    // 0x800B379C: jr          $ra
    // 0x800B37A0: nop

    return;
    // 0x800B37A0: nop

;}
RECOMP_FUNC void func_80800AB8_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800AC4: jal         0x80801018
    // 0x80800AC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80801018_chwarppad(rdram, ctx);
        goto after_0;
    // 0x80800AC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AD4: jr          $ra
    // 0x80800AD8: nop

    return;
    // 0x80800AD8: nop

;}
RECOMP_FUNC void func_80098B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098B4C: lw          $t7, 0xBC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XBC);
    // 0x80098B50: sltiu       $t6, $a1, 0x1
    ctx->r14 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80098B54: jr          $ra
    // 0x80098B58: sb          $t6, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r14;
    return;
    // 0x80098B58: sb          $t6, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_800F9AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9AAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9AB0: addiu       $v0, $v0, 0x5520
    ctx->r2 = ADD32(ctx->r2, 0X5520);
    // 0x800F9AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9ABC: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x800F9AC0: sb          $a1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r5;
    // 0x800F9AC4: jal         0x800F9488
    // 0x800F9AC8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800F9488(rdram, ctx);
        goto after_0;
    // 0x800F9AC8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x800F9ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9AD4: jr          $ra
    // 0x800F9AD8: nop

    return;
    // 0x800F9AD8: nop

;}
RECOMP_FUNC void func_800C9AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9AB4: sltiu       $at, $a0, 0x6
    ctx->r1 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x800C9AB8: beq         $at, $zero, L_800C9B20
    if (ctx->r1 == 0) {
        // 0x800C9ABC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C9B20;
    }
    // 0x800C9ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9AC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C9AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C9AC8: addu        $at, $at, $t6
    gpr jr_addend_800C9AD0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C9ACC: lw          $t6, 0x594C($at)
    ctx->r14 = ADD32(ctx->r1, 0X594C);
    // 0x800C9AD0: jr          $t6
    // 0x800C9AD4: nop

    switch (jr_addend_800C9AD0 >> 2) {
        case 0: goto L_800C9B08; break;
        case 1: goto L_800C9AD8; break;
        case 2: goto L_800C9AE8; break;
        case 3: goto L_800C9AF8; break;
        case 4: goto L_800C9B20; break;
        case 5: goto L_800C9B18; break;
        default: switch_error(__func__, 0x800C9AD0, 0x8012594C);
    }
    // 0x800C9AD4: nop

L_800C9AD8:
    // 0x800C9AD8: jal         0x80090708
    // 0x800C9ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090708(rdram, ctx);
        goto after_0;
    // 0x800C9ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C9AE0: b           L_800C9B24
    // 0x800C9AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9B24;
    // 0x800C9AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9AE8:
    // 0x800C9AE8: jal         0x80090708
    // 0x800C9AEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80090708(rdram, ctx);
        goto after_1;
    // 0x800C9AEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x800C9AF0: b           L_800C9B24
    // 0x800C9AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9B24;
    // 0x800C9AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9AF8:
    // 0x800C9AF8: jal         0x80090708
    // 0x800C9AFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_2;
    // 0x800C9AFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800C9B00: b           L_800C9B24
    // 0x800C9B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9B24;
    // 0x800C9B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9B08:
    // 0x800C9B08: jal         0x80090708
    // 0x800C9B0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x800C9B0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800C9B10: b           L_800C9B24
    // 0x800C9B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9B24;
    // 0x800C9B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9B18:
    // 0x800C9B18: jal         0x800A51C0
    // 0x800C9B1C: nop

    func_800A51C0(rdram, ctx);
        goto after_4;
    // 0x800C9B1C: nop

    after_4:
L_800C9B20:
    // 0x800C9B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9B24:
    // 0x800C9B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9B28: jr          $ra
    // 0x800C9B2C: nop

    return;
    // 0x800C9B2C: nop

;}
RECOMP_FUNC void func_800D6C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6C3C: jal         0x800D6254
    // 0x800D6C40: nop

    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D6C40: nop

    after_0:
    // 0x800D6C44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6C48: beq         $v0, $at, L_800D6C58
    if (ctx->r2 == ctx->r1) {
        // 0x800D6C4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D6C58;
    }
    // 0x800D6C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D6C50: b           L_800D6C5C
    // 0x800D6C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D6C5C;
    // 0x800D6C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D6C58:
    // 0x800D6C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6C5C:
    // 0x800D6C5C: jr          $ra
    // 0x800D6C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D6C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800280_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800288: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080028C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800290: jal         0x80100094
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800298: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080029C: jal         0x80800AD0
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AD0_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002A4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808002A8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808002AC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808002B0: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808002B4: beq         $at, $zero, L_80800404
    if (ctx->r1 == 0) {
        // 0x808002B8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800404;
    }
    // 0x808002B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X2450) << 16);
    // 0x808002C0: addu        $at, $at, $t8
    gpr jr_addend_808002C8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808002C4: lw          $t8, 0x2450($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2204, 0X2450));
    // 0x808002C8: jr          $t8
    // 0x808002CC: nop

    switch (jr_addend_808002C8 >> 2) {
        case 0: goto L_808002D0; break;
        case 1: goto L_80800314; break;
        case 2: goto L_80800394; break;
        case 3: goto L_808003D4; break;
        case 4: goto L_808003F0; break;
        default: switch_error(__func__, 0x808002C8, 0x80802450);
    }
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: jal         0x8010D248
    // 0x808002D4: nop

    func_8010D248(rdram, ctx);
        goto after_2;
    // 0x808002D4: nop

    after_2:
    // 0x808002D8: beq         $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x808002DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E8;
    }
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x808004BC
    // 0x808002E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_3;
    // 0x808002E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_808002E8:
    // 0x808002E8: jal         0x8010CD28
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_4;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002F0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808002F4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808002F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800304: jal         0x80102BF8
    // 0x80800308: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    func_80102BF8(rdram, ctx);
        goto after_5;
    // 0x80800308: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    after_5:
    // 0x8080030C: b           L_80800404
    // 0x80800310: nop

        goto L_80800404;
    // 0x80800310: nop

L_80800314:
    // 0x80800314: andi        $v1, $v0, 0x4
    ctx->r3 = ctx->r2 & 0X4;
    // 0x80800318: beql        $v1, $zero, L_80800330
    if (ctx->r3 == 0) {
        // 0x8080031C: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_80800330;
    }
    goto skip_0;
    // 0x8080031C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800320: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800324: nop

    // 0x80800328: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x8080032C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_80800330:
    // 0x80800330: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800334: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x80800338: bne         $t0, $at, L_80800404
    if (ctx->r8 != ctx->r1) {
        // 0x8080033C: nop
    
            goto L_80800404;
    }
    // 0x8080033C: nop

    // 0x80800340: beq         $v1, $zero, L_80800384
    if (ctx->r3 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8080034C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800350: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80800354: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800358: jal         0x800DC178
    // 0x8080035C: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x8080035C: nop

    after_6:
    // 0x80800360: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800364: jal         0x800136E4
    // 0x80800368: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80800368: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_7:
    // 0x8080036C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x808004BC
    // 0x80800378: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80800378: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080037C: b           L_80800404
    // 0x80800380: nop

        goto L_80800404;
    // 0x80800380: nop

L_80800384:
    // 0x80800384: jal         0x808004BC
    // 0x80800388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_9;
    // 0x80800388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080038C: b           L_80800404
    // 0x80800390: nop

        goto L_80800404;
    // 0x80800390: nop

L_80800394:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x8080039C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808003A0: jal         0x80102BF8
    // 0x808003A4: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    func_80102BF8(rdram, ctx);
        goto after_10;
    // 0x808003A4: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    after_10:
    // 0x808003A8: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808003AC: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x808003B8: nop

    // 0x808003BC: bc1f        L_80800404
    if (!c1cs) {
        // 0x808003C0: nop
    
            goto L_80800404;
    }
    // 0x808003C0: nop

    // 0x808003C4: jal         0x808004BC
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004BC_chtntmineshoot(rdram, ctx);
        goto after_11;
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808003CC: b           L_80800404
    // 0x808003D0: nop

        goto L_80800404;
    // 0x808003D0: nop

L_808003D4:
    // 0x808003D4: jal         0x80800000
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chtntmineshoot(rdram, ctx);
        goto after_12;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: jal         0x80108B04
    // 0x808003E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80108B04(rdram, ctx);
        goto after_13;
    // 0x808003E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x808003E8: b           L_80800404
    // 0x808003EC: nop

        goto L_80800404;
    // 0x808003EC: nop

L_808003F0:
    // 0x808003F0: jal         0x8080003C
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080003C_chtntmineshoot(rdram, ctx);
        goto after_14;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x80108B04
    // 0x80800400: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80108B04(rdram, ctx);
        goto after_15;
    // 0x80800400: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
L_80800404:
    // 0x80800404: jal         0x80103EF4
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_16;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080040C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800410: jal         0x80103EAC
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_17;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800418: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080041C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800420: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800424: jal         0x8008FB10
    // 0x80800428: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8008FB10(rdram, ctx);
        goto after_18;
    // 0x80800428: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_18:
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800434: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void func_80800314_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080031C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800320: jal         0x80102424
    // 0x80800324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800328: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080032C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800330: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800334: beq         $a1, $at, L_80800358
    if (ctx->r5 == ctx->r1) {
        // 0x80800338: addiu       $a0, $a3, 0x18
        ctx->r4 = ADD32(ctx->r7, 0X18);
            goto L_80800358;
    }
    // 0x80800338: addiu       $a0, $a3, 0x18
    ctx->r4 = ADD32(ctx->r7, 0X18);
    // 0x8080033C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800340: beq         $a1, $at, L_808003A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800344: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003A8;
    }
    // 0x80800344: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800348: beq         $a1, $at, L_808003A8
    if (ctx->r5 == ctx->r1) {
        // 0x8080034C: nop
    
            goto L_808003A8;
    }
    // 0x8080034C: nop

    // 0x80800350: b           L_808003B4
    // 0x80800354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B4;
    // 0x80800354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800358:
    // 0x80800358: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x8080035C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800360: jal         0x800EE7F8
    // 0x80800364: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800364: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800368: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8080036C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800370: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800374: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800378: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080037C: lwc1        $f10, 0x38($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X38);
    // 0x80800380: lwc1        $f4, 0x48($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X48);
    // 0x80800384: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080038C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800390: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800394: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800398: jal         0x800EF1B8
    // 0x8080039C: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x8080039C: nop

    after_2:
    // 0x808003A0: b           L_808003B4
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003B4;
    // 0x808003A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003A8:
    // 0x808003A8: jal         0x80800224
    // 0x808003AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800224_chblackeye(rdram, ctx);
        goto after_3;
    // 0x808003AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B4:
    // 0x808003B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void func_80800024_chbilldrillboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: jal         0x808004D4
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808004D4_chbilldrillboulder(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800038: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8080003C: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80800040: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800044: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800048: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x8080004C: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800050: xori        $t8, $t7, 0x322
    ctx->r24 = ctx->r15 ^ 0X322;
    // 0x80800054: bne         $t8, $zero, L_80800068
    if (ctx->r24 != 0) {
        // 0x80800058: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800068;
    }
    // 0x80800058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080005C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1908, 0X684) << 16);
    // 0x80800060: b           L_80800070
    // 0x80800064: addiu       $v0, $v0, 0x684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X684));
        goto L_80800070;
    // 0x80800064: addiu       $v0, $v0, 0x684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X684));
L_80800068:
    // 0x80800068: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1908, 0X618) << 16);
    // 0x8080006C: addiu       $v0, $v0, 0x618
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X618));
L_80800070:
    // 0x80800070: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800074: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800078: jal         0x800BABB8
    // 0x8080007C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x8080007C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800080: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1908, 0X6F0) << 16);
    // 0x80800084: addiu       $a2, $a2, 0x6F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1908, 0X6F0));
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80089D18
    // 0x80800090: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800090: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800094: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80800098: beql        $a0, $zero, L_8080014C
    if (ctx->r4 == 0) {
        // 0x8080009C: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_8080014C;
    }
    goto skip_0;
    // 0x8080009C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808000A0: jal         0x800DA544
    // 0x808000A4: nop

    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808000A4: nop

    after_3:
    // 0x808000A8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x808000AC: addiu       $at, $zero, 0x514
    ctx->r1 = ADD32(0, 0X514);
    // 0x808000B0: bnel        $t9, $at, L_8080014C
    if (ctx->r25 != ctx->r1) {
        // 0x808000B4: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_8080014C;
    }
    goto skip_1;
    // 0x808000B4: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_1:
    // 0x808000B8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x808000BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808000C0: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x808000C4: bgez        $t2, L_8080010C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808000C8: nop
    
            goto L_8080010C;
    }
    // 0x808000C8: nop

    // 0x808000CC: jal         0x800EE7F8
    // 0x808000D0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808000D0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808000D4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808000D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000DC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000E0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808000E4: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x808000E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808000EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808000F0: jal         0x800EF1B8
    // 0x808000F4: nop

    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x808000F4: nop

    after_5:
    // 0x808000F8: jal         0x800F54E4
    // 0x808000FC: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808000FC: nop

    after_6:
    // 0x80800100: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800104: jal         0x800F77E8
    // 0x80800108: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F77E8(rdram, ctx);
        goto after_7;
    // 0x80800108: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_7:
L_8080010C:
    // 0x8080010C: jal         0x800F54E4
    // 0x80800110: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800110: nop

    after_8:
    // 0x80800114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800118: jal         0x800F7F98
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_9;
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800120: addiu       $a0, $zero, 0x117
    ctx->r4 = ADD32(0, 0X117);
    // 0x80800124: jal         0x80089C30
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080012C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800134: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80800138: jal         0x80085748
    // 0x8080013C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_11;
    // 0x8080013C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80800140: jal         0x800DA544
    // 0x80800144: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    func_800DA544(rdram, ctx);
        goto after_12;
    // 0x80800144: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_12:
    // 0x80800148: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_8080014C:
    // 0x8080014C: addiu       $at, $zero, 0x3CF
    ctx->r1 = ADD32(0, 0X3CF);
    // 0x80800150: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800154: sll         $t3, $v0, 11
    ctx->r11 = S32(ctx->r2 << 11);
    // 0x80800158: srl         $t4, $t3, 20
    ctx->r12 = S32(U32(ctx->r11) >> 20);
    // 0x8080015C: bnel        $t4, $at, L_8080025C
    if (ctx->r12 != ctx->r1) {
        // 0x80800160: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080025C;
    }
    goto skip_2;
    // 0x80800160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800164: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80800168: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x8080016C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800170: addiu       $t8, $t7, -0x33
    ctx->r24 = ADD32(ctx->r15, -0X33);
    // 0x80800174: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800178: beq         $at, $zero, L_808001FC
    if (ctx->r1 == 0) {
        // 0x8080017C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808001FC;
    }
    // 0x8080017C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1908, 0X520) << 16);
    // 0x80800184: addu        $at, $at, $t8
    gpr jr_addend_8080018C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800188: lw          $t8, 0x520($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1908, 0X520));
    // 0x8080018C: jr          $t8
    // 0x80800190: nop

    switch (jr_addend_8080018C >> 2) {
        case 0: goto L_80800194; break;
        case 1: goto L_808001B4; break;
        case 2: goto L_808001C0; break;
        case 3: goto L_808001CC; break;
        case 4: goto L_808001D8; break;
        case 5: goto L_808001E4; break;
        default: switch_error(__func__, 0x8080018C, 0x80800520);
    }
    // 0x80800190: nop

L_80800194:
    // 0x80800194: andi        $a0, $v0, 0x1FF
    ctx->r4 = ctx->r2 & 0X1FF;
    // 0x80800198: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080019C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808001A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001A4: jal         0x800D1000
    // 0x808001A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_13;
    // 0x808001A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x808001AC: b           L_80800200
    // 0x808001B0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
        goto L_80800200;
    // 0x808001B0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
L_808001B4:
    // 0x808001B4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808001B8: b           L_808001FC
    // 0x808001BC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_808001FC;
    // 0x808001BC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_808001C0:
    // 0x808001C0: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x808001C4: b           L_808001FC
    // 0x808001C8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_808001FC;
    // 0x808001C8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_808001CC:
    // 0x808001CC: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x808001D0: b           L_808001FC
    // 0x808001D4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_808001FC;
    // 0x808001D4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_808001D8:
    // 0x808001D8: addiu       $t2, $zero, 0x17
    ctx->r10 = ADD32(0, 0X17);
    // 0x808001DC: b           L_808001FC
    // 0x808001E0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_808001FC;
    // 0x808001E0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_808001E4:
    // 0x808001E4: andi        $a0, $v0, 0x1FF
    ctx->r4 = ctx->r2 & 0X1FF;
    // 0x808001E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001EC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808001F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001F4: jal         0x800D1000
    // 0x808001F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_14;
    // 0x808001F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
L_808001FC:
    // 0x808001FC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
L_80800200:
    // 0x80800200: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800204: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800208: beql        $t3, $at, L_8080025C
    if (ctx->r11 == ctx->r1) {
        // 0x8080020C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080025C;
    }
    goto skip_3;
    // 0x8080020C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800210: jal         0x800EE7F8
    // 0x80800214: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80800214: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x80800218: jal         0x80103EF4
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_16;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800220: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800224: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800228: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080022C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80800230: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800234: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800238: addiu       $a0, $a0, 0x6D70
    ctx->r4 = ADD32(ctx->r4, 0X6D70);
    // 0x8080023C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800240: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800244: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800248: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8080024C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80800250: jal         0x80086D48
    // 0x80800254: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800254: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_17:
    // 0x80800258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080025C:
    // 0x8080025C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void func_808002E8_chanemone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002F0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808002F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002FC: beq         $a1, $at, L_80800324
    if (ctx->r5 == ctx->r1) {
        // 0x80800300: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800324;
    }
    // 0x80800300: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800304: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800308: beq         $a1, $at, L_80800338
    if (ctx->r5 == ctx->r1) {
        // 0x8080030C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800338;
    }
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x80800314: beql        $a1, $at, L_80800350
    if (ctx->r5 == ctx->r1) {
        // 0x80800318: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800350;
    }
    goto skip_0;
    // 0x80800318: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8080031C: b           L_80800394
    // 0x80800320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800394;
    // 0x80800320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800324:
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: jal         0x808005A0
    // 0x8080032C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808005A0_chanemone(rdram, ctx);
        goto after_0;
    // 0x8080032C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800330: b           L_80800394
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080033C: jal         0x80089FF0
    // 0x80800340: addiu       $a1, $a1, 0x5F50
    ctx->r5 = ADD32(ctx->r5, 0X5F50);
    _subaddiecustomhits_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800340: addiu       $a1, $a1, 0x5F50
    ctx->r5 = ADD32(ctx->r5, 0X5F50);
    after_1:
    // 0x80800344: b           L_80800394
    // 0x80800348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x80800348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080034C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800350:
    // 0x80800350: jal         0x8010262C
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010262C(rdram, ctx);
        goto after_2;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800358: beq         $v0, $zero, L_80800390
    if (ctx->r2 == 0) {
        // 0x8080035C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800390;
    }
    // 0x8080035C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800360: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800368: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x8080036C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80800370: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800374: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800378: jal         0x800E0AFC
    // 0x8080037C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x8080037C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800380: b           L_80800394
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800394;
    // 0x80800384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800388: b           L_80800394
    // 0x8080038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800394;
    // 0x8080038C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800390:
    // 0x80800390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800394:
    // 0x80800394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800398: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080039C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void bskazstill_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080069C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A0: jal         0x800832E8
    // 0x808006A4: nop

    _bskaz_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808006A4: nop

    after_0:
    // 0x808006A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006B0: jr          $ra
    // 0x808006B4: nop

    return;
    // 0x808006B4: nop

;}
RECOMP_FUNC void func_80800870_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080087C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800880: jal         0x8008CABC
    // 0x80800884: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800884: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800888: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x8080088C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800890: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800894: jal         0x8008B348
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080089C: beq         $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x808008A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008AC;
    }
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: jal         0x8009FD24
    // 0x808008A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FD24(rdram, ctx);
        goto after_2;
    // 0x808008A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808008AC:
    // 0x808008AC: lui         $a1, 0x3F61
    ctx->r5 = S32(0X3F61 << 16);
    // 0x808008B0: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x808008B4: jal         0x8008B348
    // 0x808008B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808008B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808008BC: beq         $v0, $zero, L_808008CC
    if (ctx->r2 == 0) {
        // 0x808008C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008CC;
    }
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C4: jal         0x8009FD24
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009FD24(rdram, ctx);
        goto after_4;
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_808008CC:
    // 0x808008CC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808008D0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808008D4: jal         0x8008B348
    // 0x808008D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808008D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808008DC: beq         $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x808008E0: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_808008FC;
    }
    // 0x808008E0: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808008E4: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808008E8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808008EC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F4: jal         0x8009DE74
    // 0x808008F8: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_6;
    // 0x808008F8: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_6:
L_808008FC:
    // 0x808008FC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800900: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800904: jal         0x8008B348
    // 0x80800908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8080090C: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x80800910: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080092C;
    }
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800918: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x8080091C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800920: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800924: jal         0x8009DE74
    // 0x80800928: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_8;
    // 0x80800928: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_8:
L_8080092C:
    // 0x8080092C: jal         0x808000B0
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B0_bsmumswim(rdram, ctx);
        goto after_9;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800934: jal         0x8009EF10
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_10;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080093C: bne         $v0, $zero, L_80800948
    if (ctx->r2 != 0) {
        // 0x80800940: addiu       $t6, $zero, 0xF0
        ctx->r14 = ADD32(0, 0XF0);
            goto L_80800948;
    }
    // 0x80800940: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x80800944: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800948:
    // 0x80800948: jal         0x8008E35C
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800950: bne         $v0, $zero, L_8080095C
    if (ctx->r2 != 0) {
        // 0x80800954: addiu       $t7, $zero, 0xE5
        ctx->r15 = ADD32(0, 0XE5);
            goto L_8080095C;
    }
    // 0x80800954: addiu       $t7, $zero, 0xE5
    ctx->r15 = ADD32(0, 0XE5);
    // 0x80800958: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080095C:
    // 0x8080095C: jal         0x80096500
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_12;
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800964: beq         $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800968: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800980;
    }
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: jal         0x80091A58
    // 0x80800970: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x80800970: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x80800974: beq         $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800978: addiu       $t8, $zero, 0xE8
        ctx->r24 = ADD32(0, 0XE8);
            goto L_80800980;
    }
    // 0x80800978: addiu       $t8, $zero, 0xE8
    ctx->r24 = ADD32(0, 0XE8);
    // 0x8080097C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800980:
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: jal         0x8009E5C8
    // 0x80800988: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x80800988: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x8080098C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800998: jr          $ra
    // 0x8080099C: nop

    return;
    // 0x8080099C: nop

;}
RECOMP_FUNC void func_808001E4_chwaterfallfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808001E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808001EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808001F0: jr          $ra
    // 0x808001F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808001F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void scinfobar_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x808005EC: xori        $t6, $v0, 0x66
    ctx->r14 = ctx->r2 ^ 0X66;
    // 0x808005F0: jr          $ra
    // 0x808005F4: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x808005F4: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_8009FD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FD24: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8009FD28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8009FD2C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009FD30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009FD34: jal         0x80096544
    // 0x8009FD38: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x8009FD38: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009FD3C: beq         $v0, $zero, L_8009FE44
    if (ctx->r2 == 0) {
        // 0x8009FD40: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_8009FE44;
    }
    // 0x8009FD40: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8009FD44: beq         $t6, $zero, L_8009FD60
    if (ctx->r14 == 0) {
        // 0x8009FD48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009FD60;
    }
    // 0x8009FD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009FD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009FD50: jal         0x80092C24
    // 0x8009FD54: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80092C24(rdram, ctx);
        goto after_1;
    // 0x8009FD54: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x8009FD58: b           L_8009FD68
    // 0x8009FD5C: nop

        goto L_8009FD68;
    // 0x8009FD5C: nop

L_8009FD60:
    // 0x8009FD60: jal         0x80092C00
    // 0x8009FD64: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80092C00(rdram, ctx);
        goto after_2;
    // 0x8009FD64: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
L_8009FD68:
    // 0x8009FD68: jal         0x800964DC
    // 0x8009FD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_3;
    // 0x8009FD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8009FD70: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8009FD74: jal         0x8009C984
    // 0x8009FD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x8009FD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009FD7C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8009FD80: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x8009FD84: jal         0x80088AE8
    // 0x8009FD88: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    _fxsplash_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8009FD88: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8009FD8C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8009FD90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009FD94: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009FD98: addiu       $t1, $zero, -0x78
    ctx->r9 = ADD32(0, -0X78);
    // 0x8009FD9C: addiu       $t5, $zero, 0xFA
    ctx->r13 = ADD32(0, 0XFA);
    // 0x8009FDA0: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8009FDA4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8009FDA8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8009FDAC: add.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8009FDB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009FDB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009FDB8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009FDBC: addiu       $a1, $zero, -0x8C
    ctx->r5 = ADD32(0, -0X8C);
    // 0x8009FDC0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x8009FDC4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009FDC8: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8009FDCC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8009FDD0: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x8009FDD4: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8009FDD8: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8009FDDC: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x8009FDE0: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8009FDE4: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8009FDE8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8009FDEC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8009FDF0: jal         0x800BA994
    // 0x8009FDF4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800BA994(rdram, ctx);
        goto after_6;
    // 0x8009FDF4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_6:
    // 0x8009FDF8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8009FDFC: jal         0x800BA22C
    // 0x8009FE00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x8009FE00: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x8009FE04: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8009FE08: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8009FE0C: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8009FE10: addiu       $t7, $zero, -0x5A
    ctx->r15 = ADD32(0, -0X5A);
    // 0x8009FE14: addiu       $t9, $zero, 0x190
    ctx->r25 = ADD32(0, 0X190);
    // 0x8009FE18: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009FE1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009FE20: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8009FE24: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8009FE28: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x8009FE2C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x8009FE30: jal         0x800BA994
    // 0x8009FE34: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800BA994(rdram, ctx);
        goto after_8;
    // 0x8009FE34: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_8:
    // 0x8009FE38: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8009FE3C: jal         0x800BA22C
    // 0x8009FE40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_9;
    // 0x8009FE40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
L_8009FE44:
    // 0x8009FE44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8009FE48: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009FE4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8009FE50: jr          $ra
    // 0x8009FE54: nop

    return;
    // 0x8009FE54: nop

;}
RECOMP_FUNC void func_80800924_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080092C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800930: jal         0x80801020
    // 0x80800934: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80801020_chbilldrillplate(rdram, ctx);
        goto after_0;
    // 0x80800934: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800938: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8080093C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800940: beql        $t6, $zero, L_80800954
    if (ctx->r14 == 0) {
        // 0x80800944: lw          $a1, 0x2C($t7)
        ctx->r5 = MEM_W(ctx->r15, 0X2C);
            goto L_80800954;
    }
    goto skip_0;
    // 0x80800944: lw          $a1, 0x2C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X2C);
    skip_0:
    // 0x80800948: b           L_80800954
    // 0x8080094C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800954;
    // 0x8080094C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800950: lw          $a1, 0x2C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X2C);
L_80800954:
    // 0x80800954: jal         0x800DF744
    // 0x80800958: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800958: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080095C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800960: jal         0x80101870
    // 0x80800964: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80800964: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080096C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800970: jr          $ra
    // 0x80800974: nop

    return;
    // 0x80800974: nop

;}
RECOMP_FUNC void func_800D743C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D743C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7444: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7448: jal         0x800884E0
    // 0x800D744C: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    _glsplineDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800D744C: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    after_0:
    // 0x800D7450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7458: jr          $ra
    // 0x800D745C: nop

    return;
    // 0x800D745C: nop

;}
RECOMP_FUNC void func_800E8B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8B74: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E8B78: addiu       $a2, $a2, -0x2980
    ctx->r6 = ADD32(ctx->r6, -0X2980);
    // 0x800E8B7C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800E8B80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E8B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8B88: bne         $t6, $zero, L_800E8BA8
    if (ctx->r14 != 0) {
        // 0x800E8B8C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_800E8BA8;
    }
    // 0x800E8B8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E8B90: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x800E8B94: jal         0x800B3268
    // 0x800E8B98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x800E8B98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800E8B9C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E8BA0: addiu       $a2, $a2, -0x2980
    ctx->r6 = ADD32(ctx->r6, -0X2980);
    // 0x800E8BA4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800E8BA8:
    // 0x800E8BA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E8BAC: jal         0x800B3044
    // 0x800E8BB0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    freelist_next(rdram, ctx);
        goto after_1;
    // 0x800E8BB0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800E8BB4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800E8BB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E8BBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E8BC0: beq         $t7, $zero, L_800E8BE4
    if (ctx->r15 == 0) {
        // 0x800E8BC4: nop
    
            goto L_800E8BE4;
    }
    // 0x800E8BC4: nop

    // 0x800E8BC8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800E8BCC: jal         0x800D674C
    // 0x800E8BD0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x800E8BD0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x800E8BD4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800E8BD8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800E8BDC: b           L_800E8BEC
    // 0x800E8BE0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_800E8BEC;
    // 0x800E8BE0: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_800E8BE4:
    // 0x800E8BE4: jal         0x8002D6E0
    // 0x800E8BE8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    _bzero(rdram, ctx);
        goto after_3;
    // 0x800E8BE8: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_3:
L_800E8BEC:
    // 0x800E8BEC: jal         0x800E8CDC
    // 0x800E8BF0: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800E8CDC(rdram, ctx);
        goto after_4;
    // 0x800E8BF0: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_4:
    // 0x800E8BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8BF8: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x800E8BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E8C00: jr          $ra
    // 0x800E8C04: nop

    return;
    // 0x800E8C04: nop

;}
RECOMP_FUNC void func_80101970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010197C: lw          $a0, 0x70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70);
    // 0x80101980: sll         $t7, $a0, 11
    ctx->r15 = S32(ctx->r4 << 11);
    // 0x80101984: jal         0x800DF470
    // 0x80101988: srl         $a0, $t7, 31
    ctx->r4 = S32(U32(ctx->r15) >> 31);
    func_800DF470(rdram, ctx);
        goto after_0;
    // 0x80101988: srl         $a0, $t7, 31
    ctx->r4 = S32(U32(ctx->r15) >> 31);
    after_0:
    // 0x8010198C: jal         0x80100368
    // 0x80101990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80100368(rdram, ctx);
        goto after_1;
    // 0x80101990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80101994: lhu         $t9, 0x1A($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1A);
    // 0x80101998: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010199C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801019A0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801019A4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x801019A8: bgez        $t9, L_801019BC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801019AC: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801019BC;
    }
    // 0x801019AC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801019B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801019B4: nop

    // 0x801019B8: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_801019BC:
    // 0x801019BC: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x801019C0: nop

    // 0x801019C4: bc1tl       L_801019E0
    if (c1cs) {
        // 0x801019C8: lw          $t1, 0x0($t0)
        ctx->r9 = MEM_W(ctx->r8, 0X0);
            goto L_801019E0;
    }
    goto skip_0;
    // 0x801019C8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x801019CC: jal         0x800DF428
    // 0x801019D0: nop

    func_800DF428(rdram, ctx);
        goto after_2;
    // 0x801019D0: nop

    after_2:
    // 0x801019D4: b           L_80101A28
    // 0x801019D8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
        goto L_80101A28;
    // 0x801019D8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x801019DC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
L_801019E0:
    // 0x801019E0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x801019E4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801019E8: bnel        $t3, $zero, L_80101A28
    if (ctx->r11 != 0) {
        // 0x801019EC: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_80101A28;
    }
    goto skip_1;
    // 0x801019EC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x801019F0: jal         0x800EA068
    // 0x801019F4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800EA068(rdram, ctx);
        goto after_3;
    // 0x801019F4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_3:
    // 0x801019F8: beq         $v0, $zero, L_80101A08
    if (ctx->r2 == 0) {
        // 0x801019FC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80101A08;
    }
    // 0x801019FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101A00: b           L_80101A1C
    // 0x80101A04: lwc1        $f12, 0x6430($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6430);
        goto L_80101A1C;
    // 0x80101A04: lwc1        $f12, 0x6430($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6430);
L_80101A08:
    // 0x80101A08: jal         0x800D2F20
    // 0x80101A0C: nop

    func_800D2F20(rdram, ctx);
        goto after_4;
    // 0x80101A0C: nop

    after_4:
    tooie_model_draw_distance(rdram, ctx);
    // 0x80101A10: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80101A14: nop

    // 0x80101A18: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
L_80101A1C:
    // 0x80101A1C: jal         0x800DF428
    // 0x80101A20: nop

    func_800DF428(rdram, ctx);
        goto after_5;
    // 0x80101A20: nop

    after_5:
    // 0x80101A24: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
L_80101A28:
    // 0x80101A28: lw          $t5, 0x94($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X94);
    // 0x80101A2C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80101A30: bgezl       $t7, L_80101A44
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80101A34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80101A44;
    }
    goto skip_2;
    // 0x80101A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80101A38: jal         0x800DF440
    // 0x80101A3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_6;
    // 0x80101A3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80101A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101A44:
    // 0x80101A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101A48: jr          $ra
    // 0x80101A4C: nop

    return;
    // 0x80101A4C: nop

;}
RECOMP_FUNC void func_80801368_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080136C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801374: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80801378: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8080137C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801380: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801384: nop

    // 0x80801388: bc1fl       L_808013A8
    if (!c1cs) {
        // 0x8080138C: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_808013A8;
    }
    goto skip_0;
    // 0x8080138C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80801390: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801394: jal         0x800D90F8
    // 0x80801398: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90F8(rdram, ctx);
        goto after_0;
    // 0x80801398: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x8080139C: b           L_808013B0
    // 0x808013A0: nop

        goto L_808013B0;
    // 0x808013A0: nop

    // 0x808013A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_808013A8:
    // 0x808013A8: jal         0x800D91EC
    // 0x808013AC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D91EC(rdram, ctx);
        goto after_1;
    // 0x808013AC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
L_808013B0:
    // 0x808013B0: beq         $v0, $zero, L_808013CC
    if (ctx->r2 == 0) {
        // 0x808013B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808013CC;
    }
    // 0x808013B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808013B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808013BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808013C0: jal         0x800DC178
    // 0x808013C4: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808013C4: nop

    after_2:
    // 0x808013C8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_808013CC:
    // 0x808013CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808013D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808013D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013D8: jr          $ra
    // 0x808013DC: nop

    return;
    // 0x808013DC: nop

;}
RECOMP_FUNC void func_800C2B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C2B84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C2B88: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C2B8C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C2B90: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C2B94: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C2B98: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C2B9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C2BA0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800C2BA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C2BA8: addiu       $s0, $s0, -0x73F0
    ctx->r16 = ADD32(ctx->r16, -0X73F0);
    // 0x800C2BAC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800C2BB0: addiu       $s2, $zero, 0x3C
    ctx->r18 = ADD32(0, 0X3C);
    // 0x800C2BB4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800C2BB8: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_800C2BBC:
    // 0x800C2BBC: lbu         $t6, 0x78($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X78);
    // 0x800C2BC0: beql        $t6, $zero, L_800C2C20
    if (ctx->r14 == 0) {
        // 0x800C2BC4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C2C20;
    }
    goto skip_0;
    // 0x800C2BC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800C2BC8: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x800C2BCC: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x800C2BD0: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800C2BD4: beql        $s3, $t9, L_800C2C20
    if (ctx->r19 == ctx->r25) {
        // 0x800C2BD8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C2C20;
    }
    goto skip_1;
    // 0x800C2BD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800C2BDC: lbu         $v0, 0x62($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X62);
    // 0x800C2BE0: beql        $s4, $v0, L_800C2C20
    if (ctx->r20 == ctx->r2) {
        // 0x800C2BE4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C2C20;
    }
    goto skip_2;
    // 0x800C2BE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x800C2BE8: bne         $v0, $zero, L_800C2C00
    if (ctx->r2 != 0) {
        // 0x800C2BEC: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_800C2C00;
    }
    // 0x800C2BEC: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800C2BF0: jal         0x800C2FDC
    // 0x800C2BF4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x800C2BF4: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_0:
    // 0x800C2BF8: b           L_800C2C20
    // 0x800C2BFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800C2C20;
    // 0x800C2BFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C2C00:
    // 0x800C2C00: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C2C04: bne         $t1, $zero, L_800C2C1C
    if (ctx->r9 != 0) {
        // 0x800C2C08: sb          $t0, 0x62($s0)
        MEM_B(0X62, ctx->r16) = ctx->r8;
            goto L_800C2C1C;
    }
    // 0x800C2C08: sb          $t0, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r8;
    // 0x800C2C0C: lbu         $t3, 0x7B($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7B);
    // 0x800C2C10: swc1        $f20, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f20.u32l;
    // 0x800C2C14: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x800C2C18: sb          $t4, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r12;
L_800C2C1C:
    // 0x800C2C1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C2C20:
    // 0x800C2C20: bne         $s1, $s2, L_800C2BBC
    if (ctx->r17 != ctx->r18) {
        // 0x800C2C24: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_800C2BBC;
    }
    // 0x800C2C24: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x800C2C28: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C2C2C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C2C30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C2C34: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C2C38: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C2C3C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2C40: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C2C44: jr          $ra
    // 0x800C2C48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C2C48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882A0: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882A0);
    return;
    // 0x800882A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _baalarm_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084430: syscall     110
    recomp_syscall_handler(rdram, ctx, 0x80084430);
    return;
    // 0x80084434: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80100094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100098: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8010009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801000A0: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x801000A4: lh          $a2, 0x82($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X82);
    // 0x801000A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801000AC: beq         $a2, $zero, L_801000C8
    if (ctx->r6 == 0) {
        // 0x801000B0: sll         $a0, $a2, 16
        ctx->r4 = S32(ctx->r6 << 16);
            goto L_801000C8;
    }
    // 0x801000B0: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x801000B4: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801000B8: jal         0x8001B798
    // 0x801000BC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x801000BC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x801000C0: b           L_801000CC
    // 0x801000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801000CC;
    // 0x801000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801000C8:
    // 0x801000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801000CC:
    // 0x801000CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801000D0: jr          $ra
    // 0x801000D4: nop

    return;
    // 0x801000D4: nop

;}
RECOMP_FUNC void chfpsgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2216, 0X21A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x21A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2216, 0X21A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x21A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2216, 0X21A0));
;}
RECOMP_FUNC void func_8008FC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FC30: jal         0x800F54E4
    // 0x8008FC34: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FC34: nop

    after_0:
    // 0x8008FC38: jal         0x800F55A4
    // 0x8008FC3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55A4(rdram, ctx);
        goto after_1;
    // 0x8008FC3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FC44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FC48: jr          $ra
    // 0x8008FC4C: nop

    return;
    // 0x8008FC4C: nop

;}
RECOMP_FUNC void func_80025FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025FE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025FE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80025FEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80025FF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80025FF4: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80025FF8: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80025FFC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80026000: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80026004: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80026008: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8002600C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80026010: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80026014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026018: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002601C: jal         0x80026500
    // 0x80026020: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80026020: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80026024: b           L_8002602C
    // 0x80026028: nop

        goto L_8002602C;
    // 0x80026028: nop

L_8002602C:
    // 0x8002602C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026034: jr          $ra
    // 0x80026038: nop

    return;
    // 0x80026038: nop

;}
RECOMP_FUNC void func_800B3370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3378: jal         0x8001B084
    // 0x800B337C: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800B337C: nop

    after_0:
    // 0x800B3380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3388: jr          $ra
    // 0x800B338C: nop

    return;
    // 0x800B338C: nop

;}
RECOMP_FUNC void subaddielink_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80800050: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800054: beql        $a2, $zero, L_808000A4
    if (ctx->r6 == 0) {
        // 0x80800058: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000A4;
    }
    goto skip_0;
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080005C: lhu         $t6, 0x12($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X12);
    // 0x80800060: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80800064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800068: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8080006C: bnel        $t7, $t8, L_8080009C
    if (ctx->r15 != ctx->r24) {
        // 0x80800070: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_8080009C;
    }
    goto skip_1;
    // 0x80800070: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_1:
    // 0x80800074: jal         0x80106790
    // 0x80800078: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080007C: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x80800080: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80800088: bltzl       $t1, L_8080009C
    if (SIGNED(ctx->r9) < 0) {
        // 0x8080008C: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_8080009C;
    }
    goto skip_2;
    // 0x8080008C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_2:
    // 0x80800090: b           L_808000A4
    // 0x80800094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000A4;
    // 0x80800094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800098: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8080009C:
    // 0x8080009C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x808000A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000A4:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80808258_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808258: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080825C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80808260: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80808264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808268: jal         0x80100094
    // 0x8080826C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080826C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808270: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80808274: lbu         $a1, 0x2($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2);
    // 0x80808278: addiu       $a0, $zero, 0x10A
    ctx->r4 = ADD32(0, 0X10A);
    // 0x8080827C: jal         0x800D2498
    // 0x80808280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_1;
    // 0x80808280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80808284: jal         0x808087F0
    // 0x80808288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808087F0_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80808288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080828C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80808290: lbu         $t6, 0xCC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XCC);
    // 0x80808294: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80808298: beq         $at, $zero, L_80808428
    if (ctx->r1 == 0) {
        // 0x8080829C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80808428;
    }
    // 0x8080829C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808082A0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C38) << 16);
    // 0x808082A4: addu        $at, $at, $t6
    gpr jr_addend_808082AC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808082A8: lw          $t6, -0x63C8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C38));
    // 0x808082AC: jr          $t6
    // 0x808082B0: nop

    switch (jr_addend_808082AC >> 2) {
        case 0: goto L_80808428; break;
        case 1: goto L_808082B4; break;
        case 2: goto L_808082C8; break;
        case 3: goto L_80808358; break;
        case 4: goto L_80808374; break;
        case 5: goto L_8080839C; break;
        default: switch_error(__func__, 0x808082AC, 0x80809C38);
    }
    // 0x808082B0: nop

L_808082B4:
    // 0x808082B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808082B8: jal         0x80108B04
    // 0x808082BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x808082BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x808082C0: b           L_8080842C
    // 0x808082C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080842C;
    // 0x808082C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808082C8:
    // 0x808082C8: jal         0x808086A8
    // 0x808082CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808086A8_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x808082CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808082D0: beq         $v0, $zero, L_80808310
    if (ctx->r2 == 0) {
        // 0x808082D4: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_80808310;
    }
    // 0x808082D4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808082D8: jal         0x80101F24
    // 0x808082DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_5;
    // 0x808082DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808082E0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C50) << 16);
    // 0x808082E4: lwc1        $f4, -0x63B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C50));
    // 0x808082E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808082EC: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808082F0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808082F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808082F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808082FC: jal         0x800F10B4
    // 0x80808300: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80808300: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80808304: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80808308: jal         0x80102FDC
    // 0x8080830C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x8080830C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
L_80808310:
    // 0x80808310: jal         0x80101DDC
    // 0x80808314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_8;
    // 0x80808314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80808318: beq         $v0, $zero, L_80808428
    if (ctx->r2 == 0) {
        // 0x8080831C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80808428;
    }
    // 0x8080831C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80808320: lbu         $t8, 0xCD($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XCD);
    // 0x80808324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808328: beq         $t8, $zero, L_80808340
    if (ctx->r24 == 0) {
        // 0x8080832C: nop
    
            goto L_80808340;
    }
    // 0x8080832C: nop

    // 0x80808330: jal         0x80808560
    // 0x80808334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808560_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80808334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80808338: b           L_8080842C
    // 0x8080833C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080842C;
    // 0x8080833C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80808340:
    // 0x80808340: jal         0x80800180
    // 0x80808344: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80808344: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_10:
    // 0x80808348: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8080834C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80808350: b           L_80808428
    // 0x80808354: sb          $t9, 0xCC($t0)
    MEM_B(0XCC, ctx->r8) = ctx->r25;
        goto L_80808428;
    // 0x80808354: sb          $t9, 0xCC($t0)
    MEM_B(0XCC, ctx->r8) = ctx->r25;
L_80808358:
    // 0x80808358: lbu         $t1, 0xCD($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XCD);
    // 0x8080835C: beql        $t1, $zero, L_8080842C
    if (ctx->r9 == 0) {
        // 0x80808360: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080842C;
    }
    goto skip_0;
    // 0x80808360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80808364: jal         0x80808560
    // 0x80808368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808560_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80808368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080836C: b           L_8080842C
    // 0x80808370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080842C;
    // 0x80808370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80808374:
    // 0x80808374: jal         0x800D9078
    // 0x80808378: addiu       $a0, $v0, 0xD0
    ctx->r4 = ADD32(ctx->r2, 0XD0);
    func_800D9078(rdram, ctx);
        goto after_12;
    // 0x80808378: addiu       $a0, $v0, 0xD0
    ctx->r4 = ADD32(ctx->r2, 0XD0);
    after_12:
    // 0x8080837C: beq         $v0, $zero, L_80808428
    if (ctx->r2 == 0) {
        // 0x80808380: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808428;
    }
    // 0x80808380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808384: jal         0x80800180
    // 0x80808388: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80808388: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_13:
    // 0x8080838C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80808390: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80808394: b           L_80808428
    // 0x80808398: sb          $t2, 0xCC($t3)
    MEM_B(0XCC, ctx->r11) = ctx->r10;
        goto L_80808428;
    // 0x80808398: sb          $t2, 0xCC($t3)
    MEM_B(0XCC, ctx->r11) = ctx->r10;
L_8080839C:
    // 0x8080839C: jal         0x808086A8
    // 0x808083A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808086A8_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x808083A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808083A4: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x808083A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808083AC: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x808083B0: jal         0x80101E14
    // 0x808083B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x808083B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808083B8: beq         $v0, $zero, L_808083F8
    if (ctx->r2 == 0) {
        // 0x808083BC: nop
    
            goto L_808083F8;
    }
    // 0x808083BC: nop

    // 0x808083C0: jal         0x80802248
    // 0x808083C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x808083C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808083C8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808083CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808083D0: jal         0x8010105C
    // 0x808083D4: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    func_8010105C(rdram, ctx);
        goto after_17;
    // 0x808083D4: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    after_17:
    // 0x808083D8: lh          $a2, 0x2C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2C);
    // 0x808083DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808083E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808083E4: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x808083E8: jal         0x8010108C
    // 0x808083EC: ori         $a2, $t4, 0xDAC
    ctx->r6 = ctx->r12 | 0XDAC;
    func_8010108C(rdram, ctx);
        goto after_18;
    // 0x808083EC: ori         $a2, $t4, 0xDAC
    ctx->r6 = ctx->r12 | 0XDAC;
    after_18:
    // 0x808083F0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808083F4: sw          $zero, 0xD4($t6)
    MEM_W(0XD4, ctx->r14) = 0;
L_808083F8:
    // 0x808083F8: jal         0x80101DDC
    // 0x808083FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_19;
    // 0x808083FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80808400: beq         $v0, $zero, L_80808428
    if (ctx->r2 == 0) {
        // 0x80808404: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808428;
    }
    // 0x80808404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808408: jal         0x80800180
    // 0x8080840C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x8080840C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x80808410: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80808414: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80808418: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080841C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80808420: sb          $t7, 0xCC($t8)
    MEM_B(0XCC, ctx->r24) = ctx->r15;
    // 0x80808424: swc1        $f6, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f6.u32l;
L_80808428:
    // 0x80808428: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080842C:
    // 0x8080842C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80808430: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80808434: jr          $ra
    // 0x80808438: nop

    return;
    // 0x80808438: nop

;}
RECOMP_FUNC void func_8080063C_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080063C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800640: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080064C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800650: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80800654: jal         0x800F7874
    // 0x80800658: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    func_800F7874(rdram, ctx);
        goto after_0;
    // 0x80800658: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    after_0:
    // 0x8080065C: jal         0x800F5FA8
    // 0x80800660: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F5FA8(rdram, ctx);
        goto after_1;
    // 0x80800660: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080066C: jr          $ra
    // 0x80800670: nop

    return;
    // 0x80800670: nop

;}
RECOMP_FUNC void func_800FFD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFD10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFD14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FFD18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FFD1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FFD20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FFD24: bne         $a0, $at, L_800FFD34
    if (ctx->r4 != ctx->r1) {
        // 0x800FFD28: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800FFD34;
    }
    // 0x800FFD28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FFD2C: b           L_800FFD40
    // 0x800FFD30: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
        goto L_800FFD40;
    // 0x800FFD30: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_800FFD34:
    // 0x800FFD34: jal         0x80106730
    // 0x800FFD38: nop

    func_80106730(rdram, ctx);
        goto after_0;
    // 0x800FFD38: nop

    after_0:
    // 0x800FFD3C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800FFD40:
    // 0x800FFD40: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800FFD44: addiu       $s2, $s2, 0x4390
    ctx->r18 = ADD32(ctx->r18, 0X4390);
    // 0x800FFD48: jal         0x801068A8
    // 0x800FFD4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801068A8(rdram, ctx);
        goto after_1;
    // 0x800FFD4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800FFD50: beq         $v0, $zero, L_800FFDA4
    if (ctx->r2 == 0) {
        // 0x800FFD54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FFDA4;
    }
    // 0x800FFD54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FFD58: blezl       $s1, L_800FFDA8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800FFD5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800FFDA8;
    }
    goto skip_0;
    // 0x800FFD5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800FFD60: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
L_800FFD64:
    // 0x800FFD64: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x800FFD68: bgez        $t8, L_800FFD88
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800FFD6C: nop
    
            goto L_800FFD88;
    }
    // 0x800FFD6C: nop

    // 0x800FFD70: jal         0x80103AC0
    // 0x800FFD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103AC0(rdram, ctx);
        goto after_2;
    // 0x800FFD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FFD78: bne         $v0, $zero, L_800FFD88
    if (ctx->r2 != 0) {
        // 0x800FFD7C: nop
    
            goto L_800FFD88;
    }
    // 0x800FFD7C: nop

    // 0x800FFD80: jal         0x8010381C
    // 0x800FFD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010381C(rdram, ctx);
        goto after_3;
    // 0x800FFD84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800FFD88:
    // 0x800FFD88: jal         0x80106920
    // 0x800FFD8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80106920(rdram, ctx);
        goto after_4;
    // 0x800FFD8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800FFD90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FFD94: beq         $v0, $zero, L_800FFDA4
    if (ctx->r2 == 0) {
        // 0x800FFD98: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800FFDA4;
    }
    // 0x800FFD98: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800FFD9C: bgtzl       $s1, L_800FFD64
    if (SIGNED(ctx->r17) > 0) {
        // 0x800FFDA0: lw          $t6, 0x70($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X70);
            goto L_800FFD64;
    }
    goto skip_1;
    // 0x800FFDA0: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    skip_1:
L_800FFDA4:
    // 0x800FFDA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800FFDA8:
    // 0x800FFDA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FFDAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFDB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FFDB4: jr          $ra
    // 0x800FFDB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FFDB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void charea51gate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(980, 0X290) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(980, 0X290));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(980, 0X290));
;}
RECOMP_FUNC void bsvan_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F10: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80800F14: jal         0x80800E60
    // 0x80800F18: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    func_80800E60_bsvan(rdram, ctx);
        goto after_0;
    // 0x80800F18: addiu       $a1, $a1, -0x646C
    ctx->r5 = ADD32(ctx->r5, -0X646C);
    after_0:
    // 0x80800F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F24: jr          $ra
    // 0x80800F28: nop

    return;
    // 0x80800F28: nop

;}
RECOMP_FUNC void bakey_newlyReleased(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091A9C: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091AA0: jal         0x800BCFC4
    // 0x80091AA4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCFC4(rdram, ctx);
        goto after_0;
    // 0x80091AA4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091AB0: jr          $ra
    // 0x80091AB4: nop

    return;
    // 0x80091AB4: nop

;}
RECOMP_FUNC void _chhellterskelter_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E28: syscall     246
    recomp_syscall_handler(rdram, ctx, 0x80085E28);
    return;
    // 0x80085E2C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DF738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF738: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF73C: jr          $ra
    // 0x800DF740: sw          $a0, -0x37BC($at)
    MEM_W(-0X37BC, ctx->r1) = ctx->r4;
    return;
    // 0x800DF740: sw          $a0, -0x37BC($at)
    MEM_W(-0X37BC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_bsdronefalldie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: bne         $a1, $at, L_80800020
    if (ctx->r5 != ctx->r1) {
        // 0x80800010: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800020;
    }
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x80085200
    // 0x80800018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080001C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800020:
    // 0x80800020: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: sw          $a1, 0x190($t6)
    MEM_W(0X190, ctx->r14) = ctx->r5;
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800CE8: jal         0x8008CABC
    // 0x80800CEC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800CEC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800CF0: jal         0x8008B324
    // 0x80800CF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_1;
    // 0x80800CF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800CF8: beq         $v0, $zero, L_80800D04
    if (ctx->r2 == 0) {
        // 0x80800CFC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800D04;
    }
    // 0x80800CFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800D00: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800D04:
    // 0x80800D04: jal         0x80800008
    // 0x80800D08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800008_bsbwhirl(rdram, ctx);
        goto after_2;
    // 0x80800D08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800D0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D10: jal         0x8009E5C8
    // 0x80800D14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800D14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D20: jr          $ra
    // 0x80800D24: nop

    return;
    // 0x80800D24: nop

;}
RECOMP_FUNC void ncbadie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: jr          $ra
    // 0x808000D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void gczoombox_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B48: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x80803B4C: beq         $v0, $zero, L_80803B60
    if (ctx->r2 == 0) {
        // 0x80803B50: nop
    
            goto L_80803B60;
    }
    // 0x80803B50: nop

    // 0x80803B54: lbu         $v0, 0x171($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X171);
    // 0x80803B58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80803B5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80803B60:
    // 0x80803B60: jr          $ra
    // 0x80803B64: nop

    return;
    // 0x80803B64: nop

;}
RECOMP_FUNC void func_80803204_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080320C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803210: jal         0x80807D48
    // 0x80803214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80803214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80803218: jal         0x80808E78
    // 0x8080321C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808E78_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080321C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803224: jal         0x8080633C
    // 0x80803228: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80803228: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8080322C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80803230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803234: beq         $v0, $zero, L_8080324C
    if (ctx->r2 == 0) {
        // 0x80803238: nop
    
            goto L_8080324C;
    }
    // 0x80803238: nop

    // 0x8080323C: beq         $v0, $at, L_80803280
    if (ctx->r2 == ctx->r1) {
        // 0x80803240: nop
    
            goto L_80803280;
    }
    // 0x80803240: nop

    // 0x80803244: b           L_8080329C
    // 0x80803248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080329C;
    // 0x80803248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080324C:
    // 0x8080324C: jal         0x8008D04C
    // 0x80803250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D04C(rdram, ctx);
        goto after_3;
    // 0x80803250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803254: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80803258: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080325C: jal         0x8008B348
    // 0x80803260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x80803260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80803264: beq         $v0, $zero, L_80803298
    if (ctx->r2 == 0) {
        // 0x80803268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803298;
    }
    // 0x80803268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080326C: jal         0x80803124
    // 0x80803270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80803124_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80803270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80803274: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80803278: b           L_80803298
    // 0x8080327C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80803298;
    // 0x8080327C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80803280:
    // 0x80803280: jal         0x80800228
    // 0x80803284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800228_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80803284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80803288: beq         $v0, $zero, L_80803298
    if (ctx->r2 == 0) {
        // 0x8080328C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803298;
    }
    // 0x8080328C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803290: jal         0x8009E5C8
    // 0x80803294: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80803294: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    after_7:
L_80803298:
    // 0x80803298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080329C:
    // 0x8080329C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808032A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808032A4: jr          $ra
    // 0x808032A8: nop

    return;
    // 0x808032A8: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836C8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836C8);
    return;
    // 0x800836CC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
