#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800534_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080053C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800540: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800544: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80800548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080054C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800550: beql        $a1, $v1, L_808007C8
    if (ctx->r5 == ctx->r3) {
        // 0x80800554: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x80800554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800558: beq         $v1, $at, L_80800574
    if (ctx->r3 == ctx->r1) {
        // 0x8080055C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800574;
    }
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800564: beq         $v1, $at, L_8080058C
    if (ctx->r3 == ctx->r1) {
        // 0x80800568: nop
    
            goto L_8080058C;
    }
    // 0x80800568: nop

    // 0x8080056C: b           L_808005A4
    // 0x80800570: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_808005A4;
    // 0x80800570: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80800574:
    // 0x80800574: jal         0x80800E10
    // 0x80800578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800E10_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80800578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080057C: jal         0x80087CD0
    // 0x80800580: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    _gcnewoption_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800580: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_1:
    // 0x80800584: b           L_808005A4
    // 0x80800588: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
        goto L_808005A4;
    // 0x80800588: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_8080058C:
    // 0x8080058C: jal         0x80088728
    // 0x80800590: addiu       $a0, $zero, 0x1864
    ctx->r4 = ADD32(0, 0X1864);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800590: addiu       $a0, $zero, 0x1864
    ctx->r4 = ADD32(0, 0X1864);
    after_2:
    // 0x80800594: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80800598: jal         0x8080152C
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080152C_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005A0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_808005A4:
    // 0x808005A4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808005A8: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808005AC: beq         $at, $zero, L_808007BC
    if (ctx->r1 == 0) {
        // 0x808005B0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808007BC;
    }
    // 0x808005B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808005B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1F88) << 16);
    // 0x808005B8: addu        $at, $at, $t8
    gpr jr_addend_808005C0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808005BC: lw          $t8, 0x1F88($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1F88));
    // 0x808005C0: jr          $t8
    // 0x808005C4: nop

    switch (jr_addend_808005C0 >> 2) {
        case 0: goto L_808005C8; break;
        case 1: goto L_80800690; break;
        case 2: goto L_808006B4; break;
        case 3: goto L_808006F4; break;
        case 4: goto L_80800788; break;
        default: switch_error(__func__, 0x808005C0, 0x80801F88);
    }
    // 0x808005C4: nop

L_808005C8:
    // 0x808005C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005CC: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x808005D0: jal         0x800FC348
    // 0x808005D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800FC348(rdram, ctx);
        goto after_4;
    // 0x808005D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x808005D8: jal         0x800FEC60
    // 0x808005DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FEC60(rdram, ctx);
        goto after_5;
    // 0x808005DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x808005E0: jal         0x800FC124
    // 0x808005E4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_800FC124(rdram, ctx);
        goto after_6;
    // 0x808005E4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_6:
    // 0x808005E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1F9C) << 16);
    // 0x808005EC: jal         0x80800DE0
    // 0x808005F0: lwc1        $f12, 0x1F9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1F9C));
    func_80800DE0_gcnewpause(rdram, ctx);
        goto after_7;
    // 0x808005F0: lwc1        $f12, 0x1F9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1F9C));
    after_7:
    // 0x808005F4: jal         0x800C06C4
    // 0x808005F8: nop

    func_800C06C4(rdram, ctx);
        goto after_8;
    // 0x808005F8: nop

    after_8:
    // 0x808005FC: jal         0x80018634
    // 0x80800600: nop

    func_80018634(rdram, ctx);
        goto after_9;
    // 0x80800600: nop

    after_9:
    // 0x80800604: jal         0x800D395C
    // 0x80800608: nop

    func_800D395C(rdram, ctx);
        goto after_10;
    // 0x80800608: nop

    after_10:
    // 0x8080060C: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x80800610: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8080061C;
    }
    // 0x80800610: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80800614: b           L_808007BC
    // 0x80800618: sb          $t9, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r25;
        goto L_808007BC;
    // 0x80800618: sb          $t9, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r25;
L_8080061C:
    // 0x8080061C: jal         0x800D3948
    // 0x80800620: nop

    func_800D3948(rdram, ctx);
        goto after_11;
    // 0x80800620: nop

    after_11:
    // 0x80800624: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x80800628: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800654;
    }
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x800A946C
    // 0x80800630: nop

    func_800A946C(rdram, ctx);
        goto after_12;
    // 0x80800630: nop

    after_12:
    // 0x80800634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800638: bne         $v0, $at, L_8080064C
    if (ctx->r2 != ctx->r1) {
        // 0x8080063C: addiu       $t1, $zero, 0x6
        ctx->r9 = ADD32(0, 0X6);
            goto L_8080064C;
    }
    // 0x8080063C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800640: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80800644: b           L_808007BC
    // 0x80800648: sb          $t0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r8;
        goto L_808007BC;
    // 0x80800648: sb          $t0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r8;
L_8080064C:
    // 0x8080064C: b           L_808007BC
    // 0x80800650: sb          $t1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r9;
        goto L_808007BC;
    // 0x80800650: sb          $t1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r9;
L_80800654:
    // 0x80800654: jal         0x80801EF0
    // 0x80800658: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    func_80801EF0_gcnewpause(rdram, ctx);
        goto after_13;
    // 0x80800658: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    after_13:
    // 0x8080065C: beq         $v0, $zero, L_80800670
    if (ctx->r2 == 0) {
        // 0x80800660: nop
    
            goto L_80800670;
    }
    // 0x80800660: nop

    // 0x80800664: lb          $t2, 0xD($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XD);
    // 0x80800668: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8080066C: sb          $t3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r11;
L_80800670:
    // 0x80800670: jal         0x80801F18
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F18_gcnewpause(rdram, ctx);
        goto after_14;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800678: beql        $v0, $zero, L_808007C0
    if (ctx->r2 == 0) {
        // 0x8080067C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_808007C0;
    }
    goto skip_1;
    // 0x8080067C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800680: lb          $t4, 0xD($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XD);
    // 0x80800684: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80800688: b           L_808007BC
    // 0x8080068C: sb          $t5, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r13;
        goto L_808007BC;
    // 0x8080068C: sb          $t5, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r13;
L_80800690:
    // 0x80800690: jal         0x80800A08
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A08_gcnewpause(rdram, ctx);
        goto after_15;
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800698: lb          $t6, 0xD($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD);
    // 0x8080069C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2658, 0X2072) << 16);
    // 0x808006A0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808006A4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808006A8: lb          $t8, 0x2072($t8)
    ctx->r24 = MEM_B(ctx->r24, (int16_t)RELOC_LO16(2658, 0X2072));
    // 0x808006AC: b           L_808007BC
    // 0x808006B0: sb          $t8, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r24;
        goto L_808007BC;
    // 0x808006B0: sb          $t8, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r24;
L_808006B4:
    // 0x808006B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808006B8: sb          $t9, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r25;
    // 0x808006BC: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x808006C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FA0) << 16);
    // 0x808006C4: lwc1        $f4, 0x1FA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FA0));
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: jal         0x80801660
    // 0x808006D0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    func_80801660_gcnewpause(rdram, ctx);
        goto after_16;
    // 0x808006D0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_16:
    // 0x808006D4: jal         0x8080136C
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080136C_gcnewpause(rdram, ctx);
        goto after_17;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808006DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808006E0: jal         0x800880D8
    // 0x808006E4: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x808006E4: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    after_18:
    // 0x808006E8: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x808006EC: b           L_808007BC
    // 0x808006F0: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
        goto L_808007BC;
    // 0x808006F0: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
L_808006F4:
    // 0x808006F4: jal         0x800FECB8
    // 0x808006F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FECB8(rdram, ctx);
        goto after_19;
    // 0x808006F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x808006FC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80800700: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800704: beq         $v0, $at, L_80800730
    if (ctx->r2 == ctx->r1) {
        // 0x80800708: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800730;
    }
    // 0x80800708: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080070C: beq         $v0, $at, L_80800764
    if (ctx->r2 == ctx->r1) {
        // 0x80800710: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80800764;
    }
    // 0x80800710: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800714: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800718: beq         $v0, $at, L_80800764
    if (ctx->r2 == ctx->r1) {
        // 0x8080071C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800764;
    }
    // 0x8080071C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800720: beql        $v0, $at, L_80800768
    if (ctx->r2 == ctx->r1) {
        // 0x80800724: addiu       $a1, $zero, 0x7D0
        ctx->r5 = ADD32(0, 0X7D0);
            goto L_80800768;
    }
    goto skip_2;
    // 0x80800724: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    skip_2:
    // 0x80800728: b           L_808007C0
    // 0x8080072C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_808007C0;
    // 0x8080072C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80800730:
    // 0x80800730: jal         0x800C0710
    // 0x80800734: nop

    func_800C0710(rdram, ctx);
        goto after_20;
    // 0x80800734: nop

    after_20:
    // 0x80800738: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FA4) << 16);
    // 0x8080073C: jal         0x80800DE0
    // 0x80800740: lwc1        $f12, 0x1FA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FA4));
    func_80800DE0_gcnewpause(rdram, ctx);
        goto after_21;
    // 0x80800740: lwc1        $f12, 0x1FA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FA4));
    after_21:
    // 0x80800744: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800748: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x8080074C: jal         0x800FC348
    // 0x80800750: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800FC348(rdram, ctx);
        goto after_22;
    // 0x80800750: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_22:
    // 0x80800754: jal         0x800FC1A8
    // 0x80800758: nop

    func_800FC1A8(rdram, ctx);
        goto after_23;
    // 0x80800758: nop

    after_23:
    // 0x8080075C: b           L_808007C0
    // 0x80800760: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_808007C0;
    // 0x80800760: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80800764:
    // 0x80800764: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
L_80800768:
    // 0x80800768: jal         0x800FC348
    // 0x8080076C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800FC348(rdram, ctx);
        goto after_24;
    // 0x8080076C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_24:
    // 0x80800770: jal         0x800FC1A8
    // 0x80800774: nop

    func_800FC1A8(rdram, ctx);
        goto after_25;
    // 0x80800774: nop

    after_25:
    // 0x80800778: jal         0x800FE4E4
    // 0x8080077C: nop

    func_800FE4E4(rdram, ctx);
        goto after_26;
    // 0x8080077C: nop

    after_26:
    // 0x80800780: b           L_808007C0
    // 0x80800784: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_808007C0;
    // 0x80800784: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80800788:
    // 0x80800788: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080078C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800790: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80800794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800798: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    // 0x8080079C: jal         0x800FCAE0
    // 0x808007A0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_800FCAE0(rdram, ctx);
        goto after_27;
    // 0x808007A0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_27:
    // 0x808007A4: jal         0x800FCA90
    // 0x808007A8: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_800FCA90(rdram, ctx);
        goto after_28;
    // 0x808007A8: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_28:
    // 0x808007AC: jal         0x800FC660
    // 0x808007B0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800FC660(rdram, ctx);
        goto after_29;
    // 0x808007B0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_29:
    // 0x808007B4: jal         0x80801CCC
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CCC_gcnewpause(rdram, ctx);
        goto after_30;
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_808007BC:
    // 0x808007BC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_808007C0:
    // 0x808007C0: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x808007C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007C8:
    // 0x808007C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_80111ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111AC4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80111AC8: jal         0x800EE7F8
    // 0x80111ACC: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80111ACC: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    after_0:
    // 0x80111AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111AD8: jr          $ra
    // 0x80111ADC: nop

    return;
    // 0x80111ADC: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801044: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1A8C) << 16);
    // 0x80801048: jr          $ra
    // 0x8080104C: addiu       $v0, $v0, 0x1A8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1A8C));
    return;
    // 0x8080104C: addiu       $v0, $v0, 0x1A8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1A8C));
;}
RECOMP_FUNC void _fxripple_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889A8: syscall     715
    recomp_syscall_handler(rdram, ctx, 0x800889A8);
    return;
    // 0x800889AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800B50F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B50F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B50F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B50F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B50FC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B5100: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B5104: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B5108: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B510C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B5110: jal         0x800D8FF8
    // 0x800B5114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800B5114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B5118: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B511C: addiu       $s0, $s0, 0x7F14
    ctx->r16 = ADD32(ctx->r16, 0X7F14);
    // 0x800B5120: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800B5124: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800B5128: nop

    // 0x800B512C: bc1f        L_800B5140
    if (!c1cs) {
        // 0x800B5130: nop
    
            goto L_800B5140;
    }
    // 0x800B5130: nop

    // 0x800B5134: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5138: b           L_800B5154
    // 0x800B513C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_800B5154;
    // 0x800B513C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_800B5140:
    // 0x800B5140: jal         0x800D8FF8
    // 0x800B5144: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800B5144: nop

    after_1:
    // 0x800B5148: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800B514C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800B5150: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_800B5154:
    // 0x800B5154: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800B5158: addiu       $s3, $s3, 0x7F10
    ctx->r19 = ADD32(ctx->r19, 0X7F10);
    // 0x800B515C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B5160: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800B5164: addiu       $s4, $s4, 0x7F18
    ctx->r20 = ADD32(ctx->r20, 0X7F18);
    // 0x800B5168: beql        $t6, $zero, L_800B5238
    if (ctx->r14 == 0) {
        // 0x800B516C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800B5238;
    }
    goto skip_0;
    // 0x800B516C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800B5170: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x800B5174: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B5178: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B517C: blez        $v0, L_800B51E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B5180: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_800B51E8;
    }
    // 0x800B5180: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800B5184: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800B5188: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_800B518C:
    // 0x800B518C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800B5190: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x800B5194: jal         0x800B4790
    // 0x800B5198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B4790(rdram, ctx);
        goto after_2;
    // 0x800B5198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B519C: lbu         $t9, 0x9($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X9);
    // 0x800B51A0: beql        $t9, $zero, L_800B51D0
    if (ctx->r25 == 0) {
        // 0x800B51A4: sb          $zero, 0x8($s0)
        MEM_B(0X8, ctx->r16) = 0;
            goto L_800B51D0;
    }
    goto skip_1;
    // 0x800B51A4: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    skip_1:
    // 0x800B51A8: lbu         $t0, 0x7($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7);
    // 0x800B51AC: bnel        $s5, $t0, L_800B51D0
    if (ctx->r21 != ctx->r8) {
        // 0x800B51B0: sb          $zero, 0x8($s0)
        MEM_B(0X8, ctx->r16) = 0;
            goto L_800B51D0;
    }
    goto skip_2;
    // 0x800B51B0: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    skip_2:
    // 0x800B51B4: lw          $t1, 0x8C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8C);
    // 0x800B51B8: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    // 0x800B51BC: bnel        $t1, $t2, L_800B51D0
    if (ctx->r9 != ctx->r10) {
        // 0x800B51C0: sb          $zero, 0x8($s0)
        MEM_B(0X8, ctx->r16) = 0;
            goto L_800B51D0;
    }
    goto skip_3;
    // 0x800B51C0: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    skip_3:
    // 0x800B51C4: b           L_800B51D0
    // 0x800B51C8: sb          $s6, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r22;
        goto L_800B51D0;
    // 0x800B51C8: sb          $s6, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r22;
    // 0x800B51CC: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
L_800B51D0:
    // 0x800B51D0: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x800B51D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B51D8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800B51DC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B51E0: bnel        $at, $zero, L_800B518C
    if (ctx->r1 != 0) {
        // 0x800B51E4: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_800B518C;
    }
    goto skip_4;
    // 0x800B51E4: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_4:
L_800B51E8:
    // 0x800B51E8: blez        $v0, L_800B5234
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B51EC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800B5234;
    }
    // 0x800B51EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B51F0: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
L_800B51F4:
    // 0x800B51F4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B51F8: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x800B51FC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800B5200: lbu         $t5, 0x8($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X8);
    // 0x800B5204: beql        $t5, $zero, L_800B5228
    if (ctx->r13 == 0) {
        // 0x800B5208: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800B5228;
    }
    goto skip_5;
    // 0x800B5208: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_5:
    // 0x800B520C: jal         0x800B5450
    // 0x800B5210: nop

    func_800B5450(rdram, ctx);
        goto after_3;
    // 0x800B5210: nop

    after_3:
    // 0x800B5214: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B5218: lh          $v0, 0x7F18($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7F18);
    // 0x800B521C: b           L_800B5228
    // 0x800B5220: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_800B5228;
    // 0x800B5220: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B5224: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800B5228:
    // 0x800B5228: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B522C: bnel        $at, $zero, L_800B51F4
    if (ctx->r1 != 0) {
        // 0x800B5230: lw          $t3, 0x0($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X0);
            goto L_800B51F4;
    }
    goto skip_6;
    // 0x800B5230: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    skip_6:
L_800B5234:
    // 0x800B5234: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800B5238:
    // 0x800B5238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B523C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5240: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B5244: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B5248: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B524C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5250: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B5254: jr          $ra
    // 0x800B5258: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B5258: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C7980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7980: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800C7984: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x800C7988: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800C798C: beql        $at, $zero, L_800C79A0
    if (ctx->r1 == 0) {
        // 0x800C7990: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C79A0;
    }
    goto skip_0;
    // 0x800C7990: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x800C7994: jr          $ra
    // 0x800C7998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C7998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C799C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800C79A0:
    // 0x800C79A0: bnel        $v0, $at, L_800C79B8
    if (ctx->r2 != ctx->r1) {
        // 0x800C79A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C79B8;
    }
    goto skip_1;
    // 0x800C79A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x800C79A8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C79AC: jr          $ra
    // 0x800C79B0: addiu       $v0, $v0, -0x6EF8
    ctx->r2 = ADD32(ctx->r2, -0X6EF8);
    return;
    // 0x800C79B0: addiu       $v0, $v0, -0x6EF8
    ctx->r2 = ADD32(ctx->r2, -0X6EF8);
    // 0x800C79B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800C79B8:
    // 0x800C79B8: bne         $v0, $at, L_800C79C8
    if (ctx->r2 != ctx->r1) {
        // 0x800C79BC: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800C79C8;
    }
    // 0x800C79BC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C79C0: jr          $ra
    // 0x800C79C4: addiu       $v0, $v0, -0x6EF0
    ctx->r2 = ADD32(ctx->r2, -0X6EF0);
    return;
    // 0x800C79C4: addiu       $v0, $v0, -0x6EF0
    ctx->r2 = ADD32(ctx->r2, -0X6EF0);
L_800C79C8:
    // 0x800C79C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C79CC: bne         $v1, $at, L_800C79E0
    if (ctx->r3 != ctx->r1) {
        // 0x800C79D0: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800C79E0;
    }
    // 0x800C79D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C79D4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800C79D8: jr          $ra
    // 0x800C79DC: addiu       $v0, $v0, -0x6ED8
    ctx->r2 = ADD32(ctx->r2, -0X6ED8);
    return;
    // 0x800C79DC: addiu       $v0, $v0, -0x6ED8
    ctx->r2 = ADD32(ctx->r2, -0X6ED8);
L_800C79E0:
    // 0x800C79E0: addiu       $v0, $v0, -0x6EE8
    ctx->r2 = ADD32(ctx->r2, -0X6EE8);
    // 0x800C79E4: jr          $ra
    // 0x800C79E8: nop

    return;
    // 0x800C79E8: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808007D8: jal         0x80100094
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808007E4: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x808007E8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808007EC: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x808007F0: lbu         $t1, 0x22($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X22);
    // 0x808007F4: sb          $t8, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r24;
    // 0x808007F8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808007FC: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80800800: sb          $t2, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r10;
    // 0x80800804: lhu         $t3, 0x22($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X22);
    // 0x80800808: sh          $t9, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r25;
    // 0x8080080C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80800810: sh          $t4, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r12;
    // 0x80800814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void func_80803514_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803514: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080351C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803520: jal         0x8010CD28
    // 0x80803524: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x80803524: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80803528: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080352C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803530: jal         0x800F1DCC
    // 0x80803534: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80803534: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_1:
    // 0x80803538: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8080353C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803540: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80803544: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80803548: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080354C: nop

    // 0x80803550: bc1t        L_80803570
    if (c1cs) {
        // 0x80803554: nop
    
            goto L_80803570;
    }
    // 0x80803554: nop

    // 0x80803558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080355C: nop

    // 0x80803560: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80803564: nop

    // 0x80803568: bc1fl       L_80803688
    if (!c1cs) {
        // 0x8080356C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803688;
    }
    goto skip_0;
    // 0x8080356C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80803570:
    // 0x80803570: jal         0x80101F24
    // 0x80803574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x80803574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80803578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080357C: jal         0x801022E4
    // 0x80803580: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80803580: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80803584: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80803588: beq         $v0, $at, L_808035A4
    if (ctx->r2 == ctx->r1) {
        // 0x8080358C: lwc1        $f2, 0x20($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
            goto L_808035A4;
    }
    // 0x8080358C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80803590: addiu       $at, $zero, 0x85
    ctx->r1 = ADD32(0, 0X85);
    // 0x80803594: beq         $v0, $at, L_808035E8
    if (ctx->r2 == ctx->r1) {
        // 0x80803598: nop
    
            goto L_808035E8;
    }
    // 0x80803598: nop

    // 0x8080359C: b           L_80803688
    // 0x808035A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803688;
    // 0x808035A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808035A4:
    // 0x808035A4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808035A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808035AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4590) << 16);
    // 0x808035B0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808035B4: nop

    // 0x808035B8: bc1fl       L_80803688
    if (!c1cs) {
        // 0x808035BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803688;
    }
    goto skip_1;
    // 0x808035BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808035C0: lwc1        $f10, 0x4590($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4590));
    // 0x808035C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808035C8: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x808035CC: nop

    // 0x808035D0: bc1fl       L_80803688
    if (!c1cs) {
        // 0x808035D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803688;
    }
    goto skip_2;
    // 0x808035D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808035D8: jal         0x80102B2C
    // 0x808035DC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_80102B2C(rdram, ctx);
        goto after_4;
    // 0x808035DC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_4:
    // 0x808035E0: b           L_80803688
    // 0x808035E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803688;
    // 0x808035E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808035E8:
    // 0x808035E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4594) << 16);
    // 0x808035EC: lwc1        $f16, 0x4594($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4594));
    // 0x808035F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4598) << 16);
    // 0x808035F4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x808035F8: nop

    // 0x808035FC: bc1fl       L_80803618
    if (!c1cs) {
        // 0x80803600: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80803618;
    }
    goto skip_3;
    // 0x80803600: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_3:
    // 0x80803604: lwc1        $f18, 0x4598($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4598));
    // 0x80803608: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8080360C: nop

    // 0x80803610: bc1t        L_80803644
    if (c1cs) {
        // 0x80803614: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80803644;
    }
    // 0x80803614: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80803618:
    // 0x80803618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080361C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X459C) << 16);
    // 0x80803620: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80803624: nop

    // 0x80803628: bc1fl       L_80803688
    if (!c1cs) {
        // 0x8080362C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803688;
    }
    goto skip_4;
    // 0x8080362C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80803630: lwc1        $f6, 0x459C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X459C));
    // 0x80803634: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80803638: nop

    // 0x8080363C: bc1fl       L_80803688
    if (!c1cs) {
        // 0x80803640: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803688;
    }
    goto skip_5;
    // 0x80803640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
L_80803644:
    // 0x80803644: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80803648: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080364C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80803650: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80803654: nop

    // 0x80803658: bc1fl       L_80803674
    if (!c1cs) {
        // 0x8080365C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80803674;
    }
    goto skip_6;
    // 0x8080365C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_6:
    // 0x80803660: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80803664: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803668: b           L_8080367C
    // 0x8080366C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
        goto L_8080367C;
    // 0x8080366C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803670: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80803674:
    // 0x80803674: nop

    // 0x80803678: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
L_8080367C:
    // 0x8080367C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80803680: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80803684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803688:
    // 0x80803688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080368C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803690: jr          $ra
    // 0x80803694: nop

    return;
    // 0x80803694: nop

;}
RECOMP_FUNC void func_808017FC_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801800: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801804: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080180C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801810: beq         $a1, $at, L_8080183C
    if (ctx->r5 == ctx->r1) {
        // 0x80801814: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080183C;
    }
    // 0x80801814: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801818: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x8080181C: beq         $a1, $at, L_80801884
    if (ctx->r5 == ctx->r1) {
        // 0x80801820: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80801884;
    }
    // 0x80801820: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801824: beq         $a1, $at, L_80801898
    if (ctx->r5 == ctx->r1) {
        // 0x80801828: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80801898;
    }
    // 0x80801828: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080182C: beq         $a1, $at, L_808018C4
    if (ctx->r5 == ctx->r1) {
        // 0x80801830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018C4;
    }
    // 0x80801830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801834: b           L_808018F8
    // 0x80801838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808018F8;
    // 0x80801838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080183C:
    // 0x8080183C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80801840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801844: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801848: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080184C: nop

    // 0x80801850: bc1fl       L_808018F8
    if (!c1cs) {
        // 0x80801854: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808018F8;
    }
    goto skip_0;
    // 0x80801854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801858: jal         0x80800068
    // 0x8080185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_chnewfreezy(rdram, ctx);
        goto after_0;
    // 0x8080185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801860: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801864: jal         0x80089B90
    // 0x80801868: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sufreezy_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80801868: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080186C: jal         0x808000D4
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000D4_chnewfreezy(rdram, ctx);
        goto after_2;
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801874: jal         0x808000AC
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_chnewfreezy(rdram, ctx);
        goto after_3;
    // 0x80801878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080187C: b           L_808018F8
    // 0x80801880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018F8;
    // 0x80801880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801884:
    // 0x80801884: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801888: jal         0x80089B98
    // 0x8080188C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sufreezy_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080188C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80801890: b           L_808018F8
    // 0x80801894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018F8;
    // 0x80801894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801898:
    // 0x80801898: jal         0x80800068
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_chnewfreezy(rdram, ctx);
        goto after_5;
    // 0x8080189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808018A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808018A4: jal         0x80089BA0
    // 0x808018A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sufreezy_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808018A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808018AC: jal         0x808000D4
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000D4_chnewfreezy(rdram, ctx);
        goto after_7;
    // 0x808018B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808018B4: jal         0x808000AC
    // 0x808018B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_chnewfreezy(rdram, ctx);
        goto after_8;
    // 0x808018B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808018BC: b           L_808018F8
    // 0x808018C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018F8;
    // 0x808018C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018C4:
    // 0x808018C4: jal         0x80100094
    // 0x808018C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808018C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808018CC: jal         0x8008A038
    // 0x808018D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808018D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x808018D4: bnel        $v0, $zero, L_808018F8
    if (ctx->r2 != 0) {
        // 0x808018D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808018F8;
    }
    goto skip_1;
    // 0x808018D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808018DC: jal         0x800FFAB0
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x808018E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808018E4: b           L_808018F8
    // 0x808018E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018F8;
    // 0x808018E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808018EC: b           L_808018F8
    // 0x808018F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808018F8;
    // 0x808018F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808018F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018F8:
    // 0x808018F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801904: jr          $ra
    // 0x80801908: nop

    return;
    // 0x80801908: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083960: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083960);
    return;
    // 0x80083964: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsdronewaitbabykaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x8009E6EC
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80800070: bne         $at, $zero, L_8080009C
    if (ctx->r1 != 0) {
        // 0x80800074: addiu       $t7, $v0, -0x15
        ctx->r15 = ADD32(ctx->r2, -0X15);
            goto L_8080009C;
    }
    // 0x80800074: addiu       $t7, $v0, -0x15
    ctx->r15 = ADD32(ctx->r2, -0X15);
    // 0x80800078: addiu       $t6, $v0, -0x4E
    ctx->r14 = ADD32(ctx->r2, -0X4E);
    // 0x8080007C: sltiu       $at, $t6, 0x1E
    ctx->r1 = ctx->r14 < 0X1E ? 1 : 0;
    // 0x80800080: beq         $at, $zero, L_80800104
    if (ctx->r1 == 0) {
        // 0x80800084: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800104;
    }
    // 0x80800084: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(204, 0X170) << 16);
    // 0x8080008C: addu        $at, $at, $t6
    gpr jr_addend_80800094 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800090: lw          $t6, 0x170($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(204, 0X170));
    // 0x80800094: jr          $t6
    // 0x80800098: nop

    switch (jr_addend_80800094 >> 2) {
        case 0: goto L_808000BC; break;
        case 1: goto L_80800104; break;
        case 2: goto L_80800104; break;
        case 3: goto L_808000BC; break;
        case 4: goto L_808000BC; break;
        case 5: goto L_80800104; break;
        case 6: goto L_80800104; break;
        case 7: goto L_80800104; break;
        case 8: goto L_80800104; break;
        case 9: goto L_80800104; break;
        case 10: goto L_80800104; break;
        case 11: goto L_808000BC; break;
        case 12: goto L_808000BC; break;
        case 13: goto L_808000BC; break;
        case 14: goto L_808000BC; break;
        case 15: goto L_80800104; break;
        case 16: goto L_80800104; break;
        case 17: goto L_80800104; break;
        case 18: goto L_80800104; break;
        case 19: goto L_80800104; break;
        case 20: goto L_80800104; break;
        case 21: goto L_80800104; break;
        case 22: goto L_80800104; break;
        case 23: goto L_80800104; break;
        case 24: goto L_80800104; break;
        case 25: goto L_80800104; break;
        case 26: goto L_80800104; break;
        case 27: goto L_80800104; break;
        case 28: goto L_80800104; break;
        case 29: goto L_808000F4; break;
        default: switch_error(__func__, 0x80800094, 0x80800170);
    }
    // 0x80800098: nop

L_8080009C:
    // 0x8080009C: sltiu       $at, $t7, 0x1B
    ctx->r1 = ctx->r15 < 0X1B ? 1 : 0;
    // 0x808000A0: beq         $at, $zero, L_80800104
    if (ctx->r1 == 0) {
        // 0x808000A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800104;
    }
    // 0x808000A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(204, 0X1E8) << 16);
    // 0x808000AC: addu        $at, $at, $t7
    gpr jr_addend_808000B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000B0: lw          $t7, 0x1E8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(204, 0X1E8));
    // 0x808000B4: jr          $t7
    // 0x808000B8: nop

    switch (jr_addend_808000B4 >> 2) {
        case 0: goto L_8080010C; break;
        case 1: goto L_80800104; break;
        case 2: goto L_80800104; break;
        case 3: goto L_80800104; break;
        case 4: goto L_80800104; break;
        case 5: goto L_80800104; break;
        case 6: goto L_80800104; break;
        case 7: goto L_8080010C; break;
        case 8: goto L_8080010C; break;
        case 9: goto L_8080010C; break;
        case 10: goto L_80800104; break;
        case 11: goto L_808000BC; break;
        case 12: goto L_808000BC; break;
        case 13: goto L_80800104; break;
        case 14: goto L_80800104; break;
        case 15: goto L_808000BC; break;
        case 16: goto L_80800104; break;
        case 17: goto L_80800104; break;
        case 18: goto L_80800104; break;
        case 19: goto L_80800104; break;
        case 20: goto L_80800104; break;
        case 21: goto L_80800104; break;
        case 22: goto L_80800104; break;
        case 23: goto L_80800104; break;
        case 24: goto L_808000BC; break;
        case 25: goto L_808000BC; break;
        case 26: goto L_808000BC; break;
        default: switch_error(__func__, 0x808000B4, 0x808001E8);
    }
    // 0x808000B8: nop

L_808000BC:
    // 0x808000BC: jal         0x80099B94
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000C4: jal         0x800878A0
    // 0x808000C8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_2:
    // 0x808000CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000D0: beq         $v0, $at, L_808000E0
    if (ctx->r2 == ctx->r1) {
        // 0x808000D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000E0;
    }
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D8: jal         0x800F7B9C
    // 0x808000DC: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    func_800F7B9C(rdram, ctx);
        goto after_3;
    // 0x808000DC: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    after_3:
L_808000E0:
    // 0x808000E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: jal         0x8009E830
    // 0x808000E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x808000E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000EC: b           L_80800110
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F4:
    // 0x808000F4: jal         0x80099B94
    // 0x808000F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_5;
    // 0x808000F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x808000FC: b           L_80800110
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800110;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800104:
    // 0x80800104: jal         0x80099B94
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_6;
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
L_8080010C:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800110:
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void func_80800290_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080029C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002A0: jal         0x8008CAC8
    // 0x808002A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    baanim_getTimer(rdram, ctx);
        goto after_0;
    // 0x808002A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808002A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B4: jal         0x8008CC34
    // 0x808002B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_1;
    // 0x808002B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void subaddiefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080045C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800460: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80800464: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80800468: beql        $t7, $zero, L_808004C4
    if (ctx->r15 == 0) {
        // 0x8080046C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004C4;
    }
    goto skip_0;
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800470: jal         0x80104118
    // 0x80800474: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80104118(rdram, ctx);
        goto after_0;
    // 0x80800474: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800478: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080047C: lbu         $t8, 0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3);
    // 0x80800480: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80800484: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x80800488: andi        $t9, $t8, 0xFFFC
    ctx->r25 = ctx->r24 & 0XFFFC;
    // 0x8080048C: sb          $t9, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r25;
    // 0x80800490: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x80800494: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x80800498: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8080049C: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x808004A0: lh          $t2, 0xE($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XE);
    // 0x808004A4: bnel        $t2, $zero, L_808004C4
    if (ctx->r10 != 0) {
        // 0x808004A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004C4;
    }
    goto skip_1;
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808004AC: lbu         $a0, 0xC($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XC);
    // 0x808004B0: jal         0x80089D48
    // 0x808004B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808004B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808004B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808004BC: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004C4:
    // 0x808004C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void func_80801CEC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801CF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801CF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801CFC: lwc1        $f14, 0x48($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80801D00: jal         0x800F1DCC
    // 0x80801D04: lwc1        $f12, 0x54($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X54);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x80801D04: lwc1        $f12, 0x54($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X54);
    after_0:
    // 0x80801D08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801D0C: jal         0x80801A4C
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A4C_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801D14: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801D18: jal         0x800F1DCC
    // 0x80801D1C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x80801D1C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80801D20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801D24: jal         0x80801A4C
    // 0x80801D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A4C_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80801D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D38: jr          $ra
    // 0x80801D3C: nop

    return;
    // 0x80801D3C: nop

;}
RECOMP_FUNC void func_800DAE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAE9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800DAEA0: lbu         $v1, 0x762C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X762C);
    // 0x800DAEA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DAEA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DAEAC: jal         0x800A8184
    // 0x800DAEB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800A8184(rdram, ctx);
        goto after_0;
    // 0x800DAEB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800DAEB4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800DAEB8: beq         $v0, $at, L_800DAFB4
    if (ctx->r2 == ctx->r1) {
        // 0x800DAEBC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800DAFB4;
    }
    // 0x800DAEBC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800DAEC0: jal         0x80090128
    // 0x800DAEC4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80090128(rdram, ctx);
        goto after_1;
    // 0x800DAEC4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800DAEC8: beq         $v0, $zero, L_800DAFB4
    if (ctx->r2 == 0) {
        // 0x800DAECC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800DAFB4;
    }
    // 0x800DAECC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800DAED0: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
    // 0x800DAED4: bne         $at, $zero, L_800DAFB4
    if (ctx->r1 != 0) {
        // 0x800DAED8: slti        $at, $v1, 0x1C
        ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
            goto L_800DAFB4;
    }
    // 0x800DAED8: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x800DAEDC: beq         $at, $zero, L_800DAFB4
    if (ctx->r1 == 0) {
        // 0x800DAEE0: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800DAFB4;
    }
    // 0x800DAEE0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800DAEE4: beql        $v1, $at, L_800DAFB8
    if (ctx->r3 == ctx->r1) {
        // 0x800DAEE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DAFB8;
    }
    goto skip_0;
    // 0x800DAEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DAEEC: jal         0x800D9004
    // 0x800DAEF0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800D9004(rdram, ctx);
        goto after_2;
    // 0x800DAEF0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x800DAEF4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800DAEF8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DAEFC: addiu       $t7, $t7, -0x3860
    ctx->r15 = ADD32(ctx->r15, -0X3860);
    // 0x800DAF00: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800DAF04: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800DAF08: lwc1        $f4, -0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X38);
    // 0x800DAF0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DAF10: lwc1        $f12, 0x5D44($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5D44);
    // 0x800DAF14: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800DAF18: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800DAF1C: nop

    // 0x800DAF20: bc1f        L_800DAF30
    if (!c1cs) {
        // 0x800DAF24: nop
    
            goto L_800DAF30;
    }
    // 0x800DAF24: nop

    // 0x800DAF28: b           L_800DAF44
    // 0x800DAF2C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800DAF44;
    // 0x800DAF2C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800DAF30:
    // 0x800DAF30: jal         0x800D9004
    // 0x800DAF34: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D9004(rdram, ctx);
        goto after_3;
    // 0x800DAF34: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x800DAF38: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800DAF3C: lwc1        $f8, -0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X38);
    // 0x800DAF40: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
L_800DAF44:
    // 0x800DAF44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DAF48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800DAF4C: nop

    // 0x800DAF50: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800DAF54: nop

    // 0x800DAF58: bc1f        L_800DAF68
    if (!c1cs) {
        // 0x800DAF5C: nop
    
            goto L_800DAF68;
    }
    // 0x800DAF5C: nop

    // 0x800DAF60: b           L_800DAFB4
    // 0x800DAF64: swc1        $f0, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->f0.u32l;
        goto L_800DAFB4;
    // 0x800DAF64: swc1        $f0, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->f0.u32l;
L_800DAF68:
    // 0x800DAF68: jal         0x800D9004
    // 0x800DAF6C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D9004(rdram, ctx);
        goto after_4;
    // 0x800DAF6C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_4:
    // 0x800DAF70: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800DAF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DAF78: lwc1        $f12, 0x5D4C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5D4C);
    // 0x800DAF7C: lwc1        $f10, -0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X38);
    // 0x800DAF80: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800DAF84: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800DAF88: nop

    // 0x800DAF8C: bc1f        L_800DAF9C
    if (!c1cs) {
        // 0x800DAF90: nop
    
            goto L_800DAF9C;
    }
    // 0x800DAF90: nop

    // 0x800DAF94: b           L_800DAFB0
    // 0x800DAF98: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800DAFB0;
    // 0x800DAF98: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800DAF9C:
    // 0x800DAF9C: jal         0x800D9004
    // 0x800DAFA0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D9004(rdram, ctx);
        goto after_5;
    // 0x800DAFA0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x800DAFA4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800DAFA8: lwc1        $f18, -0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X38);
    // 0x800DAFAC: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
L_800DAFB0:
    // 0x800DAFB0: swc1        $f2, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->f2.u32l;
L_800DAFB4:
    // 0x800DAFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DAFB8:
    // 0x800DAFB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DAFBC: jr          $ra
    // 0x800DAFC0: nop

    return;
    // 0x800DAFC0: nop

;}
RECOMP_FUNC void func_800A5B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5B6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5B70: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5B74: jr          $ra
    // 0x800A5B78: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    return;
    // 0x800A5B78: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
;}
RECOMP_FUNC void func_800C68DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C68E0: jr          $ra
    // 0x800C68E4: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
    return;
    // 0x800C68E4: sb          $t6, 0x93($a0)
    MEM_B(0X93, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8080000C_chproplighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800010: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800014: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800018: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080001C: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x80800020: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800024: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800028: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8080002C: jal         0x800EE904
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800034: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x80800038: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800044: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800048: jal         0x800882F8
    // 0x8080004C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80800050: beq         $v0, $zero, L_80800160
    if (ctx->r2 == 0) {
        // 0x80800054: lw          $s0, 0x40($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X40);
            goto L_80800160;
    }
    // 0x80800054: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800058: lbu         $t9, 0xB($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XB);
    // 0x8080005C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800060: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80800064: sb          $t1, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r9;
    // 0x80800068: andi        $t2, $t1, 0xEF
    ctx->r10 = ctx->r9 & 0XEF;
    // 0x8080006C: sb          $t2, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r10;
    // 0x80800070: jal         0x800EE88C
    // 0x80800074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800078: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    // 0x8080007C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800080: bgez        $t3, L_80800098
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800084: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800098;
    }
    // 0x80800084: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800088: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080008C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800090: nop

    // 0x80800094: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80800098:
    // 0x80800098: jal         0x800136E4
    // 0x8080009C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x8080009C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_3:
    // 0x808000A0: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x808000A4: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x808000A8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x808000AC: bgez        $t4, L_808000C4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808000B0: cvt.s.w     $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808000C4;
    }
    // 0x808000B0: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000BC: nop

    // 0x808000C0: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_808000C4:
    // 0x808000C4: jal         0x800136E4
    // 0x808000C8: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x808000C8: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    after_4:
    // 0x808000CC: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x808000D0: jal         0x80088C88
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000DC: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x808000E0: jal         0x80103140
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_6;
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808000E8: lbu         $t5, 0xA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA);
    // 0x808000EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000F4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x808000F8: bgez        $t5, L_8080010C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808000FC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080010C;
    }
    // 0x808000FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800104: nop

    // 0x80800108: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8080010C:
    // 0x8080010C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1316, 0X190) << 16);
    // 0x80800110: lwc1        $f6, 0x190($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1316, 0X190));
    // 0x80800114: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800118: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080011C: jal         0x80102FDC
    // 0x80800120: nop

    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x80800120: nop

    after_7:
    // 0x80800124: jal         0x80103014
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103014(rdram, ctx);
        goto after_8;
    // 0x80800128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800130: jal         0x80108944
    // 0x80800134: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80108944(rdram, ctx);
        goto after_9;
    // 0x80800134: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80800138: jal         0x80105010
    // 0x8080013C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80105010(rdram, ctx);
        goto after_10;
    // 0x8080013C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800140: bne         $v0, $zero, L_80800150
    if (ctx->r2 != 0) {
        // 0x80800144: nop
    
            goto L_80800150;
    }
    // 0x80800144: nop

    // 0x80800148: jal         0x80104E78
    // 0x8080014C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80104E78(rdram, ctx);
        goto after_11;
    // 0x8080014C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
L_80800150:
    // 0x80800150: jal         0x8010A63C
    // 0x80800154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A63C(rdram, ctx);
        goto after_12;
    // 0x80800154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800158: b           L_8080016C
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080016C;
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800160:
    // 0x80800160: jal         0x800FFAB0
    // 0x80800164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x80800164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080016C:
    // 0x8080016C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800178: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800E24E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E24E8: addiu       $v0, $v0, -0x2B90
    ctx->r2 = ADD32(ctx->r2, -0X2B90);
    // 0x800E24EC: sw          $a0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r4;
    // 0x800E24F0: jr          $ra
    // 0x800E24F4: sw          $a1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r5;
    return;
    // 0x800E24F4: sw          $a1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void aligned8_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E70: srl         $t0, $a2, 3
    ctx->r8 = S32(U32(ctx->r6) >> 3);
    // 0x80019E74: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80019E78: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
L_80019E7C:
    // 0x80019E7C: ld          $t1, 0x0($a1)
    ctx->r9 = LD(ctx->r5, 0X0);
    // 0x80019E80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80019E84: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80019E88: bne         $t0, $a0, L_80019E7C
    if (ctx->r8 != ctx->r4) {
        // 0x80019E8C: sd          $t1, -0x8($a0)
        SD(ctx->r9, -0X8, ctx->r4);
            goto L_80019E7C;
    }
    // 0x80019E8C: sd          $t1, -0x8($a0)
    SD(ctx->r9, -0X8, ctx->r4);
    // 0x80019E90: jr          $ra
    // 0x80019E94: nop

    return;
    // 0x80019E94: nop

;}
RECOMP_FUNC void baflameline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x808002B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808002BC: lbu         $a0, 0x20($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X20);
    // 0x808002C0: jal         0x800C2FDC
    // 0x808002C4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x808002C4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x808002D0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x808002D4: beq         $a0, $zero, L_808002F4
    if (ctx->r4 == 0) {
        // 0x808002D8: nop
    
            goto L_808002F4;
    }
    // 0x808002D8: nop

    // 0x808002DC: jal         0x800C8B84
    // 0x808002E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x808002E0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x808002E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808002E8: lw          $t7, 0x84($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X84);
    // 0x808002EC: sw          $zero, 0x24($t7)
    MEM_W(0X24, ctx->r15) = 0;
    // 0x808002F0: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
L_808002F4:
    // 0x808002F4: jal         0x800B5450
    // 0x808002F8: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    func_800B5450(rdram, ctx);
        goto after_2;
    // 0x808002F8: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
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
RECOMP_FUNC void func_8080090C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: jr          $ra
    // 0x80800910: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800910: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8010D23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D23C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010D240: jr          $ra
    // 0x8010D244: lh          $v0, 0x6F5C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6F5C);
    return;
    // 0x8010D244: lh          $v0, 0x6F5C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6F5C);
;}
RECOMP_FUNC void func_808001AC_chgobicommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808001B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X200) << 16);
    // 0x808001BC: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x808001C0: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808001C4: addiu       $a2, $a2, 0x200
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X200));
    // 0x808001C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001CC: jal         0x80089D20
    // 0x808001D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808001D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1448, 0X210) << 16);
    // 0x808001D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E0: addiu       $a2, $a2, 0x210
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1448, 0X210));
    // 0x808001E4: jal         0x80089D20
    // 0x808001E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808001E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

    // 0x808001FC: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001EC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x808001F0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x808001F4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808001F8: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x808001FC: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80800200: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x80800204: jal         0x8001B208
    // 0x80800208: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x80800208: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080020C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800210: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800214: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80800218: jal         0x80800000
    // 0x8080021C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    gsmaker_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080021C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    after_1:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_800C75C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C75C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C75C8: jal         0x800C77DC
    // 0x800C75CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_0;
    // 0x800C75CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C75D0: jal         0x800FC81C
    // 0x800C75D4: nop

    func_800FC81C(rdram, ctx);
        goto after_1;
    // 0x800C75D4: nop

    after_1:
    // 0x800C75D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C75DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C75E0: jr          $ra
    // 0x800C75E4: nop

    return;
    // 0x800C75E4: nop

;}
RECOMP_FUNC void func_80090768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090770: jal         0x800F54E4
    // 0x80090774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090778: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009077C: jal         0x800F83B8
    // 0x80090780: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F83B8(rdram, ctx);
        goto after_1;
    // 0x80090780: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009078C: jr          $ra
    // 0x80090790: nop

    return;
    // 0x80090790: nop

;}
RECOMP_FUNC void func_8080003C_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80800040: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800048: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x8080004C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800050: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80800054: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80800058: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8080005C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80800060: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800064: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800068: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8080006C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800070: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800074: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800078: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8080007C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800080: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800084: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800088: jal         0x80100094
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800090: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800094: jal         0x801039E4
    // 0x80800098: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_1:
    // 0x8080009C: lw          $t6, 0x6C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X6C);
    // 0x808000A0: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x808000A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808000A8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808000AC: beq         $t7, $zero, L_808001D0
    if (ctx->r15 == 0) {
        // 0x808000B0: addiu       $s3, $s1, 0x1C
        ctx->r19 = ADD32(ctx->r17, 0X1C);
            goto L_808001D0;
    }
    // 0x808000B0: addiu       $s3, $s1, 0x1C
    ctx->r19 = ADD32(ctx->r17, 0X1C);
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1A90) << 16);
    // 0x808000B8: lwc1        $f30, 0x1A90($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1A90));
    // 0x808000BC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808000C0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1A94) << 16);
    // 0x808000C8: lwc1        $f26, 0x1A94($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1A94));
    // 0x808000CC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808000D0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808000D4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808000D8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808000DC: addiu       $fp, $s6, 0x4
    ctx->r30 = ADD32(ctx->r22, 0X4);
    // 0x808000E0: addiu       $s5, $sp, 0x98
    ctx->r21 = ADD32(ctx->r29, 0X98);
    // 0x808000E4: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x808000E8: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
L_808000EC:
    // 0x808000EC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808000F0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808000F4: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x808000F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808000FC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800100: jal         0x800EFA4C
    // 0x80800104: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800104: nop

    after_2:
    // 0x80800108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080010C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80800110: jal         0x800EE780
    // 0x80800114: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EE780(rdram, ctx);
        goto after_3;
    // 0x80800114: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_3:
    // 0x80800118: jal         0x800DF830
    // 0x8080011C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_4;
    // 0x8080011C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80800120: jal         0x800DF410
    // 0x80800124: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    func_800DF410(rdram, ctx);
        goto after_5;
    // 0x80800124: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_5:
    // 0x80800128: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8080012C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800130: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800134: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800138: jal         0x800DE448
    // 0x8080013C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_800DE448(rdram, ctx);
        goto after_6;
    // 0x8080013C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_6:
    // 0x80800140: jal         0x800DF350
    // 0x80800144: nop

    func_800DF350(rdram, ctx);
        goto after_7;
    // 0x80800144: nop

    after_7:
    // 0x80800148: lbu         $t8, 0x1($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1);
    // 0x8080014C: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x80800150: or          $t9, $t8, $v0
    ctx->r25 = ctx->r24 | ctx->r2;
    // 0x80800154: beq         $at, $zero, L_808001B4
    if (ctx->r1 == 0) {
        // 0x80800158: sb          $t9, 0x1($s1)
        MEM_B(0X1, ctx->r17) = ctx->r25;
            goto L_808001B4;
    }
    // 0x80800158: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x8080015C: jal         0x800D674C
    // 0x80800160: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    func_800D674C(rdram, ctx);
        goto after_8;
    // 0x80800160: addiu       $a0, $zero, 0x637
    ctx->r4 = ADD32(0, 0X637);
    after_8:
    // 0x80800164: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x80800168: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808001B4;
    }
    // 0x80800168: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080016C: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80800170: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80800174: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x80800178: jal         0x800DF410
    // 0x8080017C: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    func_800DF410(rdram, ctx);
        goto after_9;
    // 0x8080017C: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80800180: jal         0x800DF830
    // 0x80800184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_10;
    // 0x80800184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80800188: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x8080018C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800190: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800198: jal         0x800DE448
    // 0x8080019C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800DE448(rdram, ctx);
        goto after_11;
    // 0x8080019C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_11:
    // 0x808001A0: jal         0x800DF350
    // 0x808001A4: nop

    func_800DF350(rdram, ctx);
        goto after_12;
    // 0x808001A4: nop

    after_12:
    // 0x808001A8: lbu         $t0, 0x1($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1);
    // 0x808001AC: or          $t1, $t0, $v0
    ctx->r9 = ctx->r8 | ctx->r2;
    // 0x808001B0: sb          $t1, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r9;
L_808001B4:
    // 0x808001B4: lw          $t2, 0x6C($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X6C);
    // 0x808001B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808001BC: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
    // 0x808001C0: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x808001C4: sltu        $at, $s2, $t3
    ctx->r1 = ctx->r18 < ctx->r11 ? 1 : 0;
    // 0x808001C8: bnel        $at, $zero, L_808000EC
    if (ctx->r1 != 0) {
        // 0x808001CC: lwc1        $f4, 0x28($s3)
        ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
            goto L_808000EC;
    }
    goto skip_0;
    // 0x808001CC: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    skip_0:
L_808001D0:
    // 0x808001D0: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x808001D4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808001D8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808001DC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808001E0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x808001E4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808001E8: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x808001EC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x808001F0: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x808001F4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x808001F8: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x808001FC: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800200: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80800204: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80800208: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8080020C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80800210: jr          $ra
    // 0x80800214: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800214: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_800D0B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0B10: jal         0x800D0908
    // 0x800D0B14: nop

    func_800D0908(rdram, ctx);
        goto after_0;
    // 0x800D0B14: nop

    after_0:
    // 0x800D0B18: beq         $v0, $zero, L_800D0B28
    if (ctx->r2 == 0) {
        // 0x800D0B1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0B28;
    }
    // 0x800D0B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0B20: jal         0x800DA544
    // 0x800D0B24: nop

    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x800D0B24: nop

    after_1:
L_800D0B28:
    // 0x800D0B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0B30: jr          $ra
    // 0x800D0B34: nop

    return;
    // 0x800D0B34: nop

;}
RECOMP_FUNC void chblink_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800238: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8080023C: jal         0x8001B798
    // 0x80800240: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800240: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x80800244: jal         0x800D8FF8
    // 0x80800248: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800248: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080024C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(692, 0X430) << 16);
    // 0x80800250: addiu       $a1, $a1, 0x430
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(692, 0X430));
    // 0x80800254: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080025C: jal         0x80800118
    // 0x80800260: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80800118_chblink(rdram, ctx);
        goto after_2;
    // 0x80800260: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800264: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800268: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8080026C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800270: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800274: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80800278:
    // 0x80800278: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080027C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800280: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800284: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80800288: nop

    // 0x8080028C: bc1t        L_808002F0
    if (c1cs) {
        // 0x80800290: nop
    
            goto L_808002F0;
    }
    // 0x80800290: nop

    // 0x80800294: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800298: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8080029C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808002A0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808002A4: bc1f        L_808002C4
    if (!c1cs) {
        // 0x808002A8: swc1        $f8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
            goto L_808002C4;
    }
    // 0x808002A8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x808002AC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808002B0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808002B4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808002B8: nop

    // 0x808002BC: bc1tl       L_808002F0
    if (c1cs) {
        // 0x808002C0: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_808002F0;
    }
    goto skip_0;
    // 0x808002C0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_0:
L_808002C4:
    // 0x808002C4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x808002C8: nop

    // 0x808002CC: bc1f        L_808002F0
    if (!c1cs) {
        // 0x808002D0: nop
    
            goto L_808002F0;
    }
    // 0x808002D0: nop

    // 0x808002D4: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808002D8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808002DC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808002E0: nop

    // 0x808002E4: bc1f        L_808002F0
    if (!c1cs) {
        // 0x808002E8: nop
    
            goto L_808002F0;
    }
    // 0x808002E8: nop

    // 0x808002EC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_808002F0:
    // 0x808002F0: bne         $v1, $a0, L_80800278
    if (ctx->r3 != ctx->r4) {
        // 0x808002F4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800278;
    }
    // 0x808002F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808002F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800300: jr          $ra
    // 0x80800304: nop

    return;
    // 0x80800304: nop

;}
RECOMP_FUNC void func_800F3E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3E8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F3E90: jal         0x8009BFCC
    // 0x800F3E94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x800F3E94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F3E98: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3E9C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x800F3EA0: jal         0x8009C984
    // 0x800F3EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x800F3EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F3EA8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3EAC: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x800F3EB0: jal         0x8009C53C
    // 0x800F3EB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baroll_get(rdram, ctx);
        goto after_2;
    // 0x800F3EB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800F3EB8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3EBC: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x800F3EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3EC8: jr          $ra
    // 0x800F3ECC: nop

    return;
    // 0x800F3ECC: nop

;}
RECOMP_FUNC void func_80801008_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080100C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801014: jal         0x8080081C
    // 0x80801018: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801018: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080101C: jal         0x80084600
    // 0x80801020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80801020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801024: beq         $v0, $zero, L_80801030
    if (ctx->r2 == 0) {
        // 0x80801028: addiu       $t6, $zero, 0x151
        ctx->r14 = ADD32(0, 0X151);
            goto L_80801030;
    }
    // 0x80801028: addiu       $t6, $zero, 0x151
    ctx->r14 = ADD32(0, 0X151);
    // 0x8080102C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801030:
    // 0x80801030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801034: jal         0x8009E5C8
    // 0x80801038: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80801038: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8080103C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801040: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801044: jr          $ra
    // 0x80801048: nop

    return;
    // 0x80801048: nop

;}
RECOMP_FUNC void baeggaim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800380: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800388: jal         0x80084C88
    // 0x8080038C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bafpctrl_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080038C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800390: bnel        $v0, $zero, L_808003A4
    if (ctx->r2 != 0) {
        // 0x80800394: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A4;
    }
    goto skip_0;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800398: jal         0x80094AB4
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094AB4(rdram, ctx);
        goto after_1;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003A4:
    // 0x808003A4: jal         0x808000B4
    // 0x808003A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_808000B4_baeggaim(rdram, ctx);
        goto after_2;
    // 0x808003A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: jal         0x80095738
    // 0x808003B4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    baflag_isTrue(rdram, ctx);
        goto after_3;
    // 0x808003B4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_3:
    // 0x808003B8: bnel        $v0, $zero, L_808003DC
    if (ctx->r2 != 0) {
        // 0x808003BC: sw          $zero, 0x24($sp)
        MEM_W(0X24, ctx->r29) = 0;
            goto L_808003DC;
    }
    goto skip_1;
    // 0x808003BC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    skip_1:
    // 0x808003C0: jal         0x80084C80
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003C8: bne         $v0, $zero, L_808003D8
    if (ctx->r2 != 0) {
        // 0x808003CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D8;
    }
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80800264
    // 0x808003D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80800264_baeggaim(rdram, ctx);
        goto after_5;
    // 0x808003D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
L_808003D8:
    // 0x808003D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_808003DC:
    // 0x808003DC: jal         0x80094510
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_6;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808003E8: bne         $v0, $at, L_8080040C
    if (ctx->r2 != ctx->r1) {
        // 0x808003EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080040C;
    }
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x800919F4
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_7;
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808003FC: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x80800400: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800420;
    }
    // 0x80800400: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800404: b           L_80800420
    // 0x80800408: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800420;
    // 0x80800408: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080040C:
    // 0x8080040C: jal         0x80091A58
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800414: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x80800418: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800420;
    }
    // 0x80800418: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080041C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800420:
    // 0x80800420: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800424: beq         $t8, $zero, L_80800454
    if (ctx->r24 == 0) {
        // 0x80800428: nop
    
            goto L_80800454;
    }
    // 0x80800428: nop

    // 0x8080042C: jal         0x80084C88
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800434: bne         $v0, $zero, L_80800454
    if (ctx->r2 != 0) {
        // 0x80800438: nop
    
            goto L_80800454;
    }
    // 0x80800438: nop

    // 0x8080043C: jal         0x80094B14
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_10;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800444: beq         $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x80800448: nop
    
            goto L_80800454;
    }
    // 0x80800448: nop

    // 0x8080044C: jal         0x80084B48
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggfire_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80800454:
    // 0x80800454: jal         0x80084B40
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggfire_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080045C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800464: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800468: jr          $ra
    // 0x8080046C: nop

    return;
    // 0x8080046C: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858F0: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858F0);
    return;
    // 0x800858F4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800FA4_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FAC: jal         0x8080016C
    // 0x80800FB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800FB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FB4: jal         0x800A042C
    // 0x80800FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A042C(rdram, ctx);
        goto after_1;
    // 0x80800FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800FBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FC0: jal         0x80093360
    // 0x80800FC4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093360(rdram, ctx);
        goto after_2;
    // 0x80800FC4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800FC8: jal         0x8009E0DC
    // 0x80800FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009E0DC(rdram, ctx);
        goto after_3;
    // 0x80800FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FD8: jr          $ra
    // 0x80800FDC: nop

    return;
    // 0x80800FDC: nop

;}
RECOMP_FUNC void func_800E09B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E09B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E09BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E09C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800E09C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E09C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800E09CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800E09D0: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800E09D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E09D8: jal         0x8001B668
    // 0x800E09DC: addiu       $a1, $t6, 0x20
    ctx->r5 = ADD32(ctx->r14, 0X20);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x800E09DC: addiu       $a1, $t6, 0x20
    ctx->r5 = ADD32(ctx->r14, 0X20);
    after_0:
    // 0x800E09E0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800E09E4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800E09E8: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x800E09EC: jal         0x800E0A28
    // 0x800E09F0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800E0A28(rdram, ctx);
        goto after_1;
    // 0x800E09F0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800E09F4: addiu       $t8, $v0, 0x20
    ctx->r24 = ADD32(ctx->r2, 0X20);
    // 0x800E09F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800E09FC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800E0A00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E0A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E0A08: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800E0A0C: jal         0x800E0ACC
    // 0x800E0A10: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    func_800E0ACC(rdram, ctx);
        goto after_2;
    // 0x800E0A10: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x800E0A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0A18: lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A);
    // 0x800E0A1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E0A20: jr          $ra
    // 0x800E0A24: nop

    return;
    // 0x800E0A24: nop

;}
RECOMP_FUNC void func_80800A50_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A60: jal         0x80100094
    // 0x80800A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A68: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A6C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800A70: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800A74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800A78: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800A7C: bgez        $t8, L_80800AD8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800A80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AD8;
    }
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: jal         0x80089BF0
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A8C: lui         $a1, 0x3DF5
    ctx->r5 = S32(0X3DF5 << 16);
    // 0x80800A90: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800A94: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A9C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80800AA0: jal         0x80102BF8
    // 0x80800AA4: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_2;
    // 0x80800AA4: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_2:
    // 0x80800AA8: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800AAC: ori         $a1, $a1, 0x25
    ctx->r5 = ctx->r5 | 0X25;
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB4: jal         0x8010C3A8
    // 0x80800AB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8010C3A8(rdram, ctx);
        goto after_3;
    // 0x80800AB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: addiu       $a1, $zero, 0x4004
    ctx->r5 = ADD32(0, 0X4004);
    // 0x80800AC4: jal         0x8010B990
    // 0x80800AC8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8010B990(rdram, ctx);
        goto after_4;
    // 0x80800AC8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800ACC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800AD0: b           L_80800B48
    // 0x80800AD4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
        goto L_80800B48;
    // 0x80800AD4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80800AD8:
    // 0x80800AD8: jal         0x80102D78
    // 0x80800ADC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_5;
    // 0x80800ADC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80800AE0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800AE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AE8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800AEC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800AF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800AF4: addiu       $t9, $zero, 0x5000
    ctx->r25 = ADD32(0, 0X5000);
    // 0x80800AF8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800AFC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: jal         0x80089F90
    // 0x80800B08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800B08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800B0C: lui         $a1, 0x3DF5
    ctx->r5 = S32(0X3DF5 << 16);
    // 0x80800B10: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80800B1C: jal         0x80102BF8
    // 0x80800B20: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_7;
    // 0x80800B20: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_7:
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: jal         0x8010B990
    // 0x80800B2C: addiu       $a1, $zero, 0x325
    ctx->r5 = ADD32(0, 0X325);
    func_8010B990(rdram, ctx);
        goto after_8;
    // 0x80800B2C: addiu       $a1, $zero, 0x325
    ctx->r5 = ADD32(0, 0X325);
    after_8:
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B34: addiu       $a1, $zero, 0x4004
    ctx->r5 = ADD32(0, 0X4004);
    // 0x80800B38: jal         0x8010B990
    // 0x80800B3C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8010B990(rdram, ctx);
        goto after_9;
    // 0x80800B3C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_9:
    // 0x80800B40: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800B44: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80800B48:
    // 0x80800B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B50: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800B54: jr          $ra
    // 0x80800B58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800B58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _chattract_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C00: syscall     208
    recomp_syscall_handler(rdram, ctx, 0x80085C00);
    return;
    // 0x80085C04: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808011A4_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808011A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808011AC: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x808011B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808011B8: jal         0x8009E154
    // 0x808011BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009E154(rdram, ctx);
        goto after_0;
    // 0x808011BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011C0: jal         0x800B5BE4
    // 0x808011C4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_800B5BE4(rdram, ctx);
        goto after_1;
    // 0x808011C4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_1:
    // 0x808011C8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(296, 0X17F4) << 16);
    // 0x808011CC: addiu       $t6, $t6, 0x17F4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(296, 0X17F4));
    // 0x808011D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808011D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808011DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808011E0: jal         0x800BABB8
    // 0x808011E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808011E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808011E8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(296, 0X1824) << 16);
    // 0x808011EC: addiu       $t7, $t7, 0x1824
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(296, 0X1824));
    // 0x808011F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808011F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808011FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801200: jal         0x800BABB8
    // 0x80801204: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80801204: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80801208: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(296, 0X1854) << 16);
    // 0x8080120C: addiu       $t8, $t8, 0x1854
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(296, 0X1854));
    // 0x80801210: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801214: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080121C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801220: jal         0x800BABB8
    // 0x80801224: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80801224: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80801228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080122C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801230: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801234: jr          $ra
    // 0x80801238: nop

    return;
    // 0x80801238: nop

;}
RECOMP_FUNC void func_80805A00_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805A00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80805A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805A08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80805A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80805A10: jal         0x80100094
    // 0x80805A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805A18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80805A1C: jal         0x808027F4
    // 0x80805A20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808027F4_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80805A20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80805A24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80805A28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80805A2C: jal         0x80803BE8
    // 0x80805A30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80805A30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80805A34: jal         0x80802C0C
    // 0x80805A38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802C0C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80805A38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80805A3C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80805A40: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80805A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80805A48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80805A4C: sb          $t6, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r14;
    // 0x80805A50: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80805A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80805A5C: jr          $ra
    // 0x80805A60: nop

    return;
    // 0x80805A60: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084230: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084230);
    return;
    // 0x80084234: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088330: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088330);
    return;
    // 0x80088334: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800AEBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEBA8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AEBAC: beq         $a3, $zero, L_800AEBC4
    if (ctx->r7 == 0) {
        // 0x800AEBB0: sw          $ra, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r31;
            goto L_800AEBC4;
    }
    // 0x800AEBB0: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x800AEBB4: lbu         $t0, 0xA($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0XA);
    // 0x800AEBB8: bnel        $t0, $zero, L_800AEBC8
    if (ctx->r8 != 0) {
        // 0x800AEBBC: lwc1        $f21, 0x0($a1)
        ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r5, 0X0);
            goto L_800AEBC8;
    }
    goto skip_0;
    // 0x800AEBBC: lwc1        $f21, 0x0($a1)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x800AEBC0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
L_800AEBC4:
    // 0x800AEBC4: lwc1        $f21, 0x0($a1)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r5, 0X0);
L_800AEBC8:
    // 0x800AEBC8: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800AEBCC: addiu       $s1, $a1, 0x8
    ctx->r17 = ADD32(ctx->r5, 0X8);
    // 0x800AEBD0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800AEBD4: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800AEBD8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
L_800AEBDC:
    // 0x800AEBDC: lh          $t0, 0xE($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XE);
    // 0x800AEBE0: beql        $t7, $t0, L_800AEC70
    if (ctx->r15 == ctx->r8) {
        // 0x800AEBE4: lw          $t0, 0x30($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X30);
            goto L_800AEC70;
    }
    goto skip_1;
    // 0x800AEBE4: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
    skip_1:
    // 0x800AEBE8: or          $t7, $t0, $zero
    ctx->r15 = ctx->r8 | 0;
    // 0x800AEBEC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AEBF0: bnel        $t0, $zero, L_800AEC38
    if (ctx->r8 != 0) {
        // 0x800AEBF4: sll         $t0, $t7, 6
        ctx->r8 = S32(ctx->r15 << 6);
            goto L_800AEC38;
    }
    goto skip_2;
    // 0x800AEBF4: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
    skip_2:
    // 0x800AEBF8: lui         $t0, 0x3F80
    ctx->r8 = S32(0X3F80 << 16);
    // 0x800AEBFC: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x800AEC00: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800AEC04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800AEC08: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800AEC0C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800AEC10: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800AEC14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AEC18: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800AEC1C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800AEC20: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800AEC24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AEC28: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800AEC2C: b           L_800AEC70
    // 0x800AEC30: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
        goto L_800AEC70;
    // 0x800AEC30: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
    // 0x800AEC34: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
L_800AEC38:
    // 0x800AEC38: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800AEC3C: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AEC40: lwc1        $f1, 0x4($t0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r8, 0X4);
    // 0x800AEC44: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800AEC48: lwc1        $f3, 0x10($t0)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r8, 0X10);
    // 0x800AEC4C: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800AEC50: lwc1        $f5, 0x18($t0)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r8, 0X18);
    // 0x800AEC54: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800AEC58: lwc1        $f7, 0x24($t0)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r8, 0X24);
    // 0x800AEC5C: lwc1        $f8, 0x28($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X28);
    // 0x800AEC60: lwc1        $f9, 0x30($t0)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r8, 0X30);
    // 0x800AEC64: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x800AEC68: lwc1        $f11, 0x38($t0)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r8, 0X38);
    // 0x800AEC6C: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
L_800AEC70:
    // 0x800AEC70: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800AEC74: lwc1        $f13, 0x4($s1)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r17, 0X4);
    // 0x800AEC78: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800AEC7C: lwc1        $f15, 0x0($t0)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r8, 0X0);
    // 0x800AEC80: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800AEC84: beq         $a3, $zero, L_800AEC94
    if (ctx->r7 == 0) {
        // 0x800AEC88: lwc1        $f17, 0x8($t0)
        ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r8, 0X8);
            goto L_800AEC94;
    }
    // 0x800AEC88: lwc1        $f17, 0x8($t0)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r8, 0X8);
    // 0x800AEC8C: jal         0x800AF2F0
    // 0x800AEC90: nop

    func_800AF2F0(rdram, ctx);
        goto after_0;
    // 0x800AEC90: nop

    after_0:
L_800AEC94:
    // 0x800AEC94: mul.s       $f15, $f15, $f21
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f15.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f15.fl = MUL_S(ctx->f15.fl, ctx->f21.fl);
    // 0x800AEC98: or          $t7, $t8, $zero
    ctx->r15 = ctx->r24 | 0;
    // 0x800AEC9C: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x800AECA0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800AECA4: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x800AECA8: mul.s       $f16, $f16, $f21
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f21.fl);
    // 0x800AECAC: add.s       $f15, $f15, $f12
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f15.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f15.fl = ctx->f15.fl + ctx->f12.fl;
    // 0x800AECB0: mul.s       $f17, $f17, $f21
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f17.fl = MUL_S(ctx->f17.fl, ctx->f21.fl);
    // 0x800AECB4: add.s       $f16, $f16, $f13
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f13.fl;
    // 0x800AECB8: mul.s       $f0, $f0, $f15
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f15.fl);
    // 0x800AECBC: add.s       $f17, $f17, $f14
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f17.fl = ctx->f17.fl + ctx->f14.fl;
    // 0x800AECC0: mul.s       $f3, $f3, $f16
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f3.fl = MUL_S(ctx->f3.fl, ctx->f16.fl);
    // 0x800AECC4: nop

    // 0x800AECC8: mul.s       $f6, $f6, $f17
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f17.fl);
    // 0x800AECCC: add.s       $f9, $f9, $f0
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f9.fl = ctx->f9.fl + ctx->f0.fl;
    // 0x800AECD0: mul.s       $f1, $f1, $f15
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f1.fl = MUL_S(ctx->f1.fl, ctx->f15.fl);
    // 0x800AECD4: lwc1        $f0, -0x40($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, -0X40);
    // 0x800AECD8: mul.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AECDC: add.s       $f9, $f9, $f3
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 3);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f3.fl); 
    ctx->f9.fl = ctx->f9.fl + ctx->f3.fl;
    // 0x800AECE0: mul.s       $f7, $f7, $f17
    CHECK_FR(ctx, 7);
    CHECK_FR(ctx, 7);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f7.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f7.fl = MUL_S(ctx->f7.fl, ctx->f17.fl);
    // 0x800AECE4: nop

    // 0x800AECE8: mul.s       $f2, $f2, $f15
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f15.fl);
    // 0x800AECEC: lwc1        $f3, -0x30($s2)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r18, -0X30);
    // 0x800AECF0: add.s       $f9, $f9, $f6
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f9.fl = ctx->f9.fl + ctx->f6.fl;
    // 0x800AECF4: mul.s       $f5, $f5, $f16
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f5.fl = MUL_S(ctx->f5.fl, ctx->f16.fl);
    // 0x800AECF8: lwc1        $f6, -0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, -0X20);
    // 0x800AECFC: mul.s       $f8, $f8, $f17
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f17.fl);
    // 0x800AED00: add.s       $f10, $f10, $f1
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 1);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f1.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f1.fl;
    // 0x800AED04: lwc1        $f1, -0x3C($s2)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r18, -0X3C);
    // 0x800AED08: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800AED0C: lwc1        $f4, -0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, -0X2C);
    // 0x800AED10: add.s       $f10, $f10, $f7
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f7.fl;
    // 0x800AED14: lwc1        $f7, -0x1C($s2)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r18, -0X1C);
    // 0x800AED18: add.s       $f11, $f11, $f2
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f11.fl = ctx->f11.fl + ctx->f2.fl;
    // 0x800AED1C: lwc1        $f2, -0x38($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, -0X38);
    // 0x800AED20: add.s       $f11, $f11, $f5
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 5);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f5.fl); 
    ctx->f11.fl = ctx->f11.fl + ctx->f5.fl;
    // 0x800AED24: lwc1        $f5, -0x28($s2)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r18, -0X28);
    // 0x800AED28: add.s       $f11, $f11, $f8
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f11.fl = ctx->f11.fl + ctx->f8.fl;
    // 0x800AED2C: lwc1        $f8, -0x18($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, -0X18);
    // 0x800AED30: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AED34: sub.s       $f9, $f9, $f18
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f9.fl = ctx->f9.fl - ctx->f18.fl;
    // 0x800AED38: mul.s       $f19, $f3, $f13
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f19.fl = MUL_S(ctx->f3.fl, ctx->f13.fl);
    // 0x800AED3C: sub.s       $f9, $f9, $f19
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 19);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f19.fl); 
    ctx->f9.fl = ctx->f9.fl - ctx->f19.fl;
    // 0x800AED40: mul.s       $f20, $f6, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800AED44: sub.s       $f9, $f9, $f20
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 9);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f9.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f9.fl = ctx->f9.fl - ctx->f20.fl;
    // 0x800AED48: mul.s       $f18, $f1, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f1.fl, ctx->f12.fl);
    // 0x800AED4C: swc1        $f9, -0x10($s2)
    MEM_W(-0X10, ctx->r18) = ctx->f_odd[(9 - 1) * 2];
    // 0x800AED50: mul.s       $f19, $f4, $f13
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f19.fl = MUL_S(ctx->f4.fl, ctx->f13.fl);
    // 0x800AED54: nop

    // 0x800AED58: mul.s       $f20, $f7, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 7);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f7.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f7.fl, ctx->f14.fl);
    // 0x800AED5C: sub.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AED60: sub.s       $f10, $f10, $f19
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 19);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f19.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f19.fl;
    // 0x800AED64: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AED68: sub.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800AED6C: mul.s       $f19, $f5, $f13
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f19.fl = MUL_S(ctx->f5.fl, ctx->f13.fl);
    // 0x800AED70: nop

    // 0x800AED74: mul.s       $f20, $f8, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800AED78: swc1        $f10, -0xC($s2)
    MEM_W(-0XC, ctx->r18) = ctx->f10.u32l;
    // 0x800AED7C: sub.s       $f11, $f11, $f18
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f11.fl = ctx->f11.fl - ctx->f18.fl;
    // 0x800AED80: sub.s       $f11, $f11, $f19
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 19);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f19.fl); 
    ctx->f11.fl = ctx->f11.fl - ctx->f19.fl;
    // 0x800AED84: sub.s       $f11, $f11, $f20
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 11);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f11.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f11.fl = ctx->f11.fl - ctx->f20.fl;
    // 0x800AED88: bne         $t8, $t9, L_800AEBDC
    if (ctx->r24 != ctx->r25) {
        // 0x800AED8C: swc1        $f11, -0x8($s2)
        MEM_W(-0X8, ctx->r18) = ctx->f_odd[(11 - 1) * 2];
            goto L_800AEBDC;
    }
    // 0x800AED8C: swc1        $f11, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->f_odd[(11 - 1) * 2];
    // 0x800AED90: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x800AED94: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800AED98: jr          $ra
    // 0x800AED9C: nop

    return;
    // 0x800AED9C: nop

;}
RECOMP_FUNC void func_80800384_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800388: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080038C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800390: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    // 0x80800394: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800398: jal         0x800EE7F8
    // 0x8080039C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080039C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x808003A0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808003A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808003AC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808003B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003B4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808003B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003BC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1380, 0X748) << 16);
    // 0x808003C0: addiu       $t6, $t6, 0x748
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1380, 0X748));
    // 0x808003C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808003C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808003CC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x808003D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003D4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x808003D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003DC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808003E0: jal         0x800BABB8
    // 0x808003E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x808003E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x808003E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
RECOMP_FUNC void _chfactorymaindoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087568: syscall     588
    recomp_syscall_handler(rdram, ctx, 0x80087568);
    return;
    // 0x8008756C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800A48_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A4C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(968, 0XBDC) << 16);
    // 0x80800A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A58: addiu       $t7, $t7, 0xBDC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(968, 0XBDC));
    // 0x80800A5C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800A60: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800A64: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80800A68: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800A6C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800A70: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800A74: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800A78: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800A7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A80: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A84: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80800A88: lwc1        $f16, 0x38($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800A8C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800A90: jal         0x800C8A98
    // 0x80800A94: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x80800A94: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80800A98: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(968, 0XB70) << 16);
    // 0x80800A9C: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80800AA0: addiu       $a1, $a1, 0xB70
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(968, 0XB70));
    // 0x80800AA4: jal         0x800C8E84
    // 0x80800AA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x80800AA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800AAC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800AB0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800AB4: jal         0x800C8CB8
    // 0x80800AB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x80800AB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800ABC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800AC0: jal         0x800C8F64
    // 0x80800AC4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80800AC4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x80800AC8: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800ACC: jal         0x800C8D4C
    // 0x80800AD0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8D4C(rdram, ctx);
        goto after_4;
    // 0x80800AD0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800AD4: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80800AD8: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800ADC: srl         $t1, $a1, 10
    ctx->r9 = S32(U32(ctx->r5) >> 10);
    // 0x80800AE0: xori        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 ^ 0X3;
    // 0x80800AE4: jal         0x800C8FE0
    // 0x80800AE8: sltiu       $a1, $t2, 0x1
    ctx->r5 = ctx->r10 < 0X1 ? 1 : 0;
    func_800C8FE0(rdram, ctx);
        goto after_5;
    // 0x80800AE8: sltiu       $a1, $t2, 0x1
    ctx->r5 = ctx->r10 < 0X1 ? 1 : 0;
    after_5:
    // 0x80800AEC: jal         0x800E8714
    // 0x80800AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E8714(rdram, ctx);
        goto after_6;
    // 0x80800AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800AF4: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // 0x80800AF8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800AFC: jal         0x800E8830
    // 0x80800B00: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800E8830(rdram, ctx);
        goto after_7;
    // 0x80800B00: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_7:
    // 0x80800B04: jal         0x80800828
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800828_chcablespark(rdram, ctx);
        goto after_8;
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B0C: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    // 0x80800B10: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800B14: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80800B18: andi        $t9, $t5, 0xFFFE
    ctx->r25 = ctx->r13 & 0XFFFE;
    // 0x80800B1C: or          $t8, $t4, $t9
    ctx->r24 = ctx->r12 | ctx->r25;
    // 0x80800B20: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80800B24: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800B28: bne         $t7, $at, L_80800B38
    if (ctx->r15 != ctx->r1) {
        // 0x80800B2C: sb          $t8, 0x64($s0)
        MEM_B(0X64, ctx->r16) = ctx->r24;
            goto L_80800B38;
    }
    // 0x80800B2C: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x80800B30: andi        $t1, $t8, 0xFE
    ctx->r9 = ctx->r24 & 0XFE;
    // 0x80800B34: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_80800B38:
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B44: jr          $ra
    // 0x80800B48: nop

    return;
    // 0x80800B48: nop

    // 0x80800B4C: nop

;}
RECOMP_FUNC void func_808000C8_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D8: jal         0x80091554
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_getPrevious(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808000E0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x80091538
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_1;
    // 0x808000EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808000F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x80084430
    // 0x808000FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _baalarm_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800100: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800104: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x800915E8
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isAt(rdram, ctx);
        goto after_3;
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800114: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800128;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $zero, 0x3EB
    ctx->r5 = ADD32(0, 0X3EB);
    // 0x80800120: jal         0x8009DE38
    // 0x80800124: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_4;
    // 0x80800124: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
L_80800128:
    // 0x80800128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080012C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void func_80800DC4_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800DC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800DD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800DD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DD8: jal         0x80100094
    // 0x80800DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800DE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800DE8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800DEC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80800DF0:
    // 0x80800DF0: jal         0x80089D48
    // 0x80800DF4: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800DF4: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    after_1:
    // 0x80800DF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800DFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E00: bne         $s1, $s2, L_80800DF0
    if (ctx->r17 != ctx->r18) {
        // 0x80800E04: sb          $v0, 0x7($s0)
        MEM_B(0X7, ctx->r16) = ctx->r2;
            goto L_80800DF0;
    }
    // 0x80800E04: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // 0x80800E08: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E0C: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x80800E10: beql        $a0, $zero, L_80800E2C
    if (ctx->r4 == 0) {
        // 0x80800E14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E2C;
    }
    goto skip_0;
    // 0x80800E14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800E18: jal         0x800C8B84
    // 0x80800E1C: nop

    func_800C8B84(rdram, ctx);
        goto after_2;
    // 0x80800E1C: nop

    after_2:
    // 0x80800E20: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E24: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x80800E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E2C:
    // 0x80800E2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800E38: jr          $ra
    // 0x80800E3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800E3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080095C_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080095C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800964: jal         0x80082FF0
    // 0x80800968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080096C: jal         0x80800174
    // 0x80800970: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800174_bstntswim(rdram, ctx);
        goto after_1;
    // 0x80800970: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080097C: jr          $ra
    // 0x80800980: nop

    return;
    // 0x80800980: nop

;}
RECOMP_FUNC void func_80800910_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800918: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080091C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800920: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800924: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800928: bgez        $t8, L_80800938
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080092C: nop
    
            goto L_80800938;
    }
    // 0x8080092C: nop

    // 0x80800930: b           L_808009A8
    // 0x80800934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009A8;
    // 0x80800934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800938:
    // 0x80800938: jal         0x80089F78
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800940: bne         $v0, $zero, L_80800950
    if (ctx->r2 != 0) {
        // 0x80800944: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800950;
    }
    // 0x80800944: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800948: b           L_808009A8
    // 0x8080094C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009A8;
    // 0x8080094C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800950:
    // 0x80800950: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x80800954: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800958: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    // 0x8080095C: jal         0x8010C9FC
    // 0x80800960: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8010C9FC(rdram, ctx);
        goto after_1;
    // 0x80800960: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800964: bne         $v0, $zero, L_80800974
    if (ctx->r2 != 0) {
        // 0x80800968: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800974;
    }
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: b           L_808009A8
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009A8;
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800974:
    // 0x80800974: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800978: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x8080097C: jal         0x8010C668
    // 0x80800980: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_8010C668(rdram, ctx);
        goto after_2;
    // 0x80800980: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_2:
    // 0x80800984: bne         $v0, $zero, L_80800994
    if (ctx->r2 != 0) {
        // 0x80800988: nop
    
            goto L_80800994;
    }
    // 0x80800988: nop

    // 0x8080098C: b           L_808009A8
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009A8;
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800994:
    // 0x80800994: jal         0x80089EF8
    // 0x80800998: nop

    _suchase_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800998: nop

    after_3:
    // 0x8080099C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808009A0: xor         $v0, $v0, $t9
    ctx->r2 = ctx->r2 ^ ctx->r25;
    // 0x808009A4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_808009A8:
    // 0x808009A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009B4: jr          $ra
    // 0x808009B8: nop

    return;
    // 0x808009B8: nop

;}
