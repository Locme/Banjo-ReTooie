#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808002E8_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002EC: bnel        $a1, $at, L_80800300
    if (ctx->r5 != ctx->r1) {
        // 0x808002F0: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_80800300;
    }
    goto skip_0;
    // 0x808002F0: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x808002F4: jr          $ra
    // 0x808002F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808002F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002FC: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_80800300:
    // 0x80800300: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800304: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x80800308: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8080030C: jr          $ra
    // 0x80800310: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800310: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808047E8_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808047E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808047EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808047F0: jal         0x80100094
    // 0x808047F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808047F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808047F8: jal         0x800BD09C
    // 0x808047FC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800BD09C(rdram, ctx);
        goto after_1;
    // 0x808047FC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x80804800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804808: jr          $ra
    // 0x8080480C: nop

    return;
    // 0x8080480C: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(364, 0X720) << 16);
    // 0x808004D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004D4: jr          $ra
    // 0x808004D8: lw          $v0, 0x720($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X720));
    return;
    // 0x808004D8: lw          $v0, 0x720($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X720));
;}
RECOMP_FUNC void func_80800538_chgobihailfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080053C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800540: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800544: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800548: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080054C: jal         0x800DA298
    // 0x80800550: addiu       $a0, $zero, 0x1C6
    ctx->r4 = ADD32(0, 0X1C6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800550: addiu       $a0, $zero, 0x1C6
    ctx->r4 = ADD32(0, 0X1C6);
    after_0:
    // 0x80800554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800558: jal         0x80088840
    // 0x8080055C: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x8080055C: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_1:
    // 0x80800560: jal         0x800EA05C
    // 0x80800564: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800564: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800568: addiu       $at, $zero, 0x127
    ctx->r1 = ADD32(0, 0X127);
    // 0x8080056C: beq         $v0, $at, L_80800584
    if (ctx->r2 == ctx->r1) {
        // 0x80800570: addiu       $at, $zero, 0x129
        ctx->r1 = ADD32(0, 0X129);
            goto L_80800584;
    }
    // 0x80800570: addiu       $at, $zero, 0x129
    ctx->r1 = ADD32(0, 0X129);
    // 0x80800574: beq         $v0, $at, L_80800658
    if (ctx->r2 == ctx->r1) {
        // 0x80800578: nop
    
            goto L_80800658;
    }
    // 0x80800578: nop

    // 0x8080057C: b           L_808006E4
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006E4;
    // 0x80800580: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800584:
    // 0x80800584: jal         0x800DA298
    // 0x80800588: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800588: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_3:
    // 0x8080058C: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800590: beq         $a2, $zero, L_808005B0
    if (ctx->r6 == 0) {
        // 0x80800594: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_808005B0;
    }
    // 0x80800594: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800598: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080059C: beq         $a2, $zero, L_808005B0
    if (ctx->r6 == 0) {
        // 0x808005A0: nop
    
            goto L_808005B0;
    }
    // 0x808005A0: nop

    // 0x808005A4: jal         0x800DB9B0
    // 0x808005A8: nop

    func_800DB9B0(rdram, ctx);
        goto after_4;
    // 0x808005A8: nop

    after_4:
    // 0x808005AC: sltiu       $a2, $v0, 0x1
    ctx->r6 = ctx->r2 < 0X1 ? 1 : 0;
L_808005B0:
    // 0x808005B0: jal         0x80088848
    // 0x808005B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x808005B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x808005B8: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x808005BC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808005D0;
    }
    // 0x808005BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808005C0: jal         0x800FFAB0
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808005C8: b           L_808006E4
    // 0x808005CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006E4;
    // 0x808005CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005D0:
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005D8: jal         0x80102424
    // 0x808005DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808005DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x808005E0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808005E4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808005E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808005EC: beq         $v0, $zero, L_80800604
    if (ctx->r2 == 0) {
        // 0x808005F0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800604;
    }
    // 0x808005F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005F4: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808005F8: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808005FC: b           L_80800610
    // 0x80800600: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80800610;
    // 0x80800600: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80800604:
    // 0x80800604: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800608: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x8080060C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80800610:
    // 0x80800610: bne         $v0, $zero, L_80800620
    if (ctx->r2 != 0) {
        // 0x80800614: nop
    
            goto L_80800620;
    }
    // 0x80800614: nop

    // 0x80800618: beq         $a2, $zero, L_80800648
    if (ctx->r6 == 0) {
        // 0x8080061C: nop
    
            goto L_80800648;
    }
    // 0x8080061C: nop

L_80800620:
    // 0x80800620: beq         $v0, $zero, L_8080062C
    if (ctx->r2 == 0) {
        // 0x80800624: addiu       $a3, $zero, 0x830
        ctx->r7 = ADD32(0, 0X830);
            goto L_8080062C;
    }
    // 0x80800624: addiu       $a3, $zero, 0x830
    ctx->r7 = ADD32(0, 0X830);
    // 0x80800628: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
L_8080062C:
    // 0x8080062C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800630: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800634: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800638: jal         0x80085708
    // 0x8080063C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x8080063C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x80800640: b           L_808006E4
    // 0x80800644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006E4;
    // 0x80800644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800648:
    // 0x80800648: jal         0x800FFAB0
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800650: b           L_808006E4
    // 0x80800654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006E4;
    // 0x80800654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800658:
    // 0x80800658: jal         0x80088848
    // 0x8080065C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_10;
    // 0x8080065C: nop

    after_10:
    // 0x80800660: beq         $v0, $zero, L_80800670
    if (ctx->r2 == 0) {
        // 0x80800664: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80800670;
    }
    // 0x80800664: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800668: b           L_808006E4
    // 0x8080066C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006E4;
    // 0x8080066C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800670:
    // 0x80800670: beq         $t2, $zero, L_808006AC
    if (ctx->r10 == 0) {
        // 0x80800674: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_808006AC;
    }
    // 0x80800674: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x80102424
    // 0x80800680: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800680: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x801056EC
    // 0x8080068C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_801056EC(rdram, ctx);
        goto after_12;
    // 0x8080068C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x80800690: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800698: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080069C: jal         0x80085708
    // 0x808006A0: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    _capod_entrypoint_13(rdram, ctx);
        goto after_13;
    // 0x808006A0: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
    after_13:
    // 0x808006A4: b           L_808006E4
    // 0x808006A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006E4;
    // 0x808006A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006AC:
    // 0x808006AC: beq         $t3, $zero, L_808006D8
    if (ctx->r11 == 0) {
        // 0x808006B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x80102424
    // 0x808006B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x808006B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: jal         0x801056EC
    // 0x808006C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_801056EC(rdram, ctx);
        goto after_15;
    // 0x808006C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_15:
    // 0x808006C8: jal         0x80104E78
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104E78(rdram, ctx);
        goto after_16;
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808006D0: b           L_808006E4
    // 0x808006D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006E4;
    // 0x808006D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006D8:
    // 0x808006D8: jal         0x800FFAB0
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808006E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006E4:
    // 0x808006E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006F0: jr          $ra
    // 0x808006F4: nop

    return;
    // 0x808006F4: nop

    // 0x808006F8: nop

    // 0x808006FC: nop

;}
RECOMP_FUNC void _sucoasterplayer_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A320: syscall     835
    recomp_syscall_handler(rdram, ctx, 0x8008A320);
    return;
    // 0x8008A324: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800FA8_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800FAC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800FB0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800FB4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800FB8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800FBC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800FC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800FC4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800FC8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800FCC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800FD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800FD4: addiu       $s5, $zero, 0x9
    ctx->r21 = ADD32(0, 0X9);
L_80800FD8:
    // 0x80800FD8: jal         0x800D1338
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D1338(rdram, ctx);
        goto after_0;
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800FE0: beq         $v0, $zero, L_80801028
    if (ctx->r2 == 0) {
        // 0x80800FE4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80801028;
    }
    // 0x80800FE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800FE8: jal         0x800D27A4
    // 0x80800FEC: addiu       $a0, $s0, 0xE1
    ctx->r4 = ADD32(ctx->r16, 0XE1);
    func_800D27A4(rdram, ctx);
        goto after_1;
    // 0x80800FEC: addiu       $a0, $s0, 0xE1
    ctx->r4 = ADD32(ctx->r16, 0XE1);
    after_1:
    // 0x80800FF0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800FF4: jal         0x800D129C
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D129C(rdram, ctx);
        goto after_2;
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800FFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801000: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801004: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801008: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080100C: addiu       $a2, $s0, 0x11
    ctx->r6 = ADD32(ctx->r16, 0X11);
    // 0x80801010: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80801014: jal         0x80801844
    // 0x80801018: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    func_80801844_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80801018: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_3:
    // 0x8080101C: beql        $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80801020: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080102C;
    }
    goto skip_0;
    // 0x80801020: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801024: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801028:
    // 0x80801028: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080102C:
    // 0x8080102C: bne         $s0, $s5, L_80800FD8
    if (ctx->r16 != ctx->r21) {
        // 0x80801030: nop
    
            goto L_80800FD8;
    }
    // 0x80801030: nop

    // 0x80801034: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801038: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8080103C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801040: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801044: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801048: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080104C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80801050: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80801054: jr          $ra
    // 0x80801058: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801058: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808010B8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B8: lhu         $t8, 0x6E($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6E);
    // 0x808010BC: andi        $t7, $a1, 0x1FF
    ctx->r15 = ctx->r5 & 0X1FF;
    // 0x808010C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808010C4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808010C8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808010CC: bne         $a1, $at, L_808010E4
    if (ctx->r5 != ctx->r1) {
        // 0x808010D0: sh          $t0, 0x6E($a0)
        MEM_H(0X6E, ctx->r4) = ctx->r8;
            goto L_808010E4;
    }
    // 0x808010D0: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
    // 0x808010D4: lbu         $t2, 0x64($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X64);
    // 0x808010D8: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808010DC: jr          $ra
    // 0x808010E0: sb          $t3, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r11;
    return;
    // 0x808010E0: sb          $t3, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r11;
L_808010E4:
    // 0x808010E4: lbu         $t4, 0x64($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X64);
    // 0x808010E8: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x808010EC: sb          $t5, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r13;
    // 0x808010F0: jr          $ra
    // 0x808010F4: nop

    return;
    // 0x808010F4: nop

;}
RECOMP_FUNC void _bsbeemain_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828A0: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x800828A0);
    return;
    // 0x800828A4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chstatuebossbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086740: syscall     362
    recomp_syscall_handler(rdram, ctx, 0x80086740);
    return;
    // 0x80086744: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808001BC_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001C8: jal         0x80102424
    // 0x808001CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808001CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001D0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808001D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001D8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808001DC: beq         $t6, $at, L_80800204
    if (ctx->r14 == ctx->r1) {
        // 0x808001E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800204;
    }
    // 0x808001E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001E4: beq         $t6, $at, L_80800254
    if (ctx->r14 == ctx->r1) {
        // 0x808001E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800254;
    }
    // 0x808001E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001EC: beq         $t6, $at, L_8080027C
    if (ctx->r14 == ctx->r1) {
        // 0x808001F0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080027C;
    }
    // 0x808001F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808001F4: beq         $t6, $at, L_808002A4
    if (ctx->r14 == ctx->r1) {
        // 0x808001F8: nop
    
            goto L_808002A4;
    }
    // 0x808001F8: nop

    // 0x808001FC: b           L_808002B8
    // 0x80800200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x80800200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800204:
    // 0x80800204: jal         0x800886D8
    // 0x80800208: nop

    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800208: nop

    after_1:
    // 0x8080020C: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800210: lui         $at, 0xC3FA
        ctx->r1 = S32(0XC3FA << 16);
            goto L_80800224;
    }
    // 0x80800210: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80800214: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80800218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080021C: b           L_80800230
    // 0x80800220: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800230;
    // 0x80800220: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800224:
    // 0x80800224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800228: nop

    // 0x8080022C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800230:
    // 0x80800230: jal         0x800FC660
    // 0x80800234: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x80800234: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x80800238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080023C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x8080012C
    // 0x80800248: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    func_8080012C_chquizremotectrl(rdram, ctx);
        goto after_3;
    // 0x80800248: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8080024C: b           L_808002B8
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800254:
    // 0x80800254: jal         0x800FC74C
    // 0x80800258: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800FC74C(rdram, ctx);
        goto after_4;
    // 0x80800258: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_4:
    // 0x8080025C: jal         0x8008A7F8
    // 0x80800260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _suquiz_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800264: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x80800000
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chquizremotectrl(rdram, ctx);
        goto after_6;
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800274: b           L_808002B8
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080027C:
    // 0x8080027C: jal         0x800FC660
    // 0x80800280: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800FC660(rdram, ctx);
        goto after_7;
    // 0x80800280: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_7:
    // 0x80800284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800288: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800294: jal         0x80800000
    // 0x80800298: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    func_80800000_chquizremotectrl(rdram, ctx);
        goto after_8;
    // 0x80800298: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x8080029C: b           L_808002B8
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002B8;
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A4:
    // 0x808002A4: jal         0x800FC74C
    // 0x808002A8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800FC74C(rdram, ctx);
        goto after_9;
    // 0x808002A8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_9:
    // 0x808002AC: jal         0x8008A880
    // 0x808002B0: nop

    _suquiz_entrypoint_25(rdram, ctx);
        goto after_10;
    // 0x808002B0: nop

    after_10:
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B8:
    // 0x808002B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void glglobalsettings_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004F4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2754, 0X560) << 16);
    // 0x808004F8: addiu       $t8, $t8, 0x560
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2754, 0X560));
    // 0x808004FC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80800500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800508: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8080050C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80800510: jal         0x80012F0C
    // 0x80800514: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80012F0C(rdram, ctx);
        goto after_0;
    // 0x80800514: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80800518: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8080051C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800520: jal         0x80012F34
    // 0x80800524: lh          $a1, 0x2($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X2);
    func_80012F34(rdram, ctx);
        goto after_1;
    // 0x80800524: lh          $a1, 0x2($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X2);
    after_1:
    // 0x80800528: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8080052C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800530: jal         0x80012F34
    // 0x80800534: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    func_80012F34(rdram, ctx);
        goto after_2;
    // 0x80800534: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    after_2:
    // 0x80800538: addiu       $a0, $zero, 0xBC6
    ctx->r4 = ADD32(0, 0XBC6);
    // 0x8080053C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800540: jal         0x800DA7A8
    // 0x80800544: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x80800544: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80800548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080054C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800550: jr          $ra
    // 0x80800554: nop

    return;
    // 0x80800554: nop

    // 0x80800558: nop

    // 0x8080055C: nop

;}
RECOMP_FUNC void func_80800EB4_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800EB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800EBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800EC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EC4: jal         0x8008CABC
    // 0x80800EC8: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800EC8: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x80800ECC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800ED0: jal         0x80084C20
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800ED8: jal         0x8009DDDC
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009DDDC(rdram, ctx);
        goto after_2;
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800EE0: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80800EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EE8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800EEC: beq         $v0, $at, L_80800F10
    if (ctx->r2 == ctx->r1) {
        // 0x80800EF0: lui         $a1, 0x3F30
        ctx->r5 = S32(0X3F30 << 16);
            goto L_80800F10;
    }
    // 0x80800EF0: lui         $a1, 0x3F30
    ctx->r5 = S32(0X3F30 << 16);
    // 0x80800EF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800EF8: beq         $v0, $at, L_80800F30
    if (ctx->r2 == ctx->r1) {
        // 0x80800EFC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F30;
    }
    // 0x80800EFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F00: beq         $v0, $at, L_80801034
    if (ctx->r2 == ctx->r1) {
        // 0x80800F04: nop
    
            goto L_80801034;
    }
    // 0x80800F04: nop

    // 0x80800F08: b           L_808010C0
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010C0;
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F10:
    // 0x80800F10: jal         0x8008B348
    // 0x80800F14: ori         $a1, $a1, 0xC49C
    ctx->r5 = ctx->r5 | 0XC49C;
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800F14: ori         $a1, $a1, 0xC49C
    ctx->r5 = ctx->r5 | 0XC49C;
    after_3:
    // 0x80800F18: beq         $v0, $zero, L_808010BC
    if (ctx->r2 == 0) {
        // 0x80800F1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010BC;
    }
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F20: jal         0x808009C8
    // 0x80800F24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808009C8_bskazfly(rdram, ctx);
        goto after_4;
    // 0x80800F24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800F28: b           L_808010C0
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010C0;
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F30:
    // 0x80800F30: jal         0x80800BDC
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BDC_bskazfly(rdram, ctx);
        goto after_5;
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F38: jal         0x8008B324
    // 0x80800F3C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800F3C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x80800F40: beq         $v0, $zero, L_80800F74
    if (ctx->r2 == 0) {
        // 0x80800F44: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800F74;
    }
    // 0x80800F44: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800F48: jal         0x8008AED4
    // 0x80800F4C: addiu       $a1, $zero, 0x29E
    ctx->r5 = ADD32(0, 0X29E);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x80800F4C: addiu       $a1, $zero, 0x29E
    ctx->r5 = ADD32(0, 0X29E);
    after_7:
    // 0x80800F50: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800F54: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800F58: jal         0x8008B1BC
    // 0x80800F5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x80800F5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x80800F60: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800F64: jal         0x8008B134
    // 0x80800F68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x80800F68: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800F6C: jal         0x8008B064
    // 0x80800F70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_start(rdram, ctx);
        goto after_10;
    // 0x80800F70: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_10:
L_80800F74:
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F78: jal         0x8009C128
    // 0x80800F7C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_11;
    // 0x80800F7C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80800F80: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800F84: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800F88: jal         0x800EF3DC
    // 0x80800F8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF3DC(rdram, ctx);
        goto after_12;
    // 0x80800F8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_12:
    // 0x80800F90: jal         0x800EEFD4
    // 0x80800F94: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EEFD4(rdram, ctx);
        goto after_13;
    // 0x80800F94: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x80800F98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(236, 0X1BF8) << 16);
    // 0x80800F9C: lwc1        $f4, 0x1BF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(236, 0X1BF8));
    // 0x80800FA0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800FA4: lui         $a2, 0x4B74
    ctx->r6 = S32(0X4B74 << 16);
    // 0x80800FA8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800FAC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800FB0: ori         $a2, $a2, 0x2400
    ctx->r6 = ctx->r6 | 0X2400;
    // 0x80800FB4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800FB8: jal         0x800F10B4
    // 0x80800FBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80800FBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80800FC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FC4: jal         0x80084BF8
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800FCC: jal         0x800EEFD4
    // 0x80800FD0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EEFD4(rdram, ctx);
        goto after_16;
    // 0x80800FD0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_16:
    // 0x80800FD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(236, 0X1BFC) << 16);
    // 0x80800FD8: lwc1        $f6, 0x1BFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(236, 0X1BFC));
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800FE4: nop

    // 0x80800FE8: bc1f        L_80801018
    if (!c1cs) {
        // 0x80800FEC: nop
    
            goto L_80801018;
    }
    // 0x80800FEC: nop

    // 0x80800FF0: jal         0x800919F4
    // 0x80800FF4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_17;
    // 0x80800FF4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_17:
    // 0x80800FF8: beq         $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x80800FFC: addiu       $t6, $zero, 0x175
        ctx->r14 = ADD32(0, 0X175);
            goto L_80801014;
    }
    // 0x80800FFC: addiu       $t6, $zero, 0x175
    ctx->r14 = ADD32(0, 0X175);
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801004: jal         0x808009C8
    // 0x80801008: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808009C8_bskazfly(rdram, ctx);
        goto after_18;
    // 0x80801008: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x8080100C: b           L_80801018
    // 0x80801010: nop

        goto L_80801018;
    // 0x80801010: nop

L_80801014:
    // 0x80801014: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80801018:
    // 0x80801018: jal         0x80800000
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazfly(rdram, ctx);
        goto after_19;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801024: jal         0x80800D24
    // 0x80801028: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800D24_bskazfly(rdram, ctx);
        goto after_20;
    // 0x80801028: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_20:
    // 0x8080102C: b           L_808010BC
    // 0x80801030: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
        goto L_808010BC;
    // 0x80801030: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_80801034:
    // 0x80801034: jal         0x80800BDC
    // 0x80801038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BDC_bskazfly(rdram, ctx);
        goto after_21;
    // 0x80801038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: jal         0x80091A30
    // 0x80801044: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_released(rdram, ctx);
        goto after_22;
    // 0x80801044: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_22:
    // 0x80801048: beq         $v0, $zero, L_8080105C
    if (ctx->r2 == 0) {
        // 0x8080104C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080105C;
    }
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801050: addiu       $t7, $zero, 0x175
    ctx->r15 = ADD32(0, 0X175);
    // 0x80801054: b           L_808010A4
    // 0x80801058: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
        goto L_808010A4;
    // 0x80801058: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_8080105C:
    // 0x8080105C: jal         0x800852F0
    // 0x80801060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_23;
    // 0x80801060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80801064: beq         $v0, $zero, L_808010A4
    if (ctx->r2 == 0) {
        // 0x80801068: nop
    
            goto L_808010A4;
    }
    // 0x80801068: nop

    // 0x8080106C: jal         0x80084C28
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_12(rdram, ctx);
        goto after_24;
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80801074: beq         $v0, $zero, L_808010A0
    if (ctx->r2 == 0) {
        // 0x80801078: addiu       $t8, $zero, 0x175
        ctx->r24 = ADD32(0, 0X175);
            goto L_808010A0;
    }
    // 0x80801078: addiu       $t8, $zero, 0x175
    ctx->r24 = ADD32(0, 0X175);
    // 0x8080107C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80801080: jal         0x80085948
    // 0x80801084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x80801084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80801088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080108C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801090: jal         0x80085338
    // 0x80801094: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_26;
    // 0x80801094: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_26:
    // 0x80801098: b           L_808010A4
    // 0x8080109C: nop

        goto L_808010A4;
    // 0x8080109C: nop

L_808010A0:
    // 0x808010A0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_808010A4:
    // 0x808010A4: jal         0x80800000
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazfly(rdram, ctx);
        goto after_27;
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B0: jal         0x80800D24
    // 0x808010B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80800D24_bskazfly(rdram, ctx);
        goto after_28;
    // 0x808010B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_28:
    // 0x808010B8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_808010BC:
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808010C0:
    // 0x808010C0: jal         0x8009E5C8
    // 0x808010C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_29;
    // 0x808010C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_29:
    // 0x808010C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808010CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808010D4: jr          $ra
    // 0x808010D8: nop

    return;
    // 0x808010D8: nop

;}
RECOMP_FUNC void func_80800964_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080096C: jal         0x80800090
    // 0x80800970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800090_bskazglide(rdram, ctx);
        goto after_0;
    // 0x80800970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800974: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800978: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080097C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800980: jal         0x8008CB3C
    // 0x80800984: addiu       $a1, $zero, 0x13D
    ctx->r5 = ADD32(0, 0X13D);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800984: addiu       $a1, $zero, 0x13D
    ctx->r5 = ADD32(0, 0X13D);
    after_1:
    // 0x80800988: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8080098C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800998: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080099C: jal         0x8009FFD8
    // 0x808009A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808009A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808009A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009AC: jr          $ra
    // 0x808009B0: nop

    return;
    // 0x808009B0: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E68: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E68);
    return;
    // 0x80089E6C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855C0: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855C0);
    return;
    // 0x800855C4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800D92EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D92EC: jr          $ra
    // 0x800D92F0: nop

    return;
    // 0x800D92F0: nop

;}
RECOMP_FUNC void _badrone_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084880: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084880);
    return;
    // 0x80084884: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_800B56D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B56D0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800B56D4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800B56D8: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x800B56DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800B56E0: addiu       $t7, $t7, 0x7F28
    ctx->r15 = ADD32(ctx->r15, 0X7F28);
    // 0x800B56E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B56E8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800B56EC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800B56F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B56F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B56F8: bne         $a1, $zero, L_800B573C
    if (ctx->r5 != 0) {
        // 0x800B56FC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800B573C;
    }
    // 0x800B56FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B5700: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5704: sb          $a2, 0x7F20($at)
    MEM_B(0X7F20, ctx->r1) = ctx->r6;
    // 0x800B5708: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x800B570C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800B5710: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B5714: jal         0x800B53A4
    // 0x800B5718: srl         $a0, $t8, 22
    ctx->r4 = S32(U32(ctx->r24) >> 22);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x800B5718: srl         $a0, $t8, 22
    ctx->r4 = S32(U32(ctx->r24) >> 22);
    after_0:
    // 0x800B571C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5720: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B5724: jal         0x800B5534
    // 0x800B5728: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    func_800B5534(rdram, ctx);
        goto after_1;
    // 0x800B5728: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    after_1:
    // 0x800B572C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5734: sb          $zero, 0x7F20($at)
    MEM_B(0X7F20, ctx->r1) = 0;
    // 0x800B5738: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
L_800B573C:
    // 0x800B573C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5740: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B5744: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B5748: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B574C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800B5750: jr          $ra
    // 0x800B5754: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x800B5754: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80802648_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802648: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080264C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1608, 0X51C0) << 16);
    // 0x80802650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802654: addiu       $t6, $t6, 0x51C0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1608, 0X51C0));
    // 0x80802658: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080265C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802664: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802668: jal         0x800BBCB8
    // 0x8080266C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x8080266C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x80802670: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1608, 0X5210) << 16);
    // 0x80802674: addiu       $t7, $t7, 0x5210
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1608, 0X5210));
    // 0x80802678: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080267C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802684: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802688: jal         0x800BBCB8
    // 0x8080268C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x8080268C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x80802690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802698: jr          $ra
    // 0x8080269C: nop

    return;
    // 0x8080269C: nop

;}
RECOMP_FUNC void func_8080519C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080519C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808051A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808051A4: jal         0x80082FF0
    // 0x808051A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808051A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808051AC: jal         0x80807C8C
    // 0x808051B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808051B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808051B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808051B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808051BC: jr          $ra
    // 0x808051C0: nop

    return;
    // 0x808051C0: nop

;}
RECOMP_FUNC void bskazow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080014C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(264, 0X2D0) << 16);
    // 0x80800150: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800154: jr          $ra
    // 0x80800158: lw          $v0, 0x2D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(264, 0X2D0));
    return;
    // 0x80800158: lw          $v0, 0x2D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(264, 0X2D0));
;}
RECOMP_FUNC void func_8010B088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010B08C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010B094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B098: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010B09C: jal         0x8010C4AC
    // 0x8010B0A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010C4AC(rdram, ctx);
        goto after_0;
    // 0x8010B0A0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B0A4: jal         0x800D8FF8
    // 0x8010B0A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8010B0A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8010B0AC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010B0B0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8010B0B4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010B0B8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010B0BC: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x8010B0C0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010B0C4: jal         0x800EF1B8
    // 0x8010B0C8: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x8010B0C8: nop

    after_2:
    // 0x8010B0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B0D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010B0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B0D8: jr          $ra
    // 0x8010B0DC: nop

    return;
    // 0x8010B0DC: nop

;}
RECOMP_FUNC void func_808001C0_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808001C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001CC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808001D0: jal         0x80100094
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001DC: jal         0x800B53A4
    // 0x808001E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x808001E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808001E4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x808001E8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808001EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001F0: jal         0x800EE7F8
    // 0x808001F4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808001F4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_2:
    // 0x808001F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808001FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800200: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800204: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800208: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x8080020C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800210: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80800214: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800218: jal         0x800EF214
    // 0x8080021C: nop

    func_800EF214(rdram, ctx);
        goto after_3;
    // 0x8080021C: nop

    after_3:
    // 0x80800220: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1748, 0X2108) << 16);
    // 0x80800224: addiu       $t6, $t6, 0x2108
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1748, 0X2108));
    // 0x80800228: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080022C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800230: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800238: jal         0x800BABB8
    // 0x8080023C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x8080023C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800240: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80800244: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800248: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080024C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800254: lwc1        $f12, 0x38($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80800258: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080025C: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800260: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80800264: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80800268: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080026C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800270: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80800274: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800278: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080027C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800280: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800284: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800288: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8080028C: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80800290: add.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80800294: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800298: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8080029C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808002A0: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x808002A4: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x808002A8: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x808002AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002B0: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808002B4: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x808002B8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808002BC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x808002C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808002C4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x808002C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808002CC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x808002D0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x808002D4: jal         0x800BA994
    // 0x808002D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800BA994(rdram, ctx);
        goto after_5;
    // 0x808002D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x808002DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002E0: jal         0x800BA22C
    // 0x808002E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x808002E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808002E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808002EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002F4: jr          $ra
    // 0x808002F8: nop

    return;
    // 0x808002F8: nop

;}
RECOMP_FUNC void _baeggcursor_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AF8: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AF8);
    return;
    // 0x80084AFC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void baduo_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: jal         0x8008E39C
    // 0x808002E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E39C(rdram, ctx);
        goto after_0;
    // 0x808002E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002E4: beq         $v0, $zero, L_808002F4
    if (ctx->r2 == 0) {
        // 0x808002E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002F4;
    }
    // 0x808002E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002EC: jal         0x80085008
    // 0x808002F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808002F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_808002F4:
    // 0x808002F4: jal         0x800F9A6C
    // 0x808002F8: nop

    func_800F9A6C(rdram, ctx);
        goto after_2;
    // 0x808002F8: nop

    after_2:
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void _suspline_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E00: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089E00);
    return;
    // 0x80089E04: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_808001C8_chgobiwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: jal         0x800897C8
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void func_80804168_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804168: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080416C: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80804170: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80804174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80804178: nop

    // 0x8080417C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80804180: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80804184: swc1        $f16, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f16.u32l;
    // 0x80804188: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080418C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804190: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80804194: nop

    // 0x80804198: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x8080419C: bne         $at, $zero, L_808041CC
    if (ctx->r1 != 0) {
        // 0x808041A0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_808041CC;
    }
    // 0x808041A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x808041A4: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808041AC: nop

    // 0x808041B0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808041B4: swc1        $f6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f6.u32l;
    // 0x808041B8: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041BC: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808041C0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x808041C4: b           L_808041F8
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
        goto L_808041F8;
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041CC:
    // 0x808041CC: bgez        $a0, L_808041F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808041D0: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808041F4;
    }
    // 0x808041D0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041D8: nop

    // 0x808041DC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808041E0: swc1        $f18, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f18.u32l;
    // 0x808041E4: lwc1        $f4, 0xD8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808041EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808041F0: nop

L_808041F4:
    // 0x808041F4: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041F8:
    // 0x808041F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X477C) << 16);
    // 0x808041FC: lwc1        $f10, 0x477C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X477C));
    // 0x80804200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4780) << 16);
    // 0x80804204: lwc1        $f18, 0x4780($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4780));
    // 0x80804208: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8080420C: lwc1        $f6, 0xD0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80804210: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80804214: nop

    // 0x80804218: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080421C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80804220: swc1        $f10, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f10.u32l;
    // 0x80804224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080422C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80804230: jr          $ra
    // 0x80804234: nop

    return;
    // 0x80804234: nop

;}
RECOMP_FUNC void sulights_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080080C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800814: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800818: addiu       $s0, $s0, 0x7EF0
    ctx->r16 = ADD32(ctx->r16, 0X7EF0);
    // 0x8080081C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800820: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800824: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080082C: beq         $a1, $zero, L_80800884
    if (ctx->r5 == 0) {
        // 0x80800830: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80800884;
    }
    // 0x80800830: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800834: jal         0x800B296C
    // 0x80800838: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800838: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080083C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800840: jal         0x800B28C4
    // 0x80800844: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80800844: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800848: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x8080084C: beq         $at, $zero, L_80800884
    if (ctx->r1 == 0) {
        // 0x80800850: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800884;
    }
    // 0x80800850: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800854: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_80800858:
    // 0x80800858: beql        $t6, $zero, L_80800878
    if (ctx->r14 == 0) {
        // 0x8080085C: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_80800878;
    }
    goto skip_0;
    // 0x8080085C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_0:
    // 0x80800860: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x80800864: bnel        $s2, $t7, L_80800878
    if (ctx->r18 != ctx->r15) {
        // 0x80800868: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_80800878;
    }
    goto skip_1;
    // 0x80800868: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    skip_1:
    // 0x8080086C: jal         0x808000D0
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000D0_sulights(rdram, ctx);
        goto after_2;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800874: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
L_80800878:
    // 0x80800878: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8080087C: bnel        $at, $zero, L_80800858
    if (ctx->r1 != 0) {
        // 0x80800880: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_80800858;
    }
    goto skip_2;
    // 0x80800880: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_2:
L_80800884:
    // 0x80800884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080088C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800890: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800894: jr          $ra
    // 0x80800898: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800898: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bstaxi_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: jal         0x808000D4
    // 0x808001B8: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    bstaxi_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    after_0:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void _chfantasyathlete_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876B0: syscall     605
    recomp_syscall_handler(rdram, ctx, 0x800876B0);
    return;
    // 0x800876B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddiezone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7A8: syscall     852
    recomp_syscall_handler(rdram, ctx, 0x8008A7A8);
    return;
    // 0x8008A7AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8008B4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4A8: lbu         $t9, 0x1B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008B4AC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8008B4B0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8008B4B4: andi        $t0, $t9, 0xFFFB
    ctx->r8 = ctx->r25 & 0XFFFB;
    // 0x8008B4B8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8008B4BC: jr          $ra
    // 0x8008B4C0: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
    return;
    // 0x8008B4C0: sb          $t1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80800360_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x80800364: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2348, 0XA50) << 16);
    // 0x80800368: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080036C: addiu       $a1, $a1, 0xA50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2348, 0XA50));
    // 0x80800370: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x80800374: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800378:
    // 0x80800378: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8080037C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80800380: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
    // 0x80800384: lw          $t2, 0x1C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1C);
    // 0x80800388: xor         $t7, $v0, $t6
    ctx->r15 = ctx->r2 ^ ctx->r14;
    // 0x8080038C: sltu        $t7, $zero, $t7
    ctx->r15 = 0 < ctx->r15 ? 1 : 0;
    // 0x80800390: xor         $t9, $v0, $t8
    ctx->r25 = ctx->r2 ^ ctx->r24;
    // 0x80800394: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x80800398: and         $v1, $v1, $t7
    ctx->r3 = ctx->r3 & ctx->r15;
    // 0x8080039C: xor         $t1, $v0, $t0
    ctx->r9 = ctx->r2 ^ ctx->r8;
    // 0x808003A0: sltu        $t1, $zero, $t1
    ctx->r9 = 0 < ctx->r9 ? 1 : 0;
    // 0x808003A4: and         $v1, $v1, $t9
    ctx->r3 = ctx->r3 & ctx->r25;
    // 0x808003A8: xor         $t3, $v0, $t2
    ctx->r11 = ctx->r2 ^ ctx->r10;
    // 0x808003AC: sltu        $t3, $zero, $t3
    ctx->r11 = 0 < ctx->r11 ? 1 : 0;
    // 0x808003B0: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
    // 0x808003B4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x808003B8: bne         $a0, $a1, L_80800378
    if (ctx->r4 != ctx->r5) {
        // 0x808003BC: and         $v1, $v1, $t3
        ctx->r3 = ctx->r3 & ctx->r11;
            goto L_80800378;
    }
    // 0x808003BC: and         $v1, $v1, $t3
    ctx->r3 = ctx->r3 & ctx->r11;
    // 0x808003C0: jr          $ra
    // 0x808003C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808003C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80801EEC_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801EF0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80801EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801EFC: bne         $a1, $at, L_80801F24
    if (ctx->r5 != ctx->r1) {
        // 0x80801F00: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801F24;
    }
    // 0x80801F00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801F04: addiu       $a0, $zero, 0x301
    ctx->r4 = ADD32(0, 0X301);
    // 0x80801F08: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801F0C: jal         0x80101180
    // 0x80801F10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80801F10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80801F14: jal         0x8010A570
    // 0x80801F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80801F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801F1C: b           L_80801F2C
    // 0x80801F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801F2C;
    // 0x80801F20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F24:
    // 0x80801F24: b           L_80801F2C
    // 0x80801F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801F2C;
    // 0x80801F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801F2C:
    // 0x80801F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F34: jr          $ra
    // 0x80801F38: nop

    return;
    // 0x80801F38: nop

;}
RECOMP_FUNC void bsstand_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800BB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BC8: jal         0x8009FFD8
    // 0x80800BCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x80800BCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800BD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD4: jal         0x8009B9B0
    // 0x80800BD8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800BD8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BE4: jr          $ra
    // 0x80800BE8: nop

    return;
    // 0x80800BE8: nop

;}
RECOMP_FUNC void func_80800788_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080078C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800790: jal         0x80082830
    // 0x80800794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800798: jal         0x8009BC6C
    // 0x8080079C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x8080079C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808007A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007A8: jr          $ra
    // 0x808007AC: nop

    return;
    // 0x808007AC: nop

;}
RECOMP_FUNC void func_800A5AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5AB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5AB4: lw          $t6, -0x5E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E44);
    // 0x800A5AB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A5ABC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5AC0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5AC8: lbu         $a0, 0x762C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X762C);
    // 0x800A5ACC: addiu       $a2, $a2, -0x5E50
    ctx->r6 = ADD32(ctx->r6, -0X5E50);
    // 0x800A5AD0: beq         $t6, $zero, L_800A5B04
    if (ctx->r14 == 0) {
        // 0x800A5AD4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A5B04;
    }
    // 0x800A5AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5AD8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A5ADC: addiu       $v0, $t7, -0x5E44
    ctx->r2 = ADD32(ctx->r15, -0X5E44);
    // 0x800A5AE0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_800A5AE4:
    // 0x800A5AE4: bnel        $a0, $v1, L_800A5AF4
    if (ctx->r4 != ctx->r3) {
        // 0x800A5AE8: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800A5AF4;
    }
    goto skip_0;
    // 0x800A5AE8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800A5AEC: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800A5AF0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800A5AF4:
    // 0x800A5AF4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A5AF8: bne         $v1, $zero, L_800A5AE4
    if (ctx->r3 != 0) {
        // 0x800A5AFC: nop
    
            goto L_800A5AE4;
    }
    // 0x800A5AFC: nop

    // 0x800A5B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800A5B04:
    // 0x800A5B04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A5B08: jal         0x800EA05C
    // 0x800A5B0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800A5B0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A5B10: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A5B14: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A5B18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5B1C: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x800A5B20: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800A5B24: beql        $t8, $zero, L_800A5B50
    if (ctx->r24 == 0) {
        // 0x800A5B28: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_800A5B50;
    }
    goto skip_1;
    // 0x800A5B28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    skip_1:
    // 0x800A5B2C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
L_800A5B30:
    // 0x800A5B30: beql        $v0, $a0, L_800A5B50
    if (ctx->r2 == ctx->r4) {
        // 0x800A5B34: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_800A5B50;
    }
    goto skip_2;
    // 0x800A5B34: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    skip_2:
    // 0x800A5B38: lh          $a0, 0xC($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XC);
    // 0x800A5B3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A5B40: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800A5B44: bne         $a0, $zero, L_800A5B30
    if (ctx->r4 != 0) {
        // 0x800A5B48: nop
    
            goto L_800A5B30;
    }
    // 0x800A5B48: nop

    // 0x800A5B4C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
L_800A5B50:
    // 0x800A5B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5B54: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800A5B58: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A5B5C: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x800A5B60: sw          $t0, 0x7100($at)
    MEM_W(0X7100, ctx->r1) = ctx->r8;
    // 0x800A5B64: jr          $ra
    // 0x800A5B68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A5B68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void heap_bytes_used(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AAD8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001AADC: jr          $ra
    // 0x8001AAE0: lw          $v0, -0x8B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X8B0);
    return;
    // 0x8001AAE0: lw          $v0, -0x8B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X8B0);
;}
RECOMP_FUNC void func_808000B4_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C0: jal         0x80800000
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800000_cheel(rdram, ctx);
        goto after_0;
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000D4: jal         0x80801200
    // 0x808000D8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_80801200_cheel(rdram, ctx);
        goto after_1;
    // 0x808000D8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808000DC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808000E0: jal         0x800EE7F8
    // 0x808000E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808000E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x808000E8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808000EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000F0: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000F4: lbu         $t7, 0x73($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X73);
    // 0x808000F8: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x808000FC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800100: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800104: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80800108: sb          $t8, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r24;
    // 0x8080010C: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    // 0x80800110: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_80804C28_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804C28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80804C2C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80804C30: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80804C34: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80804C38: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80804C3C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80804C40: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80804C44: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80804C48: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80804C4C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80804C50: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80804C54: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80804C58: jal         0x80100094
    // 0x80804C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804C60: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80804C64: lui         $s5, 0x8081
    ctx->r21 = S32(RELOC_HI16(1480, 0XA038) << 16);
    // 0x80804C68: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80804C6C: sb          $zero, 0x24($v0)
    MEM_B(0X24, ctx->r2) = 0;
    // 0x80804C70: addiu       $s5, $s5, -0x5FC8
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(1480, 0XA038));
    // 0x80804C74: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80804C78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804C7C: addiu       $s3, $v0, 0x3C
    ctx->r19 = ADD32(ctx->r2, 0X3C);
    // 0x80804C80: addiu       $s4, $s7, 0x4
    ctx->r20 = ADD32(ctx->r23, 0X4);
    // 0x80804C84: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_80804C88:
    // 0x80804C88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80804C8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804C90: jal         0x80805448
    // 0x80804C94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80804C94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80804C98: jal         0x800C8A98
    // 0x80804C9C: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80804C9C: nop

    after_2:
    // 0x80804CA0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80804CA4: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80804CA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804CAC: jal         0x800C8F64
    // 0x80804CB0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80804CB0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80804CB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804CB8: jal         0x800C8D4C
    // 0x80804CBC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_4;
    // 0x80804CBC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80804CC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804CC4: jal         0x800EE7F8
    // 0x80804CC8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80804CC8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x80804CCC: jal         0x800E8714
    // 0x80804CD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E8714(rdram, ctx);
        goto after_6;
    // 0x80804CD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80804CD4: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80804CD8: sb          $v0, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r2;
    // 0x80804CDC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80804CE0: jal         0x800E8830
    // 0x80804CE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800E8830(rdram, ctx);
        goto after_7;
    // 0x80804CE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_7:
    // 0x80804CE8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80804CEC: jal         0x800E8870
    // 0x80804CF0: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800E8870(rdram, ctx);
        goto after_8;
    // 0x80804CF0: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_8:
    // 0x80804CF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80804CF8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80804CFC: bne         $s1, $s6, L_80804C88
    if (ctx->r17 != ctx->r22) {
        // 0x80804D00: addiu       $s3, $s3, 0x1C
        ctx->r19 = ADD32(ctx->r19, 0X1C);
            goto L_80804C88;
    }
    // 0x80804D00: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x80804D04: jal         0x808057D0
    // 0x80804D08: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_808057D0_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80804D08: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x80804D0C: jal         0x808056B8
    // 0x80804D10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_808056B8_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80804D10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x80804D14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80804D18: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80804D1C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80804D20: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80804D24: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80804D28: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80804D2C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80804D30: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80804D34: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80804D38: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80804D3C: jr          $ra
    // 0x80804D40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80804D40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D20: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D20);
    return;
    // 0x80082D24: addi        $t0, $zero, 0xB0
    ctx->r8 = ADD32(0, 0XB0);
;}
RECOMP_FUNC void baattach_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8080007C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80800080: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800084: beq         $t6, $zero, L_80800090
    if (ctx->r14 == 0) {
        // 0x80800088: nop
    
            goto L_80800090;
    }
    // 0x80800088: nop

    // 0x8080008C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80800090:
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void chbounce_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F54: jal         0x80100094
    // 0x80800F58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F58: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800F5C: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x80800F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F68: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x80800F6C: jr          $ra
    // 0x80800F70: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x80800F70: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80806300_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806300: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80806304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806308: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080630C: jal         0x80100094
    // 0x80806310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806314: jal         0x800D8FF8
    // 0x80806318: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80806318: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080631C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80806320: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80806324: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80806328: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x8080632C: bne         $t7, $at, L_8080633C
    if (ctx->r15 != ctx->r1) {
        // 0x80806330: nop
    
            goto L_8080633C;
    }
    // 0x80806330: nop

    // 0x80806334: b           L_808063B8
    // 0x80806338: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808063B8;
    // 0x80806338: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080633C:
    // 0x8080633C: jal         0x80802248
    // 0x80806340: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80806340: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80806344: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80806348: jal         0x8010CD50
    // 0x8080634C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_3;
    // 0x8080634C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80806350: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80806354: lwc1        $f4, 0x48($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X48);
    // 0x80806358: jal         0x800136E4
    // 0x8080635C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8080635C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    after_4:
    // 0x80806360: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80806364: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80806368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080636C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80806370: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80806374: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80806378: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080637C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80806380: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80806384: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80806388: lwc1        $f12, 0x10($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8080638C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80806390: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80806394: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80806398: jal         0x800F1FF0
    // 0x8080639C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_5;
    // 0x8080639C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x808063A0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808063A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808063A8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x808063AC: swc1        $f0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f0.u32l;
    // 0x808063B0: jal         0x800F20BC
    // 0x808063B4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    func_800F20BC(rdram, ctx);
        goto after_6;
    // 0x808063B4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    after_6:
L_808063B8:
    // 0x808063B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808063BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808063C0: jr          $ra
    // 0x808063C4: nop

    return;
    // 0x808063C4: nop

;}
RECOMP_FUNC void func_80800C0C_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C10: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800C14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800C18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C20: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800C24: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800C28: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
L_80800C2C:
    // 0x80800C2C: jal         0x800D3DD0
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3DD0(rdram, ctx);
        goto after_0;
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800C34: beq         $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x80800C38: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800C40;
    }
    // 0x80800C38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800C3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800C40:
    // 0x80800C40: bne         $s0, $s2, L_80800C2C
    if (ctx->r16 != ctx->r18) {
        // 0x80800C44: nop
    
            goto L_80800C2C;
    }
    // 0x80800C44: nop

    // 0x80800C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C4C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800C50: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C58: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800C5C: jr          $ra
    // 0x80800C60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800C60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8011347C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011347C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113484: jal         0x801107F0
    // 0x80113488: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80113488: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    after_0:
    // 0x8011348C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113494: jr          $ra
    // 0x80113498: nop

    return;
    // 0x80113498: nop

;}
RECOMP_FUNC void func_80800D60_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800D64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D6C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800D70: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800D74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D7C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800D80: beq         $t6, $at, L_80800D98
    if (ctx->r14 == ctx->r1) {
        // 0x80800D84: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D98;
    }
    // 0x80800D84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D88: beq         $t6, $at, L_80800E70
    if (ctx->r14 == ctx->r1) {
        // 0x80800D8C: nop
    
            goto L_80800E70;
    }
    // 0x80800D8C: nop

    // 0x80800D90: b           L_80800EE4
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800EE4;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D98:
    // 0x80800D98: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800D9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DA0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800DA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800DA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800DAC: nop

    // 0x80800DB0: bc1f        L_80800DC8
    if (!c1cs) {
        // 0x80800DB4: nop
    
            goto L_80800DC8;
    }
    // 0x80800DB4: nop

    // 0x80800DB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DBC: nop

    // 0x80800DC0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800DC4: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80800DC8:
    // 0x80800DC8: jal         0x80800C58
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C58_chmayafarmer(rdram, ctx);
        goto after_0;
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800DD0: bne         $v0, $zero, L_80800DEC
    if (ctx->r2 != 0) {
        // 0x80800DD4: nop
    
            goto L_80800DEC;
    }
    // 0x80800DD4: nop

    // 0x80800DD8: jal         0x80800D18
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D18_chmayafarmer(rdram, ctx);
        goto after_1;
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE4: jal         0x80102424
    // 0x80800DE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800DE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_80800DEC:
    // 0x80800DEC: jal         0x800DC0C0
    // 0x80800DF0: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x80800DF0: nop

    after_3:
    // 0x80800DF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11C4) << 16);
    // 0x80800DF8: lwc1        $f10, 0x11C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11C4));
    // 0x80800DFC: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x80800E00: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800E04: nop

    // 0x80800E08: bc1f        L_80800E28
    if (!c1cs) {
        // 0x80800E0C: nop
    
            goto L_80800E28;
    }
    // 0x80800E0C: nop

    // 0x80800E10: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800E14: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800E18: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E1C: jal         0x800DC178
    // 0x80800E20: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800E20: nop

    after_4:
    // 0x80800E24: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_80800E28:
    // 0x80800E28: jal         0x800DC0C0
    // 0x80800E2C: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800E2C: nop

    after_5:
    // 0x80800E30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11C8) << 16);
    // 0x80800E34: lwc1        $f16, 0x11C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11C8));
    // 0x80800E38: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800E3C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800E40: nop

    // 0x80800E44: bc1fl       L_80800EE4
    if (!c1cs) {
        // 0x80800E48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EE4;
    }
    goto skip_0;
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800E4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800E50: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800E54: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E58: jal         0x800DC178
    // 0x80800E5C: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800E5C: nop

    after_6:
    // 0x80800E60: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800E64: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800E68: b           L_80800EE0
    // 0x80800E6C: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
        goto L_80800EE0;
    // 0x80800E6C: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_80800E70:
    // 0x80800E70: jal         0x80800C58
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C58_chmayafarmer(rdram, ctx);
        goto after_7;
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800E78: beq         $v0, $zero, L_80800E88
    if (ctx->r2 == 0) {
        // 0x80800E7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E88;
    }
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E80: jal         0x80102424
    // 0x80800E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800E88:
    // 0x80800E88: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800E8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E90: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800E94: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800E98: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800E9C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800EA0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800EA4: bc1fl       L_80800EC0
    if (!c1cs) {
        // 0x80800EA8: sw          $a0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r4;
            goto L_80800EC0;
    }
    goto skip_1;
    // 0x80800EA8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    skip_1:
    // 0x80800EAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EB0: nop

    // 0x80800EB4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800EB8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80800EBC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
L_80800EC0:
    // 0x80800EC0: jal         0x800F1DF4
    // 0x80800EC4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x80800EC4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_9:
    // 0x80800EC8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800ECC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800ED0: jal         0x800F1828
    // 0x80800ED4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_800F1828(rdram, ctx);
        goto after_10;
    // 0x80800ED4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_10:
    // 0x80800ED8: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80800EDC: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
L_80800EE0:
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EE4:
    // 0x80800EE4: jal         0x80102CF4
    // 0x80800EE8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_11;
    // 0x80800EE8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_11:
    // 0x80800EEC: bne         $v0, $zero, L_80800F74
    if (ctx->r2 != 0) {
        // 0x80800EF0: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80800F74;
    }
    // 0x80800EF0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800EF4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800EF8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800EFC: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80800F00: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800F04: nop

    // 0x80800F08: bc1fl       L_80800F48
    if (!c1cs) {
        // 0x80800F0C: lwc1        $f0, 0x4C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
            goto L_80800F48;
    }
    goto skip_2;
    // 0x80800F0C: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    skip_2:
    // 0x80800F10: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800F14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F18: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800F1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F20: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800F24: nop

    // 0x80800F28: bc1fl       L_80800F8C
    if (!c1cs) {
        // 0x80800F2C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F8C;
    }
    goto skip_3;
    // 0x80800F2C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x80800F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F34: nop

    // 0x80800F38: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800F3C: b           L_80800F88
    // 0x80800F40: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
        goto L_80800F88;
    // 0x80800F40: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80800F44: lwc1        $f0, 0x4C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4C);
L_80800F48:
    // 0x80800F48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800F4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F50: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800F54: nop

    // 0x80800F58: bc1fl       L_80800F8C
    if (!c1cs) {
        // 0x80800F5C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F8C;
    }
    goto skip_4;
    // 0x80800F5C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x80800F60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F64: nop

    // 0x80800F68: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80800F6C: b           L_80800F88
    // 0x80800F70: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
        goto L_80800F88;
    // 0x80800F70: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
L_80800F74:
    // 0x80800F74: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800F78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F7C: nop

    // 0x80800F80: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800F84: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
L_80800F88:
    // 0x80800F88: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80800F8C:
    // 0x80800F8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F94: lw          $t8, 0x6C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X6C);
    // 0x80800F98: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800F9C: bne         $t9, $at, L_80800FD4
    if (ctx->r25 != ctx->r1) {
        // 0x80800FA0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800FD4;
    }
    // 0x80800FA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800FA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11CC) << 16);
    // 0x80800FAC: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800FB0: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x80800FB4: lwc1        $f4, 0x11CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11CC));
    // 0x80800FB8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800FBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800FC0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800FC4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800FC8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800FCC: b           L_8080100C
    // 0x80800FD0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
        goto L_8080100C;
    // 0x80800FD0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
L_80800FD4:
    // 0x80800FD4: jal         0x80102D4C
    // 0x80800FD8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102D4C(rdram, ctx);
        goto after_12;
    // 0x80800FD8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_12:
    // 0x80800FDC: bne         $v0, $zero, L_80800FEC
    if (ctx->r2 != 0) {
        // 0x80800FE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FEC;
    }
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: jal         0x80102B6C
    // 0x80800FE8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102B6C(rdram, ctx);
        goto after_13;
    // 0x80800FE8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_13:
L_80800FEC:
    // 0x80800FEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X11D0) << 16);
    // 0x80800FF0: lwc1        $f18, 0x11D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1612, 0X11D0));
    // 0x80800FF4: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800FF8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800FFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801000: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80801004: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80801008: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
L_8080100C:
    // 0x8080100C: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80801010: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80801014: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80801018: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080101C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801020: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80801024: jal         0x800EF4E4
    // 0x80801028: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_14;
    // 0x80801028: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x8080102C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801030: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801034: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801038: jr          $ra
    // 0x8080103C: nop

    return;
    // 0x8080103C: nop

;}
RECOMP_FUNC void func_8009518C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009518C: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x80095190: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80095194: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80095198: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8009519C: sb          $t6, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r14;
    // 0x800951A0: lw          $t9, 0x78($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X78);
    // 0x800951A4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800951A8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800951AC: jr          $ra
    // 0x800951B0: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
    return;
    // 0x800951B0: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800344_chfantasylakebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800348: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080034C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800350: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080035C: beq         $at, $zero, L_80800550
    if (ctx->r1 == 0) {
        // 0x80800360: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80800550;
    }
    // 0x80800360: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800364: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800368: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2376, 0X900) << 16);
    // 0x8080036C: addu        $at, $at, $t7
    gpr jr_addend_80800374 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800370: lw          $t7, 0x900($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2376, 0X900));
    // 0x80800374: jr          $t7
    // 0x80800378: nop

    switch (jr_addend_80800374 >> 2) {
        case 0: goto L_8080037C; break;
        case 1: goto L_80800420; break;
        case 2: goto L_8080046C; break;
        case 3: goto L_808004A4; break;
        case 4: goto L_808004D8; break;
        default: switch_error(__func__, 0x80800374, 0x80800900);
    }
    // 0x80800378: nop

L_8080037C:
    // 0x8080037C: jal         0x800BEA88
    // 0x80800380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80800380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800384: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800388: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080038C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800394: jal         0x800BF744
    // 0x80800398: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x80800398: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8080039C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x808003A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003A4: addiu       $a1, $zero, 0x654
    ctx->r5 = ADD32(0, 0X654);
    // 0x808003A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808003AC: jal         0x80088F28
    // 0x808003B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808003B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x808003B4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808003B8: addiu       $a2, $a2, 0x7660
    ctx->r6 = ADD32(ctx->r6, 0X7660);
    // 0x808003BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003C4: jal         0x80088660
    // 0x808003C8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808003C8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808003CC: jal         0x800EA05C
    // 0x808003D0: nop

    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x808003D0: nop

    after_4:
    // 0x808003D4: addiu       $at, $zero, 0x13A
    ctx->r1 = ADD32(0, 0X13A);
    // 0x808003D8: bnel        $v0, $at, L_80800404
    if (ctx->r2 != ctx->r1) {
        // 0x808003DC: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_80800404;
    }
    goto skip_0;
    // 0x808003DC: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x808003E0: jal         0x800BEA88
    // 0x808003E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_5;
    // 0x808003E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x808003E8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F0: addiu       $a1, $zero, 0x59B
    ctx->r5 = ADD32(0, 0X59B);
    // 0x808003F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808003F8: jal         0x80088F28
    // 0x808003FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808003FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80800400: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_80800404:
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080040C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800410: jal         0x80103110
    // 0x80800414: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x80800414: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_7:
    // 0x80800418: b           L_80800554
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800554;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800420:
    // 0x80800420: jal         0x800F9C38
    // 0x80800424: nop

    func_800F9C38(rdram, ctx);
        goto after_8;
    // 0x80800424: nop

    after_8:
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x80103110
    // 0x80800430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_9;
    // 0x80800430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800434: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: jal         0x8008A490
    // 0x80800440: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800440: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_10:
    // 0x80800444: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800448: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080044C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80800458: addiu       $a1, $zero, 0x8DE
    ctx->r5 = ADD32(0, 0X8DE);
    // 0x8080045C: jal         0x80103140
    // 0x80800460: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    func_80103140(rdram, ctx);
        goto after_11;
    // 0x80800460: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    after_11:
    // 0x80800464: b           L_80800554
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800554;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080046C:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x8010A800
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_12;
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800478: jal         0x800F54E4
    // 0x8080047C: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x8080047C: nop

    after_13:
    // 0x80800480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800484: jal         0x800F5A00
    // 0x80800488: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_14;
    // 0x80800488: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_14:
    // 0x8080048C: jal         0x800F54E4
    // 0x80800490: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80800490: nop

    after_15:
    // 0x80800494: jal         0x800F5628
    // 0x80800498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5628(rdram, ctx);
        goto after_16;
    // 0x80800498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x8080049C: b           L_80800550
    // 0x808004A0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
        goto L_80800550;
    // 0x808004A0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_808004A4:
    // 0x808004A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808004A8: jal         0x800BF744
    // 0x808004AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_17;
    // 0x808004AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808004B0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808004B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004BC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808004C0: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x80089D40
    // 0x808004CC: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x808004CC: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    after_18:
    // 0x808004D0: b           L_80800554
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800554;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004D8:
    // 0x808004D8: jal         0x800BEA88
    // 0x808004DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_19;
    // 0x808004DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x808004E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808004E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808004E8: jal         0x800BF744
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_20;
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808004F0: addiu       $t4, $zero, -0xC80
    ctx->r12 = ADD32(0, -0XC80);
    // 0x808004F4: sw          $t4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r12;
    // 0x808004F8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808004FC: addiu       $a2, $a2, 0x7660
    ctx->r6 = ADD32(ctx->r6, 0X7660);
    // 0x80800500: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800508: jal         0x80088660
    // 0x8080050C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x8080050C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_21:
    // 0x80800510: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800514: addiu       $a1, $zero, 0x654
    ctx->r5 = ADD32(0, 0X654);
    // 0x80800518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080051C: jal         0x80088F28
    // 0x80800520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x80800520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_22:
    // 0x80800524: jal         0x800DA544
    // 0x80800528: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA544(rdram, ctx);
        goto after_23;
    // 0x80800528: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_23:
    // 0x8080052C: jal         0x800DA524
    // 0x80800530: addiu       $a0, $zero, 0x9FC
    ctx->r4 = ADD32(0, 0X9FC);
    func_800DA524(rdram, ctx);
        goto after_24;
    // 0x80800530: addiu       $a0, $zero, 0x9FC
    ctx->r4 = ADD32(0, 0X9FC);
    after_24:
    // 0x80800534: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80800540: jal         0x80089D40
    // 0x80800544: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80800544: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    after_25:
    // 0x80800548: jal         0x800FFAB0
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_26;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
L_80800550:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800554:
    // 0x80800554: jal         0x80101FDC
    // 0x80800558: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80101FDC(rdram, ctx);
        goto after_27;
    // 0x80800558: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_27:
    // 0x8080055C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800564: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800568: jr          $ra
    // 0x8080056C: nop

    return;
    // 0x8080056C: nop

;}
