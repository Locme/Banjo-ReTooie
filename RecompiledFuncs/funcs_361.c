#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801258_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080125C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801260: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801264: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801268: jal         0x8009C128
    // 0x8080126C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080126C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80801270: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801274: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801278: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080127C: jal         0x801013A8
    // 0x80801280: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    func_801013A8(rdram, ctx);
        goto after_1;
    // 0x80801280: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x80801284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080128C: jr          $ra
    // 0x80801290: nop

    return;
    // 0x80801290: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7D0: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7D0);
    return;
    // 0x8008A7D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800DD4_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DE0: jal         0x8009BF5C
    // 0x80800DE4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x80800DE4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80800DE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DEC: jal         0x8009C4CC
    // 0x80800DF0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x80800DF0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800DF4: jal         0x808004B8
    // 0x80800DF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800DF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E04: jr          $ra
    // 0x80800E08: nop

    return;
    // 0x80800E08: nop

;}
RECOMP_FUNC void suegg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800300: jal         0x80106790
    // 0x80800304: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800304: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800308: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800310: jal         0x80100094
    // 0x80800314: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800314: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800318: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080031C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800324: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80800328: jal         0x800EFB24
    // 0x8080032C: addiu       $a2, $v1, 0x18
    ctx->r6 = ADD32(ctx->r3, 0X18);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x8080032C: addiu       $a2, $v1, 0x18
    ctx->r6 = ADD32(ctx->r3, 0X18);
    after_2:
    // 0x80800330: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800334: lw          $a0, 0x24($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X24);
    // 0x80800338: srl         $t7, $a0, 22
    ctx->r15 = S32(U32(ctx->r4) >> 22);
    // 0x8080033C: jal         0x800883B8
    // 0x80800340: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _gcegg_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800340: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x80800344: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800348: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8080034C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: lh          $v0, 0x3A($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X3A);
    // 0x80800358: jr          $ra
    // 0x8080035C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080035C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800FC8_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800FD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FD4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1896, 0X13D4) << 16);
    // 0x80800FD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800FE0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800FE4: jal         0x808010A0
    // 0x80800FE8: addiu       $a0, $a0, 0x13D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1896, 0X13D4));
    func_808010A0_chquicksandbaddy(rdram, ctx);
        goto after_0;
    // 0x80800FE8: addiu       $a0, $a0, 0x13D4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1896, 0X13D4));
    after_0:
    // 0x80800FEC: beql        $v0, $zero, L_80801090
    if (ctx->r2 == 0) {
        // 0x80800FF0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801090;
    }
    goto skip_0;
    // 0x80800FF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800FF4: jal         0x800B53A4
    // 0x80800FF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80800FF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800FFC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801000: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1896, 0X1394) << 16);
    // 0x80801004: addiu       $t6, $t6, 0x1394
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1896, 0X1394));
    // 0x80801008: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080100C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801014: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801018: jal         0x800BABB8
    // 0x8080101C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x8080101C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_2:
    // 0x80801020: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801028: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8080102C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80801030: bne         $at, $zero, L_80801040
    if (ctx->r1 != 0) {
        // 0x80801034: nop
    
            goto L_80801040;
    }
    // 0x80801034: nop

    // 0x80801038: jal         0x800BA714
    // 0x8080103C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800BA714(rdram, ctx);
        goto after_3;
    // 0x8080103C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_3:
L_80801040:
    // 0x80801040: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1896, 0X13D4) << 16);
    // 0x80801044: addiu       $a1, $a1, 0x13D4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1896, 0X13D4));
    // 0x80801048: jal         0x800BAB80
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BAB80(rdram, ctx);
        goto after_4;
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801050: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801058: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080105C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801060: nop

    // 0x80801064: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80801068: jal         0x800BA4D0
    // 0x8080106C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_5;
    // 0x8080106C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_5:
    // 0x80801070: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80801074: addiu       $a1, $a1, 0x6F60
    ctx->r5 = ADD32(ctx->r5, 0X6F60);
    // 0x80801078: jal         0x800BA544
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA544(rdram, ctx);
        goto after_6;
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801084: jal         0x800BA22C
    // 0x80801088: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80801088: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8080108C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801090:
    // 0x80801090: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801098: jr          $ra
    // 0x8080109C: nop

    return;
    // 0x8080109C: nop

;}
RECOMP_FUNC void _badrone_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848C0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848C0);
    return;
    // 0x800848C4: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80801160_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801160: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801168: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080116C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801170: jal         0x80102424
    // 0x80801174: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80801174: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801178: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080117C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80801180: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80801184: beq         $at, $zero, L_80801258
    if (ctx->r1 == 0) {
        // 0x80801188: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801258;
    }
    // 0x80801188: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080118C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27A8) << 16);
    // 0x80801190: addu        $at, $at, $t7
    gpr jr_addend_80801198 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801194: lw          $t7, 0x27A8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27A8));
    // 0x80801198: jr          $t7
    // 0x8080119C: nop

    switch (jr_addend_80801198 >> 2) {
        case 0: goto L_808011C8; break;
        case 1: goto L_808011A0; break;
        case 2: goto L_80801258; break;
        case 3: goto L_808011A0; break;
        case 4: goto L_808011B4; break;
        case 5: goto L_80801258; break;
        case 6: goto L_808011DC; break;
        default: switch_error(__func__, 0x80801198, 0x808027A8);
    }
    // 0x8080119C: nop

L_808011A0:
    // 0x808011A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011A4: jal         0x80109FE8
    // 0x808011A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_1;
    // 0x808011A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808011AC: b           L_80801268
    // 0x808011B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801268;
    // 0x808011B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011B4:
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011B8: jal         0x80109FE8
    // 0x808011BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_2;
    // 0x808011BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808011C0: b           L_80801268
    // 0x808011C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801268;
    // 0x808011C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011C8:
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011CC: jal         0x80109FE8
    // 0x808011D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_3;
    // 0x808011D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808011D4: b           L_80801268
    // 0x808011D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801268;
    // 0x808011D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011DC:
    // 0x808011DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011E0: jal         0x80103DFC
    // 0x808011E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80103DFC(rdram, ctx);
        goto after_4;
    // 0x808011E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808011E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011EC: jal         0x80802470
    // 0x808011F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802470_chfactoryrobot(rdram, ctx);
        goto after_5;
    // 0x808011F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808011F4: lbu         $t8, 0x64($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X64);
    // 0x808011F8: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x808011FC: jal         0x80088B00
    // 0x80801200: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
    _fxgenlist_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80801200: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
    after_6:
    // 0x80801204: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801208: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080120C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801210: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801218: jal         0x800BBCB8
    // 0x8080121C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x8080121C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // 0x80801220: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801224: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1140, 0X2AB8) << 16);
    // 0x80801228: addiu       $a3, $a3, 0x2AB8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1140, 0X2AB8));
    // 0x8080122C: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x80801230: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80801234: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80801238: jal         0x8010D930
    // 0x8080123C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8010D930(rdram, ctx);
        goto after_8;
    // 0x8080123C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80801240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801244: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801248: jal         0x80086670
    // 0x8080124C: addiu       $a2, $zero, 0x124
    ctx->r6 = ADD32(0, 0X124);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x8080124C: addiu       $a2, $zero, 0x124
    ctx->r6 = ADD32(0, 0X124);
    after_9:
    // 0x80801250: b           L_80801268
    // 0x80801254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801268;
    // 0x80801254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801258:
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080125C: jal         0x80109FE8
    // 0x80801260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_10;
    // 0x80801260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80801264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801268:
    // 0x80801268: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080126C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801270: jr          $ra
    // 0x80801274: nop

    return;
    // 0x80801274: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088190: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088190);
    return;
    // 0x80088194: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800350_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80800354: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80800358: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8080035C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80800360: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800364: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800368: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080036C: beq         $t6, $zero, L_80800460
    if (ctx->r14 == 0) {
        // 0x80800370: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800460;
    }
    // 0x80800370: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800374: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x80800378: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080037C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800380: addiu       $t5, $zero, 0x6C
    ctx->r13 = ADD32(0, 0X6C);
    // 0x80800384: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80800388: addiu       $t3, $zero, 0x68
    ctx->r11 = ADD32(0, 0X68);
    // 0x8080038C: addiu       $t2, $zero, 0xFD
    ctx->r10 = ADD32(0, 0XFD);
    // 0x80800390: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80800394:
    // 0x80800394: beq         $a3, $zero, L_808003A4
    if (ctx->r7 == 0) {
        // 0x80800398: addiu       $a0, $zero, 0x7E
        ctx->r4 = ADD32(0, 0X7E);
            goto L_808003A4;
    }
    // 0x80800398: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    // 0x8080039C: b           L_808003A4
    // 0x808003A0: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
        goto L_808003A4;
    // 0x808003A0: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
L_808003A4:
    // 0x808003A4: bne         $a0, $t1, L_80800448
    if (ctx->r4 != ctx->r9) {
        // 0x808003A8: addu        $t8, $s0, $v1
        ctx->r24 = ADD32(ctx->r16, ctx->r3);
            goto L_80800448;
    }
    // 0x808003A8: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x808003AC: beq         $a1, $zero, L_808003CC
    if (ctx->r5 == 0) {
        // 0x808003B0: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_808003CC;
    }
    // 0x808003B0: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    // 0x808003B4: addu        $t7, $s0, $v1
    ctx->r15 = ADD32(ctx->r16, ctx->r3);
    // 0x808003B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808003BC: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x808003C0: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x808003C4: sb          $t3, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r11;
    // 0x808003C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_808003CC:
    // 0x808003CC: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x808003D0: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x808003D4: beq         $t1, $zero, L_80800424
    if (ctx->r9 == 0) {
        // 0x808003D8: nop
    
            goto L_80800424;
    }
    // 0x808003D8: nop

    // 0x808003DC: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
L_808003E0:
    // 0x808003E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808003E4: beq         $a1, $zero, L_80800410
    if (ctx->r5 == 0) {
        // 0x808003E8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80800410;
    }
    // 0x808003E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808003EC: bnel        $a3, $zero, L_80800414
    if (ctx->r7 != 0) {
        // 0x808003F0: lbu         $t1, 0x1($t0)
        ctx->r9 = MEM_BU(ctx->r8, 0X1);
            goto L_80800414;
    }
    goto skip_0;
    // 0x808003F0: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
    skip_0:
    // 0x808003F4: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x808003F8: bnel        $t4, $t9, L_80800414
    if (ctx->r12 != ctx->r25) {
        // 0x808003FC: lbu         $t1, 0x1($t0)
        ctx->r9 = MEM_BU(ctx->r8, 0X1);
            goto L_80800414;
    }
    goto skip_1;
    // 0x808003FC: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
    skip_1:
    // 0x80800400: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x80800404: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
    // 0x80800408: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8080040C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_80800410:
    // 0x80800410: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
L_80800414:
    // 0x80800414: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800418: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8080041C: bnel        $t1, $zero, L_808003E0
    if (ctx->r9 != 0) {
        // 0x80800420: sb          $t1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r9;
            goto L_808003E0;
    }
    goto skip_2;
    // 0x80800420: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    skip_2:
L_80800424:
    // 0x80800424: beq         $a1, $zero, L_80800450
    if (ctx->r5 == 0) {
        // 0x80800428: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80800450;
    }
    // 0x80800428: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080042C: addu        $t6, $s0, $v1
    ctx->r14 = ADD32(ctx->r16, ctx->r3);
    // 0x80800430: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800434: sb          $t2, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r10;
    // 0x80800438: addu        $t7, $s0, $v1
    ctx->r15 = ADD32(ctx->r16, ctx->r3);
    // 0x8080043C: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80800440: b           L_80800450
    // 0x80800444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80800450;
    // 0x80800444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800448:
    // 0x80800448: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x8080044C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800450:
    // 0x80800450: lbu         $t0, 0x1($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X1);
    // 0x80800454: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800458: bne         $t0, $zero, L_80800394
    if (ctx->r8 != 0) {
        // 0x8080045C: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_80800394;
    }
    // 0x8080045C: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80800460:
    // 0x80800460: addu        $t9, $s0, $v1
    ctx->r25 = ADD32(ctx->r16, ctx->r3);
    // 0x80800464: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x80800468: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8080046C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80800470: jr          $ra
    // 0x80800474: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80800474: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80801000_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801000: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80801004: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801008: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080100C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80801010: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801014: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801018: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x8080101C: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80801020: jal         0x80092AD8
    // 0x80801024: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    func_80092AD8(rdram, ctx);
        goto after_0;
    // 0x80801024: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    after_0:
    // 0x80801028: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080102C: jal         0x800E0ACC
    // 0x80801030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E0ACC(rdram, ctx);
        goto after_1;
    // 0x80801030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801038: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80801044: jal         0x800E0AF0
    // 0x80801048: nop

    func_800E0AF0(rdram, ctx);
        goto after_2;
    // 0x80801048: nop

    after_2:
    // 0x8080104C: jal         0x80806130
    // 0x80801050: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_80806130_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80801050: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_3:
    // 0x80801054: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80801058: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080105C: jal         0x800F0DC0
    // 0x80801060: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0DC0(rdram, ctx);
        goto after_4;
    // 0x80801060: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80801064: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80801068: jal         0x8080613C
    // 0x8080106C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    func_8080613C_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x8080106C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    after_5:
    // 0x80801070: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80801074: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080107C: jal         0x800F1214
    // 0x80801080: lui         $a2, 0x4434
    ctx->r6 = S32(0X4434 << 16);
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x80801080: lui         $a2, 0x4434
    ctx->r6 = S32(0X4434 << 16);
    after_6:
    // 0x80801084: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3F4) << 16);
    // 0x80801088: lwc1        $f4, -0x5C0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3F4));
    // 0x8080108C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80801090: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801094: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801098: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8080109C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x808010A0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808010A4: jal         0x80805380
    // 0x808010A8: nop

    func_80805380_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x808010A8: nop

    after_7:
    // 0x808010AC: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x808010B0: lwc1        $f8, 0x50($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X50);
    // 0x808010B4: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x808010B8: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808010BC: lwc1        $f16, 0xCC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x808010C0: jal         0x80013728
    // 0x808010C4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_80013728(rdram, ctx);
        goto after_8;
    // 0x808010C4: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_8:
    // 0x808010C8: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x808010CC: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x808010D0: lwc1        $f18, 0x20C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20C);
    // 0x808010D4: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x808010D8: lwc1        $f6, 0xC8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x808010DC: lwc1        $f4, 0x20C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20C);
    // 0x808010E0: jal         0x80013728
    // 0x808010E4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_9;
    // 0x808010E4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x808010E8: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x808010EC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x808010F0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x808010F4: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x808010F8: beq         $at, $zero, L_808015A4
    if (ctx->r1 == 0) {
        // 0x808010FC: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_808015A4;
    }
    // 0x808010FC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80801100: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA3F8) << 16);
    // 0x80801104: addu        $at, $at, $t8
    gpr jr_addend_8080110C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801108: lw          $t8, -0x5C08($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(439, 0XA3F8));
    // 0x8080110C: jr          $t8
    // 0x80801110: nop

    switch (jr_addend_8080110C >> 2) {
        case 0: goto L_80801554; break;
        case 1: goto L_80801114; break;
        case 2: goto L_80801428; break;
        case 3: goto L_80801428; break;
        case 4: goto L_808012C0; break;
        case 5: goto L_80801114; break;
        default: switch_error(__func__, 0x8080110C, 0x8080A3F8);
    }
    // 0x80801110: nop

L_80801114:
    // 0x80801114: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801118: bne         $v0, $at, L_80801128
    if (ctx->r2 != ctx->r1) {
        // 0x8080111C: lwc1        $f20, 0x78($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
            goto L_80801128;
    }
    // 0x8080111C: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801120: b           L_8080112C
    // 0x80801124: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
        goto L_8080112C;
    // 0x80801124: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
L_80801128:
    // 0x80801128: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080112C:
    // 0x8080112C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80801130: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801138: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8080113C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80801140: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801144: jal         0x800E0AFC
    // 0x80801148: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_10;
    // 0x80801148: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_10:
    // 0x8080114C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801150: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA410) << 16);
    // 0x80801154: lwc1        $f16, -0x5BF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA410));
    // 0x80801158: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8080115C: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80801160: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801164: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801168: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801170: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80801174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801178: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8080117C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801180: jal         0x800E0AFC
    // 0x80801184: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_11;
    // 0x80801184: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80801188: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8080118C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA414) << 16);
    // 0x80801190: lwc1        $f8, -0x5BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA414));
    // 0x80801194: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80801198: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8080119C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808011A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011A4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x808011A8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808011AC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x808011B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808011B4: jal         0x800E0AFC
    // 0x808011B8: nop

    func_800E0AFC(rdram, ctx);
        goto after_12;
    // 0x808011B8: nop

    after_12:
    // 0x808011BC: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x808011C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808011C4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808011C8: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x808011CC: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808011D0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808011D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808011D8: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808011DC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA418) << 16);
    // 0x808011E0: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x808011E4: lwc1        $f16, -0x5BE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA418));
    // 0x808011E8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x808011EC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808011F0: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808011F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F8: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x808011FC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80801200: add.s       $f20, $f6, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80801204: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80801208: jal         0x800E0AFC
    // 0x8080120C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_13;
    // 0x8080120C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x80801210: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801214: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801218: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080121C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80801220: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801224: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80801228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080122C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80801230: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801234: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80801238: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8080123C: jal         0x800E0AFC
    // 0x80801240: nop

    func_800E0AFC(rdram, ctx);
        goto after_14;
    // 0x80801240: nop

    after_14:
    // 0x80801244: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80801248: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8080124C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801250: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80801254: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801258: mul.s       $f20, $f12, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8080125C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801260: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801264: mul.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080126C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801270: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801274: jal         0x800E0AFC
    // 0x80801278: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_15;
    // 0x80801278: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x8080127C: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80801280: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80801284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801288: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8080128C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80801290: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801294: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801298: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8080129C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808012A0: mul.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x808012AC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808012B0: jal         0x800E0AFC
    // 0x808012B4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_16;
    // 0x808012B4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x808012B8: b           L_808015A8
    // 0x808012BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808015A8;
    // 0x808012BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808012C0:
    // 0x808012C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808012C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808012C8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808012CC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808012D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012D4: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808012D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808012DC: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x808012E0: nop

    // 0x808012E4: bc1tl       L_8080133C
    if (c1cs) {
        // 0x808012E8: lwc1        $f16, 0x70($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
            goto L_8080133C;
    }
    goto skip_0;
    // 0x808012E8: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x808012EC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808012F0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808012F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808012F8: jal         0x800E0AFC
    // 0x808012FC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_17;
    // 0x808012FC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_17:
    // 0x80801300: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801304: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080130C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80801310: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801314: jal         0x800E0AFC
    // 0x80801318: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_18;
    // 0x80801318: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_18:
    // 0x8080131C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801320: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801328: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8080132C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801330: jal         0x800E0AFC
    // 0x80801334: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_19;
    // 0x80801334: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_19:
    // 0x80801338: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
L_8080133C:
    // 0x8080133C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA41C) << 16);
    // 0x80801340: lwc1        $f6, -0x5BE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA41C));
    // 0x80801344: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801348: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x8080134C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801350: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801354: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801358: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8080135C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801360: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080136C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801370: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80801374: jal         0x800E0AFC
    // 0x80801378: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_20;
    // 0x80801378: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x8080137C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801380: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA420) << 16);
    // 0x80801384: lwc1        $f6, -0x5BE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA420));
    // 0x80801388: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x8080138C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801390: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801398: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8080139C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808013A0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x808013A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808013A8: jal         0x800E0AFC
    // 0x808013AC: nop

    func_800E0AFC(rdram, ctx);
        goto after_21;
    // 0x808013AC: nop

    after_21:
    // 0x808013B0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808013B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808013B8: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808013BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808013C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808013C4: mul.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x808013C8: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808013CC: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808013D0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808013D4: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x808013D8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E0: mul.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x808013E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808013E8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x808013EC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x808013F0: sub.s       $f20, $f16, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x808013F4: jal         0x800E0AFC
    // 0x808013F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_22;
    // 0x808013F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_22:
    // 0x808013FC: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801400: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801404: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801408: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8080140C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801410: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80801414: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80801418: jal         0x800E0AFC
    // 0x8080141C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_23;
    // 0x8080141C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_23:
    // 0x80801420: b           L_808015A8
    // 0x80801424: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808015A8;
    // 0x80801424: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80801428:
    // 0x80801428: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8080142C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801430: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801434: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080143C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801440: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801444: jal         0x800E0AFC
    // 0x80801448: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_24;
    // 0x80801448: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_24:
    // 0x8080144C: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801450: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA424) << 16);
    // 0x80801454: lwc1        $f16, -0x5BDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA424));
    // 0x80801458: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8080145C: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80801460: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA428) << 16);
    // 0x80801464: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80801468: lwc1        $f18, -0x5BD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA428));
    // 0x8080146C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80801470: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801474: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080147C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801480: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80801484: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80801488: jal         0x800E0AFC
    // 0x8080148C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_25;
    // 0x8080148C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_25:
    // 0x80801490: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801494: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA42C) << 16);
    // 0x80801498: lwc1        $f4, -0x5BD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA42C));
    // 0x8080149C: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808014A0: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x808014A4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA430) << 16);
    // 0x808014A8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x808014AC: lwc1        $f16, -0x5BD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA430));
    // 0x808014B0: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x808014B4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808014B8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x808014C4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808014C8: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x808014CC: jal         0x800E0AFC
    // 0x808014D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_26;
    // 0x808014D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_26:
    // 0x808014D4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808014D8: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808014DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014E0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA434) << 16);
    // 0x808014E4: lwc1        $f18, -0x5BCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA434));
    // 0x808014E8: mul.s       $f20, $f14, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x808014EC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808014F0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808014F4: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x808014F8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x808014FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801500: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801504: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801508: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8080150C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801514: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80801518: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8080151C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80801520: jal         0x800E0AFC
    // 0x80801524: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_27;
    // 0x80801524: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x80801528: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8080152C: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801530: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80801534: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080153C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80801540: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80801544: jal         0x800E0AFC
    // 0x80801548: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_28;
    // 0x80801548: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x8080154C: b           L_808015A8
    // 0x80801550: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_808015A8;
    // 0x80801550: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80801554:
    // 0x80801554: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801558: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8080155C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801560: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801568: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080156C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801570: jal         0x800E0AFC
    // 0x80801574: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_29;
    // 0x80801574: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_29:
    // 0x80801578: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8080157C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80801580: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801584: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    // 0x80801588: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x8080158C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801590: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80801594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801598: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x8080159C: jal         0x800E0AFC
    // 0x808015A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_30;
    // 0x808015A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_30:
L_808015A4:
    // 0x808015A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808015A8:
    // 0x808015A8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808015AC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808015B0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808015B4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808015B8: jr          $ra
    // 0x808015BC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808015BC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800C70D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C70D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C70D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C70D8: jal         0x800DA3B8
    // 0x800C70DC: addiu       $a0, $a0, 0xEE
    ctx->r4 = ADD32(ctx->r4, 0XEE);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800C70DC: addiu       $a0, $a0, 0xEE
    ctx->r4 = ADD32(ctx->r4, 0XEE);
    after_0:
    // 0x800C70E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C70E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C70E8: jr          $ra
    // 0x800C70EC: nop

    return;
    // 0x800C70EC: nop

;}
RECOMP_FUNC void func_80106EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106EE8: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x80106EEC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80106EF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106EF4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80106EF8: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80106EFC: beq         $t7, $zero, L_80106F20
    if (ctx->r15 == 0) {
        // 0x80106F00: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80106F20;
    }
    // 0x80106F00: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80106F04: lw          $a0, 0x6F00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F00);
    // 0x80106F08: jal         0x800B32C0
    // 0x80106F0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x80106F0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80106F10: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80106F14: lhu         $t8, 0x94($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X94);
    // 0x80106F18: andi        $t9, $t8, 0xC00F
    ctx->r25 = ctx->r24 & 0XC00F;
    // 0x80106F1C: sh          $t9, 0x94($a2)
    MEM_H(0X94, ctx->r6) = ctx->r25;
L_80106F20:
    // 0x80106F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106F28: jr          $ra
    // 0x80106F2C: nop

    return;
    // 0x80106F2C: nop

;}
RECOMP_FUNC void bsstatue_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FB8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800FBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X15E0) << 16);
    // 0x80800FC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800FC4: jr          $ra
    // 0x80800FC8: lw          $v0, 0x15E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15E0));
    return;
    // 0x80800FC8: lw          $v0, 0x15E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15E0));
;}
RECOMP_FUNC void _glcutDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887A8: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887A8);
    return;
    // 0x800887AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801BD0_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BD8: lbu         $t6, 0x170($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X170);
    // 0x80801BDC: beql        $a1, $t6, L_80801C00
    if (ctx->r5 == ctx->r14) {
        // 0x80801BE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C00;
    }
    goto skip_0;
    // 0x80801BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801BE4: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80801BE8: sb          $a1, 0x170($a0)
    MEM_B(0X170, ctx->r4) = ctx->r5;
    // 0x80801BEC: beql        $v0, $zero, L_80801C00
    if (ctx->r2 == 0) {
        // 0x80801BF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C00;
    }
    goto skip_1;
    // 0x80801BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801BF4: jalr        $v0
    // 0x80801BF8: lh          $a0, 0x172($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X172);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80801BF8: lh          $a0, 0x172($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X172);
    after_0:
    // 0x80801BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C00:
    // 0x80801C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C04: jr          $ra
    // 0x80801C08: nop

    return;
    // 0x80801C08: nop

;}
RECOMP_FUNC void bssnowball_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800EF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X10D4) << 16);
    // 0x80800EF8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EFC: jr          $ra
    // 0x80800F00: lw          $v0, 0x10D4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10D4));
    return;
    // 0x80800F00: lw          $v0, 0x10D4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X10D4));
    // 0x80800F04: nop

    // 0x80800F08: nop

    // 0x80800F0C: nop

;}
RECOMP_FUNC void bainput_func_80097DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097DFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097E00: jal         0x80091A58
    // 0x80097E04: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097E04: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80097E08: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097E0C: beq         $t6, $zero, L_80097E24
    if (ctx->r14 == 0) {
        // 0x80097E10: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097E24;
    }
    // 0x80097E10: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097E14: jal         0x8008D304
    // 0x80097E18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D304(rdram, ctx);
        goto after_1;
    // 0x80097E18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097E1C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097E20: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097E24:
    // 0x80097E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097E28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097E2C: jr          $ra
    // 0x80097E30: nop

    return;
    // 0x80097E30: nop

;}
RECOMP_FUNC void func_80801A8C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801A90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801A94: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80801A98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801A9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801AA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AA4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801AA8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801AAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801AB0: jal         0x80100094
    // 0x80801AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801AB8: lbu         $v1, 0x79($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X79);
    // 0x80801ABC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801AC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801AC4: srl         $t6, $v1, 4
    ctx->r14 = S32(U32(ctx->r3) >> 4);
    // 0x80801AC8: beq         $t6, $zero, L_80801AF0
    if (ctx->r14 == 0) {
        // 0x80801ACC: nop
    
            goto L_80801AF0;
    }
    // 0x80801ACC: nop

    // 0x80801AD0: beq         $t6, $at, L_80801AF0
    if (ctx->r14 == ctx->r1) {
        // 0x80801AD4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801AF0;
    }
    // 0x80801AD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801AD8: beq         $t6, $at, L_80801AF0
    if (ctx->r14 == ctx->r1) {
        // 0x80801ADC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801AF0;
    }
    // 0x80801ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801AE0: beql        $t6, $at, L_80801AFC
    if (ctx->r14 == ctx->r1) {
        // 0x80801AE4: lbu         $s3, 0xC2($v0)
        ctx->r19 = MEM_BU(ctx->r2, 0XC2);
            goto L_80801AFC;
    }
    goto skip_0;
    // 0x80801AE4: lbu         $s3, 0xC2($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0XC2);
    skip_0:
    // 0x80801AE8: b           L_80801AFC
    // 0x80801AEC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
        goto L_80801AFC;
    // 0x80801AEC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
L_80801AF0:
    // 0x80801AF0: b           L_80801AFC
    // 0x80801AF4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80801AFC;
    // 0x80801AF4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80801AF8: lbu         $s3, 0xC2($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0XC2);
L_80801AFC:
    // 0x80801AFC: blez        $s3, L_80801B6C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801B00: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801B6C;
    }
    // 0x80801B00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801B04: lbu         $t7, 0xC0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC0);
L_80801B08:
    // 0x80801B08: addiu       $s1, $s0, 0xC3
    ctx->r17 = ADD32(ctx->r16, 0XC3);
    // 0x80801B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B10: bne         $t7, $zero, L_80801B30
    if (ctx->r15 != 0) {
        // 0x80801B14: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80801B30;
    }
    // 0x80801B14: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80801B18: addiu       $s1, $s0, 0xC3
    ctx->r17 = ADD32(ctx->r16, 0XC3);
    // 0x80801B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B20: jal         0x800D2770
    // 0x80801B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_1;
    // 0x80801B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801B28: b           L_80801B40
    // 0x80801B2C: nop

        goto L_80801B40;
    // 0x80801B2C: nop

L_80801B30:
    // 0x80801B30: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80801B34: lw          $a1, 0x10($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X10);
    // 0x80801B38: jal         0x800D24E8
    // 0x80801B3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_2;
    // 0x80801B3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80801B40:
    // 0x80801B40: beq         $s4, $zero, L_80801B60
    if (ctx->r20 == 0) {
        // 0x80801B44: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_80801B60;
    }
    // 0x80801B44: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80801B48: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x80801B4C: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x80801B50: beql        $t2, $zero, L_80801B64
    if (ctx->r10 == 0) {
        // 0x80801B54: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801B64;
    }
    goto skip_1;
    // 0x80801B54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80801B58: jal         0x800D28A0
    // 0x80801B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D28A0(rdram, ctx);
        goto after_3;
    // 0x80801B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_80801B60:
    // 0x80801B60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801B64:
    // 0x80801B64: bnel        $s0, $s3, L_80801B08
    if (ctx->r16 != ctx->r19) {
        // 0x80801B68: lbu         $t7, 0xC0($s2)
        ctx->r15 = MEM_BU(ctx->r18, 0XC0);
            goto L_80801B08;
    }
    goto skip_2;
    // 0x80801B68: lbu         $t7, 0xC0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC0);
    skip_2:
L_80801B6C:
    // 0x80801B6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801B70: sb          $t3, 0xC0($s2)
    MEM_B(0XC0, ctx->r18) = ctx->r11;
    // 0x80801B74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801B78: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801B7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801B80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801B84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B8C: jr          $ra
    // 0x80801B90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801B90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bs_getNextState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E704: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E708: jr          $ra
    // 0x8009E70C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    return;
    // 0x8009E70C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
;}
RECOMP_FUNC void gccubesearch_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ABC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800AC4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800AC8: jal         0x800EB880
    // 0x80800ACC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EB880(rdram, ctx);
        goto after_0;
    // 0x80800ACC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80800AD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800AD4: jal         0x800BE52C
    // 0x80800AD8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800BE52C(rdram, ctx);
        goto after_1;
    // 0x80800AD8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80800ADC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AE0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE4: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x80800AE8: beql        $at, $zero, L_80800B18
    if (ctx->r1 == 0) {
        // 0x80800AEC: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800B18;
    }
    goto skip_0;
    // 0x80800AEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80800AF0:
    // 0x80800AF0: jal         0x800EB8C0
    // 0x80800AF4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EB8C0(rdram, ctx);
        goto after_2;
    // 0x80800AF4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800AF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AFC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800B00: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80800B04: sltu        $at, $a0, $t7
    ctx->r1 = ctx->r4 < ctx->r15 ? 1 : 0;
    // 0x80800B08: bne         $at, $zero, L_80800AF0
    if (ctx->r1 != 0) {
        // 0x80800B0C: nop
    
            goto L_80800AF0;
    }
    // 0x80800B0C: nop

    // 0x80800B10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80800B14: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800B18:
    // 0x80800B18: jal         0x800EBB30
    // 0x80800B1C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EBB30(rdram, ctx);
        goto after_3;
    // 0x80800B1C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B28: jr          $ra
    // 0x80800B2C: nop

    return;
    // 0x80800B2C: nop

;}
RECOMP_FUNC void func_808002FC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800308: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080030C: jal         0x80100094
    // 0x80800310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800314: jal         0x80088380
    // 0x80800318: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800318: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080031C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800320: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080032C: jal         0x80800CF8
    // 0x80800330: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_2;
    // 0x80800330: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    after_2:
    // 0x80800334: jal         0x80801C5C
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C5C_chfpsgame(rdram, ctx);
        goto after_3;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080033C: jal         0x80088368
    // 0x80800340: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800340: nop

    after_4:
    // 0x80800344: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800348: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8080034C: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x80800350: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800354: beq         $at, $zero, L_808003BC
    if (ctx->r1 == 0) {
        // 0x80800358: sw          $v0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r2;
            goto L_808003BC;
    }
    // 0x80800358: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8080035C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2108) << 16);
    // 0x80800364: addu        $at, $at, $t8
    gpr jr_addend_8080036C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800368: lw          $t8, 0x2108($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2108));
    // 0x8080036C: jr          $t8
    // 0x80800370: nop

    switch (jr_addend_8080036C >> 2) {
        case 0: goto L_80800374; break;
        case 1: goto L_80800394; break;
        case 2: goto L_80800384; break;
        case 3: goto L_80800374; break;
        case 4: goto L_808003B4; break;
        case 5: goto L_808003A4; break;
        default: switch_error(__func__, 0x8080036C, 0x80802108);
    }
    // 0x80800370: nop

L_80800374:
    // 0x80800374: jal         0x808003D0
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D0_chfpsgame(rdram, ctx);
        goto after_5;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080037C: b           L_808003C0
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800384:
    // 0x80800384: jal         0x808004E0
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004E0_chfpsgame(rdram, ctx);
        goto after_6;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080038C: b           L_808003C0
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800394:
    // 0x80800394: jal         0x808005B0
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005B0_chfpsgame(rdram, ctx);
        goto after_7;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080039C: b           L_808003C0
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A4:
    // 0x808003A4: jal         0x808006A8
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A8_chfpsgame(rdram, ctx);
        goto after_8;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003AC: b           L_808003C0
    // 0x808003B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003C0;
    // 0x808003B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003B4:
    // 0x808003B4: jal         0x8080075C
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080075C_chfpsgame(rdram, ctx);
        goto after_9;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808003BC:
    // 0x808003BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003C0:
    // 0x808003C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083830: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083830);
    return;
    // 0x80083834: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800E6B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6B7C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E6B80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E6B84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800E6B88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800E6B8C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800E6B90: nop

    // 0x800E6B94: bc1f        L_800E6BA4
    if (!c1cs) {
        // 0x800E6B98: nop
    
            goto L_800E6BA4;
    }
    // 0x800E6B98: nop

    // 0x800E6B9C: jr          $ra
    // 0x800E6BA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800E6BA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E6BA4:
    // 0x800E6BA4: jr          $ra
    // 0x800E6BA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800E6BA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80110B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110B68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80110B6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110B70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80110B74: beq         $a1, $zero, L_80110BB0
    if (ctx->r5 == 0) {
        // 0x80110B78: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80110BB0;
    }
    // 0x80110B78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110B7C: jal         0x800F6BE4
    // 0x80110B80: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    func_800F6BE4(rdram, ctx);
        goto after_0;
    // 0x80110B80: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    after_0:
    // 0x80110B84: beq         $v0, $zero, L_80110BDC
    if (ctx->r2 == 0) {
        // 0x80110B88: addiu       $a1, $zero, 0x6C
        ctx->r5 = ADD32(0, 0X6C);
            goto L_80110BDC;
    }
    // 0x80110B88: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x80110B8C: jal         0x800F7B9C
    // 0x80110B90: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x80110B90: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x80110B94: jal         0x800F53D0
    // 0x80110B98: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80110B98: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_2:
    // 0x80110B9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110BA0: jal         0x80093700
    // 0x80110BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093700(rdram, ctx);
        goto after_3;
    // 0x80110BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80110BA8: b           L_80110BE0
    // 0x80110BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80110BE0;
    // 0x80110BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110BB0:
    // 0x80110BB0: jal         0x800F6BE4
    // 0x80110BB4: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F6BE4(rdram, ctx);
        goto after_4;
    // 0x80110BB4: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_4:
    // 0x80110BB8: beq         $v0, $zero, L_80110BDC
    if (ctx->r2 == 0) {
        // 0x80110BBC: addiu       $a1, $zero, 0x6B
        ctx->r5 = ADD32(0, 0X6B);
            goto L_80110BDC;
    }
    // 0x80110BBC: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    // 0x80110BC0: jal         0x800F7B9C
    // 0x80110BC4: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F7B9C(rdram, ctx);
        goto after_5;
    // 0x80110BC4: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_5:
    // 0x80110BC8: jal         0x800F53D0
    // 0x80110BCC: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F53D0(rdram, ctx);
        goto after_6;
    // 0x80110BCC: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_6:
    // 0x80110BD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110BD4: jal         0x80093700
    // 0x80110BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80093700(rdram, ctx);
        goto after_7;
    // 0x80110BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_80110BDC:
    // 0x80110BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110BE0:
    // 0x80110BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80110BE8: jr          $ra
    // 0x80110BEC: nop

    return;
    // 0x80110BEC: nop

;}
RECOMP_FUNC void func_800169A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800169A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800169AC: jr          $ra
    // 0x800169B0: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
    return;
    // 0x800169B0: addiu       $v0, $v0, -0x64A8
    ctx->r2 = ADD32(ctx->r2, -0X64A8);
;}
RECOMP_FUNC void _chprisonbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FE0: syscall     491
    recomp_syscall_handler(rdram, ctx, 0x80086FE0);
    return;
    // 0x80086FE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chcrystalbaddie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086648: syscall     352
    recomp_syscall_handler(rdram, ctx, 0x80086648);
    return;
    // 0x8008664C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D70: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D70);
    return;
    // 0x80082D74: addi        $t0, $zero, 0xD8
    ctx->r8 = ADD32(0, 0XD8);
;}
RECOMP_FUNC void func_8001DA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DA60: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001DA64: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001DA68: lw          $t6, -0x27F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X27F0);
    // 0x8001DA6C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001DA70: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8001DA74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001DA78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001DA7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001DA80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001DA84: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001DA88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001DA8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DA90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DA94: bne         $t6, $zero, L_8001DB60
    if (ctx->r14 != 0) {
        // 0x8001DA98: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001DB60;
    }
    // 0x8001DA98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DA9C: bne         $a0, $zero, L_8001DAB0
    if (ctx->r4 != 0) {
        // 0x8001DAA0: nop
    
            goto L_8001DAB0;
    }
    // 0x8001DAA0: nop

    // 0x8001DAA4: jal         0x80014ED4
    // 0x8001DAA8: nop

    func_80014ED4(rdram, ctx);
        goto after_0;
    // 0x8001DAA8: nop

    after_0:
    // 0x8001DAAC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
L_8001DAB0:
    // 0x8001DAB0: jal         0x80014EC8
    // 0x8001DAB4: nop

    func_80014EC8(rdram, ctx);
        goto after_1;
    // 0x8001DAB4: nop

    after_1:
    // 0x8001DAB8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001DABC: jal         0x8002E6E0
    // 0x8001DAC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8001DAC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8001DAC4: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x8001DAC8: addiu       $fp, $fp, -0x2E90
    ctx->r30 = ADD32(ctx->r30, -0X2E90);
    // 0x8001DACC: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8001DAD0: addiu       $s5, $zero, 0x38
    ctx->r21 = ADD32(0, 0X38);
    // 0x8001DAD4: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
L_8001DAD8:
    // 0x8001DAD8: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001DADC: lw          $t7, -0x27F4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X27F4);
    // 0x8001DAE0: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8001DAE4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001DAE8: addu        $s3, $s7, $t7
    ctx->r19 = ADD32(ctx->r23, ctx->r15);
    // 0x8001DAEC: div         $zero, $s3, $at
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r1)));
    // 0x8001DAF0: mfhi        $s3
    ctx->r19 = hi;
    // 0x8001DAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001DAF8: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
L_8001DAFC:
    // 0x8001DAFC: beq         $s2, $zero, L_8001DB18
    if (ctx->r18 == 0) {
        // 0x8001DB00: lbu         $v0, 0x0($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X0);
            goto L_8001DB18;
    }
    // 0x8001DB00: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8001DB04: beql        $v0, $zero, L_8001DB34
    if (ctx->r2 == 0) {
        // 0x8001DB08: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001DB34;
    }
    goto skip_0;
    // 0x8001DB08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001DB0C: beql        $v0, $s4, L_8001DB34
    if (ctx->r2 == ctx->r20) {
        // 0x8001DB10: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001DB34;
    }
    goto skip_1;
    // 0x8001DB10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8001DB14: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8001DB18:
    // 0x8001DB18: beq         $v0, $zero, L_8001DB30
    if (ctx->r2 == 0) {
        // 0x8001DB1C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8001DB30;
    }
    // 0x8001DB1C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001DB20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DB24: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8001DB28: jal         0x8001D6C0
    // 0x8001DB2C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    func_8001D6C0(rdram, ctx);
        goto after_3;
    // 0x8001DB2C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
    after_3:
L_8001DB30:
    // 0x8001DB30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001DB34:
    // 0x8001DB34: bne         $s0, $s5, L_8001DAFC
    if (ctx->r16 != ctx->r21) {
        // 0x8001DB38: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001DAFC;
    }
    // 0x8001DB38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001DB3C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001DB40: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8001DB44: bne         $s7, $at, L_8001DAD8
    if (ctx->r23 != ctx->r1) {
        // 0x8001DB48: addiu       $fp, $fp, 0x38
        ctx->r30 = ADD32(ctx->r30, 0X38);
            goto L_8001DAD8;
    }
    // 0x8001DB48: addiu       $fp, $fp, 0x38
    ctx->r30 = ADD32(ctx->r30, 0X38);
    // 0x8001DB4C: jal         0x80014EC8
    // 0x8001DB50: nop

    func_80014EC8(rdram, ctx);
        goto after_4;
    // 0x8001DB50: nop

    after_4:
    // 0x8001DB54: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001DB58: jal         0x8002E660
    // 0x8001DB5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x8001DB5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_8001DB60:
    // 0x8001DB60: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DB64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DB68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DB6C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001DB70: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001DB74: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001DB78: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DB7C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001DB80: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001DB84: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001DB88: jr          $ra
    // 0x8001DB8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001DB8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80095A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80095A80: jal         0x800EA05C
    // 0x80095A84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80095A84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80095A88: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x80095A8C: bne         $v0, $at, L_80095AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80095A90: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80095AC0;
    }
    // 0x80095A90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80095A94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80095A98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80095A9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80095AA0: beq         $t6, $zero, L_80095AB8
    if (ctx->r14 == 0) {
        // 0x80095AA4: nop
    
            goto L_80095AB8;
    }
    // 0x80095AA4: nop

    // 0x80095AA8: jal         0x80095A08
    // 0x80095AAC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80095A08(rdram, ctx);
        goto after_1;
    // 0x80095AAC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80095AB0: b           L_80095AC4
    // 0x80095AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80095AC4;
    // 0x80095AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095AB8:
    // 0x80095AB8: jal         0x80095A08
    // 0x80095ABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80095A08(rdram, ctx);
        goto after_2;
    // 0x80095ABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80095AC0:
    // 0x80095AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095AC4:
    // 0x80095AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095AC8: jr          $ra
    // 0x80095ACC: nop

    return;
    // 0x80095ACC: nop

;}
RECOMP_FUNC void func_8011309C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011309C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801130A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801130A4: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x801130A8: jal         0x80110840
    // 0x801130AC: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x801130AC: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    after_0:
    // 0x801130B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801130B4: jal         0x800F5B64
    // 0x801130B8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800F5B64(rdram, ctx);
        goto after_1;
    // 0x801130B8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_1:
    // 0x801130BC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801130C0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x801130C4: jal         0x801107F0
    // 0x801130C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x801130C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x801130CC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x801130D0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x801130D4: jal         0x800EFB24
    // 0x801130D8: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x801130D8: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x801130DC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x801130E0: jal         0x800EF410
    // 0x801130E4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EF410(rdram, ctx);
        goto after_4;
    // 0x801130E4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_4:
    // 0x801130E8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x801130EC: jal         0x800EE7F8
    // 0x801130F0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x801130F0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_5:
    // 0x801130F4: jal         0x800EEF94
    // 0x801130F8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800EEF94(rdram, ctx);
        goto after_6;
    // 0x801130F8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_6:
    // 0x801130FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80113100: lwc1        $f2, 0x65B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65B0);
    // 0x80113104: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80113108: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8011310C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80113110: nop

    // 0x80113114: bc1fl       L_8011313C
    if (!c1cs) {
        // 0x80113118: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_8011313C;
    }
    goto skip_0;
    // 0x80113118: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    skip_0:
    // 0x8011311C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80113120: jal         0x800EFA20
    // 0x80113124: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    func_800EFA20(rdram, ctx);
        goto after_7;
    // 0x80113124: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_7:
    // 0x80113128: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8011312C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80113130: jal         0x800EE780
    // 0x80113134: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x80113134: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_8:
    // 0x80113138: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_8011313C:
    // 0x8011313C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80113140: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80113144: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80113148: beq         $at, $zero, L_801131F0
    if (ctx->r1 == 0) {
        // 0x8011314C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_801131F0;
    }
    // 0x8011314C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80113150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80113154: addu        $at, $at, $t8
    gpr jr_addend_8011315C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80113158: lw          $t8, 0x65B4($at)
    ctx->r24 = ADD32(ctx->r1, 0X65B4);
    // 0x8011315C: jr          $t8
    // 0x80113160: nop

    switch (jr_addend_8011315C >> 2) {
        case 0: goto L_80113164; break;
        case 1: goto L_80113174; break;
        case 2: goto L_8011319C; break;
        case 3: goto L_801131C4; break;
        case 4: goto L_801131E8; break;
        default: switch_error(__func__, 0x8011315C, 0x801265B4);
    }
    // 0x80113160: nop

L_80113164:
    // 0x80113164: jal         0x800EFD24
    // 0x80113168: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x80113168: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_9:
    // 0x8011316C: b           L_801131F4
    // 0x80113170: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_801131F4;
    // 0x80113170: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_80113174:
    // 0x80113174: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80113178: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8011317C: jal         0x800EFA20
    // 0x80113180: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_10;
    // 0x80113180: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80113184: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80113188: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8011318C: jal         0x800EF934
    // 0x80113190: lui         $a2, 0xC2B4
    ctx->r6 = S32(0XC2B4 << 16);
    func_800EF934(rdram, ctx);
        goto after_11;
    // 0x80113190: lui         $a2, 0xC2B4
    ctx->r6 = S32(0XC2B4 << 16);
    after_11:
    // 0x80113194: b           L_801131F4
    // 0x80113198: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_801131F4;
    // 0x80113198: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_8011319C:
    // 0x8011319C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x801131A0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x801131A4: jal         0x800EFA20
    // 0x801131A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_12;
    // 0x801131A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x801131AC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801131B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801131B4: jal         0x800EF934
    // 0x801131B8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_800EF934(rdram, ctx);
        goto after_13;
    // 0x801131B8: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_13:
    // 0x801131BC: b           L_801131F4
    // 0x801131C0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_801131F4;
    // 0x801131C0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_801131C4:
    // 0x801131C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801131C8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x801131CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801131D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801131D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801131D8: jal         0x800EFA4C
    // 0x801131DC: nop

    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x801131DC: nop

    after_14:
    // 0x801131E0: b           L_801131F4
    // 0x801131E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_801131F4;
    // 0x801131E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_801131E8:
    // 0x801131E8: jal         0x800EFD24
    // 0x801131EC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_15;
    // 0x801131EC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_15:
L_801131F0:
    // 0x801131F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
L_801131F4:
    // 0x801131F4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801131F8: jal         0x800EE780
    // 0x801131FC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EE780(rdram, ctx);
        goto after_16;
    // 0x801131FC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_16:
    // 0x80113200: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x80113204: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80113208: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8011320C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80113210: jal         0x800C6A7C
    // 0x80113214: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    func_800C6A7C(rdram, ctx);
        goto after_17;
    // 0x80113214: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    after_17:
    // 0x80113218: beq         $v0, $zero, L_80113280
    if (ctx->r2 == 0) {
        // 0x8011321C: lw          $t8, 0x90($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X90);
            goto L_80113280;
    }
    // 0x8011321C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80113220: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80113224: lui         $t7, 0x86
    ctx->r15 = S32(0X86 << 16);
    // 0x80113228: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x8011322C: lw          $v0, 0x28($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X28);
    // 0x80113230: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80113234: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x80113238: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8011323C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80113240: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x80113244: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80113248: lw          $v0, 0x28($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X28);
    // 0x8011324C: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80113250: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x80113254: bnel        $at, $zero, L_8011328C
    if (ctx->r1 != 0) {
        // 0x80113258: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8011328C;
    }
    goto skip_1;
    // 0x80113258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8011325C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80113260: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80113264: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80113268: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8011326C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80113270: jal         0x80112E98
    // 0x80113274: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80112E98(rdram, ctx);
        goto after_18;
    // 0x80113274: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_18:
    // 0x80113278: b           L_80113290
    // 0x8011327C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80113290;
    // 0x8011327C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80113280:
    // 0x80113280: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80113284: sw          $zero, 0x10($t9)
    MEM_W(0X10, ctx->r25) = 0;
    // 0x80113288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011328C:
    // 0x8011328C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80113290:
    // 0x80113290: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80113294: jr          $ra
    // 0x80113298: nop

    return;
    // 0x80113298: nop

;}
RECOMP_FUNC void sudeflect_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800594: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800598: addiu       $t6, $t6, 0x1020
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x8080059C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005A0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808005A4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808005A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808005AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808005B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808005B8: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x808005BC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808005C0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808005C4: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x808005C8: blez        $t7, L_8080060C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808005CC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8080060C;
    }
    // 0x808005CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005D0: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x808005D4: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
L_808005D8:
    // 0x808005D8: jal         0x80800630
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800630_sudeflect(rdram, ctx);
        goto after_0;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808005E0: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F4;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808005EC: jal         0x800F7700
    // 0x808005F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F7700(rdram, ctx);
        goto after_1;
    // 0x808005F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
L_808005F4:
    // 0x808005F4: lw          $t8, 0x24($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X24);
    // 0x808005F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808005FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800600: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800604: bnel        $at, $zero, L_808005D8
    if (ctx->r1 != 0) {
        // 0x80800608: lw          $s0, 0x4($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X4);
            goto L_808005D8;
    }
    goto skip_0;
    // 0x80800608: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    skip_0:
L_8080060C:
    // 0x8080060C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800610: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800614: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800618: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080061C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800620: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800624: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800628: jr          $ra
    // 0x8080062C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080062C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CF0: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CF0);
    return;
    // 0x80084CF4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void gccubesearch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80800080: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800084: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800088: nop

    // 0x8080008C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80800090: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80800094: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800098: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8080009C: nop

    // 0x808000A0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x808000A4: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808000A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808000AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808000B0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x808000B4: jal         0x808006C4
    // 0x808000B8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    gccubesearch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_8001B3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3B0: lbu         $t7, -0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X1);
    // 0x8001B3B4: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8001B3B8: jr          $ra
    // 0x8001B3BC: sb          $t8, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r24;
    return;
    // 0x8001B3BC: sb          $t8, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80800898_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080089C: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808008A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008A4: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x808008A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008B0: beq         $at, $zero, L_80800B00
    if (ctx->r1 == 0) {
        // 0x808008B4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800B00;
    }
    // 0x808008B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808008B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808008BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28A4) << 16);
    // 0x808008C0: addu        $at, $at, $t7
    gpr jr_addend_808008C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808008C4: lw          $t7, 0x28A4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28A4));
    // 0x808008C8: jr          $t7
    // 0x808008CC: nop

    switch (jr_addend_808008C8 >> 2) {
        case 0: goto L_808008D0; break;
        case 1: goto L_808008E8; break;
        case 2: goto L_80800B00; break;
        case 3: goto L_808008F8; break;
        case 4: goto L_80800948; break;
        case 5: goto L_80800988; break;
        case 6: goto L_80800B00; break;
        case 7: goto L_808009A8; break;
        case 8: goto L_80800A04; break;
        case 9: goto L_80800B00; break;
        case 10: goto L_80800A2C; break;
        case 11: goto L_80800A54; break;
        case 12: goto L_80800A74; break;
        case 13: goto L_80800A94; break;
        case 14: goto L_80800AC0; break;
        case 15: goto L_80800B00; break;
        case 16: goto L_80800AD0; break;
        default: switch_error(__func__, 0x808008C8, 0x808028A4);
    }
    // 0x808008CC: nop

L_808008D0:
    // 0x808008D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: jal         0x8010A624
    // 0x808008DC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_8010A624(rdram, ctx);
        goto after_0;
    // 0x808008DC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x808008E0: b           L_80800B04
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008E8:
    // 0x808008E8: jal         0x8010A63C
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_1;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008F0: b           L_80800B04
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008F8:
    // 0x808008F8: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    // 0x808008FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800900: jal         0x80101180
    // 0x80800904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800908: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080090C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800910: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800914: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800918: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    // 0x8080091C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800920: jal         0x800DA298
    // 0x80800924: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800924: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80800928: bne         $v0, $zero, L_80800B00
    if (ctx->r2 != 0) {
        // 0x8080092C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800B00;
    }
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800930: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800938: jal         0x80085708
    // 0x8080093C: addiu       $a3, $zero, 0x850
    ctx->r7 = ADD32(0, 0X850);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x8080093C: addiu       $a3, $zero, 0x850
    ctx->r7 = ADD32(0, 0X850);
    after_4:
    // 0x80800940: b           L_80800B04
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800948:
    // 0x80800948: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    // 0x8080094C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80800950: jal         0x80101180
    // 0x80800954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800958: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080095C: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800960: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800964: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800968: ori         $t0, $t9, 0x3C
    ctx->r8 = ctx->r25 | 0X3C;
    // 0x8080096C: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80800970: bne         $t2, $at, L_80800B00
    if (ctx->r10 != ctx->r1) {
        // 0x80800974: sh          $t0, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r8;
            goto L_80800B00;
    }
    // 0x80800974: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80800978: jal         0x80801CD8
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CD8_chfactorymagnet(rdram, ctx);
        goto after_6;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800980: b           L_80800B04
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800988:
    // 0x80800988: jal         0x800DA298
    // 0x8080098C: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x8080098C: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    after_7:
    // 0x80800990: bnel        $v0, $zero, L_80800B04
    if (ctx->r2 != 0) {
        // 0x80800994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B04;
    }
    goto skip_0;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800998: jal         0x800DA544
    // 0x8080099C: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x8080099C: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    after_8:
    // 0x808009A0: b           L_80800B04
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009A8:
    // 0x808009A8: jal         0x80800E40
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E40_chfactorymagnet(rdram, ctx);
        goto after_9;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808009B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808009B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808009B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808009C0: jal         0x80085708
    // 0x808009C4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x808009C4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_10:
    // 0x808009C8: jal         0x800DA544
    // 0x808009CC: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x808009CC: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_11:
    // 0x808009D0: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    // 0x808009D4: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    // 0x808009D8: jal         0x80101180
    // 0x808009DC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x808009DC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_12:
    // 0x808009E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808009E4: jal         0x800898B8
    // 0x808009E8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_13;
    // 0x808009E8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_13:
    // 0x808009EC: jal         0x800DA544
    // 0x808009F0: addiu       $a0, $zero, 0x57E
    ctx->r4 = ADD32(0, 0X57E);
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x808009F0: addiu       $a0, $zero, 0x57E
    ctx->r4 = ADD32(0, 0X57E);
    after_14:
    // 0x808009F4: jal         0x8010A63C
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_15;
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808009FC: b           L_80800B04
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A04:
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: jal         0x80100094
    // 0x80800A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A14: jal         0x800898D0
    // 0x80800A18: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_17;
    // 0x80800A18: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_17:
    // 0x80800A1C: jal         0x80086AF0
    // 0x80800A20: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_18;
    // 0x80800A20: nop

    after_18:
    // 0x80800A24: b           L_80800B04
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A2C:
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A30: jal         0x80100094
    // 0x80800A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80800A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800A38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A3C: jal         0x800898C8
    // 0x80800A40: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_20;
    // 0x80800A40: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_20:
    // 0x80800A44: jal         0x8010A63C
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_21;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800A4C: b           L_80800B04
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A54:
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: jal         0x80100094
    // 0x80800A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_22;
    // 0x80800A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800A60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A64: jal         0x800898C8
    // 0x80800A68: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_23;
    // 0x80800A68: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_23:
    // 0x80800A6C: b           L_80800B04
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A74:
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: jal         0x80100094
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A84: jal         0x800898C0
    // 0x80800A88: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_25;
    // 0x80800A88: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_25:
    // 0x80800A8C: b           L_80800B04
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A94:
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: jal         0x80100094
    // 0x80800A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x80800A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80089848
    // 0x80800AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x80800AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB0: jal         0x8010A800
    // 0x80800AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_28;
    // 0x80800AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x80800AB8: b           L_80800B04
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800B04;
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AC0:
    // 0x80800AC0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800AC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AC8: b           L_80800B00
    // 0x80800ACC: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
        goto L_80800B00;
    // 0x80800ACC: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
L_80800AD0:
    // 0x80800AD0: jal         0x8010A63C
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_29;
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800ADC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800AE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800AE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AE8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800AEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AF0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800AF4: jal         0x800DC178
    // 0x80800AF8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_30;
    // 0x80800AF8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    after_30:
    // 0x80800AFC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80800B00:
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B04:
    // 0x80800B04: jal         0x80101FDC
    // 0x80800B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101FDC(rdram, ctx);
        goto after_31;
    // 0x80800B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_31:
    // 0x80800B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B18: jr          $ra
    // 0x80800B1C: nop

    return;
    // 0x80800B1C: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A538: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A538);
    return;
    // 0x8008A53C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80104E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104E24: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80104E28: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80104E2C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80104E30: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80104E34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80104E38:
    // 0x80104E38: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80104E3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80104E40: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80104E44: bgez        $v0, L_80104E54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80104E48: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80104E54;
    }
    // 0x80104E48: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80104E4C: b           L_80104E68
    // 0x80104E50: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80104E68;
    // 0x80104E50: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80104E54:
    // 0x80104E54: bnel        $at, $zero, L_80104E68
    if (ctx->r1 != 0) {
        // 0x80104E58: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80104E68;
    }
    goto skip_0;
    // 0x80104E58: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    skip_0:
    // 0x80104E5C: b           L_80104E68
    // 0x80104E60: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
        goto L_80104E68;
    // 0x80104E60: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x80104E64: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_80104E68:
    // 0x80104E68: bne         $v1, $a0, L_80104E38
    if (ctx->r3 != ctx->r4) {
        // 0x80104E6C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80104E38;
    }
    // 0x80104E6C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80104E70: jr          $ra
    // 0x80104E74: nop

    return;
    // 0x80104E74: nop

;}
RECOMP_FUNC void _mlspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089108: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089108);
    return;
    // 0x8008910C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chbottlesfamily_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1300, 0XDE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xDE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1300, 0XDE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xDE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1300, 0XDE0));
;}
RECOMP_FUNC void func_800900FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800900FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090104: jal         0x800F54E4
    // 0x80090108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009010C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090110: jal         0x800F640C
    // 0x80090114: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F640C(rdram, ctx);
        goto after_1;
    // 0x80090114: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090120: jr          $ra
    // 0x80090124: nop

    return;
    // 0x80090124: nop

;}
RECOMP_FUNC void func_80800008_baflamethrower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080000C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: lw          $t6, 0x88($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X88);
    // 0x8080001C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800020: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80800024: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80800028: jalr        $t9
    // 0x8080002C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8080002C: nop

    after_0:
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x80084B78
    // 0x80800038: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _baflameline_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80084B80
    // 0x80800044: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _baflameline_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80800048: lw          $t7, 0x88($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X88);
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x80084B88
    // 0x80800054: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    _baflameline_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800054: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_3:
    // 0x80800058: lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X88);
    // 0x8080005C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800060: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800064: jal         0x800F15F8
    // 0x80800068: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x80800068: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    after_4:
    // 0x8080006C: lw          $t8, 0x88($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X88);
    // 0x80800070: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_800CA628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA628: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CA62C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800CA630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA634: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CA638: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_800CA63C:
    // 0x800CA63C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800CA640: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CA644: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800CA648: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800CA64C: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800CA650: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800CA654: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800CA658: bne         $v0, $a0, L_800CA63C
    if (ctx->r2 != ctx->r4) {
        // 0x800CA65C: swc1        $f6, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
            goto L_800CA63C;
    }
    // 0x800CA65C: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
    // 0x800CA660: jr          $ra
    // 0x800CA664: nop

    return;
    // 0x800CA664: nop

;}
RECOMP_FUNC void func_800CA7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA7B4: jr          $ra
    // 0x800CA7B8: lwc1        $f0, 0xEC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XEC);
    return;
    // 0x800CA7B8: lwc1        $f0, 0xEC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XEC);
;}
RECOMP_FUNC void func_80800638_chlinkpipefan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080063C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800640: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800648: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080064C: beq         $a1, $v1, L_80800858
    if (ctx->r5 == ctx->r3) {
        // 0x80800650: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800858;
    }
    // 0x80800650: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800654: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800658: beq         $a1, $at, L_80800810
    if (ctx->r5 == ctx->r1) {
        // 0x8080065C: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800810;
    }
    // 0x8080065C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800660: beq         $a1, $at, L_80800680
    if (ctx->r5 == ctx->r1) {
        // 0x80800664: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80800680;
    }
    // 0x80800664: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800668: beq         $a1, $at, L_808006F8
    if (ctx->r5 == ctx->r1) {
        // 0x8080066C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808006F8;
    }
    // 0x8080066C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800670: beq         $a1, $at, L_808007D0
    if (ctx->r5 == ctx->r1) {
        // 0x80800674: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808007D0;
    }
    // 0x80800674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800678: b           L_808008C4
    // 0x8080067C: nop

        goto L_808008C4;
    // 0x8080067C: nop

L_80800680:
    // 0x80800680: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800684: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800688: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080068C: beq         $t7, $at, L_808006F0
    if (ctx->r15 == ctx->r1) {
        // 0x80800690: nop
    
            goto L_808006F0;
    }
    // 0x80800690: nop

    // 0x80800694: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80800698: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080069C: lw          $v0, 0x18($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X18);
    // 0x808006A0: sll         $t9, $v0, 11
    ctx->r25 = S32(ctx->r2 << 11);
    // 0x808006A4: srl         $v0, $t9, 28
    ctx->r2 = S32(U32(ctx->r25) >> 28);
    // 0x808006A8: bne         $v1, $v0, L_808006D0
    if (ctx->r3 != ctx->r2) {
        // 0x808006AC: nop
    
            goto L_808006D0;
    }
    // 0x808006AC: nop

    // 0x808006B0: jal         0x800F54E4
    // 0x808006B4: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808006B4: nop

    after_0:
    // 0x808006B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006BC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808006C0: jal         0x800F79DC
    // 0x808006C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F79DC(rdram, ctx);
        goto after_1;
    // 0x808006C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808006C8: b           L_808008C4
    // 0x808006CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C4;
    // 0x808006CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006D0:
    // 0x808006D0: bne         $v0, $at, L_808006F0
    if (ctx->r2 != ctx->r1) {
        // 0x808006D4: nop
    
            goto L_808006F0;
    }
    // 0x808006D4: nop

    // 0x808006D8: jal         0x800F54E4
    // 0x808006DC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808006DC: nop

    after_2:
    // 0x808006E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006E8: jal         0x800F79DC
    // 0x808006EC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F79DC(rdram, ctx);
        goto after_3;
    // 0x808006EC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_3:
L_808006F0:
    // 0x808006F0: b           L_808008C4
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C4;
    // 0x808006F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006F8:
    // 0x808006F8: jal         0x80106790
    // 0x808006FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808006FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800700: lw          $t1, 0x6C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X6C);
    // 0x80800704: addiu       $at, $zero, 0x15C
    ctx->r1 = ADD32(0, 0X15C);
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: sll         $t2, $t1, 11
    ctx->r10 = S32(ctx->r9 << 11);
    // 0x80800710: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x80800714: bnel        $t3, $at, L_80800730
    if (ctx->r11 != ctx->r1) {
        // 0x80800718: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_80800730;
    }
    goto skip_0;
    // 0x80800718: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8080071C: jal         0x808003B4
    // 0x80800720: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808003B4_chlinkpipefan(rdram, ctx);
        goto after_5;
    // 0x80800720: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800724: b           L_8080076C
    // 0x80800728: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
        goto L_8080076C;
    // 0x80800728: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x8080072C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_80800730:
    // 0x80800730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800734: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x80800738: sll         $t6, $t5, 11
    ctx->r14 = S32(ctx->r13 << 11);
    // 0x8080073C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80800740: bnel        $t7, $at, L_8080076C
    if (ctx->r15 != ctx->r1) {
        // 0x80800744: lw          $t0, 0x6C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X6C);
            goto L_8080076C;
    }
    goto skip_1;
    // 0x80800744: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    skip_1:
    // 0x80800748: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x8080074C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800758: beql        $t9, $at, L_8080076C
    if (ctx->r25 == ctx->r1) {
        // 0x8080075C: lw          $t0, 0x6C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X6C);
            goto L_8080076C;
    }
    goto skip_2;
    // 0x8080075C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    skip_2:
    // 0x80800760: jal         0x808003B4
    // 0x80800764: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808003B4_chlinkpipefan(rdram, ctx);
        goto after_6;
    // 0x80800764: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800768: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
L_8080076C:
    // 0x8080076C: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800770: bnel        $t1, $zero, L_808007BC
    if (ctx->r9 != 0) {
        // 0x80800774: lhu         $t4, 0x6E($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X6E);
            goto L_808007BC;
    }
    goto skip_3;
    // 0x80800774: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    skip_3:
    // 0x80800778: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x8080077C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80800788: bne         $t3, $at, L_808007AC
    if (ctx->r11 != ctx->r1) {
        // 0x8080078C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808007AC;
    }
    // 0x8080078C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800790: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2248, 0X9B8) << 16);
    // 0x80800794: addiu       $a2, $a2, 0x9B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2248, 0X9B8));
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: jal         0x80089D18
    // 0x808007A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808007A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808007A4: b           L_808007BC
    // 0x808007A8: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
        goto L_808007BC;
    // 0x808007A8: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
L_808007AC:
    // 0x808007AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2248, 0X9AC) << 16);
    // 0x808007B0: jal         0x80089D18
    // 0x808007B4: addiu       $a2, $a2, 0x9AC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2248, 0X9AC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808007B4: addiu       $a2, $a2, 0x9AC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2248, 0X9AC));
    after_8:
    // 0x808007B8: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
L_808007BC:
    // 0x808007BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808007C0: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808007C4: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x808007C8: b           L_808008C4
    // 0x808007CC: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
        goto L_808008C4;
    // 0x808007CC: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
L_808007D0:
    // 0x808007D0: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808007D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808007D8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808007DC: bne         $t8, $at, L_80800808
    if (ctx->r24 != ctx->r1) {
        // 0x808007E0: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80800808;
    }
    // 0x808007E0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808007E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007E8: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x808007F4: nop

    // 0x808007F8: bc1f        L_80800808
    if (!c1cs) {
        // 0x808007FC: nop
    
            goto L_80800808;
    }
    // 0x808007FC: nop

    // 0x80800800: jal         0x808003B4
    // 0x80800804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808003B4_chlinkpipefan(rdram, ctx);
        goto after_9;
    // 0x80800804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80800808:
    // 0x80800808: b           L_808008C4
    // 0x8080080C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C4;
    // 0x8080080C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800810:
    // 0x80800810: jal         0x801015D0
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_10;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800818: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080081C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800820: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80800824: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800828: jal         0x800F10B4
    // 0x8080082C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x8080082C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_11:
    // 0x80800830: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800834: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800838: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8080083C: jal         0x800DF6BC
    // 0x80800840: nop

    func_800DF6BC(rdram, ctx);
        goto after_12;
    // 0x80800840: nop

    after_12:
    // 0x80800844: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800848: jal         0x800DF744
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_13;
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800850: b           L_808008C4
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C4;
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800858:
    // 0x80800858: jal         0x80101080
    // 0x8080085C: nop

    func_80101080(rdram, ctx);
        goto after_14;
    // 0x8080085C: nop

    after_14:
    // 0x80800860: jal         0x80106790
    // 0x80800864: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_15;
    // 0x80800864: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x80800868: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080086C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800874: jal         0x80086E00
    // 0x80800878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8080087C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800880: jal         0x80086E08
    // 0x80800884: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _chskeletonexplode_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800884: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_17:
    // 0x80800888: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080088C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800890: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80800894: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800898: jal         0x800F10B4
    // 0x8080089C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_18;
    // 0x8080089C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_18:
    // 0x808008A0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808008A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008A8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808008AC: jal         0x80086E10
    // 0x808008B0: nop

    _chskeletonexplode_entrypoint_5(rdram, ctx);
        goto after_19;
    // 0x808008B0: nop

    after_19:
    // 0x808008B4: jal         0x800FFA88
    // 0x808008B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_20;
    // 0x808008B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_20:
    // 0x808008BC: b           L_808008C4
    // 0x808008C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C4;
    // 0x808008C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008C4:
    // 0x808008C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008D0: jr          $ra
    // 0x808008D4: nop

    return;
    // 0x808008D4: nop

;}
RECOMP_FUNC void sucoasterplayer_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080061C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800624: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800628: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080062C: jal         0x80100094
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800634: jal         0x80107C00
    // 0x80800638: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80107C00(rdram, ctx);
        goto after_1;
    // 0x80800638: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080063C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800640: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800644: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800648: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080064C: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x80800650: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800654: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800658: jal         0x800F15F8
    // 0x8080065C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x8080065C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x80800660: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800664: jal         0x8008A188
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_18(rdram, ctx);
        goto after_3;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080066C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800670: jal         0x800F2094
    // 0x80800674: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F2094(rdram, ctx);
        goto after_4;
    // 0x80800674: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_4:
    // 0x80800678: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080067C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800680: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080068C: jal         0x80102BF8
    // 0x80800690: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    func_80102BF8(rdram, ctx);
        goto after_5;
    // 0x80800690: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    after_5:
    // 0x80800694: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800698: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080069C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x808006A8: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x808006AC: nop

    // 0x808006B0: bc1f        L_808006C0
    if (!c1cs) {
        // 0x808006B4: nop
    
            goto L_808006C0;
    }
    // 0x808006B4: nop

    // 0x808006B8: b           L_808006CC
    // 0x808006BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006CC;
    // 0x808006BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C0:
    // 0x808006C0: jal         0x8010B990
    // 0x808006C4: ori         $a1, $a1, 0x5025
    ctx->r5 = ctx->r5 | 0X5025;
    func_8010B990(rdram, ctx);
        goto after_6;
    // 0x808006C4: ori         $a1, $a1, 0x5025
    ctx->r5 = ctx->r5 | 0X5025;
    after_6:
    // 0x808006C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006CC:
    // 0x808006CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void func_8080035C_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800364: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800368: jal         0x80100094
    // 0x8080036C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080036C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800370: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800374: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800378: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8080037C: lhu         $v1, 0x72($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X72);
    // 0x80800380: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800384: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800388: beq         $t6, $at, L_808003B4
    if (ctx->r14 == ctx->r1) {
        // 0x8080038C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003B4;
    }
    // 0x8080038C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800390: beq         $t6, $at, L_808003B4
    if (ctx->r14 == ctx->r1) {
        // 0x80800394: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808003B4;
    }
    // 0x80800394: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800398: beq         $t6, $at, L_808003C4
    if (ctx->r14 == ctx->r1) {
        // 0x8080039C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808003C4;
    }
    // 0x8080039C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808003A4: beql        $t6, $at, L_808003D8
    if (ctx->r14 == ctx->r1) {
        // 0x808003A8: lw          $t7, 0x10($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X10);
            goto L_808003D8;
    }
    goto skip_0;
    // 0x808003A8: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x808003AC: b           L_80800410
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800410;
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B4:
    // 0x808003B4: jal         0x8080000C
    // 0x808003B8: addiu       $a1, $zero, 0x26F
    ctx->r5 = ADD32(0, 0X26F);
    func_8080000C_cheggsplode(rdram, ctx);
        goto after_1;
    // 0x808003B8: addiu       $a1, $zero, 0x26F
    ctx->r5 = ADD32(0, 0X26F);
    after_1:
    // 0x808003BC: b           L_80800410
    // 0x808003C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800410;
    // 0x808003C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003C4:
    // 0x808003C4: jal         0x8080000C
    // 0x808003C8: addiu       $a1, $zero, 0x270
    ctx->r5 = ADD32(0, 0X270);
    func_8080000C_cheggsplode(rdram, ctx);
        goto after_2;
    // 0x808003C8: addiu       $a1, $zero, 0x270
    ctx->r5 = ADD32(0, 0X270);
    after_2:
    // 0x808003CC: b           L_80800410
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800410;
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D4: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
L_808003D8:
    // 0x808003D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808003DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808003E0: beq         $t7, $zero, L_80800404
    if (ctx->r15 == 0) {
        // 0x808003E4: nop
    
            goto L_80800404;
    }
    // 0x808003E4: nop

    // 0x808003E8: lw          $a0, 0x10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X10);
    // 0x808003EC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x808003F0: jal         0x800863E8
    // 0x808003F4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808003F4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x808003F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x808003FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
L_80800404:
    // 0x80800404: jal         0x800FFAB0
    // 0x80800408: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800408: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x8080040C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800410:
    // 0x80800410: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void func_80094538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009453C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094540: jal         0x80094510
    // 0x80094544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80094510(rdram, ctx);
        goto after_0;
    // 0x80094544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80094548: jal         0x8009E9E4
    // 0x8009454C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8009E9E4(rdram, ctx);
        goto after_1;
    // 0x8009454C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80094550: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80094554: jal         0x80085300
    // 0x80094558: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _batimer_get(rdram, ctx);
        goto after_2;
    // 0x80094558: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_2:
    // 0x8009455C: jal         0x8009E9F0
    // 0x80094560: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8009E9F0(rdram, ctx);
        goto after_3;
    // 0x80094560: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80094564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009456C: jr          $ra
    // 0x80094570: nop

    return;
    // 0x80094570: nop

;}
RECOMP_FUNC void _chlavagargoyle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087578: syscall     589
    recomp_syscall_handler(rdram, ctx, 0x80087578);
    return;
    // 0x8008757C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800140_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080014C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800150: jal         0x800EE7F8
    // 0x80800154: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800154: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800158: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080015C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800160: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800164: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80800168: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x8080016C: ori         $a3, $a3, 0x25
    ctx->r7 = ctx->r7 | 0X25;
    // 0x80800170: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800174: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800178: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8080017C: jal         0x800C6A7C
    // 0x80800180: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    func_800C6A7C(rdram, ctx);
        goto after_1;
    // 0x80800180: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    after_1:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800188: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
