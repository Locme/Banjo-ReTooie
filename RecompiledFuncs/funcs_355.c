#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bssplitup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080011C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(364, 0X700) << 16);
    // 0x80800120: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800124: jr          $ra
    // 0x80800128: lw          $v0, 0x700($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X700));
    return;
    // 0x80800128: lw          $v0, 0x700($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(364, 0X700));
;}
RECOMP_FUNC void func_808004D8_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808004E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004EC: beq         $a1, $at, L_80800580
    if (ctx->r5 == ctx->r1) {
        // 0x808004F0: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800580;
    }
    // 0x808004F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808004F4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808004F8: beq         $a1, $at, L_80800510
    if (ctx->r5 == ctx->r1) {
        // 0x808004FC: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800510;
    }
    // 0x808004FC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800500: beq         $a1, $at, L_808005A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800504: nop
    
            goto L_808005A8;
    }
    // 0x80800504: nop

    // 0x80800508: b           L_808005F0
    // 0x8080050C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x8080050C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800510:
    // 0x80800510: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x80800514: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800520: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
    // 0x80800524: jal         0x80800604
    // 0x80800528: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80800604_chstatuebossbits(rdram, ctx);
        goto after_0;
    // 0x80800528: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080052C: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x80800530: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800534: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800538: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8080053C: bne         $at, $zero, L_808005EC
    if (ctx->r1 != 0) {
        // 0x80800540: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808005EC;
    }
    // 0x80800540: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800544: jal         0x800EC398
    // 0x80800548: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EC398(rdram, ctx);
        goto after_1;
    // 0x80800548: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080054C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800550: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080055C: jal         0x80086670
    // 0x80800560: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800560: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800564: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1424, 0X85C) << 16);
    // 0x80800568: addiu       $a2, $a2, 0x85C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1424, 0X85C));
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x80089D18
    // 0x80800574: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800574: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800578: b           L_808005F0
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x8080057C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800580:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x80101FDC
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x80103110
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800598: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080059C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005A0: b           L_808005EC
    // 0x808005A4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005EC;
    // 0x808005A4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808005A8:
    // 0x808005A8: jal         0x80101080
    // 0x808005AC: nop

    func_80101080(rdram, ctx);
        goto after_6;
    // 0x808005AC: nop

    after_6:
    // 0x808005B0: jal         0x80106790
    // 0x808005B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x808005B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808005B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808005BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005C4: jal         0x800866A0
    // 0x808005C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808005C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808005D4: jal         0x800866A0
    // 0x808005D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x808005D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808005DC: b           L_808005F0
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005E4: b           L_808005F0
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
RECOMP_FUNC void _bsbshock_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B10: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B10);
    return;
    // 0x80082B14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _cosectionstor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087848: syscall     634
    recomp_syscall_handler(rdram, ctx, 0x80087848);
    return;
    // 0x8008784C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chfaircoin_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087260: syscall     540
    recomp_syscall_handler(rdram, ctx, 0x80087260);
    return;
    // 0x80087264: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C0BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0BC0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800C0BC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C0BC8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C0BCC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C0BD0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C0BD4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C0BD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C0BDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C0BE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C0BE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C0BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0BEC: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800C0BF0: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x800C0BF4: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800C0BF8: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800C0BFC: addiu       $t8, $t8, -0x5820
    ctx->r24 = ADD32(ctx->r24, -0X5820);
    // 0x800C0C00: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800C0C04: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800C0C08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C0C0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C0C10: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0C14: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C0C18: lui         $t9, 0xFF10
    ctx->r25 = S32(0XFF10 << 16);
    // 0x800C0C1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0C20: addu        $t6, $a1, $at
    ctx->r14 = ADD32(ctx->r5, ctx->r1);
    // 0x800C0C24: ori         $t9, $t9, 0x12F
    ctx->r25 = ctx->r25 | 0X12F;
    // 0x800C0C28: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C0C2C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C0C30: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800C0C34: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x800C0C38: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0C3C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800C0C40: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C0C44: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800C0C48: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800C0C4C:
    // 0x800C0C4C: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x800C0C50: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800C0C54: sll         $s6, $t3, 16
    ctx->r22 = S32(ctx->r11 << 16);
    // 0x800C0C58: sll         $s7, $v1, 2
    ctx->r23 = S32(ctx->r3 << 2);
    // 0x800C0C5C: andi        $t9, $s7, 0xFFF
    ctx->r25 = ctx->r23 & 0XFFF;
    // 0x800C0C60: sra         $t8, $s6, 16
    ctx->r24 = S32(SIGNED(ctx->r22) >> 16);
    // 0x800C0C64: sll         $t6, $fp, 2
    ctx->r14 = S32(ctx->r30 << 2);
    // 0x800C0C68: andi        $fp, $t6, 0xFFF
    ctx->r30 = ctx->r14 & 0XFFF;
    // 0x800C0C6C: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
    // 0x800C0C70: or          $s7, $t9, $zero
    ctx->r23 = ctx->r25 | 0;
    // 0x800C0C74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C0C78: addiu       $t4, $zero, 0x47
    ctx->r12 = ADD32(0, 0X47);
    // 0x800C0C7C: addiu       $s4, $zero, 0x1F
    ctx->r20 = ADD32(0, 0X1F);
    // 0x800C0C80: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800C0C84: addiu       $s3, $zero, 0x80
    ctx->r19 = ADD32(0, 0X80);
    // 0x800C0C88: lh          $t2, 0x4E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4E);
    // 0x800C0C8C: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
L_800C0C90:
    // 0x800C0C90: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800C0C94: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800C0C98: ori         $t9, $t9, 0x12F
    ctx->r25 = ctx->r25 | 0X12F;
    // 0x800C0C9C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C0CA0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0CA4: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800C0CA8: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800C0CAC: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800C0CB0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800C0CB4: jal         0x8002E330
    // 0x800C0CB8: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0CB8: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    after_0:
    // 0x800C0CBC: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800C0CC0: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800C0CC4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800C0CC8: sra         $a2, $t4, 3
    ctx->r6 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800C0CCC: andi        $t6, $a2, 0x1FF
    ctx->r14 = ctx->r6 & 0X1FF;
    // 0x800C0CD0: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800C0CD4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800C0CD8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800C0CDC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800C0CE0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C0CE4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800C0CE8: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800C0CEC: sll         $a3, $s2, 2
    ctx->r7 = S32(ctx->r18 << 2);
    // 0x800C0CF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0CF4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C0CF8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C0CFC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800C0D00: andi        $t7, $a3, 0xFFF
    ctx->r15 = ctx->r7 & 0XFFF;
    // 0x800C0D04: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800C0D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0D0C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C0D10: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800C0D14: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800C0D18: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800C0D1C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0D20: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C0D24: sll         $t0, $s4, 2
    ctx->r8 = S32(ctx->r20 << 2);
    // 0x800C0D28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C0D2C: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x800C0D30: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800C0D34: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x800C0D38: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C0D3C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C0D40: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800C0D44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0D48: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800C0D4C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800C0D50: or          $t6, $t9, $fp
    ctx->r14 = ctx->r25 | ctx->r30;
    // 0x800C0D54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800C0D58: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0D5C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800C0D60: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800C0D64: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C0D68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C0D6C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C0D70: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0D74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C0D78: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800C0D7C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800C0D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0D84: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800C0D88: sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19 << 16);
    // 0x800C0D8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C0D90: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0D94: or          $t9, $a3, $at
    ctx->r25 = ctx->r7 | ctx->r1;
    // 0x800C0D98: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x800C0D9C: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C0DA0: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800C0DA4: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x800C0DA8: or          $t7, $t0, $fp
    ctx->r15 = ctx->r8 | ctx->r30;
    // 0x800C0DAC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0DB0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C0DB4: blez        $t8, L_800C0DC4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C0DB8: sw          $t7, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r15;
            goto L_800C0DC4;
    }
    // 0x800C0DB8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800C0DBC: b           L_800C0DC8
    // 0x800C0DC0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_800C0DC8;
    // 0x800C0DC0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800C0DC4:
    // 0x800C0DC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C0DC8:
    // 0x800C0DC8: blez        $t2, L_800C0DD8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800C0DCC: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_800C0DD8;
    }
    // 0x800C0DCC: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800C0DD0: b           L_800C0DDC
    // 0x800C0DD4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800C0DDC;
    // 0x800C0DD4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800C0DD8:
    // 0x800C0DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0DDC:
    // 0x800C0DDC: andi        $t7, $v1, 0xFFF
    ctx->r15 = ctx->r3 & 0XFFF;
    // 0x800C0DE0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C0DE4: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x800C0DE8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800C0DEC: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800C0DF0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800C0DF4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C0DF8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800C0DFC: blez        $t7, L_800C0E0C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C0E00: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800C0E0C;
    }
    // 0x800C0E00: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C0E04: b           L_800C0E10
    // 0x800C0E08: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800C0E10;
    // 0x800C0E08: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800C0E0C:
    // 0x800C0E0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C0E10:
    // 0x800C0E10: blez        $s6, L_800C0E20
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800C0E14: andi        $t8, $v1, 0xFFF
        ctx->r24 = ctx->r3 & 0XFFF;
            goto L_800C0E20;
    }
    // 0x800C0E14: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x800C0E18: b           L_800C0E24
    // 0x800C0E1C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
        goto L_800C0E24;
    // 0x800C0E1C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_800C0E20:
    // 0x800C0E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0E24:
    // 0x800C0E24: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x800C0E28: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800C0E2C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C0E30: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x800C0E34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C0E38: lui         $t8, 0xE100
    ctx->r24 = S32(0XE100 << 16);
    // 0x800C0E3C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0E40: bgez        $a0, L_800C0E68
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C0E44: sw          $t8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r24;
            goto L_800C0E68;
    }
    // 0x800C0E44: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800C0E48: sll         $v0, $a0, 10
    ctx->r2 = S32(ctx->r4 << 10);
    // 0x800C0E4C: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800C0E50: bgez        $t6, L_800C0E60
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800C0E54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C0E60;
    }
    // 0x800C0E54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C0E58: b           L_800C0E6C
    // 0x800C0E5C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
        goto L_800C0E6C;
    // 0x800C0E5C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800C0E60:
    // 0x800C0E60: b           L_800C0E6C
    // 0x800C0E64: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_800C0E6C;
    // 0x800C0E64: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800C0E68:
    // 0x800C0E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C0E6C:
    // 0x800C0E6C: bgez        $t3, L_800C0E94
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800C0E70: sll         $t6, $s2, 5
        ctx->r14 = S32(ctx->r18 << 5);
            goto L_800C0E94;
    }
    // 0x800C0E70: sll         $t6, $s2, 5
    ctx->r14 = S32(ctx->r18 << 5);
    // 0x800C0E74: sll         $v0, $s6, 10
    ctx->r2 = S32(ctx->r22 << 10);
    // 0x800C0E78: sra         $t9, $v0, 7
    ctx->r25 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800C0E7C: bgez        $t9, L_800C0E8C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C0E80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C0E8C;
    }
    // 0x800C0E80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C0E84: b           L_800C0E98
    // 0x800C0E88: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800C0E98;
    // 0x800C0E88: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800C0E8C:
    // 0x800C0E8C: b           L_800C0E98
    // 0x800C0E90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800C0E98;
    // 0x800C0E90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800C0E94:
    // 0x800C0E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0E98:
    // 0x800C0E98: subu        $t7, $t5, $v0
    ctx->r15 = SUB32(ctx->r13, ctx->r2);
    // 0x800C0E9C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800C0EA0: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x800C0EA4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C0EA8: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800C0EAC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C0EB0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800C0EB4: addiu       $s3, $s3, 0x80
    ctx->r19 = ADD32(ctx->r19, 0X80);
    // 0x800C0EB8: addiu       $at, $zero, 0x580
    ctx->r1 = ADD32(0, 0X580);
    // 0x800C0EBC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C0EC0: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800C0EC4: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x800C0EC8: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x800C0ECC: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800C0ED0: addiu       $s5, $s5, 0x80
    ctx->r21 = ADD32(ctx->r21, 0X80);
    // 0x800C0ED4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0ED8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C0EDC: bne         $s3, $at, L_800C0C90
    if (ctx->r19 != ctx->r1) {
        // 0x800C0EE0: sw          $t8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r24;
            goto L_800C0C90;
    }
    // 0x800C0EE0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C0EE4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800C0EE8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800C0EEC: addiu       $at, $zero, 0x480
    ctx->r1 = ADD32(0, 0X480);
    // 0x800C0EF0: addiu       $t9, $t6, 0x20
    ctx->r25 = ADD32(ctx->r14, 0X20);
    // 0x800C0EF4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800C0EF8: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x800C0EFC: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x800C0F00: addiu       $t9, $t6, 0x80
    ctx->r25 = ADD32(ctx->r14, 0X80);
    // 0x800C0F04: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800C0F08: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800C0F0C: bne         $t9, $at, L_800C0C4C
    if (ctx->r25 != ctx->r1) {
        // 0x800C0F10: addiu       $t3, $t3, 0x80
        ctx->r11 = ADD32(ctx->r11, 0X80);
            goto L_800C0C4C;
    }
    // 0x800C0F10: addiu       $t3, $t3, 0x80
    ctx->r11 = ADD32(ctx->r11, 0X80);
    // 0x800C0F14: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800C0F18: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800C0F1C: addiu       $t8, $t8, -0x57C0
    ctx->r24 = ADD32(ctx->r24, -0X57C0);
    // 0x800C0F20: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C0F24: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800C0F28: lui         $t6, 0xFF10
    ctx->r14 = S32(0XFF10 << 16);
    // 0x800C0F2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C0F30: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C0F34: ori         $t6, $t6, 0x12F
    ctx->r14 = ctx->r14 | 0X12F;
    // 0x800C0F38: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800C0F3C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C0F40: jal         0x80014F00
    // 0x800C0F44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    func_80014F00(rdram, ctx);
        goto after_1;
    // 0x800C0F44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800C0F48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0F4C: addu        $t9, $v0, $at
    ctx->r25 = ADD32(ctx->r2, ctx->r1);
    // 0x800C0F50: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800C0F54: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x800C0F58: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x800C0F5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C0F60: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C0F64: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C0F68: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C0F6C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C0F70: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C0F74: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C0F78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C0F7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0F80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0F84: jr          $ra
    // 0x800C0F88: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800C0F88: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_800941C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800941C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800941CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800941D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800941D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800941D8: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x800941DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800941E0: lw          $a2, 0x10C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10C);
    // 0x800941E4: beq         $a2, $zero, L_80094204
    if (ctx->r6 == 0) {
        // 0x800941E8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80094204;
    }
    // 0x800941E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800941EC: jal         0x800D70F8
    // 0x800941F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_0;
    // 0x800941F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800941F4: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x800941F8: jal         0x800D6CEC
    // 0x800941FC: lw          $a0, 0x10C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10C);
    func_800D6CEC(rdram, ctx);
        goto after_1;
    // 0x800941FC: lw          $a0, 0x10C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10C);
    after_1:
    // 0x80094200: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_80094204:
    // 0x80094204: lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X12);
    // 0x80094208: beq         $v0, $zero, L_80094228
    if (ctx->r2 == 0) {
        // 0x8009420C: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_80094228;
    }
    // 0x8009420C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80094210: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80094214: jal         0x80100E18
    // 0x80094218: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80100E18(rdram, ctx);
        goto after_2;
    // 0x80094218: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x8009421C: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80094220: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x80094224: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_80094228:
    // 0x80094228: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8009422C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094230: sw          $t9, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = ctx->r25;
    // 0x80094234: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x80094238: sw          $zero, 0x110($t0)
    MEM_W(0X110, ctx->r8) = 0;
    // 0x8009423C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80094240: beql        $t1, $zero, L_800942C0
    if (ctx->r9 == 0) {
        // 0x80094244: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800942C0;
    }
    goto skip_0;
    // 0x80094244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80094248: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009424C: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x80094250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094254: jal         0x80093F7C
    // 0x80094258: swc1        $f4, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f4.u32l;
    func_80093F7C(rdram, ctx);
        goto after_3;
    // 0x80094258: swc1        $f4, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f4.u32l;
    after_3:
    // 0x8009425C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80094260: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x80094264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80094268: jal         0x800D70F8
    // 0x8009426C: lw          $a0, 0x10C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10C);
    func_800D70F8(rdram, ctx);
        goto after_4;
    // 0x8009426C: lw          $a0, 0x10C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X10C);
    after_4:
    // 0x80094270: jal         0x800B26F0
    // 0x80094274: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B26F0(rdram, ctx);
        goto after_5;
    // 0x80094274: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80094278: beq         $v0, $zero, L_80094288
    if (ctx->r2 == 0) {
        // 0x8009427C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80094288;
    }
    // 0x8009427C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094280: b           L_8009428C
    // 0x80094284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8009428C;
    // 0x80094284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80094288:
    // 0x80094288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8009428C:
    // 0x8009428C: jal         0x800A25D0
    // 0x80094290: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_800A25D0(rdram, ctx);
        goto after_6;
    // 0x80094290: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_6:
    // 0x80094294: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x80094298: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8009429C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800942A0: lw          $a1, 0x10C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X10C);
    // 0x800942A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800942A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800942AC: jal         0x80100D24
    // 0x800942B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80100D24(rdram, ctx);
        goto after_7;
    // 0x800942B0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_7:
    // 0x800942B4: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x800942B8: sb          $v0, 0x12($t5)
    MEM_B(0X12, ctx->r13) = ctx->r2;
    // 0x800942BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800942C0:
    // 0x800942C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800942C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800942C8: jr          $ra
    // 0x800942CC: nop

    return;
    // 0x800942CC: nop

;}
RECOMP_FUNC void func_80800484_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080048C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800490: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800494: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800498: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1732, 0X4160) << 16);
    // 0x8080049C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004A0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808004A4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x808004A8: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x808004AC: jal         0x808000FC
    // 0x808004B0: lw          $s1, 0x4160($s1)
    ctx->r17 = MEM_W(ctx->r17, (int16_t)RELOC_LO16(1732, 0X4160));
    func_808000FC_chintrochar(rdram, ctx);
        goto after_0;
    // 0x808004B0: lw          $s1, 0x4160($s1)
    ctx->r17 = MEM_W(ctx->r17, (int16_t)RELOC_LO16(1732, 0X4160));
    after_0:
    // 0x808004B4: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x808004B8: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1732, 0X4790) << 16);
    // 0x808004BC: addiu       $t2, $t2, 0x4790
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1732, 0X4790));
    // 0x808004C0: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x808004C4: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x808004C8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x808004CC: lhu         $a1, -0x640($v0)
    ctx->r5 = MEM_HU(ctx->r2, -0X640);
    // 0x808004D0: lhu         $a2, -0x63E($v0)
    ctx->r6 = MEM_HU(ctx->r2, -0X63E);
    // 0x808004D4: jal         0x80103140
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004DC: andi        $t3, $s1, 0x40
    ctx->r11 = ctx->r17 & 0X40;
    // 0x808004E0: beql        $t3, $zero, L_808004F4
    if (ctx->r11 == 0) {
        // 0x808004E4: andi        $t4, $s1, 0x1000
        ctx->r12 = ctx->r17 & 0X1000;
            goto L_808004F4;
    }
    goto skip_0;
    // 0x808004E4: andi        $t4, $s1, 0x1000
    ctx->r12 = ctx->r17 & 0X1000;
    skip_0:
    // 0x808004E8: jal         0x80800000
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chintrochar(rdram, ctx);
        goto after_2;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004F0: andi        $t4, $s1, 0x1000
    ctx->r12 = ctx->r17 & 0X1000;
L_808004F4:
    // 0x808004F4: beql        $t4, $zero, L_80800508
    if (ctx->r12 == 0) {
        // 0x808004F8: sll         $t5, $s1, 15
        ctx->r13 = S32(ctx->r17 << 15);
            goto L_80800508;
    }
    goto skip_1;
    // 0x808004F8: sll         $t5, $s1, 15
    ctx->r13 = S32(ctx->r17 << 15);
    skip_1:
    // 0x808004FC: jal         0x80800398
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800398_chintrochar(rdram, ctx);
        goto after_3;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800504: sll         $t5, $s1, 15
    ctx->r13 = S32(ctx->r17 << 15);
L_80800508:
    // 0x80800508: bgezl       $t5, L_8080051C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8080050C: sll         $t6, $s1, 12
        ctx->r14 = S32(ctx->r17 << 12);
            goto L_8080051C;
    }
    goto skip_2;
    // 0x8080050C: sll         $t6, $s1, 12
    ctx->r14 = S32(ctx->r17 << 12);
    skip_2:
    // 0x80800510: jal         0x80803E98
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803E98_chintrochar(rdram, ctx);
        goto after_4;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800518: sll         $t6, $s1, 12
    ctx->r14 = S32(ctx->r17 << 12);
L_8080051C:
    // 0x8080051C: bgezl       $t6, L_80800530
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800520: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800530;
    }
    goto skip_3;
    // 0x80800520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800524: jal         0x800DA544
    // 0x80800528: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800528: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_5:
    // 0x8080052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800530:
    // 0x80800530: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800534: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800538: jr          $ra
    // 0x8080053C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080053C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80104004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104004: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80104008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010400C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80104010: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80104014: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80104018: jal         0x801039E4
    // 0x8010401C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x8010401C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80104020: bne         $v0, $zero, L_80104030
    if (ctx->r2 != 0) {
        // 0x80104024: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80104030;
    }
    // 0x80104024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80104028: b           L_80104098
    // 0x8010402C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104098;
    // 0x8010402C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80104030:
    // 0x80104030: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80104034: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80104038: lhu         $a0, 0x14($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X14);
    // 0x8010403C: jal         0x800D62E4
    // 0x80104040: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D62E4(rdram, ctx);
        goto after_1;
    // 0x80104040: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80104044: jal         0x800B2840
    // 0x80104048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x80104048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8010404C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104050: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80104054: jal         0x800B2198
    // 0x80104058: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800B2198(rdram, ctx);
        goto after_3;
    // 0x80104058: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x8010405C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80104060: jal         0x800EE84C
    // 0x80104064: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EE84C(rdram, ctx);
        goto after_4;
    // 0x80104064: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80104068: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010406C: jal         0x800EE84C
    // 0x80104070: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EE84C(rdram, ctx);
        goto after_5;
    // 0x80104070: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80104074: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80104078: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8010407C: jal         0x800EF334
    // 0x80104080: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    func_800EF334(rdram, ctx);
        goto after_6;
    // 0x80104080: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    after_6:
    // 0x80104084: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80104088: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010408C: jal         0x800EF334
    // 0x80104090: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    func_800EF334(rdram, ctx);
        goto after_7;
    // 0x80104090: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    after_7:
    // 0x80104094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80104098:
    // 0x80104098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010409C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801040A0: jr          $ra
    // 0x801040A4: nop

    return;
    // 0x801040A4: nop

;}
RECOMP_FUNC void func_808006CC_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006D4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808006D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808006DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808006E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808006E4: jal         0x80100094
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006EC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808006F0: slti        $at, $a3, 0xCEC
    ctx->r1 = SIGNED(ctx->r7) < 0XCEC ? 1 : 0;
    // 0x808006F4: bne         $at, $zero, L_8080071C
    if (ctx->r1 != 0) {
        // 0x808006F8: addiu       $t6, $a3, -0x10BB
        ctx->r14 = ADD32(ctx->r7, -0X10BB);
            goto L_8080071C;
    }
    // 0x808006F8: addiu       $t6, $a3, -0x10BB
    ctx->r14 = ADD32(ctx->r7, -0X10BB);
    // 0x808006FC: sltiu       $at, $t6, 0x42
    ctx->r1 = ctx->r14 < 0X42 ? 1 : 0;
    // 0x80800700: beq         $at, $zero, L_808008DC
    if (ctx->r1 == 0) {
        // 0x80800704: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808008DC;
    }
    // 0x80800704: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4A44) << 16);
    // 0x8080070C: addu        $at, $at, $t6
    gpr jr_addend_80800714 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800710: lw          $t6, 0x4A44($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4A44));
    // 0x80800714: jr          $t6
    // 0x80800718: nop

    switch (jr_addend_80800714 >> 2) {
        case 0: goto L_808008D4; break;
        case 1: goto L_808008D4; break;
        case 2: goto L_808008D4; break;
        case 3: goto L_808008DC; break;
        case 4: goto L_808008DC; break;
        case 5: goto L_808008DC; break;
        case 6: goto L_808008DC; break;
        case 7: goto L_808008DC; break;
        case 8: goto L_808008DC; break;
        case 9: goto L_808008DC; break;
        case 10: goto L_808008DC; break;
        case 11: goto L_808008DC; break;
        case 12: goto L_808008DC; break;
        case 13: goto L_808008DC; break;
        case 14: goto L_808008DC; break;
        case 15: goto L_808008DC; break;
        case 16: goto L_808008DC; break;
        case 17: goto L_808008DC; break;
        case 18: goto L_808008DC; break;
        case 19: goto L_808008DC; break;
        case 20: goto L_808008DC; break;
        case 21: goto L_808008DC; break;
        case 22: goto L_808008DC; break;
        case 23: goto L_808008DC; break;
        case 24: goto L_80800758; break;
        case 25: goto L_808007E4; break;
        case 26: goto L_80800804; break;
        case 27: goto L_80800824; break;
        case 28: goto L_808008BC; break;
        case 29: goto L_808008DC; break;
        case 30: goto L_80800730; break;
        case 31: goto L_80800730; break;
        case 32: goto L_808008DC; break;
        case 33: goto L_808008DC; break;
        case 34: goto L_808008DC; break;
        case 35: goto L_808008DC; break;
        case 36: goto L_808008DC; break;
        case 37: goto L_808008DC; break;
        case 38: goto L_808008DC; break;
        case 39: goto L_808008DC; break;
        case 40: goto L_808008DC; break;
        case 41: goto L_808008DC; break;
        case 42: goto L_808008DC; break;
        case 43: goto L_808008DC; break;
        case 44: goto L_808008DC; break;
        case 45: goto L_808008DC; break;
        case 46: goto L_808008DC; break;
        case 47: goto L_808008DC; break;
        case 48: goto L_80800758; break;
        case 49: goto L_808008BC; break;
        case 50: goto L_808008BC; break;
        case 51: goto L_808008BC; break;
        case 52: goto L_808008BC; break;
        case 53: goto L_808008BC; break;
        case 54: goto L_808008BC; break;
        case 55: goto L_808008DC; break;
        case 56: goto L_808008DC; break;
        case 57: goto L_808008DC; break;
        case 58: goto L_808008DC; break;
        case 59: goto L_808008DC; break;
        case 60: goto L_808008DC; break;
        case 61: goto L_808008DC; break;
        case 62: goto L_808008DC; break;
        case 63: goto L_808008DC; break;
        case 64: goto L_808008DC; break;
        case 65: goto L_80800740; break;
        default: switch_error(__func__, 0x80800714, 0x80804A44);
    }
    // 0x80800718: nop

L_8080071C:
    // 0x8080071C: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80800720: beq         $a3, $at, L_80800844
    if (ctx->r7 == ctx->r1) {
        // 0x80800724: nop
    
            goto L_80800844;
    }
    // 0x80800724: nop

    // 0x80800728: b           L_808008E0
    // 0x8080072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x8080072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800730:
    // 0x80800730: jal         0x80088180
    // 0x80800734: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800734: nop

    after_1:
    // 0x80800738: b           L_808008E0
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800740:
    // 0x80800740: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800744: addiu       $a1, $zero, 0x10D3
    ctx->r5 = ADD32(0, 0X10D3);
    // 0x80800748: jal         0x8080061C
    // 0x8080074C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x8080074C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800750: b           L_808008E0
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800758:
    // 0x80800758: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080075C: lbu         $a0, 0x79($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X79);
    // 0x80800760: srl         $t8, $a0, 4
    ctx->r24 = S32(U32(ctx->r4) >> 4);
    // 0x80800764: jal         0x808005CC
    // 0x80800768: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_808005CC_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80800768: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x8080076C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800770: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800774: lbu         $a0, 0x79($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X79);
    // 0x80800778: srl         $t0, $a0, 4
    ctx->r8 = S32(U32(ctx->r4) >> 4);
    // 0x8080077C: jal         0x808005CC
    // 0x80800780: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_808005CC_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x80800780: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x80800784: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80800788: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080078C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800790: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800794: nop

    // 0x80800798: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080079C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808007A0: jal         0x800CE8D8
    // 0x808007A4: nop

    func_800CE8D8(rdram, ctx);
        goto after_5;
    // 0x808007A4: nop

    after_5:
    // 0x808007A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007AC: jal         0x800CE88C
    // 0x808007B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_6;
    // 0x808007B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808007B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007B8: jal         0x808019C4
    // 0x808007BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808019C4_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x808007BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808007C0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808007C4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x808007C8: lbu         $t3, 0x72($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X72);
    // 0x808007CC: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x808007D0: ori         $t5, $t4, 0xC
    ctx->r13 = ctx->r12 | 0XC;
    // 0x808007D4: jal         0x800FDC28
    // 0x808007D8: sb          $t5, 0x72($t2)
    MEM_B(0X72, ctx->r10) = ctx->r13;
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x808007D8: sb          $t5, 0x72($t2)
    MEM_B(0X72, ctx->r10) = ctx->r13;
    after_8:
    // 0x808007DC: b           L_808008E0
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007E4:
    // 0x808007E4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    // 0x808007E8: jal         0x800DA3B8
    // 0x808007EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_9;
    // 0x808007EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808007F0: addiu       $a0, $zero, 0xDD
    ctx->r4 = ADD32(0, 0XDD);
    // 0x808007F4: jal         0x80087A58
    // 0x808007F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x808007F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x808007FC: b           L_808008E0
    // 0x80800800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800804:
    // 0x80800804: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80800808: jal         0x800DA3B8
    // 0x8080080C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_11;
    // 0x8080080C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800810: addiu       $a0, $zero, 0xDD
    ctx->r4 = ADD32(0, 0XDD);
    // 0x80800814: jal         0x80087A58
    // 0x80800818: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800818: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x8080081C: b           L_808008E0
    // 0x80800820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800824:
    // 0x80800824: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    // 0x80800828: jal         0x800DA3B8
    // 0x8080082C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_13;
    // 0x8080082C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800830: addiu       $a0, $zero, 0xDD
    ctx->r4 = ADD32(0, 0XDD);
    // 0x80800834: jal         0x80087A58
    // 0x80800838: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800838: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x8080083C: b           L_808008E0
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800844:
    // 0x80800844: jal         0x800D395C
    // 0x80800848: nop

    func_800D395C(rdram, ctx);
        goto after_15;
    // 0x80800848: nop

    after_15:
    // 0x8080084C: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x80800850: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80800884;
    }
    // 0x80800850: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800854: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800858: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080085C: bne         $t6, $at, L_80800874
    if (ctx->r14 != ctx->r1) {
        // 0x80800860: nop
    
            goto L_80800874;
    }
    // 0x80800860: nop

    // 0x80800864: jal         0x80088188
    // 0x80800868: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800868: nop

    after_16:
    // 0x8080086C: b           L_808008E0
    // 0x80800870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800874:
    // 0x80800874: jal         0x80088180
    // 0x80800878: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_17;
    // 0x80800878: nop

    after_17:
    // 0x8080087C: b           L_808008E0
    // 0x80800880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x80800880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800884:
    // 0x80800884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800888: bne         $t7, $at, L_808008AC
    if (ctx->r15 != ctx->r1) {
        // 0x8080088C: addiu       $a0, $zero, 0xDD
        ctx->r4 = ADD32(0, 0XDD);
            goto L_808008AC;
    }
    // 0x8080088C: addiu       $a0, $zero, 0xDD
    ctx->r4 = ADD32(0, 0XDD);
    // 0x80800890: jal         0x800EA05C
    // 0x80800894: nop

    func_800EA05C(rdram, ctx);
        goto after_18;
    // 0x80800894: nop

    after_18:
    // 0x80800898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080089C: jal         0x80087A58
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_19;
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808008A4: b           L_808008E0
    // 0x808008A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808008A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008AC:
    // 0x808008AC: jal         0x80087A58
    // 0x808008B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x808008B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
    // 0x808008B4: b           L_808008E0
    // 0x808008B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808008B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008BC:
    // 0x808008BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008C0: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808008C4: jal         0x8080061C
    // 0x808008C8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_21;
    // 0x808008C8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_21:
    // 0x808008CC: b           L_808008E0
    // 0x808008D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008E0;
    // 0x808008D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008D4:
    // 0x808008D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808008D8: sb          $t8, 0xC4($v0)
    MEM_B(0XC4, ctx->r2) = ctx->r24;
L_808008DC:
    // 0x808008DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008E0:
    // 0x808008E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008E4: jr          $ra
    // 0x808008E8: nop

    return;
    // 0x808008E8: nop

;}
RECOMP_FUNC void func_80098610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098610: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x80098614: jr          $ra
    // 0x80098618: lwc1        $f0, 0x30($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X30);
    return;
    // 0x80098618: lwc1        $f0, 0x30($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X30);
;}
RECOMP_FUNC void _fxfontstring_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088988: syscall     713
    recomp_syscall_handler(rdram, ctx, 0x80088988);
    return;
    // 0x8008898C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _baattach_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084468: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084468);
    return;
    // 0x8008446C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800ABC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABC0C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ABC10: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800ABC14: addiu       $t7, $t6, 0x4C
    ctx->r15 = ADD32(ctx->r14, 0X4C);
    // 0x800ABC18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800ABC1C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800ABC20: subu        $t9, $t7, $v0
    ctx->r25 = SUB32(ctx->r15, ctx->r2);
    // 0x800ABC24: addiu       $t0, $t9, -0x10
    ctx->r8 = ADD32(ctx->r25, -0X10);
    // 0x800ABC28: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800ABC2C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800ABC30: mflo        $t1
    ctx->r9 = lo;
    // 0x800ABC34: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800ABC38: bne         $at, $zero, L_800ABC50
    if (ctx->r1 != 0) {
        // 0x800ABC3C: nop
    
            goto L_800ABC50;
    }
    // 0x800ABC3C: nop

    // 0x800ABC40: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800ABC44: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800ABC48: addiu       $t5, $t3, 0x10
    ctx->r13 = ADD32(ctx->r11, 0X10);
    // 0x800ABC4C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_800ABC50:
    // 0x800ABC50: jr          $ra
    // 0x800ABC54: nop

    return;
    // 0x800ABC54: nop

;}
RECOMP_FUNC void func_800BE58C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE58C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BE590: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BE594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE598: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BE59C: jal         0x800EE830
    // 0x800BE5A0: addiu       $a1, $a1, -0x7BC8
    ctx->r5 = ADD32(ctx->r5, -0X7BC8);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800BE5A0: addiu       $a1, $a1, -0x7BC8
    ctx->r5 = ADD32(ctx->r5, -0X7BC8);
    after_0:
    // 0x800BE5A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BE5A8: addiu       $a1, $a1, -0x7BD4
    ctx->r5 = ADD32(ctx->r5, -0X7BD4);
    // 0x800BE5AC: jal         0x800EE830
    // 0x800BE5B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x800BE5B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800BE5B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BE5BC: jr          $ra
    // 0x800BE5C0: nop

    return;
    // 0x800BE5C0: nop

;}
RECOMP_FUNC void _glzone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088768: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088768);
    return;
    // 0x8008876C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002A0_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808002A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x808002B4: jal         0x8009C128
    // 0x808002B8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808002B8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x808002BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808002C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002C4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808002D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002D4: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x808002D8: jal         0x8009FBB0
    // 0x808002DC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_1;
    // 0x808002DC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808002E0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x808002E4: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x808002E8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x808002EC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808002F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808002F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808002F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800300: addiu       $a1, $zero, -0x1E
    ctx->r5 = ADD32(0, -0X1E);
    // 0x80800304: addiu       $a2, $zero, -0x1E
    ctx->r6 = ADD32(0, -0X1E);
    // 0x80800308: jal         0x800BA930
    // 0x8080030C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x8080030C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    after_2:
    // 0x80800310: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800314: jal         0x800BA22C
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080031C: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800320: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800324: nop

    // 0x80800328: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8080032C: nop

    // 0x80800330: bc1f        L_80800374
    if (!c1cs) {
        // 0x80800334: nop
    
            goto L_80800374;
    }
    // 0x80800334: nop

    // 0x80800338: jal         0x800F2100
    // 0x8080033C: nop

    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8080033C: nop

    after_4:
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(268, 0XA40) << 16);
    // 0x80800344: lwc1        $f16, 0xA40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(268, 0XA40));
    // 0x80800348: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080034C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800350: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800354: jal         0x800F0E00
    // 0x80800358: nop

    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x80800358: nop

    after_5:
    // 0x8080035C: lwc1        $f18, 0x16C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800368: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x8080036C: jal         0x8009BA58
    // 0x80800370: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80800370: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_6:
L_80800374:
    // 0x80800374: jal         0x8008E078
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080037C: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800380: addiu       $t9, $zero, 0x15D
        ctx->r25 = ADD32(0, 0X15D);
            goto L_80800388;
    }
    // 0x80800380: addiu       $t9, $zero, 0x15D
    ctx->r25 = ADD32(0, 0X15D);
    // 0x80800384: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_80800388:
    // 0x80800388: jal         0x8008E35C
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800390: bne         $v0, $zero, L_8080039C
    if (ctx->r2 != 0) {
        // 0x80800394: addiu       $t0, $zero, 0xBB
        ctx->r8 = ADD32(0, 0XBB);
            goto L_8080039C;
    }
    // 0x80800394: addiu       $t0, $zero, 0xBB
    ctx->r8 = ADD32(0, 0XBB);
    // 0x80800398: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_8080039C:
    // 0x8080039C: jal         0x8009BB50
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808003A8: addiu       $t1, $zero, 0x15D
    ctx->r9 = ADD32(0, 0X15D);
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x808003B4: nop

    // 0x808003B8: bc1f        L_808003C4
    if (!c1cs) {
        // 0x808003BC: nop
    
            goto L_808003C4;
    }
    // 0x808003BC: nop

    // 0x808003C0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_808003C4:
    // 0x808003C4: jal         0x8009E5C8
    // 0x808003C8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x808003C8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x808003CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808003D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void _subaddiejoy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BC0: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BC0);
    return;
    // 0x80089BC4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800C6C_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C78: jal         0x80800074
    // 0x80800C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800074_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C84: jal         0x8009E5C8
    // 0x80800C88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800C88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C94: jr          $ra
    // 0x80800C98: nop

    return;
    // 0x80800C98: nop

;}
RECOMP_FUNC void _bawandglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853B8: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853B8);
    return;
    // 0x800853BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800064_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800070: jal         0x80097AD0
    // 0x80800074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800078: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080007C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080008C;
    }
    // 0x8080007C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: jal         0x800848A8
    // 0x80800084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x80800084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800088: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080008C:
    // 0x8080008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800094: jal         0x80091A58
    // 0x80800098: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x80800098: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8080009C: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x808000A0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A8;
    }
    // 0x808000A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: addiu       $v1, $zero, 0x115
    ctx->r3 = ADD32(0, 0X115);
L_808000A8:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_800F7664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7664: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7668: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F766C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7670: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7674: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F767C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F7680: jal         0x8009AD20
    // 0x800F7684: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F7684: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7688: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F768C: jal         0x8009AD2C
    // 0x800F7690: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD2C(rdram, ctx);
        goto after_1;
    // 0x800F7690: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F7694: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7698: jal         0x8009E7C8
    // 0x800F769C: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F769C: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    after_2:
    // 0x800F76A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F76A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F76A8: jr          $ra
    // 0x800F76AC: nop

    return;
    // 0x800F76AC: nop

;}
RECOMP_FUNC void func_800F93C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F93C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F93C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F93CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F93D0: jal         0x800F54E4
    // 0x800F93D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800F93D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F93D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F93DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F93E0: jal         0x800F5410
    // 0x800F93E4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x800F93E4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    after_1:
    // 0x800F93E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F93EC: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800F93F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F93F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F93F8: jr          $ra
    // 0x800F93FC: nop

    return;
    // 0x800F93FC: nop

;}
RECOMP_FUNC void func_80025224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025224: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80025228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002522C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80025230: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80025234: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80025238: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002523C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80025240: jal         0x80025BF0
    // 0x80025244: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_0;
    // 0x80025244: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80025248: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x8002524C: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80025250: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80025254: bne         $t6, $at, L_8002553C
    if (ctx->r14 != ctx->r1) {
        // 0x80025258: nop
    
            goto L_8002553C;
    }
    // 0x80025258: nop

    // 0x8002525C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80025260: jal         0x80025BF0
    // 0x80025264: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_1;
    // 0x80025264: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80025268: sb          $v0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r2;
    // 0x8002526C: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    // 0x80025270: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80025274: bne         $t7, $at, L_800252F0
    if (ctx->r15 != ctx->r1) {
        // 0x80025278: nop
    
            goto L_800252F0;
    }
    // 0x80025278: nop

    // 0x8002527C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80025280: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80025284: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80025288: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x8002528C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80025290: sb          $t0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r8;
    // 0x80025294: lbu         $t2, 0x23($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X23);
    // 0x80025298: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8002529C: sb          $t2, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r10;
    // 0x800252A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800252A4: jal         0x80025BF0
    // 0x800252A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_2;
    // 0x800252A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800252AC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800252B0: sb          $v0, 0xB($t4)
    MEM_B(0XB, ctx->r12) = ctx->r2;
    // 0x800252B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800252B8: jal         0x80025BF0
    // 0x800252BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_3;
    // 0x800252BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x800252C0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800252C4: sb          $v0, 0xC($t5)
    MEM_B(0XC, ctx->r13) = ctx->r2;
    // 0x800252C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800252CC: jal         0x80025BF0
    // 0x800252D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_4;
    // 0x800252D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x800252D4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800252D8: sb          $v0, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r2;
    // 0x800252DC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800252E0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800252E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800252E8: b           L_80025534
    // 0x800252EC: sb          $zero, 0x138($t9)
    MEM_B(0X138, ctx->r25) = 0;
        goto L_80025534;
    // 0x800252EC: sb          $zero, 0x138($t9)
    MEM_B(0X138, ctx->r25) = 0;
L_800252F0:
    // 0x800252F0: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x800252F4: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800252F8: bne         $t0, $at, L_80025358
    if (ctx->r8 != ctx->r1) {
        // 0x800252FC: nop
    
            goto L_80025358;
    }
    // 0x800252FC: nop

    // 0x80025300: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80025304: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80025308: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8002530C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80025310: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80025314: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80025318: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8002531C: xor         $t7, $t5, $t6
    ctx->r15 = ctx->r13 ^ ctx->r14;
    // 0x80025320: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80025324: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80025328: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002532C: beq         $t9, $zero, L_80025344
    if (ctx->r25 == 0) {
        // 0x80025330: nop
    
            goto L_80025344;
    }
    // 0x80025330: nop

    // 0x80025334: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80025338: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x8002533C: b           L_80025350
    // 0x80025340: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
        goto L_80025350;
    // 0x80025340: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
L_80025344:
    // 0x80025344: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80025348: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8002534C: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
L_80025350:
    // 0x80025350: b           L_80025534
    // 0x80025354: nop

        goto L_80025534;
    // 0x80025354: nop

L_80025358:
    // 0x80025358: lbu         $t5, 0x23($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X23);
    // 0x8002535C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80025360: bne         $t5, $at, L_800253CC
    if (ctx->r13 != ctx->r1) {
        // 0x80025364: nop
    
            goto L_800253CC;
    }
    // 0x80025364: nop

    // 0x80025368: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002536C: jal         0x80025BF0
    // 0x80025370: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_5;
    // 0x80025370: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80025374: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x80025378: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x8002537C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80025380: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80025384: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x80025388: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002538C: jal         0x80025BF0
    // 0x80025390: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_6;
    // 0x80025390: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80025394: sb          $v0, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r2;
    // 0x80025398: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002539C: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x800253A0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800253A4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x800253A8: sw          $t2, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r10;
    // 0x800253AC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800253B0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800253B4: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x800253B8: sb          $zero, 0x138($t5)
    MEM_B(0X138, ctx->r13) = 0;
    // 0x800253BC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800253C0: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x800253C4: b           L_80025534
    // 0x800253C8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
        goto L_80025534;
    // 0x800253C8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_800253CC:
    // 0x800253CC: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x800253D0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800253D4: bne         $t4, $at, L_80025534
    if (ctx->r12 != ctx->r1) {
        // 0x800253D8: nop
    
            goto L_80025534;
    }
    // 0x800253D8: nop

    // 0x800253DC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800253E0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800253E4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800253E8: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x800253EC: lw          $t1, 0x18($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X18);
    // 0x800253F0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800253F4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800253F8: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x800253FC: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80025400: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80025404: sb          $t5, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r13;
    // 0x80025408: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002540C: lbu         $t4, 0x0($t7)
    ctx->r12 = MEM_BU(ctx->r15, 0X0);
    // 0x80025410: sb          $t4, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r12;
    // 0x80025414: lbu         $t0, 0x29($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X29);
    // 0x80025418: beq         $t0, $zero, L_8002542C
    if (ctx->r8 == 0) {
        // 0x8002541C: nop
    
            goto L_8002542C;
    }
    // 0x8002541C: nop

    // 0x80025420: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80025424: bne         $t9, $zero, L_80025458
    if (ctx->r25 != 0) {
        // 0x80025428: nop
    
            goto L_80025458;
    }
    // 0x80025428: nop

L_8002542C:
    // 0x8002542C: lbu         $t2, 0x2A($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2A);
    // 0x80025430: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80025434: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x80025438: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002543C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80025440: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80025444: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80025448: addiu       $t5, $t1, 0x5
    ctx->r13 = ADD32(ctx->r9, 0X5);
    // 0x8002544C: addu        $t4, $t3, $t7
    ctx->r12 = ADD32(ctx->r11, ctx->r15);
    // 0x80025450: b           L_80025518
    // 0x80025454: sw          $t5, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r13;
        goto L_80025518;
    // 0x80025454: sw          $t5, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r13;
L_80025458:
    // 0x80025458: lbu         $t0, 0x29($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X29);
    // 0x8002545C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80025460: beq         $t0, $at, L_80025478
    if (ctx->r8 == ctx->r1) {
        // 0x80025464: nop
    
            goto L_80025478;
    }
    // 0x80025464: nop

    // 0x80025468: lbu         $t9, 0x29($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X29);
    // 0x8002546C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80025470: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80025474: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
L_80025478:
    // 0x80025478: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002547C: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x80025480: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80025484: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80025488: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x8002548C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80025490: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80025494: sll         $t5, $t7, 24
    ctx->r13 = S32(ctx->r15 << 24);
    // 0x80025498: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8002549C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800254A0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800254A4: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x800254A8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800254AC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800254B0: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x800254B4: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x800254B8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800254BC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800254C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800254C4: lbu         $t3, 0x0($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X0);
    // 0x800254C8: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x800254CC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800254D0: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800254D4: addu        $t2, $t7, $t4
    ctx->r10 = ADD32(ctx->r15, ctx->r12);
    // 0x800254D8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800254DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800254E0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800254E4: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x800254E8: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800254EC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800254F0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800254F4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800254F8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800254FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80025500: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80025504: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80025508: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8002550C: subu        $t2, $t7, $t4
    ctx->r10 = SUB32(ctx->r15, ctx->r12);
    // 0x80025510: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80025514: sw          $t2, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r10;
L_80025518:
    // 0x80025518: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8002551C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80025520: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
    // 0x80025524: sb          $zero, 0x138($t3)
    MEM_B(0X138, ctx->r11) = 0;
    // 0x80025528: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002552C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80025530: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
L_80025534:
    // 0x80025534: b           L_80025648
    // 0x80025538: nop

        goto L_80025648;
    // 0x80025538: nop

L_8002553C:
    // 0x8002553C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80025540: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80025544: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x80025548: lbu         $t8, 0x2B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2B);
    // 0x8002554C: andi        $t2, $t8, 0x80
    ctx->r10 = ctx->r24 & 0X80;
    // 0x80025550: beq         $t2, $zero, L_800255A4
    if (ctx->r10 == 0) {
        // 0x80025554: nop
    
            goto L_800255A4;
    }
    // 0x80025554: nop

    // 0x80025558: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x8002555C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80025560: andi        $t6, $t9, 0xF0
    ctx->r14 = ctx->r25 & 0XF0;
    // 0x80025564: sb          $t6, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r14;
    // 0x80025568: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002556C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80025570: sb          $t3, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r11;
    // 0x80025574: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80025578: jal         0x80025BF0
    // 0x8002557C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_7;
    // 0x8002557C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80025580: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80025584: sb          $v0, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r2;
    // 0x80025588: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8002558C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80025590: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80025594: lbu         $t5, 0x8($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X8);
    // 0x80025598: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8002559C: b           L_800255D4
    // 0x800255A0: sb          $t5, 0x138($t9)
    MEM_B(0X138, ctx->r25) = ctx->r13;
        goto L_800255D4;
    // 0x800255A0: sb          $t5, 0x138($t9)
    MEM_B(0X138, ctx->r25) = ctx->r13;
L_800255A4:
    // 0x800255A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800255A8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800255AC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800255B0: addu        $t3, $t6, $t1
    ctx->r11 = ADD32(ctx->r14, ctx->r9);
    // 0x800255B4: lbu         $t7, 0x138($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X138);
    // 0x800255B8: sb          $t7, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r15;
    // 0x800255BC: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x800255C0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800255C4: sb          $t0, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r8;
    // 0x800255C8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800255CC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800255D0: sb          $t2, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r10;
L_800255D4:
    // 0x800255D4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800255D8: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800255DC: lbu         $t6, 0x8($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X8);
    // 0x800255E0: andi        $t1, $t6, 0xF0
    ctx->r9 = ctx->r14 & 0XF0;
    // 0x800255E4: beq         $t1, $at, L_80025640
    if (ctx->r9 == ctx->r1) {
        // 0x800255E8: nop
    
            goto L_80025640;
    }
    // 0x800255E8: nop

    // 0x800255EC: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800255F0: beq         $t1, $at, L_80025640
    if (ctx->r9 == ctx->r1) {
        // 0x800255F4: nop
    
            goto L_80025640;
    }
    // 0x800255F4: nop

    // 0x800255F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800255FC: jal         0x80025BF0
    // 0x80025600: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025BF0(rdram, ctx);
        goto after_8;
    // 0x80025600: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80025604: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80025608: sb          $v0, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r2;
    // 0x8002560C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80025610: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80025614: lbu         $t4, 0x8($t7)
    ctx->r12 = MEM_BU(ctx->r15, 0X8);
    // 0x80025618: andi        $t0, $t4, 0xF0
    ctx->r8 = ctx->r12 & 0XF0;
    // 0x8002561C: bne         $t0, $at, L_80025638
    if (ctx->r8 != ctx->r1) {
        // 0x80025620: nop
    
            goto L_80025638;
    }
    // 0x80025620: nop

    // 0x80025624: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80025628: jal         0x80025DE4
    // 0x8002562C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80025DE4(rdram, ctx);
        goto after_9;
    // 0x8002562C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80025630: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80025634: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
L_80025638:
    // 0x80025638: b           L_80025648
    // 0x8002563C: nop

        goto L_80025648;
    // 0x8002563C: nop

L_80025640:
    // 0x80025640: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80025644: sb          $zero, 0xB($t2)
    MEM_B(0XB, ctx->r10) = 0;
L_80025648:
    // 0x80025648: b           L_80025658
    // 0x8002564C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80025658;
    // 0x8002564C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025650: b           L_80025658
    // 0x80025654: nop

        goto L_80025658;
    // 0x80025654: nop

L_80025658:
    // 0x80025658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002565C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80025660: jr          $ra
    // 0x80025664: nop

    return;
    // 0x80025664: nop

;}
RECOMP_FUNC void func_80800020_chdiggerbossdeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: jr          $ra
    // 0x80800024: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800024: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void bavan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080005C: lw          $t7, 0x144($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X144);
    // 0x80800060: jal         0x800C2FDC
    // 0x80800064: lbu         $a0, 0x10($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X10);
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800064: lbu         $a0, 0x10($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X10);
    after_0:
    // 0x80800068: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80800070: sb          $zero, 0x10($t9)
    MEM_B(0X10, ctx->r25) = 0;
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void func_80800094_ncbasuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: jal         0x80110840
    // 0x808000A0: nop

    func_80110840(rdram, ctx);
        goto after_0;
    // 0x808000A0: nop

    after_0:
    // 0x808000A4: jal         0x800F53D0
    // 0x808000A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x808000A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000AC: jal         0x80092BC4
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80092BC4(rdram, ctx);
        goto after_2;
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_808006C4_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006C8: addiu       $at, $zero, 0xF19
    ctx->r1 = ADD32(0, 0XF19);
    // 0x808006CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006D4: beq         $a1, $at, L_8080075C
    if (ctx->r5 == ctx->r1) {
        // 0x808006D8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080075C;
    }
    // 0x808006D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808006DC: addiu       $at, $zero, 0xF1E
    ctx->r1 = ADD32(0, 0XF1E);
    // 0x808006E0: beq         $a1, $at, L_80800724
    if (ctx->r5 == ctx->r1) {
        // 0x808006E4: addiu       $at, $zero, 0xF1F
        ctx->r1 = ADD32(0, 0XF1F);
            goto L_80800724;
    }
    // 0x808006E4: addiu       $at, $zero, 0xF1F
    ctx->r1 = ADD32(0, 0XF1F);
    // 0x808006E8: beq         $a1, $at, L_80800740
    if (ctx->r5 == ctx->r1) {
        // 0x808006EC: addiu       $at, $zero, 0xF20
        ctx->r1 = ADD32(0, 0XF20);
            goto L_80800740;
    }
    // 0x808006EC: addiu       $at, $zero, 0xF20
    ctx->r1 = ADD32(0, 0XF20);
    // 0x808006F0: beq         $a1, $at, L_80800778
    if (ctx->r5 == ctx->r1) {
        // 0x808006F4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800778;
    }
    // 0x808006F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808006F8: addiu       $at, $zero, 0x1277
    ctx->r1 = ADD32(0, 0X1277);
    // 0x808006FC: beq         $a1, $at, L_808007CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800700: addiu       $at, $zero, 0x127C
        ctx->r1 = ADD32(0, 0X127C);
            goto L_808007CC;
    }
    // 0x80800700: addiu       $at, $zero, 0x127C
    ctx->r1 = ADD32(0, 0X127C);
    // 0x80800704: beq         $a1, $at, L_80800794
    if (ctx->r5 == ctx->r1) {
        // 0x80800708: addiu       $at, $zero, 0x127D
        ctx->r1 = ADD32(0, 0X127D);
            goto L_80800794;
    }
    // 0x80800708: addiu       $at, $zero, 0x127D
    ctx->r1 = ADD32(0, 0X127D);
    // 0x8080070C: beq         $a1, $at, L_808007B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800710: addiu       $at, $zero, 0x127E
        ctx->r1 = ADD32(0, 0X127E);
            goto L_808007B0;
    }
    // 0x80800710: addiu       $at, $zero, 0x127E
    ctx->r1 = ADD32(0, 0X127E);
    // 0x80800714: beq         $a1, $at, L_808007E8
    if (ctx->r5 == ctx->r1) {
        // 0x80800718: addiu       $a0, $zero, 0x44
        ctx->r4 = ADD32(0, 0X44);
            goto L_808007E8;
    }
    // 0x80800718: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8080071C: b           L_80800824
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x80800720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800724:
    // 0x80800724: jal         0x800DA544
    // 0x80800728: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800728: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_0:
    // 0x8080072C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800730: jal         0x80800680
    // 0x80800734: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800680_chfriendlystonehead(rdram, ctx);
        goto after_1;
    // 0x80800734: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800738: b           L_80800824
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800740:
    // 0x80800740: jal         0x800DA544
    // 0x80800744: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800744: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_2:
    // 0x80800748: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080074C: jal         0x80800680
    // 0x80800750: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800680_chfriendlystonehead(rdram, ctx);
        goto after_3;
    // 0x80800750: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80800754: b           L_80800824
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x80800758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080075C:
    // 0x8080075C: jal         0x800DA544
    // 0x80800760: addiu       $a0, $zero, 0x576
    ctx->r4 = ADD32(0, 0X576);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800760: addiu       $a0, $zero, 0x576
    ctx->r4 = ADD32(0, 0X576);
    after_4:
    // 0x80800764: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800768: jal         0x80800680
    // 0x8080076C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800680_chfriendlystonehead(rdram, ctx);
        goto after_5;
    // 0x8080076C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80800770: b           L_80800824
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800778:
    // 0x80800778: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080077C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800780: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800784: jal         0x800D1000
    // 0x80800788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_6;
    // 0x80800788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x8080078C: b           L_80800824
    // 0x80800790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x80800790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800794:
    // 0x80800794: jal         0x800DA544
    // 0x80800798: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80800798: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    after_7:
    // 0x8080079C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007A0: jal         0x80800680
    // 0x808007A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800680_chfriendlystonehead(rdram, ctx);
        goto after_8;
    // 0x808007A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808007A8: b           L_80800824
    // 0x808007AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x808007AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007B0:
    // 0x808007B0: jal         0x800DA544
    // 0x808007B4: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x808007B4: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    after_9:
    // 0x808007B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007BC: jal         0x80800680
    // 0x808007C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800680_chfriendlystonehead(rdram, ctx);
        goto after_10;
    // 0x808007C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x808007C4: b           L_80800824
    // 0x808007C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x808007C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007CC:
    // 0x808007CC: jal         0x800DA544
    // 0x808007D0: addiu       $a0, $zero, 0x577
    ctx->r4 = ADD32(0, 0X577);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x808007D0: addiu       $a0, $zero, 0x577
    ctx->r4 = ADD32(0, 0X577);
    after_11:
    // 0x808007D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007D8: jal         0x80800680
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800680_chfriendlystonehead(rdram, ctx);
        goto after_12;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808007E0: b           L_80800824
    // 0x808007E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800824;
    // 0x808007E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007E8:
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808007F4: jal         0x800D1000
    // 0x808007F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_13;
    // 0x808007F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x808007FC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800800: jal         0x800C01A8
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_14;
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800808: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080080C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800810: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800814: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x80800818: jal         0x80085708
    // 0x8080081C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x8080081C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_15:
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800824:
    // 0x80800824: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800828: jr          $ra
    // 0x8080082C: nop

    return;
    // 0x8080082C: nop

;}
RECOMP_FUNC void func_800963C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800963C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800963C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800963C8: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800963CC: jal         0x800C675C
    // 0x800963D0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C675C(rdram, ctx);
        goto after_0;
    // 0x800963D0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800963D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800963D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800963DC: jr          $ra
    // 0x800963E0: nop

    return;
    // 0x800963E0: nop

;}
RECOMP_FUNC void func_800D7418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D741C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7420: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7424: jal         0x800884D8
    // 0x800D7428: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    _glsplineDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800D7428: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    after_0:
    // 0x800D742C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7434: jr          $ra
    // 0x800D7438: nop

    return;
    // 0x800D7438: nop

;}
RECOMP_FUNC void anseq_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: jal         0x800B2890
    // 0x80800118: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    func_800B2890(rdram, ctx);
        goto after_0;
    // 0x80800118: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x8080011C: jal         0x800B28B8
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    vector_clear(rdram, ctx);
        goto after_1;
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void func_80800AE4_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800AF8: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800AFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B04: beq         $v0, $zero, L_80800B28
    if (ctx->r2 == 0) {
        // 0x80800B08: addiu       $a1, $zero, 0x11
        ctx->r5 = ADD32(0, 0X11);
            goto L_80800B28;
    }
    // 0x80800B08: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B10: beq         $v0, $at, L_80800B30
    if (ctx->r2 == ctx->r1) {
        // 0x80800B14: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B30;
    }
    // 0x80800B14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B18: beql        $v0, $at, L_80800B6C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B1C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    goto skip_0;
    // 0x80800B1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800B20: b           L_80800B78
    // 0x80800B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B78;
    // 0x80800B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B28:
    // 0x80800B28: jal         0x800856B0
    // 0x80800B2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800B2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80800B30:
    // 0x80800B30: jal         0x800856E0
    // 0x80800B34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800B34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800B38: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800B3C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1012, 0XF60) << 16);
    // 0x80800B40: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80800B44: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1012, 0XF60));
    // 0x80800B48: jal         0x80088090
    // 0x80800B4C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800B4C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800B50: jal         0x80088098
    // 0x80800B54: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800B54: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800B58: jal         0x800880A0
    // 0x80800B5C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800B5C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800B60: jal         0x800880B8
    // 0x80800B64: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800B64: nop

    after_5:
    // 0x80800B68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800B6C:
    // 0x80800B6C: jal         0x800856D8
    // 0x80800B70: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800B70: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B78:
    // 0x80800B78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B80: jr          $ra
    // 0x80800B84: nop

    return;
    // 0x80800B84: nop

;}
RECOMP_FUNC void func_808007DC_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808007E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007EC: beq         $a1, $at, L_80800814
    if (ctx->r5 == ctx->r1) {
        // 0x808007F0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800814;
    }
    // 0x808007F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808007F4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808007F8: beq         $a1, $at, L_8080088C
    if (ctx->r5 == ctx->r1) {
        // 0x808007FC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080088C;
    }
    // 0x808007FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800800: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800804: beq         $a1, $at, L_808008A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800808: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1868, 0X9E4) << 16);
            goto L_808008A0;
    }
    // 0x80800808: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1868, 0X9E4) << 16);
    // 0x8080080C: b           L_808008C0
    // 0x80800810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x80800810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800814:
    // 0x80800814: lhu         $t6, 0x72($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X72);
    // 0x80800818: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080081C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800820: beql        $t7, $at, L_808008C0
    if (ctx->r15 == ctx->r1) {
        // 0x80800824: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008C0;
    }
    goto skip_0;
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800828: jal         0x80101080
    // 0x8080082C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x8080082C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800830: jal         0x80106790
    // 0x80800834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800838: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8080083C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800840: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x80800844: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    // 0x80800848: jal         0x800EFB24
    // 0x8080084C: addiu       $a2, $a3, 0x28
    ctx->r6 = ADD32(ctx->r7, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x8080084C: addiu       $a2, $a3, 0x28
    ctx->r6 = ADD32(ctx->r7, 0X28);
    after_2:
    // 0x80800850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800854: lui         $a1, 0x3E12
    ctx->r5 = S32(0X3E12 << 16);
    // 0x80800858: ori         $a1, $a1, 0x4925
    ctx->r5 = ctx->r5 | 0X4925;
    // 0x8080085C: jal         0x800EF334
    // 0x80800860: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800860: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x80800864: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080086C: lhu         $t8, 0x6E($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X6E);
    // 0x80800870: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800874: ori         $t0, $t9, 0x7
    ctx->r8 = ctx->r25 | 0X7;
    // 0x80800878: sh          $t0, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r8;
    // 0x8080087C: jal         0x80102FE8
    // 0x80800880: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80102FE8(rdram, ctx);
        goto after_4;
    // 0x80800880: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800884: b           L_808008C0
    // 0x80800888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C0;
    // 0x80800888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080088C:
    // 0x8080088C: lh          $a1, 0x28($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X28);
    // 0x80800890: jal         0x80800728
    // 0x80800894: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    func_80800728_chjadesnake(rdram, ctx);
        goto after_5;
    // 0x80800894: lh          $a2, 0x2A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2A);
    after_5:
    // 0x80800898: b           L_808008C0
    // 0x8080089C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C0;
    // 0x8080089C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008A0:
    // 0x808008A0: addiu       $a0, $a0, 0x9E4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1868, 0X9E4));
    // 0x808008A4: jal         0x80088090
    // 0x808008A8: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808008A8: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_6:
    // 0x808008AC: b           L_808008C0
    // 0x808008B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008C0;
    // 0x808008B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008B4: b           L_808008C0
    // 0x808008B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008C0;
    // 0x808008B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008C0:
    // 0x808008C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008C8: jr          $ra
    // 0x808008CC: nop

    return;
    // 0x808008CC: nop

;}
RECOMP_FUNC void chfloater_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(988, 0X2A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(988, 0X2A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(988, 0X2A0));
;}
RECOMP_FUNC void func_800E9728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E972C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9730: jal         0x800EA390
    // 0x800E9734: nop

    func_800EA390(rdram, ctx);
        goto after_0;
    // 0x800E9734: nop

    after_0:
    // 0x800E9738: jal         0x800EB70C
    // 0x800E973C: nop

    func_800EB70C(rdram, ctx);
        goto after_1;
    // 0x800E973C: nop

    after_1:
    // 0x800E9740: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800E9744: jal         0x800B42FC
    // 0x800E9748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800B42FC(rdram, ctx);
        goto after_2;
    // 0x800E9748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x800E974C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9750: sw          $v0, 0x2DB0($at)
    MEM_W(0X2DB0, ctx->r1) = ctx->r2;
    // 0x800E9754: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800E9758: jal         0x800B42FC
    // 0x800E975C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800B42FC(rdram, ctx);
        goto after_3;
    // 0x800E975C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x800E9760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9764: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9768: sw          $v0, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r2;
    // 0x800E976C: jr          $ra
    // 0x800E9770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E9770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800018_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800024: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800038: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080003C: beq         $a3, $at, L_80800060
    if (ctx->r7 == ctx->r1) {
        // 0x80800040: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800060;
    }
    // 0x80800040: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800044: beq         $a3, $at, L_808000D4
    if (ctx->r7 == ctx->r1) {
        // 0x80800048: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808000D4;
    }
    // 0x80800048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080004C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800050: beq         $a3, $at, L_808002A4
    if (ctx->r7 == ctx->r1) {
        // 0x80800054: nop
    
            goto L_808002A4;
    }
    // 0x80800054: nop

    // 0x80800058: b           L_808002D4
    // 0x8080005C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
        goto L_808002D4;
    // 0x8080005C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80800060:
    // 0x80800060: jal         0x800DA524
    // 0x80800064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_1;
    // 0x80800064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800068: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080006C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800070: jal         0x8008A2C0
    // 0x80800074: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800074: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_2:
    // 0x80800078: jal         0x800DA544
    // 0x8080007C: addiu       $a0, $zero, 0x6E6
    ctx->r4 = ADD32(0, 0X6E6);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a0, $zero, 0x6E6
    ctx->r4 = ADD32(0, 0X6E6);
    after_3:
    // 0x80800080: jal         0x80088178
    // 0x80800084: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_4:
    // 0x80800088: jal         0x800FDC28
    // 0x8080008C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_5;
    // 0x8080008C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
    // 0x80800090: jal         0x80090708
    // 0x80800094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_6;
    // 0x80800094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800098: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8080009C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000A0: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808000A4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x808000A8: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x808000AC: jal         0x800CE8D8
    // 0x808000B0: sw          $zero, 0x24($t6)
    MEM_W(0X24, ctx->r14) = 0;
    func_800CE8D8(rdram, ctx);
        goto after_7;
    // 0x808000B0: sw          $zero, 0x24($t6)
    MEM_W(0X24, ctx->r14) = 0;
    after_7:
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000B8: jal         0x800CE88C
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_8;
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808000C0: addiu       $a0, $zero, 0xF5
    ctx->r4 = ADD32(0, 0XF5);
    // 0x808000C4: jal         0x800D2770
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_9;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000CC: b           L_808002D0
    // 0x808000D0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
        goto L_808002D0;
    // 0x808000D0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
L_808000D4:
    // 0x808000D4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x808000D8: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    // 0x808000DC: jal         0x800D2054
    // 0x808000E0: lw          $a2, 0x24($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X24);
    func_800D2054(rdram, ctx);
        goto after_10;
    // 0x808000E0: lw          $a2, 0x24($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X24);
    after_10:
    // 0x808000E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000E8: jal         0x80090708
    // 0x808000EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_11;
    // 0x808000EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x808000F0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808000F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808000FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800104: jal         0x8008A2C8
    // 0x80800108: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x80800108: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_12:
    // 0x8080010C: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x80800110: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x80800114: jal         0x80101180
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80800118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x8080011C: jal         0x800D395C
    // 0x80800120: nop

    func_800D395C(rdram, ctx);
        goto after_14;
    // 0x80800120: nop

    after_14:
    // 0x80800124: beq         $v0, $zero, L_80800164
    if (ctx->r2 == 0) {
        // 0x80800128: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_80800164;
    }
    // 0x80800128: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8080012C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800130: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800134: addiu       $a1, $zero, 0x144E
    ctx->r5 = ADD32(0, 0X144E);
    // 0x80800138: bne         $v0, $at, L_80800148
    if (ctx->r2 != ctx->r1) {
        // 0x8080013C: nop
    
            goto L_80800148;
    }
    // 0x8080013C: nop

    // 0x80800140: b           L_80800264
    // 0x80800144: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
        goto L_80800264;
    // 0x80800144: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
L_80800148:
    // 0x80800148: bne         $v0, $zero, L_8080015C
    if (ctx->r2 != 0) {
        // 0x8080014C: addiu       $a1, $zero, 0x1450
        ctx->r5 = ADD32(0, 0X1450);
            goto L_8080015C;
    }
    // 0x8080014C: addiu       $a1, $zero, 0x1450
    ctx->r5 = ADD32(0, 0X1450);
    // 0x80800150: addiu       $a1, $zero, 0x144F
    ctx->r5 = ADD32(0, 0X144F);
    // 0x80800154: b           L_80800264
    // 0x80800158: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
        goto L_80800264;
    // 0x80800158: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
L_8080015C:
    // 0x8080015C: b           L_80800264
    // 0x80800160: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
        goto L_80800264;
    // 0x80800160: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
L_80800164:
    // 0x80800164: jal         0x800D0A9C
    // 0x80800168: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_15;
    // 0x80800168: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x8080016C: bne         $v0, $zero, L_80800190
    if (ctx->r2 != 0) {
        // 0x80800170: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80800190;
    }
    // 0x80800170: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800174: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80800178: addiu       $a1, $zero, 0x140A
    ctx->r5 = ADD32(0, 0X140A);
    // 0x8080017C: slti        $at, $t9, 0x28
    ctx->r1 = SIGNED(ctx->r25) < 0X28 ? 1 : 0;
    // 0x80800180: bnel        $at, $zero, L_80800194
    if (ctx->r1 != 0) {
        // 0x80800184: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_80800194;
    }
    goto skip_0;
    // 0x80800184: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    skip_0:
    // 0x80800188: b           L_80800264
    // 0x8080018C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
        goto L_80800264;
    // 0x8080018C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
L_80800190:
    // 0x80800190: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
L_80800194:
    // 0x80800194: jal         0x800D0A9C
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_16;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080019C: bne         $v0, $zero, L_808001C0
    if (ctx->r2 != 0) {
        // 0x808001A0: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_808001C0;
    }
    // 0x808001A0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808001A4: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x808001A8: addiu       $a1, $zero, 0x140C
    ctx->r5 = ADD32(0, 0X140C);
    // 0x808001AC: slti        $at, $t1, 0x32
    ctx->r1 = SIGNED(ctx->r9) < 0X32 ? 1 : 0;
    // 0x808001B0: bnel        $at, $zero, L_808001C4
    if (ctx->r1 != 0) {
        // 0x808001B4: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_808001C4;
    }
    goto skip_1;
    // 0x808001B4: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    skip_1:
    // 0x808001B8: b           L_80800264
    // 0x808001BC: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
        goto L_80800264;
    // 0x808001BC: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
L_808001C0:
    // 0x808001C0: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
L_808001C4:
    // 0x808001C4: jal         0x800D0A9C
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_17;
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808001CC: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808001D0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x808001D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x808001D8: jal         0x800D0A9C
    // 0x808001DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_18;
    // 0x808001DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x808001E0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808001E4: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808001E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808001EC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x808001F0: beq         $t5, $zero, L_80800234
    if (ctx->r13 == 0) {
        // 0x808001F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800234;
    }
    // 0x808001F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001F8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808001FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800200: addiu       $a1, $zero, 0x1410
    ctx->r5 = ADD32(0, 0X1410);
    // 0x80800204: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80800208: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x8080020C: nop
    
            goto L_80800224;
    }
    // 0x8080020C: nop

    // 0x80800210: beq         $v0, $at, L_8080022C
    if (ctx->r2 == ctx->r1) {
        // 0x80800214: addiu       $a1, $zero, 0x144C
        ctx->r5 = ADD32(0, 0X144C);
            goto L_8080022C;
    }
    // 0x80800214: addiu       $a1, $zero, 0x144C
    ctx->r5 = ADD32(0, 0X144C);
    // 0x80800218: addiu       $a1, $zero, 0x140E
    ctx->r5 = ADD32(0, 0X140E);
    // 0x8080021C: b           L_80800264
    // 0x80800220: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
        goto L_80800264;
    // 0x80800220: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
L_80800224:
    // 0x80800224: b           L_80800264
    // 0x80800228: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
        goto L_80800264;
    // 0x80800228: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
L_8080022C:
    // 0x8080022C: b           L_80800264
    // 0x80800230: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
        goto L_80800264;
    // 0x80800230: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
L_80800234:
    // 0x80800234: bne         $t7, $at, L_80800248
    if (ctx->r15 != ctx->r1) {
        // 0x80800238: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80800248;
    }
    // 0x80800238: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8080023C: addiu       $a1, $zero, 0x140D
    ctx->r5 = ADD32(0, 0X140D);
    // 0x80800240: b           L_80800264
    // 0x80800244: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
        goto L_80800264;
    // 0x80800244: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
L_80800248:
    // 0x80800248: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x8080024C: addiu       $a1, $zero, 0x1410
    ctx->r5 = ADD32(0, 0X1410);
    // 0x80800250: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80800254: beq         $t9, $zero, L_80800264
    if (ctx->r25 == 0) {
        // 0x80800258: nop
    
            goto L_80800264;
    }
    // 0x80800258: nop

    // 0x8080025C: b           L_80800264
    // 0x80800260: addiu       $a1, $zero, 0x140F
    ctx->r5 = ADD32(0, 0X140F);
        goto L_80800264;
    // 0x80800260: addiu       $a1, $zero, 0x140F
    ctx->r5 = ADD32(0, 0X140F);
L_80800264:
    // 0x80800264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800268: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8080026C: jal         0x800FDC28
    // 0x80800270: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800FDC28(rdram, ctx);
        goto after_19;
    // 0x80800270: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_19:
    // 0x80800274: jal         0x800FC6B0
    // 0x80800278: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800FC6B0(rdram, ctx);
        goto after_20;
    // 0x80800278: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_20:
    // 0x8080027C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800280: addiu       $t1, $zero, 0x99
    ctx->r9 = ADD32(0, 0X99);
    // 0x80800284: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800288: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8080028C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800290: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800294: jal         0x8008A208
    // 0x80800298: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800298: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x8080029C: b           L_808002D0
    // 0x808002A0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
        goto L_808002D0;
    // 0x808002A0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
L_808002A4:
    // 0x808002A4: jal         0x80090708
    // 0x808002A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_22;
    // 0x808002A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x808002AC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808002B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002B4: jal         0x8008A2C0
    // 0x808002B8: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x808002B8: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_23:
    // 0x808002BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002C4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x808002C8: swc1        $f4, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f4.u32l;
    // 0x808002CC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
L_808002D0:
    // 0x808002D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_808002D4:
    // 0x808002D4: jal         0x80101FDC
    // 0x808002D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80101FDC(rdram, ctx);
        goto after_24;
    // 0x808002D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_24:
    // 0x808002DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002E4: jr          $ra
    // 0x808002E8: nop

    return;
    // 0x808002E8: nop

;}
RECOMP_FUNC void func_80805960_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805968: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080596C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80805970: jal         0x80100094
    // 0x80805974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805978: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080597C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80805980: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80805984: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80805988: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080598C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80805990: sh          $t6, 0x36($t9)
    MEM_H(0X36, ctx->r25) = ctx->r14;
    // 0x80805994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080599C: jr          $ra
    // 0x808059A0: nop

    return;
    // 0x808059A0: nop

;}
RECOMP_FUNC void func_800E15CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E15CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E15D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E15D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E15D8: jal         0x800E1540
    // 0x800E15DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800E1540(rdram, ctx);
        goto after_0;
    // 0x800E15DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E15E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800E15E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E15E8: jal         0x800E13F0
    // 0x800E15EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800E13F0(rdram, ctx);
        goto after_1;
    // 0x800E15EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800E15F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E15F4: jal         0x800E144C
    // 0x800E15F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800E144C(rdram, ctx);
        goto after_2;
    // 0x800E15F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800E15FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E1600: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1604: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E1608: jr          $ra
    // 0x800E160C: nop

    return;
    // 0x800E160C: nop

;}
RECOMP_FUNC void func_80800520_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800528: jal         0x800897C8
    // 0x8080052C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x8080052C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void func_80801BF0_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BF4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BFC: beq         $a1, $at, L_80801C58
    if (ctx->r5 == ctx->r1) {
        // 0x80801C00: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80801C58;
    }
    // 0x80801C00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801C04: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80801C08: beq         $a1, $at, L_80801C38
    if (ctx->r5 == ctx->r1) {
        // 0x80801C0C: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80801C38;
    }
    // 0x80801C0C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801C10: beq         $a1, $at, L_80801C28
    if (ctx->r5 == ctx->r1) {
        // 0x80801C14: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80801C28;
    }
    // 0x80801C14: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80801C18: beq         $a1, $at, L_80801CD0
    if (ctx->r5 == ctx->r1) {
        // 0x80801C1C: nop
    
            goto L_80801CD0;
    }
    // 0x80801C1C: nop

    // 0x80801C20: b           L_80801CEC
    // 0x80801C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CEC;
    // 0x80801C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C28:
    // 0x80801C28: jal         0x80801A94
    // 0x80801C2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801A94_chclockworkmouse(rdram, ctx);
        goto after_0;
    // 0x80801C2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80801C30: b           L_80801CEC
    // 0x80801C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CEC;
    // 0x80801C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C38:
    // 0x80801C38: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x80801C3C: jal         0x80106790
    // 0x80801C40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801C40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80801C44: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801C48: jal         0x80801B90
    // 0x80801C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80801B90_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80801C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801C50: b           L_80801CEC
    // 0x80801C54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801CEC;
    // 0x80801C54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801C58:
    // 0x80801C58: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x80801C5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80801C60: jal         0x80106790
    // 0x80801C64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80801C64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x80801C68: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801C6C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80801C70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801C74: beq         $a2, $at, L_80801C90
    if (ctx->r6 == ctx->r1) {
        // 0x80801C78: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80801C90;
    }
    // 0x80801C78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801C7C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80801C80: beql        $a2, $at, L_80801C9C
    if (ctx->r6 == ctx->r1) {
        // 0x80801C84: addiu       $v1, $zero, 0x142F
        ctx->r3 = ADD32(0, 0X142F);
            goto L_80801C9C;
    }
    goto skip_0;
    // 0x80801C84: addiu       $v1, $zero, 0x142F
    ctx->r3 = ADD32(0, 0X142F);
    skip_0:
    // 0x80801C88: b           L_80801C9C
    // 0x80801C8C: nop

        goto L_80801C9C;
    // 0x80801C8C: nop

L_80801C90:
    // 0x80801C90: b           L_80801C9C
    // 0x80801C94: addiu       $v1, $zero, 0x142B
    ctx->r3 = ADD32(0, 0X142B);
        goto L_80801C9C;
    // 0x80801C94: addiu       $v1, $zero, 0x142B
    ctx->r3 = ADD32(0, 0X142B);
    // 0x80801C98: addiu       $v1, $zero, 0x142F
    ctx->r3 = ADD32(0, 0X142F);
L_80801C9C:
    // 0x80801C9C: beq         $v1, $zero, L_80801CC8
    if (ctx->r3 == 0) {
        // 0x80801CA0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801CC8;
    }
    // 0x80801CA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801CA4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801CA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801CAC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80801CB0: jal         0x8080079C
    // 0x80801CB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8080079C_chclockworkmouse(rdram, ctx);
        goto after_4;
    // 0x80801CB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80801CB8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CBC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801CC0: jal         0x80801B44
    // 0x80801CC4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80801B44_chclockworkmouse(rdram, ctx);
        goto after_5;
    // 0x80801CC4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_5:
L_80801CC8:
    // 0x80801CC8: b           L_80801CEC
    // 0x80801CCC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801CEC;
    // 0x80801CCC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801CD0:
    // 0x80801CD0: jal         0x80801850
    // 0x80801CD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801850_chclockworkmouse(rdram, ctx);
        goto after_6;
    // 0x80801CD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80801CD8: b           L_80801CEC
    // 0x80801CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801CEC;
    // 0x80801CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801CE0: b           L_80801CEC
    // 0x80801CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801CEC;
    // 0x80801CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801CEC:
    // 0x80801CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801CF4: jr          $ra
    // 0x80801CF8: nop

    return;
    // 0x80801CF8: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897A0: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897A0);
    return;
    // 0x800897A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800DAC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAC78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DAC7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DAC80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DAC84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DAC88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800DAC8C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x800DAC90: jal         0x80088588
    // 0x800DAC94: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    _glgamedata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800DAC94: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800DAC98: beq         $v0, $zero, L_800DACBC
    if (ctx->r2 == 0) {
        // 0x800DAC9C: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_800DACBC;
    }
    // 0x800DAC9C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800DACA0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DACA4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800DACA8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800DACAC: jal         0x800D9E60
    // 0x800DACB0: addiu       $a1, $a1, -0x28
    ctx->r5 = ADD32(ctx->r5, -0X28);
    bitfield_get_bit(rdram, ctx);
        goto after_1;
    // 0x800DACB0: addiu       $a1, $a1, -0x28
    ctx->r5 = ADD32(ctx->r5, -0X28);
    after_1:
    // 0x800DACB4: b           L_800DACC4
    // 0x800DACB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DACC4;
    // 0x800DACB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DACBC:
    // 0x800DACBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800DACC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DACC4:
    // 0x800DACC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DACC8: jr          $ra
    // 0x800DACCC: nop

    return;
    // 0x800DACCC: nop

;}
RECOMP_FUNC void _bastatemem_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085160: syscall     153
    recomp_syscall_handler(rdram, ctx, 0x80085160);
    return;
    // 0x80085164: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C5094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5094: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C509C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C50A0: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800C50A4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C50A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C50AC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800C50B0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800C50B4: jal         0x800A8A44
    // 0x800C50B8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_800A8A44(rdram, ctx);
        goto after_0;
    // 0x800C50B8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800C50BC: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800C50C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C50C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800C50C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800C50CC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800C50D0: jal         0x800A8A04
    // 0x800C50D4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_800A8A04(rdram, ctx);
        goto after_1;
    // 0x800C50D4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x800C50D8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C50DC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C50E0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C50E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C50E8: beql        $t8, $t9, L_800C5130
    if (ctx->r24 == ctx->r25) {
        // 0x800C50EC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800C5130;
    }
    goto skip_0;
    // 0x800C50EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x800C50F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C50F4: nop

    // 0x800C50F8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C50FC: jal         0x800139F8
    // 0x800C5100: nop

    func_800139F8(rdram, ctx);
        goto after_2;
    // 0x800C5100: nop

    after_2:
    // 0x800C5104: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C5108: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800C510C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800C5110: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800C5114: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C5118: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C511C: jal         0x80013B7C
    // 0x800C5120: div.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    func_80013B7C(rdram, ctx);
        goto after_3;
    // 0x800C5120: div.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    after_3:
    // 0x800C5124: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800C5128: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800C512C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800C5130:
    // 0x800C5130: jal         0x800A8A88
    // 0x800C5134: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800A8A88(rdram, ctx);
        goto after_4;
    // 0x800C5134: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x800C5138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C513C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C5140: jr          $ra
    // 0x800C5144: nop

    return;
    // 0x800C5144: nop

;}
RECOMP_FUNC void func_808031D0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808031D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808031D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808031D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808031DC: jal         0x80802CE8
    // 0x808031E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80802CE8_chhandcart(rdram, ctx);
        goto after_0;
    // 0x808031E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808031E4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808031E8: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x808031EC: beql        $a0, $zero, L_8080320C
    if (ctx->r4 == 0) {
        // 0x808031F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080320C;
    }
    goto skip_0;
    // 0x808031F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808031F4: jal         0x80106790
    // 0x808031F8: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808031F8: nop

    after_1:
    // 0x808031FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803200: jal         0x80800FA0
    // 0x80803204: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800FA0_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80803204: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80803208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080320C:
    // 0x8080320C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803210: jr          $ra
    // 0x80803214: nop

    return;
    // 0x80803214: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803450: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803454: andi        $t7, $t6, 0xDF
    ctx->r15 = ctx->r14 & 0XDF;
    // 0x80803458: jr          $ra
    // 0x8080345C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080345C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void bsblongleg_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800968: jal         0x80800204
    // 0x8080096C: nop

    func_80800204_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x8080096C: nop

    after_0:
    // 0x80800970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void chgruntyfireball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1488, 0X480) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1488, 0X480));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1488, 0X480));
;}
RECOMP_FUNC void func_80801C04_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C04: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801C08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801C0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801C10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C14: jal         0x80100094
    // 0x80801C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C1C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80801C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C24: addiu       $a1, $v0, 0x40
    ctx->r5 = ADD32(ctx->r2, 0X40);
    // 0x80801C28: jal         0x8008A2A0
    // 0x80801C2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801C2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80801C30: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80801C34: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X21D0) << 16);
    // 0x80801C38: addiu       $a1, $a1, 0x21D0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X21D0));
    // 0x80801C3C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80801C40: jal         0x8008A300
    // 0x80801C44: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80801C44: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_2:
    // 0x80801C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C4C: jal         0x80100094
    // 0x80801C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801C54: jal         0x8008A038
    // 0x80801C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80801C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801C5C: bne         $v0, $zero, L_80801C90
    if (ctx->r2 != 0) {
        // 0x80801C60: nop
    
            goto L_80801C90;
    }
    // 0x80801C60: nop

    // 0x80801C64: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801C68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801C6C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801C70: beq         $t6, $at, L_80801C90
    if (ctx->r14 == ctx->r1) {
        // 0x80801C74: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801C90;
    }
    // 0x80801C74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C78: beq         $t6, $at, L_80801C90
    if (ctx->r14 == ctx->r1) {
        // 0x80801C7C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801C90;
    }
    // 0x80801C7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801C80: beq         $t6, $at, L_80801C90
    if (ctx->r14 == ctx->r1) {
        // 0x80801C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C90;
    }
    // 0x80801C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C88: jal         0x80102424
    // 0x80801C8C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80801C8C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
L_80801C90:
    // 0x80801C90: jal         0x800EA05C
    // 0x80801C94: nop

    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x80801C94: nop

    after_6:
    // 0x80801C98: addiu       $at, $zero, 0xAF
    ctx->r1 = ADD32(0, 0XAF);
    // 0x80801C9C: bne         $v0, $at, L_80801DB0
    if (ctx->r2 != ctx->r1) {
        // 0x80801CA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801DB0;
    }
    // 0x80801CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801CA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801CAC: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80801CB0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80801CB4: jal         0x8008A0C8
    // 0x80801CB8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80801CB8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80801CBC: jal         0x800D3934
    // 0x80801CC0: nop

    func_800D3934(rdram, ctx);
        goto after_8;
    // 0x80801CC0: nop

    after_8:
    // 0x80801CC4: bne         $v0, $zero, L_80801D24
    if (ctx->r2 != 0) {
        // 0x80801CC8: nop
    
            goto L_80801D24;
    }
    // 0x80801CC8: nop

    // 0x80801CCC: jal         0x800DA298
    // 0x80801CD0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80801CD0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_9:
    // 0x80801CD4: beq         $v0, $zero, L_80801CEC
    if (ctx->r2 == 0) {
        // 0x80801CD8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801CEC;
    }
    // 0x80801CD8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801CDC: jal         0x800FFAB0
    // 0x80801CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80801CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801CE4: b           L_80801E08
    // 0x80801CE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E08;
    // 0x80801CE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801CEC:
    // 0x80801CEC: jal         0x800EE7F8
    // 0x80801CF0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80801CF0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80801CF4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801CF8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80801CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D00: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80801D04: addiu       $a1, $zero, 0x90E
    ctx->r5 = ADD32(0, 0X90E);
    // 0x80801D08: jal         0x80103140
    // 0x80801D0C: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    func_80103140(rdram, ctx);
        goto after_12;
    // 0x80801D0C: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    after_12:
    // 0x80801D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D14: jal         0x80102424
    // 0x80801D18: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80801D18: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_13:
    // 0x80801D1C: b           L_80801DB0
    // 0x80801D20: nop

        goto L_80801DB0;
    // 0x80801D20: nop

L_80801D24:
    // 0x80801D24: jal         0x800DA298
    // 0x80801D28: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80801D28: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    after_14:
    // 0x80801D2C: bne         $v0, $zero, L_80801DB0
    if (ctx->r2 != 0) {
        // 0x80801D30: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801DB0;
    }
    // 0x80801D30: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801D34: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801D38: jal         0x800EE7F8
    // 0x80801D3C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80801D3C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_15:
    // 0x80801D40: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801D44: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D4C: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x80801D50: addiu       $a1, $zero, 0x90E
    ctx->r5 = ADD32(0, 0X90E);
    // 0x80801D54: jal         0x80103140
    // 0x80801D58: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_80103140(rdram, ctx);
        goto after_16;
    // 0x80801D58: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_16:
    // 0x80801D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D60: jal         0x80102424
    // 0x80801D64: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80801D64: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_17:
    // 0x80801D68: jal         0x800F54E4
    // 0x80801D6C: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80801D6C: nop

    after_18:
    // 0x80801D70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D74: jal         0x800F82D4
    // 0x80801D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F82D4(rdram, ctx);
        goto after_19;
    // 0x80801D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80801D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D80: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80801D84: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80801D88: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80801D8C: jal         0x8008A2D0
    // 0x80801D90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x80801D90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_20:
    // 0x80801D94: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801D98: addiu       $t0, $zero, 0xBB
    ctx->r8 = ADD32(0, 0XBB);
    // 0x80801D9C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801DA0: addiu       $a1, $zero, 0x15C5
    ctx->r5 = ADD32(0, 0X15C5);
    // 0x80801DA4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80801DA8: jal         0x8008A208
    // 0x80801DAC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80801DAC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_21:
L_80801DB0:
    // 0x80801DB0: jal         0x800BF8E4
    // 0x80801DB4: nop

    func_800BF8E4(rdram, ctx);
        goto after_22;
    // 0x80801DB4: nop

    after_22:
    // 0x80801DB8: beql        $v0, $zero, L_80801E04
    if (ctx->r2 == 0) {
        // 0x80801DBC: sw          $zero, 0x24($s0)
        MEM_W(0X24, ctx->r16) = 0;
            goto L_80801E04;
    }
    goto skip_0;
    // 0x80801DBC: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    skip_0:
    // 0x80801DC0: jal         0x80800FF8
    // 0x80801DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FF8_chevilspirit(rdram, ctx);
        goto after_23;
    // 0x80801DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801DC8: bnel        $v0, $zero, L_80801E04
    if (ctx->r2 != 0) {
        // 0x80801DCC: sw          $zero, 0x24($s0)
        MEM_W(0X24, ctx->r16) = 0;
            goto L_80801E04;
    }
    goto skip_1;
    // 0x80801DCC: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    skip_1:
    // 0x80801DD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801DD4: jal         0x800C8A98
    // 0x80801DD8: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    func_800C8A98(rdram, ctx);
        goto after_24;
    // 0x80801DD8: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    after_24:
    // 0x80801DDC: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80801DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DE4: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x80801DE8: jal         0x800C8E54
    // 0x80801DEC: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800C8E54(rdram, ctx);
        goto after_25;
    // 0x80801DEC: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_25:
    // 0x80801DF0: jal         0x80801E18
    // 0x80801DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801E18_chevilspirit(rdram, ctx);
        goto after_26;
    // 0x80801DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801DF8: b           L_80801E08
    // 0x80801DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E08;
    // 0x80801DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801E00: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80801E04:
    // 0x80801E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E08:
    // 0x80801E08: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801E0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801E10: jr          $ra
    // 0x80801E14: nop

    return;
    // 0x80801E14: nop

;}
RECOMP_FUNC void func_8008B304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B30C: jal         0x8008C038
    // 0x8008B310: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C038(rdram, ctx);
        goto after_0;
    // 0x8008B310: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B31C: jr          $ra
    // 0x8008B320: nop

    return;
    // 0x8008B320: nop

;}
