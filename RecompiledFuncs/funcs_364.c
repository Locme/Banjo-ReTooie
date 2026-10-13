#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void gctransitionDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009FC: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x80800A00: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80800A04: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80800A08: sb          $zero, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = 0;
    // 0x80800A0C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x80800A10: jal         0x800E6A00
    // 0x80800A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800E6A00(rdram, ctx);
        goto after_0;
    // 0x80800A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A24: jal         0x808000D8
    // 0x80800A28: sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    func_808000D8_gctransitionDll(rdram, ctx);
        goto after_1;
    // 0x80800A28: sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    after_1:
    // 0x80800A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A34: jr          $ra
    // 0x80800A38: nop

    return;
    // 0x80800A38: nop

;}
RECOMP_FUNC void babackpack_set_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080053C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800544: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800548: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080054C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80800550: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800558: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8080055C: bne         $v1, $at, L_80800574
    if (ctx->r3 != ctx->r1) {
        // 0x80800560: nop
    
            goto L_80800574;
    }
    // 0x80800560: nop

    // 0x80800564: jal         0x80800008
    // 0x80800568: nop

    __babackpack_free(rdram, ctx);
        goto after_0;
    // 0x80800568: nop

    after_0:
    // 0x8080056C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80800570: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_80800574:
    // 0x80800574: beq         $v1, $zero, L_808005BC
    if (ctx->r3 == 0) {
        // 0x80800578: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808005BC;
    }
    // 0x80800578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080057C: beq         $v1, $at, L_808005BC
    if (ctx->r3 == ctx->r1) {
        // 0x80800580: lw          $t6, 0x34($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X34);
            goto L_808005BC;
    }
    // 0x80800580: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800584: beq         $t6, $zero, L_808005BC
    if (ctx->r14 == 0) {
        // 0x80800588: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808005BC;
    }
    // 0x80800588: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080058C: beql        $t6, $at, L_808005C0
    if (ctx->r14 == ctx->r1) {
        // 0x80800590: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_808005C0;
    }
    goto skip_0;
    // 0x80800590: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80800594: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x80800598: beq         $v1, $zero, L_808005B0
    if (ctx->r3 == 0) {
        // 0x8080059C: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_808005B0;
    }
    // 0x8080059C: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x808005A0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x808005A4: jal         0x80100E18
    // 0x808005A8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80100E18(rdram, ctx);
        goto after_1;
    // 0x808005A8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x808005AC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_808005B0:
    // 0x808005B0: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x808005B4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x808005B8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_808005BC:
    // 0x808005BC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808005C0:
    // 0x808005C0: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x808005C4: beq         $at, $zero, L_80800724
    if (ctx->r1 == 0) {
        // 0x808005C8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800724;
    }
    // 0x808005C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808005CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(456, 0X750) << 16);
    // 0x808005D0: addu        $at, $at, $t9
    gpr jr_addend_808005D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808005D4: lw          $t9, 0x750($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(456, 0X750));
    // 0x808005D8: jr          $t9
    // 0x808005DC: nop

    switch (jr_addend_808005D8 >> 2) {
        case 0: goto L_808005E0; break;
        case 1: goto L_808005F4; break;
        case 2: goto L_80800668; break;
        case 3: goto L_80800680; break;
        case 4: goto L_8080069C; break;
        case 5: goto L_808006B8; break;
        case 6: goto L_808006D4; break;
        case 7: goto L_808006F0; break;
        default: switch_error(__func__, 0x808005D8, 0x80800750);
    }
    // 0x808005DC: nop

L_808005E0:
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E4: jal         0x8009272C
    // 0x808005E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009272C(rdram, ctx);
        goto after_2;
    // 0x808005E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808005EC: b           L_80800728
    // 0x808005F0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x808005F0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_808005F4:
    // 0x808005F4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x808005F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80800604: beql        $t0, $at, L_8080072C
    if (ctx->r8 == ctx->r1) {
        // 0x80800608: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_8080072C;
    }
    goto skip_1;
    // 0x80800608: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8080060C: jal         0x8009272C
    // 0x80800610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009272C(rdram, ctx);
        goto after_3;
    // 0x80800610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800614: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80800618: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8080061C: beql        $a0, $zero, L_80800634
    if (ctx->r4 == 0) {
        // 0x80800620: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_80800634;
    }
    goto skip_2;
    // 0x80800620: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    skip_2:
    // 0x80800624: jal         0x800DBFD8
    // 0x80800628: nop

    func_800DBFD8(rdram, ctx);
        goto after_4;
    // 0x80800628: nop

    after_4:
    // 0x8080062C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80800630: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_80800634:
    // 0x80800634: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80800638: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x8080063C: beq         $v1, $zero, L_80800654
    if (ctx->r3 == 0) {
        // 0x80800640: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_80800654;
    }
    // 0x80800640: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80800644: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800648: jal         0x80100E18
    // 0x8080064C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_80100E18(rdram, ctx);
        goto after_5;
    // 0x8080064C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_5:
    // 0x80800650: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80800654:
    // 0x80800654: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // 0x80800658: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x8080065C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80800660: b           L_80800728
    // 0x80800664: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x80800664: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80800668:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: addiu       $a1, $zero, 0x621
    ctx->r5 = ADD32(0, 0X621);
    // 0x80800670: jal         0x8080011C
    // 0x80800674: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8080011C_babackpack(rdram, ctx);
        goto after_6;
    // 0x80800674: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x80800678: b           L_80800728
    // 0x8080067C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x8080067C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80800680:
    // 0x80800680: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800684: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x8080011C
    // 0x80800690: addiu       $a1, $zero, 0x625
    ctx->r5 = ADD32(0, 0X625);
    func_8080011C_babackpack(rdram, ctx);
        goto after_7;
    // 0x80800690: addiu       $a1, $zero, 0x625
    ctx->r5 = ADD32(0, 0X625);
    after_7:
    // 0x80800694: b           L_80800728
    // 0x80800698: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x80800698: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_8080069C:
    // 0x8080069C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808006A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x8080011C
    // 0x808006AC: addiu       $a1, $zero, 0x60A
    ctx->r5 = ADD32(0, 0X60A);
    func_8080011C_babackpack(rdram, ctx);
        goto after_8;
    // 0x808006AC: addiu       $a1, $zero, 0x60A
    ctx->r5 = ADD32(0, 0X60A);
    after_8:
    // 0x808006B0: b           L_80800728
    // 0x808006B4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x808006B4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_808006B8:
    // 0x808006B8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808006BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x8080011C
    // 0x808006C8: addiu       $a1, $zero, 0x61B
    ctx->r5 = ADD32(0, 0X61B);
    func_8080011C_babackpack(rdram, ctx);
        goto after_9;
    // 0x808006C8: addiu       $a1, $zero, 0x61B
    ctx->r5 = ADD32(0, 0X61B);
    after_9:
    // 0x808006CC: b           L_80800728
    // 0x808006D0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x808006D0: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_808006D4:
    // 0x808006D4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808006D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: jal         0x8080011C
    // 0x808006E4: addiu       $a1, $zero, 0x831
    ctx->r5 = ADD32(0, 0X831);
    func_8080011C_babackpack(rdram, ctx);
        goto after_10;
    // 0x808006E4: addiu       $a1, $zero, 0x831
    ctx->r5 = ADD32(0, 0X831);
    after_10:
    // 0x808006E8: b           L_80800728
    // 0x808006EC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x808006EC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_808006F0:
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808006F8: addiu       $a2, $sp, 0x2E
    ctx->r6 = ADD32(ctx->r29, 0X2E);
    // 0x808006FC: jal         0x80084F38
    // 0x80800700: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    _bapreload_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800700: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_11:
    // 0x80800704: jal         0x8080003C
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080003C_babackpack(rdram, ctx);
        goto after_12;
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x80800714: jal         0x8080011C
    // 0x80800718: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8080011C_babackpack(rdram, ctx);
        goto after_13;
    // 0x80800718: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_13:
    // 0x8080071C: b           L_80800728
    // 0x80800720: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80800728;
    // 0x80800720: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80800724:
    // 0x80800724: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80800728:
    // 0x80800728: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_8080072C:
    // 0x8080072C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80800730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800734: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800738: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_80804B10_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804B10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804B14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804B18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804B1C: jal         0x80807BB8
    // 0x80804B20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804B20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B28: jal         0x800A3410
    // 0x80804B2C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800A3410(rdram, ctx);
        goto after_1;
    // 0x80804B2C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80804B30: jal         0x80807DD4
    // 0x80804B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807DD4_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80804B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B3C: jal         0x800936E8
    // 0x80804B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800936E8(rdram, ctx);
        goto after_3;
    // 0x80804B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80804B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B48: addiu       $a1, $zero, 0x30C
    ctx->r5 = ADD32(0, 0X30C);
    // 0x80804B4C: jal         0x8008CCBC
    // 0x80804B50: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x80804B50: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_4:
    // 0x80804B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B58: addiu       $a1, $zero, 0x310
    ctx->r5 = ADD32(0, 0X310);
    // 0x80804B5C: jal         0x808003B4
    // 0x80804B60: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_808003B4_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80804B60: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_5:
    // 0x80804B64: jal         0x80804A34
    // 0x80804B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80804A34_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80804B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80804B6C: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80804B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804B74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804B7C: jr          $ra
    // 0x80804B80: nop

    return;
    // 0x80804B80: nop

;}
RECOMP_FUNC void func_808002E4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x808002E8: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x808002EC: bltz        $t7, L_808002FC
    if (SIGNED(ctx->r15) < 0) {
        // 0x808002F0: srl         $t8, $v0, 31
        ctx->r24 = S32(U32(ctx->r2) >> 31);
            goto L_808002FC;
    }
    // 0x808002F0: srl         $t8, $v0, 31
    ctx->r24 = S32(U32(ctx->r2) >> 31);
    // 0x808002F4: beq         $t8, $zero, L_8080033C
    if (ctx->r24 == 0) {
        // 0x808002F8: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_8080033C;
    }
    // 0x808002F8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_808002FC:
    // 0x808002FC: lbu         $t0, 0x1CC($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1CC);
    // 0x80800300: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800304: sb          $t9, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r25;
    // 0x80800308: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8080030C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800310: bgez        $t0, L_80800324
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800314: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800324;
    }
    // 0x80800314: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800318: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080031C: nop

    // 0x80800320: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800324:
    // 0x80800324: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080032C: nop

    // 0x80800330: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800334: b           L_80800340
    // 0x80800338: swc1        $f16, 0x1C4($a0)
    MEM_W(0X1C4, ctx->r4) = ctx->f16.u32l;
        goto L_80800340;
    // 0x80800338: swc1        $f16, 0x1C4($a0)
    MEM_W(0X1C4, ctx->r4) = ctx->f16.u32l;
L_8080033C:
    // 0x8080033C: sb          $t1, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r9;
L_80800340:
    // 0x80800340: lbu         $t3, 0x1E5($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1E5);
    // 0x80800344: lbu         $t2, 0x19C($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X19C);
    // 0x80800348: andi        $t4, $t3, 0xFF7F
    ctx->r12 = ctx->r11 & 0XFF7F;
    // 0x8080034C: sb          $t4, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r12;
    // 0x80800350: jr          $ra
    // 0x80800354: sb          $t2, 0x19E($a0)
    MEM_B(0X19E, ctx->r4) = ctx->r10;
    return;
    // 0x80800354: sb          $t2, 0x19E($a0)
    MEM_B(0X19E, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_808000CC_basub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000D8: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E0: swc1        $f0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f0.u32l;
    // 0x808000E4: lw          $t7, 0x130($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X130);
    // 0x808000E8: sb          $zero, 0x5E($t7)
    MEM_B(0X5E, ctx->r15) = 0;
    // 0x808000EC: lw          $t8, 0x130($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X130);
    // 0x808000F0: swc1        $f0, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->f0.u32l;
    // 0x808000F4: lw          $t9, 0x130($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X130);
    // 0x808000F8: jal         0x80800008
    // 0x808000FC: sb          $zero, 0x5D($t9)
    MEM_B(0X5D, ctx->r25) = 0;
    func_80800008_basub(rdram, ctx);
        goto after_0;
    // 0x808000FC: sb          $zero, 0x5D($t9)
    MEM_B(0X5D, ctx->r25) = 0;
    after_0:
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_80800878_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080087C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800884: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800888: bne         $a3, $zero, L_80800894
    if (ctx->r7 != 0) {
        // 0x8080088C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800894;
    }
    // 0x8080088C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800890: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
L_80800894:
    // 0x80800894: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080089C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808008A0: lw          $v0, 0x28($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X28);
    // 0x808008A4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x808008A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808008AC: beql        $v0, $zero, L_808008D8
    if (ctx->r2 == 0) {
        // 0x808008B0: lw          $a0, 0x0($t8)
        ctx->r4 = MEM_W(ctx->r24, 0X0);
            goto L_808008D8;
    }
    goto skip_0;
    // 0x808008B0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    skip_0:
    // 0x808008B4: beq         $v0, $at, L_808008F0
    if (ctx->r2 == ctx->r1) {
        // 0x808008B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808008F0;
    }
    // 0x808008B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008BC: beq         $v0, $at, L_808008E4
    if (ctx->r2 == ctx->r1) {
        // 0x808008C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008E4;
    }
    // 0x808008C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808008C4: beql        $v0, $at, L_808008E8
    if (ctx->r2 == ctx->r1) {
        // 0x808008C8: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808008E8;
    }
    goto skip_1;
    // 0x808008C8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x808008CC: b           L_80800904
    // 0x808008D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800904;
    // 0x808008D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008D4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
L_808008D8:
    // 0x808008D8: jal         0x800856B0
    // 0x808008DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808008DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808008E0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_808008E4:
    // 0x808008E4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_808008E8:
    // 0x808008E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808008EC: sw          $t9, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r25;
L_808008F0:
    // 0x808008F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808008F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808008F8: jal         0x800856D0
    // 0x808008FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808008FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800904:
    // 0x80800904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800908: jr          $ra
    // 0x8080090C: nop

    return;
    // 0x8080090C: nop

;}
RECOMP_FUNC void func_801110EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801110EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801110F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801110F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801110F8: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x801110FC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80111100: bne         $t6, $at, L_80111124
    if (ctx->r14 != ctx->r1) {
        // 0x80111104: nop
    
            goto L_80111124;
    }
    // 0x80111104: nop

    // 0x80111108: jal         0x800894B8
    // 0x8011110C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _ncbatarget_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8011110C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80111110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80111114: jal         0x800894B0
    // 0x80111118: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _ncbatarget_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80111118: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8011111C: b           L_8011112C
    // 0x80111120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8011112C;
    // 0x80111120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80111124:
    // 0x80111124: b           L_8011112C
    // 0x80111128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8011112C;
    // 0x80111128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8011112C:
    // 0x8011112C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111134: jr          $ra
    // 0x80111138: nop

    return;
    // 0x80111138: nop

;}
RECOMP_FUNC void func_8080026C_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800278: jal         0x800D035C
    // 0x8080027C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x8080027C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80800280: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80800284: bnel        $at, $zero, L_80800298
    if (ctx->r1 != 0) {
        // 0x80800288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800298;
    }
    goto skip_0;
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080028C: jal         0x800FFAB0
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800298:
    // 0x80800298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void func_800A8A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8A88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A8A8C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A8A90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A8A94: addiu       $t7, $t7, 0x7688
    ctx->r15 = ADD32(ctx->r15, 0X7688);
    // 0x800A8A98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A8A9C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800A8AA0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800A8AA4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A8AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8AB0: beq         $a2, $zero, L_800A8AC4
    if (ctx->r6 == 0) {
        // 0x800A8AB4: swc1        $f12, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
            goto L_800A8AC4;
    }
    // 0x800A8AB4: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800A8AB8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800A8ABC: jal         0x800CA558
    // 0x800A8AC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800CA558(rdram, ctx);
        goto after_0;
    // 0x800A8AC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_800A8AC4:
    // 0x800A8AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A8AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8ACC: jr          $ra
    // 0x800A8AD0: nop

    return;
    // 0x800A8AD0: nop

;}
RECOMP_FUNC void func_801108A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801108A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801108A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801108A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801108AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801108B0: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x801108B4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801108B8: jal         0x8010FFB0
    // 0x801108BC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8010FFB0(rdram, ctx);
        goto after_0;
    // 0x801108BC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x801108C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801108C4: jal         0x80110770
    // 0x801108C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80110770(rdram, ctx);
        goto after_1;
    // 0x801108C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x801108CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801108D0: jal         0x80110790
    // 0x801108D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80110790(rdram, ctx);
        goto after_2;
    // 0x801108D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x801108D8: jal         0x80111348
    // 0x801108DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111348(rdram, ctx);
        goto after_3;
    // 0x801108DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801108E0: jal         0x801106A0
    // 0x801108E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801106A0(rdram, ctx);
        goto after_4;
    // 0x801108E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801108E8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x801108EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801108F0: jal         0x801106A8
    // 0x801108F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801106A8(rdram, ctx);
        goto after_5;
    // 0x801108F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x801108F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801108FC: jal         0x801106A8
    // 0x80110900: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801106A8(rdram, ctx);
        goto after_6;
    // 0x80110900: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x80110904: jal         0x800893D0
    // 0x80110908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _ncba1p_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80110908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8011090C: jal         0x80112398
    // 0x80110910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80112398(rdram, ctx);
        goto after_8;
    // 0x80110910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80110914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80110918: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8011091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80110920: jr          $ra
    // 0x80110924: nop

    return;
    // 0x80110924: nop

;}
RECOMP_FUNC void func_800BDC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BDC54: jr          $ra
    // 0x800BDC58: lw          $v0, -0x7BCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7BCC);
    return;
    // 0x800BDC58: lw          $v0, -0x7BCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7BCC);
;}
RECOMP_FUNC void func_808007EC_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007FC: beq         $a1, $zero, L_808008C0
    if (ctx->r5 == 0) {
        // 0x80800800: sw          $a1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r5;
            goto L_808008C0;
    }
    // 0x80800800: sw          $a1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r5;
    // 0x80800804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800808: beq         $a1, $at, L_80800824
    if (ctx->r5 == ctx->r1) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800824;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800814: beq         $a1, $at, L_8080086C
    if (ctx->r5 == ctx->r1) {
        // 0x80800818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080086C;
    }
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: b           L_8080091C
    // 0x80800820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080091C;
    // 0x80800820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800824:
    // 0x80800824: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80800828: jal         0x8008CCBC
    // 0x8080082C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080082C: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_0:
    // 0x80800830: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800834: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800844: jal         0x8009FFD8
    // 0x80800848: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800848: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: jal         0x8009B9B0
    // 0x80800854: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800854: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x808000D4
    // 0x80800860: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_808000D4_bstnt(rdram, ctx);
        goto after_3;
    // 0x80800860: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_3:
    // 0x80800864: b           L_8080091C
    // 0x80800868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080091C;
    // 0x80800868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080086C:
    // 0x8080086C: jal         0x808006B4
    // 0x80800870: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808006B4_bstnt(rdram, ctx);
        goto after_4;
    // 0x80800870: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x80800874: jal         0x808005F4
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F4_bstnt(rdram, ctx);
        goto after_5;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x800A17A8
    // 0x80800884: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_6;
    // 0x80800884: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_6:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: jal         0x800931AC
    // 0x80800890: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800931AC(rdram, ctx);
        goto after_7;
    // 0x80800890: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800894: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: jal         0x8009C984
    // 0x808008A4: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    yaw_get(rdram, ctx);
        goto after_8;
    // 0x808008A4: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x808008A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008AC: swc1        $f0, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f0.u32l;
    // 0x808008B0: jal         0x8009328C
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009328C(rdram, ctx);
        goto after_9;
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808008B8: b           L_8080091C
    // 0x808008BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080091C;
    // 0x808008BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008C0:
    // 0x808008C0: jal         0x80092BE8
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092BE8(rdram, ctx);
        goto after_10;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808008C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008CC: jal         0x8009C914
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808008D4: jal         0x8009C974
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_12;
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: jal         0x800931AC
    // 0x808008E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_13;
    // 0x808008E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808008E8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808008EC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808008F0: jal         0x808000D4
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000D4_bstnt(rdram, ctx);
        goto after_14;
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808008F8: jal         0x8009BC34
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BC34(rdram, ctx);
        goto after_15;
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x8009BF5C
    // 0x80800908: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_16;
    // 0x80800908: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800910: jal         0x8009C4CC
    // 0x80800914: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_17;
    // 0x80800914: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_17:
    // 0x80800918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080091C:
    // 0x8080091C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800920: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800924: jr          $ra
    // 0x80800928: nop

    return;
    // 0x80800928: nop

;}
RECOMP_FUNC void mlspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800004: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080000C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80800010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800014: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800018: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8080001C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800020: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80800024: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80800028: beql        $v0, $a1, L_80800060
    if (ctx->r2 == ctx->r5) {
        // 0x8080002C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80800060;
    }
    goto skip_0;
    // 0x8080002C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x80800030: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80800034:
    // 0x80800034: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800038: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080003C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800040: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80800044: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800048: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8080004C: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80800050: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80800054: bnel        $v0, $a1, L_80800034
    if (ctx->r2 != ctx->r5) {
        // 0x80800058: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80800034;
    }
    goto skip_1;
    // 0x80800058: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8080005C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80800060:
    // 0x80800060: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800064: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800068: swc1        $f14, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void func_80102B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102B6C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80102B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102B78: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80102B7C: lw          $a2, 0x50($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X50);
    // 0x80102B80: lw          $a1, 0x44($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X44);
    // 0x80102B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102B88: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80102B8C: jal         0x80102A04
    // 0x80102B90: nop

    func_80102A04(rdram, ctx);
        goto after_0;
    // 0x80102B90: nop

    after_0:
    // 0x80102B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80102B98: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80102B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102BA4: jr          $ra
    // 0x80102BA8: nop

    return;
    // 0x80102BA8: nop

;}
RECOMP_FUNC void func_80800000_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800010: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80800014: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800018: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080001C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800020: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800024: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800028: bc1f        L_8080007C
    if (!c1cs) {
        // 0x8080002C: nop
    
            goto L_8080007C;
    }
    // 0x8080002C: nop

    // 0x80800030: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800034: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800040: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80800044: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800048: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080004C: jal         0x800889D0
    // 0x80800050: nop

    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2160, 0X8F4) << 16);
    // 0x80800058: addiu       $t7, $t7, 0x8F4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2160, 0X8F4));
    // 0x8080005C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080006C: jal         0x800BABB8
    // 0x80800070: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800070: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80800074: b           L_808000A8
    // 0x80800078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808000A8;
    // 0x80800078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080007C:
    // 0x8080007C: jal         0x80088970
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _fxdlsmoke_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800084: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2160, 0X918) << 16);
    // 0x80800088: addiu       $t8, $t8, 0x918
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2160, 0X918));
    // 0x8080008C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800094: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080009C: jal         0x800BABB8
    // 0x808000A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808000A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x808000A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A8:
    // 0x808000A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_808001B0_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001BC: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x808001C0: addiu       $a0, $zero, 0x6B1
    ctx->r4 = ADD32(0, 0X6B1);
    // 0x808001C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001C8: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808001CC: addiu       $t9, $t8, -0x32
    ctx->r25 = ADD32(ctx->r24, -0X32);
    // 0x808001D0: jal         0x800DA564
    // 0x808001D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808001D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x808001D8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808001DC: beql        $v0, $at, L_808002BC
    if (ctx->r2 == ctx->r1) {
        // 0x808001E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002BC;
    }
    goto skip_0;
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001E4: jal         0x80800150
    // 0x808001E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800150_chmermaidstatue(rdram, ctx);
        goto after_1;
    // 0x808001E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x808001F4: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x808001F8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808001FC: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80800200: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80800204: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1144, 0X330) << 16);
    // 0x80800208: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8080020C: lh          $t3, 0x330($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(1144, 0X330));
    // 0x80800210: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800214: addiu       $a0, $zero, 0x6B1
    ctx->r4 = ADD32(0, 0X6B1);
    // 0x80800218: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080021C: bne         $t0, $t3, L_808002A8
    if (ctx->r8 != ctx->r11) {
        // 0x80800220: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_808002A8;
    }
    // 0x80800220: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800224: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800228: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8080022C: addiu       $a0, $zero, 0x6B1
    ctx->r4 = ADD32(0, 0X6B1);
    // 0x80800230: jal         0x800DA7A8
    // 0x80800234: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x80800234: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800238: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080023C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800240: bne         $v1, $at, L_80800298
    if (ctx->r3 != ctx->r1) {
        // 0x80800244: nop
    
            goto L_80800298;
    }
    // 0x80800244: nop

    // 0x80800248: jal         0x800DA298
    // 0x8080024C: addiu       $a0, $zero, 0x18D
    ctx->r4 = ADD32(0, 0X18D);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080024C: addiu       $a0, $zero, 0x18D
    ctx->r4 = ADD32(0, 0X18D);
    after_3:
    // 0x80800250: bnel        $v0, $zero, L_808002BC
    if (ctx->r2 != 0) {
        // 0x80800254: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002BC;
    }
    goto skip_1;
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800258: jal         0x800FC660
    // 0x8080025C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x8080025C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x80800260: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800268: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8080026C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800270: jal         0x80085708
    // 0x80800274: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800274: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_5:
    // 0x80800278: addiu       $a0, $zero, 0x3C1
    ctx->r4 = ADD32(0, 0X3C1);
    // 0x8080027C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800280: jal         0x80101180
    // 0x80800284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800288: jal         0x800DA544
    // 0x8080028C: addiu       $a0, $zero, 0x18D
    ctx->r4 = ADD32(0, 0X18D);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x8080028C: addiu       $a0, $zero, 0x18D
    ctx->r4 = ADD32(0, 0X18D);
    after_7:
    // 0x80800290: b           L_808002BC
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002BC;
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800298:
    // 0x80800298: jal         0x800FC660
    // 0x8080029C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_8;
    // 0x8080029C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_8:
    // 0x808002A0: b           L_808002BC
    // 0x808002A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002BC;
    // 0x808002A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002A8:
    // 0x808002A8: jal         0x800DA7A8
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA7A8(rdram, ctx);
        goto after_9;
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808002B0: jal         0x800FC660
    // 0x808002B4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_10;
    // 0x808002B4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_10:
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002BC:
    // 0x808002BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void func_80800000_bamovethrust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x8009BFCC
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080001C: jal         0x8009C984
    // 0x80800020: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800024: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800028: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080002C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800030: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800034: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800038: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080003C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80800040: jal         0x800EF4E4
    // 0x80800044: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_2;
    // 0x80800044: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080004C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void _ncbatarget_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894A8: syscall     782
    recomp_syscall_handler(rdram, ctx, 0x800894A8);
    return;
    // 0x800894AC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80018634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018638: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001863C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80018640: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80018644: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80018648: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001864C: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80018650: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80018654: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80018658: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001865C: addiu       $s4, $s4, -0x50F4
    ctx->r20 = ADD32(ctx->r20, -0X50F4);
    // 0x80018660: addiu       $s1, $s1, -0x4D30
    ctx->r17 = ADD32(ctx->r17, -0X4D30);
    // 0x80018664: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80018668: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_8001866C:
    // 0x8001866C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80018670: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80018674: addiu       $s2, $s1, 0x1C
    ctx->r18 = ADD32(ctx->r17, 0X1C);
    // 0x80018678: beql        $t6, $zero, L_800186D8
    if (ctx->r14 == 0) {
        // 0x8001867C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800186D8;
    }
    goto skip_0;
    // 0x8001867C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x80018680: jal         0x80016934
    // 0x80018684: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x80018684: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x80018688: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x8001868C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80018690: jal         0x800308B4
    // 0x80018694: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x80018694: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80018698: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001869C: beq         $t7, $zero, L_800186CC
    if (ctx->r15 == 0) {
        // 0x800186A0: sw          $t7, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r15;
            goto L_800186CC;
    }
    // 0x800186A0: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800186A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800186A8:
    // 0x800186A8: jal         0x80030640
    // 0x800186AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x800186AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800186B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800186B4: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x800186B8: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800186BC: beq         $at, $zero, L_800186CC
    if (ctx->r1 == 0) {
        // 0x800186C0: sw          $t9, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r25;
            goto L_800186CC;
    }
    // 0x800186C0: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800186C4: bnel        $t9, $zero, L_800186A8
    if (ctx->r25 != 0) {
        // 0x800186C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800186A8;
    }
    goto skip_1;
    // 0x800186C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_800186CC:
    // 0x800186CC: jal         0x80016934
    // 0x800186D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_3;
    // 0x800186D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800186D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800186D8:
    // 0x800186D8: bne         $s3, $s5, L_8001866C
    if (ctx->r19 != ctx->r21) {
        // 0x800186DC: addiu       $s1, $s1, 0x84
        ctx->r17 = ADD32(ctx->r17, 0X84);
            goto L_8001866C;
    }
    // 0x800186DC: addiu       $s1, $s1, 0x84
    ctx->r17 = ADD32(ctx->r17, 0X84);
    // 0x800186E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800186E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800186E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800186EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800186F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800186F4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800186F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800186FC: jr          $ra
    // 0x80018700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80018700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80096DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096DD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80096DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096DDC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80096DE0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80096DE4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80096DE8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80096DEC: jal         0x800EE7F8
    // 0x80096DF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80096DF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80096DF4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80096DF8: jal         0x800EE7F8
    // 0x80096DFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80096DFC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80096E00: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80096E04: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80096E08: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80096E0C: jal         0x80096ACC
    // 0x80096E10: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80096ACC(rdram, ctx);
        goto after_2;
    // 0x80096E10: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80096E14: bne         $v0, $zero, L_80096E24
    if (ctx->r2 != 0) {
        // 0x80096E18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80096E24;
    }
    // 0x80096E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096E1C: b           L_80096E28
    // 0x80096E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80096E28;
    // 0x80096E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80096E24:
    // 0x80096E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80096E28:
    // 0x80096E28: jr          $ra
    // 0x80096E2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80096E2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808006D0_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006E0: jal         0x8008CABC
    // 0x808006E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808006E8: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x808006EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808006F0: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x808006F4: jal         0x8008B348
    // 0x808006F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x808006F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808006FC: beq         $v0, $zero, L_8080070C
    if (ctx->r2 == 0) {
        // 0x80800700: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080070C;
    }
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x8009FD24
    // 0x80800708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FD24(rdram, ctx);
        goto after_2;
    // 0x80800708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_8080070C:
    // 0x8080070C: lui         $a1, 0x3F61
    ctx->r5 = S32(0X3F61 << 16);
    // 0x80800710: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80800714: jal         0x8008B348
    // 0x80800718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800718: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080071C: beq         $v0, $zero, L_8080072C
    if (ctx->r2 == 0) {
        // 0x80800720: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080072C;
    }
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: jal         0x8009FD24
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009FD24(rdram, ctx);
        goto after_4;
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_8080072C:
    // 0x8080072C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800730: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800734: jal         0x8008B348
    // 0x80800738: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800738: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8080073C: beq         $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800740: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_8080075C;
    }
    // 0x80800740: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800744: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80800748: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080074C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: jal         0x8009DE74
    // 0x80800758: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_6;
    // 0x80800758: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_6:
L_8080075C:
    // 0x8080075C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800760: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800764: jal         0x8008B348
    // 0x80800768: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800768: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8080076C: beq         $v0, $zero, L_8080078C
    if (ctx->r2 == 0) {
        // 0x80800770: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080078C;
    }
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800778: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x8080077C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800780: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800784: jal         0x8009DE74
    // 0x80800788: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_8;
    // 0x80800788: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_8:
L_8080078C:
    // 0x8080078C: jal         0x808000B0
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B0_bsvanswim(rdram, ctx);
        goto after_9;
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800794: jal         0x8009EF10
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_10;
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080079C: bne         $v0, $zero, L_808007A8
    if (ctx->r2 != 0) {
        // 0x808007A0: addiu       $t6, $zero, 0x11B
        ctx->r14 = ADD32(0, 0X11B);
            goto L_808007A8;
    }
    // 0x808007A0: addiu       $t6, $zero, 0x11B
    ctx->r14 = ADD32(0, 0X11B);
    // 0x808007A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808007A8:
    // 0x808007A8: jal         0x8008E35C
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808007B0: bne         $v0, $zero, L_808007BC
    if (ctx->r2 != 0) {
        // 0x808007B4: addiu       $t7, $zero, 0x11A
        ctx->r15 = ADD32(0, 0X11A);
            goto L_808007BC;
    }
    // 0x808007B4: addiu       $t7, $zero, 0x11A
    ctx->r15 = ADD32(0, 0X11A);
    // 0x808007B8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808007BC:
    // 0x808007BC: jal         0x80096500
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_12;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808007C4: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x808007C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007E0;
    }
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007CC: jal         0x80091A58
    // 0x808007D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x808007D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x808007D4: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x808007D8: addiu       $t8, $zero, 0x115
        ctx->r24 = ADD32(0, 0X115);
            goto L_808007E0;
    }
    // 0x808007D8: addiu       $t8, $zero, 0x115
    ctx->r24 = ADD32(0, 0X115);
    // 0x808007DC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808007E0:
    // 0x808007E0: jal         0x80084138
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsvan_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: jal         0x8009E5C8
    // 0x808007F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x808007F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808007F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800800: jr          $ra
    // 0x80800804: nop

    return;
    // 0x80800804: nop

;}
RECOMP_FUNC void func_80102FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102FE8: beql        $a1, $zero, L_80103004
    if (ctx->r5 == 0) {
        // 0x80102FEC: lbu         $t9, 0x77($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X77);
            goto L_80103004;
    }
    goto skip_0;
    // 0x80102FEC: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
    skip_0:
    // 0x80102FF0: lbu         $t7, 0x77($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X77);
    // 0x80102FF4: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80102FF8: jr          $ra
    // 0x80102FFC: sb          $t8, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r24;
    return;
    // 0x80102FFC: sb          $t8, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r24;
    // 0x80103000: lbu         $t9, 0x77($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X77);
L_80103004:
    // 0x80103004: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80103008: sb          $t0, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r8;
    // 0x8010300C: jr          $ra
    // 0x80103010: nop

    return;
    // 0x80103010: nop

;}
RECOMP_FUNC void func_800BC948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC948: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BC94C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800BC950: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BC954: addiu       $s0, $s0, -0x7D20
    ctx->r16 = ADD32(ctx->r16, -0X7D20);
    // 0x800BC958: lbu         $t6, 0xD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XD);
    // 0x800BC95C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800BC960: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800BC964: beq         $t6, $zero, L_800BCC14
    if (ctx->r14 == 0) {
        // 0x800BC968: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_800BCC14;
    }
    // 0x800BC968: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC96C: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x800BC970: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800BC974: lui         $t8, 0xDF00
    ctx->r24 = S32(0XDF00 << 16);
    // 0x800BC978: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BC97C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800BC980: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BC984: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BC988: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x800BC98C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800BC990: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BC994: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800BC998: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BC99C: subu        $a1, $t2, $a0
    ctx->r5 = SUB32(ctx->r10, ctx->r4);
    // 0x800BC9A0: sra         $t3, $a1, 3
    ctx->r11 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800BC9A4: jal         0x8002E660
    // 0x800BC9A8: sll         $a1, $t3, 3
    ctx->r5 = S32(ctx->r11 << 3);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800BC9A8: sll         $a1, $t3, 3
    ctx->r5 = S32(ctx->r11 << 3);
    after_0:
    // 0x800BC9AC: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800BC9B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BC9B4: jal         0x800E42E4
    // 0x800BC9B8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    func_800E42E4(rdram, ctx);
        goto after_1;
    // 0x800BC9B8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    after_1:
    // 0x800BC9BC: lbu         $t6, 0xC($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XC);
    // 0x800BC9C0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800BC9C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC9C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BC9CC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800BC9D0: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800BC9D4: addiu       $t9, $t8, 0xC8
    ctx->r25 = ADD32(ctx->r24, 0XC8);
    // 0x800BC9D8: jal         0x800E4640
    // 0x800BC9DC: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    func_800E4640(rdram, ctx);
        goto after_2;
    // 0x800BC9DC: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    after_2:
    // 0x800BC9E0: jal         0x800BCC90
    // 0x800BC9E4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_800BCC90(rdram, ctx);
        goto after_3;
    // 0x800BC9E4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x800BC9E8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800BC9EC: lui         $t2, 0xDF00
    ctx->r10 = S32(0XDF00 << 16);
    // 0x800BC9F0: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800BC9F4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800BC9F8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800BC9FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800BCA00: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800BCA04: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCA08: jal         0x800E4640
    // 0x800BCA0C: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    func_800E4640(rdram, ctx);
        goto after_4;
    // 0x800BCA0C: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    after_4:
    // 0x800BCA10: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCA14: lui         $t6, 0xDF00
    ctx->r14 = S32(0XDF00 << 16);
    // 0x800BCA18: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800BCA1C: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x800BCA20: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800BCA24: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800BCA28: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x800BCA2C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCA30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BCA34: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800BCA38: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800BCA3C: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x800BCA40: subu        $a1, $t9, $v0
    ctx->r5 = SUB32(ctx->r25, ctx->r2);
    // 0x800BCA44: addiu       $a1, $a1, -0xC8
    ctx->r5 = ADD32(ctx->r5, -0XC8);
    // 0x800BCA48: sra         $t0, $a1, 3
    ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800BCA4C: sll         $a1, $t0, 3
    ctx->r5 = S32(ctx->r8 << 3);
    // 0x800BCA50: jal         0x8002E660
    // 0x800BCA54: addiu       $a0, $v0, 0xC8
    ctx->r4 = ADD32(ctx->r2, 0XC8);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x800BCA54: addiu       $a0, $v0, 0xC8
    ctx->r4 = ADD32(ctx->r2, 0XC8);
    after_5:
    // 0x800BCA58: lbu         $t2, 0xE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XE);
    // 0x800BCA5C: beql        $t2, $zero, L_800BCA90
    if (ctx->r10 == 0) {
        // 0x800BCA60: lbu         $t3, 0xC($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0XC);
            goto L_800BCA90;
    }
    goto skip_0;
    // 0x800BCA60: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
    skip_0:
    // 0x800BCA64: jal         0x800E42A8
    // 0x800BCA68: nop

    func_800E42A8(rdram, ctx);
        goto after_6;
    // 0x800BCA68: nop

    after_6:
    // 0x800BCA6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BCA70: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BCA74: addiu       $a2, $a2, -0x7C64
    ctx->r6 = ADD32(ctx->r6, -0X7C64);
    // 0x800BCA78: addiu       $a1, $a1, -0x7C70
    ctx->r5 = ADD32(ctx->r5, -0X7C70);
    // 0x800BCA7C: jal         0x800CAA24
    // 0x800BCA80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CAA24(rdram, ctx);
        goto after_7;
    // 0x800BCA80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x800BCA84: beql        $v0, $zero, L_800BCBD0
    if (ctx->r2 == 0) {
        // 0x800BCA88: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800BCBD0;
    }
    goto skip_1;
    // 0x800BCA88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x800BCA8C: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
L_800BCA90:
    // 0x800BCA90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BCA94: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800BCA98: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800BCA9C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800BCAA0: addu        $a1, $s0, $t4
    ctx->r5 = ADD32(ctx->r16, ctx->r12);
    // 0x800BCAA4: jal         0x800E46E0
    // 0x800BCAA8: addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    func_800E46E0(rdram, ctx);
        goto after_8;
    // 0x800BCAA8: addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    after_8:
    // 0x800BCAAC: jal         0x800BCC90
    // 0x800BCAB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BCC90(rdram, ctx);
        goto after_9;
    // 0x800BCAB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800BCAB4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800BCAB8: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x800BCABC: ori         $t6, $t6, 0xF9FF
    ctx->r14 = ctx->r14 | 0XF9FF;
    // 0x800BCAC0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800BCAC4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800BCAC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BCACC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x800BCAD0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BCAD4: jal         0x800E7FF8
    // 0x800BCAD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    func_800E7FF8(rdram, ctx);
        goto after_10;
    // 0x800BCAD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_10:
    // 0x800BCADC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800BCAE0: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x800BCAE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCAE8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BCAEC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BCAF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BCAF4: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x800BCAF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BCAFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800BCB00: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800BCB04: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800BCB08: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800BCB0C: jal         0x800E4640
    // 0x800BCB10: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    func_800E4640(rdram, ctx);
        goto after_11;
    // 0x800BCB10: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    after_11:
    // 0x800BCB14: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800BCB18: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x800BCB1C: ori         $t5, $t5, 0xF9FF
    ctx->r13 = ctx->r13 | 0XF9FF;
    // 0x800BCB20: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800BCB24: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800BCB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BCB2C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x800BCB30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BCB34: jal         0x800E7FF8
    // 0x800BCB38: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    func_800E7FF8(rdram, ctx);
        goto after_12;
    // 0x800BCB38: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_12:
    // 0x800BCB3C: lh          $a0, 0x12($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X12);
    // 0x800BCB40: beql        $a0, $zero, L_800BCBC8
    if (ctx->r4 == 0) {
        // 0x800BCB44: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800BCBC8;
    }
    goto skip_2;
    // 0x800BCB44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_2:
    // 0x800BCB48: jal         0x800D674C
    // 0x800BCB4C: nop

    func_800D674C(rdram, ctx);
        goto after_13;
    // 0x800BCB4C: nop

    after_13:
    // 0x800BCB50: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x800BCB54: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800BCB58: bne         $t6, $zero, L_800BCB8C
    if (ctx->r14 != 0) {
        // 0x800BCB5C: nop
    
            goto L_800BCB8C;
    }
    // 0x800BCB5C: nop

    // 0x800BCB60: jal         0x800B2840
    // 0x800BCB64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2840(rdram, ctx);
        goto after_14;
    // 0x800BCB64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x800BCB68: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BCB6C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BCB70: addiu       $a2, $a2, -0x7C64
    ctx->r6 = ADD32(ctx->r6, -0X7C64);
    // 0x800BCB74: addiu       $a1, $a1, -0x7C70
    ctx->r5 = ADD32(ctx->r5, -0X7C70);
    // 0x800BCB78: jal         0x800B21CC
    // 0x800BCB7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B21CC(rdram, ctx);
        goto after_15;
    // 0x800BCB7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x800BCB80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BCB84: sb          $t8, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r24;
    // 0x800BCB88: sb          $t8, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r24;
L_800BCB8C:
    // 0x800BCB8C: jal         0x800DF440
    // 0x800BCB90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_16;
    // 0x800BCB90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x800BCB94: jal         0x800DF830
    // 0x800BCB98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_17;
    // 0x800BCB98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x800BCB9C: jal         0x800DF410
    // 0x800BCBA0: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    func_800DF410(rdram, ctx);
        goto after_18;
    // 0x800BCBA0: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    after_18:
    // 0x800BCBA4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800BCBA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BCBAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BCBB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BCBB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800BCBB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800BCBBC: jal         0x800DE498
    // 0x800BCBC0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_800DE498(rdram, ctx);
        goto after_19;
    // 0x800BCBC0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_19:
    // 0x800BCBC4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800BCBC8:
    // 0x800BCBC8: sb          $t0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r8;
    // 0x800BCBCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800BCBD0:
    // 0x800BCBD0: jal         0x800E46E0
    // 0x800BCBD4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800E46E0(rdram, ctx);
        goto after_20;
    // 0x800BCBD4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_20:
    // 0x800BCBD8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800BCBDC: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800BCBE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCBE4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800BCBE8: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800BCBEC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800BCBF0: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
    // 0x800BCBF4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800BCBF8: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x800BCBFC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800BCC00: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800BCC04: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BCC08: lbu         $t8, 0xC($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XC);
    // 0x800BCC0C: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800BCC10: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
L_800BCC14:
    // 0x800BCC14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BCC18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC1C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800BCC20: jr          $ra
    // 0x800BCC24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BCC24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void fxdlsmoke_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800B5BE4
    // 0x80800010: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80800014: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2806, 0X50) << 16);
    // 0x80800018: addiu       $t6, $t6, 0x50
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2806, 0X50));
    // 0x8080001C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080002C: jal         0x800BABB8
    // 0x80800030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80800034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

    // 0x80800044: nop

    // 0x80800048: nop

    // 0x8080004C: nop

;}
RECOMP_FUNC void func_80800B10_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800B14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B1C: jal         0x80099A58
    // 0x80800B20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80099A58(rdram, ctx);
        goto after_0;
    // 0x80800B20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: jal         0x80084F78
    // 0x80800B2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bareact_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800B2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800B30: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800B34: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B3C: jal         0x8008CDB8
    // 0x80800B40: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baanim_playForDuration_once(rdram, ctx);
        goto after_2;
    // 0x80800B40: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B48: jal         0x8009D89C
    // 0x80800B4C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D89C(rdram, ctx);
        goto after_3;
    // 0x80800B4C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: jal         0x8009C128
    // 0x80800B58: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x80800B58: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B60: jal         0x800A32C4
    // 0x80800B64: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A32C4(rdram, ctx);
        goto after_5;
    // 0x80800B64: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x80800B68: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800B6C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800B70: jal         0x800F1E6C
    // 0x80800B74: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_6;
    // 0x80800B74: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x8009C914
    // 0x80800B80: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x80800B80: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x80800B84: jal         0x8009C974
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_8;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B8C: jal         0x80084F90
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bareact_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B98: jal         0x8009B9B0
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: jal         0x8009B9C0
    // 0x80800BA8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_11;
    // 0x80800BA8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x80800BAC: jal         0x8009BB00
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800BB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BBC: jal         0x8009BA68
    // 0x80800BC0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x80800BC0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_13:
    // 0x80800BC4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800BC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800BD8: jal         0x8009FFD8
    // 0x80800BDC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_14;
    // 0x80800BDC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x80800BE0: jal         0x8008E944
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_15;
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800BE8: jal         0x8009514C
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_16;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800BF0: jal         0x80800030
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_17;
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800BF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800C04: jr          $ra
    // 0x80800C08: nop

    return;
    // 0x80800C08: nop

;}
RECOMP_FUNC void func_8010F280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F280: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010F284: addiu       $t0, $t0, 0x7240
    ctx->r8 = ADD32(ctx->r8, 0X7240);
    // 0x8010F288: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8010F28C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010F290: addiu       $v1, $v0, 0x7250
    ctx->r3 = ADD32(ctx->r2, 0X7250);
    // 0x8010F294: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8010F298: beq         $at, $zero, L_8010F2C0
    if (ctx->r1 == 0) {
        // 0x8010F29C: addiu       $t1, $zero, 0x28
        ctx->r9 = ADD32(0, 0X28);
            goto L_8010F2C0;
    }
    // 0x8010F29C: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8010F2A0: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
L_8010F2A4:
    // 0x8010F2A4: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8010F2A8: bne         $at, $zero, L_8010F2C0
    if (ctx->r1 != 0) {
        // 0x8010F2AC: nop
    
            goto L_8010F2C0;
    }
    // 0x8010F2AC: nop

    // 0x8010F2B0: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x8010F2B4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8010F2B8: bnel        $at, $zero, L_8010F2A4
    if (ctx->r1 != 0) {
        // 0x8010F2BC: lw          $t6, 0x24($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X24);
            goto L_8010F2A4;
    }
    goto skip_0;
    // 0x8010F2BC: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    skip_0:
L_8010F2C0:
    // 0x8010F2C0: bnel        $v1, $a1, L_8010F2F4
    if (ctx->r3 != ctx->r5) {
        // 0x8010F2C4: lw          $t9, 0xC($t0)
        ctx->r25 = MEM_W(ctx->r8, 0XC);
            goto L_8010F2F4;
    }
    goto skip_1;
    // 0x8010F2C4: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    skip_1:
    // 0x8010F2C8: lw          $t7, 0xC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XC);
    // 0x8010F2CC: addiu       $t8, $a1, 0x28
    ctx->r24 = ADD32(ctx->r5, 0X28);
    // 0x8010F2D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010F2D4: sltu        $at, $a1, $t7
    ctx->r1 = ctx->r5 < ctx->r15 ? 1 : 0;
    // 0x8010F2D8: beq         $at, $zero, L_8010F2E8
    if (ctx->r1 == 0) {
        // 0x8010F2DC: nop
    
            goto L_8010F2E8;
    }
    // 0x8010F2DC: nop

    // 0x8010F2E0: jr          $ra
    // 0x8010F2E4: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    return;
    // 0x8010F2E4: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
L_8010F2E8:
    // 0x8010F2E8: jr          $ra
    // 0x8010F2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8010F2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010F2F0: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
L_8010F2F4:
    // 0x8010F2F4: bnel        $t9, $a1, L_8010F30C
    if (ctx->r25 != ctx->r5) {
        // 0x8010F2F8: subu        $t3, $a1, $v1
        ctx->r11 = SUB32(ctx->r5, ctx->r3);
            goto L_8010F30C;
    }
    goto skip_2;
    // 0x8010F2F8: subu        $t3, $a1, $v1
    ctx->r11 = SUB32(ctx->r5, ctx->r3);
    skip_2:
    // 0x8010F2FC: addiu       $t2, $a1, -0x28
    ctx->r10 = ADD32(ctx->r5, -0X28);
    // 0x8010F300: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x8010F304: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8010F308: subu        $t3, $a1, $v1
    ctx->r11 = SUB32(ctx->r5, ctx->r3);
L_8010F30C:
    // 0x8010F30C: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x8010F310: mflo        $t4
    ctx->r12 = lo;
    // 0x8010F314: addiu       $a0, $a1, 0x28
    ctx->r4 = ADD32(ctx->r5, 0X28);
    // 0x8010F318: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010F31C: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F320: bne         $t1, $zero, L_8010F32C
    if (ctx->r9 != 0) {
        // 0x8010F324: nop
    
            goto L_8010F32C;
    }
    // 0x8010F324: nop

    // 0x8010F328: break       7
    do_break(2148594472);
L_8010F32C:
    // 0x8010F32C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010F330: bne         $t1, $at, L_8010F344
    if (ctx->r9 != ctx->r1) {
        // 0x8010F334: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8010F344;
    }
    // 0x8010F334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010F338: bne         $t3, $at, L_8010F344
    if (ctx->r11 != ctx->r1) {
        // 0x8010F33C: nop
    
            goto L_8010F344;
    }
    // 0x8010F33C: nop

    // 0x8010F340: break       6
    do_break(2148594496);
L_8010F344:
    // 0x8010F344: mflo        $a2
    ctx->r6 = lo;
    // 0x8010F348: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8010F34C: blez        $a2, L_8010F374
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8010F350: addiu       $a3, $a1, -0x4
        ctx->r7 = ADD32(ctx->r5, -0X4);
            goto L_8010F374;
    }
    // 0x8010F350: addiu       $a3, $a1, -0x4
    ctx->r7 = ADD32(ctx->r5, -0X4);
L_8010F354:
    // 0x8010F354: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8010F358: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8010F35C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8010F360: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x8010F364: bgtz        $a2, L_8010F354
    if (SIGNED(ctx->r6) > 0) {
        // 0x8010F368: sw          $t5, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r13;
            goto L_8010F354;
    }
    // 0x8010F368: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8010F36C: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x8010F370: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
L_8010F374:
    // 0x8010F374: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8010F378: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010F37C: jr          $ra
    // 0x8010F380: nop

    return;
    // 0x8010F380: nop

;}
RECOMP_FUNC void _chlavahand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875A0: syscall     591
    recomp_syscall_handler(rdram, ctx, 0x800875A0);
    return;
    // 0x800875A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80803558_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803558: beq         $a2, $zero, L_80803584
    if (ctx->r6 == 0) {
        // 0x8080355C: sra         $t2, $a1, 3
        ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
            goto L_80803584;
    }
    // 0x8080355C: sra         $t2, $a1, 3
    ctx->r10 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80803560: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80803564: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x80803568: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8080356C: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x80803570: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80803574: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x80803578: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x8080357C: jr          $ra
    // 0x80803580: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x80803580: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80803584:
    // 0x80803584: addu        $v0, $t2, $a0
    ctx->r2 = ADD32(ctx->r10, ctx->r4);
    // 0x80803588: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8080358C: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x80803590: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80803594: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x80803598: nor         $t9, $t6, $zero
    ctx->r25 = ~(ctx->r14 | 0);
    // 0x8080359C: and         $t8, $t3, $t9
    ctx->r24 = ctx->r11 & ctx->r25;
    // 0x808035A0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x808035A4: jr          $ra
    // 0x808035A8: nop

    return;
    // 0x808035A8: nop

;}
RECOMP_FUNC void func_80806774_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806774: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080677C: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806780: jal         0x8009B7C0
    // 0x80806784: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8009B7C0(rdram, ctx);
        goto after_0;
    // 0x80806784: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80806788: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8080678C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80806790: nop

    // 0x80806794: swc1        $f0, 0x1D8($v0)
    MEM_W(0X1D8, ctx->r2) = ctx->f0.u32l;
    // 0x80806798: swc1        $f0, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f0.u32l;
    // 0x8080679C: swc1        $f0, 0x1D4($v0)
    MEM_W(0X1D4, ctx->r2) = ctx->f0.u32l;
    // 0x808067A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808067A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808067A8: jr          $ra
    // 0x808067AC: nop

    return;
    // 0x808067AC: nop

;}
RECOMP_FUNC void func_80020D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020D8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020D90: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020D94: lw          $t6, 0x11F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F0);
    // 0x80020D98: bne         $t6, $zero, L_80020DD4
    if (ctx->r14 != 0) {
        // 0x80020D9C: nop
    
            goto L_80020DD4;
    }
    // 0x80020D9C: nop

    // 0x80020DA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80020DA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020DA8: sw          $t7, 0x11F0($at)
    MEM_W(0X11F0, ctx->r1) = ctx->r15;
    // 0x80020DAC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80020DB0: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x80020DB4: bne         $t8, $zero, L_80020DD4
    if (ctx->r24 != 0) {
        // 0x80020DB8: nop
    
            goto L_80020DD4;
    }
    // 0x80020DB8: nop

    // 0x80020DBC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80020DC0: lw          $t9, 0x11F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F0);
    // 0x80020DC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020DC8: sw          $t9, 0x11F4($at)
    MEM_W(0X11F4, ctx->r1) = ctx->r25;
    // 0x80020DCC: jal         0x80020F70
    // 0x80020DD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80020F70(rdram, ctx);
        goto after_0;
    // 0x80020DD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
L_80020DD4:
    // 0x80020DD4: b           L_80020DDC
    // 0x80020DD8: nop

        goto L_80020DDC;
    // 0x80020DD8: nop

L_80020DDC:
    // 0x80020DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020DE4: jr          $ra
    // 0x80020DE8: nop

    return;
    // 0x80020DE8: nop

;}
RECOMP_FUNC void func_80012EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012EE8: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80012EEC: jr          $ra
    // 0x80012EF0: addiu       $v0, $v0, -0x6B78
    ctx->r2 = ADD32(ctx->r2, -0X6B78);
    return;
    // 0x80012EF0: addiu       $v0, $v0, -0x6B78
    ctx->r2 = ADD32(ctx->r2, -0X6B78);
;}
RECOMP_FUNC void func_80800FF0_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FFC: jal         0x8009E6EC
    // 0x80801000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801004: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80801008: bne         $v0, $at, L_80801050
    if (ctx->r2 != ctx->r1) {
        // 0x8080100C: nop
    
            goto L_80801050;
    }
    // 0x8080100C: nop

    // 0x80801010: jal         0x80099A34
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A34(rdram, ctx);
        goto after_1;
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801018: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080101C: jal         0x8009BDAC
    // 0x80801020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BDAC(rdram, ctx);
        goto after_2;
    // 0x80801020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801028: jal         0x80093370
    // 0x8080102C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093370(rdram, ctx);
        goto after_3;
    // 0x8080102C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801034: jal         0x8009E5C8
    // 0x80801038: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801038: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    after_4:
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: jal         0x8009E830
    // 0x80801044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_5;
    // 0x80801044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80801048: b           L_8080105C
    // 0x8080104C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080105C;
    // 0x8080104C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801050:
    // 0x80801050: jal         0x80085258
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080105C:
    // 0x8080105C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801064: jr          $ra
    // 0x80801068: nop

    return;
    // 0x80801068: nop

;}
RECOMP_FUNC void func_8009C1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C1B4: lw          $v0, 0xE4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C1B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C1BC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C1C0: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8009C1C4: jr          $ra
    // 0x8009C1C8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8009C1C8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void _chpawnbroker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EE8: syscall     258
    recomp_syscall_handler(rdram, ctx, 0x80085EE8);
    return;
    // 0x80085EEC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A9B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9B84: jr          $ra
    // 0x800A9B88: nop

    return;
    // 0x800A9B88: nop

;}
RECOMP_FUNC void func_808003DC_chswappy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808003F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808003F8: jal         0x800E3E8C
    // 0x808003FC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x808003FC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_0:
    // 0x80800400: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: jal         0x8010A73C
    // 0x8080040C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_8010A73C(rdram, ctx);
        goto after_1;
    // 0x8080040C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80800410: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800414: beql        $t6, $zero, L_80800478
    if (ctx->r14 == 0) {
        // 0x80800418: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800478;
    }
    goto skip_0;
    // 0x80800418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080041C: jal         0x800F8B88
    // 0x80800420: nop

    func_800F8B88(rdram, ctx);
        goto after_2;
    // 0x80800420: nop

    after_2:
    // 0x80800424: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800428: bnel        $v0, $at, L_80800478
    if (ctx->r2 != ctx->r1) {
        // 0x8080042C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800478;
    }
    goto skip_1;
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800430: jal         0x800E3980
    // 0x80800434: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x80800434: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800438: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080043C: jal         0x800EEB40
    // 0x80800440: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x80800440: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800444: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2156, 0X684) << 16);
    // 0x80800448: lwc1        $f4, 0x684($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2156, 0X684));
    // 0x8080044C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800450: nop

    // 0x80800454: bc1fl       L_8080046C
    if (!c1cs) {
        // 0x80800458: lbu         $t1, 0x7E($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X7E);
            goto L_8080046C;
    }
    goto skip_2;
    // 0x80800458: lbu         $t1, 0x7E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7E);
    skip_2:
    // 0x8080045C: lbu         $t8, 0x7E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7E);
    // 0x80800460: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800464: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
    // 0x80800468: lbu         $t1, 0x7E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7E);
L_8080046C:
    // 0x8080046C: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80800470: sb          $t2, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r10;
    // 0x80800474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800478:
    // 0x80800478: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080047C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800480: jr          $ra
    // 0x80800484: nop

    return;
    // 0x80800484: nop

;}
RECOMP_FUNC void func_80110D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110D28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80110D2C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80110D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110D38: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80110D3C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80110D40: jal         0x80116050
    // 0x80110D44: nop

    func_80116050(rdram, ctx);
        goto after_0;
    // 0x80110D44: nop

    after_0:
    // 0x80110D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110D50: jr          $ra
    // 0x80110D54: nop

    return;
    // 0x80110D54: nop

;}
RECOMP_FUNC void _chvandoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086288: syscall     298
    recomp_syscall_handler(rdram, ctx, 0x80086288);
    return;
    // 0x8008628C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080019C_bsdronevanish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001A0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(200, 0X578) << 16);
    // 0x808001A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001AC: addiu       $t6, $t6, 0x578
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(200, 0X578));
    // 0x808001B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001C0: jal         0x800BABB8
    // 0x808001C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x808001C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x808001C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001CC: jal         0x800BA3FC
    // 0x808001D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x808001D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808001D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089870: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089870);
    return;
    // 0x80089874: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void gczoombox_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803380: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803384: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80803388: jr          $ra
    // 0x8080338C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080338C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void _chfactoryprop_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861D0: syscall     287
    recomp_syscall_handler(rdram, ctx, 0x800861D0);
    return;
    // 0x800861D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80099B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099B5C: jal         0x80099A4C
    // 0x80099B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80099A4C(rdram, ctx);
        goto after_0;
    // 0x80099B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80099B64: jal         0x80106790
    // 0x80099B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80099B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80099B6C: lw          $a0, 0x6C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6C);
    // 0x80099B70: sll         $t6, $a0, 11
    ctx->r14 = S32(ctx->r4 << 11);
    // 0x80099B74: jal         0x8009EAE8
    // 0x80099B78: srl         $a0, $t6, 20
    ctx->r4 = S32(U32(ctx->r14) >> 20);
    func_8009EAE8(rdram, ctx);
        goto after_2;
    // 0x80099B78: srl         $a0, $t6, 20
    ctx->r4 = S32(U32(ctx->r14) >> 20);
    after_2:
    // 0x80099B7C: jal         0x80084748
    // 0x80099B80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badata_entrypoint_33(rdram, ctx);
        goto after_3;
    // 0x80099B80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80099B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099B8C: jr          $ra
    // 0x80099B90: nop

    return;
    // 0x80099B90: nop

;}
RECOMP_FUNC void func_808003E0_gccollectDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808003E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808003E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808003EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808003F0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808003F4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808003F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808003FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800400: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800408: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8080040C: jal         0x800CF87C
    // 0x80800410: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    func_800CF87C(rdram, ctx);
        goto after_0;
    // 0x80800410: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    after_0:
    // 0x80800414: addiu       $t6, $v0, 0xA
    ctx->r14 = ADD32(ctx->r2, 0XA);
    // 0x80800418: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8080041C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800420: beq         $at, $zero, L_808004A0
    if (ctx->r1 == 0) {
        // 0x80800424: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808004A0;
    }
    // 0x80800424: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800428: addiu       $s6, $v0, 0xA
    ctx->r22 = ADD32(ctx->r2, 0XA);
    // 0x8080042C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800430:
    // 0x80800430: jal         0x800D0B68
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800438: bne         $v0, $zero, L_80800490
    if (ctx->r2 != 0) {
        // 0x8080043C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800490;
    }
    // 0x8080043C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800440: jal         0x800D0908
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0908(rdram, ctx);
        goto after_2;
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800448: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x8080044C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800490;
    }
    // 0x8080044C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800454: jal         0x800D0684
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0684(rdram, ctx);
        goto after_3;
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080045C: jal         0x800EA05C
    // 0x80800460: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x80800460: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_4:
    // 0x80800464: bne         $v0, $s0, L_80800490
    if (ctx->r2 != ctx->r16) {
        // 0x80800468: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800490;
    }
    // 0x80800468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080046C: jal         0x808002C4
    // 0x80800470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808002C4_gccollectDll(rdram, ctx);
        goto after_5;
    // 0x80800470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800474: bnel        $v0, $zero, L_80800494
    if (ctx->r2 != 0) {
        // 0x80800478: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800494;
    }
    goto skip_0;
    // 0x80800478: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8080047C: jal         0x800DA298
    // 0x80800480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80800484: beql        $v0, $zero, L_80800494
    if (ctx->r2 == 0) {
        // 0x80800488: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800494;
    }
    goto skip_1;
    // 0x80800488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8080048C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80800490:
    // 0x80800490: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800494:
    // 0x80800494: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80800498: bnel        $at, $zero, L_80800430
    if (ctx->r1 != 0) {
        // 0x8080049C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800430;
    }
    goto skip_2;
    // 0x8080049C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
L_808004A0:
    // 0x808004A0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x808004A4: sll         $v0, $s4, 3
    ctx->r2 = S32(ctx->r20 << 3);
    // 0x808004A8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x808004AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x808004B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004B4: addiu       $s6, $s3, 0xA
    ctx->r22 = ADD32(ctx->r19, 0XA);
    // 0x808004B8: jal         0x8001B208
    // 0x808004BC: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    heap_realloc(rdram, ctx);
        goto after_7;
    // 0x808004BC: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    after_7:
    // 0x808004C0: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x808004C4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808004C8: slt         $at, $s3, $s6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x808004CC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x808004D0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x808004D4: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x808004D8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808004DC: addu        $s2, $t1, $v0
    ctx->r18 = ADD32(ctx->r9, ctx->r2);
    // 0x808004E0: sh          $s4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r20;
    // 0x808004E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x808004E8: beq         $at, $zero, L_80800580
    if (ctx->r1 == 0) {
        // 0x808004EC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80800580;
    }
    // 0x808004EC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_808004F0:
    // 0x808004F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004F4: jal         0x800D0B68
    // 0x808004F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_8;
    // 0x808004F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808004FC: bne         $v0, $zero, L_80800574
    if (ctx->r2 != 0) {
        // 0x80800500: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800574;
    }
    // 0x80800500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800504: jal         0x800D0908
    // 0x80800508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0908(rdram, ctx);
        goto after_9;
    // 0x80800508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080050C: beq         $v0, $zero, L_80800574
    if (ctx->r2 == 0) {
        // 0x80800510: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800574;
    }
    // 0x80800510: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800518: jal         0x800D0684
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0684(rdram, ctx);
        goto after_10;
    // 0x8080051C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800520: jal         0x800EA05C
    // 0x80800524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800EA05C(rdram, ctx);
        goto after_11;
    // 0x80800524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_11:
    // 0x80800528: bne         $v0, $s0, L_80800574
    if (ctx->r2 != ctx->r16) {
        // 0x8080052C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800574;
    }
    // 0x8080052C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800530: jal         0x808002C4
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808002C4_gccollectDll(rdram, ctx);
        goto after_12;
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800538: bnel        $v0, $zero, L_80800578
    if (ctx->r2 != 0) {
        // 0x8080053C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800578;
    }
    goto skip_3;
    // 0x8080053C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x80800540: jal         0x800DA298
    // 0x80800544: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80800544: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x80800548: beq         $v0, $zero, L_80800574
    if (ctx->r2 == 0) {
        // 0x8080054C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800574;
    }
    // 0x8080054C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800550: sh          $s4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r20;
    // 0x80800554: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080055C: jal         0x800D07CC
    // 0x80800560: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800D07CC(rdram, ctx);
        goto after_14;
    // 0x80800560: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x80800564: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800568: jal         0x800EE940
    // 0x8080056C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE940(rdram, ctx);
        goto after_15;
    // 0x8080056C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_15:
    // 0x80800570: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
L_80800574:
    // 0x80800574: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800578:
    // 0x80800578: bne         $s1, $s6, L_808004F0
    if (ctx->r17 != ctx->r22) {
        // 0x8080057C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_808004F0;
    }
    // 0x8080057C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80800580:
    // 0x80800580: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80800584: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80800588: subu        $t3, $s2, $v0
    ctx->r11 = SUB32(ctx->r18, ctx->r2);
    // 0x8080058C: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x80800590: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80800594: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800598: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080059C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808005A0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808005A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808005A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808005AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808005B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005B4: jr          $ra
    // 0x808005B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808005B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084050: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084050);
    return;
    // 0x80084054: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void bafly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80803E40_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803E44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803E48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803E4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803E50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803E54: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80803E58:
    // 0x80803E58: jal         0x80016800
    // 0x80803E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80016800(rdram, ctx);
        goto after_0;
    // 0x80803E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80803E60: bnel        $v0, $zero, L_80803E74
    if (ctx->r2 != 0) {
        // 0x80803E64: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80803E74;
    }
    goto skip_0;
    // 0x80803E64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80803E68: b           L_80803E80
    // 0x80803E6C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80803E80;
    // 0x80803E6C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80803E70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80803E74:
    // 0x80803E74: bne         $s0, $s1, L_80803E58
    if (ctx->r16 != ctx->r17) {
        // 0x80803E78: nop
    
            goto L_80803E58;
    }
    // 0x80803E78: nop

    // 0x80803E7C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80803E80:
    // 0x80803E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803E84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80803E88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803E8C: jr          $ra
    // 0x80803E90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80803E90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _idlight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CF8: syscall     735
    recomp_syscall_handler(rdram, ctx, 0x80088CF8);
    return;
    // 0x80088CFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A48: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A48);
    return;
    // 0x80085A4C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chmineprospector_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(892, 0X1074) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1074
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X1074));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1074
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(892, 0X1074));
;}
