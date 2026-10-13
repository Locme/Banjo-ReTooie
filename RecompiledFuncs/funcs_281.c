#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800580_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800584: slti        $at, $a1, 0xF
    ctx->r1 = SIGNED(ctx->r5) < 0XF ? 1 : 0;
    // 0x80800588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080058C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800590: bne         $at, $zero, L_808005D8
    if (ctx->r1 != 0) {
        // 0x80800594: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808005D8;
    }
    // 0x80800594: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800598: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x8080059C: bne         $at, $zero, L_808005B8
    if (ctx->r1 != 0) {
        // 0x808005A0: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_808005B8;
    }
    // 0x808005A0: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x808005A4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005A8: beq         $a1, $at, L_808005F4
    if (ctx->r5 == ctx->r1) {
        // 0x808005AC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808005F4;
    }
    // 0x808005AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005B0: b           L_80800A0C
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B8:
    // 0x808005B8: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x808005BC: beq         $at, $zero, L_80800A08
    if (ctx->r1 == 0) {
        // 0x808005C0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800A08;
    }
    // 0x808005C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808005C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X1538) << 16);
    // 0x808005C8: addu        $at, $at, $t6
    gpr jr_addend_808005D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808005CC: lw          $t6, 0x1538($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2228, 0X1538));
    // 0x808005D0: jr          $t6
    // 0x808005D4: nop

    switch (jr_addend_808005D0 >> 2) {
        case 0: goto L_80800624; break;
        case 1: goto L_80800830; break;
        case 2: goto L_80800790; break;
        case 3: goto L_80800A08; break;
        case 4: goto L_8080092C; break;
        case 5: goto L_80800A08; break;
        case 6: goto L_80800A08; break;
        case 7: goto L_80800A08; break;
        case 8: goto L_80800A08; break;
        case 9: goto L_80800A08; break;
        case 10: goto L_80800A08; break;
        case 11: goto L_80800A08; break;
        case 12: goto L_80800A08; break;
        case 13: goto L_80800A08; break;
        case 14: goto L_80800A08; break;
        case 15: goto L_808008B8; break;
        case 16: goto L_80800A08; break;
        case 17: goto L_80800A08; break;
        case 18: goto L_80800A08; break;
        case 19: goto L_80800A08; break;
        case 20: goto L_80800A08; break;
        case 21: goto L_80800A08; break;
        case 22: goto L_80800A08; break;
        case 23: goto L_80800A08; break;
        case 24: goto L_80800A08; break;
        case 25: goto L_80800A08; break;
        case 26: goto L_80800A08; break;
        case 27: goto L_80800A08; break;
        case 28: goto L_80800A08; break;
        case 29: goto L_80800A08; break;
        case 30: goto L_80800A08; break;
        case 31: goto L_80800A08; break;
        case 32: goto L_80800A08; break;
        case 33: goto L_80800A08; break;
        case 34: goto L_80800A08; break;
        case 35: goto L_80800A08; break;
        case 36: goto L_8080089C; break;
        default: switch_error(__func__, 0x808005D0, 0x80801538);
    }
    // 0x808005D4: nop

L_808005D8:
    // 0x808005D8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808005DC: beq         $a1, $at, L_808007F0
    if (ctx->r5 == ctx->r1) {
        // 0x808005E0: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_808007F0;
    }
    // 0x808005E0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808005E4: beq         $a1, $at, L_808007CC
    if (ctx->r5 == ctx->r1) {
        // 0x808005E8: nop
    
            goto L_808007CC;
    }
    // 0x808005E8: nop

    // 0x808005EC: b           L_80800A0C
    // 0x808005F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808005F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F4:
    // 0x808005F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005F8: jal         0x800897C0
    // 0x808005FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808005FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
    // 0x80800600: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800604: jal         0x80100094
    // 0x80800608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080060C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800610: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800614: jal         0x800897E8
    // 0x80800618: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800618: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_2:
    // 0x8080061C: b           L_80800A0C
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800624:
    // 0x80800624: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800628: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8080062C: slti        $at, $v0, 0x1040
    ctx->r1 = SIGNED(ctx->r2) < 0X1040 ? 1 : 0;
    // 0x80800630: bne         $at, $zero, L_8080064C
    if (ctx->r1 != 0) {
        // 0x80800634: addiu       $t7, $v0, -0x1006
        ctx->r15 = ADD32(ctx->r2, -0X1006);
            goto L_8080064C;
    }
    // 0x80800634: addiu       $t7, $v0, -0x1006
    ctx->r15 = ADD32(ctx->r2, -0X1006);
    // 0x80800638: addiu       $at, $zero, 0x106B
    ctx->r1 = ADD32(0, 0X106B);
    // 0x8080063C: beql        $v0, $at, L_8080068C
    if (ctx->r2 == ctx->r1) {
        // 0x80800640: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8080068C;
    }
    goto skip_0;
    // 0x80800640: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800644: b           L_80800A0C
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x80800648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080064C:
    // 0x8080064C: slti        $at, $v0, 0x100C
    ctx->r1 = SIGNED(ctx->r2) < 0X100C ? 1 : 0;
    // 0x80800650: bne         $at, $zero, L_80800668
    if (ctx->r1 != 0) {
        // 0x80800654: addiu       $at, $zero, 0x103F
        ctx->r1 = ADD32(0, 0X103F);
            goto L_80800668;
    }
    // 0x80800654: addiu       $at, $zero, 0x103F
    ctx->r1 = ADD32(0, 0X103F);
    // 0x80800658: beq         $v0, $at, L_80800780
    if (ctx->r2 == ctx->r1) {
        // 0x8080065C: nop
    
            goto L_80800780;
    }
    // 0x8080065C: nop

    // 0x80800660: b           L_80800A0C
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x80800664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800668:
    // 0x80800668: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8080066C: beq         $at, $zero, L_80800788
    if (ctx->r1 == 0) {
        // 0x80800670: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800788;
    }
    // 0x80800670: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15CC) << 16);
    // 0x80800678: addu        $at, $at, $t7
    gpr jr_addend_80800680 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080067C: lw          $t7, 0x15CC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15CC));
    // 0x80800680: jr          $t7
    // 0x80800684: nop

    switch (jr_addend_80800680 >> 2) {
        case 0: goto L_80800688; break;
        case 1: goto L_80800688; break;
        case 2: goto L_808006BC; break;
        case 3: goto L_80800730; break;
        case 4: goto L_80800730; break;
        case 5: goto L_80800744; break;
        default: switch_error(__func__, 0x80800680, 0x808015CC);
    }
    // 0x80800684: nop

L_80800688:
    // 0x80800688: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_8080068C:
    // 0x8080068C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80800690: addiu       $a1, $zero, 0x1008
    ctx->r5 = ADD32(0, 0X1008);
    // 0x80800694: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800698: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080069C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808006A0: jal         0x8008A208
    // 0x808006A4: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808006A4: addiu       $a3, $t8, 0x4
    ctx->r7 = ADD32(ctx->r24, 0X4);
    after_3:
    // 0x808006A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006AC: jal         0x80102424
    // 0x808006B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808006B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808006B4: b           L_80800A0C
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006BC:
    // 0x808006BC: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x808006C0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808006C4: addiu       $a1, $zero, 0x1009
    ctx->r5 = ADD32(0, 0X1009);
    // 0x808006C8: blez        $t0, L_80800714
    if (SIGNED(ctx->r8) <= 0) {
        // 0x808006CC: addiu       $a2, $zero, 0xE
        ctx->r6 = ADD32(0, 0XE);
            goto L_80800714;
    }
    // 0x808006CC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006D0: jal         0x800D1A04
    // 0x808006D4: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1A04(rdram, ctx);
        goto after_5;
    // 0x808006D4: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_5:
    // 0x808006D8: bgtz        $v0, L_80800704
    if (SIGNED(ctx->r2) > 0) {
        // 0x808006DC: lw          $t1, 0x30($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X30);
            goto L_80800704;
    }
    // 0x808006DC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x808006E0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x808006E4: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x808006E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808006EC: addiu       $a1, $zero, 0x100A
    ctx->r5 = ADD32(0, 0X100A);
    // 0x808006F0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808006F4: jal         0x8008A208
    // 0x808006F8: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808006F8: addiu       $a3, $t1, 0x4
    ctx->r7 = ADD32(ctx->r9, 0X4);
    after_6:
    // 0x808006FC: b           L_80800A0C
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: jal         0x80800078
    // 0x80800708: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800078_chcaptainblubber(rdram, ctx);
        goto after_7;
    // 0x80800708: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8080070C: b           L_80800A0C
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800714:
    // 0x80800714: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800718: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8080071C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800720: jal         0x8008A208
    // 0x80800724: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800724: addiu       $a3, $t3, 0x4
    ctx->r7 = ADD32(ctx->r11, 0X4);
    after_8:
    // 0x80800728: b           L_80800A0C
    // 0x8080072C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x8080072C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800730:
    // 0x80800730: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800734: jal         0x80102424
    // 0x80800738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8080073C: b           L_80800A0C
    // 0x80800740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800744:
    // 0x80800744: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800748: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8080074C: addiu       $a1, $zero, 0x103F
    ctx->r5 = ADD32(0, 0X103F);
    // 0x80800750: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800754: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800758: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x8080075C: jal         0x8008A208
    // 0x80800760: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800760: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_10:
    // 0x80800764: jal         0x800DA544
    // 0x80800768: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80800768: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    after_11:
    // 0x8080076C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800770: jal         0x800D175C
    // 0x80800774: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800D175C(rdram, ctx);
        goto after_12;
    // 0x80800774: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_12:
    // 0x80800778: b           L_80800A0C
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800780:
    // 0x80800780: b           L_80800A0C
    // 0x80800784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800788:
    // 0x80800788: b           L_80800A0C
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x8080078C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800790:
    // 0x80800790: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800794: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800798: addiu       $at, $zero, 0x1006
    ctx->r1 = ADD32(0, 0X1006);
    // 0x8080079C: beq         $v0, $at, L_808007BC
    if (ctx->r2 == ctx->r1) {
        // 0x808007A0: addiu       $at, $zero, 0x1007
        ctx->r1 = ADD32(0, 0X1007);
            goto L_808007BC;
    }
    // 0x808007A0: addiu       $at, $zero, 0x1007
    ctx->r1 = ADD32(0, 0X1007);
    // 0x808007A4: beq         $v0, $at, L_808007BC
    if (ctx->r2 == ctx->r1) {
        // 0x808007A8: addiu       $at, $zero, 0x1008
        ctx->r1 = ADD32(0, 0X1008);
            goto L_808007BC;
    }
    // 0x808007A8: addiu       $at, $zero, 0x1008
    ctx->r1 = ADD32(0, 0X1008);
    // 0x808007AC: beq         $v0, $at, L_808007BC
    if (ctx->r2 == ctx->r1) {
        // 0x808007B0: addiu       $at, $zero, 0x106B
        ctx->r1 = ADD32(0, 0X106B);
            goto L_808007BC;
    }
    // 0x808007B0: addiu       $at, $zero, 0x106B
    ctx->r1 = ADD32(0, 0X106B);
    // 0x808007B4: bne         $v0, $at, L_808007C4
    if (ctx->r2 != ctx->r1) {
        // 0x808007B8: nop
    
            goto L_808007C4;
    }
    // 0x808007B8: nop

L_808007BC:
    // 0x808007BC: b           L_80800A0C
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x808007C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007C4:
    // 0x808007C4: b           L_80800A0C
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808007C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007CC:
    // 0x808007CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2228, 0X15E4) << 16);
    // 0x808007D0: jal         0x80085728
    // 0x808007D4: lwc1        $f12, 0x15E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15E4));
    _capod_entrypoint_17(rdram, ctx);
        goto after_13;
    // 0x808007D4: lwc1        $f12, 0x15E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2228, 0X15E4));
    after_13:
    // 0x808007D8: beq         $v0, $zero, L_808007E8
    if (ctx->r2 == 0) {
        // 0x808007DC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808007E8;
    }
    // 0x808007DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808007E0: jal         0x80108B04
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_808007E8:
    // 0x808007E8: b           L_80800A0C
    // 0x808007EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800A0C;
    // 0x808007EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808007F0:
    // 0x808007F0: jal         0x80085710
    // 0x808007F4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x808007F4: nop

    after_15:
    // 0x808007F8: jal         0x800C064C
    // 0x808007FC: nop

    func_800C064C(rdram, ctx);
        goto after_16;
    // 0x808007FC: nop

    after_16:
    // 0x80800800: beq         $v0, $zero, L_80800828
    if (ctx->r2 == 0) {
        // 0x80800804: addiu       $a0, $zero, 0x6B
        ctx->r4 = ADD32(0, 0X6B);
            goto L_80800828;
    }
    // 0x80800804: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80800808: jal         0x800C01A8
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_17;
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800810: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800814: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800818: addiu       $a3, $zero, 0x2011
    ctx->r7 = ADD32(0, 0X2011);
    // 0x8080081C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800820: jal         0x80085748
    // 0x80800824: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_21(rdram, ctx);
        goto after_18;
    // 0x80800824: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_18:
L_80800828:
    // 0x80800828: b           L_80800A0C
    // 0x8080082C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800A0C;
    // 0x8080082C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800830:
    // 0x80800830: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80800834: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800838: addiu       $at, $zero, 0x100B
    ctx->r1 = ADD32(0, 0X100B);
    // 0x8080083C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x80800840: beq         $v0, $at, L_80800858
    if (ctx->r2 == ctx->r1) {
        // 0x80800844: addiu       $at, $zero, 0x103F
        ctx->r1 = ADD32(0, 0X103F);
            goto L_80800858;
    }
    // 0x80800844: addiu       $at, $zero, 0x103F
    ctx->r1 = ADD32(0, 0X103F);
    // 0x80800848: beq         $v0, $at, L_80800888
    if (ctx->r2 == ctx->r1) {
        // 0x8080084C: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80800888;
    }
    // 0x8080084C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800850: b           L_80800A0C
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800858:
    // 0x80800858: jal         0x800C01A8
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_19;
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800860: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800868: addiu       $a3, $zero, 0x6010
    ctx->r7 = ADD32(0, 0X6010);
    // 0x8080086C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800870: jal         0x80085708
    // 0x80800874: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_20;
    // 0x80800874: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_20:
    // 0x80800878: jal         0x800FC6B0
    // 0x8080087C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_21;
    // 0x8080087C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_21:
    // 0x80800880: b           L_80800A0C
    // 0x80800884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800888:
    // 0x80800888: lbu         $t1, 0x65($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X65);
    // 0x8080088C: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80800890: sb          $t2, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r10;
    // 0x80800894: b           L_80800A0C
    // 0x80800898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800898: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080089C:
    // 0x8080089C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808008A0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2228, 0X16D8) << 16);
    // 0x808008A4: addiu       $a0, $a0, 0x16D8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2228, 0X16D8));
    // 0x808008A8: jal         0x80088090
    // 0x808008AC: lw          $a1, 0x38($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x808008AC: lw          $a1, 0x38($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X38);
    after_22:
    // 0x808008B0: b           L_80800A0C
    // 0x808008B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x808008B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008B8:
    // 0x808008B8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808008BC: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    // 0x808008C0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x808008C4: lwc1        $f4, 0x54($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X54);
    // 0x808008C8: addiu       $a1, $t4, 0x18
    ctx->r5 = ADD32(ctx->r12, 0X18);
    // 0x808008CC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808008D0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808008D4: jal         0x80108528
    // 0x808008D8: nop

    func_80108528(rdram, ctx);
        goto after_23;
    // 0x808008D8: nop

    after_23:
    // 0x808008DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808008E0: lhu         $t6, 0x76($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X76);
    // 0x808008E4: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x808008E8: ori         $t8, $t7, 0x1980
    ctx->r24 = ctx->r15 | 0X1980;
    // 0x808008EC: jal         0x800DB9B0
    // 0x808008F0: sh          $t8, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r24;
    func_800DB9B0(rdram, ctx);
        goto after_24;
    // 0x808008F0: sh          $t8, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r24;
    after_24:
    // 0x808008F4: beq         $v0, $zero, L_8080090C
    if (ctx->r2 == 0) {
        // 0x808008F8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_8080090C;
    }
    // 0x808008F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008FC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80800900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800904: jal         0x800862D8
    // 0x80800908: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x80800908: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_25:
L_8080090C:
    // 0x8080090C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800910: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800914: beq         $t0, $zero, L_80800924
    if (ctx->r8 == 0) {
        // 0x80800918: nop
    
            goto L_80800924;
    }
    // 0x80800918: nop

    // 0x8080091C: jal         0x800FFA88
    // 0x80800920: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_26;
    // 0x80800920: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_26:
L_80800924:
    // 0x80800924: b           L_80800A0C
    // 0x80800928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080092C:
    // 0x8080092C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800930: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80800934: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80800938: lhu         $v0, 0x72($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X72);
    // 0x8080093C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800944: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800948: beq         $t3, $at, L_80800964
    if (ctx->r11 == ctx->r1) {
        // 0x8080094C: addiu       $a0, $zero, 0xDF
        ctx->r4 = ADD32(0, 0XDF);
            goto L_80800964;
    }
    // 0x8080094C: addiu       $a0, $zero, 0xDF
    ctx->r4 = ADD32(0, 0XDF);
    // 0x80800950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800954: beq         $t3, $at, L_808009C8
    if (ctx->r11 == ctx->r1) {
        // 0x80800958: addiu       $t4, $zero, 0x4E
        ctx->r12 = ADD32(0, 0X4E);
            goto L_808009C8;
    }
    // 0x80800958: addiu       $t4, $zero, 0x4E
    ctx->r12 = ADD32(0, 0X4E);
    // 0x8080095C: b           L_808009D0
    // 0x80800960: nop

        goto L_808009D0;
    // 0x80800960: nop

L_80800964:
    // 0x80800964: jal         0x800DA298
    // 0x80800968: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x80800968: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_27:
    // 0x8080096C: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x80800970: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8080097C;
    }
    // 0x80800970: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800974: b           L_808009D0
    // 0x80800978: addiu       $a1, $zero, 0x1007
    ctx->r5 = ADD32(0, 0X1007);
        goto L_808009D0;
    // 0x80800978: addiu       $a1, $zero, 0x1007
    ctx->r5 = ADD32(0, 0X1007);
L_8080097C:
    // 0x8080097C: addiu       $a0, $zero, 0xDF
    ctx->r4 = ADD32(0, 0XDF);
    // 0x80800980: jal         0x800DA544
    // 0x80800984: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800DA544(rdram, ctx);
        goto after_28;
    // 0x80800984: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_28:
    // 0x80800988: jal         0x800F54E4
    // 0x8080098C: nop

    func_800F54E4(rdram, ctx);
        goto after_29;
    // 0x8080098C: nop

    after_29:
    // 0x80800990: jal         0x800F5410
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_30;
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x80800998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080099C: beq         $v0, $at, L_808009B8
    if (ctx->r2 == ctx->r1) {
        // 0x808009A0: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_808009B8;
    }
    // 0x808009A0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808009A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808009A8: beq         $v0, $at, L_808009C0
    if (ctx->r2 == ctx->r1) {
        // 0x808009AC: nop
    
            goto L_808009C0;
    }
    // 0x808009AC: nop

    // 0x808009B0: b           L_808009D0
    // 0x808009B4: nop

        goto L_808009D0;
    // 0x808009B4: nop

L_808009B8:
    // 0x808009B8: b           L_808009D0
    // 0x808009BC: addiu       $a1, $zero, 0x1006
    ctx->r5 = ADD32(0, 0X1006);
        goto L_808009D0;
    // 0x808009BC: addiu       $a1, $zero, 0x1006
    ctx->r5 = ADD32(0, 0X1006);
L_808009C0:
    // 0x808009C0: b           L_808009D0
    // 0x808009C4: addiu       $a1, $zero, 0x106B
    ctx->r5 = ADD32(0, 0X106B);
        goto L_808009D0;
    // 0x808009C4: addiu       $a1, $zero, 0x106B
    ctx->r5 = ADD32(0, 0X106B);
L_808009C8:
    // 0x808009C8: addiu       $a1, $zero, 0x1008
    ctx->r5 = ADD32(0, 0X1008);
    // 0x808009CC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_808009D0:
    // 0x808009D0: beq         $a1, $zero, L_808009F0
    if (ctx->r5 == 0) {
        // 0x808009D4: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_808009F0;
    }
    // 0x808009D4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808009D8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x808009DC: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x808009E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808009E8: jal         0x8008A208
    // 0x808009EC: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_31;
    // 0x808009EC: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_31:
L_808009F0:
    // 0x808009F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808009F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009F8: lbu         $t8, 0x65($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X65);
    // 0x808009FC: andi        $t0, $t8, 0xFFEF
    ctx->r8 = ctx->r24 & 0XFFEF;
    // 0x80800A00: b           L_80800A0C
    // 0x80800A04: sb          $t0, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r8;
        goto L_80800A0C;
    // 0x80800A04: sb          $t0, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r8;
L_80800A08:
    // 0x80800A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A0C:
    // 0x80800A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
RECOMP_FUNC void func_8080103C_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080103C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801040: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801044: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801048: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080104C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801050: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801054: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801058: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x8080105C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801064: blez        $v0, L_808010A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801068: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808010A0;
    }
    // 0x80801068: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080106C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80801070:
    // 0x80801070: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801074: beql        $a0, $zero, L_80801094
    if (ctx->r4 == 0) {
        // 0x80801078: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801094;
    }
    goto skip_0;
    // 0x80801078: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8080107C: jal         0x80087AE0
    // 0x80801080: addu        $s2, $s3, $s1
    ctx->r18 = ADD32(ctx->r19, ctx->r17);
    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801080: addu        $s2, $s3, $s1
    ctx->r18 = ADD32(ctx->r19, ctx->r17);
    after_0:
    // 0x80801084: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80801088: sb          $s4, 0x94($s2)
    MEM_B(0X94, ctx->r18) = ctx->r20;
    // 0x8080108C: lh          $v0, 0x2($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2);
    // 0x80801090: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801094:
    // 0x80801094: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801098: bne         $at, $zero, L_80801070
    if (ctx->r1 != 0) {
        // 0x8080109C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80801070;
    }
    // 0x8080109C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808010A0:
    // 0x808010A0: lw          $a0, 0x20($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X20);
    // 0x808010A4: beql        $a0, $zero, L_808010C4
    if (ctx->r4 == 0) {
        // 0x808010A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808010C4;
    }
    goto skip_1;
    // 0x808010A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x808010AC: jal         0x80087AE0
    // 0x808010B0: nop

    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808010B0: nop

    after_1:
    // 0x808010B4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x808010B8: sw          $zero, 0x20($s3)
    MEM_W(0X20, ctx->r19) = 0;
    // 0x808010BC: sb          $t6, 0x24($s3)
    MEM_B(0X24, ctx->r19) = ctx->r14;
    // 0x808010C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808010C4:
    // 0x808010C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808010CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808010D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808010D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808010D8: jr          $ra
    // 0x808010DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808010DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808005D0_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808005D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808005D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808005DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808005E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808005E4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x808005E8: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x808005EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808005F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808005F4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808005F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808005FC: bne         $a2, $zero, L_808006A0
    if (ctx->r6 != 0) {
        // 0x80800600: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_808006A0;
    }
    // 0x80800600: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800604: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800608: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x8080060C: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
L_80800610:
    // 0x80800610: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x80800614: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x80800618: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080061C: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x80800620: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80800624: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800628: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8080062C: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    // 0x80800630: beql        $a0, $zero, L_80800690
    if (ctx->r4 == 0) {
        // 0x80800634: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800690;
    }
    goto skip_0;
    // 0x80800634: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800638: jal         0x80088F30
    // 0x8080063C: nop

    _idworldmake_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080063C: nop

    after_0:
    // 0x80800640: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x80800644: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80800648: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x8080064C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800650: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x80800654: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80800658: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8080065C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80800660: jal         0x80088898
    // 0x80800664: lw          $a0, 0x50($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X50);
    _glidmake_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800664: lw          $a0, 0x50($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X50);
    after_1:
    // 0x80800668: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x8080066C: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x80800670: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80800674: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800678: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x8080067C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80800680: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80800684: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800688: sw          $zero, 0x50($t7)
    MEM_W(0X50, ctx->r15) = 0;
    // 0x8080068C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800690:
    // 0x80800690: bnel        $s0, $s3, L_80800610
    if (ctx->r16 != ctx->r19) {
        // 0x80800694: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_80800610;
    }
    goto skip_1;
    // 0x80800694: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    skip_1:
    // 0x80800698: b           L_8080086C
    // 0x8080069C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8080086C;
    // 0x8080069C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808006A0:
    // 0x808006A0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808006A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808006A8: addiu       $s6, $zero, 0x58
    ctx->r22 = ADD32(0, 0X58);
L_808006AC:
    // 0x808006AC: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x808006B0: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x808006B4: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x808006B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808006BC: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x808006C0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x808006C4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x808006C8: addu        $t0, $v0, $s4
    ctx->r8 = ADD32(ctx->r2, ctx->r20);
    // 0x808006CC: lhu         $v1, 0x40($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X40);
    // 0x808006D0: beql        $v1, $zero, L_808007C4
    if (ctx->r3 == 0) {
        // 0x808006D4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808007C4;
    }
    goto skip_2;
    // 0x808006D4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x808006D8: lbu         $t1, 0x81($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X81);
    // 0x808006DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808006E0: sllv        $t3, $t2, $s3
    ctx->r11 = S32(ctx->r10 << (ctx->r19 & 31));
    // 0x808006E4: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x808006E8: beq         $t4, $zero, L_808007C0
    if (ctx->r12 == 0) {
        // 0x808006EC: sll         $s0, $s3, 2
        ctx->r16 = S32(ctx->r19 << 2);
            goto L_808007C0;
    }
    // 0x808006EC: sll         $s0, $s3, 2
    ctx->r16 = S32(ctx->r19 << 2);
    // 0x808006F0: addu        $t5, $v0, $s0
    ctx->r13 = ADD32(ctx->r2, ctx->r16);
    // 0x808006F4: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x808006F8: bnel        $t6, $zero, L_808007C4
    if (ctx->r14 != 0) {
        // 0x808006FC: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808007C4;
    }
    goto skip_3;
    // 0x808006FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x80800700: beq         $s3, $zero, L_80800718
    if (ctx->r19 == 0) {
        // 0x80800704: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800718;
    }
    // 0x80800704: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800708: jal         0x800D674C
    // 0x8080070C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x8080070C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_2:
    // 0x80800710: b           L_80800718
    // 0x80800714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80800718;
    // 0x80800714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800718:
    // 0x80800718: jal         0x800B274C
    // 0x8080071C: nop

    func_800B274C(rdram, ctx);
        goto after_3;
    // 0x8080071C: nop

    after_3:
    // 0x80800720: beq         $v0, $zero, L_8080076C
    if (ctx->r2 == 0) {
        // 0x80800724: sll         $t5, $s2, 2
        ctx->r13 = S32(ctx->r18 << 2);
            goto L_8080076C;
    }
    // 0x80800724: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x80800728: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080072C: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x80800730: mflo        $t8
    ctx->r24 = lo;
    // 0x80800734: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80800738: addu        $t9, $a1, $s4
    ctx->r25 = ADD32(ctx->r5, ctx->r20);
    // 0x8080073C: jal         0x800888A0
    // 0x80800740: lhu         $a0, 0x40($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X40);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800740: lhu         $a0, 0x40($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X40);
    after_4:
    // 0x80800744: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x80800748: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x8080074C: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80800750: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800754: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x80800758: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8080075C: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x80800760: addu        $t3, $t1, $s0
    ctx->r11 = ADD32(ctx->r9, ctx->r16);
    // 0x80800764: b           L_8080078C
    // 0x80800768: sw          $v0, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->r2;
        goto L_8080078C;
    // 0x80800768: sw          $v0, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->r2;
L_8080076C:
    // 0x8080076C: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x80800770: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80800774: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800778: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x8080077C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80800780: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80800784: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800788: sw          $zero, 0x50($t7)
    MEM_W(0X50, ctx->r15) = 0;
L_8080078C:
    // 0x8080078C: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80800790: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x80800794: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x80800798: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080079C: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x808007A0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x808007A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x808007A8: addu        $t2, $t0, $s0
    ctx->r10 = ADD32(ctx->r8, ctx->r16);
    // 0x808007AC: lw          $a0, 0x50($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X50);
    // 0x808007B0: beql        $a0, $zero, L_808007C4
    if (ctx->r4 == 0) {
        // 0x808007B4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808007C4;
    }
    goto skip_4;
    // 0x808007B4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
    // 0x808007B8: jal         0x80088F20
    // 0x808007BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _idworldmake_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808007BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_808007C0:
    // 0x808007C0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808007C4:
    // 0x808007C4: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x808007C8: bne         $at, $zero, L_808006AC
    if (ctx->r1 != 0) {
        // 0x808007CC: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_808006AC;
    }
    // 0x808007CC: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x808007D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808007D4: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x808007D8: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
L_808007DC:
    // 0x808007DC: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x808007E0: lw          $v0, 0x68($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X68);
    // 0x808007E4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808007E8: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x808007EC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x808007F0: addu        $t3, $v0, $t1
    ctx->r11 = ADD32(ctx->r2, ctx->r9);
    // 0x808007F4: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x808007F8: lw          $t5, 0x50($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X50);
    // 0x808007FC: beql        $t5, $zero, L_80800860
    if (ctx->r13 == 0) {
        // 0x80800800: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800860;
    }
    goto skip_5;
    // 0x80800800: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_5:
    // 0x80800804: beq         $s0, $zero, L_80800828
    if (ctx->r16 == 0) {
        // 0x80800808: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800828;
    }
    // 0x80800808: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080080C: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800810: mflo        $t6
    ctx->r14 = lo;
    // 0x80800814: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800818: jal         0x800D674C
    // 0x8080081C: lhu         $a0, 0x42($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X42);
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x8080081C: lhu         $a0, 0x42($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X42);
    after_6:
    // 0x80800820: b           L_80800828
    // 0x80800824: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80800828;
    // 0x80800824: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800828:
    // 0x80800828: jal         0x800B2840
    // 0x8080082C: nop

    func_800B2840(rdram, ctx);
        goto after_7;
    // 0x8080082C: nop

    after_7:
    // 0x80800830: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80800834: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x80800838: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x8080083C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800840: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x80800844: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80800848: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8080084C: addu        $t2, $t0, $s0
    ctx->r10 = ADD32(ctx->r8, ctx->r16);
    // 0x80800850: lw          $a0, 0x50($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X50);
    // 0x80800854: jal         0x80088688
    // 0x80800858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _glid_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8080085C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800860:
    // 0x80800860: bnel        $s0, $s3, L_808007DC
    if (ctx->r16 != ctx->r19) {
        // 0x80800864: sll         $t1, $s2, 2
        ctx->r9 = S32(ctx->r18 << 2);
            goto L_808007DC;
    }
    goto skip_6;
    // 0x80800864: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    skip_6:
    // 0x80800868: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080086C:
    // 0x8080086C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800870: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800874: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800878: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080087C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800880: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800884: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800888: jr          $ra
    // 0x8080088C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080088C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C4350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4350: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C4354: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C4358: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x800C435C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C4360: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C4364: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800C4368: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C436C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C4370: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C4374: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C4378: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C437C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C4380: bne         $s2, $zero, L_800C43B0
    if (ctx->r18 != 0) {
        // 0x800C4384: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800C43B0;
    }
    // 0x800C4384: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C4388: jal         0x800C2E04
    // 0x800C438C: nop

    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x800C438C: nop

    after_0:
    // 0x800C4390: bne         $v0, $zero, L_800C43A0
    if (ctx->r2 != 0) {
        // 0x800C4394: andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
            goto L_800C43A0;
    }
    // 0x800C4394: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800C4398: b           L_800C4ACC
    // 0x800C439C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C4ACC;
    // 0x800C439C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C43A0:
    // 0x800C43A0: jal         0x800C1414
    // 0x800C43A4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C1414(rdram, ctx);
        goto after_1;
    // 0x800C43A4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_1:
    // 0x800C43A8: b           L_800C43BC
    // 0x800C43AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800C43BC;
    // 0x800C43AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C43B0:
    // 0x800C43B0: jal         0x800C1414
    // 0x800C43B4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C1414(rdram, ctx);
        goto after_2;
    // 0x800C43B4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_2:
    // 0x800C43B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C43BC:
    // 0x800C43BC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800C43C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C43C4: beq         $t6, $zero, L_800C43F0
    if (ctx->r14 == 0) {
        // 0x800C43C8: nop
    
            goto L_800C43F0;
    }
    // 0x800C43C8: nop

    // 0x800C43CC: jal         0x800EE7F8
    // 0x800C43D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800C43D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_3:
    // 0x800C43D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C43D8: jal         0x800C13A0
    // 0x800C43DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13A0(rdram, ctx);
        goto after_4;
    // 0x800C43DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x800C43E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C43E4: jal         0x800EA05C
    // 0x800C43E8: sb          $t7, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r15;
    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x800C43E8: sb          $t7, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r15;
    after_5:
    // 0x800C43EC: sh          $v0, 0x5E($s1)
    MEM_H(0X5E, ctx->r17) = ctx->r2;
L_800C43F0:
    // 0x800C43F0: bnel        $s0, $zero, L_800C4414
    if (ctx->r16 != 0) {
        // 0x800C43F4: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_800C4414;
    }
    goto skip_0;
    // 0x800C43F4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x800C43F8: beq         $s2, $zero, L_800C4408
    if (ctx->r18 == 0) {
        // 0x800C43FC: nop
    
            goto L_800C4408;
    }
    // 0x800C43FC: nop

    // 0x800C4400: jal         0x800C3BDC
    // 0x800C4404: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x800C4404: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_6:
L_800C4408:
    // 0x800C4408: b           L_800C4ACC
    // 0x800C440C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800C4ACC;
    // 0x800C440C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800C4410: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4414:
    // 0x800C4414: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C4418: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800C441C: beq         $v1, $zero, L_800C4AB8
    if (ctx->r3 == 0) {
        // 0x800C4420: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_800C4AB8;
    }
    // 0x800C4420: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C4424: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C4428: addiu       $s3, $s3, -0x5670
    ctx->r19 = ADD32(ctx->r19, -0X5670);
    // 0x800C442C: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
L_800C4430:
    // 0x800C4430: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C4434: sltiu       $at, $t9, 0x24
    ctx->r1 = ctx->r25 < 0X24 ? 1 : 0;
    // 0x800C4438: beq         $at, $zero, L_800C4AA8
    if (ctx->r1 == 0) {
        // 0x800C443C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800C4AA8;
    }
    // 0x800C443C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C4440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4444: addu        $at, $at, $t9
    gpr jr_addend_800C444C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C4448: lw          $t9, 0x5800($at)
    ctx->r25 = ADD32(ctx->r1, 0X5800);
    // 0x800C444C: jr          $t9
    // 0x800C4450: nop

    switch (jr_addend_800C444C >> 2) {
        case 0: goto L_800C4454; break;
        case 1: goto L_800C44A0; break;
        case 2: goto L_800C454C; break;
        case 3: goto L_800C4554; break;
        case 4: goto L_800C4564; break;
        case 5: goto L_800C4584; break;
        case 6: goto L_800C45A0; break;
        case 7: goto L_800C45B0; break;
        case 8: goto L_800C45D0; break;
        case 9: goto L_800C45F4; break;
        case 10: goto L_800C4620; break;
        case 11: goto L_800C4684; break;
        case 12: goto L_800C4700; break;
        case 13: goto L_800C4764; break;
        case 14: goto L_800C47E0; break;
        case 15: goto L_800C47F8; break;
        case 16: goto L_800C4808; break;
        case 17: goto L_800C4810; break;
        case 18: goto L_800C4854; break;
        case 19: goto L_800C4864; break;
        case 20: goto L_800C48A8; break;
        case 21: goto L_800C4908; break;
        case 22: goto L_800C4920; break;
        case 23: goto L_800C4950; break;
        case 24: goto L_800C4964; break;
        case 25: goto L_800C4998; break;
        case 26: goto L_800C49CC; break;
        case 27: goto L_800C49E8; break;
        case 28: goto L_800C4748; break;
        case 29: goto L_800C4984; break;
        case 30: goto L_800C48FC; break;
        case 31: goto L_800C44B0; break;
        case 32: goto L_800C49F8; break;
        case 33: goto L_800C44E4; break;
        case 34: goto L_800C4A0C; break;
        case 35: goto L_800C4518; break;
        default: switch_error(__func__, 0x800C444C, 0x80125800);
    }
    // 0x800C4450: nop

L_800C4454:
    // 0x800C4454: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800C4458: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x800C445C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4460: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C4464: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800C4468: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C446C: beq         $t2, $zero, L_800C4498
    if (ctx->r10 == 0) {
        // 0x800C4470: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C4498;
    }
    // 0x800C4470: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4474: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C4478: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C447C: sb          $t3, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r11;
    // 0x800C4480: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C4484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4488: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C448C: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x800C4490: jal         0x800C13A0
    // 0x800C4494: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    func_800C13A0(rdram, ctx);
        goto after_7;
    // 0x800C4494: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    after_7:
L_800C4498:
    // 0x800C4498: b           L_800C4AA8
    // 0x800C449C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_800C4AA8;
    // 0x800C449C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C44A0:
    // 0x800C44A0: andi        $t4, $v1, 0xFF00
    ctx->r12 = ctx->r3 & 0XFF00;
    // 0x800C44A4: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800C44A8: b           L_800C4AA8
    // 0x800C44AC: sb          $t5, 0x63($s1)
    MEM_B(0X63, ctx->r17) = ctx->r13;
        goto L_800C4AA8;
    // 0x800C44AC: sb          $t5, 0x63($s1)
    MEM_B(0X63, ctx->r17) = ctx->r13;
L_800C44B0:
    // 0x800C44B0: andi        $t6, $v1, 0xFF00
    ctx->r14 = ctx->r3 & 0XFF00;
    // 0x800C44B4: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C44B8: beq         $t7, $zero, L_800C44D4
    if (ctx->r15 == 0) {
        // 0x800C44BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C44D4;
    }
    // 0x800C44BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C44C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C44C4: jal         0x800C13B0
    // 0x800C44C8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13B0(rdram, ctx);
        goto after_8;
    // 0x800C44C8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_8:
    // 0x800C44CC: b           L_800C4AAC
    // 0x800C44D0: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C44D0: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C44D4:
    // 0x800C44D4: jal         0x800C13A0
    // 0x800C44D8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800C13A0(rdram, ctx);
        goto after_9;
    // 0x800C44D8: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_9:
    // 0x800C44DC: b           L_800C4AAC
    // 0x800C44E0: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C44E0: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C44E4:
    // 0x800C44E4: andi        $t8, $v1, 0xFF00
    ctx->r24 = ctx->r3 & 0XFF00;
    // 0x800C44E8: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800C44EC: beq         $t9, $zero, L_800C4508
    if (ctx->r25 == 0) {
        // 0x800C44F0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C4508;
    }
    // 0x800C44F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C44F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C44F8: jal         0x800C13B0
    // 0x800C44FC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13B0(rdram, ctx);
        goto after_10;
    // 0x800C44FC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_10:
    // 0x800C4500: b           L_800C4AAC
    // 0x800C4504: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4504: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4508:
    // 0x800C4508: jal         0x800C13A0
    // 0x800C450C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800C13A0(rdram, ctx);
        goto after_11;
    // 0x800C450C: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_11:
    // 0x800C4510: b           L_800C4AAC
    // 0x800C4514: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4514: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4518:
    // 0x800C4518: andi        $t0, $v1, 0xFF00
    ctx->r8 = ctx->r3 & 0XFF00;
    // 0x800C451C: sra         $t1, $t0, 8
    ctx->r9 = S32(SIGNED(ctx->r8) >> 8);
    // 0x800C4520: beq         $t1, $zero, L_800C453C
    if (ctx->r9 == 0) {
        // 0x800C4524: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C453C;
    }
    // 0x800C4524: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C452C: jal         0x800C13A0
    // 0x800C4530: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    func_800C13A0(rdram, ctx);
        goto after_12;
    // 0x800C4530: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_12:
    // 0x800C4534: b           L_800C4AAC
    // 0x800C4538: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4538: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C453C:
    // 0x800C453C: jal         0x800C13B0
    // 0x800C4540: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    func_800C13B0(rdram, ctx);
        goto after_13;
    // 0x800C4540: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_13:
    // 0x800C4544: b           L_800C4AAC
    // 0x800C4548: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4548: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C454C:
    // 0x800C454C: b           L_800C4ACC
    // 0x800C4550: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800C4ACC;
    // 0x800C4550: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800C4554:
    // 0x800C4554: jal         0x800C2FDC
    // 0x800C4558: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C2FDC(rdram, ctx);
        goto after_14;
    // 0x800C4558: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_14:
    // 0x800C455C: b           L_800C4ACC
    // 0x800C4560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C4ACC;
    // 0x800C4560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C4564:
    // 0x800C4564: andi        $t2, $v1, 0xFF00
    ctx->r10 = ctx->r3 & 0XFF00;
    // 0x800C4568: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800C456C: sb          $t3, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r11;
    // 0x800C4570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4574: jal         0x800C13A0
    // 0x800C4578: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800C13A0(rdram, ctx);
        goto after_15;
    // 0x800C4578: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_15:
    // 0x800C457C: b           L_800C4AAC
    // 0x800C4580: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4580: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4584:
    // 0x800C4584: andi        $a1, $v1, 0xFF00
    ctx->r5 = ctx->r3 & 0XFF00;
    // 0x800C4588: sra         $t4, $a1, 8
    ctx->r12 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800C458C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800C4590: jal         0x800C11F8
    // 0x800C4594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C11F8(rdram, ctx);
        goto after_16;
    // 0x800C4594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x800C4598: b           L_800C4AAC
    // 0x800C459C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C459C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C45A0:
    // 0x800C45A0: andi        $t5, $v1, 0xFF00
    ctx->r13 = ctx->r3 & 0XFF00;
    // 0x800C45A4: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800C45A8: b           L_800C4AA8
    // 0x800C45AC: sb          $t6, 0x62($s1)
    MEM_B(0X62, ctx->r17) = ctx->r14;
        goto L_800C4AA8;
    // 0x800C45AC: sb          $t6, 0x62($s1)
    MEM_B(0X62, ctx->r17) = ctx->r14;
L_800C45B0:
    // 0x800C45B0: andi        $t7, $v1, 0xFF00
    ctx->r15 = ctx->r3 & 0XFF00;
    // 0x800C45B4: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C45B8: sb          $t8, 0x61($s1)
    MEM_B(0X61, ctx->r17) = ctx->r24;
    // 0x800C45BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C45C0: jal         0x800C13A0
    // 0x800C45C4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_800C13A0(rdram, ctx);
        goto after_17;
    // 0x800C45C4: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_17:
    // 0x800C45C8: b           L_800C4AAC
    // 0x800C45CC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C45CC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C45D0:
    // 0x800C45D0: andi        $t9, $v1, 0xFF00
    ctx->r25 = ctx->r3 & 0XFF00;
    // 0x800C45D4: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C45D8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C45DC: beq         $t1, $zero, L_800C45EC
    if (ctx->r9 == 0) {
        // 0x800C45E0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800C45EC;
    }
    // 0x800C45E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C45E4: b           L_800C4AA8
    // 0x800C45E8: sb          $t2, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r10;
        goto L_800C4AA8;
    // 0x800C45E8: sb          $t2, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r10;
L_800C45EC:
    // 0x800C45EC: b           L_800C4AA8
    // 0x800C45F0: sb          $zero, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = 0;
        goto L_800C4AA8;
    // 0x800C45F0: sb          $zero, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = 0;
L_800C45F4:
    // 0x800C45F4: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800C45F8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C45FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4600: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800C4604: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C4608: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C460C: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4610: jal         0x800C13A0
    // 0x800C4614: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    func_800C13A0(rdram, ctx);
        goto after_18;
    // 0x800C4614: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    after_18:
    // 0x800C4618: b           L_800C4AAC
    // 0x800C461C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C461C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4620:
    // 0x800C4620: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800C4624: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800C4628: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800C462C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800C4630: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C4634: lhu         $t7, 0x7A($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X7A);
    // 0x800C4638: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C463C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C4640: andi        $t8, $t7, 0xFC3F
    ctx->r24 = ctx->r15 & 0XFC3F;
    // 0x800C4644: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800C4648: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800C464C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4650: mul.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C4654: sh          $t9, 0x7A($s1)
    MEM_H(0X7A, ctx->r17) = ctx->r25;
    // 0x800C4658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C465C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C4660: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4664: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    // 0x800C4668: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C466C: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x800C4670: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C4674: jal         0x800C13A0
    // 0x800C4678: swc1        $f12, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f12.u32l;
    func_800C13A0(rdram, ctx);
        goto after_19;
    // 0x800C4678: swc1        $f12, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f12.u32l;
    after_19:
    // 0x800C467C: b           L_800C4AAC
    // 0x800C4680: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4680: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4684:
    // 0x800C4684: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800C4688: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x800C468C: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x800C4690: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C4694: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800C4698: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800C469C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C46A0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800C46A4: lhu         $t4, 0x7A($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X7A);
    // 0x800C46A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C46AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C46B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C46B4: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C46B8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800C46BC: andi        $t5, $t4, 0xFC3F
    ctx->r13 = ctx->r12 & 0XFC3F;
    // 0x800C46C0: ori         $t6, $t5, 0xC0
    ctx->r14 = ctx->r13 | 0XC0;
    // 0x800C46C4: sh          $t6, 0x7A($s1)
    MEM_H(0X7A, ctx->r17) = ctx->r14;
    // 0x800C46C8: mul.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C46CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C46D0: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x800C46D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C46D8: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x800C46DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C46E0: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C46E4: nop

    // 0x800C46E8: mul.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C46EC: swc1        $f12, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f12.u32l;
    // 0x800C46F0: jal         0x800C13A0
    // 0x800C46F4: swc1        $f14, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f14.u32l;
    func_800C13A0(rdram, ctx);
        goto after_20;
    // 0x800C46F4: swc1        $f14, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f14.u32l;
    after_20:
    // 0x800C46F8: b           L_800C4AAC
    // 0x800C46FC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C46FC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4700:
    // 0x800C4700: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800C4704: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x800C4708: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C470C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C4710: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C4714: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4718: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C471C: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4720: nop

    // 0x800C4724: mul.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C4728: jal         0x800DC264
    // 0x800C472C: nop

    func_800DC264(rdram, ctx);
        goto after_21;
    // 0x800C472C: nop

    after_21:
    // 0x800C4730: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    // 0x800C4734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4738: jal         0x800C13A0
    // 0x800C473C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_22;
    // 0x800C473C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_22:
    // 0x800C4740: b           L_800C4AAC
    // 0x800C4744: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4744: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4748:
    // 0x800C4748: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800C474C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4750: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C4754: jal         0x800C13A0
    // 0x800C4758: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    func_800C13A0(rdram, ctx);
        goto after_23;
    // 0x800C4758: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    after_23:
    // 0x800C475C: b           L_800C4AAC
    // 0x800C4760: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4760: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4764:
    // 0x800C4764: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800C4768: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800C476C: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x800C4770: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800C4774: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800C4778: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C477C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4780: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C4784: lhu         $t2, 0x7A($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X7A);
    // 0x800C4788: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800C478C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4790: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4794: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4798: andi        $t3, $t2, 0xFC3F
    ctx->r11 = ctx->r10 & 0XFC3F;
    // 0x800C479C: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x800C47A0: sh          $t4, 0x7A($s1)
    MEM_H(0X7A, ctx->r17) = ctx->r12;
    // 0x800C47A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C47A8: mul.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C47AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C47B0: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800C47B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C47B8: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x800C47BC: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C47C0: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C47C4: nop

    // 0x800C47C8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C47CC: swc1        $f12, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f12.u32l;
    // 0x800C47D0: jal         0x800C13A0
    // 0x800C47D4: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    func_800C13A0(rdram, ctx);
        goto after_24;
    // 0x800C47D4: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    after_24:
    // 0x800C47D8: b           L_800C4AAC
    // 0x800C47DC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C47DC: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C47E0:
    // 0x800C47E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C47E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C47E8: jal         0x800C11F8
    // 0x800C47EC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    func_800C11F8(rdram, ctx);
        goto after_25;
    // 0x800C47EC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_25:
    // 0x800C47F0: b           L_800C4AA8
    // 0x800C47F4: sb          $zero, 0x62($s1)
    MEM_B(0X62, ctx->r17) = 0;
        goto L_800C4AA8;
    // 0x800C47F4: sb          $zero, 0x62($s1)
    MEM_B(0X62, ctx->r17) = 0;
L_800C47F8:
    // 0x800C47F8: jal         0x800C2E40
    // 0x800C47FC: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C2E40(rdram, ctx);
        goto after_26;
    // 0x800C47FC: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_26:
    // 0x800C4800: b           L_800C4AAC
    // 0x800C4804: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4804: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4808:
    // 0x800C4808: b           L_800C4AA8
    // 0x800C480C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
        goto L_800C4AA8;
    // 0x800C480C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800C4810:
    // 0x800C4810: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x800C4814: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C4818: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C481C: sll         $t6, $t5, 19
    ctx->r14 = S32(ctx->r13 << 19);
    // 0x800C4820: srl         $t7, $t6, 29
    ctx->r15 = S32(U32(ctx->r14) >> 29);
    // 0x800C4824: bnel        $t7, $at, L_800C4AAC
    if (ctx->r15 != ctx->r1) {
        // 0x800C4828: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_800C4AAC;
    }
    goto skip_1;
    // 0x800C4828: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x800C482C: jal         0x800C1860
    // 0x800C4830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C1860(rdram, ctx);
        goto after_27;
    // 0x800C4830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x800C4834: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x800C4838: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C483C: beql        $v0, $zero, L_800C4AAC
    if (ctx->r2 == 0) {
        // 0x800C4840: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_800C4AAC;
    }
    goto skip_2;
    // 0x800C4840: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_2:
    // 0x800C4844: jalr        $v0
    // 0x800C4848: lw          $a1, 0x68($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X68);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_28;
    // 0x800C4848: lw          $a1, 0x68($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X68);
    after_28:
    // 0x800C484C: b           L_800C4AAC
    // 0x800C4850: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4850: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4854:
    // 0x800C4854: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800C4858: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C485C: b           L_800C4AA8
    // 0x800C4860: sh          $v0, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r2;
        goto L_800C4AA8;
    // 0x800C4860: sh          $v0, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r2;
L_800C4864:
    // 0x800C4864: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4868: andi        $v0, $v1, 0xFF00
    ctx->r2 = ctx->r3 & 0XFF00;
    // 0x800C486C: sra         $t9, $v0, 8
    ctx->r25 = S32(SIGNED(ctx->r2) >> 8);
    // 0x800C4870: beql        $t8, $zero, L_800C4AAC
    if (ctx->r24 == 0) {
        // 0x800C4874: lh          $v1, 0x0($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X0);
            goto L_800C4AAC;
    }
    goto skip_3;
    // 0x800C4874: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    skip_3:
    // 0x800C4878: beq         $t9, $zero, L_800C4894
    if (ctx->r25 == 0) {
        // 0x800C487C: sb          $t9, 0x1B($s1)
        MEM_B(0X1B, ctx->r17) = ctx->r25;
            goto L_800C4894;
    }
    // 0x800C487C: sb          $t9, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r25;
    // 0x800C4880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4884: jal         0x800C13A0
    // 0x800C4888: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13A0(rdram, ctx);
        goto after_29;
    // 0x800C4888: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_29:
    // 0x800C488C: b           L_800C4AAC
    // 0x800C4890: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4890: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4894:
    // 0x800C4894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4898: jal         0x800C13B0
    // 0x800C489C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C13B0(rdram, ctx);
        goto after_30;
    // 0x800C489C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_30:
    // 0x800C48A0: b           L_800C4AAC
    // 0x800C48A4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C48A4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C48A8:
    // 0x800C48A8: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x800C48AC: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x800C48B0: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x800C48B4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800C48B8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800C48BC: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800C48C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C48C4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800C48C8: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C48CC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C48D0: mul.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C48D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C48D8: mul.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800C48DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C48E0: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C48E4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C48E8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800C48EC: jal         0x800C3A40
    // 0x800C48F0: nop

    func_800C3A40(rdram, ctx);
        goto after_31;
    // 0x800C48F0: nop

    after_31:
    // 0x800C48F4: b           L_800C4AAC
    // 0x800C48F8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C48F8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C48FC:
    // 0x800C48FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C4900: b           L_800C4AA8
    // 0x800C4904: sb          $t3, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r11;
        goto L_800C4AA8;
    // 0x800C4904: sb          $t3, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r11;
L_800C4908:
    // 0x800C4908: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C490C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800C4910: jal         0x800C3058
    // 0x800C4914: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    func_800C3058(rdram, ctx);
        goto after_32;
    // 0x800C4914: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_32:
    // 0x800C4918: b           L_800C4AAC
    // 0x800C491C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C491C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4920:
    // 0x800C4920: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800C4924: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800C4928: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x800C492C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800C4930: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x800C4934: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C4938: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C493C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800C4940: jal         0x800C316C
    // 0x800C4944: nop

    func_800C316C(rdram, ctx);
        goto after_33;
    // 0x800C4944: nop

    after_33:
    // 0x800C4948: b           L_800C4AAC
    // 0x800C494C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C494C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4950:
    // 0x800C4950: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C4954: jal         0x800C3058
    // 0x800C4958: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800C3058(rdram, ctx);
        goto after_34;
    // 0x800C4958: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_34:
    // 0x800C495C: b           L_800C4AAC
    // 0x800C4960: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4960: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4964:
    // 0x800C4964: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800C4968: jal         0x800DC214
    // 0x800C496C: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    func_800DC214(rdram, ctx);
        goto after_35;
    // 0x800C496C: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_35:
    // 0x800C4970: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C4974: jal         0x800C3058
    // 0x800C4978: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800C3058(rdram, ctx);
        goto after_36;
    // 0x800C4978: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_36:
    // 0x800C497C: b           L_800C4AA8
    // 0x800C4980: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_800C4AA8;
    // 0x800C4980: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C4984:
    // 0x800C4984: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C4988: jal         0x800C3058
    // 0x800C498C: lh          $a1, 0x4($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X4);
    func_800C3058(rdram, ctx);
        goto after_37;
    // 0x800C498C: lh          $a1, 0x4($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X4);
    after_37:
    // 0x800C4990: b           L_800C4AAC
    // 0x800C4994: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4994: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4998:
    // 0x800C4998: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800C499C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800C49A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C49A4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C49A8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C49AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C49B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C49B4: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C49B8: nop

    // 0x800C49BC: mul.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C49C0: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
    // 0x800C49C4: b           L_800C4AA8
    // 0x800C49C8: swc1        $f2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f2.u32l;
        goto L_800C4AA8;
    // 0x800C49C8: swc1        $f2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f2.u32l;
L_800C49CC:
    // 0x800C49CC: andi        $a1, $v1, 0xFF00
    ctx->r5 = ctx->r3 & 0XFF00;
    // 0x800C49D0: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800C49D4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C49D8: jal         0x800C3418
    // 0x800C49DC: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C3418(rdram, ctx);
        goto after_38;
    // 0x800C49DC: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_38:
    // 0x800C49E0: b           L_800C4AAC
    // 0x800C49E4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C49E4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C49E8:
    // 0x800C49E8: lbu         $t9, 0x7B($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X7B);
    // 0x800C49EC: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x800C49F0: b           L_800C4AA8
    // 0x800C49F4: sb          $t0, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r8;
        goto L_800C4AA8;
    // 0x800C49F4: sb          $t0, 0x7B($s1)
    MEM_B(0X7B, ctx->r17) = ctx->r8;
L_800C49F8:
    // 0x800C49F8: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C49FC: jal         0x800C301C
    // 0x800C4A00: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
    func_800C301C(rdram, ctx);
        goto after_39;
    // 0x800C4A00: lh          $a1, 0x6($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X6);
    after_39:
    // 0x800C4A04: b           L_800C4AAC
    // 0x800C4A08: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
        goto L_800C4AAC;
    // 0x800C4A08: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4A0C:
    // 0x800C4A0C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800C4A10: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800C4A14: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800C4A18: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C4A1C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800C4A20: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x800C4A24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4A28: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800C4A2C: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x800C4A30: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x800C4A34: lhu         $t7, 0x7A($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X7A);
    // 0x800C4A38: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4A3C: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4A40: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800C4A44: andi        $t8, $t7, 0xFC3F
    ctx->r24 = ctx->r15 & 0XFC3F;
    // 0x800C4A48: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800C4A4C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800C4A50: mul.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C4A54: sh          $t9, 0x7A($s1)
    MEM_H(0X7A, ctx->r17) = ctx->r25;
    // 0x800C4A58: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x800C4A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C4A60: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C4A64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4A68: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C4A6C: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x800C4A70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4A74: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4A78: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C4A7C: mul.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C4A80: swc1        $f12, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f12.u32l;
    // 0x800C4A84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4A88: swc1        $f14, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f14.u32l;
    // 0x800C4A8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4A90: mul.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C4A94: nop

    // 0x800C4A98: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C4A9C: swc1        $f16, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f16.u32l;
    // 0x800C4AA0: jal         0x800C13A0
    // 0x800C4AA4: swc1        $f18, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f18.u32l;
    func_800C13A0(rdram, ctx);
        goto after_40;
    // 0x800C4AA4: swc1        $f18, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f18.u32l;
    after_40:
L_800C4AA8:
    // 0x800C4AA8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_800C4AAC:
    // 0x800C4AAC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C4AB0: bnel        $v1, $zero, L_800C4430
    if (ctx->r3 != 0) {
        // 0x800C4AB4: andi        $t8, $v1, 0xFF
        ctx->r24 = ctx->r3 & 0XFF;
            goto L_800C4430;
    }
    goto skip_4;
    // 0x800C4AB4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    skip_4:
L_800C4AB8:
    // 0x800C4AB8: beql        $s4, $zero, L_800C4ACC
    if (ctx->r20 == 0) {
        // 0x800C4ABC: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_800C4ACC;
    }
    goto skip_5;
    // 0x800C4ABC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    skip_5:
    // 0x800C4AC0: jal         0x800C3BDC
    // 0x800C4AC4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_41;
    // 0x800C4AC4: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_41:
    // 0x800C4AC8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800C4ACC:
    // 0x800C4ACC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C4AD0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C4AD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4AD8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C4ADC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C4AE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C4AE4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C4AE8: jr          $ra
    // 0x800C4AEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C4AEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80809C90_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809C98: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80809C9C: jal         0x8009ADF0
    // 0x80809CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80809CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80809CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809CAC: jr          $ra
    // 0x80809CB0: nop

    return;
    // 0x80809CB0: nop

;}
RECOMP_FUNC void subaddiezone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x8080000C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800014: sll         $t8, $t6, 13
    ctx->r24 = S32(ctx->r14 << 13);
    // 0x80800018: bltzl       $t8, L_80800048
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080001C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800048;
    }
    goto skip_0;
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800020: jal         0x800BEC28
    // 0x80800024: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800BEC28(rdram, ctx);
        goto after_0;
    // 0x80800024: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800028: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800030: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800034: jal         0x80088788
    // 0x80800038: lbu         $a2, 0x78($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X78);
    _glzone_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800038: lbu         $a2, 0x78($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X78);
    after_1:
    // 0x8080003C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800040: sb          $v0, 0x78($a3)
    MEM_B(0X78, ctx->r7) = ctx->r2;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void func_80800168_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080016C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800174: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080017C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80800180: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800184: bgez        $t8, L_808001A8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800188: nop
    
            goto L_808001A8;
    }
    // 0x80800188: nop

    // 0x8080018C: jal         0x80102B6C
    // 0x80800190: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102B6C(rdram, ctx);
        goto after_0;
    // 0x80800190: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_0:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x80102B2C
    // 0x8080019C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_1;
    // 0x8080019C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_1:
    // 0x808001A0: b           L_808001C0
    // 0x808001A4: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
        goto L_808001C0;
    // 0x808001A4: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
L_808001A8:
    // 0x808001A8: jal         0x80102B6C
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102B6C(rdram, ctx);
        goto after_2;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: jal         0x80102B2C
    // 0x808001B8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80102B2C(rdram, ctx);
        goto after_3;
    // 0x808001B8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_3:
    // 0x808001BC: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
L_808001C0:
    // 0x808001C0: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    // 0x808001C4: jal         0x8010B990
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_4;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001CC: andi        $t9, $v0, 0x24
    ctx->r25 = ctx->r2 & 0X24;
    // 0x808001D0: beql        $t9, $zero, L_808001FC
    if (ctx->r25 == 0) {
        // 0x808001D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001D8: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808001DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808001E8: beql        $t1, $at, L_808001FC
    if (ctx->r9 == ctx->r1) {
        // 0x808001EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001FC;
    }
    goto skip_1;
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001F0: jal         0x80801200
    // 0x808001F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801200_cheel(rdram, ctx);
        goto after_5;
    // 0x808001F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001FC:
    // 0x808001FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void func_800F0734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0734: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800F0738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F073C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800F0740: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800F0744: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800F0748: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800F074C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800F0750: jal         0x800EFB24
    // 0x800F0754: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F0754: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_0:
    // 0x800F0758: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800F075C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800F0760: jal         0x800EFB24
    // 0x800F0764: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800F0764: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    after_1:
    // 0x800F0768: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800F076C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x800F0770: jal         0x800EFB24
    // 0x800F0774: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800F0774: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x800F0778: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800F077C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F0780: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800F0784: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800F0788: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F078C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800F0790: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x800F0794: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F0798: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800F079C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F07A0: nop

    // 0x800F07A4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F07A8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800F07AC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800F07B0: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800F07B4: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800F07B8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F07BC: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x800F07C0: nop

    // 0x800F07C4: bc1t        L_800F09B4
    if (c1cs) {
        // 0x800F07C8: nop
    
            goto L_800F09B4;
    }
    // 0x800F07C8: nop

    // 0x800F07CC: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800F07D0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800F07D4: div.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800F07D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F07DC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800F07E0: nop

    // 0x800F07E4: bc1fl       L_800F0800
    if (!c1cs) {
        // 0x800F07E8: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800F0800;
    }
    goto skip_0;
    // 0x800F07E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x800F07EC: jal         0x800EE7F8
    // 0x800F07F0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800F07F0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_3:
    // 0x800F07F4: b           L_800F0854
    // 0x800F07F8: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
        goto L_800F0854;
    // 0x800F07F8: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F07FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800F0800:
    // 0x800F0800: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F0804: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F0808: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800F080C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800F0810: bc1f        L_800F0848
    if (!c1cs) {
        // 0x800F0814: nop
    
            goto L_800F0848;
    }
    // 0x800F0814: nop

    // 0x800F0818: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800F081C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800F0820: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800F0824: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F0828: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800F082C: jal         0x800EFA20
    // 0x800F0830: nop

    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x800F0830: nop

    after_4:
    // 0x800F0834: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800F0838: jal         0x800EF04C
    // 0x800F083C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x800F083C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_5:
    // 0x800F0840: b           L_800F0854
    // 0x800F0844: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
        goto L_800F0854;
    // 0x800F0844: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
L_800F0848:
    // 0x800F0848: jal         0x800EE7F8
    // 0x800F084C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x800F084C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_6:
    // 0x800F0850: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
L_800F0854:
    // 0x800F0854: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800F0858: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800F085C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F0860: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F0864: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800F0868: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800F086C: mul.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800F0870: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800F0874: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800F0878: nop

    // 0x800F087C: bc1fl       L_800F0890
    if (!c1cs) {
        // 0x800F0880: neg.s       $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
            goto L_800F0890;
    }
    goto skip_1;
    // 0x800F0880: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    skip_1:
    // 0x800F0884: b           L_800F0A94
    // 0x800F0888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0A94;
    // 0x800F0888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F088C: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
L_800F0890:
    // 0x800F0890: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800F0894: div.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F0898: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x800F089C: jal         0x8002DCA0
    // 0x800F08A0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x800F08A0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800F08A4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F08A8: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F08AC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F08B0: jal         0x8002DCA0
    // 0x800F08B4: sub.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x800F08B4: sub.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f14.fl;
    after_8:
    // 0x800F08B8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F08BC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F08C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F08C4: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800F08C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F08CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F08D0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800F08D4: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800F08D8: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x800F08DC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x800F08E0: add.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800F08E4: bc1fl       L_800F08F8
    if (!c1cs) {
        // 0x800F08E8: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800F08F8;
    }
    goto skip_2;
    // 0x800F08E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_2:
    // 0x800F08EC: b           L_800F08FC
    // 0x800F08F0: sub.s       $f14, $f16, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f2.fl;
        goto L_800F08FC;
    // 0x800F08F0: sub.s       $f14, $f16, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800F08F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_800F08F8:
    // 0x800F08F8: nop

L_800F08FC:
    // 0x800F08FC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800F0900: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800F0904: bc1fl       L_800F0918
    if (!c1cs) {
        // 0x800F0908: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800F0918;
    }
    goto skip_3;
    // 0x800F0908: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x800F090C: b           L_800F091C
    // 0x800F0910: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800F091C;
    // 0x800F0910: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800F0914: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800F0918:
    // 0x800F0918: nop

L_800F091C:
    // 0x800F091C: jal         0x800EFE50
    // 0x800F0920: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800EFE50(rdram, ctx);
        goto after_9;
    // 0x800F0920: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x800F0924: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F0928: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800F092C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x800F0930: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800F0934: jal         0x800EFE50
    // 0x800F0938: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    func_800EFE50(rdram, ctx);
        goto after_10;
    // 0x800F0938: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    after_10:
    // 0x800F093C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800F0940: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x800F0944: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800F0948: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F094C: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800F0950: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800F0954: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800F0958: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800F095C: nop

    // 0x800F0960: bc1fl       L_800F0984
    if (!c1cs) {
        // 0x800F0964: lwc1        $f12, 0x4($t8)
        ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
            goto L_800F0984;
    }
    goto skip_4;
    // 0x800F0964: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    skip_4:
    // 0x800F0968: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F096C: nop

    // 0x800F0970: bc1fl       L_800F0984
    if (!c1cs) {
        // 0x800F0974: lwc1        $f12, 0x4($t8)
        ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
            goto L_800F0984;
    }
    goto skip_5;
    // 0x800F0974: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    skip_5:
    // 0x800F0978: b           L_800F0A94
    // 0x800F097C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F0A94;
    // 0x800F097C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0980: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
L_800F0984:
    // 0x800F0984: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800F0988: nop

    // 0x800F098C: bc1f        L_800F09AC
    if (!c1cs) {
        // 0x800F0990: nop
    
            goto L_800F09AC;
    }
    // 0x800F0990: nop

    // 0x800F0994: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F0998: nop

    // 0x800F099C: bc1f        L_800F09AC
    if (!c1cs) {
        // 0x800F09A0: nop
    
            goto L_800F09AC;
    }
    // 0x800F09A0: nop

    // 0x800F09A4: b           L_800F0A94
    // 0x800F09A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F0A94;
    // 0x800F09A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F09AC:
    // 0x800F09AC: b           L_800F0A94
    // 0x800F09B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0A94;
    // 0x800F09B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F09B4:
    // 0x800F09B4: jal         0x800F0064
    // 0x800F09B8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    func_800F0064(rdram, ctx);
        goto after_11;
    // 0x800F09B8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    after_11:
    // 0x800F09BC: beq         $v0, $zero, L_800F0A90
    if (ctx->r2 == 0) {
        // 0x800F09C0: lw          $t9, 0x80($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X80);
            goto L_800F0A90;
    }
    // 0x800F09C0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800F09C4: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800F09C8: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800F09CC: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x800F09D0: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800F09D4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800F09D8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800F09DC: nop

    // 0x800F09E0: bc1fl       L_800F0A3C
    if (!c1cs) {
        // 0x800F09E4: add.s       $f2, $f0, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
            goto L_800F0A3C;
    }
    goto skip_6;
    // 0x800F09E4: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
    skip_6:
    // 0x800F09E8: lwc1        $f6, 0x4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800F09EC: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800F09F0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800F09F4: nop

    // 0x800F09F8: bc1fl       L_800F0A3C
    if (!c1cs) {
        // 0x800F09FC: add.s       $f2, $f0, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
            goto L_800F0A3C;
    }
    goto skip_7;
    // 0x800F09FC: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
    skip_7:
    // 0x800F0A00: jal         0x800EE7F8
    // 0x800F0A04: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x800F0A04: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_12:
    // 0x800F0A08: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800F0A0C: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800F0A10: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800F0A14: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800F0A18: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x800F0A1C: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x800F0A20: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F0A24: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800F0A28: jal         0x800EFA4C
    // 0x800F0A2C: nop

    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x800F0A2C: nop

    after_13:
    // 0x800F0A30: b           L_800F0A94
    // 0x800F0A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F0A94;
    // 0x800F0A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F0A38: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
L_800F0A3C:
    // 0x800F0A3C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800F0A40: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800F0A44: nop

    // 0x800F0A48: bc1fl       L_800F0A94
    if (!c1cs) {
        // 0x800F0A4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F0A94;
    }
    goto skip_8;
    // 0x800F0A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x800F0A50: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800F0A54: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800F0A58: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800F0A5C: nop

    // 0x800F0A60: bc1fl       L_800F0A94
    if (!c1cs) {
        // 0x800F0A64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F0A94;
    }
    goto skip_9;
    // 0x800F0A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x800F0A68: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800F0A6C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800F0A70: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800F0A74: jal         0x800EFA4C
    // 0x800F0A78: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x800F0A78: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    after_14:
    // 0x800F0A7C: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x800F0A80: jal         0x800EE7F8
    // 0x800F0A84: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x800F0A84: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_15:
    // 0x800F0A88: b           L_800F0A94
    // 0x800F0A8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F0A94;
    // 0x800F0A8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0A90:
    // 0x800F0A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0A94:
    // 0x800F0A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0A98: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800F0A9C: jr          $ra
    // 0x800F0AA0: nop

    return;
    // 0x800F0AA0: nop

;}
RECOMP_FUNC void chshockjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(688, 0X2F8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X2F8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X2F8));
;}
RECOMP_FUNC void _idtwinkle_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E18: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088E18);
    return;
    // 0x80088E1C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _gczoombox_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BA8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BA8);
    return;
    // 0x80087BAC: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801364: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080136C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801370: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x80801374: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x80801378: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080137C: jal         0x8010114C
    // 0x80801380: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80801380: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_0:
    // 0x80801384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080138C: jr          $ra
    // 0x80801390: nop

    return;
    // 0x80801390: nop

;}
RECOMP_FUNC void func_80802730_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802730: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802734: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80802738: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080273C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802740: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802744: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80802748: beq         $t6, $zero, L_80802758
    if (ctx->r14 == 0) {
        // 0x8080274C: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_80802758;
    }
    // 0x8080274C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80802750: b           L_8080275C
    // 0x80802754: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_8080275C;
    // 0x80802754: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80802758:
    // 0x80802758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080275C:
    // 0x8080275C: ori         $t7, $v0, 0xE
    ctx->r15 = ctx->r2 | 0XE;
    // 0x80802760: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80802764: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80802768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080276C: srl         $t8, $v0, 4
    ctx->r24 = S32(U32(ctx->r2) >> 4);
    // 0x80802770: beq         $t8, $zero, L_80802798
    if (ctx->r24 == 0) {
        // 0x80802774: nop
    
            goto L_80802798;
    }
    // 0x80802774: nop

    // 0x80802778: beq         $t8, $at, L_808028D8
    if (ctx->r24 == ctx->r1) {
        // 0x8080277C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808028D8;
    }
    // 0x8080277C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802780: beq         $t8, $at, L_80802900
    if (ctx->r24 == ctx->r1) {
        // 0x80802784: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802900;
    }
    // 0x80802784: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802788: beq         $t8, $at, L_80802908
    if (ctx->r24 == ctx->r1) {
        // 0x8080278C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802908;
    }
    // 0x8080278C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802790: b           L_8080293C
    // 0x80802794: nop

        goto L_8080293C;
    // 0x80802794: nop

L_80802798:
    // 0x80802798: beq         $a2, $zero, L_808027B4
    if (ctx->r6 == 0) {
        // 0x8080279C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_808027B4;
    }
    // 0x8080279C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808027A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808027A4: jal         0x8010C9B0
    // 0x808027A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8010C9B0(rdram, ctx);
        goto after_0;
    // 0x808027A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808027AC: b           L_808027B4
    // 0x808027B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808027B4;
    // 0x808027B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808027B4:
    // 0x808027B4: beq         $v1, $zero, L_808028D0
    if (ctx->r3 == 0) {
        // 0x808027B8: nop
    
            goto L_808028D0;
    }
    // 0x808027B8: nop

    // 0x808027BC: jal         0x800F54E4
    // 0x808027C0: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808027C0: nop

    after_1:
    // 0x808027C4: jal         0x800F6C5C
    // 0x808027C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x808027C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808027CC: beq         $v0, $zero, L_808028D0
    if (ctx->r2 == 0) {
        // 0x808027D0: nop
    
            goto L_808028D0;
    }
    // 0x808027D0: nop

    // 0x808027D4: jal         0x8010CD28
    // 0x808027D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_3;
    // 0x808027D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808027DC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808027E0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808027E4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808027E8: beq         $a0, $zero, L_80802894
    if (ctx->r4 == 0) {
        // 0x808027EC: swc1        $f4, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
            goto L_80802894;
    }
    // 0x808027EC: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x808027F0: jal         0x800DA298
    // 0x808027F4: nop

    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808027F4: nop

    after_4:
    // 0x808027F8: beq         $v0, $zero, L_80802848
    if (ctx->r2 == 0) {
        // 0x808027FC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802848;
    }
    // 0x808027FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802800: jal         0x80016B30
    // 0x80802804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_5;
    // 0x80802804: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80802808: beq         $v0, $zero, L_808028D0
    if (ctx->r2 == 0) {
        // 0x8080280C: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_808028D0;
    }
    // 0x8080280C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80802810: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80802814: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80802818: addiu       $t2, $zero, 0x6B
    ctx->r10 = ADD32(0, 0X6B);
    // 0x8080281C: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80802820: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80802824: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
    // 0x80802828: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080282C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80802830: jal         0x8008A208
    // 0x80802834: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80802834: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    after_6:
    // 0x80802838: jal         0x80802D74
    // 0x8080283C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D74_chfantasyathlete(rdram, ctx);
        goto after_7;
    // 0x8080283C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80802840: b           L_8080293C
    // 0x80802844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080293C;
    // 0x80802844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802848:
    // 0x80802848: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x8080284C: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80802850: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80802854: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80802858: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    // 0x8080285C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80802860: jal         0x800DA544
    // 0x80802864: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80802864: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x80802868: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080286C: addiu       $t7, $zero, 0x6B
    ctx->r15 = ADD32(0, 0X6B);
    // 0x80802870: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802874: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x80802878: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8080287C: jal         0x8008A208
    // 0x80802880: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80802880: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80802884: jal         0x80802D74
    // 0x80802888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D74_chfantasyathlete(rdram, ctx);
        goto after_10;
    // 0x80802888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080288C: b           L_8080293C
    // 0x80802890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080293C;
    // 0x80802890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802894:
    // 0x80802894: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80802898: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080289C: addiu       $t1, $zero, 0x6B
    ctx->r9 = ADD32(0, 0X6B);
    // 0x808028A0: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x808028A4: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x808028A8: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
    // 0x808028AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808028B0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808028B4: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x808028B8: jal         0x8008A208
    // 0x808028BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x808028BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x808028C0: jal         0x80802D74
    // 0x808028C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D74_chfantasyathlete(rdram, ctx);
        goto after_12;
    // 0x808028C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808028C8: b           L_8080293C
    // 0x808028CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080293C;
    // 0x808028CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808028D0:
    // 0x808028D0: b           L_8080293C
    // 0x808028D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080293C;
    // 0x808028D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808028D8:
    // 0x808028D8: jal         0x80802950
    // 0x808028DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_13;
    // 0x808028DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808028E0: beq         $v0, $zero, L_808028F8
    if (ctx->r2 == 0) {
        // 0x808028E4: nop
    
            goto L_808028F8;
    }
    // 0x808028E4: nop

    // 0x808028E8: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x808028EC: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x808028F0: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x808028F4: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
L_808028F8:
    // 0x808028F8: b           L_8080293C
    // 0x808028FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080293C;
    // 0x808028FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802900:
    // 0x80802900: b           L_8080293C
    // 0x80802904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080293C;
    // 0x80802904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802908:
    // 0x80802908: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080290C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802910: jal         0x80802950
    // 0x80802914: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_80802950_chfantasyathlete(rdram, ctx);
        goto after_14;
    // 0x80802914: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_14:
    // 0x80802918: beq         $v0, $zero, L_80802934
    if (ctx->r2 == 0) {
        // 0x8080291C: nop
    
            goto L_80802934;
    }
    // 0x8080291C: nop

    // 0x80802920: lbu         $t5, 0x79($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X79);
    // 0x80802924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802928: andi        $t6, $t5, 0xFF0F
    ctx->r14 = ctx->r13 & 0XFF0F;
    // 0x8080292C: b           L_8080293C
    // 0x80802930: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
        goto L_8080293C;
    // 0x80802930: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
L_80802934:
    // 0x80802934: b           L_8080293C
    // 0x80802938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080293C;
    // 0x80802938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080293C:
    // 0x8080293C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802940: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802948: jr          $ra
    // 0x8080294C: nop

    return;
    // 0x8080294C: nop

;}
RECOMP_FUNC void func_800F581C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F581C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5820: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5824: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5828: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F582C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F5830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5834: jal         0x8009650C
    // 0x800F5838: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009650C(rdram, ctx);
        goto after_0;
    // 0x800F5838: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F583C: beq         $v0, $zero, L_800F5854
    if (ctx->r2 == 0) {
        // 0x800F5840: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F5854;
    }
    // 0x800F5840: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5844: jal         0x80096434
    // 0x800F5848: nop

    func_80096434(rdram, ctx);
        goto after_1;
    // 0x800F5848: nop

    after_1:
    // 0x800F584C: b           L_800F5858
    // 0x800F5850: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800F5858;
    // 0x800F5850: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800F5854:
    // 0x800F5854: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800F5858:
    // 0x800F5858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F585C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F5860: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800F5864: jr          $ra
    // 0x800F5868: nop

    return;
    // 0x800F5868: nop

;}
RECOMP_FUNC void chboggykids_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $a0, $zero, 0x59D
    ctx->r4 = ADD32(0, 0X59D);
    // 0x80800010: jal         0x800DA564
    // 0x80800014: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x8080001C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800070;
    }
    // 0x8080001C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800020: jal         0x800DC128
    // 0x80800024: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800028: addiu       $a0, $zero, 0x59D
    ctx->r4 = ADD32(0, 0X59D);
    // 0x8080002C: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800030: jal         0x800DA7A8
    // 0x80800034: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80800038: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080003C: jal         0x800DC128
    // 0x80800040: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80800040: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800044: addiu       $a0, $zero, 0x59F
    ctx->r4 = ADD32(0, 0X59F);
    // 0x80800048: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x8080004C: jal         0x800DA7A8
    // 0x80800050: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_4;
    // 0x80800050: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800058: jal         0x800DC128
    // 0x8080005C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x8080005C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800060: addiu       $a0, $zero, 0x5A1
    ctx->r4 = ADD32(0, 0X5A1);
    // 0x80800064: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800068: jal         0x800DA7A8
    // 0x8080006C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_6;
    // 0x8080006C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
L_80800070:
    // 0x80800070: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800074: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(884, 0XE0) << 16);
    // 0x80800078: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080007C: lhu         $t6, 0x76($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X76);
    // 0x80800080: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800084: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800088: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8080008C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80800090: lw          $v0, 0x24($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X24);
    // 0x80800094: srl         $t0, $v0, 22
    ctx->r8 = S32(U32(ctx->r2) >> 22);
    // 0x80800098: addiu       $v0, $t0, -0x192
    ctx->r2 = ADD32(ctx->r8, -0X192);
    // 0x8080009C: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x808000A0: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x808000A4: jal         0x800DA564
    // 0x808000A8: lhu         $a0, 0xE0($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(884, 0XE0));
    func_800DA564(rdram, ctx);
        goto after_7;
    // 0x808000A8: lhu         $a0, 0xE0($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(884, 0XE0));
    after_7:
    // 0x808000AC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x808000B8: beql        $v0, $t3, L_808000CC
    if (ctx->r2 == ctx->r11) {
        // 0x808000BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808000CC;
    }
    goto skip_0;
    // 0x808000BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808000C0: b           L_808000CC
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000CC;
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000CC:
    // 0x808000CC: jr          $ra
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: nop

    // 0x808000D8: nop

    // 0x808000DC: nop

;}
RECOMP_FUNC void _chlavaentrancebridge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087078: syscall     503
    recomp_syscall_handler(rdram, ctx, 0x80087078);
    return;
    // 0x8008707C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800CEC_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800CF0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800CF4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80800CF8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800CFC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800D00: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800D04: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800D08: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800D0C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800D10: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800D14: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800D18: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800D1C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80800D20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800D24: neg.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = -ctx->f20.fl;
    // 0x80800D28: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_80800D2C:
    // 0x80800D2C: jal         0x800DC178
    // 0x80800D30: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800D30: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_0:
    // 0x80800D34: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80800D38: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800D3C: jal         0x800DC178
    // 0x80800D40: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800D40: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x80800D44: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80800D48: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800D4C: jal         0x800DC178
    // 0x80800D50: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800D50: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_2:
    // 0x80800D54: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80800D58: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80800D5C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800D60: jal         0x800EFA4C
    // 0x80800D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800D68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800D6C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80800D70: beq         $at, $zero, L_80800D94
    if (ctx->r1 == 0) {
        // 0x80800D74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800D94;
    }
    // 0x80800D74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800D78: mul.s       $f24, $f20, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80800D7C: jal         0x800EFC7C
    // 0x80800D80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_4;
    // 0x80800D80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800D84: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80800D88: nop

    // 0x80800D8C: bc1tl       L_80800D2C
    if (c1cs) {
        // 0x80800D90: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_80800D2C;
    }
    goto skip_0;
    // 0x80800D90: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_0:
L_80800D94:
    // 0x80800D94: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800D98: jal         0x800DC178
    // 0x80800D9C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800D9C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x80800DA0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800DA4: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x80800DA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800DAC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800DB0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DB4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800DB8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800DBC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800DC0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800DC4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800DC8: jr          $ra
    // 0x80800DCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800DCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80803340_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803340: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80803344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803348: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080334C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803350: jal         0x80807D48
    // 0x80803354: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80803354: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x80803358: jal         0x80808E78
    // 0x8080335C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808E78_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080335C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803364: jal         0x8080633C
    // 0x80803368: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80803368: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8080336C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803370: jal         0x80802D50
    // 0x80803374: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80802D50_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80803374: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x80803378: beq         $v0, $zero, L_808033AC
    if (ctx->r2 == 0) {
        // 0x8080337C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808033AC;
    }
    // 0x8080337C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803380: jal         0x80802670
    // 0x80803384: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80802670_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80803384: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80803388: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080338C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803390: lh          $a1, 0x0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X0);
    // 0x80803394: jal         0x80800424
    // 0x80803398: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80803398: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    after_5:
    // 0x8080339C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808033A0: addiu       $a1, $a1, 0x42D8
    ctx->r5 = ADD32(ctx->r5, 0X42D8);
    // 0x808033A4: jal         0x80084A70
    // 0x808033A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggsetup_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808033A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_808033AC:
    // 0x808033AC: lw          $v1, 0x188($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X188);
    // 0x808033B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808033B4: lbu         $a1, 0x218($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X218);
    // 0x808033B8: jal         0x80809540
    // 0x808033BC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80809540_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x808033BC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x808033C0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x808033C4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x808033C8: beq         $t7, $zero, L_808033F0
    if (ctx->r15 == 0) {
        // 0x808033CC: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_808033F0;
    }
    // 0x808033CC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808033D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808033D4: beql        $t7, $v0, L_80803418
    if (ctx->r15 == ctx->r2) {
        // 0x808033D8: lbu         $t9, 0x218($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X218);
            goto L_80803418;
    }
    goto skip_0;
    // 0x808033D8: lbu         $t9, 0x218($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X218);
    skip_0:
    // 0x808033DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x808033E0: beql        $t7, $v0, L_80803440
    if (ctx->r15 == ctx->r2) {
        // 0x808033E4: lbu         $t0, 0x218($v1)
        ctx->r8 = MEM_BU(ctx->r3, 0X218);
            goto L_80803440;
    }
    goto skip_1;
    // 0x808033E4: lbu         $t0, 0x218($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X218);
    skip_1:
    // 0x808033E8: b           L_8080345C
    // 0x808033EC: nop

        goto L_8080345C;
    // 0x808033EC: nop

L_808033F0:
    // 0x808033F0: lbu         $t8, 0x218($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X218);
    // 0x808033F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808033F8: beq         $t8, $zero, L_8080345C
    if (ctx->r24 == 0) {
        // 0x808033FC: nop
    
            goto L_8080345C;
    }
    // 0x808033FC: nop

    // 0x80803400: jal         0x80808D80
    // 0x80803404: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80808D80_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80803404: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_8:
    // 0x80803408: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8080340C: b           L_8080345C
    // 0x80803410: sb          $zero, 0x218($v1)
    MEM_B(0X218, ctx->r3) = 0;
        goto L_8080345C;
    // 0x80803410: sb          $zero, 0x218($v1)
    MEM_B(0X218, ctx->r3) = 0;
    // 0x80803414: lbu         $t9, 0x218($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X218);
L_80803418:
    // 0x80803418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080341C: beq         $v0, $t9, L_8080342C
    if (ctx->r2 == ctx->r25) {
        // 0x80803420: nop
    
            goto L_8080342C;
    }
    // 0x80803420: nop

    // 0x80803424: jal         0x80809684
    // 0x80803428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80809684_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80803428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_8080342C:
    // 0x8080342C: jal         0x80809740
    // 0x80803430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809740_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x80803430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80803434: b           L_8080345C
    // 0x80803438: nop

        goto L_8080345C;
    // 0x80803438: nop

    // 0x8080343C: lbu         $t0, 0x218($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X218);
L_80803440:
    // 0x80803440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803444: beq         $v0, $t0, L_80803454
    if (ctx->r2 == ctx->r8) {
        // 0x80803448: nop
    
            goto L_80803454;
    }
    // 0x80803448: nop

    // 0x8080344C: jal         0x80809684
    // 0x80803450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80809684_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80803450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
L_80803454:
    // 0x80803454: jal         0x80809740
    // 0x80803458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809740_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x80803458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_8080345C:
    // 0x8080345C: jal         0x80800228
    // 0x80803460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800228_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80803460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80803464: beql        $v0, $zero, L_8080347C
    if (ctx->r2 == 0) {
        // 0x80803468: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_8080347C;
    }
    goto skip_2;
    // 0x80803468: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x8080346C: jal         0x808094F4
    // 0x80803470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808094F4_bsfirstp(rdram, ctx);
        goto after_14;
    // 0x80803470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80803474: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80803478: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_8080347C:
    // 0x8080347C: beql        $a1, $zero, L_80803490
    if (ctx->r5 == 0) {
        // 0x80803480: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803490;
    }
    goto skip_3;
    // 0x80803480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80803484: jal         0x8009E5C8
    // 0x80803488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80803488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080348C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803490:
    // 0x80803490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803494: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80803498: jr          $ra
    // 0x8080349C: nop

    return;
    // 0x8080349C: nop

;}
RECOMP_FUNC void func_8008BAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BAC0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008BAC4: addiu       $t1, $t1, 0x6CC0
    ctx->r9 = ADD32(ctx->r9, 0X6CC0);
    // 0x8008BAC8: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8008BACC: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // 0x8008BAD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008BAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BAD8: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x8008BADC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008BAE0: beq         $at, $zero, L_8008BB04
    if (ctx->r1 == 0) {
        // 0x8008BAE4: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8008BB04;
    }
    // 0x8008BAE4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8008BAE8: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
L_8008BAEC:
    // 0x8008BAEC: beq         $t6, $zero, L_8008BB04
    if (ctx->r14 == 0) {
        // 0x8008BAF0: nop
    
            goto L_8008BB04;
    }
    // 0x8008BAF0: nop

    // 0x8008BAF4: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x8008BAF8: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x8008BAFC: bnel        $at, $zero, L_8008BAEC
    if (ctx->r1 != 0) {
        // 0x8008BB00: lh          $t6, 0x4($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X4);
            goto L_8008BAEC;
    }
    goto skip_0;
    // 0x8008BB00: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    skip_0:
L_8008BB04:
    // 0x8008BB04: bne         $a2, $v0, L_8008BB84
    if (ctx->r6 != ctx->r2) {
        // 0x8008BB08: subu        $v1, $v0, $a3
        ctx->r3 = SUB32(ctx->r2, ctx->r7);
            goto L_8008BB84;
    }
    // 0x8008BB08: subu        $v1, $v0, $a3
    ctx->r3 = SUB32(ctx->r2, ctx->r7);
    // 0x8008BB0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008BB10: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x8008BB14: mflo        $t7
    ctx->r15 = lo;
    // 0x8008BB18: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8008BB1C: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x8008BB20: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8008BB24: addiu       $a1, $t0, 0x3C
    ctx->r5 = ADD32(ctx->r8, 0X3C);
    // 0x8008BB28: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8008BB2C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008BB30: jal         0x8001B208
    // 0x8008BB34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x8008BB34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8008BB38: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8008BB3C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008BB40: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008BB44: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8008BB48: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8008BB4C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008BB50: addiu       $t1, $t1, 0x6CC0
    ctx->r9 = ADD32(ctx->r9, 0X6CC0);
    // 0x8008BB54: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008BB58: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8008BB5C: addiu       $t2, $t9, 0x3C
    ctx->r10 = ADD32(ctx->r25, 0X3C);
    // 0x8008BB60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008BB64: sw          $t2, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r10;
    // 0x8008BB68: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x8008BB6C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8008BB70: jal         0x8008BBC0
    // 0x8008BB74: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    func_8008BBC0(rdram, ctx);
        goto after_1;
    // 0x8008BB74: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    after_1:
    // 0x8008BB78: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008BB7C: addiu       $t1, $t1, 0x6CC0
    ctx->r9 = ADD32(ctx->r9, 0X6CC0);
    // 0x8008BB80: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_8008BB84:
    // 0x8008BB84: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008BB88: sh          $t3, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r11;
    // 0x8008BB8C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8008BB90: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008BB94: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008BB98: subu        $t5, $a2, $t4
    ctx->r13 = SUB32(ctx->r6, ctx->r12);
    // 0x8008BB9C: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x8008BBA0: mflo        $t6
    ctx->r14 = lo;
    // 0x8008BBA4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008BBA8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8008BBAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BBB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008BBB4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8008BBB8: jr          $ra
    // 0x8008BBBC: nop

    return;
    // 0x8008BBBC: nop

;}
RECOMP_FUNC void func_800E0E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0E94: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800E0E98: sw          $s0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r16;
    // 0x800E0E9C: sdc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X0, ctx->r29);
    // 0x800E0EA0: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x800E0EA4: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x800E0EA8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E0EAC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E0EB0: blez        $v1, L_800E0FD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800E0EB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E0FD8;
    }
    // 0x800E0EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E0EB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E0EBC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800E0EC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800E0EC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E0EC8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800E0ECC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_800E0ED0:
    // 0x800E0ED0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800E0ED4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E0ED8: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x800E0EDC: lbu         $t8, 0x10($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X10);
    // 0x800E0EE0: bnel        $a3, $t8, L_800E0FD0
    if (ctx->r7 != ctx->r24) {
        // 0x800E0EE4: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E0FD0;
    }
    goto skip_0;
    // 0x800E0EE4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x800E0EE8: lbu         $t9, 0x11($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X11);
    // 0x800E0EEC: bnel        $t0, $t9, L_800E0FD0
    if (ctx->r8 != ctx->r25) {
        // 0x800E0EF0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E0FD0;
    }
    goto skip_1;
    // 0x800E0EF0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
    // 0x800E0EF4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800E0EF8: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800E0EFC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800E0F00: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800E0F04: nop

    // 0x800E0F08: bc1fl       L_800E0F68
    if (!c1cs) {
        // 0x800E0F0C: c.lt.s      $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
            goto L_800E0F68;
    }
    goto skip_2;
    // 0x800E0F0C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    skip_2:
    // 0x800E0F10: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E0F14: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800E0F18: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x800E0F1C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E0F20: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800E0F24: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800E0F28: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E0F2C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800E0F30: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800E0F34: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800E0F38: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800E0F3C: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E0F40: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800E0F44: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800E0F48: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800E0F4C: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800E0F50: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800E0F54: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800E0F58: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800E0F5C: b           L_800E0FCC
    // 0x800E0F60: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
        goto L_800E0FCC;
    // 0x800E0F60: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x800E0F64: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
L_800E0F68:
    // 0x800E0F68: nop

    // 0x800E0F6C: bc1fl       L_800E0FD0
    if (!c1cs) {
        // 0x800E0F70: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E0FD0;
    }
    goto skip_3;
    // 0x800E0F70: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_3:
    // 0x800E0F74: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800E0F78: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E0F7C: sub.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800E0F80: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800E0F84: add.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x800E0F88: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E0F8C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800E0F90: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800E0F94: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800E0F98: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800E0F9C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800E0FA0: add.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x800E0FA4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800E0FA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E0FAC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800E0FB0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800E0FB4: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800E0FB8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E0FBC: add.s       $f6, $f20, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x800E0FC0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800E0FC4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800E0FC8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
L_800E0FCC:
    // 0x800E0FCC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800E0FD0:
    // 0x800E0FD0: bne         $at, $zero, L_800E0ED0
    if (ctx->r1 != 0) {
        // 0x800E0FD4: addiu       $a2, $a2, 0x14
        ctx->r6 = ADD32(ctx->r6, 0X14);
            goto L_800E0ED0;
    }
    // 0x800E0FD4: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
L_800E0FD8:
    // 0x800E0FD8: ldc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X0);
    // 0x800E0FDC: lw          $s0, 0xC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC);
    // 0x800E0FE0: jr          $ra
    // 0x800E0FE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800E0FE4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_808000B8_cheggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000D4: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808000E0: beq         $t6, $at, L_808000F8
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F8;
    }
    // 0x808000E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E8: beq         $t6, $at, L_80800158
    if (ctx->r14 == ctx->r1) {
        // 0x808000EC: nop
    
            goto L_80800158;
    }
    // 0x808000EC: nop

    // 0x808000F0: b           L_80800200
    // 0x808000F4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800200;
    // 0x808000F4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808000F8:
    // 0x808000F8: jal         0x8008A3B8
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800100: bnel        $v0, $zero, L_80800200
    if (ctx->r2 != 0) {
        // 0x80800104: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800200;
    }
    goto skip_0;
    // 0x80800104: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800108: jal         0x800EEEA8
    // 0x8080010C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_2;
    // 0x8080010C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x80800110: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x80800114: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800128;
    }
    // 0x80800114: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800118: lbu         $t9, 0x39($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X39);
    // 0x8080011C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80800120: b           L_808001FC
    // 0x80800124: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
        goto L_808001FC;
    // 0x80800124: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
L_80800128:
    // 0x80800128: jal         0x80800000
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cheggfire(rdram, ctx);
        goto after_3;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800130: jal         0x8008A3F8
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800138: jal         0x8008A3E8
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800140: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x80800144: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_808001FC;
    }
    // 0x80800144: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800148: lbu         $t3, 0x39($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X39);
    // 0x8080014C: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x80800150: b           L_808001FC
    // 0x80800154: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
        goto L_808001FC;
    // 0x80800154: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
L_80800158:
    // 0x80800158: jal         0x8008A3B8
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800160: bne         $v0, $zero, L_808001FC
    if (ctx->r2 != 0) {
        // 0x80800164: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_808001FC;
    }
    // 0x80800164: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800168: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080016C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800170: lwc1        $f12, 0x30($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80800174: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800178: lui         $a2, 0x3E09
    ctx->r6 = S32(0X3E09 << 16);
    // 0x8080017C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800180: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800184: ori         $a2, $a2, 0x374C
    ctx->r6 = ctx->r6 | 0X374C;
    // 0x80800188: jal         0x800F10B4
    // 0x8080018C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x8080018C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80800190: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800194: jal         0x8008A450
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080019C: beq         $v0, $zero, L_808001AC
    if (ctx->r2 == 0) {
        // 0x808001A0: nop
    
            goto L_808001AC;
    }
    // 0x808001A0: nop

    // 0x808001A4: jal         0x8008A430
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_23(rdram, ctx);
        goto after_9;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808001AC:
    // 0x808001AC: jal         0x8008A3E0
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001B4: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001B8: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808001CC;
    }
    // 0x808001B8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808001BC: lbu         $t9, 0x39($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X39);
    // 0x808001C0: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x808001C4: b           L_808001FC
    // 0x808001C8: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
        goto L_808001FC;
    // 0x808001C8: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
L_808001CC:
    // 0x808001CC: jal         0x8008A3D8
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001D4: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001D8: nop
    
            goto L_808001EC;
    }
    // 0x808001D8: nop

    // 0x808001DC: jal         0x8008A348
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001E4: b           L_80800200
    // 0x808001E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800200;
    // 0x808001E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808001EC:
    // 0x808001EC: jal         0x80800000
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cheggfire(rdram, ctx);
        goto after_13;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001F4: jal         0x8008A3F8
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_14;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808001FC:
    // 0x808001FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800200:
    // 0x80800200: lb          $t3, 0x39($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X39);
    // 0x80800204: bgezl       $t3, L_80800218
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800208: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800218;
    }
    goto skip_1;
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080020C: jal         0x8008A390
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800218:
    // 0x80800218: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080021C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void _baflamethrower_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BC0: syscall     131
    recomp_syscall_handler(rdram, ctx, 0x80084BC0);
    return;
    // 0x80084BC4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800E6CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6CA8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800E6CAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E6CB0: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800E6CB4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E6CB8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800E6CBC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800E6CC0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E6CC4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800E6CC8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800E6CCC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E6CD0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800E6CD4: jal         0x800E6B7C
    // 0x800E6CD8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800E6B7C(rdram, ctx);
        goto after_0;
    // 0x800E6CD8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x800E6CDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E6CE0: beq         $v0, $at, L_800E6D14
    if (ctx->r2 == ctx->r1) {
        // 0x800E6CE4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800E6D14;
    }
    // 0x800E6CE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E6CE8: beq         $v0, $zero, L_800E6D04
    if (ctx->r2 == 0) {
        // 0x800E6CEC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800E6D04;
    }
    // 0x800E6CEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E6CF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E6CF4: beql        $v0, $at, L_800E6D28
    if (ctx->r2 == ctx->r1) {
        // 0x800E6CF8: trunc.w.s   $f4, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
            goto L_800E6D28;
    }
    goto skip_0;
    // 0x800E6CF8: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
    skip_0:
    // 0x800E6CFC: b           L_800E6D98
    // 0x800E6D00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800E6D98;
    // 0x800E6D00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800E6D04:
    // 0x800E6D04: jal         0x800E6A10
    // 0x800E6D08: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800E6A10(rdram, ctx);
        goto after_1;
    // 0x800E6D08: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x800E6D0C: b           L_800E6D98
    // 0x800E6D10: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800E6D98;
    // 0x800E6D10: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800E6D14:
    // 0x800E6D14: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800E6D18: jal         0x800E6A10
    // 0x800E6D1C: addiu       $a1, $a1, 0x5DD0
    ctx->r5 = ADD32(ctx->r5, 0X5DD0);
    func_800E6A10(rdram, ctx);
        goto after_2;
    // 0x800E6D1C: addiu       $a1, $a1, 0x5DD0
    ctx->r5 = ADD32(ctx->r5, 0X5DD0);
    after_2:
    // 0x800E6D20: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x800E6D24: trunc.w.s   $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = TRUNC_W_S(ctx->f20.fl);
L_800E6D28:
    // 0x800E6D28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E6D2C: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x800E6D30: jal         0x800E6DB4
    // 0x800E6D34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_3;
    // 0x800E6D34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800E6D38: beq         $s1, $zero, L_800E6D94
    if (ctx->r17 == 0) {
        // 0x800E6D3C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800E6D94;
    }
    // 0x800E6D3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E6D40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800E6D44: jal         0x800E6A10
    // 0x800E6D48: addiu       $a1, $a1, 0x5DD4
    ctx->r5 = ADD32(ctx->r5, 0X5DD4);
    func_800E6A10(rdram, ctx);
        goto after_4;
    // 0x800E6D48: addiu       $a1, $a1, 0x5DD4
    ctx->r5 = ADD32(ctx->r5, 0X5DD4);
    after_4:
    // 0x800E6D4C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800E6D50: beq         $s1, $zero, L_800E6D94
    if (ctx->r17 == 0) {
        // 0x800E6D54: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800E6D94;
    }
    // 0x800E6D54: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800E6D58: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800E6D5C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800E6D60: nop

L_800E6D64:
    // 0x800E6D64: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x800E6D68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E6D6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E6D70: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800E6D74: mul.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800E6D78: trunc.w.s   $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800E6D7C: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800E6D80: jal         0x800E6DB4
    // 0x800E6D84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_5;
    // 0x800E6D84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800E6D88: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800E6D8C: bne         $s1, $zero, L_800E6D64
    if (ctx->r17 != 0) {
        // 0x800E6D90: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800E6D64;
    }
    // 0x800E6D90: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800E6D94:
    // 0x800E6D94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800E6D98:
    // 0x800E6D98: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E6D9C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800E6DA0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E6DA4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E6DA8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E6DAC: jr          $ra
    // 0x800E6DB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800E6DB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80012214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012214: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012218: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001221C: jal         0x8002DB00
    // 0x80012220: nop

    osGetMemSize_recomp(rdram, ctx);
        goto after_0;
    // 0x80012220: nop

    after_0:
    // 0x80012224: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012228: jal         0x8001DDF0
    // 0x8001222C: sw          $v0, 0x59D0($at)
    MEM_W(0X59D0, ctx->r1) = ctx->r2;
    func_8001DDF0(rdram, ctx);
        goto after_1;
    // 0x8001222C: sw          $v0, 0x59D0($at)
    MEM_W(0X59D0, ctx->r1) = ctx->r2;
    after_1:
    // 0x80012230: jal         0x8001E840
    // 0x80012234: nop

    init_crc_check(rdram, ctx);
        goto after_2;
    // 0x80012234: nop

    after_2:
    // 0x80012238: jal         0x80014FE8
    // 0x8001223C: nop

    func_80014FE8(rdram, ctx);
        goto after_3;
    // 0x8001223C: nop

    after_3:
    // 0x80012240: jal         0x8001E7E8
    // 0x80012244: nop

    func_8001E7E8(rdram, ctx);
        goto after_4;
    // 0x80012244: nop

    after_4:
    // 0x80012248: jal         0x8001C1C0
    // 0x8001224C: nop

    func_8001C1C0(rdram, ctx);
        goto after_5;
    // 0x8001224C: nop

    after_5:
    // 0x80012250: lui         $t6, 0x1F0
    ctx->r14 = S32(0X1F0 << 16);
    // 0x80012254: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80012258: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8001225C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80012260: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80012264: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80012268: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8001226C: addiu       $t2, $t2, 0x7390
    ctx->r10 = ADD32(ctx->r10, 0X7390);
    // 0x80012270: addiu       $t1, $t1, 0x6730
    ctx->r9 = ADD32(ctx->r9, 0X6730);
    // 0x80012274: addiu       $t0, $t0, 0x6730
    ctx->r8 = ADD32(ctx->r8, 0X6730);
    // 0x80012278: addiu       $t9, $t9, 0x7C60
    ctx->r25 = ADD32(ctx->r25, 0X7C60);
    // 0x8001227C: addiu       $t8, $t8, 0x7C60
    ctx->r24 = ADD32(ctx->r24, 0X7C60);
    // 0x80012280: addiu       $t7, $t7, 0x15C0
    ctx->r15 = ADD32(ctx->r15, 0X15C0);
    // 0x80012284: addiu       $t6, $t6, 0x20
    ctx->r14 = ADD32(ctx->r14, 0X20);
    // 0x80012288: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001228C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80012290: lui         $a3, 0x1E6
    ctx->r7 = S32(0X1E6 << 16);
    // 0x80012294: addiu       $a3, $a3, -0x5150
    ctx->r7 = ADD32(ctx->r7, -0X5150);
    // 0x80012298: addiu       $a2, $a2, 0x7390
    ctx->r6 = ADD32(ctx->r6, 0X7390);
    // 0x8001229C: addiu       $a1, $a1, 0x15C0
    ctx->r5 = ADD32(ctx->r5, 0X15C0);
    // 0x800122A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800122A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800122A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800122AC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800122B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800122B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800122B8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800122BC: jal         0x80019EC0
    // 0x800122C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80019EC0(rdram, ctx);
        goto after_6;
    // 0x800122C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800122C4: jal         0x8001A8B4
    // 0x800122C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    heap_setup(rdram, ctx);
        goto after_7;
    // 0x800122C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x800122CC: jal         0x80014E6C
    // 0x800122D0: nop

    func_80014E6C(rdram, ctx);
        goto after_8;
    // 0x800122D0: nop

    after_8:
    // 0x800122D4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800122D8: addiu       $v0, $v0, 0x3388
    ctx->r2 = ADD32(ctx->r2, 0X3388);
    // 0x800122DC: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x800122E0: lui         $t4, 0x506
    ctx->r12 = S32(0X506 << 16);
    // 0x800122E4: ori         $t3, $t3, 0x304
    ctx->r11 = ctx->r11 | 0X304;
    // 0x800122E8: ori         $t4, $t4, 0x708
    ctx->r12 = ctx->r12 | 0X708;
    // 0x800122EC: sw          $t3, 0x400($v0)
    MEM_W(0X400, ctx->r2) = ctx->r11;
    // 0x800122F0: sw          $t4, 0x404($v0)
    MEM_W(0X404, ctx->r2) = ctx->r12;
    // 0x800122F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800122F8: sw          $t3, 0x59D8($at)
    MEM_W(0X59D8, ctx->r1) = ctx->r11;
    // 0x800122FC: jal         0x801168F0
    // 0x80012300: sw          $t4, 0x59DC($at)
    MEM_W(0X59DC, ctx->r1) = ctx->r12;
    func_801168F0(rdram, ctx);
        goto after_9;
    // 0x80012300: sw          $t4, 0x59DC($at)
    MEM_W(0X59DC, ctx->r1) = ctx->r12;
    after_9:
    // 0x80012304: jal         0x800815CC
    // 0x80012308: nop

    func_800815CC(rdram, ctx);
        goto after_10;
    // 0x80012308: nop

    after_10:
    // 0x8001230C: jal         0x8001A080
    // 0x80012310: nop

    func_8001A080(rdram, ctx);
        goto after_11;
    // 0x80012310: nop

    after_11:
    // 0x80012314: jal         0x8001A2D0
    // 0x80012318: nop

    func_8001A2D0(rdram, ctx);
        goto after_12;
    // 0x80012318: nop

    after_12:
    // 0x8001231C: jal         0x800121D0
    // 0x80012320: nop

    func_800121D0(rdram, ctx);
        goto after_13;
    // 0x80012320: nop

    after_13:
    // 0x80012324: jal         0x80016734
    // 0x80012328: nop

    func_80016734(rdram, ctx);
        goto after_14;
    // 0x80012328: nop

    after_14:
    // 0x8001232C: jal         0x800184E8
    // 0x80012330: nop

    func_800184E8(rdram, ctx);
        goto after_15;
    // 0x80012330: nop

    after_15:
    // 0x80012334: jal         0x800125B0
    // 0x80012338: nop

    func_800125B0(rdram, ctx);
        goto after_16;
    // 0x80012338: nop

    after_16:
    // 0x8001233C: jal         0x8001A3A0
    // 0x80012340: nop

    func_8001A3A0(rdram, ctx);
        goto after_17;
    // 0x80012340: nop

    after_17:
    // 0x80012344: jal         0x800D66AC
    // 0x80012348: nop

    func_800D66AC(rdram, ctx);
        goto after_18;
    // 0x80012348: nop

    after_18:
    // 0x8001234C: jal         0x800D5D70
    // 0x80012350: nop

    func_800D5D70(rdram, ctx);
        goto after_19;
    // 0x80012350: nop

    after_19:
    // 0x80012354: jal         0x800E692C
    // 0x80012358: nop

    func_800E692C(rdram, ctx);
        goto after_20;
    // 0x80012358: nop

    after_20:
    // 0x8001235C: jal         0x80088310
    // 0x80012360: nop

    _gcstatusDll_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x80012360: nop

    after_21:
    // 0x80012364: jal         0x800C929C
    // 0x80012368: nop

    func_800C929C(rdram, ctx);
        goto after_22;
    // 0x80012368: nop

    after_22:
    // 0x8001236C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012370: sw          $zero, 0x3380($at)
    MEM_W(0X3380, ctx->r1) = 0;
    // 0x80012374: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012378: jal         0x800A5BE0
    // 0x8001237C: sw          $zero, 0x59C8($at)
    MEM_W(0X59C8, ctx->r1) = 0;
    func_800A5BE0(rdram, ctx);
        goto after_23;
    // 0x8001237C: sw          $zero, 0x59C8($at)
    MEM_W(0X59C8, ctx->r1) = 0;
    after_23:
    // 0x80012380: jal         0x800D740C
    // 0x80012384: nop

    func_800D740C(rdram, ctx);
        goto after_24;
    // 0x80012384: nop

    after_24:
    // 0x80012388: jal         0x80087890
    // 0x8001238C: nop

    _cosection_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x8001238C: nop

    after_25:
    // 0x80012390: jal         0x8001253C
    // 0x80012394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001253C(rdram, ctx);
        goto after_26;
    // 0x80012394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x80012398: jal         0x8001209C
    // 0x8001239C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001209C(rdram, ctx);
        goto after_27;
    // 0x8001239C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_27:
    // 0x800123A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800123A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800123A8: jr          $ra
    // 0x800123AC: nop

    return;
    // 0x800123AC: nop

;}
RECOMP_FUNC void _idflasha_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D70: syscall     738
    recomp_syscall_handler(rdram, ctx, 0x80088D70);
    return;
    // 0x80088D74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800EC428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC42C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC430: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x800EC434: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EC438: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800EC43C: beql        $t7, $zero, L_800EC458
    if (ctx->r15 == 0) {
        // 0x800EC440: lhu         $a0, 0x14($a1)
        ctx->r4 = MEM_HU(ctx->r5, 0X14);
            goto L_800EC458;
    }
    goto skip_0;
    // 0x800EC440: lhu         $a0, 0x14($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X14);
    skip_0:
    // 0x800EC444: jal         0x801039E4
    // 0x800EC448: nop

    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x800EC448: nop

    after_0:
    // 0x800EC44C: b           L_800EC480
    // 0x800EC450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EC480;
    // 0x800EC450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC454: lhu         $a0, 0x14($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X14);
L_800EC458:
    // 0x800EC458: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800EC45C: beq         $a0, $zero, L_800EC46C
    if (ctx->r4 == 0) {
        // 0x800EC460: nop
    
            goto L_800EC46C;
    }
    // 0x800EC460: nop

    // 0x800EC464: bne         $a0, $at, L_800EC474
    if (ctx->r4 != ctx->r1) {
        // 0x800EC468: nop
    
            goto L_800EC474;
    }
    // 0x800EC468: nop

L_800EC46C:
    // 0x800EC46C: b           L_800EC47C
    // 0x800EC470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EC47C;
    // 0x800EC470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EC474:
    // 0x800EC474: jal         0x800D674C
    // 0x800EC478: nop

    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x800EC478: nop

    after_1:
L_800EC47C:
    // 0x800EC47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EC480:
    // 0x800EC480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC484: jr          $ra
    // 0x800EC488: nop

    return;
    // 0x800EC488: nop

;}
RECOMP_FUNC void _glsavegame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088518: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088518);
    return;
    // 0x8008851C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chidgoldhorde_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800094: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800098: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8080009C: jal         0x80106790
    // 0x808000A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808000A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808000A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A8: jal         0x80100094
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000B0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x808000B4: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x808000B8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000BC: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x808000C0: bne         $t6, $v1, L_8080014C
    if (ctx->r14 != ctx->r3) {
        // 0x808000C4: sh          $t7, 0x4($v0)
        MEM_H(0X4, ctx->r2) = ctx->r15;
            goto L_8080014C;
    }
    // 0x808000C4: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x808000C8: jal         0x800EE88C
    // 0x808000CC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808000CC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x808000D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(736, 0X1E4) << 16);
    // 0x808000D4: lwc1        $f0, 0x1E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X1E4));
    // 0x808000D8: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808000DC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808000E0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000E4: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x808000E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000EC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808000F0: nop

    // 0x808000F4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808000F8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808000FC: beql        $v0, $a0, L_80800130
    if (ctx->r2 == ctx->r4) {
        // 0x80800100: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800130;
    }
    goto skip_0;
    // 0x80800100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80800104: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
L_80800108:
    // 0x80800108: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8080010C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800114: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800118: nop

    // 0x8080011C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800120: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800124: bnel        $v0, $a0, L_80800108
    if (ctx->r2 != ctx->r4) {
        // 0x80800128: swc1        $f18, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
            goto L_80800108;
    }
    goto skip_1;
    // 0x80800128: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    skip_1:
    // 0x8080012C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800130:
    // 0x80800130: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80800134: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800138: jal         0x800EF04C
    // 0x8080013C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x8080013C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800140: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800144: jal         0x800888C8
    // 0x80800148: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800148: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
L_8080014C:
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_800B7ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7ADC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7AE0: jr          $ra
    // 0x800B7AE4: sb          $a0, -0x7E71($at)
    MEM_B(-0X7E71, ctx->r1) = ctx->r4;
    return;
    // 0x800B7AE4: sb          $a0, -0x7E71($at)
    MEM_B(-0X7E71, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800180_chbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080018C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1664, 0X364) << 16);
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800194: jal         0x80101E4C
    // 0x80800198: addiu       $a1, $a1, 0x364
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1664, 0X364));
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x80800198: addiu       $a1, $a1, 0x364
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1664, 0X364));
    after_0:
    // 0x8080019C: beql        $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x808001A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800258;
    }
    goto skip_0;
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001A4: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808001A8: bne         $a0, $zero, L_808001F8
    if (ctx->r4 != 0) {
        // 0x808001AC: nop
    
            goto L_808001F8;
    }
    // 0x808001AC: nop

    // 0x808001B0: jal         0x800C2E04
    // 0x808001B4: nop

    func_800C2E04(rdram, ctx);
        goto after_1;
    // 0x808001B4: nop

    after_1:
    // 0x808001B8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808001BC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808001C0: jal         0x800C301C
    // 0x808001C4: addiu       $a1, $zero, 0x447
    ctx->r5 = ADD32(0, 0X447);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x808001C4: addiu       $a1, $zero, 0x447
    ctx->r5 = ADD32(0, 0X447);
    after_2:
    // 0x808001C8: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808001CC: jal         0x800C3058
    // 0x808001D0: addiu       $a1, $zero, 0x2EE0
    ctx->r5 = ADD32(0, 0X2EE0);
    func_800C3058(rdram, ctx);
        goto after_3;
    // 0x808001D0: addiu       $a1, $zero, 0x2EE0
    ctx->r5 = ADD32(0, 0X2EE0);
    after_3:
    // 0x808001D4: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808001D8: jal         0x800C35E8
    // 0x808001DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C35E8(rdram, ctx);
        goto after_4;
    // 0x808001DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808001E0: lui         $a2, 0x44BB
    ctx->r6 = S32(0X44BB << 16);
    // 0x808001E4: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808001E8: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808001EC: jal         0x800C3584
    // 0x808001F0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_800C3584(rdram, ctx);
        goto after_5;
    // 0x808001F0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_5:
    // 0x808001F4: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_808001F8:
    // 0x808001F8: beql        $a0, $zero, L_80800258
    if (ctx->r4 == 0) {
        // 0x808001FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800258;
    }
    goto skip_1;
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800200: jal         0x800C3CE8
    // 0x80800204: nop

    func_800C3CE8(rdram, ctx);
        goto after_6;
    // 0x80800204: nop

    after_6:
    // 0x80800208: jal         0x80101F24
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_7;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800210: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800218: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080021C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800220: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800224: jal         0x800C31DC
    // 0x80800228: nop

    func_800C31DC(rdram, ctx);
        goto after_8;
    // 0x80800228: nop

    after_8:
    // 0x8080022C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800230: jal         0x800C330C
    // 0x80800234: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_9;
    // 0x80800234: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800238: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x8080023C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800240: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80800244: jal         0x80089D08
    // 0x80800248: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _subaddieaudioquick_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800248: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_10:
    // 0x8080024C: jal         0x800C3BDC
    // 0x80800250: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_11;
    // 0x80800250: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_11:
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800258:
    // 0x80800258: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080025C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800260: jr          $ra
    // 0x80800264: nop

    return;
    // 0x80800264: nop

;}
RECOMP_FUNC void func_80106630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106630: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106634: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    // 0x80106638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010663C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106640: beql        $a0, $zero, L_8010665C
    if (ctx->r4 == 0) {
        // 0x80106644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010665C;
    }
    goto skip_0;
    // 0x80106644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106648: jal         0x800B2F58
    // 0x8010664C: nop

    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x8010664C: nop

    after_0:
    // 0x80106650: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106654: sw          $v0, 0x6EE0($at)
    MEM_W(0X6EE0, ctx->r1) = ctx->r2;
    // 0x80106658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010665C:
    // 0x8010665C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106660: jr          $ra
    // 0x80106664: nop

    return;
    // 0x80106664: nop

;}
RECOMP_FUNC void chfactorylight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1100, 0XB90) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1100, 0XB90));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1100, 0XB90));
;}
RECOMP_FUNC void chtrashcompactor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1128, 0X918) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x918
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X918));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x918
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X918));
;}
RECOMP_FUNC void chdinofamilymother_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801264: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2420, 0X1474) << 16);
    // 0x80801268: jr          $ra
    // 0x8080126C: addiu       $v0, $v0, 0x1474
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2420, 0X1474));
    return;
    // 0x8080126C: addiu       $v0, $v0, 0x1474
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2420, 0X1474));
;}
RECOMP_FUNC void func_800A3F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3F1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A3F20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A3F24: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800A3F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A3F2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A3F30: lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X6);
    // 0x800A3F34: beql        $a1, $v1, L_800A4020
    if (ctx->r5 == ctx->r3) {
        // 0x800A3F38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A4020;
    }
    goto skip_0;
    // 0x800A3F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A3F3C: beq         $v1, $at, L_800A3F58
    if (ctx->r3 == ctx->r1) {
        // 0x800A3F40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3F58;
    }
    // 0x800A3F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3F44: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A3F48: beq         $v1, $at, L_800A3F68
    if (ctx->r3 == ctx->r1) {
        // 0x800A3F4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3F68;
    }
    // 0x800A3F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3F50: b           L_800A3F80
    // 0x800A3F54: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_800A3F80;
    // 0x800A3F54: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_800A3F58:
    // 0x800A3F58: jal         0x80090C28
    // 0x800A3F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80090C28(rdram, ctx);
        goto after_0;
    // 0x800A3F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800A3F60: b           L_800A3F80
    // 0x800A3F64: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
        goto L_800A3F80;
    // 0x800A3F64: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_800A3F68:
    // 0x800A3F68: lbu         $a1, 0x3A($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3A);
    // 0x800A3F6C: jal         0x800A3D78
    // 0x800A3F70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A3D78(rdram, ctx);
        goto after_1;
    // 0x800A3F70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800A3F74: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x800A3F78: sb          $zero, 0x3A($t7)
    MEM_B(0X3A, ctx->r15) = 0;
    // 0x800A3F7C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_800A3F80:
    // 0x800A3F80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3F88: beq         $t8, $at, L_800A3FB8
    if (ctx->r24 == ctx->r1) {
        // 0x800A3F8C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800A3FB8;
    }
    // 0x800A3F8C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800A3F90: beq         $t8, $at, L_800A4008
    if (ctx->r24 == ctx->r1) {
        // 0x800A3F94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A4008;
    }
    // 0x800A3F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3F98: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A3F9C: beq         $t8, $at, L_800A3FC8
    if (ctx->r24 == ctx->r1) {
        // 0x800A3FA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3FC8;
    }
    // 0x800A3FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3FA4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A3FA8: beq         $t8, $at, L_800A3FF8
    if (ctx->r24 == ctx->r1) {
        // 0x800A3FAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3FF8;
    }
    // 0x800A3FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3FB0: b           L_800A4014
    // 0x800A3FB4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4014;
    // 0x800A3FB4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A3FB8:
    // 0x800A3FB8: jal         0x800A3B78
    // 0x800A3FBC: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_800A3B78(rdram, ctx);
        goto after_2;
    // 0x800A3FBC: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_2:
    // 0x800A3FC0: b           L_800A4014
    // 0x800A3FC4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4014;
    // 0x800A3FC4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A3FC8:
    // 0x800A3FC8: jal         0x800A3B78
    // 0x800A3FCC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_800A3B78(rdram, ctx);
        goto after_3;
    // 0x800A3FCC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_3:
    // 0x800A3FD0: jal         0x800A3DAC
    // 0x800A3FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3DAC(rdram, ctx);
        goto after_4;
    // 0x800A3FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A3FD8: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x800A3FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3FE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800A3FE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A3FE8: jal         0x800A3D78
    // 0x800A3FEC: sb          $v0, 0x3A($t9)
    MEM_B(0X3A, ctx->r25) = ctx->r2;
    func_800A3D78(rdram, ctx);
        goto after_5;
    // 0x800A3FEC: sb          $v0, 0x3A($t9)
    MEM_B(0X3A, ctx->r25) = ctx->r2;
    after_5:
    // 0x800A3FF0: b           L_800A4014
    // 0x800A3FF4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4014;
    // 0x800A3FF4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A3FF8:
    // 0x800A3FF8: jal         0x800A3B78
    // 0x800A3FFC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_800A3B78(rdram, ctx);
        goto after_6;
    // 0x800A3FFC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_6:
    // 0x800A4000: b           L_800A4014
    // 0x800A4004: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
        goto L_800A4014;
    // 0x800A4004: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4008:
    // 0x800A4008: jal         0x800A3B78
    // 0x800A400C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3B78(rdram, ctx);
        goto after_7;
    // 0x800A400C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x800A4010: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_800A4014:
    // 0x800A4014: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800A4018: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800A401C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A4020:
    // 0x800A4020: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A4028: jr          $ra
    // 0x800A402C: nop

    return;
    // 0x800A402C: nop

;}
RECOMP_FUNC void func_808006E0_chfantasyonion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E8: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x808006EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808006F0: beq         $v0, $zero, L_80800708
    if (ctx->r2 == 0) {
        // 0x808006F4: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80800708;
    }
    // 0x808006F4: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808006F8: jal         0x800E87E0
    // 0x808006FC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800E87E0(rdram, ctx);
        goto after_0;
    // 0x808006FC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800700: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800704: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
L_80800708:
    // 0x80800708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080070C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C28: jal         0x80800BE0
    // 0x80800C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800BE0_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C30: bne         $v0, $zero, L_80800C40
    if (ctx->r2 != 0) {
        // 0x80800C34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800C40;
    }
    // 0x80800C34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800C38: b           L_80800C50
    // 0x80800C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C50;
    // 0x80800C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C40:
    // 0x80800C40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800C44: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C4C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800C50:
    // 0x80800C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C58: jr          $ra
    // 0x80800C5C: nop

    return;
    // 0x80800C5C: nop

;}
RECOMP_FUNC void set_crc_entry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E868: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001E86C: addiu       $v1, $v1, -0x1650
    ctx->r3 = ADD32(ctx->r3, -0X1650);
    // 0x8001E870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E874: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8001E878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E87C: beq         $a0, $at, L_8001E8D4
    if (ctx->r4 == ctx->r1) {
        // 0x8001E880: sw          $a0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r4;
            goto L_8001E8D4;
    }
    // 0x8001E880: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8001E884: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8001E888: addiu       $t8, $t8, 0x1190
    ctx->r24 = ADD32(ctx->r24, 0X1190);
    // 0x8001E88C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8001E890: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E894: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001E898: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E89C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8001E8A0: sw          $t9, -0x1660($at)
    MEM_W(-0X1660, ctx->r1) = ctx->r25;
    // 0x8001E8A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E8A8: sw          $zero, -0x165C($at)
    MEM_W(-0X165C, ctx->r1) = 0;
    // 0x8001E8AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E8B0: sw          $zero, -0x1658($at)
    MEM_W(-0X1658, ctx->r1) = 0;
    // 0x8001E8B4: lbu         $t0, 0x4($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4);
    // 0x8001E8B8: addiu       $t3, $t3, 0x50F0
    ctx->r11 = ADD32(ctx->r11, 0X50F0);
    // 0x8001E8BC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E8C0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001E8C4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8001E8C8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8001E8CC: jal         0x8001E210
    // 0x8001E8D0: addiu       $a1, $a1, -0x1654
    ctx->r5 = ADD32(ctx->r5, -0X1654);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x8001E8D0: addiu       $a1, $a1, -0x1654
    ctx->r5 = ADD32(ctx->r5, -0X1654);
    after_0:
L_8001E8D4:
    // 0x8001E8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E8DC: jr          $ra
    // 0x8001E8E0: nop

    return;
    // 0x8001E8E0: nop

;}
RECOMP_FUNC void func_80802100_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802108: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080210C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80802110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802114: jal         0x80100094
    // 0x80802118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080211C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80802120: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80802124: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80802128: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080212C: beq         $a2, $at, L_808021C4
    if (ctx->r6 == ctx->r1) {
        // 0x80802130: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_808021C4;
    }
    // 0x80802130: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80802134: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80802138: beq         $a2, $at, L_8080215C
    if (ctx->r6 == ctx->r1) {
        // 0x8080213C: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_8080215C;
    }
    // 0x8080213C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80802140: beq         $a2, $at, L_808021E0
    if (ctx->r6 == ctx->r1) {
        // 0x80802144: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808021E0;
    }
    // 0x80802144: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802148: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8080214C: beq         $a2, $at, L_808021D8
    if (ctx->r6 == ctx->r1) {
        // 0x80802150: nop
    
            goto L_808021D8;
    }
    // 0x80802150: nop

    // 0x80802154: b           L_80802204
    // 0x80802158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802204;
    // 0x80802158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080215C:
    // 0x8080215C: lhu         $t6, 0x72($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X72);
    // 0x80802160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802164: addiu       $a0, $a1, 0x30
    ctx->r4 = ADD32(ctx->r5, 0X30);
    // 0x80802168: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080216C: bne         $t7, $at, L_80802188
    if (ctx->r15 != ctx->r1) {
        // 0x80802170: nop
    
            goto L_80802188;
    }
    // 0x80802170: nop

    // 0x80802174: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802178: jal         0x80801AA0
    // 0x8080217C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_1;
    // 0x8080217C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80802180: b           L_80802200
    // 0x80802184: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80802200;
    // 0x80802184: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80802188:
    // 0x80802188: jal         0x8008A040
    // 0x8080218C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080218C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80802190: jal         0x800FFAB0
    // 0x80802194: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80802194: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80802198: jal         0x800FFAB0
    // 0x8080219C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x8080219C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x808021A0: jal         0x80803D64
    // 0x808021A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_5;
    // 0x808021A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x808021A8: jal         0x800DA544
    // 0x808021AC: addiu       $a0, $zero, 0x9C9
    ctx->r4 = ADD32(0, 0X9C9);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808021AC: addiu       $a0, $zero, 0x9C9
    ctx->r4 = ADD32(0, 0X9C9);
    after_6:
    // 0x808021B0: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    // 0x808021B4: jal         0x800887D8
    // 0x808021B8: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808021B8: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_7:
    // 0x808021BC: b           L_80802200
    // 0x808021C0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80802200;
    // 0x808021C0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_808021C4:
    // 0x808021C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808021C8: jal         0x80801AA0
    // 0x808021CC: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_8;
    // 0x808021CC: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_8:
    // 0x808021D0: b           L_80802200
    // 0x808021D4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80802200;
    // 0x808021D4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_808021D8:
    // 0x808021D8: b           L_80802200
    // 0x808021DC: sh          $zero, 0x72($v0)
    MEM_H(0X72, ctx->r2) = 0;
        goto L_80802200;
    // 0x808021DC: sh          $zero, 0x72($v0)
    MEM_H(0X72, ctx->r2) = 0;
L_808021E0:
    // 0x808021E0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x808021E4: jal         0x80803CF0
    // 0x808021E8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_9;
    // 0x808021E8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_9:
    // 0x808021EC: addiu       $a0, $zero, 0x46A
    ctx->r4 = ADD32(0, 0X46A);
    // 0x808021F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808021F4: jal         0x80101180
    // 0x808021F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x808021F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808021FC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80802200:
    // 0x80802200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802204:
    // 0x80802204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802208: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080220C: jr          $ra
    // 0x80802210: nop

    return;
    // 0x80802210: nop

;}
RECOMP_FUNC void func_80095898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095898: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x8009589C: jr          $ra
    // 0x800958A0: lbu         $v0, 0xA2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA2);
    return;
    // 0x800958A0: lbu         $v0, 0xA2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA2);
;}
RECOMP_FUNC void boot_osRecvMesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void bafly_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E8: jal         0x8009BC34
    // 0x808009EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BC34(rdram, ctx);
        goto after_0;
    // 0x808009EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009F0: jal         0x8008E95C
    // 0x808009F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x808009F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808009F8: jal         0x8009BD88
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009BD88(rdram, ctx);
        goto after_2;
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800A00: jal         0x800A4E30
    // 0x80800A04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_3;
    // 0x80800A04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A10: jr          $ra
    // 0x80800A14: nop

    return;
    // 0x80800A14: nop

;}
RECOMP_FUNC void func_808000CC_chjigsawcollect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x808000D0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x808000D8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808000DC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x808000E0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x808000E4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x808000E8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000EC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000F4: jal         0x80100094
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000FC: jal         0x800D8FF8
    // 0x80800100: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800100: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80800104: jal         0x800F54E4
    // 0x80800108: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800108: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x8080010C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800110: jal         0x800F5A00
    // 0x80800114: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800114: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_3:
    // 0x80800118: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8080011C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800120: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800124: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800128: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080012C: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80800130: lhu         $v0, 0x72($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X72);
    // 0x80800134: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800138: beq         $t6, $at, L_80800150
    if (ctx->r14 == ctx->r1) {
        // 0x8080013C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800150;
    }
    // 0x8080013C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800140: beq         $t6, $at, L_80800338
    if (ctx->r14 == ctx->r1) {
        // 0x80800144: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_80800338;
    }
    // 0x80800144: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80800148: b           L_80800470
    // 0x8080014C: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
        goto L_80800470;
    // 0x8080014C: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
L_80800150:
    // 0x80800150: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800154: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800158: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080015C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800160: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800164: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80800168: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8080016C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800170: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800174: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80800178: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080017C: swc1        $f18, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f18.u32l;
    // 0x80800180: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800184: swc1        $f10, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f10.u32l;
    // 0x80800188: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8080018C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80800190: nop

    // 0x80800194: bc1f        L_80800204
    if (!c1cs) {
        // 0x80800198: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80800204;
    }
    // 0x80800198: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080019C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001A8: jal         0x80101FDC
    // 0x808001AC: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808001AC: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    after_4:
    // 0x808001B0: lw          $t7, 0x64($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X64);
    // 0x808001B4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001BC: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808001C0: bgez        $t9, L_808001E4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001C4: nop
    
            goto L_808001E4;
    }
    // 0x808001C4: nop

    // 0x808001C8: jal         0x800FCAE0
    // 0x808001CC: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_5;
    // 0x808001CC: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_5:
    // 0x808001D0: jal         0x800FCA90
    // 0x808001D4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_6;
    // 0x808001D4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_6:
    // 0x808001D8: lbu         $t0, 0x65($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X65);
    // 0x808001DC: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808001E0: sb          $t1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r9;
L_808001E4:
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1476, 0X6B8) << 16);
    // 0x808001E8: addiu       $a2, $a2, 0x6B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1476, 0X6B8));
    // 0x808001EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001F0: jal         0x80089D18
    // 0x808001F4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808001F4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_7:
    // 0x808001F8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808001FC: b           L_808002AC
    // 0x80800200: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
        goto L_808002AC;
    // 0x80800200: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
L_80800204:
    // 0x80800204: jal         0x80013728
    // 0x80800208: nop

    func_80013728(rdram, ctx);
        goto after_8;
    // 0x80800208: nop

    after_8:
    // 0x8080020C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800210: nop

    // 0x80800214: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x80800218: nop

    // 0x8080021C: bc1fl       L_808002AC
    if (!c1cs) {
        // 0x80800220: lwc1        $f12, 0x0($s3)
        ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
            goto L_808002AC;
    }
    goto skip_0;
    // 0x80800220: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80800224: jal         0x80013728
    // 0x80800228: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    func_80013728(rdram, ctx);
        goto after_9;
    // 0x80800228: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    after_9:
    // 0x8080022C: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80800230: nop

    // 0x80800234: bc1fl       L_808002AC
    if (!c1cs) {
        // 0x80800238: lwc1        $f12, 0x0($s3)
        ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
            goto L_808002AC;
    }
    goto skip_1;
    // 0x80800238: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x8080023C: jal         0x80013728
    // 0x80800240: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    func_80013728(rdram, ctx);
        goto after_10;
    // 0x80800240: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    after_10:
    // 0x80800244: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800248: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080024C: nop

    // 0x80800250: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800254: nop

    // 0x80800258: bc1fl       L_808002AC
    if (!c1cs) {
        // 0x8080025C: lwc1        $f12, 0x0($s3)
        ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
            goto L_808002AC;
    }
    goto skip_2;
    // 0x8080025C: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x80800260: jal         0x80013728
    // 0x80800264: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    func_80013728(rdram, ctx);
        goto after_11;
    // 0x80800264: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    after_11:
    // 0x80800268: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8080026C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800270: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1476, 0X660) << 16);
    // 0x80800274: lwc1        $f4, 0x660($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1476, 0X660));
    // 0x80800278: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080027C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800280: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800284: jal         0x800F10B4
    // 0x80800288: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80800288: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x8080028C: jal         0x800C4B64
    // 0x80800290: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800C4B64(rdram, ctx);
        goto after_13;
    // 0x80800290: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_13:
    // 0x80800294: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1476, 0X6C4) << 16);
    // 0x80800298: addiu       $a2, $a2, 0x6C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1476, 0X6C4));
    // 0x8080029C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002A0: jal         0x80089D18
    // 0x808002A4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x808002A4: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_14:
    // 0x808002A8: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
L_808002AC:
    // 0x808002AC: jal         0x80013728
    // 0x808002B0: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    func_80013728(rdram, ctx);
        goto after_15;
    // 0x808002B0: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    after_15:
    // 0x808002B4: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x808002B8: jal         0x80013728
    // 0x808002BC: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    func_80013728(rdram, ctx);
        goto after_16;
    // 0x808002BC: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    after_16:
    // 0x808002C0: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: jal         0x800F1DF4
    // 0x808002CC: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800F1DF4(rdram, ctx);
        goto after_17;
    // 0x808002CC: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_17:
    // 0x808002D0: jal         0x800136E4
    // 0x808002D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_18;
    // 0x808002D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_18:
    // 0x808002D8: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x808002DC: swc1        $f0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f0.u32l;
    // 0x808002E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808002E4: jal         0x80103DFC
    // 0x808002E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80103DFC(rdram, ctx);
        goto after_19;
    // 0x808002E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
    // 0x808002EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808002F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002F4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x808002F8: jal         0x800DC178
    // 0x808002FC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_20;
    // 0x808002FC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_20:
    // 0x80800300: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800304: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80800308: jal         0x800DC178
    // 0x8080030C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x8080030C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_21:
    // 0x80800310: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800314: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080031C: jal         0x800EF214
    // 0x80800320: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_800EF214(rdram, ctx);
        goto after_22;
    // 0x80800320: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_22:
    // 0x80800324: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800328: jal         0x808005B8
    // 0x8080032C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808005B8_chjigsawcollect(rdram, ctx);
        goto after_23;
    // 0x8080032C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_23:
    // 0x80800330: b           L_80800474
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800474;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800338:
    // 0x80800338: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x8080033C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800340: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800348: lwc1        $f12, 0x8($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8080034C: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80800350: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800354: jal         0x800F15F8
    // 0x80800358: nop

    func_800F15F8(rdram, ctx);
        goto after_24;
    // 0x80800358: nop

    after_24:
    // 0x8080035C: mul.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80800360: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x80800364: lwc1        $f16, 0x48($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80800368: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080036C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800370: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800374: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800378: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080037C: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x80800380: swc1        $f6, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f6.u32l;
L_80800384:
    // 0x80800384: jal         0x800DC0C0
    // 0x80800388: nop

    func_800DC0C0(rdram, ctx);
        goto after_25;
    // 0x80800388: nop

    after_25:
    // 0x8080038C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1476, 0X664) << 16);
    // 0x80800390: lwc1        $f4, 0x664($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1476, 0X664));
    // 0x80800394: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800398: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080039C: nop

    // 0x808003A0: bc1fl       L_808003EC
    if (!c1cs) {
        // 0x808003A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808003EC;
    }
    goto skip_3;
    // 0x808003A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x808003A8: jal         0x80103DFC
    // 0x808003AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80103DFC(rdram, ctx);
        goto after_26;
    // 0x808003AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_26:
    // 0x808003B0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x808003B4: jal         0x800DC178
    // 0x808003B8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_27;
    // 0x808003B8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_27:
    // 0x808003BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808003C0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x808003C4: jal         0x800DC178
    // 0x808003C8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_28;
    // 0x808003C8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_28:
    // 0x808003CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808003D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D8: jal         0x800EF214
    // 0x808003DC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    func_800EF214(rdram, ctx);
        goto after_29;
    // 0x808003DC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_29:
    // 0x808003E0: jal         0x80088AA8
    // 0x808003E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _fxtwinkle_entrypoint_0(rdram, ctx);
        goto after_30;
    // 0x808003E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x808003E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808003EC:
    // 0x808003EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003F0: bne         $s0, $at, L_80800384
    if (ctx->r16 != ctx->r1) {
        // 0x808003F4: nop
    
            goto L_80800384;
    }
    // 0x808003F4: nop

    // 0x808003F8: jal         0x8001210C
    // 0x808003FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_31;
    // 0x808003FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_31:
    // 0x80800400: bne         $v0, $zero, L_8080041C
    if (ctx->r2 != 0) {
        // 0x80800404: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080041C;
    }
    // 0x80800404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800408: jal         0x80103DFC
    // 0x8080040C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80103DFC(rdram, ctx);
        goto after_32;
    // 0x8080040C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_32:
    // 0x80800410: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800414: jal         0x808005B8
    // 0x80800418: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808005B8_chjigsawcollect(rdram, ctx);
        goto after_33;
    // 0x80800418: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_33:
L_8080041C:
    // 0x8080041C: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800420: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800424: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80800428: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x8080042C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80800430: nop

    // 0x80800434: bc1fl       L_80800470
    if (!c1cs) {
        // 0x80800438: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_80800470;
    }
    goto skip_4;
    // 0x80800438: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    skip_4:
    // 0x8080043C: jal         0x800888C8
    // 0x80800440: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_34;
    // 0x80800440: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_34:
    // 0x80800444: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    // 0x80800448: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x8080044C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800450: beq         $a0, $zero, L_80800464
    if (ctx->r4 == 0) {
        // 0x80800454: nop
    
            goto L_80800464;
    }
    // 0x80800454: nop

    // 0x80800458: jal         0x800863E8
    // 0x8080045C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_35;
    // 0x8080045C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_35:
    // 0x80800460: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
L_80800464:
    // 0x80800464: jal         0x800FFAB0
    // 0x80800468: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_36;
    // 0x80800468: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_36:
    // 0x8080046C: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
L_80800470:
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800474:
    // 0x80800474: jal         0x800EE7F8
    // 0x80800478: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_37;
    // 0x80800478: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_37:
    // 0x8080047C: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x80800480: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800484: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800488: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080048C: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80800490: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800494: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80800498: jal         0x800F10B4
    // 0x8080049C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_38;
    // 0x8080049C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_38:
    // 0x808004A0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808004A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x808004B0: add.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808004B4: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x808004B8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808004BC: jal         0x800EF214
    // 0x808004C0: nop

    func_800EF214(rdram, ctx);
        goto after_39;
    // 0x808004C0: nop

    after_39:
    // 0x808004C4: lw          $t2, 0x10($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X10);
    // 0x808004C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004CC: beql        $t2, $zero, L_80800500
    if (ctx->r10 == 0) {
        // 0x808004D0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800500;
    }
    goto skip_5;
    // 0x808004D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x808004D4: jal         0x800EE7F8
    // 0x808004D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_40;
    // 0x808004D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_40:
    // 0x808004DC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808004E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004E4: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808004E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004EC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808004F0: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x808004F4: jal         0x800C8CB8
    // 0x808004F8: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    func_800C8CB8(rdram, ctx);
        goto after_41;
    // 0x808004F8: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    after_41:
    // 0x808004FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800500:
    // 0x80800500: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800504: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800508: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080050C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80800510: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80800514: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80800518: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8080051C: jr          $ra
    // 0x80800520: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800520: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _chstarspinnerctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E10: syscall     245
    recomp_syscall_handler(rdram, ctx, 0x80085E10);
    return;
    // 0x80085E14: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800A3280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3280: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3284: jr          $ra
    // 0x800A3288: lbu         $v0, 0x2A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2A);
    return;
    // 0x800A3288: lbu         $v0, 0x2A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2A);
;}
RECOMP_FUNC void chnastycavemen_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(760, 0X11BC) << 16);
    // 0x80800BD8: jr          $ra
    // 0x80800BDC: addiu       $v0, $v0, 0x11BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(760, 0X11BC));
    return;
    // 0x80800BDC: addiu       $v0, $v0, 0x11BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(760, 0X11BC));
;}
RECOMP_FUNC void func_80807EEC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807EF4: jal         0x800A3404
    // 0x80807EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A3404(rdram, ctx);
        goto after_0;
    // 0x80807EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80807EFC: bne         $v0, $zero, L_80807F14
    if (ctx->r2 != 0) {
        // 0x80807F00: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80807F14;
    }
    // 0x80807F00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80807F04: jal         0x800A3544
    // 0x80807F08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3544(rdram, ctx);
        goto after_1;
    // 0x80807F08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80807F0C: jal         0x80807DD4
    // 0x80807F10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807DD4_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807F10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80807F14:
    // 0x80807F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807F1C: jr          $ra
    // 0x80807F20: nop

    return;
    // 0x80807F20: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1E8: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1E8);
    return;
    // 0x8008A1EC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800D2014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2014: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D2018: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D201C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D2020: addiu       $v0, $v0, -0x4D72
    ctx->r2 = ADD32(ctx->r2, -0X4D72);
    // 0x800D2024: addiu       $v1, $v1, -0x4D9A
    ctx->r3 = ADD32(ctx->r3, -0X4D9A);
    // 0x800D2028: sh          $zero, -0x4DA0($at)
    MEM_H(-0X4DA0, ctx->r1) = 0;
    // 0x800D202C: sh          $zero, -0x4D9E($at)
    MEM_H(-0X4D9E, ctx->r1) = 0;
    // 0x800D2030: sh          $zero, -0x4D9C($at)
    MEM_H(-0X4D9C, ctx->r1) = 0;
L_800D2034:
    // 0x800D2034: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800D2038: sh          $zero, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = 0;
    // 0x800D203C: sh          $zero, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = 0;
    // 0x800D2040: sh          $zero, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = 0;
    // 0x800D2044: bne         $v1, $v0, L_800D2034
    if (ctx->r3 != ctx->r2) {
        // 0x800D2048: sh          $zero, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = 0;
            goto L_800D2034;
    }
    // 0x800D2048: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x800D204C: jr          $ra
    // 0x800D2050: nop

    return;
    // 0x800D2050: nop

;}
RECOMP_FUNC void func_80800718_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080071C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800724: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800728: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080072C: jal         0x80100094
    // 0x80800730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800734: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x80100094
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080074C: jal         0x80101FDC
    // 0x80800750: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800750: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800754: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800758: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080075C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800760: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800764: beq         $at, $zero, L_80800860
    if (ctx->r1 == 0) {
        // 0x80800768: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800860;
    }
    // 0x80800768: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080076C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2220, 0XCC0) << 16);
    // 0x80800770: addu        $at, $at, $t7
    gpr jr_addend_80800778 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800774: lw          $t7, 0xCC0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2220, 0XCC0));
    // 0x80800778: jr          $t7
    // 0x8080077C: nop

    switch (jr_addend_80800778 >> 2) {
        case 0: goto L_80800780; break;
        case 1: goto L_80800788; break;
        case 2: goto L_808007A8; break;
        case 3: goto L_808007F0; break;
        case 4: goto L_80800804; break;
        case 5: goto L_80800860; break;
        default: switch_error(__func__, 0x80800778, 0x80800CC0);
    }
    // 0x8080077C: nop

L_80800780:
    // 0x80800780: b           L_80800860
    // 0x80800784: sw          $zero, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = 0;
        goto L_80800860;
    // 0x80800784: sw          $zero, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = 0;
L_80800788:
    // 0x80800788: lui         $a1, 0xC53B
    ctx->r5 = S32(0XC53B << 16);
    // 0x8080078C: lui         $a2, 0xC6AB
    ctx->r6 = S32(0XC6AB << 16);
    // 0x80800790: ori         $a2, $a2, 0xE000
    ctx->r6 = ctx->r6 | 0XE000;
    // 0x80800794: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800798: jal         0x8008A468
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007A0: b           L_80800864
    // 0x808007A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800864;
    // 0x808007A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007A8:
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007AC: jal         0x8010A590
    // 0x808007B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x808007B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x808007B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808007B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: jal         0x8008A430
    // 0x808007C4: sw          $t8, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = ctx->r24;
    _suegg_entrypoint_23(rdram, ctx);
        goto after_5;
    // 0x808007C4: sw          $t8, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = ctx->r24;
    after_5:
    // 0x808007C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007D0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808007D4: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x808007D8: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x808007DC: swc1        $f4, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f4.u32l;
    // 0x808007E0: jal         0x80101180
    // 0x808007E4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x808007E4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x808007E8: b           L_80800864
    // 0x808007EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800864;
    // 0x808007EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007F0:
    // 0x808007F0: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x808007F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007F8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808007FC: b           L_80800860
    // 0x80800800: swc1        $f6, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f6.u32l;
        goto L_80800860;
    // 0x80800800: swc1        $f6, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f6.u32l;
L_80800804:
    // 0x80800804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800808: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8080080C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800810: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800814:
    // 0x80800814: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800818: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x8080081C: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x80800820: sw          $v0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r2;
    // 0x80800824: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x80800828: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8080082C: sw          $v0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r2;
    // 0x80800830: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800834: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x80800838: bne         $a0, $a1, L_80800814
    if (ctx->r4 != ctx->r5) {
        // 0x8080083C: sw          $v0, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->r2;
            goto L_80800814;
    }
    // 0x8080083C: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80800840: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800844: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2220, 0XD28) << 16);
    // 0x80800848: addiu       $a3, $a3, 0xD28
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2220, 0XD28));
    // 0x8080084C: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x80800850: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80800854: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800858: jal         0x8010D930
    // 0x8080085C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_7;
    // 0x8080085C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_7:
L_80800860:
    // 0x80800860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800864:
    // 0x80800864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080086C: jr          $ra
    // 0x80800870: nop

    return;
    // 0x80800870: nop

;}
