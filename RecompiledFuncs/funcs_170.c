#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800024_chmole_prehist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800899D0
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800040: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800044: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800048: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080004C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800050: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800054: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800058: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8080005C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800060: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800064: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800068: bgez        $t4, L_8080007C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080006C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080007C;
    }
    // 0x8080006C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800074: nop

    // 0x80800078: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080007C:
    // 0x8080007C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_800D34A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D34A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D34A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D34A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D34AC: jal         0x800E7188
    // 0x800D34B0: addiu       $a0, $a0, -0x4A80
    ctx->r4 = ADD32(ctx->r4, -0X4A80);
    func_800E7188(rdram, ctx);
        goto after_0;
    // 0x800D34B0: addiu       $a0, $a0, -0x4A80
    ctx->r4 = ADD32(ctx->r4, -0X4A80);
    after_0:
    // 0x800D34B4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D34B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D34BC: addiu       $a3, $a3, -0x4C90
    ctx->r7 = ADD32(ctx->r7, -0X4C90);
    // 0x800D34C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D34C4: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x800D34C8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800D34CC:
    // 0x800D34CC: blez        $v0, L_800D34FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D34D0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800D34FC;
    }
    // 0x800D34D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D34D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D34D8: addiu       $v1, $v1, -0x4A80
    ctx->r3 = ADD32(ctx->r3, -0X4A80);
L_800D34DC:
    // 0x800D34DC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800D34E0: bne         $a1, $t6, L_800D34F0
    if (ctx->r5 != ctx->r14) {
        // 0x800D34E4: addu        $t7, $a3, $a1
        ctx->r15 = ADD32(ctx->r7, ctx->r5);
            goto L_800D34F0;
    }
    // 0x800D34E4: addu        $t7, $a3, $a1
    ctx->r15 = ADD32(ctx->r7, ctx->r5);
    // 0x800D34E8: b           L_800D34FC
    // 0x800D34EC: sb          $a0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r4;
        goto L_800D34FC;
    // 0x800D34EC: sb          $a0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r4;
L_800D34F0:
    // 0x800D34F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D34F4: bne         $a0, $a2, L_800D34DC
    if (ctx->r4 != ctx->r6) {
        // 0x800D34F8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D34DC;
    }
    // 0x800D34F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D34FC:
    // 0x800D34FC: bne         $a0, $v0, L_800D3508
    if (ctx->r4 != ctx->r2) {
        // 0x800D3500: addu        $t8, $a3, $a1
        ctx->r24 = ADD32(ctx->r7, ctx->r5);
            goto L_800D3508;
    }
    // 0x800D3500: addu        $t8, $a3, $a1
    ctx->r24 = ADD32(ctx->r7, ctx->r5);
    // 0x800D3504: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
L_800D3508:
    // 0x800D3508: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800D350C: bne         $a1, $t1, L_800D34CC
    if (ctx->r5 != ctx->r9) {
        // 0x800D3510: nop
    
            goto L_800D34CC;
    }
    // 0x800D3510: nop

    // 0x800D3514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D351C: jr          $ra
    // 0x800D3520: nop

    return;
    // 0x800D3520: nop

;}
RECOMP_FUNC void chfactoryempspell_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802034: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2304, 0X2414) << 16);
    // 0x80802038: jr          $ra
    // 0x8080203C: addiu       $v0, $v0, 0x2414
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2304, 0X2414));
    return;
    // 0x8080203C: addiu       $v0, $v0, 0x2414
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2304, 0X2414));
;}
RECOMP_FUNC void _bssplitup_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B20: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083B20);
    return;
    // 0x80083B24: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80800B38_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B4C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800B50: jal         0x800DA298
    // 0x80800B54: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800B54: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    after_0:
    // 0x80800B58: bne         $v0, $zero, L_80800B90
    if (ctx->r2 != 0) {
        // 0x80800B5C: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B90;
    }
    // 0x80800B5C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B60: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80800B64: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800B68: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800B6C: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80800B70: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80800B74: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800B78: addiu       $a0, $a0, -0x5A88
    ctx->r4 = ADD32(ctx->r4, -0X5A88);
    // 0x80800B7C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800B80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800B88: jal         0x80086D58
    // 0x80800B8C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800B8C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
L_80800B90:
    // 0x80800B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B98: jr          $ra
    // 0x80800B9C: nop

    return;
    // 0x80800B9C: nop

;}
RECOMP_FUNC void func_80804ED4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804EDC: jal         0x80807D48
    // 0x80804EE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804EE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80804EE4: jal         0x800EA068
    // 0x80804EE8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80804EE8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x80804EEC: beq         $v0, $zero, L_80804EFC
    if (ctx->r2 == 0) {
        // 0x80804EF0: addiu       $a1, $zero, 0xC9
        ctx->r5 = ADD32(0, 0XC9);
            goto L_80804EFC;
    }
    // 0x80804EF0: addiu       $a1, $zero, 0xC9
    ctx->r5 = ADD32(0, 0XC9);
    // 0x80804EF4: b           L_80804EFC
    // 0x80804EF8: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
        goto L_80804EFC;
    // 0x80804EF8: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
L_80804EFC:
    // 0x80804EFC: jal         0x8009E5C8
    // 0x80804F00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80804F00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80804F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804F0C: jr          $ra
    // 0x80804F10: nop

    return;
    // 0x80804F10: nop

;}
RECOMP_FUNC void _ncbabee_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896D8: syscall     787
    recomp_syscall_handler(rdram, ctx, 0x800896D8);
    return;
    // 0x800896DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _suquiz_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A868: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A868);
    return;
    // 0x8008A86C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80800194_chtalontorpedoboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001A8: jal         0x800DF744
    // 0x808001AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808001AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001B4: jal         0x80101870
    // 0x808001B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808001B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_8009646C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009646C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80096470: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80096474: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80096478: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009647C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80096480: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80096484: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80096488: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009648C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80096490: addiu       $s3, $zero, 0x24
    ctx->r19 = ADD32(0, 0X24);
L_80096494:
    // 0x80096494: lw          $t6, 0x94($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X94);
    // 0x80096498: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009649C: addu        $a1, $t6, $s0
    ctx->r5 = ADD32(ctx->r14, ctx->r16);
    // 0x800964A0: jal         0x800EE7F8
    // 0x800964A4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800964A4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_0:
    // 0x800964A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800964AC: bne         $s0, $s3, L_80096494
    if (ctx->r16 != ctx->r19) {
        // 0x800964B0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80096494;
    }
    // 0x800964B0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800964B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800964B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800964BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800964C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800964C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800964C8: jr          $ra
    // 0x800964CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800964CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80102204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80102208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010220C: jal         0x80104248
    // 0x80102210: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80102210: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80102214: beq         $v0, $zero, L_801022D4
    if (ctx->r2 == 0) {
        // 0x80102218: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_801022D4;
    }
    // 0x80102218: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8010221C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80102220: jal         0x801039E4
    // 0x80102224: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80102224: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80102228: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8010222C: jal         0x8008B304
    // 0x80102230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008B304(rdram, ctx);
        goto after_2;
    // 0x80102230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80102234: jal         0x8008B4D4
    // 0x80102238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008B4D4(rdram, ctx);
        goto after_3;
    // 0x80102238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8010223C: jal         0x800DF330
    // 0x80102240: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DF330(rdram, ctx);
        goto after_4;
    // 0x80102240: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x80102244: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80102248: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8010224C: jal         0x80103CDC
    // 0x80102250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80103CDC(rdram, ctx);
        goto after_5;
    // 0x80102250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80102254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80102258: jal         0x800B26F0
    // 0x8010225C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B26F0(rdram, ctx);
        goto after_6;
    // 0x8010225C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80102260: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80102264: jal         0x800B27E0
    // 0x80102268: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800B27E0(rdram, ctx);
        goto after_7;
    // 0x80102268: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8010226C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80102270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80102274: jal         0x800AE160
    // 0x80102278: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800AE160(rdram, ctx);
        goto after_8;
    // 0x80102278: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x8010227C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80102280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80102284: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80102288: jal         0x800879B0
    // 0x8010228C: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    _dbanim_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x8010228C: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    after_9:
    // 0x80102290: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80102294: lbu         $t9, 0x70($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X70);
    // 0x80102298: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8010229C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x801022A0: beq         $t0, $zero, L_801022C4
    if (ctx->r8 == 0) {
        // 0x801022A4: nop
    
            goto L_801022C4;
    }
    // 0x801022A4: nop

    // 0x801022A8: jal         0x80103D00
    // 0x801022AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80103D00(rdram, ctx);
        goto after_10;
    // 0x801022AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x801022B0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801022B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801022B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801022BC: jal         0x800879B0
    // 0x801022C0: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    _dbanim_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x801022C0: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    after_11:
L_801022C4:
    // 0x801022C4: jal         0x800DF41C
    // 0x801022C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF41C(rdram, ctx);
        goto after_12;
    // 0x801022C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x801022CC: jal         0x800DF72C
    // 0x801022D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF72C(rdram, ctx);
        goto after_13;
    // 0x801022D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
L_801022D4:
    // 0x801022D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801022D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801022DC: jr          $ra
    // 0x801022E0: nop

    return;
    // 0x801022E0: nop

;}
RECOMP_FUNC void chfactorymagnet_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802848: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2284, 0X2B68) << 16);
    // 0x8080284C: jr          $ra
    // 0x80802850: addiu       $v0, $v0, 0x2B68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2B68));
    return;
    // 0x80802850: addiu       $v0, $v0, 0x2B68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2B68));
    // 0x80802854: nop

    // 0x80802858: nop

    // 0x8080285C: nop

;}
RECOMP_FUNC void func_80800030_chgruntyfireballbig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800044: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1500, 0X6C8) << 16);
    // 0x80800048: addiu       $a3, $a3, 0x6C8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1500, 0X6C8));
    // 0x8080004C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800050: jal         0x80089D50
    // 0x80800054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800058: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080005C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800060: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800064: beq         $t6, $at, L_80800084
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800084;
    }
    // 0x80800068: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080006C: beq         $t6, $at, L_80800094
    if (ctx->r14 == ctx->r1) {
        // 0x80800070: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800094;
    }
    // 0x80800070: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800074: beq         $t6, $at, L_80800100
    if (ctx->r14 == ctx->r1) {
        // 0x80800078: nop
    
            goto L_80800100;
    }
    // 0x80800078: nop

    // 0x8080007C: b           L_80800168
    // 0x80800080: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_80800168;
    // 0x80800080: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_80800084:
    // 0x80800084: jal         0x808004C4
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004C4_chgruntyfireballbig(rdram, ctx);
        goto after_1;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080008C: b           L_80800168
    // 0x80800090: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_80800168;
    // 0x80800090: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_80800094:
    // 0x80800094: jal         0x80800590
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800590_chgruntyfireballbig(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080009C: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x808000A0: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x808000A4: jal         0x8010B990
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_3;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000AC: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x808000B0: beq         $t7, $zero, L_808000F0
    if (ctx->r15 == 0) {
        // 0x808000B4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808000F0;
    }
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000B8: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x808000BC: lui         $a2, 0x3E61
    ctx->r6 = S32(0X3E61 << 16);
    // 0x808000C0: ori         $a2, $a2, 0x47AE
    ctx->r6 = ctx->r6 | 0X47AE;
    // 0x808000C4: jal         0x80018820
    // 0x808000C8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80018820(rdram, ctx);
        goto after_4;
    // 0x808000C8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_4:
    // 0x808000CC: lui         $a2, 0x3F57
    ctx->r6 = S32(0X3F57 << 16);
    // 0x808000D0: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x808000D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000D8: jal         0x800E15CC
    // 0x808000DC: lui         $a1, 0x41C0
    ctx->r5 = S32(0X41C0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_5;
    // 0x808000DC: lui         $a1, 0x41C0
    ctx->r5 = S32(0X41C0 << 16);
    after_5:
    // 0x808000E0: jal         0x8080034C
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080034C_chgruntyfireballbig(rdram, ctx);
        goto after_6;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000E8: b           L_80800168
    // 0x808000EC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_80800168;
    // 0x808000EC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_808000F0:
    // 0x808000F0: jal         0x808004C4
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004C4_chgruntyfireballbig(rdram, ctx);
        goto after_7;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000F8: b           L_80800168
    // 0x808000FC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_80800168;
    // 0x808000FC: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_80800100:
    // 0x80800100: jal         0x800D8FF8
    // 0x80800104: nop

    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x80800104: nop

    after_8:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x808004C4
    // 0x80800110: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_808004C4_chgruntyfireballbig(rdram, ctx);
        goto after_9;
    // 0x80800110: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80800114: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800118: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080011C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800120: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800124: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080012C: nop

    // 0x80800130: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800134: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800138: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080013C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800140: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800144: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800148: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8080014C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800150: nop

    // 0x80800154: bc1fl       L_80800168
    if (!c1cs) {
        // 0x80800158: lw          $a0, 0x24($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X24);
            goto L_80800168;
    }
    goto skip_0;
    // 0x80800158: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x8080015C: jal         0x800FFAB0
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800164: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_80800168:
    // 0x80800168: beql        $a0, $zero, L_808001A4
    if (ctx->r4 == 0) {
        // 0x8080016C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001A4;
    }
    goto skip_1;
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800170: jal         0x800C8CB8
    // 0x80800174: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_11;
    // 0x80800174: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80800178: jal         0x8001210C
    // 0x8080017C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_12;
    // 0x8080017C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80800180: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800184: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80800188: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1500, 0X6E0) << 16);
    // 0x8080018C: addiu       $t9, $t9, 0x6E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1500, 0X6E0));
    // 0x80800190: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800194: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80800198: jal         0x800C8E84
    // 0x8080019C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8E84(rdram, ctx);
        goto after_13;
    // 0x8080019C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_13:
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001A4:
    // 0x808001A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_8008B238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B238: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8008B23C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8008B240: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8008B244: jr          $ra
    // 0x8008B248: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x8008B248: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void _idflame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E28: syscall     743
    recomp_syscall_handler(rdram, ctx, 0x80088E28);
    return;
    // 0x80088E2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazflamethrower_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800228: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8080022C: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80800230: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800238: beq         $v0, $at, L_8080026C
    if (ctx->r2 == ctx->r1) {
        // 0x8080023C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080026C;
    }
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800244: beq         $v0, $at, L_808002B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B4;
    }
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800250: beq         $v0, $at, L_808002F0
    if (ctx->r2 == ctx->r1) {
        // 0x80800254: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080025C: beq         $v0, $at, L_80800310
    if (ctx->r2 == ctx->r1) {
        // 0x80800260: nop
    
            goto L_80800310;
    }
    // 0x80800260: nop

    // 0x80800264: b           L_80800354
    // 0x80800268: nop

        goto L_80800354;
    // 0x80800268: nop

L_8080026C:
    // 0x8080026C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800270: jal         0x8008CB10
    // 0x80800274: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800274: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80800278: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800290;
    }
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: addiu       $a1, $zero, 0x459F
    ctx->r5 = ADD32(0, 0X459F);
    // 0x80800284: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800288: jal         0x8009DF18
    // 0x8080028C: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_8009DF18(rdram, ctx);
        goto after_1;
    // 0x8080028C: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_1:
L_80800290:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x8008CB10
    // 0x80800298: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800298: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    after_2:
    // 0x8080029C: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80800094
    // 0x808002A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800094_bskazflamethrower(rdram, ctx);
        goto after_3;
    // 0x808002A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002AC: b           L_80800354
    // 0x808002B0: nop

        goto L_80800354;
    // 0x808002B0: nop

L_808002B4:
    // 0x808002B4: jal         0x800852F0
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_decrement(rdram, ctx);
        goto after_4;
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: jal         0x80085330
    // 0x808002C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_isZero(rdram, ctx);
        goto after_5;
    // 0x808002C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808002C8: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x808002CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x80091A30
    // 0x808002D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x808002D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x808002D8: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x808002DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80800094
    // 0x808002E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800094_bskazflamethrower(rdram, ctx);
        goto after_7;
    // 0x808002E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808002E8: b           L_80800354
    // 0x808002EC: nop

        goto L_80800354;
    // 0x808002EC: nop

L_808002F0:
    // 0x808002F0: jal         0x800852F0
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_8;
    // 0x808002F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808002F8: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x808002FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800354;
    }
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x80800094
    // 0x80800304: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800094_bskazflamethrower(rdram, ctx);
        goto after_9;
    // 0x80800304: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800308: b           L_80800354
    // 0x8080030C: nop

        goto L_80800354;
    // 0x8080030C: nop

L_80800310:
    // 0x80800310: jal         0x8008CAEC
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_10;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800318: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x8080031C: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_80800324;
    }
    // 0x8080031C: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x80800320: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800324:
    // 0x80800324: jal         0x8008CAC8
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_11;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080032C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(232, 0X3A4) << 16);
    // 0x80800330: lwc1        $f4, 0x3A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(232, 0X3A4));
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080033C: nop

    // 0x80800340: bc1f        L_80800354
    if (!c1cs) {
        // 0x80800344: nop
    
            goto L_80800354;
    }
    // 0x80800344: nop

    // 0x80800348: jal         0x80083628
    // 0x8080034C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _bskazstill_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x8080034C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80800350: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800354:
    // 0x80800354: jal         0x80084BC0
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: jal         0x8009E5C8
    // 0x80800364: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_14;
    // 0x80800364: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x80800368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080036C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void _bstimeout_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F40: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F40);
    return;
    // 0x80083F44: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _bskazglide_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833E8: syscall     59
    recomp_syscall_handler(rdram, ctx, 0x800833E8);
    return;
    // 0x800833EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bstntswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(408, 0X9E0) << 16);
    // 0x80800900: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800904: jr          $ra
    // 0x80800908: lw          $v0, 0x9E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9E0));
    return;
    // 0x80800908: lw          $v0, 0x9E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9E0));
;}
RECOMP_FUNC void func_800E2180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2180: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E2184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E2188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E218C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800E2190: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800E2194: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E2198: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800E219C: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x800E21A0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E21A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E21A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E21AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E21B0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800E21B4: jal         0x800AF5D8
    // 0x800E21B8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800AF5D8(rdram, ctx);
        goto after_0;
    // 0x800E21B8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800E21BC: jal         0x8002E330
    // 0x800E21C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800E21C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800E21C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800E21C8: lui         $t0, 0xDB06
    ctx->r8 = S32(0XDB06 << 16);
    // 0x800E21CC: ori         $t0, $t0, 0x4
    ctx->r8 = ctx->r8 | 0X4;
    // 0x800E21D0: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800E21D4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E21D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800E21DC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E21E0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800E21E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800E21E8: jal         0x800AF5E4
    // 0x800E21EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_800AF5E4(rdram, ctx);
        goto after_2;
    // 0x800E21EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x800E21F0: jal         0x8002E330
    // 0x800E21F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800E21F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800E21F8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800E21FC: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800E2200: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800E2204: jal         0x800AF5FC
    // 0x800E2208: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800AF5FC(rdram, ctx);
        goto after_4;
    // 0x800E2208: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x800E220C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800E2210: jal         0x800AF5F0
    // 0x800E2214: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800AF5F0(rdram, ctx);
        goto after_5;
    // 0x800E2214: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x800E2218: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800E221C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E2220: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800E2224: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x800E2228: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800E222C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800E2230: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800E2234: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800E2238: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800E223C: jal         0x8002E330
    // 0x800E2240: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800E2240: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x800E2244: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800E2248: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800E224C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E2254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E2258: jr          $ra
    // 0x800E225C: nop

    return;
    // 0x800E225C: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A640: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A640);
    return;
    // 0x8008A644: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void _chpoolkids_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860E0: syscall     278
    recomp_syscall_handler(rdram, ctx, 0x800860E0);
    return;
    // 0x800860E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802D40_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802D48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802D4C: jal         0x80106790
    // 0x80802D50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802D50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802D54: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80802D58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802D5C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80802D60: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    // 0x80802D64: jal         0x80106790
    // 0x80802D68: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80802D68: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    after_1:
    // 0x80802D6C: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x80802D70: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80802D74: jal         0x80802640
    // 0x80802D78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80802D78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80802D7C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802D84: lw          $a2, 0x28($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X28);
    // 0x80802D88: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80802D8C: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80802D90: jal         0x80100074
    // 0x80802D94: sll         $a2, $t7, 1
    ctx->r6 = S32(ctx->r15 << 1);
    func_80100074(rdram, ctx);
        goto after_3;
    // 0x80802D94: sll         $a2, $t7, 1
    ctx->r6 = S32(ctx->r15 << 1);
    after_3:
    // 0x80802D98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802D9C: jal         0x80101FDC
    // 0x80802DA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80802DA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80802DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802DA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802DAC: jr          $ra
    // 0x80802DB0: nop

    return;
    // 0x80802DB0: nop

;}
RECOMP_FUNC void _idworld_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EF0: syscall     748
    recomp_syscall_handler(rdram, ctx, 0x80088EF0);
    return;
    // 0x80088EF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chexploder_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017DC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808017E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808017E4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808017E8: jal         0x80100094
    // 0x808017EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808017EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808017F0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808017F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808017F8: addu        $t7, $v0, $a3
    ctx->r15 = ADD32(ctx->r2, ctx->r7);
    // 0x808017FC: sb          $t6, 0x18($t7)
    MEM_B(0X18, ctx->r15) = ctx->r14;
    // 0x80801800: lbu         $t8, 0x18($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18);
    // 0x80801804: slt         $at, $t8, $a3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80801808: beql        $at, $zero, L_80801818
    if (ctx->r1 == 0) {
        // 0x8080180C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801818;
    }
    goto skip_0;
    // 0x8080180C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801810: sb          $a3, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r7;
    // 0x80801814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801818:
    // 0x80801818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080181C: jr          $ra
    // 0x80801820: nop

    return;
    // 0x80801820: nop

;}
RECOMP_FUNC void func_8009EB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EB04: jr          $ra
    // 0x8009EB08: swc1        $f12, 0x7068($at)
    MEM_W(0X7068, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8009EB08: swc1        $f12, 0x7068($at)
    MEM_W(0X7068, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800910_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800918: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080091C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800920: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800924: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800928: jal         0x80100094
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080092C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800930: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800934: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800938: slti        $at, $a3, 0x10C4
    ctx->r1 = SIGNED(ctx->r7) < 0X10C4 ? 1 : 0;
    // 0x8080093C: bne         $at, $zero, L_80800978
    if (ctx->r1 != 0) {
        // 0x80800940: addiu       $at, $zero, 0x10D1
        ctx->r1 = ADD32(0, 0X10D1);
            goto L_80800978;
    }
    // 0x80800940: addiu       $at, $zero, 0x10D1
    ctx->r1 = ADD32(0, 0X10D1);
    // 0x80800944: beq         $a3, $at, L_80800BC8
    if (ctx->r7 == ctx->r1) {
        // 0x80800948: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800BC8;
    }
    // 0x80800948: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080094C: addiu       $at, $zero, 0x10F5
    ctx->r1 = ADD32(0, 0X10F5);
    // 0x80800950: beq         $a3, $at, L_80800ACC
    if (ctx->r7 == ctx->r1) {
        // 0x80800954: addiu       $at, $zero, 0x10F6
        ctx->r1 = ADD32(0, 0X10F6);
            goto L_80800ACC;
    }
    // 0x80800954: addiu       $at, $zero, 0x10F6
    ctx->r1 = ADD32(0, 0X10F6);
    // 0x80800958: beq         $a3, $at, L_80800ACC
    if (ctx->r7 == ctx->r1) {
        // 0x8080095C: addiu       $at, $zero, 0x10F7
        ctx->r1 = ADD32(0, 0X10F7);
            goto L_80800ACC;
    }
    // 0x8080095C: addiu       $at, $zero, 0x10F7
    ctx->r1 = ADD32(0, 0X10F7);
    // 0x80800960: beq         $a3, $at, L_80800ACC
    if (ctx->r7 == ctx->r1) {
        // 0x80800964: addiu       $at, $zero, 0x1119
        ctx->r1 = ADD32(0, 0X1119);
            goto L_80800ACC;
    }
    // 0x80800964: addiu       $at, $zero, 0x1119
    ctx->r1 = ADD32(0, 0X1119);
    // 0x80800968: beql        $a3, $at, L_808009B4
    if (ctx->r7 == ctx->r1) {
        // 0x8080096C: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_808009B4;
    }
    goto skip_0;
    // 0x8080096C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800970: b           L_80800BF8
    // 0x80800974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800978:
    // 0x80800978: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x8080097C: beq         $a3, $at, L_80800AF4
    if (ctx->r7 == ctx->r1) {
        // 0x80800980: addiu       $at, $zero, 0xCEC
        ctx->r1 = ADD32(0, 0XCEC);
            goto L_80800AF4;
    }
    // 0x80800980: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800984: beq         $a3, $at, L_80800BAC
    if (ctx->r7 == ctx->r1) {
        // 0x80800988: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800BAC;
    }
    // 0x80800988: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080098C: addiu       $at, $zero, 0x10C1
    ctx->r1 = ADD32(0, 0X10C1);
    // 0x80800990: beq         $a3, $at, L_808009B0
    if (ctx->r7 == ctx->r1) {
        // 0x80800994: addiu       $at, $zero, 0x10C2
        ctx->r1 = ADD32(0, 0X10C2);
            goto L_808009B0;
    }
    // 0x80800994: addiu       $at, $zero, 0x10C2
    ctx->r1 = ADD32(0, 0X10C2);
    // 0x80800998: beq         $a3, $at, L_80800A78
    if (ctx->r7 == ctx->r1) {
        // 0x8080099C: addiu       $at, $zero, 0x10C3
        ctx->r1 = ADD32(0, 0X10C3);
            goto L_80800A78;
    }
    // 0x8080099C: addiu       $at, $zero, 0x10C3
    ctx->r1 = ADD32(0, 0X10C3);
    // 0x808009A0: beql        $a3, $at, L_80800AD0
    if (ctx->r7 == ctx->r1) {
        // 0x808009A4: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_80800AD0;
    }
    goto skip_1;
    // 0x808009A4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x808009A8: b           L_80800BF8
    // 0x808009AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x808009AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009B0:
    // 0x808009B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_808009B4:
    // 0x808009B4: blez        $t6, L_80800A14
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808009B8: nop
    
            goto L_80800A14;
    }
    // 0x808009B8: nop

    // 0x808009BC: jal         0x800DA544
    // 0x808009C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808009C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808009C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808009C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009CC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808009D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808009D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808009D8: jal         0x8008A2D0
    // 0x808009DC: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808009DC: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_2:
    // 0x808009E0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808009E4: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x808009E8: addiu       $a1, $zero, 0x10C2
    ctx->r5 = ADD32(0, 0X10C2);
    // 0x808009EC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x808009F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808009F4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808009F8: jal         0x8008A208
    // 0x808009FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808009FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800A00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A04: jal         0x80108B04
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800A0C: b           L_80800A60
    // 0x80800A10: nop

        goto L_80800A60;
    // 0x80800A10: nop

L_80800A14:
    // 0x80800A14: jal         0x800F54E4
    // 0x80800A18: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800A18: nop

    after_5:
    // 0x80800A1C: jal         0x800878F8
    // 0x80800A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800A24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800A28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A2C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800A30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800A34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A38: jal         0x8008A2C8
    // 0x80800A3C: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800A3C: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_7:
    // 0x80800A40: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800A44: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x80800A48: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800A4C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80800A50: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800A54: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800A58: jal         0x8008A208
    // 0x80800A5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800A5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
L_80800A60:
    // 0x80800A60: jal         0x800DA544
    // 0x80800A64: addiu       $a0, $zero, 0x1AD
    ctx->r4 = ADD32(0, 0X1AD);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800A64: addiu       $a0, $zero, 0x1AD
    ctx->r4 = ADD32(0, 0X1AD);
    after_9:
    // 0x80800A68: jal         0x80088178
    // 0x80800A6C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800A6C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_10:
    // 0x80800A70: b           L_80800BF8
    // 0x80800A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A78:
    // 0x80800A78: jal         0x800F54E4
    // 0x80800A7C: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800A7C: nop

    after_11:
    // 0x80800A80: jal         0x800878F8
    // 0x80800A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x80800A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80800A88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800A8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A90: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800A94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800A98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800A9C: jal         0x8008A2C8
    // 0x80800AA0: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80800AA0: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_13:
    // 0x80800AA4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800AA8: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80800AAC: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800AB0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80800AB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800AB8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800ABC: jal         0x8008A208
    // 0x80800AC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800AC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800AC4: b           L_80800BF8
    // 0x80800AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800ACC:
    // 0x80800ACC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_80800AD0:
    // 0x80800AD0: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80800AD4: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800AD8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80800ADC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800AE0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80800AE4: jal         0x8008A208
    // 0x80800AE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800AE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80800AEC: b           L_80800BF8
    // 0x80800AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AF4:
    // 0x80800AF4: jal         0x800F54E4
    // 0x80800AF8: nop

    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x80800AF8: nop

    after_16:
    // 0x80800AFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B00: jal         0x800F82D4
    // 0x80800B04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_17;
    // 0x80800B04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800B08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B0C: jal         0x80101FDC
    // 0x80800B10: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x80800B10: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_18:
    // 0x80800B14: jal         0x800D395C
    // 0x80800B18: nop

    func_800D395C(rdram, ctx);
        goto after_19;
    // 0x80800B18: nop

    after_19:
    // 0x80800B1C: beq         $v0, $zero, L_80800B58
    if (ctx->r2 == 0) {
        // 0x80800B20: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_80800B58;
    }
    // 0x80800B20: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800B24: jal         0x800A16BC
    // 0x80800B28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A16BC(rdram, ctx);
        goto after_20;
    // 0x80800B28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80800B2C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800B30: blez        $t5, L_80800B48
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80800B34: nop
    
            goto L_80800B48;
    }
    // 0x80800B34: nop

    // 0x80800B38: jal         0x80088188
    // 0x80800B3C: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800B3C: nop

    after_21:
    // 0x80800B40: b           L_80800BF8
    // 0x80800B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B48:
    // 0x80800B48: jal         0x80088180
    // 0x80800B4C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_22;
    // 0x80800B4C: nop

    after_22:
    // 0x80800B50: b           L_80800BF8
    // 0x80800B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B58:
    // 0x80800B58: blez        $t6, L_80800B74
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800B5C: addiu       $a0, $zero, 0x21A
        ctx->r4 = ADD32(0, 0X21A);
            goto L_80800B74;
    }
    // 0x80800B5C: addiu       $a0, $zero, 0x21A
    ctx->r4 = ADD32(0, 0X21A);
    // 0x80800B60: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    // 0x80800B64: jal         0x80087A58
    // 0x80800B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_23;
    // 0x80800B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800B6C: b           L_80800BF8
    // 0x80800B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B74:
    // 0x80800B74: jal         0x80089C30
    // 0x80800B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800B7C: beq         $v0, $zero, L_80800B94
    if (ctx->r2 == 0) {
        // 0x80800B80: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800B94;
    }
    // 0x80800B80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B84: jal         0x80089CA8
    // 0x80800B88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800B88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_25:
    // 0x80800B8C: jal         0x8010A570
    // 0x80800B90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_26;
    // 0x80800B90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_26:
L_80800B94:
    // 0x80800B94: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800B98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B9C: jal         0x8008A2C0
    // 0x80800BA0: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800BA0: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_27:
    // 0x80800BA4: b           L_80800BF8
    // 0x80800BA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800BA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BAC:
    // 0x80800BAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BB0: jal         0x8008A2C0
    // 0x80800BB4: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_28;
    // 0x80800BB4: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_28:
    // 0x80800BB8: jal         0x808006A0
    // 0x80800BBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808006A0_chhoopswoop(rdram, ctx);
        goto after_29;
    // 0x80800BBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_29:
    // 0x80800BC0: b           L_80800BF8
    // 0x80800BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BC8:
    // 0x80800BC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800BCC: jal         0x8008A2C0
    // 0x80800BD0: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x80800BD0: addiu       $a1, $a1, 0x4C4
    ctx->r5 = ADD32(ctx->r5, 0X4C4);
    after_30:
    // 0x80800BD4: jal         0x800F54E4
    // 0x80800BD8: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x80800BD8: nop

    after_31:
    // 0x80800BDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BE0: jal         0x800F82D4
    // 0x80800BE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_32;
    // 0x80800BE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80800BE8: addiu       $a0, $zero, 0xE1
    ctx->r4 = ADD32(0, 0XE1);
    // 0x80800BEC: jal         0x800887D8
    // 0x80800BF0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_33;
    // 0x80800BF0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_33:
    // 0x80800BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BF8:
    // 0x80800BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BFC: jr          $ra
    // 0x80800C00: nop

    return;
    // 0x80800C00: nop

;}
RECOMP_FUNC void func_808025AC_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808025B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808025B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808025B8: jal         0x8010D290
    // 0x808025BC: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_8010D290(rdram, ctx);
        goto after_0;
    // 0x808025BC: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_0:
    // 0x808025C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808025C4: bne         $v0, $at, L_808025D8
    if (ctx->r2 != ctx->r1) {
        // 0x808025C8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808025D8;
    }
    // 0x808025C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808025CC: jal         0x800F54E4
    // 0x808025D0: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808025D0: nop

    after_1:
    // 0x808025D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808025D8:
    // 0x808025D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808025DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808025E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808025E4: jr          $ra
    // 0x808025E8: nop

    return;
    // 0x808025E8: nop

;}
RECOMP_FUNC void _mlwave_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FA0: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FA0);
    return;
    // 0x80088FA4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazjump_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800678: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080067C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800680: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800684: jal         0x80095738
    // 0x80800688: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x80800688: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x8080068C: beq         $v0, $zero, L_808006A4
    if (ctx->r2 == 0) {
        // 0x80800690: nop
    
            goto L_808006A4;
    }
    // 0x80800690: nop

    // 0x80800694: jal         0x8009B7C0
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_1;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080069C: b           L_808006B0
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006B0;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006A4:
    // 0x808006A4: jal         0x800834B0
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006B0:
    // 0x808006B0: jal         0x8009BB24
    // 0x808006B4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x808006B4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x808006B8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808006BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006C0: beq         $v0, $at, L_808006D8
    if (ctx->r2 == ctx->r1) {
        // 0x808006C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808006D8;
    }
    // 0x808006C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006C8: beql        $v0, $at, L_80800760
    if (ctx->r2 == ctx->r1) {
        // 0x808006CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800760;
    }
    goto skip_0;
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808006D0: b           L_80800760
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800760;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006D8:
    // 0x808006D8: jal         0x8008E260
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_4;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006E0: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x808006E4: addiu       $t6, $zero, 0xE0
        ctx->r14 = ADD32(0, 0XE0);
            goto L_808006EC;
    }
    // 0x808006E4: addiu       $t6, $zero, 0xE0
    ctx->r14 = ADD32(0, 0XE0);
    // 0x808006E8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808006EC:
    // 0x808006EC: jal         0x80097E74
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097E74(rdram, ctx);
        goto after_5;
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006F4: beq         $v0, $zero, L_8080072C
    if (ctx->r2 == 0) {
        // 0x808006F8: nop
    
            goto L_8080072C;
    }
    // 0x808006F8: nop

    // 0x808006FC: lw          $t7, 0x168($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X168);
    // 0x80800700: addiu       $t8, $zero, 0xBE
    ctx->r24 = ADD32(0, 0XBE);
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: bne         $t7, $zero, L_80800718
    if (ctx->r15 != 0) {
        // 0x8080070C: nop
    
            goto L_80800718;
    }
    // 0x8080070C: nop

    // 0x80800710: b           L_8080072C
    // 0x80800714: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_8080072C;
    // 0x80800714: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800718:
    // 0x80800718: jal         0x80091A58
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x8080071C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800720: beq         $v0, $zero, L_8080072C
    if (ctx->r2 == 0) {
        // 0x80800724: addiu       $t9, $zero, 0xBE
        ctx->r25 = ADD32(0, 0XBE);
            goto L_8080072C;
    }
    // 0x80800724: addiu       $t9, $zero, 0xBE
    ctx->r25 = ADD32(0, 0XBE);
    // 0x80800728: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8080072C:
    // 0x8080072C: jal         0x80097D9C
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_7;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800734: beq         $v0, $zero, L_80800744
    if (ctx->r2 == 0) {
        // 0x80800738: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800744;
    }
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: addiu       $t0, $zero, 0x15C
    ctx->r8 = ADD32(0, 0X15C);
    // 0x80800740: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800744:
    // 0x80800744: jal         0x8008DF8C
    // 0x80800748: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_8008DF8C(rdram, ctx);
        goto after_8;
    // 0x80800748: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_8:
    // 0x8080074C: beq         $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800750: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080075C;
    }
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: jal         0x808004C4
    // 0x80800758: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808004C4_bskazjump(rdram, ctx);
        goto after_9;
    // 0x80800758: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
L_8080075C:
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800760:
    // 0x80800760: jal         0x80095748
    // 0x80800764: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isFalse(rdram, ctx);
        goto after_10;
    // 0x80800764: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_10:
    // 0x80800768: beq         $v0, $zero, L_808007AC
    if (ctx->r2 == 0) {
        // 0x8080076C: nop
    
            goto L_808007AC;
    }
    // 0x8080076C: nop

    // 0x80800770: jal         0x8008E078
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800778: bne         $v0, $zero, L_80800794
    if (ctx->r2 != 0) {
        // 0x8080077C: nop
    
            goto L_80800794;
    }
    // 0x8080077C: nop

    // 0x80800780: jal         0x80097FB8
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_12;
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800788: beq         $v0, $zero, L_80800794
    if (ctx->r2 == 0) {
        // 0x8080078C: addiu       $t1, $zero, 0xC4
        ctx->r9 = ADD32(0, 0XC4);
            goto L_80800794;
    }
    // 0x8080078C: addiu       $t1, $zero, 0xC4
    ctx->r9 = ADD32(0, 0XC4);
    // 0x80800790: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800794:
    // 0x80800794: jal         0x8008E35C
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_13;
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080079C: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007A0: addiu       $t2, $zero, 0x160
        ctx->r10 = ADD32(0, 0X160);
            goto L_808007C4;
    }
    // 0x808007A0: addiu       $t2, $zero, 0x160
    ctx->r10 = ADD32(0, 0X160);
    // 0x808007A4: b           L_808007C4
    // 0x808007A8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
        goto L_808007C4;
    // 0x808007A8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_808007AC:
    // 0x808007AC: jal         0x8008E35C
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808007B4: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007B8: nop
    
            goto L_808007C4;
    }
    // 0x808007B8: nop

    // 0x808007BC: jal         0x800A046C
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_15;
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_808007C4:
    // 0x808007C4: jal         0x8008E078
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_16;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808007CC: beql        $v0, $zero, L_80800818
    if (ctx->r2 == 0) {
        // 0x808007D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800818;
    }
    goto skip_1;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808007D4: jal         0x8009FE58
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_17;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808007DC: jal         0x8009EF10
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_18;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808007E4: bne         $v0, $zero, L_808007F4
    if (ctx->r2 != 0) {
        // 0x808007E8: addiu       $t3, $zero, 0xDE
        ctx->r11 = ADD32(0, 0XDE);
            goto L_808007F4;
    }
    // 0x808007E8: addiu       $t3, $zero, 0xDE
    ctx->r11 = ADD32(0, 0XDE);
    // 0x808007EC: b           L_80800814
    // 0x808007F0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
        goto L_80800814;
    // 0x808007F0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_808007F4:
    // 0x808007F4: jal         0x8008E39C
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_19;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808007FC: beq         $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x80800800: addiu       $t5, $zero, 0xBC
        ctx->r13 = ADD32(0, 0XBC);
            goto L_80800810;
    }
    // 0x80800800: addiu       $t5, $zero, 0xBC
    ctx->r13 = ADD32(0, 0XBC);
    // 0x80800804: addiu       $t4, $zero, 0xC7
    ctx->r12 = ADD32(0, 0XC7);
    // 0x80800808: b           L_80800814
    // 0x8080080C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
        goto L_80800814;
    // 0x8080080C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80800810:
    // 0x80800810: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80800814:
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800818:
    // 0x80800818: jal         0x8009E5C8
    // 0x8080081C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x8080081C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800828: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801FE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801FEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801FF0: jal         0x808004B4
    // 0x80801FF4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80801FF4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FFC: jal         0x8009D3A8
    // 0x80802000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80802000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80802004: lw          $t6, 0x164($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X164);
    // 0x80802008: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x8080200C: beq         $t6, $zero, L_8080201C
    if (ctx->r14 == 0) {
        // 0x80802010: nop
    
            goto L_8080201C;
    }
    // 0x80802010: nop

    // 0x80802014: b           L_80802038
    // 0x80802018: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80802038;
    // 0x80802018: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080201C:
    // 0x8080201C: jal         0x800839E8
    // 0x80802020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80802020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802024: beql        $v0, $zero, L_8080203C
    if (ctx->r2 == 0) {
        // 0x80802028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080203C;
    }
    goto skip_0;
    // 0x80802028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080202C: jal         0x800839B0
    // 0x80802030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80802030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802034: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80802038:
    // 0x80802038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080203C:
    // 0x8080203C: jal         0x8009E5C8
    // 0x80802040: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80802040: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80802044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080204C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802050: jr          $ra
    // 0x80802054: nop

    return;
    // 0x80802054: nop

;}
RECOMP_FUNC void func_80800024_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800028: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80800038: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8080003C: jal         0x80089D00
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800044: jal         0x8010A63C
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A63C(rdram, ctx);
        goto after_1;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080004C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800058: nop

    // 0x8080005C: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void gspropctrl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80800118: srl         $t6, $v0, 23
    ctx->r14 = S32(U32(ctx->r2) >> 23);
    // 0x8080011C: jr          $ra
    // 0x80800120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80800120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80801F98_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801F9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801FA4: jal         0x80802218
    // 0x80801FA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80802218_chaliendad(rdram, ctx);
        goto after_0;
    // 0x80801FA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801FAC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801FB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801FB4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801FB8: beq         $t6, $at, L_80801FD8
    if (ctx->r14 == ctx->r1) {
        // 0x80801FBC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801FD8;
    }
    // 0x80801FBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801FC0: beq         $t6, $at, L_8080203C
    if (ctx->r14 == ctx->r1) {
        // 0x80801FC4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080203C;
    }
    // 0x80801FC4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801FC8: beq         $t6, $at, L_8080201C
    if (ctx->r14 == ctx->r1) {
        // 0x80801FCC: nop
    
            goto L_8080201C;
    }
    // 0x80801FCC: nop

    // 0x80801FD0: b           L_8080203C
    // 0x80801FD4: nop

        goto L_8080203C;
    // 0x80801FD4: nop

L_80801FD8:
    // 0x80801FD8: jal         0x80105834
    // 0x80801FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_1;
    // 0x80801FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801FE0: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80801FE4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801FE8: jal         0x80105998
    // 0x80801FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105998(rdram, ctx);
        goto after_2;
    // 0x80801FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801FF0: beq         $v0, $zero, L_8080203C
    if (ctx->r2 == 0) {
        // 0x80801FF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080203C;
    }
    // 0x80801FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FF8: jal         0x80102424
    // 0x80801FFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80801FFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80802000: addiu       $a0, $zero, 0x45A
    ctx->r4 = ADD32(0, 0X45A);
    // 0x80802004: jal         0x80089C30
    // 0x80802008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80802008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080200C: jal         0x80801BD4
    // 0x80802010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80801BD4_chaliendad(rdram, ctx);
        goto after_5;
    // 0x80802010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80802014: b           L_8080203C
    // 0x80802018: nop

        goto L_8080203C;
    // 0x80802018: nop

L_8080201C:
    // 0x8080201C: jal         0x80105834
    // 0x80802020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_6;
    // 0x80802020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802024: jal         0x80105A5C
    // 0x80802028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_7;
    // 0x80802028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080202C: beq         $v0, $zero, L_8080203C
    if (ctx->r2 == 0) {
        // 0x80802030: nop
    
            goto L_8080203C;
    }
    // 0x80802030: nop

    // 0x80802034: jal         0x800FFAB0
    // 0x80802038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80802038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8080203C:
    // 0x8080203C: jal         0x80802284
    // 0x80802040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802284_chaliendad(rdram, ctx);
        goto after_9;
    // 0x80802040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080204C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802050: jr          $ra
    // 0x80802054: nop

    return;
    // 0x80802054: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B28: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B28);
    return;
    // 0x80087B2C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_8080003C_chwaspstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800048: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800054: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800058: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8080005C: beq         $at, $zero, L_80800110
    if (ctx->r1 == 0) {
        // 0x80800060: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800110;
    }
    // 0x80800060: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800064: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2364, 0X630) << 16);
    // 0x80800068: addu        $at, $at, $t8
    gpr jr_addend_80800070 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080006C: lw          $t8, 0x630($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2364, 0X630));
    // 0x80800070: jr          $t8
    // 0x80800074: nop

    switch (jr_addend_80800070 >> 2) {
        case 0: goto L_80800110; break;
        case 1: goto L_80800078; break;
        case 2: goto L_808000C4; break;
        case 3: goto L_808000E4; break;
        case 4: goto L_80800104; break;
        case 5: goto L_80800110; break;
        default: switch_error(__func__, 0x80800070, 0x80800630);
    }
    // 0x80800074: nop

L_80800078:
    // 0x80800078: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8080007C: jal         0x800D91EC
    // 0x80800080: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_800D91EC(rdram, ctx);
        goto after_0;
    // 0x80800080: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x80800084: beql        $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x80800088: lw          $a1, 0x6C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X6C);
            goto L_808000A8;
    }
    goto skip_0;
    // 0x80800088: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x8080008C: jal         0x800DA298
    // 0x80800090: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800090: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    after_1:
    // 0x80800094: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x80800134
    // 0x808000A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_2;
    // 0x808000A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_808000A4:
    // 0x808000A4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_808000A8:
    // 0x808000A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x808000AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000B0: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x808000B4: jal         0x800D2498
    // 0x808000B8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800D2498(rdram, ctx);
        goto after_3;
    // 0x808000B8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_3:
    // 0x808000BC: b           L_80800114
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800114;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000C4:
    // 0x808000C4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808000C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x808000CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000D0: andi        $t0, $a1, 0x1FF
    ctx->r8 = ctx->r5 & 0X1FF;
    // 0x808000D4: jal         0x800D2498
    // 0x808000D8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800D2498(rdram, ctx);
        goto after_4;
    // 0x808000D8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_4:
    // 0x808000DC: b           L_80800114
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800114;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000E4:
    // 0x808000E4: jal         0x800D90A4
    // 0x808000E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x808000E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x808000EC: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800110;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80800134
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_6;
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000FC: b           L_80800114
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800114;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800104:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x80800134
    // 0x8080010C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_7;
    // 0x8080010C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
L_80800110:
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800114:
    // 0x80800114: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800118: jal         0x8010C93C
    // 0x8080011C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_8010C93C(rdram, ctx);
        goto after_8;
    // 0x8080011C: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_8:
    // 0x80800120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800124: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void func_80800000_indrv_audio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8080000C: bltz        $a1, L_80800028
    if (SIGNED(ctx->r5) < 0) {
        // 0x80800010: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800028;
    }
    // 0x80800010: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800014: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x80800018: jal         0x800DBEFC
    // 0x8080001C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800020: b           L_80800038
    // 0x80800024: nop

        goto L_80800038;
    // 0x80800024: nop

L_80800028:
    // 0x80800028: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8080002C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800030: jal         0x800EE88C
    // 0x80800034: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
L_80800038:
    // 0x80800038: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2970, 0X1478) << 16);
    // 0x8080003C: addiu       $a2, $a2, 0x1478
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2970, 0X1478));
    // 0x80800040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800044: jal         0x800C4350
    // 0x80800048: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C4350(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x8080004C: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x80800050: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800054: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800058: jal         0x800C4350
    // 0x8080005C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x8080005C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x80800060: jal         0x8008FFE8
    // 0x80800064: nop

    func_8008FFE8(rdram, ctx);
        goto after_4;
    // 0x80800064: nop

    after_4:
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080006C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800070: jal         0x8010FFB0
    // 0x80800074: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8010FFB0(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80800078: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080007C: jal         0x800F1DF4
    // 0x80800080: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_6;
    // 0x80800080: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80800084: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800088: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8080008C: jal         0x800F20BC
    // 0x80800090: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800F20BC(rdram, ctx);
        goto after_7;
    // 0x80800090: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_7:
    // 0x80800094: bne         $v0, $zero, L_808000A4
    if (ctx->r2 != 0) {
        // 0x80800098: lbu         $a0, 0x3B($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X3B);
            goto L_808000A4;
    }
    // 0x80800098: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    // 0x8080009C: jal         0x800C3AE0
    // 0x808000A0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_800C3AE0(rdram, ctx);
        goto after_8;
    // 0x808000A0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_8:
L_808000A4:
    // 0x808000A4: jal         0x800C3BDC
    // 0x808000A8: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    func_800C3BDC(rdram, ctx);
        goto after_9;
    // 0x808000A8: lbu         $a0, 0x3B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X3B);
    after_9:
    // 0x808000AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082600: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082600);
    return;
    // 0x80082604: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void _chcrusher_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AA8: syscall     413
    recomp_syscall_handler(rdram, ctx, 0x80086AA8);
    return;
    // 0x80086AAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chstoneballcontrol_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A48: syscall     409
    recomp_syscall_handler(rdram, ctx, 0x80086A48);
    return;
    // 0x80086A4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8001443C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001443C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014440: lw          $a1, -0x7B84($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B84);
    // 0x80014444: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80014448: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001444C: sltu        $t6, $zero, $a1
    ctx->r14 = 0 < ctx->r5 ? 1 : 0;
    // 0x80014450: beq         $t6, $zero, L_800144A8
    if (ctx->r14 == 0) {
        // 0x80014454: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800144A8;
    }
    // 0x80014454: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80014458: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001445C: addiu       $t7, $t7, -0x7158
    ctx->r15 = ADD32(ctx->r15, -0X7158);
    // 0x80014460: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80014464: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014468: addiu       $t9, $t9, -0x7154
    ctx->r25 = ADD32(ctx->r25, -0X7154);
    // 0x8001446C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80014470: xor         $a1, $t8, $t0
    ctx->r5 = ctx->r24 ^ ctx->r8;
    // 0x80014474: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80014478: beql        $a1, $zero, L_800144AC
    if (ctx->r5 == 0) {
        // 0x8001447C: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_800144AC;
    }
    goto skip_0;
    // 0x8001447C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    skip_0:
    // 0x80014480: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014484: lw          $a1, -0x7B78($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B78);
    // 0x80014488: xori        $t1, $a1, 0x2
    ctx->r9 = ctx->r5 ^ 0X2;
    // 0x8001448C: sltiu       $a1, $t1, 0x1
    ctx->r5 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80014490: beql        $a1, $zero, L_800144AC
    if (ctx->r5 == 0) {
        // 0x80014494: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_800144AC;
    }
    goto skip_1;
    // 0x80014494: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    skip_1:
    // 0x80014498: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001449C: lw          $a1, -0x7B74($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B74);
    // 0x800144A0: xori        $t2, $a1, 0x10
    ctx->r10 = ctx->r5 ^ 0X10;
    // 0x800144A4: sltiu       $a1, $t2, 0x1
    ctx->r5 = ctx->r10 < 0X1 ? 1 : 0;
L_800144A8:
    // 0x800144A8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800144AC:
    // 0x800144AC: jal         0x8002F250
    // 0x800144B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x800144B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800144B4: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800144B8: lw          $t3, -0x70F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X70F8);
    // 0x800144BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800144C0: bne         $v0, $t3, L_800144D0
    if (ctx->r2 != ctx->r11) {
        // 0x800144C4: nop
    
            goto L_800144D0;
    }
    // 0x800144C4: nop

    // 0x800144C8: beq         $a1, $zero, L_8001454C
    if (ctx->r5 == 0) {
        // 0x800144CC: nop
    
            goto L_8001454C;
    }
    // 0x800144CC: nop

L_800144D0:
    // 0x800144D0: jal         0x8002F240
    // 0x800144D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osDpGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x800144D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800144D8: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x800144DC: beq         $t4, $zero, L_80014520
    if (ctx->r12 == 0) {
        // 0x800144E0: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80014520;
    }
    // 0x800144E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800144E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800144E8: jal         0x8002EF70
    // 0x800144EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osDpSetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x800144EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x800144F0: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x800144F4: lw          $t5, -0x7B78($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7B78);
    // 0x800144F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800144FC: addiu       $v0, $v0, -0x7B7C
    ctx->r2 = ADD32(ctx->r2, -0X7B7C);
    // 0x80014500: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80014504: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80014508: beq         $t7, $zero, L_80014520
    if (ctx->r15 == 0) {
        // 0x8001450C: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_80014520;
    }
    // 0x8001450C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80014510: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80014514: addiu       $a3, $a3, -0x70F0
    ctx->r7 = ADD32(ctx->r7, -0X70F0);
    // 0x80014518: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8001451C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_80014520:
    // 0x80014520: beq         $a1, $zero, L_8001454C
    if (ctx->r5 == 0) {
        // 0x80014524: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8001454C;
    }
    // 0x80014524: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014528: addiu       $a0, $a0, -0x7BC8
    ctx->r4 = ADD32(ctx->r4, -0X7BC8);
    // 0x8001452C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014530: jal         0x8002EAD0
    // 0x80014534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80014534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80014538: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001453C: addiu       $a0, $a0, -0x7B84
    ctx->r4 = ADD32(ctx->r4, -0X7B84);
    // 0x80014540: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80014544: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x80014548: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8001454C:
    if (tooie_scheduler_vi_skip(rdram, ctx)) { ctx->r31 = MEM_W(ctx->r29, 0X24); goto L_800146CC; }
    // 0x8001454C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80014550: addiu       $v1, $v1, -0x70F4
    ctx->r3 = ADD32(ctx->r3, -0X70F4);
    // 0x80014554: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80014558: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001455C: addiu       $a3, $a3, -0x70F0
    ctx->r7 = ADD32(ctx->r7, -0X70F0);
    // 0x80014560: beq         $v0, $zero, L_80014578
    if (ctx->r2 == 0) {
        // 0x80014564: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80014578;
    }
    // 0x80014564: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80014568: bne         $t1, $zero, L_80014578
    if (ctx->r9 != 0) {
        // 0x8001456C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_80014578;
    }
    // 0x8001456C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80014570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80014574: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
L_80014578:
    // 0x80014578: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001457C: addiu       $v1, $v1, -0x70EC
    ctx->r3 = ADD32(ctx->r3, -0X70EC);
    // 0x80014580: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80014584: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014588: beq         $v0, $zero, L_8001459C
    if (ctx->r2 == 0) {
        // 0x8001458C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8001459C;
    }
    // 0x8001458C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80014590: bne         $t3, $zero, L_8001459C
    if (ctx->r11 != 0) {
        // 0x80014594: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_8001459C;
    }
    // 0x80014594: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80014598: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001459C:
    // 0x8001459C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800145A0: beq         $v0, $zero, L_800145B4
    if (ctx->r2 == 0) {
        // 0x800145A4: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800145B4;
    }
    // 0x800145A4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800145A8: bne         $t5, $zero, L_800145B4
    if (ctx->r13 != 0) {
        // 0x800145AC: sw          $t5, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r13;
            goto L_800145B4;
    }
    // 0x800145AC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800145B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800145B4:
    // 0x800145B4: beq         $a0, $zero, L_800145C4
    if (ctx->r4 == 0) {
        // 0x800145B8: nop
    
            goto L_800145C4;
    }
    // 0x800145B8: nop

    // 0x800145BC: jal         0x8001E5DC
    // 0x800145C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001E5DC(rdram, ctx);
        goto after_4;
    // 0x800145C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
L_800145C4:
    // 0x800145C4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800145C8: lw          $v0, -0xBCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XBCC);
    // 0x800145CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800145D0: sw          $zero, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = 0;
    // 0x800145D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800145D8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800145DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800145E0: bne         $t7, $zero, L_80014630
    if (ctx->r15 != 0) {
        // 0x800145E4: sw          $v0, -0xBCC($at)
        MEM_W(-0XBCC, ctx->r1) = ctx->r2;
            goto L_80014630;
    }
    // 0x800145E4: sw          $v0, -0xBCC($at)
    MEM_W(-0XBCC, ctx->r1) = ctx->r2;
    // 0x800145E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800145EC: jal         0x8002F290
    // 0x800145F0: addiu       $a0, $a0, -0x70E8
    ctx->r4 = ADD32(ctx->r4, -0X70E8);
    osStopTimer_recomp(rdram, ctx);
        goto after_5;
    // 0x800145F0: addiu       $a0, $a0, -0x70E8
    ctx->r4 = ADD32(ctx->r4, -0X70E8);
    after_5:
    // 0x800145F4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800145F8: addiu       $t0, $t0, -0x7C30
    ctx->r8 = ADD32(ctx->r8, -0X7C30);
    // 0x800145FC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014600: lui         $a3, 0x4
    ctx->r7 = S32(0X4 << 16);
    // 0x80014604: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80014608: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8001460C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80014610: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80014614: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80014618: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001461C: ori         $a3, $a3, 0x45C0
    ctx->r7 = ctx->r7 | 0X45C0;
    // 0x80014620: addiu       $a0, $a0, -0x70E8
    ctx->r4 = ADD32(ctx->r4, -0X70E8);
    // 0x80014624: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80014628: jal         0x8002F360
    // 0x8001462C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    osSetTimer_recomp(rdram, ctx);
        goto after_6;
    // 0x8001462C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
L_80014630:
    // 0x80014630: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80014634: lw          $t2, -0x70A8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X70A8);
    // 0x80014638: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001463C: beql        $t2, $zero, L_800146CC
    if (ctx->r10 == 0) {
        // 0x80014640: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800146CC;
    }
    goto skip_2;
    // 0x80014640: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80014644: jal         0x8002F290
    // 0x80014648: addiu       $a0, $a0, -0x70C8
    ctx->r4 = ADD32(ctx->r4, -0X70C8);
    osStopTimer_recomp(rdram, ctx);
        goto after_7;
    // 0x80014648: addiu       $a0, $a0, -0x70C8
    ctx->r4 = ADD32(ctx->r4, -0X70C8);
    after_7:
    // 0x8001464C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80014650: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80014654: lw          $a1, 0x1394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1394);
    // 0x80014658: lw          $a0, 0x1390($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1390);
    // 0x8001465C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80014660: jal         0x8002F4A8
    // 0x80014664: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    __ull_div_recomp(rdram, ctx);
        goto after_8;
    // 0x80014664: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_8:
    // 0x80014668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001466C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80014670: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80014674: jal         0x8002F5A8
    // 0x80014678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    __ll_mul_recomp(rdram, ctx);
        goto after_9;
    // 0x80014678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x8001467C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80014680: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80014684: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80014688: jal         0x8002F4A8
    // 0x8001468C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ull_div_recomp(rdram, ctx);
        goto after_10;
    // 0x8001468C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80014690: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80014694: addiu       $t3, $t3, -0x7C30
    ctx->r11 = ADD32(ctx->r11, -0X7C30);
    // 0x80014698: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001469C: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800146A0: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x800146A4: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800146A8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800146AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800146B0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800146B4: addiu       $a0, $a0, -0x70C8
    ctx->r4 = ADD32(ctx->r4, -0X70C8);
    // 0x800146B8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800146BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800146C0: jal         0x8002F360
    // 0x800146C4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    osSetTimer_recomp(rdram, ctx);
        goto after_11;
    // 0x800146C4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_11:
    // 0x800146C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800146CC:
    // 0x800146CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800146D0: jr          $ra
    // 0x800146D4: nop

    return;
    // 0x800146D4: nop

;}
RECOMP_FUNC void bssplat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x800954E8
    // 0x80800014: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800954E8(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800018: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    tooie_fall_damage_begin(rdram, ctx);
    // 0x80800020: jal         0x800A17A8
    // 0x80800024: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    func_800A17A8(rdram, ctx);
        goto after_1;
    // 0x80800024: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_1:
    tooie_fall_damage_end(rdram, ctx);
    // 0x80800028: jal         0x80096694
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096694(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800030: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800034: bne         $v0, $at, L_8080005C
    if (ctx->r2 != ctx->r1) {
        // 0x80800038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080005C;
    }
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800040: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x8080004C: jal         0x8009DB04
    // 0x80800050: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_3:
    // 0x80800054: b           L_80800070
    // 0x80800058: nop

        goto L_80800070;
    // 0x80800058: nop

L_8080005C:
    // 0x8080005C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800060: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800064: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800068: jal         0x8009DB04
    // 0x8080006C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_4;
    // 0x8080006C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_4:
L_80800070:
    // 0x80800070: jal         0x80084A08
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800080: jal         0x80084FC8
    // 0x80800084: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800084: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080171C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80801720: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801724: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80801728: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8080172C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80801730: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80801734: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801738: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080173C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801740: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801744: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801748: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8080174C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80801750: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80801754: blez        $t6, L_80801870
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80801758: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80801870;
    }
    // 0x80801758: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8080175C: addiu       $t7, $sp, 0x64
    ctx->r15 = ADD32(ctx->r29, 0X64);
    // 0x80801760: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80801764: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x80801768: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8080176C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80801770:
    // 0x80801770: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_80801774:
    // 0x80801774: jal         0x800DC128
    // 0x80801778: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80801778: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    after_0:
    // 0x8080177C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80801780: jal         0x80088440
    // 0x80801784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gczoomboxdata_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801784: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801788: beq         $v0, $zero, L_8080182C
    if (ctx->r2 == 0) {
        // 0x8080178C: nop
    
            goto L_8080182C;
    }
    // 0x8080178C: nop

    // 0x80801790: jal         0x80088438
    // 0x80801794: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    _gczoomboxdata_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801794: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x80801798: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8080179C: jal         0x80088438
    // 0x808017A0: lh          $a0, 0x236($fp)
    ctx->r4 = MEM_H(ctx->r30, 0X236);
    _gczoomboxdata_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808017A0: lh          $a0, 0x236($fp)
    ctx->r4 = MEM_H(ctx->r30, 0X236);
    after_3:
    // 0x808017A4: beq         $s0, $v0, L_8080182C
    if (ctx->r16 == ctx->r2) {
        // 0x808017A8: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_8080182C;
    }
    // 0x808017A8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x808017AC: beq         $s5, $zero, L_808017F0
    if (ctx->r21 == 0) {
        // 0x808017B0: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_808017F0;
    }
    // 0x808017B0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x808017B4: lh          $t8, 0x0($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X0);
    // 0x808017B8: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x808017BC: beq         $s2, $t8, L_808017F0
    if (ctx->r18 == ctx->r24) {
        // 0x808017C0: nop
    
            goto L_808017F0;
    }
    // 0x808017C0: nop

    // 0x808017C4: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
L_808017C8:
    // 0x808017C8: jal         0x80088438
    // 0x808017CC: nop

    _gczoomboxdata_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x808017CC: nop

    after_4:
    // 0x808017D0: bnel        $s1, $v0, L_808017E4
    if (ctx->r17 != ctx->r2) {
        // 0x808017D4: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_808017E4;
    }
    goto skip_0;
    // 0x808017D4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x808017D8: b           L_808017F0
    // 0x808017DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_808017F0;
    // 0x808017DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808017E0: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_808017E4:
    // 0x808017E4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808017E8: bne         $s2, $a0, L_808017C8
    if (ctx->r18 != ctx->r4) {
        // 0x808017EC: nop
    
            goto L_808017C8;
    }
    // 0x808017EC: nop

L_808017F0:
    // 0x808017F0: beq         $s4, $zero, L_8080182C
    if (ctx->r20 == 0) {
        // 0x808017F4: addiu       $v0, $s7, -0x1
        ctx->r2 = ADD32(ctx->r23, -0X1);
            goto L_8080182C;
    }
    // 0x808017F4: addiu       $v0, $s7, -0x1
    ctx->r2 = ADD32(ctx->r23, -0X1);
    // 0x808017F8: bltz        $v0, L_8080182C
    if (SIGNED(ctx->r2) < 0) {
        // 0x808017FC: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_8080182C;
    }
    // 0x808017FC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80801800: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x80801804: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
L_80801808:
    // 0x80801808: jal         0x80088438
    // 0x8080180C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _gczoomboxdata_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x8080180C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_5:
    // 0x80801810: bne         $s1, $v0, L_80801820
    if (ctx->r17 != ctx->r2) {
        // 0x80801814: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_80801820;
    }
    // 0x80801814: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x80801818: b           L_8080182C
    // 0x8080181C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_8080182C;
    // 0x8080181C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80801820:
    // 0x80801820: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80801824: beq         $at, $zero, L_80801808
    if (ctx->r1 == 0) {
        // 0x80801828: nop
    
            goto L_80801808;
    }
    // 0x80801828: nop

L_8080182C:
    // 0x8080182C: beql        $s4, $zero, L_80801774
    if (ctx->r20 == 0) {
        // 0x80801830: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80801774;
    }
    goto skip_1;
    // 0x80801830: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    skip_1:
    // 0x80801834: sll         $a2, $s6, 16
    ctx->r6 = S32(ctx->r22 << 16);
    // 0x80801838: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8080183C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80801840: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80801844: jal         0x808018A0
    // 0x80801848: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    gcnewoption_entrypoint_31(rdram, ctx);
        goto after_6;
    // 0x80801848: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_6:
    // 0x8080184C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80801850: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80801854: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80801858: sh          $s6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r22;
    // 0x8080185C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80801860: lh          $t4, 0x4($fp)
    ctx->r12 = MEM_H(ctx->r30, 0X4);
    // 0x80801864: slt         $at, $s7, $t4
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80801868: bnel        $at, $zero, L_80801770
    if (ctx->r1 != 0) {
        // 0x8080186C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80801770;
    }
    goto skip_2;
    // 0x8080186C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_2:
L_80801870:
    // 0x80801870: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801878: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080187C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801880: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801884: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801888: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080188C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801890: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80801894: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80801898: jr          $ra
    // 0x8080189C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8080189C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80800620_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800624: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800628: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080062C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800630: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800634: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080063C: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800640: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800644: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800648: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080064C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80800650: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80800654: jal         0x80800384
    // 0x80800658: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_80800384_susplinet(rdram, ctx);
        goto after_0;
    // 0x80800658: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_0:
    // 0x8080065C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800660: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80800664: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x80800668: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8080066C: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80800670: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80800674: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80800678: lw          $t3, 0x54($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X54);
    // 0x8080067C: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80800680: bnel        $t4, $zero, L_808006DC
    if (ctx->r12 != 0) {
        // 0x80800684: lh          $v1, 0x4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X4);
            goto L_808006DC;
    }
    goto skip_0;
    // 0x80800684: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    skip_0:
    // 0x80800688: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // 0x8080068C: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x80800690: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800694: bne         $at, $zero, L_808006A4
    if (ctx->r1 != 0) {
        // 0x80800698: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_808006A4;
    }
    // 0x80800698: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8080069C: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x808006A0: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
L_808006A4:
    // 0x808006A4: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x808006A8: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x808006AC: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x808006B0: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x808006B4: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808006B8: bne         $at, $zero, L_808006C4
    if (ctx->r1 != 0) {
        // 0x808006BC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_808006C4;
    }
    // 0x808006BC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x808006C0: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_808006C4:
    // 0x808006C4: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x808006C8: bgezl       $t9, L_8080073C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808006CC: lh          $a1, 0x2($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X2);
            goto L_8080073C;
    }
    goto skip_1;
    // 0x808006CC: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x808006D0: b           L_80800738
    // 0x808006D4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_80800738;
    // 0x808006D4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x808006D8: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
L_808006DC:
    // 0x808006DC: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x808006E0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808006E4: bne         $at, $zero, L_808006F8
    if (ctx->r1 != 0) {
        // 0x808006E8: subu        $t0, $v1, $v0
        ctx->r8 = SUB32(ctx->r3, ctx->r2);
            goto L_808006F8;
    }
    // 0x808006E8: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x808006EC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x808006F0: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x808006F4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
L_808006F8:
    // 0x808006F8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x808006FC: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80800700: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x80800704: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x80800708: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080070C: bne         $at, $zero, L_8080071C
    if (ctx->r1 != 0) {
        // 0x80800710: subu        $t3, $a1, $v0
        ctx->r11 = SUB32(ctx->r5, ctx->r2);
            goto L_8080071C;
    }
    // 0x80800710: subu        $t3, $a1, $v0
    ctx->r11 = SUB32(ctx->r5, ctx->r2);
    // 0x80800714: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80800718: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
L_8080071C:
    // 0x8080071C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80800720: bgezl       $v0, L_8080073C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800724: lh          $a1, 0x2($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X2);
            goto L_8080073C;
    }
    goto skip_2;
    // 0x80800724: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x80800728: lh          $t5, 0x4E($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4E);
    // 0x8080072C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80800730: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800734: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_80800738:
    // 0x80800738: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
L_8080073C:
    // 0x8080073C: jal         0x80800048
    // 0x80800740: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80800048_susplinet(rdram, ctx);
        goto after_1;
    // 0x80800740: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800744: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x80800748: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800754;
    }
    // 0x80800748: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080074C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80800750: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80800754:
    // 0x80800754: jal         0x80800068
    // 0x80800758: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    func_80800068_susplinet(rdram, ctx);
        goto after_2;
    // 0x80800758: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    after_2:
    // 0x8080075C: beq         $v0, $zero, L_8080076C
    if (ctx->r2 == 0) {
        // 0x80800760: lui         $a3, 0x3EAA
        ctx->r7 = S32(0X3EAA << 16);
            goto L_8080076C;
    }
    // 0x80800760: lui         $a3, 0x3EAA
    ctx->r7 = S32(0X3EAA << 16);
    // 0x80800764: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x80800768: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_8080076C:
    // 0x8080076C: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x80800770: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800774: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80800778: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8080077C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80800780: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80800784: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80800788: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8080078C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80800790: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80800794: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3206, 0X1300) << 16);
    // 0x80800798: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080079C: lwc1        $f16, 0x1300($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3206, 0X1300));
    // 0x808007A0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x808007A4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808007A8: ori         $a3, $a3, 0x7EFA
    ctx->r7 = ctx->r7 | 0X7EFA;
    // 0x808007AC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808007B0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808007B4: jal         0x800F10B4
    // 0x808007B8: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808007B8: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    after_3:
    // 0x808007BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808007C8: jr          $ra
    // 0x808007CC: nop

    return;
    // 0x808007CC: nop

;}
RECOMP_FUNC void func_80800138_chlavaexplodbuild(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8080013C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80800140: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800144: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800148: addiu       $s4, $sp, 0x74
    ctx->r20 = ADD32(ctx->r29, 0X74);
    // 0x8080014C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800150: addiu       $s2, $a2, 0x4
    ctx->r18 = ADD32(ctx->r6, 0X4);
    // 0x80800154: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80800158: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8080015C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80800160: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80800164: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800168: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8080016C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800170: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800174: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800178: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080017C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800180: jal         0x800EE7F8
    // 0x80800184: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800184: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x80800188: jal         0x800B53A4
    // 0x8080018C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x8080018C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80800190: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80800194: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800198: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080019C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808001A0: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x808001A4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808001A8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808001AC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808001B0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808001B4: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(2068, 0X2A4) << 16);
    // 0x808001B8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808001BC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808001C0: addiu       $s5, $s5, 0x2A4
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(2068, 0X2A4));
    // 0x808001C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001C8: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x808001CC: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
    // 0x808001D0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_808001D4:
    // 0x808001D4: jal         0x800DC178
    // 0x808001D8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808001D8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_2:
    // 0x808001DC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x808001E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001EC: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x808001F0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808001F4: jal         0x800EEB9C
    // 0x808001F8: nop

    func_800EEB9C(rdram, ctx);
        goto after_3;
    // 0x808001F8: nop

    after_3:
    // 0x808001FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800200: jal         0x800EF04C
    // 0x80800204: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800204: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800208: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080020C: jal         0x800DC178
    // 0x80800210: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800210: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_5:
    // 0x80800214: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800218: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8080021C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800220: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800224: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800228: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080022C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80800230: jal         0x800BABB8
    // 0x80800234: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800234: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80800238: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080023C: bnel        $s0, $s6, L_808001D4
    if (ctx->r16 != ctx->r22) {
        // 0x80800240: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_808001D4;
    }
    goto skip_0;
    // 0x80800240: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_0:
    // 0x80800244: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800248: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080024C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800250: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800254: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800258: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8080025C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800260: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800264: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800268: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8080026C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800270: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800274: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800278: jr          $ra
    // 0x8080027C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8080027C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void gcdialogexec_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D3C: jal         0x80800A50
    // 0x80801D40: nop

    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80801D40: nop

    after_0:
    // 0x80801D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D4C: jr          $ra
    // 0x80801D50: nop

    return;
    // 0x80801D50: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080074C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800750: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800754: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800758: jal         0x80085228
    // 0x8080075C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8080075C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x8009B9B0
    // 0x80800768: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800768: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x8080076C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800770: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800774: beq         $v0, $at, L_80800798
    if (ctx->r2 == ctx->r1) {
        // 0x80800778: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800798;
    }
    // 0x80800778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080077C: beq         $v0, $at, L_808007B8
    if (ctx->r2 == ctx->r1) {
        // 0x80800780: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007B8;
    }
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800788: beql        $v0, $at, L_808007CC
    if (ctx->r2 == ctx->r1) {
        // 0x8080078C: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_808007CC;
    }
    goto skip_0;
    // 0x8080078C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x80800790: b           L_808007F8
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808007F8;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800798:
    // 0x80800798: jal         0x8008E078
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007A0: beq         $v0, $zero, L_808007F4
    if (ctx->r2 == 0) {
        // 0x808007A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007F4;
    }
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: jal         0x808005F0
    // 0x808007AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808005F0_bsstonehead(rdram, ctx);
        goto after_3;
    // 0x808007AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808007B0: b           L_808007F8
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808007F8;
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007B8:
    // 0x808007B8: jal         0x808005F0
    // 0x808007BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005F0_bsstonehead(rdram, ctx);
        goto after_4;
    // 0x808007BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808007C0: b           L_808007F8
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808007F8;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_808007CC:
    // 0x808007CC: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808007D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808007D4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808007D8: nop

    // 0x808007DC: bc1fl       L_808007F8
    if (!c1cs) {
        // 0x808007E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007F8;
    }
    goto skip_1;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808007E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007E8: jal         0x800F0E00
    // 0x808007EC: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_5;
    // 0x808007EC: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    after_5:
    // 0x808007F0: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_808007F4:
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007F8:
    // 0x808007F8: jal         0x8009E5C8
    // 0x808007FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808007FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080080C: jr          $ra
    // 0x80800810: nop

    return;
    // 0x80800810: nop

;}
RECOMP_FUNC void func_800CEF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEF48: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CEF4C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800CEF50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CEF54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CEF58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800CEF5C: lh          $t7, -0x5572($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X5572);
    // 0x800CEF60: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800CEF64: jr          $ra
    // 0x800CEF68: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x800CEF68: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_800E8830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8838: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800E883C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8840: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E8844: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8848: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    // 0x800E884C: jal         0x800B301C
    // 0x800E8850: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x800E8850: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800E8854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E8858: jal         0x800EE7F8
    // 0x800E885C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800E885C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800E8860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8868: jr          $ra
    // 0x800E886C: nop

    return;
    // 0x800E886C: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x80800140: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x80800144: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800148: jr          $ra
    // 0x8080014C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x8080014C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
