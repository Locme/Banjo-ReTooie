#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800674_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800678: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080067C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800680: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800684: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800688: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x8080068C: jal         0x800F7CF4
    // 0x80800690: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800F7CF4(rdram, ctx);
        goto after_0;
    // 0x80800690: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_0:
    // 0x80800694: jal         0x800C067C
    // 0x80800698: addiu       $a0, $zero, 0x11DD
    ctx->r4 = ADD32(0, 0X11DD);
    func_800C067C(rdram, ctx);
        goto after_1;
    // 0x80800698: addiu       $a0, $zero, 0x11DD
    ctx->r4 = ADD32(0, 0X11DD);
    after_1:
    // 0x8080069C: jal         0x80800048
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_chmumbopad(rdram, ctx);
        goto after_2;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006A4: bne         $v0, $zero, L_808006CC
    if (ctx->r2 != 0) {
        // 0x808006A8: addiu       $a1, $zero, 0x11DE
        ctx->r5 = ADD32(0, 0X11DE);
            goto L_808006CC;
    }
    // 0x808006A8: addiu       $a1, $zero, 0x11DE
    ctx->r5 = ADD32(0, 0X11DE);
    // 0x808006AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808006B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808006B8: jal         0x8008A208
    // 0x808006BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808006BC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808006C0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808006C4: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808006C8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808006CC:
    // 0x808006CC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808006D0: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808006D4: addiu       $a0, $zero, 0x11DD
    ctx->r4 = ADD32(0, 0X11DD);
    // 0x808006D8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x808006DC: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808006E0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808006E4: jal         0x800C067C
    // 0x808006E8: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    func_800C067C(rdram, ctx);
        goto after_4;
    // 0x808006E8: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    after_4:
    // 0x808006EC: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x808006F0: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x808006F4: sltiu       $at, $t5, 0x11
    ctx->r1 = ctx->r13 < 0X11 ? 1 : 0;
    // 0x808006F8: beq         $at, $zero, L_8080088C
    if (ctx->r1 == 0) {
        // 0x808006FC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8080088C;
    }
    // 0x808006FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800700: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1720, 0XFCC) << 16);
    // 0x80800704: addu        $at, $at, $t5
    gpr jr_addend_8080070C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80800708: lw          $t5, 0xFCC($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1720, 0XFCC));
    // 0x8080070C: jr          $t5
    // 0x80800710: nop

    switch (jr_addend_8080070C >> 2) {
        case 0: goto L_8080088C; break;
        case 1: goto L_8080088C; break;
        case 2: goto L_80800714; break;
        case 3: goto L_80800724; break;
        case 4: goto L_8080073C; break;
        case 5: goto L_80800754; break;
        case 6: goto L_8080076C; break;
        case 7: goto L_80800784; break;
        case 8: goto L_8080079C; break;
        case 9: goto L_808007B4; break;
        case 10: goto L_808007F4; break;
        case 11: goto L_808007D4; break;
        case 12: goto L_80800814; break;
        case 13: goto L_80800834; break;
        case 14: goto L_8080084C; break;
        case 15: goto L_80800864; break;
        case 16: goto L_8080087C; break;
        default: switch_error(__func__, 0x8080070C, 0x80800FCC);
    }
    // 0x80800710: nop

L_80800714:
    // 0x80800714: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800718: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8080071C: b           L_8080088C
    // 0x80800720: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_8080088C;
    // 0x80800720: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_80800724:
    // 0x80800724: addiu       $a0, $zero, 0x337
    ctx->r4 = ADD32(0, 0X337);
    // 0x80800728: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080072C: jal         0x80101180
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800734: b           L_80800890
    // 0x80800738: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800738: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080073C:
    // 0x8080073C: addiu       $a0, $zero, 0x39D
    ctx->r4 = ADD32(0, 0X39D);
    // 0x80800740: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800744: jal         0x80101180
    // 0x80800748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800748: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8080074C: b           L_80800890
    // 0x80800750: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800750: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800754:
    // 0x80800754: addiu       $a0, $zero, 0x39C
    ctx->r4 = ADD32(0, 0X39C);
    // 0x80800758: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080075C: jal         0x80101180
    // 0x80800760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800764: b           L_80800890
    // 0x80800768: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800768: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080076C:
    // 0x8080076C: addiu       $a0, $zero, 0x297
    ctx->r4 = ADD32(0, 0X297);
    // 0x80800770: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800774: jal         0x80101180
    // 0x80800778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_8;
    // 0x80800778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8080077C: b           L_80800890
    // 0x80800780: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800780: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800784:
    // 0x80800784: addiu       $a0, $zero, 0x292
    ctx->r4 = ADD32(0, 0X292);
    // 0x80800788: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080078C: jal         0x80101180
    // 0x80800790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80800790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80800794: b           L_80800890
    // 0x80800798: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800798: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080079C:
    // 0x8080079C: addiu       $a0, $zero, 0x28E
    ctx->r4 = ADD32(0, 0X28E);
    // 0x808007A0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007A4: jal         0x80101180
    // 0x808007A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x808007A8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_10:
    // 0x808007AC: b           L_80800890
    // 0x808007B0: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x808007B0: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_808007B4:
    // 0x808007B4: addiu       $a0, $zero, 0x28D
    ctx->r4 = ADD32(0, 0X28D);
    // 0x808007B8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007BC: jal         0x80101180
    // 0x808007C0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80101180(rdram, ctx);
        goto after_11;
    // 0x808007C0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_11:
    // 0x808007C4: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808007C8: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x808007CC: b           L_8080088C
    // 0x808007D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_8080088C;
    // 0x808007D0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_808007D4:
    // 0x808007D4: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    // 0x808007D8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007DC: jal         0x80101180
    // 0x808007E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x808007E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808007E4: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808007E8: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808007EC: b           L_8080088C
    // 0x808007F0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_8080088C;
    // 0x808007F0: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_808007F4:
    // 0x808007F4: addiu       $a0, $zero, 0x3F5
    ctx->r4 = ADD32(0, 0X3F5);
    // 0x808007F8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x808007FC: jal         0x80101180
    // 0x80800800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80800800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800804: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800808: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080080C: b           L_8080088C
    // 0x80800810: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_8080088C;
    // 0x80800810: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800814:
    // 0x80800814: addiu       $a0, $zero, 0x40E
    ctx->r4 = ADD32(0, 0X40E);
    // 0x80800818: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080081C: jal         0x80101180
    // 0x80800820: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80101180(rdram, ctx);
        goto after_14;
    // 0x80800820: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_14:
    // 0x80800824: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800828: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x8080082C: b           L_8080088C
    // 0x80800830: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_8080088C;
    // 0x80800830: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80800834:
    // 0x80800834: addiu       $a0, $zero, 0x346
    ctx->r4 = ADD32(0, 0X346);
    // 0x80800838: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080083C: jal         0x80101180
    // 0x80800840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_15;
    // 0x80800840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80800844: b           L_80800890
    // 0x80800848: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800848: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080084C:
    // 0x8080084C: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x80800850: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800854: jal         0x80101180
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_16;
    // 0x80800858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8080085C: b           L_80800890
    // 0x80800860: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800860: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800864:
    // 0x80800864: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    // 0x80800868: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8080086C: jal         0x80101180
    // 0x80800870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_17;
    // 0x80800870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80800874: b           L_80800890
    // 0x80800878: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
        goto L_80800890;
    // 0x80800878: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_8080087C:
    // 0x8080087C: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    // 0x80800880: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800884: jal         0x80101180
    // 0x80800888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_18;
    // 0x80800888: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
L_8080088C:
    // 0x8080088C: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
L_80800890:
    // 0x80800890: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800894: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x80800898: lbu         $t2, 0x2A($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2A);
    // 0x8080089C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x808008A0: sltiu       $t9, $t7, 0x1
    ctx->r25 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x808008A4: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x808008A8: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x808008AC: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x808008B0: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x808008B4: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008C4: jr          $ra
    // 0x808008C8: nop

    return;
    // 0x808008C8: nop

;}
RECOMP_FUNC void func_80800734_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800738: jr          $ra
    // 0x8080073C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8080073C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8010BF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BF4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010BF50: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8010BF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010BF58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010BF5C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010BF60: swc1        $f12, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f12.u32l;
    // 0x8010BF64: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8010BF68: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010BF6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010BF70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010BF74: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8010BF78: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BF7C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010BF80: jal         0x80102844
    // 0x8010BF84: nop

    func_80102844(rdram, ctx);
        goto after_0;
    // 0x8010BF84: nop

    after_0:
    // 0x8010BF88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010BF8C: jal         0x8010B990
    // 0x8010BF90: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x8010BF90: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8010BF94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010BF98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010BF9C: jr          $ra
    // 0x8010BFA0: nop

    return;
    // 0x8010BFA0: nop

;}
RECOMP_FUNC void func_8080024C_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800258: jal         0x80800090
    // 0x8080025C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800090_bskazglide(rdram, ctx);
        goto after_0;
    // 0x8080025C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800260: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800264: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x8008CB3C
    // 0x80800270: addiu       $a1, $zero, 0x13D
    ctx->r5 = ADD32(0, 0X13D);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800270: addiu       $a1, $zero, 0x13D
    ctx->r5 = ADD32(0, 0X13D);
    after_1:
    // 0x80800274: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800278: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800284: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800288: jal         0x8009FFD8
    // 0x8080028C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080028C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x80095738
    // 0x80800298: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    baflag_isTrue(rdram, ctx);
        goto after_3;
    // 0x80800298: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x8080029C: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B8;
    }
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x8009B9B0
    // 0x808002AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808002AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808002B0: b           L_808002C0
    // 0x808002B4: nop

        goto L_808002C0;
    // 0x808002B4: nop

L_808002B8:
    // 0x808002B8: jal         0x8009B9B0
    // 0x808002BC: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x808002BC: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_5:
L_808002C0:
    // 0x808002C0: jal         0x8009630C
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009630C(rdram, ctx);
        goto after_6;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808002C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808002CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002D0: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808002DC: nop

    // 0x808002E0: bc1f        L_808002EC
    if (!c1cs) {
        // 0x808002E4: nop
    
            goto L_808002EC;
    }
    // 0x808002E4: nop

    // 0x808002E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: jal         0x8009BB50
    // 0x808002F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_7;
    // 0x808002F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_7:
    // 0x808002F4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808002F8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: bne         $t8, $zero, L_8080032C
    if (ctx->r24 != 0) {
        // 0x80800304: nop
    
            goto L_8080032C;
    }
    // 0x80800304: nop

    // 0x80800308: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080030C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80800310: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800314: nop

    // 0x80800318: bc1f        L_80800324
    if (!c1cs) {
        // 0x8080031C: nop
    
            goto L_80800324;
    }
    // 0x8080031C: nop

    // 0x80800320: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80800324:
    // 0x80800324: beql        $t9, $zero, L_80800338
    if (ctx->r25 == 0) {
        // 0x80800328: lui         $a2, 0x3EC2
        ctx->r6 = S32(0X3EC2 << 16);
            goto L_80800338;
    }
    goto skip_0;
    // 0x80800328: lui         $a2, 0x3EC2
    ctx->r6 = S32(0X3EC2 << 16);
    skip_0:
L_8080032C:
    // 0x8080032C: jal         0x8009BA58
    // 0x80800330: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_8;
    // 0x80800330: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    after_8:
    // 0x80800334: lui         $a2, 0x3EC2
    ctx->r6 = S32(0X3EC2 << 16);
L_80800338:
    // 0x80800338: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80085338
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_9;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800348: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    // 0x8080034C: sb          $zero, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = 0;
    // 0x80800350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800354: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800358: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void basnowball_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E4: beq         $a1, $zero, L_808005FC
    if (ctx->r5 == 0) {
        // 0x808005E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808005FC;
    }
    // 0x808005E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005EC: jal         0x80800150
    // 0x808005F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800150_basnowball(rdram, ctx);
        goto after_0;
    // 0x808005F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808005F4: b           L_80800608
    // 0x808005F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800608;
    // 0x808005F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005FC:
    // 0x808005FC: jal         0x80800150
    // 0x80800600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800150_basnowball(rdram, ctx);
        goto after_1;
    // 0x80800600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800608:
    // 0x80800608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080060C: jr          $ra
    // 0x80800610: nop

    return;
    // 0x80800610: nop

;}
RECOMP_FUNC void chlagoonfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B3C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1800, 0XB70) << 16);
    // 0x80800B40: jr          $ra
    // 0x80800B44: addiu       $v0, $v0, 0xB70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1800, 0XB70));
    return;
    // 0x80800B44: addiu       $v0, $v0, 0xB70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1800, 0XB70));
    // 0x80800B48: nop

    // 0x80800B4C: nop

;}
RECOMP_FUNC void bamovespline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808002D0: jr          $ra
    // 0x808002D4: lbu         $v0, 0x92($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X92);
    return;
    // 0x808002D4: lbu         $v0, 0x92($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X92);
;}
RECOMP_FUNC void func_80800114_cheggice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800118: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800124: jal         0x80100094
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080012C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800130: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800134: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800138: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080013C: beq         $t6, $at, L_80800154
    if (ctx->r14 == ctx->r1) {
        // 0x80800140: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800154;
    }
    // 0x80800140: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800144: beq         $t6, $at, L_808001B4
    if (ctx->r14 == ctx->r1) {
        // 0x80800148: nop
    
            goto L_808001B4;
    }
    // 0x80800148: nop

    // 0x8080014C: b           L_8080025C
    // 0x80800150: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_8080025C;
    // 0x80800150: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800154:
    // 0x80800154: jal         0x8008A3B8
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080015C: bnel        $v0, $zero, L_8080025C
    if (ctx->r2 != 0) {
        // 0x80800160: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_8080025C;
    }
    goto skip_0;
    // 0x80800160: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800164: jal         0x800EEEA8
    // 0x80800168: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_2;
    // 0x80800168: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x8080016C: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x80800170: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800184;
    }
    // 0x80800170: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800174: lbu         $t9, 0x39($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X39);
    // 0x80800178: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8080017C: b           L_80800258
    // 0x80800180: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
        goto L_80800258;
    // 0x80800180: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
L_80800184:
    // 0x80800184: jal         0x80800000
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cheggice(rdram, ctx);
        goto after_3;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080018C: jal         0x8008A3F8
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800194: jal         0x8008A3E8
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080019C: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x808001A0: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80800258;
    }
    // 0x808001A0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808001A4: lbu         $t3, 0x39($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X39);
    // 0x808001A8: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x808001AC: b           L_80800258
    // 0x808001B0: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
        goto L_80800258;
    // 0x808001B0: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
L_808001B4:
    // 0x808001B4: jal         0x8008A3B8
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001BC: bne         $v0, $zero, L_80800258
    if (ctx->r2 != 0) {
        // 0x808001C0: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80800258;
    }
    // 0x808001C0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808001C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f12, 0x30($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X30);
    // 0x808001D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001D4: lui         $a2, 0x3E09
    ctx->r6 = S32(0X3E09 << 16);
    // 0x808001D8: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808001DC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808001E0: ori         $a2, $a2, 0x374C
    ctx->r6 = ctx->r6 | 0X374C;
    // 0x808001E4: jal         0x800F10B4
    // 0x808001E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808001E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x808001EC: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x808001F0: jal         0x8008A450
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001F8: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x808001FC: nop
    
            goto L_80800208;
    }
    // 0x808001FC: nop

    // 0x80800200: jal         0x8008A430
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_23(rdram, ctx);
        goto after_9;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800208:
    // 0x80800208: jal         0x8008A3E0
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800210: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x80800214: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80800228;
    }
    // 0x80800214: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800218: lbu         $t9, 0x39($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X39);
    // 0x8080021C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80800220: b           L_80800258
    // 0x80800224: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
        goto L_80800258;
    // 0x80800224: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
L_80800228:
    // 0x80800228: jal         0x8008A3D8
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800230: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800234: nop
    
            goto L_80800248;
    }
    // 0x80800234: nop

    // 0x80800238: jal         0x8008A348
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800240: b           L_8080025C
    // 0x80800244: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_8080025C;
    // 0x80800244: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800248:
    // 0x80800248: jal         0x80800000
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cheggice(rdram, ctx);
        goto after_13;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800250: jal         0x8008A3F8
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_14;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80800258:
    // 0x80800258: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8080025C:
    // 0x8080025C: lb          $t3, 0x39($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X39);
    // 0x80800260: bgezl       $t3, L_80800274
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800264: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800274;
    }
    goto skip_1;
    // 0x80800264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800268: jal         0x8008A390
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800274:
    // 0x80800274: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800278: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

;}
RECOMP_FUNC void _chmayafarmer_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A80: syscall     410
    recomp_syscall_handler(rdram, ctx, 0x80086A80);
    return;
    // 0x80086A84: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800124EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800124EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800124F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800124F4: jal         0x80012214
    // 0x800124F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80012214(rdram, ctx);
        goto after_0;
    // 0x800124F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
L_800124FC:
    // 0x800124FC: jal         0x800123F4
    // 0x80012500: nop

    func_800123F4(rdram, ctx);
        goto after_1;
    // 0x80012500: nop

    after_1:
    // 0x80012504: b           L_800124FC
    // 0x80012508: nop

        goto L_800124FC;
    // 0x80012508: nop

    // 0x8001250C: nop

    // 0x80012510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012518: jr          $ra
    // 0x8001251C: nop

    return;
    // 0x8001251C: nop

;}
RECOMP_FUNC void func_80801B94_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801B98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B9C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801BA0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801BA4: jal         0x800B53A4
    // 0x80801BA8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80801BA8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80801BAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801BB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801BB4: jal         0x80103DFC
    // 0x80801BB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80103DFC(rdram, ctx);
        goto after_1;
    // 0x80801BB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80801BBC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1752, 0X4E78) << 16);
    // 0x80801BC0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80801BC4: addiu       $t6, $t6, 0x4E78
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1752, 0X4E78));
    // 0x80801BC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801BCC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801BD0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BD4: jal         0x800BABB8
    // 0x80801BD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80801BD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80801BDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BE0: jal         0x800BA3FC
    // 0x80801BE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800BA3FC(rdram, ctx);
        goto after_3;
    // 0x80801BE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80801BE8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BEC: jal         0x800BA22C
    // 0x80801BF0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x80801BF0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_4:
    // 0x80801BF4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1752, 0X4EA4) << 16);
    // 0x80801BF8: addiu       $a2, $a2, 0x4EA4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1752, 0X4EA4));
    // 0x80801BFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801C00: jal         0x80089D18
    // 0x80801C04: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80801C04: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80801C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801C10: jr          $ra
    // 0x80801C14: nop

    return;
    // 0x80801C14: nop

;}
RECOMP_FUNC void func_80801AEC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AF4: jal         0x80801B64
    // 0x80801AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B04: jr          $ra
    // 0x80801B08: nop

    return;
    // 0x80801B08: nop

;}
RECOMP_FUNC void _suegg_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A418: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A418);
    return;
    // 0x8008A41C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_80800118_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080011C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800128: jal         0x80100094
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800134: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800138: jal         0x800897D8
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800140: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800144: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800148: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080014C: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800150: beq         $at, $zero, L_80800258
    if (ctx->r1 == 0) {
        // 0x80800154: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800258;
    }
    // 0x80800154: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(948, 0X650) << 16);
    // 0x8080015C: addu        $at, $at, $t8
    gpr jr_addend_80800164 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800160: lw          $t8, 0x650($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(948, 0X650));
    // 0x80800164: jr          $t8
    // 0x80800168: nop

    switch (jr_addend_80800164 >> 2) {
        case 0: goto L_8080016C; break;
        case 1: goto L_8080018C; break;
        case 2: goto L_808001A4; break;
        case 3: goto L_80800240; break;
        case 4: goto L_80800250; break;
        default: switch_error(__func__, 0x80800164, 0x80800650);
    }
    // 0x80800168: nop

L_8080016C:
    // 0x8080016C: jal         0x800D1824
    // 0x80800170: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1824(rdram, ctx);
        goto after_2;
    // 0x80800170: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_2:
    // 0x80800174: jal         0x80800538
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800538_chconga(rdram, ctx);
        goto after_3;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080017C: jal         0x80800618
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800618_chconga(rdram, ctx);
        goto after_4;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800184: b           L_8080025C
    // 0x80800188: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_8080025C;
    // 0x80800188: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_8080018C:
    // 0x8080018C: jal         0x800D1824
    // 0x80800190: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1824(rdram, ctx);
        goto after_5;
    // 0x80800190: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_5:
    // 0x80800194: jal         0x80800618
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800618_chconga(rdram, ctx);
        goto after_6;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080019C: b           L_8080025C
    // 0x808001A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_8080025C;
    // 0x808001A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_808001A4:
    // 0x808001A4: jal         0x800D1824
    // 0x808001A8: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1824(rdram, ctx);
        goto after_7;
    // 0x808001A8: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_7:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x80103DFC
    // 0x808001B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80103DFC(rdram, ctx);
        goto after_8;
    // 0x808001B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80100094
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808001CC: jal         0x80089FE8
    // 0x808001D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808001D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_10:
    // 0x808001D4: beql        $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x808001D8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080025C;
    }
    goto skip_0;
    // 0x808001D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808001DC: jal         0x800DA544
    // 0x808001E0: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x808001E0: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_11:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80102424
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808001F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001F4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x808001F8: addiu       $t9, $zero, 0x52
    ctx->r25 = ADD32(0, 0X52);
    // 0x808001FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800200: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800204: jal         0x8008A208
    // 0x80800208: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800208: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x8080020C: jal         0x800C6E38
    // 0x80800210: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800C6E38(rdram, ctx);
        goto after_14;
    // 0x80800210: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_14:
    // 0x80800214: beql        $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800218: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080025C;
    }
    goto skip_1;
    // 0x80800218: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x8080021C: jal         0x800C6E38
    // 0x80800220: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800C6E38(rdram, ctx);
        goto after_15;
    // 0x80800220: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_15:
    // 0x80800224: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x80800228: addiu       $a0, $zero, 0x46E
        ctx->r4 = ADD32(0, 0X46E);
            goto L_80800258;
    }
    // 0x80800228: addiu       $a0, $zero, 0x46E
    ctx->r4 = ADD32(0, 0X46E);
    // 0x8080022C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800230: jal         0x80101180
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_16;
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80800238: b           L_8080025C
    // 0x8080023C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_8080025C;
    // 0x8080023C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800240:
    // 0x80800240: jal         0x80105854
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105854(rdram, ctx);
        goto after_17;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800248: b           L_8080025C
    // 0x8080024C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_8080025C;
    // 0x8080024C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800250:
    // 0x80800250: jal         0x80800618
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800618_chconga(rdram, ctx);
        goto after_18;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_80800258:
    // 0x80800258: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_8080025C:
    // 0x8080025C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80800260: lui         $a2, 0x432F
    ctx->r6 = S32(0X432F << 16);
    // 0x80800264: jal         0x80089F18
    // 0x80800268: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80800268: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_19:
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800270: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800274: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void func_80800008_ncbastring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80112524
    // 0x80800014: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void _dbzone_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087950: syscall     640
    recomp_syscall_handler(rdram, ctx, 0x80087950);
    return;
    // 0x80087954: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808010C0_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808010CC: jal         0x80085808
    // 0x808010D0: addiu       $a1, $zero, 0x351
    ctx->r5 = ADD32(0, 0X351);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808010D0: addiu       $a1, $zero, 0x351
    ctx->r5 = ADD32(0, 0X351);
    after_0:
    // 0x808010D4: jal         0x80085818
    // 0x808010D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808010D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808010DC: jal         0x800DA298
    // 0x808010E0: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808010E0: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    after_2:
    // 0x808010E4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808010E8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x808010EC: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x808010F0: lbu         $t9, 0x65($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X65);
    // 0x808010F4: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x808010F8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808010FC: sb          $t1, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r9;
    // 0x80801100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801108: jr          $ra
    // 0x8080110C: nop

    return;
    // 0x8080110C: nop

;}
RECOMP_FUNC void func_8010D490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D490: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8010D494: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8010D498: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8010D49C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010D4A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010D4A4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8010D4A8: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8010D4AC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8010D4B0: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x8010D4B4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8010D4B8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8010D4BC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8010D4C0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8010D4C4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8010D4C8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8010D4CC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010D4D0: jal         0x800EE7F8
    // 0x8010D4D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010D4D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8010D4D8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8010D4DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8010D4E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010D4E4: jal         0x800F0C68
    // 0x8010D4E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F0C68(rdram, ctx);
        goto after_1;
    // 0x8010D4E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x8010D4EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010D4F0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8010D4F4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x8010D4F8: lwc1        $f20, 0x6530($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6530);
    // 0x8010D4FC: jal         0x800F5898
    // 0x8010D500: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_2;
    // 0x8010D500: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x8010D504: blez        $v0, L_8010D594
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010D508: lw          $s3, 0x98($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X98);
            goto L_8010D594;
    }
    // 0x8010D508: lw          $s3, 0x98($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X98);
    // 0x8010D50C: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x8010D510: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_8010D514:
    // 0x8010D514: jal         0x800F6438
    // 0x8010D518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x8010D518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010D51C: beq         $v0, $zero, L_8010D580
    if (ctx->r2 == 0) {
        // 0x8010D520: nop
    
            goto L_8010D580;
    }
    // 0x8010D520: nop

    // 0x8010D524: beq         $s0, $s3, L_8010D580
    if (ctx->r16 == ctx->r19) {
        // 0x8010D528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010D580;
    }
    // 0x8010D528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010D52C: jal         0x800F5BF0
    // 0x8010D530: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F5BF0(rdram, ctx);
        goto after_4;
    // 0x8010D530: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x8010D534: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010D538: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8010D53C: jal         0x800EFB24
    // 0x8010D540: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x8010D540: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_5:
    // 0x8010D544: jal         0x800EEFD4
    // 0x8010D548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_6;
    // 0x8010D548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8010D54C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8010D550: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8010D554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010D558: bc1f        L_8010D580
    if (!c1cs) {
        // 0x8010D55C: nop
    
            goto L_8010D580;
    }
    // 0x8010D55C: nop

    // 0x8010D560: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8010D564: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8010D568: jal         0x800F0BD0
    // 0x8010D56C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F0BD0(rdram, ctx);
        goto after_7;
    // 0x8010D56C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
    // 0x8010D570: beq         $v0, $zero, L_8010D580
    if (ctx->r2 == 0) {
        // 0x8010D574: nop
    
            goto L_8010D580;
    }
    // 0x8010D574: nop

    // 0x8010D578: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    // 0x8010D57C: lwc1        $f20, 0x64($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X64);
L_8010D580:
    // 0x8010D580: jal         0x800F5898
    // 0x8010D584: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_8;
    // 0x8010D584: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // 0x8010D588: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010D58C: bne         $at, $zero, L_8010D514
    if (ctx->r1 != 0) {
        // 0x8010D590: nop
    
            goto L_8010D514;
    }
    // 0x8010D590: nop

L_8010D594:
    // 0x8010D594: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010D598: bne         $s6, $at, L_8010D5A8
    if (ctx->r22 != ctx->r1) {
        // 0x8010D59C: ldc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
            goto L_8010D5A8;
    }
    // 0x8010D59C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010D5A0: b           L_8010D5AC
    // 0x8010D5A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010D5AC;
    // 0x8010D5A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010D5A8:
    // 0x8010D5A8: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_8010D5AC:
    // 0x8010D5AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8010D5B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010D5B4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010D5B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8010D5BC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8010D5C0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8010D5C4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8010D5C8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8010D5CC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8010D5D0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8010D5D4: jr          $ra
    // 0x8010D5D8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8010D5D8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void bsrest_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800538: jal         0x8008E35C
    // 0x8080053C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x8080053C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800540: beq         $v0, $zero, L_8080054C
    if (ctx->r2 == 0) {
        // 0x80800544: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080054C;
    }
    // 0x80800544: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800548: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
L_8080054C:
    // 0x8080054C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800550: jal         0x8080032C
    // 0x80800554: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    static_344_8080032C(rdram, ctx);
        goto after_1;
    // 0x80800554: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800558: beq         $v0, $zero, L_8080056C
    if (ctx->r2 == 0) {
        // 0x8080055C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080056C;
    }
    // 0x8080055C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800560: jal         0x8080069C
    // 0x80800564: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bsrest_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800564: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8080056C:
    // 0x8080056C: jal         0x8009E5C8
    // 0x80800570: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800570: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080057C: jr          $ra
    // 0x80800580: nop

    return;
    // 0x80800580: nop

;}
RECOMP_FUNC void suegg_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C0C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C10: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800C14: jal         0x800EFB24
    // 0x80800C18: addiu       $a2, $a3, 0x18
    ctx->r6 = ADD32(ctx->r7, 0X18);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x80800C18: addiu       $a2, $a3, 0x18
    ctx->r6 = ADD32(ctx->r7, 0X18);
    after_0:
    // 0x80800C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C24: jr          $ra
    // 0x80800C28: nop

    return;
    // 0x80800C28: nop

;}
RECOMP_FUNC void func_800EE530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EE534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EE53C: jal         0x8001BAFC
    // 0x800EE540: lw          $a0, 0x2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C);
    defrag(rdram, ctx);
        goto after_0;
    // 0x800EE540: lw          $a0, 0x2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C);
    after_0:
    // 0x800EE544: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800EE548: sw          $v0, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r2;
    // 0x800EE54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EE550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EE554: jr          $ra
    // 0x800EE558: nop

    return;
    // 0x800EE558: nop

;}
RECOMP_FUNC void func_80800414_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800414: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800418: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080041C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800420: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800424: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800428: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8080042C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800430: bne         $a1, $at, L_808005C0
    if (ctx->r5 != ctx->r1) {
        // 0x80800434: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808005C0;
    }
    // 0x80800434: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800438: lhu         $t6, 0x18($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X18);
    // 0x8080043C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800440: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800444: beq         $t7, $zero, L_80800534
    if (ctx->r15 == 0) {
        // 0x80800448: nop
    
            goto L_80800534;
    }
    // 0x80800448: nop

    // 0x8080044C: jal         0x80106790
    // 0x80800450: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800450: nop

    after_0:
    // 0x80800454: lw          $t8, 0x6C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6C);
    // 0x80800458: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x8080045C: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80800460: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x80800464: bne         $t0, $at, L_808004F0
    if (ctx->r8 != ctx->r1) {
        // 0x80800468: nop
    
            goto L_808004F0;
    }
    // 0x80800468: nop

    // 0x8080046C: jal         0x800B53A4
    // 0x80800470: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80800470: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x80800474: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800478: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080047C: lwc1        $f4, 0x30($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80800480: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2280, 0X9BC) << 16);
    // 0x80800484: addiu       $t1, $t1, 0x9BC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2280, 0X9BC));
    // 0x80800488: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080048C: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x80800490: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800494: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800498: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080049C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004A4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808004A8: jal         0x800BABB8
    // 0x808004AC: nop

    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808004AC: nop

    after_2:
    // 0x808004B0: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x808004B4: addiu       $t3, $zero, 0x320
    ctx->r11 = ADD32(0, 0X320);
    // 0x808004B8: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x808004BC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x808004C0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808004C4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: addiu       $a1, $zero, -0xC8
    ctx->r5 = ADD32(0, -0XC8);
    // 0x808004D0: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x808004D4: jal         0x800BA930
    // 0x808004D8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    func_800BA930(rdram, ctx);
        goto after_3;
    // 0x808004D8: addiu       $a3, $zero, -0xC8
    ctx->r7 = ADD32(0, -0XC8);
    after_3:
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E0: jal         0x800BA22C
    // 0x808004E4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x808004E4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_4:
    // 0x808004E8: b           L_80800584
    // 0x808004EC: nop

        goto L_80800584;
    // 0x808004EC: nop

L_808004F0:
    // 0x808004F0: jal         0x800B53A4
    // 0x808004F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800B53A4(rdram, ctx);
        goto after_5;
    // 0x808004F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_5:
    // 0x808004F8: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2280, 0X9BC) << 16);
    // 0x808004FC: addiu       $t5, $t5, 0x9BC
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2280, 0X9BC));
    // 0x80800500: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x80800504: lw          $a3, 0x30($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X30);
    // 0x80800508: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080050C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800510: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800518: jal         0x800BABB8
    // 0x8080051C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x8080051C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x800BA22C
    // 0x80800528: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80800528: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x8080052C: b           L_80800584
    // 0x80800530: nop

        goto L_80800584;
    // 0x80800530: nop

L_80800534:
    // 0x80800534: jal         0x800B53A4
    // 0x80800538: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_8;
    // 0x80800538: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_8:
    // 0x8080053C: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800540: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800544: lwc1        $f10, 0x30($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80800548: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2280, 0X9BC) << 16);
    // 0x8080054C: addiu       $t6, $t6, 0x9BC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2280, 0X9BC));
    // 0x80800550: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800554: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x80800558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080055C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800560: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080056C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800570: jal         0x800BABB8
    // 0x80800574: nop

    func_800BABB8(rdram, ctx);
        goto after_9;
    // 0x80800574: nop

    after_9:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x800BA22C
    // 0x80800580: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_10;
    // 0x80800580: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
L_80800584:
    // 0x80800584: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2280, 0X9FC) << 16);
    // 0x80800588: addiu       $a2, $a2, 0x9FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2280, 0X9FC));
    // 0x8080058C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800590: jal         0x80089D18
    // 0x80800594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x80800598: lw          $a0, 0x6C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X6C);
    // 0x8080059C: srl         $t7, $a0, 21
    ctx->r15 = S32(U32(ctx->r4) >> 21);
    // 0x808005A0: jal         0x8080015C
    // 0x808005A4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8080015C_chfactoryroofbits(rdram, ctx);
        goto after_12;
    // 0x808005A4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_12:
    // 0x808005A8: jal         0x800DA544
    // 0x808005AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x808005AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x808005B0: jal         0x800FFAB0
    // 0x808005B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x808005B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x808005B8: b           L_808005C4
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005C4;
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C0:
    // 0x808005C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005C4:
    // 0x808005C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808005C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808005CC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808005D0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808005D4: jr          $ra
    // 0x808005D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808005D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80108944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108944: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80108948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010894C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80108950: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80108954: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80108958: lbu         $v0, 0x7B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X7B);
    // 0x8010895C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80108960: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80108964: srl         $t6, $v0, 6
    ctx->r14 = S32(U32(ctx->r2) >> 6);
    // 0x80108968: beq         $t6, $at, L_8010898C
    if (ctx->r14 == ctx->r1) {
        // 0x8010896C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8010898C;
    }
    // 0x8010896C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80108970: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80108974: beq         $t6, $at, L_80108994
    if (ctx->r14 == ctx->r1) {
        // 0x80108978: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80108994;
    }
    // 0x80108978: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010897C: beql        $t6, $at, L_801089A0
    if (ctx->r14 == ctx->r1) {
        // 0x80108980: lui         $s0, 0x3000
        ctx->r16 = S32(0X3000 << 16);
            goto L_801089A0;
    }
    goto skip_0;
    // 0x80108980: lui         $s0, 0x3000
    ctx->r16 = S32(0X3000 << 16);
    skip_0:
    // 0x80108984: b           L_801089A4
    // 0x80108988: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
        goto L_801089A4;
    // 0x80108988: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
L_8010898C:
    // 0x8010898C: b           L_801089A0
    // 0x80108990: lui         $s0, 0x1000
    ctx->r16 = S32(0X1000 << 16);
        goto L_801089A0;
    // 0x80108990: lui         $s0, 0x1000
    ctx->r16 = S32(0X1000 << 16);
L_80108994:
    // 0x80108994: b           L_801089A0
    // 0x80108998: lui         $s0, 0x2000
    ctx->r16 = S32(0X2000 << 16);
        goto L_801089A0;
    // 0x80108998: lui         $s0, 0x2000
    ctx->r16 = S32(0X2000 << 16);
    // 0x8010899C: lui         $s0, 0x3000
    ctx->r16 = S32(0X3000 << 16);
L_801089A0:
    // 0x801089A0: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
L_801089A4:
    // 0x801089A4: ori         $t0, $s0, 0x2000
    ctx->r8 = ctx->r16 | 0X2000;
    // 0x801089A8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x801089AC: sll         $t9, $t7, 25
    ctx->r25 = S32(ctx->r15 << 25);
    // 0x801089B0: bgezl       $t9, L_801089C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801089B4: lw          $t1, 0x78($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X78);
            goto L_801089C0;
    }
    goto skip_1;
    // 0x801089B4: lw          $t1, 0x78($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X78);
    skip_1:
    // 0x801089B8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x801089BC: lw          $t1, 0x78($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X78);
L_801089C0:
    // 0x801089C0: sll         $t3, $t1, 30
    ctx->r11 = S32(ctx->r9 << 30);
    // 0x801089C4: bgezl       $t3, L_801089FC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801089C8: lh          $t9, 0x96($a2)
        ctx->r25 = MEM_H(ctx->r6, 0X96);
            goto L_801089FC;
    }
    goto skip_2;
    // 0x801089C8: lh          $t9, 0x96($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X96);
    skip_2:
    // 0x801089CC: lbu         $t6, 0x7B($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X7B);
    // 0x801089D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801089D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801089D8: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x801089DC: sb          $t7, 0x7B($t4)
    MEM_B(0X7B, ctx->r12) = ctx->r15;
    // 0x801089E0: jal         0x80089CD8
    // 0x801089E4: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x801089E4: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801089E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801089EC: jal         0x80089CE8
    // 0x801089F0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x801089F0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x801089F4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x801089F8: lh          $t9, 0x96($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X96);
L_801089FC:
    // 0x801089FC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80108A00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80108A04: bgez        $t9, L_80108A10
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80108A08: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80108A10;
    }
    // 0x80108A08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80108A0C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_80108A10:
    // 0x80108A10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80108A14: jal         0x80108658
    // 0x80108A18: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80108658(rdram, ctx);
        goto after_2;
    // 0x80108A18: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80108A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80108A20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80108A24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80108A28: jr          $ra
    // 0x80108A2C: nop

    return;
    // 0x80108A2C: nop

;}
RECOMP_FUNC void chbigterrysbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1056, 0X3C8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x3C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1056, 0X3C8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x3C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1056, 0X3C8));
;}
RECOMP_FUNC void bskazstilt_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080107C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801084: jal         0x800839B8
    // 0x80801088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080108C: jal         0x80800234
    // 0x80801090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800234_bskazstilt(rdram, ctx);
        goto after_1;
    // 0x80801090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080109C: jr          $ra
    // 0x808010A0: nop

    return;
    // 0x808010A0: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088858: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088858);
    return;
    // 0x8008885C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80090248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009024C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090250: jal         0x800F54E4
    // 0x80090254: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090254: nop

    after_0:
    // 0x80090258: jal         0x800F6C5C
    // 0x8009025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_1;
    // 0x8009025C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090268: jr          $ra
    // 0x8009026C: nop

    return;
    // 0x8009026C: nop

;}
RECOMP_FUNC void func_80800078_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800084: jal         0x800CEAD0
    // 0x80800088: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CEAD0(rdram, ctx);
        goto after_0;
    // 0x80800088: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_808085A8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808085A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808085AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808085B0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808085B4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x808085B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808085BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808085C0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x808085C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808085C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808085CC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_808085D0:
    // 0x808085D0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808085D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808085D8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x808085DC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808085E0: nop

    // 0x808085E4: bc1fl       L_808085F8
    if (!c1cs) {
        // 0x808085E8: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_808085F8;
    }
    goto skip_0;
    // 0x808085E8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x808085EC: b           L_80808620
    // 0x808085F0: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
        goto L_80808620;
    // 0x808085F0: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x808085F4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_808085F8:
    // 0x808085F8: nop

    // 0x808085FC: bc1fl       L_80808610
    if (!c1cs) {
        // 0x80808600: add.s       $f4, $f0, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_80808610;
    }
    goto skip_1;
    // 0x80808600: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    skip_1:
    // 0x80808604: b           L_80808620
    // 0x80808608: sh          $a0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r4;
        goto L_80808620;
    // 0x80808608: sh          $a0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r4;
    // 0x8080860C: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
L_80808610:
    // 0x80808610: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80808614: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80808618: nop

    // 0x8080861C: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_80808620:
    // 0x80808620: bne         $a2, $v0, L_808085D0
    if (ctx->r6 != ctx->r2) {
        // 0x80808624: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_808085D0;
    }
    // 0x80808624: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80808628: jr          $ra
    // 0x8080862C: nop

    return;
    // 0x8080862C: nop

;}
RECOMP_FUNC void func_80800D8C_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D98: jal         0x80101870
    // 0x80800D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DA4: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
    // 0x80800DA8: beql        $a1, $zero, L_80800DF4
    if (ctx->r5 == 0) {
        // 0x80800DAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DF4;
    }
    goto skip_0;
    // 0x80800DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800DB0: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800DB4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800DB8: bgezl       $t8, L_80800DF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DF4;
    }
    goto skip_1;
    // 0x80800DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800DC0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800DC4: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80800DC8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80800DCC: bne         $at, $zero, L_80800DF0
    if (ctx->r1 != 0) {
        // 0x80800DD0: slti        $at, $t9, 0x8
        ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
            goto L_80800DF0;
    }
    // 0x80800DD0: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x80800DD4: beql        $at, $zero, L_80800DF4
    if (ctx->r1 == 0) {
        // 0x80800DD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800DF4;
    }
    goto skip_2;
    // 0x80800DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800DDC: jal         0x80106790
    // 0x80800DE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800DE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80800DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DE8: jal         0x80800FB4
    // 0x80800DEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800FB4_chlavahand(rdram, ctx);
        goto after_2;
    // 0x80800DEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80800DF0:
    // 0x80800DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DF4:
    // 0x80800DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DF8: jr          $ra
    // 0x80800DFC: nop

    return;
    // 0x80800DFC: nop

;}
RECOMP_FUNC void func_80800294_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080029C: jal         0x8009E6EC
    // 0x808002A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808002A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002A4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x808002A8: beq         $v0, $at, L_808002D0
    if (ctx->r2 == ctx->r1) {
        // 0x808002AC: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_808002D0;
    }
    // 0x808002AC: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x808002B0: beq         $v0, $at, L_808002D0
    if (ctx->r2 == ctx->r1) {
        // 0x808002B4: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_808002D0;
    }
    // 0x808002B4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x808002B8: beq         $v0, $at, L_808002D0
    if (ctx->r2 == ctx->r1) {
        // 0x808002BC: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_808002D0;
    }
    // 0x808002BC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x808002C0: beql        $v0, $at, L_808002D4
    if (ctx->r2 == ctx->r1) {
        // 0x808002C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002D4;
    }
    goto skip_0;
    // 0x808002C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002C8: jal         0x8080024C
    // 0x808002CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080024C_bstrexlarge(rdram, ctx);
        goto after_1;
    // 0x808002CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_808002D0:
    // 0x808002D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D4:
    // 0x808002D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void _chicywind_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086470: syscall     326
    recomp_syscall_handler(rdram, ctx, 0x80086470);
    return;
    // 0x80086474: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfirefx_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808007E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007EC: bne         $a1, $at, L_80800830
    if (ctx->r5 != ctx->r1) {
        // 0x808007F0: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800830;
    }
    // 0x808007F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007F4: jal         0x80100094
    // 0x808007F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007FC: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800800: jal         0x8008A038
    // 0x80800804: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800804: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800808: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080080C: lhu         $t6, 0x10($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X10);
    // 0x80800810: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80800814: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800818: beql        $t7, $zero, L_8080083C
    if (ctx->r15 == 0) {
        // 0x8080081C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080083C;
    }
    goto skip_0;
    // 0x8080081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800820: jal         0x80800C18
    // 0x80800824: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C18_chfirefx(rdram, ctx);
        goto after_2;
    // 0x80800824: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800828: b           L_8080083C
    // 0x8080082C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080083C;
    // 0x8080082C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800830:
    // 0x80800830: b           L_8080083C
    // 0x80800834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080083C;
    // 0x80800834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080083C:
    // 0x8080083C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800844: jr          $ra
    // 0x80800848: nop

    return;
    // 0x80800848: nop

;}
RECOMP_FUNC void plcamera_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080019C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001A8: jal         0x800F5EF8
    // 0x808001AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x808001AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001B0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001EC;
    }
    // 0x808001B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B8: jal         0x80110014
    // 0x808001BC: nop

    func_80110014(rdram, ctx);
        goto after_1;
    // 0x808001BC: nop

    after_1:
    // 0x808001C0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001C4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001EC;
    }
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808001CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001D8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808001DC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808001E4: jal         0x80089440
    // 0x808001E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _ncbadeflect_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808001E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
L_808001EC:
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void badrone_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001C0: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x808001C4: jal         0x800EE7F8
    // 0x808001C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x808001CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001D4: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x808001D8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x808001DC: bnel        $t8, $at, L_80800204
    if (ctx->r24 != ctx->r1) {
        // 0x808001E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001E4: jal         0x8009BAF4
    // 0x808001E8: nop

    func_8009BAF4(rdram, ctx);
        goto after_1;
    // 0x808001E8: nop

    after_1:
    // 0x808001EC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808001F0: bne         $v0, $at, L_80800200
    if (ctx->r2 != ctx->r1) {
        // 0x808001F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800200;
    }
    // 0x808001F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: jal         0x80084E18
    // 0x808001FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808001FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80800200:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800204:
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80801C84_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C8C: lbu         $t6, 0x5E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5E);
    // 0x80801C90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801C94: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80801C98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80801C9C: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80801CA0: bgez        $t6, L_80801CB8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80801CA4: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80801CB8;
    }
    // 0x80801CA4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801CA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801CAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801CB0: nop

    // 0x80801CB4: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_80801CB8:
    // 0x80801CB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X2A18) << 16);
    // 0x80801CBC: lwc1        $f8, 0x2A18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X2A18));
    // 0x80801CC0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80801CC4: jal         0x800F10B4
    // 0x80801CC8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80801CC8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80801CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801CD4: jr          $ra
    // 0x80801CD8: nop

    return;
    // 0x80801CD8: nop

;}
RECOMP_FUNC void badata_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808009B0: jal         0x80800000
    // 0x808009B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x808009B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808009B8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808009BC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808009C0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(473, 0X2498) << 16);
    // 0x808009C4: addiu       $t7, $t7, 0x2498
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(473, 0X2498));
    // 0x808009C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808009CC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808009D0: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x808009D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808009D8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x808009DC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808009E0: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808009E4: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x808009E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009F0: jr          $ra
    // 0x808009F4: nop

    return;
    // 0x808009F4: nop

;}
RECOMP_FUNC void func_80800024_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800034: jal         0x80100094
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080003C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x80800048: jal         0x80089F70
    // 0x8080004C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x8080092C
    // 0x80800058: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_2;
    // 0x80800058: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080005C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800060: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800064: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80800068: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080006C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void _suspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DB0: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DB0);
    return;
    // 0x80089DB4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800064_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800070: jal         0x8009E6EC
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800078: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8080007C: beq         $v0, $at, L_808000AC
    if (ctx->r2 == ctx->r1) {
        // 0x80800080: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000AC;
    }
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: addiu       $at, $zero, 0x85
    ctx->r1 = ADD32(0, 0X85);
    // 0x80800088: bne         $v0, $at, L_808000D4
    if (ctx->r2 != ctx->r1) {
        // 0x8080008C: nop
    
            goto L_808000D4;
    }
    // 0x8080008C: nop

    // 0x80800090: jal         0x80099A58
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_1;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800851F8
    // 0x808000A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _basub_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x808000A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808000A4: b           L_808000E0
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000E0;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: jal         0x800995B8
    // 0x808000B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800995B8(rdram, ctx);
        goto after_3;
    // 0x808000B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x8009E830
    // 0x808000BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x808000BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x8009E5C8
    // 0x808000C8: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x808000C8: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_5:
    // 0x808000CC: b           L_808000E0
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000E0;
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D4:
    // 0x808000D4: jal         0x80099B94
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_6;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E0:
    // 0x808000E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80801320_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801328: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080132C: jal         0x8009E0DC
    // 0x80801330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E0DC(rdram, ctx);
        goto after_0;
    // 0x80801330: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801334: jal         0x8009E100
    // 0x80801338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E100(rdram, ctx);
        goto after_1;
    // 0x80801338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080133C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801340: jal         0x8009E74C
    // 0x80801344: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E74C(rdram, ctx);
        goto after_2;
    // 0x80801344: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x80801348: beq         $v0, $zero, L_80801358
    if (ctx->r2 == 0) {
        // 0x8080134C: nop
    
            goto L_80801358;
    }
    // 0x8080134C: nop

    // 0x80801350: jal         0x808000AC
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_bskazfly(rdram, ctx);
        goto after_3;
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80801358:
    // 0x80801358: jal         0x8009E704
    // 0x8080135C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getNextState(rdram, ctx);
        goto after_4;
    // 0x8080135C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801360: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x80801364: beq         $v0, $at, L_80801374
    if (ctx->r2 == ctx->r1) {
        // 0x80801368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801374;
    }
    // 0x80801368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080136C: addiu       $at, $zero, 0x162
    ctx->r1 = ADD32(0, 0X162);
    // 0x80801370: bne         $v0, $at, L_80801380
    if (ctx->r2 != ctx->r1) {
        // 0x80801374: addiu       $a1, $zero, 0x4435
        ctx->r5 = ADD32(0, 0X4435);
            goto L_80801380;
    }
L_80801374:
    // 0x80801374: addiu       $a1, $zero, 0x4435
    ctx->r5 = ADD32(0, 0X4435);
    // 0x80801378: jal         0x8009DBF0
    // 0x8080137C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DBF0(rdram, ctx);
        goto after_5;
    // 0x8080137C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
L_80801380:
    // 0x80801380: jal         0x80800188
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800188_bskazfly(rdram, ctx);
        goto after_6;
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080138C: jal         0x800A0CF4
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_7;
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080139C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013A0: jr          $ra
    // 0x808013A4: nop

    return;
    // 0x808013A4: nop

;}
RECOMP_FUNC void func_8009E8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E8B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E8B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E8BC: jal         0x800C6E58
    // 0x8009E8C0: nop

    func_800C6E58(rdram, ctx);
        goto after_0;
    // 0x8009E8C0: nop

    after_0:
    // 0x8009E8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E8C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E8CC: jr          $ra
    // 0x8009E8D0: nop

    return;
    // 0x8009E8D0: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025D8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808025DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808025E0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808025E4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808025E8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808025EC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x808025F0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x808025F4: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x808025F8: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x808025FC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80802600: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802604: bne         $t6, $zero, L_80802614
    if (ctx->r14 != 0) {
        // 0x80802608: nop
    
            goto L_80802614;
    }
    // 0x80802608: nop

    // 0x8080260C: b           L_80802784
    // 0x80802610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802784;
    // 0x80802610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802614:
    // 0x80802614: jal         0x800BEB58
    // 0x80802618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB58(rdram, ctx);
        goto after_0;
    // 0x80802618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080261C: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x80802620: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80802624: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x80802628: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8080262C: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80802630: sll         $s2, $s2, 3
    ctx->r18 = S32(ctx->r18 << 3);
    // 0x80802634: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80802638: jal         0x800D674C
    // 0x8080263C: lhu         $a0, 0x40($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X40);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x8080263C: lhu         $a0, 0x40($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X40);
    after_1:
    // 0x80802640: beq         $v0, $zero, L_80802780
    if (ctx->r2 == 0) {
        // 0x80802644: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80802780;
    }
    // 0x80802644: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802648: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8080264C: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80802650: jal         0x800D62E4
    // 0x80802654: lhu         $a0, 0x40($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X40);
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x80802654: lhu         $a0, 0x40($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X40);
    after_2:
    // 0x80802658: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8080265C: addiu       $at, $zero, 0x1F00
    ctx->r1 = ADD32(0, 0X1F00);
    // 0x80802660: andi        $t2, $t1, 0x1F00
    ctx->r10 = ctx->r9 & 0X1F00;
    // 0x80802664: beql        $t2, $at, L_808026CC
    if (ctx->r10 == ctx->r1) {
        // 0x80802668: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_808026CC;
    }
    goto skip_0;
    // 0x80802668: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8080266C: jal         0x800B2720
    // 0x80802670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2720(rdram, ctx);
        goto after_3;
    // 0x80802670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802674: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80802678: jal         0x800B2840
    // 0x8080267C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2840(rdram, ctx);
        goto after_4;
    // 0x8080267C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802680: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x80802684: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802688: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080268C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80802690: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80802694: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80802698: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8080269C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808026A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808026A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808026A8: addu        $a2, $t3, $s2
    ctx->r6 = ADD32(ctx->r11, ctx->r18);
    // 0x808026AC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808026B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808026B4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x808026B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x808026BC: jal         0x800AB868
    // 0x808026C0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_800AB868(rdram, ctx);
        goto after_5;
    // 0x808026C0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_5:
    // 0x808026C4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808026C8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_808026CC:
    // 0x808026CC: beql        $t8, $zero, L_808026E8
    if (ctx->r24 == 0) {
        // 0x808026D0: lw          $t9, 0x68($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X68);
            goto L_808026E8;
    }
    goto skip_1;
    // 0x808026D0: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    skip_1:
    // 0x808026D4: jal         0x800BEB58
    // 0x808026D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BEB58(rdram, ctx);
        goto after_6;
    // 0x808026D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808026DC: b           L_80802784
    // 0x808026E0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
        goto L_80802784;
    // 0x808026E0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x808026E4: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
L_808026E8:
    // 0x808026E8: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x808026EC: lhu         $v0, 0x42($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X42);
    // 0x808026F0: beql        $v0, $zero, L_80802784
    if (ctx->r2 == 0) {
        // 0x808026F4: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_80802784;
    }
    goto skip_2;
    // 0x808026F4: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x808026F8: jal         0x800D674C
    // 0x808026FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_7;
    // 0x808026FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80802700: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x80802704: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802708: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8080270C: jal         0x800D62E4
    // 0x80802710: lhu         $a0, 0x42($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X42);
    func_800D62E4(rdram, ctx);
        goto after_8;
    // 0x80802710: lhu         $a0, 0x42($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X42);
    after_8:
    // 0x80802714: jal         0x800B2720
    // 0x80802718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2720(rdram, ctx);
        goto after_9;
    // 0x80802718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080271C: beql        $v0, $zero, L_80802784
    if (ctx->r2 == 0) {
        // 0x80802720: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_80802784;
    }
    goto skip_3;
    // 0x80802720: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x80802724: jal         0x800B2720
    // 0x80802728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2720(rdram, ctx);
        goto after_10;
    // 0x80802728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080272C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80802730: jal         0x800B2840
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2840(rdram, ctx);
        goto after_11;
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80802738: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x8080273C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802740: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802744: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80802748: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8080274C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80802750: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80802754: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80802758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080275C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802760: addu        $a2, $t3, $s2
    ctx->r6 = ADD32(ctx->r11, ctx->r18);
    // 0x80802764: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802768: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8080276C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80802770: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80802774: jal         0x800AB868
    // 0x80802778: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_800AB868(rdram, ctx);
        goto after_12;
    // 0x80802778: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_12:
    // 0x8080277C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80802780:
    // 0x80802780: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
L_80802784:
    // 0x80802784: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80802788: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8080278C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80802790: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80802794: jr          $ra
    // 0x80802798: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80802798: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80801A04_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801A08: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x80801A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801A14: bne         $at, $zero, L_80801A40
    if (ctx->r1 != 0) {
        // 0x80801A18: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80801A40;
    }
    // 0x80801A18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80801A1C: addiu       $t6, $a1, -0x8D
    ctx->r14 = ADD32(ctx->r5, -0X8D);
    // 0x80801A20: sltiu       $at, $t6, 0x29
    ctx->r1 = ctx->r14 < 0X29 ? 1 : 0;
    // 0x80801A24: beq         $at, $zero, L_80801DC4
    if (ctx->r1 == 0) {
        // 0x80801A28: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801DC4;
    }
    // 0x80801A28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801A2C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X983C) << 16);
    // 0x80801A30: addu        $at, $at, $t6
    gpr jr_addend_80801A38 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801A34: lw          $t6, -0x67C4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X983C));
    // 0x80801A38: jr          $t6
    // 0x80801A3C: nop

    switch (jr_addend_80801A38 >> 2) {
        case 0: goto L_80801D7C; break;
        case 1: goto L_80801DC4; break;
        case 2: goto L_80801DC4; break;
        case 3: goto L_80801D6C; break;
        case 4: goto L_80801DC4; break;
        case 5: goto L_80801DC4; break;
        case 6: goto L_80801DC4; break;
        case 7: goto L_80801DC4; break;
        case 8: goto L_80801AE0; break;
        case 9: goto L_80801C38; break;
        case 10: goto L_80801DC4; break;
        case 11: goto L_80801DC4; break;
        case 12: goto L_80801DC4; break;
        case 13: goto L_80801DC4; break;
        case 14: goto L_80801DC4; break;
        case 15: goto L_80801B64; break;
        case 16: goto L_80801DC4; break;
        case 17: goto L_80801DC4; break;
        case 18: goto L_80801C64; break;
        case 19: goto L_80801DC4; break;
        case 20: goto L_80801DC4; break;
        case 21: goto L_80801D20; break;
        case 22: goto L_80801DC4; break;
        case 23: goto L_80801DC4; break;
        case 24: goto L_80801DC4; break;
        case 25: goto L_80801DC4; break;
        case 26: goto L_80801DC4; break;
        case 27: goto L_80801DC4; break;
        case 28: goto L_80801DC4; break;
        case 29: goto L_80801DC4; break;
        case 30: goto L_80801DC4; break;
        case 31: goto L_80801DC4; break;
        case 32: goto L_80801DC4; break;
        case 33: goto L_80801DC4; break;
        case 34: goto L_80801DC4; break;
        case 35: goto L_80801DC4; break;
        case 36: goto L_80801DC4; break;
        case 37: goto L_80801DC4; break;
        case 38: goto L_80801DC4; break;
        case 39: goto L_80801DC4; break;
        case 40: goto L_80801DB0; break;
        default: switch_error(__func__, 0x80801A38, 0x8080983C);
    }
    // 0x80801A3C: nop

L_80801A40:
    // 0x80801A40: addiu       $t7, $a1, -0xB
    ctx->r15 = ADD32(ctx->r5, -0XB);
    // 0x80801A44: sltiu       $at, $t7, 0x4D
    ctx->r1 = ctx->r15 < 0X4D ? 1 : 0;
    // 0x80801A48: beq         $at, $zero, L_80801DC4
    if (ctx->r1 == 0) {
        // 0x80801A4C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801DC4;
    }
    // 0x80801A4C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801A50: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X98E0) << 16);
    // 0x80801A54: addu        $at, $at, $t7
    gpr jr_addend_80801A5C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801A58: lw          $t7, -0x6720($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X98E0));
    // 0x80801A5C: jr          $t7
    // 0x80801A60: nop

    switch (jr_addend_80801A5C >> 2) {
        case 0: goto L_80801AF0; break;
        case 1: goto L_80801DC4; break;
        case 2: goto L_80801DC4; break;
        case 3: goto L_80801DC4; break;
        case 4: goto L_80801DC4; break;
        case 5: goto L_80801DC4; break;
        case 6: goto L_80801DC4; break;
        case 7: goto L_80801DC4; break;
        case 8: goto L_80801DC4; break;
        case 9: goto L_80801DC4; break;
        case 10: goto L_80801DC4; break;
        case 11: goto L_80801DC4; break;
        case 12: goto L_80801DC4; break;
        case 13: goto L_80801DC4; break;
        case 14: goto L_80801DC4; break;
        case 15: goto L_80801DC4; break;
        case 16: goto L_80801DC4; break;
        case 17: goto L_80801DC4; break;
        case 18: goto L_80801DC4; break;
        case 19: goto L_80801DC4; break;
        case 20: goto L_80801B4C; break;
        case 21: goto L_80801AB8; break;
        case 22: goto L_80801DC4; break;
        case 23: goto L_80801DC4; break;
        case 24: goto L_80801DC4; break;
        case 25: goto L_80801DC4; break;
        case 26: goto L_80801DC4; break;
        case 27: goto L_80801DC4; break;
        case 28: goto L_80801DC4; break;
        case 29: goto L_80801DC4; break;
        case 30: goto L_80801CF4; break;
        case 31: goto L_80801D0C; break;
        case 32: goto L_80801DC4; break;
        case 33: goto L_80801DC4; break;
        case 34: goto L_80801DC4; break;
        case 35: goto L_80801B04; break;
        case 36: goto L_80801B20; break;
        case 37: goto L_80801DC4; break;
        case 38: goto L_80801DC4; break;
        case 39: goto L_80801DC4; break;
        case 40: goto L_80801DC4; break;
        case 41: goto L_80801DC4; break;
        case 42: goto L_80801DC4; break;
        case 43: goto L_80801DC4; break;
        case 44: goto L_80801DC4; break;
        case 45: goto L_80801DC4; break;
        case 46: goto L_80801DC4; break;
        case 47: goto L_80801DC4; break;
        case 48: goto L_80801DC4; break;
        case 49: goto L_80801DC4; break;
        case 50: goto L_80801BC4; break;
        case 51: goto L_80801DC4; break;
        case 52: goto L_80801DC4; break;
        case 53: goto L_80801B7C; break;
        case 54: goto L_80801DC4; break;
        case 55: goto L_80801DC4; break;
        case 56: goto L_80801DC4; break;
        case 57: goto L_80801DC4; break;
        case 58: goto L_80801DC4; break;
        case 59: goto L_80801DC4; break;
        case 60: goto L_80801DC4; break;
        case 61: goto L_80801DC4; break;
        case 62: goto L_80801A64; break;
        case 63: goto L_80801DC4; break;
        case 64: goto L_80801DC4; break;
        case 65: goto L_80801DC4; break;
        case 66: goto L_80801DC4; break;
        case 67: goto L_80801DC4; break;
        case 68: goto L_80801DC4; break;
        case 69: goto L_80801DC4; break;
        case 70: goto L_80801DC4; break;
        case 71: goto L_80801B3C; break;
        case 72: goto L_80801DC4; break;
        case 73: goto L_80801DC4; break;
        case 74: goto L_80801DC4; break;
        case 75: goto L_80801DC4; break;
        case 76: goto L_80801A8C; break;
        default: switch_error(__func__, 0x80801A5C, 0x808098E0);
    }
    // 0x80801A60: nop

L_80801A64:
    // 0x80801A64: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x80801A68: jal         0x801084B0
    // 0x80801A6C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80801A6C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80801A70: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80801A74: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80801A78: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
    // 0x80801A7C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80801A80: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80801A84: b           L_80801DCC
    // 0x80801A88: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
        goto L_80801DCC;
    // 0x80801A88: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
L_80801A8C:
    // 0x80801A8C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801A90: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80801A94: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80801A98: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x80801A9C: and         $t3, $a2, $at
    ctx->r11 = ctx->r6 & ctx->r1;
    // 0x80801AA0: srl         $a2, $t3, 16
    ctx->r6 = S32(U32(ctx->r11) >> 16);
    // 0x80801AA4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80801AA8: jal         0x80802718
    // 0x80801AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802718_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80801AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80801AB0: b           L_80801DD4
    // 0x80801AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801DD4;
    // 0x80801AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801AB8:
    // 0x80801AB8: jal         0x80101080
    // 0x80801ABC: nop

    func_80101080(rdram, ctx);
        goto after_2;
    // 0x80801ABC: nop

    after_2:
    // 0x80801AC0: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801AC4: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80801AC8: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    // 0x80801ACC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801AD0: jal         0x80803078
    // 0x80801AD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80803078_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80801AD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80801AD8: b           L_80801DD0
    // 0x80801ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801AE0:
    // 0x80801AE0: jal         0x80801DE0
    // 0x80801AE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80801DE0_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80801AE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80801AE8: b           L_80801DD0
    // 0x80801AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801AF0:
    // 0x80801AF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801AF4: jal         0x80802AB8
    // 0x80801AF8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80802AB8_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80801AF8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x80801AFC: b           L_80801DD4
    // 0x80801B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801DD4;
    // 0x80801B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B04:
    // 0x80801B04: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801B08: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80801B0C: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x80801B10: jal         0x80803694
    // 0x80801B14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80803694_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80801B14: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80801B18: b           L_80801DD0
    // 0x80801B1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801B1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B20:
    // 0x80801B20: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801B24: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80801B28: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x80801B2C: jal         0x808039C0
    // 0x80801B30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808039C0_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80801B30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80801B34: b           L_80801DD0
    // 0x80801B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B3C:
    // 0x80801B3C: jal         0x808029C8
    // 0x80801B40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808029C8_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80801B40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80801B44: b           L_80801DD0
    // 0x80801B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B4C:
    // 0x80801B4C: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801B50: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80801B54: jal         0x80800568
    // 0x80801B58: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800568_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80801B58: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x80801B5C: b           L_80801DD0
    // 0x80801B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B64:
    // 0x80801B64: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801B68: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80801B6C: jal         0x808005DC
    // 0x80801B70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808005DC_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80801B70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_10:
    // 0x80801B74: b           L_80801DD0
    // 0x80801B78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801B78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B7C:
    // 0x80801B7C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801B80: jal         0x80100094
    // 0x80801B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80801B84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801B88: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x80801B8C: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801B90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801B94: beq         $t5, $zero, L_80801BB4
    if (ctx->r13 == 0) {
        // 0x80801B98: nop
    
            goto L_80801BB4;
    }
    // 0x80801B98: nop

    // 0x80801B9C: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80801BA0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80801BA4: jal         0x808086E8
    // 0x80801BA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808086E8_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80801BA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_12:
    // 0x80801BAC: b           L_80801DD0
    // 0x80801BB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801BB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801BB4:
    // 0x80801BB4: jal         0x80806DC4
    // 0x80801BB8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_80806DC4_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x80801BB8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_13:
    // 0x80801BBC: b           L_80801DD0
    // 0x80801BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801BC4:
    // 0x80801BC4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80801BC8: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80801BCC: beq         $at, $zero, L_80801DCC
    if (ctx->r1 == 0) {
        // 0x80801BD0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801DCC;
    }
    // 0x80801BD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801BD4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A14) << 16);
    // 0x80801BD8: addu        $at, $at, $t6
    gpr jr_addend_80801BE0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801BDC: lw          $t6, -0x65EC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A14));
    // 0x80801BE0: jr          $t6
    // 0x80801BE4: nop

    switch (jr_addend_80801BE0 >> 2) {
        case 0: goto L_80801BE8; break;
        case 1: goto L_80801BFC; break;
        case 2: goto L_80801BFC; break;
        case 3: goto L_80801DCC; break;
        case 4: goto L_80801C10; break;
        case 5: goto L_80801C24; break;
        default: switch_error(__func__, 0x80801BE0, 0x80809A14);
    }
    // 0x80801BE4: nop

L_80801BE8:
    // 0x80801BE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801BEC: jal         0x80806CF8
    // 0x80801BF0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80806CF8_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x80801BF0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_14:
    // 0x80801BF4: b           L_80801DD0
    // 0x80801BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801BFC:
    // 0x80801BFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801C00: jal         0x80807304
    // 0x80801C04: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80807304_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x80801C04: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x80801C08: b           L_80801DD0
    // 0x80801C0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801C0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C10:
    // 0x80801C10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801C14: jal         0x80807E3C
    // 0x80801C18: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80807E3C_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x80801C18: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_16:
    // 0x80801C1C: b           L_80801DD0
    // 0x80801C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C24:
    // 0x80801C24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801C28: jal         0x808085E0
    // 0x80801C2C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_808085E0_chdiggerboss(rdram, ctx);
        goto after_17;
    // 0x80801C2C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_17:
    // 0x80801C30: b           L_80801DD0
    // 0x80801C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C38:
    // 0x80801C38: jal         0x800D395C
    // 0x80801C3C: nop

    func_800D395C(rdram, ctx);
        goto after_18;
    // 0x80801C3C: nop

    after_18:
    // 0x80801C40: bne         $v0, $zero, L_80801C50
    if (ctx->r2 != 0) {
        // 0x80801C44: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801C50;
    }
    // 0x80801C44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801C48: b           L_80801DD0
    // 0x80801C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801DD0;
    // 0x80801C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C50:
    // 0x80801C50: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80801C54: jal         0x80803660
    // 0x80801C58: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x80801C58: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_19:
    // 0x80801C5C: b           L_80801DD0
    // 0x80801C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C64:
    // 0x80801C64: jal         0x80802228
    // 0x80801C68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x80801C68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_20:
    // 0x80801C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801C70: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801C74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80801C78:
    // 0x80801C78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801C7C: jal         0x80805448
    // 0x80801C80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x80801C80: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_21:
    // 0x80801C84: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801C88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801C8C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80801C90: bnel        $a1, $at, L_80801C78
    if (ctx->r5 != ctx->r1) {
        // 0x80801C94: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80801C78;
    }
    goto skip_0;
    // 0x80801C94: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80801C98: jal         0x800FDC28
    // 0x80801C9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_22;
    // 0x80801C9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x80801CA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801CA8: jal         0x80800618
    // 0x80801CAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800618_chdiggerboss(rdram, ctx);
        goto after_23;
    // 0x80801CAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80801CB0: jal         0x80802288
    // 0x80801CB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802288_chdiggerboss(rdram, ctx);
        goto after_24;
    // 0x80801CB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_24:
    // 0x80801CB8: beq         $v0, $zero, L_80801CE0
    if (ctx->r2 == 0) {
        // 0x80801CBC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801CE0;
    }
    // 0x80801CBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801CC0: jal         0x800D395C
    // 0x80801CC4: nop

    func_800D395C(rdram, ctx);
        goto after_25;
    // 0x80801CC4: nop

    after_25:
    // 0x80801CC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801CCC: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80801CD0: jal         0x80803BE8
    // 0x80801CD4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_26;
    // 0x80801CD4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_26:
    // 0x80801CD8: b           L_80801DD0
    // 0x80801CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CE0:
    // 0x80801CE0: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x80801CE4: jal         0x80803BE8
    // 0x80801CE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_27;
    // 0x80801CE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_27:
    // 0x80801CEC: b           L_80801DD0
    // 0x80801CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CF4:
    // 0x80801CF4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801CFC: jal         0x800897C0
    // 0x80801D00: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_28;
    // 0x80801D00: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_28:
    // 0x80801D04: b           L_80801DD0
    // 0x80801D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D0C:
    // 0x80801D0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801D10: jal         0x800897C8
    // 0x80801D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_29;
    // 0x80801D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80801D18: b           L_80801DD0
    // 0x80801D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D20:
    // 0x80801D20: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801D24: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x80801D28: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x80801D2C: bgez        $t0, L_80801D44
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801D30: nop
    
            goto L_80801D44;
    }
    // 0x80801D30: nop

    // 0x80801D34: jal         0x80802288
    // 0x80801D38: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80802288_chdiggerboss(rdram, ctx);
        goto after_30;
    // 0x80801D38: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_30:
    // 0x80801D3C: bne         $v0, $zero, L_80801D4C
    if (ctx->r2 != 0) {
        // 0x80801D40: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801D4C;
    }
    // 0x80801D40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80801D44:
    // 0x80801D44: b           L_80801DD0
    // 0x80801D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801DD0;
    // 0x80801D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801D4C:
    // 0x80801D4C: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(1480, 0XA300) << 16);
    // 0x80801D50: jal         0x80802298
    // 0x80801D54: addiu       $a1, $a1, -0x5D00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1480, 0XA300));
    func_80802298_chdiggerboss(rdram, ctx);
        goto after_31;
    // 0x80801D54: addiu       $a1, $a1, -0x5D00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1480, 0XA300));
    after_31:
    // 0x80801D58: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(1480, 0XA300) << 16);
    // 0x80801D5C: jal         0x80101074
    // 0x80801D60: addiu       $a0, $a0, -0x5D00
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA300));
    func_80101074(rdram, ctx);
        goto after_32;
    // 0x80801D60: addiu       $a0, $a0, -0x5D00
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA300));
    after_32:
    // 0x80801D64: b           L_80801DD0
    // 0x80801D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D6C:
    // 0x80801D6C: jal         0x80809310
    // 0x80801D70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80809310_chdiggerboss(rdram, ctx);
        goto after_33;
    // 0x80801D70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_33:
    // 0x80801D74: b           L_80801DD0
    // 0x80801D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801D7C:
    // 0x80801D7C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801D80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801D84: jal         0x800EE7F8
    // 0x80801D88: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_34;
    // 0x80801D88: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_34:
    // 0x80801D8C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80801D90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D94: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801D98: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801D9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801DA0: jal         0x80101010
    // 0x80801DA4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_80101010(rdram, ctx);
        goto after_35;
    // 0x80801DA4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_35:
    // 0x80801DA8: b           L_80801DD0
    // 0x80801DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801DB0:
    // 0x80801DB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801DB4: jal         0x80806CA4
    // 0x80801DB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80806CA4_chdiggerboss(rdram, ctx);
        goto after_36;
    // 0x80801DB8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_36:
    // 0x80801DBC: b           L_80801DD0
    // 0x80801DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801DD0;
    // 0x80801DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801DC4:
    // 0x80801DC4: b           L_80801DD0
    // 0x80801DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801DD0;
    // 0x80801DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801DCC:
    // 0x80801DCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801DD0:
    // 0x80801DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801DD4:
    // 0x80801DD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801DD8: jr          $ra
    // 0x80801DDC: nop

    return;
    // 0x80801DDC: nop

;}
RECOMP_FUNC void func_808012E4_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808012E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808012F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808012F4: jal         0x80090178
    // 0x808012F8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x808012F8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x808012FC: beq         $v0, $zero, L_80801354
    if (ctx->r2 == 0) {
        // 0x80801300: addiu       $a0, $zero, 0x3FC
        ctx->r4 = ADD32(0, 0X3FC);
            goto L_80801354;
    }
    // 0x80801300: addiu       $a0, $zero, 0x3FC
    ctx->r4 = ADD32(0, 0X3FC);
    // 0x80801304: jal         0x80089C30
    // 0x80801308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080130C: jal         0x800F54E4
    // 0x80801310: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801310: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801318: jal         0x800F5A00
    // 0x8080131C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x8080131C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80801320: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801324: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801328: jal         0x800EFC7C
    // 0x8080132C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EFC7C(rdram, ctx);
        goto after_4;
    // 0x8080132C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x80801330: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801338: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080133C: nop

    // 0x80801340: bc1fl       L_8080135C
    if (!c1cs) {
        // 0x80801344: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080135C;
    }
    goto skip_0;
    // 0x80801344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080134C: b           L_8080135C
    // 0x80801350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080135C;
    // 0x80801350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801354:
    // 0x80801354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080135C:
    // 0x8080135C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801360: jr          $ra
    // 0x80801364: nop

    return;
    // 0x80801364: nop

;}
RECOMP_FUNC void sukickball_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D24: jal         0x80100094
    // 0x80800D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D2C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D34: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D38: lbu         $v0, 0x34($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X34);
    // 0x80800D3C: jr          $ra
    // 0x80800D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _ncbakaztorp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089728: syscall     791
    recomp_syscall_handler(rdram, ctx, 0x80089728);
    return;
    // 0x8008972C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfactorymagnet_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FAC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2284, 0X2A4C) << 16);
    // 0x80801FB0: jr          $ra
    // 0x80801FB4: addiu       $v0, $v0, 0x2A4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2A4C));
    return;
    // 0x80801FB4: addiu       $v0, $v0, 0x2A4C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2A4C));
;}
RECOMP_FUNC void _sudeflect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F20: syscall     816
    recomp_syscall_handler(rdram, ctx, 0x80089F20);
    return;
    // 0x80089F24: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DFB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFB7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DFB80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFB84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DFB88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DFB8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800DFB90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800DFB94: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFB98: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFB9C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFBA0: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800DFBA4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800DFBA8: jal         0x800D9600
    // 0x800DFBAC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800D9600(rdram, ctx);
        goto after_0;
    // 0x800DFBAC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800DFBB0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800DFBB4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800DFBB8: jal         0x800EE7F8
    // 0x800DFBBC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800DFBBC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_1:
    // 0x800DFBC0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800DFBC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800DFBC8: jal         0x800EE7F8
    // 0x800DFBCC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800DFBCC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x800DFBD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFBD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DFBD8: jr          $ra
    // 0x800DFBDC: nop

    return;
    // 0x800DFBDC: nop

;}
