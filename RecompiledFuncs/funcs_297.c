#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chexplodingchainlinks_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086760: syscall     366
    recomp_syscall_handler(rdram, ctx, 0x80086760);
    return;
    // 0x80086764: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bakey_heldCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091978: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8009197C: addu        $t6, $v0, $a1
    ctx->r14 = ADD32(ctx->r2, ctx->r5);
    // 0x80091980: lbu         $t7, 0x18($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X18);
    // 0x80091984: beq         $t7, $zero, L_80091994
    if (ctx->r15 == 0) {
        // 0x80091988: nop
    
            goto L_80091994;
    }
    // 0x80091988: nop

    // 0x8009198C: b           L_8009199C
    // 0x80091990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009199C;
    // 0x80091990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091994:
    // 0x80091994: jal         0x800BCF28
    // 0x80091998: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800BCF28(rdram, ctx);
        goto after_0;
    // 0x80091998: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
L_8009199C:
    // 0x8009199C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800919A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800919A4: jr          $ra
    // 0x800919A8: nop

    return;
    // 0x800919A8: nop

;}
RECOMP_FUNC void func_80808BE4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80808BEC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80808BF0: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80808BF4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0XA1AC) << 16);
    // 0x80808BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808BFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80808C00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80808C04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80808C08: lwc1        $f4, -0x5E54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0XA1AC));
    // 0x80808C0C: lwc1        $f6, 0x48($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80808C10: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x80808C14: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(1480, 0XA1BC) << 16);
    // 0x80808C18: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80808C1C: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA1CC) << 16);
    // 0x80808C20: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80808C24: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80808C28: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80808C2C: lw          $a1, -0x5E44($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1480, 0XA1BC));
    // 0x80808C30: lw          $a3, -0x5E34($a3)
    ctx->r7 = MEM_W(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA1CC));
    // 0x80808C34: jal         0x800EEC30
    // 0x80808C38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EEC30(rdram, ctx);
        goto after_0;
    // 0x80808C38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80808C3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80808C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80808C44: jal         0x800EF04C
    // 0x80808C48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80808C48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80808C4C: jal         0x80103014
    // 0x80808C50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80103014(rdram, ctx);
        goto after_2;
    // 0x80808C50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80808C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808C5C: jr          $ra
    // 0x80808C60: nop

    return;
    // 0x80808C60: nop

;}
RECOMP_FUNC void chgameselect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D68: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X8038) << 16);
    // 0x80800D6C: jr          $ra
    // 0x80800D70: addiu       $v0, $v0, -0x7FC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8038));
    return;
    // 0x80800D70: addiu       $v0, $v0, -0x7FC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8038));
;}
RECOMP_FUNC void subaddiefind_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007B0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808007B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808007C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808007C4: jal         0x80800808
    // 0x808007C8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    subaddiefind_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808007C8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808007CC: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x808007D0: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_808007E0;
    }
    // 0x808007D0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808007D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808007D8: b           L_808007E4
    // 0x808007DC: sw          $t6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r14;
        goto L_808007E4;
    // 0x808007DC: sw          $t6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r14;
L_808007E0:
    // 0x808007E0: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
L_808007E4:
    // 0x808007E4: lw          $t7, 0x3C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X3C);
    // 0x808007E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007F0: beq         $t7, $zero, L_80800800
    if (ctx->r15 == 0) {
        // 0x808007F4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800800;
    }
    // 0x808007F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808007F8: b           L_80800800
    // 0x808007FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800800;
    // 0x808007FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800800:
    // 0x80800800: jr          $ra
    // 0x80800804: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800804: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808008B0_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B8: jal         0x80100094
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008C0: sb          $zero, 0x99($v0)
    MEM_B(0X99, ctx->r2) = 0;
    // 0x808008C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008CC: jr          $ra
    // 0x808008D0: nop

    return;
    // 0x808008D0: nop

;}
RECOMP_FUNC void func_800F5680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5680: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5688: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F568C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5690: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5694: jal         0x800963C0
    // 0x800F5698: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800963C0(rdram, ctx);
        goto after_0;
    // 0x800F5698: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F569C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F56A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F56A4: jr          $ra
    // 0x800F56A8: nop

    return;
    // 0x800F56A8: nop

;}
RECOMP_FUNC void gzthread_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3398, 0X380) << 16);
    // 0x80800008: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080000C: lw          $v0, 0x380($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(3398, 0X380));
    // 0x80800010: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800014: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80800018: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080001C: beq         $v1, $zero, L_80800038
    if (ctx->r3 == 0) {
        // 0x80800020: sb          $v1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r3;
            goto L_80800038;
    }
    // 0x80800020: sb          $v1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r3;
L_80800024:
    // 0x80800024: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80800028: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8080002C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800030: bne         $v1, $zero, L_80800024
    if (ctx->r3 != 0) {
        // 0x80800034: sb          $v1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r3;
            goto L_80800024;
    }
    // 0x80800034: sb          $v1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r3;
L_80800038:
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void chswitch_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800450: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080045C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800460: beq         $t6, $at, L_808005D4
    if (ctx->r14 == ctx->r1) {
        // 0x80800464: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005D4;
    }
    // 0x80800464: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800468: beq         $t6, $at, L_80800488
    if (ctx->r14 == ctx->r1) {
        // 0x8080046C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800488;
    }
    // 0x8080046C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800470: beq         $t6, $at, L_808004A8
    if (ctx->r14 == ctx->r1) {
        // 0x80800474: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808004A8;
    }
    // 0x80800474: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800478: beq         $t6, $at, L_80800594
    if (ctx->r14 == ctx->r1) {
        // 0x8080047C: nop
    
            goto L_80800594;
    }
    // 0x8080047C: nop

    // 0x80800480: b           L_808005D8
    // 0x80800484: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
        goto L_808005D8;
    // 0x80800484: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
L_80800488:
    // 0x80800488: jal         0x80101DDC
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800490: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x80800494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D4;
    }
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x80102424
    // 0x8080049C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080049C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808004A0: b           L_808005D8
    // 0x808004A4: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
        goto L_808005D8;
    // 0x808004A4: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
L_808004A8:
    // 0x808004A8: jal         0x800878A0
    // 0x808004AC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808004AC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_2:
    // 0x808004B0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808004B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808004B8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x808004BC: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808004C0: bltzl       $t9, L_80800530
    if (SIGNED(ctx->r25) < 0) {
        // 0x808004C4: lw          $t5, 0x6C($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X6C);
            goto L_80800530;
    }
    goto skip_0;
    // 0x808004C4: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x808004C8: beq         $t0, $zero, L_8080052C
    if (ctx->r8 == 0) {
        // 0x808004CC: addiu       $a0, $s0, 0x54
        ctx->r4 = ADD32(ctx->r16, 0X54);
            goto L_8080052C;
    }
    // 0x808004CC: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x808004D0: jal         0x800D9078
    // 0x808004D4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x808004D4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x808004D8: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808004DC: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_808005D4;
    }
    // 0x808004DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808004E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808004E4: jal         0x800F7F98
    // 0x808004E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x808004E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004EC: jal         0x800DA544
    // 0x808004F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808004F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x808004F4: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808004F8: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800504: beq         $t4, $zero, L_80800514
    if (ctx->r12 == 0) {
        // 0x80800508: sb          $t3, 0x65($s0)
        MEM_B(0X65, ctx->r16) = ctx->r11;
            goto L_80800514;
    }
    // 0x80800508: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x8080050C: jal         0x80103110
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x80800510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80800514:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080051C: jal         0x8010108C
    // 0x80800520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_7;
    // 0x80800520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800524: b           L_808005D8
    // 0x80800528: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
        goto L_808005D8;
    // 0x80800528: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
L_8080052C:
    // 0x8080052C: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
L_80800530:
    // 0x80800530: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80800534: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800538: beq         $t6, $zero, L_80800548
    if (ctx->r14 == 0) {
        // 0x8080053C: nop
    
            goto L_80800548;
    }
    // 0x8080053C: nop

    // 0x80800540: bne         $t7, $zero, L_80800588
    if (ctx->r15 != 0) {
        // 0x80800544: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(696, 0XDA0) << 16);
            goto L_80800588;
    }
    // 0x80800544: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(696, 0XDA0) << 16);
L_80800548:
    // 0x80800548: jal         0x800D90A4
    // 0x8080054C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x8080054C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x80800550: beql        $v0, $zero, L_808005D8
    if (ctx->r2 == 0) {
        // 0x80800554: lhu         $t0, 0x6E($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X6E);
            goto L_808005D8;
    }
    goto skip_1;
    // 0x80800554: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    skip_1:
    // 0x80800558: jal         0x800880D0
    // 0x8080055C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x8080055C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800564: jal         0x80102424
    // 0x80800568: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80800568: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x8080056C: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800570: lui         $at, 0x3EC0
    ctx->r1 = S32(0X3EC0 << 16);
    // 0x80800574: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800578: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x8080057C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800580: b           L_808005D4
    // 0x80800584: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
        goto L_808005D4;
    // 0x80800584: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_80800588:
    // 0x80800588: lwc1        $f6, 0xDA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(696, 0XDA0));
    // 0x8080058C: b           L_808005D4
    // 0x80800590: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005D4;
    // 0x80800590: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800594:
    // 0x80800594: jal         0x80101DDC
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_11;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080059C: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808005A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D4;
    }
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: jal         0x80103110
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_12;
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: jal         0x80102424
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x808005B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808005B8: jal         0x800DA524
    // 0x808005BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA524(rdram, ctx);
        goto after_14;
    // 0x808005BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_14:
    // 0x808005C0: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808005CC: jal         0x8010108C
    // 0x808005D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_15;
    // 0x808005D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
L_808005D4:
    // 0x808005D4: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
L_808005D8:
    // 0x808005D8: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x808005DC: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void func_800FB338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB338: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800FB33C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800FB340: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800FB344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FB348: jr          $ra
    // 0x800FB34C: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    return;
    // 0x800FB34C: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80104544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010454C: jal         0x801043D8
    // 0x80104550: nop

    func_801043D8(rdram, ctx);
        goto after_0;
    // 0x80104550: nop

    after_0:
    // 0x80104554: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80104558: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8010455C: beq         $t6, $zero, L_80104570
    if (ctx->r14 == 0) {
        // 0x80104560: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80104570;
    }
    // 0x80104560: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80104564: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x80104568: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8010456C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80104570:
    // 0x80104570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104578: jr          $ra
    // 0x8010457C: nop

    return;
    // 0x8010457C: nop

;}
RECOMP_FUNC void chwandglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080033C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800340: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800344: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800348: jal         0x800F5A2C
    // 0x8080034C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800F5A2C(rdram, ctx);
        goto after_0;
    // 0x8080034C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800350: addiu       $a0, $zero, 0x164
    ctx->r4 = ADD32(0, 0X164);
    // 0x80800354: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800358: jal         0x80108474
    // 0x8080035C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x8080035C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800360: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800364: lhu         $t9, 0x6E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X6E);
    // 0x80800368: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080036C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800370: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800374: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800378: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080037C: sh          $t1, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r9;
    // 0x80800380: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80800384: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800388: jal         0x8080011C
    // 0x8080038C: sw          $t2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r10;
    func_8080011C_chwandglow(rdram, ctx);
        goto after_2;
    // 0x8080038C: sw          $t2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r10;
    after_2:
    // 0x80800390: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80800394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800398: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8080039C: jr          $ra
    // 0x808003A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808003A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C883C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C883C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8840: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C884C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8850: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8854: jal         0x800B28CC
    // 0x800C8858: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C8858: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C885C: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800C8860: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8864: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C8868: nop

    // 0x800C886C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C8870: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800C8874: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x800C8878: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C887C: nop

    // 0x800C8880: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C8884: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800C8888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C888C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8890: jr          $ra
    // 0x800C8894: nop

    return;
    // 0x800C8894: nop

;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DC24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002DC28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DC2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DC30: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002DC34: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002DC38: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x8002DC3C: addiu       $a0, $a0, -0x2388
    ctx->r4 = ADD32(ctx->r4, -0X2388);
    // 0x8002DC40: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8002DC44: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8002DC48: jal         0x80030B30
    // 0x8002DC4C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x8002DC4C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8002DC50: bltz        $v0, L_8002DC64
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002DC54: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8002DC64;
    }
    // 0x8002DC54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002DC58: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002DC5C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8002DC60: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_8002DC64:
    // 0x8002DC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DC68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DC6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8002DC70: jr          $ra
    // 0x8002DC74: nop

    return;
    // 0x8002DC74: nop

;}
RECOMP_FUNC void func_80801924_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080192C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801934: jal         0x80100094
    // 0x80801938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080193C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801940: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801944: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80801948: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080194C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80801950: bgez        $t8, L_80801960
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801954: nop
    
            goto L_80801960;
    }
    // 0x80801954: nop

    // 0x80801958: b           L_80801960
    // 0x8080195C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80801960;
    // 0x8080195C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80801960:
    // 0x80801960: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x80801964: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80801968: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8080196C: beql        $at, $zero, L_80801A40
    if (ctx->r1 == 0) {
        // 0x80801970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801A40;
    }
    goto skip_0;
    // 0x80801970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801974: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80801978: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8080197C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80801980: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80801984: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80801988: bgtz        $t2, L_808019A0
    if (SIGNED(ctx->r10) > 0) {
        // 0x8080198C: sw          $t4, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r12;
            goto L_808019A0;
    }
    // 0x8080198C: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x80801990: jal         0x808012B4
    // 0x80801994: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x80801994: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_1:
    // 0x80801998: b           L_80801A40
    // 0x8080199C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801A40;
    // 0x8080199C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808019A0:
    // 0x808019A0: lhu         $t6, 0x76($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X76);
    // 0x808019A4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x808019A8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808019AC: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x808019B0: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x808019B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808019B8: sb          $t9, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r25;
    // 0x808019BC: lhu         $t0, 0x76($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X76);
    // 0x808019C0: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x808019C4: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x808019C8: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x808019CC: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x808019D0: bnel        $at, $zero, L_808019E0
    if (ctx->r1 != 0) {
        // 0x808019D4: lhu         $t4, 0x72($a0)
        ctx->r12 = MEM_HU(ctx->r4, 0X72);
            goto L_808019E0;
    }
    goto skip_1;
    // 0x808019D4: lhu         $t4, 0x72($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X72);
    skip_1:
    // 0x808019D8: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x808019DC: lhu         $t4, 0x72($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X72);
L_808019E0:
    // 0x808019E0: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x808019E4: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x808019E8: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x808019EC: beq         $at, $zero, L_80801A3C
    if (ctx->r1 == 0) {
        // 0x808019F0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801A3C;
    }
    // 0x808019F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808019F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X50FC) << 16);
    // 0x808019F8: addu        $at, $at, $t6
    gpr jr_addend_80801A00 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808019FC: lw          $t6, 0x50FC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X50FC));
    // 0x80801A00: jr          $t6
    // 0x80801A04: nop

    switch (jr_addend_80801A00 >> 2) {
        case 0: goto L_80801A08; break;
        case 1: goto L_80801A08; break;
        case 2: goto L_80801A08; break;
        case 3: goto L_80801A18; break;
        case 4: goto L_80801A18; break;
        case 5: goto L_80801A18; break;
        default: switch_error(__func__, 0x80801A00, 0x808050FC);
    }
    // 0x80801A04: nop

L_80801A08:
    // 0x80801A08: jal         0x808012B4
    // 0x80801A0C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80801A0C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_2:
    // 0x80801A10: b           L_80801A40
    // 0x80801A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801A40;
    // 0x80801A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A18:
    // 0x80801A18: lw          $t8, 0x6C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X6C);
    // 0x80801A1C: lhu         $t1, 0x6E($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X6E);
    // 0x80801A20: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80801A24: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80801A28: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80801A2C: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80801A30: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80801A34: jal         0x808012B4
    // 0x80801A38: sh          $t3, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r11;
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80801A38: sh          $t3, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r11;
    after_3:
L_80801A3C:
    // 0x80801A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A40:
    // 0x80801A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A44: jr          $ra
    // 0x80801A48: nop

    return;
    // 0x80801A48: nop

;}
RECOMP_FUNC void func_80800A08_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A08: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800A0C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800A10: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800A14: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800A18: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800A1C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800A20: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800A24: jal         0x80087CA8
    // 0x80800A28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    _gcnewoption_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800A2C: addiu       $s3, $s4, 0x30
    ctx->r19 = ADD32(ctx->r20, 0X30);
    // 0x80800A30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A34: jal         0x8002D6E0
    // 0x80800A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_1;
    // 0x80800A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800A3C: lb          $t6, 0xD($s4)
    ctx->r14 = MEM_B(ctx->r20, 0XD);
    // 0x80800A40: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2658, 0X2070) << 16);
    // 0x80800A44: addiu       $s0, $s0, 0x2070
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2658, 0X2070));
    tooie_pause_settings_setup(rdram, ctx);
    // 0x80800A48: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800A4C: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80800A50: lh          $a3, 0x0($t8)
    ctx->r7 = MEM_H(ctx->r24, 0X0);
    // 0x80800A54: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80800A58: addiu       $a1, $a1, -0x7DE8
    ctx->r5 = ADD32(ctx->r5, -0X7DE8);
    // 0x80800A5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A64: jal         0x80087CC0
    // 0x80800A68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcnewoption_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800A68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800A6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A70: jal         0x80087CE8
    // 0x80800A74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800A74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800A78: lb          $t9, 0xD($s4)
    ctx->r25 = MEM_B(ctx->r20, 0XD);
    // 0x80800A7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A80: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80800A84: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x80800A88: lbu         $s2, 0x3($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X3);
    // 0x80800A8C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80800A90: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    tooie_pause_settings_visible(rdram, ctx);
    // 0x80800A94: jal         0x80087CD8
    // 0x80800A98: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800A98: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    after_4:
    // 0x80800A9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AA0: jal         0x80087CE0
    // 0x80800AA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800AA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800AA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AAC: jal         0x80087E08
    // 0x80800AB0: lbu         $a1, 0xC($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0XC);
    _gcnewoption_entrypoint_46(rdram, ctx);
        goto after_6;
    // 0x80800AB0: lbu         $a1, 0xC($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0XC);
    after_6:
    // 0x80800AB4: blez        $s2, L_80800ADC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800AB8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800ADC;
    }
    // 0x80800AB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800ABC: lw          $s1, 0x80($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X80);
L_80800AC0:
    // 0x80800AC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800AC8: jal         0x80087D90
    // 0x80800ACC: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_7;
    // 0x80800ACC: lh          $a2, 0x0($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X0);
    after_7:
    // 0x80800AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800AD4: bne         $s0, $s2, L_80800AC0
    if (ctx->r16 != ctx->r18) {
        // 0x80800AD8: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_80800AC0;
    }
    // 0x80800AD8: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
L_80800ADC:
    // 0x80800ADC: jal         0x80087DB8
    // 0x80800AE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_36(rdram, ctx);
        goto after_8;
    // 0x80800AE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x80800AE4: lb          $v0, 0xD($s4)
    ctx->r2 = MEM_B(ctx->r20, 0XD);
    // 0x80800AE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800AEC: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x80800AF0: beq         $v0, $at, L_80800BDC
    if (ctx->r2 == ctx->r1) {
        // 0x80800AF4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800BDC;
    }
    // 0x80800AF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AF8: bne         $v0, $s2, L_80800BDC
    if (ctx->r2 != ctx->r18) {
        // 0x80800AFC: addiu       $t2, $sp, 0x5C
        ctx->r10 = ADD32(ctx->r29, 0X5C);
            goto L_80800BDC;
    }
    // 0x80800AFC: addiu       $t2, $sp, 0x5C
    ctx->r10 = ADD32(ctx->r29, 0X5C);
    // 0x80800B00: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2658, 0X2190) << 16);
    // 0x80800B04: addiu       $t3, $t3, 0x2190
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2658, 0X2190));
    // 0x80800B08: addiu       $t5, $t3, 0x24
    ctx->r13 = ADD32(ctx->r11, 0X24);
L_80800B0C:
    // 0x80800B0C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80800B10: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80800B14: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80800B18: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x80800B1C: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x80800B20: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x80800B24: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x80800B28: bne         $t3, $t5, L_80800B0C
    if (ctx->r11 != ctx->r13) {
        // 0x80800B2C: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_80800B0C;
    }
    // 0x80800B2C: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x80800B30: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X21B4) << 16);
    // 0x80800B34: addiu       $t7, $t7, 0x21B4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X21B4));
    // 0x80800B38: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800B3C: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x80800B40: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80800B44: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800B48: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800B4C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80800B50: jal         0x80088368
    // 0x80800B54: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800B54: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_9:
    // 0x80800B58: lbu         $t0, 0xC($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0XC);
    // 0x80800B5C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x80800B60: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800B64: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80800B68: addu        $t4, $t1, $v0
    ctx->r12 = ADD32(ctx->r9, ctx->r2);
    // 0x80800B6C: addu        $a0, $sp, $t4
    ctx->r4 = ADD32(ctx->r29, ctx->r12);
    // 0x80800B70: lbu         $a0, 0x4E($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4E);
    // 0x80800B74: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800B78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B7C: mflo        $t5
    ctx->r13 = lo;
    // 0x80800B80: addu        $v1, $t5, $t3
    ctx->r3 = ADD32(ctx->r13, ctx->r11);
    // 0x80800B84: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80800B88: lh          $s0, 0x0($v1)
    ctx->r16 = MEM_H(ctx->r3, 0X0);
    // 0x80800B8C: lh          $s1, 0x2($v1)
    ctx->r17 = MEM_H(ctx->r3, 0X2);
    // 0x80800B90: beq         $t2, $zero, L_80800BA0
    if (ctx->r10 == 0) {
        // 0x80800B94: nop
    
            goto L_80800BA0;
    }
    // 0x80800B94: nop

    // 0x80800B98: jal         0x80087E20
    // 0x80800B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_49(rdram, ctx);
        goto after_10;
    // 0x80800B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80800BA0:
    // 0x80800BA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FC0) << 16);
    // 0x80800BA4: lwc1        $f0, 0x1FC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FC0));
    // 0x80800BA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800BAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800BB0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800BB4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80800BB8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800BBC: jal         0x80087DD8
    // 0x80800BC0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_11;
    // 0x80800BC0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80800BC4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800BC8: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80800BCC: sb          $v0, 0x10($s4)
    MEM_B(0X10, ctx->r20) = ctx->r2;
    // 0x80800BD0: sb          $v0, 0x11($s4)
    MEM_B(0X11, ctx->r20) = ctx->r2;
    // 0x80800BD4: b           L_80800C1C
    // 0x80800BD8: sb          $t8, 0x12($s4)
    MEM_B(0X12, ctx->r20) = ctx->r24;
        goto L_80800C1C;
    // 0x80800BD8: sb          $t8, 0x12($s4)
    MEM_B(0X12, ctx->r20) = ctx->r24;
L_80800BDC:
    // 0x80800BDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FC4) << 16);
    // 0x80800BE0: lwc1        $f4, 0x1FC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FC4));
    // 0x80800BE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FC8) << 16);
    // 0x80800BE8: lwc1        $f6, 0x1FC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FC8));
    // 0x80800BEC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80800BF0: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    // 0x80800BF4: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    // 0x80800BF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800BFC: jal         0x80087DD8
    // 0x80800C00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_12;
    // 0x80800C00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80800C04: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800C08: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800C0C: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80800C10: sb          $v0, 0x10($s4)
    MEM_B(0X10, ctx->r20) = ctx->r2;
    // 0x80800C14: sb          $t6, 0x11($s4)
    MEM_B(0X11, ctx->r20) = ctx->r14;
    // 0x80800C18: sb          $t7, 0x12($s4)
    MEM_B(0X12, ctx->r20) = ctx->r15;
L_80800C1C:
    // 0x80800C1C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800C20: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800C24: jal         0x80087DE8
    // 0x80800C28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_13;
    // 0x80800C28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x80800C2C: jal         0x80087CF0
    // 0x80800C30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800C30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x80800C34: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800C38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C3C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800C40: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800C44: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C48: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800C4C: jr          $ra
    // 0x80800C50: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800C50: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8080232C_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080232C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80802330: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80802334: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80802338: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080233C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80802340: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80802344: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80802348: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080234C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80802350: jal         0x80100094
    // 0x80802354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802358: lh          $t6, 0x13E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X13E);
    // 0x8080235C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80802360: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802364: beq         $t6, $zero, L_80802454
    if (ctx->r14 == 0) {
        // 0x80802368: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802454;
    }
    // 0x80802368: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080236C: jal         0x800D9078
    // 0x80802370: addiu       $a0, $v0, 0x140
    ctx->r4 = ADD32(ctx->r2, 0X140);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80802370: addiu       $a0, $v0, 0x140
    ctx->r4 = ADD32(ctx->r2, 0X140);
    after_1:
    // 0x80802374: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80802378: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080237C: lw          $a2, 0x144($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X144);
    // 0x80802380: lwc1        $f12, 0x140($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X140);
    // 0x80802384: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80802388: jal         0x800F12D4
    // 0x8080238C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x8080238C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80802390: addiu       $s0, $s3, 0x148
    ctx->r16 = ADD32(ctx->r19, 0X148);
    // 0x80802394: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80802398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080239C: jal         0x800F1A88
    // 0x808023A0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800F1A88(rdram, ctx);
        goto after_3;
    // 0x808023A0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x808023A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808023A8: jal         0x800F1A88
    // 0x808023AC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x808023AC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_4:
    // 0x808023B0: jal         0x800EEF94
    // 0x808023B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEF94(rdram, ctx);
        goto after_5;
    // 0x808023B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808023B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808023BC: jal         0x800EEF94
    // 0x808023C0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    func_800EEF94(rdram, ctx);
        goto after_6;
    // 0x808023C0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x808023C4: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808023C8: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x808023CC: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x808023D0: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808023D4: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
    // 0x808023D8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808023DC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x808023E0: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
L_808023E4:
    // 0x808023E4: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808023E8: jal         0x800F1DCC
    // 0x808023EC: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    func_800F1DCC(rdram, ctx);
        goto after_7;
    // 0x808023EC: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x808023F0: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808023F4: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808023F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808023FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80802400: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80802404: bne         $s0, $s2, L_808023E4
    if (ctx->r16 != ctx->r18) {
        // 0x80802408: swc1        $f18, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f18.u32l;
            goto L_808023E4;
    }
    // 0x80802408: swc1        $f18, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8080240C: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x80802410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802414: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80802418: jal         0x800EEBF0
    // 0x8080241C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_800EEBF0(rdram, ctx);
        goto after_8;
    // 0x8080241C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x80802420: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80802424: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802428: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x8080242C: jal         0x800A516C
    // 0x80802430: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800A516C(rdram, ctx);
        goto after_9;
    // 0x80802430: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80802434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802438: jal         0x80801ECC
    // 0x8080243C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80801ECC_chdinoboss(rdram, ctx);
        goto after_10;
    // 0x8080243C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x80802440: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80802444: beql        $t7, $zero, L_80802470
    if (ctx->r15 == 0) {
        // 0x80802448: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80802470;
    }
    goto skip_0;
    // 0x80802448: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8080244C: b           L_8080246C
    // 0x80802450: sh          $zero, 0x13E($s3)
    MEM_H(0X13E, ctx->r19) = 0;
        goto L_8080246C;
    // 0x80802450: sh          $zero, 0x13E($s3)
    MEM_H(0X13E, ctx->r19) = 0;
L_80802454:
    // 0x80802454: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x80802458: jal         0x800A516C
    // 0x8080245C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800A516C(rdram, ctx);
        goto after_11;
    // 0x8080245C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_11:
    // 0x80802460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802464: jal         0x80801ECC
    // 0x80802468: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80801ECC_chdinoboss(rdram, ctx);
        goto after_12;
    // 0x80802468: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
L_8080246C:
    // 0x8080246C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80802470:
    // 0x80802470: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802474: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80802478: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080247C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80802480: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80802484: jr          $ra
    // 0x80802488: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80802488: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800D740C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D740C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D7410: jr          $ra
    // 0x800D7414: sw          $zero, -0x4004($at)
    MEM_W(-0X4004, ctx->r1) = 0;
    return;
    // 0x800D7414: sw          $zero, -0x4004($at)
    MEM_W(-0X4004, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80801A54_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A58: slti        $at, $a1, 0xCED
    ctx->r1 = SIGNED(ctx->r5) < 0XCED ? 1 : 0;
    // 0x80801A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801A64: bne         $at, $zero, L_80801A90
    if (ctx->r1 != 0) {
        // 0x80801A68: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80801A90;
    }
    // 0x80801A68: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801A6C: addiu       $t6, $a1, -0xFA2
    ctx->r14 = ADD32(ctx->r5, -0XFA2);
    // 0x80801A70: sltiu       $at, $t6, 0x15
    ctx->r1 = ctx->r14 < 0X15 ? 1 : 0;
    // 0x80801A74: beq         $at, $zero, L_80801B84
    if (ctx->r1 == 0) {
        // 0x80801A78: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801B84;
    }
    // 0x80801A78: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801A7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24EC) << 16);
    // 0x80801A80: addu        $at, $at, $t6
    gpr jr_addend_80801A88 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801A84: lw          $t6, 0x24EC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24EC));
    // 0x80801A88: jr          $t6
    // 0x80801A8C: nop

    switch (jr_addend_80801A88 >> 2) {
        case 0: goto L_80801AE8; break;
        case 1: goto L_80801AAC; break;
        case 2: goto L_80801B84; break;
        case 3: goto L_80801B84; break;
        case 4: goto L_80801B84; break;
        case 5: goto L_80801B84; break;
        case 6: goto L_80801B84; break;
        case 7: goto L_80801B84; break;
        case 8: goto L_80801B84; break;
        case 9: goto L_80801B84; break;
        case 10: goto L_80801B84; break;
        case 11: goto L_80801B84; break;
        case 12: goto L_80801B84; break;
        case 13: goto L_80801B84; break;
        case 14: goto L_80801B84; break;
        case 15: goto L_80801B84; break;
        case 16: goto L_80801B84; break;
        case 17: goto L_80801AFC; break;
        case 18: goto L_80801B38; break;
        case 19: goto L_80801B38; break;
        case 20: goto L_80801B38; break;
        default: switch_error(__func__, 0x80801A88, 0x808024EC);
    }
    // 0x80801A8C: nop

L_80801A90:
    // 0x80801A90: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801A94: beq         $a1, $at, L_80801B4C
    if (ctx->r5 == ctx->r1) {
        // 0x80801A98: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_80801B4C;
    }
    // 0x80801A98: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80801A9C: beq         $a1, $at, L_80801B10
    if (ctx->r5 == ctx->r1) {
        // 0x80801AA0: nop
    
            goto L_80801B10;
    }
    // 0x80801AA0: nop

    // 0x80801AA4: b           L_80801B88
    // 0x80801AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801AAC:
    // 0x80801AAC: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80801AB0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801AB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801AB8: jal         0x80800078
    // 0x80801ABC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80800078_chtntmineshoot(rdram, ctx);
        goto after_0;
    // 0x80801ABC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801AC0: jal         0x80800150
    // 0x80801AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800150_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x80801AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801AC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801ACC: jal         0x800A7AD4
    // 0x80801AD0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800A7AD4(rdram, ctx);
        goto after_2;
    // 0x80801AD0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80801AD4: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    // 0x80801AD8: jal         0x80087A58
    // 0x80801ADC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801ADC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80801AE0: b           L_80801B88
    // 0x80801AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801AE8:
    // 0x80801AE8: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    // 0x80801AEC: jal         0x800887D8
    // 0x80801AF0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80801AF0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_4:
    // 0x80801AF4: b           L_80801B88
    // 0x80801AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801AFC:
    // 0x80801AFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801B00: jal         0x80801974
    // 0x80801B04: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_5;
    // 0x80801B04: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    after_5:
    // 0x80801B08: b           L_80801B88
    // 0x80801B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B10:
    // 0x80801B10: jal         0x800F54E4
    // 0x80801B14: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80801B14: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_6:
    // 0x80801B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B1C: jal         0x800F7F98
    // 0x80801B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_7;
    // 0x80801B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801B28: jal         0x80800E64
    // 0x80801B2C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80801B2C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_8:
    // 0x80801B30: b           L_80801B88
    // 0x80801B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B38:
    // 0x80801B38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801B3C: jal         0x80800E64
    // 0x80801B40: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_9;
    // 0x80801B40: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_9:
    // 0x80801B44: b           L_80801B88
    // 0x80801B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B4C:
    // 0x80801B4C: jal         0x800F54E4
    // 0x80801B50: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80801B50: nop

    after_10:
    // 0x80801B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B58: jal         0x800F7F98
    // 0x80801B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_11;
    // 0x80801B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801B60: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80801B64: blez        $t7, L_80801B7C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80801B68: nop
    
            goto L_80801B7C;
    }
    // 0x80801B68: nop

    // 0x80801B6C: jal         0x80088188
    // 0x80801B70: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80801B70: nop

    after_12:
    // 0x80801B74: b           L_80801B88
    // 0x80801B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B88;
    // 0x80801B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B7C:
    // 0x80801B7C: jal         0x80088180
    // 0x80801B80: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80801B80: nop

    after_13:
L_80801B84:
    // 0x80801B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B88:
    // 0x80801B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B8C: jr          $ra
    // 0x80801B90: nop

    return;
    // 0x80801B90: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080063C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800648: jal         0x8008CABC
    // 0x8080064C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080064C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800650: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800654: jal         0x808000C8
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_1;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800664: jal         0x8009D2F0
    // 0x80800668: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_2;
    // 0x80800668: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x8080066C: lui         $a1, 0x3EF0
    ctx->r5 = S32(0X3EF0 << 16);
    // 0x80800670: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: jal         0x800A2CE8
    // 0x8080067C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x8080067C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80800680: lui         $a1, 0x3F78
    ctx->r5 = S32(0X3F78 << 16);
    // 0x80800684: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x800A2CE8
    // 0x80800690: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x80800690: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800694: lui         $a1, 0x3F47
    ctx->r5 = S32(0X3F47 << 16);
    // 0x80800698: ori         $a1, $a1, 0x3190
    ctx->r5 = ctx->r5 | 0X3190;
    // 0x8080069C: jal         0x8008B348
    // 0x808006A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808006A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808006A4: beq         $v0, $zero, L_808006B4
    if (ctx->r2 == 0) {
        // 0x808006A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B4;
    }
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x80800020
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800020_bskazstilt(rdram, ctx);
        goto after_6;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_808006B4:
    // 0x808006B4: lui         $a1, 0x3E8E
    ctx->r5 = S32(0X3E8E << 16);
    // 0x808006B8: ori         $a1, $a1, 0x6320
    ctx->r5 = ctx->r5 | 0X6320;
    // 0x808006BC: jal         0x8008B348
    // 0x808006C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808006C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808006C4: beq         $v0, $zero, L_808006D4
    if (ctx->r2 == 0) {
        // 0x808006C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D4;
    }
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: jal         0x80800020
    // 0x808006D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800020_bskazstilt(rdram, ctx);
        goto after_8;
    // 0x808006D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_808006D4:
    // 0x808006D4: jal         0x80800064
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800064_bskazstilt(rdram, ctx);
        goto after_9;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: jal         0x80091A58
    // 0x808006E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x808006E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x808006E8: beq         $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x808006EC: nop
    
            goto L_80800718;
    }
    // 0x808006EC: nop

    // 0x808006F0: jal         0x8009BB00
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808006F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800704: nop

    // 0x80800708: bc1f        L_80800718
    if (!c1cs) {
        // 0x8080070C: nop
    
            goto L_80800718;
    }
    // 0x8080070C: nop

    // 0x80800710: jal         0x80091788
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_clear(rdram, ctx);
        goto after_12;
    // 0x80800714: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
L_80800718:
    // 0x80800718: jal         0x8009EF10
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_13;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800720: bne         $v0, $zero, L_8080073C
    if (ctx->r2 != 0) {
        // 0x80800724: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080073C;
    }
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: jal         0x8009BCD4
    // 0x8080072C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_14;
    // 0x8080072C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_14:
    // 0x80800730: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800734: addiu       $t6, $zero, 0x48
        ctx->r14 = ADD32(0, 0X48);
            goto L_8080073C;
    }
    // 0x80800734: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x80800738: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080073C:
    // 0x8080073C: jal         0x8008DF18
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_15;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800744: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x80800748: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800754;
    }
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: addiu       $t7, $zero, 0x4D
    ctx->r15 = ADD32(0, 0X4D);
    // 0x80800750: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800754:
    // 0x80800754: jal         0x80091A58
    // 0x80800758: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x80800758: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x8080075C: beql        $v0, $zero, L_8080077C
    if (ctx->r2 == 0) {
        // 0x80800760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080077C;
    }
    goto skip_0;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800764: jal         0x8008E078
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_17;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080076C: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x80800770: addiu       $t8, $zero, 0x4A
        ctx->r24 = ADD32(0, 0X4A);
            goto L_80800778;
    }
    // 0x80800770: addiu       $t8, $zero, 0x4A
    ctx->r24 = ADD32(0, 0X4A);
    // 0x80800774: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800778:
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080077C:
    // 0x8080077C: jal         0x800915AC
    // 0x80800780: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_18;
    // 0x80800780: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800784: beq         $v0, $zero, L_80800790
    if (ctx->r2 == 0) {
        // 0x80800788: addiu       $t9, $zero, 0x4B
        ctx->r25 = ADD32(0, 0X4B);
            goto L_80800790;
    }
    // 0x80800788: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x8080078C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800790:
    // 0x80800790: jal         0x80800000
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazstilt(rdram, ctx);
        goto after_19;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800798: beq         $v0, $zero, L_808007A8
    if (ctx->r2 == 0) {
        // 0x8080079C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007A8;
    }
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: addiu       $t0, $zero, 0x160
    ctx->r8 = ADD32(0, 0X160);
    // 0x808007A4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808007A8:
    // 0x808007A8: jal         0x8009E5C8
    // 0x808007AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x808007AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x808007B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_80800320_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080032C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800330: jal         0x8008CABC
    // 0x80800334: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800334: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800338: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x8080033C: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
    // 0x80800340: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800344: bne         $t6, $zero, L_80800394
    if (ctx->r14 != 0) {
        // 0x80800348: ori         $a1, $a1, 0xAE14
        ctx->r5 = ctx->r5 | 0XAE14;
            goto L_80800394;
    }
    // 0x80800348: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    // 0x8080034C: jal         0x8008B348
    // 0x80800350: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800350: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800354: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x80800358: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003C0;
    }
    // 0x80800358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080035C: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x80800360: jal         0x8008B1BC
    // 0x80800364: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x80800364: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_2:
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x8009BA58
    // 0x80800370: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x80800370: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    after_3:
    // 0x80800374: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800378: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x8009DE38
    // 0x80800384: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    func_8009DE38(rdram, ctx);
        goto after_4;
    // 0x80800384: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    after_4:
    // 0x80800388: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080038C: b           L_808003C0
    // 0x80800390: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
        goto L_808003C0;
    // 0x80800390: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
L_80800394:
    // 0x80800394: jal         0x80800000
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazfly(rdram, ctx);
        goto after_5;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080039C: jal         0x8009BB50
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003A8: addiu       $t8, $zero, 0x162
    ctx->r24 = ADD32(0, 0X162);
    // 0x808003AC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003B0: nop

    // 0x808003B4: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    goto skip_0;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003BC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808003C0:
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003C4:
    // 0x808003C4: jal         0x8009E5C8
    // 0x808003C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808003C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808003CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void func_800DF35C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF35C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF364: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF368: jal         0x800ADF5C
    // 0x800DF36C: lw          $a0, -0x37C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37C0);
    func_800ADF5C(rdram, ctx);
        goto after_0;
    // 0x800DF36C: lw          $a0, -0x37C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37C0);
    after_0:
    // 0x800DF370: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF374: jal         0x8010E390
    // 0x800DF378: sw          $zero, -0x37C0($at)
    MEM_W(-0X37C0, ctx->r1) = 0;
    func_8010E390(rdram, ctx);
        goto after_1;
    // 0x800DF378: sw          $zero, -0x37C0($at)
    MEM_W(-0X37C0, ctx->r1) = 0;
    after_1:
    // 0x800DF37C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF384: jr          $ra
    // 0x800DF388: nop

    return;
    // 0x800DF388: nop

;}
RECOMP_FUNC void func_800DF72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF72C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF730: jr          $ra
    // 0x800DF734: sw          $a0, -0x3698($at)
    MEM_W(-0X3698, ctx->r1) = ctx->r4;
    return;
    // 0x800DF734: sw          $a0, -0x3698($at)
    MEM_W(-0X3698, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void bamovegoto_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8080014C: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x80800150: jal         0x800EEAD4
    // 0x80800154: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    func_800EEAD4(rdram, ctx);
        goto after_0;
    // 0x80800154: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    after_0:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1680) << 16);
    // 0x808010D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808010D4: jr          $ra
    // 0x808010D8: lw          $v0, 0x1680($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1680));
    return;
    // 0x808010D8: lw          $v0, 0x1680($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1680));
;}
RECOMP_FUNC void func_800D39DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D39E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D39E4: bltz        $a0, L_800D3A04
    if (SIGNED(ctx->r4) < 0) {
        // 0x800D39E8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800D3A04;
    }
    // 0x800D39E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D39EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D39F0: addiu       $a1, $a1, 0x39D0
    ctx->r5 = ADD32(ctx->r5, 0X39D0);
    // 0x800D39F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D39F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D39FC: jal         0x800D3B6C
    // 0x800D3A00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D3B6C(rdram, ctx);
        goto after_0;
    // 0x800D3A00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
L_800D3A04:
    // 0x800D3A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3A08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3A0C: jr          $ra
    // 0x800D3A10: nop

    return;
    // 0x800D3A10: nop

;}
RECOMP_FUNC void baflag_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095774: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x80095778: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8009577C: jr          $ra
    // 0x80095780: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    return;
    // 0x80095780: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
;}
RECOMP_FUNC void chsparkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2100, 0X164) << 16);
    // 0x80800118: jr          $ra
    // 0x8080011C: addiu       $v0, $v0, 0x164
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2100, 0X164));
    return;
    // 0x8080011C: addiu       $v0, $v0, 0x164
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2100, 0X164));
;}
RECOMP_FUNC void _dbskeleton_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A08: syscall     649
    recomp_syscall_handler(rdram, ctx, 0x80087A08);
    return;
    // 0x80087A0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808007BC_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007CC: jal         0x80100094
    // 0x808007D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808007D8: jal         0x808006A4
    // 0x808007DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808006A4_chclinker(rdram, ctx);
        goto after_1;
    // 0x808007DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808007E0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808007E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007E8: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x808007EC: lhu         $v0, 0x72($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X72);
    // 0x808007F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007F4: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808007F8: beq         $t7, $at, L_80800824
    if (ctx->r15 == ctx->r1) {
        // 0x808007FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800824;
    }
    // 0x808007FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800800: beq         $t7, $at, L_8080084C
    if (ctx->r15 == ctx->r1) {
        // 0x80800804: addiu       $a0, $zero, 0x103
        ctx->r4 = ADD32(0, 0X103);
            goto L_8080084C;
    }
    // 0x80800804: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x80800808: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080080C: beq         $t7, $at, L_80800860
    if (ctx->r15 == ctx->r1) {
        // 0x80800810: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800860;
    }
    // 0x80800810: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800814: beql        $t7, $at, L_808008B0
    if (ctx->r15 == ctx->r1) {
        // 0x80800818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008B0;
    }
    goto skip_0;
    // 0x80800818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080081C: b           L_808008B0
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008B0;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800824:
    // 0x80800824: jal         0x800D24E8
    // 0x80800828: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800D24E8(rdram, ctx);
        goto after_2;
    // 0x80800828: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8080082C: jal         0x800CEAD0
    // 0x80800830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_3;
    // 0x80800830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800834: beq         $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x80800838: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808008AC;
    }
    // 0x80800838: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080083C: jal         0x808008E0
    // 0x80800840: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808008E0_chclinker(rdram, ctx);
        goto after_4;
    // 0x80800840: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800844: b           L_808008B0
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008B0;
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080084C:
    // 0x8080084C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800850: jal         0x800D24E8
    // 0x80800854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_5;
    // 0x80800854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800858: b           L_808008B0
    // 0x8080085C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008B0;
    // 0x8080085C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800860:
    // 0x80800860: jal         0x800D8FF8
    // 0x80800864: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800864: nop

    after_6:
    // 0x80800868: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080086C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X12FC) << 16);
    // 0x80800870: lwc1        $f14, 0x12FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2208, 0X12FC));
    // 0x80800874: jal         0x800F13F0
    // 0x80800878: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800F13F0(rdram, ctx);
        goto after_7;
    // 0x80800878: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_7:
    // 0x8080087C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80800880: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x80800884: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800888: jal         0x800D24E8
    // 0x8080088C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_8;
    // 0x8080088C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80800890: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800894: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x80800898: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080089C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808008A0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808008A4: jal         0x800D2498
    // 0x808008A8: nop

    func_800D2498(rdram, ctx);
        goto after_9;
    // 0x808008A8: nop

    after_9:
L_808008AC:
    // 0x808008AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008B0:
    // 0x808008B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008B8: jr          $ra
    // 0x808008BC: nop

    return;
    // 0x808008BC: nop

;}
RECOMP_FUNC void _glrecord_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886B8: syscall     698
    recomp_syscall_handler(rdram, ctx, 0x800886B8);
    return;
    // 0x800886BC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80105AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105AF0: jal         0x80105494
    // 0x80105AF4: nop

    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105AF4: nop

    after_0:
    // 0x80105AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105AFC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80105B00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105B04: jr          $ra
    // 0x80105B08: nop

    return;
    // 0x80105B08: nop

;}
RECOMP_FUNC void func_800D9078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D907C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9080: jal         0x800D8FF8
    // 0x800D9084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D9084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D9088: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D908C: jal         0x800F1574
    // 0x800D9090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x800D9090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D9094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D909C: jr          $ra
    // 0x800D90A0: nop

    return;
    // 0x800D90A0: nop

;}
RECOMP_FUNC void func_80800044_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800050: jal         0x800DA298
    // 0x80800054: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800054: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_0:
    // 0x80800058: bne         $v0, $zero, L_808000A8
    if (ctx->r2 != 0) {
        // 0x8080005C: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_808000A8;
    }
    // 0x8080005C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800060: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80800064: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800068: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080006C: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80800070: jal         0x8008A1B8
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800078: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x8080007C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_808000A8;
    }
    // 0x8080007C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800080: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800084: addiu       $a1, $zero, 0xD82
    ctx->r5 = ADD32(0, 0XD82);
    // 0x80800088: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080008C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800090: jal         0x8008A208
    // 0x80800094: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800094: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80800098: beql        $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000A0: jal         0x800DA544
    // 0x808000A4: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808000A4: addiu       $a0, $zero, 0x4F4
    ctx->r4 = ADD32(0, 0X4F4);
    after_3:
L_808000A8:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DD8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(128, 0XFE8) << 16);
    // 0x80800DDC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DE0: jr          $ra
    // 0x80800DE4: lw          $v0, 0xFE8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFE8));
    return;
    // 0x80800DE4: lw          $v0, 0xFE8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFE8));
;}
RECOMP_FUNC void chfactoryliftdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1132, 0X188) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x188
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1132, 0X188));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x188
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1132, 0X188));
;}
RECOMP_FUNC void func_8080102C_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801038: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x8080103C: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80801040: bgezl       $t9, L_8080107C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080107C;
    }
    goto skip_0;
    // 0x80801044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801048: jal         0x800FECB8
    // 0x8080104C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800FECB8(rdram, ctx);
        goto after_0;
    // 0x8080104C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80801050: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x80801054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801058: jal         0x800FCAE0
    // 0x8080105C: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    func_800FCAE0(rdram, ctx);
        goto after_1;
    // 0x8080105C: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    after_1:
    // 0x80801060: jal         0x800FCA90
    // 0x80801064: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800FCA90(rdram, ctx);
        goto after_2;
    // 0x80801064: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_2:
    // 0x80801068: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080106C: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    // 0x80801070: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80801074: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    // 0x80801078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080107C:
    // 0x8080107C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801080: jr          $ra
    // 0x80801084: nop

    return;
    // 0x80801084: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089558: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089558);
    return;
    // 0x8008955C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void gczoombox_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035E8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808035EC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x808035F0: beq         $a0, $zero, L_8080365C
    if (ctx->r4 == 0) {
        // 0x808035F4: nop
    
            goto L_8080365C;
    }
    // 0x808035F4: nop

    // 0x808035F8: lbu         $t6, 0x1E4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1E4);
    // 0x808035FC: addiu       $t8, $zero, 0x130
    ctx->r24 = ADD32(0, 0X130);
    // 0x80803600: subu        $t9, $t8, $a1
    ctx->r25 = SUB32(ctx->r24, ctx->r5);
    // 0x80803604: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80803608: beq         $t7, $zero, L_80803624
    if (ctx->r15 == 0) {
        // 0x8080360C: addiu       $t2, $a1, -0x8C
        ctx->r10 = ADD32(ctx->r5, -0X8C);
            goto L_80803624;
    }
    // 0x8080360C: addiu       $t2, $a1, -0x8C
    ctx->r10 = ADD32(ctx->r5, -0X8C);
    // 0x80803610: addiu       $t0, $zero, 0x1BC
    ctx->r8 = ADD32(0, 0X1BC);
    // 0x80803614: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80803618: sh          $t9, 0x1B2($a0)
    MEM_H(0X1B2, ctx->r4) = ctx->r25;
    // 0x8080361C: b           L_8080362C
    // 0x80803620: sh          $t1, 0x1AE($a0)
    MEM_H(0X1AE, ctx->r4) = ctx->r9;
        goto L_8080362C;
    // 0x80803620: sh          $t1, 0x1AE($a0)
    MEM_H(0X1AE, ctx->r4) = ctx->r9;
L_80803624:
    // 0x80803624: sh          $a1, 0x1B2($a0)
    MEM_H(0X1B2, ctx->r4) = ctx->r5;
    // 0x80803628: sh          $t2, 0x1AE($a0)
    MEM_H(0X1AE, ctx->r4) = ctx->r10;
L_8080362C:
    // 0x8080362C: swc1        $f12, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->f12.u32l;
    // 0x80803630: swc1        $f14, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f14.u32l;
    // 0x80803634: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80803638: beql        $t3, $zero, L_80803654
    if (ctx->r11 == 0) {
        // 0x8080363C: lbu         $t7, 0x1E6($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1E6);
            goto L_80803654;
    }
    goto skip_0;
    // 0x8080363C: lbu         $t7, 0x1E6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E6);
    skip_0:
    // 0x80803640: lbu         $t5, 0x1E6($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X1E6);
    // 0x80803644: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80803648: jr          $ra
    // 0x8080364C: sb          $t6, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r14;
    return;
    // 0x8080364C: sb          $t6, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r14;
    // 0x80803650: lbu         $t7, 0x1E6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E6);
L_80803654:
    // 0x80803654: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80803658: sb          $t8, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r24;
L_8080365C:
    // 0x8080365C: jr          $ra
    // 0x80803660: nop

    return;
    // 0x80803660: nop

;}
RECOMP_FUNC void func_800E9774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E977C: jal         0x800EA398
    // 0x800E9780: nop

    func_800EA398(rdram, ctx);
        goto after_0;
    // 0x800E9780: nop

    after_0:
    // 0x800E9784: jal         0x800EB750
    // 0x800E9788: nop

    func_800EB750(rdram, ctx);
        goto after_1;
    // 0x800E9788: nop

    after_1:
    // 0x800E978C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9790: jal         0x800B42DC
    // 0x800E9794: lw          $a0, 0x2DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB0);
    func_800B42DC(rdram, ctx);
        goto after_2;
    // 0x800E9794: lw          $a0, 0x2DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB0);
    after_2:
    // 0x800E9798: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E979C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E97A0: sw          $zero, 0x2DB0($at)
    MEM_W(0X2DB0, ctx->r1) = 0;
    // 0x800E97A4: jal         0x800B42DC
    // 0x800E97A8: lw          $a0, 0x2DB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB4);
    func_800B42DC(rdram, ctx);
        goto after_3;
    // 0x800E97A8: lw          $a0, 0x2DB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB4);
    after_3:
    // 0x800E97AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E97B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E97B4: sw          $zero, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = 0;
    // 0x800E97B8: jr          $ra
    // 0x800E97BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E97BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800AE0_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800AE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AE8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AEC: jal         0x80800238
    // 0x80800AF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800238_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800AF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800AF4: jal         0x80800AA0
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_bsledge(rdram, ctx);
        goto after_1;
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800B04: jal         0x8008CB3C
    // 0x80800B08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800B08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80800B0C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80800B10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800B20: jal         0x8009FFD8
    // 0x80800B24: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x80800B24: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80800B28: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800B2C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B34: jal         0x8008C9BC
    // 0x80800B38: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x80800B38: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_4:
    // 0x80800B3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(304, 0X131C) << 16);
    // 0x80800B40: lwc1        $f4, 0x131C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(304, 0X131C));
    // 0x80800B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B48: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80800B4C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800B50: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80800B54: jal         0x8008C9F0
    // 0x80800B58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x80800B58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B60: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B68: jr          $ra
    // 0x80800B6C: nop

    return;
    // 0x80800B6C: nop

;}
RECOMP_FUNC void func_800A5D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5D6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5D70: lw          $a0, 0x7110($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7110);
    // 0x800A5D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5D7C: beql        $a0, $zero, L_800A5D98
    if (ctx->r4 == 0) {
        // 0x800A5D80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A5D98;
    }
    goto skip_0;
    // 0x800A5D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A5D84: jal         0x8001BAFC
    // 0x800A5D88: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800A5D88: nop

    after_0:
    // 0x800A5D8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5D90: sw          $v0, 0x7110($at)
    MEM_W(0X7110, ctx->r1) = ctx->r2;
    // 0x800A5D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A5D98:
    // 0x800A5D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5D9C: jr          $ra
    // 0x800A5DA0: nop

    return;
    // 0x800A5DA0: nop

    // 0x800A5DA4: nop

    // 0x800A5DA8: nop

    // 0x800A5DAC: nop

;}
RECOMP_FUNC void func_800CF6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF6B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF6B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF6B8: jal         0x800CEA84
    // 0x800CF6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEA84(rdram, ctx);
        goto after_0;
    // 0x800CF6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF6C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF6C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF6C8: jr          $ra
    // 0x800CF6CC: nop

    return;
    // 0x800CF6CC: nop

;}
RECOMP_FUNC void func_80808470_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808470: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80808474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808478: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080847C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80808480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808484: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80808488: jal         0x80100094
    // 0x8080848C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080848C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808490: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80808494: jal         0x80802248
    // 0x80808498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80808498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080849C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808084A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808084A4: sb          $t6, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r14;
    // 0x808084A8: sb          $zero, 0xD8($s1)
    MEM_B(0XD8, ctx->r17) = 0;
    // 0x808084AC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808084B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808084B4: jal         0x80803BE8
    // 0x808084B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808084B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x808084BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808084C0: jal         0x800F5A00
    // 0x808084C4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808084C4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x808084C8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808084CC: jal         0x800F1DF4
    // 0x808084D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_4;
    // 0x808084D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808084D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808084D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808084DC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808084E0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808084E4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808084E8: jal         0x800EFA4C
    // 0x808084EC: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x808084EC: nop

    after_5:
    // 0x808084F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808084F4: jal         0x800F8444
    // 0x808084F8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F8444(rdram, ctx);
        goto after_6;
    // 0x808084F8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808084FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808500: jal         0x808021E8
    // 0x80808504: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808021E8_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80808504: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_7:
    // 0x80808508: bne         $v0, $zero, L_8080853C
    if (ctx->r2 != 0) {
        // 0x8080850C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080853C;
    }
    // 0x8080850C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808514: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80808518: jal         0x80802878
    // 0x8080851C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x8080851C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80808520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808524: addiu       $a1, $zero, 0x172D
    ctx->r5 = ADD32(0, 0X172D);
    // 0x80808528: jal         0x80803660
    // 0x8080852C: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x8080852C: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    after_9:
    // 0x80808530: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80808534: b           L_8080854C
    // 0x80808538: sb          $t7, 0xCC($s1)
    MEM_B(0XCC, ctx->r17) = ctx->r15;
        goto L_8080854C;
    // 0x80808538: sb          $t7, 0xCC($s1)
    MEM_B(0XCC, ctx->r17) = ctx->r15;
L_8080853C:
    // 0x8080853C: jal         0x80109FE8
    // 0x80808540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_10;
    // 0x80808540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80808544: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80808548: sb          $t8, 0xCC($s1)
    MEM_B(0XCC, ctx->r17) = ctx->r24;
L_8080854C:
    // 0x8080854C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808550: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80808554: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80808558: jr          $ra
    // 0x8080855C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080855C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _chbaddieDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085938: syscall     181
    recomp_syscall_handler(rdram, ctx, 0x80085938);
    return;
    // 0x8008593C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801A9C_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801AA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801AA8: beq         $a1, $zero, L_80801AC4
    if (ctx->r5 == 0) {
        // 0x80801AAC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801AC4;
    }
    // 0x80801AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AB0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2284, 0X298C) << 16);
    // 0x80801AB4: addiu       $a1, $a1, 0x298C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2284, 0X298C));
    // 0x80801AB8: jal         0x800EE7F8
    // 0x80801ABC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801ABC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801AC0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80801AC4:
    // 0x80801AC4: beq         $a2, $zero, L_80801AD8
    if (ctx->r6 == 0) {
        // 0x80801AC8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80801AD8;
    }
    // 0x80801AC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801ACC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2284, 0X2998) << 16);
    // 0x80801AD0: jal         0x800EE7F8
    // 0x80801AD4: addiu       $a1, $a1, 0x2998
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2284, 0X2998));
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801AD4: addiu       $a1, $a1, 0x2998
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2284, 0X2998));
    after_1:
L_80801AD8:
    // 0x80801AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AE0: jr          $ra
    // 0x80801AE4: nop

    return;
    // 0x80801AE4: nop

;}
RECOMP_FUNC void func_80801370_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801370: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80801374: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80801378: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080137C: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x80801380: bne         $a2, $zero, L_8080138C
    if (ctx->r6 != 0) {
        // 0x80801384: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8080138C;
    }
    // 0x80801384: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801388: addiu       $a2, $a1, -0x1C
    ctx->r6 = ADD32(ctx->r5, -0X1C);
L_8080138C:
    // 0x8080138C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x80801390: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80801394: beq         $at, $zero, L_808013C8
    if (ctx->r1 == 0) {
        // 0x80801398: lw          $v1, 0x10($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X10);
            goto L_808013C8;
    }
    // 0x80801398: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8080139C: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
L_808013A0:
    // 0x808013A0: beq         $a3, $t7, L_808013B0
    if (ctx->r7 == ctx->r15) {
        // 0x808013A4: nop
    
            goto L_808013B0;
    }
    // 0x808013A4: nop

    // 0x808013A8: beql        $v1, $zero, L_808013BC
    if (ctx->r3 == 0) {
        // 0x808013AC: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_808013BC;
    }
    goto skip_0;
    // 0x808013AC: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    skip_0:
L_808013B0:
    // 0x808013B0: jr          $ra
    // 0x808013B4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x808013B4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x808013B8: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
L_808013BC:
    // 0x808013BC: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x808013C0: bnel        $at, $zero, L_808013A0
    if (ctx->r1 != 0) {
        // 0x808013C4: lw          $t7, 0x14($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X14);
            goto L_808013A0;
    }
    goto skip_1;
    // 0x808013C4: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    skip_1:
L_808013C8:
    // 0x808013C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808013CC: jr          $ra
    // 0x808013D0: nop

    return;
    // 0x808013D0: nop

;}
RECOMP_FUNC void suflamefx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808001E0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808001E4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808001E8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001EC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808001F0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808001F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808001F8: addiu       $s0, $a0, 0x20
    ctx->r16 = ADD32(ctx->r4, 0X20);
    // 0x808001FC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800200: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800204: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800208: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x8080020C: jal         0x800E3E8C
    // 0x80800210: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x80800210: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_0:
    // 0x80800214: beql        $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x80800218: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808002BC;
    }
    goto skip_0;
    // 0x80800218: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8080021C: jal         0x800D674C
    // 0x80800220: lh          $a0, 0x18($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X18);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800220: lh          $a0, 0x18($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X18);
    after_1:
    // 0x80800224: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800228: jal         0x800E2588
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_2;
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800230: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800234: jal         0x800E2594
    // 0x80800238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2594(rdram, ctx);
        goto after_3;
    // 0x80800238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8080023C: lbu         $v1, 0x1B($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1B);
    // 0x80800240: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3150, 0X524) << 16);
    // 0x80800248: blez        $v1, L_808002B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8080024C: addiu       $s2, $sp, 0x54
        ctx->r18 = ADD32(ctx->r29, 0X54);
            goto L_808002B0;
    }
    // 0x8080024C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x80800250: lwc1        $f20, 0x524($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3150, 0X524));
L_80800254:
    // 0x80800254: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800258: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1fl       L_808002A4
    if (!c1cs) {
        // 0x80800264: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808002A4;
    }
    goto skip_1;
    // 0x80800264: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800268: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080026C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800270: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800274: jal         0x800EFA4C
    // 0x80800278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8080027C: lbu         $a1, 0x2C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2C);
    // 0x80800280: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80800284: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800288: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8080028C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800290: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800294: jal         0x800E2720
    // 0x80800298: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    func_800E2720(rdram, ctx);
        goto after_5;
    // 0x80800298: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x8080029C: lbu         $v1, 0x1B($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X1B);
    // 0x808002A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808002A4:
    // 0x808002A4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808002A8: bne         $at, $zero, L_80800254
    if (ctx->r1 != 0) {
        // 0x808002AC: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_80800254;
    }
    // 0x808002AC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
L_808002B0:
    // 0x808002B0: jal         0x800E2A14
    // 0x808002B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E2A14(rdram, ctx);
        goto after_6;
    // 0x808002B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x808002B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808002BC:
    // 0x808002BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808002C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808002CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808002D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808002D4: jr          $ra
    // 0x808002D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808002D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void suexpressjoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808000B4: jal         0x80800000
    // 0x808000B8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_80800000_suexpressjoint(rdram, ctx);
        goto after_0;
    // 0x808000B8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808000BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000C0: bne         $v0, $at, L_808000D0
    if (ctx->r2 != ctx->r1) {
        // 0x808000C4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000D0;
    }
    // 0x808000C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C8: b           L_808000E4
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E4;
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D0:
    // 0x808000D0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x808000D4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(3134, 0X1824) << 16);
    // 0x808000D8: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x808000DC: lbu         $v1, 0x1824($v1)
    ctx->r3 = MEM_BU(ctx->r3, (int16_t)RELOC_LO16(3134, 0X1824));
    // 0x808000E0: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
L_808000E4:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800124: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800130: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_80800134:
    // 0x80800134: jal         0x8080008C
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gccollectDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080013C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800140: bne         $s0, $s1, L_80800134
    if (ctx->r16 != ctx->r17) {
        // 0x80800144: nop
    
            goto L_80800134;
    }
    // 0x80800144: nop

    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080014C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

RECOMP_FUNC void func_8002DC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002DC7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DC80: jal         0x80032AD8
    // 0x8002DC84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8002DC84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002DC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DC8C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002DC90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002DC94: jr          $ra
    // 0x8002DC98: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x8002DC98: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8002DC9C: nop

;}
