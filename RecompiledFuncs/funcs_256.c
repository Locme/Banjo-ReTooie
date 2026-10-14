#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800E3980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3984: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E398C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3990: jal         0x800CA7E4
    // 0x800E3994: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA7E4(rdram, ctx);
        goto after_0;
    // 0x800E3994: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E399C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E39A0: jr          $ra
    // 0x800E39A4: nop

    return;
    // 0x800E39A4: nop

;}
RECOMP_FUNC void func_80800B30_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B3C: jal         0x800DA524
    // 0x80800B40: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800B40: addiu       $a0, $zero, 0x9F4
    ctx->r4 = ADD32(0, 0X9F4);
    after_0:
    // 0x80800B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B4C: jr          $ra
    // 0x80800B50: nop

    return;
    // 0x80800B50: nop

;}
RECOMP_FUNC void func_80807030_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80807034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80807038: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080703C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80807040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807044: jal         0x80100094
    // 0x80807048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080704C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80807050: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80807054: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80807058: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_8080705C:
    // 0x8080705C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80807060: beql        $a0, $zero, L_80807074
    if (ctx->r4 == 0) {
        // 0x80807064: lw          $a0, 0x10($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X10);
            goto L_80807074;
    }
    goto skip_0;
    // 0x80807064: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x80807068: jal         0x80087AE0
    // 0x8080706C: nop

    _gczoombox_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080706C: nop

    after_1:
    // 0x80807070: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
L_80807074:
    // 0x80807074: beql        $a0, $zero, L_80807088
    if (ctx->r4 == 0) {
        // 0x80807078: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80807088;
    }
    goto skip_1;
    // 0x80807078: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_1:
    // 0x8080707C: jal         0x8001B084
    // 0x80807080: nop

    heap_free(rdram, ctx);
        goto after_2;
    // 0x80807080: nop

    after_2:
    // 0x80807084: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80807088:
    // 0x80807088: bne         $s1, $s2, L_8080705C
    if (ctx->r17 != ctx->r18) {
        // 0x8080708C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080705C;
    }
    // 0x8080708C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80807090: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80807094: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    // 0x80807098: beql        $a0, $zero, L_808070AC
    if (ctx->r4 == 0) {
        // 0x8080709C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808070AC;
    }
    goto skip_2;
    // 0x8080709C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808070A0: jal         0x8001B084
    // 0x808070A4: nop

    heap_free(rdram, ctx);
        goto after_3;
    // 0x808070A4: nop

    after_3:
    // 0x808070A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808070AC:
    // 0x808070AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808070B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808070B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808070B8: jr          $ra
    // 0x808070BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808070BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void chpickups_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(700, 0X7D8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x7D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X7D8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x7D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X7D8));
;}
RECOMP_FUNC void suquiz_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800624: jal         0x800DA298
    // 0x80800628: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800628: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x8080062C: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x80800630: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800644;
    }
    // 0x80800630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800634: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800638: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x8080063C: b           L_80800648
    // 0x80800640: lb          $v0, 0x28($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X28);
        goto L_80800648;
    // 0x80800640: lb          $v0, 0x28($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X28);
L_80800644:
    // 0x80800644: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800648:
    // 0x80800648: jr          $ra
    // 0x8080064C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080064C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsbswim_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BB8: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082BB8);
    return;
    // 0x80082BBC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void chkingjinjo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1296, 0X11F0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x11F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1296, 0X11F0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x11F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1296, 0X11F0));
;}
RECOMP_FUNC void bskazmove_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BB0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800BB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(260, 0XC80) << 16);
    // 0x80800BB8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800BBC: jr          $ra
    // 0x80800BC0: lw          $v0, 0xC80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(260, 0XC80));
    return;
    // 0x80800BC0: lw          $v0, 0xC80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(260, 0XC80));
;}
RECOMP_FUNC void func_808003EC_chpodiumbankaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x808003F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F8: beq         $a1, $at, L_80800414
    if (ctx->r5 == ctx->r1) {
        // 0x808003FC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800414;
    }
    // 0x808003FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800400: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800404: beq         $a1, $at, L_80800428
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: addiu       $a0, $zero, 0xA84
        ctx->r4 = ADD32(0, 0XA84);
            goto L_80800428;
    }
    // 0x80800408: addiu       $a0, $zero, 0xA84
    ctx->r4 = ADD32(0, 0XA84);
    // 0x8080040C: b           L_80800454
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800454;
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800414:
    // 0x80800414: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800418: jal         0x808003C4
    // 0x8080041C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808003C4_chpodiumbankaz(rdram, ctx);
        goto after_0;
    // 0x8080041C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800420: b           L_80800454
    // 0x80800424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800454;
    // 0x80800424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800428:
    // 0x80800428: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080042C: jal         0x800DA298
    // 0x80800430: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800430: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800434: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800438: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x8080043C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8080044C;
    }
    // 0x8080043C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800444: jal         0x80800228
    // 0x80800448: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800228_chpodiumbankaz(rdram, ctx);
        goto after_2;
    // 0x80800448: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
L_8080044C:
    // 0x8080044C: b           L_80800454
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800454;
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800454:
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080045C: jr          $ra
    // 0x80800460: nop

    return;
    // 0x80800460: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A558: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A558);
    return;
    // 0x8008A55C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void chburgerstand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(936, 0XC28) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XC28));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XC28));
;}
RECOMP_FUNC void func_800BFFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFFB4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BFFB8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BFFBC: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800BFFC0: lw          $a3, -0x7890($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7890);
    // 0x800BFFC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFFC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFFCC: beq         $a3, $zero, L_800BFFE4
    if (ctx->r7 == 0) {
        // 0x800BFFD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BFFE4;
    }
    // 0x800BFFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFFD4: jal         0x800DBEFC
    // 0x800BFFD8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x800BFFD8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800BFFDC: b           L_800BFFE4
    // 0x800BFFE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800BFFE4;
    // 0x800BFFE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BFFE4:
    // 0x800BFFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFFEC: jr          $ra
    // 0x800BFFF0: nop

    return;
    // 0x800BFFF0: nop

;}
RECOMP_FUNC void chswampplatform_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080099C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2268, 0X9F8) << 16);
    // 0x808009A0: jr          $ra
    // 0x808009A4: addiu       $v0, $v0, 0x9F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2268, 0X9F8));
    return;
    // 0x808009A4: addiu       $v0, $v0, 0x9F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2268, 0X9F8));
    // 0x808009A8: nop

    // 0x808009AC: nop

;}
RECOMP_FUNC void func_80800790_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800798: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x8080079C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808007A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007A4: beql        $t6, $zero, L_808007C0
    if (ctx->r14 == 0) {
        // 0x808007A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007C0;
    }
    goto skip_0;
    // 0x808007A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007AC: jal         0x800856B8
    // 0x808007B0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808007B0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007B4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808007B8: sw          $zero, 0x28($a1)
    MEM_W(0X28, ctx->r5) = 0;
    // 0x808007BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C0:
    // 0x808007C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007C4: jr          $ra
    // 0x808007C8: nop

    return;
    // 0x808007C8: nop

;}
RECOMP_FUNC void func_80801538_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801538: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080153C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801540: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801544: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801548: jal         0x8008CABC
    // 0x8080154C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080154C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80801550: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801554: jal         0x80800030
    // 0x80801558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80801558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080155C: jal         0x800A046C
    // 0x80801560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A046C(rdram, ctx);
        goto after_2;
    // 0x80801560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801564: jal         0x800A3298
    // 0x80801568: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A3298(rdram, ctx);
        goto after_3;
    // 0x80801568: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8080156C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801570: jal         0x8009E710
    // 0x80801574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_4;
    // 0x80801574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80801578: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8080157C: bne         $v0, $at, L_80801594
    if (ctx->r2 != ctx->r1) {
        // 0x80801580: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_80801594;
    }
    // 0x80801580: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80801584: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801588: jal         0x800F0E00
    // 0x8080158C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x8080158C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80801590: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80801594:
    // 0x80801594: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80801598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080159C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808015A0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808015A4: nop

    // 0x808015A8: bc1f        L_80801600
    if (!c1cs) {
        // 0x808015AC: nop
    
            goto L_80801600;
    }
    // 0x808015AC: nop

    // 0x808015B0: jal         0x8008AF24
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808015B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015BC: jal         0x8008AED4
    // 0x808015C0: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x808015C0: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    after_7:
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015C8: jal         0x8008B134
    // 0x808015CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808015CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808015D0: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x808015D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808015D8: jal         0x8008B1BC
    // 0x808015DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x808015DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808015E0: lui         $a1, 0x3F52
    ctx->r5 = S32(0X3F52 << 16);
    // 0x808015E4: ori         $a1, $a1, 0x5BC
    ctx->r5 = ctx->r5 | 0X5BC;
    // 0x808015E8: jal         0x8008B24C
    // 0x808015EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_10;
    // 0x808015EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808015F0: jal         0x8008B064
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_11;
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808015F8: b           L_8080164C
    // 0x808015FC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
        goto L_8080164C;
    // 0x808015FC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_80801600:
    // 0x80801600: jal         0x8008AF24
    // 0x80801604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_12;
    // 0x80801604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080160C: jal         0x8008AED4
    // 0x80801610: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    anctrl_setIndex(rdram, ctx);
        goto after_13;
    // 0x80801610: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    after_13:
    // 0x80801614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801618: jal         0x8008B134
    // 0x8080161C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_14;
    // 0x8080161C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80801620: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80801624: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801628: jal         0x8008B1BC
    // 0x8080162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_15;
    // 0x8080162C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801630: lui         $a1, 0x3F24
    ctx->r5 = S32(0X3F24 << 16);
    // 0x80801634: ori         $a1, $a1, 0x25AF
    ctx->r5 = ctx->r5 | 0X25AF;
    // 0x80801638: jal         0x8008B24C
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_16;
    // 0x8080163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801640: jal         0x8008B064
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_17;
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801648: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_8080164C:
    // 0x8080164C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801650: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80801654: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801658: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080165C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80801660: lui         $a3, 0xC396
    ctx->r7 = S32(0XC396 << 16);
    // 0x80801664: jal         0x800F10B4
    // 0x80801668: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_18;
    // 0x80801668: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x8080166C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801670: swc1        $f0, 0x178($s1)
    MEM_W(0X178, ctx->r17) = ctx->f0.u32l;
    // 0x80801674: jal         0x8009BA58
    // 0x80801678: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x80801678: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x8080167C: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80801680: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080168C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801690: jal         0x8009FFD8
    // 0x80801694: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_20;
    // 0x80801694: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_20:
    // 0x80801698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080169C: jal         0x8009B800
    // 0x808016A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_21;
    // 0x808016A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_21:
    // 0x808016A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808016A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808016AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808016B0: jr          $ra
    // 0x808016B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808016B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800934_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080093C: jal         0x80082FE8
    // 0x80800940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800944: jal         0x80083F70
    // 0x80800948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bstnt_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080094C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800954: jr          $ra
    // 0x80800958: nop

    return;
    // 0x80800958: nop

;}
RECOMP_FUNC void func_800FCD5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCD5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800FCD60: lbu         $t6, 0x3E40($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3E40);
    // 0x800FCD64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCD68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCD6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FCD70: beq         $t6, $zero, L_800FCDA0
    if (ctx->r14 == 0) {
        // 0x800FCD74: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FCDA0;
    }
    // 0x800FCD74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FCD78: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FCD7C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FCD80: addiu       $s1, $s1, 0x59B0
    ctx->r17 = ADD32(ctx->r17, 0X59B0);
    // 0x800FCD84: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
L_800FCD88:
    // 0x800FCD88: jal         0x800B32E4
    // 0x800FCD8C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x800FCD8C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x800FCD90: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x800FCD94: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800FCD98: bne         $at, $zero, L_800FCD88
    if (ctx->r1 != 0) {
        // 0x800FCD9C: sw          $v0, -0x18($s0)
        MEM_W(-0X18, ctx->r16) = ctx->r2;
            goto L_800FCD88;
    }
    // 0x800FCD9C: sw          $v0, -0x18($s0)
    MEM_W(-0X18, ctx->r16) = ctx->r2;
L_800FCDA0:
    // 0x800FCDA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCDA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FCDA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FCDAC: jr          $ra
    // 0x800FCDB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FCDB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80802BE8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802BF0: jal         0x80106790
    // 0x80802BF4: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802BF4: nop

    after_0:
    // 0x80802BF8: jal         0x808029D8
    // 0x80802BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808029D8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80802BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80802C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C08: jr          $ra
    // 0x80802C0C: nop

    return;
    // 0x80802C0C: nop

;}
RECOMP_FUNC void func_8080007C_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080008C: jal         0x80102FDC
    // 0x80800090: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800090: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x80800094: jal         0x800CB3E0
    // 0x80800098: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800CB3E0(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8080009C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000A0: beq         $v0, $at, L_808000D0
    if (ctx->r2 == ctx->r1) {
        // 0x808000A4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808000D0;
    }
    // 0x808000A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000AC: beq         $v0, $at, L_80800100
    if (ctx->r2 == ctx->r1) {
        // 0x808000B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800100;
    }
    // 0x808000B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000B8: beq         $v0, $at, L_80800100
    if (ctx->r2 == ctx->r1) {
        // 0x808000BC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800100;
    }
    // 0x808000BC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808000C0: beq         $v0, $at, L_80800100
    if (ctx->r2 == ctx->r1) {
        // 0x808000C4: nop
    
            goto L_80800100;
    }
    // 0x808000C4: nop

    // 0x808000C8: b           L_8080010C
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080010C;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D0:
    // 0x808000D0: lhu         $a0, 0x76($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X76);
    // 0x808000D4: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x808000D8: jal         0x800DA298
    // 0x808000DC: addiu       $a0, $t7, 0x320
    ctx->r4 = ADD32(ctx->r15, 0X320);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808000DC: addiu       $a0, $t7, 0x320
    ctx->r4 = ADD32(ctx->r15, 0X320);
    after_2:
    // 0x808000E0: beq         $v0, $zero, L_808000F0
    if (ctx->r2 == 0) {
        // 0x808000E4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808000F0;
    }
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E8: b           L_808000F0
    // 0x808000EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_808000F0;
    // 0x808000EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_808000F0:
    // 0x808000F0: jal         0x808006AC
    // 0x808000F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_3;
    // 0x808000F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808000F8: b           L_8080010C
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080010C;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800100:
    // 0x80800100: jal         0x808006AC
    // 0x80800104: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_4;
    // 0x80800104: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080010C:
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void ncpod_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800DAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800DB0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800DB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DB8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800DC0: jal         0x80800958
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DC8: bne         $v0, $zero, L_80800DD8
    if (ctx->r2 != 0) {
        // 0x80800DCC: nop
    
            goto L_80800DD8;
    }
    // 0x80800DCC: nop

    // 0x80800DD0: b           L_80800E6C
    // 0x80800DD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E6C;
    // 0x80800DD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DD8:
    // 0x80800DD8: jal         0x80110024
    // 0x80800DDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80800DDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800DE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DE8: jal         0x808005C0
    // 0x80800DEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ncpod_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800DEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800DF0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800DF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800DF8: beq         $a1, $zero, L_80800E10
    if (ctx->r5 == 0) {
        // 0x80800DFC: nop
    
            goto L_80800E10;
    }
    // 0x80800DFC: nop

    // 0x80800E00: jal         0x80800548
    // 0x80800E04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ncpod_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800E04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800E08: b           L_80800E24
    // 0x80800E0C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_80800E24;
    // 0x80800E0C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80800E10:
    // 0x80800E10: beq         $t6, $zero, L_80800E20
    if (ctx->r14 == 0) {
        // 0x80800E14: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E20;
    }
    // 0x80800E14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E18: jal         0x80800548
    // 0x80800E1C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    ncpod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800E1C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_4:
L_80800E20:
    // 0x80800E20: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80800E24:
    // 0x80800E24: jal         0x80089638
    // 0x80800E28: lh          $a0, 0x2($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800E28: lh          $a0, 0x2($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2);
    after_5:
    // 0x80800E2C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800E30: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800E34: beql        $a1, $zero, L_80800E48
    if (ctx->r5 == 0) {
        // 0x80800E38: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800E48;
    }
    goto skip_0;
    // 0x80800E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800E3C: jal         0x80089648
    // 0x80800E40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpoducam_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800E40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800E44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800E48:
    // 0x80800E48: jal         0x80089650
    // 0x80800E4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _ncpoducam_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800E4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800E50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800E58: jal         0x80089640
    // 0x80800E5C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _ncpoducam_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800E5C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800E60: jal         0x8010FD88
    // 0x80800E64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010FD88(rdram, ctx);
        goto after_9;
    // 0x80800E64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E6C:
    // 0x80800E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E74: jr          $ra
    // 0x80800E78: nop

    return;
    // 0x80800E78: nop

;}
RECOMP_FUNC void func_800C8A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8A08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8A10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8A14: jal         0x800B28C4
    // 0x800C8A18: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800C8A18: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    after_0:
    // 0x800C8A1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8A20: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8A24: jal         0x800B296C
    // 0x800C8A28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800C8A28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C8A2C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C8A34: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800C8A38: beq         $at, $zero, L_800C8A88
    if (ctx->r1 == 0) {
        // 0x800C8A3C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C8A88;
    }
    // 0x800C8A3C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C8A40: lbu         $t6, 0x15($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X15);
L_800C8A44:
    // 0x800C8A44: beql        $t6, $zero, L_800C8A7C
    if (ctx->r14 == 0) {
        // 0x800C8A48: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_800C8A7C;
    }
    goto skip_0;
    // 0x800C8A48: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    skip_0:
    // 0x800C8A4C: lbu         $t7, 0x16($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X16);
    // 0x800C8A50: bnel        $v0, $t7, L_800C8A64
    if (ctx->r2 != ctx->r15) {
        // 0x800C8A54: sb          $zero, 0x16($v1)
        MEM_B(0X16, ctx->r3) = 0;
            goto L_800C8A64;
    }
    goto skip_1;
    // 0x800C8A54: sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
    skip_1:
    // 0x800C8A58: b           L_800C8A64
    // 0x800C8A5C: sb          $zero, 0x15($v1)
    MEM_B(0X15, ctx->r3) = 0;
        goto L_800C8A64;
    // 0x800C8A5C: sb          $zero, 0x15($v1)
    MEM_B(0X15, ctx->r3) = 0;
    // 0x800C8A60: sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
L_800C8A64:
    // 0x800C8A64: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    // 0x800C8A68: beql        $t8, $zero, L_800C8A78
    if (ctx->r24 == 0) {
        // 0x800C8A6C: sb          $zero, 0x19($v1)
        MEM_B(0X19, ctx->r3) = 0;
            goto L_800C8A78;
    }
    goto skip_2;
    // 0x800C8A6C: sb          $zero, 0x19($v1)
    MEM_B(0X19, ctx->r3) = 0;
    skip_2:
    // 0x800C8A70: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
    // 0x800C8A74: sb          $zero, 0x19($v1)
    MEM_B(0X19, ctx->r3) = 0;
L_800C8A78:
    // 0x800C8A78: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
L_800C8A7C:
    // 0x800C8A7C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800C8A80: bnel        $at, $zero, L_800C8A44
    if (ctx->r1 != 0) {
        // 0x800C8A84: lbu         $t6, 0x15($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X15);
            goto L_800C8A44;
    }
    goto skip_3;
    // 0x800C8A84: lbu         $t6, 0x15($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X15);
    skip_3:
L_800C8A88:
    // 0x800C8A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8A8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C8A90: jr          $ra
    // 0x800C8A94: nop

    return;
    // 0x800C8A94: nop

;}
RECOMP_FUNC void func_80800B34_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B48: beq         $a3, $zero, L_80800BBC
    if (ctx->r7 == 0) {
        // 0x80800B4C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800BBC;
    }
    // 0x80800B4C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B54: beq         $a3, $at, L_80800BD0
    if (ctx->r7 == ctx->r1) {
        // 0x80800B58: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800BD0;
    }
    // 0x80800B58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B5C: bnel        $a3, $at, L_80800BF0
    if (ctx->r7 != ctx->r1) {
        // 0x80800B60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF0;
    }
    goto skip_0;
    // 0x80800B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B64: jal         0x808002F4
    // 0x80800B68: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808002F4_chwarppad(rdram, ctx);
        goto after_0;
    // 0x80800B68: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800B6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800B70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B74: jal         0x80087D30
    // 0x80800B78: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800B78: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800B7C: beq         $v0, $zero, L_80800BA4
    if (ctx->r2 == 0) {
        // 0x80800B80: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80800BA4;
    }
    // 0x80800B80: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800B84: jal         0x80800ADC
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800ADC_chwarppad(rdram, ctx);
        goto after_2;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800B8C: beq         $v0, $zero, L_80800BEC
    if (ctx->r2 == 0) {
        // 0x80800B90: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800BEC;
    }
    // 0x80800B90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800B94: jal         0x80087DA8
    // 0x80800B98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_34(rdram, ctx);
        goto after_3;
    // 0x80800B98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800B9C: b           L_80800BF0
    // 0x80800BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF0;
    // 0x80800BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BA4:
    // 0x80800BA4: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BAC: jal         0x80800418
    // 0x80800BB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800418_chwarppad(rdram, ctx);
        goto after_4;
    // 0x80800BB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800BB4: b           L_80800BF0
    // 0x80800BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF0;
    // 0x80800BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BBC:
    // 0x80800BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC0: jal         0x808001F4
    // 0x80800BC4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808001F4_chwarppad(rdram, ctx);
        goto after_5;
    // 0x80800BC4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800BC8: b           L_80800BF0
    // 0x80800BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF0;
    // 0x80800BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BD0:
    // 0x80800BD0: jal         0x800C78CC
    // 0x80800BD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C78CC(rdram, ctx);
        goto after_6;
    // 0x80800BD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BDC: jal         0x80800418
    // 0x80800BE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800418_chwarppad(rdram, ctx);
        goto after_7;
    // 0x80800BE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800BE4: jal         0x80801018
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801018_chwarppad(rdram, ctx);
        goto after_8;
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800BEC:
    // 0x80800BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BF0:
    // 0x80800BF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BF8: jr          $ra
    // 0x80800BFC: nop

    return;
    // 0x80800BFC: nop

;}
RECOMP_FUNC void func_800FCD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCD14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCD18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCD1C: jal         0x800FB5F8
    // 0x800FCD20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCD20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FCD24: beq         $v0, $zero, L_800FCD4C
    if (ctx->r2 == 0) {
        // 0x800FCD28: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FCD4C;
    }
    // 0x800FCD28: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FCD2C: addiu       $t6, $t6, 0x57D0
    ctx->r14 = ADD32(ctx->r14, 0X57D0);
    // 0x800FCD30: subu        $a0, $v0, $t6
    ctx->r4 = SUB32(ctx->r2, ctx->r14);
    // 0x800FCD34: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FCD38: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800FCD3C: mflo        $t7
    ctx->r15 = lo;
    // 0x800FCD40: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    // 0x800FCD44: jal         0x800174C0
    // 0x800FCD48: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800174C0(rdram, ctx);
        goto after_1;
    // 0x800FCD48: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800FCD4C:
    // 0x800FCD4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FCD50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FCD54: jr          $ra
    // 0x800FCD58: nop

    return;
    // 0x800FCD58: nop

;}
RECOMP_FUNC void func_800A1760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1768: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x800A176C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A1770: beq         $t6, $zero, L_800A1788
    if (ctx->r14 == 0) {
        // 0x800A1774: nop
    
            goto L_800A1788;
    }
    // 0x800A1774: nop

    // 0x800A1778: jal         0x800F9F18
    // 0x800A177C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F9F18(rdram, ctx);
        goto after_0;
    // 0x800A177C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A1780: b           L_800A179C
    // 0x800A1784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A179C;
    // 0x800A1784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1788:
    // 0x800A1788: jal         0x800A3274
    // 0x800A178C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800A178C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800A1790: jal         0x800D4EB8
    // 0x800A1794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D4EB8(rdram, ctx);
        goto after_2;
    // 0x800A1794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A1798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A179C:
    // 0x800A179C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A17A0: jr          $ra
    // 0x800A17A4: nop

    return;
    // 0x800A17A4: nop

;}
RECOMP_FUNC void func_800EC890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC890: jr          $ra
    // 0x800EC894: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800EC894: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800EFB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFB24: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFB28: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EFB2C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EFB30: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800EFB34: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EFB38: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EFB3C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EFB40: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800EFB44: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EFB48: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFB4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EFB50: jr          $ra
    // 0x800EFB54: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800EFB54: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800EFBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFBFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EFC00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFC04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EFC08: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EFC0C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EFC10: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFC14: jal         0x800F2100
    // 0x800EFC18: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800EFC18: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x800EFC1C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800EFC20: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800EFC24: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800EFC28: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800EFC2C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800EFC30: jal         0x800F2100
    // 0x800EFC34: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800EFC34: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_1:
    // 0x800EFC38: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EFC3C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800EFC40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EFC44: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800EFC48: nop

    // 0x800EFC4C: bc1fl       L_800EFC60
    if (!c1cs) {
        // 0x800EFC50: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_800EFC60;
    }
    goto skip_0;
    // 0x800EFC50: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x800EFC54: b           L_800EFC60
    // 0x800EFC58: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_800EFC60;
    // 0x800EFC58: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x800EFC5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800EFC60:
    // 0x800EFC60: lwc1        $f18, 0x5EA0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5EA0);
    // 0x800EFC64: add.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800EFC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFC6C: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800EFC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EFC74: jr          $ra
    // 0x800EFC78: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
    return;
    // 0x800EFC78: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
;}
RECOMP_FUNC void func_80801DCC_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801DD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801DD8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x80801DDC: jal         0x80106790
    // 0x80801DE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801DE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801DE4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801DE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801DEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DF0: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    // 0x80801DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801DF8: beql        $t6, $at, L_80801E4C
    if (ctx->r14 == ctx->r1) {
        // 0x80801DFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801E4C;
    }
    goto skip_0;
    // 0x80801DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801E00: jal         0x80100094
    // 0x80801E04: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801E04: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80801E08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801E0C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801E10: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801E14: lw          $t7, 0x2C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X2C);
    // 0x80801E18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801E1C: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801E20: mflo        $t8
    ctx->r24 = lo;
    // 0x80801E24: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x80801E28: lbu         $t9, 0x15($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X15);
    // 0x80801E2C: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80801E30: sb          $t0, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r8;
    // 0x80801E34: lw          $t1, 0x2C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X2C);
    // 0x80801E38: multu       $t1, $a0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80801E3C: mflo        $t2
    ctx->r10 = lo;
    // 0x80801E40: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80801E44: swc1        $f4, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f4.u32l;
    // 0x80801E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801E4C:
    // 0x80801E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801E50: jr          $ra
    // 0x80801E54: nop

    return;
    // 0x80801E54: nop

    // 0x80801E58: nop

    // 0x80801E5C: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800004: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800008: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080000C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800010: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800014: addiu       $s6, $sp, 0x54
    ctx->r22 = ADD32(ctx->r29, 0X54);
    // 0x80800018: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800020: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800024: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800028: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080002C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800030: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800034: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800038: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8080003C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800040: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800044: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80800048: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8080004C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800050: jal         0x801067C4
    // 0x80800054: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800054: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80800058: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x8080005C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808000F4;
    }
    // 0x8080005C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800060: addiu       $fp, $zero, 0x243
    ctx->r30 = ADD32(0, 0X243);
    // 0x80800064: addiu       $s7, $zero, 0x215
    ctx->r23 = ADD32(0, 0X215);
L_80800068:
    // 0x80800068: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x8080006C: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x80800070: srl         $v1, $t6, 20
    ctx->r3 = S32(U32(ctx->r14) >> 20);
    // 0x80800074: beql        $s2, $v1, L_80800088
    if (ctx->r18 == ctx->r3) {
        // 0x80800078: lhu         $t8, 0x72($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X72);
            goto L_80800088;
    }
    goto skip_0;
    // 0x80800078: lhu         $t8, 0x72($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X72);
    skip_0:
    // 0x8080007C: bgez        $s2, L_808000E4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80800080: nop
    
            goto L_808000E4;
    }
    // 0x80800080: nop

    // 0x80800084: lhu         $t8, 0x72($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X72);
L_80800088:
    // 0x80800088: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080008C: beq         $s4, $t9, L_808000E4
    if (ctx->r20 == ctx->r25) {
        // 0x80800090: nop
    
            goto L_808000E4;
    }
    // 0x80800090: nop

    // 0x80800094: beq         $s7, $v1, L_808000E4
    if (ctx->r23 == ctx->r3) {
        // 0x80800098: nop
    
            goto L_808000E4;
    }
    // 0x80800098: nop

    // 0x8080009C: beq         $fp, $v1, L_808000E4
    if (ctx->r30 == ctx->r3) {
        // 0x808000A0: nop
    
            goto L_808000E4;
    }
    // 0x808000A0: nop

    // 0x808000A4: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x808000A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808000AC: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x808000B0: bltz        $t2, L_808000E4
    if (SIGNED(ctx->r10) < 0) {
        // 0x808000B4: nop
    
            goto L_808000E4;
    }
    // 0x808000B4: nop

    // 0x808000B8: jal         0x800EEB40
    // 0x808000BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x808000BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808000C0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808000C4: nop

    // 0x808000C8: bc1tl       L_808000DC
    if (c1cs) {
        // 0x808000CC: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_808000DC;
    }
    goto skip_1;
    // 0x808000CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_1:
    // 0x808000D0: bne         $s1, $zero, L_808000E4
    if (ctx->r17 != 0) {
        // 0x808000D4: nop
    
            goto L_808000E4;
    }
    // 0x808000D4: nop

    // 0x808000D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_808000DC:
    // 0x808000DC: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x808000E0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_808000E4:
    // 0x808000E4: jal         0x8010682C
    // 0x808000E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x808000E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x808000EC: bne         $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x808000F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800068;
    }
    // 0x808000F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808000F4:
    // 0x808000F4: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x808000F8: beql        $t3, $zero, L_80800114
    if (ctx->r11 == 0) {
        // 0x808000FC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800114;
    }
    goto skip_2;
    // 0x808000FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80800100: jal         0x8002DCA0
    // 0x80800104: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80800104: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x80800108: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8080010C: swc1        $f0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f0.u32l;
    // 0x80800110: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800114:
    // 0x80800114: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800118: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8080011C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800124: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800128: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080012C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800130: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800134: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800138: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8080013C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80800140: jr          $ra
    // 0x80800144: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800144: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800F5CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5CEC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5CF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5CF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5CFC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5D00: jal         0x8009EF04
    // 0x800F5D04: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x800F5D04: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5D10: jr          $ra
    // 0x800F5D14: nop

    return;
    // 0x800F5D14: nop

;}
RECOMP_FUNC void func_80017330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017330: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80017334: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017338: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001733C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80017340: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017344: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017348: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001734C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80017350: addiu       $t8, $t8, -0x6060
    ctx->r24 = ADD32(ctx->r24, -0X6060);
    // 0x80017354: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017358: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001735C: lh          $a1, 0x26C($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X26C);
    // 0x80017360: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80017364: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80017368: beq         $a1, $at, L_8001737C
    if (ctx->r5 == ctx->r1) {
        // 0x8001736C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8001737C;
    }
    // 0x8001736C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80017370: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80017374: bne         $v0, $at, L_80017390
    if (ctx->r2 != ctx->r1) {
        // 0x80017378: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80017390;
    }
    // 0x80017378: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_8001737C:
    // 0x8001737C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017380: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80017384: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80017388: jr          $ra
    // 0x8001738C: sh          $a1, 0x26E($v1)
    MEM_H(0X26E, ctx->r3) = ctx->r5;
    return;
    // 0x8001738C: sh          $a1, 0x26E($v1)
    MEM_H(0X26E, ctx->r3) = ctx->r5;
L_80017390:
    // 0x80017390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017394: sh          $t9, 0x26E($v1)
    MEM_H(0X26E, ctx->r3) = ctx->r25;
    // 0x80017398: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x8001739C: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x800173A0: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x800173A4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800173A8: jr          $ra
    // 0x800173AC: nop

    return;
    // 0x800173AC: nop

;}
RECOMP_FUNC void func_800A7D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7D34: lwc1        $f6, 0x7638($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7638);
    // 0x800A7D38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A7D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7D44: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800A7D48: nop

    // 0x800A7D4C: bc1f        L_800A7D64
    if (!c1cs) {
        // 0x800A7D50: nop
    
            goto L_800A7D64;
    }
    // 0x800A7D50: nop

    // 0x800A7D54: jal         0x800D8FA0
    // 0x800A7D58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D8FA0(rdram, ctx);
        goto after_0;
    // 0x800A7D58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800A7D5C: b           L_800A7D78
    // 0x800A7D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A7D78;
    // 0x800A7D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7D64:
    // 0x800A7D64: jal         0x80014F4C
    // 0x800A7D68: nop

    func_80014F4C(rdram, ctx);
        goto after_1;
    // 0x800A7D68: nop

    after_1:
    tooie_frame_step(rdram, ctx);
    // 0x800A7D6C: jal         0x800D8FA0
    // 0x800A7D70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D8FA0(rdram, ctx);
        goto after_2;
    // 0x800A7D70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A7D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7D78:
    // 0x800A7D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7D7C: jr          $ra
    // 0x800A7D80: nop

    return;
    // 0x800A7D80: nop

;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080020C: jal         0x800956B8
    // 0x80800210: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_800956B8(rdram, ctx);
        goto after_0;
    // 0x80800210: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800214: jal         0x800834E0
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080021C: jal         0x800834B0
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800224: jal         0x800850A0
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080022C: jal         0x8009EF10
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800234: bne         $v0, $zero, L_80800250
    if (ctx->r2 != 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800250;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x8009BCD4
    // 0x80800240: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_5;
    // 0x80800240: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800244: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800248: addiu       $t6, $zero, 0x187
        ctx->r14 = ADD32(0, 0X187);
            goto L_80800250;
    }
    // 0x80800248: addiu       $t6, $zero, 0x187
    ctx->r14 = ADD32(0, 0X187);
    // 0x8080024C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80800250:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x80091A58
    // 0x80800258: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x80800258: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x8080025C: beql        $v0, $zero, L_80800274
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800274;
    }
    goto skip_0;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800264: jal         0x800832F0
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080026C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800274:
    // 0x80800274: jal         0x80084E80
    // 0x80800278: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    _bamovespline_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800278: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_8:
    // 0x8080027C: bnel        $v0, $zero, L_80800298
    if (ctx->r2 != 0) {
        // 0x80800280: addiu       $t7, $zero, 0xDF
        ctx->r15 = ADD32(0, 0XDF);
            goto L_80800298;
    }
    goto skip_1;
    // 0x80800280: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
    skip_1:
    // 0x80800284: jal         0x80084FE0
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080028C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800290: beq         $v0, $at, L_8080029C
    if (ctx->r2 == ctx->r1) {
        // 0x80800294: addiu       $t7, $zero, 0xDF
        ctx->r15 = ADD32(0, 0XDF);
            goto L_8080029C;
    }
    // 0x80800294: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
L_80800298:
    // 0x80800298: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8080029C:
    // 0x8080029C: jal         0x80084E90
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002A4: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x808002A8: addiu       $t8, $zero, 0xC7
        ctx->r24 = ADD32(0, 0XC7);
            goto L_808002B0;
    }
    // 0x808002A8: addiu       $t8, $zero, 0xC7
    ctx->r24 = ADD32(0, 0XC7);
    // 0x808002AC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808002B0:
    // 0x808002B0: jal         0x80084E88
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002B8: beql        $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002FC;
    }
    goto skip_2;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808002C0: jal         0x80084FE8
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002CC: bne         $v0, $at, L_808002F4
    if (ctx->r2 != ctx->r1) {
        // 0x808002D0: addiu       $t9, $zero, 0xC7
        ctx->r25 = ADD32(0, 0XC7);
            goto L_808002F4;
    }
    // 0x808002D0: addiu       $t9, $zero, 0xC7
    ctx->r25 = ADD32(0, 0XC7);
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x80085088
    // 0x808002DC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _bashoessuck_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808002DC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_13:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x800848A0
    // 0x808002E8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _badrone_entrypoint_23(rdram, ctx);
        goto after_14;
    // 0x808002E8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_14:
    // 0x808002EC: b           L_808002F8
    // 0x808002F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_808002F8;
    // 0x808002F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808002F4:
    // 0x808002F4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_808002F8:
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002FC:
    // 0x808002FC: jal         0x8009E5C8
    // 0x80800300: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80800300: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800308: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080030C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800310: jr          $ra
    // 0x80800314: nop

    return;
    // 0x80800314: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887C8: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887C8);
    return;
    // 0x800887CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D60: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D60);
    return;
    // 0x80087D64: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void bsbansack_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801428: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080142C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E50) << 16);
    // 0x80801430: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801434: jr          $ra
    // 0x80801438: lw          $v0, 0x1E50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E50));
    return;
    // 0x80801438: lw          $v0, 0x1E50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E50));
;}
RECOMP_FUNC void func_80800D24_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800D34: jal         0x800F5578
    // 0x80800D38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F5578(rdram, ctx);
        goto after_0;
    // 0x80800D38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800D3C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800D40: sh          $v0, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r2;
    // 0x80800D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D4C: jr          $ra
    // 0x80800D50: nop

    return;
    // 0x80800D50: nop

;}
RECOMP_FUNC void func_80800044_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800050: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800054: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800058: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x8080005C: jal         0x800EFA4C
    // 0x80800060: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800060: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_0:
    // 0x80800064: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800068: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080006C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800070: jal         0x800EF934
    // 0x80800074: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    func_800EF934(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x80800078: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080007C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800080: jal         0x800EF04C
    // 0x80800084: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800084: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800088: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080008C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jal         0x800EE7F8
    // 0x80800094: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800094: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_3:
    // 0x80800098: jal         0x800906B0
    // 0x8080009C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800906B0(rdram, ctx);
        goto after_4;
    // 0x8080009C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x808000A0: jal         0x800906DC
    // 0x808000A4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800906DC(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_808010AC_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808010B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808010B4: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808010B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808010C0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(896, 0X13A4) << 16);
    // 0x808010C4: addiu       $t7, $t7, 0x13A4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(896, 0X13A4));
    // 0x808010C8: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x808010CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808010D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808010D4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808010D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808010DC: jal         0x800BBCB8
    // 0x808010E0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808010E0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x808010E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(896, 0X13DC) << 16);
    // 0x808010E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808010EC: jal         0x800C4AF0
    // 0x808010F0: addiu       $a1, $a1, 0x13DC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(896, 0X13DC));
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x808010F0: addiu       $a1, $a1, 0x13DC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(896, 0X13DC));
    after_1:
    // 0x808010F4: jal         0x8010A570
    // 0x808010F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808010F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808010FC: jal         0x800FFAB0
    // 0x80801100: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80801100: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80801104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080110C: jr          $ra
    // 0x80801110: nop

    return;
    // 0x80801110: nop

;}
RECOMP_FUNC void func_80800064_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800074: jal         0x80091A30
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_0;
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080007C: beq         $v0, $zero, L_80800088
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800088;
    }
    // 0x80800080: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800084: addiu       $v1, $zero, 0x127
    ctx->r3 = ADD32(0, 0X127);
L_80800088:
    // 0x80800088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800090: jal         0x80091A58
    // 0x80800094: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x80800094: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800098: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A4;
    }
    // 0x8080009C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: addiu       $v1, $zero, 0x124
    ctx->r3 = ADD32(0, 0X124);
L_808000A4:
    // 0x808000A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808000AC: jal         0x80091A58
    // 0x808000B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x808000B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808000B4: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000C0;
    }
    // 0x808000B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: addiu       $v1, $zero, 0x126
    ctx->r3 = ADD32(0, 0X126);
L_808000C0:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_800DF440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF440: beq         $a0, $zero, L_800DF458
    if (ctx->r4 == 0) {
        // 0x800DF444: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800DF458;
    }
    // 0x800DF444: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DF44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF450: jr          $ra
    // 0x800DF454: sw          $t6, -0x37D8($at)
    MEM_W(-0X37D8, ctx->r1) = ctx->r14;
    return;
    // 0x800DF454: sw          $t6, -0x37D8($at)
    MEM_W(-0X37D8, ctx->r1) = ctx->r14;
L_800DF458:
    // 0x800DF458: sw          $zero, -0x37D8($at)
    MEM_W(-0X37D8, ctx->r1) = 0;
    // 0x800DF45C: jr          $ra
    // 0x800DF460: nop

    return;
    // 0x800DF460: nop

;}
RECOMP_FUNC void _chcablespark_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E40: syscall     247
    recomp_syscall_handler(rdram, ctx, 0x80085E40);
    return;
    // 0x80085E44: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void suquiz_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080089C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008A4: jal         0x800DA298
    // 0x808008A8: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808008A8: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    after_0:
    // 0x808008AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008B4: jr          $ra
    // 0x808008B8: nop

    return;
    // 0x808008B8: nop

;}
RECOMP_FUNC void func_8009370C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009370C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093714: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093718: jal         0x800AE080
    // 0x8009371C: lh          $a0, 0x90($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X90);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x8009371C: lh          $a0, 0x90($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X90);
    after_0:
    // 0x80093720: jal         0x800AE6BC
    // 0x80093724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE6BC(rdram, ctx);
        goto after_1;
    // 0x80093724: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80093728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009372C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093730: jr          $ra
    // 0x80093734: nop

    return;
    // 0x80093734: nop

;}
RECOMP_FUNC void _chstarspinnerstar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DF8: syscall     244
    recomp_syscall_handler(rdram, ctx, 0x80085DF8);
    return;
    // 0x80085DFC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800164_gcgamefix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x800DA298
    // 0x80800170: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800170: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_0:
    // 0x80800174: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x80800178: addiu       $a0, $zero, 0x2A
        ctx->r4 = ADD32(0, 0X2A);
            goto L_80800198;
    }
    // 0x80800178: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x8080017C: jal         0x800D0B68
    // 0x80800180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x80800180: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800184: bne         $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x80800188: addiu       $a0, $zero, 0x2A
        ctx->r4 = ADD32(0, 0X2A);
            goto L_80800198;
    }
    // 0x80800188: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800190: jal         0x800D0C78
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800D0C78(rdram, ctx);
        goto after_2;
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80800198:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80800044_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800054: jal         0x8009C128
    // 0x80800058: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800058: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x80096394
    // 0x80800064: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80096394(rdram, ctx);
        goto after_1;
    // 0x80800064: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80800068: jal         0x800962D4
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800962D4(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800070: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800074: jal         0x80096518
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096518(rdram, ctx);
        goto after_3;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080007C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800080: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800084: jal         0x8009BB50
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_4;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080008C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800090: jal         0x8009650C
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_5;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800098: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800128;
    }
    // 0x8080009C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808000A0: beq         $t7, $zero, L_80800128
    if (ctx->r15 == 0) {
        // 0x808000A4: lwc1        $f4, 0x4C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80800128;
    }
    // 0x808000A4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808000A8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808000AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000B4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000BC: nop

    // 0x808000C0: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000C4: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080012C;
    }
    goto skip_0;
    // 0x808000C4: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_0:
    // 0x808000C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000CC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x808000D0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808000D4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808000D8: nop

    // 0x808000DC: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000E0: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080012C;
    }
    goto skip_1;
    // 0x808000E0: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_1:
    // 0x808000E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000E8: nop

    // 0x808000EC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808000F0: nop

    // 0x808000F4: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000F8: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080012C;
    }
    goto skip_2;
    // 0x808000F8: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_2:
    // 0x808000FC: lw          $t8, 0x164($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X164);
    // 0x80800100: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800104: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800108: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8080010C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800110: jal         0x800F13F0
    // 0x80800114: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F13F0(rdram, ctx);
        goto after_6;
    // 0x80800114: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x80800118: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080011C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80800120: b           L_8080012C
    // 0x80800124: sw          $t1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r9;
        goto L_8080012C;
    // 0x80800124: sw          $t1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r9;
L_80800128:
    // 0x80800128: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_8080012C:
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800130: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800134: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_808011CC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808011D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808011DC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808011E0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808011E4: beql        $a1, $t7, L_8080122C
    if (ctx->r5 == ctx->r15) {
        // 0x808011E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080122C;
    }
    goto skip_0;
    // 0x808011E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808011EC: jal         0x80101FDC
    // 0x808011F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808011F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011F8: jal         0x80100094
    // 0x808011FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808011FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801200: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13E4) << 16);
    // 0x80801208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080120C: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80801210: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80801214: lwc1        $f6, 0x13E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13E4));
    // 0x80801218: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8080121C: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x80801220: jal         0x80018820
    // 0x80801224: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80801224: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080122C:
    // 0x8080122C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801230: jr          $ra
    // 0x80801234: nop

    return;
    // 0x80801234: nop

;}
RECOMP_FUNC void func_80106E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106E50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106E54: lw          $a0, 0x6F00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F00);
    // 0x80106E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106E60: beql        $a0, $zero, L_80106E7C
    if (ctx->r4 == 0) {
        // 0x80106E64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106E7C;
    }
    goto skip_0;
    // 0x80106E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106E68: jal         0x800B32E4
    // 0x80106E6C: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x80106E6C: nop

    after_0:
    // 0x80106E70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106E74: sw          $v0, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->r2;
    // 0x80106E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106E7C:
    // 0x80106E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106E80: jr          $ra
    // 0x80106E84: nop

    return;
    // 0x80106E84: nop

;}
RECOMP_FUNC void func_800D7184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7184: beq         $a1, $zero, L_800D71C0
    if (ctx->r5 == 0) {
        // 0x800D7188: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_800D71C0;
    }
    // 0x800D7188: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x800D718C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D7190: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D7194: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D7198: addiu       $t7, $t7, 0x7E90
    if (tooie_more_memory()) ctx->r15 = ADD32(ctx->r15, 0X7E90); else ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x800D719C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D71A0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D71A4: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x800D71A8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D71AC: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800D71B0: andi        $t1, $t8, 0xFFF0
    ctx->r9 = ctx->r24 & 0XFFF0;
    // 0x800D71B4: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x800D71B8: jr          $ra
    // 0x800D71BC: sb          $t2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r10;
    return;
    // 0x800D71BC: sb          $t2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r10;
L_800D71C0:
    // 0x800D71C0: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800D71C4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800D71C8: addiu       $t4, $t4, 0x7E90
    if (tooie_more_memory()) ctx->r12 = ADD32(ctx->r12, 0X7E90); else ctx->r12 = ADD32(ctx->r12, -0X4800);
    // 0x800D71CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800D71D0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800D71D4: lbu         $t5, 0xA($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XA);
    // 0x800D71D8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800D71DC: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800D71E0: andi        $t8, $t5, 0xFFF0
    ctx->r24 = ctx->r13 & 0XFFF0;
    // 0x800D71E4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D71E8: sb          $t9, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r25;
    // 0x800D71EC: jr          $ra
    // 0x800D71F0: nop

    return;
    // 0x800D71F0: nop

;}
