#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F4244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4244: jr          $ra
    // 0x800F4248: lw          $v0, 0x17C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X17C);
    return;
    // 0x800F4248: lw          $v0, 0x17C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X17C);
;}
RECOMP_FUNC void func_808000B8_chtntblockage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: beq         $a1, $at, L_808000F0
    if (ctx->r5 == ctx->r1) {
        // 0x808000D0: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808000F0;
    }
    // 0x808000D0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808000D4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000D8: beq         $a1, $at, L_80800138
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800138;
    }
    // 0x808000DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000E0: beq         $a1, $at, L_80800148
    if (ctx->r5 == ctx->r1) {
        // 0x808000E4: nop
    
            goto L_80800148;
    }
    // 0x808000E4: nop

    // 0x808000E8: b           L_80800170
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800170;
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000F0:
    // 0x808000F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808000F4: jal         0x800EE7F8
    // 0x808000F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x808000FC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800100: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800104: jal         0x800EF1B8
    // 0x80800108: lui         $a2, 0xC396
    ctx->r6 = S32(0XC396 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800108: lui         $a2, 0xC396
    ctx->r6 = S32(0XC396 << 16);
    after_1:
    // 0x8080010C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80800110: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800114: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800120: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800128: jal         0x80086670
    // 0x8080012C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080012C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800130: b           L_80800170
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800138:
    // 0x80800138: jal         0x80800184
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800184_chtntblockage(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800140: b           L_80800170
    // 0x80800144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800148:
    // 0x80800148: jal         0x808000A8
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000A8_chtntblockage(rdram, ctx);
        goto after_4;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80085D28
    // 0x80800158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _chtntdetonator_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8080015C: b           L_80800170
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800164: b           L_80800170
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800170;
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800170:
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void func_800D70F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D70F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D70FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7100: jal         0x800D6254
    // 0x800D7104: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D7104: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D7108: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D710C: beq         $v0, $at, L_800D7124
    if (ctx->r2 == ctx->r1) {
        // 0x800D7110: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D7124;
    }
    // 0x800D7110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D7114: jal         0x800D7050
    // 0x800D7118: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800D7050(rdram, ctx);
        goto after_1;
    // 0x800D7118: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800D711C: b           L_800D7128
    // 0x800D7120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D7128;
    // 0x800D7120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D7124:
    // 0x800D7124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D7128:
    // 0x800D7128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D712C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7130: jr          $ra
    // 0x800D7134: nop

    return;
    // 0x800D7134: nop

;}
RECOMP_FUNC void func_808005C4_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808005C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808005CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005D4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x808005D8: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808005DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005E0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808005E4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x808005E8: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x808005EC: beq         $at, $zero, L_8080094C
    if (ctx->r1 == 0) {
        // 0x808005F0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080094C;
    }
    // 0x808005F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808005F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1112, 0X1228) << 16);
    // 0x808005F8: addu        $at, $at, $t9
    gpr jr_addend_80800600 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808005FC: lw          $t9, 0x1228($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1112, 0X1228));
    // 0x80800600: jr          $t9
    // 0x80800604: nop

    switch (jr_addend_80800600 >> 2) {
        case 0: goto L_80800608; break;
        case 1: goto L_80800644; break;
        case 2: goto L_808007AC; break;
        case 3: goto L_808007BC; break;
        case 4: goto L_808007CC; break;
        case 5: goto L_808007DC; break;
        case 6: goto L_808007EC; break;
        case 7: goto L_808007FC; break;
        case 8: goto L_80800804; break;
        case 9: goto L_80800864; break;
        case 10: goto L_808008E0; break;
        case 11: goto L_80800920; break;
        default: switch_error(__func__, 0x80800600, 0x80801228);
    }
    // 0x80800604: nop

L_80800608:
    // 0x80800608: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8080060C: lbu         $t2, 0x75($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X75);
    // 0x80800610: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800614: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    // 0x80800618: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080061C: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80800620: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800624: jal         0x800DA298
    // 0x80800628: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800628: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
    after_0:
    // 0x8080062C: beql        $v0, $zero, L_80800950
    if (ctx->r2 == 0) {
        // 0x80800630: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_80800950;
    }
    goto skip_0;
    // 0x80800630: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80800634: jal         0x80800FE0
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FE0_chterryegg(rdram, ctx);
        goto after_1;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080063C: b           L_80800950
    // 0x80800640: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x80800640: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_80800644:
    // 0x80800644: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800648: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80800654: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80800658: lhu         $t8, 0x64($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X64);
    // 0x8080065C: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800660: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800664: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x80800668: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8080066C: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
    // 0x80800670: jal         0x80101DDC
    // 0x80800674: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    func_80101DDC(rdram, ctx);
        goto after_2;
    // 0x80800674: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_2:
    // 0x80800678: beql        $v0, $zero, L_80800950
    if (ctx->r2 == 0) {
        // 0x8080067C: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_80800950;
    }
    goto skip_1;
    // 0x8080067C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x80800680: jal         0x800F54E4
    // 0x80800684: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800684: nop

    after_3:
    // 0x80800688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080068C: jal         0x800F82D4
    // 0x80800690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_4;
    // 0x80800690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800694: jal         0x808010DC
    // 0x80800698: nop

    func_808010DC_chterryegg(rdram, ctx);
        goto after_5;
    // 0x80800698: nop

    after_5:
    // 0x8080069C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006A0: bne         $v0, $at, L_808006F4
    if (ctx->r2 != ctx->r1) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F4;
    }
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808006B0: addiu       $a1, $zero, 0x17FE
    ctx->r5 = ADD32(0, 0X17FE);
    // 0x808006B4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808006B8: jal         0x8008A208
    // 0x808006BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808006BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x808006C0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808006C4: addiu       $a0, $zero, 0x361
    ctx->r4 = ADD32(0, 0X361);
    // 0x808006C8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808006CC: srl         $t4, $a1, 7
    ctx->r12 = S32(U32(ctx->r5) >> 7);
    // 0x808006D0: jal         0x800DA7A8
    // 0x808006D4: addiu       $a1, $t4, -0x31
    ctx->r5 = ADD32(ctx->r12, -0X31);
    func_800DA7A8(rdram, ctx);
        goto after_7;
    // 0x808006D4: addiu       $a1, $t4, -0x31
    ctx->r5 = ADD32(ctx->r12, -0X31);
    after_7:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x80102424
    // 0x808006E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808006E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x808006E4: jal         0x8010A590
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_9;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006EC: b           L_80800950
    // 0x808006F0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808006F0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808006F4:
    // 0x808006F4: jal         0x80100094
    // 0x808006F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x808006F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808006FC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800700: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800704: srl         $t5, $a0, 7
    ctx->r13 = S32(U32(ctx->r4) >> 7);
    // 0x80800708: jal         0x800DA544
    // 0x8080070C: addiu       $a0, $t5, 0x143
    ctx->r4 = ADD32(ctx->r13, 0X143);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x8080070C: addiu       $a0, $t5, 0x143
    ctx->r4 = ADD32(ctx->r13, 0X143);
    after_11:
    // 0x80800710: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800714: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800718: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x8080071C: jal         0x800CB698
    // 0x80800720: addiu       $a0, $t6, -0x2B
    ctx->r4 = ADD32(ctx->r14, -0X2B);
    func_800CB698(rdram, ctx);
        goto after_12;
    // 0x80800720: addiu       $a0, $t6, -0x2B
    ctx->r4 = ADD32(ctx->r14, -0X2B);
    after_12:
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: jal         0x80102424
    // 0x8080072C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x8080072C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x80800730: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800734: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800738: addiu       $a1, $zero, 0x17E1
    ctx->r5 = ADD32(0, 0X17E1);
    // 0x8080073C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800740: jal         0x8008A208
    // 0x80800744: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800744: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_14:
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: jal         0x8008A4B0
    // 0x80800750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800754: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080075C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800760: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80800764: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1112, 0X1236) << 16);
    // 0x80800768: beql        $t8, $at, L_80800950
    if (ctx->r24 == ctx->r1) {
        // 0x8080076C: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_80800950;
    }
    goto skip_2;
    // 0x8080076C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_2:
    // 0x80800770: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x80800774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800778: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    // 0x8080077C: srl         $t1, $t9, 7
    ctx->r9 = S32(U32(ctx->r25) >> 7);
    // 0x80800780: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80800784: jal         0x80085708
    // 0x80800788: lbu         $a2, 0x1236($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1236));
    _capod_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x80800788: lbu         $a2, 0x1236($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1236));
    after_16:
    // 0x8080078C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800798: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080079C: jal         0x801058C4
    // 0x808007A0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    func_801058C4(rdram, ctx);
        goto after_17;
    // 0x808007A0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_17:
    // 0x808007A4: b           L_80800950
    // 0x808007A8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808007A8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808007AC:
    // 0x808007AC: jal         0x80801080
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801080_chterryegg(rdram, ctx);
        goto after_18;
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808007B4: b           L_80800950
    // 0x808007B8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808007B8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808007BC:
    // 0x808007BC: jal         0x80801050
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801050_chterryegg(rdram, ctx);
        goto after_19;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808007C4: b           L_80800950
    // 0x808007C8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808007C8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808007CC:
    // 0x808007CC: jal         0x800FFAB0
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_20;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808007D4: b           L_80800950
    // 0x808007D8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808007D8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808007DC:
    // 0x808007DC: jal         0x80801050
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801050_chterryegg(rdram, ctx);
        goto after_21;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808007E4: b           L_80800950
    // 0x808007E8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808007E8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808007EC:
    // 0x808007EC: jal         0x80801050
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801050_chterryegg(rdram, ctx);
        goto after_22;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808007F4: b           L_80800950
    // 0x808007F8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x808007F8: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808007FC:
    // 0x808007FC: b           L_8080094C
    // 0x80800800: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
        goto L_8080094C;
    // 0x80800800: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80800804:
    // 0x80800804: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80800808: jal         0x80801080
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801080_chterryegg(rdram, ctx);
        goto after_23;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800810: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: srl         $t2, $a1, 7
    ctx->r10 = S32(U32(ctx->r5) >> 7);
    // 0x8080081C: jal         0x8008A500
    // 0x80800820: addiu       $a1, $t2, -0x2B
    ctx->r5 = ADD32(ctx->r10, -0X2B);
    _subaddietaxi_entrypoint_1(rdram, ctx);
        goto after_24;
    // 0x80800820: addiu       $a1, $t2, -0x2B
    ctx->r5 = ADD32(ctx->r10, -0X2B);
    after_24:
    // 0x80800824: beq         $v0, $zero, L_8080094C
    if (ctx->r2 == 0) {
        // 0x80800828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080094C;
    }
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x80102424
    // 0x80800830: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_25;
    // 0x80800830: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_25:
    // 0x80800834: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800838: srl         $t3, $a0, 7
    ctx->r11 = S32(U32(ctx->r4) >> 7);
    // 0x8080083C: jal         0x800DA544
    // 0x80800840: addiu       $a0, $t3, 0x143
    ctx->r4 = ADD32(ctx->r11, 0X143);
    func_800DA544(rdram, ctx);
        goto after_26;
    // 0x80800840: addiu       $a0, $t3, 0x143
    ctx->r4 = ADD32(ctx->r11, 0X143);
    after_26:
    // 0x80800844: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800848: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    // 0x8080084C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80800850: srl         $t4, $a2, 7
    ctx->r12 = S32(U32(ctx->r6) >> 7);
    // 0x80800854: jal         0x80101180
    // 0x80800858: addiu       $a2, $t4, -0x32
    ctx->r6 = ADD32(ctx->r12, -0X32);
    func_80101180(rdram, ctx);
        goto after_27;
    // 0x80800858: addiu       $a2, $t4, -0x32
    ctx->r6 = ADD32(ctx->r12, -0X32);
    after_27:
    // 0x8080085C: b           L_80800950
    // 0x80800860: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x80800860: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_80800864:
    // 0x80800864: jal         0x80801050
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801050_chterryegg(rdram, ctx);
        goto after_28;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8080086C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: srl         $t5, $a1, 7
    ctx->r13 = S32(U32(ctx->r5) >> 7);
    // 0x80800878: jal         0x8008A550
    // 0x8080087C: addiu       $a1, $t5, -0x2B
    ctx->r5 = ADD32(ctx->r13, -0X2B);
    _subaddietaxi_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x8080087C: addiu       $a1, $t5, -0x2B
    ctx->r5 = ADD32(ctx->r13, -0X2B);
    after_29:
    // 0x80800880: beql        $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x80800884: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_808008C8;
    }
    goto skip_3;
    // 0x80800884: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_3:
    // 0x80800888: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80800894: jal         0x8008A520
    // 0x80800898: addiu       $a1, $t6, -0x2B
    ctx->r5 = ADD32(ctx->r14, -0X2B);
    _subaddietaxi_entrypoint_5(rdram, ctx);
        goto after_30;
    // 0x80800898: addiu       $a1, $t6, -0x2B
    ctx->r5 = ADD32(ctx->r14, -0X2B);
    after_30:
    // 0x8080089C: beql        $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x808008A0: lhu         $a1, 0x76($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X76);
            goto L_808008C8;
    }
    goto skip_4;
    // 0x808008A0: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    skip_4:
    // 0x808008A4: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: srl         $t7, $a1, 7
    ctx->r15 = S32(U32(ctx->r5) >> 7);
    // 0x808008B0: jal         0x8008A568
    // 0x808008B4: addiu       $a1, $t7, -0x2B
    ctx->r5 = ADD32(ctx->r15, -0X2B);
    _subaddietaxi_entrypoint_14(rdram, ctx);
        goto after_31;
    // 0x808008B4: addiu       $a1, $t7, -0x2B
    ctx->r5 = ADD32(ctx->r15, -0X2B);
    after_31:
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: jal         0x80102424
    // 0x808008C0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_32;
    // 0x808008C0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_32:
    // 0x808008C4: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_808008C8:
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: srl         $t8, $a1, 7
    ctx->r24 = S32(U32(ctx->r5) >> 7);
    // 0x808008D0: jal         0x8008A558
    // 0x808008D4: addiu       $a1, $t8, -0x2B
    ctx->r5 = ADD32(ctx->r24, -0X2B);
    _subaddietaxi_entrypoint_12(rdram, ctx);
        goto after_33;
    // 0x808008D4: addiu       $a1, $t8, -0x2B
    ctx->r5 = ADD32(ctx->r24, -0X2B);
    after_33:
    // 0x808008D8: b           L_8080094C
    // 0x808008DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
        goto L_8080094C;
    // 0x808008DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_808008E0:
    // 0x808008E0: jal         0x800EFD24
    // 0x808008E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFD24(rdram, ctx);
        goto after_34;
    // 0x808008E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_34:
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: jal         0x80102D78
    // 0x808008F0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80102D78(rdram, ctx);
        goto after_35;
    // 0x808008F0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_35:
    // 0x808008F4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808008F8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808008FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800908: jal         0x80102BF8
    // 0x8080090C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_80102BF8(rdram, ctx);
        goto after_36;
    // 0x8080090C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_36:
    // 0x80800910: jal         0x80801080
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801080_chterryegg(rdram, ctx);
        goto after_37;
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800918: b           L_80800950
    // 0x8080091C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
        goto L_80800950;
    // 0x8080091C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_80800920:
    // 0x80800920: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: srl         $t9, $a1, 7
    ctx->r25 = S32(U32(ctx->r5) >> 7);
    // 0x8080092C: jal         0x8008A570
    // 0x80800930: addiu       $a1, $t9, -0x2B
    ctx->r5 = ADD32(ctx->r25, -0X2B);
    _subaddietaxi_entrypoint_15(rdram, ctx);
        goto after_38;
    // 0x80800930: addiu       $a1, $t9, -0x2B
    ctx->r5 = ADD32(ctx->r25, -0X2B);
    after_38:
    // 0x80800934: beq         $v0, $zero, L_8080094C
    if (ctx->r2 == 0) {
        // 0x80800938: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080094C;
    }
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: jal         0x80102424
    // 0x80800940: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_39;
    // 0x80800940: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_39:
    // 0x80800944: jal         0x8010A590
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_40;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
L_8080094C:
    // 0x8080094C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
L_80800950:
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: srl         $t1, $a1, 7
    ctx->r9 = S32(U32(ctx->r5) >> 7);
    // 0x80800958: jal         0x8008A540
    // 0x8080095C: addiu       $a1, $t1, -0x2B
    ctx->r5 = ADD32(ctx->r9, -0X2B);
    _subaddietaxi_entrypoint_9(rdram, ctx);
        goto after_41;
    // 0x8080095C: addiu       $a1, $t1, -0x2B
    ctx->r5 = ADD32(ctx->r9, -0X2B);
    after_41:
    // 0x80800960: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80800964: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80800968: beql        $t0, $zero, L_808009A4
    if (ctx->r8 == 0) {
        // 0x8080096C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808009A4;
    }
    goto skip_5;
    // 0x8080096C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80800970: jal         0x800F54E4
    // 0x80800974: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    func_800F54E4(rdram, ctx);
        goto after_42;
    // 0x80800974: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_42:
    // 0x80800978: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080097C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800980: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800988: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080098C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800990: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800994: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800998: jal         0x800F4F34
    // 0x8080099C: nop

    func_800F4F34(rdram, ctx);
        goto after_43;
    // 0x8080099C: nop

    after_43:
    // 0x808009A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009A4:
    // 0x808009A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808009AC: jr          $ra
    // 0x808009B0: nop

    return;
    // 0x808009B0: nop

;}
RECOMP_FUNC void func_80800E2C_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E34: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x80800E38: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X165C) << 16);
    // 0x80800E3C: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x80800E40: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800E44: addiu       $a2, $a2, 0x165C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X165C));
    // 0x80800E48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800E4C: jal         0x80089D20
    // 0x80800E50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800E50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E54: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1668) << 16);
    // 0x80800E58: lui         $a3, 0x3E0F
    ctx->r7 = S32(0X3E0F << 16);
    // 0x80800E5C: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x80800E60: addiu       $a2, $a2, 0x1668
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1668));
    // 0x80800E64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E68: jal         0x80089D20
    // 0x80800E6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800E6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800E70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X1674) << 16);
    // 0x80800E74: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1020, 0X167C) << 16);
    // 0x80800E78: addiu       $a3, $a3, 0x167C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1020, 0X167C));
    // 0x80800E7C: addiu       $a2, $a2, 0x1674
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X1674));
    // 0x80800E80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E84: jal         0x80089D28
    // 0x80800E88: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800E88: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E94: jr          $ra
    // 0x80800E98: nop

    return;
    // 0x80800E98: nop

;}
RECOMP_FUNC void func_8080000C_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: jal         0x800EA05C
    // 0x80800028: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800028: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x8080002C: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // 0x80800030: jal         0x8008A020
    // 0x80800034: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    after_2:
    // 0x80800038: jal         0x80800C48
    // 0x8080003C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800C48_chboilerid(rdram, ctx);
        goto after_3;
    // 0x8080003C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80800040: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x80800CB0
    // 0x8080004C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_80800CB0_chboilerid(rdram, ctx);
        goto after_4;
    // 0x8080004C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800050: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80800054: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800058: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8080005C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1084, 0XD00) << 16);
    // 0x80800060: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800064: lh          $t7, 0xD00($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(1084, 0XD00));
    // 0x80800068: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80800074: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800078: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080007C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800080: jal         0x80088FA0
    // 0x80800084: nop

    _mlwave_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800084: nop

    after_5:
    // 0x80800088: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8080008C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1084, 0XD00) << 16);
    // 0x80800090: addiu       $t0, $t0, 0xD00
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1084, 0XD00));
    // 0x80800094: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800098: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8080009C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x808000A0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x808000A4: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x808000A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000AC: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x808000B0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x808000B4: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808000B8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000BC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808000C0: jal         0x80088FA0
    // 0x808000C4: nop

    _mlwave_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808000C4: nop

    after_6:
    // 0x808000C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808000CC: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x808000D0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808000D4: lh          $t2, 0x10($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X10);
    // 0x808000D8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808000DC: nop

    // 0x808000E0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808000E4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808000E8: jal         0x80088FA0
    // 0x808000EC: nop

    _mlwave_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808000EC: nop

    after_7:
    // 0x808000F0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    // 0x808000F8: lh          $t3, 0x1A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1A);
    // 0x808000FC: sh          $t3, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r11;
    // 0x80800100: lh          $t4, 0x18($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X18);
    // 0x80800104: sh          $t4, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r12;
    // 0x80800108: lh          $t5, 0x1C($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X1C);
    // 0x8080010C: jal         0x800DA524
    // 0x80800110: sh          $t5, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r13;
    func_800DA524(rdram, ctx);
        goto after_8;
    // 0x80800110: sh          $t5, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r13;
    after_8:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_80800D28_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D28: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800D2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D30: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800D34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D38: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80800D3C: jal         0x800DA298
    // 0x80800D40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800D40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800D44: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800D48: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800D4C: jal         0x80100094
    // 0x80800D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800D54: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D58: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800D5C: jal         0x800DC128
    // 0x80800D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800D64: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D68: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80800D6C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800D70: beq         $t6, $zero, L_80800DA8
    if (ctx->r14 == 0) {
        // 0x80800D74: addiu       $s0, $sp, 0x5C
        ctx->r16 = ADD32(ctx->r29, 0X5C);
            goto L_80800DA8;
    }
    // 0x80800D74: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D7C: lui         $a1, 0x44AF
    ctx->r5 = S32(0X44AF << 16);
    // 0x80800D80: lui         $a2, 0x4382
    ctx->r6 = S32(0X4382 << 16);
    // 0x80800D84: lui         $a3, 0xC4AF
    ctx->r7 = S32(0XC4AF << 16);
    // 0x80800D88: jal         0x800EFA4C
    // 0x80800D8C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800D8C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    after_3:
    // 0x80800D90: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80800D94: addiu       $t7, $zero, -0xC
    ctx->r15 = ADD32(0, -0XC);
    // 0x80800D98: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80800D9C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800DA0: b           L_80800E58
    // 0x80800DA4: addiu       $t0, $t1, -0xC
    ctx->r8 = ADD32(ctx->r9, -0XC);
        goto L_80800E58;
    // 0x80800DA4: addiu       $t0, $t1, -0xC
    ctx->r8 = ADD32(ctx->r9, -0XC);
L_80800DA8:
    // 0x80800DA8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80800DAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800DB4: blez        $v1, L_80800E20
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800DB8: nop
    
            goto L_80800E20;
    }
    // 0x80800DB8: nop

    // 0x80800DBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800DC0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_80800DC4:
    // 0x80800DC4: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800DC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800DCC: mflo        $t8
    ctx->r24 = lo;
    // 0x80800DD0: addu        $t0, $t1, $t8
    ctx->r8 = ADD32(ctx->r9, ctx->r24);
    // 0x80800DD4: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80800DD8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800DDC: nop

    // 0x80800DE0: bc1fl       L_80800E04
    if (!c1cs) {
        // 0x80800DE4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80800E04;
    }
    goto skip_0;
    // 0x80800DE4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x80800DE8: lhu         $t9, 0x14($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X14);
    // 0x80800DEC: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x80800DF0: bnel        $t2, $zero, L_80800E04
    if (ctx->r10 != 0) {
        // 0x80800DF4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80800E04;
    }
    goto skip_1;
    // 0x80800DF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x80800DF8: b           L_80800E20
    // 0x80800DFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80800E20;
    // 0x80800DFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800E00: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80800E04:
    // 0x80800E04: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800E08: bnel        $at, $zero, L_80800E18
    if (ctx->r1 != 0) {
        // 0x80800E0C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80800E18;
    }
    goto skip_2;
    // 0x80800E0C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_2:
    // 0x80800E10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800E14: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80800E18:
    // 0x80800E18: bne         $at, $zero, L_80800DC4
    if (ctx->r1 != 0) {
        // 0x80800E1C: nop
    
            goto L_80800DC4;
    }
    // 0x80800E1C: nop

L_80800E20:
    // 0x80800E20: beq         $a0, $zero, L_8080111C
    if (ctx->r4 == 0) {
        // 0x80800E24: addiu       $a2, $zero, 0xC
        ctx->r6 = ADD32(0, 0XC);
            goto L_8080111C;
    }
    // 0x80800E24: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800E28: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800E2C: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E34: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80800E38: mflo        $v0
    ctx->r2 = lo;
    // 0x80800E3C: addu        $t0, $t1, $v0
    ctx->r8 = ADD32(ctx->r9, ctx->r2);
    // 0x80800E40: addiu       $a1, $t0, 0x16
    ctx->r5 = ADD32(ctx->r8, 0X16);
    // 0x80800E44: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80800E48: jal         0x800EE88C
    // 0x80800E4C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x80800E4C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800E50: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800E54: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80800E58:
    // 0x80800E58: lw          $a2, 0x14($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X14);
    // 0x80800E5C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80800E60: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80800E64: sra         $t3, $a2, 17
    ctx->r11 = S32(SIGNED(ctx->r6) >> 17);
    // 0x80800E68: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80800E6C: addiu       $a0, $zero, 0x356
    ctx->r4 = ADD32(0, 0X356);
    // 0x80800E70: jal         0x80108474
    // 0x80800E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80108474(rdram, ctx);
        goto after_5;
    // 0x80800E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800E78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E80: jal         0x80100094
    // 0x80800E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80800E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800E88: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800E8C: jal         0x80089CA0
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800E94: jal         0x800DC0C0
    // 0x80800E98: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x80800E98: nop

    after_8:
    // 0x80800E9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1016, 0X1EB8) << 16);
    // 0x80800EA0: lwc1        $f6, 0x1EB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1016, 0X1EB8));
    // 0x80800EA4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800EA8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800EAC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800EB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800EB4: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80800EB8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80800EBC: bc1fl       L_80800ED0
    if (!c1cs) {
        // 0x80800EC0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80800ED0;
    }
    goto skip_3;
    // 0x80800EC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80800EC4: b           L_80800EEC
    // 0x80800EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EEC;
    // 0x80800EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800ECC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80800ED0:
    // 0x80800ED0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80800ED4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800ED8: nop

    // 0x80800EDC: bc1f        L_80800EEC
    if (!c1cs) {
        // 0x80800EE0: nop
    
            goto L_80800EEC;
    }
    // 0x80800EE0: nop

    // 0x80800EE4: b           L_80800EEC
    // 0x80800EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EEC;
    // 0x80800EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EEC:
    // 0x80800EEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800EF0: beql        $v1, $at, L_80800F00
    if (ctx->r3 == ctx->r1) {
        // 0x80800EF4: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80800F00;
    }
    goto skip_4;
    // 0x80800EF4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_4:
    // 0x80800EF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800EFC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800F00:
    // 0x80800F00: subu        $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x80800F04: beq         $v0, $zero, L_80800F28
    if (ctx->r2 == 0) {
        // 0x80800F08: sw          $t4, 0x40($t5)
        MEM_W(0X40, ctx->r13) = ctx->r12;
            goto L_80800F28;
    }
    // 0x80800F08: sw          $t4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r12;
    // 0x80800F0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F10: beql        $v0, $at, L_80800F9C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F14: sw          $a3, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r7;
            goto L_80800F9C;
    }
    goto skip_5;
    // 0x80800F14: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    skip_5:
    // 0x80800F18: beql        $v0, $v1, L_8080100C
    if (ctx->r2 == ctx->r3) {
        // 0x80800F1C: sw          $a3, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r7;
            goto L_8080100C;
    }
    goto skip_6;
    // 0x80800F1C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    skip_6:
    // 0x80800F20: b           L_80801078
    // 0x80800F24: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
        goto L_80801078;
    // 0x80800F24: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80800F28:
    // 0x80800F28: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x80800F2C: jal         0x800D3948
    // 0x80800F30: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800D3948(rdram, ctx);
        goto after_9;
    // 0x80800F30: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_9:
    // 0x80800F34: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800F38: beq         $v0, $zero, L_80800F48
    if (ctx->r2 == 0) {
        // 0x80800F3C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80800F48;
    }
    // 0x80800F3C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800F40: b           L_80800F4C
    // 0x80800F44: addiu       $v0, $zero, 0x958
    ctx->r2 = ADD32(0, 0X958);
        goto L_80800F4C;
    // 0x80800F44: addiu       $v0, $zero, 0x958
    ctx->r2 = ADD32(0, 0X958);
L_80800F48:
    // 0x80800F48: addiu       $v0, $zero, 0x878
    ctx->r2 = ADD32(0, 0X878);
L_80800F4C:
    // 0x80800F4C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F54: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800F58: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800F5C: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    // 0x80800F60: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80800F64: jal         0x80103140
    // 0x80800F68: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_10;
    // 0x80800F68: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_10:
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F70: jal         0x80102424
    // 0x80800F74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800F74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800F78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800F7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F80: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80800F84: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800F88: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800F8C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80800F90: b           L_80801074
    // 0x80800F94: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80801074;
    // 0x80800F94: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80800F98: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
L_80800F9C:
    // 0x80800F9C: jal         0x800D3948
    // 0x80800FA0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800D3948(rdram, ctx);
        goto after_12;
    // 0x80800FA0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_12:
    // 0x80800FA4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800FA8: beq         $v0, $zero, L_80800FB8
    if (ctx->r2 == 0) {
        // 0x80800FAC: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80800FB8;
    }
    // 0x80800FAC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800FB0: b           L_80800FBC
    // 0x80800FB4: addiu       $v0, $zero, 0x957
    ctx->r2 = ADD32(0, 0X957);
        goto L_80800FBC;
    // 0x80800FB4: addiu       $v0, $zero, 0x957
    ctx->r2 = ADD32(0, 0X957);
L_80800FB8:
    // 0x80800FB8: addiu       $v0, $zero, 0x877
    ctx->r2 = ADD32(0, 0X877);
L_80800FBC:
    // 0x80800FBC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80800FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800FC8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80800FCC: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    // 0x80800FD0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80800FD4: jal         0x80103140
    // 0x80800FD8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_13;
    // 0x80800FD8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_13:
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE0: jal         0x80102424
    // 0x80800FE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800FE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800FE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800FEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FF0: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x80800FF4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80800FF8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800FFC: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80801000: b           L_80801074
    // 0x80801004: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80801074;
    // 0x80801004: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80801008: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
L_8080100C:
    // 0x8080100C: jal         0x800D3948
    // 0x80801010: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_800D3948(rdram, ctx);
        goto after_15;
    // 0x80801010: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_15:
    // 0x80801014: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801018: beq         $v0, $zero, L_80801028
    if (ctx->r2 == 0) {
        // 0x8080101C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80801028;
    }
    // 0x8080101C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801020: b           L_8080102C
    // 0x80801024: addiu       $v0, $zero, 0x956
    ctx->r2 = ADD32(0, 0X956);
        goto L_8080102C;
    // 0x80801024: addiu       $v0, $zero, 0x956
    ctx->r2 = ADD32(0, 0X956);
L_80801028:
    // 0x80801028: addiu       $v0, $zero, 0x7A1
    ctx->r2 = ADD32(0, 0X7A1);
L_8080102C:
    // 0x8080102C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801034: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80801038: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8080103C: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    // 0x80801040: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80801044: jal         0x80103140
    // 0x80801048: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    func_80103140(rdram, ctx);
        goto after_16;
    // 0x80801048: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_16:
    // 0x8080104C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801050: jal         0x80102424
    // 0x80801054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80801054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80801058: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080105C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801060: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80801064: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80801068: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8080106C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80801070: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80801074:
    // 0x80801074: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80801078:
    // 0x80801078: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8080107C: bnel        $t7, $zero, L_808010A0
    if (ctx->r15 != 0) {
        // 0x80801080: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_808010A0;
    }
    goto skip_7;
    // 0x80801080: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    skip_7:
    // 0x80801084: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80801088: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080108C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801090: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801094: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801098: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8080109C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_808010A0:
    // 0x808010A0: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x808010A4: addiu       $at, $zero, -0xC
    ctx->r1 = ADD32(0, -0XC);
    // 0x808010A8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808010AC: sw          $a3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r7;
    // 0x808010B0: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x808010B4: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x808010B8: lw          $t3, 0x6C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X6C);
    // 0x808010BC: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x808010C0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x808010C4: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x808010C8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808010CC: beql        $t8, $at, L_808010E4
    if (ctx->r24 == ctx->r1) {
        // 0x808010D0: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_808010E4;
    }
    goto skip_8;
    // 0x808010D0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x808010D4: lbu         $t2, 0x15($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X15);
    // 0x808010D8: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808010DC: sb          $t3, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r11;
    // 0x808010E0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_808010E4:
    // 0x808010E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808010E8: beql        $t5, $zero, L_80801120
    if (ctx->r13 == 0) {
        // 0x808010EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801120;
    }
    goto skip_9;
    // 0x808010EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x808010F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808010F4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x808010F8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x808010FC: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    // 0x80801100: beql        $a0, $zero, L_80801118
    if (ctx->r4 == 0) {
        // 0x80801104: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_80801118;
    }
    goto skip_10;
    // 0x80801104: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x80801108: jal         0x8010114C
    // 0x8080110C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010114C(rdram, ctx);
        goto after_18;
    // 0x8080110C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x80801110: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80801114: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_80801118:
    // 0x80801118: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
L_8080111C:
    // 0x8080111C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801120:
    // 0x80801120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801124: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801128: jr          $ra
    // 0x8080112C: nop

    return;
    // 0x8080112C: nop

;}
RECOMP_FUNC void func_80800068_chtemplebrokendoorpiece(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080006C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800074: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800078: bne         $a1, $at, L_808000D8
    if (ctx->r5 != ctx->r1) {
        // 0x8080007C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808000D8;
    }
    // 0x8080007C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800080: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800084: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800088: jal         0x800EE7F8
    // 0x8080008C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080008C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800090: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800094: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800098: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x8080009C: jal         0x800EF1B8
    // 0x808000A0: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808000A0: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x808000A4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808000A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000AC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000B4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808000B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808000BC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808000C0: jal         0x80086670
    // 0x808000C4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000C4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808000C8: jal         0x80800008
    // 0x808000CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800008_chtemplebrokendoorpiece(rdram, ctx);
        goto after_3;
    // 0x808000CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808000D0: b           L_808000E0
    // 0x808000D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E0;
    // 0x808000D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D8:
    // 0x808000D8: b           L_808000E0
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E0;
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E0:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_800CF264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF26C: jal         0x800EA09C
    // 0x800CF270: nop

    func_800EA09C(rdram, ctx);
        goto after_0;
    // 0x800CF270: nop

    after_0:
    // 0x800CF274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CF278: bnel        $v0, $at, L_800CF2A4
    if (ctx->r2 != ctx->r1) {
        // 0x800CF27C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF2A4;
    }
    goto skip_0;
    // 0x800CF27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CF280: jal         0x800CF01C
    // 0x800CF284: nop

    func_800CF01C(rdram, ctx);
        goto after_1;
    // 0x800CF284: nop

    after_1:
    // 0x800CF288: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800CF28C: lbu         $t6, -0x4E94($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4E94);
    // 0x800CF290: beql        $t6, $zero, L_800CF2A4
    if (ctx->r14 == 0) {
        // 0x800CF294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CF2A4;
    }
    goto skip_1;
    // 0x800CF294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CF298: jal         0x800CF190
    // 0x800CF29C: nop

    func_800CF190(rdram, ctx);
        goto after_2;
    // 0x800CF29C: nop

    after_2:
    // 0x800CF2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CF2A4:
    // 0x800CF2A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF2A8: jr          $ra
    // 0x800CF2AC: nop

    return;
    // 0x800CF2AC: nop

;}
RECOMP_FUNC void func_800EB2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB2DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EB2E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EB2E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EB2E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EB2EC: jal         0x800EB15C
    // 0x800EB2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EB15C(rdram, ctx);
        goto after_0;
    // 0x800EB2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800EB2F4: beq         $v0, $zero, L_800EB340
    if (ctx->r2 == 0) {
        // 0x800EB2F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800EB340;
    }
    // 0x800EB2F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EB2FC: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x800EB300: sll         $t8, $t6, 22
    ctx->r24 = S32(ctx->r14 << 22);
    // 0x800EB304: bgezl       $t8, L_800EB344
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800EB308: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EB344;
    }
    goto skip_0;
    // 0x800EB308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EB30C: jal         0x800EC3C4
    // 0x800EB310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EC3C4(rdram, ctx);
        goto after_1;
    // 0x800EB310: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800EB314: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EB318: beql        $a0, $zero, L_800EB344
    if (ctx->r4 == 0) {
        // 0x800EB31C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EB344;
    }
    goto skip_1;
    // 0x800EB31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800EB320: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800EB324: beql        $t9, $zero, L_800EB344
    if (ctx->r25 == 0) {
        // 0x800EB328: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EB344;
    }
    goto skip_2;
    // 0x800EB328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800EB32C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800EB330: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB334: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800EB338: jalr        $t9
    // 0x800EB33C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800EB33C: nop

    after_2:
L_800EB340:
    // 0x800EB340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EB344:
    // 0x800EB344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EB348: jr          $ra
    // 0x800EB34C: nop

    return;
    // 0x800EB34C: nop

;}
RECOMP_FUNC void func_80800B68_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B70: jal         0x800845D0
    // 0x80800B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B78: jal         0x80082830
    // 0x80800B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B88: jr          $ra
    // 0x80800B8C: nop

    return;
    // 0x80800B8C: nop

;}
RECOMP_FUNC void _badronemem_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084908: syscall     123
    recomp_syscall_handler(rdram, ctx, 0x80084908);
    return;
    // 0x8008490C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836D0: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836D0);
    return;
    // 0x800836D4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _ncpod_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089598: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089598);
    return;
    // 0x8008959C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_800A0D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A0D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0D4C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800A0D50: jal         0x800A0D14
    // 0x800A0D54: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    func_800A0D14(rdram, ctx);
        goto after_0;
    // 0x800A0D54: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    after_0:
    // 0x800A0D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0D60: jr          $ra
    // 0x800A0D64: nop

    return;
    // 0x800A0D64: nop

;}
RECOMP_FUNC void func_808016F0_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016F8: jal         0x808016A4
    // 0x808016FC: nop

    func_808016A4_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x808016FC: nop

    after_0:
    // 0x80801700: jal         0x80088238
    // 0x80801704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gclevel_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080170C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801710: jr          $ra
    // 0x80801714: nop

    return;
    // 0x80801714: nop

;}
RECOMP_FUNC void func_800C13E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C13E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C13EC: addiu       $v0, $v0, -0x5670
    ctx->r2 = ADD32(ctx->r2, -0X5670);
    // 0x800C13F0: addiu       $v1, $v1, -0x7470
    ctx->r3 = ADD32(ctx->r3, -0X7470);
L_800C13F4:
    // 0x800C13F4: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // 0x800C13F8: sb          $zero, -0x108($v1)
    MEM_B(-0X108, ctx->r3) = 0;
    // 0x800C13FC: sb          $zero, -0x88($v1)
    MEM_B(-0X88, ctx->r3) = 0;
    // 0x800C1400: sb          $zero, -0x8($v1)
    MEM_B(-0X8, ctx->r3) = 0;
    // 0x800C1404: bne         $v1, $v0, L_800C13F4
    if (ctx->r3 != ctx->r2) {
        // 0x800C1408: sb          $zero, -0x188($v1)
        MEM_B(-0X188, ctx->r3) = 0;
            goto L_800C13F4;
    }
    // 0x800C1408: sb          $zero, -0x188($v1)
    MEM_B(-0X188, ctx->r3) = 0;
    // 0x800C140C: jr          $ra
    // 0x800C1410: nop

    return;
    // 0x800C1410: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A08: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A08);
    return;
    // 0x80088A0C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800D39A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D39AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D39B0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800D39B4: jal         0x800B2DC0
    // 0x800D39B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B2DC0(rdram, ctx);
        goto after_0;
    // 0x800D39B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800D39BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D39C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D39C4: sh          $v0, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = ctx->r2;
    // 0x800D39C8: jr          $ra
    // 0x800D39CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D39CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _fxegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A60: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A60);
    return;
    // 0x80088A64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chdoubloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800004: jr          $ra
    // 0x80800008: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800008: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_808015D4_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808015D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808015DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808015E0: jal         0x800D8FF8
    // 0x808015E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808015E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808015E8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808015EC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x808015F0: jal         0x800DA298
    // 0x808015F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808015F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808015F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808015FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801600: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80801604: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80801608: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080160C: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80801610: jal         0x800CEAD0
    // 0x80801614: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_2;
    // 0x80801614: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80801618: beql        $v0, $zero, L_8080162C
    if (ctx->r2 == 0) {
        // 0x8080161C: lwc1        $f4, 0x50($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
            goto L_8080162C;
    }
    goto skip_0;
    // 0x8080161C: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x80801620: jal         0x8010A570
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80801624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801628: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
L_8080162C:
    // 0x8080162C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801630: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801634: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801638: jal         0x800136E4
    // 0x8080163C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8080163C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_4:
    // 0x80801640: lui         $at, 0x452F
    ctx->r1 = S32(0X452F << 16);
    // 0x80801644: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801648: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080164C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80801650: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801654: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80801658: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080165C: bc1fl       L_8080167C
    if (!c1cs) {
        // 0x80801660: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_8080167C;
    }
    goto skip_1;
    // 0x80801660: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    skip_1:
    // 0x80801664: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801668: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8080166C: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80801670: b           L_8080167C
    // 0x80801674: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_8080167C;
    // 0x80801674: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80801678: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_8080167C:
    // 0x8080167C: jal         0x80089C90
    // 0x80801680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80801680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801684: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80801688: bne         $v0, $at, L_80801698
    if (ctx->r2 != ctx->r1) {
        // 0x8080168C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801698;
    }
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801690: jal         0x8010A800
    // 0x80801694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x80801694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80801698:
    // 0x80801698: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080169C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016A0: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808016A4: beq         $t9, $at, L_808016EC
    if (ctx->r25 == ctx->r1) {
        // 0x808016A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808016EC;
    }
    // 0x808016A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808016AC: beq         $t9, $at, L_808016DC
    if (ctx->r25 == ctx->r1) {
        // 0x808016B0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808016DC;
    }
    // 0x808016B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808016B4: beq         $t9, $at, L_808016CC
    if (ctx->r25 == ctx->r1) {
        // 0x808016B8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808016CC;
    }
    // 0x808016B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808016BC: beq         $t9, $at, L_808016FC
    if (ctx->r25 == ctx->r1) {
        // 0x808016C0: lui         $a2, 0x3FB3
        ctx->r6 = S32(0X3FB3 << 16);
            goto L_808016FC;
    }
    // 0x808016C0: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808016C4: b           L_8080175C
    // 0x808016C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_8080175C;
    // 0x808016C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808016CC:
    // 0x808016CC: jal         0x800DA298
    // 0x808016D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808016D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x808016D4: b           L_80801758
    // 0x808016D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_80801758;
    // 0x808016D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_808016DC:
    // 0x808016DC: jal         0x800DA298
    // 0x808016E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808016E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x808016E4: b           L_80801758
    // 0x808016E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_80801758;
    // 0x808016E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_808016EC:
    // 0x808016EC: jal         0x800DA298
    // 0x808016F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808016F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x808016F4: b           L_80801758
    // 0x808016F8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_80801758;
    // 0x808016F8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_808016FC:
    // 0x808016FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801700: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801704: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801708: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080170C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80801710: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801714: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801718: jal         0x800F10B4
    // 0x8080171C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x8080171C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x80801720: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801724: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80801728: jal         0x80102FDC
    // 0x8080172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_11;
    // 0x8080172C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801730: jal         0x800D90A4
    // 0x80801734: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x80801734: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_12:
    // 0x80801738: beql        $v0, $zero, L_8080175C
    if (ctx->r2 == 0) {
        // 0x8080173C: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8080175C;
    }
    goto skip_2;
    // 0x8080173C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80801740: jal         0x8010A570
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_13;
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801748: jal         0x800FFAB0
    // 0x8080174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x8080174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801750: b           L_80801794
    // 0x80801754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801794;
    // 0x80801754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801758:
    // 0x80801758: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8080175C:
    // 0x8080175C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80801760: beql        $t0, $zero, L_80801794
    if (ctx->r8 == 0) {
        // 0x80801764: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801794;
    }
    goto skip_3;
    // 0x80801764: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80801768: bne         $v0, $zero, L_80801778
    if (ctx->r2 != 0) {
        // 0x8080176C: lw          $t1, 0x38($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X38);
            goto L_80801778;
    }
    // 0x8080176C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80801770: bne         $t1, $zero, L_80801788
    if (ctx->r9 != 0) {
        // 0x80801774: nop
    
            goto L_80801788;
    }
    // 0x80801774: nop

L_80801778:
    // 0x80801778: beq         $v0, $zero, L_80801790
    if (ctx->r2 == 0) {
        // 0x8080177C: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_80801790;
    }
    // 0x8080177C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80801780: beql        $t2, $zero, L_80801794
    if (ctx->r10 == 0) {
        // 0x80801784: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801794;
    }
    goto skip_4;
    // 0x80801784: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
L_80801788:
    // 0x80801788: jal         0x80801B6C
    // 0x8080178C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B6C_chballoonburst(rdram, ctx);
        goto after_15;
    // 0x8080178C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_80801790:
    // 0x80801790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801794:
    // 0x80801794: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080179C: jr          $ra
    // 0x808017A0: nop

    return;
    // 0x808017A0: nop

;}
RECOMP_FUNC void func_80800020_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: beq         $a1, $zero, L_80800044
    if (ctx->r5 == 0) {
        // 0x80800028: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800044;
    }
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: lui         $a2, 0x3F61
    ctx->r6 = S32(0X3F61 << 16);
    // 0x80800030: ori         $a2, $a2, 0x47AE
    ctx->r6 = ctx->r6 | 0X47AE;
    // 0x80800034: jal         0x8009DE38
    // 0x80800038: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    func_8009DE38(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    after_0:
    // 0x8080003C: b           L_80800058
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: lui         $a2, 0x3F75
    ctx->r6 = S32(0X3F75 << 16);
    // 0x80800048: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080004C: jal         0x8009DE38
    // 0x80800050: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x4433
    ctx->r5 = ADD32(0, 0X4433);
    after_1:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_800F7F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F7F04: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F7F08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F7F0C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7F10: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800F7F14: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800F7F18: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F7F1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7F20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F7F24: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F7F28: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800F7F2C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7F30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800F7F34: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800F7F38: jal         0x80098778
    // 0x800F7F3C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_80098778(rdram, ctx);
        goto after_0;
    // 0x800F7F3C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800F7F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F7F44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F7F48: jr          $ra
    // 0x800F7F4C: nop

    return;
    // 0x800F7F4C: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4B0: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4B0);
    return;
    // 0x8008A4B4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80804BF4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804BF8: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x80804BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804C00: beq         $at, $zero, L_80804C18
    if (ctx->r1 == 0) {
        // 0x80804C04: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80804C18;
    }
    // 0x80804C04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804C08: jal         0x80800478
    // 0x80804C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804C10: b           L_80804C24
    // 0x80804C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804C24;
    // 0x80804C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804C18:
    // 0x80804C18: jal         0x80804C30
    // 0x80804C1C: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
    func_80804C30_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804C1C: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
    after_1:
    // 0x80804C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804C24:
    // 0x80804C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804C28: jr          $ra
    // 0x80804C2C: nop

    return;
    // 0x80804C2C: nop

;}
RECOMP_FUNC void chprisonbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1932, 0X1050) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x1050
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0X1050));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x1050
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0X1050));
;}
RECOMP_FUNC void boot_osVirtualToPhysical(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void ncbaspiral_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: jr          $ra
    // 0x808000B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800A34CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34CC: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A34D0: jr          $ra
    // 0x800A34D4: sb          $a1, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = ctx->r5;
    return;
    // 0x800A34D4: sb          $a1, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80808848_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080884C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808850: jal         0x80807BB8
    // 0x80808854: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808854: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80808858: jal         0x80808DB0
    // 0x8080885C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080885C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80808860: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80808864: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80808868: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA588) << 16);
    // 0x8080886C: lwc1        $f4, -0x5A78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA588));
    // 0x80808870: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80808874: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80808878: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080887C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80808880: jal         0x800854E0
    // 0x80808884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _bainvisible_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80808884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80808888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080888C: jal         0x808086B0
    // 0x80808890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808086B0_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80808894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080889C: jr          $ra
    // 0x808088A0: nop

    return;
    // 0x808088A0: nop

;}
RECOMP_FUNC void _bamovehover_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E48: syscall     138
    recomp_syscall_handler(rdram, ctx, 0x80084E48);
    return;
    // 0x80084E4C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bssplitup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A98: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083A98);
    return;
    // 0x80083A9C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800CC6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC6F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC6F8: lw          $t7, -0x516C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X516C);
    // 0x800CC6FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CC700: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800CC704: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CC708: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800CC70C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CC710: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC718: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800CC71C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CC720: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CC724: jal         0x800CB8F0
    // 0x800CC728: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800CB8F0(rdram, ctx);
        goto after_0;
    // 0x800CC728: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CC72C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CC730: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800CC734: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC738: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CC73C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800CC740: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800CC744: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x800CC748: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800CC74C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CC750: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CC754: sll         $t0, $v1, 12
    ctx->r8 = S32(ctx->r3 << 12);
    // 0x800CC758: srl         $t1, $t0, 29
    ctx->r9 = S32(U32(ctx->r8) >> 29);
    // 0x800CC75C: beq         $t1, $zero, L_800CC784
    if (ctx->r9 == 0) {
        // 0x800CC760: nop
    
            goto L_800CC784;
    }
    // 0x800CC760: nop

    // 0x800CC764: beq         $t1, $at, L_800CC7A8
    if (ctx->r9 == ctx->r1) {
        // 0x800CC768: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CC7A8;
    }
    // 0x800CC768: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC76C: beq         $t1, $at, L_800CC810
    if (ctx->r9 == ctx->r1) {
        // 0x800CC770: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CC810;
    }
    // 0x800CC770: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CC774: beql        $t1, $at, L_800CC864
    if (ctx->r9 == ctx->r1) {
        // 0x800CC778: lh          $t4, 0xE($a0)
        ctx->r12 = MEM_H(ctx->r4, 0XE);
            goto L_800CC864;
    }
    goto skip_0;
    // 0x800CC778: lh          $t4, 0xE($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800CC77C: b           L_800CC8B0
    // 0x800CC780: nop

        goto L_800CC8B0;
    // 0x800CC780: nop

L_800CC784:
    // 0x800CC784: jal         0x800EFC7C
    // 0x800CC788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x800CC788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800CC78C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC790: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CC794: nop

    // 0x800CC798: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC79C: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC79C: nop

    // 0x800CC7A0: b           L_800CCA9C
    // 0x800CC7A4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800CCA9C;
    // 0x800CC7A4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800CC7A8:
    // 0x800CC7A8: lh          $t2, 0xE($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XE);
    // 0x800CC7AC: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CC7B0: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC7B4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800CC7B8: nop

    // 0x800CC7BC: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CC7C0: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800CC7C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800CC7C8: nop

    // 0x800CC7CC: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC7D0: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC7D0: nop

    // 0x800CC7D4: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800CC7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC7DC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CC7E0: nop

    // 0x800CC7E4: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC7E8: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC7E8: nop

    // 0x800CC7EC: jal         0x800EFC7C
    // 0x800CC7F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x800CC7F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800CC7F4: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC7F8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800CC7FC: nop

    // 0x800CC800: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC804: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC804: nop

    // 0x800CC808: b           L_800CCA9C
    // 0x800CC80C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800CCA9C;
    // 0x800CC80C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800CC810:
    // 0x800CC810: lh          $t3, 0xE($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XE);
    // 0x800CC814: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CC818: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC81C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800CC820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC824: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CC828: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800CC82C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800CC830: nop

    // 0x800CC834: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC838: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC838: nop

    // 0x800CC83C: jal         0x800EFC7C
    // 0x800CC840: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x800CC840: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800CC844: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC848: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800CC84C: nop

    // 0x800CC850: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC854: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC854: nop

    // 0x800CC858: b           L_800CCA9C
    // 0x800CC85C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800CCA9C;
    // 0x800CC85C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800CC860: lh          $t4, 0xE($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XE);
L_800CC864:
    // 0x800CC864: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CC868: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC86C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800CC870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC874: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CC878: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800CC87C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800CC880: nop

    // 0x800CC884: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC888: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC888: nop

    // 0x800CC88C: jal         0x800EFC7C
    // 0x800CC890: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_4;
    // 0x800CC890: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800CC894: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC898: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800CC89C: nop

    // 0x800CC8A0: bc1f        L_800CC8B0
    if (!c1cs) {
        // 0x800CC8A4: nop
    
            goto L_800CC8B0;
    }
    // 0x800CC8A4: nop

    // 0x800CC8A8: b           L_800CCA9C
    // 0x800CC8AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800CCA9C;
    // 0x800CC8AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800CC8B0:
    // 0x800CC8B0: jal         0x800CB910
    // 0x800CC8B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800CB910(rdram, ctx);
        goto after_5;
    // 0x800CC8B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x800CC8B8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800CC8BC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800CC8C0: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800CC8C4: beql        $at, $zero, L_800CCA9C
    if (ctx->r1 == 0) {
        // 0x800CC8C8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800CCA9C;
    }
    goto skip_1;
    // 0x800CC8C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800CC8CC: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
L_800CC8D0:
    // 0x800CC8D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC8D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC8D8: sll         $t6, $v1, 12
    ctx->r14 = S32(ctx->r3 << 12);
    // 0x800CC8DC: srl         $t7, $t6, 29
    ctx->r15 = S32(U32(ctx->r14) >> 29);
    // 0x800CC8E0: beq         $t7, $zero, L_800CC908
    if (ctx->r15 == 0) {
        // 0x800CC8E4: nop
    
            goto L_800CC908;
    }
    // 0x800CC8E4: nop

    // 0x800CC8E8: beq         $t7, $at, L_800CC940
    if (ctx->r15 == ctx->r1) {
        // 0x800CC8EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CC940;
    }
    // 0x800CC8EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CC8F0: beq         $t7, $at, L_800CC9BC
    if (ctx->r15 == ctx->r1) {
        // 0x800CC8F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CC9BC;
    }
    // 0x800CC8F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CC8F8: beql        $t7, $at, L_800CCA24
    if (ctx->r15 == ctx->r1) {
        // 0x800CC8FC: lh          $t6, 0xE($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XE);
            goto L_800CCA24;
    }
    goto skip_2;
    // 0x800CC8FC: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
    skip_2:
    // 0x800CC900: b           L_800CCA88
    // 0x800CC904: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
        goto L_800CCA88;
    // 0x800CC904: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_800CC908:
    // 0x800CC908: jal         0x800EFC7C
    // 0x800CC90C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_6;
    // 0x800CC90C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800CC910: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC914: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800CC918: nop

    // 0x800CC91C: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CC920: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_3;
    // 0x800CC920: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x800CC924: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CC928: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CC92C: subu        $v0, $s0, $t8
    ctx->r2 = SUB32(ctx->r16, ctx->r24);
    // 0x800CC930: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC934: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC938: b           L_800CCAA0
    // 0x800CC93C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CCAA0;
    // 0x800CC93C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CC940:
    // 0x800CC940: lh          $t0, 0xE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XE);
    // 0x800CC944: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC948: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC94C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800CC950: nop

    // 0x800CC954: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CC958: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800CC95C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800CC960: nop

    // 0x800CC964: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CC968: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_4;
    // 0x800CC968: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_4:
    // 0x800CC96C: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800CC970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC974: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CC978: nop

    // 0x800CC97C: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CC980: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_5;
    // 0x800CC980: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_5:
    // 0x800CC984: jal         0x800EFC7C
    // 0x800CC988: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_7;
    // 0x800CC988: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800CC98C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC990: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CC994: nop

    // 0x800CC998: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CC99C: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_6;
    // 0x800CC99C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_6:
    // 0x800CC9A0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CC9A4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CC9A8: subu        $v0, $s0, $t1
    ctx->r2 = SUB32(ctx->r16, ctx->r9);
    // 0x800CC9AC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CC9B0: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC9B4: b           L_800CCAA0
    // 0x800CC9B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CCAA0;
    // 0x800CC9B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CC9BC:
    // 0x800CC9BC: lh          $t3, 0xE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE);
    // 0x800CC9C0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CC9C4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CC9C8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CC9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC9D0: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CC9D4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800CC9D8: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800CC9DC: nop

    // 0x800CC9E0: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CC9E4: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_7;
    // 0x800CC9E4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_7:
    // 0x800CC9E8: jal         0x800EFC7C
    // 0x800CC9EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_8;
    // 0x800CC9EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800CC9F0: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CC9F4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CC9F8: nop

    // 0x800CC9FC: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CCA00: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_8;
    // 0x800CCA00: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_8:
    // 0x800CCA04: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800CCA08: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CCA0C: subu        $v0, $s0, $t4
    ctx->r2 = SUB32(ctx->r16, ctx->r12);
    // 0x800CCA10: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CCA14: mflo        $v0
    ctx->r2 = lo;
    // 0x800CCA18: b           L_800CCAA0
    // 0x800CCA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CCAA0;
    // 0x800CCA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCA20: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
L_800CCA24:
    // 0x800CCA24: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800CCA28: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CCA2C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800CCA30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCA34: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CCA38: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800CCA3C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800CCA40: nop

    // 0x800CCA44: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CCA48: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_9;
    // 0x800CCA48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_9:
    // 0x800CCA4C: jal         0x800EFC7C
    // 0x800CCA50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_9;
    // 0x800CCA50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800CCA54: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800CCA58: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CCA5C: nop

    // 0x800CCA60: bc1fl       L_800CCA88
    if (!c1cs) {
        // 0x800CCA64: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800CCA88;
    }
    goto skip_10;
    // 0x800CCA64: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_10:
    // 0x800CCA68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800CCA6C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800CCA70: subu        $v0, $s0, $t7
    ctx->r2 = SUB32(ctx->r16, ctx->r15);
    // 0x800CCA74: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800CCA78: mflo        $v0
    ctx->r2 = lo;
    // 0x800CCA7C: b           L_800CCAA0
    // 0x800CCA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CCAA0;
    // 0x800CCA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCA84: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_800CCA88:
    // 0x800CCA88: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800CCA8C: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x800CCA90: bnel        $at, $zero, L_800CC8D0
    if (ctx->r1 != 0) {
        // 0x800CCA94: lw          $v1, 0x14($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X14);
            goto L_800CC8D0;
    }
    goto skip_11;
    // 0x800CCA94: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    skip_11:
    // 0x800CCA98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CCA9C:
    // 0x800CCA9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CCAA0:
    // 0x800CCAA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CCAA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CCAA8: jr          $ra
    // 0x800CCAAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CCAAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8009EA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA5C: jr          $ra
    // 0x8009EA60: lw          $v0, 0x7080($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7080);
    return;
    // 0x8009EA60: lw          $v0, 0x7080($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7080);
;}
RECOMP_FUNC void func_800815CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800815CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800815D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800815D4: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x800815D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800815DC: addiu       $a1, $a1, 0x6730
    ctx->r5 = ADD32(ctx->r5, 0X6730);
    // 0x800815E0: jal         0x8001E210
    // 0x800815E4: addiu       $a0, $a0, 0x50E0
    ctx->r4 = ADD32(ctx->r4, 0X50E0);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800815E4: addiu       $a0, $a0, 0x50E0
    ctx->r4 = ADD32(ctx->r4, 0X50E0);
    after_0:
    // 0x800815E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800815EC: sw          $zero, 0x7C60($at)
    MEM_W(0X7C60, ctx->r1) = 0;
    // 0x800815F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800815F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800815F8: sw          $zero, 0x7C64($at)
    MEM_W(0X7C64, ctx->r1) = 0;
    // 0x800815FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081600: sw          $zero, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = 0;
    // 0x80081604: jr          $ra
    // 0x80081608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80081608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B7C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7C54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7C58: lw          $v1, -0x7D4C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D4C);
    // 0x800B7C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7C64: bnel        $v1, $zero, L_800B7C88
    if (ctx->r3 != 0) {
        // 0x800B7C68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7C88;
    }
    goto skip_0;
    // 0x800B7C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B7C6C: jal         0x80088908
    // 0x800B7C70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    _fxrain_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800B7C70: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x800B7C74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7C78: sw          $v0, -0x7D4C($at)
    MEM_W(-0X7D4C, ctx->r1) = ctx->r2;
    // 0x800B7C7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7C80: lw          $v1, -0x7D4C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D4C);
    // 0x800B7C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B7C88:
    // 0x800B7C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B7C90: jr          $ra
    // 0x800B7C94: nop

    return;
    // 0x800B7C94: nop

;}
RECOMP_FUNC void func_80800320_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080032C: jal         0x80100094
    // 0x80800330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800334: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800338: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080033C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800340: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800344: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800348: jal         0x800EE7F8
    // 0x8080034C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080034C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800350: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800354: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800358: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080035C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800360: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800364: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800368: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8080036C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800370: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800374: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80800378: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080037C: jal         0x800D1000
    // 0x80800380: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800D1000(rdram, ctx);
        goto after_2;
    // 0x80800380: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80800384: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800388: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080038C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800390: addiu       $a3, $zero, 0x2090
    ctx->r7 = ADD32(0, 0X2090);
    // 0x80800394: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800398: jal         0x8008A2D0
    // 0x8080039C: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080039C: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    after_3:
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void func_80800024_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x80089F48
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080003C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800040: jal         0x80089F50
    // 0x80800044: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800044: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    after_1:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_80807664_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80807668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080766C: jal         0x80100094
    // 0x80807670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807674: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80807678: jal         0x80089D48
    // 0x8080767C: lbu         $a0, 0xA0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA0);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080767C: lbu         $a0, 0xA0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA0);
    after_1:
    // 0x80807680: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80807684: sb          $v0, 0xA0($t6)
    MEM_B(0XA0, ctx->r14) = ctx->r2;
    // 0x80807688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080768C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80807690: jr          $ra
    // 0x80807694: nop

    return;
    // 0x80807694: nop

;}
RECOMP_FUNC void huft_build_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA6C: beq         $a1, $zero, L_8001CEE8
    if (ctx->r5 == 0) {
        // 0x8001CA70: mtc1        $s0, $f2
        ctx->f2.u32l = ctx->r16;
            goto L_8001CEE8;
    }
    // 0x8001CA70: mtc1        $s0, $f2
    ctx->f2.u32l = ctx->r16;
    // 0x8001CA74: mtc1        $s1, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r17;
    // 0x8001CA78: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x8001CA7C: mtc1        $s3, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r19;
    // 0x8001CA80: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x8001CA84: mtc1        $s5, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r21;
    // 0x8001CA88: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x8001CA8C: mtc1        $s7, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r23;
    // 0x8001CA90: mtc1        $fp, $f10
    ctx->f10.u32l = ctx->r30;
    // 0x8001CA94: mtc1        $gp, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r28;
    // 0x8001CA98: mfc1        $s3, $f19
    ctx->r19 = (int32_t)ctx->f_odd[(19 - 1) * 2];
    // 0x8001CA9C: sd          $zero, 0x0($sp)
    SD(0, 0X0, ctx->r29);
    // 0x8001CAA0: sd          $zero, 0x8($sp)
    SD(0, 0X8, ctx->r29);
    // 0x8001CAA4: sd          $zero, 0x10($sp)
    SD(0, 0X10, ctx->r29);
    // 0x8001CAA8: sd          $zero, 0x18($sp)
    SD(0, 0X18, ctx->r29);
    // 0x8001CAAC: sd          $zero, 0x20($sp)
    SD(0, 0X20, ctx->r29);
    // 0x8001CAB0: sd          $zero, 0x28($sp)
    SD(0, 0X28, ctx->r29);
    // 0x8001CAB4: sd          $zero, 0x30($sp)
    SD(0, 0X30, ctx->r29);
    // 0x8001CAB8: sd          $zero, 0x38($sp)
    SD(0, 0X38, ctx->r29);
    // 0x8001CABC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8001CAC0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8001CAC4: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
L_8001CAC8:
    // 0x8001CAC8: lw          $s7, 0x0($t0)
    ctx->r23 = MEM_W(ctx->r8, 0X0);
    // 0x8001CACC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001CAD0: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x8001CAD4: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x8001CAD8: lw          $at, 0x0($s7)
    ctx->r1 = MEM_W(ctx->r23, 0X0);
    // 0x8001CADC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001CAE0: addiu       $at, $at, 0x1
    ctx->r1 = ADD32(ctx->r1, 0X1);
    // 0x8001CAE4: bne         $t1, $zero, L_8001CAC8
    if (ctx->r9 != 0) {
        // 0x8001CAE8: sw          $at, 0x0($s7)
        MEM_W(0X0, ctx->r23) = ctx->r1;
            goto L_8001CAC8;
    }
    // 0x8001CAE8: sw          $at, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r1;
    // 0x8001CAEC: lw          $s7, 0x0($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X0);
    // 0x8001CAF0: beq         $s7, $a1, L_8001CEF0
    if (ctx->r23 == ctx->r5) {
        // 0x8001CAF4: lw          $t2, 0x0($t9)
        ctx->r10 = MEM_W(ctx->r25, 0X0);
            goto L_8001CEF0;
    }
    // 0x8001CAF4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8001CAF8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8001CAFC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001CB00: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_8001CB04:
    // 0x8001CB04: addu        $s7, $t3, $sp
    ctx->r23 = ADD32(ctx->r11, ctx->r29);
    // 0x8001CB08: lw          $s7, 0x0($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X0);
    // 0x8001CB0C: bne         $s7, $zero, L_8001CB1C
    if (ctx->r23 != 0) {
        // 0x8001CB10: nop
    
            goto L_8001CB1C;
    }
    // 0x8001CB10: nop

    // 0x8001CB14: bne         $t3, $at, L_8001CB04
    if (ctx->r11 != ctx->r1) {
        // 0x8001CB18: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_8001CB04;
    }
    // 0x8001CB18: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_8001CB1C:
    // 0x8001CB1C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001CB20: beq         $at, $zero, L_8001CB2C
    if (ctx->r1 == 0) {
        // 0x8001CB24: or          $t4, $t3, $zero
        ctx->r12 = ctx->r11 | 0;
            goto L_8001CB2C;
    }
    // 0x8001CB24: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x8001CB28: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_8001CB2C:
    // 0x8001CB2C: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_8001CB30:
    // 0x8001CB30: addu        $s7, $t1, $sp
    ctx->r23 = ADD32(ctx->r9, ctx->r29);
    // 0x8001CB34: lw          $s7, 0x0($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X0);
    // 0x8001CB38: bne         $s7, $zero, L_8001CB4C
    if (ctx->r23 != 0) {
        // 0x8001CB3C: nop
    
            goto L_8001CB4C;
    }
    // 0x8001CB3C: nop

    // 0x8001CB40: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x8001CB44: bne         $t1, $zero, L_8001CB30
    if (ctx->r9 != 0) {
        // 0x8001CB48: nop
    
            goto L_8001CB30;
    }
    // 0x8001CB48: nop

L_8001CB4C:
    // 0x8001CB4C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001CB50: beq         $at, $zero, L_8001CB5C
    if (ctx->r1 == 0) {
        // 0x8001CB54: or          $t5, $t1, $zero
        ctx->r13 = ctx->r9 | 0;
            goto L_8001CB5C;
    }
    // 0x8001CB54: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x8001CB58: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_8001CB5C:
    // 0x8001CB5C: srl         $t2, $t2, 2
    ctx->r10 = S32(U32(ctx->r10) >> 2);
    // 0x8001CB60: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8001CB64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001CB68: srl         $s7, $t3, 2
    ctx->r23 = S32(U32(ctx->r11) >> 2);
    // 0x8001CB6C: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001CB70: beq         $at, $zero, L_8001CB94
    if (ctx->r1 == 0) {
        // 0x8001CB74: sllv        $t9, $t9, $s7
        ctx->r25 = S32(ctx->r25 << (ctx->r23 & 31));
            goto L_8001CB94;
    }
    // 0x8001CB74: sllv        $t9, $t9, $s7
    ctx->r25 = S32(ctx->r25 << (ctx->r23 & 31));
L_8001CB78:
    // 0x8001CB78: addu        $s7, $t3, $sp
    ctx->r23 = ADD32(ctx->r11, ctx->r29);
    // 0x8001CB7C: lw          $s7, 0x0($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X0);
    // 0x8001CB80: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x8001CB84: subu        $t9, $t9, $s7
    ctx->r25 = SUB32(ctx->r25, ctx->r23);
    // 0x8001CB88: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001CB8C: bne         $at, $zero, L_8001CB78
    if (ctx->r1 != 0) {
        // 0x8001CB90: sll         $t9, $t9, 1
        ctx->r25 = S32(ctx->r25 << 1);
            goto L_8001CB78;
    }
    // 0x8001CB90: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
L_8001CB94:
    // 0x8001CB94: addu        $s7, $t1, $sp
    ctx->r23 = ADD32(ctx->r9, ctx->r29);
    // 0x8001CB98: lw          $at, 0x0($s7)
    ctx->r1 = MEM_W(ctx->r23, 0X0);
    // 0x8001CB9C: sw          $t9, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r25;
    // 0x8001CBA0: subu        $t9, $t9, $at
    ctx->r25 = SUB32(ctx->r25, ctx->r1);
    // 0x8001CBA4: sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
    // 0x8001CBA8: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8001CBAC: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x8001CBB0: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x8001CBB4: beq         $t1, $zero, L_8001CBD8
    if (ctx->r9 == 0) {
        // 0x8001CBB8: addiu       $t6, $sp, 0x50C
        ctx->r14 = ADD32(ctx->r29, 0X50C);
            goto L_8001CBD8;
    }
    // 0x8001CBB8: addiu       $t6, $sp, 0x50C
    ctx->r14 = ADD32(ctx->r29, 0X50C);
L_8001CBBC:
    // 0x8001CBBC: lw          $s7, 0x0($t0)
    ctx->r23 = MEM_W(ctx->r8, 0X0);
    // 0x8001CBC0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001CBC4: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x8001CBC8: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8001CBCC: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x8001CBD0: bne         $t1, $zero, L_8001CBBC
    if (ctx->r9 != 0) {
        // 0x8001CBD4: addiu       $t6, $t6, 0x4
        ctx->r14 = ADD32(ctx->r14, 0X4);
            goto L_8001CBBC;
    }
    // 0x8001CBD4: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
L_8001CBD8:
    // 0x8001CBD8: srl         $t5, $t5, 2
    ctx->r13 = S32(U32(ctx->r13) >> 2);
    // 0x8001CBDC: srl         $t4, $t4, 2
    ctx->r12 = S32(U32(ctx->r12) >> 2);
    // 0x8001CBE0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8001CBE4: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8001CBE8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_8001CBEC:
    // 0x8001CBEC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001CBF0: beq         $t3, $zero, L_8001CC14
    if (ctx->r11 == 0) {
        // 0x8001CBF4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8001CC14;
    }
    // 0x8001CBF4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001CBF8: addu        $t3, $t3, $sp
    ctx->r11 = ADD32(ctx->r11, ctx->r29);
    // 0x8001CBFC: lw          $s7, 0x504($t3)
    ctx->r23 = MEM_W(ctx->r11, 0X504);
    // 0x8001CC00: sll         $fp, $s7, 2
    ctx->r30 = S32(ctx->r23 << 2);
    // 0x8001CC04: addiu       $at, $s7, 0x1
    ctx->r1 = ADD32(ctx->r23, 0X1);
    // 0x8001CC08: sw          $at, 0x504($t3)
    MEM_W(0X504, ctx->r11) = ctx->r1;
    // 0x8001CC0C: addu        $fp, $fp, $sp
    ctx->r30 = ADD32(ctx->r30, ctx->r29);
    // 0x8001CC10: sw          $t1, 0x84($fp)
    MEM_W(0X84, ctx->r30) = ctx->r9;
L_8001CC14:
    // 0x8001CC14: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CC18: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001CC1C: bnel        $at, $zero, L_8001CBEC
    if (ctx->r1 != 0) {
        // 0x8001CC20: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_8001CBEC;
    }
    goto skip_0;
    // 0x8001CC20: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8001CC24: sw          $zero, 0x504($sp)
    MEM_W(0X504, ctx->r29) = 0;
    // 0x8001CC28: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x8001CC2C: addiu       $t0, $sp, 0x84
    ctx->r8 = ADD32(ctx->r29, 0X84);
    // 0x8001CC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001CC34: negu        $s1, $t2
    ctx->r17 = SUB32(0, ctx->r10);
    // 0x8001CC38: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8001CC3C: j           L_8001CE74
    // 0x8001CC40: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
        goto L_8001CE74;
    // 0x8001CC40: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
    // 0x8001CC44: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
L_8001CC48:
    // 0x8001CC48: subu        $s0, $t5, $s1
    ctx->r16 = SUB32(ctx->r13, ctx->r17);
    // 0x8001CC4C: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001CC50: beq         $at, $zero, L_8001CC5C
    if (ctx->r1 == 0) {
        // 0x8001CC54: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001CC5C;
    }
    // 0x8001CC54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001CC58: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8001CC5C:
    // 0x8001CC5C: subu        $t3, $t4, $s1
    ctx->r11 = SUB32(ctx->r12, ctx->r17);
    // 0x8001CC60: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001CC64: sllv        $s2, $s2, $t3
    ctx->r18 = S32(ctx->r18 << (ctx->r11 & 31));
    // 0x8001CC68: addiu       $s7, $a0, 0x1
    ctx->r23 = ADD32(ctx->r4, 0X1);
    // 0x8001CC6C: slt         $at, $s7, $s2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8001CC70: beq         $at, $zero, L_8001CCBC
    if (ctx->r1 == 0) {
        // 0x8001CC74: nop
    
            goto L_8001CCBC;
    }
    // 0x8001CC74: nop

    // 0x8001CC78: subu        $s2, $s2, $s7
    ctx->r18 = SUB32(ctx->r18, ctx->r23);
    // 0x8001CC7C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8001CC80: addu        $t6, $t6, $sp
    ctx->r14 = ADD32(ctx->r14, ctx->r29);
    // 0x8001CC84: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8001CC88: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001CC8C: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001CC90: beq         $at, $zero, L_8001CCBC
    if (ctx->r1 == 0) {
        // 0x8001CC94: nop
    
            goto L_8001CCBC;
    }
    // 0x8001CC94: nop

L_8001CC98:
    // 0x8001CC98: lw          $s7, 0x4($t6)
    ctx->r23 = MEM_W(ctx->r14, 0X4);
    // 0x8001CC9C: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x8001CCA0: slt         $at, $s7, $s2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8001CCA4: beq         $at, $zero, L_8001CCBC
    if (ctx->r1 == 0) {
        // 0x8001CCA8: addiu       $t6, $t6, 0x4
        ctx->r14 = ADD32(ctx->r14, 0X4);
            goto L_8001CCBC;
    }
    // 0x8001CCA8: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x8001CCAC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001CCB0: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001CCB4: bne         $at, $zero, L_8001CC98
    if (ctx->r1 != 0) {
        // 0x8001CCB8: subu        $s2, $s2, $s7
        ctx->r18 = SUB32(ctx->r18, ctx->r23);
            goto L_8001CC98;
    }
    // 0x8001CCB8: subu        $s2, $s2, $s7
    ctx->r18 = SUB32(ctx->r18, ctx->r23);
L_8001CCBC:
    // 0x8001CCBC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8001CCC0: sllv        $s0, $s0, $t3
    ctx->r16 = S32(ctx->r16 << (ctx->r11 & 31));
    // 0x8001CCC4: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8001CCC8: addu        $t6, $t6, $s6
    ctx->r14 = ADD32(ctx->r14, ctx->r22);
    // 0x8001CCCC: addiu       $s7, $s3, 0x1
    ctx->r23 = ADD32(ctx->r19, 0X1);
    // 0x8001CCD0: sh          $s7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r23;
    // 0x8001CCD4: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x8001CCD8: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x8001CCDC: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x8001CCE0: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x8001CCE4: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x8001CCE8: beq         $v0, $zero, L_8001CD34
    if (ctx->r2 == 0) {
        // 0x8001CCEC: sw          $t6, 0x44($s7)
        MEM_W(0X44, ctx->r23) = ctx->r14;
            goto L_8001CD34;
    }
    // 0x8001CCEC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
    // 0x8001CCF0: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x8001CCF4: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x8001CCF8: sw          $t1, 0x504($s7)
    MEM_W(0X504, ctx->r23) = ctx->r9;
    // 0x8001CCFC: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x8001CD00: addiu       $s4, $t3, 0x10
    ctx->r20 = ADD32(ctx->r11, 0X10);
    // 0x8001CD04: addiu       $gp, $s3, 0x1
    ctx->r28 = ADD32(ctx->r19, 0X1);
    // 0x8001CD08: subu        $t3, $s1, $t2
    ctx->r11 = SUB32(ctx->r17, ctx->r10);
    // 0x8001CD0C: srlv        $t3, $t1, $t3
    ctx->r11 = S32(U32(ctx->r9) >> (ctx->r11 & 31));
    // 0x8001CD10: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
    // 0x8001CD14: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x8001CD18: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x8001CD1C: lw          $s7, 0x44($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X44);
    // 0x8001CD20: sll         $at, $t3, 2
    ctx->r1 = S32(ctx->r11 << 2);
    // 0x8001CD24: addu        $s7, $s7, $at
    ctx->r23 = ADD32(ctx->r23, ctx->r1);
    // 0x8001CD28: sb          $s4, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r20;
    // 0x8001CD2C: sb          $s5, 0x1($s7)
    MEM_B(0X1, ctx->r23) = ctx->r21;
    // 0x8001CD30: sh          $gp, 0x2($s7)
    MEM_H(0X2, ctx->r23) = ctx->r28;
L_8001CD34:
    // 0x8001CD34: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x8001CD38: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8001CD3C:
    // 0x8001CD3C: addu        $s7, $s1, $t2
    ctx->r23 = ADD32(ctx->r17, ctx->r10);
L_8001CD40:
    // 0x8001CD40: slt         $at, $s7, $t4
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001CD44: bnel        $at, $zero, L_8001CC48
    if (ctx->r1 != 0) {
        // 0x8001CD48: addu        $s1, $s1, $t2
        ctx->r17 = ADD32(ctx->r17, ctx->r10);
            goto L_8001CC48;
    }
    goto skip_1;
    // 0x8001CD48: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    skip_1:
    // 0x8001CD4C: subu        $s5, $t4, $s1
    ctx->r21 = SUB32(ctx->r12, ctx->r17);
    // 0x8001CD50: sll         $s7, $a1, 2
    ctx->r23 = S32(ctx->r5 << 2);
    // 0x8001CD54: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x8001CD58: addiu       $s7, $s7, 0x84
    ctx->r23 = ADD32(ctx->r23, 0X84);
    // 0x8001CD5C: slt         $at, $t0, $s7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8001CD60: bne         $at, $zero, L_8001CD70
    if (ctx->r1 != 0) {
        // 0x8001CD64: addiu       $s4, $zero, 0x63
        ctx->r20 = ADD32(0, 0X63);
            goto L_8001CD70;
    }
    // 0x8001CD64: addiu       $s4, $zero, 0x63
    ctx->r20 = ADD32(0, 0X63);
    // 0x8001CD68: j           L_8001CDBC
    // 0x8001CD6C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8001CDBC;
    // 0x8001CD6C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001CD70:
    // 0x8001CD70: lw          $s7, 0x0($t0)
    ctx->r23 = MEM_W(ctx->r8, 0X0);
    // 0x8001CD74: slt         $at, $s7, $a2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001CD78: beq         $at, $zero, L_8001CD9C
    if (ctx->r1 == 0) {
        // 0x8001CD7C: nop
    
            goto L_8001CD9C;
    }
    // 0x8001CD7C: nop

    // 0x8001CD80: or          $gp, $s7, $zero
    ctx->r28 = ctx->r23 | 0;
    // 0x8001CD84: slti        $at, $s7, 0x100
    ctx->r1 = SIGNED(ctx->r23) < 0X100 ? 1 : 0;
    // 0x8001CD88: bnel        $at, $zero, L_8001CD94
    if (ctx->r1 != 0) {
        // 0x8001CD8C: addiu       $s4, $zero, 0x10
        ctx->r20 = ADD32(0, 0X10);
            goto L_8001CD94;
    }
    goto skip_2;
    // 0x8001CD8C: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    skip_2:
    // 0x8001CD90: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
L_8001CD94:
    // 0x8001CD94: j           L_8001CDB8
    // 0x8001CD98: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
        goto L_8001CDB8;
    // 0x8001CD98: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8001CD9C:
    // 0x8001CD9C: subu        $s7, $s7, $a2
    ctx->r23 = SUB32(ctx->r23, ctx->r6);
    // 0x8001CDA0: addu        $s4, $s7, $t7
    ctx->r20 = ADD32(ctx->r23, ctx->r15);
    // 0x8001CDA4: lbu         $s4, 0x0($s4)
    ctx->r20 = MEM_BU(ctx->r20, 0X0);
    // 0x8001CDA8: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
    // 0x8001CDAC: addu        $s7, $s7, $a3
    ctx->r23 = ADD32(ctx->r23, ctx->r7);
    // 0x8001CDB0: lhu         $gp, 0x0($s7)
    ctx->r28 = MEM_HU(ctx->r23, 0X0);
    // 0x8001CDB4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8001CDB8:
    // 0x8001CDB8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001CDBC:
    // 0x8001CDBC: subu        $s7, $t4, $s1
    ctx->r23 = SUB32(ctx->r12, ctx->r17);
    // 0x8001CDC0: sllv        $s2, $s2, $s7
    ctx->r18 = S32(ctx->r18 << (ctx->r23 & 31));
    // 0x8001CDC4: srlv        $t3, $t1, $s1
    ctx->r11 = S32(U32(ctx->r9) >> (ctx->r17 & 31));
    // 0x8001CDC8: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001CDCC: beq         $at, $zero, L_8001CE10
    if (ctx->r1 == 0) {
        // 0x8001CDD0: sll         $s7, $s4, 24
        ctx->r23 = S32(ctx->r20 << 24);
            goto L_8001CE10;
    }
    // 0x8001CDD0: sll         $s7, $s4, 24
    ctx->r23 = S32(ctx->r20 << 24);
    // 0x8001CDD4: andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // 0x8001CDD8: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8001CDDC: or          $s7, $s7, $s5
    ctx->r23 = ctx->r23 | ctx->r21;
    // 0x8001CDE0: andi        $s5, $gp, 0xFFFF
    ctx->r21 = ctx->r28 & 0XFFFF;
    // 0x8001CDE4: or          $s5, $s5, $s7
    ctx->r21 = ctx->r21 | ctx->r23;
    // 0x8001CDE8: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8001CDEC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001CDF0: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8001CDF4: sll         $s7, $s0, 2
    ctx->r23 = S32(ctx->r16 << 2);
    // 0x8001CDF8: addu        $s7, $s7, $t6
    ctx->r23 = ADD32(ctx->r23, ctx->r14);
    // 0x8001CDFC: sw          $s5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r21;
L_8001CE00:
    // 0x8001CE00: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x8001CE04: slt         $at, $t3, $s7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8001CE08: bnel        $at, $zero, L_8001CE00
    if (ctx->r1 != 0) {
        // 0x8001CE0C: sw          $s5, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r21;
            goto L_8001CE00;
    }
    goto skip_3;
    // 0x8001CE0C: sw          $s5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r21;
    skip_3:
L_8001CE10:
    // 0x8001CE10: addiu       $s7, $t4, -0x1
    ctx->r23 = ADD32(ctx->r12, -0X1);
    // 0x8001CE14: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001CE18: sllv        $t3, $t3, $s7
    ctx->r11 = S32(ctx->r11 << (ctx->r23 & 31));
    // 0x8001CE1C: and         $s7, $t1, $t3
    ctx->r23 = ctx->r9 & ctx->r11;
    // 0x8001CE20: beq         $s7, $zero, L_8001CE38
    if (ctx->r23 == 0) {
        // 0x8001CE24: xor         $t1, $t1, $t3
        ctx->r9 = ctx->r9 ^ ctx->r11;
            goto L_8001CE38;
    }
    // 0x8001CE24: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
L_8001CE28:
    // 0x8001CE28: srl         $t3, $t3, 1
    ctx->r11 = S32(U32(ctx->r11) >> 1);
    // 0x8001CE2C: and         $s7, $t1, $t3
    ctx->r23 = ctx->r9 & ctx->r11;
    // 0x8001CE30: bne         $s7, $zero, L_8001CE28
    if (ctx->r23 != 0) {
        // 0x8001CE34: xor         $t1, $t1, $t3
        ctx->r9 = ctx->r9 ^ ctx->r11;
            goto L_8001CE28;
    }
    // 0x8001CE34: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
L_8001CE38:
    // 0x8001CE38: j           L_8001CE48
    // 0x8001CE3C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_8001CE48;
    // 0x8001CE3C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8001CE40: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001CE44:
    // 0x8001CE44: subu        $s1, $s1, $t2
    ctx->r17 = SUB32(ctx->r17, ctx->r10);
L_8001CE48:
    // 0x8001CE48: sllv        $s7, $fp, $s1
    ctx->r23 = S32(ctx->r30 << (ctx->r17 & 31));
    // 0x8001CE4C: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x8001CE50: sll         $at, $v0, 2
    ctx->r1 = S32(ctx->r2 << 2);
    // 0x8001CE54: addu        $at, $at, $sp
    ctx->r1 = ADD32(ctx->r1, ctx->r29);
    // 0x8001CE58: lw          $at, 0x504($at)
    ctx->r1 = MEM_W(ctx->r1, 0X504);
    // 0x8001CE5C: and         $s7, $s7, $t1
    ctx->r23 = ctx->r23 & ctx->r9;
    // 0x8001CE60: bnel        $s7, $at, L_8001CE44
    if (ctx->r23 != ctx->r1) {
        // 0x8001CE64: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001CE44;
    }
    goto skip_4;
    // 0x8001CE64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_4:
    // 0x8001CE68: bne         $a0, $zero, L_8001CD3C
    if (ctx->r4 != 0) {
        // 0x8001CE6C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8001CD3C;
    }
    // 0x8001CE6C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8001CE70:
    // 0x8001CE70: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_8001CE74:
    // 0x8001CE74: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001CE78: bne         $at, $zero, L_8001CE98
    if (ctx->r1 != 0) {
        // 0x8001CE7C: sll         $a0, $t4, 2
        ctx->r4 = S32(ctx->r12 << 2);
            goto L_8001CE98;
    }
    // 0x8001CE7C: sll         $a0, $t4, 2
    ctx->r4 = S32(ctx->r12 << 2);
    // 0x8001CE80: addu        $a0, $a0, $sp
    ctx->r4 = ADD32(ctx->r4, ctx->r29);
    // 0x8001CE84: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8001CE88: beq         $a0, $zero, L_8001CE70
    if (ctx->r4 == 0) {
        // 0x8001CE8C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8001CE70;
    }
    // 0x8001CE8C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8001CE90: j           L_8001CD40
    // 0x8001CE94: addu        $s7, $s1, $t2
    ctx->r23 = ADD32(ctx->r17, ctx->r10);
        goto L_8001CD40;
    // 0x8001CE94: addu        $s7, $s1, $t2
    ctx->r23 = ADD32(ctx->r17, ctx->r10);
L_8001CE98:
    // 0x8001CE98: bnel        $t9, $zero, L_8001CEA4
    if (ctx->r25 != 0) {
        // 0x8001CE9C: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_8001CEA4;
    }
    goto skip_5;
    // 0x8001CE9C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    skip_5:
    // 0x8001CEA0: addiu       $s7, $zero, 0x0
    ctx->r23 = ADD32(0, 0X0);
L_8001CEA4:
    // 0x8001CEA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CEA8: bnel        $t5, $at, L_8001CEB4
    if (ctx->r13 != ctx->r1) {
        // 0x8001CEAC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001CEB4;
    }
    goto skip_6;
    // 0x8001CEAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
    // 0x8001CEB0: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
L_8001CEB4:
    // 0x8001CEB4: and         $v0, $s7, $at
    ctx->r2 = ctx->r23 & ctx->r1;
    // 0x8001CEB8: mtc1        $s3, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r19;
L_8001CEBC:
    // 0x8001CEBC: mfc1        $s0, $f2
    ctx->r16 = (int32_t)ctx->f2.u32l;
    // 0x8001CEC0: mfc1        $s1, $f3
    ctx->r17 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x8001CEC4: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x8001CEC8: mfc1        $s3, $f5
    ctx->r19 = (int32_t)ctx->f_odd[(5 - 1) * 2];
    // 0x8001CECC: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x8001CED0: mfc1        $s5, $f7
    ctx->r21 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8001CED4: mfc1        $s6, $f8
    ctx->r22 = (int32_t)ctx->f8.u32l;
    // 0x8001CED8: mfc1        $s7, $f9
    ctx->r23 = (int32_t)ctx->f_odd[(9 - 1) * 2];
    // 0x8001CEDC: mfc1        $fp, $f10
    ctx->r30 = (int32_t)ctx->f10.u32l;
    // 0x8001CEE0: jr          $ra
    // 0x8001CEE4: mfc1        $gp, $f11
    ctx->r28 = (int32_t)ctx->f_odd[(11 - 1) * 2];
    return;
    // 0x8001CEE4: mfc1        $gp, $f11
    ctx->r28 = (int32_t)ctx->f_odd[(11 - 1) * 2];
L_8001CEE8:
    // 0x8001CEE8: jr          $ra
    // 0x8001CEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001CEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001CEF0:
    // 0x8001CEF0: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x8001CEF4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8001CEF8: j           L_8001CEBC
    // 0x8001CEFC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_8001CEBC;
    // 0x8001CEFC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080A194_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080A194: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080A198: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8080A19C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080A1A0: lw          $v1, 0x26C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X26C);
    // 0x8080A1A4: lw          $a1, 0x2A4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2A4);
    // 0x8080A1A8: xor         $a3, $v1, $t0
    ctx->r7 = ctx->r3 ^ ctx->r8;
    // 0x8080A1AC: sltiu       $a3, $a3, 0x1
    ctx->r7 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x8080A1B0: bne         $a3, $zero, L_8080A1C0
    if (ctx->r7 != 0) {
        // 0x8080A1B4: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8080A1C0;
    }
    // 0x8080A1B4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8080A1B8: xori        $a2, $v1, 0x2
    ctx->r6 = ctx->r3 ^ 0X2;
    // 0x8080A1BC: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
L_8080A1C0:
    // 0x8080A1C0: xor         $a0, $a1, $t0
    ctx->r4 = ctx->r5 ^ ctx->r8;
    // 0x8080A1C4: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x8080A1C8: beq         $a0, $zero, L_8080A1DC
    if (ctx->r4 == 0) {
        // 0x8080A1CC: addiu       $v1, $v0, 0x254
        ctx->r3 = ADD32(ctx->r2, 0X254);
            goto L_8080A1DC;
    }
    // 0x8080A1CC: addiu       $v1, $v0, 0x254
    ctx->r3 = ADD32(ctx->r2, 0X254);
    // 0x8080A1D0: bne         $a2, $zero, L_8080A1DC
    if (ctx->r6 != 0) {
        // 0x8080A1D4: nop
    
            goto L_8080A1DC;
    }
    // 0x8080A1D4: nop

    // 0x8080A1D8: sw          $zero, 0x268($v0)
    MEM_W(0X268, ctx->r2) = 0;
L_8080A1DC:
    // 0x8080A1DC: bne         $a0, $zero, L_8080A1EC
    if (ctx->r4 != 0) {
        // 0x8080A1E0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8080A1EC;
    }
    // 0x8080A1E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080A1E4: xori        $a2, $a1, 0x2
    ctx->r6 = ctx->r5 ^ 0X2;
    // 0x8080A1E8: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
L_8080A1EC:
    // 0x8080A1EC: sltiu       $t6, $a2, 0x1
    ctx->r14 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x8080A1F0: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x8080A1F4: beql        $t7, $zero, L_8080A204
    if (ctx->r15 == 0) {
        // 0x8080A1F8: lw          $t8, 0x14($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X14);
            goto L_8080A204;
    }
    goto skip_0;
    // 0x8080A1F8: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    skip_0:
    // 0x8080A1FC: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x8080A200: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
L_8080A204:
    // 0x8080A204: beql        $t8, $zero, L_8080A21C
    if (ctx->r24 == 0) {
        // 0x8080A208: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8080A21C;
    }
    goto skip_1;
    // 0x8080A208: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x8080A20C: lwc1        $f4, 0x44($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8080A210: jr          $ra
    // 0x8080A214: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x8080A214: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x8080A218: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8080A21C:
    // 0x8080A21C: lwc1        $f8, 0x48($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8080A220: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8080A224: nop

    // 0x8080A228: bc1f        L_8080A248
    if (!c1cs) {
        // 0x8080A22C: nop
    
            goto L_8080A248;
    }
    // 0x8080A22C: nop

    // 0x8080A230: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8080A234: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8080A238: bne         $at, $zero, L_8080A248
    if (ctx->r1 != 0) {
        // 0x8080A23C: nop
    
            goto L_8080A248;
    }
    // 0x8080A23C: nop

    // 0x8080A240: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8080A244: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
L_8080A248:
    // 0x8080A248: jr          $ra
    // 0x8080A24C: nop

    return;
    // 0x8080A24C: nop

;}
RECOMP_FUNC void mlspline_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801720: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801724: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80801728: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8080172C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3006, 0X1C68) << 16);
    // 0x80801730: lwc1        $f4, 0x1C68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3006, 0X1C68));
    // 0x80801734: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801738: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080173C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801740: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801744: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801748: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x8080174C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80801750: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801754: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801758: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080175C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80801760: jal         0x80801488
    // 0x80801764: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80801488_mlspline(rdram, ctx);
        goto after_0;
    // 0x80801764: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80801768: jal         0x800F2100
    // 0x8080176C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8080176C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80801770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801774: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801778: jr          $ra
    // 0x8080177C: nop

    return;
    // 0x8080177C: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F90: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F90);
    return;
    // 0x80087F94: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80809CF8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809CF8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809CFC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA5A4) << 16);
    // 0x80809D00: lwc1        $f4, -0x5A5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA5A4));
    // 0x80809D04: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80809D08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80809D0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80809D10: sw          $zero, 0x264($v0)
    MEM_W(0X264, ctx->r2) = 0;
    // 0x80809D14: swc1        $f4, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->f4.u32l;
    // 0x80809D18: swc1        $f6, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->f6.u32l;
    // 0x80809D1C: jr          $ra
    // 0x80809D20: swc1        $f8, 0x25C($v0)
    MEM_W(0X25C, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80809D20: swc1        $f8, 0x25C($v0)
    MEM_W(0X25C, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void _chtnthut_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D30: syscall     232
    recomp_syscall_handler(rdram, ctx, 0x80085D30);
    return;
    // 0x80085D34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080272C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080272C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802730: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802734: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802738: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080273C: jal         0x80100094
    // 0x80802740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802744: lbu         $v1, 0x498($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X498);
    // 0x80802748: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080274C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802750: beq         $v1, $at, L_808028FC
    if (ctx->r3 == ctx->r1) {
        // 0x80802754: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808028FC;
    }
    // 0x80802754: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802758: beq         $v1, $at, L_8080277C
    if (ctx->r3 == ctx->r1) {
        // 0x8080275C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080277C;
    }
    // 0x8080275C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802760: beq         $v1, $at, L_8080287C
    if (ctx->r3 == ctx->r1) {
        // 0x80802764: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_8080287C;
    }
    // 0x80802764: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80802768: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080276C: beql        $v1, $at, L_80802900
    if (ctx->r3 == ctx->r1) {
        // 0x80802770: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802900;
    }
    goto skip_0;
    // 0x80802770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802774: b           L_80802900
    // 0x80802778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802900;
    // 0x80802778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080277C:
    // 0x8080277C: lbu         $t6, 0x49A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49A);
    // 0x80802780: beql        $t6, $zero, L_80802900
    if (ctx->r14 == 0) {
        // 0x80802784: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802900;
    }
    goto skip_1;
    // 0x80802784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80802788: lbu         $t7, 0x499($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X499);
    // 0x8080278C: beql        $t7, $zero, L_80802900
    if (ctx->r15 == 0) {
        // 0x80802790: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802900;
    }
    goto skip_2;
    // 0x80802790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80802794: lbu         $t8, 0x49B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49B);
    // 0x80802798: bnel        $t8, $zero, L_808027FC
    if (ctx->r24 != 0) {
        // 0x8080279C: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_808027FC;
    }
    goto skip_3;
    // 0x8080279C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x808027A0: jal         0x800DA544
    // 0x808027A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808027A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808027A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808027AC: jal         0x80800F84
    // 0x808027B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_2;
    // 0x808027B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808027B4: jal         0x80104248
    // 0x808027B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80104248(rdram, ctx);
        goto after_3;
    // 0x808027B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808027BC: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808027C0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808027C4: jal         0x8008B1C8
    // 0x808027C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x808027C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808027CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808027D0: jal         0x8010A85C
    // 0x808027D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_5;
    // 0x808027D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808027D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808027DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808027E0: jal         0x80802A00
    // 0x808027E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_6;
    // 0x808027E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x808027E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808027EC: sb          $t9, 0x49B($s0)
    MEM_B(0X49B, ctx->r16) = ctx->r25;
    // 0x808027F0: jal         0x800FDC28
    // 0x808027F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_7;
    // 0x808027F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x808027F8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_808027FC:
    // 0x808027FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802800: lhu         $t1, 0x72($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X72);
    // 0x80802804: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80802808: bnel        $t2, $at, L_80802900
    if (ctx->r10 != ctx->r1) {
        // 0x8080280C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802900;
    }
    goto skip_4;
    // 0x8080280C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80802810: sb          $zero, 0x499($s0)
    MEM_B(0X499, ctx->r16) = 0;
    // 0x80802814: jal         0x800F54E4
    // 0x80802818: sb          $zero, 0x49A($s0)
    MEM_B(0X49A, ctx->r16) = 0;
    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80802818: sb          $zero, 0x49A($s0)
    MEM_B(0X49A, ctx->r16) = 0;
    after_8:
    // 0x8080281C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802820: jal         0x800F82D4
    // 0x80802824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_9;
    // 0x80802824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80802828: jal         0x800F54E4
    // 0x8080282C: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x8080282C: nop

    after_10:
    // 0x80802830: jal         0x800F497C
    // 0x80802834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F497C(rdram, ctx);
        goto after_11;
    // 0x80802834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80802838: jal         0x800F54E4
    // 0x8080283C: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x8080283C: nop

    after_12:
    // 0x80802840: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80802844: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80802848: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x8080284C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802850: jal         0x800F49D4
    // 0x80802854: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_13;
    // 0x80802854: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    after_13:
    // 0x80802858: jal         0x800F54E4
    // 0x8080285C: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x8080285C: nop

    after_14:
    // 0x80802860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802864: addiu       $a1, $s0, 0x60
    ctx->r5 = ADD32(ctx->r16, 0X60);
    // 0x80802868: jal         0x800F4A58
    // 0x8080286C: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800F4A58(rdram, ctx);
        goto after_15;
    // 0x8080286C: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_15:
    // 0x80802870: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80802874: b           L_808028FC
    // 0x80802878: sb          $t5, 0x498($s0)
    MEM_B(0X498, ctx->r16) = ctx->r13;
        goto L_808028FC;
    // 0x80802878: sb          $t5, 0x498($s0)
    MEM_B(0X498, ctx->r16) = ctx->r13;
L_8080287C:
    // 0x8080287C: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80802880: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802884: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80802888: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080288C: bnel        $t8, $at, L_80802900
    if (ctx->r24 != ctx->r1) {
        // 0x80802890: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802900;
    }
    goto skip_5;
    // 0x80802890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80802894: sb          $zero, 0x49A($s0)
    MEM_B(0X49A, ctx->r16) = 0;
    // 0x80802898: jal         0x800F54E4
    // 0x8080289C: sb          $t9, 0x499($s0)
    MEM_B(0X499, ctx->r16) = ctx->r25;
    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x8080289C: sb          $t9, 0x499($s0)
    MEM_B(0X499, ctx->r16) = ctx->r25;
    after_16:
    // 0x808028A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808028A4: jal         0x800F82D4
    // 0x808028A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_17;
    // 0x808028A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808028AC: jal         0x800F54E4
    // 0x808028B0: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808028B0: nop

    after_18:
    // 0x808028B4: jal         0x800F497C
    // 0x808028B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F497C(rdram, ctx);
        goto after_19;
    // 0x808028B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x808028BC: jal         0x800F54E4
    // 0x808028C0: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x808028C0: nop

    after_20:
    // 0x808028C4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808028C8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808028CC: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808028D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808028D4: jal         0x800F49D4
    // 0x808028D8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_21;
    // 0x808028D8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    after_21:
    // 0x808028DC: jal         0x800F54E4
    // 0x808028E0: nop

    func_800F54E4(rdram, ctx);
        goto after_22;
    // 0x808028E0: nop

    after_22:
    // 0x808028E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808028E8: addiu       $a1, $s0, 0x60
    ctx->r5 = ADD32(ctx->r16, 0X60);
    // 0x808028EC: jal         0x800F4A58
    // 0x808028F0: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800F4A58(rdram, ctx);
        goto after_23;
    // 0x808028F0: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_23:
    // 0x808028F4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x808028F8: sb          $t1, 0x498($s0)
    MEM_B(0X498, ctx->r16) = ctx->r9;
L_808028FC:
    // 0x808028FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802900:
    // 0x80802900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802904: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802908: jr          $ra
    // 0x8080290C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080290C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _gccubesearch_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882B8: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882B8);
    return;
    // 0x800882BC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bsbswim_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801818: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080181C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1F00) << 16);
    // 0x80801820: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801824: jr          $ra
    // 0x80801828: lw          $v0, 0x1F00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F00));
    return;
    // 0x80801828: lw          $v0, 0x1F00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1F00));
;}
RECOMP_FUNC void bsfirstp_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803890: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803898: jal         0x800F53D0
    // 0x8080389C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8080389C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x808038A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808038A4: jal         0x8009E6F8
    // 0x808038A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_1;
    // 0x808038A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808038AC: addiu       $at, $zero, 0xD9
    ctx->r1 = ADD32(0, 0XD9);
    // 0x808038B0: bne         $v0, $at, L_80803904
    if (ctx->r2 != ctx->r1) {
        // 0x808038B4: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80803904;
    }
    // 0x808038B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808038B8: lw          $t7, 0x188($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X188);
    // 0x808038BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808038C0: jal         0x800873F0
    // 0x808038C4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    _ch1pfreeze_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808038C4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_2:
    // 0x808038C8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808038CC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808038D0: sw          $v0, 0x114($t8)
    MEM_W(0X114, ctx->r24) = ctx->r2;
    // 0x808038D4: jal         0x8009C128
    // 0x808038D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x808038D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808038DC: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(439, 0XB4A4) << 16);
    // 0x808038E0: addiu       $a3, $a3, -0x4B5C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(439, 0XB4A4));
    // 0x808038E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x808038E8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808038EC: jal         0x8010D930
    // 0x808038F0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8010D930(rdram, ctx);
        goto after_4;
    // 0x808038F0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x808038F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808038F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808038FC: jal         0x80085338
    // 0x80803900: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x80803900: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_5:
L_80803904:
    // 0x80803904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803908: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080390C: jr          $ra
    // 0x80803910: nop

    return;
    // 0x80803910: nop

;}
