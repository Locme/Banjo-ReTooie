#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A33F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A33F8: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A33FC: jr          $ra
    // 0x800A3400: lbu         $v0, 0x28($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X28);
    return;
    // 0x800A3400: lbu         $v0, 0x28($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X28);
;}
RECOMP_FUNC void chflamer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800608: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080060C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800610: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800614: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800618: bltzl       $t8, L_80800698
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080061C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800698;
    }
    goto skip_0;
    // 0x8080061C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800620: lbu         $v0, 0x74($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X74);
    // 0x80800624: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80800628: bnel        $t9, $zero, L_80800698
    if (ctx->r25 != 0) {
        // 0x8080062C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800698;
    }
    goto skip_1;
    // 0x8080062C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800630: beql        $a1, $zero, L_80800664
    if (ctx->r5 == 0) {
        // 0x80800634: ori         $t4, $v0, 0x1
        ctx->r12 = ctx->r2 | 0X1;
            goto L_80800664;
    }
    goto skip_2;
    // 0x80800634: ori         $t4, $v0, 0x1
    ctx->r12 = ctx->r2 | 0X1;
    skip_2:
    // 0x80800638: lhu         $t1, 0x18($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X18);
    // 0x8080063C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800640: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x80800644: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800648: beq         $t2, $zero, L_80800660
    if (ctx->r10 == 0) {
        // 0x8080064C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800660;
    }
    // 0x8080064C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800650: jal         0x8010114C
    // 0x80800654: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80800654: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800658: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080065C: lbu         $v0, 0x74($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X74);
L_80800660:
    // 0x80800660: ori         $t4, $v0, 0x1
    ctx->r12 = ctx->r2 | 0X1;
L_80800664:
    // 0x80800664: sb          $t4, 0x74($a3)
    MEM_B(0X74, ctx->r7) = ctx->r12;
    // 0x80800668: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8080066C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800670: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800674: jal         0x8010108C
    // 0x80800678: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x80800678: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8080067C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800680: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800684: addiu       $a0, $a0, 0x60D8
    ctx->r4 = ADD32(ctx->r4, 0X60D8);
    // 0x80800688: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080068C: jal         0x80086D38
    // 0x80800690: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    _chbaddiesetup_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800690: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    after_2:
    // 0x80800694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800698:
    // 0x80800698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080069C: jr          $ra
    // 0x808006A0: nop

    return;
    // 0x808006A0: nop

;}
RECOMP_FUNC void func_8080005C_chmrsboggyhome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080006C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80800070: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800074: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800078: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8080007C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800080: jal         0x80089F20
    // 0x80800084: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800084: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_0:
    // 0x80800088: jal         0x80089828
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800094: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800098: jal         0x800897D8
    // 0x8080009C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x8080009C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808000A0: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808000A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000A8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808000AC: bnel        $t8, $at, L_808000C0
    if (ctx->r24 != ctx->r1) {
        // 0x808000B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000B4: jal         0x80800174
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800174_chmrsboggyhome(rdram, ctx);
        goto after_3;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000C0:
    // 0x808000C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_808005EC_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005F0: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808005F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005F8: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x808005FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800600: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800604: beq         $at, $zero, L_808008C4
    if (ctx->r1 == 0) {
        // 0x80800608: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_808008C4;
    }
    // 0x80800608: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080060C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2420, 0X1304) << 16);
    // 0x80800614: addu        $at, $at, $t7
    gpr jr_addend_8080061C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800618: lw          $t7, 0x1304($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2420, 0X1304));
    // 0x8080061C: jr          $t7
    // 0x80800620: nop

    switch (jr_addend_8080061C >> 2) {
        case 0: goto L_80800624; break;
        case 1: goto L_80800634; break;
        case 2: goto L_808006D8; break;
        case 3: goto L_80800724; break;
        case 4: goto L_808007C4; break;
        case 5: goto L_808007E8; break;
        case 6: goto L_80800820; break;
        case 7: goto L_808008C4; break;
        case 8: goto L_808008BC; break;
        default: switch_error(__func__, 0x8080061C, 0x80801304);
    }
    // 0x80800620: nop

L_80800624:
    // 0x80800624: jal         0x80801228
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801228_chdinofamilymother(rdram, ctx);
        goto after_0;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080062C: b           L_808008C8
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800634:
    // 0x80800634: addiu       $a0, $zero, 0x52D
    ctx->r4 = ADD32(0, 0X52D);
    // 0x80800638: jal         0x80089C30
    // 0x8080063C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080063C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800640: bne         $v0, $zero, L_80800654
    if (ctx->r2 != 0) {
        // 0x80800644: addiu       $a0, $zero, 0x291
        ctx->r4 = ADD32(0, 0X291);
            goto L_80800654;
    }
    // 0x80800644: addiu       $a0, $zero, 0x291
    ctx->r4 = ADD32(0, 0X291);
    // 0x80800648: jal         0x80089C30
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800650: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x80800654: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
L_80800654:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080065C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800660: jal         0x80801118
    // 0x80800664: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80801118_chdinofamilymother(rdram, ctx);
        goto after_3;
    // 0x80800664: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_3:
    // 0x80800668: jal         0x800F54E4
    // 0x8080066C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080066C: nop

    after_4:
    // 0x80800670: jal         0x800F5410
    // 0x80800674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_5;
    // 0x80800674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800678: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080067C: bne         $v0, $at, L_808006A8
    if (ctx->r2 != ctx->r1) {
        // 0x80800680: addiu       $a1, $zero, 0x17BC
        ctx->r5 = ADD32(0, 0X17BC);
            goto L_808006A8;
    }
    // 0x80800680: addiu       $a1, $zero, 0x17BC
    ctx->r5 = ADD32(0, 0X17BC);
    // 0x80800684: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800688: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x8080068C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800690: addiu       $a1, $zero, 0x1815
    ctx->r5 = ADD32(0, 0X1815);
    // 0x80800694: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800698: jal         0x8008A208
    // 0x8080069C: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080069C: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_6:
    // 0x808006A0: b           L_808006C4
    // 0x808006A4: addiu       $a0, $zero, 0x291
    ctx->r4 = ADD32(0, 0X291);
        goto L_808006C4;
    // 0x808006A4: addiu       $a0, $zero, 0x291
    ctx->r4 = ADD32(0, 0X291);
L_808006A8:
    // 0x808006A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006AC: addiu       $t9, $zero, 0x65
    ctx->r25 = ADD32(0, 0X65);
    // 0x808006B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808006B4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808006B8: jal         0x8008A208
    // 0x808006BC: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808006BC: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x808006C0: addiu       $a0, $zero, 0x291
    ctx->r4 = ADD32(0, 0X291);
L_808006C4:
    // 0x808006C4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x808006C8: jal         0x80101180
    // 0x808006CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_8;
    // 0x808006CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808006D0: b           L_808008C8
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006D8:
    // 0x808006D8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808006DC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808006E0: jal         0x800DA298
    // 0x808006E4: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808006E4: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_9:
    // 0x808006E8: bne         $v0, $zero, L_80800724
    if (ctx->r2 != 0) {
        // 0x808006EC: addiu       $a1, $zero, 0x17BD
        ctx->r5 = ADD32(0, 0X17BD);
            goto L_80800724;
    }
    // 0x808006EC: addiu       $a1, $zero, 0x17BD
    ctx->r5 = ADD32(0, 0X17BD);
    // 0x808006F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006F4: addiu       $t1, $zero, 0x65
    ctx->r9 = ADD32(0, 0X65);
    // 0x808006F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808006FC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800700: jal         0x8008A208
    // 0x80800704: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800704: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_10:
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800710: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800714: jal         0x80801118
    // 0x80800718: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80801118_chdinofamilymother(rdram, ctx);
        goto after_11;
    // 0x80800718: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_11:
    // 0x8080071C: b           L_808008C8
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800724:
    // 0x80800724: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80800728: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8080072C: jal         0x800DA298
    // 0x80800730: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x80800730: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_12:
    // 0x80800734: bnel        $v0, $zero, L_808007C8
    if (ctx->r2 != 0) {
        // 0x80800738: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x80800738: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8080073C: jal         0x800F54E4
    // 0x80800740: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800740: nop

    after_13:
    // 0x80800744: jal         0x800F5410
    // 0x80800748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_14;
    // 0x80800748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8080074C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800750: beq         $v0, $at, L_80800778
    if (ctx->r2 == ctx->r1) {
        // 0x80800754: addiu       $a2, $zero, 0xC
        ctx->r6 = ADD32(0, 0XC);
            goto L_80800778;
    }
    // 0x80800754: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800758: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080075C: beq         $v0, $at, L_80800784
    if (ctx->r2 == ctx->r1) {
        // 0x80800760: addiu       $t4, $zero, 0x1816
        ctx->r12 = ADD32(0, 0X1816);
            goto L_80800784;
    }
    // 0x80800760: addiu       $t4, $zero, 0x1816
    ctx->r12 = ADD32(0, 0X1816);
    // 0x80800764: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800768: beq         $v0, $at, L_8080078C
    if (ctx->r2 == ctx->r1) {
        // 0x8080076C: addiu       $t5, $zero, 0x1817
        ctx->r13 = ADD32(0, 0X1817);
            goto L_8080078C;
    }
    // 0x8080076C: addiu       $t5, $zero, 0x1817
    ctx->r13 = ADD32(0, 0X1817);
    // 0x80800770: b           L_80800794
    // 0x80800774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_80800794;
    // 0x80800774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800778:
    // 0x80800778: addiu       $t3, $zero, 0x17BE
    ctx->r11 = ADD32(0, 0X17BE);
    // 0x8080077C: b           L_80800790
    // 0x80800780: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_80800790;
    // 0x80800780: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80800784:
    // 0x80800784: b           L_80800790
    // 0x80800788: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_80800790;
    // 0x80800788: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8080078C:
    // 0x8080078C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80800790:
    // 0x80800790: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800794:
    // 0x80800794: addiu       $t6, $zero, 0x65
    ctx->r14 = ADD32(0, 0X65);
    // 0x80800798: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080079C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808007A0: jal         0x8008A208
    // 0x808007A4: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808007A4: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_15:
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808007B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808007B4: jal         0x80801118
    // 0x808007B8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80801118_chdinofamilymother(rdram, ctx);
        goto after_16;
    // 0x808007B8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_16:
    // 0x808007BC: b           L_808008C8
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007C4:
    // 0x808007C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808007C8:
    // 0x808007C8: addiu       $t7, $zero, 0x65
    ctx->r15 = ADD32(0, 0X65);
    // 0x808007CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808007D0: addiu       $a1, $zero, 0x17BF
    ctx->r5 = ADD32(0, 0X17BF);
    // 0x808007D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808007D8: jal         0x8008A208
    // 0x808007DC: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x808007DC: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_17:
    // 0x808007E0: b           L_808008C8
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007E8:
    // 0x808007E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007EC: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x808007F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808007F4: addiu       $a1, $zero, 0x17C1
    ctx->r5 = ADD32(0, 0X17C1);
    // 0x808007F8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808007FC: jal         0x8008A208
    // 0x80800800: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80800800: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_18:
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080080C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80800810: jal         0x80801118
    // 0x80800814: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80801118_chdinofamilymother(rdram, ctx);
        goto after_19;
    // 0x80800814: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_19:
    // 0x80800818: b           L_808008C8
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800820:
    // 0x80800820: jal         0x800F54E4
    // 0x80800824: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x80800824: nop

    after_20:
    // 0x80800828: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080082C: jal         0x800F64A4
    // 0x80800830: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_800F64A4(rdram, ctx);
        goto after_21;
    // 0x80800830: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_21:
    // 0x80800834: beq         $v0, $zero, L_8080088C
    if (ctx->r2 == 0) {
        // 0x80800838: addiu       $a0, $zero, 0x2B
        ctx->r4 = ADD32(0, 0X2B);
            goto L_8080088C;
    }
    // 0x80800838: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8080083C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x80800840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800848: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080084C: jal         0x800D1000
    // 0x80800850: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_22;
    // 0x80800850: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080085C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80800860: jal         0x80801118
    // 0x80800864: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80801118_chdinofamilymother(rdram, ctx);
        goto after_23;
    // 0x80800864: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_23:
    // 0x80800868: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080086C: addiu       $t9, $zero, 0x65
    ctx->r25 = ADD32(0, 0X65);
    // 0x80800870: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800874: addiu       $a1, $zero, 0x1818
    ctx->r5 = ADD32(0, 0X1818);
    // 0x80800878: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080087C: jal         0x8008A208
    // 0x80800880: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x80800880: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_24:
    // 0x80800884: b           L_808008C8
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080088C:
    // 0x8080088C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800890: jal         0x800D0C78
    // 0x80800894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D0C78(rdram, ctx);
        goto after_25;
    // 0x80800894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80800898: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080089C: addiu       $t0, $zero, 0x65
    ctx->r8 = ADD32(0, 0X65);
    // 0x808008A0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808008A4: addiu       $a1, $zero, 0x17C2
    ctx->r5 = ADD32(0, 0X17C2);
    // 0x808008A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808008AC: jal         0x8008A208
    // 0x808008B0: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x808008B0: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_26:
    // 0x808008B4: b           L_808008C8
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008C8;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008BC:
    // 0x808008BC: jal         0x80801228
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801228_chdinofamilymother(rdram, ctx);
        goto after_27;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
L_808008C4:
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008C8:
    // 0x808008C8: jal         0x80102424
    // 0x808008CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x808008CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_28:
    // 0x808008D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008DC: jr          $ra
    // 0x808008E0: nop

    return;
    // 0x808008E0: nop

;}
RECOMP_FUNC void _inantab_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F60: syscall     750
    recomp_syscall_handler(rdram, ctx, 0x80088F60);
    return;
    // 0x80088F64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080032C_chlagoonufoext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800334: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800338: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080033C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800340: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800344: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800348: beq         $t6, $at, L_80800360
    if (ctx->r14 == ctx->r1) {
        // 0x8080034C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800360;
    }
    // 0x8080034C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800350: beq         $t6, $at, L_80800388
    if (ctx->r14 == ctx->r1) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800388;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: b           L_8080046C
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080046C;
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800360:
    // 0x80800360: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080036C: andi        $t7, $a1, 0x1FF
    ctx->r15 = ctx->r5 & 0X1FF;
    // 0x80800370: jal         0x80089F40
    // 0x80800374: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    _subaddiesect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800374: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x80800378: bnel        $v0, $zero, L_8080046C
    if (ctx->r2 != 0) {
        // 0x8080037C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080046C;
    }
    goto skip_0;
    // 0x8080037C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800380: b           L_8080046C
    // 0x80800384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080046C;
    // 0x80800384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800388:
    // 0x80800388: lui         $a1, 0x3EFA
    ctx->r5 = S32(0X3EFA << 16);
    // 0x8080038C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800390: jal         0x80101E14
    // 0x80800394: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800394: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    after_1:
    // 0x80800398: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x8080039C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: lbu         $t8, 0x73($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X73);
    // 0x808003A4: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x808003A8: sb          $t9, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r25;
L_808003AC:
    // 0x808003AC: lui         $a1, 0x3F07
    ctx->r5 = S32(0X3F07 << 16);
    // 0x808003B0: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808003B4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808003B8: jal         0x80102320
    // 0x808003BC: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    func_80102320(rdram, ctx);
        goto after_2;
    // 0x808003BC: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    after_2:
    // 0x808003C0: beq         $v0, $zero, L_808003D8
    if (ctx->r2 == 0) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D8;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808003CC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808003D0: b           L_808003F4
    // 0x808003D4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
        goto L_808003F4;
    // 0x808003D4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
L_808003D8:
    // 0x808003D8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808003DC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(744, 0X510) << 16);
    // 0x808003E0: addiu       $a3, $a3, 0x510
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(744, 0X510));
    // 0x808003E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808003E8: jal         0x80089D50
    // 0x808003EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808003EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808003F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_808003F4:
    // 0x808003F4: lw          $t1, 0x70($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X70);
    // 0x808003F8: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x808003FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(744, 0X500) << 16);
    // 0x80800400: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80800404: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800408: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(744, 0X500));
    // 0x8080040C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800410: jal         0x80089D68
    // 0x80800414: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800414: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800418: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080041C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(744, 0X524) << 16);
    // 0x80800420: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(744, 0X5A0) << 16);
    // 0x80800424: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x80800428: addiu       $a3, $a3, 0x5A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(744, 0X5A0));
    // 0x8080042C: addiu       $a2, $a2, 0x524
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(744, 0X524));
    // 0x80800430: jal         0x80089D28
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800438: jal         0x800DA298
    // 0x8080043C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x8080043C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_6:
    // 0x80800440: beql        $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800444: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080046C;
    }
    goto skip_1;
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800448: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8080044C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800450: beq         $a0, $at, L_80800460
    if (ctx->r4 == ctx->r1) {
        // 0x80800454: nop
    
            goto L_80800460;
    }
    // 0x80800454: nop

    // 0x80800458: jal         0x800CBB80
    // 0x8080045C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CBB80(rdram, ctx);
        goto after_7;
    // 0x8080045C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_80800460:
    // 0x80800460: jal         0x800FFAB0
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080046C:
    // 0x8080046C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800470: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080071C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800720: jal         0x80800204
    // 0x80800724: nop

    func_80800204_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x80800724: nop

    after_0:
    // 0x80800728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080072C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800730: jr          $ra
    // 0x80800734: nop

    return;
    // 0x80800734: nop

;}
RECOMP_FUNC void _mlwave_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FB8: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FB8);
    return;
    // 0x80088FBC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chexploder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1392, 0X1AE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1AE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1392, 0X1AE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1AE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1392, 0X1AE0));
;}
RECOMP_FUNC void func_80800564_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800568: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080056C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800570: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800574: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800578: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8080057C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(916, 0XAF0) << 16);
    // 0x80800580: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(916, 0XB50) << 16);
    // 0x80800584: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800588: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8080058C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800590: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800594: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800598: addiu       $s1, $s1, 0xB50
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(916, 0XB50));
    // 0x8080059C: addiu       $s0, $s0, 0xAF0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(916, 0XAF0));
    // 0x808005A0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x808005A4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_808005A8:
    // 0x808005A8: beql        $s2, $a0, L_808005C4
    if (ctx->r18 == ctx->r4) {
        // 0x808005AC: lwc1        $f4, 0x8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
            goto L_808005C4;
    }
    goto skip_0;
    // 0x808005AC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x808005B0: jal         0x800C6E38
    // 0x808005B4: nop

    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x808005B4: nop

    after_0:
    // 0x808005B8: beql        $v0, $zero, L_808005CC
    if (ctx->r2 == 0) {
        // 0x808005BC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808005CC;
    }
    goto skip_1;
    // 0x808005BC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x808005C0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
L_808005C4:
    // 0x808005C4: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x808005C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_808005CC:
    // 0x808005CC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x808005D0: bnel        $at, $zero, L_808005A8
    if (ctx->r1 != 0) {
        // 0x808005D4: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_808005A8;
    }
    goto skip_2;
    // 0x808005D4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x808005D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808005DC: jal         0x800DC178
    // 0x808005E0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808005E0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x808005E4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(916, 0XAF0) << 16);
    // 0x808005E8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808005EC: addiu       $s0, $s0, 0xAF0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(916, 0XAF0));
    // 0x808005F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005F4: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_808005F8:
    // 0x808005F8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x808005FC: beql        $s2, $a0, L_80800618
    if (ctx->r18 == ctx->r4) {
        // 0x80800600: lwc1        $f6, 0x8($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80800618;
    }
    goto skip_3;
    // 0x80800600: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    skip_3:
    // 0x80800604: jal         0x800C6E38
    // 0x80800608: nop

    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x80800608: nop

    after_2:
    // 0x8080060C: beql        $v0, $zero, L_80800640
    if (ctx->r2 == 0) {
        // 0x80800610: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800640;
    }
    goto skip_4;
    // 0x80800610: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x80800614: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
L_80800618:
    // 0x80800618: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x8080061C: c.le.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl <= ctx->f22.fl;
    // 0x80800620: nop

    // 0x80800624: bc1fl       L_80800640
    if (!c1cs) {
        // 0x80800628: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800640;
    }
    goto skip_5;
    // 0x80800628: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8080062C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800630: addiu       $v0, $s1, 0x10A1
    ctx->r2 = ADD32(ctx->r17, 0X10A1);
    // 0x80800634: b           L_8080064C
    // 0x80800638: sw          $s1, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->r17;
        goto L_8080064C;
    // 0x80800638: sw          $s1, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->r17;
    // 0x8080063C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800640:
    // 0x80800640: bne         $s1, $s3, L_808005F8
    if (ctx->r17 != ctx->r19) {
        // 0x80800644: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808005F8;
    }
    // 0x80800644: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080064C:
    // 0x8080064C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800650: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800654: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800658: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080065C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800660: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800664: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800668: jr          $ra
    // 0x8080066C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080066C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800000_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800004: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1820, 0X12EC) << 16);
    // 0x80800008: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8080000C: lw          $v1, 0x12EC($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(1820, 0X12EC));
    // 0x80800010: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800014: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800018: andi        $a3, $v1, 0xFFFF
    ctx->r7 = ctx->r3 & 0XFFFF;
    // 0x8080001C: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    // 0x80800020: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800024: and         $a2, $v1, $at
    ctx->r6 = ctx->r3 & ctx->r1;
    // 0x80800028: srl         $t7, $a2, 16
    ctx->r15 = S32(U32(ctx->r6) >> 16);
    // 0x8080002C: andi        $t8, $a3, 0x2
    ctx->r24 = ctx->r7 & 0X2;
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: beq         $t8, $zero, L_8080006C
    if (ctx->r24 == 0) {
        // 0x80800038: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8080006C;
    }
    // 0x80800038: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8080003C: srl         $a0, $a3, 2
    ctx->r4 = S32(U32(ctx->r7) >> 2);
    // 0x80800040: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80800044: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800048: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080004C: jal         0x8001E210
    // 0x80800050: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x80800050: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800054: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800058: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080005C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: and         $t0, $v1, $at
    ctx->r8 = ctx->r3 & ctx->r1;
    // 0x80800064: b           L_8080008C
    // 0x80800068: srl         $v1, $t0, 16
    ctx->r3 = S32(U32(ctx->r8) >> 16);
        goto L_8080008C;
    // 0x80800068: srl         $v1, $t0, 16
    ctx->r3 = S32(U32(ctx->r8) >> 16);
L_8080006C:
    // 0x8080006C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800070: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800074: jal         0x8001E210
    // 0x80800078: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x80800078: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080007C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800080: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80800088: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_8080008C:
    // 0x8080008C: beq         $a2, $zero, L_808000F0
    if (ctx->r6 == 0) {
        // 0x80800090: lui         $at, 0xB000
        ctx->r1 = S32(0XB000 << 16);
            goto L_808000F0;
    }
    // 0x80800090: lui         $at, 0xB000
    ctx->r1 = S32(0XB000 << 16);
    // 0x80800094: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80800098: andi        $t3, $a2, 0x2
    ctx->r11 = ctx->r6 & 0X2;
    // 0x8080009C: beq         $t3, $zero, L_808000D4
    if (ctx->r11 == 0) {
        // 0x808000A0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808000D4;
    }
    // 0x808000A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808000A4: srl         $t4, $a2, 2
    ctx->r12 = S32(U32(ctx->r6) >> 2);
    // 0x808000A8: sll         $a0, $t4, 2
    ctx->r4 = S32(ctx->r12 << 2);
    // 0x808000AC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000B0: jal         0x8001E210
    // 0x808000B4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    rom_read_word(rdram, ctx);
        goto after_2;
    // 0x808000B4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808000B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000BC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808000C0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808000C4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x808000C8: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x808000CC: b           L_808000F0
    // 0x808000D0: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
        goto L_808000F0;
    // 0x808000D0: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_808000D4:
    // 0x808000D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000D8: jal         0x8001E210
    // 0x808000DC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    rom_read_word(rdram, ctx);
        goto after_3;
    // 0x808000DC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x808000E0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808000E4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808000E8: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x808000EC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_808000F0:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000F8: addiu       $v0, $v1, 0xA0
    ctx->r2 = ADD32(ctx->r3, 0XA0);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_80800000_vpwibble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800004: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80800008: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2982, 0X70E) << 16);
    // 0x8080000C: lh          $t7, 0x70E($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2982, 0X70E));
    // 0x80800010: mfhi        $t6
    ctx->r14 = hi;
    // 0x80800014: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x80800018: bne         $a0, $t7, L_8080002C
    if (ctx->r4 != ctx->r15) {
        // 0x8080001C: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(2982, 0X71E) << 16);
            goto L_8080002C;
    }
    // 0x8080001C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2982, 0X71E) << 16);
    // 0x80800020: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2982, 0X700) << 16);
    // 0x80800024: jr          $ra
    // 0x80800028: addiu       $v0, $a1, 0x700
    ctx->r2 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2982, 0X700));
    return;
    // 0x80800028: addiu       $v0, $a1, 0x700
    ctx->r2 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2982, 0X700));
L_8080002C:
    // 0x8080002C: lh          $t8, 0x71E($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(2982, 0X71E));
    // 0x80800030: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2982, 0X700) << 16);
    // 0x80800034: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2982, 0X700));
    // 0x80800038: bne         $a0, $t8, L_8080004C
    if (ctx->r4 != ctx->r24) {
        // 0x8080003C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8080004C;
    }
    // 0x8080003C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800040: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2982, 0X710) << 16);
    // 0x80800044: jr          $ra
    // 0x80800048: addiu       $v0, $v0, 0x710
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2982, 0X710));
    return;
    // 0x80800048: addiu       $v0, $v0, 0x710
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2982, 0X710));
L_8080004C:
    // 0x8080004C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800050: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x80800054: lh          $t0, 0xE($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XE);
    // 0x80800058: bnel        $a0, $t0, L_8080006C
    if (ctx->r4 != ctx->r8) {
        // 0x8080005C: lh          $t1, 0x1E($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X1E);
            goto L_8080006C;
    }
    goto skip_0;
    // 0x8080005C: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
    skip_0:
    // 0x80800060: jr          $ra
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800068: lh          $t1, 0x1E($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X1E);
L_8080006C:
    // 0x8080006C: bnel        $a0, $t1, L_80800080
    if (ctx->r4 != ctx->r9) {
        // 0x80800070: lh          $t2, 0x2E($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X2E);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800070: lh          $t2, 0x2E($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2E);
    skip_1:
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    return;
    // 0x80800078: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8080007C: lh          $t2, 0x2E($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2E);
L_80800080:
    // 0x80800080: bnel        $a0, $t2, L_80800094
    if (ctx->r4 != ctx->r10) {
        // 0x80800084: lh          $t3, 0x3E($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X3E);
            goto L_80800094;
    }
    goto skip_2;
    // 0x80800084: lh          $t3, 0x3E($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X3E);
    skip_2:
    // 0x80800088: jr          $ra
    // 0x8080008C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    return;
    // 0x8080008C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80800090: lh          $t3, 0x3E($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X3E);
L_80800094:
    // 0x80800094: bnel        $a0, $t3, L_808000A8
    if (ctx->r4 != ctx->r11) {
        // 0x80800098: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_808000A8;
    }
    goto skip_3;
    // 0x80800098: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_3:
    // 0x8080009C: jr          $ra
    // 0x808000A0: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    return;
    // 0x808000A0: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x808000A4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_808000A8:
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_800F54E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F54E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F54E8: jr          $ra
    // 0x800F54EC: lw          $v0, 0x54DC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X54DC);
    return;
    // 0x800F54EC: lw          $v0, 0x54DC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X54DC);
;}
RECOMP_FUNC void func_80013970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013970: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013974: lwc1        $f14, 0x16F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16F4);
    // 0x80013978: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8001397C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013980: nop

    // 0x80013984: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80013988: lui         $at, 0x4B00
    ctx->r1 = S32(0X4B00 << 16);
    // 0x8001398C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80013990: addiu       $t1, $t1, -0x2C60
    ctx->r9 = ADD32(ctx->r9, -0X2C60);
    // 0x80013994: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80013998: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001399C: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800139A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800139A4: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800139A8: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800139AC: nop

    // 0x800139B0: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800139B4: round.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = lroundf(ctx->f4.fl);
    // 0x800139B8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800139BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800139C0: lwc1        $f6, 0x16F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X16F8);
    // 0x800139C4: andi        $t2, $a0, 0xFFF
    ctx->r10 = ctx->r4 & 0XFFF;
    // 0x800139C8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800139CC: srl         $t0, $a0, 10
    ctx->r8 = S32(U32(ctx->r4) >> 10);
    // 0x800139D0: andi        $t0, $t0, 0x1FFC
    ctx->r8 = ctx->r8 & 0X1FFC;
    // 0x800139D4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800139D8: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x800139DC: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800139E0: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800139E4: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800139E8: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800139EC: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800139F0: jr          $ra
    // 0x800139F4: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
    return;
    // 0x800139F4: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
;}
RECOMP_FUNC void func_808063C8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808063C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808063CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808063D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808063D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808063D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808063DC: jal         0x800D8FF8
    // 0x808063E0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808063E0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x808063E4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808063E8: jal         0x80802228
    // 0x808063EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808063EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808063F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808063F4: jal         0x80802248
    // 0x808063F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808063F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808063FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806400: jal         0x8010CD50
    // 0x80806404: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_3;
    // 0x80806404: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80806408: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080640C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80806410: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80806414: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80806418: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080641C: lwc1        $f12, 0x48($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80806420: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80806424: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80806428: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080642C: jal         0x800F1F38
    // 0x80806430: nop

    func_800F1F38(rdram, ctx);
        goto after_4;
    // 0x80806430: nop

    after_4:
    // 0x80806434: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80806438: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080643C: swc1        $f0, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f0.u32l;
    // 0x80806440: jal         0x800F1DCC
    // 0x80806444: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80806444: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80806448: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080644C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80806450: jal         0x800F1DCC
    // 0x80806454: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x80806454: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80806458: jal         0x800F2100
    // 0x8080645C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_7;
    // 0x8080645C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80806460: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80806464: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80806468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080646C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80806470: nop

    // 0x80806474: bc1fl       L_80806488
    if (!c1cs) {
        // 0x80806478: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80806488;
    }
    goto skip_0;
    // 0x80806478: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080647C: jal         0x80805B8C
    // 0x80806480: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80805B8C_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80806480: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80806484: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80806488:
    // 0x80806488: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080648C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80806490: jal         0x800F20BC
    // 0x80806494: lwc1        $f12, 0x48($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X48);
    func_800F20BC(rdram, ctx);
        goto after_9;
    // 0x80806494: lwc1        $f12, 0x48($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X48);
    after_9:
    // 0x80806498: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8080649C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808064A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808064A4: beq         $t9, $zero, L_808064B8
    if (ctx->r25 == 0) {
        // 0x808064A8: sltiu       $a1, $v0, 0x1
        ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_808064B8;
    }
    // 0x808064A8: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808064AC: jal         0x808064CC
    // 0x808064B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_808064CC_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x808064B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_10:
    // 0x808064B4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_808064B8:
    // 0x808064B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808064BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808064C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808064C4: jr          $ra
    // 0x808064C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808064C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808026F8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808026FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802700: jal         0x80106790
    // 0x80802704: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802704: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080270C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802710: jr          $ra
    // 0x80802714: nop

    return;
    // 0x80802714: nop

;}
RECOMP_FUNC void func_80013EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013EF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013EF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80013EF8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80013EFC: addiu       $s0, $s0, -0xC10
    ctx->r16 = ADD32(ctx->r16, -0XC10);
    // 0x80013F00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80013F04: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80013F08: addiu       $v0, $v0, -0x6FB0
    ctx->r2 = ADD32(ctx->r2, -0X6FB0);
    // 0x80013F0C: addiu       $t6, $t6, -0x6EE0
    ctx->r14 = ADD32(ctx->r14, -0X6EE0);
    // 0x80013F10: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80013F14: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80013F18: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80013F1C: addiu       $t8, $t8, -0x6EE0
    ctx->r24 = ADD32(ctx->r24, -0X6EE0);
    // 0x80013F20: addiu       $t9, $t9, 0x2750
    ctx->r25 = ADD32(ctx->r25, 0X2750);
    // 0x80013F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013F28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80013F2C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80013F30: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x80013F34: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x80013F38: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80013F3C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80013F40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80013F44: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80013F48: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80013F4C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80013F50: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80013F54: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80013F58: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80013F5C: sll         $a1, $t4, 3
    ctx->r5 = S32(ctx->r12 << 3);
    // 0x80013F60: jal         0x8002E660
    // 0x80013F64: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80013F64: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    after_0:
    // 0x80013F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013F6C: jal         0x8002E660
    // 0x80013F70: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80013F70: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80013F74: jal         0x8002F08C
    // 0x80013F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x80013F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80013F7C: jal         0x8002F1F4
    // 0x80013F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x80013F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80013F84: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80013F88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013F8C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80013F90: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80013F94: sw          $t7, -0x7B74($at)
    MEM_W(-0X7B74, ctx->r1) = ctx->r15;
    // 0x80013F98: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80013F9C: addiu       $s0, $s0, -0x7B78
    ctx->r16 = ADD32(ctx->r16, -0X7B78);
    // 0x80013FA0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80013FA4: jal         0x8002F240
    // 0x80013FA8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    osDpGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x80013FA8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    after_4:
    // 0x80013FAC: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x80013FB0: bnel        $t0, $zero, L_80013FD4
    if (ctx->r8 != 0) {
        // 0x80013FB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80013FD4;
    }
    goto skip_0;
    // 0x80013FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80013FB8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80013FBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013FC0: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80013FC4: sw          $t1, -0x7B7C($at)
    MEM_W(-0X7B7C, ctx->r1) = ctx->r9;
    // 0x80013FC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013FCC: sw          $t2, -0x70F0($at)
    MEM_W(-0X70F0, ctx->r1) = ctx->r10;
    // 0x80013FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80013FD4:
    // 0x80013FD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80013FD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80013FDC: jr          $ra
    // 0x80013FE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80013FE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80013AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013AA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013AA4: b           L_80013ABC
    // 0x80013AA8: lwc1        $f14, 0x1708($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X1708);
    func_80013ABC(rdram, ctx);
    return;
    // 0x80013AA8: lwc1        $f14, 0x1708($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X1708);
;}
RECOMP_FUNC void func_800C7618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C761C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C7624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7628: beq         $a1, $zero, L_800C76B0
    if (ctx->r5 == 0) {
        // 0x800C762C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800C76B0;
    }
    // 0x800C762C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7630: jal         0x800FCCD4
    // 0x800C7634: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800FCCD4(rdram, ctx);
        goto after_0;
    // 0x800C7634: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C7638: beq         $v0, $zero, L_800C7694
    if (ctx->r2 == 0) {
        // 0x800C763C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_800C7694;
    }
    // 0x800C763C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C7640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C7644: bne         $a3, $at, L_800C7668
    if (ctx->r7 != ctx->r1) {
        // 0x800C7648: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C7668;
    }
    // 0x800C7648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C764C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7654: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x800C7658: jal         0x800FCDE0
    // 0x800C765C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800FCDE0(rdram, ctx);
        goto after_1;
    // 0x800C765C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x800C7660: b           L_800C767C
    // 0x800C7664: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_800C767C;
    // 0x800C7664: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_800C7668:
    // 0x800C7668: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800C766C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x800C7670: jal         0x800FCDE0
    // 0x800C7674: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800FCDE0(rdram, ctx);
        goto after_2;
    // 0x800C7674: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x800C7678: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_800C767C:
    // 0x800C767C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7680: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800C7684: jal         0x800FCAE0
    // 0x800C7688: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    func_800FCAE0(rdram, ctx);
        goto after_3;
    // 0x800C7688: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_3:
    // 0x800C768C: b           L_800C76D8
    // 0x800C7690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C76D8;
    // 0x800C7690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C7694:
    // 0x800C7694: jal         0x800FC660
    // 0x800C7698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x800C7698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800C769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C76A0: jal         0x800FC788
    // 0x800C76A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800FC788(rdram, ctx);
        goto after_5;
    // 0x800C76A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800C76A8: b           L_800C76D8
    // 0x800C76AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C76D8;
    // 0x800C76AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C76B0:
    // 0x800C76B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C76B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800C76B8: jal         0x800FCAE0
    // 0x800C76BC: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    func_800FCAE0(rdram, ctx);
        goto after_6;
    // 0x800C76BC: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_6:
    // 0x800C76C0: jal         0x800FCA90
    // 0x800C76C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FCA90(rdram, ctx);
        goto after_7;
    // 0x800C76C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800C76C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C76CC: jal         0x800FC788
    // 0x800C76D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FC788(rdram, ctx);
        goto after_8;
    // 0x800C76D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800C76D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C76D8:
    // 0x800C76D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C76DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C76E0: jr          $ra
    // 0x800C76E4: nop

    return;
    // 0x800C76E4: nop

;}
RECOMP_FUNC void badata_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080081C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800820: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800824: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800828: jal         0x80800000
    // 0x8080082C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x8080082C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800830: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(473, 0X1718) << 16);
    // 0x80800834: addiu       $t7, $t7, 0x1718
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(473, 0X1718));
    // 0x80800838: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8080083C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800840: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80800844: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800848: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8080084C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800850: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800854: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80800858: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8080085C: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800860: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80800864: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800868: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8080086C: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x80800870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800878: jr          $ra
    // 0x8080087C: nop

    return;
    // 0x8080087C: nop

;}
RECOMP_FUNC void func_80800138_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080013C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800140: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800144: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800148: addiu       $a1, $zero, 0x653
    ctx->r5 = ADD32(0, 0X653);
    // 0x8080014C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800150: bnel        $t7, $at, L_80800164
    if (ctx->r15 != ctx->r1) {
        // 0x80800154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800164;
    }
    goto skip_0;
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800158: jal         0x80103140
    // 0x8080015C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x8080015C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800164:
    // 0x80800164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void func_800CA9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA9D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA9DC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA9E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CA9E8: jal         0x800EE7F8
    // 0x800CA9EC: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CA9EC: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    after_0:
    // 0x800CA9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA9F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA9F8: jr          $ra
    // 0x800CA9FC: nop

    return;
    // 0x800CA9FC: nop

;}
RECOMP_FUNC void func_8008DD04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008DD08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD0C: jal         0x8009C150
    // 0x8008DD10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x8008DD10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008DD14: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008DD18: jal         0x80096364
    // 0x8008DD1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80096364(rdram, ctx);
        goto after_1;
    // 0x8008DD1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8008DD20: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008DD24: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8008DD28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008DD2C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8008DD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DD34: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8008DD38: nop

    // 0x8008DD3C: bc1f        L_8008DD48
    if (!c1cs) {
        // 0x8008DD40: nop
    
            goto L_8008DD48;
    }
    // 0x8008DD40: nop

    // 0x8008DD44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DD48:
    // 0x8008DD48: beql        $v0, $zero, L_8008DD64
    if (ctx->r2 == 0) {
        // 0x8008DD4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008DD64;
    }
    goto skip_0;
    // 0x8008DD4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008DD50: jal         0x8008E078
    // 0x8008DD54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x8008DD54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8008DD58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008DD5C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008DD60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DD64:
    // 0x8008DD64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008DD68: jr          $ra
    // 0x8008DD6C: nop

    return;
    // 0x8008DD6C: nop

;}
RECOMP_FUNC void func_8080000C_chhotfloorsmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800018: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8080001C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x80800020: jal         0x800EA05C
    // 0x80800024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800028: addiu       $at, $zero, 0xD1
    ctx->r1 = ADD32(0, 0XD1);
    // 0x8080002C: beq         $v0, $at, L_80800070
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800070;
    }
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x80800038: beql        $v0, $at, L_80800054
    if (ctx->r2 == ctx->r1) {
        // 0x8080003C: lhu         $t3, 0x6E($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0X6E);
            goto L_80800054;
    }
    goto skip_0;
    // 0x8080003C: lhu         $t3, 0x6E($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X6E);
    skip_0:
    // 0x80800040: lhu         $t9, 0x6E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800044: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800048: b           L_80800080
    // 0x8080004C: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
        goto L_80800080;
    // 0x8080004C: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
    // 0x80800050: lhu         $t3, 0x6E($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X6E);
L_80800054:
    // 0x80800054: lbu         $t1, 0x65($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X65);
    // 0x80800058: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x8080005C: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80800060: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800064: sb          $t2, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r10;
    // 0x80800068: b           L_80800080
    // 0x8080006C: sh          $t5, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r13;
        goto L_80800080;
    // 0x8080006C: sh          $t5, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r13;
L_80800070:
    // 0x80800070: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800074: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800078: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8080007C: sh          $t8, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r24;
L_80800080:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void gcdialogexec_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D9C: jal         0x80800F60
    // 0x80801DA0: nop

    func_80800F60_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80801DA0: nop

    after_0:
    // 0x80801DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801DAC: jr          $ra
    // 0x80801DB0: nop

    return;
    // 0x80801DB0: nop

;}
RECOMP_FUNC void func_80801718_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801718: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8080171C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801720: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801728: lwc1        $f14, 0x30($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8080172C: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80801730: jal         0x800F15F8
    // 0x80801734: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800F15F8(rdram, ctx);
        goto after_0;
    // 0x80801734: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_0:
    // 0x80801738: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080173C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2388, 0X3034) << 16);
    // 0x80801740: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801744: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801748: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8080174C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80801750: lhu         $v0, 0x3034($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(2388, 0X3034));
    // 0x80801754: addiu       $at, $zero, 0x3FA
    ctx->r1 = ADD32(0, 0X3FA);
    // 0x80801758: addiu       $t9, $sp, 0x60
    ctx->r25 = ADD32(ctx->r29, 0X60);
    // 0x8080175C: beq         $v0, $at, L_80801778
    if (ctx->r2 == ctx->r1) {
        // 0x80801760: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(2388, 0X315C) << 16);
            goto L_80801778;
    }
    // 0x80801760: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2388, 0X315C) << 16);
    // 0x80801764: addiu       $at, $zero, 0x3FC
    ctx->r1 = ADD32(0, 0X3FC);
    // 0x80801768: beq         $v0, $at, L_8080180C
    if (ctx->r2 == ctx->r1) {
        // 0x8080176C: addiu       $t3, $sp, 0x38
        ctx->r11 = ADD32(ctx->r29, 0X38);
            goto L_8080180C;
    }
    // 0x8080176C: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x80801770: b           L_808018A8
    // 0x80801774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808018A8;
    // 0x80801774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801778:
    // 0x80801778: addiu       $t0, $t0, 0x315C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2388, 0X315C));
    // 0x8080177C: addiu       $t2, $t0, 0x30
    ctx->r10 = ADD32(ctx->r8, 0X30);
L_80801780:
    // 0x80801780: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80801784: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80801788: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8080178C: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x80801790: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x80801794: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x80801798: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x8080179C: bne         $t0, $t2, L_80801780
    if (ctx->r8 != ctx->r10) {
        // 0x808017A0: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_80801780;
    }
    // 0x808017A0: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x808017A4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808017A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808017AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808017B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808017B4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808017B8: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x808017BC: lui         $a3, 0x3FA0
    ctx->r7 = S32(0X3FA0 << 16);
    // 0x808017C0: jal         0x800F10B4
    // 0x808017C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808017C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808017C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808017CC: jal         0x80101CDC
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808017D4: jal         0x80101F24
    // 0x808017D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_3;
    // 0x808017D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808017DC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808017E0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808017E4: jal         0x800F3780
    // 0x808017E8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800F3780(rdram, ctx);
        goto after_4;
    // 0x808017E8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x808017EC: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808017F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808017F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808017FC: jal         0x80105A9C
    // 0x80801800: nop

    func_80105A9C(rdram, ctx);
        goto after_5;
    // 0x80801800: nop

    after_5:
    // 0x80801804: b           L_808018A8
    // 0x80801808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808018A8;
    // 0x80801808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080180C:
    // 0x8080180C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2388, 0X318C) << 16);
    // 0x80801810: addiu       $t4, $t4, 0x318C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2388, 0X318C));
    // 0x80801814: addiu       $t6, $t4, 0x24
    ctx->r14 = ADD32(ctx->r12, 0X24);
L_80801818:
    // 0x80801818: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x8080181C: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80801820: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80801824: sw          $at, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r1;
    // 0x80801828: lw          $at, -0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X8);
    // 0x8080182C: sw          $at, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r1;
    // 0x80801830: lw          $at, -0x4($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X4);
    // 0x80801834: bne         $t4, $t6, L_80801818
    if (ctx->r12 != ctx->r14) {
        // 0x80801838: sw          $at, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r1;
            goto L_80801818;
    }
    // 0x80801838: sw          $at, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r1;
    // 0x8080183C: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80801840: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80801844: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80801848: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x8080184C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80801850: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801854: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801858: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080185C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801860: jal         0x800F10B4
    // 0x80801864: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80801864: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80801868: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080186C: jal         0x80101CDC
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_7;
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801874: jal         0x80101F24
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_8;
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080187C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801880: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801884: jal         0x800F3780
    // 0x80801888: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800F3780(rdram, ctx);
        goto after_9;
    // 0x80801888: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_9:
    // 0x8080188C: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801894: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801898: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080189C: jal         0x80105A9C
    // 0x808018A0: nop

    func_80105A9C(rdram, ctx);
        goto after_10;
    // 0x808018A0: nop

    after_10:
    // 0x808018A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808018A8:
    // 0x808018A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808018AC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808018B0: jr          $ra
    // 0x808018B4: nop

    return;
    // 0x808018B4: nop

;}
RECOMP_FUNC void chegggrenade_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2116, 0X450) << 16);
    // 0x808002F0: jr          $ra
    // 0x808002F4: addiu       $v0, $v0, 0x450
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2116, 0X450));
    return;
    // 0x808002F4: addiu       $v0, $v0, 0x450
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2116, 0X450));
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883A0: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x800883A0);
    return;
    // 0x800883A4: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void idflash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808000B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808000B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x808000B8: jr          $ra
    // 0x808000BC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x808000BC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void chmermaidstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1144, 0X39C) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x39C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1144, 0X39C));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x39C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1144, 0X39C));
;}
RECOMP_FUNC void _bashoes_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085048: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085048);
    return;
    // 0x8008504C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80026FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026FF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026FFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80027000: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80027004: beq         $t7, $zero, L_80027078
    if (ctx->r15 == 0) {
        // 0x80027008: nop
    
            goto L_80027078;
    }
    // 0x80027008: nop

    // 0x8002700C: jal         0x80021794
    // 0x80027010: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x80027010: nop

    after_0:
    // 0x80027014: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80027018: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002701C: bne         $t8, $zero, L_8002702C
    if (ctx->r24 != 0) {
        // 0x80027020: nop
    
            goto L_8002702C;
    }
    // 0x80027020: nop

    // 0x80027024: b           L_80027080
    // 0x80027028: nop

        goto L_80027080;
    // 0x80027028: nop

L_8002702C:
    // 0x8002702C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80027030: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80027034: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80027038: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002703C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80027040: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80027044: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80027048: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8002704C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80027050: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80027054: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80027058: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8002705C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80027060: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80027064: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80027068: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002706C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80027070: jal         0x8002B684
    // 0x80027074: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x80027074: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    after_1:
L_80027078:
    // 0x80027078: b           L_80027080
    // 0x8002707C: nop

        goto L_80027080;
    // 0x8002707C: nop

L_80027080:
    // 0x80027080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027088: jr          $ra
    // 0x8002708C: nop

    return;
    // 0x8002708C: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001C8: jal         0x808000F0
    // 0x808001CC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    ncpoducam_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001CC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_0:
    // 0x808001D0: jal         0x80800160
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800160_ncpoducam(rdram, ctx);
        goto after_1;
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001D8: jal         0x8001B754
    // 0x808001DC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    func_8001B754(rdram, ctx);
        goto after_2;
    // 0x808001DC: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_2:
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void vpflicker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x808001B8: addu        $v0, $t6, $a2
    ctx->r2 = ADD32(ctx->r14, ctx->r6);
    // 0x808001BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808001C0: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808001C4: beq         $at, $zero, L_808003DC
    if (ctx->r1 == 0) {
        // 0x808001C8: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_808003DC;
    }
    // 0x808001C8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_808001CC:
    // 0x808001CC: lbu         $t7, 0xC($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XC);
    // 0x808001D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001D4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808001D8: bgez        $t7, L_808001EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808001DC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808001EC;
    }
    // 0x808001DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001E4: nop

    // 0x808001E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808001EC:
    // 0x808001EC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808001F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808001F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808001FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800200: nop

    // 0x80800204: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800208: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080020C: nop

    // 0x80800210: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800214: beql        $t9, $zero, L_80800264
    if (ctx->r25 == 0) {
        // 0x80800218: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_80800264;
    }
    goto skip_0;
    // 0x80800218: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x8080021C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800224: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800228: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080022C: nop

    // 0x80800230: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800234: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800238: nop

    // 0x8080023C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800240: bne         $t9, $zero, L_80800258
    if (ctx->r25 != 0) {
        // 0x80800244: nop
    
            goto L_80800258;
    }
    // 0x80800244: nop

    // 0x80800248: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8080024C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800250: b           L_80800270
    // 0x80800254: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80800270;
    // 0x80800254: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80800258:
    // 0x80800258: b           L_80800270
    // 0x8080025C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80800270;
    // 0x8080025C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800260: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_80800264:
    // 0x80800264: nop

    // 0x80800268: bltz        $t9, L_80800258
    if (SIGNED(ctx->r25) < 0) {
        // 0x8080026C: nop
    
            goto L_80800258;
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: lbu         $t0, 0xD($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XD);
    // 0x80800274: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800278: sb          $t9, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r25;
    // 0x8080027C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80800280: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800284: bgez        $t0, L_80800298
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800288: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800298;
    }
    // 0x80800288: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080028C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800290: nop

    // 0x80800294: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80800298:
    // 0x80800298: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080029C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808002A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808002A4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x808002A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808002AC: nop

    // 0x808002B0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808002B4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808002B8: nop

    // 0x808002BC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x808002C0: beql        $t2, $zero, L_80800310
    if (ctx->r10 == 0) {
        // 0x808002C4: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_80800310;
    }
    goto skip_1;
    // 0x808002C4: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x808002C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808002D0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x808002D4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808002D8: nop

    // 0x808002DC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808002E0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x808002E4: nop

    // 0x808002E8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x808002EC: bne         $t2, $zero, L_80800304
    if (ctx->r10 != 0) {
        // 0x808002F0: nop
    
            goto L_80800304;
    }
    // 0x808002F0: nop

    // 0x808002F4: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x808002F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002FC: b           L_8080031C
    // 0x80800300: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8080031C;
    // 0x80800300: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80800304:
    // 0x80800304: b           L_8080031C
    // 0x80800308: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8080031C;
    // 0x80800308: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8080030C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_80800310:
    // 0x80800310: nop

    // 0x80800314: bltz        $t2, L_80800304
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800318: nop
    
            goto L_80800304;
    }
    // 0x80800318: nop

L_8080031C:
    // 0x8080031C: lbu         $t3, 0xE($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XE);
    // 0x80800320: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800324: sb          $t2, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r10;
    // 0x80800328: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8080032C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800330: bgez        $t3, L_80800344
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800334: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800344;
    }
    // 0x80800334: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080033C: nop

    // 0x80800340: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80800344:
    // 0x80800344: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800348: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080034C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800350: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800354: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800358: nop

    // 0x8080035C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800360: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800364: nop

    // 0x80800368: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8080036C: beql        $t5, $zero, L_808003BC
    if (ctx->r13 == 0) {
        // 0x80800370: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_808003BC;
    }
    goto skip_2;
    // 0x80800370: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x80800374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800378: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8080037C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800380: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80800384: nop

    // 0x80800388: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080038C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80800390: nop

    // 0x80800394: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80800398: bne         $t5, $zero, L_808003B0
    if (ctx->r13 != 0) {
        // 0x8080039C: nop
    
            goto L_808003B0;
    }
    // 0x8080039C: nop

    // 0x808003A0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x808003A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003A8: b           L_808003C8
    // 0x808003AC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_808003C8;
    // 0x808003AC: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_808003B0:
    // 0x808003B0: b           L_808003C8
    // 0x808003B4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_808003C8;
    // 0x808003B4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808003B8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_808003BC:
    // 0x808003BC: nop

    // 0x808003C0: bltz        $t5, L_808003B0
    if (SIGNED(ctx->r13) < 0) {
        // 0x808003C4: nop
    
            goto L_808003B0;
    }
    // 0x808003C4: nop

L_808003C8:
    // 0x808003C8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808003CC: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808003D0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808003D4: bne         $at, $zero, L_808001CC
    if (ctx->r1 != 0) {
        // 0x808003D8: sb          $t5, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r13;
            goto L_808001CC;
    }
    // 0x808003D8: sb          $t5, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r13;
L_808003DC:
    // 0x808003DC: jr          $ra
    // 0x808003E0: nop

    return;
    // 0x808003E0: nop

    // 0x808003E4: nop

    // 0x808003E8: nop

    // 0x808003EC: nop

;}
RECOMP_FUNC void _bsstand_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B60: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B60);
    return;
    // 0x80083B64: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800A4030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4038: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A403C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A4040: lbu         $t7, 0x6($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X6);
    // 0x800A4044: bne         $t7, $at, L_800A405C
    if (ctx->r15 != ctx->r1) {
        // 0x800A4048: nop
    
            goto L_800A405C;
    }
    // 0x800A4048: nop

    // 0x800A404C: jal         0x800A4074
    // 0x800A4050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800A4074(rdram, ctx);
        goto after_0;
    // 0x800A4050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x800A4054: b           L_800A4068
    // 0x800A4058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A4068;
    // 0x800A4058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A405C:
    // 0x800A405C: jal         0x800A4074
    // 0x800A4060: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A4074(rdram, ctx);
        goto after_1;
    // 0x800A4060: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x800A4064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A4068:
    // 0x800A4068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A406C: jr          $ra
    // 0x800A4070: nop

    return;
    // 0x800A4070: nop

;}
RECOMP_FUNC void func_8001C0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C0A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001C0A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001C0A8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001C0AC: addiu       $s2, $s2, -0x1670
    ctx->r18 = ADD32(ctx->r18, -0X1670);
    // 0x8001C0B0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001C0B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001C0B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001C0BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C0C0: blez        $a0, L_8001C0D0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001C0C4: lw          $s0, 0x4($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X4);
            goto L_8001C0D0;
    }
    // 0x8001C0C4: lw          $s0, 0x4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X4);
    // 0x8001C0C8: b           L_8001C0D4
    // 0x8001C0CC: nop

        goto L_8001C0D4;
    // 0x8001C0CC: nop

L_8001C0D0:
    // 0x8001C0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001C0D4:
    // 0x8001C0D4: jal         0x8001BD30
    // 0x8001C0D8: nop

    func_8001BD30(rdram, ctx);
        goto after_0;
    // 0x8001C0D8: nop

    after_0:
    // 0x8001C0DC: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8001C0E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001C0E4: subu        $t7, $v1, $s0
    ctx->r15 = SUB32(ctx->r3, ctx->r16);
    // 0x8001C0E8: addiu       $t8, $t7, -0x10
    ctx->r24 = ADD32(ctx->r15, -0X10);
    // 0x8001C0EC: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x8001C0F0: bne         $at, $zero, L_8001C108
    if (ctx->r1 != 0) {
        // 0x8001C0F4: nop
    
            goto L_8001C108;
    }
    // 0x8001C0F4: nop

    // 0x8001C0F8: lbu         $t9, 0xF($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XF);
    // 0x8001C0FC: srl         $t0, $t9, 6
    ctx->r8 = S32(U32(ctx->r25) >> 6);
    // 0x8001C100: beql        $t0, $zero, L_8001C178
    if (ctx->r8 == 0) {
        // 0x8001C104: lbu         $t2, 0xF($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XF);
            goto L_8001C178;
    }
    goto skip_0;
    // 0x8001C104: lbu         $t2, 0xF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XF);
    skip_0:
L_8001C108:
    // 0x8001C108: jal         0x8001B3E8
    // 0x8001C10C: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_1;
    // 0x8001C10C: nop

    after_1:
    // 0x8001C110: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8001C114: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8001C118: addiu       $t1, $v1, 0x20
    ctx->r9 = ADD32(ctx->r3, 0X20);
    // 0x8001C11C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001C120: beql        $t1, $t3, L_8001C178
    if (ctx->r9 == ctx->r11) {
        // 0x8001C124: lbu         $t2, 0xF($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XF);
            goto L_8001C178;
    }
    goto skip_1;
    // 0x8001C124: lbu         $t2, 0xF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XF);
    skip_1:
    // 0x8001C128: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_8001C12C:
    // 0x8001C12C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x8001C130: subu        $t4, $v1, $s0
    ctx->r12 = SUB32(ctx->r3, ctx->r16);
    // 0x8001C134: addiu       $t5, $t4, -0x10
    ctx->r13 = ADD32(ctx->r12, -0X10);
    // 0x8001C138: sltu        $at, $t5, $s1
    ctx->r1 = ctx->r13 < ctx->r17 ? 1 : 0;
    // 0x8001C13C: bne         $at, $zero, L_8001C154
    if (ctx->r1 != 0) {
        // 0x8001C140: nop
    
            goto L_8001C154;
    }
    // 0x8001C140: nop

    // 0x8001C144: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x8001C148: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x8001C14C: beql        $t7, $zero, L_8001C178
    if (ctx->r15 == 0) {
        // 0x8001C150: lbu         $t2, 0xF($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XF);
            goto L_8001C178;
    }
    goto skip_2;
    // 0x8001C150: lbu         $t2, 0xF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XF);
    skip_2:
L_8001C154:
    // 0x8001C154: jal         0x8001B3E8
    // 0x8001C158: nop

    heap_bytes_allocated(rdram, ctx);
        goto after_2;
    // 0x8001C158: nop

    after_2:
    // 0x8001C15C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8001C160: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8001C164: addiu       $t8, $v1, 0x20
    ctx->r24 = ADD32(ctx->r3, 0X20);
    // 0x8001C168: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8001C16C: bnel        $t8, $t0, L_8001C12C
    if (ctx->r24 != ctx->r8) {
        // 0x8001C170: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_8001C12C;
    }
    goto skip_3;
    // 0x8001C170: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    skip_3:
    // 0x8001C174: lbu         $t2, 0xF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XF);
L_8001C178:
    // 0x8001C178: subu        $t3, $v1, $s0
    ctx->r11 = SUB32(ctx->r3, ctx->r16);
    // 0x8001C17C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C180: srl         $t1, $t2, 6
    ctx->r9 = S32(U32(ctx->r10) >> 6);
    // 0x8001C184: beq         $t1, $zero, L_8001C194
    if (ctx->r9 == 0) {
        // 0x8001C188: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001C194;
    }
    // 0x8001C188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001C18C: b           L_8001C1AC
    // 0x8001C190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001C1AC;
    // 0x8001C190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001C194:
    // 0x8001C194: addiu       $t4, $t3, -0x10
    ctx->r12 = ADD32(ctx->r11, -0X10);
    // 0x8001C198: sltu        $at, $t4, $s1
    ctx->r1 = ctx->r12 < ctx->r17 ? 1 : 0;
    // 0x8001C19C: beq         $at, $zero, L_8001C1AC
    if (ctx->r1 == 0) {
        // 0x8001C1A0: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8001C1AC;
    }
    // 0x8001C1A0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8001C1A4: b           L_8001C1AC
    // 0x8001C1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001C1AC;
    // 0x8001C1A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001C1AC:
    // 0x8001C1AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C1B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C1B4: jr          $ra
    // 0x8001C1B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001C1B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001C1BC: nop

;}
RECOMP_FUNC void idscroll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80800050: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800054: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800058: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080005C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800060: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80800064: jr          $ra
    // 0x80800068: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80800068: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8011546C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011546C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80115470: jr          $ra
    // 0x80115474: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x80115474: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_80803378_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080337C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803380: jal         0x80100094
    // 0x80803384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803388: lbu         $t6, 0x6F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6F);
    // 0x8080338C: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x80803390: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80803394: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80803398: bgez        $t6, L_808033AC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080339C: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808033AC;
    }
    // 0x8080339C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808033A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808033A4: nop

    // 0x808033A8: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_808033AC:
    // 0x808033AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808033B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808033B4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808033B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808033BC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808033C0: jal         0x800F10B4
    // 0x808033C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808033C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808033C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808033CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808033D0: jr          $ra
    // 0x808033D4: nop

    return;
    // 0x808033D4: nop

;}
RECOMP_FUNC void func_80800730_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800730: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800738: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080073C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800740: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800744: jal         0x80100094
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080074C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800750: jal         0x800DA298
    // 0x80800754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800758: bne         $v0, $zero, L_808007E0
    if (ctx->r2 != 0) {
        // 0x8080075C: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_808007E0;
    }
    // 0x8080075C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800760: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x80800764: jal         0x8010114C
    // 0x80800768: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x80800768: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8080076C: beql        $v0, $zero, L_80800780
    if (ctx->r2 == 0) {
        // 0x80800770: addiu       $t6, $s0, 0x4
        ctx->r14 = ADD32(ctx->r16, 0X4);
            goto L_80800780;
    }
    goto skip_0;
    // 0x80800770: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800774: jal         0x80101038
    // 0x80800778: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_80101038(rdram, ctx);
        goto after_3;
    // 0x80800778: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8080077C: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
L_80800780:
    // 0x80800780: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80800784: jal         0x800DA298
    // 0x80800788: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800788: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x8080078C: beq         $v0, $zero, L_808007A4
    if (ctx->r2 == 0) {
        // 0x80800790: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808007A4;
    }
    // 0x80800790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800794: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80800798: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    // 0x8080079C: jal         0x800EF214
    // 0x808007A0: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_800EF214(rdram, ctx);
        goto after_5;
    // 0x808007A0: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_5:
L_808007A4:
    // 0x808007A4: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808007A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007AC: jal         0x800F18FC
    // 0x808007B0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F18FC(rdram, ctx);
        goto after_6;
    // 0x808007B0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808007B4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808007B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007BC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x808007C0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x808007C4: swc1        $f6, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f6.u32l;
    // 0x808007C8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808007CC: jal         0x80102B2C
    // 0x808007D0: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    func_80102B2C(rdram, ctx);
        goto after_7;
    // 0x808007D0: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    after_7:
    // 0x808007D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007D8: jal         0x80102B6C
    // 0x808007DC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102B6C(rdram, ctx);
        goto after_8;
    // 0x808007DC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_8:
L_808007E0:
    // 0x808007E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808007E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808007EC: jr          $ra
    // 0x808007F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808007F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801ECC_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ECC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801ED0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801ED4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801ED8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801EDC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801EE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801EE4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80801EE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801EEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801EF0: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_80801EF4:
    // 0x80801EF4: jal         0x800F6438
    // 0x80801EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80801EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801EFC: beql        $v0, $zero, L_80801F20
    if (ctx->r2 == 0) {
        // 0x80801F00: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801F20;
    }
    goto skip_0;
    // 0x80801F00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801F04: jal         0x800F5EF8
    // 0x80801F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x80801F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801F0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801F14: jal         0x8010FE14
    // 0x80801F18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8010FE14(rdram, ctx);
        goto after_2;
    // 0x80801F18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80801F1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801F20:
    // 0x80801F20: bne         $s0, $s3, L_80801EF4
    if (ctx->r16 != ctx->r19) {
        // 0x80801F24: nop
    
            goto L_80801EF4;
    }
    // 0x80801F24: nop

    // 0x80801F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801F2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801F30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801F34: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F38: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801F3C: jr          $ra
    // 0x80801F40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801F40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800BA2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA2C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA2CC: jal         0x8001B084
    // 0x800BA2D0: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800BA2D0: nop

    after_0:
    // 0x800BA2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA2D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA2DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BA2E0: jr          $ra
    // 0x800BA2E4: nop

    return;
    // 0x800BA2E4: nop

;}
RECOMP_FUNC void func_800BF228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF228: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF22C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BF230: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BF234: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BF238: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
    // 0x800BF23C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BF240: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800BF244: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BF248: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BF24C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800BF250: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF254: beq         $t6, $zero, L_800BF27C
    if (ctx->r14 == 0) {
        // 0x800BF258: sw          $zero, 0x1B0($s0)
        MEM_W(0X1B0, ctx->r16) = 0;
            goto L_800BF27C;
    }
    // 0x800BF258: sw          $zero, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = 0;
    // 0x800BF25C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BF264: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BF268: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800BF26C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800BF270: jal         0x80087FD0
    // 0x800BF274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _gcmapsects_entrypoint_26(rdram, ctx);
        goto after_0;
    // 0x800BF274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x800BF278: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800BF27C:
    // 0x800BF27C: bne         $v1, $zero, L_800BF2C0
    if (ctx->r3 != 0) {
        // 0x800BF280: nop
    
            goto L_800BF2C0;
    }
    // 0x800BF280: nop

    // 0x800BF284: lbu         $t8, 0x2A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2A);
    // 0x800BF288: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800BF28C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800BF290: beq         $t8, $zero, L_800BF2C0
    if (ctx->r24 == 0) {
        // 0x800BF294: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_800BF2C0;
    }
    // 0x800BF294: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800BF298: lbu         $t9, 0x29($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X29);
    // 0x800BF29C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF2A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800BF2A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BF2A8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800BF2AC: lw          $a1, 0x10($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X10);
    // 0x800BF2B0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800BF2B4: jal         0x800AC978
    // 0x800BF2B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800AC978(rdram, ctx);
        goto after_1;
    // 0x800BF2B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x800BF2BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800BF2C0:
    // 0x800BF2C0: beql        $v1, $zero, L_800BF2D4
    if (ctx->r3 == 0) {
        // 0x800BF2C4: lbu         $t5, 0x56($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X56);
            goto L_800BF2D4;
    }
    goto skip_0;
    // 0x800BF2C4: lbu         $t5, 0x56($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X56);
    skip_0:
    // 0x800BF2C8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x800BF2CC: sw          $t4, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r12;
    // 0x800BF2D0: lbu         $t5, 0x56($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X56);
L_800BF2D4:
    // 0x800BF2D4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800BF2D8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800BF2DC: bne         $t5, $zero, L_800BF2EC
    if (ctx->r13 != 0) {
        // 0x800BF2E0: lw          $t9, 0x38($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X38);
            goto L_800BF2EC;
    }
    // 0x800BF2E0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800BF2E4: b           L_800BF32C
    // 0x800BF2E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800BF32C;
    // 0x800BF2E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800BF2EC:
    // 0x800BF2EC: lbu         $t6, 0x55($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X55);
    // 0x800BF2F0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF2F4: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x800BF2F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BF2FC: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800BF300: lw          $a1, 0x3C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X3C);
    // 0x800BF304: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800BF308: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800BF30C: jal         0x800AC978
    // 0x800BF310: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800AC978(rdram, ctx);
        goto after_2;
    // 0x800BF310: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x800BF314: beq         $v0, $zero, L_800BF328
    if (ctx->r2 == 0) {
        // 0x800BF318: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_800BF328;
    }
    // 0x800BF318: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF31C: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x800BF320: b           L_800BF32C
    // 0x800BF324: sw          $t1, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r9;
        goto L_800BF32C;
    // 0x800BF324: sw          $t1, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r9;
L_800BF328:
    // 0x800BF328: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800BF32C:
    // 0x800BF32C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BF330: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800BF334: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BF338: jr          $ra
    // 0x800BF33C: nop

    return;
    // 0x800BF33C: nop

;}
RECOMP_FUNC void func_80800078_chjinjovillagecamera1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080007C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800088: beq         $a1, $at, L_808000B0
    if (ctx->r5 == ctx->r1) {
        // 0x8080008C: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808000B0;
    }
    // 0x8080008C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800090: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800094: beq         $a1, $at, L_80800288
    if (ctx->r5 == ctx->r1) {
        // 0x80800098: addiu       $v0, $sp, 0x40
        ctx->r2 = ADD32(ctx->r29, 0X40);
            goto L_80800288;
    }
    // 0x80800098: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8080009C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808000A0: beq         $a1, $at, L_80800120
    if (ctx->r5 == ctx->r1) {
        // 0x808000A4: addiu       $a0, $zero, 0x6D0
        ctx->r4 = ADD32(0, 0X6D0);
            goto L_80800120;
    }
    // 0x808000A4: addiu       $a0, $zero, 0x6D0
    ctx->r4 = ADD32(0, 0X6D0);
    // 0x808000A8: b           L_808002AC
    // 0x808000AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002AC;
    // 0x808000AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000B0:
    // 0x808000B0: addiu       $a0, $zero, 0x6D0
    ctx->r4 = ADD32(0, 0X6D0);
    // 0x808000B4: jal         0x800DA564
    // 0x808000B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808000B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808000BC: jal         0x800EA05C
    // 0x808000C0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808000C0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000C4: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x808000C8: bne         $v0, $at, L_808000F8
    if (ctx->r2 != ctx->r1) {
        // 0x808000CC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_808000F8;
    }
    // 0x808000CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808000D0: jal         0x80086B98
    // 0x808000D4: nop

    _chjinjo_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000D4: nop

    after_2:
    // 0x808000D8: jal         0x800887F0
    // 0x808000DC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808000DC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_3:
    // 0x808000E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000E8: jal         0x80088868
    // 0x808000EC: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x808000EC: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    after_4:
    // 0x808000F0: b           L_808002AC
    // 0x808000F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808002AC;
    // 0x808000F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808000F8:
    // 0x808000F8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2028, 0X47C) << 16);
    // 0x808000FC: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80800100: lbu         $t7, 0x47C($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(2028, 0X47C));
    // 0x80800104: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800108: bne         $t6, $t7, L_80800118
    if (ctx->r14 != ctx->r15) {
        // 0x8080010C: nop
    
            goto L_80800118;
    }
    // 0x8080010C: nop

    // 0x80800110: jal         0x800DA544
    // 0x80800114: addiu       $a0, $zero, 0x39E
    ctx->r4 = ADD32(0, 0X39E);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800114: addiu       $a0, $zero, 0x39E
    ctx->r4 = ADD32(0, 0X39E);
    after_5:
L_80800118:
    // 0x80800118: b           L_808002AC
    // 0x8080011C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808002AC;
    // 0x8080011C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800120:
    // 0x80800120: jal         0x800DA564
    // 0x80800124: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_6;
    // 0x80800124: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800128: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080012C: jal         0x80088840
    // 0x80800130: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_7;
    // 0x80800130: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_7:
    // 0x80800134: bne         $v0, $zero, L_80800144
    if (ctx->r2 != 0) {
        // 0x80800138: nop
    
            goto L_80800144;
    }
    // 0x80800138: nop

    // 0x8080013C: b           L_808002AC
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002AC;
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800144:
    // 0x80800144: jal         0x800EA05C
    // 0x80800148: nop

    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x80800148: nop

    after_8:
    // 0x8080014C: addiu       $at, $zero, 0x142
    ctx->r1 = ADD32(0, 0X142);
    // 0x80800150: bne         $v0, $at, L_80800184
    if (ctx->r2 != ctx->r1) {
        // 0x80800154: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_80800184;
    }
    // 0x80800154: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800158: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080015C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800160: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2028, 0X470) << 16);
    // 0x80800164: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80800168: lbu         $a2, 0x470($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(2028, 0X470));
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800170: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x80800174: jal         0x80085708
    // 0x80800178: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800178: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_9:
    // 0x8080017C: b           L_808002AC
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002AC;
    // 0x80800180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800184:
    // 0x80800184: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800188: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2028, 0X47C) << 16);
    // 0x8080018C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80800190: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80800194: lbu         $a2, 0x47C($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(2028, 0X47C));
    // 0x80800198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080019C: jal         0x80085708
    // 0x808001A0: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x808001A0: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_10:
    // 0x808001A4: addiu       $a0, $zero, 0x43C
    ctx->r4 = ADD32(0, 0X43C);
    // 0x808001A8: jal         0x800DA9E4
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_11;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808001B0: bne         $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x808001B4: addiu       $a0, $zero, 0x43D
        ctx->r4 = ADD32(0, 0X43D);
            goto L_80800238;
    }
    // 0x808001B4: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    // 0x808001B8: jal         0x800D1338
    // 0x808001BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800D1338(rdram, ctx);
        goto after_12;
    // 0x808001BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x808001C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808001C4: jal         0x800D129C
    // 0x808001C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800D129C(rdram, ctx);
        goto after_13;
    // 0x808001C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x808001CC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808001D0: bne         $v0, $t2, L_8080020C
    if (ctx->r2 != ctx->r10) {
        // 0x808001D4: nop
    
            goto L_8080020C;
    }
    // 0x808001D4: nop

    // 0x808001D8: jal         0x800DA544
    // 0x808001DC: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x808001DC: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_14:
    // 0x808001E0: jal         0x80086B80
    // 0x808001E4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _chjinjo_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x808001E4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x808001E8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x808001EC: addiu       $a1, $zero, 0x1524
    ctx->r5 = ADD32(0, 0X1524);
    // 0x808001F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808001F4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808001F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808001FC: jal         0x8008A208
    // 0x80800200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x80800204: b           L_808002AC
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002AC;
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080020C:
    // 0x8080020C: jal         0x80086B80
    // 0x80800210: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _chjinjo_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800210: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x80800214: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80800218: addiu       $a1, $zero, 0x1522
    ctx->r5 = ADD32(0, 0X1522);
    // 0x8080021C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800220: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80800224: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800228: jal         0x8008A208
    // 0x8080022C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x8080022C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80800230: b           L_808002AC
    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002AC;
    // 0x80800234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800238:
    // 0x80800238: jal         0x800DA9E4
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_19;
    // 0x8080023C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800240: bne         $v0, $zero, L_808002A8
    if (ctx->r2 != 0) {
        // 0x80800244: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_808002A8;
    }
    // 0x80800244: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800248: bne         $t5, $zero, L_80800258
    if (ctx->r13 != 0) {
        // 0x8080024C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800258;
    }
    // 0x8080024C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800250: b           L_8080025C
    // 0x80800254: addiu       $a1, $zero, 0x1565
    ctx->r5 = ADD32(0, 0X1565);
        goto L_8080025C;
    // 0x80800254: addiu       $a1, $zero, 0x1565
    ctx->r5 = ADD32(0, 0X1565);
L_80800258:
    // 0x80800258: addiu       $a1, $zero, 0x1523
    ctx->r5 = ADD32(0, 0X1523);
L_8080025C:
    // 0x8080025C: jal         0x80086B80
    // 0x80800260: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _chjinjo_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80800260: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_20:
    // 0x80800264: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800268: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080026C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800270: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800274: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800278: jal         0x8008A208
    // 0x8080027C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x8080027C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x80800280: b           L_808002AC
    // 0x80800284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002AC;
    // 0x80800284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800288:
    // 0x80800288: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080028C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800290: jal         0x80800000
    // 0x80800294: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800000_chjinjovillagecamera1(rdram, ctx);
        goto after_22;
    // 0x80800294: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_22:
    // 0x80800298: b           L_808002AC
    // 0x8080029C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002AC;
    // 0x8080029C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002A0: b           L_808002AC
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002AC;
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A8:
    // 0x808002A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002AC:
    // 0x808002AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002B4: jr          $ra
    // 0x808002B8: nop

    return;
    // 0x808002B8: nop

;}
RECOMP_FUNC void func_80800A58_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A60: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800A64: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800A68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A6C: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800A70: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800A74: addiu       $at, $zero, 0x39E
    ctx->r1 = ADD32(0, 0X39E);
    // 0x80800A78: bne         $t8, $at, L_80800A8C
    if (ctx->r24 != ctx->r1) {
        // 0x80800A7C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800A8C;
    }
    // 0x80800A7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800A80: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800A84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800A8C:
    // 0x80800A8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A90: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800A94: addiu       $t0, $zero, 0xEC
    ctx->r8 = ADD32(0, 0XEC);
    // 0x80800A98: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800A9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800AA0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800AA4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80800AA8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80800AAC: jal         0x80086898
    // 0x80800AB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800AB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AB4: beq         $v0, $zero, L_80800AE4
    if (ctx->r2 == 0) {
        // 0x80800AB8: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80800AE4;
    }
    // 0x80800AB8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800ABC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AC0: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80800AC4: jal         0x800868B0
    // 0x80800AC8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800AC8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800ACC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800AD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AD4: beql        $v1, $zero, L_80800AE8
    if (ctx->r3 == 0) {
        // 0x80800AD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AE8;
    }
    goto skip_0;
    // 0x80800AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800ADC: jal         0x800868C0
    // 0x80800AE0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800AE0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
L_80800AE4:
    // 0x80800AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AE8:
    // 0x80800AE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800AEC: jr          $ra
    // 0x80800AF0: nop

    return;
    // 0x80800AF0: nop

    // 0x80800AF4: nop

    // 0x80800AF8: nop

    // 0x80800AFC: nop

;}
RECOMP_FUNC void func_800CB5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB5D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB5D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB5DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CB5E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB5E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CB5E8: jal         0x800CB698
    // 0x800CB5EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800CB698(rdram, ctx);
        goto after_0;
    // 0x800CB5EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800CB5F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CB5F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB5F8: jal         0x800CB534
    // 0x800CB5FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800CB534(rdram, ctx);
        goto after_1;
    // 0x800CB5FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800CB600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB608: jr          $ra
    // 0x800CB60C: nop

    return;
    // 0x800CB60C: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F78: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F78);
    return;
    // 0x80083F7C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800E4AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E4AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4AF8: jal         0x800E4730
    // 0x800E4AFC: nop

    func_800E4730(rdram, ctx);
        goto after_0;
    // 0x800E4AFC: nop

    after_0:
    // 0x800E4B00: bgez        $v0, L_800E4B10
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E4B04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E4B10;
    }
    // 0x800E4B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4B08: b           L_800E4B14
    // 0x800E4B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4B14;
    // 0x800E4B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4B10:
    // 0x800E4B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E4B14:
    // 0x800E4B14: jr          $ra
    // 0x800E4B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E4B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chlakemonster_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CD8: syscall     444
    recomp_syscall_handler(rdram, ctx, 0x80086CD8);
    return;
    // 0x80086CDC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
