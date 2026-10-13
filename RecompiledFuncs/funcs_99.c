#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _sujiggy_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A700: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A700);
    return;
    // 0x8008A704: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _bsdronesuckunder_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083170: syscall     47
    recomp_syscall_handler(rdram, ctx, 0x80083170);
    return;
    // 0x80083174: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080183C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080183C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801844: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801848: jal         0x80100094
    // 0x8080184C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080184C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801854: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801858: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080185C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80801860: bgezl       $t8, L_80801880
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801864: lbu         $t2, 0x79($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X79);
            goto L_80801880;
    }
    goto skip_0;
    // 0x80801864: lbu         $t2, 0x79($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X79);
    skip_0:
    // 0x80801868: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x8080186C: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80801870: ori         $t1, $t0, 0x30
    ctx->r9 = ctx->r8 | 0X30;
    // 0x80801874: b           L_8080188C
    // 0x80801878: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
        goto L_8080188C;
    // 0x80801878: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    // 0x8080187C: lbu         $t2, 0x79($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X79);
L_80801880:
    // 0x80801880: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80801884: ori         $t4, $t3, 0x30
    ctx->r12 = ctx->r11 | 0X30;
    // 0x80801888: sb          $t4, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r12;
L_8080188C:
    // 0x8080188C: lb          $t5, 0x5E($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X5E);
    // 0x80801890: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80801894: sb          $t6, 0x5E($v1)
    MEM_B(0X5E, ctx->r3) = ctx->r14;
    // 0x80801898: jal         0x8010A590
    // 0x8080189C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x8080189C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808018A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018A4: jal         0x808012B4
    // 0x808018A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x808018A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x808018AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018B4: jr          $ra
    // 0x808018B8: nop

    return;
    // 0x808018B8: nop

;}
RECOMP_FUNC void _chpotogoldgame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875B8: syscall     592
    recomp_syscall_handler(rdram, ctx, 0x800875B8);
    return;
    // 0x800875BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808014CC_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014CC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808014D0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x808014D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808014D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014DC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x808014E0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x808014E4: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x808014E8: jal         0x80100094
    // 0x808014EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014F0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x808014F4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808014F8: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // 0x808014FC: slti        $at, $a2, 0x3E
    ctx->r1 = SIGNED(ctx->r6) < 0X3E ? 1 : 0;
    // 0x80801500: bne         $at, $zero, L_80801550
    if (ctx->r1 != 0) {
        // 0x80801504: addiu       $t6, $a2, -0x8D
        ctx->r14 = ADD32(ctx->r6, -0X8D);
            goto L_80801550;
    }
    // 0x80801504: addiu       $t6, $a2, -0x8D
    ctx->r14 = ADD32(ctx->r6, -0X8D);
    // 0x80801508: slti        $at, $a2, 0x41
    ctx->r1 = SIGNED(ctx->r6) < 0X41 ? 1 : 0;
    // 0x8080150C: bne         $at, $zero, L_80801530
    if (ctx->r1 != 0) {
        // 0x80801510: sltiu       $at, $t6, 0x13
        ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
            goto L_80801530;
    }
    // 0x80801510: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x80801514: beq         $at, $zero, L_80801548
    if (ctx->r1 == 0) {
        // 0x80801518: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801548;
    }
    // 0x80801518: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080151C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X436C) << 16);
    // 0x80801520: addu        $at, $at, $t6
    gpr jr_addend_80801528 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801524: lw          $t6, 0x436C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X436C));
    // 0x80801528: jr          $t6
    // 0x8080152C: nop

    switch (jr_addend_80801528 >> 2) {
        case 0: goto L_80801780; break;
        case 1: goto L_80801548; break;
        case 2: goto L_80801548; break;
        case 3: goto L_80801674; break;
        case 4: goto L_80801548; break;
        case 5: goto L_80801548; break;
        case 6: goto L_80801548; break;
        case 7: goto L_80801548; break;
        case 8: goto L_808018B0; break;
        case 9: goto L_808018E0; break;
        case 10: goto L_80801548; break;
        case 11: goto L_80801548; break;
        case 12: goto L_80801548; break;
        case 13: goto L_80801548; break;
        case 14: goto L_80801548; break;
        case 15: goto L_80801548; break;
        case 16: goto L_80801548; break;
        case 17: goto L_80801548; break;
        case 18: goto L_8080190C; break;
        default: switch_error(__func__, 0x80801528, 0x8080436C);
    }
    // 0x8080152C: nop

L_80801530:
    // 0x80801530: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80801534: beq         $a2, $at, L_808015C0
    if (ctx->r6 == ctx->r1) {
        // 0x80801538: lw          $a3, 0x68($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X68);
            goto L_808015C0;
    }
    // 0x80801538: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8080153C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801540: beq         $a2, $at, L_80801638
    if (ctx->r6 == ctx->r1) {
        // 0x80801544: addiu       $v1, $sp, 0x70
        ctx->r3 = ADD32(ctx->r29, 0X70);
            goto L_80801638;
    }
    // 0x80801544: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
L_80801548:
    // 0x80801548: b           L_80801934
    // 0x8080154C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801934;
    // 0x8080154C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801550:
    // 0x80801550: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80801554: beq         $a2, $at, L_808018A0
    if (ctx->r6 == ctx->r1) {
        // 0x80801558: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_808018A0;
    }
    // 0x80801558: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8080155C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801560: beq         $a2, $at, L_808015A0
    if (ctx->r6 == ctx->r1) {
        // 0x80801564: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_808015A0;
    }
    // 0x80801564: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80801568: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080156C: beq         $a2, $at, L_80801588
    if (ctx->r6 == ctx->r1) {
        // 0x80801570: addiu       $v1, $sp, 0x70
        ctx->r3 = ADD32(ctx->r29, 0X70);
            goto L_80801588;
    }
    // 0x80801570: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // 0x80801574: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801578: beq         $a2, $at, L_808015B0
    if (ctx->r6 == ctx->r1) {
        // 0x8080157C: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_808015B0;
    }
    // 0x8080157C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80801580: b           L_80801934
    // 0x80801584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801934;
    // 0x80801584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801588:
    // 0x80801588: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8080158C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80801590: jal         0x80801F30
    // 0x80801594: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    func_80801F30_chweldarboss(rdram, ctx);
        goto after_1;
    // 0x80801594: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    after_1:
    // 0x80801598: b           L_80801934
    // 0x8080159C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x8080159C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015A0:
    // 0x808015A0: jal         0x80802100
    // 0x808015A4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_80802100_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x808015A4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_2:
    // 0x808015A8: b           L_80801938
    // 0x808015AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801938;
    // 0x808015AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808015B0:
    // 0x808015B0: jal         0x8080227C
    // 0x808015B4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_8080227C_chweldarboss(rdram, ctx);
        goto after_3;
    // 0x808015B4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_3:
    // 0x808015B8: b           L_80801934
    // 0x808015BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808015BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015C0:
    // 0x808015C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x808015C4: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x808015C8: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x808015CC: bnel        $t8, $zero, L_80801934
    if (ctx->r24 != 0) {
        // 0x808015D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801934;
    }
    goto skip_0;
    // 0x808015D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808015D4: lhu         $t9, 0x72($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X72);
    // 0x808015D8: srl         $t1, $t9, 10
    ctx->r9 = S32(U32(ctx->r25) >> 10);
    // 0x808015DC: addiu       $t2, $t1, -0xB
    ctx->r10 = ADD32(ctx->r9, -0XB);
    // 0x808015E0: sltiu       $at, $t2, 0x20
    ctx->r1 = ctx->r10 < 0X20 ? 1 : 0;
    // 0x808015E4: beq         $at, $zero, L_80801618
    if (ctx->r1 == 0) {
        // 0x808015E8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80801618;
    }
    // 0x808015E8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808015EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X43B8) << 16);
    // 0x808015F0: addu        $at, $at, $t2
    gpr jr_addend_808015F8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x808015F4: lw          $t2, 0x43B8($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X43B8));
    // 0x808015F8: jr          $t2
    // 0x808015FC: nop

    switch (jr_addend_808015F8 >> 2) {
        case 0: goto L_80801930; break;
        case 1: goto L_80801930; break;
        case 2: goto L_80801618; break;
        case 3: goto L_80801618; break;
        case 4: goto L_80801618; break;
        case 5: goto L_80801930; break;
        case 6: goto L_80801618; break;
        case 7: goto L_80801618; break;
        case 8: goto L_80801618; break;
        case 9: goto L_80801618; break;
        case 10: goto L_80801618; break;
        case 11: goto L_80801930; break;
        case 12: goto L_80801930; break;
        case 13: goto L_80801618; break;
        case 14: goto L_80801618; break;
        case 15: goto L_80801930; break;
        case 16: goto L_80801618; break;
        case 17: goto L_80801618; break;
        case 18: goto L_80801618; break;
        case 19: goto L_80801618; break;
        case 20: goto L_80801618; break;
        case 21: goto L_80801600; break;
        case 22: goto L_80801618; break;
        case 23: goto L_80801618; break;
        case 24: goto L_80801618; break;
        case 25: goto L_80801618; break;
        case 26: goto L_80801618; break;
        case 27: goto L_80801930; break;
        case 28: goto L_80801930; break;
        case 29: goto L_80801618; break;
        case 30: goto L_80801618; break;
        case 31: goto L_80801930; break;
        default: switch_error(__func__, 0x808015F8, 0x808043B8);
    }
    // 0x808015FC: nop

L_80801600:
    // 0x80801600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801604: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80801608: jal         0x80801AA0
    // 0x8080160C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_4;
    // 0x8080160C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_4:
    // 0x80801610: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80801614: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
L_80801618:
    // 0x80801618: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x8080161C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801620: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80801624: srl         $t3, $a0, 5
    ctx->r11 = S32(U32(ctx->r4) >> 5);
    // 0x80801628: jal         0x800F79DC
    // 0x8080162C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_800F79DC(rdram, ctx);
        goto after_5;
    // 0x8080162C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_5:
    // 0x80801630: b           L_80801934
    // 0x80801634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x80801634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801638:
    // 0x80801638: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8080163C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80801640: jal         0x80803DD8
    // 0x80801644: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    func_80803DD8_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x80801644: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    after_6:
    // 0x80801648: beql        $v0, $zero, L_80801934
    if (ctx->r2 == 0) {
        // 0x8080164C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801934;
    }
    goto skip_1;
    // 0x8080164C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80801650: jal         0x8008A340
    // 0x80801654: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80801654: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_7:
    // 0x80801658: beq         $v0, $zero, L_80801930
    if (ctx->r2 == 0) {
        // 0x8080165C: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_80801930;
    }
    // 0x8080165C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80801660: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80801664: jal         0x8010114C
    // 0x80801668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_8;
    // 0x80801668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8080166C: b           L_80801934
    // 0x80801670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x80801670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801674:
    // 0x80801674: jal         0x80101080
    // 0x80801678: nop

    func_80101080(rdram, ctx);
        goto after_9;
    // 0x80801678: nop

    after_9:
    // 0x8080167C: jal         0x80106790
    // 0x80801680: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x80801680: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80801684: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80801688: addiu       $at, $zero, 0x86E
    ctx->r1 = ADD32(0, 0X86E);
    // 0x8080168C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801690: beq         $v1, $at, L_808016B8
    if (ctx->r3 == ctx->r1) {
        // 0x80801694: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808016B8;
    }
    // 0x80801694: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801698: addiu       $at, $zero, 0x86F
    ctx->r1 = ADD32(0, 0X86F);
    // 0x8080169C: beq         $v1, $at, L_808016D8
    if (ctx->r3 == ctx->r1) {
        // 0x808016A0: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_808016D8;
    }
    // 0x808016A0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x808016A4: addiu       $at, $zero, 0x870
    ctx->r1 = ADD32(0, 0X870);
    // 0x808016A8: beq         $v1, $at, L_808016F8
    if (ctx->r3 == ctx->r1) {
        // 0x808016AC: nop
    
            goto L_808016F8;
    }
    // 0x808016AC: nop

    // 0x808016B0: b           L_80801934
    // 0x808016B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808016B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016B8:
    // 0x808016B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808016BC: jal         0x800866D0
    // 0x808016C0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_11;
    // 0x808016C0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_11:
    // 0x808016C4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808016C8: jal         0x800866C0
    // 0x808016CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x808016CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808016D0: b           L_80801934
    // 0x808016D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808016D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016D8:
    // 0x808016D8: lbu         $t5, 0x65($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X65);
    // 0x808016DC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808016E0: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    // 0x808016E4: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x808016E8: jal         0x80086688
    // 0x808016EC: sb          $t6, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r14;
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x808016EC: sb          $t6, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r14;
    after_13:
    // 0x808016F0: b           L_80801934
    // 0x808016F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808016F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016F8:
    // 0x808016F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4438) << 16);
    // 0x808016FC: lwc1        $f0, 0x4438($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4438));
    // 0x80801700: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80801704: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801708: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080170C: jal         0x80086688
    // 0x80801710: nop

    _chexploder_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x80801710: nop

    after_14:
    // 0x80801714: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80801718: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080171C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801720: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801724: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801728: jal         0x80086698
    // 0x8080172C: nop

    _chexploder_entrypoint_8(rdram, ctx);
        goto after_15;
    // 0x8080172C: nop

    after_15:
    // 0x80801730: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801738: jal         0x800866A0
    // 0x8080173C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x8080173C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x80801740: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801744: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801748: jal         0x800866A0
    // 0x8080174C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_17;
    // 0x8080174C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80801750: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801754: jal         0x800866C0
    // 0x80801758: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_18;
    // 0x80801758: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_18:
    // 0x8080175C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80801760: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801764: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801768: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080176C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801770: jal         0x80086698
    // 0x80801774: nop

    _chexploder_entrypoint_8(rdram, ctx);
        goto after_19;
    // 0x80801774: nop

    after_19:
    // 0x80801778: b           L_80801934
    // 0x8080177C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x8080177C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801780:
    // 0x80801780: jal         0x80101080
    // 0x80801784: nop

    func_80101080(rdram, ctx);
        goto after_20;
    // 0x80801784: nop

    after_20:
    // 0x80801788: jal         0x80106790
    // 0x8080178C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_21;
    // 0x8080178C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x80801790: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80801794: addiu       $at, $zero, 0x86E
    ctx->r1 = ADD32(0, 0X86E);
    // 0x80801798: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8080179C: beq         $v1, $at, L_808017B8
    if (ctx->r3 == ctx->r1) {
        // 0x808017A0: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_808017B8;
    }
    // 0x808017A0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808017A4: addiu       $at, $zero, 0x870
    ctx->r1 = ADD32(0, 0X870);
    // 0x808017A8: beq         $v1, $at, L_80801814
    if (ctx->r3 == ctx->r1) {
        // 0x808017AC: lui         $t2, 0x8080
        ctx->r10 = S32(RELOC_HI16(1360, 0X48EC) << 16);
            goto L_80801814;
    }
    // 0x808017AC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1360, 0X48EC) << 16);
    // 0x808017B0: b           L_80801934
    // 0x808017B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801934;
    // 0x808017B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017B8:
    // 0x808017B8: addiu       $a3, $t0, 0x4
    ctx->r7 = ADD32(ctx->r8, 0X4);
    // 0x808017BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808017C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808017C4: jal         0x800F1DF4
    // 0x808017C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_22;
    // 0x808017C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_22:
    // 0x808017CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808017D0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808017D4: jal         0x800EE7F8
    // 0x808017D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x808017D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_23:
    // 0x808017DC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808017E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808017E4: jal         0x800EF1B8
    // 0x808017E8: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_24;
    // 0x808017E8: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    after_24:
    // 0x808017EC: jal         0x80101010
    // 0x808017F0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_80101010(rdram, ctx);
        goto after_25;
    // 0x808017F0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_25:
    // 0x808017F4: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x808017F8: lbu         $t7, 0x66($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X66);
    // 0x808017FC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801800: sb          $zero, 0x68($t8)
    MEM_B(0X68, ctx->r24) = 0;
    // 0x80801804: lbu         $t9, 0x66($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X66);
    // 0x80801808: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8080180C: b           L_80801930
    // 0x80801810: sb          $t1, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r9;
        goto L_80801930;
    // 0x80801810: sb          $t1, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r9;
L_80801814:
    // 0x80801814: addiu       $t2, $t2, 0x48EC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1360, 0X48EC));
    // 0x80801818: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8080181C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801820: addiu       $a3, $t0, 0x4
    ctx->r7 = ADD32(ctx->r8, 0X4);
    // 0x80801824: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80801828: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8080182C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801830: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801834: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80801838: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8080183C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80801840: jal         0x800F18FC
    // 0x80801844: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F18FC(rdram, ctx);
        goto after_26;
    // 0x80801844: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_26:
    // 0x80801848: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080184C: jal         0x800EE7F8
    // 0x80801850: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_27;
    // 0x80801850: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_27:
    // 0x80801854: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801858: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8080185C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80801860: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80801864: lui         $a3, 0xC3FA
    ctx->r7 = S32(0XC3FA << 16);
    // 0x80801868: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080186C: jal         0x800EF214
    // 0x80801870: nop

    func_800EF214(rdram, ctx);
        goto after_28;
    // 0x80801870: nop

    after_28:
    // 0x80801874: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801878: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080187C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801880: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80801884: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80801888: jal         0x80101010
    // 0x8080188C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_80101010(rdram, ctx);
        goto after_29;
    // 0x8080188C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_29:
    // 0x80801890: b           L_80801934
    // 0x80801894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x80801894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801898: b           L_80801934
    // 0x8080189C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801934;
    // 0x8080189C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808018A0:
    // 0x808018A0: jal         0x80801AA0
    // 0x808018A4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_30;
    // 0x808018A4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_30:
    // 0x808018A8: b           L_80801934
    // 0x808018AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808018AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018B0:
    // 0x808018B0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808018B4: jal         0x8008A038
    // 0x808018B8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x808018B8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_31:
    // 0x808018BC: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x808018C0: lbu         $t6, 0x61($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X61);
    // 0x808018C4: beql        $t6, $zero, L_80801934
    if (ctx->r14 == 0) {
        // 0x808018C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801934;
    }
    goto skip_2;
    // 0x808018C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808018CC: jal         0x800FDC28
    // 0x808018D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_32;
    // 0x808018D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_32:
    // 0x808018D4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x808018D8: b           L_80801930
    // 0x808018DC: sb          $zero, 0x61($t7)
    MEM_B(0X61, ctx->r15) = 0;
        goto L_80801930;
    // 0x808018DC: sb          $zero, 0x61($t7)
    MEM_B(0X61, ctx->r15) = 0;
L_808018E0:
    // 0x808018E0: jal         0x800D395C
    // 0x808018E4: nop

    func_800D395C(rdram, ctx);
        goto after_33;
    // 0x808018E4: nop

    after_33:
    // 0x808018E8: bne         $v0, $zero, L_808018F8
    if (ctx->r2 != 0) {
        // 0x808018EC: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_808018F8;
    }
    // 0x808018EC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808018F0: b           L_80801934
    // 0x808018F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801934;
    // 0x808018F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808018F8:
    // 0x808018F8: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808018FC: jal         0x80802214
    // 0x80801900: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_34;
    // 0x80801900: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_34:
    // 0x80801904: b           L_80801934
    // 0x80801908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x80801908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080190C:
    // 0x8080190C: jal         0x800FDC28
    // 0x80801910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_35;
    // 0x80801910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_35:
    // 0x80801914: jal         0x8080373C
    // 0x80801918: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_8080373C_chweldarboss(rdram, ctx);
        goto after_36;
    // 0x80801918: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_36:
    // 0x8080191C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80801920: jal         0x80801AA0
    // 0x80801924: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_37;
    // 0x80801924: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_37:
    // 0x80801928: jal         0x80803D64
    // 0x8080192C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_38;
    // 0x8080192C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_38:
L_80801930:
    // 0x80801930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801934:
    // 0x80801934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801938:
    // 0x80801938: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8080193C: jr          $ra
    // 0x80801940: nop

    return;
    // 0x80801940: nop

;}
RECOMP_FUNC void _sulights_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8C0: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8C0);
    return;
    // 0x8008A8C4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void baboost_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800310: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800318: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080031C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800320: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80800324: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800328: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080032C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80800330: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // 0x80800334: beql        $t7, $zero, L_80800388
    if (ctx->r15 == 0) {
        // 0x80800338: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800388;
    }
    goto skip_0;
    // 0x80800338: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080033C: lw          $t8, 0x24($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X24);
L_80800340:
    // 0x80800340: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x80800344: jal         0x800D9078
    // 0x80800348: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800348: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8080034C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800350: bnel        $s0, $s1, L_80800340
    if (ctx->r16 != ctx->r17) {
        // 0x80800354: lw          $t8, 0x24($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X24);
            goto L_80800340;
    }
    goto skip_1;
    // 0x80800354: lw          $t8, 0x24($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X24);
    skip_1:
    // 0x80800358: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x8080035C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800364: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800368: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8080036C: nop

    // 0x80800370: bc1tl       L_80800388
    if (c1cs) {
        // 0x80800374: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800388;
    }
    goto skip_2;
    // 0x80800374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800378: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080037C: jal         0x8080009C
    // 0x80800380: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    baboost_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800380: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    after_1:
    // 0x80800384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800388:
    // 0x80800388: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800390: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800394: jr          $ra
    // 0x80800398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80804404_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804404: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080440C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804410: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80804414: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80804418: bnel        $at, $zero, L_80804434
    if (ctx->r1 != 0) {
        // 0x8080441C: lbu         $t7, 0x65($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X65);
            goto L_80804434;
    }
    goto skip_0;
    // 0x8080441C: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    skip_0:
    // 0x80804420: jal         0x80800478
    // 0x80804424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804428: b           L_80804440
    // 0x8080442C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804440;
    // 0x8080442C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804430: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
L_80804434:
    // 0x80804434: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80804438: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x8080443C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804440:
    // 0x80804440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804444: jr          $ra
    // 0x80804448: nop

    return;
    // 0x80804448: nop

;}
RECOMP_FUNC void func_80800238_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080023C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800248: jal         0x8009E77C
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800250: bnel        $v0, $zero, L_80800314
    if (ctx->r2 != 0) {
        // 0x80800254: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800314;
    }
    goto skip_0;
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800258: jal         0x8009E4AC
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_1;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800268: jal         0x8009E55C
    // 0x8080026C: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    func_8009E55C(rdram, ctx);
        goto after_2;
    // 0x8080026C: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    after_2:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800278: jal         0x8009E53C
    // 0x8080027C: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_8009E53C(rdram, ctx);
        goto after_3;
    // 0x8080027C: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_3:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800288: jal         0x8009E55C
    // 0x8080028C: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_4;
    // 0x8080028C: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    after_4:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800298: jal         0x8009E53C
    // 0x8080029C: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    func_8009E53C(rdram, ctx);
        goto after_5;
    // 0x8080029C: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_5:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x800961AC
    // 0x808002A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_800961AC(rdram, ctx);
        goto after_6;
    // 0x808002A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x808002AC: jal         0x800974FC
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800974FC(rdram, ctx);
        goto after_7;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002B8: jal         0x8009C914
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808002C0: jal         0x8009C974
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_9;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002C8: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808002CC: jal         0x80800324
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_304_80800324(rdram, ctx);
        goto after_10;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002D4: jal         0x8008E0E8
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_11;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002DC: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002EC;
    }
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80084788
    // 0x808002E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x808002E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
L_808002EC:
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x800A4DFC
    // 0x808002F4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_800A4DFC(rdram, ctx);
        goto after_13;
    // 0x808002F4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_13:
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: jal         0x800A2018
    // 0x80800300: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A2018(rdram, ctx);
        goto after_14;
    // 0x80800300: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x80092880
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092880(rdram, ctx);
        goto after_15;
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800314:
    // 0x80800314: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void func_80800040_chzubba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x80089ED8
    // 0x8080004C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _sucoasterfly_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080004C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800058: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080005C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800060: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800064: beq         $at, $zero, L_80800088
    if (ctx->r1 == 0) {
        // 0x80800068: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800088;
    }
    // 0x80800068: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080006C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1344, 0XC0) << 16);
    // 0x80800070: addu        $at, $at, $t8
    gpr jr_addend_80800078 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800074: lw          $t8, 0xC0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1344, 0XC0));
    // 0x80800078: jr          $t8
    // 0x8080007C: nop

    switch (jr_addend_80800078 >> 2) {
        case 0: goto L_80800080; break;
        case 1: goto L_80800080; break;
        case 2: goto L_80800080; break;
        case 3: goto L_80800080; break;
        case 4: goto L_80800080; break;
        case 5: goto L_80800080; break;
        case 6: goto L_80800080; break;
        case 7: goto L_80800080; break;
        case 8: goto L_80800080; break;
        default: switch_error(__func__, 0x80800078, 0x808000C0);
    }
    // 0x8080007C: nop

L_80800080:
    // 0x80800080: b           L_8080008C
    // 0x80800084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8080008C;
    // 0x80800084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800088:
    // 0x80800088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8080008C:
    // 0x8080008C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1344, 0X1C0) << 16);
    // 0x80800090: addiu       $t9, $t9, 0x1C0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1344, 0X1C0));
    // 0x80800094: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800098: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080009C: jal         0x80089D58
    // 0x808000A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808000A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_1:
    // 0x808000A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

    // 0x808000B4: nop

    // 0x808000B8: nop

    // 0x808000BC: nop

;}
RECOMP_FUNC void func_8010573C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010573C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80105740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80105744: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80105748: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010574C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80105750: jal         0x80105494
    // 0x80105754: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105754: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80105758: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010575C: jal         0x800D7DE8
    // 0x80105760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D7DE8(rdram, ctx);
        goto after_1;
    // 0x80105760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80105764: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80105768: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8010576C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80105770: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80105774: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80105778: sll         $t6, $a0, 21
    ctx->r14 = S32(ctx->r4 << 21);
    // 0x8010577C: sra         $a0, $t6, 22
    ctx->r4 = S32(SIGNED(ctx->r14) >> 22);
    // 0x80105780: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x80105784: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80105788: jal         0x800D86F0
    // 0x8010578C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    func_800D86F0(rdram, ctx);
        goto after_2;
    // 0x8010578C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80105790: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80105794: sll         $t8, $a0, 21
    ctx->r24 = S32(ctx->r4 << 21);
    // 0x80105798: jal         0x800D7520
    // 0x8010579C: sra         $a0, $t8, 22
    ctx->r4 = S32(SIGNED(ctx->r24) >> 22);
    func_800D7520(rdram, ctx);
        goto after_3;
    // 0x8010579C: sra         $a0, $t8, 22
    ctx->r4 = S32(SIGNED(ctx->r24) >> 22);
    after_3:
    // 0x801057A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801057A4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x801057A8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x801057AC: jal         0x800C810C
    // 0x801057B0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800C810C(rdram, ctx);
        goto after_4;
    // 0x801057B0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x801057B4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x801057B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801057BC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801057C0: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x801057C4: beq         $t0, $zero, L_801057F8
    if (ctx->r8 == 0) {
        // 0x801057C8: andi        $t1, $v0, 0x200
        ctx->r9 = ctx->r2 & 0X200;
            goto L_801057F8;
    }
    // 0x801057C8: andi        $t1, $v0, 0x200
    ctx->r9 = ctx->r2 & 0X200;
    // 0x801057CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801057D0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801057D4: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801057D8: nop

    // 0x801057DC: bc1fl       L_801057F4
    if (!c1cs) {
        // 0x801057E0: add.s       $f16, $f10, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
            goto L_801057F4;
    }
    goto skip_0;
    // 0x801057E0: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    skip_0:
    // 0x801057E4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x801057E8: b           L_801057F8
    // 0x801057EC: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
        goto L_801057F8;
    // 0x801057EC: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    // 0x801057F0: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
L_801057F4:
    // 0x801057F4: swc1        $f16, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f16.u32l;
L_801057F8:
    // 0x801057F8: beq         $t1, $zero, L_80105810
    if (ctx->r9 == 0) {
        // 0x801057FC: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80105810;
    }
    // 0x801057FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80105800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80105804: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80105808: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8010580C: swc1        $f6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f6.u32l;
L_80105810:
    // 0x80105810: lwc1        $f8, 0x54($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80105814: lwc1        $f10, 0x50($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80105818: swc1        $f8, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f8.u32l;
    // 0x8010581C: swc1        $f10, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f10.u32l;
    // 0x80105820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80105824: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80105828: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010582C: jr          $ra
    // 0x80105830: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80105830: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808002D0_ch1pfreeze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002E4: jal         0x80100094
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808002F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808002F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002F8: beq         $t6, $at, L_80800320
    if (ctx->r14 == ctx->r1) {
        // 0x808002FC: addiu       $a0, $v1, 0x4
        ctx->r4 = ADD32(ctx->r3, 0X4);
            goto L_80800320;
    }
    // 0x808002FC: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x80800300: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800304: beq         $t6, $at, L_80800358
    if (ctx->r14 == ctx->r1) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800358;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800310: beq         $t6, $at, L_80800368
    if (ctx->r14 == ctx->r1) {
        // 0x80800314: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80800368;
    }
    // 0x80800314: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800318: b           L_80800398
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800398;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800320:
    // 0x80800320: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80800324: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80800328: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8080032C: jal         0x800EFA88
    // 0x80800330: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800EFA88(rdram, ctx);
        goto after_1;
    // 0x80800330: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800334: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800338: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080033C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800340: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800344: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80800348: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8080034C: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x80800350: b           L_80800394
    // 0x80800354: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
        goto L_80800394;
    // 0x80800354: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
L_80800358:
    // 0x80800358: jal         0x80103110
    // 0x8080035C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x8080035C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800360: b           L_80800398
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800398;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800368:
    // 0x80800368: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080036C: jal         0x80089B88
    // 0x80800370: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    _sufreezy_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800370: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800374: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800378: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080037C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800388: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8080038C: jal         0x80103110
    // 0x80800390: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x80800390: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    after_4:
L_80800394:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800398:
    // 0x80800398: jal         0x80101FDC
    // 0x8080039C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x8080039C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A170: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A170);
    return;
    // 0x8008A174: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_8080000C_chlagoonpirate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8008A0F8
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800028: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080002C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800030: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800034: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800038: jal         0x80102FDC
    // 0x8080003C: nop

    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x8080003C: nop

    after_1:
    // 0x80800040: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800044: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800048: jal         0x8010A3E8
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void chfactoryrobot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1140, 0X2970) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2970
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1140, 0X2970));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2970
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1140, 0X2970));
;}
RECOMP_FUNC void bsride_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080099C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(348, 0XA90) << 16);
    // 0x808009A0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009A4: jr          $ra
    // 0x808009A8: lw          $v0, 0xA90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA90));
    return;
    // 0x808009A8: lw          $v0, 0xA90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA90));
    // 0x808009AC: nop

;}
RECOMP_FUNC void _gcboundDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EE0: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EE0);
    return;
    // 0x80087EE4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800B2824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2824: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800B2828: bne         $v1, $zero, L_800B2838
    if (ctx->r3 != 0) {
        // 0x800B282C: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B2838;
    }
    // 0x800B282C: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B2830: jr          $ra
    // 0x800B2834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B2834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2838:
    // 0x800B2838: jr          $ra
    // 0x800B283C: nop

    return;
    // 0x800B283C: nop

;}
RECOMP_FUNC void func_80109F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109F70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80109F74: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80109F78: jal         0x8010114C
    // 0x80109F7C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80109F7C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80109F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109F88: jr          $ra
    // 0x80109F8C: nop

    return;
    // 0x80109F8C: nop

;}
RECOMP_FUNC void _idscroll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DC0: syscall     740
    recomp_syscall_handler(rdram, ctx, 0x80088DC0);
    return;
    // 0x80088DC4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800124_chquizexitdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: jr          $ra
    // 0x80800128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8080054C_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080054C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800550: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800554: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800558: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080055C: jal         0x8008CABC
    // 0x80800560: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800560: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800564: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80800568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080056C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80800570: beq         $at, $zero, L_8080077C
    if (ctx->r1 == 0) {
        // 0x80800574: sb          $v1, 0x15C($s0)
        MEM_B(0X15C, ctx->r16) = ctx->r3;
            goto L_8080077C;
    }
    // 0x80800574: sb          $v1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r3;
    // 0x80800578: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8080057C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X155C) << 16);
    // 0x80800580: addu        $at, $at, $t6
    gpr jr_addend_80800588 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800584: lw          $t6, 0x155C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(372, 0X155C));
    // 0x80800588: jr          $t6
    // 0x8080058C: nop

    switch (jr_addend_80800588 >> 2) {
        case 0: goto L_80800768; break;
        case 1: goto L_80800590; break;
        case 2: goto L_80800640; break;
        case 3: goto L_808006BC; break;
        case 4: goto L_808006D8; break;
        case 5: goto L_80800730; break;
        default: switch_error(__func__, 0x80800588, 0x8080155C);
    }
    // 0x8080058C: nop

L_80800590:
    // 0x80800590: jal         0x8008AF24
    // 0x80800594: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800594: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800598: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080059C: jal         0x8008AED4
    // 0x808005A0: addiu       $a1, $zero, 0x1EF
    ctx->r5 = ADD32(0, 0X1EF);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808005A0: addiu       $a1, $zero, 0x1EF
    ctx->r5 = ADD32(0, 0X1EF);
    after_2:
    // 0x808005A4: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x808005A8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808005AC: jal         0x8008B1BC
    // 0x808005B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x808005B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808005B4: lui         $a2, 0x3E91
    ctx->r6 = S32(0X3E91 << 16);
    // 0x808005B8: ori         $a2, $a2, 0xCB3
    ctx->r6 = ctx->r6 | 0XCB3;
    // 0x808005BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005C0: jal         0x8008B1D4
    // 0x808005C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808005C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808005C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808005CC: jal         0x8008B134
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808005D4: jal         0x8008B064
    // 0x808005D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x808005D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x808005DC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x808005E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808005F0: jal         0x8009FFD8
    // 0x808005F4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x808005F4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: jal         0x8009B9B0
    // 0x80800600: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800600: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800604: jal         0x8009EF04
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_9;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080060C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800610: nop

    // 0x80800614: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800618: nop

    // 0x8080061C: bc1tl       L_80800780
    if (c1cs) {
        // 0x80800620: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800780;
    }
    goto skip_0;
    // 0x80800620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800624: jal         0x8009EEB8
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_10;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080062C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800630: jal         0x8009C914
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800638: b           L_80800780
    // 0x8080063C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800780;
    // 0x8080063C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800640:
    // 0x80800640: lui         $a1, 0x3EEE
    ctx->r5 = S32(0X3EEE << 16);
    // 0x80800644: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800648: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080064C: ori         $a1, $a1, 0x6320
    ctx->r5 = ctx->r5 | 0X6320;
    // 0x80800650: jal         0x8008CF1C
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_12;
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800658: jal         0x8009C990
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800660: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800664: jal         0x8009B9C0
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080066C: jal         0x80800BEC
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BEC_bsstatue(rdram, ctx);
        goto after_15;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800674: jal         0x8009C990
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080067C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800680: jal         0x8009BB00
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800688: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x8009BA68
    // 0x80800694: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800694: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800698: lui         $a1, 0x4431
    ctx->r5 = S32(0X4431 << 16);
    // 0x8080069C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808006A0: jal         0x8009BA58
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x8009BCB4
    // 0x808006B0: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x808006B0: lui         $a1, 0xC516
    ctx->r5 = S32(0XC516 << 16);
    after_20:
    // 0x808006B4: b           L_80800780
    // 0x808006B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800780;
    // 0x808006B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006BC:
    // 0x808006BC: lui         $a1, 0x3F0B
    ctx->r5 = S32(0X3F0B << 16);
    // 0x808006C0: ori         $a1, $a1, 0xAC71
    ctx->r5 = ctx->r5 | 0XAC71;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: jal         0x8008CF1C
    // 0x808006CC: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_21;
    // 0x808006CC: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_21:
    // 0x808006D0: b           L_80800780
    // 0x808006D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800780;
    // 0x808006D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006D8:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808006E0: jal         0x8009E55C
    // 0x808006E4: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    func_8009E55C(rdram, ctx);
        goto after_22;
    // 0x808006E4: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    after_22:
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808006F0: jal         0x8009E53C
    // 0x808006F4: lui         $a2, 0xC334
    ctx->r6 = S32(0XC334 << 16);
    func_8009E53C(rdram, ctx);
        goto after_23;
    // 0x808006F4: lui         $a2, 0xC334
    ctx->r6 = S32(0XC334 << 16);
    after_23:
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800700: jal         0x8009E5A4
    // 0x80800704: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8009E5A4(rdram, ctx);
        goto after_24;
    // 0x80800704: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_24:
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: jal         0x80095760
    // 0x80800710: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    baflag_set(rdram, ctx);
        goto after_25;
    // 0x80800710: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_25:
    // 0x80800714: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800718: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: jal         0x8008CF1C
    // 0x80800724: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_26;
    // 0x80800724: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_26:
    // 0x80800728: b           L_80800780
    // 0x8080072C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800780;
    // 0x8080072C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800730:
    // 0x80800730: jal         0x800A2EAC
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_27;
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x80095774
    // 0x80800740: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    baflag_clear(rdram, ctx);
        goto after_28;
    // 0x80800740: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_28:
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080074C: jal         0x8009E55C
    // 0x80800750: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_29;
    // 0x80800750: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_29:
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x8009B9B0
    // 0x8080075C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_30;
    // 0x8080075C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_30:
    // 0x80800760: b           L_80800780
    // 0x80800764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800780;
    // 0x80800764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800768:
    // 0x80800768: jal         0x8009BC6C
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_31;
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: jal         0x80095774
    // 0x80800778: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    baflag_clear(rdram, ctx);
        goto after_32;
    // 0x80800778: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_32:
L_8080077C:
    // 0x8080077C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800780:
    // 0x80800780: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800784: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800788: jr          $ra
    // 0x8080078C: nop

    return;
    // 0x8080078C: nop

;}
RECOMP_FUNC void _chkingjinjobits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086798: syscall     372
    recomp_syscall_handler(rdram, ctx, 0x80086798);
    return;
    // 0x8008679C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008C038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C03C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C044: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x8008C048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C04C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C050: bne         $t6, $at, L_8008C068
    if (ctx->r14 != ctx->r1) {
        // 0x8008C054: nop
    
            goto L_8008C068;
    }
    // 0x8008C054: nop

    // 0x8008C058: jal         0x8008BEB4
    // 0x8008C05C: nop

    func_8008BEB4(rdram, ctx);
        goto after_0;
    // 0x8008C05C: nop

    after_0:
    // 0x8008C060: b           L_8008C074
    // 0x8008C064: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
        goto L_8008C074;
    // 0x8008C064: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_8008C068:
    // 0x8008C068: jal         0x8008BD94
    // 0x8008C06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD94(rdram, ctx);
        goto after_1;
    // 0x8008C06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008C070: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_8008C074:
    // 0x8008C074: beql        $t7, $zero, L_8008C09C
    if (ctx->r15 == 0) {
        // 0x8008C078: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C09C;
    }
    goto skip_0;
    // 0x8008C078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008C07C: jal         0x8008BD1C
    // 0x8008C080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008BD1C(rdram, ctx);
        goto after_2;
    // 0x8008C080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008C084: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8008C088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008C08C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8008C090: jalr        $t9
    // 0x8008C094: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8008C094: nop

    after_3:
    // 0x8008C098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C09C:
    // 0x8008C09C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C0A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C0A4: jr          $ra
    // 0x8008C0A8: nop

    return;
    // 0x8008C0A8: nop

;}
RECOMP_FUNC void _glid_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088678: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088678);
    return;
    // 0x8008867C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bafly_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C28: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C28);
    return;
    // 0x80084C2C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800C28_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800C2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C34: jal         0x8008CABC
    // 0x80800C38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800C38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800C3C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800C40: jal         0x800EA068
    // 0x80800C44: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80800C44: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_1:
    // 0x80800C48: beq         $v0, $zero, L_80800C60
    if (ctx->r2 == 0) {
        // 0x80800C4C: sw          $v0, 0x160($s0)
        MEM_W(0X160, ctx->r16) = ctx->r2;
            goto L_80800C60;
    }
    // 0x80800C4C: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800C50: jal         0x800FC660
    // 0x80800C54: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x80800C54: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_2:
    // 0x80800C58: b           L_80800CA0
    // 0x80800C5C: nop

        goto L_80800CA0;
    // 0x80800C5C: nop

L_80800C60:
    // 0x80800C60: jal         0x80085208
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800C68: jal         0x8008E944
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_4;
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800C70: jal         0x8009514C
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_5;
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C7C: jal         0x800A4DA4
    // 0x80800C80: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DA4(rdram, ctx);
        goto after_6;
    // 0x80800C80: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x80800C84: jal         0x800A4CA8
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_7;
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C90: jal         0x80089288
    // 0x80800C94: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800C94: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_8:
    // 0x80800C98: jal         0x800A0180
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_9;
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800CA0:
    // 0x80800CA0: jal         0x80082838
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800CA8: jal         0x8008AF24
    // 0x80800CAC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    anctrl_reset(rdram, ctx);
        goto after_11;
    // 0x80800CAC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x80800CB0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800CB4: jal         0x8008B1A0
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_12;
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800CBC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800CC0: jal         0x8008AED4
    // 0x80800CC4: addiu       $a1, $zero, 0x1E1
    ctx->r5 = ADD32(0, 0X1E1);
    anctrl_setIndex(rdram, ctx);
        goto after_13;
    // 0x80800CC4: addiu       $a1, $zero, 0x1E1
    ctx->r5 = ADD32(0, 0X1E1);
    after_13:
    // 0x80800CC8: lui         $a2, 0x3ECB
    ctx->r6 = S32(0X3ECB << 16);
    // 0x80800CCC: ori         $a2, $a2, 0xF28
    ctx->r6 = ctx->r6 | 0XF28;
    // 0x80800CD0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800CD4: jal         0x8008B1D4
    // 0x80800CD8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_14;
    // 0x80800CD8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_14:
    // 0x80800CDC: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x80800CE0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800CE4: jal         0x8008B1BC
    // 0x80800CE8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    anctrl_setDuration(rdram, ctx);
        goto after_15;
    // 0x80800CE8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_15:
    // 0x80800CEC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800CF0: jal         0x8008B134
    // 0x80800CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_16;
    // 0x80800CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800CF8: jal         0x8008B064
    // 0x80800CFC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    anctrl_start(rdram, ctx);
        goto after_17;
    // 0x80800CFC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_17:
    // 0x80800D00: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800D04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800D14: jal         0x8009FFD8
    // 0x80800D18: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_18;
    // 0x80800D18: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_18:
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D20: jal         0x8009C128
    // 0x80800D24: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_19;
    // 0x80800D24: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_19:
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: jal         0x800A32C4
    // 0x80800D30: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800A32C4(rdram, ctx);
        goto after_20;
    // 0x80800D30: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_20:
    // 0x80800D34: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800D38: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800D3C: jal         0x800F1E6C
    // 0x80800D40: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800F1E6C(rdram, ctx);
        goto after_21;
    // 0x80800D40: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_21:
    // 0x80800D44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800D48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D4C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800D50: jal         0x800136E4
    // 0x80800D54: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_22;
    // 0x80800D54: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_22:
    // 0x80800D58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D5C: jal         0x8009C914
    // 0x80800D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_23;
    // 0x80800D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800D64: jal         0x8009C974
    // 0x80800D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_24;
    // 0x80800D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800D6C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800D70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D7C: jal         0x8009B9B0
    // 0x80800D80: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_25;
    // 0x80800D80: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    after_25:
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D88: jal         0x8009B9C0
    // 0x80800D8C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_26;
    // 0x80800D8C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_26:
    // 0x80800D90: jal         0x8009BB00
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_27;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800D98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA0: jal         0x8009BA68
    // 0x80800DA4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_28;
    // 0x80800DA4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_28:
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: jal         0x8009BA58
    // 0x80800DB0: lui         $a1, 0x43D2
    ctx->r5 = S32(0X43D2 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_29;
    // 0x80800DB0: lui         $a1, 0x43D2
    ctx->r5 = S32(0X43D2 << 16);
    after_29:
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB8: jal         0x8009BCB4
    // 0x80800DBC: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_30;
    // 0x80800DBC: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_30:
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800DC8: jal         0x8009BFE4
    // 0x80800DCC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_31;
    // 0x80800DCC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_31:
    // 0x80800DD0: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x80800DD4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800DD8: jal         0x8009D820
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D820(rdram, ctx);
        goto after_32;
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800DE0: lui         $a2, 0x4039
    ctx->r6 = S32(0X4039 << 16);
    // 0x80800DE4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DEC: jal         0x80085338
    // 0x80800DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_33;
    // 0x80800DF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80800DF4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800DF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800DFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800E04: jr          $ra
    // 0x80800E08: nop

    return;
    // 0x80800E08: nop

;}
RECOMP_FUNC void func_80801FFC_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802000: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80802004: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080200C: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    // 0x80802010: jal         0x80088280
    // 0x80802014: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80802014: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80802018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080201C: jal         0x80088C00
    // 0x80802020: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80802020: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80802024: addiu       $a0, $zero, 0x51E
    ctx->r4 = ADD32(0, 0X51E);
    // 0x80802028: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080202C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802030: jal         0x80108528
    // 0x80802034: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80802034: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80802038: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8080203C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80802040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802044: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x80802048: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8080204C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80802050: jal         0x80100120
    // 0x80802054: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    func_80100120(rdram, ctx);
        goto after_3;
    // 0x80802054: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    after_3:
    // 0x80802058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080205C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802060: jr          $ra
    // 0x80802064: nop

    return;
    // 0x80802064: nop

;}
RECOMP_FUNC void func_80800488_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080048C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800490: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800494: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800498: jal         0x8008D04C
    // 0x8080049C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x8080049C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808004A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004A4: jal         0x8008AF24
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x8008B1A0
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x8008AED4
    // 0x808004C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808004C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x8008B1BC
    // 0x808004CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808004CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x8008B134
    // 0x808004D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808004D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808004DC: jal         0x8008B064
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void _vpglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089058: syscall     758
    recomp_syscall_handler(rdram, ctx, 0x80089058);
    return;
    // 0x8008905C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chdodgemcontrol_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CF0: syscall     445
    recomp_syscall_handler(rdram, ctx, 0x80086CF0);
    return;
    // 0x80086CF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glsavegame_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088550: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088550);
    return;
    // 0x80088554: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void chintroticker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1648, 0X934) << 16);
    // 0x808006E8: jr          $ra
    // 0x808006EC: addiu       $v0, $v0, 0x934
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1648, 0X934));
    return;
    // 0x808006EC: addiu       $v0, $v0, 0x934
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1648, 0X934));
;}
RECOMP_FUNC void chnests_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FD4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(752, 0X1118) << 16);
    // 0x80800FD8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80800FDC: addiu       $a1, $a1, 0x1118
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(752, 0X1118));
    // 0x80800FE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800FE4:
    // 0x80800FE4: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80800FE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800FEC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800FF0: bne         $a0, $t6, L_80801000
    if (ctx->r4 != ctx->r14) {
        // 0x80800FF4: nop
    
            goto L_80801000;
    }
    // 0x80800FF4: nop

    // 0x80800FF8: jr          $ra
    // 0x80800FFC: lbu         $v0, 0xB($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB);
    return;
    // 0x80800FFC: lbu         $v0, 0xB($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XB);
L_80801000:
    // 0x80801000: bne         $at, $zero, L_80800FE4
    if (ctx->r1 != 0) {
        // 0x80801004: addiu       $a1, $a1, 0xE
        ctx->r5 = ADD32(ctx->r5, 0XE);
            goto L_80800FE4;
    }
    // 0x80801004: addiu       $a1, $a1, 0xE
    ctx->r5 = ADD32(ctx->r5, 0XE);
    // 0x80801008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080100C: jr          $ra
    // 0x80801010: nop

    return;
    // 0x80801010: nop

;}
RECOMP_FUNC void func_800E24C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E24C4: jr          $ra
    // 0x800E24C8: sb          $a0, -0x2B6E($at)
    MEM_B(-0X2B6E, ctx->r1) = ctx->r4;
    return;
    // 0x800E24C8: sb          $a0, -0x2B6E($at)
    MEM_B(-0X2B6E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8080000C_chspiralgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8010A800
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x80109EEC
    // 0x80800028: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80808DB0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808DB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808DB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808DBC: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80808DC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808DC4: jal         0x80802444
    // 0x80808DC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80802444_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808DC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80808DCC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80808DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808DD4: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80808DD8: beql        $v0, $t6, L_80808E68
    if (ctx->r2 == ctx->r14) {
        // 0x80808DDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80808E68;
    }
    goto skip_0;
    // 0x80808DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80808DE0: jal         0x80802444
    // 0x80808DE4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    func_80802444_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808DE4: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    after_1:
    // 0x80808DE8: beq         $v0, $zero, L_80808E04
    if (ctx->r2 == 0) {
        // 0x80808DEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808E04;
    }
    // 0x80808DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808DF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80808DF4: beq         $v0, $at, L_80808E38
    if (ctx->r2 == ctx->r1) {
        // 0x80808DF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808E38;
    }
    // 0x80808DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808DFC: b           L_80808E68
    // 0x80808E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80808E68;
    // 0x80808E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808E04:
    // 0x80808E04: jal         0x808061AC
    // 0x80808E08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808E08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80808E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808E10: jal         0x80809DA0
    // 0x80808E14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80809DA0_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808E14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80808E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808E1C: jal         0x8080483C
    // 0x80808E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080483C_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80808E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80808E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808E28: jal         0x808099A8
    // 0x80808E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808099A8_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80808E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80808E30: b           L_80808E68
    // 0x80808E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80808E68;
    // 0x80808E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808E38:
    // 0x80808E38: jal         0x808061AC
    // 0x80808E3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80808E3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80808E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808E44: jal         0x80809DA0
    // 0x80808E48: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80809DA0_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80808E48: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_7:
    // 0x80808E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808E50: jal         0x8080483C
    // 0x80808E54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080483C_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80808E54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80808E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808E5C: jal         0x808099A8
    // 0x80808E60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808099A8_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80808E60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80808E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808E68:
    // 0x80808E68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808E6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80808E70: jr          $ra
    // 0x80808E74: nop

    return;
    // 0x80808E74: nop

;}
RECOMP_FUNC void func_8080450C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080450C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80804510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804518: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080451C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80804520: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80804524: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080452C: beq         $v0, $zero, L_80804544
    if (ctx->r2 == 0) {
        // 0x80804530: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80804544;
    }
    // 0x80804530: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80804534: beql        $v0, $at, L_808045A0
    if (ctx->r2 == ctx->r1) {
        // 0x80804538: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_808045A0;
    }
    goto skip_0;
    // 0x80804538: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8080453C: b           L_808045D4
    // 0x80804540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808045D4;
    // 0x80804540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804544:
    // 0x80804544: jal         0x808036F8
    // 0x80804548: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_808036F8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804548: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080454C: beq         $v0, $zero, L_80804588
    if (ctx->r2 == 0) {
        // 0x80804550: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80804588;
    }
    // 0x80804550: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80804554: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80804558: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8080455C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80804560: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80804564: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80804568: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080456C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804570: jal         0x80801658
    // 0x80804574: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    func_80801658_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804574: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    after_1:
    // 0x80804578: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080457C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80804580: b           L_808045D0
    // 0x80804584: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_808045D0;
    // 0x80804584: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80804588:
    // 0x80804588: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8080458C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80804590: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80804594: b           L_808045D0
    // 0x80804598: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
        goto L_808045D0;
    // 0x80804598: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8080459C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_808045A0:
    // 0x808045A0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x808045A4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x808045A8: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x808045AC: bltzl       $t6, L_808045D4
    if (SIGNED(ctx->r14) < 0) {
        // 0x808045B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808045D4;
    }
    goto skip_1;
    // 0x808045B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808045B4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x808045B8: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x808045BC: jal         0x80803658
    // 0x808045C0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_80803658_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808045C0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_2:
    // 0x808045C4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808045C8: jal         0x80801714
    // 0x808045CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801714_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808045CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808045D0:
    // 0x808045D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808045D4:
    // 0x808045D4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808045D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808045DC: jr          $ra
    // 0x808045E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808045E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080000C_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080001C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800028: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080002C: jal         0x80102FDC
    // 0x80800030: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800030: nop

    after_0:
    // 0x80800034: jal         0x80089D00
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080003C: jal         0x8010A63C
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A63C(rdram, ctx);
        goto after_2;
    // 0x80800040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void chtrashcompactor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1128, 0X8D0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x8D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X8D0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x8D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X8D0));
;}
RECOMP_FUNC void baeggcursor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800120: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800124: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80800128: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x8080012C: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80800130: jr          $ra
    // 0x80800134: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x80800134: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void chfactorylight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800478: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080047C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800484: jal         0x80106790
    // 0x80800488: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800488: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080048C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800490: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800494: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800498: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8080049C: addu        $v1, $t7, $a2
    ctx->r3 = ADD32(ctx->r15, ctx->r6);
    // 0x808004A0: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x808004A4: beql        $at, $zero, L_80800570
    if (ctx->r1 == 0) {
        // 0x808004A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800570;
    }
    goto skip_0;
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808004AC:
    // 0x808004AC: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x808004B0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x808004B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808004BC: bgez        $t8, L_808004D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004C0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808004D0;
    }
    // 0x808004C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004C8: nop

    // 0x808004CC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808004D0:
    // 0x808004D0: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x808004D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808004D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808004DC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808004E0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808004E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808004E8: nop

    // 0x808004EC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808004F0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x808004F4: nop

    // 0x808004F8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x808004FC: beql        $t0, $zero, L_8080054C
    if (ctx->r8 == 0) {
        // 0x80800500: mfc1        $t0, $f18
        ctx->r8 = (int32_t)ctx->f18.u32l;
            goto L_8080054C;
    }
    goto skip_1;
    // 0x80800500: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80800504: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800508: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080050C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800510: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800514: nop

    // 0x80800518: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8080051C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800520: nop

    // 0x80800524: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800528: bne         $t0, $zero, L_80800540
    if (ctx->r8 != 0) {
        // 0x8080052C: nop
    
            goto L_80800540;
    }
    // 0x8080052C: nop

    // 0x80800530: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800534: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800538: b           L_80800558
    // 0x8080053C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80800558;
    // 0x8080053C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80800540:
    // 0x80800540: b           L_80800558
    // 0x80800544: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80800558;
    // 0x80800544: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80800548: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
L_8080054C:
    // 0x8080054C: nop

    // 0x80800550: bltz        $t0, L_80800540
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800554: nop
    
            goto L_80800540;
    }
    // 0x80800554: nop

L_80800558:
    // 0x80800558: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8080055C: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80800560: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800564: bne         $at, $zero, L_808004AC
    if (ctx->r1 != 0) {
        // 0x80800568: sb          $t0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r8;
            goto L_808004AC;
    }
    // 0x80800568: sb          $t0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r8;
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800570:
    // 0x80800570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void func_808053BC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808053BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808053C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808053C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808053C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808053CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808053D0: jal         0x80100094
    // 0x808053D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808053D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808053D8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808053DC: jal         0x80089D48
    // 0x808053E0: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808053E0: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    after_1:
    // 0x808053E4: sb          $v0, 0x24($s2)
    MEM_B(0X24, ctx->r18) = ctx->r2;
    // 0x808053E8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808053EC: addiu       $s2, $zero, 0x70
    ctx->r18 = ADD32(0, 0X70);
    // 0x808053F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808053F4:
    // 0x808053F4: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x808053F8: beql        $a0, $zero, L_80805410
    if (ctx->r4 == 0) {
        // 0x808053FC: lbu         $a0, 0x48($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X48);
            goto L_80805410;
    }
    goto skip_0;
    // 0x808053FC: lbu         $a0, 0x48($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X48);
    skip_0:
    // 0x80805400: jal         0x800C8B84
    // 0x80805404: nop

    func_800C8B84(rdram, ctx);
        goto after_2;
    // 0x80805404: nop

    after_2:
    // 0x80805408: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8080540C: lbu         $a0, 0x48($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X48);
L_80805410:
    // 0x80805410: beql        $a0, $zero, L_80805428
    if (ctx->r4 == 0) {
        // 0x80805414: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_80805428;
    }
    goto skip_1;
    // 0x80805414: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    skip_1:
    // 0x80805418: jal         0x800E87E0
    // 0x8080541C: nop

    func_800E87E0(rdram, ctx);
        goto after_3;
    // 0x8080541C: nop

    after_3:
    // 0x80805420: sb          $zero, 0x48($s0)
    MEM_B(0X48, ctx->r16) = 0;
    // 0x80805424: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_80805428:
    // 0x80805428: bne         $s1, $s2, L_808053F4
    if (ctx->r17 != ctx->r18) {
        // 0x8080542C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_808053F4;
    }
    // 0x8080542C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80805430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80805434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805438: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080543C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80805440: jr          $ra
    // 0x80805444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80805444: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _ncbadive_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892A0: syscall     770
    recomp_syscall_handler(rdram, ctx, 0x800892A0);
    return;
    // 0x800892A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void capod_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: jal         0x8008FFE8
    // 0x80800178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080017C: jal         0x80110024
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80800180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800184: beq         $v0, $zero, L_80800194
    if (ctx->r2 == 0) {
        // 0x80800188: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800194;
    }
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080018C: jal         0x80089558
    // 0x80800190: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x80800190: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80800194:
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void _chstarspinnerctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E18: syscall     245
    recomp_syscall_handler(rdram, ctx, 0x80085E18);
    return;
    // 0x80085E1C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800E2434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2434: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2438: jr          $ra
    // 0x800E243C: sb          $a0, -0x2B70($at)
    MEM_B(-0X2B70, ctx->r1) = ctx->r4;
    return;
    // 0x800E243C: sb          $a0, -0x2B70($at)
    MEM_B(-0X2B70, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _chdinoswitches_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FA0: syscall     267
    recomp_syscall_handler(rdram, ctx, 0x80085FA0);
    return;
    // 0x80085FA4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chnastycavemen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(760, 0X10E8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x10E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(760, 0X10E8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x10E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(760, 0X10E8));
;}
RECOMP_FUNC void func_800A9828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A982C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9834: beq         $a1, $zero, L_800A9848
    if (ctx->r5 == 0) {
        // 0x800A9838: sw          $a0, 0x7754($at)
        MEM_W(0X7754, ctx->r1) = ctx->r4;
            goto L_800A9848;
    }
    // 0x800A9838: sw          $a0, 0x7754($at)
    MEM_W(0X7754, ctx->r1) = ctx->r4;
    // 0x800A983C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9840: b           L_800A9854
    // 0x800A9844: sh          $a1, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r5;
        goto L_800A9854;
    // 0x800A9844: sh          $a1, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r5;
L_800A9848:
    // 0x800A9848: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x800A984C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9850: sh          $t6, 0x7750($at)
    MEM_H(0X7750, ctx->r1) = ctx->r14;
L_800A9854:
    // 0x800A9854: beq         $a2, $zero, L_800A9868
    if (ctx->r6 == 0) {
        // 0x800A9858: addiu       $t7, $zero, 0xE4
        ctx->r15 = ADD32(0, 0XE4);
            goto L_800A9868;
    }
    // 0x800A9858: addiu       $t7, $zero, 0xE4
    ctx->r15 = ADD32(0, 0XE4);
    // 0x800A985C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9860: b           L_800A9870
    // 0x800A9864: sh          $a2, 0x7752($at)
    MEM_H(0X7752, ctx->r1) = ctx->r6;
        goto L_800A9870;
    // 0x800A9864: sh          $a2, 0x7752($at)
    MEM_H(0X7752, ctx->r1) = ctx->r6;
L_800A9868:
    // 0x800A9868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A986C: sh          $t7, 0x7752($at)
    MEM_H(0X7752, ctx->r1) = ctx->r15;
L_800A9870:
    // 0x800A9870: jal         0x800E7F60
    // 0x800A9874: nop

    func_800E7F60(rdram, ctx);
        goto after_0;
    // 0x800A9874: nop

    after_0:
    // 0x800A9878: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A987C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9880: lh          $a1, 0x7752($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7752);
    // 0x800A9884: jal         0x800A8D00
    // 0x800A9888: lh          $a0, 0x7750($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7750);
    func_800A8D00(rdram, ctx);
        goto after_1;
    // 0x800A9888: lh          $a0, 0x7750($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7750);
    after_1:
    // 0x800A988C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9894: jr          $ra
    // 0x800A9898: nop

    return;
    // 0x800A9898: nop

;}
