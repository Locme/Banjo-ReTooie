#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80110818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011081C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80110820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110824: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80110828: jal         0x800EE7F8
    // 0x8011082C: addiu       $a1, $a3, 0x80
    ctx->r5 = ADD32(ctx->r7, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8011082C: addiu       $a1, $a3, 0x80
    ctx->r5 = ADD32(ctx->r7, 0X80);
    after_0:
    // 0x80110830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110838: jr          $ra
    // 0x8011083C: nop

    return;
    // 0x8011083C: nop

;}
RECOMP_FUNC void _chlensflare_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087510: syscall     582
    recomp_syscall_handler(rdram, ctx, 0x80087510);
    return;
    // 0x80087514: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_801104F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801104F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801104F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801104FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80110500: jal         0x801106A8
    // 0x80110504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801106A8(rdram, ctx);
        goto after_0;
    // 0x80110504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80110508: jal         0x80113410
    // 0x8011050C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80113410(rdram, ctx);
        goto after_1;
    // 0x8011050C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80110510: jal         0x8001B084
    // 0x80110514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x80110514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80110518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011051C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110520: jr          $ra
    // 0x80110524: nop

    return;
    // 0x80110524: nop

;}
RECOMP_FUNC void chwarriorbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(876, 0X128) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x128
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(876, 0X128));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x128
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(876, 0X128));
;}
RECOMP_FUNC void func_80800C54_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800C60: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800C64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800C68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800C6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C70: lb          $t7, 0xD($a0)
    ctx->r15 = MEM_B(ctx->r4, 0XD);
    // 0x80800C74: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2658, 0X2070) << 16);
    // 0x80800C78: addiu       $t9, $t9, 0x2070
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2658, 0X2070));
    // 0x80800C7C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800C80: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80800C84: lbu         $s2, 0x3($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X3);
    // 0x80800C88: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800C8C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80800C90: blez        $s2, L_80800CB8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800C94: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800CB8;
    }
    // 0x80800C94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800C98: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_80800C9C:
    // 0x80800C9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800CA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CA4: jal         0x80087CF8
    // 0x80800CA8: lbu         $a2, 0x2($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X2);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80800CA8: lbu         $a2, 0x2($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X2);
    after_0:
    // 0x80800CAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800CB0: bne         $s0, $s2, L_80800C9C
    if (ctx->r16 != ctx->r18) {
        // 0x80800CB4: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_80800C9C;
    }
    // 0x80800CB4: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
L_80800CB8:
    // 0x80800CB8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800CBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800CC0: jal         0x80087DE0
    // 0x80800CC4: lbu         $a1, 0x5($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X5);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_1;
    // 0x80800CC4: lbu         $a1, 0x5($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X5);
    after_1:
    // 0x80800CC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800CCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800CD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800CD4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CD8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800CDC: jr          $ra
    // 0x80800CE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800CE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80804B90_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804B98: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x80804B9C: jal         0x80801658
    // 0x80804BA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801658_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804BA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804BAC: jr          $ra
    // 0x80804BB0: nop

    return;
    // 0x80804BB0: nop

;}
RECOMP_FUNC void bsvan_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808013AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1CFC) << 16);
    // 0x808013B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808013B4: jr          $ra
    // 0x808013B8: lw          $v0, 0x1CFC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CFC));
    return;
    // 0x808013B8: lw          $v0, 0x1CFC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CFC));
;}
RECOMP_FUNC void func_8080079C_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080079C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007A4: sltiu       $at, $a3, 0x6
    ctx->r1 = ctx->r7 < 0X6 ? 1 : 0;
    // 0x808007A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007B0: beq         $at, $zero, L_8080091C
    if (ctx->r1 == 0) {
        // 0x808007B4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8080091C;
    }
    // 0x808007B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007B8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x808007BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1824, 0X1250) << 16);
    // 0x808007C0: addu        $at, $at, $t6
    gpr jr_addend_808007C8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808007C4: lw          $t6, 0x1250($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1824, 0X1250));
    // 0x808007C8: jr          $t6
    // 0x808007CC: nop

    switch (jr_addend_808007C8 >> 2) {
        case 0: goto L_80800898; break;
        case 1: goto L_8080091C; break;
        case 2: goto L_808008DC; break;
        case 3: goto L_80800880; break;
        case 4: goto L_808007D0; break;
        case 5: goto L_808008AC; break;
        default: switch_error(__func__, 0x808007C8, 0x80801250);
    }
    // 0x808007CC: nop

L_808007D0:
    // 0x808007D0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x808007D4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x808007D8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x808007DC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808007E0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808007E4: lw          $t9, 0x14F4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x808007E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x808007EC: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x808007F0: jal         0x800FCF50
    // 0x808007F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800FCF50(rdram, ctx);
        goto after_0;
    // 0x808007F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808007F8: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x808007FC: nop
    
            goto L_80800870;
    }
    // 0x808007FC: nop

    // 0x80800800: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800804: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800808: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x8080080C: bltzl       $t4, L_80800920
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800810: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800920;
    }
    goto skip_0;
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800814: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x80800818: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080081C: beql        $a1, $t5, L_80800920
    if (ctx->r5 == ctx->r13) {
        // 0x80800820: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800920;
    }
    goto skip_1;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800824: jal         0x80087D70
    // 0x80800828: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_27(rdram, ctx);
        goto after_1;
    // 0x80800828: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8080082C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80800830: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800834: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800838: beql        $a1, $at, L_8080084C
    if (ctx->r5 == ctx->r1) {
        // 0x8080083C: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_8080084C;
    }
    goto skip_2;
    // 0x8080083C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800840: jal         0x80087D70
    // 0x80800844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcnewoption_entrypoint_27(rdram, ctx);
        goto after_2;
    // 0x80800844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800848: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
L_8080084C:
    // 0x8080084C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x80800858: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080085C: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x80800860: jal         0x80800610
    // 0x80800864: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    func_80800610_chmusicmenu(rdram, ctx);
        goto after_3;
    // 0x80800864: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    after_3:
    // 0x80800868: b           L_80800920
    // 0x8080086C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x8080086C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800870:
    // 0x80800870: jal         0x800FC660
    // 0x80800874: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x80800874: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x80800878: b           L_80800920
    // 0x8080087C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x8080087C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800880:
    // 0x80800880: sw          $a2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r6;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: jal         0x80800930
    // 0x8080088C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_5;
    // 0x8080088C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800890: b           L_80800920
    // 0x80800894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x80800894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800898:
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: jal         0x8080021C
    // 0x808008A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8080021C_chmusicmenu(rdram, ctx);
        goto after_6;
    // 0x808008A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808008A4: b           L_80800920
    // 0x808008A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x808008A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008AC:
    // 0x808008AC: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B4: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x808008B8: bltzl       $t1, L_80800920
    if (SIGNED(ctx->r9) < 0) {
        // 0x808008BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800920;
    }
    goto skip_3;
    // 0x808008BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808008C0: jal         0x80100094
    // 0x808008C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808008C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808008C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008CC: jal         0x80087DC0
    // 0x808008D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_8;
    // 0x808008D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808008D4: b           L_80800920
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008DC:
    // 0x808008DC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808008E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x808008EC: beq         $t2, $at, L_80800904
    if (ctx->r10 == ctx->r1) {
        // 0x808008F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800904;
    }
    // 0x808008F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008F4: beq         $t2, $at, L_80800914
    if (ctx->r10 == ctx->r1) {
        // 0x808008F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800914;
    }
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008FC: b           L_80800920
    // 0x80800900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x80800900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800904:
    // 0x80800904: jal         0x80800930
    // 0x80800908: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_9;
    // 0x80800908: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8080090C: b           L_80800920
    // 0x80800910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800920;
    // 0x80800910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800914:
    // 0x80800914: jal         0x80800930
    // 0x80800918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_10;
    // 0x80800918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_8080091C:
    // 0x8080091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800920:
    // 0x80800920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800924: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ED00: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8002ED04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002ED08: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8002ED0C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8002ED10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002ED14: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002ED18: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8002ED1C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8002ED20: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8002ED24:
    // 0x8002ED24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002ED28: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8002ED2C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8002ED30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002ED34: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002ED38: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002ED3C: beq         $a0, $t3, L_8002EDA4
    if (ctx->r4 == ctx->r11) {
        // 0x8002ED40: nop
    
            goto L_8002EDA4;
    }
    // 0x8002ED40: nop

L_8002ED44:
    // 0x8002ED44: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002ED48: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002ED4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002ED50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002ED54: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002ED58: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002ED5C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8002ED60: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8002ED64: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002ED68: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002ED6C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8002ED70: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8002ED74: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8002ED78: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002ED7C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8002ED80: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8002ED84: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8002ED88: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002ED8C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8002ED90: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8002ED94: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002ED98: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002ED9C: bne         $a0, $t3, L_8002ED44
    if (ctx->r4 != ctx->r11) {
        // 0x8002EDA0: nop
    
            goto L_8002ED44;
    }
    // 0x8002EDA0: nop

L_8002EDA4:
    // 0x8002EDA4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002EDA8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002EDAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002EDB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002EDB4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002EDB8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8002EDBC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8002EDC0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002EDC4: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002EDC8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8002EDCC: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8002EDD0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8002EDD4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002EDD8: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8002EDDC: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8002EDE0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8002EDE4: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002EDE8: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8002EDEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002EDF0: bne         $a2, $t4, L_8002ED24
    if (ctx->r6 != ctx->r12) {
        // 0x8002EDF4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002ED24;
    }
    // 0x8002EDF4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8002EDF8: jr          $ra
    // 0x8002EDFC: nop

    return;
    // 0x8002EDFC: nop

;}
RECOMP_FUNC void func_800CD230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD230: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CD234: jr          $ra
    // 0x800CD238: swc1        $f12, -0x4FF0($at)
    MEM_W(-0X4FF0, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800CD238: swc1        $f12, -0x4FF0($at)
    MEM_W(-0X4FF0, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808003D0_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808003D8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808003DC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x808003E0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x808003E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808003E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808003EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003F4: jal         0x80100094
    // 0x808003F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003FC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800400: jal         0x800883A8
    // 0x80800404: addiu       $s5, $v0, 0x14
    ctx->r21 = ADD32(ctx->r2, 0X14);
    _gcstatusDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800404: addiu       $s5, $v0, 0x14
    ctx->r21 = ADD32(ctx->r2, 0X14);
    after_1:
    // 0x80800408: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8080040C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800410: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800414: blez        $t6, L_80800464
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800418: nop
    
            goto L_80800464;
    }
    // 0x80800418: nop

L_8080041C:
    // 0x8080041C: jal         0x800F53D0
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800424: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800428: jal         0x80088378
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800430: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800438: jal         0x800842A8
    // 0x8080043C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    _bsfirstp_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080043C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x80800440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800448: jal         0x800842B0
    // 0x8080044C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _bsfirstp_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x8080044C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80800450: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80800454: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800458: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080045C: bne         $at, $zero, L_8080041C
    if (ctx->r1 != 0) {
        // 0x80800460: nop
    
            goto L_8080041C;
    }
    // 0x80800460: nop

L_80800464:
    // 0x80800464: jal         0x80089980
    // 0x80800468: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800468: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x8080046C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800474: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800478: jal         0x80089988
    // 0x8080047C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080047C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80800480: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800484: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800488: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080048C: jal         0x80089988
    // 0x80800490: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800490: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80800494: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800498: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080049C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808004A0: jal         0x80089988
    // 0x808004A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808004A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x808004A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808004B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808004B4: jal         0x80089988
    // 0x808004B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808004B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x808004BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808004C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004C8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808004CC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808004D4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808004D8: jr          $ra
    // 0x808004DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808004DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8008A990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A998: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8008A99C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A9A0: sll         $t6, $v0, 27
    ctx->r14 = S32(ctx->r2 << 27);
    // 0x8008A9A4: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x8008A9A8: beq         $t7, $zero, L_8008A9C8
    if (ctx->r15 == 0) {
        // 0x8008A9AC: nop
    
            goto L_8008A9C8;
    }
    // 0x8008A9AC: nop

    // 0x8008A9B0: beq         $t7, $at, L_8008A9D8
    if (ctx->r15 == ctx->r1) {
        // 0x8008A9B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008A9D8;
    }
    // 0x8008A9B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A9B8: beq         $t7, $at, L_8008A9E4
    if (ctx->r15 == ctx->r1) {
        // 0x8008A9BC: nop
    
            goto L_8008A9E4;
    }
    // 0x8008A9BC: nop

    // 0x8008A9C0: b           L_8008A9F4
    // 0x8008A9C4: nop

        goto L_8008A9F4;
    // 0x8008A9C4: nop

L_8008A9C8:
    // 0x8008A9C8: jal         0x800D8FF8
    // 0x8008A9CC: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8008A9CC: nop

    after_0:
    // 0x8008A9D0: b           L_8008AA00
    // 0x8008A9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008AA00;
    // 0x8008A9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A9D8:
    // 0x8008A9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9DC: b           L_8008A9FC
    // 0x8008A9E0: lwc1        $f0, 0x4A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4A90);
        goto L_8008A9FC;
    // 0x8008A9E0: lwc1        $f0, 0x4A90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4A90);
L_8008A9E4:
    // 0x8008A9E4: jal         0x800885F8
    // 0x8008A9E8: nop

    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8008A9E8: nop

    after_1:
    // 0x8008A9EC: b           L_8008AA00
    // 0x8008A9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008AA00;
    // 0x8008A9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A9F4:
    // 0x8008A9F4: jal         0x800D8FF8
    // 0x8008A9F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8008A9F8: nop

    after_2:
L_8008A9FC:
    // 0x8008A9FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008AA00:
    // 0x8008AA00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AA04: jr          $ra
    // 0x8008AA08: nop

    return;
    // 0x8008AA08: nop

;}
RECOMP_FUNC void func_8008E260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008E264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E268: jal         0x8008E078
    // 0x8008E26C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    player_isStable(rdram, ctx);
        goto after_0;
    // 0x8008E26C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E270: beq         $v0, $zero, L_8008E280
    if (ctx->r2 == 0) {
        // 0x8008E274: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008E280;
    }
    // 0x8008E274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008E278: b           L_8008E29C
    // 0x8008E27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E29C;
    // 0x8008E27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E280:
    // 0x8008E280: jal         0x800954E8
    // 0x8008E284: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800954E8(rdram, ctx);
        goto after_1;
    // 0x8008E284: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8008E288: bnel        $v0, $zero, L_8008E29C
    if (ctx->r2 != 0) {
        // 0x8008E28C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008E29C;
    }
    goto skip_0;
    // 0x8008E28C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8008E290: b           L_8008E29C
    // 0x8008E294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E29C;
    // 0x8008E294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E29C:
    // 0x8008E29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E2A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008E2A4: jr          $ra
    // 0x8008E2A8: nop

    return;
    // 0x8008E2A8: nop

;}
RECOMP_FUNC void chjinjovillagecamera1_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800460: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2028, 0X494) << 16);
    // 0x80800464: jr          $ra
    // 0x80800468: addiu       $v0, $v0, 0x494
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2028, 0X494));
    return;
    // 0x80800468: addiu       $v0, $v0, 0x494
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2028, 0X494));
    // 0x8080046C: nop

;}
RECOMP_FUNC void _rtlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089098: syscall     760
    recomp_syscall_handler(rdram, ctx, 0x80089098);
    return;
    // 0x8008909C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808006D0_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006E0: beq         $a1, $zero, L_8080075C
    if (ctx->r5 == 0) {
        // 0x808006E4: sw          $a1, 0x160($a0)
        MEM_W(0X160, ctx->r4) = ctx->r5;
            goto L_8080075C;
    }
    // 0x808006E4: sw          $a1, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r5;
    // 0x808006E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006EC: beq         $a1, $at, L_80800708
    if (ctx->r5 == ctx->r1) {
        // 0x808006F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800708;
    }
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006F8: beq         $a1, $at, L_80800724
    if (ctx->r5 == ctx->r1) {
        // 0x808006FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800724;
    }
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: b           L_80800788
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800788;
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800708:
    // 0x80800708: jal         0x80084CE8
    // 0x8080070C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080070C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800710: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800714: jal         0x800F817C
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F817C(rdram, ctx);
        goto after_1;
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080071C: b           L_80800788
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800788;
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800724:
    // 0x80800724: jal         0x80084CC0
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800734: jal         0x80084CD0
    // 0x80800738: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800738: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: jal         0x80084CE8
    // 0x80800744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800744: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: jal         0x80095760
    // 0x80800750: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x80800750: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_5:
    // 0x80800754: b           L_80800788
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800788;
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080075C:
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800760: jal         0x80084CE8
    // 0x80800764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x80800764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800770: jal         0x80084CD0
    // 0x80800774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _bafpctrl_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800774: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080077C: jal         0x80095774
    // 0x80800780: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x80800780: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_8:
    // 0x80800784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800788:
    // 0x80800788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080078C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800790: jr          $ra
    // 0x80800794: nop

    return;
    // 0x80800794: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6D0: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6D0);
    return;
    // 0x8008A6D4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chsignpost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B50: syscall     421
    recomp_syscall_handler(rdram, ctx, 0x80086B50);
    return;
    // 0x80086B54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CAA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAA00: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800CAA04: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800CAA08: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800CAA0C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800CAA10: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800CAA14: jr          $ra
    // 0x800CAA18: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    return;
    // 0x800CAA18: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80800050_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800054: jr          $ra
    // 0x80800058: swc1        $f4, 0x170($a0)
    MEM_W(0X170, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800058: swc1        $f4, 0x170($a0)
    MEM_W(0X170, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80800034_chdiggergroundgen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: jal         0x80100094
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800048: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800054: lhu         $v1, 0x72($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X72);
    // 0x80800058: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080005C: beq         $t6, $at, L_80800074
    if (ctx->r14 == ctx->r1) {
        // 0x80800060: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800074;
    }
    // 0x80800060: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800064: beq         $t6, $at, L_80800094
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: nop
    
            goto L_80800094;
    }
    // 0x80800068: nop

    // 0x8080006C: b           L_808000A0
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A0;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: jal         0x8008A040
    // 0x80800078: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800078: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080007C: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x80800080: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080009C;
    }
    // 0x80800080: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: jal         0x80800118
    // 0x80800088: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800118_chdiggergroundgen(rdram, ctx);
        goto after_2;
    // 0x80800088: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8080008C: b           L_808000A0
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A0;
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800094:
    // 0x80800094: jal         0x8080035C
    // 0x80800098: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8080035C_chdiggergroundgen(rdram, ctx);
        goto after_3;
    // 0x80800098: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_8080009C:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A0:
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_808008F4_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800900: jal         0x80800824
    // 0x80800904: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800824_chfiregen(rdram, ctx);
        goto after_0;
    // 0x80800904: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080090C: jal         0x800DA3B8
    // 0x80800910: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x80800910: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800914: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800918: beql        $t6, $zero, L_8080096C
    if (ctx->r14 == 0) {
        // 0x8080091C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080096C;
    }
    goto skip_0;
    // 0x8080091C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800920: jal         0x800DA298
    // 0x80800924: addiu       $a0, $zero, 0x678
    ctx->r4 = ADD32(0, 0X678);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800924: addiu       $a0, $zero, 0x678
    ctx->r4 = ADD32(0, 0X678);
    after_2:
    // 0x80800928: bnel        $v0, $zero, L_8080096C
    if (ctx->r2 != 0) {
        // 0x8080092C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080096C;
    }
    goto skip_1;
    // 0x8080092C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800930: jal         0x80800890
    // 0x80800934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800890_chfiregen(rdram, ctx);
        goto after_3;
    // 0x80800934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080093C: beq         $v0, $at, L_80800968
    if (ctx->r2 == ctx->r1) {
        // 0x80800940: addiu       $a0, $zero, 0x678
        ctx->r4 = ADD32(0, 0X678);
            goto L_80800968;
    }
    // 0x80800940: addiu       $a0, $zero, 0x678
    ctx->r4 = ADD32(0, 0X678);
    // 0x80800944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800948: jal         0x800DA3B8
    // 0x8080094C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA3B8(rdram, ctx);
        goto after_4;
    // 0x8080094C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800950: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800954: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080095C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800960: jal         0x80085708
    // 0x80800964: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800964: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_5:
L_80800968:
    // 0x80800968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080096C:
    // 0x8080096C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800970: jr          $ra
    // 0x80800974: nop

    return;
    // 0x80800974: nop

;}
RECOMP_FUNC void func_80800BD8_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE0: jal         0x80085158
    // 0x80800BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BEC: jal         0x800852F0
    // 0x80800BF0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _batimer_decrement(rdram, ctx);
        goto after_1;
    // 0x80800BF0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80800BF4: beq         $v0, $zero, L_80800C0C
    if (ctx->r2 == 0) {
        // 0x80800BF8: addiu       $a0, $zero, 0x2C4
        ctx->r4 = ADD32(0, 0X2C4);
            goto L_80800C0C;
    }
    // 0x80800BF8: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80800BFC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800C00: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80800C04: jal         0x80101180
    // 0x80800C08: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800C08: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    after_2:
L_80800C0C:
    // 0x80800C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C14: jr          $ra
    // 0x80800C18: nop

    return;
    // 0x80800C18: nop

;}
RECOMP_FUNC void func_8080000C_chdiggerbossdeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    // 0x80800010: sh          $v0, 0x62($a0)
    MEM_H(0X62, ctx->r4) = ctx->r2;
    // 0x80800014: sh          $v0, 0x6A($a0)
    MEM_H(0X6A, ctx->r4) = ctx->r2;
    // 0x80800018: jr          $ra
    // 0x8080001C: sh          $v0, 0x68($a0)
    MEM_H(0X68, ctx->r4) = ctx->r2;
    return;
    // 0x8080001C: sh          $v0, 0x68($a0)
    MEM_H(0X68, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void _chchuffy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C20: syscall     432
    recomp_syscall_handler(rdram, ctx, 0x80086C20);
    return;
    // 0x80086C24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808009C0_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C8: addiu       $a0, $zero, 0x42D
    ctx->r4 = ADD32(0, 0X42D);
    // 0x808009CC: jal         0x800DA564
    // 0x808009D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808009D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x808009D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009DC: jr          $ra
    // 0x808009E0: nop

    return;
    // 0x808009E0: nop

;}
RECOMP_FUNC void func_8080000C_chidgoldhorde(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x80800024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800028: jal         0x800BEA88
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800BEA88(rdram, ctx);
        goto after_1;
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800030: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800034: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080003C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800040: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80800044: jal         0x80088890
    // 0x80800048: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    _glidmake_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800048: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    after_2:
    // 0x8080004C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800050: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(736, 0X1E0) << 16);
    // 0x80800054: sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // 0x80800058: lwc1        $f6, 0x1E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X1E0));
    // 0x8080005C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800060: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800064: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80800068: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x8080006C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800070: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void dbvtxnormal_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: jal         0x800B2840
    // 0x80800038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800B2840(rdram, ctx);
        goto after_0;
    // 0x80800038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080003C: jal         0x800B2344
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2344(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800044: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80800048: jal         0x8001ACCC
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800054: jal         0x800B27A0
    // 0x80800058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800B27A0(rdram, ctx);
        goto after_3;
    // 0x80800058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080005C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800060: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800064: jal         0x8001BBC8
    // 0x80800068: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    aligned4_memcpy(rdram, ctx);
        goto after_4;
    // 0x80800068: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A750: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A750);
    return;
    // 0x8008A754: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void _chfactorysparkroom_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087650: syscall     601
    recomp_syscall_handler(rdram, ctx, 0x80087650);
    return;
    // 0x80087654: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bashake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FD0: syscall     147
    recomp_syscall_handler(rdram, ctx, 0x80084FD0);
    return;
    // 0x80084FD4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800BF340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF340: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800BF344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF348: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800BF34C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BF350: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800BF354: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800BF358: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800BF35C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800BF360: jal         0x800EE7F8
    // 0x800BF364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800BF364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800BF368: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800BF36C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BF370: jal         0x800EFB24
    // 0x800BF374: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800BF374: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800BF378: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800BF37C: jal         0x800EF368
    // 0x800BF380: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x800BF380: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x800BF384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BF388: jal         0x800EF04C
    // 0x800BF38C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800BF38C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800BF390: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800BF394: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BF398: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800BF39C: jal         0x800BEF00
    // 0x800BF3A0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x800BF3A0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x800BF3A4: bne         $v0, $zero, L_800BF3B4
    if (ctx->r2 != 0) {
        // 0x800BF3A8: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_800BF3B4;
    }
    // 0x800BF3A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BF3AC: b           L_800BF3D0
    // 0x800BF3B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BF3D0;
    // 0x800BF3B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF3B4:
    // 0x800BF3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BF3B8: jal         0x800EF3DC
    // 0x800BF3BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF3DC(rdram, ctx);
        goto after_5;
    // 0x800BF3BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800BF3C0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800BF3C4: jal         0x800EE7F8
    // 0x800BF3C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x800BF3C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800BF3CC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800BF3D0:
    // 0x800BF3D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF3D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BF3D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800BF3DC: jr          $ra
    // 0x800BF3E0: nop

    return;
    // 0x800BF3E0: nop

;}
RECOMP_FUNC void badust_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800B39E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B39E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B39EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B39F0: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800B39F4: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x800B39F8: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800B39FC: beq         $t6, $zero, L_800B3A2C
    if (ctx->r14 == 0) {
        // 0x800B3A00: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800B3A2C;
    }
    // 0x800B3A00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B3A04: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800B3A08: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x800B3A0C: jal         0x800B39D0
    // 0x800B3A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B3A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800B3A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3A18: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800B3A1C: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B3A20: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B3A24: b           L_800B3A30
    // 0x800B3A28: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
        goto L_800B3A30;
    // 0x800B3A28: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_800B3A2C:
    // 0x800B3A2C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
L_800B3A30:
    // 0x800B3A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3A38: jr          $ra
    // 0x800B3A3C: nop

    return;
    // 0x800B3A3C: nop

;}
RECOMP_FUNC void bsturn_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: jal         0x8009C984
    // 0x808002EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x808002EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808002F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002F8: jal         0x800136E4
    // 0x808002FC: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x808002FC: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_1:
    // 0x80800300: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800304: jal         0x8009C944
    // 0x80800308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    yaw_set(rdram, ctx);
        goto after_2;
    // 0x80800308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080030C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800310: jal         0x8009BF5C
    // 0x80800314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_3;
    // 0x80800314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800318: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080031C: jal         0x8009C4CC
    // 0x80800320: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_4;
    // 0x80800320: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080032C: jr          $ra
    // 0x80800330: nop

    return;
    // 0x80800330: nop

;}
RECOMP_FUNC void _babuzz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847B0: syscall     120
    recomp_syscall_handler(rdram, ctx, 0x800847B0);
    return;
    // 0x800847B4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80094C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094C14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80094C18: jal         0x80094348
    // 0x80094C1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80094348(rdram, ctx);
        goto after_0;
    // 0x80094C1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80094C20: bne         $v0, $zero, L_80094C54
    if (ctx->r2 != 0) {
        // 0x80094C24: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80094C54;
    }
    // 0x80094C24: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80094C28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80094C2C: bne         $t6, $at, L_80094C44
    if (ctx->r14 != ctx->r1) {
        // 0x80094C30: nop
    
            goto L_80094C44;
    }
    // 0x80094C30: nop

    // 0x80094C34: jal         0x8009EA2C
    // 0x80094C38: nop

    func_8009EA2C(rdram, ctx);
        goto after_1;
    // 0x80094C38: nop

    after_1:
    // 0x80094C3C: bnel        $v0, $zero, L_80094C58
    if (ctx->r2 != 0) {
        // 0x80094C40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80094C58;
    }
    goto skip_0;
    // 0x80094C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80094C44:
    // 0x80094C44: jal         0x800883E0
    // 0x80094C48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80094C48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80094C4C: jal         0x800D1804
    // 0x80094C50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1804(rdram, ctx);
        goto after_3;
    // 0x80094C50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
L_80094C54:
    // 0x80094C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094C58:
    // 0x80094C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094C5C: jr          $ra
    // 0x80094C60: nop

    return;
    // 0x80094C60: nop

;}
RECOMP_FUNC void func_800DB83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB83C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DB840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DB844: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800DB848: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800DB84C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800DB850: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800DB854: jal         0x80088588
    // 0x800DB858: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    _glgamedata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800DB858: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800DB85C: beq         $v0, $zero, L_800DB8A8
    if (ctx->r2 == 0) {
        // 0x800DB860: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_800DB8A8;
    }
    // 0x800DB860: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800DB864: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800DB868: addiu       $a1, $a1, -0xE
    ctx->r5 = ADD32(ctx->r5, -0XE);
    // 0x800DB86C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800DB870: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x800DB874: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800DB878: beq         $at, $zero, L_800DB888
    if (ctx->r1 == 0) {
        // 0x800DB87C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800DB888;
    }
    // 0x800DB87C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800DB880: b           L_800DB8AC
    // 0x800DB884: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800DB8AC;
    // 0x800DB884: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800DB888:
    // 0x800DB888: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800DB88C: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x800DB890: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800DB894: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x800DB898: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x800DB89C: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800DB8A0: b           L_800DB8AC
    // 0x800DB8A4: or          $v0, $t2, $t4
    ctx->r2 = ctx->r10 | ctx->r12;
        goto L_800DB8AC;
    // 0x800DB8A4: or          $v0, $t2, $t4
    ctx->r2 = ctx->r10 | ctx->r12;
L_800DB8A8:
    // 0x800DB8A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800DB8AC:
    // 0x800DB8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DB8B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DB8B4: jr          $ra
    // 0x800DB8B8: nop

    return;
    // 0x800DB8B8: nop

;}
RECOMP_FUNC void func_80800000_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800008: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8080000C: lbu         $s1, 0x762C($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X762C);
    // 0x80800010: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: bne         $s1, $at, L_80800028
    if (ctx->r17 != ctx->r1) {
        // 0x8080001C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80800028;
    }
    // 0x8080001C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800020: b           L_80800078
    // 0x80800024: addiu       $v0, $zero, 0x5B
    ctx->r2 = ADD32(0, 0X5B);
        goto L_80800078;
    // 0x80800024: addiu       $v0, $zero, 0x5B
    ctx->r2 = ADD32(0, 0X5B);
L_80800028:
    // 0x80800028: jal         0x800D0820
    // 0x8080002C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800030: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800034: jal         0x800D0894
    // 0x80800038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080003C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800040: bne         $at, $zero, L_80800074
    if (ctx->r1 != 0) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800048:
    // 0x80800048: jal         0x800D06D4
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D06D4(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800050: bne         $v0, $s1, L_80800060
    if (ctx->r2 != ctx->r17) {
        // 0x80800054: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800060;
    }
    // 0x80800054: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800058: b           L_80800078
    // 0x8080005C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800078;
    // 0x8080005C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800060:
    // 0x80800060: jal         0x800D0894
    // 0x80800064: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D0894(rdram, ctx);
        goto after_3;
    // 0x80800064: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x80800068: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8080006C: beql        $at, $zero, L_80800048
    if (ctx->r1 == 0) {
        // 0x80800070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800048;
    }
    goto skip_0;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800074:
    // 0x80800074: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800078:
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080007C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chskeletonexplode_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800D48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D4C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800D50: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800D54: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800D58: jal         0x800EE904
    // 0x80800D5C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80800D5C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800D60: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800D64: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800D68: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800D6C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80800D70: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80800D74: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800D78: addiu       $a0, $a0, 0x6DE8
    ctx->r4 = ADD32(ctx->r4, 0X6DE8);
    // 0x80800D7C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D80: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800D84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800D88: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800D8C: jal         0x80086D58
    // 0x80800D90: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800D90: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_1:
    // 0x80800D94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D98: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D9C: jr          $ra
    // 0x80800DA0: nop

    return;
    // 0x80800DA0: nop

;}
RECOMP_FUNC void babounce_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x808004FC: jr          $ra
    // 0x80800500: sw          $a1, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r5;
    return;
    // 0x80800500: sw          $a1, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _chburgerstand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D98: syscall     239
    recomp_syscall_handler(rdram, ctx, 0x80085D98);
    return;
    // 0x80085D9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void baswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8009EC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EC64: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, 0X7040);
    // 0x8009EC68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009EC6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8009EC70: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    // 0x8009EC74: jr          $ra
    // 0x8009EC78: sh          $a1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r5;
    return;
    // 0x8009EC78: sh          $a1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void sucoaster_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800D28: jal         0x80100094
    // 0x80800D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D30: jal         0x80107C00
    // 0x80800D34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80107C00(rdram, ctx);
        goto after_1;
    // 0x80800D34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800D38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D3C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800D40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D44: lh          $t6, 0xC($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XC);
    // 0x80800D48: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800D4C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800D50: nop

    // 0x80800D54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800D58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800D5C: nop

    // 0x80800D60: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800D64: nop

    // 0x80800D68: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800D6C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800D70: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80800D74: nop

    // 0x80800D78: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
    // 0x80800D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D84: jr          $ra
    // 0x80800D88: nop

    return;
    // 0x80800D88: nop

;}
RECOMP_FUNC void _baspin_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085150: syscall     152
    recomp_syscall_handler(rdram, ctx, 0x80085150);
    return;
    // 0x80085154: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800618_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080061C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800620: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(948, 0X714) << 16);
    // 0x80800624: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(948, 0X724) << 16);
    // 0x80800628: addiu       $a3, $a3, 0x724
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(948, 0X724));
    // 0x8080062C: addiu       $a2, $a2, 0x714
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(948, 0X714));
    // 0x80800630: jal         0x80089D28
    // 0x80800634: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800634: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080063C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800640: jr          $ra
    // 0x80800644: nop

    return;
    // 0x80800644: nop

    // 0x80800648: nop

    // 0x8080064C: nop

;}
RECOMP_FUNC void func_80800018_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8080001C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800030: jal         0x80100094
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8080003C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800040: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800044: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800050: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800054: jal         0x80102FDC
    // 0x80800058: nop

    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800058: nop

    after_1:
    // 0x8080005C: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800064: jal         0x800EE7F8
    // 0x80800068: addiu       $a0, $s2, 0x104
    ctx->r4 = ADD32(ctx->r18, 0X104);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a0, $s2, 0x104
    ctx->r4 = ADD32(ctx->r18, 0X104);
    after_2:
    // 0x8080006C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800070: sh          $zero, 0x138($s2)
    MEM_H(0X138, ctx->r18) = 0;
    // 0x80800074: sh          $t6, 0x164($s2)
    MEM_H(0X164, ctx->r18) = ctx->r14;
    // 0x80800078: jal         0x800DA524
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800080: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80800084: sb          $t7, 0x5E($s0)
    MEM_B(0X5E, ctx->r16) = ctx->r15;
    // 0x80800088: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8080008C: sh          $t8, 0x11C($s2)
    MEM_H(0X11C, ctx->r18) = ctx->r24;
    // 0x80800090: sh          $zero, 0x138($s2)
    MEM_H(0X138, ctx->r18) = 0;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80109EEC
    // 0x8080009C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_4;
    // 0x8080009C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x80109FE8
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_5;
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808000AC: jal         0x80088848
    // 0x808000B0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x808000B0: nop

    after_6:
    // 0x808000B4: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000CC;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80102424
    // 0x808000C0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808000C0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_7:
    // 0x808000C4: b           L_8080018C
    // 0x808000C8: nop

        goto L_8080018C;
    // 0x808000C8: nop

L_808000CC:
    // 0x808000CC: jal         0x800D395C
    // 0x808000D0: nop

    func_800D395C(rdram, ctx);
        goto after_8;
    // 0x808000D0: nop

    after_8:
    // 0x808000D4: beq         $v0, $zero, L_8080014C
    if (ctx->r2 == 0) {
        // 0x808000D8: nop
    
            goto L_8080014C;
    }
    // 0x808000D8: nop

    // 0x808000DC: jal         0x800DA298
    // 0x808000E0: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808000E0: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    after_9:
    // 0x808000E4: beq         $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080012C;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x808000F4: jal         0x8080248C
    // 0x808000F8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_10;
    // 0x808000F8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_10:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80800F70
    // 0x80800104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_11;
    // 0x80800104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800108: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080010C: addiu       $t9, $zero, 0x57
    ctx->r25 = ADD32(0, 0X57);
    // 0x80800110: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800114: addiu       $a1, $zero, 0x1801
    ctx->r5 = ADD32(0, 0X1801);
    // 0x80800118: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080011C: jal         0x8008A208
    // 0x80800120: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800120: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x80800124: b           L_8080018C
    // 0x80800128: nop

        goto L_8080018C;
    // 0x80800128: nop

L_8080012C:
    // 0x8080012C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80800130: jal         0x8080248C
    // 0x80800134: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_13;
    // 0x80800134: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_13:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x80800F70
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_14;
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800144: b           L_8080018C
    // 0x80800148: nop

        goto L_8080018C;
    // 0x80800148: nop

L_8080014C:
    // 0x8080014C: jal         0x800DA298
    // 0x80800150: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800150: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_15:
    // 0x80800154: beq         $v0, $zero, L_8080018C
    if (ctx->r2 == 0) {
        // 0x80800158: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80101FDC
    // 0x80800160: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x80800160: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_16:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80109EEC
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109EEC(rdram, ctx);
        goto after_17;
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800170: jal         0x80800E2C
    // 0x80800174: nop

    func_80800E2C_chdinoboss(rdram, ctx);
        goto after_18;
    // 0x80800174: nop

    after_18:
    // 0x80800178: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080017C: bne         $v0, $at, L_8080018C
    if (ctx->r2 != ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80101FDC
    // 0x80800188: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x80800188: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_19:
L_8080018C:
    // 0x8080018C: jal         0x800D395C
    // 0x80800190: nop

    func_800D395C(rdram, ctx);
        goto after_20;
    // 0x80800190: nop

    after_20:
    // 0x80800194: bnel        $v0, $zero, L_808001B8
    if (ctx->r2 != 0) {
        // 0x80800198: addiu       $a0, $zero, 0x154
        ctx->r4 = ADD32(0, 0X154);
            goto L_808001B8;
    }
    goto skip_0;
    // 0x80800198: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    skip_0:
    // 0x8080019C: jal         0x80088848
    // 0x808001A0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_21;
    // 0x808001A0: nop

    after_21:
    // 0x808001A4: bnel        $v0, $zero, L_808001B8
    if (ctx->r2 != 0) {
        // 0x808001A8: addiu       $a0, $zero, 0x154
        ctx->r4 = ADD32(0, 0X154);
            goto L_808001B8;
    }
    goto skip_1;
    // 0x808001A8: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    skip_1:
    // 0x808001AC: jal         0x800861A8
    // 0x808001B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chintrotext_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x808001B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x808001B4: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
L_808001B8:
    // 0x808001B8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808001BC: jal         0x800882C0
    // 0x808001C0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_23;
    // 0x808001C0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_23:
    // 0x808001C4: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x808001C8: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x808001CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808001D0: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x808001D4: blez        $t0, L_80800208
    if (SIGNED(ctx->r8) <= 0) {
        // 0x808001D8: addiu       $s1, $sp, 0x40
        ctx->r17 = ADD32(ctx->r29, 0X40);
            goto L_80800208;
    }
    // 0x808001D8: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
L_808001DC:
    // 0x808001DC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x808001E0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x808001E4: jal         0x800EE88C
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE88C(rdram, ctx);
        goto after_24;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808001EC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x808001F0: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x808001F4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808001F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808001FC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800200: bne         $at, $zero, L_808001DC
    if (ctx->r1 != 0) {
        // 0x80800204: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808001DC;
    }
    // 0x80800204: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800208:
    // 0x80800208: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080020C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800214: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800218: jr          $ra
    // 0x8080021C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8080021C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_808012C0_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808012C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808012C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808012CC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x808012D0: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x808012D4: jal         0x800E3980
    // 0x808012D8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x808012D8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x808012DC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808012E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808012E4: nop

    // 0x808012E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808012EC: nop

    // 0x808012F0: bc1fl       L_80801304
    if (!c1cs) {
        // 0x808012F4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80801304;
    }
    goto skip_0;
    // 0x808012F4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_0:
    // 0x808012F8: b           L_80801304
    // 0x808012FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80801304;
    // 0x808012FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801300: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80801304:
    // 0x80801304: jal         0x800DC0C0
    // 0x80801308: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80801308: nop

    after_1:
    // 0x8080130C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801310: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801314: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80801318: nop

    // 0x8080131C: bc1f        L_8080135C
    if (!c1cs) {
        // 0x80801320: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_8080135C;
    }
    // 0x80801320: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80801324: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80801328: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2304, 0X22C8) << 16);
    // 0x8080132C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2304, 0X2240) << 16);
    // 0x80801330: addiu       $t8, $t8, 0x2240
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2304, 0X2240));
    // 0x80801334: addiu       $t7, $t7, 0x22C8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2304, 0X22C8));
    // 0x80801338: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080133C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80801340: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801348: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080134C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801350: jal         0x800BBCB8
    // 0x80801354: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80801354: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80801358: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
L_8080135C:
    // 0x8080135C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801360: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80801364: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80801368: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8080136C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2304, 0X22C8) << 16);
    // 0x80801370: addiu       $t0, $t0, 0x22C8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2304, 0X22C8));
    // 0x80801374: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80801378: bc1f        L_808013EC
    if (!c1cs) {
        // 0x8080137C: addu        $v0, $t9, $t0
        ctx->r2 = ADD32(ctx->r25, ctx->r8);
            goto L_808013EC;
    }
    // 0x8080137C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80801380: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801384: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801388: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080138C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801394: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80801398: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080139C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808013A0: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808013A4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808013A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808013AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808013B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808013B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808013B8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808013BC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x808013C0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808013C4: jal         0x800EFA4C
    // 0x808013C8: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x808013C8: nop

    after_3:
    // 0x808013CC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2304, 0X227C) << 16);
    // 0x808013D0: addiu       $t1, $t1, 0x227C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2304, 0X227C));
    // 0x808013D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808013D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808013DC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808013E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808013E4: jal         0x800BBCB8
    // 0x808013E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808013E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
L_808013EC:
    // 0x808013EC: jal         0x800DC0C0
    // 0x808013F0: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x808013F0: nop

    after_5:
    // 0x808013F4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808013F8: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x808013FC: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x80801400: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801404: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2304, 0X22E0) << 16);
    // 0x80801408: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080140C: addiu       $t3, $t3, 0x22E0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2304, 0X22E0));
    // 0x80801410: bc1f        L_80801440
    if (!c1cs) {
        // 0x80801414: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80801440;
    }
    // 0x80801414: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801418: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2304, 0X2240) << 16);
    // 0x8080141C: addiu       $t4, $t4, 0x2240
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2304, 0X2240));
    // 0x80801420: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801424: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80801428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080142C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801430: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801434: jal         0x800BBCB8
    // 0x80801438: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80801438: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x8080143C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
L_80801440:
    // 0x80801440: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801444: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80801448: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x8080144C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80801450: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2304, 0X22E0) << 16);
    // 0x80801454: addiu       $t6, $t6, 0x22E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2304, 0X22E0));
    // 0x80801458: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8080145C: bc1f        L_808014D0
    if (!c1cs) {
        // 0x80801460: addu        $v0, $t5, $t6
        ctx->r2 = ADD32(ctx->r13, ctx->r14);
            goto L_808014D0;
    }
    // 0x80801460: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80801464: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801468: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080146C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801470: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801478: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080147C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801484: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80801488: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080148C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80801490: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80801494: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801498: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080149C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808014A0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808014A4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808014A8: jal         0x800EFA4C
    // 0x808014AC: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x808014AC: nop

    after_7:
    // 0x808014B0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2304, 0X227C) << 16);
    // 0x808014B4: addiu       $t7, $t7, 0x227C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2304, 0X227C));
    // 0x808014B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808014BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808014C0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808014C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808014C8: jal         0x800BBCB8
    // 0x808014CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_8;
    // 0x808014CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_8:
L_808014D0:
    // 0x808014D0: jal         0x800DC0C0
    // 0x808014D4: nop

    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x808014D4: nop

    after_9:
    // 0x808014D8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808014DC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x808014E0: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x808014E4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808014E8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2304, 0X22F8) << 16);
    // 0x808014EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808014F0: addiu       $t9, $t9, 0x22F8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2304, 0X22F8));
    // 0x808014F4: bc1f        L_80801524
    if (!c1cs) {
        // 0x808014F8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801524;
    }
    // 0x808014F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808014FC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2304, 0X2240) << 16);
    // 0x80801500: addiu       $t0, $t0, 0x2240
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2304, 0X2240));
    // 0x80801504: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801508: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8080150C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801510: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801514: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801518: jal         0x800BBCB8
    // 0x8080151C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_10;
    // 0x8080151C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_10:
    // 0x80801520: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
L_80801524:
    // 0x80801524: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801528: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8080152C: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x80801530: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80801534: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2304, 0X22F8) << 16);
    // 0x80801538: addiu       $t2, $t2, 0x22F8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2304, 0X22F8));
    // 0x8080153C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80801540: bc1f        L_808015B4
    if (!c1cs) {
        // 0x80801544: addu        $v0, $t1, $t2
        ctx->r2 = ADD32(ctx->r9, ctx->r10);
            goto L_808015B4;
    }
    // 0x80801544: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80801548: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080154C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801550: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801554: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801558: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080155C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801560: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801568: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080156C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801570: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801574: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801578: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080157C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801580: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80801584: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80801588: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080158C: jal         0x800EFA4C
    // 0x80801590: nop

    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x80801590: nop

    after_11:
    // 0x80801594: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2304, 0X227C) << 16);
    // 0x80801598: addiu       $t3, $t3, 0x227C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2304, 0X227C));
    // 0x8080159C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808015A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808015A4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808015A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808015AC: jal         0x800BBCB8
    // 0x808015B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x808015B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_12:
L_808015B4:
    // 0x808015B4: jal         0x800DC0C0
    // 0x808015B8: nop

    func_800DC0C0(rdram, ctx);
        goto after_13;
    // 0x808015B8: nop

    after_13:
    // 0x808015BC: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808015C0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x808015C4: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x808015C8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808015CC: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2304, 0X2310) << 16);
    // 0x808015D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808015D4: addiu       $t5, $t5, 0x2310
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2304, 0X2310));
    // 0x808015D8: bc1f        L_80801608
    if (!c1cs) {
        // 0x808015DC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80801608;
    }
    // 0x808015DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808015E0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2304, 0X2240) << 16);
    // 0x808015E4: addiu       $t6, $t6, 0x2240
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2304, 0X2240));
    // 0x808015E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808015EC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x808015F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808015F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808015F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808015FC: jal         0x800BBCB8
    // 0x80801600: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_14;
    // 0x80801600: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_14:
    // 0x80801604: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
L_80801608:
    // 0x80801608: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080160C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80801610: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80801614: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80801618: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2304, 0X2310) << 16);
    // 0x8080161C: addiu       $t8, $t8, 0x2310
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2304, 0X2310));
    // 0x80801620: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801624: bc1f        L_80801698
    if (!c1cs) {
        // 0x80801628: addu        $v0, $t7, $t8
        ctx->r2 = ADD32(ctx->r15, ctx->r24);
            goto L_80801698;
    }
    // 0x80801628: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8080162C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801630: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801634: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801638: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080163C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801640: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801644: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801648: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080164C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80801650: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801654: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801658: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080165C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801660: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801664: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801668: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8080166C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80801670: jal         0x800EFA4C
    // 0x80801674: nop

    func_800EFA4C(rdram, ctx);
        goto after_15;
    // 0x80801674: nop

    after_15:
    // 0x80801678: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2304, 0X227C) << 16);
    // 0x8080167C: addiu       $t9, $t9, 0x227C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2304, 0X227C));
    // 0x80801680: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801684: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801688: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080168C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801690: jal         0x800BBCB8
    // 0x80801694: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_16;
    // 0x80801694: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_16:
L_80801698:
    // 0x80801698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080169C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808016A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808016A4: jr          $ra
    // 0x808016A8: nop

    return;
    // 0x808016A8: nop

;}
RECOMP_FUNC void func_80800008_chtemplebrokendoorpiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800010: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1924, 0X114) << 16);
    // 0x8080001C: addiu       $t7, $t7, 0x114
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1924, 0X114));
    // 0x80800020: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x80800024: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    // 0x80800028: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080002C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800030: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800034: jal         0x800BABB8
    // 0x80800038: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80800038: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080003C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1924, 0X100) << 16);
    // 0x80800040: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800044: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1924, 0X100));
    // 0x80800048: jal         0x80089D18
    // 0x8080004C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080004C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800050: jal         0x800DA544
    // 0x80800054: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    after_2:
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
